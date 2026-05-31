// Phase 1 smoke test for the native Rando (Archipelago) builtin.
// Does NOT call connect() — no server, no network thread — so output is
// fully deterministic regardless of environment.
class Test {
	static function main() {
		trace(typeof Rando);
		var r:Rando = new Rando("127.0.0.1", "38281", "TestGame", "Player1", "");
		trace(typeof r);
		trace(r.isConnected());
		trace(r.receivedItemsSize());
		trace(r.hasItem(42));
		trace(r.locationIsChecked(1));
	}
}
