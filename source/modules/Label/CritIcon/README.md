
# CritLabelIcon

This module draws a label icon for the crit stat.

# User configuration

By default, this module draws the label icon aligned to the 8x8px tile grid. Users can specify the `CRT_LABEL_X_PIXELS` and `CRT_LABEL_Y_PIXELS` definitions in order to position using pixels.

The `ICON_LABEL_CRIT` and `USE_ICON_` definitions control the icon used. By default, this module uses the EA definition `USE_ICON_000198`.

The `SMALLICON_BASE_TILE` definition does not normally need to be set, as it will be automatically calculated from the `SMALLICON_DICT_TILE` and `SMALLICON_COUNT` definitions.

The `SMALLICON_COUNT` definition should ideally be a multiple of 16 (and is set to 256 by default). The actual max number of icons able to be registered at once will be slightly fewer than this number, so it is unwise to expect an exact max.

## Simple definitions (shared)

  * `CRT_LABEL_X` and `CRT_LABEL_Y`: The coordinates of the label in tiles

## Simple definitions (decoupled)

  * `CRT_LABEL_X_PIXELS` and `CRT_LABEL_Y_PIXELS`: The coordinates of the label in tiles
  * `ICON_LABEL_CRIT`: The index of the label icon
  * `SMALLICON_DICT_TILE`: The VRAM tile index of the icon cache dictionary
  * `SMALLICON_PALETTE`: The PalRAM index of the icon palette
  * `SMALLICON_COUNT`: The approximate maximum number of concurrent icons to cache

## Other definitions (shared)

  * `SMALLICON_BASE_TILE`: The VRAM tile index of the icon graphics
