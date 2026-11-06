
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


void VerifySmallIconDict(void);
void RenderSmallIcon(u16 sheetIndex, int x, int y, struct PlayerInterfaceProc * proc);
void RegisterSmallIcon(u16 sheetIndex);
extern const u16 gSmallIconPalette[];


#ifndef ATK_LABEL_X_PIXELS
  #ifdef ATK_LABEL_X
    #define ATK_LABEL_X_PIXELS (ATK_LABEL_X * 8)
  #else
    #define ATK_LABEL_X_PIXELS 8
  #endif // ATK_LABEL_X
#endif // ATK_LABEL_X_PIXELS

#ifndef ATK_LABEL_Y_PIXELS
  #ifdef ATK_LABEL_Y
    #define ATK_LABEL_Y_PIXELS (ATK_LABEL_Y * 8)
  #else
    #define ATK_LABEL_Y_PIXELS 8
  #endif // ATK_LABEL_Y
#endif // ATK_LABEL_Y_PIXELS


void AttackLabelIcon_Init(struct PlayerInterfaceProc * proc)
{
  /* Sets up the palette for the icon.
   */
  ApplyPalette(gSmallIconPalette, OBJ_PALETTE(SMALLICON_PALETTE));
}


void AttackLabelIcon_Static(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Verifies the icon cache and adds the icon.
   */
  VerifySmallIconDict();
  RegisterSmallIcon(ICON_LABEL_ATTACK);
}


void AttackLabelIcon_Dynamic(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Draw the icon.
   */
  if ( proc->hideContents )
    return;

  RenderSmallIcon(ICON_LABEL_ATTACK, ATK_LABEL_X_PIXELS, ATK_LABEL_Y_PIXELS, proc);
}
