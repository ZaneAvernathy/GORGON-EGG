
#include "TargetList.h"


void ForEachTarget(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp, void (* func)(struct PlayerInterfaceProc* proc, struct UnitDataProc * udp, struct Unit * target))
{
  /* Run a function on each target within a target list.
   *
   * The target list must be built before calling this function.
   */
  unsigned count = GetSelectTargetCount();

  if ( count == 0 )
    return;

  for ( unsigned i = 0; i < count; i++ )
  {
    func(proc, udp, GetUnit(GetTarget(i)->uid));
  }
}

