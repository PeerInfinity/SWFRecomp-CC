// Source for regression/avm1_child_timeline_holder_stop (test.swf).
// See create_test_swf.py: holder.stop() / holder.play() from the PARENT drive
// the loaded movie's timeline, and the movie parks on its last frame.
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
            // The loaded movie is the holder's timeline and has three frames
            // still to run, so a stop here has to be visible as cf FREEZING at
            // 3 rather than climbing to 4, 5, 6.
            if (Parent.t == 3) {
                _root.holder.stop();
                trace("stop");
            }
            if (Parent.t == 6) {
                _root.holder.play();
                trace("play");
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
