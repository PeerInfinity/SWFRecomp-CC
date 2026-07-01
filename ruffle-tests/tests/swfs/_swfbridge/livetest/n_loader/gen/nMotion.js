// nMotion.js - N's motion model, MEASURED on real N (gen/nMotion_calib.json via
// calibrate.mjs), not derived. Provides the envelopes the generator needs to lay
// reachable geometry: run-up ramp, jump apex (vertical reach), airtime, and the
// momentum-coupled horizontal air distance (gap clearance). The real-N Ruffle
// gate (nVerify) is still the final judge; this model is CONSERVATIVE input to
// construction so accepted levels almost always pass.
//
// Measured facts: ground speed clamps at ~5 px/tick via vx[n+1]=min(5, vx*0.99+0.15)
// (reached ~tick 38 from rest); jump launch impulse is constant (vy=-3); apex
// height and airtime depend ONLY on the jump-hold K (vertical/horizontal
// decoupled); air distance depends on entry speed AND K because air-control ramps
// vx back toward 5 mid-flight.
import { readFileSync } from "node:fs";
import { fileURLToPath } from "node:url";
import { dirname, join } from "node:path";

const here = dirname(fileURLToPath(import.meta.url));
const calib = JSON.parse(readFileSync(join(here, "nMotion_calib.json"), "utf8"));

export const MAX_SPEED = calib.speed.maxSpeed; // ~5 px/tick
export const TILE = 24;
const GROUND_REST_Y = calib.ground.restY;

// ---- run-up ramp (closed recurrence, matches measured rampVx) ---------------
export function runStep(vx) { return Math.min(MAX_SPEED, vx * 0.99 + 0.15); }

/** Ticks of hold-right to reach speed `v` from rest (>= ramp tail returns Infinity-safe cap). */
export function runUpTicksForSpeed(v) {
	if (v <= 0.15) return 0;
	let vx = 0, t = 0;
	while (vx < v && t < 1000) { vx = runStep(vx); t++; }
	return t;
}
/** Horizontal distance covered while ramping to speed `v` from rest. */
export function runUpDistForSpeed(v) {
	let vx = 0, d = 0, t = 0;
	while (vx < v && t < 1000) { vx = runStep(vx); d += vx; t++; }
	return d;
}

// ---- jump envelope (interpolated over the measured grid) ---------------------
const J = calib.jumps.filter((j) => !j.error);
const KS = [...new Set(J.map((j) => j.K))].sort((a, b) => a - b);
const VS = [...new Set(J.map((j) => j.entryVx))].sort((a, b) => a - b);
const cell = new Map(J.map((j) => [`${j.entryVx}|${j.K}`, j]));

function lerp(a, b, t) { return a + (b - a) * t; }
function bracket(arr, x) {
	if (x <= arr[0]) return [0, 0, 0];
	if (x >= arr[arr.length - 1]) return [arr.length - 1, arr.length - 1, 0];
	let i = 0; while (arr[i + 1] < x) i++;
	return [i, i + 1, (x - arr[i]) / (arr[i + 1] - arr[i])];
}

/** Apex height (px above takeoff) for a jump-hold of K ticks. Depends only on K. */
export function apexHeight(K) {
	const [i0, i1, t] = bracket(KS, K);
	const at = (kk) => avg(VS.map((v) => cell.get(`${v}|${kk}`)?.apexHeight).filter((x) => x != null));
	return lerp(at(KS[i0]), at(KS[i1]), t);
}
/** Airtime (ticks aloft) for a jump-hold of K. Depends only on K. */
export function airtime(K) {
	const [i0, i1, t] = bracket(KS, K);
	const at = (kk) => avg(VS.map((v) => cell.get(`${v}|${kk}`)?.airtime).filter((x) => x != null));
	return lerp(at(KS[i0]), at(KS[i1]), t);
}
/** The measured jump trajectory ([dx,dy] per air tick, dy<0=above takeoff) for the
 *  grid cell closest to (entry speed, hold). Arcs are only measured at grid points;
 *  the generator uses full-speed entry so the closest cell is faithful. */
export function arcFor(entryVx, K) {
	const v = closest(VS, entryVx), k = closest(KS, K);
	return cell.get(`${v}|${k}`)?.arc ?? [];
}

