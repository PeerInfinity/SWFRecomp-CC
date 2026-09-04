// Source for regression/avm1_parent_child_render (test.swf).
// See create_test_swf.py for what this pins down: a loaded child movie's
// shape geometry is indexed by movie-LOCAL offsets, and every reader used the
// MAIN movie's arrays.
//
// Build (SWF8 AVM1 parent, then the shape tags are spliced into frame 1):
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

    // Two probe points, both tested against both movies. The parent's square
    // covers (20,20)-(80,80) and the child's (120,20)-(180,80), so "inside"
    // and "outside" swap between them: a reader that took the wrong movie's
    // outline answers every SHAPE row backwards while the bbox row and the
    // control rows stay put.
    //
    // The probes go through the child's own sprite (`h.sub`), not through the
    // holder. `_root.holder.hitTest` reads the HOLDER's bounds, and our
    // runtime still leaves a loaded movie's display children in the shared
    // root list rather than under the holder (the Route 1 sub-arc), so the
    // holder measures empty here and would fail this test for a reason that
    // has nothing to do with geometry indices.
    static function report(): Void {
        var ctl: MovieClip = _root.ctl;
        var sub: MovieClip = _root.holder.sub;
        trace("ctl:shape:50:"  + ctl.hitTest(50, 50, true));
        trace("ctl:shape:150:" + ctl.hitTest(150, 50, true));
        trace("chd:shape:50:"  + sub.hitTest(50, 50, true));
        trace("chd:shape:150:" + sub.hitTest(150, 50, true));
        trace("chd:bbox:150:"  + sub.hitTest(150, 50, false));
        trace("chd:sub:"       + typeof(sub));
        trace("done");
    }
}
