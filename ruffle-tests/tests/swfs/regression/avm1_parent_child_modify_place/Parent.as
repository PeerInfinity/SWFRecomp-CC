// Source for regression/avm1_parent_child_modify_place (test.swf).
// See create_test_swf.py for what this pins down: `_x`/`_y` on a loaded
// child's TAG-PLACED clip (they used to read past the end of the parent's
// one-row transform table), and character id 0 as the "no character" sentinel
// that must never be re-based when a child's dictionary is lifted clear of
// its parent's.
//
// Build (SWF8 AVM1 parent):
//   ~/CC/mtasc/bin/mtasc -cp ~/CC/mtasc/ocaml/mtasc/std \
//     -cp ~/CC/mtasc/ocaml/mtasc/std8 -main -header 200:200:30 \
//     Parent.as -swf test.swf -version 8
class Parent {
    static var frames: Number = 0;

    static function main(): Void {
        _root.createEmptyMovieClip("holder", 1);
        _root.holder.loadMovie("child.swf");
        _root.onEnterFrame = function(): Void {
            Parent.frames++;
            // The child needs its own frame 1 AND frame 2 to have run; five
            // parent ticks is comfortably past that and well inside the
            // test's frame budget.
            if (Parent.frames < 5) {
                return;
            }
            _root.onEnterFrame = null;
            Parent.report();
        };
    }

    static function report(): Void {
        // typeof/_name are controls: they read correctly even when the
        // coordinates do not. _x/_y are the discriminating rows — the child
        // places "mc" at (10, 5) and Modifies it to (50, 30) in the same
        // frame, so 50/30 means BOTH the transform-table lookup and the
        // character-id-0 sentinel are intact.
        trace("t:" + typeof(_root.holder.mc));
        trace("nm:" + _root.holder.mc._name);
        trace("x:" + _root.holder.mc._x);
        trace("y:" + _root.holder.mc._y);
        trace("done");
    }
}
