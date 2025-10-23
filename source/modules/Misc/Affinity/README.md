
# Affinity

This module draws a unit's affinity, if they have one.

# User configuration

## Simple definitions

  * `AFFINITY_X` and `AFFINITY_Y`: The coordinates of the icon in pixels
  * `AFFINITY_PAGE`: If using an 'icon rework' hack, such as one provided by the FE8 skill system, this is the index of the icon's 'page'.
  * `AFFINITY_BASE_TILE`: The VRAM tile index of the start of the graphics
  * `AFFINITY_PALETTE`: The PalRAM index of the palette

## Other definitions

The `ItemIconPalettes` definition describes an enum for values passed into the `LoadIconPalette` function, which generally should not be edited.
