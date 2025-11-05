
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


typedef void (*number_renderer) (int number, int x, int y, u16 baseObj);
void GenericUnsignedNumberThreeDigits(int number, int x, int y, u16 baseObj, number_renderer renderer, struct PlayerInterfaceProc* proc);
void RegisterTileGraphics(const void* source, void* target, unsigned size);
int GetUnitResistance(struct Unit* unit);


extern const unsigned char* gDefenseLabel[];
extern const unsigned char* gResistanceLabel[];


#define DEF_BASE_OBJ (OAM2_CHR(DEF_BASE_TILE) | OAM2_LAYER(0) | OAM2_PAL(DEF_PALETTE))
#define RES_BASE_OBJ (OAM2_CHR(RES_BASE_TILE) | OAM2_LAYER(0) | OAM2_PAL(RES_PALETTE))


// These definitions allow for users to specify `DEF_OR_RES_X` and `DEF_OR_RES_Y`
// in tiles and have the labels/numbers automatically go to the right spot.

// By default, the numbers and labels go in the same place for both defense and resistance.

#ifdef DEF_OR_RES_X

  #ifndef DEF_LABEL_X
    #define DEF_LABEL_X DEF_OR_RES_X
  #endif // DEF_LABEL_X

  #ifndef RES_LABEL_X
    #define RES_LABEL_X DEF_OR_RES_X
  #endif // RES_LABEL_X

  #ifndef DEF_X
    #define DEF_X ((DEF_OR_RES_X * 8) + DEF_OR_RES_SPACING)
  #endif // DEF_X

  #ifndef RES_X
    #define RES_X ((DEF_OR_RES_X * 8) + DEF_OR_RES_SPACING)
  #endif // RES_X

#else // DEF_OR_RES_X

  #ifndef DEF_LABEL_X
    #define DEF_LABEL_X 1
  #endif // DEF_LABEL_X

  #ifndef RES_LABEL_X
    #define RES_LABEL_X 1
  #endif // RES_LABEL_X

  #ifndef DEF_X
    #define DEF_X 32
  #endif // DEF_X

  #ifndef RES_X
    #define RES_X 32
  #endif // RES_X

#endif // DEF_OR_RES_X

#ifdef DEF_OR_RES_Y

  #ifndef DEF_LABEL_Y
    #define DEF_LABEL_Y DEF_OR_RES_Y
  #endif // DEF_LABEL_Y

  #ifndef RES_LABEL_Y
    #define RES_LABEL_Y DEF_OR_RES_Y
  #endif // RES_LABEL_Y

  #ifndef DEF_Y
    #define DEF_Y ((DEF_OR_RES_Y * 8) + 0)
  #endif // DEF_Y

  #ifndef RES_Y
    #define RES_Y ((DEF_OR_RES_Y * 8) + 0)
  #endif // RES_Y

#else // DEF_OR_RES_Y

  #ifndef DEF_LABEL_Y
    #define DEF_LABEL_Y 1
  #endif // DEF_LABEL_Y

  #ifndef RES_LABEL_Y
    #define RES_LABEL_Y 1
  #endif // RES_LABEL_Y

  #ifndef DEF_Y
    #define DEF_Y 8
  #endif // DEF_Y

  #ifndef RES_Y
    #define RES_Y 8
  #endif // RES_Y

#endif // DEF_OR_RES_Y


void DefenseOrResistance_Init(struct PlayerInterfaceProc* proc)
{
  /* Copies the label graphics for both defense and resistance.
   */

  RegisterTileGraphics(gDefenseLabel, VRAM_ADDRESS(DEF_LABEL_BASE_TILE), (DEF_LABEL_WIDTH * CHR_SIZE));
  RegisterTileGraphics(gResistanceLabel, VRAM_ADDRESS(RES_LABEL_BASE_TILE), (RES_LABEL_WIDTH * CHR_SIZE));

  return;
}


void DefenseOrResistance_Dynamic(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Draws either the unit's defense or resistance stat and label, alternating.
   *
   * This only draws the label once every alternation.
   */

  unsigned i;
  unsigned labelX, labelY, labelWidth, labelPalette;
  u16 labelBaseTile;

  bool showResistance = ((proc->hoverFramecount / DEF_OR_RES_FRAMES) & 1);
  bool firstFrame = ((proc->hoverFramecount % DEF_OR_RES_FRAMES) == 0);

  if ( firstFrame )
  {
    if ( showResistance )
    {
      labelX = RES_LABEL_X;
      labelY = RES_LABEL_Y;
      labelWidth = RES_LABEL_WIDTH;
      labelBaseTile = RES_LABEL_BASE_TILE;
      labelPalette = RES_LABEL_PALETTE;
    }
    else
    {
      labelX = DEF_LABEL_X;
      labelY = DEF_LABEL_Y;
      labelWidth = DEF_LABEL_WIDTH;
      labelBaseTile = DEF_LABEL_BASE_TILE;
      labelPalette = DEF_LABEL_PALETTE;
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

  if ( showResistance )
    GenericUnsignedNumberThreeDigits(GetUnitResistance(udp->unit), RES_X, RES_Y, RES_BASE_OBJ, RES_RENDERER, proc);

  else
    GenericUnsignedNumberThreeDigits(udp->battleDefense, DEF_X, DEF_Y, DEF_BASE_OBJ, DEF_RENDERER, proc);

  return;
}
