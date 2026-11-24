#!/usr/bin/env python3
"""avm1_empty_clip_drawing_depth_order: an empty clip's Drawing-API content
layers at its own AS depth among attached siblings (s27 w1-render-bitmap-leads
lead 1, case B + control C of ../avm1_holder_drawing_under_children's script):
d = createEmptyMovieClip("d", 5) draws green; _root.attachMovie("sq","t",6)
must paint red OVER it. Ours paints every childless empty clip's drawing in the
late global actionIterateDrawings pass, so green covers red. Fixing it needs
the late sprite-text pass interleaved too (see the s27 report).
Usage: create_test_swf.py <out.swf>
"""
import os, runpy, sys
here = os.path.dirname(os.path.abspath(__file__))
sys.argv = [sys.argv[0], sys.argv[1], 'BC']
runpy.run_path(os.path.join(here, '..', 'avm1_holder_drawing_under_children', 'create_test_swf.py'), run_name='__main__')
