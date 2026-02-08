"""
Helper module for generating SWF files via swfmill.

Provides a Python API that generates swfmill-compatible XML and invokes
`swfmill xml2swf` to produce SWF binary files.  Used by each graphics
test's create_test_swf.py script.
"""

import base64
import math
import os
import shutil
import struct
import subprocess
import sys
import tempfile
import zlib
from xml.etree.ElementTree import Element, SubElement, tostring
from xml.dom import minidom


# ---------------------------------------------------------------------------
# Bit-level writer for building raw SWF binary structures
# ---------------------------------------------------------------------------

class _BitWriter:
    """Writes individual bits for SWF bit-packed structures."""
    def __init__(self):
        self.bits = []

    def write_ub(self, value, nbits):
        """Write an unsigned bit-field value."""
        for i in range(nbits - 1, -1, -1):
            self.bits.append((value >> i) & 1)

    def write_sb(self, value, nbits):
        """Write a signed bit-field value (two's complement)."""
        if value < 0:
            value = (1 << nbits) + value
        self.write_ub(value, nbits)

    def write_fb(self, value, nbits):
        """Write a fixed-point 16.16 bit-field value."""
        fixed = int(round(value * 65536))
        self.write_sb(fixed, nbits)

    def align(self):
        """Pad to the next byte boundary."""
        while len(self.bits) % 8 != 0:
            self.bits.append(0)

    def to_bytes(self):
        """Convert accumulated bits to bytes (auto-aligns)."""
        self.align()
        result = bytearray()
        for i in range(0, len(self.bits), 8):
            byte = 0
            for j in range(8):
                byte = (byte << 1) | (self.bits[i + j] if i + j < len(self.bits) else 0)
            result.append(byte)
        return bytes(result)


def _bits_needed_sb(value):
    """Minimum bits to represent a signed value in SWF SB format."""
    if value == 0:
        return 1
    if value > 0:
        return value.bit_length() + 1
    return (-value - 1).bit_length() + 1


def _bits_needed_fb(value):
    """Minimum bits to represent a fixed-point 16.16 value."""
    fixed = int(round(value * 65536))
    return _bits_needed_sb(fixed)


def _build_rect_bytes(left, right, top, bottom):
    """Build byte-aligned RECT structure."""
    nbits = max(_bits_needed_sb(left), _bits_needed_sb(right),
                _bits_needed_sb(top), _bits_needed_sb(bottom), 1)
    bw = _BitWriter()
    bw.write_ub(nbits, 5)
    bw.write_sb(left, nbits)
    bw.write_sb(right, nbits)
    bw.write_sb(top, nbits)
    bw.write_sb(bottom, nbits)
    return bw.to_bytes()


def _build_matrix_bytes(trans_x=0, trans_y=0, scale_x=None, scale_y=None):
    """Build byte-aligned MATRIX structure."""
    bw = _BitWriter()
    has_scale = scale_x is not None and scale_y is not None
    bw.write_ub(int(has_scale), 1)
    if has_scale:
        nbits = max(_bits_needed_fb(scale_x), _bits_needed_fb(scale_y))
        bw.write_ub(nbits, 5)
        bw.write_fb(scale_x, nbits)
        bw.write_fb(scale_y, nbits)
    # No rotate
    bw.write_ub(0, 1)
    # Translate
    if trans_x == 0 and trans_y == 0:
        bw.write_ub(0, 5)
    else:
        nbits = max(_bits_needed_sb(trans_x), _bits_needed_sb(trans_y))
        bw.write_ub(nbits, 5)
        bw.write_sb(trans_x, nbits)
        bw.write_sb(trans_y, nbits)
    return bw.to_bytes()


