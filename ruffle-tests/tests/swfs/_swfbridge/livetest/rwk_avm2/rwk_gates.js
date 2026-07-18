// rwk_gates.js — the RWK AP sanity gates, run against the packaged game page
// in the same same-origin iframe a host uses. Two things are graded:
//
//   1. EI ROUND-TRIP COST. Times N inbound readState() calls (each one a full
//      JS -> avm2_ei_dispatch -> BridgeGeneric -> path-walk -> JSON -> JS
//      round trip). This isolates the bridge's cost from the render path,
//      which is the only way to get a resolvable perf number under WSL: WSL
//      headed Chrome software-renders RWK at ~200 ms/frame, so a frame-rate
//      A/B there cannot see a sub-millisecond bridge cost at all. The
//      authoritative frame number is the real-GPU Windows rig (RWK-3:
//      5.1 ms/frame); this gate exists to catch a bridge that got
//      pathologically slow, not to benchmark the game.
//
//   2. BRIDGE-ACTIVE SURVIVAL. A long soak in real gameplay (booted via the
//      config-driven teleport) with the bridge fully live — per-frame path
//      reads + getItemQueue poll, plus host readState() at 20 Hz — asserting
//      zero aborts, OOM, or page errors. This directly falsifies the RWK-3
//      failure mode: before collectable strings + the weak orphan registry,
//      RWK grew ~94 MB/min and OOM-exited the browser after 6-7 minutes, so a
//      clean soak PAST that window is the meaningful memory signal available
//      from JS. (The per-tick allocation number itself is measured natively
//      via AVM2_HEAP_STATS — the runtime exposes no heap counter to JS, and
//      swf_perf_report's "live AS objs/arrays" are AVM1-only: avm2_main.c
//      passes literal 0s, so they must NOT be used as an AVM2 census.)
//
// Exit 0 = both gates held.

const { chromium } = require('playwright');
const fs = require('fs');

const BASE = process.env.HARNESS_BASE || 'http://127.0.0.1:8091';
const CHROME = process.env.CHROME || '/usr/bin/google-chrome';
const CONFIG_PATH = process.env.RWK_CONFIG ||
	(process.env.HOME + '/CC/Archipelago-CC/frontend/modules/flashPanel/games/robotkitty.json');
// Default soak is 10 min — comfortably past RWK-3's 6-7 min pre-fix OOM point.
const SOAK_MS = parseInt(process.env.SOAK_MS || '600000', 10);
const SAMPLE_MS = 30000;
const RS_CALLS = 300;
// A readState round trip walking 2 paths should be well under a millisecond of
// real work; this bound only catches pathological regressions.
const RS_MAX_MS = 5;

const TP = { x: 1072, y: 1200 };   // "Save Point 3" from robotkitty.json

const sleep = (ms) => new Promise((r) => setTimeout(r, ms));

async function until(page, fn, arg, timeoutMs, label) {
	const t0 = Date.now();
	while (Date.now() - t0 < timeoutMs) {
		const v = await page.evaluate(fn, arg);
		if (v) return v;
		await sleep(250);
	}
	console.log('  [timeout] ' + label);
	return null;
}

const readFrames = () => {
	const S = window.__gameWindow().__swfPerf;
	return S ? S.frames : null;
};

