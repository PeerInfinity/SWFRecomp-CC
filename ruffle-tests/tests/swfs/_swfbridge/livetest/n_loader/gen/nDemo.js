// nDemo.js - N demo (input replay) (de)serialization.
//
// N's demo format (decoded; see the status doc): per tick = 4 bits
// L=1, R=2, J=4, JTRIG=8 (jump rising-edge). 7 ticks are packed per list entry
// at shifts 0,4,8,12,16,20,24. Serialized "<tickCount>:<e0>|<e1>|...". The
// canonical "hold right" 7-tick entry = 35791394.
//
// game.LoadDemo(demoStr) + game.StartDemoPlayback() replays it; the player reads
// input via game.GetInputState. This module is the JS authoring side.

export const IN = { L: 1, R: 2, J: 4, JTRIG: 8 };
const TICKS_PER_ENTRY = 7;

/** Pack a per-tick input array (each a 4-bit L/R/J/JTRIG mask) to a demo string. */
export function encodeDemo(perTick) {
	const ticks = perTick.length;
	const entries = [];
	for (let i = 0; i < ticks; i += TICKS_PER_ENTRY) {
		let e = 0;
		for (let k = 0; k < TICKS_PER_ENTRY; k++) {
			const v = (perTick[i + k] | 0) & 0xf;
			e |= v << (4 * k);
		}
		entries.push(e >>> 0);
	}
	return `${ticks}:${entries.join("|")}`;
}

/** Parse a demo string back to a per-tick input array (inverse of encodeDemo). */
export function decodeDemo(str) {
	const colon = str.indexOf(":");
	if (colon < 0) throw new Error("demo string has no ':' tick-count separator");
	const ticks = Number(str.slice(0, colon));
	const rest = str.slice(colon + 1);
	const entries = rest.length > 0 ? rest.split("|").map(Number) : [];
	const perTick = [];
	for (let i = 0; i < ticks; i++) {
		const e = entries[Math.floor(i / TICKS_PER_ENTRY)] >>> 0;
		const shift = 4 * (i % TICKS_PER_ENTRY);
		perTick.push((e >> shift) & 0xf);
	}
	return perTick;
}

/** "Hold right for `ticks` ticks" - the flat-level walk demo. */
export function holdRight(ticks) {
	return encodeDemo(new Array(ticks).fill(IN.R));
}

/** "Hold left for `ticks` ticks". */
export function holdLeft(ticks) {
	return encodeDemo(new Array(ticks).fill(IN.L));
}
