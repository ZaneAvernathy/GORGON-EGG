
# TilemapFlag

This module defines the window's tilemap. It should be used alongside a `Draw` module in order to display the window.

This variant draws a two separate tilemaps depending on whether an event flag is set.

# User configuration

## Simple definitions

  * `UI1_BASE_WIDTH` and `UI1_BASE_HEIGHT`: The size of the normal tilemap in tiles
  * `UI1_ALTERNATE_WIDTH` and `UI1_ALTERNATE_HEIGHT`: The size of the alternate tilemap in tiles
  * `UI1_TILEMAP_PALETTE`: The PalRAM index of the palette
  * `ALTERNATE_TILEMAP_FLAG`: The event flag
