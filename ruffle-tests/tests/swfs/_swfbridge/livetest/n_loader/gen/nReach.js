// nReach.js - reachability planning over the measured motion model (nMotion).
// For P2 #1 (same-level gaps) the reachability question is "can the ninja run up
// and clear this pit?", answered by construction-by-simulation: simulate the
// run-up with the real ramp, read the entry speed at the takeoff edge, pick the
// smallest measured jump-hold whose air distance clears the gap, and emit the
// exact demo that does it (the demo IS the solving proof; Ruffle is the judge).
import { runStep, airDist, MODEL } from "./nMotion.js";
import { encodeDemo, IN } from "./nDemo.js";

/**
 * Plan a run-and-jump over a same-level gap.
 *   spawnX  : player start x (px)
 *   launchX : x of the takeoff edge (right edge of the takeoff platform, px)
 *   gapPx   : horizontal distance that must be cleared (px)
 * opts: margin (clearance safety px, default 36), lead (jump this many px before
 *   the edge so takeoff is grounded, default 8), tail (hold-right ticks after the
 *   jump to walk into the exit, default 160).
 * Returns { demo, entryVx, K, ok, jumpTick, need, reach }. ok=false means no
 * measured hold clears it (still returns a best-effort demo for the Ruffle gate).
 */
export function planRunJump(spawnX, launchX, gapPx, opts = {}) {
	const margin = opts.margin != null ? opts.margin : 36;
	const lead = opts.lead != null ? opts.lead : 8;
	const tail = opts.tail != null ? opts.tail : 160;

	// Simulate the run-up (hold right) until just before the takeoff edge.
	let x = spawnX, vx = 0, t = 0;
	while (x < launchX - lead && t < 800) { vx = runStep(vx); x += vx; t++; }
	const entryVx = vx;

	// Smallest measured hold whose air distance clears the gap + margin.
	const need = gapPx + margin;
	let K = null;
	for (const k of MODEL.holds) { if (airDist(entryVx, k) >= need) { K = k; break; } }
	const ok = K != null;
	if (!ok) K = MODEL.holds[MODEL.holds.length - 1]; // best effort (widest jump)

	const seq = new Array(t).fill(IN.R);
	seq.push(IN.R | IN.J | IN.JTRIG);              // jump rising-edge at the takeoff
	for (let i = 1; i < K; i++) seq.push(IN.R | IN.J);
	for (let i = 0; i < tail; i++) seq.push(IN.R); // walk into the exit after landing

	return { demo: encodeDemo(seq), entryVx, K, ok, jumpTick: t, need, reach: airDist(entryVx, K) };
}

/** Distance covered while ramping to (near) full speed - min run-up before a gap. */
export function runUpRoomForFullSpeed() {
	let x = 0, vx = 0, t = 0;
	while (vx < MODEL.maxSpeed * 0.97 && t < 800) { vx = runStep(vx); x += vx; t++; }
	return x;
}
