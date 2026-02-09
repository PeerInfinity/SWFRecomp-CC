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


class FocalRadialGradientFill:
    """Focal radial gradient fill (type 0x13) with an off-center focal point.

    The focal point shifts where the gradient radiates from, creating an
    asymmetric radial effect.  swfmill represents this as a
    ``<ShiftedRadialGradient shift="...">`` element.
    """
    def __init__(self, matrix, stops, focal_point=0.0):
        """
        matrix: dict with keys from {scaleX, scaleY, skewX, skewY, transX, transY}
        stops: list of (position, r, g, b) tuples
        focal_point: float in [-1.0, 1.0] — offset of the focal point along
                     the gradient's x axis.  0 = centered (same as radial),
                     positive = shifted right, negative = shifted left.
        """
        self.matrix = matrix
        self.stops = stops
        self.focal_point = focal_point

    def to_xml(self, parent):
        grad = SubElement(parent, "ShiftedRadialGradient",
                          shift=f"{self.focal_point:.16f}")
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
    """LINESTYLE2 with advanced cap/join styles for DefineShape4.

    swfmill represents LINESTYLE2 as a ``<LineStyle>`` element with additional
    attributes (startCapStyle, jointStyle, etc.) and the color inside a
    ``<fillColor>`` child element instead of ``<color>``.
    """
    def __init__(self, width, r, g, b, a=255,
                 start_cap=0, end_cap=0, join_style=0,
                 no_h_scale=0, no_v_scale=0, pixel_hinting=0,
                 no_close=0, miter_limit=None):
        self.width = width
        self.r = r
        self.g = g
        self.b = b
        self.a = a
        self.start_cap = start_cap    # 0=round, 1=none, 2=square
        self.end_cap = end_cap        # 0=round, 1=none, 2=square
        self.join_style = join_style  # 0=round, 1=bevel, 2=miter
        self.no_h_scale = no_h_scale
        self.no_v_scale = no_v_scale
        self.pixel_hinting = pixel_hinting
        self.no_close = no_close
        self.miter_limit = miter_limit  # FIXED8, only used if join_style == 2

    def to_xml(self, parent):
        attrs = {
            "width": str(self.width),
            "startCapStyle": str(self.start_cap),
            "jointStyle": str(self.join_style),
            "hasFill": "0",
            "noHScale": str(self.no_h_scale),
            "noVScale": str(self.no_v_scale),
            "pixelHinting": str(self.pixel_hinting),
            "noClose": str(self.no_close),
            "endCapStyle": str(self.end_cap),
        }
        if self.miter_limit is not None:
            if isinstance(self.miter_limit, float):
                attrs["miterLimitFactor"] = f"{self.miter_limit:.16f}"
            else:
                attrs["miterLimitFactor"] = str(self.miter_limit)
        ls = SubElement(parent, "LineStyle", **attrs)
        color_el = SubElement(ls, "fillColor")
        SubElement(color_el, "Color",
                   red=str(self.r), green=str(self.g),
                   blue=str(self.b), alpha=str(self.a))


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
        self.shape_version = shape_version  # 1 = DefineShape, 2 = DefineShape2, 3 = DefineShape3, 4 = DefineShape4
        self.edge_bounds = None  # (left, right, top, bottom) for DefineShape4; defaults to bounds

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
        version_tags = {
            1: "DefineShape", 2: "DefineShape2",
            3: "DefineShape3", 4: "DefineShape5",
        }
        tag_name = version_tags.get(self.shape_version, "DefineShape")
        left, right, top, bottom = self.bounds

        if self.shape_version == 4:
            # DefineShape4 -> swfmill "DefineShape5"
            shape_el = SubElement(parent, tag_name,
                                  objectID=str(self.object_id),
                                  nonScalingStrokes="0",
                                  scalingStrokes="1")
            bounds_el = SubElement(shape_el, "bounds")
            SubElement(bounds_el, "Rectangle",
                       left=str(left), right=str(right),
                       top=str(top), bottom=str(bottom))
            stroke_bounds_el = SubElement(shape_el, "strokeBounds")
            eb = self.edge_bounds if self.edge_bounds else self.bounds
            eb_left, eb_right, eb_top, eb_bottom = eb
            SubElement(stroke_bounds_el, "Rectangle",
                       left=str(eb_left), right=str(eb_right),
                       top=str(eb_top), bottom=str(eb_bottom))
        else:
            shape_el = SubElement(parent, tag_name, objectID=str(self.object_id))
            bounds_el = SubElement(shape_el, "bounds")
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

    def remove_object(self, depth):
        """Remove the character at the given depth from the sprite's display list."""
        self.sub_tags.append(("RemoveObject2", {"depth": depth}))

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
            elif tag_type == "RemoveObject2":
                d = tag_data
                SubElement(tags_el, "RemoveObject2", depth=str(d["depth"]))
            elif tag_type == "ShowFrame":
                SubElement(tags_el, "ShowFrame")

        SubElement(tags_el, "End")


# ---------------------------------------------------------------------------
# Button definition helper
# ---------------------------------------------------------------------------

class ButtonDefinition:
    """Collects button records for a DefineButton tag (tag 7).

    Builds raw binary since swfmill's xml2swf omits the CharacterEndFlag
    (0x00 record terminator) when actions are present.
    """
    def __init__(self, object_id):
        self.object_id = object_id
        self.records = []  # list of record dicts
        self.trace_actions = []  # list of message strings

    def add_record(self, char_id, depth, up=False, over=False, down=False,
                   hit_test=False, trans_x=0, trans_y=0):
        """Add a button record mapping a character to one or more button states.

        char_id: character ID to display
        depth: display list depth for this record
        up/over/down/hit_test: which button states use this character
        trans_x/trans_y: placement offset in twips
        """
        self.records.append({
            "char_id": char_id,
            "depth": depth,
            "up": up,
            "over": over,
            "down": down,
            "hit_test": hit_test,
            "trans_x": trans_x,
            "trans_y": trans_y,
        })

    def add_trace_action(self, message):
        """Add a Trace action that prints a message (fires on click/release)."""
        self.trace_actions.append(message)

    def build_body(self):
        """Build the raw DefineButton tag body as bytes."""
        body = bytearray()
        # ButtonId (UI16 LE)
        body += struct.pack('<H', self.object_id)
        # BUTTONRECORD entries
        for rec in self.records:
            flags = 0
            if rec["up"]:       flags |= 0x01
            if rec["over"]:     flags |= 0x02
            if rec["down"]:     flags |= 0x04
            if rec["hit_test"]: flags |= 0x08
            body.append(flags)
            body += struct.pack('<H', rec["char_id"])
            body += struct.pack('<H', rec["depth"])
            # MATRIX (bit-packed)
            matrix = {"transX": rec["trans_x"], "transY": rec["trans_y"]}
            body += _build_matrix_bits(matrix)
        # CharacterEndFlag (UI8) — record terminator
        body.append(0x00)
        # ACTIONRECORD entries
        for msg in self.trace_actions:
            msg_bytes = msg.encode('ascii') + b'\x00'
            # ActionPush (0x96) + length (UI16) + type 0x00 (string) + string
            push_len = 1 + len(msg_bytes)
            body.append(0x96)
            body += struct.pack('<H', push_len)
            body.append(0x00)  # type: string
            body += msg_bytes
            # ActionTrace (0x26)
            body.append(0x26)
        # ActionEnd (0x00)
        body.append(0x00)
        return bytes(body)


