// Main.as — Mode-1 cooperative AVM1 minigame for the converged SWFRecomp
// Archipelago substrate. The production counterpart of rando_browser_toy: it
// exercises the SAME item-application / objective-reporting glue, but over the
// window.__swfBridge contract via ExternalInterface (the proven injected-AS
// seam) instead of the native `Rando` builtin — so it needs no WITH_AP, no
// WebSocket, and no AP server. The host (Archipelago-CC's iframe bridge.js, or
// the headed-Chrome test harness) drives it through __swfBridge.
//
// Plan-of-record:
//   ~/CC/Archipelago-CC/NewDocs/plans/procedural-generation/swfrecomp-substrate-converged.md
//   SWFRecompDocs/plans/archipelago-phase3-slice3-reconciliation.md
//
// Contract, from the game's side (all via ExternalInterface.call → window[name]):
//   __swfConfig()                 → JSON config payload (gameId/params/ap_*).
//   __swfSendLocation(flashName)  → report an objective completion (outward).
//   __swfPoll()                   → comma-separated flash_names received since
//                                   the last poll (inward pull; '' when empty).
//
// Built as a GRAPHICS wasm demo: the graphics swf.c loop is the only runtime
// that paces frames in real time (emscripten_sleep + ASYNCIFY), which lets the
// host deliver items asynchronously between frames — exactly the live model.
//   SWFRecomp/scripts/build_test.sh swfbridge_toy wasm --graphics
//
// The headed-Chrome harness (ruffle-tests/tests/swfs/_swfbridge/livetest/
// toy_browser/run_toy_livetest.sh) asserts the "[toy] DONE" console line.

class Main {
	static function main() {
		_global.gameState = { canAttack: false, doorUnlocked: false };

		// Untyped reference so the variadic AVM1 ExternalInterface.call (1 OR 2
		// args here) isn't rejected by MTASC's 1-arg intrinsic signature.
		var EI:Object = flash.external.ExternalInterface;
		var available:Boolean = EI.available;
		trace("[toy] EI available=" + available);

		// Inward pull: read the Mode-1 config once (gameId / params / maps). The
		// substrate owns flash_name -> AP location name; the game just logs it.
		var cfg:String = String(EI.call("__swfConfig"));
		trace("[toy] config=" + cfg);

		_global.tg = { ei: EI, checksSent: false };

		// State machine paced by the real-time render loop.
		_root.onEnterFrame = function():Void {
			var g = _global.tg;

			if (!g.checksSent) {
				// Outward (cooperative AS->JS): report the two in-game objectives
				// by their native flash_names. The host maps them to AP locations.
				trace("[toy] sending location checks (chest, enemy)");
				g.ei.call("__swfSendLocation", "chest");
				g.ei.call("__swfSendLocation", "enemy");
				g.checksSent = true;
			}

			// Inward pull: apply any flash_names received since the last frame.
			var pulled:String = String(g.ei.call("__swfPoll"));
			if (pulled != "" && pulled != "undefined" && pulled != "null") {
				var names:Array = pulled.split(",");
				for (var i:Number = 0; i < names.length; i++) {
					var nm:String = names[i];
					if (nm == "sword") {
						_global.gameState.canAttack = true;
						trace("apply: sword -> attack enabled");
					} else if (nm == "key") {
						_global.gameState.doorUnlocked = true;
						trace("apply: key -> door unlocked");
					} else if (nm != "") {
						trace("apply: unknown flash_name " + nm);
					}
				}
			}

			if (_global.gameState.canAttack && _global.gameState.doorUnlocked) {
				trace("[toy] DONE: canAttack=" + _global.gameState.canAttack
				      + " doorUnlocked=" + _global.gameState.doorUnlocked);
				delete _root.onEnterFrame;
			}
		};
	}
}
