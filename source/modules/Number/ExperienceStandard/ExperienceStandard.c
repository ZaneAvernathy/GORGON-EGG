
#include "gbafe.h"
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

struct Vec2 GE_GetWindowPosition(struct PlayerInterfaceProc* proc);

void DrawUnsignedSmallNumber(int number, int x, int y);


void ExperienceStandard_Dynamic(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Draws the unit's experience, right-aligned.
   */

  int experience;
  struct Vec2 coords;

  if ( proc->busyFlag )
    return;

  coords = GE_GetWindowPosition(proc);
  experience = udp->unit->exp;

  DrawUnsignedSmallNumber(
      (experience >= 100) ? 0xFF : experience,
      (coords.x * 8) + EXP_X,
      (coords.y * 8) + EXP_Y
    );

  return;
}