class Button2Definition:
    """Collects button records for a DefineButton2 tag (tag 34).

    Builds raw binary since DefineButton2 has CXFORMWITHALPHA per record.
    """
    def __init__(self, object_id):
        self.object_id = object_id
        self.records = []
        self.actions = []  # list of (condition, message) tuples

    def add_record(self, char_id, depth, up=False, over=False, down=False,
                   hit_test=False, trans_x=0, trans_y=0,
                   mult_r=256, mult_g=256, mult_b=256, mult_a=256,
                   add_r=0, add_g=0, add_b=0, add_a=0):
        """Add a button record mapping a character to one or more button states.

        CXFORMWITHALPHA params: mult_* are 8.8 fixed point (256=1.0), add_* are -255..255.
        """
        self.records.append({
            "char_id": char_id,
            "depth": depth,
            "up": up,
            "over": over,
            "down": down,
            "hit_test": hit_test,
            "trans_x": trans_x,
            "trans_y": trans_y,
            "mult_r": mult_r, "mult_g": mult_g, "mult_b": mult_b, "mult_a": mult_a,
            "add_r": add_r, "add_g": add_g, "add_b": add_b, "add_a": add_a,
        })

    def add_trace_action(self, message, condition=0x0010):
        """Add a BUTTONCONDACTION with a Trace action.

        condition: bitmask of triggering transitions (default 0x0010 = OverDownToOverUp = click)
        """
        self.actions.append((condition, message))

    def _build_action_block(self, condition, message, is_last):
        """Build a single BUTTONCONDACTION block."""
        # Build the action bytes first to know the size
        action = bytearray()
        msg_bytes = message.encode('ascii') + b'\x00'
        push_len = 1 + len(msg_bytes)
        action.append(0x96)  # ActionPush
        action += struct.pack('<H', push_len)
        action.append(0x00)  # type: string
        action += msg_bytes
        action.append(0x26)  # ActionTrace
        action.append(0x00)  # ActionEnd

        block = bytearray()
        # CondActionSize (UI16): 0 for last block, otherwise size of this block
        size = 4 + len(action)  # 2 (CondActionSize) + 2 (Condition) + actions
        block += struct.pack('<H', 0 if is_last else size)
        # Condition (UI16)
        block += struct.pack('<H', condition)
        block += action
        return bytes(block)

    def build_body(self):
        """Build the raw DefineButton2 tag body as bytes."""
        body = bytearray()
        # ButtonId (UI16 LE)
        body += struct.pack('<H', self.object_id)
        # Flags (UI8): TrackAsMenu=0
        body.append(0x00)
        # ActionOffset placeholder — fill in after building records
        action_offset_pos = len(body)
        body += struct.pack('<H', 0)
        # BUTTONRECORD2 entries
        for rec in self.records:
            flags = 0
            if rec["up"]:       flags |= 0x01
            if rec["over"]:     flags |= 0x02
            if rec["down"]:     flags |= 0x04
            if rec["hit_test"]: flags |= 0x08
            body.append(flags)
            body += struct.pack('<H', rec["char_id"])
            body += struct.pack('<H', rec["depth"])
            # MATRIX (bit-packed)
            matrix = {"transX": rec["trans_x"], "transY": rec["trans_y"]}
            body += _build_matrix_bits(matrix)
            # CXFORMWITHALPHA
            mr, mg, mb, ma = rec["mult_r"], rec["mult_g"], rec["mult_b"], rec["mult_a"]
            ar, ag, ab, aa = rec["add_r"], rec["add_g"], rec["add_b"], rec["add_a"]
            has_mult = not (mr == 256 and mg == 256 and mb == 256 and ma == 256)
            has_add = not (ar == 0 and ag == 0 and ab == 0 and aa == 0)
            cxform_bw = _BitWriter()
            cxform_bw.write_bits(1 if has_add else 0, 1)   # HasAddTerms
            cxform_bw.write_bits(1 if has_mult else 0, 1)  # HasMultTerms
            if has_mult or has_add:
                vals = []
                if has_mult: vals += [mr, mg, mb, ma]
                if has_add: vals += [ar, ag, ab, aa]
                nbits = max(_bits_needed_signed(v) for v in vals)
                nbits = max(nbits, 1)
                cxform_bw.write_bits(nbits, 4)
                if has_mult:
                    for v in [mr, mg, mb, ma]: cxform_bw.write_sb(v, nbits)
                if has_add:
                    for v in [ar, ag, ab, aa]: cxform_bw.write_sb(v, nbits)
            else:
                cxform_bw.write_bits(0, 4)  # Nbits=0
            body += cxform_bw.to_bytes()
        # Terminator
        body.append(0x00)
        # Patch ActionOffset (byte offset from the ActionOffset field to first BUTTONCONDACTION)
        if self.actions:
            action_offset = len(body) - action_offset_pos
            struct.pack_into('<H', body, action_offset_pos, action_offset)
            for idx, (condition, message) in enumerate(self.actions):
                is_last = (idx == len(self.actions) - 1)
                body += self._build_action_block(condition, message, is_last)
        return bytes(body)


# ---------------------------------------------------------------------------
# Main SWF builder
# ---------------------------------------------------------------------------

# ---------------------------------------------------------------------------
# Font definition helper
# ---------------------------------------------------------------------------

class _BitWriter:
    """Writes bit-packed data to a byte buffer (MSB first, SWF convention)."""
    def __init__(self):
        self.buffer = bytearray()
        self.current_byte = 0
        self.bit_position = 7

    def write_bits(self, value, num_bits):
        for i in range(num_bits - 1, -1, -1):
            bit = (value >> i) & 1
            self.current_byte |= (bit << self.bit_position)
            self.bit_position -= 1
            if self.bit_position < 0:
                self.buffer.append(self.current_byte)
                self.current_byte = 0
                self.bit_position = 7

    def write_sb(self, value, num_bits):
        if value < 0:
            value = (1 << num_bits) + value
        self.write_bits(value, num_bits)

    def align(self):
        if self.bit_position != 7:
            self.buffer.append(self.current_byte)
            self.current_byte = 0
            self.bit_position = 7

    def to_bytes(self):
        self.align()
        return bytes(self.buffer)


def _bits_needed_signed(value):
    """Minimum bits to represent a signed value."""
    if value == 0:
        return 1
    if value > 0:
        return value.bit_length() + 1
    return (abs(value) - 1).bit_length() + 1


