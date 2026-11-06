
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


void VerifySmallIconDict(void);
void RenderSmallIcon(u16 sheetIndex, int x, int y, struct PlayerInterfaceProc * proc);
void RegisterSmallIcon(u16 sheetIndex);
extern const u16 gSmallIconPalette[];


#ifndef HIT_LABEL_X_PIXELS
  #ifdef HIT_LABEL_X
    #define HIT_LABEL_X_PIXELS (HIT_LABEL_X * 8)
  #else
    #define HIT_LABEL_X_PIXELS 8
  #endif // HIT_LABEL_X
#endif // HIT_LABEL_X_PIXELS

#ifndef HIT_LABEL_Y_PIXELS
  #ifdef HIT_LABEL_Y
    #define HIT_LABEL_Y_PIXELS (HIT_LABEL_Y * 8)
  #else
    #define HIT_LABEL_Y_PIXELS 8
  #endif // HIT_LABEL_Y
#endif // HIT_LABEL_Y_PIXELS


void HitLabelIcon_Init(struct PlayerInterfaceProc * proc)
{
  /* Sets up the palette for the icon.
   */
  ApplyPalette(gSmallIconPalette, OBJ_PALETTE(SMALLICON_PALETTE));
}


void HitLabelIcon_Static(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Verifies the icon cache and adds the icon.
   */
  VerifySmallIconDict();
  RegisterSmallIcon(ICON_LABEL_HIT);
}


void HitLabelIcon_Dynamic(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Draw the icon.
   */
  if ( proc->hideContents )
    return;

  RenderSmallIcon(ICON_LABEL_HIT, HIT_LABEL_X_PIXELS, HIT_LABEL_Y_PIXELS, proc);
}
