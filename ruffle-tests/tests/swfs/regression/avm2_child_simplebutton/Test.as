package {
    import flash.display.DisplayObject;
    import flash.display.DisplayObjectContainer;
    import flash.display.Loader;
    import flash.display.SimpleButton;
    import flash.display.Sprite;
    import flash.events.Event;
    import flash.net.URLRequest;
    import flash.utils.getQualifiedClassName;

    public class Test extends Sprite {
        private var ldr:Loader;
        public function Test() {
            ldr = new Loader();
            ldr.contentLoaderInfo.addEventListener(Event.COMPLETE, onDone);
            trace("load");
            ldr.load(new URLRequest("child.swf"));
        }
        private function desc(n:String, s:DisplayObject):void {
            if (s == null) { trace(n + ": null"); return; }
            var line:String = n + ": " + getQualifiedClassName(s) + " w=" + s.width + " h=" + s.height;
            var c:DisplayObjectContainer = s as DisplayObjectContainer;
            if (c != null) line += " kids=" + c.numChildren;
            trace(line);
        }
        private function onDone(e:Event):void {
            var root:DisplayObjectContainer = ldr.content as DisplayObjectContainer;
            trace("root kids=" + root.numChildren);
            var b:SimpleButton = root.getChildAt(0) as SimpleButton;
            trace("child0:" + getQualifiedClassName(root.getChildAt(0)));
            if (b == null) { trace("not a button"); return; }
            desc("up", b.upState);
            desc("over", b.overState);
            desc("down", b.downState);
            desc("hit", b.hitTestState);
            trace("button w=" + b.width + " h=" + b.height);
            trace("done");
        }
    }
}