def _build_glyph_shape_binary(edges):
    """Build the binary SHAPE data for a single font glyph.

    Font glyphs use a minimal shape format: only 1 fill-bit (fill 0/1),
    0 line-bits, and only fillStyle0/fillStyle1 + moveTo + straight/curved
    edges.

    edges: list of ShapeSetup / LineTo / CurveTo instances describing the glyph.
           The first edge should be a ShapeSetup with fillStyle1=1 and x,y coords.
    """
    bw = _BitWriter()
    # NumFillBits = 1, NumLineBits = 0
    bw.write_bits(1, 4)  # NumFillBits
    bw.write_bits(0, 4)  # NumLineBits

    for edge in edges:
        if isinstance(edge, ShapeSetup):
            bw.write_bits(0, 1)  # TypeFlag = non-edge
            bw.write_bits(0, 1)  # StateNewStyles = 0
            bw.write_bits(0, 1)  # StateLineStyle = 0

            has_fs1 = edge.fillStyle1 is not None
            has_fs0 = edge.fillStyle0 is not None
            has_move = edge.x is not None and edge.y is not None

            bw.write_bits(1 if has_fs1 else 0, 1)  # StateFillStyle1
            bw.write_bits(1 if has_fs0 else 0, 1)  # StateFillStyle0
            bw.write_bits(1 if has_move else 0, 1)  # StateMoveTo

            if has_move:
                move_nbits = max(_bits_needed_signed(edge.x),
                                 _bits_needed_signed(edge.y), 1)
                bw.write_bits(move_nbits, 5)
                bw.write_sb(edge.x, move_nbits)
                bw.write_sb(edge.y, move_nbits)

            if has_fs0:
                bw.write_bits(edge.fillStyle0, 1)  # 1 fill-bit
            if has_fs1:
                bw.write_bits(edge.fillStyle1, 1)  # 1 fill-bit

        elif isinstance(edge, LineTo):
            bw.write_bits(1, 1)  # TypeFlag = edge
            bw.write_bits(1, 1)  # StraightFlag
            nbits = max(_bits_needed_signed(edge.x),
                        _bits_needed_signed(edge.y), 2)
            bw.write_bits(nbits - 2, 4)  # NumBits - 2
            if edge.x != 0 and edge.y != 0:
                bw.write_bits(1, 1)  # GeneralLine
                bw.write_sb(edge.x, nbits)
                bw.write_sb(edge.y, nbits)
            elif edge.y == 0:
                bw.write_bits(0, 1)  # not GeneralLine
                bw.write_bits(0, 1)  # Horizontal
                bw.write_sb(edge.x, nbits)
            else:
                bw.write_bits(0, 1)  # not GeneralLine
                bw.write_bits(1, 1)  # Vertical
                bw.write_sb(edge.y, nbits)

        elif isinstance(edge, CurveTo):
            bw.write_bits(1, 1)  # TypeFlag = edge
            bw.write_bits(0, 1)  # StraightFlag = 0 (curved)
            nbits = max(_bits_needed_signed(edge.x1),
                        _bits_needed_signed(edge.y1),
                        _bits_needed_signed(edge.x2),
                        _bits_needed_signed(edge.y2), 2)
            bw.write_bits(nbits - 2, 4)  # NumBits - 2
            bw.write_sb(edge.x1, nbits)
            bw.write_sb(edge.y1, nbits)
            bw.write_sb(edge.x2, nbits)
            bw.write_sb(edge.y2, nbits)

    # EndShape record: 6 zero bits
    bw.write_bits(0, 6)
    return bw.to_bytes()


def _build_shape_binary(edges, fill_bits, line_bits):
    """Build SWF SHAPE binary from edge records with configurable fill/line bits.

    Generic version of _build_glyph_shape_binary that supports arbitrary
    fill_bits, line_bits, and line style changes.

    edges: list of ShapeSetup / LineTo / CurveTo instances.
    fill_bits: number of bits for fill style indices.
    line_bits: number of bits for line style indices.
    """
    bw = _BitWriter()
    bw.write_bits(fill_bits, 4)  # NumFillBits
    bw.write_bits(line_bits, 4)  # NumLineBits

    for edge in edges:
        if isinstance(edge, ShapeSetup):
            bw.write_bits(0, 1)  # TypeFlag = non-edge
            bw.write_bits(0, 1)  # StateNewStyles = 0
            has_ls = edge.lineStyle is not None
            has_fs1 = edge.fillStyle1 is not None
            has_fs0 = edge.fillStyle0 is not None
            has_move = edge.x is not None and edge.y is not None

            bw.write_bits(1 if has_ls else 0, 1)   # StateLineStyle
            bw.write_bits(1 if has_fs1 else 0, 1)  # StateFillStyle1
            bw.write_bits(1 if has_fs0 else 0, 1)  # StateFillStyle0
            bw.write_bits(1 if has_move else 0, 1)  # StateMoveTo

            if has_move:
                move_nbits = max(_bits_needed_signed(edge.x),
                                 _bits_needed_signed(edge.y), 1)
                bw.write_bits(move_nbits, 5)
                bw.write_sb(edge.x, move_nbits)
                bw.write_sb(edge.y, move_nbits)

            if has_fs0:
                bw.write_bits(edge.fillStyle0, fill_bits)
            if has_fs1:
                bw.write_bits(edge.fillStyle1, fill_bits)
            if has_ls:
                bw.write_bits(edge.lineStyle, line_bits)

        elif isinstance(edge, LineTo):
            bw.write_bits(1, 1)  # TypeFlag = edge
            bw.write_bits(1, 1)  # StraightFlag
            nbits = max(_bits_needed_signed(edge.x),
                        _bits_needed_signed(edge.y), 2)
            bw.write_bits(nbits - 2, 4)  # NumBits - 2
            if edge.x != 0 and edge.y != 0:
                bw.write_bits(1, 1)  # GeneralLine
                bw.write_sb(edge.x, nbits)
                bw.write_sb(edge.y, nbits)
            elif edge.y == 0:
                bw.write_bits(0, 1)  # not GeneralLine
                bw.write_bits(0, 1)  # Horizontal
                bw.write_sb(edge.x, nbits)
            else:
                bw.write_bits(0, 1)  # not GeneralLine
                bw.write_bits(1, 1)  # Vertical
                bw.write_sb(edge.y, nbits)

        elif isinstance(edge, CurveTo):
            bw.write_bits(1, 1)  # TypeFlag = edge
            bw.write_bits(0, 1)  # StraightFlag = 0 (curved)
            nbits = max(_bits_needed_signed(edge.x1),
                        _bits_needed_signed(edge.y1),
                        _bits_needed_signed(edge.x2),
                        _bits_needed_signed(edge.y2), 2)
            bw.write_bits(nbits - 2, 4)  # NumBits - 2
            bw.write_sb(edge.x1, nbits)
            bw.write_sb(edge.y1, nbits)
            bw.write_sb(edge.x2, nbits)
            bw.write_sb(edge.y2, nbits)

    # EndShape record: 6 zero bits
    bw.write_bits(0, 6)
    return bw.to_bytes()


class MorphShapeDefinition:
    """Collects morph fill styles, line styles, and start/end edges for DefineMorphShape."""
    def __init__(self, object_id, start_bounds, end_bounds):
        self.object_id = object_id
        self.start_bounds = start_bounds  # (left, right, top, bottom) in twips
        self.end_bounds = end_bounds      # (left, right, top, bottom) in twips
        self.fill_styles = []   # list of (start_fill, end_fill) tuples
        self.line_styles = []   # list of (start_width, end_width, start_color, end_color)
        self.start_edges = []   # edge records for start shape
        self.end_edges = []     # edge records for end shape

    def add_solid_fill(self, start_color, end_color):
        """Add a solid morph fill style.

        start_color: (r, g, b, a) for ratio=0
        end_color: (r, g, b, a) for ratio=65535
        Returns 1-based fill style index.
        """
        self.fill_styles.append(("solid", start_color, end_color))
        return len(self.fill_styles)

    def add_start_edges(self, edges):
        self.start_edges.extend(edges)

    def add_end_edges(self, edges):
        self.end_edges.extend(edges)


