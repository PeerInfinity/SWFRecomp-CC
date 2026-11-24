#!/usr/bin/env python3
"""avm1_bare_depth_methods_v7_gate_swf7: the SWF7 twin of
avm1_bare_depth_methods_v7_gate (same rows, SWF version 7: the methods exist).
Usage: create_test_swf.py <out.swf>
"""
import os
import subprocess
import sys

here = os.path.dirname(os.path.abspath(__file__))
gen = os.path.join(here, '..', 'avm1_bare_depth_methods_v7_gate', 'create_test_swf.py')
subprocess.check_call([sys.executable, gen, sys.argv[1], '7'])
