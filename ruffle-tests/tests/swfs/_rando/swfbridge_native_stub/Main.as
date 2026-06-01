// Main.as — deterministic native test of the __swfBridge contract over the
// runtime's NATIVE ExternalInterface handler (swf_bridge_native_external_call in
// action.c), backed by the synthetic rando_ap stub (RANDO_STUB=1).
//
// This is the EI-based sibling of rando_item_application: it exercises the SAME
// item-application / objective-reporting glue, but through the unified
// __swfBridge cooperative contract (the interface used by WASM + Ruffle) instead
// of the native `Rando` builtin class. The game's AS deals only in flash_names;
// the native handler owns the flash_name <-> AP-id maps (loaded from
// swf_bridge_config.json) and routes to the rando_ap.h backend — exactly as
// swf_bridge.js does in the browser, ported to C.
//
// Scenario (synthetic RANDO_STUB backend): connect() delivers item 2 -> "sword";
// reporting flash_name "chest" maps to AP location 100, which the stub grants as
// item 1 -> "key".
//
//   $ RANDO_STUB=1 python3 ruffle-tests/verify_output.py \
//         --test=_rando/swfbridge_native_stub --diff --verbose

class Main {
	static function main() {
		// Untyped reference so the variadic AVM1 ExternalInterface.call isn't
		// rejected by MTASC's 1-arg intrinsic signature.
		var EI:Object = flash.external.ExternalInterface;
		trace("EI available=" + EI.available);

		var cfg:String = String(EI.call("__swfConfig"));
		trace("config nonempty=" + (cfg.length > 0));

		// Items received on connect (the stub's starting Sword).
		Main.applyPoll(EI);

		// In-game objective complete -> report its flash_name (maps to AP loc 100,
		// which the stub grants as the Key).
		trace("send chest");
		EI.call("__swfSendLocation", "chest");

		// Poll again: the granted Key is now available.
		Main.applyPoll(EI);

		trace("DONE");
	}

	static function applyPoll(EI:Object):Void {
		var pulled:String = String(EI.call("__swfPoll"));
		if (pulled != "" && pulled != "undefined" && pulled != "null") {
			var names:Array = pulled.split(",");
			for (var i:Number = 0; i < names.length; i++) {
				trace("apply: " + names[i]);
			}
		}
	}
}
