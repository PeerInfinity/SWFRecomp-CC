// Main.as — AVM1 stand-in for flashPanel's memory-poke (readState) path-walker,
// for probing whether the host-initiated ExternalInterface.addCallback direction
// (configure-in / readState-out) survives the iframe boundary under both Ruffle
// and the SWFRecomp WASM runtime.
//
// This is the OPPOSITE EI direction from swfbridge_toy: there the game pulls
// (ExternalInterface.call -> window[name]); here the HOST calls AS-registered
// callbacks (addCallback) and reads their string return — exactly flashPanel's
// mechanism (BridgeGeneric.as registers configure/readState/wireCheck the same
// way; that one is AS3/AVM2, which SWFRecomp can't run yet, so this is an AVM1
// stand-in per the probe brief — the stub result is the load-bearing answer).
//
// readState returns a realistic multi-field nested JSON with mixed types and a
// non-ASCII field (UTF round-trip on the OUT direction); configure echoes the
// received config back (strongest integrity check for the IN direction: size +
// encoding) and records its length so readState can confirm the full arg landed.
//
// Built as a graphics WASM (the frame loop must keep running so the host can
// call swf_ei_call_internal between frames) and also compiled to test.swf for
// the Ruffle harness. Needs the SWFRecomp EI handler installed, which the game
// page triggers by exposing window.__swfBridge (addCallback no-ops otherwise);
// under Ruffle, allowScriptAccess gates EI.available instead.

class Main {
	static function main() {
		var EI:Object = flash.external.ExternalInterface;
		var available:Boolean = EI.available;
		trace("[mem] EI available=" + available);
		if (!available) {
			trace("[mem] EI NOT available — cannot register callbacks");
			return;
		}

		_global.memState = { cfg: "", cfgLen: 0 };

		// Hold the callback functions on _global so they outlive main()'s scope —
		// in the NO_GRAPHICS WASM build runSWF() returns after the movie's bounded
		// tick loop, and the host calls these afterward; _global persists and keeps
		// them alive regardless of GC. (Under Ruffle / graphics they'd stay alive
		// anyway; this is belt-and-braces for the returned-runSWF case.)
		_global.memCb = {};

		_global.memCb.wire = function():String {
			return "ok";
		};

		_global.memCb.cfg = function(json:String):String {
			_global.memState.cfg = json;
			_global.memState.cfgLen = (json == undefined) ? -1 : json.length;
			trace("[mem] configure received len=" + _global.memState.cfgLen);
			// Echo the full config back so the host can byte/UTF-verify integrity.
			return json;
		};

		_global.memCb.read = function():String {
			// Realistic path_reads-style result: ~10 fields, mixed types, a nested
			// object + array, and a non-ASCII label (UTF check). cfg_len reflects
			// the last configure() arg, proving the IN arg arrived whole.
			var s:String = "";
			s += "{";
			s += "\"player_x\":123,";
			s += "\"player_y\":45,";
			s += "\"hp\":100,";
			s += "\"coins\":7,";
			s += "\"boss_dead\":true,";
			s += "\"name\":\"hero\",";
			s += "\"label\":\"café→☃\",";        // "café→☃" — UTF round-trip
			s += "\"powers\":[\"jump\",\"dash\",\"double_jump\"],";
			s += "\"pos\":{\"x\":1,\"y\":2,\"z\":3},";
			s += "\"cfg_len\":" + _global.memState.cfgLen;
			s += "}";
			return s;
		};

		EI.addCallback("wireCheck", null, _global.memCb.wire);
		EI.addCallback("configure", null, _global.memCb.cfg);
		EI.addCallback("readState", null, _global.memCb.read);

		trace("[mem] callbacks registered (wireCheck/configure/readState)");
	}
}