// --- arc crossing helpers (trajectory queries the generator needs) -----------
function apexIdx(arc) { let a = 0; for (let i = 1; i < arc.length; i++) if (arc[i][1] < arc[a][1]) a = i; return a; }
// First dx where the rising arc reaches height dyTarget (dy<=dyTarget); null if never.
function ascendCrossDx(arc, dyTarget) { for (const [dx, dy] of arc) if (dy <= dyTarget) return dx; return null; }
// After apex, first dx where the falling arc returns to dyTarget (dy>=dyTarget).
function descendCrossDx(arc, dyTarget) {
	if (!arc.length) return 0;
	const a = apexIdx(arc);
	for (let i = a; i < arc.length; i++) if (arc[i][1] >= dyTarget) return arc[i][0];
	return arc[arc.length - 1][0];
}

/** Landing dx for a same-level jump (arc returns to takeoff height). */
export function gapLandingDx(entryVx, K) { return descendCrossDx(arcFor(entryVx, K), 0); }
/** For a jump onto a ledge `upPx` above takeoff: where the ninja is `clearance`
 *  above the ledge (near-edge placement) and where it descends to the surface. */
export function stepUpPlacement(entryVx, K, upPx, clearance = 12) {
	const arc = arcFor(entryVx, K);
	return { nearEdgeDx: ascendCrossDx(arc, -(upPx + clearance)), landDx: descendCrossDx(arc, -upPx) };
}
/** Landing dx for a hop onto a ledge `downPx` below takeoff. */
export function stepDownLandingDx(entryVx, K, downPx) { return descendCrossDx(arcFor(entryVx, K), downPx); }

/** Horizontal air distance for entry speed `vx` and jump-hold `K` (bilinear). */
export function airDist(vx, K) {
	const [vi0, vi1, vt] = bracket(VS, vx);
	const [ki0, ki1, kt] = bracket(KS, K);
	const g = (vi, ki) => cell.get(`${VS[vi]}|${KS[ki]}`)?.airDist ?? 0;
	return lerp(lerp(g(vi0, ki0), g(vi0, ki1), kt), lerp(g(vi1, ki0), g(vi1, ki1), kt), vt);
}

// ---- generator-facing envelopes (conservative) ------------------------------

/** Max same-level horizontal gap clearable from entry speed `vx` (best hold),
 *  shrunk by `margin` so the real-N gate almost always agrees. In pixels. */
export function maxGap(vx, margin = 0.12) {
	const best = Math.max(...KS.map((K) => airDist(vx, K)));
	return best * (1 - margin);
}
/** Max upward ledge height reachable (best hold), shrunk by `margin`. In pixels. */
export function maxStepUp(margin = 0.15) {
	return Math.max(...KS.map((K) => apexHeight(K))) * (1 - margin);
}
/** Best-case max gap from full running speed. */
export function maxRunningGap(margin = 0.12) { return maxGap(MAX_SPEED, margin); }

function avg(a) { return a.reduce((s, x) => s + x, 0) / a.length; }
function closest(arr, x) { return arr.reduce((b, v) => (Math.abs(v - x) < Math.abs(b - x) ? v : b), arr[0]); }

export const MODEL = {
	maxSpeed: MAX_SPEED, restY: GROUND_REST_Y, holds: KS, entrySpeeds: VS,
	rampToFullTicks: runUpTicksForSpeed(MAX_SPEED * 0.99),
};

// CLI self-report.
if (process.argv[1] && process.argv[1].endsWith("nMotion.js")) {
	console.log("MAX_SPEED", MAX_SPEED, "ramp-to-full ticks", MODEL.rampToFullTicks);
	console.log("maxStepUp", maxStepUp().toFixed(1), "px =", (maxStepUp() / TILE).toFixed(1), "tiles");
	console.log("maxGap @ standing", maxGap(0.15).toFixed(1), "px; @ full run", maxRunningGap().toFixed(1),
		"px =", (maxRunningGap() / TILE).toFixed(1), "tiles");
	for (const K of [3, 8, 15, 30]) console.log(`  K=${K}: apex ${apexHeight(K).toFixed(1)}px airtime ${airtime(K).toFixed(0)} airDist@full ${airDist(MAX_SPEED, K).toFixed(0)}px`);
}
