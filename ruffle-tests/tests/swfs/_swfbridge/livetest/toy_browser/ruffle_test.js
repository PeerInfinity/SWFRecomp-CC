// ruffle_test.js — Playwright driver for the __swfBridge runtime-neutrality
// check under Ruffle web (AVM1). Loads ruffle_harness.html, clicks Run, and
// asserts the SAME 8 conditions as the SWFRecomp WASM livetest (toy_test.js) —
// proving the swf_bridge.js shim + minigame round-trip identically under Ruffle.
//
// Ruffle uses WebGL/canvas (not WebGPU), so it can run under headless chromium;
// we still drive headed google-chrome for parity with the WASM harness + a real
// GPU, and because Ruffle needs network access to the CDN bundle.

const { chromium } = require('playwright');

const URL = process.env.HARNESS_URL || 'http://127.0.0.1:8088/ruffle_harness.html';
const CHROME = process.env.CHROME || '/usr/bin/google-chrome';
const T = 45000;

(async () => {
	const lines = [];
	let resolveDone;
	const donePromise = new Promise((res) => { resolveDone = res; });

	const browser = await chromium.launch({
		executablePath: CHROME,
		headless: false,
		args: ['--enable-unsafe-webgpu', '--ignore-gpu-blocklist', '--no-sandbox'],
	});
	let sentLocations = [];
	try {
		const page = await browser.newPage();
		const onLine = (t) => { lines.push(t); console.log('  [page]', t); if (t.indexOf('[toy] DONE') !== -1) resolveDone(true); };
		page.on('console', (m) => onLine(m.text()));
		page.on('pageerror', (e) => onLine('PAGEERROR: ' + e.message));

		await page.goto(URL, { waitUntil: 'load' });

		await page.waitForFunction(() => {
			const b = document.getElementById('btn-run');
			return b && !b.disabled;
		}, null, { timeout: 25000 });
		await page.click('#btn-run');

		const timeout = new Promise((res) => setTimeout(() => res(false), T));
		await Promise.race([donePromise, timeout]);
		await page.waitForTimeout(400);

		sentLocations = await page.evaluate(() => window.__sentLocations || []);
		console.log('  [driver] host recorded sendLocation:', JSON.stringify(sentLocations));
	} finally {
		await browser.close();
	}

	const has = (s) => lines.some((l) => l.indexOf(s) !== -1);
	let failures = 0;
	const check = (cond, msg) => { if (!cond) { console.log('FAIL:', msg); failures++; } else { console.log('PASS:', msg); } };

	check(has('[toy] EI available=true'), 'ExternalInterface.available is true under Ruffle');
	check(has('[swfBridge] configure'), 'host configure() reached the bridge');
	check(has('[toy] sending location checks'), 'game sent its objective checks outward (EI .call)');
	check(sentLocations.indexOf('chest') !== -1, 'host recorded sendLocation("chest") — outward round-trip');
	check(sentLocations.indexOf('enemy') !== -1, 'host recorded sendLocation("enemy") — outward round-trip');
	check(has('apply: sword -> attack enabled'), 'Sword pulled + applied — inward return-value pull');
	check(has('apply: key -> door unlocked'), 'Key pulled + applied — inward return-value pull');
	check(has('[toy] DONE'), 'reached DONE (both effects applied)');

	if (failures > 0) {
		console.log(`\nRESULT: FAIL (${failures} failed assertion(s))`);
		process.exit(1);
	}
	console.log('\nRESULT: PASS');
	process.exit(0);
})().catch((e) => { console.error('harness error:', e); process.exit(2); });
