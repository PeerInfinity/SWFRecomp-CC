// Source for regression/avm1_parent_child_morph (test.swf).
// See create_test_swf.py for what this pins down: a loaded child movie's
// MORPH SHAPE carries movie-LOCAL offsets into morph_end_shape_data,
// color_data, morph_end_color_data and path_data, and every one of them was
// read against the MAIN movie's array.
//
// Build (SWF8 AVM1 parent, then the morph tags are spliced into frame 1):
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

    // Both morphs are placed at ratio 65535, so each renders its END
    // rectangle: the parent's at px (20,20)-(80,80) and the child's at
    // (120,20)-(180,80). Their START rectangles are at y 120..180, so the
    // ":start" rows also prove the ratio is being applied to the right
    // movie's interleaved path run rather than to the root's.
    //
    // The probes go through the child's own sprite (`h.sub`), not through the
    // holder: our runtime still leaves a loaded movie's display children in
    // the shared root list rather than under the holder (the Route 1
    // sub-arc), so the holder measures empty.
    static function report(): Void {
        var ctl: MovieClip = _root.ctl;
        var sub: MovieClip = _root.holder.sub;
        trace("ctl:end:50:"    + ctl.hitTest(50, 50, true));
        trace("ctl:start:50:"  + ctl.hitTest(50, 150, true));
        trace("ctl:end:150:"   + ctl.hitTest(150, 50, true));
        trace("chd:end:50:"    + sub.hitTest(50, 50, true));
        trace("chd:end:150:"   + sub.hitTest(150, 50, true));
        trace("chd:start:150:" + sub.hitTest(150, 150, true));
        trace("chd:bbox:150:"  + sub.hitTest(150, 50, false));
        trace("done");
    }
}
