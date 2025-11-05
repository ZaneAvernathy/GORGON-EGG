
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


typedef void (*number_renderer) (int number, int x, int y, u16 baseObj);
void GenericUnsignedNumberThreeDigits(int number, int x, int y, u16 baseObj, number_renderer renderer, struct PlayerInterfaceProc* proc);
void RegisterTileGraphics(const void* source, void* target, unsigned size);


extern const unsigned char* gCritLabel[];
extern const unsigned char* gDodgeLabel[];


#define CRT_BASE_OBJ (OAM2_CHR(CRT_BASE_TILE) | OAM2_LAYER(0) | OAM2_PAL(CRT_PALETTE))
#define DOD_BASE_OBJ (OAM2_CHR(DOD_BASE_TILE) | OAM2_LAYER(0) | OAM2_PAL(DOD_PALETTE))


// These definitions allow for users to specify `CRT_OR_DOD_X` and `CRT_OR_DOD_Y`
// in tiles and have the labels/numbers automatically go to the right spot.

// By default, the numbers and labels go in the same place for both crit and dodge.

#ifdef CRT_OR_DOD_X

  #ifndef CRT_LABEL_X
    #define CRT_LABEL_X CRT_OR_DOD_X
  #endif // CRT_LABEL_X

  #ifndef DOD_LABEL_X
    #define DOD_LABEL_X CRT_OR_DOD_X
  #endif // DOD_LABEL_X

  #ifndef CRT_X
    #define CRT_X ((CRT_OR_DOD_X * 8) + CRT_OR_DOD_SPACING)
  #endif // CRT_X

  #ifndef DOD_X
    #define DOD_X ((CRT_OR_DOD_X * 8) + CRT_OR_DOD_SPACING)
  #endif // DOD_X

#else // CRT_OR_DOD_X

  #ifndef CRT_LABEL_X
    #define CRT_LABEL_X 1
  #endif // CRT_LABEL_X

  #ifndef DOD_LABEL_X
    #define DOD_LABEL_X 1
  #endif // DOD_LABEL_X

  #ifndef CRT_X
    #define CRT_X 32
  #endif // CRT_X

  #ifndef DOD_X
    #define DOD_X 32
  #endif // DOD_X

#endif // CRT_OR_DOD_X

#ifdef CRT_OR_DOD_Y

  #ifndef CRT_LABEL_Y
    #define CRT_LABEL_Y CRT_OR_DOD_Y
  #endif // CRT_LABEL_Y

  #ifndef DOD_LABEL_Y
    #define DOD_LABEL_Y CRT_OR_DOD_Y
  #endif // DOD_LABEL_Y

  #ifndef CRT_Y
    #define CRT_Y ((CRT_OR_DOD_Y * 8) + 0)
  #endif // CRT_Y

  #ifndef DOD_Y
    #define DOD_Y ((CRT_OR_DOD_Y * 8) + 0)
  #endif // DOD_Y

#else // CRT_OR_DOD_Y

  #ifndef CRT_LABEL_Y
    #define CRT_LABEL_Y 1
  #endif // CRT_LABEL_Y

  #ifndef DOD_LABEL_Y
    #define DOD_LABEL_Y 1
  #endif // DOD_LABEL_Y

  #ifndef CRT_Y
    #define CRT_Y 8
  #endif // CRT_Y

  #ifndef DOD_Y
    #define DOD_Y 8
  #endif // DOD_Y

#endif // CRT_OR_DOD_Y


void CritOrDodge_Init(struct PlayerInterfaceProc* proc)
{
  /* Copies the label graphics for both crit and dodge.
   */

  RegisterTileGraphics(gCritLabel, VRAM_ADDRESS(CRT_LABEL_BASE_TILE), (CRT_LABEL_WIDTH * CHR_SIZE));
  RegisterTileGraphics(gDodgeLabel, VRAM_ADDRESS(DOD_LABEL_BASE_TILE), (DOD_LABEL_WIDTH * CHR_SIZE));

  return;
}


void CritOrDodge_Dynamic(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Draws either the unit's crit or dodge stat and label, alternating.
   *
   * This only draws the label once every alternation.
   */

  unsigned i;
  unsigned labelX, labelY, labelWidth, labelPalette;
  u16 labelBaseTile;

  bool showDodge = ((proc->hoverFramecount / CRT_OR_DOD_FRAMES) & 1);
  bool firstFrame = ((proc->hoverFramecount % CRT_OR_DOD_FRAMES) == 0);

  if ( firstFrame )
  {
    if ( showDodge )
    {
      labelX = DOD_LABEL_X;
      labelY = DOD_LABEL_Y;
      labelWidth = DOD_LABEL_WIDTH;
      labelBaseTile = DOD_LABEL_BASE_TILE;
      labelPalette = DOD_LABEL_PALETTE;
    }
    else
    {
      labelX = CRT_LABEL_X;
      labelY = CRT_LABEL_Y;
      labelWidth = CRT_LABEL_WIDTH;
      labelBaseTile = CRT_LABEL_BASE_TILE;
      labelPalette = CRT_LABEL_PALETTE;
    }

    for ( i = 0; i < labelWidth; i++ )
      gUiTmScratchA[TILEMAP_INDEX(labelX + i, labelY)] = TILEREF(labelBaseTile + i, labelPalette);

    if ( !(proc->hideContents) )
    {
      UI1_CopyTilemap(proc);
      EnableBgSyncByMask(BG0_SYNC_BIT);
    }
  }

  if ( proc->hideContents )
    return;

  if ( showDodge )
    GenericUnsignedNumberThreeDigits(udp->battleDodgeRate, DOD_X, DOD_Y, DOD_BASE_OBJ, DOD_RENDERER, proc);

  else
    GenericUnsignedNumberThreeDigits(udp->battleCritRate, CRT_X, CRT_Y, CRT_BASE_OBJ, CRT_RENDERER, proc);

  return;
}
