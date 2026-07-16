// BitmapData.draw(TextField) — CPU glyph rasterization (RWK-2).
// Flixel (FlxText.calcFrame) and FlashPunk (Text.as updateBuffer) both
// render ALL their text by drawing a TextField into a BitmapData buffer:
//   _framePixels.draw(_tf, _mtx, _ct);
// bd_draw used to silently no-op for any non-Bitmap DisplayObject source,
// which left every Robot Wants Kitty button label and every Seedling
// FlashPunk text invisible. The assertions here are implementation-loose
// (no exact AA pixel counts) but each one fails on the old no-op:
//   1. drawing produces nonzero pixels,
//   2. a fully-covered stroke pixel is exactly the solid text color,
//   3. an integer matrix translation shifts the raster exactly,
//   4. a ColorTransform composes with the glyph color.
//
// Build: see build_swf.sh (mxmlc).
package {
	import flash.display.MovieClip;
	import flash.display.BitmapData;
	import flash.geom.ColorTransform;
	import flash.geom.Matrix;
	import flash.text.TextField;
	import flash.text.TextFormat;

	public class Test extends MovieClip {
		[Embed(source="/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf",
		       fontName="TestFont", embedAsCFF="false", mimeType="application/x-font",
		       unicodeRange="U+0020-U+007E")]
		private var TestFontClass:Class;

		private function makeField():TextField {
			var tf:TextField = new TextField();
			tf.embedFonts = true;
			tf.selectable = false;
			tf.width = 200;
			tf.height = 40;
			tf.defaultTextFormat = new TextFormat("TestFont", 20, 0xFF0000);
			tf.text = "Hello";
			return tf;
		}

		private function bbox(bd:BitmapData):Array {
			var x0:int = bd.width, y0:int = bd.height, x1:int = -1, y1:int = -1;
			var nz:uint = 0;
			for (var y:int = 0; y < bd.height; y++) {
				for (var x:int = 0; x < bd.width; x++) {
					if (bd.getPixel32(x, y) != 0) {
						nz++;
						if (x < x0) x0 = x;
						if (y < y0) y0 = y;
						if (x > x1) x1 = x;
						if (y > y1) y1 = y;
					}
				}
			}
			return [nz, x0, y0, x1, y1];
		}

		public function Test() {
			var tf:TextField = makeField();

			var bd:BitmapData = new BitmapData(200, 40, true, 0);
			bd.draw(tf);
			var a:Array = bbox(bd);
			trace("drawn: " + (a[0] > 0));

			var solid:Boolean = false;
			for (var y:int = 0; y < bd.height && !solid; y++)
				for (var x:int = 0; x < bd.width && !solid; x++)
					if (bd.getPixel32(x, y) == 0xFFFF0000) solid = true;
			trace("solid red: " + solid);

			var bd2:BitmapData = new BitmapData(200, 40, true, 0);
			var m:Matrix = new Matrix();
			m.translate(10, 5);
			bd2.draw(tf, m);
			var b:Array = bbox(bd2);
			trace("shifted: " + (b[1] == a[1] + 10 && b[2] == a[2] + 5
			                     && b[3] == a[3] + 10 && b[4] == a[4] + 5));

			var bd3:BitmapData = new BitmapData(200, 40, true, 0);
			var ct:ColorTransform = new ColorTransform(0, 1, 0, 1, 0, 255, 0, 0);
			bd3.draw(tf, null, ct);
			var green:Boolean = false;
			var stray:Boolean = false;
			for (y = 0; y < bd3.height; y++) {
				for (x = 0; x < bd3.width; x++) {
					var p:uint = bd3.getPixel32(x, y);
					if (p == 0xFF00FF00) green = true;
					if (p != 0 && (p & 0x00FF00FF) != 0) stray = true;
				}
			}
			trace("cxform green: " + (green && !stray));

			trace("done");
		}
	}
}
