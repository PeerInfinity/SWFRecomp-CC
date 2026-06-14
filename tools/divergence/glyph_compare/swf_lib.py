"""Minimal SWF read/write primitives for building isolated test SWFs.

Used by the glyph_compare tools to extract a single font / DefineShape /
DefineText out of a real SWF and wrap it in a tiny SWF that can be rendered
by BOTH the Ruffle exporter and SWFRecomp for a per-asset visual diff.

These are deliberately small and dependency-free (stdlib only). They cover the
subset of the SWF format the comparison harness needs; they are NOT a general
SWF library.
"""
import struct
import zlib


# --------------------------------------------------------------------------
# Reading
# --------------------------------------------------------------------------

def decompress(data: bytes) -> bytes:
    """CWS/ZWS -> FWS (uncompressed). Returns FWS data unchanged."""
    sig = data[:3]
    if sig == b'FWS':
        return data
    if sig == b'CWS':
        return b'FWS' + data[3:8] + zlib.decompress(data[8:])
    if sig == b'ZWS':
        import lzma
        props = data[12:17]
        stream = data[17:]
        body = lzma.decompress(
            props + struct.pack('<Q', 0xFFFFFFFFFFFFFFFF) + stream,
            format=lzma.FORMAT_ALONE)
        return b'FWS' + data[3:8] + body
    raise RuntimeError(f"Unknown SWF signature {sig!r}")


def body_start(data: bytes) -> int:
    """Byte offset of the first tag (after header rect + framerate + count)."""
    pos = 8
    nbits = (data[pos] >> 3) & 0x1F
    pos += (5 + nbits * 4 + 7) // 8   # frame size RECT
    pos += 4                          # framerate(2) + frame count(2)
    return pos


def iter_tags(data: bytes):
    """Yield (code, tag_start, header_size, body_len) for every top-level tag."""
    p = body_start(data)
    while p < len(data):
        th = struct.unpack('<H', data[p:p + 2])[0]
        code = th >> 6
        ln = th & 0x3F
        hs = 2
        if ln == 0x3F:
            ln = struct.unpack('<I', data[p + 2:p + 6])[0]
            hs = 6
        yield code, p, hs, ln
        p += hs + ln
        if code == 0:
            break


# Tag codes
DEFINE_SHAPE = 2
DEFINE_SHAPE2 = 22
DEFINE_SHAPE3 = 32
DEFINE_SHAPE4 = 83
DEFINE_FONT = 10
DEFINE_FONT2 = 48
DEFINE_FONT3 = 75
DEFINE_TEXT = 11
DEFINE_TEXT2 = 33
SHAPE_TAGS = (DEFINE_SHAPE, DEFINE_SHAPE2, DEFINE_SHAPE3, DEFINE_SHAPE4)
FONT_TAGS = (DEFINE_FONT, DEFINE_FONT2, DEFINE_FONT3)


def find_tag_by_id(data: bytes, codes, char_id: int):
    """Return raw tag bytes (header+body) for the Define* tag with this id."""
    for code, p, hs, ln in iter_tags(data):
        if code in codes:
            cid = struct.unpack('<H', data[p + hs:p + hs + 2])[0]
            if cid == char_id:
                return data[p:p + hs + ln]
    return None


def font2_num_glyphs(font_tag: bytes):
    """(font_id, num_glyphs) for a DefineFont2/3 raw tag."""
    th = struct.unpack('<H', font_tag[:2])[0]
    hs = 6 if (th & 0x3F) == 0x3F else 2
    b = font_tag[hs:]
    fid = struct.unpack('<H', b[:2])[0]
    namelen = b[4]
    ng = struct.unpack('<H', b[5 + namelen:7 + namelen])[0]
    return fid, ng


# --------------------------------------------------------------------------
# Writing
# --------------------------------------------------------------------------

class Bits:
    """MSB-first bit writer (matches SWF bit packing)."""
    def __init__(self):
        self.b = bytearray()
        self.cur = 0
        self.n = 0

    def w(self, val, bits):
        for i in range(bits - 1, -1, -1):
            self.cur = (self.cur << 1) | ((val >> i) & 1)
            self.n += 1
            if self.n == 8:
                self.b.append(self.cur)
                self.cur = 0
                self.n = 0

    def bytes(self):
        if self.n:
            self.b.append(self.cur << (8 - self.n))
            self.cur = 0
            self.n = 0
        return bytes(self.b)


def _sbits_needed(v):
    n = 1
    while not (-(1 << (n - 1)) <= v <= (1 << (n - 1)) - 1):
        n += 1
    return n


def rect(xmin, xmax, ymin, ymax) -> bytes:
    nbits = max(_sbits_needed(v) for v in (xmin, xmax, ymin, ymax))
    bw = Bits()
    bw.w(nbits, 5)
    for v in (xmin, xmax, ymin, ymax):
        bw.w(v & ((1 << nbits) - 1), nbits)
    return bw.bytes()


def matrix_translate(tx=0, ty=0) -> bytes:
    """MATRIX with no scale/rotate, optional translate."""
    mb = Bits()
    mb.w(0, 1)   # HasScale
    mb.w(0, 1)   # HasRotate
    nb = max(_sbits_needed(tx), _sbits_needed(ty), 1)
    mb.w(nb, 5)
    mb.w(tx & ((1 << nb) - 1), nb)
    mb.w(ty & ((1 << nb) - 1), nb)
    return mb.bytes()


def tag(code, payload: bytes) -> bytes:
    if len(payload) < 0x3F:
        return struct.pack('<H', (code << 6) | len(payload)) + payload
    return struct.pack('<H', (code << 6) | 0x3F) + struct.pack('<I', len(payload)) + payload


def place_object2(depth, char_id, tx=0, ty=0) -> bytes:
    """PlaceObject2 with HasCharacter|HasMatrix, translate-only matrix."""
    po = bytearray()
    po.append(0x06)                        # HasCharacter(0x02)|HasMatrix(0x04)
    po += struct.pack('<H', depth)
    po += struct.pack('<H', char_id)
    po += matrix_translate(tx, ty)
    return tag(26, bytes(po))


def set_background_color(r, g, b) -> bytes:
    return tag(9, bytes([r, g, b]))


def show_frame() -> bytes:
    return tag(1, b'')


def end_tag() -> bytes:
    return tag(0, b'')


def wrap_swf(frame_rect: bytes, tags: bytes, version=8, fps=30) -> bytes:
    """Assemble a complete FWS SWF from a frame RECT and a tag byte stream."""
    body = bytearray()
    body += frame_rect
    body += struct.pack('<H', fps << 8)    # framerate 8.8 fixed
    body += struct.pack('<H', 1)           # frame count
    body += tags
    header = b'FWS' + bytes([version])
    return header + struct.pack('<I', 8 + len(body)) + bytes(body)
