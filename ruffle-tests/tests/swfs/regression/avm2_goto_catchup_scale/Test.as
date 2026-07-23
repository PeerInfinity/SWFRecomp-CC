package {
	import flash.display.MovieClip;
	import flash.events.Event;

	// Regression for the AVM2 goto catch-up walk gate (Elephant Quest EQ-4,
	// plan gap #2b).
	//
	// Every explicit AVM2 goto runs a full stage + orphan catch-up pass
	// (Ruffle frame_lifecycle.rs run_inner_goto_frame, mirrored by
	// avm2_display.c avm2_display_inner_goto_frame). The loop below is shaped
	// exactly like Elephant Quest's Level.initTiles — create a clip, attach
	// it, goto it, detach some of them again — so before the walk gate each
	// iteration re-walked every clip built so far AND the whole (never
	// shrinking) orphan list: O(n^2). EQ's ~4000-tile level never finished;
	// this loop took minutes.
	//
	// With the gate (walk_clean / dirty_kids / the dirty-orphan candidate
	// list) a goto only touches subtrees that actually have pending work, so
	// this completes in well under the harness' 30 s run timeout. The trace
	// is also the semantic gate: the detach/attach bookkeeping must still be
	// exact, and enterFrame must keep firing AFTER the gate has certified the
	// whole tree quiescent (a stale certificate would freeze the timeline).
	public class Test extends MovieClip {
		private static const NA:int = 8000;
		private static const NB:int = 3000;
		private var ticks:int = 0;

		public function Test() {
			// Loop A — parentless clips. Every AVM2 goto also walks the whole
			// orphan list (Ruffle each_orphan_obj), and clips detached or
			// never attached by ActionScript stay on it for good, so this is
			// the shape that made Elephant Quest's init2 quadratic.
			for (var a:int = 0; a < NA; a++) {
				var o:MovieClip = new MovieClip();
				o.addChild(new MovieClip());
				o.addChild(new MovieClip());
				gotoAndStop(1);
			}
			// Loop B — attach / goto / detach, the Level.initTiles shape:
			// exercises the container bookkeeping (a freshly attached child
			// must still be found and constructed even though its siblings
			// are certified quiescent).
			var box:MovieClip = new MovieClip();
			addChild(box);
			var kept:int = 0;
			for (var i:int = 0; i < NB; i++) {
				var t:MovieClip = new MovieClip();
				box.addChild(t);
				// The goto must be on a clip that HAS a timeline (the root):
				// a timeline-less `new MovieClip()` never reaches run_goto.
				// Landing on the frame we are already on is the AVM2 "no-op
				// goto", which still runs the full catch-up (Ruffle
				// MovieClip::no_op_goto -> run_inner_goto_frame).
				gotoAndStop(1);
				if ((i & 1) == 0) {
					box.removeChild(t);   // becomes a permanent orphan
				} else {
					kept++;
				}
			}
			trace("built kept=" + kept + " children=" + box.numChildren);
			addEventListener(Event.ENTER_FRAME, onEnter);
		}

		private function onEnter(e:Event):void {
			ticks++;
			trace("enterFrame " + ticks);
			if (ticks == 2) {
				trace("timeline still live after catch-up gate");
			}
		}
	}
}
