
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


void VerifySmallIconDict(void);
void RenderSmallIcon(u16 sheetIndex, int x, int y, struct PlayerInterfaceProc * proc);
void RegisterSmallIcon(u16 sheetIndex);
extern const u16 gSmallIconPalette[];


#ifndef EXP_LABEL_X_PIXELS
  #ifdef EXP_LABEL_X
    #define EXP_LABEL_X_PIXELS (EXP_LABEL_X * 8)
  #else
    #define EXP_LABEL_X_PIXELS 8
  #endif // EXP_LABEL_X
#endif // EXP_LABEL_X_PIXELS

#ifndef EXP_LABEL_Y_PIXELS
  #ifdef EXP_LABEL_Y
    #define EXP_LABEL_Y_PIXELS (EXP_LABEL_Y * 8)
  #else
    #define EXP_LABEL_Y_PIXELS 8
  #endif // EXP_LABEL_Y
#endif // EXP_LABEL_Y_PIXELS


void ExperienceLabelIcon_Init(struct PlayerInterfaceProc * proc)
{
  /* Sets up the palette for the icon.
   */
  ApplyPalette(gSmallIconPalette, OBJ_PALETTE(SMALLICON_PALETTE));
}


void ExperienceLabelIcon_Static(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Verifies the icon cache and adds the icon.
   */
  VerifySmallIconDict();
  RegisterSmallIcon(ICON_LABEL_EXPERIENCE);
}


void ExperienceLabelIcon_Dynamic(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Draw the icon.
   */
  if ( proc->hideContents )
    return;

  RenderSmallIcon(ICON_LABEL_EXPERIENCE, EXP_LABEL_X_PIXELS, EXP_LABEL_Y_PIXELS, proc);
}
