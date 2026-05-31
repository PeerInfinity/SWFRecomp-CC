// browser_livetest.js — Playwright driver for the WASM/browser transport test.
// Loads harness.html in headless chromium and drives window.__randoBridge
// (rando_bridge.js + archipelago.js) against a live local AP server, asserting
// the full round-trip. Transport-level: no WASM/SWF/WebGPU.
//
// Reuses Playwright via NODE_PATH (the runner points it at a node_modules that
// has 'playwright' — currently the Archipelago-CC repo; set NODE_PATH to a
// SWFRecomp-local install later). Run by run_browser_livetest.sh.
//
// Fixture: ChecksFinder seed 1, slot Player1, no password. Unlike the native
// APCpp path, archipelago.js does NOT filter own-location items, so the item
// granted by checking Tile 2 (80000) DOES appear in received items here.

const { chromium } = require('playwright');

const URL = process.env.HARNESS_URL || 'http://localhost:8076/harness.html';
// Use 127.0.0.1, not "localhost": setup_ap_server.py binds the AP server to
// 127.0.0.1 only, and headless chromium resolves "localhost" to IPv6 (::1)
// first → connection refused. Forcing IPv4 matches the server's bind.
const HOST = '127.0.0.1', PORT = '38281', GAME = 'ChecksFinder', SLOT = 'Player1', PW = '';
const ITEM_ON_CONNECT = 80002, LOCATION = 81001, ITEM_FROM_CHECK = 80000;
const T = 25000;

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
			([h, p, g, s, pw]) => window.__randoBridge.init(h, p, g, s, pw),
			[HOST, PORT, GAME, SLOT, PW]);
		await page.evaluate((i) => window.__randoBridge.connect(i), id);

		// 1) connected
		try {
			await page.waitForFunction((i) => window.__randoBridge.isConnected(i), id, { timeout: T });
			console.log(`PASS: connected to ${HOST}:${PORT} as ${GAME}/${SLOT}`);
		} catch {
			console.log('FAIL: not connected within timeout');
			failures++;
		}

		// 2) starting item on connect
		try {
			await page.waitForFunction((i) => window.__randoBridge.hasItem(i, 80002), id, { timeout: T });
			console.log(`PASS: received starting item ${ITEM_ON_CONNECT} (Map Bombs)`);
		} catch {
			console.log(`FAIL: starting item ${ITEM_ON_CONNECT} not received`);
			failures++;
		}

		// 3) sendLocation -> checked (round-trip confirmation)
		await page.evaluate((i) => window.__randoBridge.sendLocation(i, 81001), id);
		try {
			await page.waitForFunction((i) => window.__randoBridge.locationIsChecked(i, 81001), id, { timeout: T });
			console.log(`PASS: location ${LOCATION} (Tile 2) checked (sendLocation round-trip)`);
		} catch {
			console.log(`FAIL: location ${LOCATION} not checked`);
			failures++;
		}

		// 4) granted item (archipelago.js does NOT filter own-location items)
		try {
			await page.waitForFunction((i) => window.__randoBridge.hasItem(i, 80000), id, { timeout: T });
			console.log(`PASS: received granted item ${ITEM_FROM_CHECK} (Map Width)`);
		} catch {
			console.log(`FAIL: granted item ${ITEM_FROM_CHECK} not received`);
			failures++;
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
