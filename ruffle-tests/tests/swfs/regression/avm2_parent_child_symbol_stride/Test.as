package {
    import flash.display.Sprite;
    import flash.display.Loader;
    import flash.display.DisplayObject;
    import flash.events.Event;
    import flash.net.URLRequest;
    import flash.utils.getQualifiedClassName;

    // Parent of avm2_parent_child_symbol_stride. See README.md for what this
    // pins down: the child's character ids are re-based by char_id_base, and
    // every AVM2-side reader of them (the root SymbolClass binding, the
    // embedded bitmap's SymbolClass row, the child's timeline tables) has to
    // agree on the same base.
    public class Test extends Sprite {
        private var ldr:Loader;

        public function Test() {
            ldr = new Loader();
            ldr.contentLoaderInfo.addEventListener(Event.COMPLETE, onDone);
            ldr.load(new URLRequest("child.swf"));
        }

        private function onDone(e:Event):void {
            var c:DisplayObject = ldr.content;
            trace("root:" + getQualifiedClassName(c));
            trace("done");
        }
    }
}
