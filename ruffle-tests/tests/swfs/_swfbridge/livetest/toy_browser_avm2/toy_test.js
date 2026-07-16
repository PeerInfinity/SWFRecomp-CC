// toy_test.js — Playwright driver for the AVM2 ExternalInterface toy.
// The AS3/BridgeGeneric-contract counterpart of ../toy_browser/toy_test.js:
// loads harness.html in REAL headed google-chrome (WebGPU needs a GPU
// compositor — headless chromium has no navigator.gpu; headed chrome via
// WSLg/DISPLAY does, on a localhost secure-context page), clicks Run, and
// asserts the 8-probe round-trip of the AVM2 EI subset:
//   1. ExternalInterface.available true (window.__swfBridge gate installed)
//   2. inbound wireCheck() -> "ok"
//   3. inbound configure(json) -> "ok" (+ the game logged the payload)
//   4. inbound readState() -> parseable JSON with the toy's fields
//   5. outward stateChanged("attackEnabled", true) with a TYPED boolean
//   6. outward stateChanged("doorUnlocked", true) with a TYPED boolean
//   7. items pulled + applied via outward getItemQueue (sword + key)
//   8. reached DONE
//
// No AP server needed — the harness's mock host plays the adapter role.
// Driven by run_toy_livetest.sh, which builds the AVM2 wasm and serves it.

const { chromium } = require('playwright');

const URL = process.env.HARNESS_URL || 'http://127.0.0.1:8088/harness.html';
const CHROME = process.env.CHROME || '/usr/bin/google-chrome';
const T = 60000;

(async () => {
	const lines = [];
	let resolveDone;
	const donePromise = new Promise((res) => { resolveDone = res; });

	const browser = await chromium.launch({
		executablePath: CHROME,
		headless: false,   // headed: WebGPU needs a real compositor (WSLg/DISPLAY)
		args: ['--enable-unsafe-webgpu', '--ignore-gpu-blocklist', '--no-sandbox'],
	});
	let hostResults = {};
	let stateChanges = [];
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
		await page.waitForTimeout(1800);   // flush trailing logs + final readState

		hostResults = await page.evaluate(() => window.__hostResults || {});
		stateChanges = await page.evaluate(() => window.__stateChanges || []);
		console.log('  [driver] hostResults:', JSON.stringify(hostResults));
		console.log('  [driver] stateChanges:', JSON.stringify(stateChanges));
	} finally {
		await browser.close();
	}

	const has = (s) => lines.some((l) => l.indexOf(s) !== -1);
	let failures = 0;
	const check = (cond, msg) => { if (!cond) { console.log('FAIL:', msg); failures++; } else { console.log('PASS:', msg); } };

	let state = null;
	try { state = JSON.parse(hostResults.readState); } catch (e) {}
	const sc = (n) => stateChanges.find((s) => s.name === n);

	check(has('[toy] EI available=true'), 'ExternalInterface.available is true (opt-in bridge installed)');
	check(hostResults.wireCheck === 'ok', 'inbound wireCheck() returned "ok"');
	check(hostResults.configureRet === 'ok' && has('[toy] configured:'), 'inbound configure(json) returned "ok" and reached the game');
	check(state !== null && state.attackEnabled === false && typeof state.frames === 'number', 'inbound readState() returned parseable initial JSON');
	check(!!sc('attackEnabled') && sc('attackEnabled').value === true, 'outward stateChanged("attackEnabled", true) with typed boolean');
	check(!!sc('doorUnlocked') && sc('doorUnlocked').value === true, 'outward stateChanged("doorUnlocked", true) with typed boolean');
	check(has('apply: sword -> attack enabled') && has('apply: key -> door unlocked'), 'items pulled + applied via getItemQueue (sword + key)');
	check(has('[toy] DONE'), 'reached DONE (both effects applied)');

	if (failures > 0) {
		console.log(`\nRESULT: FAIL (${failures} failed assertion(s))`);
		process.exit(1);
	}
	console.log('\nRESULT: PASS');
	process.exit(0);
})().catch((e) => { console.error('harness error:', e); process.exit(2); });
