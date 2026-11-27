#!/usr/bin/env python3
"""avm1_exec_order_sibling_interleave: AVM1 per-clip exec order, the `sibling`
shape of ../avm1_exec_order_attached_selfremove/create_test_swf.py (timeline
sprite `tl`, attachMovie'd `a` at root f1, attachMovie'd `b` at root f2; every
clip has an onEnterFrame and frame scripts; `a`/`b` self-remove on frame 3).

Pins: each clip's onEnterFrame runs immediately before ITS OWN queued frame
script, clips newest-first, _root last (n-exec-order-report.md section 2b
reqs 1-2; Ruffle avm1/runtime.rs run_frame + movie_clip.rs run_frame_avm1).
Red before s30 w1-exec-order (ours ran every child enterFrame before any child
frame script), green after. Kill switch: SWF_EXEC_ORDER_EF=0 restores red.

Expected output: Ruffle exporter (local build) --frames 8 trace, from the
s26 parked fixture (SWFRecompDocs/plans/n-exec-order-sibling-fixture/).
A Flash Player 32 capture is requested in the s30 w1-exec-order report.

Usage: create_test_swf.py <out.swf>   (byte-identical to the shipped test.swf)
"""
import os, subprocess, sys

here = os.path.dirname(os.path.abspath(__file__))
gen = os.path.join(here, "..", "avm1_exec_order_attached_selfremove", "create_test_swf.py")
out = sys.argv[1] if len(sys.argv) > 1 else os.path.join(here, "test.swf")
sys.exit(subprocess.call([sys.executable, gen, out, "sibling"]))
