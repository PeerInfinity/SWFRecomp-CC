// Native timeline TextField (EditText) render — the getPixel gate for the
// AVM2 native-text-render track (sibling to the T1–T6 vector line).
//
// The existing avm2_bitmapdata_draw_textfield probe draws a TextField DIRECTLY
// (BitmapData.draw(tf) -> the bd_draw text_src path). That does NOT exercise a
// *placed* field composited through a container walk — the path both display
// walks (avm2_cpu_walk / avm2_render_node) and bd_draw_shape_walk use, and the
// path that leaves EQ's HUD blank. This probe adds a TextField as a CHILD of a
// container and draws the CONTAINER, so the raster runs through
// bd_draw_shape_walk -> avm2_cpu_raster_text (the new Leg-A arm). On the
// pre-Leg-A runtime the container walk had no text arm, so every assertion here
// fails (the container draws nothing).
//
// Assertions are exact by construction (T4-probe style — no Ruffle export
// needed): a fully-covered glyph-interior pixel is the pure text colour
// (0xFFFF0000), and the only difference between drawing the field directly and
// drawing the container is the child's integer (10,10)px placement, so the pure-
// red pixel set shifts by exactly (10,10). CPU == GPU == Ruffle rides that
// invariant (the GPU/Dawn sink is graded by the image oracle, informational).
package {
	import flash.display.MovieClip;
	import flash.display.Sprite;
	import flash.display.BitmapData;
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
			tf.height = 60;
			tf.defaultTextFormat = new TextFormat("TestFont", 30, 0xFF0000);
			tf.text = "Hi";
			return tf;
		}

		// bbox of the pure text-colour pixels only (AA edges excluded, so the
		// box is exact under an integer translation).
		private function redBox(bd:BitmapData):Array {
			var x0:int = bd.width, y0:int = bd.height, x1:int = -1, y1:int = -1;
			var n:uint = 0;
			for (var y:int = 0; y < bd.height; y++)
				for (var x:int = 0; x < bd.width; x++)
					if (bd.getPixel32(x, y) == 0xFFFF0000) {
						n++;
						if (x < x0) x0 = x;  if (y < y0) y0 = y;
						if (x > x1) x1 = x;  if (y > y1) y1 = y;
					}
			return [n, x0, y0, x1, y1];
		}

		public function Test() {
			// Direct field draw (the already-tested text_src path) as the oracle.
			var tf1:TextField = makeField();
			var bdDirect:BitmapData = new BitmapData(300, 100, true, 0);
			bdDirect.draw(tf1);
			var d:Array = redBox(bdDirect);

			// Placed field: child of a container, offset (10,10)px, container drawn.
			var holder:Sprite = new Sprite();
			var tf2:TextField = makeField();
			tf2.x = 10;
			tf2.y = 10;
			holder.addChild(tf2);
			var bdCont:BitmapData = new BitmapData(300, 100, true, 0);
			bdCont.draw(holder);
			var c:Array = redBox(bdCont);

			// 1) The container walk produced solid text pixels (fails on no-op).
			trace("container: " + (c[0] > 0 && d[0] > 0));

			// 2) The placed field composited at exactly the child's (10,10)px
			//    offset — same glyph coverage, translated.
			trace("shifted: " + (c[0] == d[0]
			                     && c[1] == d[1] + 10 && c[2] == d[2] + 10
			                     && c[3] == d[3] + 10 && c[4] == d[4] + 10));

			// 3) Background between/around glyphs stays clear (no stray fill).
			trace("bg clear: " + (bdCont.getPixel32(0, 0) == 0
			                      && bdCont.getPixel32(299, 99) == 0));

			trace("done");
		}
	}
}
