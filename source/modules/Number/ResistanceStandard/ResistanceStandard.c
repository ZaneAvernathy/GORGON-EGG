
#include "gbafe.h"
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

struct Vec2 GE_GetWindowPosition(struct PlayerInterfaceProc* proc);

void DrawUnsignedSmallNumber(int number, int x, int y);


void ResistanceStandard_Dynamic(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Draws the unit's resistance, right-aligned.
   *
   * As a note, this is resistance without bonuses, because it's
   * difficult to generate.
   */

  int resistance;
  struct Vec2 coords;

  if ( proc->busyFlag )
    return;

  coords = GE_GetWindowPosition(proc);
  resistance = udp->unit->res;

  DrawUnsignedSmallNumber(
      (resistance >= 100) ? 0xFF : resistance,
      (coords.x * 8) + RES_X,
      (coords.y * 8) + RES_Y
    );

  return;
}