def _build_glyph_shape_binary(edges):
    """Build binary SHAPE data for a single font glyph.

    Font glyphs have NumFillBits=1, NumLineBits=0 and use
    fill style 1 as the implicit glyph fill.
    """
    bw = _BitWriter()
    bw.write_ub(1, 4)  # NumFillBits
    bw.write_ub(0, 4)  # NumLineBits
    fill_bits = 1

    for edge in edges:
        if isinstance(edge, ShapeSetup):
            has_move = edge.x is not None or edge.y is not None
            has_fill0 = edge.fillStyle0 is not None
            has_fill1 = edge.fillStyle1 is not None
            state_flags = ((int(has_fill1) << 2) |
                           (int(has_fill0) << 1) |
                           (int(has_move)))
            bw.write_ub(0, 1)  # TypeFlag = 0 (non-edge)
            bw.write_ub(state_flags, 5)
            if has_move:
                x = edge.x if edge.x is not None else 0
                y = edge.y if edge.y is not None else 0
                move_bits = max(_bits_needed_sb(x), _bits_needed_sb(y), 1)
                bw.write_ub(move_bits, 5)
                bw.write_sb(x, move_bits)
                bw.write_sb(y, move_bits)
            if has_fill0:
                bw.write_ub(edge.fillStyle0, fill_bits)
            if has_fill1:
                bw.write_ub(edge.fillStyle1, fill_bits)

        elif isinstance(edge, LineTo):
            dx, dy = edge.x, edge.y
            actual_bits = max(_bits_needed_sb(dx), _bits_needed_sb(dy), 2)
            num_bits_field = actual_bits - 2
            bw.write_ub(1, 1)  # TypeFlag = 1 (edge)
            bw.write_ub(1, 1)  # StraightFlag
            bw.write_ub(num_bits_field, 4)
            if dx != 0 and dy != 0:
                bw.write_ub(1, 1)  # GeneralLine
                bw.write_sb(dx, actual_bits)
                bw.write_sb(dy, actual_bits)
            elif dx == 0:
                bw.write_ub(0, 1)  # Not general
                bw.write_ub(1, 1)  # VertLine
                bw.write_sb(dy, actual_bits)
            else:
                bw.write_ub(0, 1)  # Not general
                bw.write_ub(0, 1)  # HorizLine
                bw.write_sb(dx, actual_bits)

        elif isinstance(edge, CurveTo):
            cx, cy = edge.x1, edge.y1
            ax, ay = edge.x2, edge.y2
            actual_bits = max(_bits_needed_sb(cx), _bits_needed_sb(cy),
                              _bits_needed_sb(ax), _bits_needed_sb(ay), 2)
            num_bits_field = actual_bits - 2
            bw.write_ub(1, 1)  # TypeFlag = 1 (edge)
            bw.write_ub(0, 1)  # CurvedFlag
            bw.write_ub(num_bits_field, 4)
            bw.write_sb(cx, actual_bits)
            bw.write_sb(cy, actual_bits)
            bw.write_sb(ax, actual_bits)
            bw.write_sb(ay, actual_bits)

    # EndShape
    bw.write_ub(0, 1)  # TypeFlag = 0
    bw.write_ub(0, 5)  # All flags zero
    return bw.to_bytes()


# ---------------------------------------------------------------------------
# Fill style types
# ---------------------------------------------------------------------------

class SolidFill:
    """Solid color fill."""
    def __init__(self, r, g, b, a=None):
        self.r = r
        self.g = g
        self.b = b
        self.a = a  # Alpha (0-255), None for RGB-only (DefineShape/DefineShape2)

    def to_xml(self, parent):
        solid = SubElement(parent, "Solid")
        color_el = SubElement(solid, "color")
        attrs = {"red": str(self.r), "green": str(self.g), "blue": str(self.b)}
        if self.a is not None:
            attrs["alpha"] = str(self.a)
        SubElement(color_el, "Color", **attrs)


class LinearGradientFill:
    """Linear gradient fill with a transform matrix and color stops."""
    def __init__(self, matrix, stops):
        """
        matrix: dict with keys from {scaleX, scaleY, skewX, skewY, transX, transY}
        stops: list of (position, r, g, b) tuples
        """
        self.matrix = matrix
        self.stops = stops

    def to_xml(self, parent):
        grad = SubElement(parent, "LinearGradient")
        mat_el = SubElement(grad, "matrix")
        attrs = {}
        for key in ("scaleX", "scaleY", "skewX", "skewY", "transX", "transY"):
            if key in self.matrix:
                val = self.matrix[key]
                if isinstance(val, float):
                    attrs[key] = f"{val:.16f}"
                else:
                    attrs[key] = str(val)
        SubElement(mat_el, "Transform", **attrs)
        colors = SubElement(grad, "gradientColors")
        for pos, r, g, b in self.stops:
            item = SubElement(colors, "GradientItem", position=str(pos))
            c = SubElement(item, "color")
            SubElement(c, "Color", red=str(r), green=str(g), blue=str(b))


class RadialGradientFill:
    """Radial gradient fill with a transform matrix and color stops."""
    def __init__(self, matrix, stops):
        self.matrix = matrix
        self.stops = stops

    def to_xml(self, parent):
        grad = SubElement(parent, "RadialGradient")
        mat_el = SubElement(grad, "matrix")
        attrs = {}
        for key in ("scaleX", "scaleY", "skewX", "skewY", "transX", "transY"):
            if key in self.matrix:
                val = self.matrix[key]
                if isinstance(val, float):
                    attrs[key] = f"{val:.16f}"
                else:
                    attrs[key] = str(val)
        SubElement(mat_el, "Transform", **attrs)
        colors = SubElement(grad, "gradientColors")
        for pos, r, g, b in self.stops:
            item = SubElement(colors, "GradientItem", position=str(pos))
            c = SubElement(item, "color")
            SubElement(c, "Color", red=str(r), green=str(g), blue=str(b))


