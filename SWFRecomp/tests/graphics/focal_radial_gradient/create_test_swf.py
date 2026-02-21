#!/usr/bin/env python3
"""Generate test.swf for focal_radial_gradient graphics test.

Shape with a focal radial gradient fill (fill type 0x13).
The focal point is offset from the gradient center, creating
an asymmetric radial gradient effect.

NOTE: swfmill does not support focal gradient (FOCALGRADIENT) natively,
so this script generates the SWF binary directly instead of using
swfmill_helpers.py.
"""
import struct


class BitWriter:
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


def bits_needed_signed(value):
    """Minimum bits to represent a signed value."""
    if value == 0:
        return 1
    if value > 0:
        return value.bit_length() + 1
    return (abs(value) - 1).bit_length() + 1


def write_rect(bw, xmin, xmax, ymin, ymax):
    vals = [xmin, xmax, ymin, ymax]
    nbits = max(bits_needed_signed(v) for v in vals)
    bw.write_bits(nbits, 5)
    for v in vals:
        bw.write_sb(v, nbits)
    bw.align()


def write_matrix(bw, scale_x=None, scale_y=None, tx=0, ty=0):
    has_scale = scale_x is not None and scale_y is not None
    bw.write_bits(1 if has_scale else 0, 1)
    if has_scale:
        sx_fixed = int(scale_x * 65536)
        sy_fixed = int(scale_y * 65536)
        nbits = max(bits_needed_signed(sx_fixed), bits_needed_signed(sy_fixed))
        bw.write_bits(nbits, 5)
        bw.write_sb(sx_fixed, nbits)
        bw.write_sb(sy_fixed, nbits)
    bw.write_bits(0, 1)  # HasRotate = 0
    max_trans = max(abs(tx), abs(ty))
    if max_trans == 0:
        nbits = 1
    else:
        nbits = bits_needed_signed(max(tx, ty, -tx, -ty, key=lambda v: abs(v) if isinstance(v, int) else 0))
        nbits = max(bits_needed_signed(tx), bits_needed_signed(ty))
    bw.write_bits(nbits, 5)
    bw.write_sb(tx, nbits)
    bw.write_sb(ty, nbits)
    bw.align()


def make_define_shape(shape_id, bounds, fill_type, grad_scale, grad_tx, grad_ty,
                      gradient_stops, focal_point=None, line_width=0, line_rgb=None):
    """Build a DefineShape tag body (tag 2) with a gradient fill."""
    body = bytearray()
    body += struct.pack('<H', shape_id)

    # Bounds RECT
    bw = BitWriter()
    write_rect(bw, *bounds)
    body += bw.to_bytes()

    # Fill style array
    body += struct.pack('B', 1)  # count = 1
    body += struct.pack('B', fill_type)

    # Gradient matrix
    bw = BitWriter()
    write_matrix(bw, scale_x=grad_scale, scale_y=grad_scale, tx=grad_tx, ty=grad_ty)
    body += bw.to_bytes()

    # Gradient: SpreadMode(2) | InterpolationMode(2) | NumGradients(4)
    num_stops = len(gradient_stops)
    body += struct.pack('B', num_stops & 0x0F)

    for ratio, r, g, b in gradient_stops:
        body += struct.pack('BBBB', ratio, r, g, b)

    # Focal point (FIXED8, only for type 0x13)
    if focal_point is not None:
        focal_fixed8 = int(focal_point * 256)
        body += struct.pack('<h', focal_fixed8)

    # Line style array
    has_line = line_width > 0 and line_rgb is not None
    body += struct.pack('B', 1 if has_line else 0)
    if has_line:
        body += struct.pack('<H', line_width)
        body += struct.pack('BBB', *line_rgb)

    # Shape records
    bw = BitWriter()
    num_fill_bits = 1
    num_line_bits = 1 if has_line else 0
    bw.write_bits(num_fill_bits, 4)
    bw.write_bits(num_line_bits, 4)

    # StyleChange: move to start, set fillStyle1=1 (and lineStyle=1 if applicable)
    bw.write_bits(0, 1)  # TypeFlag = non-edge
    bw.write_bits(0, 1)  # StateNewStyles
    bw.write_bits(1 if has_line else 0, 1)  # StateLineStyle
    bw.write_bits(1, 1)  # StateFillStyle1
    bw.write_bits(0, 1)  # StateFillStyle0
    bw.write_bits(1, 1)  # StateMoveTo
    bw.write_bits(1, 5)  # MoveBits = 1
    bw.write_sb(0, 1)    # MoveDeltaX = 0
    bw.write_sb(0, 1)    # MoveDeltaY = 0
    bw.write_bits(1, num_fill_bits)  # FillStyle1 = 1
    if has_line:
        bw.write_bits(1, num_line_bits)  # LineStyle = 1

    # Rectangle edges
    w = bounds[1]  # xmax
    h = bounds[3]  # ymax
    edges = [(w, 0), (0, h), (-w, 0), (0, -h)]

    for dx, dy in edges:
        bw.write_bits(1, 1)  # TypeFlag = edge
        bw.write_bits(1, 1)  # StraightFlag
        max_delta = max(abs(dx), abs(dy))
        nbits = max(bits_needed_signed(dx), bits_needed_signed(dy), 2)
        bw.write_bits(nbits - 2, 4)  # NumBits - 2
        if dx != 0 and dy != 0:
            bw.write_bits(1, 1)  # GeneralLine
            bw.write_sb(dx, nbits)
            bw.write_sb(dy, nbits)
        elif dy == 0:
            bw.write_bits(0, 1)  # not GeneralLine
            bw.write_bits(0, 1)  # Horizontal
            bw.write_sb(dx, nbits)
        else:
            bw.write_bits(0, 1)  # not GeneralLine
            bw.write_bits(1, 1)  # Vertical
            bw.write_sb(dy, nbits)

    # EndShape
    bw.write_bits(0, 6)
    body += bw.to_bytes()

    return bytes(body)


