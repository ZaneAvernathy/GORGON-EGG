
#include "TargetList.h"


void AddUnitToTargetListIfNotAllied(struct Unit * unit);
extern struct Unit * gSubjectUnit;


void GetTargetList_HostileAll(struct Unit * unit)
{
  /* Generate a list of targets hostile to the unit.
   */

  InitTargets(unit->xPos, unit->yPos);

  gSubjectUnit = unit;
  FOR_UNITS_ALL(target, AddUnitToTargetListIfNotAllied(target););
}
