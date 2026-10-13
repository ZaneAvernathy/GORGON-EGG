
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"


void InitTargets(int xRoot, int yRoot);
int GetSelectTargetCount(void);
struct SelectTarget * GetTarget(int index);


void ForEachTarget(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp, void (* func)(struct PlayerInterfaceProc * proc, struct UnitDataProc * udp, struct Unit * target));


struct SelectTarget
{
  /* 00 */ s8 x, y;
  /* 02 */ s8 uid;
  /* 03 */ s8 extra;

  /* 04 */ struct SelectTarget * next;
  /* 08 */ struct SelectTarget * prev;
};
