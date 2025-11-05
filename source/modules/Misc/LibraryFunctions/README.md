
# LibraryFunctions

This module allows user configs to make use of GORGON-EGG's included library functions.

If you run into errors about requiring library functions (functions beginning with `__` that you otherwise didn't specify yourself), include this module.

See the [LibraryFunctions internal file](/source/internal/LibraryFunctions/LibraryFunctions.event) to see a list of supported library features.

# User configuration

Before including this module, you must create assembly definitions for any library features you require. The name of the assembly definition is prefixed with `NEED_`, followed by the name of the feature with its leading underscores removed.

For example, if you require the `__gnu_thumb1_case_sqi` function, add the following to your config:

```toml
[[config.asm_definitions]]
  name = "NEED_gnu_thumb1_case_sqi"
  value = 1

[[config.modules]]
  name = "LibraryFunctions"
```
