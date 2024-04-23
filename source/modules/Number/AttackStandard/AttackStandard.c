
#include "gbafe.h"
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

struct Vec2 GE_GetWindowPosition(struct PlayerInterfaceProc* proc);

void DrawUnsignedSmallNumber(int number, int x, int y);


void AttackStandard_Dynamic(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Draws the unit's attack, right-aligned.
   */

  int attack;
  struct Vec2 coords;

  if ( proc->busyFlag )
    return;

  coords = GE_GetWindowPosition(proc);
  attack = udp->battleAttack;

  DrawUnsignedSmallNumber(
      (attack >= 100) ? 0xFF : attack,
      (coords.x * 8) + ATK_X,
      (coords.y * 8) + ATK_Y
    );

  return;
}
