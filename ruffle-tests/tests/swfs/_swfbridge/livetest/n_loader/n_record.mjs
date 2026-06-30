// n_record.mjs - parse a captured N run log (Ruffle console.txt or SWFRecomp
// native trace.txt) into a structured per-frame JSON record.
//
// NLoader emits one "NF ..." line per simulated frame (player telemetry) plus
// "NEV <type> ..." event lines and a final "N_COMPLETE ..." marker. This reads
// those, strips Ruffle's console formatting if present, and writes:
//   { meta:{levelId, frames, completed, completedTick, result},
//     events:[{type, tick, ...}], frames:[{t,gt,x,y,vx,vy,st,air,wall,jt,face,
//     L,R,J,JT,gold,swon,dead}] }
//
// Usage: node n_record.mjs <input-log> [output.json]   (stdout if no output)
import { readFileSync, writeFileSync } from 'node:fs';

const ST_NAMES = ['stand', 'run', 'skid', 'jump', 'fall', 'wallslide', 'ragdoll', 'celebrate'];

// Ruffle wraps AVM trace() as "%cINFO%c web/src/log_adapter.rs:18%c <msg> color:...".
// Native trace.txt lines are raw. Strip the wrapper if present.
function clean(line) {
	return line
		.replace(/^.*log_adapter\.rs:\d+%c /, '')
		.replace(/ color: whitesmoke.*$/, '')
		.trim();
}

// Parse "k=v k=v ..." into an object; numeric values become numbers.
function kv(rest) {
	const o = {};
	for (const tok of rest.split(/\s+/)) {
		if (!tok) continue;
		const i = tok.indexOf('=');
		if (i < 0) continue;
		const k = tok.slice(0, i);
		const v = tok.slice(i + 1);
		const n = Number(v);
		o[k] = (v !== '' && !Number.isNaN(n)) ? n : v;
	}
	return o;
}

function parse(text) {
	const frames = [];
	const events = [];
	const meta = { levelId: null, frames: 0, completed: false, completedTick: null, result: 'incomplete' };

	for (const raw of text.split(/\r?\n/)) {
		const line = clean(raw);
		if (line.startsWith('NF ')) {
			const f = kv(line.slice(3));
			if (f.st != null) f.stName = ST_NAMES[f.st] ?? String(f.st);
			frames.push(f);
		} else if (line.startsWith('NEV ')) {
			const rest = line.slice(4);
			const sp = rest.indexOf(' ');
			const type = sp < 0 ? rest : rest.slice(0, sp);
			const fields = sp < 0 ? {} : kv(rest.slice(sp + 1));
			events.push({ type, ...fields });
			if (type === 'exit') { meta.completed = true; meta.result = 'complete'; }
		} else if (line.startsWith('N_COMPLETE')) {
			const f = kv(line.replace('N_COMPLETE', ''));
			meta.completed = true;
			meta.result = 'complete';
			meta.completedTick = f.tick ?? meta.completedTick;
			if (f.id != null) meta.levelId = String(f.id);
		} else {
			const m = line.match(/^\[nloader\] (?:loading level|EI configured id=) ?(\S+)/);
			if (m && !meta.levelId) meta.levelId = m[1].replace(/^id=/, '');
			if (/PLAYER DIED/.test(line)) meta.result = 'died';
		}
	}
	meta.frames = frames.length;
	if (frames.length) {
		meta.firstTick = frames[0].t;
		meta.lastTick = frames[frames.length - 1].t;
	}
	return { meta, events, frames };
}

const [, , inPath, outPath] = process.argv;
if (!inPath) {
	console.error('usage: node n_record.mjs <input-log> [output.json]');
	process.exit(2);
}
const record = parse(readFileSync(inPath, 'utf8'));
const json = JSON.stringify(record, null, 2);
if (outPath) {
	writeFileSync(outPath, json);
	const e = record.events.map((x) => x.type).join(',') || 'none';
	console.error(`wrote ${outPath}: ${record.meta.frames} frames, result=${record.meta.result}, events=[${e}]`);
} else {
	process.stdout.write(json + '\n');
}
