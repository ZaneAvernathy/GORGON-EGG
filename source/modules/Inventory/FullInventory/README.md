
# FullInventory

This module draws a unit's items as a horizontal row.

# User configuration

## Simple definitions

  * `INVENTORY_ICON_X` and `INVENTORY_ICON_Y`: The coordinates of the icons in pixels
  * `INVENTORY_ICON_BASE_TILE`: The VRAM tile index of the start of the icon graphics
  * `INVENTORY_ICON_PALETTE`: The PalRAM index of the palette
  * `ITEM_ICON_PAGE`: If using an 'icon rework' hack, such as one provided by the FE8 skill system, this is the index of the icon's 'page'.

## Other definitions

The `ItemIconPalettes` definition describes an enum for values passed into the `LoadIconPalette` function, which generally should not be edited.

