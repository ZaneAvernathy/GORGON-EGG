
This file requires GORGON-EGG v1.2.0

The `DrawSmallIcons.event` file provides utilities for drawing 8x8px icons.

Basic usage:

  * Call `VerifySmallIconDict`, preferably during an `Init` or `Static` function
  * Register your icon(s) using `RegisterSmallIcon`, preferably ahead of time
  * Render your icon(s) using one of the `RenderSmallIcon` functions during a `Dynamic` function

Modules can provide default definitions for the following C definitions:

  * `SMALLICON_PALETTE`: The PalRAM slot for icons
  * `SMALLICON_COUNT`: The max number of icons able to be registered at once (see below)
  * `SMALLICON_DICT_TILE`: The VRAM tile index of the start of the icon cache dict
  * `SMALLICON_BASE_TILE`: The VRAM tile index of the start of icon graphics

The actual number of concurrent registered icons will be slightly fewer than `SMALLICON_COUNT`, due to bookkeeping shenanigans. By default, the system will allocate space for nearly 256 icons, and will manage the `SMALLICON_BASE_TILE` definition automatically by placing it after the cache dict.

The system also provides the function `InitializeSmallIconDict`, which will clear any registered icons. This will disrupt any other modules that use the system, so it is recommended to use `VerifySmallIconDict` instead. `VerifySmallIconDict` will only rebuild the cache dict if it is found to be invalid.

The system uses a sheet to organize the icons, and icons are referred to by their index on the sheet. The sheet must be processed manually when edited, splitting it into individual icons. There is a `Makefile` provided for this purpose.

Modules must specify which icons they need using EA definitions, like:

```toml
[[module.ea_definitions]]
  name = "USE_ICON_00000"
  body = "#define USE_ICON_00000"
```

The icon sheet includes 8x8 version of the GBAFE item icons, with icons 000256-000511 being the FE7/8 sheet and 000512-00767 being the FE6 sheet. If your module needs to access these icons, you can use the `USE_ICON_ITEMS` EA definition, which will automatically define all of the icon definitions for the assembled game's icon sheet.
