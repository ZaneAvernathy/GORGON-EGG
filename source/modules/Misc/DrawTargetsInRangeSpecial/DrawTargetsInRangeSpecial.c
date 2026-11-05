
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

#include <string.h>


int GetItemIconId(int item);
int GetUnitItemCount(struct Unit * unit);
bool IsPrepMapActive(void);
bool IsUnitEffectiveAgainst(struct Unit * unit, struct Unit * target);
bool IsItemEffectiveAgainst(u16 item, struct Unit * unit);
int GetItemAttributes(int item);
int GetItemType(int item);
int GetItemWeaponEffect(int item);
bool IsItemStealable(int item);


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

#define ICON_NONE (-1)
#define MODIFIER_NONE (-1)


#define ICON_TYPE_SWORD      2
#define ICON_TYPE_LANCE      3
#define ICON_TYPE_AXE        4
#define ICON_TYPE_BOW        5
#define ICON_TYPE_STAFF      6
#define ICON_TYPE_ANIMA      7
#define ICON_TYPE_LIGHT      8
#define ICON_TYPE_DARK       9
#define ICON_TYPE_BALLISTA  30
#define ICON_TYPE_ITEM      84
#define ICON_TYPE_DRAGON   452
#define ICON_TYPE_MONSTER  464
#define ICON_TYPE_DANCE     38

#define ICON_DOWN_ARROW     16
#define ICON_EXCLAIMATION   22

#define ICON_HORSE         385
#define ICON_ARMOR          66
#define ICON_FLYING        386
#define ICON_DRAGON        387

#define ICON_KEY            81
#define ICON_TORCH          82
#define ICON_ITEM           84
#define ICON_FILLI_SHIELD   74
#define ICON_HOPLON_GUARD   75
#define ICON_BRAVE          59
#define ICON_DROPPABLE       1

#define ICON_STATUS_POISON            32
#define ICON_STATUS_SLEEP             33
#define ICON_STATUS_SILENCE           34
#define ICON_STATUS_BERSERK           35
#define ICON_STATUS_ATTACK            36
#define ICON_STATUS_DEFENSE           37
#define ICON_STATUS_CRIT              38
#define ICON_STATUS_AVOID             39
#define ICON_STATUS_SICK              40
#define ICON_STATUS_GORGON_EGG        41
#define ICON_STATUS_PETRIFY           42
#define ICON_STATUS_GREAT_SHIELD_PROC 43
#define ICON_STATUS_PETRIFY_BY_ALLY   44

#define ICON_WARNING 48


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


static const u16 MiscIcons[] = {
    ICON_DOWN_ARROW,
    ICON_EXCLAIMATION,
    ICON_HORSE,
    ICON_ARMOR,
    ICON_FLYING,
    ICON_DRAGON,
    ICON_KEY,
    ICON_TORCH,
    ICON_ITEM,
    ICON_FILLI_SHIELD,
    ICON_HOPLON_GUARD,
    ICON_BRAVE,
    ICON_DROPPABLE,
    ICON_STATUS_POISON,
    ICON_STATUS_SLEEP,
    ICON_STATUS_SILENCE,
    ICON_STATUS_BERSERK,
    ICON_STATUS_ATTACK,
    ICON_STATUS_DEFENSE,
    ICON_STATUS_CRIT,
    ICON_STATUS_AVOID,
    ICON_STATUS_SICK,
    ICON_STATUS_GORGON_EGG,
    ICON_STATUS_PETRIFY,
    ICON_STATUS_GREAT_SHIELD_PROC,
    ICON_STATUS_PETRIFY_BY_ALLY,
    ICON_WARNING,
};

#define MISCICON_COUNT (sizeof(MiscIcons) / sizeof(typeof(* MiscIcons)))


void DrawTargetsInRangeSpecial_Init(struct PlayerInterfaceProc* proc)
{
  /* Ensure that the icon palette is loaded.
   */
  ApplyPalette(gSmallIconPalette, OBJ_PALETTE(SMALLICON_PALETTE));
}


