// browser_livetest.js — Playwright driver for the WASM/browser transport test.
// Loads harness.html in headless chromium and drives window.__randoBridge
// (rando_bridge.js + archipelago.js) against a live local AP server, asserting
// the full round-trip. Transport-level: no WASM/SWF/WebGPU.
//
// Fixture-driven: process.env.GAME (default 'checksfinder') selects a FIXTURES
// entry below; run_browser_livetest.sh starts the matching server. Unlike the
// native APCpp path, archipelago.js does NOT filter own-location items, so the
// item a checked location grants DOES appear in received items here — hence
// every check asserts its granted item.
//
// Reuses Playwright via NODE_PATH (the runner points it at a node_modules that
// has 'playwright' — currently the Archipelago-CC repo).

const { chromium } = require('playwright');

const URL = process.env.HARNESS_URL || 'http://localhost:8076/harness.html';
// Use 127.0.0.1, not "localhost": setup_ap_server.py binds the AP server to
// 127.0.0.1 only, and headless chromium resolves "localhost" to IPv6 (::1)
// first → connection refused. Forcing IPv4 matches the server's bind.
const HOST = '127.0.0.1';
const PORT = process.env.AP_PORT || '38281';
const T = 25000;

// Per-game fixtures. Verified live against setup_ap_server.py --game <g> --seed 1
// (ids used directly; ap_id_offset = 0 for both).
const FIXTURES = {
	checksfinder: {
		game: 'ChecksFinder', slot: 'Player1',
		startingItems: [{ id: 80002, name: 'Map Bombs' }],
		checks: [{ loc: 81001, name: 'Tile 2', grants: { id: 80000, name: 'Map Width' } }],
	},
	apquest: {
		game: 'APQuest', slot: 'Player1',
		startingItems: [],   // Start With One Confetti Cannon: No → nothing on connect
		checks: [
			{ loc: 2,  name: 'Top Middle Chest',      grants: { id: 2, name: 'Sword' } },
			{ loc: 10, name: 'Right Room Enemy Drop', grants: { id: 1, name: 'Key' } },
		],
	},
};

const GAME = process.env.GAME || 'checksfinder';
const F = FIXTURES[GAME];
if (!F) { console.error(`unknown GAME '${GAME}' (expected: ${Object.keys(FIXTURES).join(' | ')})`); process.exit(2); }

(async () => {
	let failures = 0;
	const browser = await chromium.launch({ headless: true, args: ['--no-sandbox'] });
	try {
		const page = await browser.newPage();
		page.on('console', (m) => console.log('  [page]', m.text()));
		page.on('pageerror', (e) => console.log('  [pageerror]', e.message));

		await page.goto(URL, { waitUntil: 'load' });
		await page.waitForFunction(() => !!window.__randoBridge, null, { timeout: 10000 });

		const id = await page.evaluate(
			([h, p, g, s]) => window.__randoBridge.init(h, p, g, s, ''),
			[HOST, PORT, F.game, F.slot]);
		await page.evaluate((i) => window.__randoBridge.connect(i), id);

		// 1) connected
		try {
			await page.waitForFunction((i) => window.__randoBridge.isConnected(i), id, { timeout: T });
			console.log(`PASS: connected to ${HOST}:${PORT} as ${F.game}/${F.slot}`);
		} catch {
			console.log('FAIL: not connected within timeout');
			failures++;
		}

		// 2) starting items on connect (if any)
		for (const it of F.startingItems) {
			try {
				await page.waitForFunction((args) => window.__randoBridge.hasItem(args[0], args[1]), [id, it.id], { timeout: T });
				console.log(`PASS: received starting item ${it.id} (${it.name})`);
			} catch {
				console.log(`FAIL: starting item ${it.id} (${it.name}) not received`);
				failures++;
			}
		}
		if (F.startingItems.length === 0) {
			console.log('info: no starting items expected on connect');
		}

		// 3) each location check → checked (round-trip) → granted item appears
		for (const c of F.checks) {
			await page.evaluate((args) => window.__randoBridge.sendLocation(args[0], args[1]), [id, c.loc]);
			try {
				await page.waitForFunction((args) => window.__randoBridge.locationIsChecked(args[0], args[1]), [id, c.loc], { timeout: T });
				console.log(`PASS: location ${c.loc} (${c.name}) checked (sendLocation round-trip)`);
			} catch {
				console.log(`FAIL: location ${c.loc} (${c.name}) not checked`);
				failures++;
			}
			if (c.grants) {
				try {
					await page.waitForFunction((args) => window.__randoBridge.hasItem(args[0], args[1]), [id, c.grants.id], { timeout: T });
					console.log(`PASS: received granted item ${c.grants.id} (${c.grants.name})`);
				} catch {
					console.log(`FAIL: granted item ${c.grants.id} (${c.grants.name}) not received`);
					failures++;
				}
			}
		}

		const size = await page.evaluate((i) => window.__randoBridge.receivedItemsSize(i), id);
		console.log(`info: receivedItemsSize=${size}`);
	} finally {
		await browser.close();
	}

	if (failures > 0) {
		console.log(`\nRESULT: FAIL (${failures} failed assertion(s))`);
		process.exit(1);
	}
	console.log('\nRESULT: PASS');
	process.exit(0);
})().catch((e) => { console.error('harness error:', e); process.exit(2); });
