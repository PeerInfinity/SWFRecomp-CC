#!/usr/bin/env python3
r"""Build child.swf, child2.swf and test.swf for regression/avm1_child_timeline_loop.

WHAT THIS PINS DOWN
-------------------
**A loaded child SWF's timeline WRAPS back to its frame 1, and the wrap takes
that movie's OWN display children off the list — nobody else's.**

Ruffle `MovieClip::determine_next_frame` (movie_clip.rs:1340) answers
`NextFrame::First` for any clip with more than one loaded frame and an End tag,
which every SWF file has, so a loaded movie plays and loops unless it is
stopped. Before this test's fix the movie parked on its last frame forever: a
wrap has to clear the movie's own display children first (frame 1 re-places at
the same depths, and the runtime REFUSES a place onto an occupied depth and
prints `Warning: Failed to place object at depth N.`), and a clip target's
children are interleaved with the parent's in the global display_list with
nothing to tell them apart. `DisplayObject.placed_by_holder` is what tells them
apart, and this test is what says it tells them apart CORRECTLY.

THE SHAPE
---------
    parent test.swf   (AVM1, SWF8, MTASC)
                      loadMovie("child.swf")  into _root.h1
                      loadMovie("child2.swf") into _root.h2

    child.swf   3 frames, depths 1..3          child2.swf  2 frames, depths 11..12
      f1: place "a" @ (10,0)   trace c1          f1: place "p"   trace d1
      f2: move "a" -> (20,0)                     f2: place "q"   trace d2
          place "b"            trace c2
      f3: place "c"            trace c3

Two loaded movies, DIFFERENT cycle lengths (3 and 2), disjoint depth ranges.
They fall out of phase on the very first wrap, so from t3 on, every tick is one
movie wrapping while the other is mid-pass.

WHAT EACH ROW DISCRIMINATES
---------------------------
    t<N> f1:<h1._currentframe> a:.. b:.. c:.. ax:<h1.a._x>
       | f2:<h2._currentframe> p:.. q:..
       | rf:<_root._currentframe>

  * `f1` running 1,2,3,1,2,3,... instead of pinning at 3 is the wrap itself.
    An implementation that re-ran the last frame forever, or that jumped to
    frame 2, shows a different sequence with the same set of values.
  * `a`/`b`/`c` are the CLEAR. On the wrap tick they must all be back to
    `movieclip`-then-`undefined` in frame-1 shape (a only): `c` surviving a wrap
    means the clear missed it, and frame 1's own re-place of `a` succeeding
    means the clear ran BEFORE the frame call rather than after it.
  * `ax` returning to 10 on each wrap proves frame 1's PlaceObject2 really
    re-ran (a cleared-but-not-replaced depth leaves `ax` undefined).
  * `p`/`q` are the NEGATIVE CONTROL for over-clearing. h2's children are on
    the same global display_list as h1's. At t3 h2 wraps while h1 holds a, b
    and c; at t4 h1 wraps while h2 holds p. A clear that keyed on "placed by
    some loaded movie" rather than on THIS holder empties both, and the
    interleaving catches it on the first wrap.
  * `rf` and the monotonic `t` are the parent-rewind guard. A child's LAST
    frame carries the recompiler's root loop-back into `next_frame` /
    `manual_next_frame`, which are the MAIN movie's globals; looping means
    running last frames deliberately and often. If the driver's save/restore
    did not cover the wrap path, main() would re-enter and `t` would restart.

WHY THE HOLDER AND NOT THE MOVIE ID
-----------------------------------
`placed_by_holder` records the holder MovieClip, not `g_current_movie_id`.
The two disagree for one shape: the SAME child file loaded into two different
holders, which is one MovieEntry and one movie id but two independent
playheads, so a movie-id-keyed clear would empty both. That shape cannot be
built today — both loads place at the same depths in the same global
display_list and the second one is refused — so this file cannot assert it.
It becomes buildable the moment per-movie display lists land, and the holder is
the identity that survives that change at no extra cost now.

NEGATIVE CONTROL
----------------
Reverting the wrap puts both movies back on their last frame forever:
`f1` pinned at 3 with a, b and c all `movieclip`, `f2` pinned at 2.

See SWFRecompDocs/status/per-movie-display-list-ownership.md for the write-up.
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


def build_child1(path):
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
    # frame 3 — the LAST frame, so it also carries the root loop-back emission
    tags += place_character(3, CHAR_A, "c", 0, 0)
    tags += do_action(trace_str("c3"))
    tags += show_frame()
    tags += end_tag()

    rect = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
    body = rect + struct.pack('<H', 30 << 8) + struct.pack('<H', 3) + tags
    file_length = 8 + len(body)
    path.write_bytes(b'FWS' + struct.pack('<BI', 8, file_length) + body)
    print(f'Created {path} (SWF8, 3 frames, {file_length} bytes)')


def build_child2(path):
    """Two frames, depths 11..12 — disjoint from child.swf's 1..3 so the two
    loaded movies share the global display_list without colliding."""
    tags = define_sprite(CHAR_A, 1, show_frame() + end_tag())

    # frame 1
    tags += place_character(11, CHAR_A, "p", 0, 0)
    tags += do_action(trace_str("d1"))
    tags += show_frame()
    # frame 2 — the LAST frame
    tags += place_character(12, CHAR_A, "q", 0, 0)
    tags += do_action(trace_str("d2"))
    tags += show_frame()
    tags += end_tag()

    rect = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
    body = rect + struct.pack('<H', 30 << 8) + struct.pack('<H', 2) + tags
    file_length = 8 + len(body)
    path.write_bytes(b'FWS' + struct.pack('<BI', 8, file_length) + body)
    print(f'Created {path} (SWF8, 2 frames, {file_length} bytes)')


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
    build_child1(HERE / 'child.swf')
    build_child2(HERE / 'child2.swf')
    try:
        build_parent(HERE / 'test.swf')
    except FileNotFoundError:
        print('MTASC not found; test.swf left as-is', file=sys.stderr)
