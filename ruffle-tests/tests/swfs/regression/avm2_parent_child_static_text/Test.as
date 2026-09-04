package {
	import flash.display.MovieClip;
	import flash.display.DisplayObject;
	import flash.display.DisplayObjectContainer;
	import flash.display.Loader;
	import flash.display.BitmapData;
	import flash.events.Event;
	import flash.net.URLRequest;
	import flash.text.StaticText;

	// Parent of avm2_parent_child_static_text. See README.md.
	//
	// Each movie carries ONE hand-spliced DefineFont3 + DefineText
	// (build_statictext.py), placed on its own root timeline at depth 1. Each
	// font has ONE glyph — a full-EM square — but a DIFFERENT character code
	// ('A' in the parent, 'B' in the child), and each text record draws that
	// glyph twice in a colour and at a pen x of its own. Both movies therefore
	// sit at static-glyph run start 0 of their OWN static_glyphs array, which
	// is the index-0 collision avm2_parent_child_render uses: a read against
	// the ROOT's array lands on real, in-bounds data (the parent's run) rather
	// than on garbage, and reports the PARENT's character code.
	//
	// Two independent readers of that run are graded:
	//   StaticText.text          -> avm2_display.c statictext_get_text
	//   BitmapData.draw+getPixel -> avm2_cpu_raster_statictext ->
	//                               avm2_text.c avm2_statictext_collect_glyphs
	// Both go through avm2_display_static_glyphs_for(), the registry lookup
	// keyed on the Avm2StaticTextData* pointer itself, and both are ordinary
	// ActionScript — so both rows run in NO_GRAPHICS as well as graphics.
	public class Test extends MovieClip {
		private var ldr:Loader;

		public function Test() {
			ldr = new Loader();
			addChild(ldr);
			ldr.contentLoaderInfo.addEventListener(Event.COMPLETE, onDone);
			ldr.load(new URLRequest("child.swf"));
		}

		private function onDone(e:Event):void {
			var c:DisplayObjectContainer = ldr.content as DisplayObjectContainer;
			trace("root:kids=" + this.numChildren + " content=" + (c != null));
			trace("chd:kids=" + (c == null ? -1 : c.numChildren));

			// Reader 1: the glyph run's character codes.
			txt("ctl:txt", findStatic(this));
			txt("chd:txt", findStatic(c));

			// Reader 2: the CPU raster of the same run — colour AND pen x.
			var bd:BitmapData = new BitmapData(400, 400, false, 0xFFFFFF);
			bd.draw(this);
			px(bd, "ctl:px",       20, 30);   // parent glyph0 interior -> red
			px(bd, "ctl:px:gap",   40, 30);   // between the parent's glyphs
			px(bd, "chd:px",      220, 30);   // child glyph0 interior -> blue
			px(bd, "chd:px:2",    260, 30);   // child glyph1 interior -> blue
			px(bd, "chd:px:gap",  240, 30);   // between the child's glyphs
			px(bd, "chd:px:below", 220, 50);  // under the child's glyph cell
			trace("done");
		}

		private function findStatic(d:DisplayObjectContainer):StaticText {
			if (d == null) return null;
			for (var i:int = 0; i < d.numChildren; i++) {
				var k:DisplayObject = d.getChildAt(i);
				if (k is StaticText) return k as StaticText;
			}
			return null;
		}
		private function txt(name:String, s:StaticText):void {
			trace(name + "=" + (s == null ? "<none>" : s.text));
		}
		private function px(bd:BitmapData, name:String, x:int, y:int):void {
			trace(name + "=" + bd.getPixel(x, y).toString(16));
		}
	}
}
