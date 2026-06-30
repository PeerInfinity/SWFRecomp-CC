// nLevel.js - the N level model + encoder/decoder.
//
// A level for N ("the way of the ninja", Metanet) is a 31x23 tile grid plus a
// list of typed objects, serialized as `mapStr "|" objStr` and handed to N's
// own `App_LoadLevel_Raw(levStr, cb)`. Format facts (decoded; see
// SWFRecompDocs/status/2026-06-30-n-substrate-investigation.md):
//
//   - Grid is COLS=31 (X) by ROWS=23 (Y).
//   - mapStr: one char per tile, COLS*ROWS = 713 chars, COLUMN-MAJOR with X
//     outer and Y inner -> char index = mx*ROWS + my. Tile state = charCode-48
//     (CHAR_PAD=48); '0' = empty, '1' = full solid; 2..33 = slope/half family.
//   - objStr: objects joined by "!", each "<type>^<p0>,<p1>,...". Empty objStr
//     means no objects.
//   - Pixel mapping (1-tile solid border around the playfield): map cell
//     (mx,my) center = (mx*24+36, my*24+36). Object params are free pixel coords.
//
// This module generalizes n_host_mock.js::buildWalkLevel(). It is plain ES
// modules, no deps, usable from node and the browser.

export const COLS = 31; // X (columns)
export const ROWS = 23; // Y (rows)
export const CELL_COUNT = COLS * ROWS; // 713
export const TILE = 24; // pixel size of one tile
export const CHAR_PAD = 48; // tile state <-> char offset
export const PIX_OFF = 36; // cell-center pixel offset (12 + one border tile of 24)

// Tile state codes (charCode-48). 0 empty, 1 full; the rest are the slope/half
// family - see the status doc's tile table. We model state as a raw int so any
// shipped tile survives round-trip; named constants cover the common cases.
export const TILE_EMPTY = 0;
export const TILE_FULL = 1;

// Object type codes (status doc "Object type + Init params").
export const OBJ = {
	GOLD: 0,           // [x,y]
	BOUNCEBLOCK: 1,    // [x,y]
	LAUNCHPAD: 2,      // [x,y,nx,ny]
	TURRET: 3,         // [x,y]
	FLOORGUARD: 4,     // [x,y,dir]
	PLAYER: 5,         // [x,y]
	DRONE: 6,          // [x,y,movetype,isChaser,weaptype,dir]
	ONEWAYPLATFORM: 7, // [x,y,dir]
	THWOMP: 8,         // [x,y,dir]
	TESTDOOR: 9,       // [x,y,vert,isTrap,doorI,doorJ,isLocked,dI,dJ]
	HOMINGLAUNCHER: 10,// [x,y]
	EXIT: 11,          // [doorX,doorY,switchX,switchY]
	MINE: 12,          // [x,y]
};

// ---- cell <-> pixel helpers --------------------------------------------------

/** Pixel center of map cell (mx,my). */
export function cellToPixel(mx, my) {
	return { x: mx * TILE + PIX_OFF, y: my * TILE + PIX_OFF };
}

/** Map cell whose center is nearest pixel (x,y). */
export function pixelToCell(x, y) {
	return { mx: Math.round((x - PIX_OFF) / TILE), my: Math.round((y - PIX_OFF) / TILE) };
}

/** Flat mapStr index for cell (mx,my) - column-major, X outer / Y inner. */
export function cellIndex(mx, my) {
	return mx * ROWS + my;
}

// ---- the Level model ---------------------------------------------------------

export class Level {
	constructor() {
		// Flat tile grid, length CELL_COUNT, indexed by cellIndex(mx,my).
		this.tiles = new Int16Array(CELL_COUNT); // defaults all-empty (0)
		// Objects in authoring order: { type:int, params:number[] }.
		this.objects = [];
	}

	inBounds(mx, my) {
		return mx >= 0 && mx < COLS && my >= 0 && my < ROWS;
	}

	getTile(mx, my) {
		if (!this.inBounds(mx, my)) return TILE_EMPTY;
		return this.tiles[cellIndex(mx, my)];
	}