def make_swf_tag(tag_code, body):
    """Encode a SWF tag with header."""
    length = len(body)
    if length < 63:
        return struct.pack('<H', (tag_code << 6) | length) + body
    else:
        return struct.pack('<H', (tag_code << 6) | 0x3F) + struct.pack('<I', length) + body


def make_swf(tags, width=550, height=400, fps=12, version=4, frame_count=1):
    """Build a complete SWF file."""
    tag_data = bytearray()
    for tag_code, body in tags:
        tag_data += make_swf_tag(tag_code, body)

    bw = BitWriter()
    write_rect(bw, 0, width * 20, 0, height * 20)
    rect_bytes = bw.to_bytes()

    file_length = 8 + len(rect_bytes) + 2 + 2 + len(tag_data)

    header = bytearray()
    header += b'FWS'
    header += struct.pack('B', version)
    header += struct.pack('<I', file_length)
    header += rect_bytes
    header += struct.pack('<H', fps << 8)  # 8.8 fixed-point frame rate
    header += struct.pack('<H', frame_count)

    return bytes(header) + bytes(tag_data)


# --- Build the test SWF ---

tags = []

# SetBackgroundColor (tag 9): white
tags.append((9, struct.pack('BBB', 255, 255, 255)))

# DefineShape (tag 2): full-stage rectangle with focal radial gradient
shape_body = make_define_shape(
    shape_id=1,
    bounds=(0, 11000, 0, 8000),  # full stage in twips
    fill_type=0x13,  # FILL_GRAD_FOCAL
    grad_scale=0.30,
    grad_tx=5500,
    grad_ty=4000,
    gradient_stops=[
        (0, 255, 0, 0),      # red at center
        (128, 255, 255, 0),   # yellow at midpoint
        (255, 0, 0, 255),     # blue at edge
    ],
    focal_point=0.75,
    line_width=20,
    line_rgb=(0, 0, 0),
)
tags.append((2, shape_body))

# PlaceObject2 (tag 26): place shape at depth 1
place_body = bytearray()
place_body += struct.pack('B', 0x06)  # HasMatrix + HasCharacter
place_body += struct.pack('<H', 1)    # Depth
place_body += struct.pack('<H', 1)    # CharacterID
bw = BitWriter()
write_matrix(bw)  # identity
place_body += bw.to_bytes()
tags.append((26, bytes(place_body)))

# ShowFrame (tag 1)
tags.append((1, b''))

# End (tag 0)
tags.append((0, b''))

swf_data = make_swf(tags)

with open('test.swf', 'wb') as f:
    f.write(swf_data)
print("Created test.swf")
