#!/usr/bin/env python3
r"""Build child.swf and test.swf for regression/avm1_parent_child_modify_place.

WHAT THIS PINS DOWN
-------------------
Two things, both about a loaded child SWF's own `PlaceObject2` tags.

1. **`_x` / `_y` on a child's tag-placed clip.** A display entry's
   `transform_id` indexes the transform table of the movie whose TAG placed it.
   The child's ids index `child_transform_data`; the AVM1 property getters
   indexed the MAIN movie's `transform_data`, which for an MTASC parent with no
   timeline content is `float transform_data[1][16]` — so `_x` read past the end
   of a one-row array and returned a different garbage float on every run
   (measured: 8197.8125, -1.92062288988382e-6, -1.48600998484698e+20). Fixed by
   recording the placing movie's table on the display entry
   (`DisplayObject::place_transform_data`, written by `ng_cache_transform`).

2. **Character id 0 must never be re-based.** It is the "no character"
   sentinel, and in a `PlaceObject2` it is what makes the tag a MODIFY of
   whatever already sits at that depth rather than a place of a new character.
   Offsetting it turns every Modify in a loaded child into a place of character
   `base` — and because parent and child share ONE dictionary, `base` is an id
   the parent may well define.

   That bug is not hypothetical. The harness's original per-call regex list had
   it (`tagPlaceObject2\w*` rewrote `..., 0,` to `..., 1000,`); the value-keyed
   substitution that replaced the list skipped 0 explicitly; and the offset now
   lives in the recompiler (`charId()` in SWFRecomp/src/swf.cpp), which skips 0
   for the same reason.

THE SHAPE
---------
    parent test.swf  (AVM1, SWF8, MTASC + a spliced decoy sprite at char 1000)
                     loadMovie("child.swf") into _root.holder
    child.swf        (AVM1, SWF8, hand-built, 1 frame)

    frame 1: PlaceObject2 HasCharacter|HasMatrix|HasName  depth 1, char 1,
             "mc", translate (200, 100) twips = (10, 5) px
             PlaceObject2 Move|HasMatrix, char id ABSENT (= 0),
             translate (1000, 600) twips = (50, 30) px
    -> _root.holder.mc._x == 50, _y == 30

The parent defines (and never places) a sprite at char id 1000 = the child's
`movie_id * stride`, so a re-based sentinel does not name "nothing" — it names
a real character in the shared dictionary, which is the sharpest form the bug
can take.

BOTH TAGS ARE IN ONE FRAME, ON PURPOSE
--------------------------------------
The Modify used to sit in the child's frame 2. It never executed: a loaded
child movie's timeline does not advance past frame 0 in this configuration —
`actionFirePendingDirectLoads` runs `child_frame_0` and nothing ever calls
`child_frame_1` (verified by breaking on `tagPlaceObject2`: exactly one call,
from `child_frame_0`). That is a separate defect, filed in BACKLOG §Multi-SWF;
it is also the real reason the earlier version of this test could not
discriminate, superseding "an is_replace == 0 place at an occupied depth is a
no-op". Placing and modifying in the SAME frame sidesteps it entirely and makes
the Modify observable.

THIS TEST DISCRIMINATES
-----------------------
Three distinguishable states, all measured:

  * before the `place_transform_data` fix: `x:` and `y:` are garbage floats
    that differ on every run (an out-of-bounds read);
  * with `charId()` sabotaged to offset 0 as well
    (`std::to_string(id + g_char_id_base)`): the second tag stops being a
    Modify and becomes a place of the parent's decoy character 1000 at an
    already-occupied depth, so the translate never lands and the rows read
    `x:10` / `y:5` — the FIRST placement's matrix;
  * correct: `x:50` / `y:30`.

`typeof` and `_name` are kept as controls: they read correctly in all three
states, so a failure that moves them is a different bug.

See SWFRecompDocs/status/child-placed-clip-uninit.md for the full write-up.
"""
import struct
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent

INNER_ID = 1          # the sprite placed at depth 1
DEPTH = 1
CLIP_NAME = "mc"
PLACE_TWIPS = (200, 100)     # the first placement's matrix: (10, 5) px
MODIFY_TWIPS = (1000, 600)   # the same-frame Modify's matrix: (50, 30) px

# The parent defines a sprite at exactly the id the child's stride would
# produce if character id 0 were re-based (movie_id 1 * stride 1000). That is
# what makes the 0 sentinel's re-basing OBSERVABLE rather than merely wrong:
# the dictionary is SHARED between parent and child, so an offset 0 does not
# name "nothing", it names the parent's decoy.
DECOY_ID = 1000


def tag(code, data):
    if len(data) < 0x3F:
        return struct.pack('<H', (code << 6) | len(data)) + data
    return struct.pack('<HI', (code << 6) | 0x3F, len(data)) + data


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
            byte = 0
            for b in self.bits[i:i + 8]:
                byte = (byte << 1) | b
            byte <<= (8 - len(self.bits[i:i + 8]))
            out.append(byte)
        return bytes(out)


def matrix_identity():
    # HasScale=0, HasRotate=0, NTranslateBits=0 -> 7 bits, one padded byte.
    return Bits().u(0, 1).u(0, 1).u(0, 5).bytes()