def _build_define_morph_shape_body(morph_def):
    """Build the raw tag body for DefineMorphShape (tag 46).

    morph_def: a MorphShapeDefinition instance.
    Returns bytes containing the full tag body (including CharacterID).
    """
    body = bytearray()

    # CharacterID (UI16)
    body += struct.pack('<H', morph_def.object_id)

    # StartBounds (RECT)
    left, right, top, bottom = morph_def.start_bounds
    body += _build_rect_bits(left, right, top, bottom)

    # EndBounds (RECT)
    left, right, top, bottom = morph_def.end_bounds
    body += _build_rect_bits(left, right, top, bottom)

    # Build fill styles, line styles, and start edges first to compute Offset
    fill_count = len(morph_def.fill_styles)
    line_count = len(morph_def.line_styles)

    # MORPHFILLSTYLEARRAY
    fill_bytes = bytearray()
    fill_bytes.append(fill_count)  # FillStyleCount (UI8)
    for fill_type, start_color, end_color in morph_def.fill_styles:
        if fill_type == "solid":
            fill_bytes.append(0x00)  # FillStyleType = solid
            sr, sg, sb, sa = start_color
            fill_bytes.extend((sr, sg, sb, sa))  # StartColor (RGBA)
            er, eg, eb, ea = end_color
            fill_bytes.extend((er, eg, eb, ea))  # EndColor (RGBA)

    # MORPHLINESTYLEARRAY
    line_bytes = bytearray()
    line_bytes.append(line_count)  # LineStyleCount (UI8)
    for start_width, end_width, start_color, end_color in morph_def.line_styles:
        line_bytes += struct.pack('<H', start_width)   # StartWidth (UI16)
        line_bytes += struct.pack('<H', end_width)     # EndWidth (UI16)
        sr, sg, sb, sa = start_color
        line_bytes.extend((sr, sg, sb, sa))  # StartColor (RGBA)
        er, eg, eb, ea = end_color
        line_bytes.extend((er, eg, eb, ea))  # EndColor (RGBA)

    # StartEdges SHAPE
    fill_bits = max(fill_count.bit_length(), 1) if fill_count > 0 else 0
    line_bits = max(line_count.bit_length(), 1) if line_count > 0 else 0
    start_edges_bytes = _build_shape_binary(morph_def.start_edges, fill_bits, line_bits)

    # EndEdges SHAPE (fill/line bits = 0, edges only)
    end_edges_bytes = _build_shape_binary(morph_def.end_edges, 0, 0)

    # Offset = length from after Offset field to EndEdges start
    # = fill_bytes + line_bytes + start_edges_bytes
    offset = len(fill_bytes) + len(line_bytes) + len(start_edges_bytes)
    body += struct.pack('<I', offset)  # Offset (UI32)

    body += fill_bytes
    body += line_bytes
    body += start_edges_bytes
    body += end_edges_bytes

    return bytes(body)


def _build_define_font2_body(object_id, glyphs, font_name="TestFont",
                             char_codes=None, advance_widths=None,
                             ascent=0, descent=0, leading=0):
    """Build the raw tag body for DefineFont2 (tag 48).

    object_id: character ID for the font
    glyphs: list of edge-record lists, one per glyph.
    font_name: font name string (ASCII).
    char_codes: list of UI16 character codes (parallel to glyphs). If None, sequential A/B/C...
    advance_widths: list of SI16 advance widths (parallel to glyphs). If provided, layout section is emitted.
    ascent/descent/leading: SI16 font metrics for layout section.

    Returns bytes containing the full tag body.
    """
    num_glyphs = len(glyphs)

    # Build glyph shape binaries
    glyph_binaries = [_build_glyph_shape_binary(g) for g in glyphs]

    # Flags: bit 2 = WideCodes (1)
    flags = 0x04
    if advance_widths is not None:
        flags |= 0x80  # HasLayout
    language_code = 0
    font_name_bytes = font_name.encode('ascii')

    body = bytearray()
    body += struct.pack('<H', object_id)  # FontID
    body.append(flags)                     # Flags
    body.append(language_code)             # LanguageCode
    body.append(len(font_name_bytes))      # FontNameLen
    body += font_name_bytes                # FontName
    body += struct.pack('<H', num_glyphs)  # NumGlyphs

    if num_glyphs > 0:
        # Offset table: NumGlyphs glyph offsets + CodeTableOffset, all UI16
        # Offsets are relative to start of offset table
        offset_table_size = (num_glyphs + 1) * 2  # +1 for CodeTableOffset
        offsets = []
        current_offset = offset_table_size
        for gb in glyph_binaries:
            offsets.append(current_offset)
            current_offset += len(gb)
        # CodeTableOffset = offset after all glyph data
        offsets.append(current_offset)

        for off in offsets:
            body += struct.pack('<H', off)

        # Glyph shapes
        for gb in glyph_binaries:
            body += gb

        # Code table: UI16 per glyph
        if char_codes is not None:
            for code in char_codes:
                body += struct.pack('<H', code)
        else:
            for i in range(num_glyphs):
                body += struct.pack('<H', 65 + i)

    # Layout section (if advance_widths provided)
    if advance_widths is not None and num_glyphs > 0:
        body += struct.pack('<h', ascent)   # FontAscent (SI16)
        body += struct.pack('<h', descent)  # FontDescent (SI16)
        body += struct.pack('<h', leading)  # FontLeading (SI16)
        # Advance table: SI16 per glyph
        for adv in advance_widths:
            body += struct.pack('<h', adv)
        # Bounds table: one RECT per glyph (empty RECTs: Nbits=0 → 1 byte each)
        for _ in range(num_glyphs):
            body += _build_rect_bits(0, 0, 0, 0)
        # Kerning count = 0
        body += struct.pack('<H', 0)

    return bytes(body)


def _build_define_font_body(object_id, glyphs):
    """Build the raw tag body (after the tag header) for DefineFont (tag 10).

    object_id: character ID for the font
    glyphs: list of edge-record lists, one per glyph.  Each is a list of
            ShapeSetup / LineTo / CurveTo instances.

    Returns bytes containing the full tag body.
    """
    num_glyphs = len(glyphs)

    # First, build all glyph shape binaries
    glyph_binaries = []
    for g in glyphs:
        glyph_binaries.append(_build_glyph_shape_binary(g))

    # Offset table: num_glyphs UI16 entries
    # First offset = num_glyphs * 2 (size of offset table itself)
    offset_table_size = num_glyphs * 2
    offsets = []
    current_offset = offset_table_size
    for gb in glyph_binaries:
        offsets.append(current_offset)
        current_offset += len(gb)

    body = bytearray()
    body += struct.pack('<H', object_id)
    for off in offsets:
        body += struct.pack('<H', off)
    for gb in glyph_binaries:
        body += gb

    return bytes(body)


def _build_rect_bits(left, right, top, bottom):
    """Build a SWF RECT as bit-packed bytes."""
    vals = [left, right, top, bottom]
    nbits = max(_bits_needed_signed(v) for v in vals)
    bw = _BitWriter()
    bw.write_bits(nbits, 5)
    for v in vals:
        bw.write_sb(v, nbits)
    return bw.to_bytes()


