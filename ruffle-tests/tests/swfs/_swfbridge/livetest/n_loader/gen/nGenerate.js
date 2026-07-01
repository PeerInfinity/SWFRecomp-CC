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
import { maxRunningGap, maxGap, apexHeight, airtime, airDist, runStep, stepUpPlacement, stepDownLandingDx, MAX_SPEED, MODEL } from "./nMotion.js";
import { planRunJump, planStepUp, planStepDown } from "./nReach.js";
import { encodeDemo, IN } from "./nDemo.js";

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

// ---- P2 #2: multi-segment course (chain features, one demo through all) --------

function smallestGapK(entryVx, needPx) {
	for (const k of MODEL.holds) if (airDist(entryVx, k) >= needPx) return k;
	return MODEL.holds[MODEL.holds.length - 1];
}
function smallestApexK(needPx) {
	for (const k of MODEL.holds) if (apexHeight(k) >= needPx) return k;
	return MODEL.holds[MODEL.holds.length - 1];
}
const clampRow = (r) => Math.max(6, Math.min(19, r));

/**
 * Generate one multi-segment course: spawn -> a chain of 2-3 features (gap /
 * step-up / step-down) -> exit, threaded by a SINGLE demo. Construction-by-
 * simulation: the ninja runs up to full speed once, then cruises at ~maxSpeed
 * between features, so each feature is a full-speed jump placed by the measured
 * arc. Laid strictly left-to-right (monotonic columns) to fit the 31-wide grid,
 * so courses are short (2-3 features / one screen). Ruffle is the final judge.
 */
