package {
    import flash.display.MovieClip;

    // Root of child.swf. Its frame 1 places character 2 (Outer) at depth 1 —
    // the TIMELINE placement row. Inner/Outer are referenced here only so
    // mxmlc links them into the child's ABC.
    public class Child extends MovieClip {
        private static const LINK:Array = [Inner, Outer];
        public function Child() {
            trace("  Child ctor, numChildren=" + numChildren);
        }
    }
}
