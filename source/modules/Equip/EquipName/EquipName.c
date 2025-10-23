
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


void Text_InitDB(struct TextHandle* text, int width);
void Text_Clear(struct TextHandle* text);
int Text_GetStringTextCenteredPos(int width, const char* string);
void Text_SetParameters(struct TextHandle* text, int padding, int color);
void Text_DrawString(struct TextHandle* text, const char* string);
void Text_Display(struct TextHandle* text, u16* tilemap);
unsigned Text_GetStringTextWidth(const char* string);

char* String_ExpandNames(void);
char* GetItemName(int item);


extern const struct ProcInstruction ProcGORGON_EGG[];


struct EquipNameProc
{
  /* 00 */ PROC_FIELDS;
  /* 2C */ struct TextHandle equipText;
};

const char EquipNameProc_Name[] = "EquipName";

const struct ProcInstruction ProcEquipName[] = {
  PROC_SET_NAME(&EquipNameProc_Name),
  PROC_SLEEP(0),

  PROC_WHILE_PROC(ProcGORGON_EGG),

  PROC_END,
};


void EquipName_Static(struct PlayerInterfaceProc* proc, struct UnitDataProc* udp)
{
  /* Draws a unit's equipped weapon's name.
   */

  unsigned padding;
  char* equipString;

  struct EquipNameProc* equipProc = (struct EquipNameProc*)ProcFind(ProcEquipName);
  if ( equipProc == NULL )
  {
    equipProc = (struct EquipNameProc*)START_PROC(ProcEquipName, proc);
    Text_InitDB(&equipProc->equipText, EQUIP_NAME_BASE_WIDTH);
  }

  Text_Clear(&equipProc->equipText);

  if ( udp->weapon != 0 )
  {
    equipString = GetItemName(udp->weapon);

    #if defined(__FE7U__) || defined(__FE7J__) || defined(__FE8U__) || defined(__FE8J__)

    equipString = String_ExpandNames();

    #endif // defined(__FE7U__) || defined(__FE7J__) || defined(__FE8U__) || defined(__FE8J__)

    if ( EQUIP_NAME_BASE_ALIGNMENT == EQUIP_NAME_CENTERED )
      padding = Text_GetStringTextCenteredPos((EQUIP_NAME_BASE_WIDTH * 8), equipString);

    else if ( EQUIP_NAME_BASE_ALIGNMENT == EQUIP_NAME_LEFT_ALIGNED )
      padding = 0;

    else if ( EQUIP_NAME_BASE_ALIGNMENT == EQUIP_NAME_RIGHT_ALIGNED )
      padding = (EQUIP_NAME_BASE_WIDTH * 8) - Text_GetStringTextWidth(equipString);

    else
      padding = Text_GetStringTextCenteredPos((EQUIP_NAME_BASE_WIDTH * 8), equipString);

    Text_SetParameters(&equipProc->equipText, padding, EQUIP_NAME_BASE_COLOR);
    Text_DrawString(&equipProc->equipText, equipString);

    Text_Display(&equipProc->equipText, gUiTmScratchA + TILEMAP_INDEX(EQUIP_NAME_BASE_X, EQUIP_NAME_BASE_Y));
  }

  return;
}
