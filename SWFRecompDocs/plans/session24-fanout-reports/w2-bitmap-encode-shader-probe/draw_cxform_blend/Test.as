package {
	// s24 w2-bitmap-encode-shader probe (w1-pixel-bitmap LOCAL ORACLE REQUEST 1):
	// vector BitmapData.draw() with a colorTransform AND a blendMode, at the
	// default quality (draw(), not drawWithQuality). The corpus row
	// (bitmapdata_draw_cab_quality) only uses ColorTransform(0,1,1) +
	// "difference" over black, which cannot tell cxform-then-blend from
	// blend-then-cxform. Three swatches: multiply, add, normal (cxform only).
	import flash.display.*;
	import flash.geom.*;

	[SWF(width="200", height="80", frameRate="30", backgroundColor="#FFFFFF")]
	public class Test extends MovieClip {
		public function Test() {
			var modes: Array = ["multiply", "add", "normal"];
			for (var k: int = 0; k < modes.length; k++) {
				var bd: BitmapData = new BitmapData(60, 60, false, 0xFF808080);
				var s: Shape = new Shape();
				s.graphics.beginFill(0xC0E040, 1.0);
				s.graphics.drawRect(0, 0, 30, 30);
				s.graphics.endFill();
				s.graphics.beginFill(0x2080FF, 0.5);
				s.graphics.drawCircle(30, 30, 18);
				s.graphics.endFill();
				bd.draw(s, new Matrix(1, 0, 0, 1, 10, 10),
				        new ColorTransform(0.5, 1, 0, 1, 0, 0, 128, 0), modes[k]);
				var b: Bitmap = new Bitmap(bd);
				b.x = 5 + k * 65; b.y = 10;
				addChild(b);
				trace(modes[k] + " " + bd.getPixel(15, 15).toString(16) + " "
				      + bd.getPixel(40, 40).toString(16));
			}
		}
	}
}
