
#include "gbafe.h"
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

struct Vec2 GE_GetWindowPosition(struct PlayerInterfaceProc* proc);

void DrawUnsignedSmallNumber(int number, int x, int y);


void DefenseStandard_Dynamic(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Draws the unit's defense, right-aligned.
   */

  int defense;
  struct Vec2 coords;

  if ( proc->busyFlag )
    return;

  coords = GE_GetWindowPosition(proc);
  defense = udp->battleDefense;

  DrawUnsignedSmallNumber(
      (defense >= 100) ? 0xFF : defense,
      (coords.x * 8) + DEF_X,
      (coords.y * 8) + DEF_Y
    );

  return;
}
