
# RandomDrawDelay

This module changes window drawing to make it more chaotic, only drawing the window after a random-ish delay. This make it more and more likely to be drawn as a timer reaches a specified delay, but does not guarantee that the window is drawn at that time.

# User configuration

## Simple definitions

The `UI1_DELAY` definition is the average number of frames before the window is drawn. The window may be drawn sooner or later, however.
