
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

#include <string.h>


int GetUnitItemCount(struct Unit * unit);
bool IsPrepMapActive(void);
int GetItemType(int item);


s8 CanUnitUseWeapon(struct Unit * unit, int item);
s8 CanUnitUseStaff(struct Unit * unit, int item);
s8 CanUnitUseWeaponNow(struct Unit * unit, int item);
s8 CanUnitUseStaffNow(struct Unit * unit, int item);


void VerifySmallIconDict(void);
void RenderSmallIconAbsolute_(u16 sheetIndex, int x, int y, int base);
void RegisterSmallIcon(u16 sheetIndex);
extern const u16 gSmallIconPalette[];

void GetTargetList_HostileAll(struct Unit * unit);
void GetTargetList_HostileInRange(struct Unit * unit);
void ForEachTarget(struct PlayerInterfaceProc* proc, struct UnitDataProc * udp, void (* func)(struct PlayerInterfaceProc* proc, struct UnitDataProc * udp, struct Unit * target));
void InitTargets(int, int);


#if defined(__FE7U__) || defined(__FE7J__) || defined(__FE8U__) || defined(__FE8J__)

#define CanUseWeapon CanUnitUseWeaponNow
#define CanUseStaff  CanUnitUseStaffNow

#else

#define CanUseWeapon CanUnitUseWeapon
#define CanUseStaff  CanUnitUseStaff

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


// This table maps weapon type -> icon

#define ICON_TYPE_SWORD      2
#define ICON_TYPE_LANCE      3
#define ICON_TYPE_AXE        4
#define ICON_TYPE_BOW        5
#define ICON_TYPE_STAFF      6
#define ICON_TYPE_ANIMA      7
#define ICON_TYPE_LIGHT      8
#define ICON_TYPE_DARK       9
#define ICON_TYPE_BALLISTA  30
#define ICON_TYPE_ITEM       1
#define ICON_TYPE_DRAGON   452
#define ICON_TYPE_MONSTER  464
#define ICON_TYPE_DANCE     38

static const u16 TypeIcons[] = {
    ICON_TYPE_SWORD,
    ICON_TYPE_LANCE,
    ICON_TYPE_AXE,
    ICON_TYPE_BOW,
    ICON_TYPE_STAFF,
    ICON_TYPE_ANIMA,
    ICON_TYPE_LIGHT,
    ICON_TYPE_DARK,
    ICON_TYPE_BALLISTA,
    ICON_TYPE_ITEM,
    ICON_TYPE_DRAGON,
    ICON_TYPE_MONSTER,
    ICON_TYPE_DANCE,
  };

#define TYPEICON_COUNT (sizeof(TypeIcons) / sizeof(typeof(* TypeIcons)))


void DrawTargetsInRangeWeaponTypes_Init(struct PlayerInterfaceProc * proc)
{
  /* Ensure that the icon palette is loaded.
   */
  ApplyPalette(gSmallIconPalette, OBJ_PALETTE(SMALLICON_PALETTE));
}


void DrawTargetsInRangeWeaponTypes_Static(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Ensure that our weapon type icons exist and build our target list.
   */

  VerifySmallIconDict();

  if ( IsPrepMapActive() )
    GetTargetList_HostileAll(udp->unit);

  else
    GetTargetList_HostileInRange(udp->unit);

  for ( unsigned i = 0; i < TYPEICON_COUNT; i++ )
  {
    RegisterSmallIcon(TypeIcons[i]);
  }

}


void DrawTargetsInRangeWeaponTypes_RenderIcons(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp, struct Unit * target)
{
  /* Render a single item type from a target, alternating every `PERIOD` frames.
   *
   * If `DRAW_TARGETS_IN_RANGE_INACTIVE_FRAMES` is nonzero, the icon will blink.
   * This function should be used with `ForEachTarget`.
   */

  if ( target->state & (US_HIDDEN | US_UNDER_A_ROOF | US_FOG) )
    return;

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
    u16 item = target->items[j];

    if ( CanUseWeapon(target, item) || CanUseStaff(target, item) )
    {
      u16 icon = TypeIcons[GetItemType(item)];
      RegisterSmallIcon(icon);
      AddIcon(icon);
    }
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


void DrawTargetsInRangeWeaponTypes_Dynamic(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Render all of a unit's targets' type icons.
   */

  if ( proc->hideContents )
    return;

  ForEachTarget(proc, udp, DrawTargetsInRangeWeaponTypes_RenderIcons);
}
