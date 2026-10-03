// Memory-bounded Array/Vector growth (seedling-wasm-leak L2). Every element
// buffer growth (array_reserve, Array unshift/splice/insertAt, vec_reserve)
// allocated the bigger buffer and never freed the old one, so a growing
// array leaked about its own final size in dead buffers even after the
// array itself was collected. test_env.json pins a small arena
// (SWF_HEAP_MB): with the leak these loops exhaust it and the run dies
// before "done"; fixed, the floor stays flat. Also checks contents survive
// every growth path (old buffer freed AFTER the copy).
//
// Build: see build_swf.sh (mxmlc).
package {
	import flash.display.MovieClip;
	import flash.events.Event;

	public class Test extends MovieClip {
		private var tick:int = 0;
		private var sum:Number = 0;
		private var keep:Array = [];

		public function Test() {
			trace("start");
			addEventListener(Event.ENTER_FRAME, onFrame);
		}

		private function onFrame(e:Event):void {
			tick++;
			if (tick > 120) return;
			for (var r:int = 0; r < 3; r++) {
				var a:Array = [];
				for (var i:int = 0; i < 6000; i++) a.push(i);
				var u:Array = [];
				for (i = 0; i < 300; i++) u.unshift(i);
				var s:Array = [0];
				for (i = 0; i < 300; i++) s.splice(1, 0, i, i);
				var ins:Array = [];
				for (i = 0; i < 300; i++) ins.insertAt(0, i);
				var v:Vector.<int> = new Vector.<int>();
				for (i = 0; i < 6000; i++) v.push(i);
				var vo:Vector.<Object> = new Vector.<Object>();
				for (i = 0; i < 2000; i++) vo[vo.length] = { k: i };
				sum += a[5999] + u[0] + s[600] + ins[0] + v[5999] + vo[1999].k
				     + a.length + u.length + s.length + ins.length + v.length + vo.length;
			}
			// One array that lives across ticks and keeps growing.
			for (i = 0; i < 100; i++) keep.push(tick * 1000 + i);
			if (tick % 40 == 0) trace("tick " + tick + " sum=" + sum + " keep=" + keep.length
			                          + " first=" + keep[0] + " last=" + keep[keep.length - 1]);
			if (tick == 120) trace("done");
		}
	}
}
