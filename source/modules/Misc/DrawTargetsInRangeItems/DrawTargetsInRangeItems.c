
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

#include <string.h>


int GetItemIconId(int item);
int GetUnitItemCount(struct Unit * unit);
bool IsPrepMapActive(void);


void VerifySmallIconDict(void);
void RenderSmallIconAbsolute_(u16 sheetIndex, int x, int y, int base);
void RegisterSmallIcon(u16 sheetIndex);
extern const u16 gSmallIconPalette[];

void GetTargetList_HostileAll(struct Unit * unit);
void GetTargetList_HostileInRange(struct Unit * unit);
void ForEachTarget(struct PlayerInterfaceProc* proc, struct UnitDataProc * udp, void (* func)(struct PlayerInterfaceProc* proc, struct UnitDataProc * udp, struct Unit * target));
void InitTargets(int, int);


#if defined(__FE7U__) || defined(__FE7J__) || defined(__FE8U__) || defined(__FE8J__)

#define ITEM_ICON_START 256

#else // defined(__FE7U__) || defined(__FE7J__) || defined(__FE8U__) || defined(__FE8J__)

#define ITEM_ICON_START 512

#endif // defined(__FE7U__) || defined(__FE7J__) || defined(__FE8U__) || defined(__FE8J__)

#define ICON_MAX (UNIT_ITEM_COUNT + 1)

#ifndef DRAW_TARGETS_IN_RANGE_FRAMES_PER_ICON
  #define DRAW_TARGETS_IN_RANGE_FRAMES_PER_ICON (64)
#endif // DRAW_TARGETS_IN_RANGE_FRAMES_PER_ICON

#ifndef DRAW_TARGETS_IN_RANGE_INACTIVE_FRAMES
  #define DRAW_TARGETS_IN_RANGE_INACTIVE_FRAMES (0)
#endif // DRAW_TARGETS_IN_RANGE_INACTIVE_FRAMES

#define PERIOD (DRAW_TARGETS_IN_RANGE_FRAMES_PER_ICON)
#define ACTIVE_PERIOD (PERIOD - DRAW_TARGETS_IN_RANGE_INACTIVE_FRAMES)


void DrawTargetsInRangeItems_Init(struct PlayerInterfaceProc * proc)
{
  /* Ensure that the icon palette is loaded.
   */
  ApplyPalette(gSmallIconPalette, OBJ_PALETTE(SMALLICON_PALETTE));
}


void DrawTargetsInRangeItems_Static(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Set up the target list and icon cache.
   *
   * Chapter preparations make use of the same machinery needed by the
   * target generation stuff, so we choose to render all non-player units'
   * icons during preps instead.
   */

  VerifySmallIconDict();

  if ( IsPrepMapActive() )
    GetTargetList_HostileAll(udp->unit);

  else
    GetTargetList_HostileInRange(udp->unit);
}


void DrawTargetsInRangeItems_RenderIcons(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp, struct Unit * target)
{
  /* Render a single item from a target, alternating every `PERIOD` frames.
   *
   * If `DRAW_TARGETS_IN_RANGE_INACTIVE_FRAMES` is nonzero, the icon will blink.
   * This function should be used with `ForEachTarget`.
   */

  int x = (target->xPos * 16) - gGameState.cameraRealPos.x;
  int y = (target->yPos * 16) - gGameState.cameraRealPos.y;

  if ( x < 0 || x > DISPLAY_WIDTH )
    return;

  if ( y < 0 || y > DISPLAY_HEIGHT )
    return;

  unsigned frame = proc->hoverFramecount;

  if ( (ACTIVE_PERIOD != PERIOD) && ((frame % PERIOD) >= ACTIVE_PERIOD) )
    return;

  unsigned count = 0;
  s16 icons[ICON_MAX];
  memset(&icons, -1, sizeof(icons));

  void AddIcon(s16 icon)
  {
    /* Adds an icon to the unit's personal list of icons.
     *
     * This avoids duplicating icons.
     */

    unsigned i = 0;

    if ( (count + 1) == ICON_MAX )
      return;

    for ( ; i < count; i++ )
      if ( icon == icons[i] )
        return;

    icons[i] = icon;
    count++;
  }

  for ( unsigned j = 0; j < GetUnitItemCount(target); j++ )
  {
    u16 icon = ITEM_ICON_START + GetItemIconId(target->items[j]);
    RegisterSmallIcon(icon);
    AddIcon(icon);
  }

  if ( count == 0 )
    return;

  unsigned index = (frame / (PERIOD)) % count;

  RenderSmallIconAbsolute_(
      icons[index],
      x,
      y + 7,
      OAM2_LAYER(2) | OAM2_PAL(SMALLICON_PALETTE)
    );
}


void DrawTargetsInRangeItems_Dynamic(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Render all of a unit's targets' icons.
   */

  if ( proc->hideContents )
    return;

  ForEachTarget(proc, udp, DrawTargetsInRangeItems_RenderIcons);
}
