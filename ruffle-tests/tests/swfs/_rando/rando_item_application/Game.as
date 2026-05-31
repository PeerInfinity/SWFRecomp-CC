// Game.as — the Archipelago-NAIVE toy game, compiled into test.swf. It knows
// nothing about Archipelago item/location numbers: it only reads _global.gameState
// and calls _global.rg (the glue installed by the prelude). Stands in for a real
// game whose loop polls for granted items each frame and reports events that map
// to location checks.
//
// Scenario (driven by the synthetic RANDO_STUB backend):
//   1. connect (in the prelude) delivered the starting Sword -> applyItems
//      enables attack.
//   2. the player "reaches the chest" -> rg.check sends location 100, the stub
//      grants the Key.
//   3. next poll -> applyItems applies the Key -> door unlocked.

class Game {
	static function main() {
		var rg = _global.rg;

		trace("[game] start; canAttack=" + _global.gameState.canAttack);

		// Frame tick 1: apply items received so far (the starting Sword).
		rg.applyItems();
		trace("[game] after tick 1; canAttack=" + _global.gameState.canAttack);

		// In-game event: reach the chest -> location check.
		trace("[game] reached chest -> check(bottom_left_chest)");
		rg.check("bottom_left_chest");
		trace("[game] chest checked=" + rg.rando.locationIsChecked(100));

		// Frame tick 2: apply items received since (the granted Key).
		rg.applyItems();
		trace("[game] after tick 2; doorUnlocked=" + _global.gameState.doorUnlocked);
	}
}
