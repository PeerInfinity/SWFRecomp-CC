package {
    import flash.display.MovieClip;
    import flash.media.Sound;
    import flash.utils.ByteArray;
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

        // A DefineBinaryData character in the CHILD movie. Same defect family
        // as Pix: the class -> char id map and the payload table are both
        // built from the MAIN movie only, so this read came back 0 bytes.
        [Embed(source="blob.bin", mimeType="application/octet-stream")]
        private static var Blob:Class;

        // A DefineSound character in the CHILD movie — the third table in the
        // same family (see README.md).
        [Embed(source="silence.mp3")]
        private static var Snd:Class;

        public function Child() {
            var o:Object = new Pix();
            trace("child:tf" + this.totalFrames
                  + ":" + getQualifiedClassName(o));
            // The embedded PNG is 4x3. Reading its DIMENSIONS (not just its
            // class name) is the child-bitmap lock: the pixels live in the
            // CHILD movie's bitmap table, and until
            // SWFRecompDocs/status/child-embedded-asset-lookup.md
            // embedded_bitmap_for_char scanned only the MAIN movie's, so this
            // read came back 0x0 here and 4x3 when the same SWF is the root.
            trace("child:pix:" + o.width + "x" + o.height);
            var b:ByteArray = new Blob() as ByteArray;
            trace("child:blob:" + (b == null ? -1 : b.length));
            var sn:Sound = new Snd() as Sound;
            trace("child:snd:" + (sn == null ? -1 : Math.floor(sn.length)));
        }
    }
}
