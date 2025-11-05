
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


typedef void (*number_renderer) (int number, int x, int y, u16 baseObj);
void GenericUnsignedNumberTwoDigits(int number, int x, int y, u16 baseObj, number_renderer renderer, struct PlayerInterfaceProc* proc);
int GetUnitCurrentHp(struct Unit* unit);
int GetUnitMaxHp(struct Unit* unit);


void DrawStatus(unsigned status, unsigned duration);


#define CURRENT_HP_BASE_OBJ (OAM2_CHR(CURRENT_HP_BASE_TILE) | OAM2_LAYER(0) | OAM2_PAL(CURRENT_HP_PALETTE))
#define MAX_HP_BASE_OBJ (OAM2_CHR(MAX_HP_BASE_TILE) | OAM2_LAYER(0) | OAM2_PAL(MAX_HP_PALETTE))

#define BLANK_TILE TILEREF(0, 0)


void ClearStatusAndLabelTilemaps(void)
{
  unsigned i;

  for ( i = 0; i < STATUS_WIDTH; i++ )
    gUiTmScratchA[TILEMAP_INDEX(STATUS_X + i, STATUS_Y)] = BLANK_TILE;

  for ( i = 0; i < HP_LABEL_WIDTH; i++ )
    gUiTmScratchA[TILEMAP_INDEX(HP_LABEL_X + i, HP_LABEL_Y)] = BLANK_TILE;

  for ( i = 0; i < HP_DIVIDER_WIDTH; i++ )
    gUiTmScratchA[TILEMAP_INDEX(HP_DIVIDER_X + i, HP_DIVIDER_Y)] = BLANK_TILE;

  return;
}


void DrawHPLabels(void)
{
  /* Replace the status image tilemap with the HP label and divider.
   */
  unsigned i;

  ClearStatusAndLabelTilemaps();

  for ( i = 0; i < HP_LABEL_WIDTH; i++ )
    gUiTmScratchA[TILEMAP_INDEX(HP_LABEL_X + i, HP_LABEL_Y)] = TILEREF(HP_LABEL_BASE_TILE + i, HP_LABEL_PALETTE);

  for ( i = 0; i < HP_DIVIDER_WIDTH; i++ )
    gUiTmScratchA[TILEMAP_INDEX(HP_DIVIDER_X + i, HP_DIVIDER_Y)] = TILEREF(HP_DIVIDER_BASE_TILE + i, HP_DIVIDER_PALETTE);

  return;
}



void HPOrStatusStandard_Static(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Start the window out by drawing the HP label and divider.
   */

  DrawHPLabels();
  return;
}


void HPOrStatusStandard_Dynamic(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Alternates between drawing HP and status, as vanilla does.
   */
  bool hasStatus;

  bool firstFrame = ((proc->hoverFramecount % HP_OR_STATUS_FRAMES) == 0);

  unsigned status = udp->unit->statusIndex;
  unsigned duration = udp->unit->statusDuration;

  #if defined(__FE8U__) || defined(__FE8J__)

  switch ( status )
  {
  case UNIT_STATUS_NONE:
  case UNIT_STATUS_SICK:
  case UNIT_STATUS_GORGON_EGG:
  case UNIT_STATUS_GREAT_SHIELD_PROC:
    hasStatus = FALSE;
    break;

  default:
    hasStatus = TRUE;
    break;
  }

  #else // !(efined(__FE8U__) || defined(__FE8J__))

  hasStatus = (status != UNIT_STATUS_NONE);

  #endif // defined(__FE8U__) || defined(__FE8J__)

  bool showStatus = ((proc->hoverFramecount / HP_OR_STATUS_FRAMES) & 1);

  if ( firstFrame && hasStatus )
  {
    if ( showStatus )
      DrawStatus(status, duration);

    else
      DrawHPLabels();

    UI1_CopyTilemap(proc);
  }

  if ( proc->hideContents || (showStatus && hasStatus) )
    return;

  GenericUnsignedNumberTwoDigits(
      GetUnitCurrentHp(udp->unit),
      CURRENT_HP_X, CURRENT_HP_Y,
      CURRENT_HP_BASE_OBJ, CURRENT_HP_RENDERER,
      proc
    );

  GenericUnsignedNumberTwoDigits(
      GetUnitMaxHp(udp->unit),
      MAX_HP_X, MAX_HP_Y,
      MAX_HP_BASE_OBJ, MAX_HP_RENDERER,
      proc
    );

  return;
}
