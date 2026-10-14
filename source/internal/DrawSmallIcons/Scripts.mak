
# This makefile is actually a set of Python 3 scripts.
# It requires the package `Pillow` to be installed.
# Yes, this is mildly cursed.


SHELL = python
.ONESHELL:
.PHONY: all icons


all: Icons.event


icons: Sheet.png
	from itertools import product
	from PIL import Image
	with Image.open("$<") as sheet:
	  for (i, (y, x)) in enumerate(product(range(0, sheet.height, 8), range(0, sheet.width, 8))):
	    crop = sheet.crop((x, y, x + 8, y + 8))
	    if any(crop.getdata()):
	      crop.save("Icons/{:05d}.png".format(i))


Icons.event: icons
	from pathlib import Path
	template = """\
	#ifdef USE_ICON_{0}
	  WORD {0}
	  #incbin "Icons/{0}.4bpp"
	#endif // USE_ICON_{0}
	"""
	file_template = """
	
	// This file is generated and should not be manually edited.
	// See the `Scripts.mak` makefile.
	
	{}
	"""
	macro_lines = []
	for icon in Path("Icons").glob("*.png"):
	  macro_lines.append(template.format(icon.stem))
	with open("$@", "w") as o:
	  o.write(file_template.format("\n".join(macro_lines)))
