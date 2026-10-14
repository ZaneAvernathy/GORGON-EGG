
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

#include <string.h>


/* This file provides a system for rendering 8x8px icons.
 *
 * The system keeps a cache of registered icons in order to save VRAM space
 * and time spent copying icons. The cache must be initialized and
 * icons to be rendered must be registered in the cache before rendering.
 *
 * Basic usage:
 *
 * 1) Ensure that the cache exists using `VerifySmallIconDict`, preferably once
 * during an `Init` or `Static` function.
 * 2) Register your icon(s) using `RegisterSmallIcon`, preferably ahead of time.
 * 3) Render your icon(s) using one of the `RenderSmallIcon...` functions during a
 * `Dynamic` function.
 *
 * ~~~
 *
 * Icons are sourced from a common sheet (the `Sheet.png` file in this directory),
 * and are referred to by their index on this sheet. The sheet must be chopped
 * into individual icons before assembly. This process is not automated by
 * building GORGON-EGG: advanced users looking to edit the icon sheet must
 * manually update the chopped icons (see the `Makefile` in this directory).
 * Rather than including the graphics from the entire sheet, this system only
 * assembles selected icons, necessitating some kind of mapping between sheet
 * index and in-ROM index. Upon determining this mapping, the system caches
 * it in a dictionary. This dictionary is kept in VRAM (just before the icon graphics
 * by default) in order to avoid having to find and manage some free WRAM.
 *
 * The cache dict essentially functions as `dict[vram_icon_index] = sheet_icon_index`.
 * Since the cache is stored in VRAM, it may be wiped by other graphics drawn
 * when the GORGON-EGG window is closed, so it must be verified by modules at least
 * once when the window is redrawn. Each 'tile' occupied by the cache dict begins
 * with a magic number, and all tiles must match for the cache to be valid.
 */


// Exports
void InitializeSmallIconDict(void);
void VerifySmallIconDict(void);
void RegisterSmallIcon(u16 sheetIndex);
void RenderSmallIcon(u16 sheetIndex, int x, int y, struct PlayerInterfaceProc * proc);
void RenderSmallIcon_(u16 sheetIndex, int x, int y, int base, struct PlayerInterfaceProc * proc);
void RenderSmallIconAbsolute(u16 sheetIndex, int x, int y);
void RenderSmallIconAbsolute_(u16 sheetIndex, int x, int y, int base);


typedef s16 small_icon_entry;

struct SmallIconEntry
{
  union
  {
    s32 terminator;
    struct
    {
      u32 sheetIndex;
      u8 icon[CHR_SIZE];
    };
  };
};

extern const struct SmallIconEntry gSmallIcons[];
extern const u16 gSmallIconPalette[];
extern const u8 gSmallIconGraphics[];


#ifndef SMALLICON_PALETTE
  #define SMALLICON_PALETTE 6
#endif // SMALLICON_PALETTE

#ifndef SMALLICON_COUNT
  #define SMALLICON_COUNT (256)
#endif // SMALLICON_COUNT

#ifndef SMALLICON_DICT_TILE
  #define SMALLICON_DICT_TILE (0x340)
#endif // SMALLICON_DICT_TILE

#define SMALLICON_MAGIC (0x4547)
#define SMALLICON_DICT_TERMINATOR (-1)
#define SMALLICON_MAPPING_TERMINATOR (-1)

#define SMALLICON_DICT_SIZE ((sizeof(small_icon_entry) * SMALLICON_COUNT))
#define SMALLICON_DICT_TILE_COUNT ((SMALLICON_DICT_SIZE + (CHR_SIZE - 1)) / CHR_SIZE)
#define SMALLICON_ENTRIES_PER_TILE (CHR_SIZE / sizeof(small_icon_entry))

#define MAX_SMALLICON (SMALLICON_COUNT - 1 - SMALLICON_DICT_TILE_COUNT)

#ifndef SMALLICON_BASE_TILE
  #define SMALLICON_BASE_TILE (SMALLICON_DICT_TILE + (SMALLICON_DICT_SIZE / CHR_SIZE))
#endif // SMALLICON_BASE_TILE

#define gSmallIconDict ((small_icon_entry *)(VRAM_OBJ_ADDRESS(SMALLICON_DICT_TILE)))


void InitializeSmallIconDict(void)
{
  /* Reset the icon cache dict to a usable, empty state.
   */
  CpuFastFill16(SMALLICON_DICT_TERMINATOR, gSmallIconDict, SMALLICON_DICT_SIZE);

  for ( unsigned i = 0; i < SMALLICON_DICT_TILE_COUNT; i++ )
    gSmallIconDict[i * SMALLICON_ENTRIES_PER_TILE] = SMALLICON_MAGIC;
}


