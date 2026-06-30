// nTelemetry.js - parse a Ruffle QUEUE-run console into PER-LEVEL frame streams,
// and extract motion-model features (entry speed, jump apex, airtime, air
// distance, run-up ramp) from a probe arc. Used by calibrate.mjs to fit nMotion
// against real N. The single-level recorder is n_record.mjs; this splits a batch.
import { readFileSync } from "node:fs";

const ST_NAMES = ["stand", "run", "skid", "jump", "fall", "wallslide", "ragdoll", "celebrate"];

function clean(line) {
	return line
		.replace(/^.*log_adapter\.rs:\d+%c /, "")
		.replace(/ color: whitesmoke.*$/, "")
		.trim();
}
function kv(rest) {
	const o = {};
	for (const tok of rest.split(/\s+/)) {
		if (!tok) continue;
		const i = tok.indexOf("=");
		if (i < 0) continue;
		const k = tok.slice(0, i), v = tok.slice(i + 1);
		const n = Number(v);
		o[k] = v !== "" && !Number.isNaN(n) ? n : v;
	}
	return o;
}

/** Parse a queue console into [{levelId, frames, result, completedTick}] in order. */
export function parseQueueConsole(text) {
	const levels = [];
	let cur = null;
	const start = (id) => {
		// A boundary trace can repeat (poll loops); only open a new bucket per id once.
		if (cur && cur.levelId === id && cur.frames.length === 0) return;
		cur = { levelId: id, frames: [], result: "incomplete", completedTick: null };
		levels.push(cur);
	};
	for (const raw of text.split(/\r?\n/)) {
		const line = clean(raw);
		let m;
		if ((m = line.match(/^\[nloader\] (?:loading level|next level id=|EI configured id=)\s*(\S+)/))) {
			start(m[1].replace(/^id=/, ""));
		} else if (line.startsWith("NF ")) {
			if (!cur) continue;
			const f = kv(line.slice(3));
			if (f.st != null) f.stName = ST_NAMES[f.st] ?? String(f.st);
			cur.frames.push(f);
		} else if ((m = line.match(/^N_COMPLETE id=(\S+) tick=(\d+)/))) {
			const lv = levels.find((l) => l.levelId === m[1] && l.result === "incomplete") || cur;
			if (lv) { lv.result = "complete"; lv.completedTick = Number(m[2]); }
		} else if ((m = line.match(/^N_FAIL id=(\S+) reason=(\S+)/))) {
			const lv = levels.find((l) => l.levelId === m[1] && l.result === "incomplete") || cur;
			if (lv) lv.result = "fail:" + m[2];
		}
	}
	return levels;
}

/**
 * Extract motion features from a probe level's frames.
 * Returns null if no jump (JT) is present (e.g. a pure run-up probe -> use ramp).
 */
export function extractJumpFeatures(frames) {
	const ground = frames.length ? frames[0].y : 0;
	const ji = frames.findIndex((f) => f.JT === 1);
	const maxVx = frames.reduce((m, f) => Math.max(m, f.vx), 0);
	if (ji < 0) return { jump: false, ground, maxVx, frames: frames.length };

	const entryVx = frames[ji].vx;
	const startX = frames[ji].x;
	const startY = frames[ji].y;
	// Airborne run = contiguous air===1 frames from the jump.
	let k = ji;
	while (k < frames.length && (frames[k].air === 1 || frames[k].JT === 1)) k++;
	const air = frames.slice(ji, k);
	let apexY = Infinity, apexFrame = null, initVy = 0;
	for (const f of air) {
		if (f.y < apexY) { apexY = f.y; apexFrame = f; }
		if (f.vy < initVy) initVy = f.vy; // most-negative = launch impulse
	}
	const last = air[air.length - 1] || frames[ji];
	return {
		jump: true,
		ground,
		entryVx,
		initVy,
		apexHeight: startY - apexY,
		apexAtVx: apexFrame ? apexFrame.vx : null,
		airtime: air.length,
		airDist: last.x - startX,
		exitVx: last.vx,
		maxVx,
		startX,
	};
}

// CLI: node nTelemetry.js <console.txt>  -> dump per-level summary
if (process.argv[1] && process.argv[1].endsWith("nTelemetry.js")) {
	const path = process.argv[2];
	if (!path) { console.error("usage: node nTelemetry.js <console.txt>"); process.exit(2); }
	const levels = parseQueueConsole(readFileSync(path, "utf8"));
	for (const lv of levels) {
		console.log(`${lv.levelId}: ${lv.frames.length} frames, ${lv.result}`,
			JSON.stringify(extractJumpFeatures(lv.frames)));
	}
}
