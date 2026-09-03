#!/usr/bin/env python3
r"""Build child.swf and test.swf for regression/avm1_child_timeline_advance.

WHAT THIS PINS DOWN
-------------------
**A loaded child SWF's timeline advances, and stops where the child stops it.**

`loadMovie` into a holder clip makes the loaded movie BECOME that clip's
timeline (Ruffle `MovieClip::replace_with_movie`, movie_clip.rs:371 — it swaps
the clip's shared data for the loaded movie, sets `total_frames` to the movie's
frame count, sets the PLAYING flag and parks `current_frame` at 0). Before this
test's fix, `actionFirePendingDirectLoads` ran the child's `child_frame_0` and
nothing ever called `child_frame_1`, so every tag and every DoAction past a
loaded child's FIRST frame was dead code.

THE SHAPE
---------
    parent test.swf  (AVM1, SWF8, MTASC)
                     loadMovie("child.swf") into _root.holder
    child.swf        (AVM1, SWF8, hand-built, 5 frames)

    frame 1: PlaceObject2 char 1, depth 1, "a", at (10, 0) px   DoAction trace
    frame 2: PlaceObject2 Move depth 1 -> (20, 0) px            DoAction trace
             PlaceObject2 char 2, depth 2, "b"
    frame 3: PlaceObject2 Move depth 1 -> (30, 0) px            DoAction trace
             RemoveObject2 depth 2
    frame 4: DoAction trace + stop()
    frame 5: PlaceObject2 char 1, depth 3, "z"                  DoAction trace

Frame 5 is the stop() control: it must NEVER run. A playhead that jumps
straight to the last frame passes an end-state assertion and is still wrong,
so every row here is a per-tick SEQUENCE row, not an end state.

WHAT EACH ROW DISCRIMINATES
---------------------------
The child traces `c1`..`c5` from its own DoAction, so the frame trace lines are
a direct readout of which frame functions ran, in order. The parent then traces
one row per tick:

    t<N> cf:<holder._currentframe> tf:<holder._totalframes>
         ax:<holder.a._x> b:<typeof holder.b> z:<typeof holder.z>

  * `cf` rising 1,2,3,4 and then pinning at 4 is the playhead itself.
  * `tf:5` is the child's frame count on the HOLDER — the loaded movie became
    the holder's timeline (it is 0 for an empty clip that never loaded).
  * `ax` 10 -> 20 -> 30 proves the later frames' Modify tags ran, against the
    holder's own display list.
  * `b` appearing at frame 2 and going undefined at frame 3 proves a later
    frame's RemoveObject2 ran (an end-state-only test cannot see this at all).
  * `z` staying undefined proves frame 5 never ran — i.e. the child's own
    `stop()` stopped the child's playhead and not something else.

NEGATIVE CONTROL
----------------
Reverting the runtime change puts the child back at frame 1 forever:
`c1` alone, `cf:1` on every tick, `ax:10`, `b:undefined` throughout.

See SWFRecompDocs/status/child-timeline-advance.md for the full write-up.
"""
import struct
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent

CHAR_A = 1
CHAR_B = 2


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


def remove_object2(depth):
    """RemoveObject2 (code 28): depth only."""
    return tag(28, struct.pack('<H', depth))


def show_frame():
    return tag(1, b'')


def end_tag():
    return struct.pack('<H', 0)


def define_sprite(char_id, declared_frames, body):
    return tag(39, struct.pack('<HH', char_id, declared_frames) + body)


# --- AVM1 action records ------------------------------------------------
ACTION_STOP = b'\x07'
ACTION_TRACE = b'\x26'


def push_string(s):
    """ActionPush (0x96) carrying one type-0 (string) value."""
    payload = b'\x00' + s.encode('ascii') + b'\x00'
    return b'\x96' + struct.pack('<H', len(payload)) + payload


def do_action(body):
    """DoAction (code 12). The terminating 0x00 is added here."""
    return tag(12, body + b'\x00')


def trace_str(s):
    return push_string(s) + ACTION_TRACE


def build_child(path):
    # Two one-frame sprites to place. They carry no content: everything this
    # test reads is display-list identity and _x, never pixels (a loaded
    # child's shapes are not on the GPU — see BACKLOG §Multi-SWF).
    tags = define_sprite(CHAR_A, 1, show_frame() + end_tag())
    tags += define_sprite(CHAR_B, 1, show_frame() + end_tag())

    # frame 1
    tags += place_character(1, CHAR_A, "a", 200, 0)      # (10, 0) px
    tags += do_action(trace_str("c1"))
    tags += show_frame()
    # frame 2
    tags += modify_matrix(1, 400, 0)                     # (20, 0) px
    tags += place_character(2, CHAR_B, "b", 0, 0)
    tags += do_action(trace_str("c2"))
    tags += show_frame()
    # frame 3
    tags += modify_matrix(1, 600, 0)                     # (30, 0) px
    tags += remove_object2(2)
    tags += do_action(trace_str("c3"))
    tags += show_frame()
    # frame 4 — the child stops itself here
    tags += do_action(trace_str("c4") + ACTION_STOP)
    tags += show_frame()
    # frame 5 — must never run
    tags += place_character(3, CHAR_A, "z", 0, 0)
    tags += do_action(trace_str("c5"))
    tags += show_frame()
    tags += end_tag()

    # RECT nbits=15, 0..4000 twips square (200x200 px stage, never rendered).
    rect = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
    body = rect + struct.pack('<H', 30 << 8) + struct.pack('<H', 5) + tags
    file_length = 8 + len(body)
    path.write_bytes(b'FWS' + struct.pack('<BI', 8, file_length) + body)
    print(f'Created {path} (SWF8, 5 frames, {file_length} bytes)')


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
