// nGenerate.js - level generator for N. Phase 1 = flat "walk right" levels:
// a solid floor row with spawn -> switch -> door laid left-to-right, solvable by
// a hold-right demo (the demo IS the solving proof). Construction-by-simulation
// is trivial here because the path is a straight walk; jumps/gaps come in P2.
//
// Seeded + deterministic: the same seed always yields the same level (no runtime
// RNG, matching the framework). Each level is {levelId, level, demo, meta}; feed
// a batch to nVerify.js to confirm every one completes on real N via Ruffle.
import { Level, OBJ, TILE_FULL, cellToPixel, pixelToCell, COLS } from "./nLevel.js";
import { holdRight } from "./nDemo.js";

// N geometry (status doc): player radius 10; floor map-row `fr` has its top
// surface at pixel (fr+1)*24, so a grounded body rests at center y = top - r.
const PLAYER_R = 10;
const TILE = 24;
function restY(floorRow) { return (floorRow + 1) * TILE - PLAYER_R; }

/** mulberry32 - small deterministic PRNG; returns a float in [0,1). */
export function makeRng(seed) {
	let s = seed >>> 0;
	return function () {
		s = (s + 0x6d2b79f5) | 0;
		let t = Math.imul(s ^ (s >>> 15), 1 | s);
		t = (t + Math.imul(t ^ (t >>> 7), 61 | t)) ^ t;
		return ((t ^ (t >>> 14)) >>> 0) / 4294967296;
	};
}
function randint(rng, lo, hi) { return lo + Math.floor(rng() * (hi - lo + 1)); }

/**
 * Generate one flat walk-right level.
 * opts (all optional; defaults give a solvable spread):
 *   floorRow [11..17], spawnX [120..260], walk distance [minWalk..maxWalk],
 *   gold count [goldMin..goldMax].
 */
export function generateFlatLevel(seed, opts = {}) {
	const rng = makeRng(seed);
	const floorRow = opts.floorRow != null ? opts.floorRow : randint(rng, 11, 17);
	const ry = restY(floorRow);
	const spawnX = opts.spawnX != null ? opts.spawnX : randint(rng, 120, 260);
	const minWalk = opts.minWalk != null ? opts.minWalk : 60;
	const maxWalk = opts.maxWalk != null ? opts.maxWalk : 300;
	const walk = opts.walk != null ? opts.walk : randint(rng, minWalk, maxWalk);
	const switchX = spawnX + Math.round(walk * 0.45); // switch on the way to the door
	const doorX = spawnX + walk;

	const lvl = new Level();
	// Floor spans one tile beyond spawn and door so nothing rests over a gap.
	const x0 = Math.max(0, pixelToCell(spawnX, ry).mx - 1);
	const x1 = Math.min(COLS - 1, pixelToCell(doorX, ry).mx + 1);
	for (let mx = x0; mx <= x1; mx++) lvl.setTile(mx, floorRow, TILE_FULL);

	lvl.addObject(OBJ.PLAYER, [spawnX, ry]);
	lvl.addObject(OBJ.EXIT, [doorX, ry, switchX, ry]); // [doorX,doorY,switchX,switchY]

	// Optional gold along the walked path (bonus only; doesn't gate completion).
	const goldMin = opts.goldMin != null ? opts.goldMin : 0;
	const goldMax = opts.goldMax != null ? opts.goldMax : 3;
	const goldCount = opts.goldCount != null ? opts.goldCount : randint(rng, goldMin, goldMax);
	const gold = [];
	for (let i = 0; i < goldCount; i++) {
		const gx = spawnX + Math.round((walk * (i + 1)) / (goldCount + 1));
		lvl.addGold(gx, ry);
		gold.push(gx);
	}

	// Hold-right long enough to reach the door (generous; extra ticks are free
	// since the level ends on completion). N runs at ~<=5px/tick after ramp-up.
	const ticks = Math.ceil((doorX - spawnX) / 2) + 30;

	return {
		levelId: `flat-s${seed >>> 0}`,
		level: lvl.encode(),
		demo: holdRight(ticks),
		meta: { seed: seed >>> 0, floorRow, spawnX, switchX, doorX, walk, ticks, gold },
	};
}

/** Generate `count` distinct flat levels from consecutive seeds. */
export function generateFlatBatch(count, baseSeed = 1, opts = {}) {
	const out = [];
	for (let i = 0; i < count; i++) out.push(generateFlatLevel((baseSeed + i) >>> 0, opts));
	return out;
}
