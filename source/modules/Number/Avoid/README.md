
# Avoid

This module draws a unit's 'Avoid' stat, based on whatever their current weapon is.

This module draws the stat as a three digit number, with values over 254 displaying special text.

By default, this module draws the number as right-aligned, with the position specifying the top-left position of the lowest digit in the number.

# User configuration

The precise meaning of `AVO_X` and `AVO_Y` depends on the number renderer.

By default, this shares the number graphics and palette of the other numbers. You can decouple this behavior by setting the `AVO_BASE_TILE` and `AVO_PALETTE` definitions.

## Simple definitions (shared)

  * `NUMBER_BASE_TILE`: The base tile of the number graphics in VRAM
  * `NUMBER_PALETTE`: The PalRAM index of the number palette

## Simple definitions (decoupled)

  * `AVO_X` and `AVO_Y`: The position of the number in pixels
  * `AVO_BASE_TILE`: The base tile of the number graphics in VRAM
  * `AVO_PALETTE`: The PalRAM index of the number palette

# Other definitions

The `AVO_RENDERER` definition is the name of the function responsible for rendering the number. The `AVO_RENDERER_DEFS` definition Has the declaration for the renderer as well as a flag that tells the number drawing internals that it needs a specific renderer installed.
