
# FullInventoryAlternating

This module draws a unit's items, showing each one for a number of frames before switching to the next.

# User configuration

## Simple definitions

  * `INVENTORY_ICON_X` and `INVENTORY_ICON_Y`: The coordinates of the icons in pixels
  * `INVENTORY_ICON_BASE_TILE`: The VRAM tile index of the start of the icon graphics
  * `INVENTORY_ICON_PALETTE`: The PalRAM index of the palette
  * `INVENTORY_ALTERNATE_FRAMES`: The number of frames to pause on each item
  * `ITEM_ICON_PAGE`: If using an 'icon rework' hack, such as one provided by the FE8 skill system, this is the index of the icon's 'page'.

## Other definitions

The `ItemIconPalettes` definition describes an enum for values passed into the `LoadIconPalette` function, which generally should not be edited.

By default, the currently-displayed icon is determined by
```c
i = (proc->hoverFramecount / INVENTORY_ALTERNATE_FRAMES) % itemCount;
```

but can be overridden by setting the `INVENTORY_ALTERNATE_FRAME_GETTER` to a C expression that yields a number `[0, itemCount)`.
