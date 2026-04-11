package {
    import flash.display.Sprite;
    import flash.external.ExternalInterface;

    public class TestAS3Inject extends Sprite {
        private static var _init:Boolean = doInit();

        private static function doInit():Boolean {
            // Use ExternalInterface.call which can't be optimized away
            if (ExternalInterface.available) {
                ExternalInterface.call("console.log", "AS3_BRIDGE_STATIC_INIT");
                ExternalInterface.addCallback("wireCheck", function():String {
                    return "ok";
                });
            }
            return true;
        }

        public function TestAS3Inject() {
            super();
        }
    }
}
