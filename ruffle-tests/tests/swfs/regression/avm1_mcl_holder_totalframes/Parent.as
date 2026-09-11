// Source for regression/avm1_mcl_holder_totalframes (test.swf).
// See create_test_swf.py for what this pins down: a holder that
// MovieClipLoader.loadClip loaded a multi-frame SWF into must report the
// loaded movie's _totalframes / _framesloaded, exactly like a holder that
// loadMovie loaded the same SWF into (the negative control).
//
// Build (SWF8 AVM1 parent):
//   ~/CC/mtasc/bin/mtasc -cp ~/CC/mtasc/ocaml/mtasc/std \
//     -cp ~/CC/mtasc/ocaml/mtasc/std8 -main -header 200:200:30 \
//     Parent.as -swf test.swf -version 8
class Parent {
    static var t: Number = 0;
    // Per-holder log of DISTINCT rows, printed once at the end. A change log
    // rather than a per-tick trace, so the expected output does not depend on
    // which tick each load lands on (our MCL load lands a tick later than
    // Flash's -- BACKLOG §Multi-SWF, deliberately out of scope here).
    static var seen: Object = {};
    static var last: Object = {};

    static function main(): Void {
        _root.createEmptyMovieClip("m", 1);   // MovieClipLoader.loadClip holder
        _root.createEmptyMovieClip("d", 2);   // direct loadMovie holder (control)

        var mcl: MovieClipLoader = new MovieClipLoader();
        var l: Object = {};
        // Before the movie's frame 1 has run: the frame counts are the
        // movie's already, the playhead is still 0.
        l.onLoadComplete = function(h: MovieClip): Void {
            trace("complete " + h._name + " cf:" + h._currentframe + " "
                  + Parent.row(h));
        };
        // After it: the playhead reads 1.
        l.onLoadInit = function(h: MovieClip): Void {
            trace("init " + h._name + " cf:" + h._currentframe + " "
                  + Parent.row(h));
        };
        mcl.addListener(l);
        mcl.loadClip("child.swf", _root.m);
        _root.d.loadMovie("child.swf");

        _root.onEnterFrame = function(): Void {
            Parent.t++;
            Parent.poll("m", _root.m);
            Parent.poll("d", _root.d);
            if (Parent.t >= 10) {
                _root.onEnterFrame = null;
                trace("m " + Parent.seen["m"]);
                trace("d " + Parent.seen["d"]);
                trace("end m cf:" + _root.m._currentframe
                      + " d cf:" + _root.d._currentframe);
            }
        };
    }

    static function row(h: MovieClip): String {
        return "tf:" + h._totalframes + " fl:" + h._framesloaded
               + " bt:" + h.getBytesTotal();
    }

    static function poll(k: String, h: MovieClip): Void {
        var r: String = Parent.row(h);
        if (r != Parent.last[k]) {
            Parent.last[k] = r;
            Parent.seen[k] = (Parent.seen[k] == undefined)
                ? "[" + r + "]" : Parent.seen[k] + " [" + r + "]";
        }
    }
}
