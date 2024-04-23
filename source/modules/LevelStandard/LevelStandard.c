
#include "gbafe.h"
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

struct Vec2 GE_GetWindowPosition(struct PlayerInterfaceProc* proc);

void DrawUnsignedSmallNumber(int number, int x, int y);


void LevelStandard_Dynamic(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Draws the unit's level, right-aligned.
   */

  int level;
  struct Vec2 coords;

  if ( proc->busyFlag )
    return;

  coords = GE_GetWindowPosition(proc);
  level = udp->unit->level;

  DrawUnsignedSmallNumber(
      (level >= 100) ? 0xFF : level,
      (coords.x * 8) + LEVEL_X,
      (coords.y * 8) + LEVEL_Y
    );

  return;
}
