// s27 w2-draw-cx-text: Flash characterization of TEXT colour in
// BitmapData.draw() (LOCAL ORACLE REQUEST, FLASH trace). Build with
// ruffle-tests/tests/swfs/regression/avm2_bitmapdata_draw_textfield/build_swf.sh
// (mxmlc; DejaVuSans embed, same as that fixture).
//
// Flash already told us (w1 oracle avm2_bitmapdata_draw_edittext_box) that a
// DEVICE-font field's BOX is not tinted by the draw() ct nor by its own cx.
// Open questions this answers, each on a device-font AND an embedded field:
//   G*: glyph colour under draw(tf), draw(tf, ct), draw(holder > tinted tf),
//       draw(holder > tf, ct). Glyphs are red 0xFF0000; the tint (0,1,1,1,
//       0,255,0,0) turns red into green 0x00FF00 (red*0+0, green*1+255).
//   X*: the BOX of an EMBEDDED field under the same tints (is "untinted box"
//       a device-font rule or a draw() rule?).
// Glyph probes count EXACT solid pixels on a transparent target (stroke
// interiors are fully covered, so 0xFFFF0000 / 0xFF00FF00 are exact by
// construction; AA edges are ignored). Box probes read the centre pixel of an
// opaque-blue target behind a field with no text.
package {
	import flash.display.MovieClip;
	import flash.display.Sprite;
	import flash.display.BitmapData;
	import flash.geom.ColorTransform;
	import flash.text.TextField;
	import flash.text.TextFormat;

	public class Test extends MovieClip {
		[Embed(source="/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf",
		       fontName="TestFont", embedAsCFF="false", mimeType="application/x-font",
		       unicodeRange="U+0020-U+007E")]
		private var TestFontClass:Class;

		private function tint():ColorTransform {
			return new ColorTransform(0, 1, 1, 1, 0, 255, 0, 0);
		}
		private function glyphField(embed:Boolean):TextField {
			var tf:TextField = new TextField();
			tf.embedFonts = embed;
			tf.selectable = false;
			tf.width = 200; tf.height = 60;
			tf.defaultTextFormat = new TextFormat(embed ? "TestFont" : "_sans", 40, 0xFF0000, true);
			tf.text = "WMW";
			return tf;
		}
		private function boxField(embed:Boolean):TextField {
			var tf:TextField = new TextField();
			tf.embedFonts = embed;
			tf.width = 40; tf.height = 20;
			tf.background = true; tf.backgroundColor = 0xFF0000;
			return tf;
		}
		private function glyphs(src:*, ct:ColorTransform = null):String {
			var bd:BitmapData = new BitmapData(200, 60, true, 0);
			bd.draw(src, null, ct);
			var red:uint = 0, green:uint = 0;
			for (var y:int = 0; y < bd.height; y++)
				for (var x:int = 0; x < bd.width; x++) {
					var p:uint = bd.getPixel32(x, y);
					if (p == 0xFFFF0000) red++;
					else if (p == 0xFF00FF00) green++;
				}
			return "red=" + (red > 0) + " green=" + (green > 0);
		}
		private function box(src:*, ct:ColorTransform = null):String {
			var bd:BitmapData = new BitmapData(40, 20, false, 0x0000FF);
			bd.draw(src, null, ct);
			return bd.getPixel(20, 10).toString(16);
		}
		private function holder(child:*, tinted:Boolean):Sprite {
			var h:Sprite = new Sprite();
			if (tinted) child.transform.colorTransform = tint();
			h.addChild(child);
			return h;
		}
		public function Test() {
			for each (var embed:Boolean in [false, true]) {
				var k:String = embed ? "embed" : "device";
				trace("G " + k + " draw(tf) " + glyphs(glyphField(embed)));
				trace("G " + k + " draw(tf,ct) " + glyphs(glyphField(embed), tint()));
				trace("G " + k + " draw(h>tinted tf) " + glyphs(holder(glyphField(embed), true)));
				trace("G " + k + " draw(h>tf,ct) " + glyphs(holder(glyphField(embed), false), tint()));
				trace("X " + k + " box draw(tf) = " + box(boxField(embed)));
				trace("X " + k + " box draw(tf,ct) = " + box(boxField(embed), tint()));
				trace("X " + k + " box draw(h>tinted tf) = " + box(holder(boxField(embed), true)));
				trace("X " + k + " box draw(h>tf,ct) = " + box(holder(boxField(embed), false), tint()));
			}
		}
	}
}
