"""
Helper module for generating SWF files via swfmill.

Provides a Python API that generates swfmill-compatible XML and invokes
`swfmill xml2swf` to produce SWF binary files.  Used by each graphics
test's create_test_swf.py script.
"""

import base64
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


class LineStyle2:
    """Advanced line style (LINESTYLE2) with cap/join control.

    Used with DefineShape4 (shape_version=4).
    Cap styles: 0=round, 1=none, 2=square.
    Join styles: 0=round, 1=bevel, 2=miter.
    """
    def __init__(self, width, r, g, b, a=255,
                 start_cap=0, end_cap=0, join_style=0, miter_limit=None):
        self.width = width
        self.r = r
        self.g = g
        self.b = b
        self.a = a
        self.start_cap = start_cap
        self.end_cap = end_cap
        self.join_style = join_style
        self.miter_limit = miter_limit  # FIXED8 (8.8), only if join_style==2


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
# SWF binary bit-packing utilities (for DefineShape4 raw encoding)
# ---------------------------------------------------------------------------

class SWFBitWriter:
    """Writes SWF-format bit-packed binary data."""
    def __init__(self):
        self.data = bytearray()
        self._current_byte = 0
        self._bits_left = 8

    def write_ub(self, value, nbits):
        """Write an unsigned bit field."""
        for i in range(nbits - 1, -1, -1):
            bit = (value >> i) & 1
            self._current_byte = (self._current_byte << 1) | bit
            self._bits_left -= 1
            if self._bits_left == 0:
                self.data.append(self._current_byte)
                self._current_byte = 0
                self._bits_left = 8

    def write_sb(self, value, nbits):
        """Write a signed bit field (two's complement)."""
        if value < 0:
            value = (1 << nbits) + value
        self.write_ub(value, nbits)

    def flush_byte(self):
        """Pad the current byte with zeros and flush."""
        if self._bits_left < 8:
            self._current_byte <<= self._bits_left
            self.data.append(self._current_byte)
            self._current_byte = 0
            self._bits_left = 8

    def write_ui8(self, value):
        """Write a byte-aligned UI8."""
        self.flush_byte()
        self.data.append(value & 0xFF)

    def write_ui16(self, value):
        """Write a byte-aligned UI16 (little-endian)."""
        self.flush_byte()
        self.data.extend(struct.pack('<H', value))

    def write_rgba(self, r, g, b, a):
        """Write an RGBA color (4 bytes)."""
        self.flush_byte()
        self.data.extend([r, g, b, a])

    def write_rect(self, xmin, xmax, ymin, ymax):
        """Write a RECT structure."""
        values = [xmin, xmax, ymin, ymax]
        max_val = max(abs(v) for v in values) if any(values) else 0
        if max_val == 0:
            nbits = 1
        else:
            nbits = max_val.bit_length() + 1  # +1 for sign bit
        self.write_ub(nbits, 5)
        for v in values:
            self.write_sb(v, nbits)
        self.flush_byte()

    def get_bytes(self):
        """Return the accumulated bytes (flushes any partial byte)."""
        self.flush_byte()
        return bytes(self.data)


def _sb_bits_needed(*values):
    """Calculate the minimum number of bits for signed bit fields."""
    max_val = max(abs(v) for v in values) if any(values) else 0
    if max_val == 0:
        return 1
    return max_val.bit_length() + 1  # +1 for sign bit


def _ub_bits_needed(*values):
    """Calculate the minimum number of bits for unsigned bit fields."""
    max_val = max(values) if any(values) else 0
    if max_val == 0:
        return 1
    return max_val.bit_length()


def _encode_shape4_fill_style(fill, writer):
    """Encode a single fill style into the binary writer (RGBA mode)."""
    if isinstance(fill, SolidFill):
        writer.write_ui8(0x00)  # type = solid
        a = fill.a if fill.a is not None else 255
        writer.write_rgba(fill.r, fill.g, fill.b, a)
    else:
        raise ValueError(f"Unsupported fill type for DefineShape4 binary encoding: {type(fill)}")


def _encode_linestyle2(ls, writer):
    """Encode a single LINESTYLE2 record into the binary writer."""
    writer.write_ui16(ls.width)
    # Bit fields: StartCapStyle(2), JoinStyle(2), HasFillFlag(1),
    # NoHScaleFlag(1), NoVScaleFlag(1), PixelHintingFlag(1),
    # Reserved(5), NoClose(1), EndCapStyle(2)
    writer.write_ub(ls.start_cap, 2)
    writer.write_ub(ls.join_style, 2)
    writer.write_ub(0, 1)  # HasFillFlag = 0 (using color, not fill)
    writer.write_ub(0, 1)  # NoHScaleFlag
    writer.write_ub(0, 1)  # NoVScaleFlag
    writer.write_ub(0, 1)  # PixelHintingFlag
    writer.write_ub(0, 5)  # Reserved
    writer.write_ub(0, 1)  # NoClose
    writer.write_ub(ls.end_cap, 2)
    # MiterLimitFactor if JoinStyle == 2
    if ls.join_style == 2:
        ml = ls.miter_limit if ls.miter_limit is not None else 2.0
        # FIXED8: 8.8 fixed point (UI16 where high byte = integer, low byte = fraction)
        fixed8 = int(ml * 256) & 0xFFFF
        writer.write_ui16(fixed8)
    # Color (RGBA) - since HasFillFlag=0
    writer.write_rgba(ls.r, ls.g, ls.b, ls.a)


