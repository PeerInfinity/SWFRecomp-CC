// s27 w1-text-glyph-fidelity item 4 (AVM2 side); landed by s27
// w2-draw-cx-text. Build: build_swf.sh (mxmlc; test.swf is the coordinator's
// build archived under SWFRecomp-CC-history:SWFRecompDocs/plans/session27-fanout-reports/
// w1-local-oracles/w1-text-glyph-fidelity/avm2_bitmapdata_draw_edittext_box/).
// output.txt is FLASH PLAYER 32's trace (flash.txt there). Flash: the box IS
// drawn, but neither the draw ct (A) nor the field's own cx (B) tints it,
// while a tinted SHAPE child is tinted (B shape = ff00). The trailing
// per-line comments below are the original by-construction guesses; lines
// 2-3 are wrong (Flash: ff0000), as is Ruffle's exporter (ff00).
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
