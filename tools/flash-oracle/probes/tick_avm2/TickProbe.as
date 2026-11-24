package {
    // AVM2 tick-alignment probe: constructor = tick 1; each ENTER_FRAME after
    // that is the next tick. Traces "tick N" + currentFrame and draws bar N.
    import flash.display.*;
    import flash.events.Event;
    public class TickProbe extends MovieClip {
        private var n:int = 0;
        public function TickProbe() {
            bar();
            addEventListener(Event.ENTER_FRAME, function(e:Event):void { bar(); });
        }
        private function bar():void {
            n++;
            trace("tick " + n + " currentFrame=" + currentFrame);
            var x:int = (n - 1) * 12 + 4;
            graphics.beginFill(0x2040C0);
            graphics.drawRect(x, 4, 8, 36);
            graphics.endFill();
        }
    }
}
