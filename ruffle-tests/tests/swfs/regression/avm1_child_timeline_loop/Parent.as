// Source for regression/avm1_child_timeline_loop (test.swf).
// See create_test_swf.py for what this pins down: a loaded child SWF's
// timeline WRAPPING back to its frame 1, taking its own display children off
// the list on the way, and leaving everybody else's alone.
//
// Build (SWF8 AVM1 parent):
//   ~/CC/mtasc/bin/mtasc -cp ~/CC/mtasc/ocaml/mtasc/std \
//     -cp ~/CC/mtasc/ocaml/mtasc/std8 -main -header 200:200:30 \
//     Parent.as -swf test.swf -version 8
class Parent {
    static var t: Number = 0;

    static function main(): Void {
        // Two loaded movies with DIFFERENT cycle lengths (3 and 2) at disjoint
        // depths. They go out of phase immediately, so every wrap of one is a
        // live assertion that the other one's children survived it.
        _root.createEmptyMovieClip("h1", 1);
        _root.h1.loadMovie("child.swf");
        _root.createEmptyMovieClip("h2", 2);
        _root.h2.loadMovie("child2.swf");
        _root.onEnterFrame = function(): Void {
            Parent.t++;
            Parent.sample();
            if (Parent.t >= 9) {
                _root.onEnterFrame = null;
                trace("done");
            }
        };
    }

    // One row per tick. `t` rising 1..9 exactly once is itself the assertion
    // that the child's LAST frame did not rewind the PARENT: the root wrap
    // (`next_frame = 0; manual_next_frame = 1;`) that the recompiler emits into
    // every multi-frame movie's last frame would re-run this movie's frame 1,
    // re-enter main(), and restart the counter.
    static function sample(): Void {
        var a: MovieClip = _root.h1;
        var b: MovieClip = _root.h2;
        trace("t" + Parent.t
              + " f1:" + a._currentframe
              + " a:" + typeof(a.a) + " b:" + typeof(a.b) + " c:" + typeof(a.c)
              + " ax:" + a.a._x
              + " | f2:" + b._currentframe
              + " p:" + typeof(b.p) + " q:" + typeof(b.q)
              + " | rf:" + _root._currentframe);
    }
}
