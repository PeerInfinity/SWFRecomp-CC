// Source for regression/avm1_child_timeline_advance (test.swf).
// See create_test_swf.py for what this pins down: a loaded child SWF's
// timeline advancing frame by frame, stopping where the child's own stop()
// puts it, and resuming from a holder.play().
//
// Build (SWF8 AVM1 parent):
//   ~/CC/mtasc/bin/mtasc -cp ~/CC/mtasc/ocaml/mtasc/std \
//     -cp ~/CC/mtasc/ocaml/mtasc/std8 -main -header 200:200:30 \
//     Parent.as -swf test.swf -version 8
class Parent {
    static var t: Number = 0;

    static function main(): Void {
        _root.createEmptyMovieClip("holder", 1);
        _root.holder.loadMovie("child.swf");
        _root.onEnterFrame = function(): Void {
            Parent.t++;
            Parent.sample();
            // The child stopped ITSELF on frame 4. play() on the holder is
            // play() on the loaded movie's timeline, so frame 5 (and then the
            // wrap back to frame 1) only happen from here on.
            if (Parent.t == 7) {
                _root.holder.play();
                trace("play");
            }
            if (Parent.t >= 12) {
                _root.onEnterFrame = null;
                trace("done");
            }
        };
    }

    // One row per tick. Every row is part of a SEQUENCE assertion: a playhead
    // that jumped straight to the last frame, or one that ran every frame in
    // a single tick, would show a different sequence with the same last row.
    static function sample(): Void {
        var h: MovieClip = _root.holder;
        trace("t" + Parent.t
              + " cf:" + h._currentframe
              + " tf:" + h._totalframes
              + " ax:" + h.a._x
              + " b:" + typeof(h.b)
              + " z:" + typeof(h.z));
    }
}
