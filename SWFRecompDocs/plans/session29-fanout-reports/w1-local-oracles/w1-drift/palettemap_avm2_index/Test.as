// w1-drift (s29) Flash probe: how AVM2 BitmapData.paletteMap indexes its
// channel arrays. Ruffle reads get_enumerant_value(i) = arr[i-1] (and 0 for
// i == 0); the documented behaviour is arr[i]. Each line names both
// predictions.
package {
    import flash.display.BitmapData;
    import flash.display.Sprite;
    import flash.geom.Point;
    import flash.geom.Rectangle;

    public class Test extends Sprite {
        public function Test() {
            var idR:Array = [], idG:Array = [], idB:Array = [], idA:Array = [];
            var zero0:Array = [], zeros:Array = [];
            for (var i:int = 0; i < 256; i++) {
                idR.push(i << 16); idG.push(i << 8); idB.push(i); idA.push(uint(i) << 24);
                zero0.push(i == 0 ? 0x00AA0000 : 0);
                zeros.push(0);
            }

            // arr[i]: 0xFF102030   arr[i-1]: 0xFF0F1F2F
            trace("identity arrays opaque: " + map(false, 0xFF102030, idR, idG, idB, idA));
            // arr[i]: 0xFFAA0000   arr[i-1]: 0xFE000000
            trace("index zero transparent: " + map(true, 0xFF000000, zero0, zeros, zeros, idA));
            // arr[i]: 0x80102030 (premultiplied round trip may move rgb)
            trace("identity arrays transparent half: " + map(true, 0x80102030, idR, idG, idB, idA));
            // arr[i]: 0xFF102030   arr[i-1]: 0xFF101F2F (null red = identity)
            trace("null red, identity rest opaque: " + map(false, 0xFF102030, null, idG, idB, idA));
            trace("Done");
        }

        private function map(transparent:Boolean, srcColor:uint, r:Array, g:Array, b:Array, a:Array):String {
            var src:BitmapData = new BitmapData(1, 1, transparent, srcColor);
            var dst:BitmapData = new BitmapData(1, 1, transparent, 0xFF000000);
            dst.paletteMap(src, new Rectangle(0, 0, 1, 1), new Point(0, 0), r, g, b, a);
            return hex(dst.getPixel32(0, 0));
        }

        private function hex(v:uint):String {
            var s:String = v.toString(16).toUpperCase();
            while (s.length < 8) s = "0" + s;
            return "0x" + s;
        }
    }
}
