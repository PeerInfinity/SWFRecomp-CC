// nVerify.js - the authoritative acceptance gate for generated levels.
//
// Generates a batch of levels, writes them to the Ruffle QUEUE harness payload,
// runs them all in ONE Ruffle session, and asserts every level reported
// N_COMPLETE on real N. This is the ground truth: a level is "good" only if real
// N completes it with its demo. Pass/fail is read from the N_COMPLETE / N_FAIL
// trace lines (the SWF advances the queue on either, so a bad level never stalls
// the batch).
//
//   node gen/nVerify.js [count] [baseSeed] [captureSecs]
//
// Defaults: count=6, baseSeed=1, captureSecs auto (12 + 4*count). Exit 0 iff all
// generated levels completed. Needs DISPLAY + chrome + playwright (run_ruffle.sh).
import { execFileSync } from "node:child_process";
import { readFileSync } from "node:fs";
import { fileURLToPath } from "node:url";
import { dirname, join } from "node:path";
import { generateFlatBatch } from "./nGenerate.js";
import { writeQueueFile } from "./queueFile.js";

const here = dirname(fileURLToPath(import.meta.url));
const loaderDir = join(here, "..");

const count = Number(process.argv[2] || 6);
const baseSeed = Number(process.argv[3] || 1);
const captureSecs = Number(process.argv[4] || 12 + 4 * count);

console.log(`[nVerify] generating ${count} flat levels (baseSeed=${baseSeed})`);
const batch = generateFlatBatch(count, baseSeed);
for (const b of batch) {
	console.log(`  ${b.levelId}: floorRow ${b.meta.floorRow} spawn ${b.meta.spawnX}` +
		` -> switch ${b.meta.switchX} -> door ${b.meta.doorX} (${b.meta.walk}px,` +
		` ${b.meta.gold.length} gold, demo ${b.meta.ticks} ticks)`);
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
		console.log(`  FAIL ${b.levelId} (${failed.get(b.levelId)}) walk=${b.meta.walk}px`);
		missing.push(b);
	} else {
		console.log(`  MISS ${b.levelId} (no trace - never ran or capture too short) walk=${b.meta.walk}px`);
		missing.push(b);
	}
}

console.log(`\n[nVerify] ${pass}/${batch.length} levels verified on real N (Ruffle)`);
if (pass !== batch.length) {
	console.error(`[nVerify] FAILED: ${missing.map((b) => b.levelId).join(", ")}`);
	process.exit(1);
}
console.log("[nVerify] ALL GREEN");
