#!/usr/bin/env python3
"""avm1_empty_clip_drawing_depth_order: an empty clip's Drawing-API content
layers at its own AS depth among attached siblings (s27 w1-render-bitmap-leads
lead 1, case B + control C of ../avm1_holder_drawing_under_children's script):
d = createEmptyMovieClip("d", 5) draws green; _root.attachMovie("sq","t",6)
must paint red OVER it. Fixed by s27 w2-holder-drawing-full (drawing-only
clips paint at their sorted attached position; the late sprite-text pass no
longer depends on the global Drawing-API pass running after it).
Golden: real Flash Player 32 (coordinator oracle, s27
w1-local-oracles/w1-render-bitmap-leads/.../flash.png).
Usage: create_test_swf.py <out.swf>
"""
import os, runpy, sys
here = os.path.dirname(os.path.abspath(__file__))
sys.argv = [sys.argv[0], sys.argv[1], 'BC']
runpy.run_path(os.path.join(here, '..', 'avm1_holder_drawing_under_children', 'create_test_swf.py'), run_name='__main__')
