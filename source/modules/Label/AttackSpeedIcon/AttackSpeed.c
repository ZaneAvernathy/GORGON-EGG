
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


void VerifySmallIconDict(void);
void RenderSmallIcon(u16 sheetIndex, int x, int y, struct PlayerInterfaceProc * proc);
void RegisterSmallIcon(u16 sheetIndex);
extern const u16 gSmallIconPalette[];


#ifndef AS_LABEL_X_PIXELS
  #ifdef AS_LABEL_X
    #define AS_LABEL_X_PIXELS (AS_LABEL_X * 8)
  #else
    #define AS_LABEL_X_PIXELS 8
  #endif // AS_LABEL_X
#endif // AS_LABEL_X_PIXELS

#ifndef AS_LABEL_Y_PIXELS
  #ifdef AS_LABEL_Y
    #define AS_LABEL_Y_PIXELS (AS_LABEL_Y * 8)
  #else
    #define AS_LABEL_Y_PIXELS 8
  #endif // AS_LABEL_Y
#endif // AS_LABEL_Y_PIXELS


void AttackSpeedLabelIcon_Init(struct PlayerInterfaceProc * proc)
{
  /* Sets up the palette for the icon.
   */
  ApplyPalette(gSmallIconPalette, OBJ_PALETTE(SMALLICON_PALETTE));
}


void AttackSpeedLabelIcon_Static(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Verifies the icon cache and adds the icon.
   */
  VerifySmallIconDict();
  RegisterSmallIcon(ICON_LABEL_ATTACK_SPEED);
}


void AttackSpeedLabelIcon_Dynamic(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp)
{
  /* Draw the icon.
   */
  if ( proc->hideContents )
    return;

  RenderSmallIcon(ICON_LABEL_ATTACK_SPEED, AS_LABEL_X_PIXELS, AS_LABEL_Y_PIXELS, proc);
}
