
#include "gbafe.h"
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

struct Vec2 GE_GetWindowPosition(struct PlayerInterfaceProc* proc);

void DrawUnsignedSmallNumber(int number, int x, int y);


void HitStandard_Dynamic(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Draws the unit's hit, right-aligned.
   */

  int hit;
  struct Vec2 coords;

  if ( proc->busyFlag )
    return;

  coords = GE_GetWindowPosition(proc);
  hit = udp->battleHitRate;

  DrawUnsignedSmallNumber(
      hit,
      (coords.x * 8) + HIT_X,
      (coords.y * 8) + HIT_Y
    );

  return;
}
