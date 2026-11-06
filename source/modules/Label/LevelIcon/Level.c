
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


void VerifySmallIconDict(void);
void RenderSmallIcon(u16 sheetIndex, int x, int y, struct PlayerInterfaceProc * proc);
void RegisterSmallIcon(u16 sheetIndex);
extern const u16 gSmallIconPalette[];


#ifndef LVL_LABEL_X_PIXELS
  #ifdef LVL_LABEL_X
    #define LVL_LABEL_X_PIXELS (LVL_LABEL_X * 8)
  #else
    #define LVL_LABEL_X_PIXELS 8
  #endif // LVL_LABEL_X
#endif // LVL_LABEL_X_PIXELS

#ifndef LVL_LABEL_Y_PIXELS
  #ifdef LVL_LABEL_Y
    #define LVL_LABEL_Y_PIXELS (LVL_LABEL_Y * 8)
  #else
    #define LVL_LABEL_Y_PIXELS 8
  #endif // LVL_LABEL_Y
#endif // LVL_LABEL_Y_PIXELS


void LevelLabelIcon_Init(struct PlayerInterfaceProc * proc)
{
  /* Sets up the palette for the icon.
   */
  ApplyPalette(gSmallIconPalette, OBJ_PALETTE(SMALLICON_PALETTE));
}


void LevelLabelIcon_Static(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Verifies the icon cache and adds the icon.
   */
  VerifySmallIconDict();
  RegisterSmallIcon(ICON_LABEL_LEVEL);
}


void LevelLabelIcon_Dynamic(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Draw the icon.
   */
  if ( proc->hideContents )
    return;

  RenderSmallIcon(ICON_LABEL_LEVEL, LVL_LABEL_X_PIXELS, LVL_LABEL_Y_PIXELS, proc);
}
