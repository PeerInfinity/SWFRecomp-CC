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
// Dense full-speed hold sweep (K=1..30) — measured (sweep.mjs). Apex/airtime depend
// only on K, and the generator's jumps are all ~full speed, so this dense curve is
// the primary source for apex/airtime and full-speed airDist/arc; the 4x4 calib
// remains the fallback for non-full-speed entry.
let denseSweep = null;
try { denseSweep = JSON.parse(readFileSync(join(here, "sweep_kdense.json"), "utf8")); } catch { /* optional */ }

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

// ---- jump envelope ----------------------------------------------------------
// 4x4 grid (entry speed x hold) — fallback for non-full-speed entry.
const J = calib.jumps.filter((j) => !j.error);
const KS = [...new Set(J.map((j) => j.K))].sort((a, b) => a - b);
const VS = [...new Set(J.map((j) => j.entryVx))].sort((a, b) => a - b);
const cell = new Map(J.map((j) => [`${j.entryVx}|${j.K}`, j]));

// Dense full-speed curve: K -> {apexHeight, airtime, airDist, arc} for K=1..30.
// From the sweep (K=1..29); K30 spliced from the 4x4 full-speed cell (sweep's last
// probe truncates on capture cutoff).
const DK = new Map();
if (denseSweep) for (const r of denseSweep.rows) {
	if (!r.error && r.apexHeight != null) DK.set(r.K, { apexHeight: r.apexHeight, airtime: r.airtime, airDist: r.airDist, arc: r.arc });
}
{
	const fullV = Math.max(...VS);
	for (const k of KS) {
		if (DK.has(k)) continue;
		const c = cell.get(`${fullV}|${k}`);
		if (c) DK.set(k, { apexHeight: c.apexHeight, airtime: c.airtime, airDist: c.airDist, arc: c.arc });
	}
}
const DKS = [...DK.keys()].sort((a, b) => a - b);
const FULL = 0.9 * MAX_SPEED; // "full speed" threshold for using the dense curve

function lerp(a, b, t) { return a + (b - a) * t; }
function bracket(arr, x) {
	if (x <= arr[0]) return [0, 0, 0];
	if (x >= arr[arr.length - 1]) return [arr.length - 1, arr.length - 1, 0];
	let i = 0; while (arr[i + 1] < x) i++;
	return [i, i + 1, (x - arr[i]) / (arr[i + 1] - arr[i])];
}
// Interpolate a field of the dense full-speed curve over hold K.
function denseField(K, field) {
	const [i0, i1, t] = bracket(DKS, K);
	return lerp(DK.get(DKS[i0])[field], DK.get(DKS[i1])[field], t);
}

/** Apex height (px above takeoff) for a jump-hold of K ticks. Depends only on K. */
export function apexHeight(K) { return denseField(K, "apexHeight"); }
/** Airtime (ticks aloft) for a jump-hold of K. Depends only on K. */
export function airtime(K) { return denseField(K, "airtime"); }
/** The measured jump trajectory ([dx,dy] per air tick, dy<0=above takeoff). Uses the
 *  dense full-speed arc for full-speed entry (the generator's case); else the closest
 *  4x4 grid cell. */
export function arcFor(entryVx, K) {
	if (entryVx >= FULL) return DK.get(closest(DKS, K))?.arc ?? [];
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

/** Horizontal air distance for entry speed `vx` and jump-hold `K`. Full-speed uses
 *  the dense K curve (exact per hold); else bilinear over the 4x4 grid. */
export function airDist(vx, K) {
	if (vx >= FULL) return denseField(K, "airDist");
	const [vi0, vi1, vt] = bracket(VS, vx);
	const [ki0, ki1, kt] = bracket(KS, K);
	const g = (vi, ki) => cell.get(`${VS[vi]}|${KS[ki]}`)?.airDist ?? 0;
	return lerp(lerp(g(vi0, ki0), g(vi0, ki1), kt), lerp(g(vi1, ki0), g(vi1, ki1), kt), vt);
}

// ---- generator-facing envelopes (conservative) ------------------------------

/** Max same-level horizontal gap clearable from entry speed `vx` (best hold),
 *  shrunk by `margin` so the real-N gate almost always agrees. In pixels. */
export function maxGap(vx, margin = 0.12) {
	const best = Math.max(...DKS.map((K) => airDist(vx, K)));
	return best * (1 - margin);
}
/** Max upward ledge height reachable (best hold), shrunk by `margin`. In pixels. */
export function maxStepUp(margin = 0.15) {
	return Math.max(...DKS.map((K) => apexHeight(K))) * (1 - margin);
}
/** Best-case max gap from full running speed. */
export function maxRunningGap(margin = 0.12) { return maxGap(MAX_SPEED, margin); }

function closest(arr, x) { return arr.reduce((b, v) => (Math.abs(v - x) < Math.abs(b - x) ? v : b), arr[0]); }

export const MODEL = {
	// holds = the full measured hold range (dense K=1..30), so the generator can
	// pick any hold, not just the 4x4 grid points.
	maxSpeed: MAX_SPEED, restY: GROUND_REST_Y, holds: DKS, entrySpeeds: VS,
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
