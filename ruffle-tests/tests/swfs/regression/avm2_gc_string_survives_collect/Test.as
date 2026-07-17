// GC collectable strings: every C-side stash a heap string can live in must
// survive a collect — instance slot, Array element, dynamic prop VALUE and
// NAME (Avm2DynProp.name is a by-value copy sharing the census string's
// inline bytes), Dictionary string key, EDListener event type, and E4X node
// text (the immortal-node registry root). Strings are built by runtime
// concat so none is a static pool literal. Under AVM2_GC_STRESS=1 a collect
// runs before every tick; a swept live string surfaces as garbage traces or
// a crash instead of a rare corruption.
//
// Build: see build_swf.sh (mxmlc).
package {
	import flash.display.MovieClip;
	import flash.events.Event;
	import flash.utils.Dictionary;

	public class Test extends MovieClip {
		private var tick:int = 0;
		private var slotStr:String;
		private var arr:Array = [];
		private var dyn:Object = {};
		private var dict:Dictionary = new Dictionary();
		private var xml:XML;
		private var key:String;

		public function Test() {
			var base:String = "";
			for (var i:int = 0; i < 26; i++) base += String.fromCharCode(65 + i);
			slotStr = base + "-slot";
			arr.push(base + "-arr");
			key = base.toLowerCase() + "-key";
			dyn[key] = base + "-objval";
			dict[base + "-dictkey"] = base + "-dictval";
			xml = new XML("<r><c>" + base + "-xmltext</c></r>");
			addEventListener("evt-" + base, onCustom);
			addEventListener(Event.ENTER_FRAME, onFrame);
			trace("stored " + slotStr.length);
		}

		private function onCustom(e:Event):void {
			trace("custom " + e.type);
		}

		private function onFrame(e:Event):void {
			tick++;
			if (tick < 3) {
				// Cross the 4 MB GC watermark with throwaway concat garbage so
				// a real collect runs between ticks even in DEFAULT mode (not
				// just under AVM2_GC_STRESS=1) before the re-reads below.
				var junk:String = "";
				for (var j:int = 0; j < 400; j++) {
					junk += "0123456789012345678901234567890123456789";
				}
				return;
			}
			trace("slot=" + slotStr);
			trace("arr=" + arr[0]);
			trace("dyn=" + dyn[key]);
			for (var k:String in dyn) trace("enumkey=" + k);
			trace("dict=" + dict["ABCDEFGHIJKLMNOPQRSTUVWXYZ-dictkey"]);
			trace("xml=" + xml.c.toString());
			dispatchEvent(new Event("evt-ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
			removeEventListener(Event.ENTER_FRAME, onFrame);
			trace("done");
		}
	}
}
