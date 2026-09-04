// Source for regression/avm1_parent_child_text (test.swf).
// See create_test_swf.py for what this pins down: a loaded child movie's
// STATIC TEXT is indexed by movie-LOCAL offsets into text_data, glyph_data,
// transform_data and cxform_data, and every reader used the MAIN movie's.
//
// Build (SWF8 AVM1 parent, then the font/text tags are spliced into frame 1):
//   ~/CC/mtasc/bin/mtasc -cp ~/CC/mtasc/ocaml/mtasc/std \
//     -cp ~/CC/mtasc/ocaml/mtasc/std8 -main -header 200:200:30 \
//     Parent.as -swf test.swf -version 8
class Parent {
    static var frames: Number = 0;

    static function main(): Void {
        _root.createEmptyMovieClip("holder", 2);
        _root.holder.loadMovie("child.swf");
        _root.onEnterFrame = function(): Void {
            Parent.frames++;
            if (Parent.frames < 3) {
                return;
            }
            _root.onEnterFrame = null;
            Parent.report();
        };
    }

    // Two probe points, both tested against both movies. The parent's glyph
    // covers px (20,20)-(80,80) and the child's (120,20)-(180,80), so
    // "inside" and "outside" swap between them: a reader that took the wrong
    // movie's glyph outline OR the wrong movie's glyph position answers every
    // SHAPE row backwards while the bbox row and the control rows stay put.
    //
    // The probes go through the child's own sprite (`h.sub`), not through the
    // holder: our runtime still leaves a loaded movie's display children in
    // the shared root list rather than under the holder (the Route 1 sub-arc),
    // so the holder measures empty and would fail for a reason that has
    // nothing to do with geometry indices.
    static function report(): Void {
        var ctl: MovieClip = _root.ctl;
        var sub: MovieClip = _root.holder.sub;
        trace("ctl:glyph:50:"  + ctl.hitTest(50, 50, true));
        trace("ctl:glyph:150:" + ctl.hitTest(150, 50, true));
        trace("chd:glyph:50:"  + sub.hitTest(50, 50, true));
        trace("chd:glyph:150:" + sub.hitTest(150, 50, true));
        trace("chd:bbox:150:"  + sub.hitTest(150, 50, false));
        // text_data / text_char_codes on the same index as the glyph rows:
        // the parent's one glyph is code 'P', the child's is 'C'.
        trace("ctl:snap:" + ctl.getTextSnapshot().getText(0, 4, false));
        trace("chd:snap:" + sub.getTextSnapshot().getText(0, 4, false));
        trace("done");
    }
}
