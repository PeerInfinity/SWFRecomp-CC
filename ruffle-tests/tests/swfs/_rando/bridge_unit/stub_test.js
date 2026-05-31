// stub_test.js — Playwright driver for the rando_bridge.js StubTransport.
// Loads stub.html in headless chromium and drives window.__randoBridge with the
// stub transport (no server, no WebSocket): a pure transport-contract test that
// the bridge's AS-facing API behaves correctly over the StubTransport. The
// WebSocket path is covered by ../livetest/browser/; the native synthetic
// backend (rando_stub.c) by ../rando_item_application. Run by run_stub_test.sh.
//
// Reuses Playwright via NODE_PATH (the runner points it at a node_modules that
// has 'playwright' — currently the Archipelago-CC repo).

const { chromium } = require('playwright');

const URL = process.env.HARNESS_URL || 'http://127.0.0.1:8078/stub.html';

(async () => {
	let failures = 0;
	const check = (cond, msg) => { if (!cond) { console.log('FAIL:', msg); failures++; } else { console.log('PASS:', msg); } };

	const browser = await chromium.launch({ headless: true, args: ['--no-sandbox'] });
	try {
		const page = await browser.newPage();
		page.on('console', (m) => console.log('  [page]', m.text()));
		page.on('pageerror', (e) => console.log('  [pageerror]', e.message));

		await page.goto(URL, { waitUntil: 'load' });
		await page.waitForFunction(() => !!window.__randoBridge, null, { timeout: 10000 });

		const r = await page.evaluate(() => {
			const B = window.__randoBridge;
			const id = B.init("h", "1", "APQuest", "Player1", "");
			const before = { connected: B.isConnected(id), size: B.receivedItemsSize(id) };
			B.connect(id);
			const afterConnect = {
				connected: B.isConnected(id),
				size: B.receivedItemsSize(id),
				hasStart: B.hasItem(id, 80002),
				grantNotYet: B.hasItem(id, 80000),
				locChecked: B.locationIsChecked(id, 81001),
			};
			B.sendLocation(id, 81001);
			const afterSend = {
				locChecked: B.locationIsChecked(id, 81001),
				hasGrant: B.hasItem(id, 80000),
				size: B.receivedItemsSize(id),
				item0: B.receivedItem(id, 0),
				item1: B.receivedItem(id, 1),
				oob: B.receivedItem(id, 9),
				status: B.latestStatus(),
			};
			return { before, afterConnect, afterSend };
		});

		const a = r.afterConnect, s = r.afterSend;
		check(r.before.connected === false && r.before.size === 0, "not connected before connect()");
		check(a.connected === true, "connected after connect()");
		check(a.size === 1 && a.hasStart === true, "starting item 80002 delivered on connect");
		check(a.grantNotYet === false, "grant item 80000 NOT present before sendLocation");
		check(a.locChecked === false, "location 81001 not checked before sendLocation");
		check(s.locChecked === true, "location 81001 checked after sendLocation");
		check(s.hasGrant === true && s.size === 2, "grant item 80000 delivered after sendLocation");
		check(s.item0 === 80002 && s.item1 === 80000 && s.oob === -1, "receivedItem indexing + OOB");
		check(s.status === "connected — 2 item(s) received", "latestStatus text");
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
