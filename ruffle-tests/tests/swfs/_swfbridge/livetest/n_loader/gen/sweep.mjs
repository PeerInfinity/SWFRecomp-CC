// sweep.mjs - dense measurement sweep (finer than calibrate.mjs's 4x4 grid).
// Writes to a SEPARATE file (gen/sweep_<name>.json) so it never clobbers the
// production nMotion_calib.json until we've compared and decided to promote it.
//
//   node gen/sweep.mjs kdense [captureSecs]   # holds K=1..30 at full entry speed
//
// Highest-value sweep: replaces the 4-point hold curve (K in {3,8,15,30}) with the
// exact apexHeight/airtime/airDist per integer hold, so GAP_MARGIN/CLEAR can shrink
// from measured error instead of interpolation padding.
import { execFileSync } from "node:child_process";
import { readFileSync, writeFileSync } from "node:fs";
import { fileURLToPath } from "node:url";
import { dirname, join } from "node:path";
import { buildProbeMatrix } from "./nProbe.js";
import { writeQueueFile } from "./queueFile.js";
import { parseQueueConsole, extractJumpFeatures } from "./nTelemetry.js";

const here = dirname(fileURLToPath(import.meta.url));
const loaderDir = join(here, "..");
const name = process.argv[2] || "kdense";

// kdense: full-speed run-up (R=45), holds 1..30.
const holds = Array.from({ length: 30 }, (_, i) => i + 1);
const probes = buildProbeMatrix([45], holds);
const captureSecs = Number(process.argv[3] || 18 + 6 * probes.length);

console.log(`[sweep:${name}] ${probes.length} probes (R45 x K1..30); Ruffle ${captureSecs}s`);
writeQueueFile(join(loaderDir, "n_queue_testcases.js"), probes);
try {
	execFileSync("./run_ruffle.sh", [String(captureSecs)], {
		cwd: loaderDir, env: { ...process.env, QUEUE: "1" }, stdio: ["ignore", "ignore", "inherit"],
	});
} catch (e) { console.error("[sweep] run_ruffle.sh failed:", e.message); process.exit(2); }

const levels = parseQueueConsole(readFileSync(join(loaderDir, "ruffle_run", "console.txt"), "utf8"));
const byId = new Map(levels.map((l) => [l.levelId, l]));
const round = (x) => (x == null ? null : Math.round(x * 100) / 100);

const rows = [];
for (const K of holds) {
	const lv = byId.get(`jump-R45-K${K}`);
	if (!lv || !lv.frames.length) { rows.push({ K, error: "no frames", result: lv && lv.result }); continue; }
	const f = extractJumpFeatures(lv.frames);
	rows.push({ K, entryVx: round(f.entryVx), apexHeight: round(f.apexHeight), airtime: f.airtime, airDist: round(f.airDist), exitVx: round(f.exitVx), result: lv.result, arc: f.arc });
}

const out = { name, measuredOn: "real N via Ruffle", entrySpeed: "full (R45)", holds, rows };
const outPath = join(here, `sweep_${name}.json`);
writeFileSync(outPath, JSON.stringify(out, null, 2) + "\n");

// Report with per-step deltas (shows how finely apex/airDist change per hold tick).
console.log("\n   K  apexH  dApex  airT  airDist  dDist  result");
let prev = null;
for (const r of rows) {
	if (r.error) { console.log(`  ${String(r.K).padStart(2)}  ${r.error} (${r.result})`); continue; }
	const dA = prev ? (r.apexHeight - prev.apexHeight).toFixed(1) : "-";
	const dD = prev ? (r.airDist - prev.airDist).toFixed(1) : "-";
	console.log(`  ${String(r.K).padStart(2)}  ${String(r.apexHeight).padStart(5)}  ${String(dA).padStart(5)}  ${String(r.airtime).padStart(4)}  ${String(r.airDist).padStart(7)}  ${String(dD).padStart(5)}  ${r.result}`);
	prev = r;
}
console.log(`\n[sweep:${name}] wrote ${outPath} (${rows.filter((r) => !r.error).length}/${rows.length} measured)`);
