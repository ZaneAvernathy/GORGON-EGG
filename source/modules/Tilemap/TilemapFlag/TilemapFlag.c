
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

extern const u16 UI1Tilemap_1[];
extern const u16 UI1AlternateTilemap_1[];


bool CheckFlag(int flag);
void TileMap_Apply(u16* tilemap, const void* tsa, int tileref);

extern u16 gPal_PlayerInterface_Blue[];
extern u16 gPal_PlayerInterface_Red[];
extern u16 gPal_PlayerInterface_Green[];


void GetTilemapPalette(struct Unit* unit, int paletteID)
{
  /* Get a tilemap palette based on unit faction.
   */

  u16* palette = NULL;

  switch ( UNIT_FACTION(unit) )
  {
    case FACTION_BLUE:
      palette = gPal_PlayerInterface_Blue;
      break;

    case FACTION_RED:
      palette = gPal_PlayerInterface_Red;
      break;

    case FACTION_GREEN:
      palette = gPal_PlayerInterface_Green;
      break;

    default:
      palette = gPal_PlayerInterface_Blue;
      break;

  }
  ApplyPalette(palette, BG_PALETTE(paletteID));

  return;
}


unsigned GetTilemapWidth(void)
{
  if ( CheckFlag(ALTERNATE_TILEMAP_FLAG) )
    return UI1_ALTERNATE_WIDTH;

  else
    return UI1_BASE_WIDTH;
}


unsigned GetTilemapHeight(void)
{
  if ( CheckFlag(ALTERNATE_TILEMAP_FLAG) )
    return UI1_ALTERNATE_HEIGHT;

  else
    return UI1_BASE_HEIGHT;
}


void TilemapFlag_Static(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Copy the tilemap and its palette.
   *
   * Copies a different tilemap if a specific flag is set.
   */

  const u16* tilemap;

  if ( CheckFlag(ALTERNATE_TILEMAP_FLAG) )
    tilemap = UI1AlternateTilemap_1;

  else
    tilemap = UI1Tilemap_1;

  TileMap_Apply(gUiTmScratchB, tilemap, TILEREF(0, UI1_TILEMAP_PALETTE));
  GetTilemapPalette(udp->unit, UI1_TILEMAP_PALETTE);

  return;
}
