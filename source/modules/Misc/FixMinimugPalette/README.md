
# FixMinimugPalette

In vanilla, the minimug palette is copied to PalRAM one frame after the graphics are drawn, causing a brief period where the graphics are shown with the wrong palette. This module causes the graphics to be buffered before drawing, preventing this desync.

This module is not for FE6J, as it does not have this delay.

This is based on work by [Huichelaar](https://github.com/Huichelaar/FE8U_MinimugPalette).

# User configuration

## Advanced ASM definitions

The `gMinimugTempBuffer` ASM definition is for some unused space in RAM into which the minimug graphics are buffered. By default, this module uses space used for the sound room, which is not active while the GORGON-EGG window is shown. If this causes conflicts, this definition should be changed, like:
```toml
[[config.asm_definitions]]
  name = "gMinimugTempBuffer"
  body = "SET_DATA gMinimugTempBuffer, 0x0201EA50" # Edit this to your new address
  games = [ "FE7U" ] # Obviously, edit this to match your game

```

## Other definitions

This module relies on the `MINIMUG_WIDTH` and `MINIMUG_HEIGHT` definitions, which should be set by the minimug module.

