
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


typedef void (*number_renderer) (int number, int x, int y, u16 baseObj);
void GenericUnsignedNumberThreeDigits(int number, int x, int y, u16 baseObj, number_renderer renderer, struct PlayerInterfaceProc* proc);


#define DOD_BASE_OBJ (OAM2_CHR(DOD_BASE_TILE) | OAM2_LAYER(0) | OAM2_PAL(DOD_PALETTE))


void Dodge_Dynamic(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Draws the unit's dodge (crit avoid).
   */
  GenericUnsignedNumberThreeDigits(udp->battleDodgeRate, DOD_X, DOD_Y, DOD_BASE_OBJ, DOD_RENDERER, proc);
  return;
}
