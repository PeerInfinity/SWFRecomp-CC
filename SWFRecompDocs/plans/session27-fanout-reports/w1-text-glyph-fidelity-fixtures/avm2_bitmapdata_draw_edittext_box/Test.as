// s27 w1-text-glyph-fidelity item 4 (AVM2 side). NOT BUILT in the cloud (no
// mxmlc): build with ../../../../../ruffle-tests/tests/swfs/regression/
// avm2_bitmapdata_draw_textfield/build_swf.sh's recipe and take output.txt
// from Flash/Ruffle (LOCAL ORACLE REQUEST).
//
// Pins two gaps in avm2_bitmap.c:
//  A. bd_draw_textfield / avm2_cpu_raster_text -> text_raster_core draws the
//     field's GLYPHS only: a background/border is never painted by draw().
//     Ruffle draws the TextField through render_self (draw_text_box), so the
//     box is part of the capture.
//  B. bd_draw_shape_walk carries only `alpha` down the subtree: a CHILD's
//     colorTransform (shape, text, bitmap) never reaches the CPU draw(). Flash
//     ignores only the SOURCE's own transform.
// Probes read solid fills (exact by construction) on an opaque blue target.
package {
	import flash.display.MovieClip;
	import flash.display.Sprite;
	import flash.display.BitmapData;
	import flash.geom.ColorTransform;
	import flash.text.TextField;

	public class Test extends MovieClip {
		private function field():TextField {
			var tf:TextField = new TextField();
			tf.width = 40; tf.height = 20;
			tf.background = true; tf.backgroundColor = 0xFF0000;
			return tf;
		}
		private function px(src:*, ct:ColorTransform = null):String {
			var bd:BitmapData = new BitmapData(40, 20, false, 0x0000FF);
			bd.draw(src, null, ct);
			return bd.getPixel(20, 10).toString(16);
		}
		public function Test() {
			var tf:TextField = field();
			trace("A draw(tf) = " + px(tf));                                   // ff0000
			trace("A draw(tf, ct) = " + px(tf, new ColorTransform(0, 1, 1, 1, 0, 255, 0, 0))); // ff00
			var h:Sprite = new Sprite();
			var t2:TextField = field();
			t2.transform.colorTransform = new ColorTransform(0, 1, 1, 1, 0, 255, 0, 0);
			h.addChild(t2);
			trace("B draw(holder>tinted tf) = " + px(h));                      // ff00
			var h2:Sprite = new Sprite();
			var s:Sprite = new Sprite();
			s.graphics.beginFill(0xFF0000); s.graphics.drawRect(0, 0, 40, 20); s.graphics.endFill();
			s.transform.colorTransform = new ColorTransform(0, 1, 1, 1, 0, 255, 0, 0);
			h2.addChild(s);
			trace("B draw(holder>tinted shape) = " + px(h2));                  // ff00
			trace("C tf.background(timeline-less) = " + tf.background);       // true
		}
	}
}
