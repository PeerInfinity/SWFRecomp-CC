// GC dyn-prop tombstone purge: deleted dynamic props leave tombstone nodes
// (kept for mid-iteration enumeration stability); the collector purges them
// from LIVE objects between ticks. This locks the trace-visible semantics
// the purge must preserve:
//   - delete → re-add appends at the END of for-in order (fresh node), and
//     that order is IDENTICAL before and after a collect purges the
//     tombstone (the purge only removes never-enumerated dead nodes);
//   - a delete DURING for-in doesn't shift the iteration (the tombstone's
//     whole purpose) — and iteration the tick AFTER a purge re-derives the
//     cursor correctly (obj->dyn_enum_pos is reset by the purge);
//   - values/names survive repeated delete/re-add cycles across collects.
// Under AVM2_GC_STRESS=1 a collect (and purge) runs before every tick.
//
// Build: see build_swf.sh (mxmlc).
package {
	import flash.display.MovieClip;
	import flash.events.Event;

	public class Test extends MovieClip {
		private var tick:int = 0;
		private var obj:Object = {};

		public function Test() {
			obj.a = "A1";
			obj.b = "B1";
			obj.c = "C1";
			obj.d = "D1";
			// delete + re-add in the same tick: b moves to the end.
			delete obj.b;
			obj.b = "B2";
			dumpOrder("t0");
			addEventListener(Event.ENTER_FRAME, onFrame);
		}

		private function dumpOrder(tag:String):void {
			var s:String = "";
			for (var k:String in obj) s += k + "=" + obj[k] + " ";
			trace(tag + ": " + s);
		}

		private function churn():void {
			// Cross the 4 MB GC watermark with throwaway concat garbage so a
			// real collect (and tombstone purge) runs between ticks even in
			// DEFAULT mode, not just under AVM2_GC_STRESS=1.
			var junk:String = "";
			for (var j:int = 0; j < 400; j++) {
				junk += "0123456789012345678901234567890123456789";
			}
		}

		private function onFrame(e:Event):void {
			tick++;
			if (tick == 1) {
				// Order after the between-tick collect purged t0's tombstone:
				// must match t0 exactly.
				dumpOrder("t1");
				// Delete mid-iteration: iteration must not shift.
				var seen:String = "";
				for (var k:String in obj) {
					if (k == "c") delete obj.d;
					seen += k + " ";
				}
				trace("t1-mid: " + seen);
				obj.d = "D2";
				dumpOrder("t1b");
				churn();
			} else if (tick == 2) {
				// Cursor was reset by the purge; a fresh iteration works.
				dumpOrder("t2");
				// Several delete/re-add cycles on one key.
				for (var i:int = 0; i < 5; i++) {
					delete obj.a;
					obj.a = "A" + (i + 3);
				}
				dumpOrder("t2b");
				churn();
			} else if (tick == 3) {
				dumpOrder("t3");
				removeEventListener(Event.ENTER_FRAME, onFrame);
				trace("done");
			}
		}
	}
}