export function generateCourseLevel(seed, opts = {}) {
	const rng = makeRng(seed);
	// A full-speed jump already covers ~8 tiles (air-control ramps vx to ~5 mid-
	// flight), so on a 31-wide grid only ~2 features fit. The demo is open-loop, so
	// landing estimates MUST be accurate or the next jump mistriggers: give a full
	// run-up (START_PLAT) so EVERY jump is at ~full speed (matching the measured
	// full-speed arc), and keep a little platform margin (INTER) for residual drift.
	const LEAD = 8;
	const RIGHT_LIMIT = opts.rightLimit != null ? opts.rightLimit : 30;
	const START_PLAT = 7, INTER = 2, EXIT_RESERVE = 2, CLEAR = 8;
	const GAP_MARGIN = opts.margin != null ? opts.margin : 14;

	let row = clampRow(opts.floorRow != null ? opts.floorRow : randint(rng, 12, 15));
	const lvl = new Level();
	let platEnd = 1 + START_PLAT;
	lvl.fillRect(1, row, platEnd, row, TILE_FULL);
	const spawnX = cellToPixel(2, row).x;
	lvl.addObject(OBJ.PLAYER, [spawnX, restY(row)]);

	const seq = [];
	let x = spawnX, vx = 0;
	const features = [];
	const runTo = (targetX) => { let n = 0; while (x < targetX - LEAD && n < 400) { vx = runStep(vx); x += vx; seq.push(IN.R); n++; } };
	const doJump = (K, at) => {
		seq.push(IN.R | IN.J | IN.JTRIG);
		for (let i = 1; i < K; i++) seq.push(IN.R | IN.J);
		for (let i = K; i < at; i++) seq.push(IN.R); // finish the flight
	};

	const nWant = opts.features != null ? opts.features : randint(rng, 2, 3);
	while (features.length < nWant) {
		const launchCol = platEnd;
		const launchX = launchCol * TILE + 48;
		const budget = RIGHT_LIMIT - launchCol;

		// A feature is only allowed if its full-speed horizontal reach + the exit
		// still fits — else it overshoots into the right wall past the exit. Steps
		// reach ~11-13 tiles (long, high-air jumps), gaps ~9 (min-hold K3), so on a
		// 31-wide grid steps fit mainly as the first/only feature; 2-feature courses
		// are gap chains. (Reaches are conservative over-estimates.)
		const REACH = { gap: 9, up: 13, down: 12 };
		const fits = (t) => launchCol + REACH[t] + EXIT_RESERVE <= RIGHT_LIMIT;
		const types = [];
		if (fits("gap")) types.push("gap");
		if (row - 2 >= 6 && fits("up")) types.push("up");
		if (row + 2 <= 19 && fits("down")) types.push("down");
		if (types.length === 0) break; // no feature fits -> finish with the exit
		const type = types[Math.floor(rng() * types.length)];

		runTo(launchX);
		const entryVx = vx;

		let K, at, landX, nextRow, nearCol;
		if (type === "gap") {
			const maxW = Math.min(6, Math.floor(maxGap(entryVx) / TILE), budget - EXIT_RESERVE - 2);
			const W = Math.max(3, Math.min(maxW, randint(rng, 3, 5)));
			K = smallestGapK(entryVx, W * TILE + GAP_MARGIN);
			landX = launchX + airDist(entryVx, K);
			nextRow = row;
			nearCol = launchCol + 1 + W;
			features.push({ type: "gap", W, K });
		} else if (type === "up") {
			const upTiles = rng() < 0.4 && row - 2 >= 6 ? 2 : 1;
			K = smallestApexK(upTiles * TILE + CLEAR + 2);
			const pl = stepUpPlacement(entryVx, K, upTiles * TILE, CLEAR);
			landX = launchX + pl.landDx;
			nextRow = row - upTiles;
			nearCol = Math.max(launchCol + 2, colAtOrAfter(launchX + (pl.nearEdgeDx ?? 60)));
			features.push({ type: "up", upTiles, K });
		} else {
			const downTiles = randint(rng, 1, 2);
			K = MODEL.holds[1];
			landX = launchX + stepDownLandingDx(entryVx, K, downTiles * TILE);
			nextRow = row + downTiles;
			nearCol = Math.max(launchCol + 2, colNearest(landX) - 1);
			features.push({ type: "down", downTiles, K });
		}
		at = Math.round(airtime(K));
		doJump(K, at);

		const landCol = colNearest(landX);
		const platRight = Math.min(RIGHT_LIMIT, Math.max(landCol, nearCol) + INTER);
		nextRow = clampRow(nextRow);
		lvl.fillRect(nearCol, nextRow, platRight, nextRow, TILE_FULL);
		row = nextRow;
		platEnd = platRight;
		x = landX; vx = MAX_SPEED; // cruise speed carried out of the jump
		// Chaining AFTER a height change (step) is not yet reliable open-loop —
		// the landing estimate off a stepped platform drifts enough to mistrigger
		// the next jump. Gaps (same-level) chain fine. So a step terminates the
		// chain; multi-step vertical courses are the vertical/serpentine work.
		if (type !== "gap") break;
	}

	// Exit on the final platform (extend it if there's room).
	const exitEnd = Math.min(COLS - 1, platEnd + EXIT_RESERVE);
	if (exitEnd > platEnd) lvl.fillRect(platEnd + 1, row, exitEnd, row, TILE_FULL);
	platEnd = exitEnd;
	const doorCol = platEnd - 1, switchCol = platEnd - 2;
	lvl.addObject(OBJ.EXIT, [cellToPixel(doorCol, row).x, restY(row), cellToPixel(switchCol, row).x, restY(row)]);
	runTo(cellToPixel(doorCol, row).x + 30);
	for (let i = 0; i < 20; i++) seq.push(IN.R);

	return {
		levelId: `course-s${seed >>> 0}`,
		level: lvl.encode(),
		demo: encodeDemo(seq),
		meta: { seed: seed >>> 0, nFeatures: features.length, features: features.map((f) => f.type + (f.W || f.upTiles || f.downTiles)), endRow: row, endCol: platEnd, ticks: seq.length },
	};
}

/** Generate `count` distinct courses from consecutive seeds. */
export function generateCourseBatch(count, baseSeed = 1, opts = {}) {
	const out = [];
	for (let i = 0; i < count; i++) out.push(generateCourseLevel((baseSeed + i) >>> 0, opts));
	return out;
}
