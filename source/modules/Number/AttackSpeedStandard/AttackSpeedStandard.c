
#include "gbafe.h"
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

struct Vec2 GE_GetWindowPosition(struct PlayerInterfaceProc* proc);

void DrawUnsignedSmallNumber(int number, int x, int y);


void AttackSpeedStandard_Dynamic(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Draws the unit's Attack Speed, right-aligned.
   */

  int attackSpeed;
  struct Vec2 coords;

  if ( proc->busyFlag )
    return;

  coords = GE_GetWindowPosition(proc);
  attackSpeed = udp->battleSpeed;

  DrawUnsignedSmallNumber(
      attackSpeed,
      (coords.x * 8) + AS_X,
      (coords.y * 8) + AS_Y
    );

  return;
}
