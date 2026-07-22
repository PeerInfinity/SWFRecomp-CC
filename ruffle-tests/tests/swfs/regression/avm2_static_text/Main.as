package {
	import flash.display.MovieClip;
	import flash.display.BitmapData;
	import flash.utils.getQualifiedClassName;

	// Native static-text (DefineText/2 -> StaticText) render gate. The timeline
	// places ONE hand-authored DefineText (build_statictext.py) that draws a full
	// EM-box square glyph TWICE at text height 400 twips (scale 400/20480), colour
	// RED, pen (200,400) twips, 800-twip advance between the two glyphs. Exact by
	// construction (px = twips/20):
	//   glyph0 rect x[10,30] y[20,40] px ; glyph1 rect x[50,70] y[20,40] px.
	// BitmapData.draw(this) rasterizes via bd_draw_shape_walk -> the new StaticText
	// arm (avm2_cpu_raster_statictext) — on the old runtime nothing was drawn.
	// getPixel reads interior = text colour, between-glyphs / outside = bg white.
	public class Main extends MovieClip {
		public function Main() {
			trace("static children=" + this.numChildren
			      + " " + getQualifiedClassName(this.getChildAt(0)));
			var bd:BitmapData = new BitmapData(200, 200, false, 0xFFFFFF);
			bd.draw(this);
			emit(bd, "g0_in",  20, 30);  // glyph0 interior -> red
			emit(bd, "g1_in",  60, 30);  // glyph1 interior -> red
			emit(bd, "gap",    40, 30);  // between glyphs -> bg white
			emit(bd, "below",  20, 50);  // below the glyph cell -> bg white
			emit(bd, "left",    5, 30);  // left of glyph0 -> bg white
		}
		private function emit(bd:BitmapData, name:String, x:int, y:int):void {
			trace(name + "=" + bd.getPixel(x, y).toString(16));
		}
	}
}
