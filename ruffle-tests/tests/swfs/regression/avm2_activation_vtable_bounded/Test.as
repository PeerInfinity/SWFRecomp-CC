// Memory-bounded per-call activation vtables (swfrecomp-seedling-frame-leak).
// A method that needs an activation object (here: a closure captures its
// locals) gets a fresh per-call vtable from newactivation. Building it grows
// the entries/metas arrays past their first capacity of 8, and every growth
// dropped the old array without freeing it: ~2 KB of native heap per call,
// outside the GC census. Seedling's injected BridgeGeneric.resolvePath runs
// 21 times a frame, so the recompiled game leaked ~70 KB/frame and filled its
// 512 MiB arena in ~3 minutes, frozen or not. test_env.json pins a small arena
// (SWF_HEAP_MB): with the leak the loop exhausts it before "done"; fixed, the
// floor stays flat. Also checks the captured values and a catch scope.
//
// Build: see build_swf.sh (mxmlc).
package {
	import flash.display.MovieClip;
	import flash.events.Event;

	public class Test extends MovieClip {
		private var tick:int = 0;
		private var sum:Number = 0;
		private var caught:int = 0;

		public function Test() {
			trace("start");
			addEventListener(Event.ENTER_FRAME, onFrame);
		}

		// Twelve locals captured by the closure → twelve activation slots,
		// past the vtable's initial capacity of 8.
		private function wide(k:int):int {
			var a:int = k, b:int = k + 1, c:int = k + 2, d:int = k + 3;
			var e:int = k + 4, f:int = k + 5, g:int = k + 6, h:int = k + 7;
			var i:int = k + 8, j:int = k + 9, l:int = k + 10, m:int = k + 11;
			var add:Function = function ():int {
				return a + b + c + d + e + f + g + h + i + j + l + m;
			};
			return add();
		}

		private function guarded(k:int):int {
			try {
				if (k % 7 == 0) throw new Error("seven");
				return k;
			} catch (err:Error) {
				caught++;
			}
			return 0;
		}

		private function onFrame(ev:Event):void {
			tick++;
			if (tick > 120) return;
			for (var r:int = 0; r < 400; r++) {
				sum += wide(r) + guarded(r);
			}
			if (tick % 40 == 0) trace("tick " + tick + " sum=" + sum + " caught=" + caught);
			if (tick == 120) trace("done");
		}
	}
}
