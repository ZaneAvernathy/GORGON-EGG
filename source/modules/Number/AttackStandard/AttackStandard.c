
#include "gbafe.h"
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

struct Vec2 GE_GetWindowPosition(struct PlayerInterfaceProc* proc);

void DrawUnsignedSmallNumber(int number, int x, int y);


void AttackStandard_Dynamic(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Draws the unit's attack, right-aligned.
   */

  GenericNumberTwoDigits(udp->battleAttack, ATK_X, ATK_Y);

  return;
}
