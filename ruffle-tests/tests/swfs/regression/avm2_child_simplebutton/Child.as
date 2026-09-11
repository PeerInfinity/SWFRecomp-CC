package {
    import flash.display.MovieClip;
    public class Child extends MovieClip {
        public function Child() {
            trace("  Child ctor, numChildren=" + numChildren);
        }
    }
}
