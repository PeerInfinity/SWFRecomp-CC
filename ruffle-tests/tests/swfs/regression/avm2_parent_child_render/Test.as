package {
	import flash.display.Sprite;
	import flash.display.Loader;
	import flash.display.DisplayObject;
	import flash.display.BitmapData;
	import flash.events.Event;
	import flash.net.URLRequest;

	// Parent of avm2_parent_child_render. See README.md.
	//
	// Two circles of the same radius in DISJOINT x ranges: the parent's own
	// (red, centre 100,200) is the CONTROL and the loaded child's (blue,
	// centre 300,200) is the discriminator. Each movie defines exactly one
	// shape, so both sit at vertex offset 0 / colour index 0 of their own
	// tables.
	//
	// Two independent readers of the same geometry are graded:
	//   hitTestPoint(x, y, true) walks the shape's TRIANGLES
	//     (avm2_display.c shape_contains_local -> shape_data). A circle's
	//     bounding-box corner is outside the circle, so the ":cor" probes tell
	//     an exact test from the bounding-box fallback a shape with no
	//     resolved geometry falls back to.
	//   BitmapData.draw + getPixel runs the CPU raster
	//     (avm2_cpu_raster_shape -> shape_data + color_data), which is the
	//     only trace-visible read of the fill COLOUR.
	public class Test extends Sprite {
		[Embed(source="parent_art.svg")]
		private var Art:Class;

		private var ldr:Loader;
		private var art:Sprite;

		public function Test() {
			art = new Art() as Sprite;
			addChild(art);
			ldr = new Loader();
			addChild(ldr);
			ldr.contentLoaderInfo.addEventListener(Event.COMPLETE, onDone);
			ldr.load(new URLRequest("child.swf"));
		}

		private function onDone(e:Event):void {
			var c:DisplayObject = ldr.content;
			trace("root:kids=" + this.numChildren + " content=" + (c != null));

			// Exact (shape) hit tests, stage coordinates.
			hit("ctl:in",  art, 100, 200);   // parent circle centre
			hit("ctl:cor", art,  48, 148);   // inside its bbox, outside the circle
			hit("chd:in",  c,   300, 200);   // child circle centre
			hit("chd:cor", c,   248, 148);   // inside its bbox, outside the circle

			// CPU raster read-back: fill colour at the same four points.
			var bd:BitmapData = new BitmapData(400, 400, false, 0xFFFFFF);
			bd.draw(this);
			px(bd, "ctl:px",     100, 200);
			px(bd, "ctl:px:cor",  48, 148);
			px(bd, "chd:px",     300, 200);
			px(bd, "chd:px:cor", 248, 148);
			trace("done");
		}

		private function hit(name:String, d:DisplayObject, x:int, y:int):void {
			trace(name + "=" + (d == null ? "null" : String(d.hitTestPoint(x, y, true))));
		}
		private function px(bd:BitmapData, name:String, x:int, y:int):void {
			trace(name + "=" + bd.getPixel(x, y).toString(16));
		}
	}
}