class ClippedBitmapFill:
    """Clipped bitmap fill referencing a DefineBits object."""
    def __init__(self, object_id, matrix):
        self.object_id = object_id
        self.matrix = matrix

    def to_xml(self, parent):
        bmp = SubElement(parent, "ClippedBitmap", objectID=str(self.object_id))
        mat_el = SubElement(bmp, "matrix")
        attrs = {}
        for key in ("scaleX", "scaleY", "skewX", "skewY", "transX", "transY"):
            if key in self.matrix:
                val = self.matrix[key]
                if isinstance(val, float):
                    attrs[key] = f"{val:.16f}"
                else:
                    attrs[key] = str(val)
        SubElement(mat_el, "Transform", **attrs)


class RepeatingBitmapFill:
    """Repeating (tiled) bitmap fill referencing a DefineBits object."""
    def __init__(self, object_id, matrix):
        self.object_id = object_id
        self.matrix = matrix

    def to_xml(self, parent):
        bmp = SubElement(parent, "TiledBitmap", objectID=str(self.object_id))
        mat_el = SubElement(bmp, "matrix")
        attrs = {}
        for key in ("scaleX", "scaleY", "skewX", "skewY", "transX", "transY"):
            if key in self.matrix:
                val = self.matrix[key]
                if isinstance(val, float):
                    attrs[key] = f"{val:.16f}"
                else:
                    attrs[key] = str(val)
        SubElement(mat_el, "Transform", **attrs)


class NonSmoothedClippedBitmapFill:
    """Non-smoothed clipped bitmap fill (type 0x43) referencing a DefineBits object."""
    def __init__(self, object_id, matrix):
        self.object_id = object_id
        self.matrix = matrix

    def to_xml(self, parent):
        bmp = SubElement(parent, "ClippedBitmap2", objectID=str(self.object_id))
        mat_el = SubElement(bmp, "matrix")
        attrs = {}
        for key in ("scaleX", "scaleY", "skewX", "skewY", "transX", "transY"):
            if key in self.matrix:
                val = self.matrix[key]
                if isinstance(val, float):
                    attrs[key] = f"{val:.16f}"
                else:
                    attrs[key] = str(val)
        SubElement(mat_el, "Transform", **attrs)


class NonSmoothedRepeatingBitmapFill:
    """Non-smoothed repeating bitmap fill (type 0x42) referencing a DefineBits object."""
    def __init__(self, object_id, matrix):
        self.object_id = object_id
        self.matrix = matrix

    def to_xml(self, parent):
        bmp = SubElement(parent, "TiledBitmap2", objectID=str(self.object_id))
        mat_el = SubElement(bmp, "matrix")
        attrs = {}
        for key in ("scaleX", "scaleY", "skewX", "skewY", "transX", "transY"):
            if key in self.matrix:
                val = self.matrix[key]
                if isinstance(val, float):
                    attrs[key] = f"{val:.16f}"
                else:
                    attrs[key] = str(val)
        SubElement(mat_el, "Transform", **attrs)


# ---------------------------------------------------------------------------
# Color transform
# ---------------------------------------------------------------------------

class ColorTransform:
    """Color transform (CXFORMWITHALPHA).

    Applies multiplicative and additive adjustments to each color channel.
    The multiply factors use 8.8 fixed-point: 256 = 1.0 (identity).
    The add terms are signed integers (-255 to 255).

    Result: channel' = clamp((channel * factor / 256) + add, 0, 255)
    """
    def __init__(self, factor_red=256, factor_green=256, factor_blue=256,
                 factor_alpha=256, add_red=0, add_green=0, add_blue=0,
                 add_alpha=0):
        self.factor_red = factor_red
        self.factor_green = factor_green
        self.factor_blue = factor_blue
        self.factor_alpha = factor_alpha
        self.add_red = add_red
        self.add_green = add_green
        self.add_blue = add_blue
        self.add_alpha = add_alpha

    def to_xml(self, parent):
        ct_el = SubElement(parent, "colorTransform")
        attrs = {
            "factorRed": str(self.factor_red),
            "factorGreen": str(self.factor_green),
            "factorBlue": str(self.factor_blue),
            "factorAlpha": str(self.factor_alpha),
        }
        if self.add_red != 0:
            attrs["addRed"] = str(self.add_red)
        if self.add_green != 0:
            attrs["addGreen"] = str(self.add_green)
        if self.add_blue != 0:
            attrs["addBlue"] = str(self.add_blue)
        if self.add_alpha != 0:
            attrs["addAlpha"] = str(self.add_alpha)
        SubElement(ct_el, "ColorTransform2", **attrs)


