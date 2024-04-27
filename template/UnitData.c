
#include "gbafe.h"
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

void BattleGenerateUiStats(struct Unit* unit, s8 itemSlot);

extern const struct ProcInstruction ProcGE[];

const char UnitDataProc_Name[] = "EGG";

const struct ProcInstruction ProcUnitData[] = {
  PROC_SET_NAME(&UnitDataProc_Name),
  PROC_SLEEP(0),

  PROC_WHILE_EXISTS(ProcGE),

  PROC_END,
};

#define BATTLE_DATA_START (offsetof(struct UnitDataProc, weapon))
#define BATTLE_DATA_SIZE  (sizeof(struct UnitDataProc) - BATTLE_DATA_START - sizeof(u32))


void ResetUnitDataProc(struct UnitDataProc* udp)
{
  /* Repopulate the unit data proc.
   */

  struct Unit* unit = GetUnitAtCursor();

  udp->unit = unit;

  BattleGenerateUiStats(unit, GetUnitEquippedWeaponSlot(unit));

  CpuFastCopy(&gBattleActor.weapon, &((u8*)udp)[BATTLE_DATA_START], BATTLE_DATA_SIZE);

}


struct UnitDataProc* GetUnitDataProc(struct PlayerInterfaceProc* proc)
{
  /* Get a proc that carries a unit's battle struct and unit data.
   *
   * If the proc hasn't already been made, it'll create one.
   */

  struct UnitDataProc* udp = (struct UnitDataProc*)Proc_Find(ProcUnitData);

  if ( udp == NULL )
  {
    udp = (struct UnitDataProc*)START_PROC(ProcUnitData, proc);

    ResetUnitDataProc(udp);
  }

  return udp;
}
