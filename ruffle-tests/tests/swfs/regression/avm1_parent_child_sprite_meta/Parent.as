// Source for regression/avm1_parent_child_sprite_meta (test.swf).
// See create_test_swf.py for what this pins down (the child-movie char-id
// offset reaching sprite METADATA — labels, placements, frame counts, the
// no-End-tag flag — and not just the sprite definition itself).
//
// Build: create_test_swf.py runs MTASC and then splices the three hand-built
// sprites into frame 1 of its output.
//
// Every row is a parent/child pair read through the SAME code path, so the
// parent row is the control and the child row is the discriminator.

class Parent {
    static var frames: Number = 0;
    static var pUnload: Number = 0;
    static var cUnload: Number = 0;
    static var armed: Boolean = false;
    static var reported: Boolean = false;

    static function main(): Void {
        _root.createEmptyMovieClip("holder", 1);
        _root.holder.loadMovie("child.swf");
        _root.onEnterFrame = function(): Void { Parent.tick(); };
    }

    static function tick(): Void {
        Parent.frames++;
        if (!Parent.armed) {
            Parent.arm();
            return;
        }
        // Sprite A is a 2-frame looper, so by frame 9 both copies have
        // wrapped several times — one surviving wrap is all the unload rows
        // need, and the extra ticks keep the row insensitive to load timing.
        if (Parent.frames >= 9 && !Parent.reported) {
            Parent.reported = true;
            _root.onEnterFrame = null;
            Parent.report();
        }
    }

    // Attach onUnload to both sprite A inners as soon as BOTH exist. Reading
    // them from AS is also what mints their cached MovieClips, which is what
    // the loop-back path invalidates for non-survivors.
    static function arm(): Void {
        var p: MovieClip = MovieClip(_root.psp);
        var c: MovieClip = MovieClip(_root.holder.csp);
        if (p == undefined || p.inner == undefined) {
            return;
        }
        if (c == undefined || c.inner == undefined) {
            return;
        }
        p.inner.onUnload = function(): Void { Parent.pUnload++; };
        c.inner.onUnload = function(): Void { Parent.cUnload++; };
        Parent.armed = true;
        trace("armed");
    }

    static function report(): Void {
        // Booleans, not counts: the number of wraps inside the measurement
        // window is timing-dependent, "did it ever unload" is not.
        trace("pU:" + Parent.yn(Parent.pUnload > 0));
        trace("cU:" + Parent.yn(Parent.cUnload > 0));

        trace("pA:" + Parent.gotoLabel(MovieClip(_root.psp)));
        trace("cA:" + Parent.gotoLabel(MovieClip(_root.holder.csp)));

        trace("pB:" + Parent.reachedFrame2(MovieClip(_root.pfc)));
        trace("cB:" + Parent.reachedFrame2(MovieClip(_root.holder.cfc)));
        trace("done");
    }

    static function yn(b: Boolean): String {
        return b ? "y" : "n";
    }

    // tagSetSpriteLabels: the label must resolve on the sprite's own char id.
    static function gotoLabel(mc: MovieClip): String {
        if (mc == undefined) {
            return "none";
        }
        mc.gotoAndStop("two");
        return String(mc._currentframe);
    }

    // tagSetSpriteFrameCounts + tagSetSpriteNoEndTag: sprite B only reaches
    // its second frame (where "inner2" is placed) if the body's frame count
    // overrode the header's, and only STAYS there if the missing End record
    // parked it.
    static function reachedFrame2(mc: MovieClip): String {
        if (mc == undefined) {
            return "none";
        }
        return Parent.yn(mc.inner2 != undefined);
    }
}
