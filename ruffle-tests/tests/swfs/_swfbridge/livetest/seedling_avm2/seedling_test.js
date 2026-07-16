// seedling_test.js — Playwright driver for the injected-Seedling AVM2 EI
// verification. Runs TWO pages in headed google-chrome (WebGPU via
// WSLg/DISPLAY):
//
//   harness_noshim.html — behavior A: no window.__swfBridge, so the injected
//     BridgeGeneric must no-op silently (EI available=false): zero
//     [BridgeGeneric] output, zero page errors, game boots normally.
//     (The strict gameplay-identity grade is the native headless A/B diff —
//     injected vs plain trace over N frames — run by run_seedling_livetest.sh.)
//
//   harness_shim.html — behavior B: the production shim is loaded and a mock
//     host drives the REAL injected bridge: wireCheck/configure/readState
//     inbound, Main class resolution, stateChanged reports (typed), one
//     hasSword=true property write applied via getItemQueue.

const { chromium } = require('playwright');

const BASE = process.env.HARNESS_BASE || 'http://127.0.0.1:8089';
const CHROME = process.env.CHROME || '/usr/bin/google-chrome';
// FULL_B=0: injected ORIGINAL Seedling — state monitoring is gated on the
// player starting the game (Main.SAVE_FILE set in Main's constructor, behind
// the NG preloader), so only the boot-time B probes are graded.
const FULL_B = process.env.FULL_B !== '0';

async function runPage(browser, url, opts) {
	const lines = [];
	const page = await browser.newPage();
	const onLine = (t) => { lines.push(t); console.log('  [page]', t); };
	page.on('console', (m) => onLine(m.text()));
	page.on('pageerror', (e) => onLine('PAGEERROR: ' + e.message));
	await page.goto(url, { waitUntil: 'load' });
	await page.waitForFunction(() => {
		const b = document.getElementById('btn-run');
		return b && !b.disabled;
	}, null, { timeout: 60000 });
	await page.click('#btn-run');

	if (opts.waitFor) {
		await Promise.race([
			new Promise((res) => {
				const iv = setInterval(() => {
					if (lines.some((l) => l.indexOf(opts.waitFor) !== -1)) { clearInterval(iv); res(true); }
				}, 250);
			}),
			new Promise((res) => setTimeout(() => res(false), opts.timeout)),
		]);
		await page.waitForTimeout(opts.settle || 2000);
	} else {
		await page.waitForTimeout(opts.timeout);
	}

	const state = {
		hostResults: await page.evaluate(() => window.__hostResults || null),
		stateChanges: await page.evaluate(() => window.__stateChanges || null),
	};
	await page.close();
	return { lines, state };
}

(async () => {
	const browser = await chromium.launch({
		executablePath: CHROME,
		headless: false,
		args: ['--enable-unsafe-webgpu', '--ignore-gpu-blocklist', '--no-sandbox'],
	});

	let failures = 0;
	const check = (cond, msg) => { if (!cond) { console.log('FAIL:', msg); failures++; } else { console.log('PASS:', msg); } };

	try {
		// ---- Behavior A: no shim → BridgeGeneric no-ops silently ----
		console.log('\n=== behavior A: no shim (BridgeGeneric must no-op) ===');
		const a = await runPage(browser, BASE + '/harness_noshim.html', { timeout: 25000 });
		const aHas = (s) => a.lines.some((l) => l.indexOf(s) !== -1);
		check(aHas('SWF Execution Started'), 'A: game booted');
		check(!a.lines.some((l) => l.indexOf('[BridgeGeneric]') !== -1), 'A: zero [BridgeGeneric] output (EI gate closed)');
		check(!a.lines.some((l) => l.indexOf('PAGEERROR') !== -1), 'A: no page errors');

		// ---- Behavior B: shim loaded → full BridgeGeneric round-trip ----
		console.log('\n=== behavior B: shim loaded (BridgeGeneric live) ===');
		const b = await runPage(browser, BASE + '/harness_shim.html', FULL_B ? {
			waitFor: '[BridgeGeneric] Applied: hasSword = true',
			timeout: 150000,
			settle: 3000,
		} : {
			waitFor: '[BridgeGeneric] Configured:',
			timeout: 60000,
			settle: 3000,
		});
		const bHas = (s) => b.lines.some((l) => l.indexOf(s) !== -1);
		const hr = b.state.hostResults || {};
		const sc = (b.state.stateChanges || []);
		const scFind = (n) => sc.filter((s) => s.name === n);

		check(bHas('[BridgeGeneric] Ready for configuration'), 'B: bridge alive (EI available + outward console.log)');
		check(hr.wireCheck === 'ok', 'B: inbound wireCheck() -> "ok"');
		check(hr.configureRet === 'ok' && bHas('[BridgeGeneric] Configured:'), 'B: inbound configure(json) -> "ok"');
		check(bHas('[BridgeGeneric] Resolved: Main'), 'B: getDefinitionByName resolved Main');
		if (FULL_B) {
			const initialSword = scFind('hasSword');
			check(initialSword.length > 0 && typeof initialSword[0].value === 'boolean', 'B: stateChanged("hasSword", <boolean>) reported');
			let rs = null;
			try { rs = JSON.parse(hr.readState); } catch (e) {}
			check(rs !== null && ('hasSword' in rs), 'B: inbound readState() -> JSON with hasSword');
			check(bHas('[BridgeGeneric] Applied: hasSword = true'), 'B: getItemQueue write applied (hasSword = true)');
			check(scFind('hasSword').some((s) => s.value === true), 'B: post-write stateChanged("hasSword", true) observed');
		} else {
			console.log('SKIP: state-monitoring probes (original build — game not started; SAVE_FILE is constructor-gated)');
		}
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
