
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


extern u8 gStatusImage[];
void ClearStatusAndLabelTilemaps(void);


void DrawStatus(unsigned status, unsigned duration)
{
  /* Draws the status image using FE8's status images.
   */
  unsigned i;
  unsigned offset;

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
    [UNIT_STATUS_SLEEP] = STATUS_IMAGE_SLEEP,
    [UNIT_STATUS_POISON] = STATUS_IMAGE_POISON,
    [UNIT_STATUS_SILENCE] = STATUS_IMAGE_SILENCE,
    [UNIT_STATUS_BERSERK] = STATUS_IMAGE_BERSERK,
    [UNIT_STATUS_ATTACK] = STATUS_IMAGE_ATTACK,
    [UNIT_STATUS_DEFENSE] = STATUS_IMAGE_DEFENSE,
    [UNIT_STATUS_CRIT] = STATUS_IMAGE_CRIT,
    [UNIT_STATUS_AVOID] = STATUS_IMAGE_AVOID,
    [UNIT_STATUS_PETRIFY] = STATUS_IMAGE_PETRIFY,
    [UNIT_STATUS_PETRIFY_BY_ALLY] = STATUS_IMAGE_PETRIFY,
  };

  switch ( status )
  {

  case UNIT_STATUS_NONE:
  case UNIT_STATUS_SICK:
  case UNIT_STATUS_GORGON_EGG:
  case UNIT_STATUS_GREAT_SHIELD_PROC:
    return;

  default:
    break;

  }

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
