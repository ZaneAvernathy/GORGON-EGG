
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


void VerifySmallIconDict(void);
void RenderSmallIcon(u16 sheetIndex, int x, int y, struct PlayerInterfaceProc * proc);
void RegisterSmallIcon(u16 sheetIndex);
extern const u16 gSmallIconPalette[];


#ifndef AVO_LABEL_X_PIXELS
  #ifdef AVO_LABEL_X
    #define AVO_LABEL_X_PIXELS (AVO_LABEL_X * 8)
  #else
    #define AVO_LABEL_X_PIXELS 8
  #endif // AVO_LABEL_X
#endif // AVO_LABEL_X_PIXELS

#ifndef AVO_LABEL_Y_PIXELS
  #ifdef AVO_LABEL_Y
    #define AVO_LABEL_Y_PIXELS (AVO_LABEL_Y * 8)
  #else
    #define AVO_LABEL_Y_PIXELS 8
  #endif // AVO_LABEL_Y
#endif // AVO_LABEL_Y_PIXELS


void AvoidLabelIcon_Init(struct PlayerInterfaceProc * proc)
{
  /* Sets up the palette for the icon.
   */
  ApplyPalette(gSmallIconPalette, OBJ_PALETTE(SMALLICON_PALETTE));
}


void AvoidLabelIcon_Static(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Verifies the icon cache and adds the icon.
   */
  VerifySmallIconDict();
  RegisterSmallIcon(ICON_LABEL_AVOID);
}


void AvoidLabelIcon_Dynamic(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Draw the icon.
   */
  if ( proc->hideContents )
    return;

  RenderSmallIcon(ICON_LABEL_AVOID, AVO_LABEL_X_PIXELS, AVO_LABEL_Y_PIXELS, proc);
}
