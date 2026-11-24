#!/usr/bin/env python3
"""avm1_swf7_case_sensitive_builtins: the SWF7 twin of
avm1_swf6_case_insensitive_builtins (same rows, SWF version 7): every case
variant must MISS (Ruffle is_case_sensitive() for swf_version > 6), except the
display properties (`_X`, `_NAME`: Ruffle stage_object get_by_name is case
insensitive in every version). Generator: ../avm1_swf6_case_insensitive_builtins.

Golden: Flash Player 32 trace (== the Ruffle-source prediction).

Usage: create_test_swf.py <out.swf>
"""
import os
import subprocess
import sys

here = os.path.dirname(os.path.abspath(__file__))
gen = os.path.join(here, '..', 'avm1_swf6_case_insensitive_builtins', 'create_test_swf.py')
subprocess.check_call([sys.executable, gen, sys.argv[1], '7'])
