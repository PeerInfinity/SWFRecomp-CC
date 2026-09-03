// Source for regression/avm1_child_timeline_frame1_stop (test.swf).
// See create_test_swf.py: a loaded child SWF whose OWN first frame calls
// stop() must stay on frame 1 -- the preloader shape, and the ordering trap
// in the fix that made loaded children advance at all.
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
            if (Parent.t >= 5) {
                _root.onEnterFrame = null;
                trace("done");
            }
        };
    }

    static function sample(): Void {
        var h: MovieClip = _root.holder;
        trace("t" + Parent.t + " cf:" + h._currentframe
              + " ax:" + h.a._x + " b:" + typeof(h.b));
    }
}
