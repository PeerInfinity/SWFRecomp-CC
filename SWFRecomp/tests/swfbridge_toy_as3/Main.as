// swfbridge_toy_as3 — AS3/AVM2 ExternalInterface toy for the __swfBridge
// livetest (the AVM2 counterpart of ../swfbridge_toy/Main.as, exercising the
// BridgeGeneric-shaped contract instead of the AVM1 pull contract).
//
// Surfaces exercised (exactly the injected-BridgeGeneric usage):
//   outward  ExternalInterface.call: console.log(msg),
//            stateChanged(pname, pvalue)   — 2 args, typed value (variadic),
//            getItemQueue()                — JSON-string return, drained
//   inbound  ExternalInterface.addCallback: wireCheck / configure / readState
//            (string-in/string-out via the avm2_ei_dispatch funnel)
//
// Flow: constructor checks available, registers the three callbacks, then an
// ENTER_FRAME loop polls getItemQueue until the mock host's sword + key both
// arrive and apply; every applied effect reports back via stateChanged.
//
// Build (AS3 — mxmlc, not MTASC; -omit-trace-statements=false keeps trace()):
//   ~/CC/flex-sdk/bin/mxmlc -omit-trace-statements=false -target-player=11.1 \
//     -static-link-runtime-shared-libraries=true -default-size 200 150 \
//     -default-frame-rate 30 -output test.swf Main.as
// (run_toy_livetest.sh does this, then recompiles + builds the AVM2 wasm.)
package {
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.external.ExternalInterface;

	public class Main extends Sprite {
		private var configured:Boolean = false;
		private var attackEnabled:Boolean = false;
		private var doorUnlocked:Boolean = false;
		private var frames:int = 0;
		private var done:Boolean = false;

		public function Main() {
			trace("[toy] boot, EI available=" + ExternalInterface.available);
			if (!ExternalInterface.available) return;
			ExternalInterface.call("console.log",
				"[toy] EI available=" + ExternalInterface.available);

			var self:Main = this;
			ExternalInterface.addCallback("wireCheck", function():String {
				return "ok";
			});
			ExternalInterface.addCallback("configure", function(json:String):String {
				self.configured = true;
				ExternalInterface.call("console.log", "[toy] configured: " + json);
				return "ok";
			});
			ExternalInterface.addCallback("readState", function():String {
				return '{"attackEnabled":' + self.attackEnabled +
					',"doorUnlocked":' + self.doorUnlocked +
					',"frames":' + self.frames + '}';
			});
			addEventListener(Event.ENTER_FRAME, onFrame);
		}

		private function onFrame(e:Event):void {
			frames++;
			if (!configured || done) return;

			// Poll the host's item queue (JSON array, drained on read — the
			// BridgeGeneric per-frame pattern).
			var q:* = ExternalInterface.call("getItemQueue");
			if (q != null && q != "" && q != "[]") {
				var items:Array = JSON.parse(String(q)) as Array;
				if (items != null) {
					for (var i:int = 0; i < items.length; i++) {
						applyItem(items[i]);
					}
				}
			}

			if (attackEnabled && doorUnlocked && !done) {
				done = true;
				ExternalInterface.call("console.log", "[toy] DONE");
			}
		}

		private function applyItem(it:*):void {
			var name:String = (it is String) ? String(it) : String(it["item"]);
			if (name == "sword" && !attackEnabled) {
				attackEnabled = true;
				ExternalInterface.call("console.log",
					"[toy] apply: sword -> attack enabled");
				// 2-arg outward call with a typed (boolean) value — the AVM2
				// variadic surface AVM1's 1-arg handler couldn't do.
				ExternalInterface.call("stateChanged", "attackEnabled", true);
			} else if (name == "key" && !doorUnlocked) {
				doorUnlocked = true;
				ExternalInterface.call("console.log",
					"[toy] apply: key -> door unlocked");
				ExternalInterface.call("stateChanged", "doorUnlocked", true);
			}
		}
	}
}
