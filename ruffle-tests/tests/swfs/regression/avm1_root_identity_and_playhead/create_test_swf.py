#!/usr/bin/env python3
r"""Build test.swf for regression/avm1_root_identity_and_playhead.

WHAT THIS PINS DOWN
-------------------
**`_root` is a MovieClip, and its playhead properties track the natural
advance** — in EVERY build configuration, not only the two the CI test modes
compile.

Two independent root-side facts, one row per frame:

1. **Identity.** `typeof(_root)` is `movieclip`, and the three MovieClip-only
   properties `_currentframe` / `_totalframes` / `_framesloaded` resolve to
   numbers. They share a single guard — `!MC_IS_TEXTFIELD(mc)` in the member
   getter, and `MC_IS_TEXTFIELD(mc) && g_swf_version >= 6` in `actionTypeof` —
   so one wrong field on the root MovieClip makes all four rows wrong at once
   and nothing else move. `s:` adds a root-placed named bare `DefineShape`,
   which is `movieclip` in Flash and in Ruffle, and which reads through the
   same `_root` member path.

2. **Playhead.** `cf:` rises 1, 2, 3 across the three frames. A build that
   never syncs `root_movieclip.currentframe` to the natural advance parks it
   at 1 forever while every other column stays right.

WHY IT IS HAND-BUILT AND NOT MTASC
----------------------------------
MTASC emits a single-frame SWF, and a one-frame movie cannot tell a synced
playhead from a frozen one — column 2 needs three frames of root timeline.
The traces are therefore raw AVM1: GetVariable / GetMember / Typeof / Add2.

WHAT THE CORPUS CAN AND CANNOT SEE
----------------------------------
Both facts were BROKEN in browser-WASM and in the native windowed player, and
correct in both CI test modes, so **a corpus run cannot flip these rows** — the
fields that carry them (`root_movieclip`'s designated initializer; the
`root_movieclip.currentframe` sync in swf.c) were gated on
`NO_GRAPHICS || OFFSCREEN_RENDER`, which is exactly the set CI compiles. The
fixture is graded in the browser harness
(`tools/browser-test/child_probe/`) and runs green in the corpus as a
non-regression guard on the headless side.

See SWFRecompDocs/status/browser-root-side-gaps.md.
"""
import struct
from pathlib import Path

HERE = Path(__file__).resolve().parent
SHAPE_ID = 1
FRAMES = 3


def sbits_needed(*vals):
    m = 1
    for v in vals:
        m = max(m, v.bit_length() + 1 if v >= 0 else (~v).bit_length() + 1)
    return m


class Bits:
    """MSB-first bit writer (SWF bit order)."""

    def __init__(self):
        self.bits = []

    def u(self, value, n):
        for i in range(n - 1, -1, -1):
            self.bits.append((value >> i) & 1)
        return self

    def s(self, value, n):
        return self.u(value & ((1 << n) - 1), n)

    def bytes(self):
        out = bytearray()
        for i in range(0, len(self.bits), 8):
            chunk = self.bits[i:i + 8]
            byte = 0
            for b in chunk:
                byte = (byte << 1) | b
            byte <<= (8 - len(chunk))
            out.append(byte)
        return bytes(out)


def rect(xmin, xmax, ymin, ymax):
    nb = max(sbits_needed(v) for v in (xmin, xmax, ymin, ymax))
    b = Bits()
    b.u(nb, 5)
    for v in (xmin, xmax, ymin, ymax):
        b.s(v, nb)
    return b.bytes()


def tag(code, data):
    n = len(data)
    if n < 0x3F:
        return struct.pack('<H', (code << 6) | n) + data
    return struct.pack('<H', (code << 6) | 0x3F) + struct.pack('<I', n) + data


