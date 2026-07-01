// nVerify.js - the authoritative acceptance gate for generated levels.
//
// Generates a batch of levels, writes them to the Ruffle QUEUE harness payload,
// runs them all in ONE Ruffle session, and asserts every level reported
// N_COMPLETE on real N. This is the ground truth: a level is "good" only if real
// N completes it with its demo. Pass/fail is read from the N_COMPLETE / N_FAIL
// trace lines (the SWF advances the queue on either, so a bad level never stalls
// the batch).
//
//   node gen/nVerify.js [flat|gap] [count] [baseSeed] [captureSecs]
//
// Args are order-flexible: 'flat'/'gap' picks the generator (default flat), the
// numeric args fill count, baseSeed, captureSecs in order. Exit 0 iff all
// generated levels completed. Needs DISPLAY + chrome + playwright (run_ruffle.sh).
import { execFileSync } from "node:child_process";
import { readFileSync } from "node:fs";
import { fileURLToPath } from "node:url";
import { dirname, join } from "node:path";
import { generateFlatBatch, generateGapBatch, generateStepBatch } from "./nGenerate.js";
import { writeQueueFile } from "./queueFile.js";

const here = dirname(fileURLToPath(import.meta.url));
const loaderDir = join(here, "..");

let kind = "flat";
const nums = [];
for (const a of process.argv.slice(2)) {
	if (a === "flat" || a === "gap" || a === "step") kind = a;
	else if (a !== "" && !Number.isNaN(Number(a))) nums.push(Number(a));
}
const count = nums[0] || 6;
const baseSeed = nums[1] || 1;
const captureSecs = nums[2] || 12 + 5 * count;

console.log(`[nVerify] generating ${count} ${kind} levels (baseSeed=${baseSeed})`);
const batch = kind === "gap" ? generateGapBatch(count, baseSeed)
	: kind === "step" ? generateStepBatch(count, baseSeed)
	: generateFlatBatch(count, baseSeed);
for (const b of batch) {
	if (kind === "step") {
		console.log(`  ${b.levelId}: ${b.meta.dir} ${b.meta.stepTiles} tiles` +
			` (row ${b.meta.floorRow}->${b.meta.floorRow2}) K=${b.meta.K} entryVx ${b.meta.entryVx}` +
			` land@col${b.meta.landCol} plat[${b.meta.nearCol}..${b.meta.landEnd}] planOk=${b.meta.planOk}`);
	} else if (kind === "gap") {
		console.log(`  ${b.levelId}: floorRow ${b.meta.floorRow} gap ${b.meta.gapTiles} tiles` +
			` (${b.meta.gapPx}px) entryVx ${b.meta.entryVx} K=${b.meta.K} reach ${b.meta.reach}px` +
			` planOk=${b.meta.planOk}`);
	} else {
		console.log(`  ${b.levelId}: floorRow ${b.meta.floorRow} spawn ${b.meta.spawnX}` +
			` -> switch ${b.meta.switchX} -> door ${b.meta.doorX} (${b.meta.walk}px,` +
			` ${b.meta.gold.length} gold, demo ${b.meta.ticks} ticks)`);
	}
}

writeQueueFile(join(loaderDir, "n_queue_testcases.js"), batch);

console.log(`[nVerify] running Ruffle QUEUE (${captureSecs}s capture)...`);
try {
	execFileSync("./run_ruffle.sh", [String(captureSecs)], {
		cwd: loaderDir,
		env: { ...process.env, QUEUE: "1" },
		stdio: ["ignore", "ignore", "inherit"], // keep stderr; console.txt has the trace
	});
} catch (e) {
	console.error("[nVerify] run_ruffle.sh failed:", e.message);
	process.exit(2);
}

const console_txt = readFileSync(join(loaderDir, "ruffle_run", "console.txt"), "utf8");
const completed = new Map(); // id -> tick
const failed = new Map();    // id -> reason
for (const m of console_txt.matchAll(/N_COMPLETE id=(\S+) tick=(\d+)/g)) {
	completed.set(m[1], Number(m[2]));
}
for (const m of console_txt.matchAll(/N_FAIL id=(\S+) reason=(\S+) tick=(\d+)/g)) {
	failed.set(m[1], m[2]);
}

console.log("\n[nVerify] results:");
let pass = 0;
const missing = [];
for (const b of batch) {
	if (completed.has(b.levelId)) {
		pass++;
		console.log(`  PASS ${b.levelId} (tick ${completed.get(b.levelId)})`);
	} else if (failed.has(b.levelId)) {
		console.log(`  FAIL ${b.levelId} (${failed.get(b.levelId)}) ${describe(b)}`);
		missing.push(b);
	} else {
		console.log(`  MISS ${b.levelId} (no trace - never ran or capture too short) ${describe(b)}`);
		missing.push(b);
	}
}

function describe(b) {
	if (kind === "gap") return `gap=${b.meta.gapTiles}t K=${b.meta.K}`;
	if (kind === "step") return `${b.meta.dir}=${b.meta.stepTiles}t K=${b.meta.K} land@${b.meta.landCol}`;
	return `walk=${b.meta.walk}px`;
}
console.log(`\n[nVerify] ${pass}/${batch.length} levels verified on real N (Ruffle)`);
if (pass !== batch.length) {
	console.error(`[nVerify] FAILED: ${missing.map((b) => b.levelId).join(", ")}`);
	process.exit(1);
}
console.log("[nVerify] ALL GREEN");
