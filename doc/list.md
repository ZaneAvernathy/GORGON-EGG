
# Module list

This file lists all prepackaged modules included with GORGON-EGG. See the individual module files for customization details.

# Bar

These modules draw a bar representing some stat or value.

  * [HPBarStandard](/source/modules/Bar/HPBarStandard): Draws the ratio of current HP/max HP as a bar

# Draw

These modules handle extending/retracting the window and are used in conjunction with the [tilemap modules](#tilemap).

  * [DrawNotConst](/source/modules/Draw/DrawNotConst): Extends/retracts horizontally from the corner of the screen, with the possibility that the window's size is not constant.
  * [DrawStandard](/source/modules/Draw/DrawStandard): Extends/retracts horizontally from the corner of the screen the way vanilla does
  * [DrawVertical](/source/modules/Draw/DrawVertical): Extends/retracts vertically from the corner of the screen

# Equip

These modules draw something for the unit's equipped weapon.

  * [EquipIcon](/source/modules/Equip/EquipIcon): Draws the weapon's icon as an object
  * [EquipName](/source/modules/Equip/EquipName): Draws the weapon's name using the standard text font
  * [EquipNameIfEnemy](/source/modules/Equip/EquipNameIfEnemy): Draws the weapon's name using the standard text font, but only if the unit is an enemy
  * [EquipNameIfNPC](/source/modules/Equip/EquipNameIfNPC): Draws the weapon's name using the standard text font, but only if the unit is an NPC
  * [EquipNameIfPlayer](/source/modules/Equip/EquipNameIfPlayer): Draws the weapon's name using the standard text font, but only if the unit is a player unit
  * [EquipNameWithWarning](/source/module/Equip/EquipNameWithWarning): Draws the weapon's name using the standard font, using a different color for the name if the item's durability is below a certain threshold

# Inventory

These modules draw something for the unit's inventory.

  * [FullInventory](/source/modules/Inventory/FullInventory): Draws the unit's items (as a horizontal panel, by default)
  * [FullInventoryAlternating](/source/modules/Inventory/FullInventoryAlternating): Draws the unit's items, displaying one at a time in a single place, alternating regularly
  * [FullInventoryAlternatingDroppable](/source/modules/Inventory/FullInventoryAlternatingDroppable): Draws the unit's items, displaying one at a time in a single place, alternating regularly, but with an icon drawn over their last item if the unit is set to drop items
  * [FullInventoryDroppable](/source/modules/Inventory/FullInventoryDroppable): Draws the unit's items (as a horizontal panel, by default), but with an icon drawn over their last item if the unit is set to drop items
  * [FullInventoryFirstFixed](/source/modules/Inventory/FullInventoryFirstFixed): Draws the units items, always displaying the first item but also displaying a second icon that cycles between the unit's remaining items

# Label

These modules draw a label graphic that generally corresponds with a stat. They are typically used alongside a [number module](#number).

The [HPDivider](/source/modules/Label/HPDivider) module draws the `/` that is displayed between the current and max HP numbers on the vanilla window.

  * [Attack](/source/modules/Label/Attack)
  * [AttackSpeed](/source/modules/Label/AttackSpeed)
  * [Avoid](/source/modules/Label/Avoid)
  * [Crit](/source/modules/Label/Crit)
  * [Defense](/source/modules/Label/Defense)
  * [Dodge](/source/modules/Label/Dodge)
  * [Experience](/source/modules/Label/Experience)
  * [Hit](/source/modules/Label/Hit)
  * [HP](/source/modules/Label/HP)
  * [HPDivider](/source/modules/Label/HPDivider)
  * [Level](/source/modules/Label/Level)
  * [Rating](/source/modules/Label/Rating)
  * [Resistance](/source/modules/Label/Resistance)

# Minimug

These modules draw the unit's minimug (the small portrait normally displayed on the window, sometimes called a `chibi`).

  * [MinimugEnemyFlipped](/source/modules/Minimug/MinimugEnemyFlipped): Draws the unit's minimug (which normally faces left) facing to the right if they are an enemy
  * [MinimugStandard](/source/modules/Minimug/MinimugStandard): Draws the unit's minimug the way vanilla does

# Misc

This section of modules is a catch-all for modules that do not fit cleanly into other categories.

  * [Affinity](/source/modules/Misc/Affinity): Draws the unit's affinity icon as an object
  * [CritOrDodge](/source/modules/Misc/CritOrDodge): Alternates between drawing a crit label+number and a dodge (crit avoid) label+number
  * [DefenseOrResistance](/source/modules/Misc/DefenseOrResistance): Alternates between drawing a defense label+number and a resistance label+number
  * [DrawMiscWarningIcons](/source/modules/Misc/DrawMiscWarningIcons): Draws configurable icons (by default, for dangerous weapons and droppable items)
  * [FixMinimugPalette](/source/modules/Misc/FixMinimugPalette): Fixes minimug palette flickering when selecting units
  * [HitOrAvoid](/source/modules/Misc/HitOrAvoid): Alternates between drawing a hit label+number and a avoid label+number
  * [HPOrStatusStandard](/source/modules/Misc/HPOrStatus): Alternates between drawing the unit's HP and status (the way the vanilla window does)
  * [HPOrStatus](/source/modules/Misc/HPOrStatus): Alternates between drawing the unit's HP and status (this variant installs new graphics for the statuses instead of reusing the vanilla ones)
  * [LibraryFunctions](/source/modules/Misc/LibraryFunctions): Provides missing GCC library functions
  * [RandomDrawDelay](/source/modules/Misc/RandomDrawDelay): Modifies window drawing to occur roughly after a certain amount of time has elapsed
  * [ReplaceBarGraphics](/source/modules/Misc/ReplaceBarGraphics): Provides an easy way to replace bar graphics
  * [ReplaceNumberGraphics](/source/modules/Misc/ReplaceBNumberGraphics): Provides an easy way to replace number graphics

# Name

These modules draw the unit's name.

  * [NameSmall](/source/modules/Name/NameSmall): Draws the unit's name using a specialized 8-pixel-tall font (for Latin text only)
  * [NameSmallSJIS](/source/modules/Name/NameSmallSJIS): Draws the unit's name using a specialized 8-pixel-tall font (for Japanese text with ASCII support)
  * [NameStandard](/source/modules/Name/NameStandard): Draws a unit's name (by default, the way vanilla does)

# Number

These modules draw numbers for various stats.

  * [Attack](/source/modules/Number/Attack)
  * [AttackSpeed](/source/modules/Number/AttackSpeed)
  * [Avoid](/source/modules/Number/Avoid)
  * [Crit](/source/modules/Number/Crit)
  * [CurrentHP](/source/modules/Number/CurrentHP)
  * [Defense](/source/modules/Number/Defense)
  * [Dodge](/source/modules/Number/Dodge)
  * [Experience](/source/modules/Number/Experience)
  * [Hit](/source/modules/Number/Hit)
  * [Level](/source/modules/Number/Level)
  * [MaxHP](/source/modules/Number/MaxHP)
  * [Rating](/source/modules/Number/Rating)
  * [Resistance](/source/modules/Number/Resistance)

# Tilemap

These modules handle defining the window's tilemap. They are used alongside [Draw modules](#draw).

  * [TilemapStandard](/source/modules/Tilemap/TilemapStandard): Vanilla's tilemap
  * [TilemapZane](/source/modules/Tilemap/TilemapZane): An example tilemap
  * [TilemapFlag](/source/modules/Tilemap/TilemapFlag): Draws two different tilemaps depending on an event flag
