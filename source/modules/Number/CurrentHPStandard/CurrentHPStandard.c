
#include "gbafe.h"
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

struct Vec2 GE_GetWindowPosition(struct PlayerInterfaceProc* proc);

void DrawUnsignedSmallNumber(int number, int x, int y);


void CurrentHPStandard_Dynamic(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Draws the unit's current HP, right-aligned.
   *
   * Draws `--` if the unit's HP is over 99.
   */

  GenericNumberTwoDigits(GetUnitCurrentHp(udp->unit), CURRENT_HP_X, CURRENT_HP_Y);

  return;
}
