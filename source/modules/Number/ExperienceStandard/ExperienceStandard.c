
#include "gbafe.h"
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

struct Vec2 GE_GetWindowPosition(struct PlayerInterfaceProc* proc);

void DrawUnsignedSmallNumber(int number, int x, int y);


void ExperienceStandard_Dynamic(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Draws the unit's experience, right-aligned.
   */

  GenericNumberTwoDigits(udp->unit->exp, EXP_X, EXP_Y);

  return;
}
