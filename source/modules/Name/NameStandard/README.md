
# NameStandard

This module draws the unit's name similarly to how vanilla does. This module can be configured to draw the text using a variety of alignments.

# User configuration

The `Name` modules share a set of definitions, assuming that most users will only have one `Name` module per config. These definitions begin with `NAME_`. If you want this module's configuration to be decoupled from the other modules, use the `NAME_STANDARD_` definitions.

If using the `NAME_SHIFTED_RIGHT` alignment, the text will be shifted to the right by `NAME_STANDARD_SHIFT` pixels if `NAME_STANDARD_SHIFT_CONDITION` yields `TRUE`.

## Simple definitions (shared)

  * `NAME_X` and `NAME_Y`: The coordinates of the left edge of the text space in tiles
  * `NAME_WIDTH`: The width of the text space in tiles
  * `NAME_COLOR`: The color of the text, see [the text header](/template/include/Text.h)
  * `NAME_ALIGNMENT`: How the text is aligned. This should be one of `NameAlignments`

## Simple definitions (decoupled)

  * `NAME_STANDARD_X` and `NAME_STANDARD_Y`: The coordinates of the left edge of the text space in tiles
  * `NAME_STANDARD_WIDTH`: The width of the text space in tiles
  * `NAME_STANDARD_COLOR`: The color of the text, see [the text header](/template/include/Text.h)
  * `NAME_STANDARD_ALIGNMENT`: How the text is aligned. This should be one of `NameAlignments`
  * `NAME_STANDARD_SHIFT`: Distance to shift in pixels when using a shift alignment

## Other definitions

The `NameAlignments` definition describes an enum for text alignment values, and generally should not be edited.

The `NAME_STANDARD_SHIFT_CONDITION` should be a C expression that yields `TRUE` if the name should be shifted and `FALSE` otherwise.

<details><summary>Example shift conditions</summary>

By default, `NAME_STANDARD_SHIFT_CONDITION` shifts the text if the unit has an affinity.

You can write your own  condition by adding something like this to your config:

```toml
[[config.definitions]]
  name = "NAME_STANDARD_SHIFT_CONDITION"
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
  name = "NAME_STANDARD_SHIFT_DECLS"
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
  name = "NAME_STANDARD_SHIFT_CONDITION"
  value = "( !Foo() || Bar(udp->unit) )"
```

</details>
