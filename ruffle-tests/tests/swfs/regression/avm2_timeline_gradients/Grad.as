package {
	import flash.display.Sprite;
	import flash.display.BitmapData;
	public class Grad extends Sprite {
		[Embed(source="grad.svg")]
		private var Art:Class;
		public function Grad() {
			var art:Sprite = new Art() as Sprite;
			addChild(art);
			trace("grad placed");
			// T5 getPixel gate: CPU-raster the timeline gradient shapes into a
			// BitmapData and read them back; expected == Ruffle --graphics gl
			// export pixel (output.expected.png). CPU == GPU == Ruffle.
			var bd:BitmapData = new BitmapData(400, 400, false, 0xFFFFFF);
			bd.draw(art);
			emit(bd, "bg", 200, 380);       // stage background
			emit(bd, "rad_c", 80, 80);      // radial gradient, centre
			emit(bd, "rad_e", 80, 130);     // radial gradient, edge
			emit(bd, "foc_c", 280, 80);     // focal gradient, centre
			emit(bd, "reflect", 100, 260);  // reflect-spread linear
			emit(bd, "repeat", 300, 260);   // repeat-spread linear
		}
		private function emit(bd:BitmapData, name:String, x:int, y:int):void {
			trace(name + "=" + bd.getPixel(x, y).toString(16));
		}
	}
}
