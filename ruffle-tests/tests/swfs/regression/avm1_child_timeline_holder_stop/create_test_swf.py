#!/usr/bin/env python3
r"""Build child.swf and test.swf for regression/avm1_child_timeline_holder_stop.

WHAT THIS PINS DOWN
-------------------
**`holder.stop()` and `holder.play()` from the PARENT drive the loaded movie's
timeline, and the movie parks on its last frame.**

A movie loaded into a clip becomes that clip's timeline (Ruffle
`MovieClip::replace_with_movie`, movie_clip.rs:371), so `holder.stop()` is a
stop on the loaded movie. Before the child-timeline slice it fell all the way
through to `actionStop` and stopped the **ROOT** -- a dynamic holder is missed
by `ng_findDisplayEntryByName` and has no `display_obj`, so both of that arm's
clip-specific branches missed it. The sibling `avm1_child_timeline_advance`
covers the movie stopping ITSELF; this one covers the parent doing it, which is
a different code path (`actionCallMethod`'s `stop`/`play` arms, not
`actionStop`).

THE SHAPE
---------
    parent test.swf  (AVM1, SWF8, MTASC)
                     loadMovie("child.swf") into _root.holder
    child.swf        (AVM1, SWF8, hand-built, 6 frames, NO stop() of its own)

    frame N: PlaceObject2 Move depth 1 -> (10*N, 0) px   DoAction trace LN

The parent lets it run to frame 3, calls `holder.stop()`, holds for three
ticks, then calls `holder.play()`.

WHAT EACH ROW DISCRIMINATES
---------------------------
  * `cf` frozen at 3 for ticks 4-6 is the parent-driven stop. The movie has no
    stop() of its own and three frames left, so without the fix those ticks
    read 4, 5, 6.
  * `ax` frozen with it proves the frames' TAGS stopped too, not just a
    counter.
  * `cf` resuming 4, 5, 6 after `play` is the parent-driven play.
  * `cf:6` held to the end is the PARK. A loaded movie should WRAP here
    (Ruffle `determine_next_frame` -> `NextFrame::First` for any clip with more
    than one loaded frame and an End tag, which every SWF file has). It does
    not, because a wrap has to clear the movie's own display children and a
    clip target's children are interleaved with the parent's in the global
    display_list -- see SWFRecompDocs/status/child-timeline-advance.md §2.2.
    **Those rows are a lock on known-incomplete behaviour**: when the wrap
    lands they must flip to `cf:1 ax:10`, deliberately.

NEGATIVE CONTROL
----------------
Reverting the child-timeline change puts the movie back at frame 1 forever:
`L1` alone, `cf:1` and `ax:10` on every tick.

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


FRAMES = 6


def build_child(path):
    tags = define_sprite(CHAR_A, 1, show_frame() + end_tag())
    # frame 1 places, frames 2..N each Modify. The movie never stops itself:
    # everything this test measures is driven from the parent.
    tags += place_character(1, CHAR_A, "a", 200, 0)      # (10, 0) px
    tags += do_action(trace_str("L1"))
    tags += show_frame()
    for n in range(2, FRAMES + 1):
        tags += modify_matrix(1, 200 * n, 0)             # (10*n, 0) px
        tags += do_action(trace_str("L%d" % n))
        tags += show_frame()
    tags += end_tag()

    # RECT nbits=15, 0..4000 twips square (200x200 px stage, never rendered).
    rect = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
    body = rect + struct.pack('<H', 30 << 8) + struct.pack('<H', FRAMES) + tags
    file_length = 8 + len(body)
    path.write_bytes(b'FWS' + struct.pack('<BI', 8, file_length) + body)
    print(f'Created {path} (SWF8, {FRAMES} frames, {file_length} bytes)')


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
