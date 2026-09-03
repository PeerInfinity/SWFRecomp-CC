#!/usr/bin/env python3
r"""Build child.swf and test.swf for regression/avm1_child_timeline_loop.

WHAT THIS PINS DOWN
-------------------
**A loaded child SWF's timeline LOOPS, and the holder clip's `stop()` stops
it.** The sibling `avm1_child_timeline_advance` covers the forward sequence and
the child's own `stop()`; this one covers the two things that test cannot see:
the wrap back to frame 1, and a stop driven from the PARENT.

Ruffle: `MovieClip::replace_with_movie` (movie_clip.rs:371) makes the loaded
movie the holder clip's timeline and sets the PLAYING flag;
`determine_next_frame` (movie_clip.rs:1340) answers `NextFrame::First` — i.e.
wrap to the first frame — for any clip with more than one loaded frame and an
End tag, which every real SWF file has. So a loaded child plays and loops
unless something stops it.

THE SHAPE
---------
    parent test.swf  (AVM1, SWF8, MTASC)
                     loadMovie("child.swf") into _root.holder
    child.swf        (AVM1, SWF8, hand-built, 3 frames, NO stop())

    frame 1: PlaceObject2 char 1, depth 1, "a", at (10, 0) px   DoAction trace L1
    frame 2: PlaceObject2 Move depth 1 -> (20, 0) px            DoAction trace L2
    frame 3: PlaceObject2 Move depth 1 -> (30, 0) px            DoAction trace L3

The parent samples `holder._currentframe` and `holder.a._x` every tick, and on
tick 8 calls `holder.stop()`.

WHAT EACH ROW DISCRIMINATES
---------------------------
  * `cf` cycling 1,2,3,1,2,3 is the wrap itself. A one-shot playhead — which
    is what `_levelN` loads and MovieClipLoader targets still have — parks on
    3 and never returns to 1.
  * `ax` returning to 10 on the wrap tick proves the wrap RE-RAN frame 1's
    tags, rather than only resetting a counter. This is the row that
    distinguishes a real loop-back from a `_currentframe` that merely wraps.
  * The `L1/L2/L3` trace lines from the child's own DoAction are the same
    assertion from inside the child.
  * After `holder.stop()` the rows must freeze — `stop()` on the holder is
    `stop()` on the loaded movie's timeline, because the loaded movie IS that
    clip's timeline.

NEGATIVE CONTROL
----------------
Reverting the runtime change puts the child back at frame 1 forever: `L1`
alone, `cf:1` and `ax:10` on every tick.

See SWFRecompDocs/status/child-timeline-advance.md for the full write-up.
"""
import struct
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent

CHAR_A = 1


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


def matrix_translate(tx, ty):
    nbits = max(tx.bit_length(), ty.bit_length()) + 1   # +1 for the sign bit
    return Bits().u(0, 1).u(0, 1).u(nbits, 5).s(tx, nbits).s(ty, nbits).bytes()


def place_character(depth, char_id, name, tx, ty):
    """PlaceObject2 HasCharacter | HasMatrix | HasName."""
    flags = 0x02 | 0x04 | 0x20
    return tag(26, struct.pack('<BHH', flags, depth, char_id)
               + matrix_translate(tx, ty) + name.encode('ascii') + b'\x00')


def modify_matrix(depth, tx, ty):
    """PlaceObject2 Move | HasMatrix — no HasCharacter, so the char id is 0."""
    flags = 0x01 | 0x04
    return tag(26, struct.pack('<BH', flags, depth) + matrix_translate(tx, ty))


def show_frame():
    return tag(1, b'')


def end_tag():
    return struct.pack('<H', 0)


def define_sprite(char_id, declared_frames, body):
    return tag(39, struct.pack('<HH', char_id, declared_frames) + body)


ACTION_TRACE = b'\x26'


def push_string(s):
    payload = b'\x00' + s.encode('ascii') + b'\x00'
    return b'\x96' + struct.pack('<H', len(payload)) + payload


def do_action(body):
    return tag(12, body + b'\x00')


def trace_str(s):
    return push_string(s) + ACTION_TRACE


def build_child(path):
    tags = define_sprite(CHAR_A, 1, show_frame() + end_tag())
    # frame 1
    tags += place_character(1, CHAR_A, "a", 200, 0)      # (10, 0) px
    tags += do_action(trace_str("L1"))
    tags += show_frame()
    # frame 2
    tags += modify_matrix(1, 400, 0)                     # (20, 0) px
    tags += do_action(trace_str("L2"))
    tags += show_frame()
    # frame 3 — no stop(): the movie wraps back to frame 1
    tags += modify_matrix(1, 600, 0)                     # (30, 0) px
    tags += do_action(trace_str("L3"))
    tags += show_frame()
    tags += end_tag()

    # RECT nbits=15, 0..4000 twips square (200x200 px stage, never rendered).
    rect = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
    body = rect + struct.pack('<H', 30 << 8) + struct.pack('<H', 3) + tags
    file_length = 8 + len(body)
    path.write_bytes(b'FWS' + struct.pack('<BI', 8, file_length) + body)
    print(f'Created {path} (SWF8, 3 frames, {file_length} bytes)')


def build_parent(path):
    mtasc = Path.home() / 'CC' / 'mtasc' / 'bin' / 'mtasc'
    std = Path.home() / 'CC' / 'mtasc' / 'ocaml' / 'mtasc' / 'std'
    std8 = Path.home() / 'CC' / 'mtasc' / 'ocaml' / 'mtasc' / 'std8'
    cmd = [str(mtasc), '-cp', str(std), '-cp', str(std8), '-main',
           '-header', '200:200:30', 'Parent.as', '-swf', path.name,
           '-version', '8']
    print('$ ' + ' '.join(cmd))
    subprocess.run(cmd, cwd=str(HERE), check=True)
    print(f'Created {path} ({path.stat().st_size} bytes)')


if __name__ == '__main__':
    build_child(HERE / 'child.swf')
    try:
        build_parent(HERE / 'test.swf')
    except FileNotFoundError:
        print('MTASC not found; test.swf left as-is', file=sys.stderr)
