
# DrawMiscWarningIcons

This module draws two icons, a sword and a bag, depending on user-configurable circumstances.

Icons are drawn left to right, with the bag appearing to the left of the sword, if drawing both.

Default behavior:
  * Icons are not drawn for player units
  * Icons are not drawn for units with no items
  * The sword icon is drawn if the unit is holding a 'dangerous weapon', which is any combination of the following traits: high crit, effectiveness, long range (3+), or being a status staff
  * The bag icon is drawn if the unit is set to drop an item

# User configuration

## Simple definitions

  * `MISC_WARNINGS_X` and `MISC_WARNINGS_Y`: The coordinates of the leftmost icon in pixels
  * `MISC_WARNINGS_BASE_TILE`: The VRAM tile index of the start of the graphics
  * `MISC_WARNINGS_PALETTE`: The PalRAM index of the palette

## Baseline display conditions

By default, icons are only drawn if the unit is a non-player unit with at least one item. You can override the `SHOULD_DISPLAY_MISC_WARNING` advanced definition to provide a new condition to enable these icons. This definition should yield a boolean value, with `TRUE` enabling the potential for the icons to be drawn for the unit. Then, the individual conditions for the icons will need to be met before anything is drawn.

[details="Example baseline conditions"]

To allow any unit to be able to have these icons, try the following definition:
```toml
[[config.definitions]]
  name = "SHOULD_DISPLAY_MISC_WARNING"
  value = "( !(proc->hideContents) )"
```

GORGON-EGG modules should hide object-based elements from the window when the `hideContents` flag is set.

---

You can write your own conditions by adding something like this to your config:

```toml
[[config.definitions]]
  name = "SHOULD_DISPLAY_MISC_WARNING"
  value = '''
({                             \
  bool shouldDisplay = TRUE;   \
                               \
  if ( proc->hideContents )    \
    shouldDisplay = FALSE;     \
                               \
  /* Place your checks here */ \
                               \
  shouldDisplay;               \
})'''
```

You may need to place some additional definitions and ASM definitions before this definition if your checks rely on other functions. For example:

```toml
[[config.definitions]]
  name = "MISC_WARNING_DECLS"
  body = '''
bool SomeVanillaFunction(struct Unit* unit);
bool SomeOtherFunction(void);
'''

[[config.asm_definitions]]
  name = "SomeVanillaFunction"
  body = "SET_FUNC SomeVanillaFunction, 0xDEADBEEF | 1"

[[config.asm_definitions]]
  name = "SomeOtherFunction"
  body = "SET_FUNC SomeOtherFunction, 0x00C0FFEE | 1"

[[config.definitions]]
  name = "SHOULD_DISPLAY_MISC_WARNING"
  value = "( !(proc->hideContents) || SomeVanillaFunction(udp->unit) || SomeOtherFunction() )"
```

[/details]

## Sword display conditions

By default, the sword icon is shown if the unit is carrying any items that have the following properties:
  * Has an effectiveness set
  * Has a crit rate over a specific threshold (default: 25)
  * Has a max range over a specific threshold (default: 3)
  * Is any one of the following staves: Silence, Sleep, Berserk

You can edit the thresholds by overriding the following definitions:
  * `MISC_WARNING_CRIT_THRESHOLD`
  * `MISC_WARNING_RANGE_THRESHOLD`

If you change the item slots of the staves but still need them, you can edit the following definitions:
  * `ITEM_STAFF_SILENCE`
  * `ITEM_STAFF_SLEEP`
  * `ITEM_STAFF_BERSERK`

---

You can override the `SHOULD_DISPLAY_MISC_WARNING_SWORD` definition to provide a new condition for the sword to be displayed. This definition should yield a boolean value, with `TRUE` drawing the icon for the unit.

[details="Example sword conditions"]

To show the sword icon regardless of conditions, you can override the `SHOULD_DISPLAY_MISC_WARNING_SWORD` like:
```toml
[[config.definitions]]
  name = "SHOULD_DISPLAY_MISC_WARNING_SWORD"
  value = "( TRUE )"
```

You can write a more complex condition by following the same steps as for the baseline condition.

[/details]

## Bag display conditions

By default, the bag icon is shown if the unit can drop an item. You can override the `SHOULD_DISPLAY_MISC_WARNING_BAG` definition to provide a new condition. This definition should yield a boolean value, with `TRUE` drawing the icon for the unit.

[details="Example bag conditions"]

To show the bag icon regardless of conditions, you can override the `SHOULD_DISPLAY_MISC_WARNING_BAG` like:
```toml
[[config.definitions]]
  name = "SHOULD_DISPLAY_MISC_WARNING_BAG"
  value = "( TRUE )"
```

You can write a more complex condition by following the same steps as for the baseline condition.

[/details]
