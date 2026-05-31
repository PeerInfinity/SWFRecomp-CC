// Prelude.as — the Archipelago-AWARE glue, compiled into prelude_rando.swf and
// recompiled BEFORE the game (test.swf). It installs `_global.rg`, the glue
// object, and owns the single Rando instance. The game never touches Rando
// directly — it only calls _global.rg methods. This is the AP-naive / AP-aware
// split (the game is naive; all AP knowledge lives here).
//
// Mapping is config-driven, in the flashPanel ap_items/ap_locations shape:
//   ap_items     : AP item id   -> game-meaningful "flash_name"
//   ap_locations : flash_name    -> AP location id
// (offset-free toy id space; the live Slice-2 test adds ap_id_offset.) Item
// application is per-frame POLLING: the game calls rg.applyItems() each "tick";
// applyItems walks newly-received items and applies their effect once.
//
// Phase 3 Slice 1b, driven by the synthetic RANDO_STUB backend (which on
// connect delivers item 2 = "Sword", and on checking location 100 grants
// item 1 = "Key"). See
// SWFRecompDocs/plans/archipelago-phase3-substrate-and-item-application.md.

class Prelude {
	static function main() {
		// Game state the glue mutates as items are applied. Owned at _global so
		// the (separately compiled) game SWF reads the same object.
		_global.gameState = { canAttack: false, doorUnlocked: false };

		var rg:Object = {};
		rg.rando = new Rando("127.0.0.1", "38281", "APQuest", "Player1", "");
		rg.appliedCount = 0;

		// Config: the ITEM/LOCATION "enums". ap_items is keyed by ap item id
		// (built imperatively — MTASC object literals don't allow numeric keys);
		// obj[id] coerces the Number id to a string key.
		rg.ap_items = {};
		rg.ap_items[2] = "sword";                         // ap id -> flash_name
		rg.ap_items[1] = "key";
		rg.ap_locations = { bottom_left_chest: 100 };     // flash_name -> ap id

		// Apply one item's effect by its flash_name (the per-game item->effect map).
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
				} else {
					trace("apply: no mapping for ap item " + id);
				}
				i++;
			}
			this.appliedCount = n;
		};

		// A game event that maps to an AP location check.
		rg.check = function(flash_name:String):Void {
			var id = this.ap_locations[flash_name];
			if (id == undefined) {
				trace("check: no mapping for location " + flash_name);
				return;
			}
			this.rando.sendLocation(id);
		};

		_global.rg = rg;

		// Connect via the stub (synchronous: starting items delivered now).
		rg.rando.connect();
		trace("[prelude] glue ready; connected=" + rg.rando.isConnected()
		      + "; starting items=" + rg.rando.receivedItemsSize());
	}
}