# ---------------------------------------------------------------------------
# Line style
# ---------------------------------------------------------------------------

class LineStyle:
    """Line style with width (in twips) and color."""
    def __init__(self, width, r, g, b, a=None):
        self.width = width
        self.r = r
        self.g = g
        self.b = b
        self.a = a  # Alpha (0-255), None for RGB-only

    def to_xml(self, parent):
        ls = SubElement(parent, "LineStyle", width=str(self.width))
        color_el = SubElement(ls, "color")
        attrs = {"red": str(self.r), "green": str(self.g), "blue": str(self.b)}
        if self.a is not None:
            attrs["alpha"] = str(self.a)
        SubElement(color_el, "Color", **attrs)


# ---------------------------------------------------------------------------
# Edge records
# ---------------------------------------------------------------------------

class ShapeSetup:
    """Style change / move-to record.

    With no arguments, this is the end-of-shape marker.
    """
    def __init__(self, x=None, y=None, fillStyle0=None, fillStyle1=None,
                 lineStyle=None, new_styles=None):
        self.x = x
        self.y = y
        self.fillStyle0 = fillStyle0
        self.fillStyle1 = fillStyle1
        self.lineStyle = lineStyle
        self.new_styles = new_styles  # (fill_styles_list, line_styles_list) for DefineShape2

    def to_xml(self, parent):
        attrs = {}
        if self.x is not None:
            attrs["x"] = str(self.x)
        if self.y is not None:
            attrs["y"] = str(self.y)
        if self.fillStyle0 is not None:
            attrs["fillStyle0"] = str(self.fillStyle0)
        if self.fillStyle1 is not None:
            attrs["fillStyle1"] = str(self.fillStyle1)
        if self.lineStyle is not None:
            attrs["lineStyle"] = str(self.lineStyle)
        el = SubElement(parent, "ShapeSetup", **attrs)
        if self.new_styles is not None:
            fills, lines = self.new_styles
            styles_el = SubElement(el, "styles")
            style_list = SubElement(styles_el, "StyleList")
            fill_el = SubElement(style_list, "fillStyles")
            for f in fills:
                f.to_xml(fill_el)
            line_el = SubElement(style_list, "lineStyles")
            for l in lines:
                l.to_xml(line_el)


class LineTo:
    """Straight edge record (delta coordinates in twips)."""
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def to_xml(self, parent):
        SubElement(parent, "LineTo", x=str(self.x), y=str(self.y))


class CurveTo:
    """Quadratic bezier curve edge record (control and anchor deltas in twips)."""
    def __init__(self, x1, y1, x2, y2):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2

    def to_xml(self, parent):
        SubElement(parent, "CurveTo",
                   x1=str(self.x1), y1=str(self.y1),
                   x2=str(self.x2), y2=str(self.y2))


# ---------------------------------------------------------------------------
# Shape definition helper
# ---------------------------------------------------------------------------

class ShapeDefinition:
    """Collects fill styles, line styles, and edge records for a DefineShape tag."""
    def __init__(self, object_id, bounds, shape_version=1):
        self.object_id = object_id
        self.bounds = bounds  # (left, right, top, bottom) in twips
        self.fill_styles = []
        self.line_styles = []
        self.edges = []
        self.shape_version = shape_version  # 1 = DefineShape, 2 = DefineShape2, 3 = DefineShape3

    def add_fill(self, fill):
        self.fill_styles.append(fill)
        return len(self.fill_styles)  # 1-based index

    def add_line_style(self, style):
        self.line_styles.append(style)
        return len(self.line_styles)  # 1-based index

    def add_edge(self, edge):
        self.edges.append(edge)

    def add_edges(self, edges):
        self.edges.extend(edges)

    def to_xml(self, parent):
        version_tags = {1: "DefineShape", 2: "DefineShape2", 3: "DefineShape3"}
        tag_name = version_tags.get(self.shape_version, "DefineShape")
        shape_el = SubElement(parent, tag_name, objectID=str(self.object_id))
        bounds_el = SubElement(shape_el, "bounds")
        left, right, top, bottom = self.bounds
        SubElement(bounds_el, "Rectangle",
                   left=str(left), right=str(right),
                   top=str(top), bottom=str(bottom))
        styles_el = SubElement(shape_el, "styles")
        style_list = SubElement(styles_el, "StyleList")
        fill_el = SubElement(style_list, "fillStyles")
        for f in self.fill_styles:
            f.to_xml(fill_el)
        line_el = SubElement(style_list, "lineStyles")
        for l in self.line_styles:
            l.to_xml(line_el)
        shapes_el = SubElement(shape_el, "shapes")
        shape_inner = SubElement(shapes_el, "Shape")
        edges_el = SubElement(shape_inner, "edges")
        for e in self.edges:
            e.to_xml(edges_el)
        # End shape marker
        SubElement(edges_el, "ShapeSetup")


