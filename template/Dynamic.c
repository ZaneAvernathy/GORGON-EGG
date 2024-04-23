
#include "gbafe.h"
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

#ifndef DYNAMIC_CALLS
  /* This dummy macro will have its definition replaced
   * with a series of calls of the form
   * SomeFunction(proc, udp);
   * for each <Dynamic> tag in a module.
   */
  #define DYNAMIC_CALLS
  #endif // DYNAMIC_CALLS


void GE_Dynamic(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Draw dynamic elements.
   *
   * Handles all window elements that must be
   * updated or redrawn every frame.
   */

  DYNAMIC_CALLS;

  return;
}
