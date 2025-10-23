
# HPBarStandard

This module draws an HP bar similarly to the vanilla HP bar. Unlike the vanilla bar, it does not alternate between the bar and a unit's status, if they have one.

# User configuration

This uses the `DrawBarStandard` internal file, and by default shares graphics/palette with other bars.

This uses the bar graphics and palette that are already in VRAM/PalRAM at the time of window creation. You can use the `ReplaceBarGraphics` module to change the graphics/palette that is used for bars.

## Simple definitions

  * `HPBAR_X` and `HPBAR_Y`: Coordinates of the bar in tiles
  * `HPBAR_WIDTH`: The width of the bar in tiles
  * `HPBAR_BASE_TILE`: The VRAM tile index of the start of the bar graphics
  * `HPBAR_PALETTE`: The PalRAM index of the palette
