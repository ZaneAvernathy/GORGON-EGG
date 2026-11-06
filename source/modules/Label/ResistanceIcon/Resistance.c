
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


void VerifySmallIconDict(void);
void RenderSmallIcon(u16 sheetIndex, int x, int y, struct PlayerInterfaceProc * proc);
void RegisterSmallIcon(u16 sheetIndex);
extern const u16 gSmallIconPalette[];


#ifndef RES_LABEL_X_PIXELS
  #ifdef RES_LABEL_X
    #define RES_LABEL_X_PIXELS (RES_LABEL_X * 8)
  #else
    #define RES_LABEL_X_PIXELS 8
  #endif // RES_LABEL_X
#endif // RES_LABEL_X_PIXELS

#ifndef RES_LABEL_Y_PIXELS
  #ifdef RES_LABEL_Y
    #define RES_LABEL_Y_PIXELS (RES_LABEL_Y * 8)
  #else
    #define RES_LABEL_Y_PIXELS 8
  #endif // RES_LABEL_Y
#endif // RES_LABEL_Y_PIXELS


void ResistanceLabelIcon_Init(struct PlayerInterfaceProc * proc)
{
  /* Sets up the palette for the icon.
   */
  ApplyPalette(gSmallIconPalette, OBJ_PALETTE(SMALLICON_PALETTE));
}


void ResistanceLabelIcon_Static(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Verifies the icon cache and adds the icon.
   */
  VerifySmallIconDict();
  RegisterSmallIcon(ICON_LABEL_RESISTANCE);
}


void ResistanceLabelIcon_Dynamic(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Draw the icon.
   */
  if ( proc->hideContents )
    return;

  RenderSmallIcon(ICON_LABEL_RESISTANCE, RES_LABEL_X_PIXELS, RES_LABEL_Y_PIXELS, proc);
}
