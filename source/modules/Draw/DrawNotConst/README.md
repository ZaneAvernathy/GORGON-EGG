
# DrawNotConst

This module handles extension and retraction of the window in the same way that the vanilla works, by extending/retracting horizontally from the corner of the screen.

This module does not handle the window's tilemap itself.

This variant does not require the `UI1_WIDTH` and `UI1_HEIGHT` definitions to be constant, unlike the `DrawStandard` module.

# User configuration

This module relies on something else (generally, the user's config) setting the `UI1_WIDTH` and `UI1_HEIGHT` definitions.
