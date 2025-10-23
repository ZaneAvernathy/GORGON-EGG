
# Rating

This module draws a unit's 'Rating' stat, which by default is the sum of their combat stats.

This module draws the stat as a three digit number, with values over 254 displaying special text.

By default, this module draws the number as right-aligned, with the position specifying the top-left position of the lowest digit in the number.

# User configuration

The precise meaning of `RTG_X` and `RTG_Y` depends on the number renderer.

By default, this shares the number graphics and palette of the other numbers. You can decouple this behavior by setting the `RTG_BASE_TILE` and `RTG_PALETTE` definitions.

## Simple definitions (shared)

  * `NUMBER_BASE_TILE`: The base tile of the number graphics in VRAM
  * `NUMBER_PALETTE`: The PalRAM index of the number palette

## Simple definitions (decoupled)

  * `RTG_X` and `RTG_Y`: The position of the number in pixels
  * `RTG_BASE_TILE`: The base tile of the number graphics in VRAM
  * `RTG_PALETTE`: The PalRAM index of the number palette

# Other definitions

The `RTG_RENDERER` definition is the name of the function responsible for rendering the number. The `RTG_RENDERER_DEFS` definition Has the declaration for the renderer as well as a flag that tells the number drawing internals that it needs a specific renderer installed.

The `RTG_CALCULATION` definition is a C expression that calculates the rating.

[details="Example rating calculation"]

By default, the rating calculation looks like:

```c
#define RTG_CALCULATION             \
  ({                                \
    GetUnitMaxHp(udp->unit)         \
    + GetUnitPower(udp->unit)       \
    + GetUnitSkill(udp->unit)       \
    + GetUnitSpeed(udp->unit)       \
    + GetUnitLuck(udp->unit)        \
    + GetUnitDefense(udp->unit)     \
    + GetUnitResistance(udp->unit); \
  });
```

You can override this definition in your config by adding something like

```toml
[[config.definitions]]
  name = "RTG_CALCULATION"
  value = "( Foo(udp->unit) + Bar(udp->unit) )"

[[config.definitions]]
  name = "RTG_CALCULATION_DECLS"
  body = '''
int Foo(struct Unit* unit);
int Bar(struct Unit* unit);
'''

[[config.asm_definitions]]
  name = "Foo"
  body = "SET_FUNC Foo, 0xDEADBEEF | 1"

[[config.asm_definitions]]
  name = "Bar"
  body = "SET_FUNC Bar, 0x08DADADA | 1"

```

[/details]