void DrawTargetsInRangeSpecial_Static(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
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

  for ( unsigned i = 0; i < TYPEICON_COUNT; i++ )
    RegisterSmallIcon(TypeIcons[i]);

  for ( unsigned i = 0; i < MISCICON_COUNT; i++ )
    RegisterSmallIcon(MiscIcons[i]);
}


void DrawTargetsInRangeSpecial_RenderIcons(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp, struct Unit * target)
{
  /* Render a single icon from a target, alternating every `PERIOD` frames.
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
  s16 modifiers[ICON_MAX];
  memset(&icons, ICON_NONE, sizeof(icons));
  memset(&modifiers, MODIFIER_NONE, sizeof(modifiers));

  void AddIcon_(s16 icon, s16 modifier)
  {
    /* Adds an icon to the unit's personal list of icons.
     *
     * This avoids duplicating icons.
     */

    unsigned i = 0;

    if ( (count + 1) == ICON_MAX )
      return;

    for ( ; i < count; i++ )
      if ( (icon == icons[i]) && (modifier == modifiers[i]) )
        return;

    icons[i] = icon;
    modifiers[i] = modifier;
    count++;
  }

  #define AddIcon(icon) AddIcon_((icon), MODIFIER_NONE)

  static const s16 TriangleReverseAssociation[] = {
    [ITYPE_SWORD]    = ICON_TYPE_LANCE,
    [ITYPE_LANCE]    = ICON_TYPE_AXE,
    [ITYPE_AXE]      = ICON_TYPE_SWORD,
    [ITYPE_BOW]      = ICON_NONE,
    [ITYPE_STAFF]    = ICON_NONE,
    [ITYPE_ANIMA]    = ICON_TYPE_DARK,
    [ITYPE_LIGHT]    = ICON_TYPE_ANIMA,
    [ITYPE_DARK]     = ICON_TYPE_LIGHT,
    [ITYPE_BALLISTA] = ICON_NONE,
    [ITYPE_ITEM]     = ICON_NONE,
    [ITYPE_DRAGON]   = ICON_NONE,
    [ITYPE_MONSTER]  = ICON_NONE,
    [ITYPE_DANCE]    = ICON_NONE,
  };

  // Here's a breakdown of how icons are drawn:

  // If the unit has a weapon and that unit is inherently effective against
  // the selected unit, draw a warning icon

  // Then, for each item that the unit has, draw an icon if the item:
  //   Is a usable weapon, and it:
  //     Is effective against the selected unit
  //     Is brave
  //     Reverses the weapon triangle
  //     Has a status effect
  //   Is a usable staff, and it:
  //     Inflicts a status
  //   Negates crits
  //   Negates flying effectiveness
  //   Is a torch
  //   Is a key
  //   Is a dancer ring
  //   Is otherwise a stealable item (and not the last item held by a unit that drops items)

  // Finally, if the unit is set to drop their last item, draw an icon

  if ( (GetUnitEquippedWeaponSlot(target) != -1) && IsUnitEffectiveAgainst(target, udp->unit) )
    AddIcon(ICON_WARNING);

  unsigned item_count = GetUnitItemCount(target);
  unsigned idx = 0;
  u16 item = target->items[idx];

  for ( ; idx < item_count; item = target->items[++idx] )
  {
    int attributes = GetItemAttributes(item);

    if ( CanUseWeapon(target, item) )
    {
      if ( IsItemEffectiveAgainst(item, udp->unit) )
        AddIcon(ICON_WARNING);

      if ( attributes & IA_BRAVE )
        AddIcon(ICON_BRAVE);

      if ( attributes & IA_INVERT_TRIANGLE )
      {
        s16 icon = TriangleReverseAssociation[GetItemType(item)];
        if ( icon != ICON_NONE )
          AddIcon_(icon, ICON_DOWN_ARROW);
      }

      switch ( GetItemWeaponEffect(item) )
      {
      case WPN_EFFECT_POISON:
        AddIcon(ICON_STATUS_POISON);
        break;

      case WPN_EFFECT_PETRIFY:
        AddIcon(ICON_STATUS_PETRIFY);
        break;
      }
    }

    if ( CanUseStaff(target, item) )
    {

      switch ( ITEM_INDEX(item) )
      {
      case ITEM_STAFF_SILENCE:
        AddIcon(ICON_STATUS_SILENCE);
        break;

      case ITEM_STAFF_SLEEP:
        AddIcon(ICON_STATUS_SLEEP);
        break;

      case ITEM_STAFF_BERSERK:
        AddIcon(ICON_STATUS_BERSERK);
        break;
      }
    }

    if ( attributes & IA_DELPHI_SHIELD )
      AddIcon(ICON_FILLI_SHIELD);

    #if defined(__FE7U__) || defined(__FE7J__) || defined(__FE8U__) || defined(__FE8J__)

    if ( attributes & IA_IRON_RUNE )
      AddIcon(ICON_HOPLON_GUARD);

    #endif // defined(__FE7U__) || defined(__FE7J__) || defined(__FE8U__) || defined(__FE8J__)

    switch ( ITEM_INDEX(item) )
    {
    case ITEM_TORCH:
      AddIcon(ICON_TORCH);
      break;

    case ITEM_CHESTKEY:
    case ITEM_DOORKEY:

    #if defined(__FE6J__)

    case ITEM_BRIDGEKEY:

    #endif // defined(__FE6J__)

    #if defined(__FE7U__) || defined(__FE7J__) || defined(__FE8U__) || defined(__FE8J__)

    case ITEM_CHESTKEY_BUNDLE:

    #endif // defined(__FE7U__) || defined(__FE7J__) || defined(__FE8U__) || defined(__FE8J__)

      AddIcon(ICON_KEY);
      break;

    #if defined(__FE7U__) || defined(__FE7J__) || defined(__FE8U__) || defined(__FE8J__)

    case ITEM_FILLAS_MIGHT:
    case ITEM_NINISS_GRACE:
    case ITEM_THORS_IRE:
    case ITEM_SETS_LITANY:
      AddIcon(ICON_TYPE_DANCE);
      break;

    #endif // defined(__FE7U__) || defined(__FE7J__) || defined(__FE8U__) || defined(__FE8J__)

    default:
      if ( IsItemStealable(item) )
      {
        if ( (UNIT_FACTION(target) == FACTION_RED) || (UNIT_CATTRIBUTES(udp->unit) & CA_THIEF) )
        {
          // We want to avoid drawing an icon for stealable items if the unit
          // would otherwise be dropping it as their `drop last item` slot.

          #if defined(__FE7U__) || defined(__FE7J__) || defined(__FE8U__) || defined(__FE8J__)

          if ( !(target->state & US_DROP_ITEM) )
          {
            AddIcon(ICON_ITEM);
          }
          else
          {
            if ( (idx + 1) != item_count )
            {
              AddIcon(ICON_ITEM);
            }
          }

          #else

          AddIcon(ICON_ITEM);

          #endif // defined(__FE7U__) || defined(__FE7J__) || defined(__FE8U__) || defined(__FE8J__)

        }
      }
      break;
    }
  }

  #if defined(__FE7U__) || defined(__FE7J__) || defined(__FE8U__) || defined(__FE8J__)

  if ( target->state & US_DROP_ITEM )
    AddIcon(ICON_DROPPABLE);

  #endif // defined(__FE7U__) || defined(__FE7J__) || defined(__FE8U__) || defined(__FE8J__)

  if ( count == 0 )
    return;

  unsigned index = (frame / (PERIOD)) % count;

  if ( modifiers[index] != MODIFIER_NONE )
    RenderSmallIconAbsolute_(
        modifiers[index],
        x,
        y + 7,
        OAM2_LAYER(2) | OAM2_PAL(SMALLICON_PALETTE)
      );

  RenderSmallIconAbsolute_(
      icons[index],
      x,
      y + 7,
      OAM2_LAYER(2) | OAM2_PAL(SMALLICON_PALETTE)
    );
}


void DrawTargetsInRangeSpecial_Dynamic(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  if ( proc->hideContents )
    return;

  ForEachTarget(proc, udp, DrawTargetsInRangeSpecial_RenderIcons);
}
