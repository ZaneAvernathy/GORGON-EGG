
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


void VerifySmallIconDict(void);
void RenderSmallIcon(u16 sheetIndex, int x, int y, struct PlayerInterfaceProc * proc);
void RegisterSmallIcon(u16 sheetIndex);
extern const u16 gSmallIconPalette[];


#ifndef HP_LABEL_X_PIXELS
  #ifdef HP_LABEL_X
    #define HP_LABEL_X_PIXELS (HP_LABEL_X * 8)
  #else
    #define HP_LABEL_X_PIXELS 8
  #endif // HP_LABEL_X
#endif // HP_LABEL_X_PIXELS

#ifndef HP_LABEL_Y_PIXELS
  #ifdef HP_LABEL_Y
    #define HP_LABEL_Y_PIXELS (HP_LABEL_Y * 8)
  #else
    #define HP_LABEL_Y_PIXELS 8
  #endif // HP_LABEL_Y
#endif // HP_LABEL_Y_PIXELS


void HPLabelIcon_Init(struct PlayerInterfaceProc * proc)
{
  /* Sets up the palette for the icon.
   */
  ApplyPalette(gSmallIconPalette, OBJ_PALETTE(SMALLICON_PALETTE));
}


void HPLabelIcon_Static(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Verifies the icon cache and adds the icon.
   */
  VerifySmallIconDict();
  RegisterSmallIcon(ICON_LABEL_HP);
}


void HPLabelIcon_Dynamic(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Draw the icon.
   */
  if ( proc->hideContents )
    return;

  RenderSmallIcon(ICON_LABEL_HP, HP_LABEL_X_PIXELS, HP_LABEL_Y_PIXELS, proc);
}
