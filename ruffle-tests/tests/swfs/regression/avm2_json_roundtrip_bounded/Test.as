// Memory-bounded JSON round-trips (seedling-wasm-leak L2). JSON.stringify
// never freed its string builder, cycle stack or PropList, and JSON.parse
// leaked its whole intermediate tree plus a per-string scratch sized to the
// REST of the input — a few KB to tens of KB per call that no GC reclaims.
// test_env.json pins a small arena (SWF_HEAP_MB): with the leak, these
// 4,800 calls exhaust it and the run dies before "done"; fixed, every
// tick's garbage is collected and the floor stays flat. Also locks the
// scratch-freeing exits: a throwing replacer, toJSON, reviver, a cycle
// (#1129) and a syntax error (#1132) each rethrow the SAME value.
//
// Build: see build_swf.sh (mxmlc).
package {
	import flash.display.MovieClip;
	import flash.events.Event;

	public class Test extends MovieClip {
		private var tick:int = 0;
		private var check:Number = 0;

		public function Test() {
			trace("start");
			errors();
			addEventListener(Event.ENTER_FRAME, onFrame);
		}

		private function payload(k:int):Object {
			var o:Object = { id: k, name: "room_" + k, flags: [true, false, null],
			                 pos: { x: k * 1.5, y: -k, z: "é中😀" } };
			var items:Array = [];
			for (var i:int = 0; i < 40; i++) {
				items.push({ slot: i, label: "item number " + i + " of room " + k,
				             tag: "esc\"aped\\\n" + i });
			}
			o.items = items;
			return o;
		}

		private function errors():void {
			var marker:Object = { why: "marker" };
			try { JSON.stringify({ a: 1 }, function (k:String, v:*):* { if (k == "a") throw marker; return v; }); }
			catch (e:*) { trace("replacer rethrows same: " + (e === marker)); }
			try { JSON.stringify({ a: { toJSON: function (k:String):* { throw marker; } } }); }
			catch (e:*) { trace("toJSON rethrows same: " + (e === marker)); }
			try { JSON.parse("{\"a\":[1,2,{\"b\":\"x\"}]}", function (k:String, v:*):* { if (k == "b") throw marker; return v; }); }
			catch (e:*) { trace("reviver rethrows same: " + (e === marker)); }
			var cyc:Object = { n: 1 }; cyc.self = cyc;
			try { JSON.stringify(cyc); } catch (e:Error) { trace("cycle: " + e.errorID); }
			try { JSON.parse("{\"a\":\"unterminated"); } catch (e:Error) { trace("syntax: " + e.errorID); }
			try { JSON.parse("[1,2,]"); } catch (e:Error) { trace("syntax2: " + e.errorID); }
			trace("long string: " + JSON.parse("[\"" + new Array(2001).join("ab") + "\"]")[0].length);
		}

		private function onFrame(e:Event):void {
			tick++;
			if (tick > 120) return;
			for (var i:int = 0; i < 40; i++) {
				var s:String = JSON.stringify(payload(i));
				var back:Object = JSON.parse(s);
				check += back.items[39].slot + back.pos.y + back.name.length;
			}
			if (tick % 40 == 0) trace("tick " + tick + " check=" + check + " len=" + s.length);
			if (tick == 120) {
				var p:Object = JSON.parse(s).pos;
				trace("sample=" + p.x + " " + p.y + " " + p.z);
				trace("done");
			}
		}
	}
}
