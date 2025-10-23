
# CurrentHP

This module draws a unit's 'Current HP' stat, based on whatever their current weapon is.

This module draws the stat as a two digit number, with values over 99 displaying special text.

By default, this module draws the number as right-aligned, with the position specifying the top-left position of the lowest digit in the number.

# User configuration

The precise meaning of `CURRENT_HP_X` and `CURRENT_HP_Y` depends on the number renderer.

By default, this shares the number graphics and palette of the other numbers. You can decouple this behavior by setting the `CURRENT_HP_BASE_TILE` and `CURRENT_HP_PALETTE` definitions.

## Simple definitions (shared)

  * `NUMBER_BASE_TILE`: The base tile of the number graphics in VRAM
  * `NUMBER_PALETTE`: The PalRAM index of the number palette

## Simple definitions (decoupled)

  * `CURRENT_HP_X` and `CURRENT_HP_Y`: The position of the number in pixels
  * `CURRENT_HP_BASE_TILE`: The base tile of the number graphics in VRAM
  * `CURRENT_HP_PALETTE`: The PalRAM index of the number palette

# Other definitions

The `CURRENT_HP_RENDERER` definition is the name of the function responsible for rendering the number. The `CURRENT_HP_RENDERER_DEFS` definition Has the declaration for the renderer as well as a flag that tells the number drawing internals that it needs a specific renderer installed.
