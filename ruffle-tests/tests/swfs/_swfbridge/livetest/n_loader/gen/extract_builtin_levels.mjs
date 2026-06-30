// extract_builtin_levels.mjs - pull every built-in `new LevelData(name, levStr)`
// out of N's decompiled frame_1 scripts into a JSON fixture for the golden
// round-trip test. Run with the JPEXS script-export dir as argv[2]:
//
//   java -jar ~/CC/jpexs/ffdec.jar -export script <outdir> ~/CC/flasharchive/N.swf
//   node extract_builtin_levels.mjs <outdir> > builtin_levels.json
//
// The level strings contain no escaped double-quotes (verified), so a simple
// "..."  ,  "..."  scan is sufficient.
import { readFileSync, readdirSync } from "node:fs";
import { join } from "node:path";

const outdir = process.argv[2];
if (!outdir) {
	console.error("usage: node extract_builtin_levels.mjs <jpexs-script-export-dir>");
	process.exit(2);
}

// new LevelData( "name" , "levStr" ) - both args plain double-quoted strings.
const RE = /new LevelData\(\s*"((?:[^"\\]|\\.)*)"\s*,\s*"((?:[^"\\]|\\.)*)"\s*\)/g;

const dir = join(outdir, "scripts", "frame_1");
const files = readdirSync(dir).filter((f) => f.endsWith(".as")).sort();
const levels = [];
const seenNames = new Map();
for (const f of files) {
	const src = readFileSync(join(dir, f), "utf8");
	let m;
	while ((m = RE.exec(src)) !== null) {
		const name = m[1];
		const level = m[2];
		// disambiguate duplicate display names (N reuses some), keep order.
		const n = (seenNames.get(name) || 0) + 1;
		seenNames.set(name, n);
		const id = n === 1 ? name : `${name}#${n}`;
		levels.push({ id, name, source: f, level });
	}
}

console.error(`extracted ${levels.length} levels from ${files.length} files`);
process.stdout.write(JSON.stringify({ count: levels.length, levels }, null, 2) + "\n");
