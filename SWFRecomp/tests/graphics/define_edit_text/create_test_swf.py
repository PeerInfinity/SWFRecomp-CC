#!/usr/bin/env python3
"""Generate test.swf for define_edit_text graphics test.

Tests DefineEditText (tag 37) rendering with a real pixel font (04B_03).
Defines a DefineFont2 with layout/advance widths extracted from the TTF,
then uses DefineEditText with InitialText="Hello World" to render text.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, extract_ttf_glyphs,
)

TTF_PATH = "/home/robert/projects/Seedling/src/net/flashpunk/graphics/04B_03__.TTF"
TEXT = "Hello World"

# Extract glyph outlines from the TTF
glyph_info = extract_ttf_glyphs(TTF_PATH, TEXT, em_square=1024)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=6)
swf.set_background(255, 255, 255)

# ---- Define Font2 (object ID 1) with real font glyphs ----
font = swf.define_font2(object_id=1, font_name="04B_03")
font.ascent = glyph_info['ascent']
font.descent = glyph_info['descent']
font.leading = glyph_info['leading']

for char_code, edges, advance in glyph_info['glyphs']:
    font.add_glyph_mapped(edges, char_code, advance)

# ---- Define EditText (object ID 2) with InitialText ----
swf.define_edit_text(
    object_id=2,
    bounds=(0, 11000, 0, 2000),
    font_id=1,
    font_height=1200,
    color=(255, 0, 0, 255),
    initial_text=TEXT,
    read_only=True,
)

swf.place_object(object_id=2, depth=1, trans_x=1000, trans_y=4000)
swf.show_frame()
swf.save("test.swf")
