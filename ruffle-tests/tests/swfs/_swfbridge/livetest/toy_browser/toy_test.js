// toy_test.js — Playwright driver for the __swfBridge Mode-1 substrate toy.
// Loads harness.html in REAL headed google-chrome (WebGPU needs a GPU
// compositor — Playwright's bundled headless chromium has no navigator.gpu;
// headed chrome via WSLg/DISPLAY does, on a localhost secure-context page),
// clicks Run, and asserts the full __swfBridge contract round-trip:
//   - ExternalInterface.available is true (the opt-in C bridge installed),
//   - the game reported both objectives outward (host recorded chest + enemy),
//   - the game pulled + applied the host-delivered items (sword, key),
//   - reached DONE.
//
// No AP server needed — the harness's mock host plays Archipelago-CC's role.
// Driven by run_toy_livetest.sh, which builds the graphics WASM and serves it.

const { chromium } = require('playwright');

const URL = process.env.HARNESS_URL || 'http://127.0.0.1:8087/harness.html';
const CHROME = process.env.CHROME || '/usr/bin/google-chrome';
const T = 45000;

(async () => {
	const lines = [];
	let resolveDone;
	const donePromise = new Promise((res) => { resolveDone = res; });

	const browser = await chromium.launch({
		executablePath: CHROME,
		headless: false,   // headed: WebGPU needs a real compositor (WSLg/DISPLAY)
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
		}, null, { timeout: 20000 });
		await page.click('#btn-run');

		const timeout = new Promise((res) => setTimeout(() => res(false), T));
		await Promise.race([donePromise, timeout]);
		await page.waitForTimeout(300);   // flush trailing logs

		// Read the host-recorded outward location checks.
		sentLocations = await page.evaluate(() => window.__sentLocations || []);
		console.log('  [driver] host recorded sendLocation:', JSON.stringify(sentLocations));
	} finally {
		await browser.close();
	}

	const has = (s) => lines.some((l) => l.indexOf(s) !== -1);
	let failures = 0;
	const check = (cond, msg) => { if (!cond) { console.log('FAIL:', msg); failures++; } else { console.log('PASS:', msg); } };

	check(has('[toy] EI available=true'), 'ExternalInterface.available is true (opt-in bridge installed)');
	check(has('[swfBridge] configure'), 'host configure() reached the bridge');
	check(has('[toy] sending location checks'), 'game sent its objective checks outward');
	check(sentLocations.indexOf('chest') !== -1, 'host recorded sendLocation("chest")');
	check(sentLocations.indexOf('enemy') !== -1, 'host recorded sendLocation("enemy")');
	check(has('apply: sword -> attack enabled'), 'Sword item pulled + applied (Sword -> sword)');
	check(has('apply: key -> door unlocked'), 'Key item pulled + applied (Key -> key)');
	check(has('[toy] DONE'), 'reached DONE (both effects applied)');

	if (failures > 0) {
		console.log(`\nRESULT: FAIL (${failures} failed assertion(s))`);
		process.exit(1);
	}
	console.log('\nRESULT: PASS');
	process.exit(0);
})().catch((e) => { console.error('harness error:', e); process.exit(2); });
