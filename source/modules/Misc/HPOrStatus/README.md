
# HPOrStatusStandard

This module alternates between showing a unit's HP and their status, if they have one. For their HP, it shows the HP label, current HP number, divider, and max HP number. The status shows both the status image and duration.

This module renders the status using the status image(s) already in the vanilla game. If you wish to have fine-grained control over the status images, consider using the `HPOrStatus` module instead.

# HPOrStatus

This module functions like the `HPOrStatusStandard` module, except that it installs images for all the the statuses.

# User configuration

This module assumes that most users will want all of the elements to appear as they do in vanilla. You can move the entire module's elements as a group by setting the `STATUS_X` and `STATUS_Y` definitions.

## Simple definitions (shared)

  * `NUMBER_BASE_TILE`: The base tile of the number graphics in VRAM
  * `NUMBER_PALETTE`: The PalRAM index of the number palette

## Simple definitions

  * `HP_OR_STATUS_FRAMES`: The time (in frames) between each alternation
  * `STATUS_BASE_TILE`: The base tile of the status image in VRAM
  * `STATUS_PALETTE`: The PalRAM index of the status image palette
  * `STATUS_IMAGE_WIDTH`: The width of the status image in tiles
  * `STATUS_NUMBER_BASE_TILE`: The base tile of the status numbers in VRAM
  * `STATUS_NUMBER_PALETTE`: The PalRAM index of the status numbers palette
  * `HP_LABEL_BASE_TILE`: The base tile of the HP label in VRAM
  * `HP_LABEL_PALETTE`: The PalRAM index if the HP label palette
  * `HP_DIVIDER_BASE_TILE`: The base tile of the divider image in VRAM
  * `HP_DIVIDER_PALETTE`: The PalRAM index of the divider palette
  * `HP_DIVIDER_WIDTH`: The width of the divider in tiles
  * `CURRENT_HP_BASE_TILE`: The base tile of the current HP number tile in VRAM (default: NUMBER_BASE_TILE)
  * `CURRENT_HP_PALETTE`: The PalRAM index of the current HP number palette (default: NUMBER_PALETTE)
  * `MAX_HP_BASE_TILE`: The base tile of the max HP number tile in VRAM (default: NUMBER_BASE_TILE)
  * `MAX_HP_PALETTE`: The PalRAM index of the max HP number palette (default: NUMBER_PALETTE)

## Simple definitions (linked positions)

  * `STATUS_X` and `STATUS_Y`: The base position of the elements in tiles

## Simple definitions (decoupled positions)

  * `STATUS_X` and `STATUS_Y`: The position of the status image in tiles
  * `HP_LABEL_X` and `HP_LABEL_Y`: The position of the HP label in tiles
  * `HP_DIVIDER_X` and `HP_DIVIDER_Y`: The position of the HP divider in tiles
  * `CURRENT_HP_X` and `CURRENT_HP_Y`: The position of the current HP number in pixels
  * `MAX_HP_X` and `MAX_HP_Y`: The position of the max HP number in pixels

# Other definitions

The `UnitStatus` definition defines an enum for unit statuses, and generally should not be edited.

The `CURRENT_HP_RENDERER` and `MAX_HP_RENDERER` definitions are the name of the functions responsible for rendering the numbers. The `HP_RENDERER_DEFS` definition has the declaration for the renderer as well as a flag that tells the number drawing internals that it needs a specific renderer installed.
