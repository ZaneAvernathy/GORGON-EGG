
# Defense

This module draws a unit's 'Defense' stat, based on whatever their current weapon is.

This module draws the stat as a two digit number, with values over 99 displaying special text.

By default, this module draws the number as right-aligned, with the position specifying the top-left position of the lowest digit in the number.

# User configuration

The precise meaning of `DEF_X` and `DEF_Y` depends on the number renderer.

By default, this shares the number graphics and palette of the other numbers. You can decouple this behavior by setting the `DEF_BASE_TILE` and `DEF_PALETTE` definitions.

## Simple definitions (shared)

  * `NUMBER_BASE_TILE`: The base tile of the number graphics in VRAM
  * `NUMBER_PALETTE`: The PalRAM index of the number palette

## Simple definitions (decoupled)

  * `DEF_X` and `DEF_Y`: The position of the number in pixels
  * `DEF_BASE_TILE`: The base tile of the number graphics in VRAM
  * `DEF_PALETTE`: The PalRAM index of the number palette

# Other definitions

The `DEF_RENDERER` definition is the name of the function responsible for rendering the number. The `DEF_RENDERER_DEFS` definition Has the declaration for the renderer as well as a flag that tells the number drawing internals that it needs a specific renderer installed.
