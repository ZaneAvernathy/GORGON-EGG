
# NameSmallSJIS

This module draws the unit's name similarly to how vanilla does. This module can be configured to draw the text using a variety of alignments.

This module supports both SJIS text and most of the Latin character set. This module should be used for games that use SJIS text, while games that use Latin text exclusively can save space and time by using the `NameSmall` module instead.

# User configuration

The `Name` modules share a set of definitions, assuming that most users will only have one `Name` module per config. These definitions begin with `NAME_`. If you want this module's configuration to be decoupled from the other modules, use the `NAME_SMALL_SJIS_` definitions.

If using the `NAME_SHIFTED_RIGHT` alignment, the text will be shifted to the right by `NAME_SMALL_SJIS_SHIFT` pixels if `NAME_SMALL_SJIS_SHIFT_CONDITION` yields `TRUE`.

## Simple definitions (shared)

  * `NAME_X` and `NAME_Y`: The coordinates of the left edge of the text space in tiles
  * `NAME_WIDTH`: The width of the text space in tiles
  * `NAME_COLOR`: The color of the text, see [the text header](/template/include/Text.h)
  * `NAME_ALIGNMENT`: How the text is aligned. This should be one of `NameAlignments`

## Simple definitions (decoupled)

  * `NAME_SMALL_SJIS_X` and `NAME_SMALL_SJIS_Y`: The coordinates of the left edge of the text space in tiles
  * `NAME_SMALL_SJIS_WIDTH`: The width of the text space in tiles
  * `NAME_SMALL_SJIS_COLOR`: The color of the text, see [the text header](/template/include/Text.h)
  * `NAME_SMALL_SJIS_ALIGNMENT`: How the text is aligned. This should be one of `NameAlignments`
  * `NAME_SMALL_SJIS_SHIFT`: Distance to shift in pixels when using a shift alignment

## Other definitions

The `NameAlignments` definition describes an enum for text alignment values, and generally should not be edited.

The `NAME_SMALL_SJIS_SHIFT_CONDITION` should be a C expression that yields `TRUE` if the name should be shifted and `FALSE` otherwise.

[details="Example shift conditions"]

By default, `NAME_SMALL_SJIS_SHIFT_CONDITION` shifts the text if the unit has an affinity.

You can write your own  condition by adding something like this to your config:

```toml
[[config.definitions]]
  name = "NAME_SMALL_SJIS_SHIFT_CONDITION"
  body = '''
({                                    \
  bool shouldShift = FALSE;           \
                                      \
  if ( /* Your condition here... */ ) \
    shouldShift = TRUE;               \
                                      \
  /* ... */                           \
                                      \
  shouldShift;                        \
})'''
```

You may need to place some additional definitions and ASM definitions before this definition if your checks rely on other functions. For example:

```toml
[[config.definitions]]
  name = "NAME_SMALL_SJIS_SHIFT_DECLS"
  body = '''
bool Foo(void);
bool Bar(struct Unit* unit);
'''

[[config.asm_definitions]]
  name = "Foo"
  body = "SET_FUNC Foo, 0x08000420 | 1"

[[config.asm_definitions]]
  name = "Bar"
  body = "SET_FUNC Bar, 0x08001336 | 1"

[[config.definitions]]
  name = "NAME_SMALL_SJIS_SHIFT_CONDITION"
  value = "( !Foo() || Bar(udp->unit) )"
```

[/details]
