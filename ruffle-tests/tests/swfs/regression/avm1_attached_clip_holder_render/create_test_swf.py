#!/usr/bin/env python3
"""avm1_attached_clip_holder_render: OFFSCREEN renders a clip attached under a
createEmptyMovieClip holder (s26 w2-attached-holder-render).

The SWF is byte-identical to ../avm1_attached_clip_button_click/test.swf (this
script just runs that generator): three attached copies of the red 100x100
`menu` square, `m` (root-attached, at 50,50), `h.m2` (attached under
`h = _root.createEmptyMovieClip("h", 2)`, h at 200,50) and `c.m3` (attached
under a timeline clip scaled 50% x, at 100,180).

Before s26 the OFFSCREEN attached passes (tagShowFrame / tagRerenderFrame)
drew only root-attached clips and relied on ng_attachMovie's
attach_registration alias for nested ones; a holder with no
sprite_display_list gets no alias, so `h.m2` rendered white.

Golden output.expected.png: Ruffle exporter at 0ddd12b6a, frame 0 (archived
as SWFRecomp-CC-history:SWFRecompDocs/plans/session26-fanout-reports/w1-local-oracles/
attached_clip_button_click.exporter-0ddd12b6a.f0.png). Pixel-aligned solid
squares, no AA, so tolerance 1 / max_outliers 0.

Usage: create_test_swf.py <out.swf>
"""
import os
import runpy
import sys

here = os.path.dirname(os.path.abspath(__file__))
sys.argv = [sys.argv[0], sys.argv[1]]
runpy.run_path(os.path.join(here, '..', 'avm1_attached_clip_button_click', 'create_test_swf.py'), run_name='__main__')
