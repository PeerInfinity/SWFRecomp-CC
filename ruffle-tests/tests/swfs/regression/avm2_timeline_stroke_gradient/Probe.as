package {
	import flash.display.Sprite;
	import flash.display.BitmapData;
	public class Probe extends Sprite {
		[Embed(source="probe.svg")]
		private var Art:Class;
		public function Probe() {
			var art:Sprite = new Art() as Sprite;
			addChild(art);
			trace("probe placed");
			// T5: rasterize the timeline shapes into a BitmapData via the CPU
			// shape raster (bd.draw of a shape Sprite), then read pixels back.
			// Each expected value == the Ruffle --graphics gl export pixel at that
			// coordinate (output.expected.png), closing CPU == GPU == Ruffle in a
			// no-graphics trace gate. Points are shape-interior / stroke-centreline
			// to avoid antialiased-edge coverage differences.
			var bd:BitmapData = new BitmapData(400, 400, false, 0xFFFFFF);
			bd.draw(art);
			emit(bd, "bg", 200, 380);          // stage background (outside all art)
			emit(bd, "stroke_l", 10, 50);      // stroke rect, left edge (T2)
			emit(bd, "stroke_t", 70, 10);      // stroke rect, top edge (T2)
			emit(bd, "rect_hollow", 70, 50);   // inside the unfilled stroke rect = bg
			emit(bd, "lin_l", 15, 150);        // linear gradient, near start (T3)
			emit(bd, "lin_m", 70, 150);        // linear gradient, middle (T3)
			emit(bd, "lin_r", 125, 150);       // linear gradient, near end (T3)
			emit(bd, "rad_c", 250, 150);       // radial gradient, centre (T3)
		}
		private function emit(bd:BitmapData, name:String, x:int, y:int):void {
			trace(name + "=" + bd.getPixel(x, y).toString(16));
		}
	}
}
