
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


extern u8 gRingStatusImage[];
void ClearStatusAndLabelTilemaps(void);


void DrawStatus(unsigned status, unsigned duration)
{
  /* Draws the status image using FE7's status images.
   */

  unsigned i;

  // FE7 has a solid sheet (as FE6J does) as part of the
  // menu graphics in VRAM, but also has an alternate sheet
  // that it copies slices of into VRAM for the new status rings.

  enum StatusImageOrder
  {
    STATUS_IMAGE_SLEEP,
    STATUS_IMAGE_POISON,
    STATUS_IMAGE_BERSERK,
    STATUS_IMAGE_SILENCE,
    STATUS_IMAGE_RING,
  };

  static const u8 StatusImageOffsets[UNIT_STATUS_MAX] = {
    [UNIT_STATUS_POISON] = STATUS_IMAGE_POISON,
    [UNIT_STATUS_SLEEP] = STATUS_IMAGE_SLEEP,
    [UNIT_STATUS_SILENCE] = STATUS_IMAGE_SILENCE,
    [UNIT_STATUS_BERSERK] = STATUS_IMAGE_BERSERK,
    [UNIT_STATUS_ATTACK] = STATUS_IMAGE_RING,
    [UNIT_STATUS_DEFENSE] = STATUS_IMAGE_RING,
    [UNIT_STATUS_CRIT] = STATUS_IMAGE_RING,
    [UNIT_STATUS_AVOID] = STATUS_IMAGE_RING
  };

  unsigned offset = StatusImageOffsets[status] * STATUS_IMAGE_WIDTH;

  if ( status >= UNIT_STATUS_ATTACK )
  {
    CpuFastCopy(
        gRingStatusImage + ((status - UNIT_STATUS_ATTACK) * STATUS_IMAGE_WIDTH * CHR_SIZE),
        VRAM_ADDRESS(STATUS_BASE_TILE + offset),
        STATUS_IMAGE_WIDTH * CHR_SIZE
      );
  }

  ClearStatusAndLabelTilemaps();

  for ( i = 0; i < STATUS_IMAGE_WIDTH; i++ )
    gUiTmScratchA[TILEMAP_INDEX(STATUS_X + i, STATUS_Y)] = TILEREF(STATUS_BASE_TILE + offset + i, STATUS_PALETTE);

  gUiTmScratchA[TILEMAP_INDEX(STATUS_X + STATUS_WIDTH - 1, STATUS_Y)] = TILEREF(STATUS_NUMBER_BASE_TILE + (duration % 10), STATUS_NUMBER_PALETTE);

  if ( duration >= 10 )
    gUiTmScratchA[TILEMAP_INDEX(STATUS_X + STATUS_WIDTH - 2, STATUS_Y)] = TILEREF(STATUS_NUMBER_BASE_TILE + (duration - 9), STATUS_NUMBER_PALETTE);

  return;
}
