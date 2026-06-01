// Main.as — LIVE native test of the __swfBridge contract over a real Archipelago
// server (APCpp backend). The live sibling of swfbridge_native_stub: same EI
// __swfBridge calls, same native handler (swf_bridge_native_external_call), but
// WITH_AP=1 (APCpp) connecting to a local ChecksFinder seed-1 server instead of
// the synthetic stub.
//
// The native handler blocks until APCpp authenticates before the first frame
// runs (see sbn_load_config in action.c), so this frame-based SWF can drive the
// round-trip synchronously despite native's flat-out frame loop.
//
// What this asserts: the OUTWARD round-trip — report an objective via
// __swfSendLocation, then confirm the AP server checked it via __swfLocationChecked
// (which polls the backend until the async ack lands). This is the path that
// demonstrably round-trips over APCpp in a solo seed. The INWARD item path is NOT
// asserted here: APCpp filters the player's own-location item grants out of
// received_items, and the current ChecksFinder seed delivers no starting
// inventory, so __swfPoll has nothing observable to apply in a solo seed (the
// real substrate's host observes received items instead). See the run script +
// the reconciliation note's native-convergence section.
//
// Driven by ../livetest/run_swfbridge_native_livetest.sh, which starts the server
// and runs this under WITH_AP=1 verify_output.py against output.txt.

class Main {
	static function main() {
		var EI:Object = flash.external.ExternalInterface;
		trace("EI available=" + EI.available);

		var cfg:String = String(EI.call("__swfConfig"));
		trace("config nonempty=" + (cfg.length > 0));

		// Outward round-trip: report an objective (maps to AP location 81001,
		// Tile 2), then confirm the server checked it (connection-dependent).
		trace("send tile2");
		EI.call("__swfSendLocation", "tile2");
		trace("tile2 checked=" + String(EI.call("__swfLocationChecked", "tile2")));

		trace("DONE");
	}
}
