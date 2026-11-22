package {
	// s24 w2-bitmap-encode-shader probe: a ShaderFilter on a Bitmap must
	// follow every later write to its BitmapData (our runtime caches the CPU
	// shader output on the BitmapData's content version). One write path per
	// frame; the final frame shows the cumulative result. `ref` is the same
	// BitmapData, unfiltered, for eyeballing.
	import flash.display.*;
	import flash.events.Event;
	import flash.filters.ShaderFilter;
	import flash.geom.*;

	[SWF(width="200", height="100", frameRate="30", backgroundColor="#FFFFFF")]
	public class Test extends MovieClip {
		[Embed(source = "tintype.pbj", mimeType = "application/octet-stream")]
		public static var TINTYPE: Class;

		private var bd: BitmapData;
		private var shader: Shader;
		private var bmp: Bitmap;
		private var frame: int = 0;

		public function Test() {
			bd = new BitmapData(80, 80, false, 0xFF336699);
			shader = new Shader(new TINTYPE());
			shader.data.contrast.value = [1.0];
			shader.data.mid.value = [0.5];
			bmp = new Bitmap(bd);
			bmp.x = 10; bmp.y = 10;
			bmp.filters = [new ShaderFilter(shader)];
			addChild(bmp);
			var ref: Bitmap = new Bitmap(bd);
			ref.x = 110; ref.y = 10;
			addChild(ref);
			addEventListener(Event.ENTER_FRAME, tick);
			trace("init");
		}

		private function tick(e: Event): void {
			frame++;
			if (frame == 1) {
				bd.fillRect(new Rectangle(5, 5, 30, 30), 0xFFFF0000);
				trace("fillRect");
			} else if (frame == 2) {
				for (var i: int = 0; i < 80; i++) bd.setPixel(i, 60, 0x00FF00);
				trace("setPixel");
			} else if (frame == 3) {
				bd.lock();
				for (var j: int = 0; j < 80; j++) bd.setPixel32(70, j, 0xFFFFFF00);
				bd.unlock();
				trace("lock/setPixel32/unlock");
			} else if (frame == 4) {
				var s: Shape = new Shape();
				s.graphics.beginFill(0x0000FF);
				s.graphics.drawCircle(55, 25, 12);
				s.graphics.endFill();
				bd.draw(s);
				trace("draw");
			} else if (frame == 5) {
				// A parameter change only reaches the display when `filters`
				// is reassigned (filters are copied at assignment).
				shader.data.contrast.value = [2.0];
				bmp.filters = [new ShaderFilter(shader)];
				trace("contrast=2 + filters reassigned");
			} else if (frame == 6) {
				bd.copyPixels(bd, new Rectangle(0, 0, 20, 20), new Point(60, 60));
				trace("copyPixels");
				removeEventListener(Event.ENTER_FRAME, tick);
			}
		}
	}
}
