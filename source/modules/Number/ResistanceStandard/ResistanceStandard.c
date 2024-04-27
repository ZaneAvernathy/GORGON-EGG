
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

  GenericNumberTwoDigits(udp->unit->res, RES_X, RES_Y);

  return;
}
