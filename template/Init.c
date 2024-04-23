
#include "gbafe.h"
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

#ifndef INIT_CALLS
  /* This dummy macro will have its definition replaced
   * with a series of calls of the form
   * SomeFunction(proc);
   * for each <Init> tag in a module.
   */
  #define INIT_CALLS
  #endif // INIT_CALLS

extern const struct ProcInstruction ProcUnitData[];


void GE_Init(struct PlayerInterfaceProc* proc)
{
  /* Handle first-time setup.
   */

  proc->windowQuadrant = -1;

  START_PROC(ProcUnitData, proc);

  INIT_CALLS;

  proc->movementFrame = 0;
  proc->isRetracting = FALSE;

  return;
}