# ---------------------------------------------------------------------------
# Sprite definition helper
# ---------------------------------------------------------------------------

class SpriteDefinition:
    """Collects sub-tags (PlaceObject2, ShowFrame) for a DefineSprite tag."""
    def __init__(self, object_id, frame_count=1):
        self.object_id = object_id
        self.frame_count = frame_count
        self.sub_tags = []

    def place_object(self, object_id, depth, trans_x=0, trans_y=0,
                     scale_x=None, scale_y=None):
        """Place an object in the sprite's display list."""
        self.sub_tags.append(("PlaceObject2", {
            "object_id": object_id,
            "depth": depth,
            "trans_x": trans_x,
            "trans_y": trans_y,
            "scale_x": scale_x,
            "scale_y": scale_y,
        }))

    def show_frame(self):
        """Add a ShowFrame to the sprite's timeline."""
        self.sub_tags.append(("ShowFrame", None))

    def to_xml(self, parent):
        sprite_el = SubElement(parent, "DefineSprite",
                               objectID=str(self.object_id),
                               frames=str(self.frame_count))
        tags_el = SubElement(sprite_el, "tags")

        for tag_type, tag_data in self.sub_tags:
            if tag_type == "PlaceObject2":
                d = tag_data
                po = SubElement(tags_el, "PlaceObject2",
                                replace="0",
                                depth=str(d["depth"]),
                                objectID=str(d["object_id"]))
                transform_el = SubElement(po, "transform")
                attrs = {
                    "transX": str(d["trans_x"]),
                    "transY": str(d["trans_y"]),
                }
                if d.get("scale_x") is not None:
                    attrs["scaleX"] = f"{d['scale_x']:.16f}"
                if d.get("scale_y") is not None:
                    attrs["scaleY"] = f"{d['scale_y']:.16f}"
                SubElement(transform_el, "Transform", **attrs)
            elif tag_type == "ShowFrame":
                SubElement(tags_el, "ShowFrame")

        SubElement(tags_el, "End")


# ---------------------------------------------------------------------------
# Main SWF builder
# ---------------------------------------------------------------------------

