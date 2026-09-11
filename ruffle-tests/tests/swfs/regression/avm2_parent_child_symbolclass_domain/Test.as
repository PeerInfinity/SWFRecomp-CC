package {
    import flash.display.DisplayObjectContainer;
    import flash.display.Loader;
    import flash.display.Sprite;
    import flash.events.Event;
    import flash.net.URLRequest;
    import flash.system.ApplicationDomain;
    import flash.utils.getQualifiedClassName;

    // Parent of avm2_parent_child_symbolclass_domain. See README.md.
    // The child loads with the default LoaderContext, i.e. into a FRESH child
    // ApplicationDomain: Inner and Outer exist there and nowhere else.
    public class Test extends Sprite {
        private var ldr:Loader;

        public function Test() {
            trace("parent:Inner visible=" + ApplicationDomain.currentDomain.hasDefinition("Inner"));
            ldr = new Loader();
            ldr.contentLoaderInfo.addEventListener(Event.COMPLETE, onDone);
            trace("load");
            ldr.load(new URLRequest("child.swf"));
        }

        private function onDone(e:Event):void {
            var root:DisplayObjectContainer = ldr.content as DisplayObjectContainer;
            var placed:DisplayObjectContainer = root.getChildAt(0) as DisplayObjectContainer;
            trace("timeline:" + getQualifiedClassName(placed)
                  + " kid:" + getQualifiedClassName(placed.getChildAt(0)));
            trace("parent:Inner visible=" + ApplicationDomain.currentDomain.hasDefinition("Inner"));
            var dom:ApplicationDomain = ldr.contentLoaderInfo.applicationDomain;
            var OuterCls:Class = dom.getDefinition("Outer") as Class;
            trace("script: new Outer()");
            var o:DisplayObjectContainer = new OuterCls() as DisplayObjectContainer;
            trace("script:" + getQualifiedClassName(o)
                  + " kid:" + getQualifiedClassName(o.getChildAt(0)));
            trace("done");
        }
    }
}
