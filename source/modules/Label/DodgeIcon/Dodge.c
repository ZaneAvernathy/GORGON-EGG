
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


void VerifySmallIconDict(void);
void RenderSmallIcon(u16 sheetIndex, int x, int y, struct PlayerInterfaceProc * proc);
void RegisterSmallIcon(u16 sheetIndex);
extern const u16 gSmallIconPalette[];


#ifndef DOD_LABEL_X_PIXELS
  #ifdef DOD_LABEL_X
    #define DOD_LABEL_X_PIXELS (DOD_LABEL_X * 8)
  #else
    #define DOD_LABEL_X_PIXELS 8
  #endif // DOD_LABEL_X
#endif // DOD_LABEL_X_PIXELS

#ifndef DOD_LABEL_Y_PIXELS
  #ifdef DOD_LABEL_Y
    #define DOD_LABEL_Y_PIXELS (DOD_LABEL_Y * 8)
  #else
    #define DOD_LABEL_Y_PIXELS 8
  #endif // DOD_LABEL_Y
#endif // DOD_LABEL_Y_PIXELS


void DodgeLabelIcon_Init(struct PlayerInterfaceProc * proc)
{
  /* Sets up the palette for the icon.
   */
  ApplyPalette(gSmallIconPalette, OBJ_PALETTE(SMALLICON_PALETTE));
}


void DodgeLabelIcon_Static(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Verifies the icon cache and adds the icon.
   */
  VerifySmallIconDict();
  RegisterSmallIcon(ICON_LABEL_DODGE);
}


void DodgeLabelIcon_Dynamic(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Draw the icon.
   */
  if ( proc->hideContents )
    return;

  RenderSmallIcon(ICON_LABEL_DODGE, DOD_LABEL_X_PIXELS, DOD_LABEL_Y_PIXELS, proc);
}
