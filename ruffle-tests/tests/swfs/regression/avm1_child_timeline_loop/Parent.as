// Source for regression/avm1_child_timeline_loop (test.swf).
// See create_test_swf.py for what this pins down: a loaded child SWF's
// timeline wrapping back to frame 1, and the HOLDER's stop() stopping it.
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
            // Stop from the PARENT once the child has been round the loop.
            // The loaded movie is the holder's timeline, so this is a stop()
            // on that timeline — the rows after it must be frozen.
            if (Parent.t == 8) {
                _root.holder.stop();
                trace("stop");
            }
            if (Parent.t >= 11) {
                _root.onEnterFrame = null;
                trace("done");
            }
        };
    }

    static function sample(): Void {
        var h: MovieClip = _root.holder;
        trace("t" + Parent.t + " cf:" + h._currentframe + " ax:" + h.a._x);
    }
}
