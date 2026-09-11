package {
    import flash.display.MovieClip;
    import flash.utils.getQualifiedClassName;

    // Bound by SymbolClass to character 2 of child.swf, whose one frame
    // places character 1 (Inner) at depth 1. The implicit super() builds that
    // frame, so the child is already there when this body runs.
    public class Outer extends MovieClip {
        public function Outer() {
            trace("  Outer ctor, kid=" + getQualifiedClassName(getChildAt(0)));
        }
    }
}
