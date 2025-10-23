
# FullInventoryFirstFixed

This module draws a unit's items. Their first item is always shown, while any remaining items are shown in a different position, alternating regularly.

# User configuration

If `INVENTORY_ICON_2_X` and `INVENTORY_ICON_2_Y` are not specified, the alternating icons are drawn 16 pixels to the right of the first icon.

## Simple definitions

  * `INVENTORY_ICON_X` and `INVENTORY_ICON_Y`: The coordinates of the first icon in pixels
  * `INVENTORY_ICON_BASE_TILE`: The VRAM tile index of the start of the icon graphics
  * `INVENTORY_ICON_PALETTE`: The PalRAM index of the palette
  * `INVENTORY_ALTERNATE_FRAMES`: The number of frames to pause on each item
  * `ITEM_ICON_PAGE`: If using an 'icon rework' hack, such as one provided by the FE8 skill system, this is the index of the icon's 'page'.
  * `INVENTORY_ICON_2_X` and `INVENTORY_ICON_2_Y`: The coordinates of the alternating icons in pixels

## Other definitions

The `ItemIconPalettes` definition describes an enum for values passed into the `LoadIconPalette` function, which generally should not be edited.
