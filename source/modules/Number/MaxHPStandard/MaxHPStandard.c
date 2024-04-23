
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

  int maxHP;
  struct Vec2 coords;

  if ( proc->busyFlag )
    return;

  coords = GE_GetWindowPosition(proc);
  maxHP = GetUnitMaxHp(udp->unit);

  DrawUnsignedSmallNumber(
      (maxHP >= 100) ? 0xFF : maxHP,
      (coords.x * 8) + MAX_HP_X,
      (coords.y * 8) + MAX_HP_Y
    );

  return;
}
