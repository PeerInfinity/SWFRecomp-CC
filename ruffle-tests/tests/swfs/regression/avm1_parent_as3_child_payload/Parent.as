// Source for regression/avm1_parent_as3_child_payload (test.swf).
// See create_test_swf.py for what this pins down (the dead-payload skip's
// is_as3 seam: an AS3 child loaded by an AVM1 parent still runs its tagInit).
//
// Build (SWF8 AVM1 parent):
//   ~/CC/mtasc/bin/mtasc -cp ~/CC/mtasc/ocaml/mtasc/std -main \
//     -header 200:150:30 Parent.as -swf test.swf -version 8
//
// The child is loaded, not linked: its sound reaches the parent only through
// the runtime's export + sound-metadata registries, both filled by the
// child's tagInit. attachSound resolves the export (never dropped) and reads
// the duration (dropped with the payload), so getDuration is the discriminator.
class Parent {
    static var frames: Number = 0;

    static function main(): Void {
        _root.createEmptyMovieClip("holder", 1);
        _root.holder.loadMovie("child.swf");
        _root.onEnterFrame = function(): Void {
            Parent.frames++;
            if (Parent.frames < 3) {
                return;
            }
            _root.onEnterFrame = null;
            Parent.report();
        };
    }

    static function report(): Void {
        var s: Sound = new Sound();
        s.attachSound("childSound");
        trace("dur:" + s.getDuration());
        trace("done");
    }
}
