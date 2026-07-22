package {
	import flash.display.MovieClip;
	import flash.display.BitmapData;
	import flash.utils.getQualifiedClassName;

	// T6 morph render gate. The timeline places ONE DefineMorphShape (a solid
	// rect whose right edge grows from x=50px (start) to x=90px (end); solid
	// fill morphs RED -> BLUE) three times at ratios 0 / 32768 / 65535, stacked
	// vertically (ty = 0 / 100 / 200 px). BitmapData.draw rasterizes them and
	// getPixel reads back:
	//   - ratio 0   (top band, edge x=50): fill = pure START = red; x=70 outside.
	//   - ratio 0.5 (mid band, edge x=70): x=60 inside / x=80 outside (position
	//     interpolation); x=30 fill = the RED->BLUE midpoint colour.
	//   - ratio 1   (bottom band, edge x=90): fill = pure END = blue; x=80 inside.
	// Endpoints are exact by construction; the expected midpoint values come from
	// a Ruffle --graphics gl run of THIS swf (see output.txt) — CPU == GPU ==
	// Ruffle.
	public class Main extends MovieClip {
		public function Main() {
			trace("morph children=" + this.numChildren
			      + " " + getQualifiedClassName(this.getChildAt(0)));
			var bd:BitmapData = new BitmapData(400, 400, false, 0xFFFFFF);
			bd.draw(this);
			emit(bd, "r0_fill", 30, 25);   // ratio 0: pure start red
			emit(bd, "r0_out",  70, 25);   // ratio 0: outside (edge 50) -> bg
			emit(bd, "r5_in",   60, 125);  // ratio .5: inside (edge ~70)
			emit(bd, "r5_out",  80, 125);  // ratio .5: outside -> bg
			emit(bd, "r5_fill", 30, 125);  // ratio .5: interpolated fill colour
			emit(bd, "r1_fill", 30, 225);  // ratio 1: pure end blue
			emit(bd, "r1_in",   80, 225);  // ratio 1: inside (edge 90)
		}
		private function emit(bd:BitmapData, name:String, x:int, y:int):void {
			trace(name + "=" + bd.getPixel(x, y).toString(16));
		}
	}
}
