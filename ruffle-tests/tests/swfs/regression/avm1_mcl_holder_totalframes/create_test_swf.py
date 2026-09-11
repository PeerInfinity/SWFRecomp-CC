#!/usr/bin/env python3
r"""Build child.swf and test.swf for regression/avm1_mcl_holder_totalframes.

WHAT THIS PINS DOWN
-------------------
**A holder that `MovieClipLoader.loadClip` loaded a multi-frame SWF into
reports the loaded movie's `_totalframes` and `_framesloaded`, and reads
`_currentframe` 1 at `onLoadInit`.**

A loaded movie becomes the holder's timeline (Ruffle
`MovieClip::replace_with_movie`, movie_clip.rs:375: it sets `total_frames` to
the movie's frame count and parks `current_frame` at 0; the movie's first frame
then runs before `onLoadInit` is broadcast). The direct `loadMovie` drain
(`actionFirePendingDirectLoads`) always wrote the frame counts onto the holder.
The MovieClipLoader drain (`actionFirePendingLoadInits`) wrote them only for a
ROOT replacement or an image, so a `createEmptyMovieClip` holder kept its own
`_totalframes` / `_framesloaded` of 1 forever, and its `_currentframe` stayed 0
until the per-tick driver first advanced it -- AFTER `onLoadInit`.

THE SHAPE
---------
    parent test.swf  (AVM1, SWF8, MTASC -- Parent.as)
                     m = createEmptyMovieClip; MovieClipLoader.loadClip -> m
                     d = createEmptyMovieClip; d.loadMovie(same child)
    child.swf        (AVM1, SWF8, hand-built, 4 frames, silent, stop() on 4)

ROWS (expected output is the Ruffle exporter's trace, not ours)
---------------------------------------------------------------
    complete m cf:0 tf:4 fl:4 bt:35   onLoadComplete: counts are the movie's,
                                      its frame 1 has not run yet
    init m cf:1 tf:4 fl:4 bt:35       onLoadInit: frame 1 has run
    m [tf:4 fl:4 bt:35]               every distinct m row over 10 ticks
    d [tf:4 fl:4 bt:35]               NEGATIVE CONTROL: the direct-loadMovie
                                      holder, correct before and after
    end m cf:4 d cf:4                 both playheads ran to the child's stop()

The per-tick rows are a CHANGE LOG printed at the end, not one trace per tick:
our MCL load lands a tick later than Flash's and double-steps on its load tick
(BACKLOG §Multi-SWF, out of scope here), so a per-tick trace would grade that
timing instead of the frame counts. The child is silent for the same reason.

REVERT ATTRIBUTION (both modes)
-------------------------------
    revert the Pre-phase frame-count write  complete/init read tf:1 fl:1,
                                            m row reads [tf:1 fl:1 bt:35]
    revert the Phase 2 currentframe write   init reads cf:0
    the d row and the end row never flip.

Oracle: RUFFLE_LOCAL_FETCH_DIR=<dir> RUFFLE_MOVIE_URL=https://armorgames.com/test.swf \
        ~/CC/ruffle/target/release/exporter test.swf out -s -f 20 --trace-log output.txt
        with test.swf and child.swf copied to <dir>/armorgames.com/. Without the
        local-fetch navigator the exporter cannot load child.swf at all (both
        holders stay tf:1 fl:1 bt:0).

Closeout: SWFRecompDocs/status/avm1-mcl-holder-totalframes.md
"""
import struct
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent

CHILD_FRAMES = 4


def tag(code, data):
    if len(data) < 0x3F:
        return struct.pack('<H', (code << 6) | len(data)) + data
    return struct.pack('<HI', (code << 6) | 0x3F, len(data)) + data


def show_frame():
    return tag(1, b'')


def end_tag():
    return struct.pack('<H', 0)


ACTION_STOP = b'\x07'


def do_action(body):
    """DoAction (code 12). The terminating 0x00 is added here."""
    return tag(12, body + b'\x00')


def build_child(path):
    # Silent on purpose: two holders run this movie, and their frame scripts
    # would interleave differently depending on which tick each load lands on.
    # Frames 1..3 are empty; frame 4 stops the movie so the end state is fixed.
    tags = b''
    for _ in range(CHILD_FRAMES - 1):
        tags += show_frame()
    tags += do_action(ACTION_STOP)
    tags += show_frame()
    tags += end_tag()

    # RECT nbits=15, 0..4000 twips square (200x200 px stage, never rendered).
    rect = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
    body = rect + struct.pack('<H', 30 << 8) + struct.pack('<H', CHILD_FRAMES) + tags
    file_length = 8 + len(body)
    path.write_bytes(b'FWS' + struct.pack('<BI', 8, file_length) + body)
    print(f'Created {path} (SWF8, {CHILD_FRAMES} frames, {file_length} bytes)')


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
