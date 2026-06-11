// run_pausestack.js — load the WASM harness, wait for the runtime hang
// (console goes silent), then Debugger.pause the busy main thread via CDP
// (V8 interrupts work on spinning JS/wasm) and print the call stack. emcc
// keeps the wasm name section, so runtime function names appear directly.
//
// Env: HARNESS_URL, CHROME, HANG_SILENCE_MS (default 4000), MAX_WAIT_S (60).
const { chromium } = require('playwright');

const URL = process.env.HARNESS_URL;
const CHROME = process.env.CHROME || '/usr/bin/google-chrome';
const SILENCE = parseInt(process.env.HANG_SILENCE_MS || '4000', 10);
const MAX_WAIT = parseInt(process.env.MAX_WAIT_S || '60', 10) * 1000;

(async () => {
	const browser = await chromium.launch({
		executablePath: CHROME,
		headless: false,
		args: ['--enable-unsafe-webgpu', '--ignore-gpu-blocklist', '--no-sandbox'],
	});
	try {
		const page = await browser.newPage();
		let lastLine = Date.now();
		let sawTick = false;
		page.on('console', (m) => {
			lastLine = Date.now();
			const t = m.text();
			if (/^LT\d+ /.test(t)) sawTick = true;
			console.log(t);
		});
		const client = await page.context().newCDPSession(page);
		await client.send('Debugger.enable');

		const paused = new Promise((resolve) => {
			client.on('Debugger.paused', (ev) => resolve(ev));
		});

		await page.goto(URL, { waitUntil: 'load' });
		const t0 = Date.now();
		for (;;) {
			await new Promise((r) => setTimeout(r, 500));
			if (sawTick && Date.now() - lastLine > SILENCE) break;
			if (Date.now() - t0 > MAX_WAIT) { console.log('[pauser] no hang detected'); break; }
		}
		console.log('[pauser] hang detected -> Debugger.pause');
		await client.send('Debugger.pause');
		const ev = await Promise.race([
			paused,
			new Promise((r) => setTimeout(() => r(null), 10000)),
		]);
		if (!ev) {
			console.log('[pauser] pause did not land within 10s');
			return;
		}
		console.log('[pauser] paused, reason=' + ev.reason + ', stack:');
		for (const f of ev.callFrames.slice(0, 40)) {
			const loc = f.location || {};
			console.log('  ' + (f.functionName || '(anon)') + '  [' + (f.url || '')
				.split('/').pop() + ':' + (loc.lineNumber ?? '?') + ']');
		}
		// Resume + pause twice more to confirm the loop (different samples).
		for (let i = 0; i < 2; i++) {
			const again = new Promise((resolve) => client.once('Debugger.paused', resolve));
			await client.send('Debugger.resume');
			await new Promise((r) => setTimeout(r, 700));
			await client.send('Debugger.pause');
			const e2 = await Promise.race([again, new Promise((r) => setTimeout(() => r(null), 8000))]);
			if (e2) {
				console.log('[pauser] sample ' + (i + 2) + ' top: '
					+ e2.callFrames.slice(0, 6).map((f) => f.functionName || '(anon)').join(' < '));
			}
		}
	} finally {
		await browser.close();
	}
})();
