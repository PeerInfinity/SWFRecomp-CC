#!/usr/bin/env python3
"""Compatibility shim: `KEEP_BUILD_DIR=<dir> verify_output_keep.py ...`.

This file used to be a full fork of verify_output.py whose only real
difference was keeping the native build directory (for game bring-up:
build once, then run `<dir>/test_run <events>` by hand). CI never ran it,
so its hand-maintained runtime source list drifted out of date twice
(avm2_net.c, then amf_packet.c + avm1_amf.c) and the build stopped
linking, and it still did harness-side char-id offsetting after the
recompiler took that over. verify_output.py has supported the same thing
natively since 2026-07-21 via SWF_KEEP_BUILD_DIR, so this shim just
forwards to it. Prefer calling verify_output.py with SWF_KEEP_BUILD_DIR
directly; this file exists so the documented KEEP_BUILD_DIR commands keep
working.
"""

import os
import sys
from pathlib import Path

keep = os.environ.get("KEEP_BUILD_DIR")
if keep and not os.environ.get("SWF_KEEP_BUILD_DIR"):
    os.environ["SWF_KEEP_BUILD_DIR"] = keep

target = Path(__file__).resolve().parent / "verify_output.py"
os.execv(sys.executable, [sys.executable, str(target), *sys.argv[1:]])
