
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


void VerifySmallIconDict(void);
void RenderSmallIcon(u16 sheetIndex, int x, int y, struct PlayerInterfaceProc * proc);
void RegisterSmallIcon(u16 sheetIndex);
extern const u16 gSmallIconPalette[];


#ifndef DEF_LABEL_X_PIXELS
  #ifdef DEF_LABEL_X
    #define DEF_LABEL_X_PIXELS (DEF_LABEL_X * 8)
  #else
    #define DEF_LABEL_X_PIXELS 8
  #endif // DEF_LABEL_X
#endif // DEF_LABEL_X_PIXELS

#ifndef DEF_LABEL_Y_PIXELS
  #ifdef DEF_LABEL_Y
    #define DEF_LABEL_Y_PIXELS (DEF_LABEL_Y * 8)
  #else
    #define DEF_LABEL_Y_PIXELS 8
  #endif // DEF_LABEL_Y
#endif // DEF_LABEL_Y_PIXELS


void DefenseLabelIcon_Init(struct PlayerInterfaceProc * proc)
{
  /* Sets up the palette for the icon.
   */
  ApplyPalette(gSmallIconPalette, OBJ_PALETTE(SMALLICON_PALETTE));
}


void DefenseLabelIcon_Static(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Verifies the icon cache and adds the icon.
   */
  VerifySmallIconDict();
  RegisterSmallIcon(ICON_LABEL_DEFENSE);
}


void DefenseLabelIcon_Dynamic(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Draw the icon.
   */
  if ( proc->hideContents )
    return;

  RenderSmallIcon(ICON_LABEL_DEFENSE, DEF_LABEL_X_PIXELS, DEF_LABEL_Y_PIXELS, proc);
}
