
# ReplaceNumberGraphics

This module replaces the vanilla number graphics and palette that are found in VRAM/PalRAM.

# User configuration

By default, the bar graphics drawn are the ones used for the FE8 map battle UI. This will use the numbers that are already present in the vanilla games unless you specify not to.

If you want to use your own graphics/palette, there are two options:

You can copy this module into the `custom` folder and edit the `Bar.png` image. Then, add the following to your buildfile before `#include`ing the GORGON-EGG installer:
```
#define NEED_NUMBER_GRAPHICS
#define NEED_NUMBER_PALETTE
```

Otherwise, you can add the following to your buildfile before `#include`ing the GORGON-EGG installer:
```
#define CUSTOM_NUMBER_GRAPHICS
#define CUSTOM_NUMBER_PALETTE

ALIGN 4: gNumberGraphics: {
  #incbin "YourGraphics.4bpp.lz77"
};

ALIGN 4; gNumberPalette: {
  #incbin "YourPalette.pal"
};
```

If you don't want to use compressed graphics, be sure to set the `NUMBER_GRAPHICS_COMPRESSED` definition in your config to `FALSE`.

## Simple definitions

  * `NUMBER_BASE_TILE`: The base VRAM tile for the graphics
  * `NUMBER_PALETTE`: The PalRAM index of the palette
  * `NUMBER_GRAPHICS_WIDTH`: The width of the number graphics in tiles
  * `NUMBER_GRAPHICS_COMPRESSED`: A boolean whether the number graphics are compressed