def define_shape(shape_id, x0, y0, x1, y1, rgb):
    """DefineShape (tag 2): one solid-filled rectangle. Coordinates in TWIPS."""
    body = bytearray()
    body += struct.pack('<H', shape_id)
    body += rect(x0, x1, y0, y1)
    body.append(1)                  # FillStyleCount = 1
    body.append(0x00)               # FILLSTYLE type 0x00 = solid
    body += bytes(rgb)              # RGB
    body.append(0)                  # LineStyleCount = 0

    b = Bits()
    b.u(1, 4)                       # NumFillBits = 1
    b.u(0, 4)                       # NumLineBits = 0
    b.u(0, 1)                       # TypeFlag = 0 (non-edge)
    b.u(0, 1)                       # StateNewStyles
    b.u(0, 1)                       # StateLineStyle
    b.u(0, 1)                       # StateFillStyle1
    b.u(1, 1)                       # StateFillStyle0
    b.u(1, 1)                       # StateMoveTo
    nb = sbits_needed(x0, y0)
    b.u(nb, 5)
    b.s(x0, nb)
    b.s(y0, nb)
    b.u(1, 1)                       # FillStyle0 index = 1
    w, h = x1 - x0, y1 - y0
    for dx, dy in ((w, 0), (0, h), (-w, 0), (0, -h)):
        n2 = max(sbits_needed(dx, dy), 2)
        b.u(1, 1)                   # TypeFlag = 1 (edge)
        b.u(1, 1)                   # StraightFlag = 1
        b.u(n2 - 2, 4)              # NumBits
        b.u(1, 1)                   # GeneralLineFlag = 1
        b.s(dx, n2)
        b.s(dy, n2)
    b.u(0, 6)                       # EndShapeRecord
    body += b.bytes()
    return tag(2, bytes(body))


def matrix_translate(tx, ty):
    nbits = max(tx.bit_length(), ty.bit_length()) + 1   # +1 for the sign bit
    return Bits().u(0, 1).u(0, 1).u(nbits, 5).s(tx, nbits).s(ty, nbits).bytes()


def place_character(depth, char_id, name, tx, ty):
    """PlaceObject2 HasCharacter | HasMatrix | HasName."""
    flags = 0x02 | 0x04 | 0x20
    return tag(26, struct.pack('<BHH', flags, depth, char_id)
               + matrix_translate(tx, ty) + name.encode('ascii') + b'\x00')


def show_frame():
    return tag(1, b'')


def end_tag():
    return struct.pack('<H', 0)


# --- AVM1 action records ------------------------------------------------
ACTION_GET_VARIABLE = b'\x1c'
ACTION_GET_MEMBER = b'\x4e'
ACTION_TYPEOF = b'\x44'
ACTION_ADD2 = b'\x47'
ACTION_TRACE = b'\x26'


def push_string(s):
    """ActionPush (0x96) carrying one type-0 (string) value."""
    payload = b'\x00' + s.encode('ascii') + b'\x00'
    return b'\x96' + struct.pack('<H', len(payload)) + payload


def do_action(body):
    """DoAction (code 12). The terminating 0x00 is added here."""
    return tag(12, body + b'\x00')


def get_var(name):
    return push_string(name) + ACTION_GET_VARIABLE


def get_member(obj_code, name):
    return obj_code + push_string(name) + ACTION_GET_MEMBER


def concat(*parts):
    """Left-to-right string concatenation. Add2 pops b then a and pushes a+b,
    so each new part is appended with one Add2 immediately after it."""
    out = parts[0]
    for p in parts[1:]:
        out += p + ACTION_ADD2
    return out


def frame_trace(n):
    root = get_var('_root')
    return do_action(concat(
        push_string('r%d t:' % n),
        root + ACTION_TYPEOF,
        push_string(' cf:'),
        get_member(root, '_currentframe'),
        push_string(' tf:'),
        get_member(root, '_totalframes'),
        push_string(' fl:'),
        get_member(root, '_framesloaded'),
        push_string(' s:'),
        get_member(root, 'ctl') + ACTION_TYPEOF,
    ) + ACTION_TRACE)


def build(path):
    tags = define_shape(SHAPE_ID, 0, 0, 400, 400, (255, 0, 0))
    # frame 1: place the bare shape under a name, then read the root.
    tags += place_character(1, SHAPE_ID, 'ctl', 200, 200)
    tags += frame_trace(1)
    tags += show_frame()
    for n in range(2, FRAMES + 1):
        tags += frame_trace(n)
        tags += show_frame()
    tags += end_tag()

    # RECT nbits=15, 0..4000 twips square (200x200 px stage).
    stage = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
    body = stage + struct.pack('<H', 30 << 8) + struct.pack('<H', FRAMES) + tags
    file_length = 8 + len(body)
    path.write_bytes(b'FWS' + struct.pack('<BI', 8, file_length) + body)
    print('Created %s (SWF8, %d frames, %d bytes)' % (path, FRAMES, file_length))


if __name__ == '__main__':
    build(HERE / 'test.swf')
