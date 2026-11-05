
# DrawTargetsInRangeSpecial

This module draws various icons for the selected unit's reachable targets over their map sprites. By default, the icons shown are:

  * Generic 'warning' icon: target has some kind of effectiveness against the unit
  * 'x2' icon: target has a brave weapon
  * Weapon type icon + down arrow: target has a weapon triangle reversal weapon
  * Status icons: target has a weapon or staff that inflicts a status
  * Delphi/Filli Shield icon: target has an item that negates flying effectiveness
  * Iron Rune/Hoplon Guard icon: target has an item that negates critical hits
  * Torch icon: target has a torch
  * Key icon: target is holding some kind of key
  * Ring icon: target is holding a dancer ring
  * Generic 'item' icon: unit has a (non-dropped) item
  * Special 'item' icon: unit has a droppable item


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
