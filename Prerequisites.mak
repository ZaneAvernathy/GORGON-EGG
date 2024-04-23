
# This file handles prerequisites and requirements for building.


export ROOTDIR  := $(realpath .)
export TOOLSDIR  = tools

# Spaces within file paths often cause problems, so we require that
# there are no spaces in our file path.

EMPTY          :=
SPACECHAR      := $(EMPTY) $(EMPTY)

define SPACE_ERROR =
Please ensure that there are no spaces in your file names
endef

ifeq ($(findstring $(SPACECHAR),$(ROOTDIR)), $(SPACECHAR))
  $(error $(SPACE_ERROR))
endif


# Add some compatibility programs for building on various operating systems.

ifeq ($(OS),Windows_NT)
  export COMPAT_PREFIX  = 
  export COMPAT_SUFFIX  = .exe
  export PATH_SEPARATOR = \\
else
  export COMPAT_PREFIX  = wine 
  export COMPAT_SUFFIX  = 
  export PATH_SEPARATOR = /
endif


# Check if we have a Python virtual environment set up.

define PYTHON_MISSING_ERROR =
Unable to find a Python virtual environment. Please create a Python 3.11+ virtual environment (named venv) in the tools folder.
endef

define PYTHON_VERSION_ERROR =
This requires a recent version of Python 3 (3.11+)
endef

export PYTHON := \
  $(shell \
    { \
      command -v $(TOOLSDIR)/venv/Scripts/python$(COMPAT_SUFFIX) || \
      command -v $(TOOLSDIR)/venv/bin/python$(COMPAT_SUFFIX) ; \
    } \
  )

ifeq ($(PYTHON),)
  $(error $(PYTHON_MISSING_ERROR))
endif

ifeq ($(shell $(PYTHON) -c "import sys; print(int(sys.version_info < (3, 11)))"),1)
  $(error $(PYTHON_VERSION_ERROR))
endif


# Check if we have devkitARM installed.

define DKA_MISSING_ERROR =
Please install devkitARM and ensure that DEVKITARM is in your environment variables. export DEVKITARM=<path to>devkitARM
endef

ifeq ($(strip $(DEVKITARM)),)
  $(error $(DKA_MISSING_ERROR))
endif

# Add devkitARM's tools.
include $(DEVKITARM)/base_tools


# Check if we have CLib.

define CLIB_MISSING_ERROR =
Please place a copy of CLib into the `tools` folder. https://github.com/StanHash/FE-CLib
endef

export CLIBDIR := $(TOOLSDIR)/CLib

ifeq ($(wildcard $(CLIBDIR)),)
  $(error $(CLIB_MISSING_ERROR))
endif


# Check if we have lyn.

define LYN_MISSING_ERROR =
Please place a copy of lyn into the tools folder. https://github.com/StanHash/lyn
endef

export lyn := $(TOOLSDIR)/lyn$(COMPAT_SUFFIX)

ifeq ($(wildcard $(lyn)),)
  $(error $(LYN_MISSING_ERROR))
endif


# Check if we have ea-dep.

define EADEP_MISSING_ERROR =
Please place a copy of ea-dep into the tools folder. https://github.com/StanHash/ea-dep
endef

export ea-dep := $(TOOLSDIR)/ea-dep$(COMPAT_SUFFIX)

ifeq ($(wildcard $(ea-dep)),)
  $(error $(EADEP_MISSING_ERROR))
endif