def _build_place_object2_body(d):
    """Build raw PlaceObject2 (tag 26) body with ratio support.

    d: dict with keys object_id, depth, trans_x, trans_y, scale_x, scale_y,
       skew_x, skew_y, color_transform, clip_depth, ratio.
    """
    flags = 0
    has_character = True
    flags |= 0x02  # HasCharacter

    # Build matrix
    mat_dict = {"transX": d["trans_x"], "transY": d["trans_y"]}
    if d.get("scale_x") is not None:
        mat_dict["scaleX"] = d["scale_x"]
    if d.get("scale_y") is not None:
        mat_dict["scaleY"] = d["scale_y"]
    if d.get("skew_x") is not None:
        mat_dict["skewX"] = d["skew_x"]
    if d.get("skew_y") is not None:
        mat_dict["skewY"] = d["skew_y"]
    flags |= 0x04  # HasMatrix

    if d.get("ratio") is not None:
        flags |= 0x10  # HasRatio
    if d.get("clip_depth") is not None:
        flags |= 0x40  # HasClipDepth

    body = struct.pack('<B', flags)
    body += struct.pack('<H', d["depth"])
    # HasCharacter
    body += struct.pack('<H', d["object_id"])
    # HasMatrix
    body += _build_matrix_bits(mat_dict)
    # HasRatio
    if d.get("ratio") is not None:
        body += struct.pack('<H', d["ratio"])
    # HasClipDepth
    if d.get("clip_depth") is not None:
        body += struct.pack('<H', d["clip_depth"])
    return body


def _build_matrix_bits(transform):
    """Build a SWF MATRIX as bit-packed bytes.

    transform: dict with keys from {transX, transY, scaleX, scaleY, skewX, skewY}
    Values are in SWF fixed-point or twips as appropriate.
    """
    bw = _BitWriter()

    # HasScale
    has_scale = "scaleX" in transform or "scaleY" in transform
    bw.write_bits(1 if has_scale else 0, 1)
    if has_scale:
        sx = int(round(transform.get("scaleX", 1.0) * 65536))
        sy = int(round(transform.get("scaleY", 1.0) * 65536))
        nbits = max(_bits_needed_signed(sx), _bits_needed_signed(sy), 1)
        bw.write_bits(nbits, 5)
        bw.write_sb(sx, nbits)
        bw.write_sb(sy, nbits)

    # HasRotate
    has_rotate = "skewX" in transform or "skewY" in transform
    bw.write_bits(1 if has_rotate else 0, 1)
    if has_rotate:
        rx = int(round(transform.get("skewX", 0.0) * 65536))
        ry = int(round(transform.get("skewY", 0.0) * 65536))
        nbits = max(_bits_needed_signed(rx), _bits_needed_signed(ry), 1)
        bw.write_bits(nbits, 5)
        bw.write_sb(rx, nbits)
        bw.write_sb(ry, nbits)

    # Translate (always present)
    tx = transform.get("transX", 0)
    ty = transform.get("transY", 0)
    if tx == 0 and ty == 0:
        bw.write_bits(0, 5)  # NTranslateBits = 0
    else:
        nbits = max(_bits_needed_signed(tx), _bits_needed_signed(ty), 1)
        bw.write_bits(nbits, 5)
        bw.write_sb(tx, nbits)
        bw.write_sb(ty, nbits)

    return bw.to_bytes()


def _build_define_text2_body(text_def):
    """Build the raw tag body for DefineText2 (tag 33).

    DefineText2 is identical to DefineText (tag 11) except that colors
    are RGBA (4 bytes) instead of RGB (3 bytes).

    text_def: a TextDefinition instance.
    Returns bytes containing the full tag body (including CharacterID).
    """
    body = bytearray()

    # CharacterID (UI16)
    body += struct.pack('<H', text_def.object_id)

    # TextBounds (RECT)
    left, right, top, bottom = text_def.bounds
    body += _build_rect_bits(left, right, top, bottom)

    # Matrix
    body += _build_matrix_bits(text_def.transform)

    # Collect all glyphs to determine GlyphBits and AdvanceBits
    all_glyphs = []
    for rec in text_def.records:
        all_glyphs.extend(rec.glyphs)

    max_glyph = max((g[0] for g in all_glyphs), default=0)
    max_advance = max((abs(g[1]) for g in all_glyphs), default=0)

    glyph_bits = max(max_glyph.bit_length(), 1) if max_glyph > 0 else 1
    advance_bits = max(_bits_needed_signed(max_advance), 1)

    # GlyphBits (UI8), AdvanceBits (UI8)
    body.append(glyph_bits)
    body.append(advance_bits)

    # Text records
    for rec in text_def.records:
        # TextRecord flags byte: bit 7 = 1 (type flag), bits 3-0 = flags
        flags = 0x80  # type flag
        if rec.font_id is not None:
            flags |= 0x08  # HasFont
        if rec.color is not None:
            flags |= 0x04  # HasColor
        if rec.y_offset is not None:
            flags |= 0x01  # HasYOffset
        if rec.x_offset is not None:
            flags |= 0x02  # HasXOffset

        body.append(flags)

        if rec.font_id is not None:
            body += struct.pack('<H', rec.font_id)

        if rec.color is not None:
            if len(rec.color) == 4:
                r, g, b, a = rec.color
            else:
                r, g, b = rec.color
                a = 255
            body.extend((r, g, b, a))  # RGBA for DefineText2

        if rec.x_offset is not None:
            body += struct.pack('<h', rec.x_offset)

        if rec.y_offset is not None:
            body += struct.pack('<h', rec.y_offset)

        if rec.font_id is not None:
            body += struct.pack('<H', rec.text_height)

        # GlyphCount (UI8)
        body.append(len(rec.glyphs))

        # Glyph entries (bit-packed)
        bw = _BitWriter()
        for glyph_idx, advance in rec.glyphs:
            bw.write_bits(glyph_idx, glyph_bits)
            bw.write_sb(advance, advance_bits)
        body += bw.to_bytes()

    # End of records: 0x00 byte
    body.append(0x00)

    return bytes(body)


def _build_define_edit_text_body(edit_text_def):
    """Build the raw tag body for DefineEditText (tag 37).

    edit_text_def: dict with keys:
        object_id: UI16 character ID
        bounds: (left, right, top, bottom) in twips
        font_id: UI16 (optional)
        font_height: UI16 in twips (optional, requires font_id)
        color: (r, g, b, a) tuple (optional)
        max_length: UI16 (optional)
        initial_text: string (optional)
        read_only: bool (default True)
        layout: dict with align, left_margin, right_margin, indent, leading (optional)

    Returns bytes containing the full tag body.
    """
    body = bytearray()

    # CharacterID (UI16)
    body += struct.pack('<H', edit_text_def['object_id'])

    # Bounds (RECT)
    left, right, top, bottom = edit_text_def['bounds']
    body += _build_rect_bits(left, right, top, bottom)

    # Build flags
    has_font = 'font_id' in edit_text_def
    has_text_color = 'color' in edit_text_def
    has_max_length = 'max_length' in edit_text_def
    has_text = 'initial_text' in edit_text_def
    has_layout = 'layout' in edit_text_def
    read_only = edit_text_def.get('read_only', True)

    # First flags byte: HasText(0x80), WordWrap(0x40), Multiline(0x20),
    #   Password(0x10), ReadOnly(0x08), HasTextColor(0x04), HasMaxLength(0x02), HasFont(0x01)
    flags_lo = 0
    if has_text:
        flags_lo |= 0x80
    if read_only:
        flags_lo |= 0x08
    if has_text_color:
        flags_lo |= 0x04
    if has_max_length:
        flags_lo |= 0x02
    if has_font:
        flags_lo |= 0x01

    # Second flags byte: HasFontClass(0x80), AutoSize(0x40), HasLayout(0x20),
    #   NoSelect(0x10), Border(0x08), WasStatic(0x04), HTML(0x02), UseOutlines(0x01)
    flags_hi = 0
    if has_layout:
        flags_hi |= 0x20

    body.append(flags_lo)
    body.append(flags_hi)

    if has_font:
        body += struct.pack('<H', edit_text_def['font_id'])
        body += struct.pack('<H', edit_text_def.get('font_height', 240))

    if has_text_color:
        r, g, b, a = edit_text_def['color']
        body.extend((r, g, b, a))

    if has_max_length:
        body += struct.pack('<H', edit_text_def['max_length'])

    if has_layout:
        layout = edit_text_def['layout']
        body.append(layout.get('align', 0))
        body += struct.pack('<H', layout.get('left_margin', 0))
        body += struct.pack('<H', layout.get('right_margin', 0))
        body += struct.pack('<H', layout.get('indent', 0))
        body += struct.pack('<h', layout.get('leading', 0))

    # VariableName (null-terminated STRING)
    body.append(0x00)

    # InitialText (null-terminated STRING, if HasText)
    if has_text:
        body += edit_text_def['initial_text'].encode('ascii') + b'\x00'

    return bytes(body)


