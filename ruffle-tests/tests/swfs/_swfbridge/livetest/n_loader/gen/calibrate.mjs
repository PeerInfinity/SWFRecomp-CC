// calibrate.mjs - measure N's motion model on real N (Ruffle) and write a
// calibration table (nMotion_calib.json) consumed by nMotion.js. Runs the probe
// matrix (nProbe) through ONE Ruffle QUEUE session, parses per-level arcs
// (nTelemetry), and tabulates the momentum-coupled jump envelope.
//
//   node gen/calibrate.mjs [captureSecs]
//
// Needs DISPLAY + chrome + playwright (run_ruffle.sh). Writes gen/nMotion_calib.json.
import { execFileSync } from "node:child_process";
import { readFileSync, writeFileSync } from "node:fs";
import { fileURLToPath } from "node:url";
import { dirname, join } from "node:path";
import { buildProbeMatrix } from "./nProbe.js";
import { writeQueueFile } from "./queueFile.js";
import { parseQueueConsole, extractJumpFeatures } from "./nTelemetry.js";

const here = dirname(fileURLToPath(import.meta.url));
const loaderDir = join(here, "..");

const probes = buildProbeMatrix();
const captureSecs = Number(process.argv[2] || 18 + 5 * probes.length);

console.log(`[calibrate] ${probes.length} probes; writing queue + running Ruffle (${captureSecs}s)`);
writeQueueFile(join(loaderDir, "n_queue_testcases.js"), probes);
try {
	execFileSync("./run_ruffle.sh", [String(captureSecs)], {
		cwd: loaderDir,
		env: { ...process.env, QUEUE: "1" },
		stdio: ["ignore", "ignore", "inherit"],
	});
} catch (e) {
	console.error("[calibrate] run_ruffle.sh failed:", e.message);
	process.exit(2);
}

const levels = parseQueueConsole(readFileSync(join(loaderDir, "ruffle_run", "console.txt"), "utf8"));
const byId = new Map(levels.map((l) => [l.levelId, l]));

// Speed ramp from the pure run-up probe: vx series + max speed.
const ramp = byId.get("ramp");
const rampVx = ramp ? ramp.frames.map((f) => f.vx) : [];
const maxSpeed = rampVx.length ? Math.max(...rampVx) : null;
// Ticks of hold-right to reach 95% / 99% of max speed (run-up distance budget).
function ticksToFrac(frac) {
	if (!maxSpeed) return null;
	const t = rampVx.findIndex((v) => v >= frac * maxSpeed);
	return t < 0 ? null : t;
}

const jumps = [];
for (const p of probes) {
	if (p.meta.kind !== "jump") continue;
	const lv = byId.get(p.levelId);
	if (!lv || !lv.frames.length) { jumps.push({ ...p.meta, error: "no frames", result: lv && lv.result }); continue; }
	const f = extractJumpFeatures(lv.frames);
	jumps.push({
		R: p.meta.R, K: p.meta.K, result: lv.result,
		entryVx: round(f.entryVx), initVy: round(f.initVy), apexHeight: round(f.apexHeight),
		airtime: f.airtime, airDist: round(f.airDist), exitVx: round(f.exitVx), maxVx: round(f.maxVx),
		arc: f.arc, // [dx,dy] per air tick relative to takeoff (for step-up/down placement)
	});
}

function round(x) { return x == null ? null : Math.round(x * 1000) / 1000; }

const calib = {
	measuredOn: "real N via Ruffle (deterministic demo replay)",
	ground: { restY: 350, floorRow: 14, playerR: 10 },
	speed: { maxSpeed: round(maxSpeed), ticksTo95pct: ticksToFrac(0.95), ticksTo99pct: ticksToFrac(0.99), rampVx: rampVx.slice(0, 60).map(round) },
	jumps,
};
const outPath = join(here, "nMotion_calib.json");
writeFileSync(outPath, JSON.stringify(calib, null, 2) + "\n");

// Report.
console.log(`\n[calibrate] max ground speed = ${calib.speed.maxSpeed} px/tick` +
	`  (95% at ${calib.speed.ticksTo95pct} ticks, 99% at ${calib.speed.ticksTo99pct})`);
console.log("\n  R(runup)  K(hold)  entryVx  initVy  apexH   airT  airDist  exitVx  result");
for (const j of jumps) {
	if (j.error) { console.log(`  R${j.R} K${j.K}: ${j.error} (${j.result})`); continue; }
	console.log(
		`  ${pad(j.R, 7)}  ${pad(j.K, 6)}  ${pad(j.entryVx, 6)}  ${pad(j.initVy, 6)}  ` +
		`${pad(j.apexHeight, 6)}  ${pad(j.airtime, 4)}  ${pad(j.airDist, 7)}  ${pad(j.exitVx, 5)}  ${j.result}`);
}
console.log(`\n[calibrate] wrote ${outPath}`);

function pad(x, n) { return String(x).padStart(n); }
