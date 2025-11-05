
# DefenseOrResistance

This module alternates between showing a unit's defense and their resistance. It shows both the label and the number.

# User configuration

This module assumes that most users will want both stats' labels and numbers to end up in the same place. It provides the `DEF_OR_RES_X` and `DEF_OR_RES_Y` definitions which, if set, will link the labels for the stats to be drawn to the same location, as well as the numbers drawn to the same location (at `DEF_OR_RES_SPACING` pixels to the right of the start of the label).

If you do not specify `DEF_OR_RES_X` or `DEF_OR_RES_Y`, the normal `DEF_X`, `DEF_Y`, `RES_X`, `RES_Y`, and the equivalent `_LABEL_` definitions will be used instead.

The precise meaning of `DEF_X` and `DEF_Y` depends on the number renderer.

By default, this shares the number graphics and palette of the other numbers. You can decouple this behavior by setting the `_BASE_TILE` and `_PALETTE` definitions.

## Simple definitions (shared)

These set the default number tile and palette:

  * `NUMBER_BASE_TILE`: The base tile of the number graphics in VRAM
  * `NUMBER_PALETTE`: The PalRAM index of the number palette

## Simple definitions

  * `DEF_OR_RES_FRAMES`: The time (in frames) between each stat alternation
  * `DEF_LABEL_BASE_TILE`: The base tile of the defense label graphics in VRAM
  * `DEF_LABEL_PALETTE`: The PalRAM index of the defense label palette
  * `DEF_LABEL_WIDTH`: The width of the defense label in tiles
  * `DEF_BASE_TILE`: The base tile of the defense number graphics in VRAM
  * `DEF_PALETTE`: The PalRAM index of the defense number palette
  * `RES_LABEL_BASE_TILE`: The base tile of the resistance label graphics in VRAM
  * `RES_LABEL_PALETTE`: The PalRAM index of the resistance label palette
  * `RES_LABEL_WIDTH`: The width of the resistance label in tiles
  * `RES_BASE_TILE`: The base tile of the resistance number graphics in VRAM
  * `RES_PALETTE`: The PalRAM index of the resistance number palette

## Simple definitions (linked positions)

  * `DEF_OR_RES_X` and `DEF_OR_RES_Y`: The base position of the labels in tiles
  * `DEF_OR_RES_SPACING`: The number of pixels to place the numbers, measured from the start of the label

## Simple definitions (decoupled positions)

  `DEF_X` and `DEF_Y`: The position of the defense number in pixels
  `RES_X` and `RES_Y`: The position of the resistance number in pixels
  `DEF_LABEL_X` and `DEF_LABEL_Y`: The position of the defense label in tiles
  `RES_LABEL_X` and `RES_LABEL_Y`: The position of the resistance label in tiles

# Other definitions

The `DEF_RENDERER` and `RES_RENDERER` definitions are the name of the functions responsible for rendering the numbers. The `DEF_OR_RES_RENDERER_DEFS` definition has the declaration for the renderer as well as a flag that tells the number drawing internals that it needs a specific renderer installed.
