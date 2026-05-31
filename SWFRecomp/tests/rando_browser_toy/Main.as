// Main.as — single-SWF browser item-application toy (Phase 3 Slice 2b).
//
// The browser counterpart of _rando/rando_item_application: it exercises the
// SAME item-application glue (config-driven id->flash_name->effect mapping,
// per-frame polling, event->location check), but LIVE against a real APQuest
// server in a real browser, where the graphics WASM loop paces frames in real
// time and ASYNCIFY lets the WebSocket connect.
//
// Single SWF (build_test.sh has no prelude mechanism) — the glue + the
// "game" live together here. Built as a GRAPHICS wasm demo so the runtime uses
// the real-time-paced render loop:
//   WITH_AP=1 SWFRecomp/scripts/build_test.sh rando_browser_toy wasm --graphics
//
// Connection is ASYNC (the Rando WASM bridge -> archipelago.js WebSocket), so we
// can't use the synchronous connect-then-read shape of the stub toy. Instead an
// onEnterFrame state machine waits for isConnected(), fires the two location
// checks once, and polls received items each frame, applying effects as they
// arrive. APQuest seed-1 fixture (live-confirmed): Top Middle Chest (loc 2)
// grants Sword (item 2); Right Room Enemy Drop (loc 10) grants Key (item 1).
// archipelago.js does NOT filter own-location items, so both appear in-browser.
//
// The headed-chrome harness (../../../ruffle-tests/tests/swfs/_rando/livetest/
// toy_browser/run_toy_livetest.sh) asserts the "[toy] DONE" console line.

class Main {
	static function main() {
		_global.gameState = { canAttack: false, doorUnlocked: false };

		var rg:Object = {};
		rg.rando = new Rando("127.0.0.1", "38281", "APQuest", "Player1", "");
		rg.appliedCount = 0;
		rg.checksSent = false;

		// Config: the ITEM/LOCATION "enums" (APQuest, ap_id_offset 0).
		rg.ap_items = {};
		rg.ap_items[2] = "sword";                 // ap id -> flash_name
		rg.ap_items[1] = "key";
		rg.ap_locations = { top_middle_chest: 2, enemy_drop: 10 };

		rg.applyEffect = function(flash_name:String):Void {
			if (flash_name == "sword") {
				_global.gameState.canAttack = true;
				trace("apply: sword -> attack enabled");
			} else if (flash_name == "key") {
				_global.gameState.doorUnlocked = true;
				trace("apply: key -> door unlocked");
			} else {
				trace("apply: unknown flash_name " + flash_name);
			}
		};

		// Per-frame poll: apply any items received since the last call.
		rg.applyItems = function():Void {
			var n:Number = this.rando.receivedItemsSize();
			var i:Number = this.appliedCount;
			while (i < n) {
				var id:Number = this.rando.receivedItem(i);
				var flash_name = this.ap_items[id];
				if (flash_name != undefined) {
					this.applyEffect(flash_name);
				}
				i++;
			}
			this.appliedCount = n;
		};

		_global.rg = rg;

		rg.rando.connect();   // async; returns immediately
		trace("[toy] connecting to 127.0.0.1:38281 as APQuest/Player1 ...");

		// State machine driven by the real-time render loop.
		_root.onEnterFrame = function():Void {
			var g = _global.rg;
			if (!g.rando.isConnected()) {
				return;   // still connecting — wait for a later frame
			}
			if (!g.checksSent) {
				trace("[toy] connected; sending location checks (Top Middle Chest, Enemy Drop)");
				g.rando.sendLocation(g.ap_locations.top_middle_chest);
				g.rando.sendLocation(g.ap_locations.enemy_drop);
				g.checksSent = true;
			}
			g.applyItems();
			if (_global.gameState.canAttack && _global.gameState.doorUnlocked) {
				trace("[toy] DONE: canAttack=" + _global.gameState.canAttack
				      + " doorUnlocked=" + _global.gameState.doorUnlocked);
				delete _root.onEnterFrame;
			}
		};
	}
}