class SWFMLBuilder:
    """Builds a complete SWF file via swfmill XML.

    Usage:
        swf = SWFMLBuilder(width=550, height=400)
        swf.set_background(255, 255, 255)
        shape = swf.define_shape(object_id=1, bounds=(0, 11000, 0, 8000))
        shape.add_fill(SolidFill(255, 0, 0))
        shape.add_edge(ShapeSetup(x=100, y=200, fillStyle1=1))
        shape.add_edge(LineTo(300, 0))
        ...
        swf.place_object(object_id=1, depth=1)
        swf.show_frame()
        swf.save("test.swf")
    """

    def __init__(self, width=550, height=400, fps=12, version=4):
        """
        width/height: stage size in pixels (converted to twips internally)
        fps: frame rate
        version: SWF version
        """
        self.width_twips = width * 20
        self.height_twips = height * 20
        self.fps = fps
        self.version = version
        self.tags = []
        self._frame_count = 0

    def set_background(self, r, g, b):
        self.tags.append(("SetBackgroundColor", (r, g, b)))

    def add_trace(self, text):
        """Add a DoAction tag with a Push+Trace sequence."""
        self.tags.append(("DoAction", text))

    def define_shape(self, object_id, bounds, shape_version=1):
        """Create and register a shape definition. Returns the ShapeDefinition for adding styles/edges."""
        shape = ShapeDefinition(object_id, bounds, shape_version)
        self.tags.append(("DefineShape", shape))
        return shape

    def define_bits_jpeg(self, object_id, jpeg_data_base64):
        """Add a DefineBits tag with base64-encoded JPEG data."""
        self.tags.append(("DefineBits", (object_id, jpeg_data_base64)))

    def add_jpeg_tables(self, tables_base64):
        """Add a JPEGTables tag (UnknownTag 0x08) with base64-encoded data."""
        self.tags.append(("JPEGTables", tables_base64))

    def define_bits_lossless(self, object_id, width, height, pixels):
        """Add a DefineBitsLossless tag (tag 20, format 5 = 24-bit RGB).

        pixels: list of (r, g, b) tuples, length must equal width * height.
        Each channel is 0-255.
        """
        assert len(pixels) == width * height, \
            f"Expected {width*height} pixels, got {len(pixels)}"
        # Build uncompressed pixel data: PIX24 = [0x00, R, G, B] per pixel
        raw = bytearray()
        for r, g, b in pixels:
            raw.extend((0x00, r, g, b))
        compressed = zlib.compress(bytes(raw))
        # Tag body: CharacterID(UI16) + Format(UI8) + Width(UI16) + Height(UI16) + ZLIB data
        tag_body = struct.pack('<HBHH', object_id, 5, width, height) + compressed
        tag_b64 = base64.b64encode(tag_body).decode('ascii')
        self.tags.append(("DefineBitsLossless", tag_b64))

    def define_bits_lossless2(self, object_id, width, height, pixels):
        """Add a DefineBitsLossless2 tag (tag 36, format 5 = 32-bit ARGB).

        pixels: list of (r, g, b, a) tuples, length must equal width * height.
        Each channel is 0-255.
        """
        assert len(pixels) == width * height, \
            f"Expected {width*height} pixels, got {len(pixels)}"
        # Build uncompressed pixel data: ARGB per pixel
        raw = bytearray()
        for r, g, b, a in pixels:
            raw.extend((a, r, g, b))
        compressed = zlib.compress(bytes(raw))
        # Tag body: CharacterID(UI16) + Format(UI8) + Width(UI16) + Height(UI16) + ZLIB data
        tag_body = struct.pack('<HBHH', object_id, 5, width, height) + compressed
        tag_b64 = base64.b64encode(tag_body).decode('ascii')
        self.tags.append(("DefineBitsLossless2", tag_b64))

    def define_bits_jpeg2(self, object_id, jpeg_data_bytes):
        """Add a DefineBitsJPEG2 tag (tag 21) with self-contained JPEG data.

        jpeg_data_bytes: raw JPEG file bytes (complete JPEG, no JPEGTables needed).
        """
        # Tag body: CharacterID(UI16) + raw JPEG data
        tag_body = struct.pack('<H', object_id) + jpeg_data_bytes
        tag_b64 = base64.b64encode(tag_body).decode('ascii')
        self.tags.append(("DefineBitsJPEG2", tag_b64))

    def define_bits_jpeg3(self, object_id, jpeg_data_bytes, alpha_data):
        """Add a DefineBitsJPEG3 tag (tag 35) with JPEG data + zlib-compressed alpha.

        jpeg_data_bytes: raw JPEG file bytes (complete JPEG).
        alpha_data: bytes/list of alpha values, one byte per pixel (length = width * height).
        """
        compressed_alpha = zlib.compress(bytes(alpha_data))
        # Tag body: CharacterID(UI16) + AlphaDataOffset(UI32) + JPEG data + compressed alpha
        alpha_data_offset = len(jpeg_data_bytes)
        tag_body = struct.pack('<HI', object_id, alpha_data_offset) + jpeg_data_bytes + compressed_alpha
        tag_b64 = base64.b64encode(tag_body).decode('ascii')
        self.tags.append(("DefineBitsJPEG3", tag_b64))

    def define_font(self, object_id, glyphs):
        """Add a DefineFont tag (tag 10) with glyph shapes.

        object_id: character ID for the font
        glyphs: list of edge-record lists, one per glyph. Each glyph's
                edges should use fillStyle1=1 as the implicit glyph fill.
                Example: [[ShapeSetup(x=0, y=0, fillStyle1=1), LineTo(500, 0), ...], ...]
        """
        glyph_binaries = [_build_glyph_shape_binary(g) for g in glyphs]
        num_glyphs = len(glyphs)
        offset_table_size = num_glyphs * 2  # UI16 per glyph offset
        # Calculate offsets from start of offset table
        offsets = []
        pos = offset_table_size
        for gb in glyph_binaries:
            offsets.append(pos)
            pos += len(gb)
        # Build tag body: FontID + OffsetTable + GlyphShapes
        body = struct.pack('<H', object_id)
        for off in offsets:
            body += struct.pack('<H', off)
        for gb in glyph_binaries:
            body += gb
        tag_b64 = base64.b64encode(body).decode('ascii')
        self.tags.append(("DefineFont", tag_b64))

    def define_text(self, object_id, bounds, font_id, text_height, color,
                    glyphs, x_offset=0, y_offset=0,
                    matrix_trans_x=0, matrix_trans_y=0):
        """Add a DefineText tag (tag 11) with a single text record.

        object_id: character ID for this text object
        bounds: (left, right, top, bottom) bounding box in twips
        font_id: references a DefineFont character ID
        text_height: em-square height in twips (controls glyph scaling)
        color: (r, g, b) tuple, each 0-255
        glyphs: list of (glyph_index, advance) tuples
        x_offset: starting X offset in twips (default 0)
        y_offset: starting Y offset in twips (default 0)
        matrix_trans_x: MATRIX translateX in twips
        matrix_trans_y: MATRIX translateY in twips
        """
        body = bytearray()
        # CharacterID
        body += struct.pack('<H', object_id)
        # TextBounds (RECT)
        body += _build_rect_bytes(*bounds)
        # Matrix
        body += _build_matrix_bytes(trans_x=matrix_trans_x, trans_y=matrix_trans_y)
        # Calculate required bit widths
        max_glyph_idx = max(g[0] for g in glyphs) if glyphs else 0
        glyph_bits = max(max_glyph_idx.bit_length(), 1) if max_glyph_idx > 0 else 1
        advances = [g[1] for g in glyphs]
        advance_bits = max(max(_bits_needed_sb(a) for a in advances), 2) if advances else 2
        body += struct.pack('BB', glyph_bits, advance_bits)
        # Single TextRecord
        # Flags: bit7=1(type), bit3=HasFont, bit2=HasColor, bit1=HasXOffset, bit0=HasYOffset
        # NOTE: the recompiler maps bit1->x_offset and bit0->y_offset
        flags = 0x80 | 0x08 | 0x04  # HasFont + HasColor
        has_x = x_offset != 0
        has_y = y_offset != 0
        if has_x:
            flags |= 0x02  # bit 1 -> recompiler reads as x_offset
        if has_y:
            flags |= 0x01  # bit 0 -> recompiler reads as y_offset
        body += struct.pack('B', flags)
        # FontID
        body += struct.pack('<H', font_id)
        # Color (RGB)
        r, g, b = color
        body += struct.pack('BBB', r, g, b)
        # X offset
        if has_x:
            body += struct.pack('<h', x_offset)
        # Y offset
        if has_y:
            body += struct.pack('<h', y_offset)
        # TextHeight
        body += struct.pack('<H', text_height)
        # GlyphCount
        body += struct.pack('B', len(glyphs))
        # Glyph entries (bit-packed)
        bw = _BitWriter()
        for glyph_index, advance in glyphs:
            bw.write_ub(glyph_index, glyph_bits)
            bw.write_sb(advance, advance_bits)
        body += bw.to_bytes()
        # End marker
        body += b'\x00'

        tag_b64 = base64.b64encode(bytes(body)).decode('ascii')
        self.tags.append(("DefineText", tag_b64))

    def place_object(self, object_id, depth, trans_x=0, trans_y=0,
                     scale_x=None, scale_y=None,
                     skew_x=None, skew_y=None,
                     color_transform=None, clip_depth=None):
        self.tags.append(("PlaceObject2", {
            "object_id": object_id,
            "depth": depth,
            "trans_x": trans_x,
            "trans_y": trans_y,
            "scale_x": scale_x,
            "scale_y": scale_y,
            "skew_x": skew_x,
            "skew_y": skew_y,
            "color_transform": color_transform,
            "clip_depth": clip_depth,
        }))

    def define_sprite(self, object_id, frame_count=1):
        """Create a sprite (movie clip) definition. Returns a SpriteDefinition for adding sub-tags."""
        sprite = SpriteDefinition(object_id, frame_count)
        self.tags.append(("DefineSprite", sprite))
        return sprite

    def show_frame(self):
        self._frame_count += 1
        self.tags.append(("ShowFrame", None))

    def _build_xml(self):
        root = Element("swf", version=str(self.version), compressed="0")
        header = SubElement(root, "Header",
                            framerate=str(self.fps),
                            frames=str(self._frame_count))
        size_el = SubElement(header, "size")
        SubElement(size_el, "Rectangle",
                   left="0", right=str(self.width_twips),
                   top="0", bottom=str(self.height_twips))
        tags_el = SubElement(header, "tags")

        for tag_type, tag_data in self.tags:
            if tag_type == "SetBackgroundColor":
                r, g, b = tag_data
                bg = SubElement(tags_el, "SetBackgroundColor")
                c = SubElement(bg, "color")
                SubElement(c, "Color", red=str(r), green=str(g), blue=str(b))

            elif tag_type == "DoAction":
                da = SubElement(tags_el, "DoAction")
                actions = SubElement(da, "actions")
                push = SubElement(actions, "PushData")
                items = SubElement(push, "items")
                SubElement(items, "StackString", value=str(tag_data))
                SubElement(actions, "Trace")
                SubElement(actions, "EndAction")

            elif tag_type == "JPEGTables":
                unk = SubElement(tags_el, "UnknownTag", id="0x08")
                data_el = SubElement(unk, "data")
                data_el.text = tag_data

            elif tag_type == "DefineBitsLossless":
                unk = SubElement(tags_el, "UnknownTag", id="0x14")
                data_el = SubElement(unk, "data")
                data_el.text = tag_data

            elif tag_type == "DefineBitsLossless2":
                unk = SubElement(tags_el, "UnknownTag", id="0x24")
                data_el = SubElement(unk, "data")
                data_el.text = tag_data

            elif tag_type == "DefineBitsJPEG2":
                unk = SubElement(tags_el, "UnknownTag", id="0x15")
                data_el = SubElement(unk, "data")
                data_el.text = tag_data

            elif tag_type == "DefineBitsJPEG3":
                unk = SubElement(tags_el, "UnknownTag", id="0x23")
                data_el = SubElement(unk, "data")
                data_el.text = tag_data

            elif tag_type == "DefineBits":
                obj_id, jpeg_b64 = tag_data
                db = SubElement(tags_el, "DefineBits", objectID=str(obj_id))
                data_wrap = SubElement(db, "data")
                data_el = SubElement(data_wrap, "data")
                data_el.text = jpeg_b64

            elif tag_type == "DefineFont":
                # Tag 10 = 0x0A, emitted as raw binary via UnknownTag
                unk = SubElement(tags_el, "UnknownTag", id="0x0a")
                data_el = SubElement(unk, "data")
                data_el.text = tag_data

            elif tag_type == "DefineText":
                # Tag 11 = 0x0B, emitted as raw binary via UnknownTag
                unk = SubElement(tags_el, "UnknownTag", id="0x0b")
                data_el = SubElement(unk, "data")
                data_el.text = tag_data

            elif tag_type == "DefineShape":
                tag_data.to_xml(tags_el)

            elif tag_type == "DefineSprite":
                tag_data.to_xml(tags_el)

            elif tag_type == "PlaceObject2":
                d = tag_data
                po_attrs = {
                    "replace": "0",
                    "depth": str(d["depth"]),
                    "objectID": str(d["object_id"]),
                }
                if d.get("clip_depth") is not None:
                    po_attrs["clipDepth"] = str(d["clip_depth"])
                po = SubElement(tags_el, "PlaceObject2", **po_attrs)
                transform_el = SubElement(po, "transform")
                attrs = {
                    "transX": str(d["trans_x"]),
                    "transY": str(d["trans_y"]),
                }
                if d.get("scale_x") is not None:
                    attrs["scaleX"] = f"{d['scale_x']:.16f}"
                if d.get("scale_y") is not None:
                    attrs["scaleY"] = f"{d['scale_y']:.16f}"
                if d.get("skew_x") is not None:
                    attrs["skewX"] = f"{d['skew_x']:.16f}"
                if d.get("skew_y") is not None:
                    attrs["skewY"] = f"{d['skew_y']:.16f}"
                SubElement(transform_el, "Transform", **attrs)
                if d.get("color_transform") is not None:
                    d["color_transform"].to_xml(po)

            elif tag_type == "ShowFrame":
                SubElement(tags_el, "ShowFrame")

        SubElement(tags_el, "End")
        return root

    def save(self, output_path):
        """Generate the SWF file at output_path."""
        if shutil.which("swfmill") is None:
            print("Error: swfmill not found. Install with: apt install swfmill",
                  file=sys.stderr)
            sys.exit(1)

        root = self._build_xml()
        rough = tostring(root, encoding="unicode")
        dom = minidom.parseString(rough)
        pretty = dom.toprettyxml(indent="  ", encoding="UTF-8")

        # minidom adds an extra XML declaration; we write it ourselves
        xml_str = pretty.decode("UTF-8")

        # Write XML to a temp file, run swfmill, clean up
        xml_path = output_path.replace(".swf", ".xml")
        with open(xml_path, "w", encoding="utf-8") as f:
            f.write(xml_str)

        result = subprocess.run(
            ["swfmill", "xml2swf", xml_path, output_path],
            capture_output=True, text=True
        )
        if result.returncode != 0:
            print(f"swfmill error:\n{result.stderr}", file=sys.stderr)
            sys.exit(1)

        os.remove(xml_path)
        print(f"Created {output_path}")