def _encode_shape_records(edges, fill_count, line_count, writer):
    """Encode shape records (edges + end marker) into the binary writer."""
    fill_bits = _ub_bits_needed(fill_count)
    line_bits = _ub_bits_needed(line_count)
    writer.write_ub(fill_bits, 4)
    writer.write_ub(line_bits, 4)

    for edge in edges:
        if isinstance(edge, ShapeSetup):
            if (edge.x is None and edge.y is None and
                edge.fillStyle0 is None and edge.fillStyle1 is None and
                edge.lineStyle is None and edge.new_styles is None):
                continue  # Skip end markers, we'll add our own
            # Non-edge record: TypeFlag=0
            state_move = edge.x is not None or edge.y is not None
            state_fs0 = edge.fillStyle0 is not None
            state_fs1 = edge.fillStyle1 is not None
            state_ls = edge.lineStyle is not None
            state_ns = edge.new_styles is not None

            flags = ((1 if state_ns else 0) << 4 |
                     (1 if state_ls else 0) << 3 |
                     (1 if state_fs1 else 0) << 2 |
                     (1 if state_fs0 else 0) << 1 |
                     (1 if state_move else 0))

            writer.write_ub(0, 1)   # TypeFlag = 0 (non-edge)
            writer.write_ub(flags, 5)

            if state_move:
                mx = edge.x if edge.x is not None else 0
                my = edge.y if edge.y is not None else 0
                move_bits = _sb_bits_needed(mx, my)
                writer.write_ub(move_bits, 5)
                writer.write_sb(mx, move_bits)
                writer.write_sb(my, move_bits)

            if state_fs0:
                writer.write_ub(edge.fillStyle0, fill_bits)
            if state_fs1:
                writer.write_ub(edge.fillStyle1, fill_bits)
            if state_ls:
                writer.write_ub(edge.lineStyle, line_bits)

        elif isinstance(edge, LineTo):
            # StraightEdgeRecord: TypeFlag=1, StraightFlag=1
            dx = edge.x
            dy = edge.y
            nbits = _sb_bits_needed(dx, dy)
            nbits = max(nbits, 2)  # minimum 2 per SWF spec
            writer.write_ub(1, 1)   # TypeFlag = 1 (edge)
            writer.write_ub(1, 1)   # StraightFlag = 1
            writer.write_ub(nbits - 2, 4)  # NumBits - 2
            if dx == 0:
                writer.write_ub(0, 1)  # GeneralLineFlag = 0
                writer.write_ub(1, 1)  # VertLineFlag = 1
                writer.write_sb(dy, nbits)
            elif dy == 0:
                writer.write_ub(0, 1)  # GeneralLineFlag = 0
                writer.write_ub(0, 1)  # VertLineFlag = 0
                writer.write_sb(dx, nbits)
            else:
                writer.write_ub(1, 1)  # GeneralLineFlag = 1
                writer.write_sb(dx, nbits)
                writer.write_sb(dy, nbits)

        elif isinstance(edge, CurveTo):
            nbits = _sb_bits_needed(edge.x1, edge.y1, edge.x2, edge.y2)
            nbits = max(nbits, 2)
            writer.write_ub(1, 1)   # TypeFlag = 1 (edge)
            writer.write_ub(0, 1)   # StraightFlag = 0 (curved)
            writer.write_ub(nbits - 2, 4)
            writer.write_sb(edge.x1, nbits)
            writer.write_sb(edge.y1, nbits)
            writer.write_sb(edge.x2, nbits)
            writer.write_sb(edge.y2, nbits)

    # EndShapeRecord: TypeFlag=0, flags=0 (6 zero bits)
    writer.write_ub(0, 6)
    writer.flush_byte()


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
        self.shape_version = shape_version  # 1 = DefineShape, 2 = DefineShape2, 3 = DefineShape3, 4 = DefineShape4

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
        if self.shape_version == 4:
            self._to_xml_shape4(parent)
            return

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

    def _to_xml_shape4(self, parent):
        """Emit DefineShape4 as an UnknownTag with raw binary data.

        swfmill 0.3.6 doesn't fully support DefineShape4 structured XML,
        so we build the tag body manually.
        """
        writer = SWFBitWriter()
        left, right, top, bottom = self.bounds

        # ShapeId (UI16)
        writer.write_ui16(self.object_id)

        # ShapeBounds RECT
        writer.write_rect(left, right, top, bottom)

        # EdgeBounds RECT (same as ShapeBounds for simplicity)
        writer.write_rect(left, right, top, bottom)

        # Flags byte: Reserved(5) + UsesFillWindingRule(1) +
        # UsesNonScalingStrokes(1) + UsesScalingStrokes(1)
        writer.write_ub(0, 5)  # Reserved
        writer.write_ub(0, 1)  # UsesFillWindingRule
        writer.write_ub(0, 1)  # UsesNonScalingStrokes
        writer.write_ub(1, 1)  # UsesScalingStrokes
        writer.flush_byte()

        # FILLSTYLEARRAY
        fill_count = len(self.fill_styles)
        if fill_count < 0xFF:
            writer.write_ui8(fill_count)
        else:
            writer.write_ui8(0xFF)
            writer.write_ui16(fill_count)
        for f in self.fill_styles:
            _encode_shape4_fill_style(f, writer)

        # LINESTYLE2ARRAY
        line_count = len(self.line_styles)
        if line_count < 0xFF:
            writer.write_ui8(line_count)
        else:
            writer.write_ui8(0xFF)
            writer.write_ui16(line_count)
        for ls in self.line_styles:
            _encode_linestyle2(ls, writer)

        # Shape records
        _encode_shape_records(self.edges, fill_count, line_count, writer)

        tag_body = writer.get_bytes()
        tag_b64 = base64.b64encode(tag_body).decode('ascii')

        # Tag 83 = 0x53
        unk = SubElement(parent, "UnknownTag", id="0x53")
        data_el = SubElement(unk, "data")
        data_el.text = tag_b64


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
