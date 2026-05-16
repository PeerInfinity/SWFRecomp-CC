#!/usr/bin/env python3
"""Generate test.swf for jpeg_mid_stream_eoi_soi regression test.

Verifies the recompiler's stripInvalidJpegMarkers helper: a JPEG payload
embedded in a DefineBitsJPEG2 tag has a spurious FF D9 FF D8 (EOI+SOI)
sequence spliced in *between the encoding tables and the SOF0 marker*.

This reproduces the defect observed in Avalanche's 3 failing
DefineBitsJPEG2/3 tags (see SWFRecompDocs/plans/define-bits-jpeg-robustness.md
and Ruffle issue ruffle-rs/ruffle#8775). Before the fix, our handler only
stripped this sequence when it appeared at offset 0; stb_image fails the
mid-stream case with "unknown marker". With the fix, the recompiler
splices it out and the bitmap decodes correctly.
"""
import io
import sys
import os

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from PIL import Image
from swfmill_helpers import (
    SWFMLBuilder, ClippedBitmapFill,
    ShapeSetup, LineTo,
)


def inject_mid_stream_eoi_soi(jpeg_bytes: bytes) -> bytes:
    """Splice an FF D9 FF D8 sequence between the JPEG tables and SOF0.

    Walks the JPEG marker sequence to find the SOF0 marker, then inserts
    the 4-byte EOI+SOI sequence immediately before it. The result is a
    JPEG that stb_image rejects ("unknown marker") unless the recompiler
    runs Ruffle's remove_invalid_jpeg_data pass on it.
    """
    SOF0 = 0xC0
    STANDALONE = {0xD8, 0xD9, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7}

    i = 0
    while i + 1 < len(jpeg_bytes):
        if jpeg_bytes[i] != 0xFF:
            raise RuntimeError(f"lost JPEG marker stream at offset {i}")
        m = jpeg_bytes[i + 1]
        if m == SOF0:
            break
        if m in STANDALONE:
            i += 2
            continue
        if i + 4 > len(jpeg_bytes):
            raise RuntimeError("truncated JPEG before SOF0")
        seg_len = (jpeg_bytes[i + 2] << 8) | jpeg_bytes[i + 3]
        i += 2 + seg_len
    else:
        raise RuntimeError("no SOF0 marker found")

    # i now points at FF C0 (SOF0). Insert the spurious sequence right here.
    return jpeg_bytes[:i] + bytes([0xFF, 0xD9, 0xFF, 0xD8]) + jpeg_bytes[i:]


# Build an 8x8 quadrant bitmap (same scheme as jpeg2_bitmap).
W, H = 8, 8
img = Image.new("RGB", (W, H))
for y in range(H):
    for x in range(W):
        if y < H // 2:
            img.putpixel((x, y), (255, 0, 0) if x < W // 2 else (0, 255, 0))
        else:
            img.putpixel((x, y), (0, 0, 255) if x < W // 2 else (255, 255, 0))

jpeg_buf = io.BytesIO()
img.save(jpeg_buf, format="JPEG", quality=100, subsampling=0)
jpeg_bytes = jpeg_buf.getvalue()
corrupted = inject_mid_stream_eoi_soi(jpeg_bytes)
assert corrupted != jpeg_bytes, "injection failed (bytes unchanged)"
assert b"\xFF\xD9\xFF\xD8" in corrupted, "EOI+SOI sequence not present"

swf = SWFMLBuilder(width=550, height=400, fps=12, version=8)
swf.set_background(255, 255, 255)

swf.define_bits_jpeg2(object_id=1, jpeg_data_bytes=corrupted)

DISPLAY_W, DISPLAY_H = 200, 200
left = (550 - DISPLAY_W) // 2 * 20
top = (400 - DISPLAY_H) // 2 * 20
right = left + DISPLAY_W * 20
bottom = top + DISPLAY_H * 20
sx = float(DISPLAY_W) / W * 20.0
sy = float(DISPLAY_H) / H * 20.0

shape = swf.define_shape(object_id=2, bounds=(left, right, top, bottom))
shape.add_fill(ClippedBitmapFill(
    object_id=1,
    matrix={"scaleX": sx, "scaleY": sy, "transX": left, "transY": top},
))

shape.add_edges([
    ShapeSetup(x=right, y=bottom, fillStyle1=1),
    LineTo(-(right - left), 0),
    LineTo(0, -(bottom - top)),
    LineTo(right - left, 0),
    LineTo(0, bottom - top),
])

swf.place_object(object_id=2, depth=1)
swf.show_frame()
swf.save("test.swf")
