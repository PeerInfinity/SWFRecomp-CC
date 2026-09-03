#!/usr/bin/env python3
r"""Build child.swf and test.swf for regression/avm1_child_timeline_frame1_stop.

WHAT THIS PINS DOWN
-------------------
**A loaded child SWF that calls `stop()` in its OWN first frame stays there.**

This is the preloader shape and the commonest real use of a stopped loaded
movie, and it is an ORDERING trap in the fix that made loaded children advance
at all. The loader has to mark the holder PLAYING (Ruffle
`MovieClip::replace_with_movie` sets MovieClipFlags::PLAYING unconditionally,
movie_clip.rs:371) -- but the natural place to do that, next to the playhead
registration, runs AFTER the movie's frame 1 has already executed. Marking
there overwrites the stop the movie just performed and the movie plays on.
Found by inspection while writing the advance fixture, and fixed by hoisting
the mark to before `frame_funcs[0]` in both loader paths
(`actionFirePendingDirectLoads` and `actionFirePendingLoadInits` Phase 2).

THE SHAPE
---------
    parent test.swf  (AVM1, SWF8, MTASC)
                     loadMovie("child.swf") into _root.holder
    child.swf        (AVM1, SWF8, hand-built, 3 frames)

    frame 1: PlaceObject2 char 1, depth 1, "a"   DoAction trace S1 + stop()
    frame 2: PlaceObject2 char 1, depth 2, "b"   DoAction trace S2
    frame 3:                                     DoAction trace S3

WHAT EACH ROW DISCRIMINATES
---------------------------
  * `S1` alone: frames 2 and 3 never ran.
  * `cf:1` on every tick: the playhead never left frame 1.
  * `b:undefined` throughout: frame 2's PlaceObject2 never ran either, so this
    is not just a `_currentframe` that failed to move.

The sibling `avm1_child_timeline_advance` covers the opposite polarity -- a
child that stops on a LATER frame, where a mark placed after frame 1 would
still look correct.

NEGATIVE CONTROLS
-----------------
  * Mark hoisted back to registration time (i.e. the ordering bug): `S2` and
    `S3` appear and `cf` climbs to 3.
  * The whole child-timeline change reverted (the pre-slice baseline): the
    output is the same as the correct one here, because a frozen child looks
    identical to a correctly stopped one. That is deliberate -- this fixture's
    job is to stop the FIX from over-running, so `avm1_child_timeline_advance`
    is the test that discriminates against the baseline and this one is the
    test that discriminates against the over-correction.

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


def show_frame():
    return tag(1, b'')


def end_tag():
    return struct.pack('<H', 0)


def define_sprite(char_id, declared_frames, body):
    return tag(39, struct.pack('<HH', char_id, declared_frames) + body)


ACTION_STOP = b'\x07'
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
    # frame 1 -- the movie stops itself here, in its very first frame
    tags += place_character(1, CHAR_A, "a", 200, 0)      # (10, 0) px
    tags += do_action(trace_str("S1") + ACTION_STOP)
    tags += show_frame()
    # frame 2 -- must never run
    tags += place_character(2, CHAR_A, "b", 0, 0)
    tags += do_action(trace_str("S2"))
    tags += show_frame()
    # frame 3 -- must never run
    tags += do_action(trace_str("S3"))
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
