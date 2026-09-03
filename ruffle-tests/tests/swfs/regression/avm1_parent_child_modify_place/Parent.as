// Source for regression/avm1_parent_child_modify_place (test.swf).
// See create_test_swf.py for what this pins down (character id 0 is the
// "no character" sentinel and must never be re-based when a loaded child's
// dictionary is lifted clear of its parent's).
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
        trace("t:" + typeof(_root.holder.mc));
        trace("nm:" + _root.holder.mc._name);
        trace("done");
    }
}
