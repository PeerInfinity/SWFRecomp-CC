// toy_test.js — Playwright driver for the browser item-application toy (Phase 3
// Slice 2b). Loads harness.html in REAL headed google-chrome (WebGPU needs a GPU
// compositor — Playwright's bundled headless chromium has no navigator.gpu;
// headed chrome via WSLg/DISPLAY does, on a localhost secure-context page),
// clicks Run, and asserts the toy's live item-application trace against a real
// APQuest server.
//
// Expected console sequence (APQuest seed-1; archipelago.js does not filter
// own-location items): connect → send checks → Sword applied → Key applied → DONE.
//
// Driven by run_toy_livetest.sh, which builds the graphics WASM, starts the AP
// server, serves the assets, and points CHROME/HARNESS_URL here.

const { chromium } = require('playwright');

const URL = process.env.HARNESS_URL || 'http://127.0.0.1:8086/harness.html';
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
	try {
		const page = await browser.newPage();
		const onLine = (t) => { lines.push(t); console.log('  [page]', t); if (t.indexOf('[toy] DONE') !== -1) resolveDone(true); };
		page.on('console', (m) => onLine(m.text()));
		page.on('pageerror', (e) => onLine('PAGEERROR: ' + e.message));

		await page.goto(URL, { waitUntil: 'load' });

		// Wait for the harness to enable Run (runtime + bridge ready), then click.
		await page.waitForFunction(() => {
			const b = document.getElementById('btn-run');
			return b && !b.disabled;
		}, null, { timeout: 20000 });
		await page.click('#btn-run');

		// Wait for the toy's terminal DONE line, or time out.
		const timeout = new Promise((res) => setTimeout(() => res(false), T));
		await Promise.race([donePromise, timeout]);
		await page.waitForTimeout(300);   // flush trailing logs
	} finally {
		await browser.close();
	}

	// Assert against captured console lines.
	const has = (s) => lines.some((l) => l.indexOf(s) !== -1);
	const check = (cond, msg) => { if (!cond) { console.log('FAIL:', msg); failures++; } else { console.log('PASS:', msg); } };
	let failures = 0;

	check(has('[toy] connecting'), 'toy started + attempted connect');
	check(has('[toy] connected; sending location checks'), 'connected and sent location checks');
	check(has('apply: sword -> attack enabled'), 'Sword item applied (Top Middle Chest grant)');
	check(has('apply: key -> door unlocked'), 'Key item applied (Enemy Drop grant)');
	check(has('[toy] DONE'), 'reached DONE (both effects applied)');

	if (failures > 0) {
		console.log(`\nRESULT: FAIL (${failures} failed assertion(s))`);
		process.exit(1);
	}
	console.log('\nRESULT: PASS');
	process.exit(0);
})().catch((e) => { console.error('harness error:', e); process.exit(2); });
