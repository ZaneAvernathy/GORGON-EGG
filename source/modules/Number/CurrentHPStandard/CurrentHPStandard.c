
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

  int currentHP;
  struct Vec2 coords;

  if ( proc->busyFlag )
    return;

  coords = GE_GetWindowPosition(proc);
  currentHP = GetUnitCurrentHp(udp->unit);

  DrawUnsignedSmallNumber(
      (currentHP >= 100) ? 0xFF : currentHP,
      (coords.x * 8) + CURRENT_HP_X,
      (coords.y * 8) + CURRENT_HP_Y
    );

  return;
}