class FontDefinition:
    """Collects glyph shape data for a DefineFont tag."""
    def __init__(self, object_id):
        self.object_id = object_id
        self.glyphs = []  # list of edge-record lists
        self.char_codes = []  # list of character codes (parallel to glyphs)
        self.advance_widths = []  # list of advance widths in EM units (parallel to glyphs)
        self.ascent = 0  # font ascent in EM units
        self.descent = 0  # font descent in EM units
        self.leading = 0  # font leading in EM units

    def add_glyph(self, edges):
        """Add a glyph defined by a list of edge records (ShapeSetup, LineTo, CurveTo).

        The first edge should be a ShapeSetup with fillStyle1=1 and x/y coords.
        Returns the 0-based glyph index.
        """
        self.glyphs.append(edges)
        return len(self.glyphs) - 1

    def add_glyph_mapped(self, edges, char_code, advance_width):
        """Add a glyph with explicit character code and advance width.

        edges: list of edge records (ShapeSetup, LineTo, CurveTo)
        char_code: Unicode code point for this glyph
        advance_width: advance width in EM units (e.g. 1024-based for DefineFont2)
        Returns the 0-based glyph index.
        """
        idx = self.add_glyph(edges)
        self.char_codes.append(char_code)
        self.advance_widths.append(advance_width)
        return idx


# ---------------------------------------------------------------------------
# Text definition helper
# ---------------------------------------------------------------------------

class TextRecord:
    """A text record for DefineText.

    A setup record sets font, color, position, and height; a glyph record
    contains the actual glyph index + advance pairs.
    """
    def __init__(self, font_id=None, color=None, x_offset=None,
                 y_offset=None, text_height=None, glyphs=None):
        """
        For a setup+glyph record:
            font_id: UI16 character ID of a DefineFont
            color: (r, g, b) tuple
            x_offset: SI16 x position (twips)
            y_offset: SI16 y position (twips)
            text_height: UI16 font height (twips, e.g. 240 = 12pt)
            glyphs: list of (glyph_index, advance) tuples
        """
        self.font_id = font_id
        self.color = color
        self.x_offset = x_offset
        self.y_offset = y_offset
        self.text_height = text_height
        self.glyphs = glyphs or []


class TextDefinition:
    """Collects text records for a DefineText tag."""
    def __init__(self, object_id, bounds, transform=None):
        """
        object_id: character ID for this text object
        bounds: (left, right, top, bottom) in twips
        transform: dict with transX, transY (default: origin)
        """
        self.object_id = object_id
        self.bounds = bounds
        self.transform = transform or {"transX": 0, "transY": 0}
        self.records = []

    def add_record(self, record):
        """Add a TextRecord to this text definition."""
        self.records.append(record)


# ---------------------------------------------------------------------------
# TTF glyph extraction
# ---------------------------------------------------------------------------

