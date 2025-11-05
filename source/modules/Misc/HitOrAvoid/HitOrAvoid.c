
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


typedef void (*number_renderer) (int number, int x, int y, u16 baseObj);
void GenericUnsignedNumberThreeDigits(int number, int x, int y, u16 baseObj, number_renderer renderer, struct PlayerInterfaceProc* proc);
void RegisterTileGraphics(const void* source, void* target, unsigned size);


extern const unsigned char* gHitLabel[];
extern const unsigned char* gAvoidLabel[];


#define HIT_BASE_OBJ (OAM2_CHR(HIT_BASE_TILE) | OAM2_LAYER(0) | OAM2_PAL(HIT_PALETTE))
#define AVO_BASE_OBJ (OAM2_CHR(AVO_BASE_TILE) | OAM2_LAYER(0) | OAM2_PAL(AVO_PALETTE))


// These definitions allow for users to specify `HIT_OR_AVO_X` and `HIT_OR_AVO_Y`
// in tiles and have the labels/numbers automatically go to the right spot.

// By default, the numbers and labels go in the same place for both hit and avoid.

#ifdef HIT_OR_AVO_X

  #ifndef HIT_LABEL_X
    #define HIT_LABEL_X HIT_OR_AVO_X
  #endif // HIT_LABEL_X

  #ifndef AVO_LABEL_X
    #define AVO_LABEL_X HIT_OR_AVO_X
  #endif // AVO_LABEL_X

  #ifndef HIT_X
    #define HIT_X ((HIT_OR_AVO_X * 8) + HIT_OR_AVO_SPACING)
  #endif // HIT_X

  #ifndef AVO_X
    #define AVO_X ((HIT_OR_AVO_X * 8) + HIT_OR_AVO_SPACING)
  #endif // AVO_X

#else // HIT_OR_AVO_X

  #ifndef HIT_LABEL_X
    #define HIT_LABEL_X 1
  #endif // HIT_LABEL_X

  #ifndef AVO_LABEL_X
    #define AVO_LABEL_X 1
  #endif // AVO_LABEL_X

  #ifndef HIT_X
    #define HIT_X 32
  #endif // HIT_X

  #ifndef AVO_X
    #define AVO_X 32
  #endif // AVO_X

#endif // HIT_OR_AVO_X

#ifdef HIT_OR_AVO_Y

  #ifndef HIT_LABEL_Y
    #define HIT_LABEL_Y HIT_OR_AVO_Y
  #endif // HIT_LABEL_Y

  #ifndef AVO_LABEL_Y
    #define AVO_LABEL_Y HIT_OR_AVO_Y
  #endif // AVO_LABEL_Y

  #ifndef HIT_Y
    #define HIT_Y ((HIT_OR_AVO_Y * 8) + 0)
  #endif // HIT_Y

  #ifndef AVO_Y
    #define AVO_Y ((HIT_OR_AVO_Y * 8) + 0)
  #endif // AVO_Y

#else // HIT_OR_AVO_Y

  #ifndef HIT_LABEL_Y
    #define HIT_LABEL_Y 1
  #endif // HIT_LABEL_Y

  #ifndef AVO_LABEL_Y
    #define AVO_LABEL_Y 1
  #endif // AVO_LABEL_Y

  #ifndef HIT_Y
    #define HIT_Y 8
  #endif // HIT_Y

  #ifndef AVO_Y
    #define AVO_Y 8
  #endif // AVO_Y

#endif // HIT_OR_AVO_Y


void HitOrAvoid_Init(struct PlayerInterfaceProc* proc)
{
  /* Copies the label graphics for both hit and avoid.
   */

  RegisterTileGraphics(gHitLabel, VRAM_ADDRESS(HIT_LABEL_BASE_TILE), (HIT_LABEL_WIDTH * CHR_SIZE));
  RegisterTileGraphics(gAvoidLabel, VRAM_ADDRESS(AVO_LABEL_BASE_TILE), (AVO_LABEL_WIDTH * CHR_SIZE));

  return;
}


void HitOrAvoid_Dynamic(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Draws either the unit's hit or avoid stat and label, alternating.
   *
   * This only draws the label once every alternation.
   */

  unsigned i;
  unsigned labelX, labelY, labelWidth, labelPalette;
  u16 labelBaseTile;

  bool showAvoid = ((proc->hoverFramecount / HIT_OR_AVO_FRAMES) & 1);
  bool firstFrame = ((proc->hoverFramecount % HIT_OR_AVO_FRAMES) == 0);

  if ( firstFrame )
  {
    if ( showAvoid )
    {
      labelX = AVO_LABEL_X;
      labelY = AVO_LABEL_Y;
      labelWidth = AVO_LABEL_WIDTH;
      labelBaseTile = AVO_LABEL_BASE_TILE;
      labelPalette = AVO_LABEL_PALETTE;
    }
    else
    {
      labelX = HIT_LABEL_X;
      labelY = HIT_LABEL_Y;
      labelWidth = HIT_LABEL_WIDTH;
      labelBaseTile = HIT_LABEL_BASE_TILE;
      labelPalette = HIT_LABEL_PALETTE;
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

  if ( showAvoid )
    GenericUnsignedNumberThreeDigits(udp->battleAvoidRate, AVO_X, AVO_Y, AVO_BASE_OBJ, AVO_RENDERER, proc);

  else
    GenericUnsignedNumberThreeDigits(udp->battleHitRate, HIT_X, HIT_Y, HIT_BASE_OBJ, HIT_RENDERER, proc);

  return;
}
