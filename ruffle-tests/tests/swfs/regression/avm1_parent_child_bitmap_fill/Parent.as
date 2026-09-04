// Source for regression/avm1_parent_child_bitmap_fill (test.swf).
// See create_test_swf.py: this test is graded by PIXELS. There is no
// trace-visible read of the renderer's bitmap slot table, so the trace output
// only says the movie ran and the child loaded.
//
// Build (SWF8 AVM1 parent, then the bitmap + shape tags are spliced into
// frame 1):
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
            trace("ctl:" + typeof(_root.ctl));
            trace("chd:" + typeof(_root.holder.sub));
            trace("done");
        };
    }
}
