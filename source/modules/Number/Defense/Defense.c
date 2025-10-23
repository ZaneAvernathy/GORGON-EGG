
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


typedef void (*number_renderer) (int number, int x, int y, u16 baseObj);
void GenericUnsignedNumberTwoDigits(int number, int x, int y, u16 baseObj, number_renderer renderer, struct PlayerInterfaceProc* proc);


#define DEF_BASE_OBJ (OAM2_CHR(DEF_BASE_TILE) | OAM2_LAYER(0) | OAM2_PAL(DEF_PALETTE))


void Defense_Dynamic(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Draws the unit's defense.
   */
  GenericUnsignedNumberTwoDigits(udp->battleDefense, DEF_X, DEF_Y, DEF_BASE_OBJ, DEF_RENDERER, proc);
  return;
}
