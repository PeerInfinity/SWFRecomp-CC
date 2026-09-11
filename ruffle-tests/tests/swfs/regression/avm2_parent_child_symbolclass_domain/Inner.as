package {
    import flash.display.MovieClip;

    // Bound by SymbolClass to character 1 of child.swf (injected by
    // create_test_swf.py). Never constructed by name: only ever reached through
    // its character, placed by Outer's timeline.
    public class Inner extends MovieClip {
        public static const NAME:String = "Inner from child";
        public function Inner() {
            trace("  Inner ctor");
        }
    }
}