(async () => {
	const cfg = JSON.parse(fs.readFileSync(CONFIG_PATH, 'utf8'));
	const browser = await chromium.launch({
		executablePath: CHROME,
		headless: false,
		args: ['--enable-unsafe-webgpu', '--ignore-gpu-blocklist', '--no-sandbox'],
	});

	let failures = 0;
	const check = (cond, msg) => {
		if (!cond) { console.log('FAIL:', msg); failures++; } else { console.log('PASS:', msg); }
	};

	try {
		const errors = [];
		const aborts = [];
		const page = await browser.newPage();
		page.on('pageerror', (e) => { errors.push(e.message); console.log('  [pageerror]', e.message); });
		page.on('console', (m) => {
			const t = m.text();
			if (/abort|out of memory|OOM|Cannot enlarge|RuntimeError/i.test(t)) {
				aborts.push(t); console.log('  [ABORT]', t);
			} else if (t.indexOf('[BridgeGeneric]') !== -1) {
				console.log('  [page]', t);
			}
		});

		await page.goto(BASE + '/parent.html', { waitUntil: 'load' });
		await until(page, () => {
			const w = window.__gameWindow();
			return !!(w && w.__swfBridge && w.__runtimeReady);
		}, null, 90000, 'iframe ready');
		await page.frameLocator('#game').locator('#btn-start').click();
		await until(page, () => {
			const g = window.__gameWindow().__swfBridge.game;
			return !!(g && g.configure);
		}, null, 120000, 'callbacks registered');

		// Boot into real gameplay through the config-driven teleport.
		await page.evaluate((c) => window.__gameWindow().__swfBridge.game.configure(JSON.stringify(c)), cfg);
		await page.evaluate((a) => {
			const w = window.__gameWindow();
			const items = (a.tp.pre_invocations || []).slice();
			for (const wr of a.tp.writes) {
				items.push({ path: wr.path, value: wr.value === '$x' ? a.x : (wr.value === '$y' ? a.y : wr.value) });
			}
			w.__swfBridge.queueItems(items);
		}, { tp: cfg.teleport, x: TP.x, y: TP.y });
		const landed = await until(page, () => window.__gameWindow().__swfBridge.stateLog.some(
			(s) => s.name === 'player_x'), null, 60000, 'teleport landed');
		check(landed !== null, 'gate setup: teleported into PlayState (bridge live in gameplay)');

		// ---- Gate 1: EI round-trip cost --------------------------------------
		const rs = await page.evaluate((n) => {
			const g = window.__gameWindow().__swfBridge.game;
			g.readState();                       // warm
			const t0 = performance.now();
			for (let i = 0; i < n; i++) g.readState();
			const dt = performance.now() - t0;
			return { totalMs: dt, perCallMs: dt / n, sample: g.readState() };
		}, RS_CALLS);
		console.log(`\nEI round trip: ${RS_CALLS} readState() calls in ${rs.totalMs.toFixed(1)} ms ` +
			`= ${rs.perCallMs.toFixed(3)} ms/call`);
		console.log(`  sample payload: ${rs.sample}`);
		check(rs.perCallMs <= RS_MAX_MS,
			`perf: inbound readState round trip <= ${RS_MAX_MS} ms/call (got ${rs.perCallMs.toFixed(3)})`);

		// ---- Gate 2: bridge-active survival soak ------------------------------
		console.log(`\n=== bridge-active soak (${(SOAK_MS / 1000 / 60).toFixed(1)} min, readState @20Hz) ===`);
		await page.evaluate(() => {
			window.__readStateCalls = 0;
			window.__rsTimer = setInterval(function () {
				try { window.__gameWindow().__swfBridge.game.readState(); window.__readStateCalls++; } catch (e) {}
			}, 50);
		});
		const t0 = Date.now();
		let lastFrames = null;
		while (Date.now() - t0 < SOAK_MS) {
			await sleep(SAMPLE_MS);
			const mins = ((Date.now() - t0) / 60000).toFixed(1);
			lastFrames = await page.evaluate(readFrames);
			const calls = await page.evaluate(() => window.__readStateCalls);
			const st = await page.evaluate(() => {
				const log = window.__gameWindow().__swfBridge.stateLog;
				return log.length ? log[log.length - 1] : null;
			});
			console.log(`  t+${mins}min  frames=${lastFrames}  readState=${calls}` +
				`  last stateChanged=${st ? st.name + '=' + st.value : 'none'}` +
				`  aborts=${aborts.length} errors=${errors.length}`);
			if (aborts.length) break;
		}
		const rsCalls = await page.evaluate(() => window.__readStateCalls);
		await page.evaluate(() => clearInterval(window.__rsTimer));

		// Still alive and still ticking after the soak?
		const aliveFrames = await page.evaluate(readFrames);
		const alive = await page.evaluate(() => {
			try { return window.__gameWindow().__swfBridge.game.readState(); } catch (e) { return null; }
		});
		console.log(`\nsoak done: ${aliveFrames} frames, ${rsCalls} readState calls, ` +
			`final state ${alive}`);
		check(aborts.length === 0, 'memory: no abort / OOM over the soak ' +
			`(RWK-3 pre-fix OOM'd at 6-7 min; soaked ${(SOAK_MS / 60000).toFixed(1)} min)`);
		check(errors.length === 0, 'memory: no page errors over the soak');
		check(alive !== null && alive.indexOf('player_x') !== -1,
			'memory: bridge still answering readState after the soak');
		check(aliveFrames !== null && lastFrames !== null && aliveFrames >= lastFrames,
			'memory: game still ticking at the end of the soak');

		await page.close();
	} finally {
		await browser.close();
	}

	if (failures > 0) {
		console.log(`\nRESULT: FAIL (${failures} failed gate(s))`);
		process.exit(1);
	}
	console.log('\nRESULT: PASS');
	process.exit(0);
})().catch((e) => { console.error('gates error:', e); process.exit(2); });