void VerifySmallIconDict(void)
{
  /* Ensure that the icon cache dict is usable, resetting if unsure.
   */
  for ( unsigned i = 0; i < SMALLICON_DICT_TILE_COUNT; i++ )
  {
    if ( gSmallIconDict[i * SMALLICON_ENTRIES_PER_TILE] != SMALLICON_MAGIC )
    {
      InitializeSmallIconDict();
      break;
    }
  }
}


static inline unsigned TrySkipMagicNumber(unsigned index)
{
  /* Adjust the current cache dict position to skip over our magic numbers.
   */
  if ( (index % SMALLICON_ENTRIES_PER_TILE) == 0 )
    index += 1;

  return index;
}


void RegisterSmallIcon(u16 sheetIndex)
{
  /* Make a small icon available to be rendered.
   *
   * This will copy the icon to VRAM and add it to the cache dict, if it
   * does not already exist.
   */

  const u8 * GetSheetIcon(u16 sheetIndex)
  {
    /* Get the ROM address of the requested icon.
     */
    unsigned i = 0;
    const struct SmallIconEntry * cur = &gSmallIcons[i];

    const u8 * offset = cur->icon;

    for ( ; cur->terminator != SMALLICON_MAPPING_TERMINATOR; cur = &gSmallIcons[++i] )
    {
      if ( cur->sheetIndex == sheetIndex )
        offset = cur->icon;
    }

    return offset;
  }

  unsigned dict_pos = 1;
  unsigned vram_pos = 0;

  // We only copy an icon if we reach the end of the cache without finding it.

  for ( ; dict_pos < MAX_SMALLICON; dict_pos += 1, vram_pos += 1 )
  {
    dict_pos = TrySkipMagicNumber(dict_pos);

    if ( gSmallIconDict[dict_pos] == sheetIndex )
      break;

    else if ( gSmallIconDict[dict_pos] == SMALLICON_DICT_TERMINATOR )
    {
      gSmallIconDict[dict_pos] = sheetIndex;
      gSmallIconDict[dict_pos + 1] = SMALLICON_DICT_TERMINATOR;

      CpuFastCopy(
          GetSheetIcon(sheetIndex),
          VRAM_OBJ_ADDRESS(SMALLICON_BASE_TILE + vram_pos),
          CHR_SIZE
        );
      break;
    }
  }
}


u16 GetSmallIconVRAMIndex(u16 sheetIndex)
{
  /* Given an icon index, return its VRAM tile index.
   *
   * The icon must have already been registered in the icon cache.
   */
  unsigned dict_pos = 1;
  unsigned vram_pos = 0;
  for ( ; dict_pos < MAX_SMALLICON; dict_pos += 1, vram_pos += 1 )
  {
    dict_pos = TrySkipMagicNumber(dict_pos);

    if ( gSmallIconDict[dict_pos] == sheetIndex )
      break;
  }

  return SMALLICON_BASE_TILE + vram_pos;
}


void RenderSmallIcon_(u16 sheetIndex, int x, int y, int base, struct PlayerInterfaceProc * proc)
{
  /* Render a small icon relative to the window, providing a base OAM2.
   *
   * Before rendering a small icon, ensure that it is registered.
   */
  struct Vec2 baseCoords = UI1_GetWindowPosition(proc);

  PushToHiOAM(
      (baseCoords.x * 8) + x,
      (baseCoords.y * 8) + y,
      &gObj_8x8,
      OAM2_CHR(GetSmallIconVRAMIndex(sheetIndex)) | base
    );
}


void RenderSmallIcon(u16 sheetIndex, int x, int y, struct PlayerInterfaceProc * proc)
{
  /* Render a small icon relative to the window.
   *
   * Before rendering a small icon, ensure that it is registered.
   */
  RenderSmallIcon_(sheetIndex, x, y, OAM2_LAYER(0) | OAM2_PAL(SMALLICON_PALETTE), proc);
}


void RenderSmallIconAbsolute_(u16 sheetIndex, int x, int y, int base)
{
  /* Render a small icon relative to the top of the screen, providing a base OAM2.
   *
   * Before rendering a small icon, ensure that it is registered.
   */

  PushToHiOAM(
      x,
      y,
      &gObj_8x8,
      OAM2_CHR(GetSmallIconVRAMIndex(sheetIndex)) | base
    );
}


void RenderSmallIconAbsolute(u16 sheetIndex, int x, int y)
{
  /* Render a small icon relative to the top of the screen.
   *
   * Before rendering a small icon, ensure that it is registered.
   */
  RenderSmallIconAbsolute_(sheetIndex, x, y, OAM2_LAYER(0) | OAM2_PAL(SMALLICON_PALETTE));
}
