
#include "gbafe.h"
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

struct Vec2 GE_GetWindowPosition(struct PlayerInterfaceProc* proc);

void DrawUnsignedSmallNumber(int number, int x, int y);


void MaxHPStandard_Dynamic(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Draws the unit's max HP, right-aligned.
   *
   * Draws `--` if the unit's HP is over 99.
   */

  GenericNumberTwoDigits(GetUnitMaxHp(udp->unit), MAX_HP_X, MAX_HP_Y)

  return;
}
