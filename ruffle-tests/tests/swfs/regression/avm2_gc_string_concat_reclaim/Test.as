// GC collectable strings (avm2_gc.c string census): loop-concat builds a
// large string across several frames, leaving quadratic intermediate
// concat garbage the collector reclaims between ticks. A sweep bug that
// frees the live accumulator (or the final string's bytes) corrupts the
// traced length/slices; under AVM2_GC_STRESS=1 (the CI avm2_gc=1 input) a
// collect runs before every tick, so any such bug fires deterministically.
//
// Build: see build_swf.sh (mxmlc).
package {
	import flash.display.MovieClip;
	import flash.events.Event;

	public class Test extends MovieClip {
		private var tick:int = 0;
		private var acc:String = "";

		public function Test() {
			trace("start");
			addEventListener(Event.ENTER_FRAME, onFrame);
		}

		private function onFrame(e:Event):void {
			tick++;
			if (tick > 5) return;
			// 50-char chunk, 200 appends per frame: every += abandons the
			// previous accumulation as census garbage.
			var chunk:String = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMN";
			for (var i:int = 0; i < 200; i++) {
				acc += chunk;
			}
			trace("tick " + tick + " len=" + acc.length);
			if (tick == 5) {
				trace("head=" + acc.substr(0, 12));
				trace("tail=" + acc.substr(acc.length - 12, 12));
				trace("charAt=" + acc.charAt(31337));
				trace("done");
			}
		}
	}
}
