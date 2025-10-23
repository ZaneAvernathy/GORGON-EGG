
# Crit

This module draws a unit's 'Crit' stat, based on whatever their current weapon is.

This module draws the stat as a three digit number, with values over 254 displaying special text.

By default, this module draws the number as right-aligned, with the position specifying the top-left position of the lowest digit in the number.

# User configuration

The precise meaning of `CRT_X` and `CRT_Y` depends on the number renderer.

By default, this shares the number graphics and palette of the other numbers. You can decouple this behavior by setting the `CRT_BASE_TILE` and `CRT_PALETTE` definitions.

## Simple definitions (shared)

  * `NUMBER_BASE_TILE`: The base tile of the number graphics in VRAM
  * `NUMBER_PALETTE`: The PalRAM index of the number palette

## Simple definitions (decoupled)

  * `CRT_X` and `CRT_Y`: The position of the number in pixels
  * `CRT_BASE_TILE`: The base tile of the number graphics in VRAM
  * `CRT_PALETTE`: The PalRAM index of the number palette

# Other definitions

The `CRT_RENDERER` definition is the name of the function responsible for rendering the number. The `CRT_RENDERER_DEFS` definition Has the declaration for the renderer as well as a flag that tells the number drawing internals that it needs a specific renderer installed.
