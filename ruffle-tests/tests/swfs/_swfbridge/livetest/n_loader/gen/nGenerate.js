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
import { maxRunningGap, apexHeight, MODEL } from "./nMotion.js";
import { planRunJump, planStepUp, planStepDown } from "./nReach.js";

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

// ---- P2 #1: same-level gap (run -> jump over a pit -> land, exit on landing) --

const TAKEOFF_COL = 8; // right edge of the takeoff platform (~150px run-up from spawn)
const LAND_TILES = 10; // landing platform width (tiles) - long enough to catch overshoot

/**
 * Generate one same-level gap level: a takeoff platform, a pit of `gapTiles`, and
 * a landing platform carrying the exit. The demo (from nReach) runs up and clears
 * the pit with one timed jump. Gap width is capped to the measured envelope so the
 * jump is physically possible; Ruffle is the final judge.
 */
export function generateGapLevel(seed, opts = {}) {
	const rng = makeRng(seed);
	const floorRow = opts.floorRow != null ? opts.floorRow : randint(rng, 12, 16);
	const ry = restY(floorRow);
	const envTiles = Math.floor(maxRunningGap() / TILE); // conservative reachable tiles (~11)
	const minGap = opts.minGapTiles != null ? opts.minGapTiles : 3;
	const maxGap = Math.min(opts.maxGapTiles != null ? opts.maxGapTiles : 9, envTiles);
	const gapTiles = opts.gapTiles != null ? opts.gapTiles : randint(rng, minGap, maxGap);

	const spawnCol = 2;
	const tCol = TAKEOFF_COL;
	const landStart = tCol + 1 + gapTiles;
	const landEnd = Math.min(COLS - 1, landStart + LAND_TILES);

	const lvl = new Level();
	lvl.fillRect(1, floorRow, tCol, floorRow, TILE_FULL);          // takeoff platform
	lvl.fillRect(landStart, floorRow, landEnd, floorRow, TILE_FULL); // landing platform

	const spawnX = cellToPixel(spawnCol, floorRow).x;
	lvl.addObject(OBJ.PLAYER, [spawnX, ry]);
	const doorCol = landEnd - 1, switchCol = landEnd - 2;
	lvl.addObject(OBJ.EXIT, [cellToPixel(doorCol, floorRow).x, ry, cellToPixel(switchCol, floorRow).x, ry]);

	// Takeoff edge = right edge of the takeoff floor; gap to clear = gapTiles wide.
	const launchX = tCol * TILE + 48; // cell tCol center (tCol*24+36) + half tile
	const plan = planRunJump(spawnX, launchX, gapTiles * TILE, { margin: opts.margin });

	return {
		levelId: `gap-s${seed >>> 0}`,
		level: lvl.encode(),
		demo: plan.demo,
		meta: { seed: seed >>> 0, floorRow, gapTiles, gapPx: gapTiles * TILE, entryVx: Math.round(plan.entryVx * 100) / 100, K: plan.K, reach: Math.round(plan.reach), planOk: plan.ok },
	};
}

/** Generate `count` distinct gap levels from consecutive seeds. */
export function generateGapBatch(count, baseSeed = 1, opts = {}) {
	const out = [];
	for (let i = 0; i < count; i++) out.push(generateGapLevel((baseSeed + i) >>> 0, opts));
	return out;
}

// ---- P2 #1 (step): land on a platform at a DIFFERENT height across a gap -------

// Cell whose LEFT edge is at/after pixel x (left edge of cell c = c*24+24).
function colAtOrAfter(x) { return Math.ceil((x - 24) / TILE); }
// Cell whose center is nearest pixel x.
function colNearest(x) { return Math.round((x - 36) / TILE); }
// Max upward step (tiles) the best jump clears with clearance+margin.
function maxStepUpTiles() {
	const apex = apexHeight(MODEL.holds[MODEL.holds.length - 1]);
	return Math.max(1, Math.floor((apex - 22) / TILE)); // -22 ~ clearance+margin
}

/**
 * Generate one step level: takeoff platform, a gap, then a landing platform a few
 * tiles HIGHER (dir "up") or LOWER (dir "down"), carrying the exit. Uses the
 * measured jump arc to place the landing platform where the ninja actually lands.
 */
export function generateStepLevel(seed, opts = {}) {
	const rng = makeRng(seed);
	const floorRow = opts.floorRow != null ? opts.floorRow : randint(rng, 12, 15);
	const ry = restY(floorRow);
	const dir = opts.dir || (rng() < 0.5 ? "up" : "down");

	const spawnCol = 2;
	const tCol = TAKEOFF_COL;
	const launchX = tCol * TILE + 48;
	const spawnX = cellToPixel(spawnCol, floorRow).x;

	const lvl = new Level();
	lvl.fillRect(1, floorRow, tCol, floorRow, TILE_FULL); // takeoff platform

	let stepTiles, floorRow2, plan, nearCol, landCol;
	if (dir === "up") {
		const maxUp = Math.min(opts.maxStepTiles != null ? opts.maxStepTiles : 2, maxStepUpTiles());
		stepTiles = opts.stepTiles != null ? opts.stepTiles : randint(rng, 1, maxUp);
		floorRow2 = floorRow - stepTiles;
		plan = planStepUp(spawnX, launchX, stepTiles * TILE, { margin: opts.margin });
		nearCol = Math.max(tCol + 2, colAtOrAfter(launchX + (plan.nearEdgeDx ?? 60)));
		landCol = colNearest(launchX + plan.landDx);
	} else {
		const maxDown = opts.maxStepTiles != null ? opts.maxStepTiles : 3;
		stepTiles = opts.stepTiles != null ? opts.stepTiles : randint(rng, 1, maxDown);
		floorRow2 = floorRow + stepTiles;
		plan = planStepDown(spawnX, launchX, stepTiles * TILE, { K: opts.K });
		landCol = colNearest(launchX + plan.landDx);
		nearCol = Math.max(tCol + 2, landCol - 1); // small gap; land a tile onto the ledge
	}

	const landEnd = Math.min(COLS - 1, nearCol + LAND_TILES);
	lvl.fillRect(nearCol, floorRow2, landEnd, floorRow2, TILE_FULL); // landing platform

	const ry2 = restY(floorRow2);
	lvl.addObject(OBJ.PLAYER, [spawnX, ry]);
	const doorCol = landEnd - 1, switchCol = landEnd - 2;
	lvl.addObject(OBJ.EXIT, [cellToPixel(doorCol, floorRow2).x, ry2, cellToPixel(switchCol, floorRow2).x, ry2]);

	return {
		levelId: `step-${dir}-s${seed >>> 0}`,
		level: lvl.encode(),
		demo: plan.demo,
		meta: { seed: seed >>> 0, dir, stepTiles, floorRow, floorRow2, K: plan.K, entryVx: Math.round(plan.entryVx * 100) / 100, nearCol, landCol, landEnd, planOk: plan.ok, apexH: Math.round(plan.apexH) },
	};
}

/** Generate `count` distinct step levels (alternating up/down) from consecutive seeds. */
export function generateStepBatch(count, baseSeed = 1, opts = {}) {
	const out = [];
	for (let i = 0; i < count; i++) {
		const dir = opts.dir || (i % 2 === 0 ? "up" : "down");
		out.push(generateStepLevel((baseSeed + i) >>> 0, { ...opts, dir }));
	}
	return out;
}
