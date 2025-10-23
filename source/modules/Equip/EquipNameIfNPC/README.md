
# EquipNameIfNPC

This module draws the unit's equipped weapon's name, but only if the unit is an NPC.

# User configuration

The `EquipName` modules share a set of definitions, assuming that most users will only have one `EquipName` module per config. These definitions begin with `EQUIP_NAME_`. If you want this module's configuration to be decoupled from the other modules, use the `EQUIP_NAME_IF_NPC_` definitions.

## Simple definitions (shared)

  * `EQUIP_NAME_X` and `EQUIP_NAME_Y`: The coordinates of the left edge of the text space in tiles
  * `EQUIP_NAME_WIDTH`: The width of the text space in tiles
  * `EQUIP_NAME_COLOR`: The color of the text, see [the text header](/template/include/Text.h)
  * `EQUIP_NAME_ALIGNMENT`: How the text is aligned. This should be one of `EquipNameAlignments`

## Simple definitions (decoupled)

  * `EQUIP_NAME_IF_NPC_X` and `EQUIP_NAME_IF_NPC_Y`: The coordinates of the left edge of the text space in tiles
  * `EQUIP_NAME_IF_NPC_WIDTH`: The width of the text space in tiles
  * `EQUIP_NAME_IF_NPC_COLOR`: The color of the text, see [the text header](/template/include/Text.h)
  * `EQUIP_NAME_IF_NPC_ALIGNMENT`: How the text is aligned. This should be one of `EquipNameAlignments`

## Other definitions

The `EquipNameAlignments` definition describes an enum for text alignment values, and generally should not be edited.
