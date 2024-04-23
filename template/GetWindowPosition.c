
#include "gbafe.h"
#include "CommonDefinitions.h"
#include "GeneratedDefinitions.h"

#ifndef TILEMAP_DESTINATION
  /* This dummy macro will have its definition replaced
   * with a series of calls of the form
   * coords = SomeFunction(proc, coords);
   * for each <TilemapDestination> tag in a module.
   * Generally, there should be exactly one (from
   * whatever handles the window tilemap).
   */
  #define TILEMAP_DESTINATION
  #endif // TILEMAP_DESTINATION

// These definitions should be overridden by a module or
// the config, but are defined here for safety.

#ifndef GE_WIDTH
  #define GE_WIDTH 13
  #endif // GE_WIDTH

#ifndef GE_HEIGHT
  #define GE_HEIGHT 6
  #endif // GE_HEIGHT


struct Vec2 GE_GetWindowPosition(struct PlayerInterfaceProc* proc)
{
  /* Get the position of the (fully extended) window.
   */

  struct Vec2 coords = {0, 0};

  TILEMAP_DESTINATION;

  return coords;
}
