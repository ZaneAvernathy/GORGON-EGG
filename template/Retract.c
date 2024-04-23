
#include "gbafe.h"
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

#ifndef RETRACT_CALLS
  /* This dummy macro will have its definition replaced
   * with a series of calls of the form
   * SomeFunction(proc);
   * for each <Retract> tag in a module.
   * Generally, there should be exactly one
   * (from whatever handles extending/retracting).
   */
  #define RETRACT_CALLS
  #endif // RETRACT_CALLS


void GE_Retract(struct PlayerInterfaceProc* proc)
{
  /* Retract the window every cycle.
   *
   * This handles retracting the window every cycle. It
   * is up to the `RETRACT_CALLS` function(s) to increment
   * the proc's `movementFrame` and break the current
   * proc loop upon finishing the retraction.
   */

  RETRACT_CALLS;

  return;
}
