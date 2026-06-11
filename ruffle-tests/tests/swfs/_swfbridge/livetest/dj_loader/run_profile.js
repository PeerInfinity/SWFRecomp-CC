// run_profile.js — load the WASM harness, wait for the runtime hang (console
// goes silent), then CPU-profile the busy main thread via CDP and print the
// hottest functions. V8's sampling profiler interrupts a spinning main
// thread, and emcc keeps the wasm name section, so the offending runtime
// function shows up by name.
//
// Env: HARNESS_URL, CHROME, HANG_SILENCE_MS (default 4000), MAX_WAIT_S (60),
//      PROFILE_MS (default 3000).
const { chromium } = require('playwright');

const URL = process.env.HARNESS_URL;
const CHROME = process.env.CHROME || '/usr/bin/google-chrome';
const SILENCE = parseInt(process.env.HANG_SILENCE_MS || '4000', 10);
const MAX_WAIT = parseInt(process.env.MAX_WAIT_S || '60', 10) * 1000;
const PROFILE_MS = parseInt(process.env.PROFILE_MS || '3000', 10);

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
		// Arm the profiler BEFORE the hang: Profiler.start on a busy thread
		// would block, so start sampling up front and stop after the hang.
		const client = await page.context().newCDPSession(page);
		await client.send('Profiler.enable');
		await client.send('Profiler.setSamplingInterval', { interval: 200 });
		await client.send('Profiler.start');

		await page.goto(URL, { waitUntil: 'load' });
		const t0 = Date.now();
		// Wait until ticks started AND console then went silent (the hang).
		for (;;) {
			await new Promise((r) => setTimeout(r, 500));
			if (sawTick && Date.now() - lastLine > SILENCE) break;
			if (Date.now() - t0 > MAX_WAIT) { console.log('[profiler] no hang detected'); break; }
		}
		console.log('[profiler] hang detected; sampling ' + PROFILE_MS + 'ms more');
		await new Promise((r) => setTimeout(r, PROFILE_MS));
		const { profile } = await client.send('Profiler.stop');
		// Aggregate self time per function.
		const nodes = new Map(profile.nodes.map((n) => [n.id, n]));
		const self = new Map();
		const total = profile.samples.length;
		// Only count samples in the tail (the hang window): last 60%.
		const tail = profile.samples.slice(Math.floor(total * 0.4));
		for (const id of tail) {
			const n = nodes.get(id);
			if (!n) continue;
			const f = n.callFrame;
			const key = (f.functionName || '(anon)') + ' @' + (f.url || '').split('/').pop();
			self.set(key, (self.get(key) || 0) + 1);
		}
		const top = [...self.entries()].sort((a, b) => b[1] - a[1]).slice(0, 20);
		console.log('[profiler] top frames over ' + tail.length + ' tail samples:');
		for (const [k, v] of top) {
			console.log('  ' + ((100 * v) / tail.length).toFixed(1) + '%  ' + k);
		}
	} finally {
		await browser.close();
	}
})();
