
#include "gbafe.h"
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

#define EXP_LABEL_TILE0 TILEREF(EXP_LABEL_BASE_TILE, EXP_LABEL_PALETTE)
#define EXP_LABEL_TILE1 TILEREF(EXP_LABEL_BASE_TILE + 1, EXP_LABEL_PALETTE)

extern const u8 gEXPLabel[];


void ExperienceLabelStandard_Init(struct PlayerInterfaceProc* proc)
{
  /* Copies the EXP label to VRAM.
   */

  void* graphicsDest = (void*)(((int)((EXP_LABEL_BASE_TILE * CHR_SIZE) + VRAM) & 0x1FFFF) + VRAM);

  RegisterTileGraphics(gEXPLabel, graphicsDest, (2 * CHR_SIZE));

  return;
}


void ExperienceLabelStandard_Static(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Draw a label for EXP.
   */

  gUiTmScratchA[TILEMAP_INDEX(EXP_LABEL_X + 0, EXP_LABEL_Y)] = EXP_LABEL_TILE0;
  gUiTmScratchA[TILEMAP_INDEX(EXP_LABEL_X + 1, EXP_LABEL_Y)] = EXP_LABEL_TILE1;

  return;
}
