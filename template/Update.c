
#include "gbafe.h"
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

void GE_Dynamic(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp);

struct UnitDataProc* GetUnitDataProc(struct PlayerInterfaceProc* proc);


void GE_Update(struct PlayerInterfaceProc* proc)
{
  int cursorQuadrant;
  s8 cursorX, cursorY;
  s8 windowX, windowY;
  struct UnitDataProc* udp;

  struct Unit* unit = GetUnitAtCursor();

  proc->hoverFramecount++;

  if ( unit )
  {
    udp = GetUnitDataProc(proc);
    GE_Dynamic(proc, udp);
  }

  proc->xCursorPrevious = proc->xCursor;
  proc->yCursorPrevious = proc->yCursor;

  proc->xCursor = gGameState.cursorMapPos.x;
  proc->yCursor = gGameState.cursorMapPos.y;

  if ( (proc->xCursor == proc->xCursorPrevious) && (proc->yCursor == proc->yCursorPrevious) )
    return;

  if ( unit && !(ProcFind(gProc_CameraMovement)) )
  {
    cursorQuadrant = GetCursorQuadrant();

    cursorX = sPlayerInterfaceConfigLut[cursorQuadrant].xMinimug;
    cursorY = sPlayerInterfaceConfigLut[cursorQuadrant].yMinimug;

    windowX = sPlayerInterfaceConfigLut[proc->cursorQuadrant].xMinimug;
    windowY = sPlayerInterfaceConfigLut[proc->cursorQuadrant].yMinimug;

    if ( (cursorQuadrant == proc->cursorQuadrant) || ((cursorX == windowX) && (cursorY == windowY)) )
    {
      ProcGoto((Proc*)proc, GE_PROC_CHECK_FOR_UNIT);
      return;
    }

  }

  proc->isRetracting = TRUE;
  BreakProcLoop((Proc*)proc);

  return;
}
