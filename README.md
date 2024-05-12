
# GORGON-EGG

## Purpose

`GORGON-EGG` is a replacement for Fire Emblem: The Sacred Stones' "Panel" mode unit window, which is the window displayed when the cursor is over a unit during a chapter map. It is designed to be used within an [Event Assembler](https://feuniverse.us/t/event-assembler/1749) buildfile. `GORGON-EGG` is designed to be configured by users. It uses (mostly) self-contained groups of assets called `modules` to provide window functionality such as displaying unit statistics, graphics (notably, the unit's 32x32px small portrait, commonly called a "chibi" or "minimug"), or to handle functional tasks like controlling when or how the window is displayed. User configuration is handled by a `config` file, which allows users to easily add, remove, and reposition elements. A config file is a text file with a .xml extension (commonly named `Config.xml`), which allows configurations to be easily shared and adapted.

## Acronym

The full name of this project is `Modular, User-configurable, Makefile-based, C Language, "Panel"-setting Unit Window Replacement With No Pronounceable Acronym`, which is, for obvious reasons, abbreviated `GORGON-EGG`.

## Prerequisites

`GORGON-EGG` has a few requirements that must be met before building:

* A [Python3.11+](https://www.python.org/downloads/) virtual environment named [`venv`](https://docs.python.org/3/library/venv.html) must be placed in the `tools` folder (normally, by navigating to the `tools` folder and invoking `python -m venv venv`).
* A devkitARM installation from [devkitPro](https://devkitpro.org/wiki/Getting_Started), with the path to devkitARM in your environment variables (as `DEVKITARM`)
* A copy of [nat's FE-CLib](https://github.com/StanHash/FE-CLib) named `CLib` in the `tools` folder
* A copy of [nat's lyn](https://github.com/StanHash/lyn) named `lyn` in the `tools` folder
* A copy of [nat's ea-dep](https://github.com/StanHash/ea-dep) named `ea-dep` in the `tools` folder
* A copy of [CrazyColorz5's png2dmp](https://feuniverse.us/t/1764) named `png2dmp` in the `tools` folder
* An installation of [GNU Make](https://www.gnu.org/software/make/) (likely, your installation of devkitARM already provides `Make`)

Afterward, you can build `GORGON-EGG` by running `make` in the root directory.

## User Configuration

Configuring the window is done by editing the `Config.xml` file within the `config` folder. The `Config.xml` file is an XML-formatted text document. It consists of exactly one set of `Config` tags, between which there are any number of `Module`, `Definition`, or `ASMDefinition` tags.

There are example configs in the [example folder](example).

### Module READMEs

`Module`s, located in subfolders within the [modules folder](source/modules), come with a `README.md` file that gives the module's name, a description of the module, and the definitions/ASM definitions it provides.

### Module tags

A `Module` tag selects a module to be added to the window. A module adds some kind of functionality or element to the window. For example, to add a minimug to your window, you would add the following line to your config:
```xml
<Module Name="MinimugStandard"/>
```

The `Name` attribute here should be the name of the module you wish to add.

### Definition tags

`Definition` tags are the main way for users to configure the modules that they include. 

A `Definition` tag has two forms. The main form has two attributes, `Name` and `Value`. For example, to change the X coordinate of the bar drawn by the [HPBarStandard module](source/modules/HPBarStandard), you would add the following line to your config (and change the `Value` attribute):
```xml
<Definition Name="HPBAR_X" Value="5"/>
```

The second form of the `Definition` tag has only the `Name` attribute. The tag's text field is used to generate the definition. For example:
```xml
<Definition Name="Foo">
  #define Foo 42
</Definition>
```

This second form is rarely needed inside configs.

### ASMDefinition tags

`ASMDefinition` tags have the same forms and styling of `Definition` tags, but they affect THUMB assembly sources instead of C sources. These are rarely used in configs.

Here's an example of an `ASMDefinition`:
```xml
<ASMDefinition Name="Frob">
  .macro Frob Foo, Bar
    .long \Foo, \Bar
  .endm
</ASMDefinition>
```

## Custom modules

GORGON-EGG provides the [custom](custom) folder for user-provided modules. This allows users to create custom modules or modules that override/replace prepackaged modules without having to disrupt existing files. See the [modules README](source/modules/README.md) for more details on how to make a module.