	setTile(mx, my, state) {
		if (!this.inBounds(mx, my)) throw new RangeError(`cell (${mx},${my}) out of 31x23 bounds`);
		this.tiles[cellIndex(mx, my)] = state | 0;
		return this;
	}

	fillRect(mx0, my0, mx1, my1, state = TILE_FULL) {
		for (let mx = mx0; mx <= mx1; mx++)
			for (let my = my0; my <= my1; my++)
				if (this.inBounds(mx, my)) this.tiles[cellIndex(mx, my)] = state | 0;
		return this;
	}

	addObject(type, params) {
		this.objects.push({ type: type | 0, params: params.map(Number) });
		return this;
	}

	// Convenience object adders (pixel coords, matching N's params).
	setPlayer(x, y) { return this.addObject(OBJ.PLAYER, [x, y]); }
	setExit(doorX, doorY, switchX, switchY) {
		return this.addObject(OBJ.EXIT, [doorX, doorY, switchX, switchY]);
	}
	addGold(x, y) { return this.addObject(OBJ.GOLD, [x, y]); }

	encode() { return encode(this); }
}

// ---- encode / decode ---------------------------------------------------------

/** Serialize a Level to N's `mapStr "|" objStr` string. */
export function encode(level) {
	let mapStr = "";
	// Column-major: X outer, Y inner -> matches cellIndex(mx,my) = mx*ROWS+my.
	for (let mx = 0; mx < COLS; mx++) {
		for (let my = 0; my < ROWS; my++) {
			mapStr += String.fromCharCode((level.tiles[cellIndex(mx, my)] | 0) + CHAR_PAD);
		}
	}
	const objStr = level.objects
		.map((o) => `${o.type}^${o.params.map(String).join(",")}`)
		.join("!");
	return `${mapStr}|${objStr}`;
}

/** Parse N's `mapStr "|" objStr` string into a Level. */
export function decode(str) {
	const pipe = str.indexOf("|");
	if (pipe < 0) throw new Error("level string has no '|' map/obj separator");
	const mapStr = str.slice(0, pipe);
	const objStr = str.slice(pipe + 1);
	if (mapStr.length !== CELL_COUNT)
		throw new Error(`mapStr length ${mapStr.length} != ${CELL_COUNT} (${COLS}x${ROWS})`);

	const level = new Level();
	for (let i = 0; i < CELL_COUNT; i++) level.tiles[i] = mapStr.charCodeAt(i) - CHAR_PAD;

	if (objStr.length > 0) {
		for (const tok of objStr.split("!")) {
			const caret = tok.indexOf("^");
			if (caret < 0) throw new Error(`object token has no '^': ${tok}`);
			const type = Number(tok.slice(0, caret));
			const rest = tok.slice(caret + 1);
			const params = rest.length > 0 ? rest.split(",").map(Number) : [];
			level.objects.push({ type, params });
		}
	}
	return level;
}

// ---- convenience builder (generalizes buildWalkLevel) ------------------------

/**
 * Build a flat grounded walk level: a solid floor row, a player spawn, and an
 * exit (switch + door) on that floor, optional gold. All positions in CELLS.
 * Returns a Level. (The page-side n_host_mock buildWalkLevel() is the special
 * case floorRow=14, x 8..18, spawn col ~10.)
 */
export function buildFloorLevel({ floorRow, floorX0, floorX1, playerCell, switchCell, doorCell, goldCells = [] }) {
	const lvl = new Level();
	lvl.fillRect(floorX0, floorRow, floorX1, floorRow, TILE_FULL);
	const p = cellToPixel(playerCell[0], playerCell[1]);
	const s = cellToPixel(switchCell[0], switchCell[1]);
	const d = cellToPixel(doorCell[0], doorCell[1]);
	lvl.setPlayer(p.x, p.y);
	lvl.setExit(d.x, d.y, s.x, s.y);
	for (const [cx, cy] of goldCells) {
		const g = cellToPixel(cx, cy);
		lvl.addGold(g.x, g.y);
	}
	return lvl;
}
