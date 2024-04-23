
#include "gbafe.h"
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

#ifndef EXTEND_CALLS
  /* This dummy macro will have its definition replaced
   * with a series of calls of the form
   * SomeFunction(proc);
   * for each <Extend> tag in a module.
   * Generally, there should be exactly one
   * (from whatever handles extending/retracting).
   */
  #define EXTEND_CALLS
  #endif // EXTEND_CALLS


void GE_Extend(struct PlayerInterfaceProc* proc)
{
  /* Extend the window every cycle.
   *
   * This handles extending the window every cycle. It
   * is up to the `EXTEND_CALLS` function(s) to increment
   * the proc's `movementFrame` and break the current
   * proc loop upon finishing the extension.
   */

  EXTEND_CALLS;

  return;
}
