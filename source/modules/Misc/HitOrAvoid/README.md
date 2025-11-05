
# HitOrAvoid

This module alternates between showing a unit's hit and their avoid. It shows both the label and the number.

# User configuration

This module assumes that most users will want both stats' labels and numbers to end up in the same place. It provides the `HIT_OR_AVO_X` and `HIT_OR_AVO_Y` definitions which, if set, will link the labels for the stats to be drawn to the same location, as well as the numbers drawn to the same location (at `HIT_OR_AVO_SPACING` pixels to the right of the start of the label).

If you do not specify `HIT_OR_AVO_X` or `HIT_OR_AVO_Y`, the normal `HIT_X`, `HIT_Y`, `AVO_X`, `AVO_Y`, and the equivalent `_LABEL_` definitions will be used instead.

The precise meaning of `HIT_X` and `HIT_Y` depends on the number renderer.

By default, this shares the number graphics and palette of the other numbers. You can decouple this behavior by setting the `_BASE_TILE` and `_PALETTE` definitions.

## Simple definitions (shared)

These set the default number tile and palette:

  * `NUMBER_BASE_TILE`: The base tile of the number graphics in VRAM
  * `NUMBER_PALETTE`: The PalRAM index of the number palette

## Simple definitions

  * `HIT_OR_AVO_FRAMES`: The time (in frames) between each stat alternation
  * `HIT_LABEL_BASE_TILE`: The base tile of the hit label graphics in VRAM
  * `HIT_LABEL_PALETTE`: The PalRAM index of the hit label palette
  * `HIT_LABEL_WIDTH`: The width of the hit label in tiles
  * `HIT_BASE_TILE`: The base tile of the hit number graphics in VRAM
  * `HIT_PALETTE`: The PalRAM index of the hit number palette
  * `AVO_LABEL_BASE_TILE`: The base tile of the avoid label graphics in VRAM
  * `AVO_LABEL_PALETTE`: The PalRAM index of the avoid label palette
  * `AVO_LABEL_WIDTH`: The width of the avoid label in tiles
  * `AVO_BASE_TILE`: The base tile of the avoid number graphics in VRAM
  * `AVO_PALETTE`: The PalRAM index of the avoid number palette

## Simple definitions (linked positions)

  * `HIT_OR_AVO_X` and `HIT_OR_AVO_Y`: The base position of the labels in tiles
  * `HIT_OR_AVO_SPACING`: The number of pixels to place the numbers, measured from the start of the label

## Simple definitions (decoupled positions)

  `HIT_X` and `HIT_Y`: The position of the hit number in pixels
  `AVO_X` and `AVO_Y`: The position of the avoid number in pixels
  `HIT_LABEL_X` and `HIT_LABEL_Y`: The position of the hit label in tiles
  `AVO_LABEL_X` and `AVO_LABEL_Y`: The position of the avoid label in tiles

# Other definitions

The `HIT_RENDERER` and `AVO_RENDERER` definitions are the name of the functions responsible for rendering the numbers. The `HIT_OR_AVO_RENDERER_DEFS` definition has the declaration for the renderer as well as a flag that tells the number drawing internals that it needs a specific renderer installed.