def extract_ttf_glyphs(ttf_path, characters, em_square=1024):
    """Extract glyph outlines from a TTF file for use with DefineFont2.

    ttf_path: path to TTF file
    characters: string of characters to extract (e.g. "Hello World")
    em_square: target EM square size (1024 for DefineFont2, 20480 for DefineFont3)

    Returns dict with:
        'glyphs': list of (char_code, edges, advance_width) tuples
        'ascent': font ascent in EM units
        'descent': font descent in EM units
        'leading': font leading in EM units (always 0)
    """
    from fontTools.ttLib import TTFont
    from fontTools.pens.recordingPen import RecordingPen

    font = TTFont(ttf_path)
    cmap = font.getBestCmap()
    glyf_table = font['glyf']
    hmtx = font['hmtx']
    head = font['head']
    os2 = font['OS/2']

    upm = head.unitsPerEm
    scale = em_square / upm

    ascent = round(os2.sTypoAscender * scale)
    descent = round(abs(os2.sTypoDescender) * scale)

    # Deduplicate characters while preserving order
    seen = set()
    unique_chars = []
    for ch in characters:
        if ch not in seen:
            seen.add(ch)
            unique_chars.append(ch)

    glyphs = []
    for ch in unique_chars:
        code_point = ord(ch)
        if code_point not in cmap:
            continue

        glyph_name = cmap[code_point]
        advance_raw = hmtx[glyph_name][0]
        advance = round(advance_raw * scale)

        glyph = glyf_table[glyph_name]
        if glyph.numberOfContours == 0 or not hasattr(glyph, 'coordinates') or len(glyph.coordinates) == 0:
            # Space or empty glyph — emit empty edges
            glyphs.append((code_point, [], advance))
            continue

        # Extract contours from glyph coordinates
        edges = []
        coords = glyph.coordinates
        end_pts = glyph.endPtsOfContours

        # First pass: convert all contours to SWF coordinates and compute
        # signed areas to determine winding direction.
        ascent_ttf = ascent / scale  # ascent in TTF units
        swf_contours = []  # list of (swf_points, signed_area)
        contour_start = 0
        for end_pt in end_pts:
            raw = coords[contour_start:end_pt + 1]
            contour_start = end_pt + 1
            if len(raw) < 2:
                continue
            pts = [(round(p[0] * scale), round((ascent_ttf - p[1]) * scale))
                   for p in raw]
            # Signed area (shoelace): positive = CW in Y-down, negative = CCW
            area = 0
            n = len(pts)
            for i in range(n):
                x1, y1 = pts[i]
                x2, y2 = pts[(i + 1) % n]
                area += x1 * y2 - x2 * y1
            swf_contours.append((pts, area / 2))

        if swf_contours:
            # Determine which contours are holes via point-in-polygon.
            # A contour is a hole if any of its points lies inside another
            # contour with larger absolute area.
            def _point_in_polygon(px, py, polygon):
                """Ray-casting point-in-polygon test."""
                inside = False
                n = len(polygon)
                j = n - 1
                for i in range(n):
                    xi, yi = polygon[i]
                    xj, yj = polygon[j]
                    if ((yi > py) != (yj > py)) and \
                       (px < (xj - xi) * (py - yi) / (yj - yi) + xi):
                        inside = not inside
                    j = i
                return inside

            is_hole = [False] * len(swf_contours)
            for i, (pts_i, area_i) in enumerate(swf_contours):
                for j, (pts_j, area_j) in enumerate(swf_contours):
                    if i == j:
                        continue
                    # If contour j has larger area and contains a point of i
                    if abs(area_j) > abs(area_i) and \
                       _point_in_polygon(pts_i[0][0], pts_i[0][1], pts_j):
                        is_hole[i] = True
                        break

            for ci, (pts, area) in enumerate(swf_contours):
                if is_hole[ci]:
                    # Hole: should be CCW (negative area)
                    if area > 0:
                        pts = list(reversed(pts))
                else:
                    # Outer/independent solid: should be CW (positive area)
                    if area < 0:
                        pts = list(reversed(pts))

                # First point (absolute, with fillStyle1=1 on first contour)
                x0, y0 = pts[0]
                setup_kwargs = {"x": x0, "y": y0}
                if ci == 0:
                    setup_kwargs["fillStyle1"] = 1
                edges.append(ShapeSetup(**setup_kwargs))

                # Subsequent points as LineTo (delta from previous)
                prev_x, prev_y = x0, y0
                for px, py in pts[1:]:
                    dx = px - prev_x
                    dy = py - prev_y
                    if dx != 0 or dy != 0:
                        edges.append(LineTo(dx, dy))
                    prev_x, prev_y = px, py

                # Close contour
                dx = x0 - prev_x
                dy = y0 - prev_y
                if dx != 0 or dy != 0:
                    edges.append(LineTo(dx, dy))

        glyphs.append((code_point, edges, advance))

    font.close()
    return {
        'glyphs': glyphs,
        'ascent': ascent,
        'descent': descent,
        'leading': 0,
    }


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

    def define_bits_jpeg4(self, object_id, jpeg_data_bytes, alpha_data,
                          deblocking=0.0):
        """Add a DefineBitsJPEG4 tag (tag 90) with JPEG data + zlib-compressed alpha + deblocking.

        jpeg_data_bytes: raw JPEG file bytes (complete JPEG).
        alpha_data: bytes/list of alpha values, one byte per pixel (length = width * height).
        deblocking: float deblocking filter parameter (FIXED8: 8.8 fixed-point).
                    0.0 means no deblocking.
        """
        compressed_alpha = zlib.compress(bytes(alpha_data))
        # Encode deblocking as FIXED8 (signed 8.8): integer part in high byte, fraction in low byte
        deblock_fixed = int(round(deblocking * 256.0))
        deblock_u16 = deblock_fixed & 0xFFFF
        # Tag body: CharacterID(UI16) + AlphaDataOffset(UI32) + DeblockParam(UI16) + JPEG data + compressed alpha
        alpha_data_offset = len(jpeg_data_bytes)
        tag_body = struct.pack('<HIH', object_id, alpha_data_offset, deblock_u16) + jpeg_data_bytes + compressed_alpha
        tag_b64 = base64.b64encode(tag_body).decode('ascii')
        self.tags.append(("DefineBitsJPEG4", tag_b64))

    def place_object(self, object_id, depth, trans_x=0, trans_y=0,
                     scale_x=None, scale_y=None,
                     skew_x=None, skew_y=None,
                     color_transform=None, clip_depth=None,
                     ratio=None):
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
            "ratio": ratio,
        }))

    def remove_object(self, depth):
        """Remove the character at the given depth from the display list (RemoveObject2, tag 28)."""
        self.tags.append(("RemoveObject2", {"depth": depth}))

    def remove_object_v1(self, object_id, depth):
        """Remove a character by ID and depth from the display list (RemoveObject, tag 5)."""
        self.tags.append(("RemoveObject", {"object_id": object_id, "depth": depth}))

    def define_font(self, object_id):
        """Create and register a font definition. Returns a FontDefinition for adding glyphs.

        Each glyph is a list of edge records (ShapeSetup, LineTo, CurveTo) that define
        a mini-shape.  The first edge should be a ShapeSetup with fillStyle1=1 and x/y.
        """
        font = FontDefinition(object_id)
        self.tags.append(("DefineFont", font))
        return font

    def define_font2(self, object_id, font_name="TestFont"):
        """Create and register a DefineFont2 definition (tag 48).

        Same glyph API as define_font but produces a DefineFont2 tag with
        font name, flags, code table, etc.
        """
        font = FontDefinition(object_id)
        font.font_name = font_name
        self.tags.append(("DefineFont2", font))
        return font

    def define_font3(self, object_id, font_name="TestFont"):
        """Create and register a DefineFont3 definition (tag 75).

        Same as DefineFont2 but uses 20480-unit EM square and always has
        wide codes.  Glyph coordinates should use the higher-resolution
        EM square (20x DefineFont2's 1024 units).
        """
        font = FontDefinition(object_id)
        font.font_name = font_name
        self.tags.append(("DefineFont3", font))
        return font

    def define_text(self, object_id, bounds, transform=None):
        """Create and register a text definition. Returns a TextDefinition for adding text records.

        bounds: (left, right, top, bottom) in twips
        transform: dict with transX, transY (optional)
        """
        text = TextDefinition(object_id, bounds, transform)
        self.tags.append(("DefineText", text))
        return text

    def define_text2(self, object_id, bounds, transform=None):
        """Create and register a DefineText2 definition (tag 33, RGBA colors).

        Same as define_text but uses RGBA colors instead of RGB.
        TextRecord color should be a 4-tuple (r, g, b, a).

        bounds: (left, right, top, bottom) in twips
        transform: dict with transX, transY (optional)
        """
        text = TextDefinition(object_id, bounds, transform)
        self.tags.append(("DefineText2", text))
        return text

    def define_edit_text(self, object_id, bounds, font_id=None, font_height=240,
                         color=None, initial_text=None, read_only=True,
                         max_length=None, layout=None):
        """Create and register a DefineEditText definition (tag 37).

        object_id: character ID
        bounds: (left, right, top, bottom) in twips
        font_id: UI16 character ID of a DefineFont2/3 (optional)
        font_height: UI16 text height in twips (default 240 = 12pt)
        color: (r, g, b, a) tuple (optional)
        initial_text: string to pre-populate the field with (optional)
        read_only: make the text field read-only (default True)
        max_length: maximum character count (optional)
        layout: dict with align, left_margin, right_margin, indent, leading (optional)
        """
        edit_text_def = {'object_id': object_id, 'bounds': bounds, 'read_only': read_only}
        if font_id is not None:
            edit_text_def['font_id'] = font_id
            edit_text_def['font_height'] = font_height
        if color is not None:
            edit_text_def['color'] = color
        if initial_text is not None:
            edit_text_def['initial_text'] = initial_text
        if max_length is not None:
            edit_text_def['max_length'] = max_length
        if layout is not None:
            edit_text_def['layout'] = layout
        self.tags.append(("DefineEditText", edit_text_def))

    def define_morph_shape(self, object_id, start_bounds, end_bounds):
        """Create and register a morph shape definition (tag 46).

        Returns a MorphShapeDefinition for adding fill/line styles and edges.
        """
        morph = MorphShapeDefinition(object_id, start_bounds, end_bounds)
        self.tags.append(("DefineMorphShape", morph))
        return morph

    def define_sprite(self, object_id, frame_count=1):
        """Create a sprite (movie clip) definition. Returns a SpriteDefinition for adding sub-tags."""
        sprite = SpriteDefinition(object_id, frame_count)
        self.tags.append(("DefineSprite", sprite))
        return sprite

    def define_button(self, object_id):
        """Create a button definition (tag 7). Returns a ButtonDefinition for adding records."""
        button = ButtonDefinition(object_id)
        self.tags.append(("DefineButton", button))
        return button

    def define_button2(self, object_id):
        """Create a button definition (tag 34). Returns a Button2Definition for adding records."""
        button = Button2Definition(object_id)
        self.tags.append(("DefineButton2", button))
        return button

    def add_raw_tag(self, tag_id, body_bytes):
        """Add a raw binary tag (emitted as UnknownTag)."""
        self.tags.append(("RawTag", (tag_id, body_bytes)))

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

            elif tag_type == "DefineBitsJPEG4":
                unk = SubElement(tags_el, "UnknownTag", id="0x5a")
                data_el = SubElement(unk, "data")
                data_el.text = tag_data

            elif tag_type == "DefineBits":
                obj_id, jpeg_b64 = tag_data
                db = SubElement(tags_el, "DefineBits", objectID=str(obj_id))
                data_wrap = SubElement(db, "data")
                data_el = SubElement(data_wrap, "data")
                data_el.text = jpeg_b64

            elif tag_type == "DefineFont":
                font = tag_data
                font_body = _build_define_font_body(font.object_id, font.glyphs)
                font_el = SubElement(tags_el, "DefineFont",
                                     objectID=str(font.object_id))
                data_outer = SubElement(font_el, "data")
                data_inner = SubElement(data_outer, "data")
                # swfmill expects base64-encoded tag body WITHOUT the
                # character ID (DefineFont element has objectID attr).
                # The <data> contains everything after the characterID field.
                data_inner.text = base64.b64encode(font_body[2:]).decode('ascii')

            elif tag_type == "DefineFont2":
                font = tag_data
                font_body = _build_define_font2_body(
                    font.object_id, font.glyphs,
                    getattr(font, 'font_name', 'TestFont'),
                    char_codes=font.char_codes or None,
                    advance_widths=font.advance_widths or None,
                    ascent=font.ascent, descent=font.descent,
                    leading=font.leading)
                tag_b64 = base64.b64encode(font_body).decode('ascii')
                unk = SubElement(tags_el, "UnknownTag", id="0x30")
                data_el = SubElement(unk, "data")
                data_el.text = tag_b64

            elif tag_type == "DefineFont3":
                font = tag_data
                font_body = _build_define_font2_body(
                    font.object_id, font.glyphs,
                    getattr(font, 'font_name', 'TestFont'),
                    char_codes=font.char_codes or None,
                    advance_widths=font.advance_widths or None,
                    ascent=font.ascent, descent=font.descent,
                    leading=font.leading)
                tag_b64 = base64.b64encode(font_body).decode('ascii')
                unk = SubElement(tags_el, "UnknownTag", id="0x4b")
                data_el = SubElement(unk, "data")
                data_el.text = tag_b64

            elif tag_type == "DefineText":
                text = tag_data
                text_el = SubElement(tags_el, "DefineText",
                                     objectID=str(text.object_id))
                # Bounds
                bounds_el = SubElement(text_el, "bounds")
                left, right, top, bottom = text.bounds
                SubElement(bounds_el, "Rectangle",
                           left=str(left), right=str(right),
                           top=str(top), bottom=str(bottom))
                # Transform
                transform_el = SubElement(text_el, "transform")
                t_attrs = {}
                for key in ("transX", "transY", "scaleX", "scaleY",
                            "skewX", "skewY"):
                    if key in text.transform:
                        val = text.transform[key]
                        if isinstance(val, float):
                            t_attrs[key] = f"{val:.16f}"
                        else:
                            t_attrs[key] = str(val)
                SubElement(transform_el, "Transform", **t_attrs)
                # Records
                records_el = SubElement(text_el, "records")
                tr_outer = SubElement(records_el, "TextRecord")
                tr_records = SubElement(tr_outer, "records")
                for rec in text.records:
                    # Setup record
                    setup_attrs = {"isSetup": "1"}
                    if rec.font_id is not None:
                        setup_attrs["objectID"] = str(rec.font_id)
                    if rec.text_height is not None:
                        setup_attrs["fontHeight"] = str(rec.text_height)
                    if rec.y_offset is not None:
                        setup_attrs["y"] = str(rec.y_offset)
                    if rec.x_offset is not None:
                        setup_attrs["x"] = str(rec.x_offset)
                    setup_el = SubElement(tr_records, "TextRecord6",
                                          **setup_attrs)
                    if rec.color is not None:
                        color_el = SubElement(setup_el, "color")
                        r, g, b = rec.color
                        SubElement(color_el, "Color",
                                   red=str(r), green=str(g), blue=str(b))
                    # Glyph record
                    if rec.glyphs:
                        glyph_rec = SubElement(tr_records, "TextRecord6",
                                               isSetup="0")
                        glyphs_el = SubElement(glyph_rec, "glyphs")
                        for glyph_idx, advance in rec.glyphs:
                            SubElement(glyphs_el, "TextEntry",
                                       glyph=str(glyph_idx),
                                       advance=str(advance))
                # End record (empty glyph record)
                end_rec = SubElement(tr_records, "TextRecord6", isSetup="0")
                SubElement(end_rec, "glyphs")

            elif tag_type == "DefineText2":
                text = tag_data
                tag_body = _build_define_text2_body(text)
                tag_b64 = base64.b64encode(tag_body).decode('ascii')
                unk = SubElement(tags_el, "UnknownTag", id="0x21")
                data_el = SubElement(unk, "data")
                data_el.text = tag_b64

            elif tag_type == "DefineEditText":
                edit_text_body = _build_define_edit_text_body(tag_data)
                tag_b64 = base64.b64encode(edit_text_body).decode('ascii')
                unk = SubElement(tags_el, "UnknownTag", id="0x25")
                data_el = SubElement(unk, "data")
                data_el.text = tag_b64

            elif tag_type == "DefineShape":
                tag_data.to_xml(tags_el)

            elif tag_type == "DefineMorphShape":
                morph_body = _build_define_morph_shape_body(tag_data)
                tag_b64 = base64.b64encode(morph_body).decode('ascii')
                unk = SubElement(tags_el, "UnknownTag", id="0x2e")
                data_el = SubElement(unk, "data")
                data_el.text = tag_b64

            elif tag_type == "DefineSprite":
                tag_data.to_xml(tags_el)

            elif tag_type == "DefineButton":
                body = tag_data.build_body()
                tag_b64 = base64.b64encode(body).decode('ascii')
                unk = SubElement(tags_el, "UnknownTag", id="0x07")
                data_el = SubElement(unk, "data")
                data_el.text = tag_b64

            elif tag_type == "DefineButton2":
                body = tag_data.build_body()
                tag_b64 = base64.b64encode(body).decode('ascii')
                unk = SubElement(tags_el, "UnknownTag", id="0x22")
                data_el = SubElement(unk, "data")
                data_el.text = tag_b64

            elif tag_type == "PlaceObject2":
                d = tag_data
                if d.get("ratio") is not None:
                    # swfmill doesn't support ratio in xml2swf, build raw binary
                    body = _build_place_object2_body(d)
                    tag_b64 = base64.b64encode(body).decode('ascii')
                    unk = SubElement(tags_el, "UnknownTag", id="0x1a")
                    data_el = SubElement(unk, "data")
                    data_el.text = tag_b64
                else:
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

            elif tag_type == "RemoveObject":
                d = tag_data
                SubElement(tags_el, "RemoveObject",
                           objectID=str(d["object_id"]),
                           depth=str(d["depth"]))

            elif tag_type == "RemoveObject2":
                d = tag_data
                SubElement(tags_el, "RemoveObject2", depth=str(d["depth"]))

            elif tag_type == "RawTag":
                tag_id, body_bytes = tag_data
                unk = SubElement(tags_el, "UnknownTag", id=hex(tag_id))
                data_el = SubElement(unk, "data")
                data_el.text = base64.b64encode(body_bytes).decode('ascii')

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
