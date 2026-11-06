
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


void VerifySmallIconDict(void);
void RenderSmallIcon(u16 sheetIndex, int x, int y, struct PlayerInterfaceProc * proc);
void RegisterSmallIcon(u16 sheetIndex);
extern const u16 gSmallIconPalette[];


#ifndef CRT_LABEL_X_PIXELS
  #ifdef CRT_LABEL_X
    #define CRT_LABEL_X_PIXELS (CRT_LABEL_X * 8)
  #else
    #define CRT_LABEL_X_PIXELS 8
  #endif // CRT_LABEL_X
#endif // CRT_LABEL_X_PIXELS

#ifndef CRT_LABEL_Y_PIXELS
  #ifdef CRT_LABEL_Y
    #define CRT_LABEL_Y_PIXELS (CRT_LABEL_Y * 8)
  #else
    #define CRT_LABEL_Y_PIXELS 8
  #endif // CRT_LABEL_Y
#endif // CRT_LABEL_Y_PIXELS


void CritLabelIcon_Init(struct PlayerInterfaceProc * proc)
{
  /* Sets up the palette for the icon.
   */
  ApplyPalette(gSmallIconPalette, OBJ_PALETTE(SMALLICON_PALETTE));
}


void CritLabelIcon_Static(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Verifies the icon cache and adds the icon.
   */
  VerifySmallIconDict();
  RegisterSmallIcon(ICON_LABEL_CRIT);
}


void CritLabelIcon_Dynamic(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Draw the icon.
   */
  if ( proc->hideContents )
    return;

  RenderSmallIcon(ICON_LABEL_CRIT, CRT_LABEL_X_PIXELS, CRT_LABEL_Y_PIXELS, proc);
}
