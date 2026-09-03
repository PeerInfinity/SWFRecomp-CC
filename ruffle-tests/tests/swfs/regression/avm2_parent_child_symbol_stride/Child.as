package {
    import flash.display.MovieClip;
    import flash.utils.getQualifiedClassName;

    // Child movie of avm2_parent_child_symbol_stride (see README.md).
    //
    // Everything traced here is keyed on a CHARACTER ID that the recompiler
    // re-based by this movie's `char_id_base`:
    //
    //   totalFrames  -> the child root's row in child_avm2_generated_timelines,
    //                   looked up by char id (avm2_display.c timeline_for_char).
    //                   The row's id and the id the root is instantiated under
    //                   must be the same number or the frame count reads 0/1.
    //   Child_Pix    -> the embedded PNG gives the child a SECOND, NON-ZERO
    //                   character (a DefineBitsLossless) with its own
    //                   SymbolClass row, so `char_id_base + 0` (the root
    //                   binding) is not the only id in the movie and a
    //                   collision between the two would be visible.
    public class Child extends MovieClip {
        [Embed(source="pixel.png")]
        private static var Pix:Class;

        public function Child() {
            var o:Object = new Pix();
            trace("child:tf" + this.totalFrames
                  + ":" + getQualifiedClassName(o));
        }
    }
}
