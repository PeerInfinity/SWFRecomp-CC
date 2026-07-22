package {
	import flash.display.Sprite;
	import flash.display.BitmapData;
	public class Solid extends Sprite {
		[Embed(source="solid.svg")]
		private var Art:Class;
		public function Solid() {
			var art:Sprite = new Art() as Sprite;
			addChild(art);
			trace("solid placed");
			// T5 getPixel gate for T1 solid fills. Solid fills are exact by
			// construction: color_data holds the literal SWF fill RGBA and an
			// opaque getPixel round-trips it, so CPU == GPU == Ruffle == the
			// SVG fill colour. Points are well inside each shape.
			var bd:BitmapData = new BitmapData(400, 400, false, 0xFFFFFF);
			bd.draw(art);
			emit(bd, "bg", 200, 380);     // stage background
			emit(bd, "blue", 100, 90);    // blue rect interior
			emit(bd, "green", 270, 120);  // green circle centre
			emit(bd, "orange", 120, 280); // orange rect interior
			emit(bd, "gap", 220, 200);    // between shapes = bg
		}
		private function emit(bd:BitmapData, name:String, x:int, y:int):void {
			trace(name + "=" + bd.getPixel(x, y).toString(16));
		}
	}
}
