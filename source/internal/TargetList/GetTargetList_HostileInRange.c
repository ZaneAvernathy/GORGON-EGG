
#include "TargetList.h"


s8 UnitHasMagicRank(struct Unit * unit);
int GetUnitWeaponUsabilityBits(struct Unit * unit);
void BmMapFill(u8 ** map, int value);
void GenerateUnitMovementMapExt(struct Unit * unit, s8 movement);
void GenerateMagicSealMap(int value);
void SetWorkingBmMap(u8 ** map);
void GenerateUnitCompleteAttackRange(struct Unit * unit);
void ForEachUnitInRange(void(* func)(struct Unit * unit));
void AddUnitToTargetListIfNotAllied(struct Unit * unit);

extern struct Unit * gSubjectUnit;
extern u8 ** gBmMapRange;
extern u8 ** gBmMapOther;
extern u8 ** gBmMapUnit;


void GetTargetList_HostileInRange(struct Unit * unit)
{
  /* Generate a list of hostile targets within a unit's total attack range.
   *
   * As a note, this should not be used during chapter preparations, as it
   * interferes with deployment slots.
   */

  InitTargets(unit->xPos, unit->yPos);

  if ( !(GetUnitWeaponUsabilityBits(unit) & UNIT_USEBIT_WEAPON) )
    return;

  GenerateUnitMovementMapExt(unit, UNIT_MOV(unit));
  BmMapFill(gBmMapOther, 0);

  #if defined(__FE7U__) || defined(__FE7J__) || defined(__FE8U__) || defined(__FE8J__)

  if ( UnitHasMagicRank(unit) )
    GenerateMagicSealMap(1);

  #endif // defined(__FE7U__) || defined(__FE7J__) || defined(__FE8U__) || defined(__FE8J__)

  BmMapFill(gBmMapRange, 0);

  gBmMapUnit[unit->yPos][unit->xPos] = 0;

  SetWorkingBmMap(gBmMapRange);
  GenerateUnitCompleteAttackRange(unit);

  gBmMapUnit[unit->yPos][unit->xPos] = unit->index;

  gSubjectUnit = unit;
  ForEachUnitInRange(AddUnitToTargetListIfNotAllied);
}
