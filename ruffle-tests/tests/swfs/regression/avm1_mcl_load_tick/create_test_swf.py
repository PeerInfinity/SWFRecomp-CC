#!/usr/bin/env python3
"""Regenerate test.swf + child.swf for avm1_mcl_load_tick.

Pins down the TICK POSITION of a MovieClipLoader load, which is two coupled
facts (both fixed together — reverting either flips a different pair of lines):

  1. `onLoadInit` fires on the tick AFTER the load's own drain, in the slot
     between that tick's enterFrame broadcast and the loaded movie's advance.
     Before: `c1, onLoadInit, c2, t1 h.cf=2` — the handler ran inside
     tagShowFrame, ahead of the root's first onEnterFrame.
  2. A MovieClipLoader target starts UNARMED. The loader already runs the
     movie's frame 1 itself (Phase 2), so arming at birth made the same tick's
     actionAdvancePlayingLevels run frame 2 as well — a double step that was
     compensating for (1)'s position, not for the delivery tick.

Reverting only (2) gives `c1, c2, t1 h.cf=2, onLoadInit cf=2`; reverting only
(1) gives `c1, onLoadInit, t1 h.cf=1`. Both are one-line-pair discriminators.

What is DELIBERATELY not changed: the two-bucket delivery deferral in
`builtin_mcl_loadClip` (`defer_to_next_tick` + actionPromotePendingMCLLoads).
Our onLoadStart/Progress/Complete land one tick later than Ruffle's, and that
is FLASH's order — `from_shumway/avm1/moviecliploader` grades it (its Flash
`output.txt` puts `loader frame 2` before `onLoadStart`, its
`output.ruffle.txt` does not), and we pass it. So this fixture uses a ONE-FRAME
loader, whose Ruffle order is reachable without touching delivery at all.
See SWFRecompDocs/plans/session19-fanout-reports/w1-loaders-report.md §4.

The loader is MTASC-compiled; the 3-frame child is hand-assembled (each frame
is one DoAction: Push "cN", Trace; then ShowFrame), because a compiler-built
child would drag in class-init frames and blur the frame boundaries the test
is measuring.

output.txt is the Ruffle exporter's trace, byte for byte; see README.md.
"""
import pathlib
import struct
import subprocess

HERE = pathlib.Path(__file__).resolve().parent
MTASC = pathlib.Path.home() / "CC/mtasc/bin/mtasc"
MTASC_STD = pathlib.Path.home() / "CC/mtasc/ocaml/mtasc/std"

T_END, T_SHOWFRAME, T_DOACTION = 0, 1, 12
ACTION_PUSH, ACTION_TRACE, ACTION_STOP = 0x96, 0x26, 0x07


def tag(code, body):
    if len(body) < 0x3F:
        return struct.pack("<H", (code << 6) | len(body)) + body
    return struct.pack("<HI", (code << 6) | 0x3F, len(body)) + body


def rect(xmax_tw, ymax_tw, nbits=13):
    bits = format(nbits, "05b") + "".join(
        format(v & ((1 << nbits) - 1), f"0{nbits}b")
        for v in (0, xmax_tw, 0, ymax_tw)
    )
    bits += "0" * ((-len(bits)) % 8)
    return bytes(int(bits[i:i + 8], 2) for i in range(0, len(bits), 8))


def do_trace(text, stop=False):
    payload = b"\x00" + text.encode("ascii") + b"\x00"     # push type 0 = string
    body = bytes([ACTION_PUSH]) + struct.pack("<H", len(payload)) + payload
    body += bytes([ACTION_TRACE])
    if stop:
        body += bytes([ACTION_STOP])
    body += b"\x00"                                         # end of actions
    return tag(T_DOACTION, body)


def build_child(path):
    """3 frames tracing c1 / c2 / c3; frame 3 also stops, so the playhead
    parks there instead of wrapping (the oracle's `t4..t6 h.cf=3` rows).
    200x150 @ 30fps, SWF 8."""
    body = rect(200 * 20, 150 * 20) + struct.pack("<HH", 30 * 256, 3)
    for i in (1, 2, 3):
        body += do_trace(f"c{i}", stop=(i == 3)) + tag(T_SHOWFRAME, b"")
    body += tag(T_END, b"")
    path.write_bytes(b"FWS" + bytes([8]) + struct.pack("<I", 8 + len(body)) + body)


def build_parent(path):
    subprocess.run(
        [str(MTASC), "-cp", str(MTASC_STD), "-main", "-header", "200:150:30",
         str(HERE / "Parent.as"), "-swf", str(path), "-version", "8"],
        check=True, cwd=str(HERE))


build_child(HERE / "child.swf")
build_parent(HERE / "test.swf")
