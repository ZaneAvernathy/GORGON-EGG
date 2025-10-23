
# Experience

This module draws a unit's 'Experience' stat.

This module draws the stat as a two digit number, with values over 99 displaying special text.

By default, this module draws the number as right-aligned, with the position specifying the top-left position of the lowest digit in the number.

# User configuration

The precise meaning of `EXP_X` and `EXP_Y` depends on the number renderer.

By default, this shares the number graphics and palette of the other numbers. You can decouple this behavior by setting the `EXP_BASE_TILE` and `EXP_PALETTE` definitions.

## Simple definitions (shared)

  * `NUMBER_BASE_TILE`: The base tile of the number graphics in VRAM
  * `NUMBER_PALETTE`: The PalRAM index of the number palette

## Simple definitions (decoupled)

  * `EXP_X` and `EXP_Y`: The position of the number in pixels
  * `EXP_BASE_TILE`: The base tile of the number graphics in VRAM
  * `EXP_PALETTE`: The PalRAM index of the number palette

# Other definitions

The `EXP_RENDERER` definition is the name of the function responsible for rendering the number. The `EXP_RENDERER_DEFS` definition Has the declaration for the renderer as well as a flag that tells the number drawing internals that it needs a specific renderer installed.
