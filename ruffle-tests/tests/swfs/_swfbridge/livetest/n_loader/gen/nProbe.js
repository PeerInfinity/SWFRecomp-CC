// nProbe.js - calibration probe levels for measuring N's motion model on real N.
//
// Each probe is a flat full-width floor (no gaps -> no accidental death) with the
// exit far to the right, driven by a demo that: runs right for R ticks (to set an
// ENTRY horizontal speed), then jumps holding J for K ticks (variable-height),
// then keeps holding right until it walks into the exit (self-terminating so the
// batch stays fast). The per-frame arc is captured; nTelemetry extracts entry vx,
// apex height, airtime, and air distance. Sweeping R (entry momentum) x K (hold)
// maps the momentum-coupled jump envelope - the core of N's feel.
import { Level, OBJ, TILE_FULL } from "./nLevel.js";
import { encodeDemo, IN } from "./nDemo.js";

const SPAWN_X = 80;
const FLOOR_ROW = 14;
const REST_Y = 350;            // (14+1)*24 - 10
const SWITCH_X = 680;          // far right; safely past any landing point
const DOOR_X = 704;
const FLOOR_X0 = 1, FLOOR_X1 = 29;
const TAIL = 220;              // hold-right ticks after the jump to reach the exit

function flatFloorLevel() {
	const L = new Level();
	for (let mx = FLOOR_X0; mx <= FLOOR_X1; mx++) L.setTile(mx, FLOOR_ROW, TILE_FULL);
	L.addObject(OBJ.PLAYER, [SPAWN_X, REST_Y]);
	L.addObject(OBJ.EXIT, [DOOR_X, REST_Y, SWITCH_X, REST_Y]);
	return L;
}

/** Demo: R run-up ticks, K jump-hold ticks (JTRIG on the first), then hold-right. */
function runJumpDemo(R, K) {
	const seq = [];
	for (let i = 0; i < R; i++) seq.push(IN.R);
	if (K > 0) {
		seq.push(IN.R | IN.J | IN.JTRIG);
		for (let i = 1; i < K; i++) seq.push(IN.R | IN.J);
	}
	for (let i = 0; i < TAIL; i++) seq.push(IN.R);
	return encodeDemo(seq);
}

/**
 * Build the calibration probe matrix.
 *   runUps: entry-speed run-up tick counts (0 = standing jump).
 *   holds:  jump-hold tick counts (variable-height; 30 ~= max_jump_time).
 * Plus one pure run-up probe (no jump) to map the speed ramp + max speed.
 */
export function buildProbeMatrix(runUps = [0, 8, 20, 45], holds = [3, 8, 15, 30]) {
	const level = flatFloorLevel().encode();
	const probes = [];
	// Pure run-up: long hold-right, no jump -> measures vx ramp and max speed.
	probes.push({ levelId: "ramp", level, demo: encodeDemo(new Array(120).fill(IN.R)), meta: { R: 120, K: 0, kind: "ramp" } });
	for (const R of runUps) {
		for (const K of holds) {
			probes.push({ levelId: `jump-R${R}-K${K}`, level, demo: runJumpDemo(R, K), meta: { R, K, kind: "jump" } });
		}
	}
	return probes;
}
