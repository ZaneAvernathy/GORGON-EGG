
# DrawTargetsInRangeItems

This module draws the inventories of hostile units in range of the selected unit as alternating 8x8px icons over their map sprites. During chapter preparations it shows the inventories of all hostile units, regardless of range.

# User configuration

The `SMALLICON_BASE_TILE` definition does not normally need to be set, as it will be automatically calculated from the `SMALLICON_DICT_TILE` and `SMALLICON_COUNT` definitions.

The `SMALLICON_COUNT` definition should ideally be a multiple of 16 (and is set to 256 by default). The actual max number of icons able to be registered at once will be slightly fewer than this number, so it is unwise to expect an exact max.

If `DRAW_TARGETS_IN_RANGE_INACTIVE_FRAMES` is nonzero, the icons will blink in and out, similar to how vanilla's boss indicators blink.

## Simple definitions (shared)

  * `SMALLICON_DICT_TILE`: The VRAM tile index of the icon cache dictionary
  * `SMALLICON_PALETTE`: The PalRAM index of the icon palette
  * `SMALLICON_COUNT`: The approximate maximum number of concurrent icons to cache

## Simple definitions

  * `DRAW_TARGETS_IN_RANGE_FRAMES_PER_ICON`: The number of frames dedicated to each icon
  * `DRAW_TARGETS_IN_RANGE_INACTIVE_FRAMES`: The number of frames that an icon is invisible during its cycle

## Other definitions (shared)

  * `SMALLICON_BASE_TILE`: The VRAM tile index of the icon graphics
