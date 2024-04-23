
#include "gbafe.h"
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

struct Vec2 GE_GetWindowPosition(struct PlayerInterfaceProc* proc);

void DrawUnsignedSmallNumber(int number, int x, int y);


void CritStandard_Dynamic(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Draws the unit's crit, right-aligned.
   */

  int crit;
  struct Vec2 coords;

  if ( proc->busyFlag )
    return;

  coords = GE_GetWindowPosition(proc);
  crit = udp->battleCritRate;

  DrawUnsignedSmallNumber(
      crit,
      (coords.x * 8) + CRT_X,
      (coords.y * 8) + CRT_Y
    );

  return;
}
