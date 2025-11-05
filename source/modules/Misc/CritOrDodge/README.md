
# CritOrDodge

This module alternates between showing a unit's crit and their dodge (crit avoid). It shows both the label and the number.

# User configuration

This module assumes that most users will want both stats' labels and numbers to end up in the same place. It provides the `CRT_OR_DOD_X` and `CRT_OR_DOD_Y` definitions which, if set, will link the labels for the stats to be drawn to the same location, as well as the numbers drawn to the same location (at `CRT_OR_DOD_SPACING` pixels to the right of the start of the label).

If you do not specify `CRT_OR_DOD_X` or `CRT_OR_DOD_Y`, the normal `CRT_X`, `CRT_Y`, `DOD_X`, `DOD_Y`, and the equivalent `_LABEL_` definitions will be used instead.

The precise meaning of `CRT_X` and `CRT_Y` depends on the number renderer.

By default, this shares the number graphics and palette of the other numbers. You can decouple this behavior by setting the `_BASE_TILE` and `_PALETTE` definitions.

## Simple definitions (shared)

These set the default number tile and palette:

  * `NUMBER_BASE_TILE`: The base tile of the number graphics in VRAM
  * `NUMBER_PALETTE`: The PalRAM index of the number palette

## Simple definitions

  * `CRT_OR_DOD_FRAMES`: The time (in frames) between each stat alternation
  * `CRT_LABEL_BASE_TILE`: The base tile of the crit label graphics in VRAM
  * `CRT_LABEL_PALETTE`: The PalRAM index of the crit label palette
  * `CRT_LABEL_WIDTH`: The width of the crit label in tiles
  * `CRT_BASE_TILE`: The base tile of the crit number graphics in VRAM
  * `CRT_PALETTE`: The PalRAM index of the crit number palette
  * `DOD_LABEL_BASE_TILE`: The base tile of the dodge label graphics in VRAM
  * `DOD_LABEL_PALETTE`: The PalRAM index of the dodge label palette
  * `DOD_LABEL_WIDTH`: The width of the dodge label in tiles
  * `DOD_BASE_TILE`: The base tile of the dodge number graphics in VRAM
  * `DOD_PALETTE`: The PalRAM index of the dodge number palette

## Simple definitions (linked positions)

  * `CRT_OR_DOD_X` and `CRT_OR_DOD_Y`: The base position of the labels in tiles
  * `CRT_OR_DOD_SPACING`: The number of pixels to place the numbers, measured from the start of the label

## Simple definitions (decoupled positions)

  `CRT_X` and `CRT_Y`: The position of the crit number in pixels
  `DOD_X` and `DOD_Y`: The position of the dodge number in pixels
  `CRT_LABEL_X` and `CRT_LABEL_Y`: The position of the crit label in tiles
  `DOD_LABEL_X` and `DOD_LABEL_Y`: The position of the dodge label in tiles

# Other definitions

The `CRT_RENDERER` and `DOD_RENDERER` definitions are the name of the functions responsible for rendering the numbers. The `CRT_OR_DOD_RENDERER_DEFS` definition has the declaration for the renderer as well as a flag that tells the number drawing internals that it needs a specific renderer installed.
