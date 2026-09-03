// Source for regression/avm1_parent_child_bitmap (test.swf).
// See create_test_swf.py for what this pins down (the bitmap-metadata
// registry's missing per-movie base: a loaded child's bitmap offsets used to
// index the PARENT's bitmap_data array).
//
// Build (SWF8 AVM1 parent, then the bitmap tags are spliced in):
//   ~/CC/mtasc/bin/mtasc -cp ~/CC/mtasc/ocaml/mtasc/std \
//     -cp ~/CC/mtasc/ocaml/mtasc/std8 -main -header 200:150:30 \
//     Parent.as -swf test.swf -version 8
//
// Both bitmaps are read through the SAME two registries — ng_lookupExport
// (export name -> char id) and ng_getBitmapMetadata (char id -> pixels). The
// parent row is the control: it must keep working. The child row is the
// discriminator.
import flash.display.BitmapData;

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
        Parent.show("p", BitmapData.loadBitmap("parentBitmap"));
        Parent.show("c", BitmapData.loadBitmap("childBitmap"));
        trace("done");
    }

    // Two lines per bitmap: the pixel says WHICH array was read, the size says
    // which metadata entry was found.
    static function show(tag: String, b: BitmapData): Void {
        if (b == null) {
            trace(tag + "px:none");
            trace(tag + "sz:none");
            return;
        }
        trace(tag + "px:" + b.getPixel(0, 0));
        trace(tag + "sz:" + b.width + "x" + b.height);
    }
}
