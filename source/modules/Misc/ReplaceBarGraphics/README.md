
# ReplaceBarGraphics

This module replaces the vanilla bar graphics and palette that are found in VRAM/PalRAM.

# User configuration

By default, the bar graphics drawn are the ones used for the FE8 map battle UI. This will use the ones already in the vanilla game if the game is FE8U or FE8J, and will install new graphics and a palette for the other games.

If you want to use your own graphics/palette, there are two options:

You can copy this module into the `custom` folder and edit the `Bar.png` image. Then, add the following to your buildfile before `#include`ing the GORGON-EGG installer:
```
#define NEED_BAR_GRAPHICS
#define NEED_BAR_PALETTE
```

Otherwise, you can add the following to your buildfile before `#include`ing the GORGON-EGG installer:
```
#define CUSTOM_BAR_GRAPHICS
#define CUSTOM_BAR_PALETTE

ALIGN 4: gBarGraphics: {
  #incbin "YourGraphics.4bpp.lz77"
};

ALIGN 4; gBarPalette: {
  #incbin "YourPalette.pal"
};
```

If you don't want to use compressed graphics, be sure to set the `BAR_GRAPHICS_COMPRESSED` definition in your config to `FALSE`.

## Simple definitions

  * `BAR_BASE_TILE`: The base VRAM tile for the graphics
  * `BAR_PALETTE`: The PalRAM index of the palette
  * `BAR_GRAPHICS_WIDTH`: The width of the bar graphics in tiles
  * `BAR_GRAPHICS_COMPRESSED`: A boolean whether the bar graphics are compressed
