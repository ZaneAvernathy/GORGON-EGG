
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


void ClearStatusAndLabelTilemaps(void);


void DrawStatus(unsigned status, unsigned duration)
{
  /* Draws the status image using FE6J's status image.
   */

  unsigned i;

  // FE6J has all of its status images already in VRAM as
  // a solid sheet.

  enum StatusImageOrder
  {
    STATUS_IMAGE_SLEEP,
    STATUS_IMAGE_POISON,
    STATUS_IMAGE_BERSERK,
    STATUS_IMAGE_SILENCE,
  };

  static const u8 StatusImageOffsets[UNIT_STATUS_MAX] = {
    [UNIT_STATUS_POISON] = STATUS_IMAGE_POISON,
    [UNIT_STATUS_SLEEP] = STATUS_IMAGE_SLEEP,
    [UNIT_STATUS_SILENCE] = STATUS_IMAGE_SILENCE,
    [UNIT_STATUS_BERSERK] = STATUS_IMAGE_BERSERK
  };

  unsigned offset = StatusImageOffsets[status] * STATUS_IMAGE_WIDTH;

  ClearStatusAndLabelTilemaps();

  for ( i = 0; i < STATUS_IMAGE_WIDTH; i++ )
    gUiTmScratchA[TILEMAP_INDEX(STATUS_X + i, STATUS_Y)] = TILEREF(STATUS_BASE_TILE + offset + i, STATUS_PALETTE);

  gUiTmScratchA[TILEMAP_INDEX(STATUS_X + STATUS_WIDTH - 1, STATUS_Y)] = TILEREF(STATUS_NUMBER_BASE_TILE + (duration % 10), STATUS_NUMBER_PALETTE);

  if ( duration >= 10 )
    gUiTmScratchA[TILEMAP_INDEX(STATUS_X + STATUS_WIDTH - 2, STATUS_Y)] = TILEREF(STATUS_NUMBER_BASE_TILE + (duration - 9), STATUS_NUMBER_PALETTE);

  return;
}
