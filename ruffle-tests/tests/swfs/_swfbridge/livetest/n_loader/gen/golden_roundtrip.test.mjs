// golden_roundtrip.test.mjs - the format-correctness lock for nLevel.js.
//
// For EVERY built-in N level (extracted by extract_builtin_levels.mjs into
// builtin_levels.json), assert that encode(decode(s)) is BYTE-IDENTICAL to s.
// This proves the encoder/decoder faithfully model N's real on-disk format
// before any level generation is built on top of it.
//
//   node golden_roundtrip.test.mjs
//
// Exit 0 = all pass; exit 1 = at least one mismatch (details printed).
import { readFileSync } from "node:fs";
import { fileURLToPath } from "node:url";
import { dirname, join } from "node:path";
import { decode, encode, COLS, ROWS } from "./nLevel.js";

const here = dirname(fileURLToPath(import.meta.url));
const fixture = JSON.parse(readFileSync(join(here, "builtin_levels.json"), "utf8"));
const levels = fixture.levels;

let pass = 0;
const failures = [];

for (const { id, level } of levels) {
	let out;
	try {
		out = encode(decode(level));
	} catch (e) {
		failures.push({ id, reason: `threw: ${e.message}` });
		continue;
	}
	if (out === level) {
		pass++;
	} else {
		// Locate the first differing character for a useful message.
		let i = 0;
		const n = Math.min(out.length, level.length);
		while (i < n && out[i] === level[i]) i++;
		failures.push({
			id,
			reason: `mismatch at index ${i} (len ${level.length} -> ${out.length})`,
			expected: level.slice(Math.max(0, i - 10), i + 10),
			actual: out.slice(Math.max(0, i - 10), i + 10),
		});
	}
}

console.log(`golden round-trip: ${pass}/${levels.length} built-in levels byte-identical (${COLS}x${ROWS})`);
if (failures.length > 0) {
	console.error(`\nFAILURES (${failures.length}):`);
	for (const f of failures.slice(0, 20)) {
		console.error(`  - ${f.id}: ${f.reason}`);
		if (f.expected !== undefined) {
			console.error(`      expected ...${JSON.stringify(f.expected)}...`);
			console.error(`      actual   ...${JSON.stringify(f.actual)}...`);
		}
	}
	process.exit(1);
}

// Sanity self-check: a couple of structural invariants on the parse.
const sample = decode(levels[0].level);
const objCount = sample.objects.length;
if (sample.tiles.length !== COLS * ROWS) {
	console.error(`tiles length ${sample.tiles.length} != ${COLS * ROWS}`);
	process.exit(1);
}
console.log(`sample "${levels[0].id}": ${objCount} objects, ${sample.tiles.length} tiles - OK`);
console.log("ALL GREEN");
