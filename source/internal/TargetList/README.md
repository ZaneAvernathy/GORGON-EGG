
This internal file requires GORGON-EGG v1.2.0

The `TargetList.event` file provides utilities for generating lists of targets. Modules that request target utilities should include the corresponding `NEED_` EA definition(s) in their module declaration file. For example:

```toml
[[module.ea_definitions]]
  name = "NEED_ForEachTarget"
  body = "#define NEED_ForEachTarget"
```

Generally, user configs should avoid having more than one module that requires target list generation, as the target list will be overwritten by each.

Currently, the following utilities are provided:

Target list generators:

  * `GetTargetList_HostileAll`: Given a unit, make a list of all units on the map that are hostile to them.
  * `GetTargetList_HostileInRange`: Given a unit, make a list of all attackable units in range.

Target list consumers:

  * `ForEachTarget`: Run a function on each unit in the target list.