def matrix_translate(tx, ty):
    nbits = max(tx.bit_length(), ty.bit_length()) + 1   # +1 for the sign bit
    return Bits().u(0, 1).u(0, 1).u(nbits, 5).s(tx, nbits).s(ty, nbits).bytes()


def place_character(depth, char_id, name, tx, ty):
    """PlaceObject2 HasCharacter | HasMatrix | HasName."""
    flags = 0x02 | 0x04 | 0x20
    return tag(26, struct.pack('<BHH', flags, depth, char_id)
               + matrix_translate(tx, ty) + name.encode('ascii') + b'\x00')


def modify_matrix(depth, tx, ty):
    """PlaceObject2 Move | HasMatrix — no HasCharacter, so the char id is 0.

    PlaceFlagMove (0x01) with HasCharacter (0x02) CLEAR is exactly what makes
    this a Modify of whatever occupies `depth`; the tag carries no character
    id at all, and the recompiler emits 0 for it.
    """
    flags = 0x01 | 0x04
    return tag(26, struct.pack('<BH', flags, depth) + matrix_translate(tx, ty))


def show_frame():
    return tag(1, b'')


def end_tag():
    return struct.pack('<H', 0)


def define_sprite(char_id, declared_frames, body):
    return tag(39, struct.pack('<HH', char_id, declared_frames) + body)


def build_child(path):
    tags = define_sprite(INNER_ID, 1, show_frame() + end_tag())
    tags += place_character(DEPTH, INNER_ID, CLIP_NAME, *PLACE_TWIPS)
    # Same frame as the place: a loaded child never reaches its frame 2 (see
    # the module docstring), so a cross-frame Modify would simply not run.
    tags += modify_matrix(DEPTH, *MODIFY_TWIPS)
    tags += show_frame()
    tags += end_tag()

    # RECT nbits=15, 0..4000 twips square (200x200 px stage, never rendered).
    rect = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
    body = rect + struct.pack('<H', 30 << 8) + struct.pack('<H', 1) + tags
    file_length = 8 + len(body)
    path.write_bytes(b'FWS' + struct.pack('<BI', 8, file_length) + body)
    print(f'Created {path} (SWF8, 1 frame, {file_length} bytes)')


def read_swf(path):
    """Split an SWF into (version, header_prefix, tag_stream)."""
    raw = path.read_bytes()
    sig, version = raw[:3], raw[3]
    body = raw[8:]
    if sig == b'CWS':
        import zlib
        body = zlib.decompress(body)
    elif sig != b'FWS':
        raise SystemExit(f'{path}: unsupported signature {sig!r}')
    nbits = body[0] >> 3
    rect_len = (5 + 4 * nbits + 7) // 8
    prefix = body[:rect_len + 4]        # RECT + frame rate + frame count
    return version, prefix, body[rect_len + 4:]


def first_showframe_offset(tag_bytes):
    """Byte offset of the first ShowFrame (code 1) record."""
    pos = 0
    while pos + 2 <= len(tag_bytes):
        code_len = struct.unpack('<H', tag_bytes[pos:pos + 2])[0]
        code, length = code_len >> 6, code_len & 0x3F
        hdr = 2
        if length == 0x3F:
            length = struct.unpack('<I', tag_bytes[pos + 2:pos + 6])[0]
            hdr = 6
        if code == 1:
            return pos
        if code == 0:
            break
        pos += hdr + length
    raise SystemExit('no ShowFrame tag found')


def build_parent(path):
    mtasc = Path.home() / 'CC' / 'mtasc' / 'bin' / 'mtasc'
    std = Path.home() / 'CC' / 'mtasc' / 'ocaml' / 'mtasc' / 'std'
    std8 = Path.home() / 'CC' / 'mtasc' / 'ocaml' / 'mtasc' / 'std8'
    cmd = [str(mtasc), '-cp', str(std), '-cp', str(std8), '-main',
           '-header', '200:200:30', 'Parent.as', '-swf', path.name,
           '-version', '8']
    print('$ ' + ' '.join(cmd))
    subprocess.run(cmd, cwd=str(HERE), check=True)

    # Splice the decoy sprite into the parent's frame 1 (MTASC has no
    # timeline-authoring syntax). It is DEFINED and never PLACED: the only
    # thing that can place it is a lookup of character DECOY_ID, and the only
    # code that could produce that id is the child's re-based sentinel.
    version, prefix, tag_bytes = read_swf(path)
    decoy = define_sprite(DECOY_ID, 1, show_frame() + end_tag())
    cut = first_showframe_offset(tag_bytes)
    body = prefix + tag_bytes[:cut] + decoy + tag_bytes[cut:]
    path.write_bytes(b'FWS' + struct.pack('<BI', version, 8 + len(body)) + body)
    print(f'Created {path} ({path.stat().st_size} bytes, '
          f'decoy sprite {DECOY_ID} spliced into frame 1)')


if __name__ == '__main__':
    build_child(HERE / 'child.swf')
    try:
        build_parent(HERE / 'test.swf')
    except FileNotFoundError:
        print('MTASC not found; test.swf left as-is', file=sys.stderr)
