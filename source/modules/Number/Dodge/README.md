
# Dodge

This module draws a unit's 'Dodge' (critical avoid) stat, based on whatever their current weapon is.

This module draws the stat as a three digit number, with values over 254 displaying special text.

By default, this module draws the number as right-aligned, with the position specifying the top-left position of the lowest digit in the number.

# User configuration

The precise meaning of `DOD_X` and `DOD_Y` depends on the number renderer.

By default, this shares the number graphics and palette of the other numbers. You can decouple this behavior by setting the `DOD_BASE_TILE` and `DOD_PALETTE` definitions.

## Simple definitions (shared)

  * `NUMBER_BASE_TILE`: The base tile of the number graphics in VRAM
  * `NUMBER_PALETTE`: The PalRAM index of the number palette

## Simple definitions (decoupled)

  * `DOD_X` and `DOD_Y`: The position of the number in pixels
  * `DOD_BASE_TILE`: The base tile of the number graphics in VRAM
  * `DOD_PALETTE`: The PalRAM index of the number palette

# Other definitions

The `DOD_RENDERER` definition is the name of the function responsible for rendering the number. The `DOD_RENDERER_DEFS` definition Has the declaration for the renderer as well as a flag that tells the number drawing internals that it needs a specific renderer installed.
