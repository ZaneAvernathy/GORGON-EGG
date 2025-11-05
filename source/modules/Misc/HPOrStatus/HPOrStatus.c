
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


typedef void (*number_renderer) (int number, int x, int y, u16 baseObj);
void GenericUnsignedNumberTwoDigits(int number, int x, int y, u16 baseObj, number_renderer renderer, struct PlayerInterfaceProc* proc);
int GetUnitCurrentHp(struct Unit* unit);
int GetUnitMaxHp(struct Unit* unit);


extern u8 gStatusImage[];


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


void DrawStatus(unsigned status, unsigned duration)
{
  /* Draws the status image.
   */
  unsigned i, offset;

  if ( status == UNIT_STATUS_NONE )
    return;

  enum StatusImageOrder
  {
    STATUS_IMAGE_POISON,
    STATUS_IMAGE_SLEEP,
    STATUS_IMAGE_SILENCE,
    STATUS_IMAGE_BERSERK,
    STATUS_IMAGE_ATTACK,
    STATUS_IMAGE_DEFENSE,
    STATUS_IMAGE_CRIT,
    STATUS_IMAGE_AVOID,
    STATUS_IMAGE_PETRIFY,
  };

  static const u8 StatusImageOffsets[UNIT_STATUS_MAX] = {
    [UNIT_STATUS_POISON] = STATUS_IMAGE_POISON,
    [UNIT_STATUS_SLEEP] = STATUS_IMAGE_SLEEP,
    [UNIT_STATUS_SILENCE] = STATUS_IMAGE_SILENCE,
    [UNIT_STATUS_BERSERK] = STATUS_IMAGE_BERSERK,

    #if defined(__FE7U__) || defined(__FE7J__) || defined(__FE8U__) || defined(__FE8U__)

    [UNIT_STATUS_ATTACK] = STATUS_IMAGE_ATTACK,
    [UNIT_STATUS_DEFENSE] = STATUS_IMAGE_DEFENSE,
    [UNIT_STATUS_CRIT] = STATUS_IMAGE_CRIT,
    [UNIT_STATUS_AVOID] = STATUS_IMAGE_AVOID,

    #endif // defined(__FE7U__) || defined(__FE7J__) || defined(__FE8U__) || defined(__FE8U__)

    #if defined(__FE8U__) || defined(__FE8J__)

    [UNIT_STATUS_PETRIFY] = STATUS_IMAGE_PETRIFY,
    [UNIT_STATUS_PETRIFY_BY_ALLY] = STATUS_IMAGE_PETRIFY,

  #endif // defined(__FE8U__) || defined(__FE8J__)

  };

  ClearStatusAndLabelTilemaps();

  offset = StatusImageOffsets[status] * STATUS_IMAGE_WIDTH * CHR_SIZE;

  CpuFastCopy(gStatusImage + offset, VRAM_ADDRESS(STATUS_BASE_TILE), STATUS_IMAGE_WIDTH * CHR_SIZE);

  for ( i = 0; i < STATUS_IMAGE_WIDTH; i++ )
    gUiTmScratchA[TILEMAP_INDEX(STATUS_X + i, STATUS_Y)] = TILEREF(STATUS_BASE_TILE + i, STATUS_PALETTE);

  gUiTmScratchA[TILEMAP_INDEX(STATUS_X + STATUS_WIDTH - 1, STATUS_Y)] = TILEREF(STATUS_NUMBER_BASE_TILE + (duration % 10), STATUS_NUMBER_PALETTE);

  if ( duration >= 10 )
    gUiTmScratchA[TILEMAP_INDEX(STATUS_X + STATUS_WIDTH - 2, STATUS_Y)] = TILEREF(STATUS_NUMBER_BASE_TILE + (duration - 9), STATUS_NUMBER_PALETTE);

  return;
}


void HPOrStatus_Static(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Start the window out by drawing the HP label and divider.
   */

  DrawHPLabels();
  return;
}


void HPOrStatus_Dynamic(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
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
