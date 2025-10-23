
# EquipIcon

This module draws an icon for the unit's equipped weapon, if they have one.

# User configuration

## Simple definitions

  * `EQUIP_ICON_X` and `EQUIP_ICON_Y`: The coordinates of the icon in pixels
  * `EQUIP_ICON_PAGE`: If using an 'icon rework' hack, such as one provided by the FE8 skill system, this is the index of the icon's 'page'.
  * `EQUIP_ICON_BASE_TILE`: The VRAM tile index of the start of the icon graphics
  * `EQUIP_ICON_PALETTE`: The PalRAM index of the weapon palette

## Other definitions

The `ItemIconPalettes` definition describes an enum for values passed into the `LoadIconPalette` function, which generally should not be edited.
