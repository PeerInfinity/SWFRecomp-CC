// rwk_test.js — Playwright driver for the injected Robot Wants Kitty AVM2 EI
// verification. Runs TWO pages in headed google-chrome (WebGPU via
// WSLg/DISPLAY):
//
//   harness_noshim.html — behavior A: no window.__swfBridge, so the injected
//     BridgeGeneric must no-op silently (EI available=false): zero
//     [BridgeGeneric] output, zero page errors, game boots.
//     (The strict gameplay-identity grade is the native headless A/B diff —
//     injected vs plain 300-frame trace — run by run_rwk_livetest.sh.)
//
//   parent.html — behavior B, driven through the REAL deliverable: the
//     packaged game.html in a SAME-ORIGIN iframe, reached into via
//     contentWindow exactly like Archipelago-CC's flashSubstrate/bridge.js.
//     Full BridgeGeneric round-trip against the canonical robotkitty.json:
//     wireCheck / configure / readState inbound, stateChanged outbound, and
//     the config-driven TELEPORT (remove_last_child + new_instance
//     xplor.PlayState from the title screen, then path-writes of Player.x/y),
//     re-verified through readState and a post-write stateChanged report.
//
// Unlike Seedling, RWK has no NG-preloader gate: the single injected SWF
// reaches the full write -> apply -> re-report grade on its own.

const { chromium } = require('playwright');
const fs = require('fs');

const BASE = process.env.HARNESS_BASE || 'http://127.0.0.1:8091';
const CHROME = process.env.CHROME || '/usr/bin/google-chrome';
const CONFIG_PATH = process.env.RWK_CONFIG ||
	(process.env.HOME + '/CC/Archipelago-CC/frontend/modules/flashPanel/games/robotkitty.json');

// Teleport destination: "Save Point 3" from robotkitty.json's location_coords.
// Far from the (160, 1088) player spawn, so a successful write is unambiguous.
const TP = { x: 1072, y: 1200 };

const sleep = (ms) => new Promise((r) => setTimeout(r, ms));

// Poll `fn` (evaluated in the page) until truthy or timeout.
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
		// ---- Behavior A: no shim → BridgeGeneric no-ops ----------------------
		console.log('\n=== behavior A: no shim (BridgeGeneric must no-op) ===');
		const aLines = [];
		const aPage = await browser.newPage();
		aPage.on('console', (m) => { aLines.push(m.text()); console.log('  [page]', m.text()); });
		aPage.on('pageerror', (e) => { aLines.push('PAGEERROR: ' + e.message); console.log('  [page] PAGEERROR:', e.message); });
		await aPage.goto(BASE + '/harness_noshim.html', { waitUntil: 'load' });
		await aPage.waitForFunction(() => {
			const b = document.getElementById('btn-run');
			return b && !b.disabled;
		}, null, { timeout: 60000 });
		await aPage.click('#btn-run');
		await aPage.waitForTimeout(25000);
		check(aLines.some((l) => l.indexOf('SWF Execution Started') !== -1), 'A: game booted');
		check(!aLines.some((l) => l.indexOf('[BridgeGeneric]') !== -1), 'A: zero [BridgeGeneric] output (EI gate closed)');
		check(!aLines.some((l) => l.indexOf('PAGEERROR') !== -1), 'A: no page errors');
		await aPage.close();

		// ---- Behavior B: packaged game.html in a same-origin iframe -----------
		console.log('\n=== behavior B: packaged game.html via same-origin iframe ===');
		const bLines = [];
		const page = await browser.newPage();
		page.on('console', (m) => { bLines.push(m.text()); console.log('  [page]', m.text()); });
		page.on('pageerror', (e) => { bLines.push('PAGEERROR: ' + e.message); console.log('  [page] PAGEERROR:', e.message); });
		const bHas = (s) => bLines.some((l) => l.indexOf(s) !== -1);

		await page.goto(BASE + '/parent.html', { waitUntil: 'load' });

		// The host installs its stateChanged sink through contentWindow — the
		// same reach-in flashSubstrate/bridge.js does.
		await until(page, () => {
			const w = window.__gameWindow();
			return !!(w && w.__swfBridge && w.__runtimeReady);
		}, null, 90000, 'iframe runtime + shim ready');
		await page.evaluate(() => {
			const w = window.__gameWindow();
			w.__swfBridge.onStateChanged = function (pname, pvalue) {
				window.__stateChanges.push({ name: pname, value: pvalue });
				console.log('[host] stateChanged: ' + pname + ' = ' + pvalue + ' (' + typeof pvalue + ')');
			};
		});

		// __swfBridgeStart() must run from a USER GESTURE inside the iframe:
		// click the packaged page's own Start button via a frame locator.
		await page.frameLocator('#game').locator('#btn-start').click();
		console.log('[driver] clicked in-iframe Start (user gesture)');

		// B1..B4: bridge alive, inbound callbacks, configure with the canonical
		// Archipelago-CC mapping.
		await until(page, () => {
			const g = window.__gameWindow().__swfBridge.game;
			return !!(g && g.wireCheck && g.configure && g.readState);
		}, null, 120000, 'BridgeGeneric callbacks registered');
		check(bHas('[BridgeGeneric] Ready for configuration'), 'B1: bridge alive (EI available + outward console.log)');

		const wireCheck = await page.evaluate(() => window.__gameWindow().__swfBridge.game.wireCheck());
		check(wireCheck === 'ok', 'B2: inbound wireCheck() -> "ok" (got ' + JSON.stringify(wireCheck) + ')');

		const configureRet = await page.evaluate((c) =>
			window.__gameWindow().__swfBridge.game.configure(JSON.stringify(c)), cfg);
		check(configureRet === 'ok' && bHas('[BridgeGeneric] Configured:'),
			'B3: inbound configure(robotkitty.json) -> "ok" (got ' + JSON.stringify(configureRet) + ')');

		// resolveClasses() runs inside configure(), so the Resolved log is
		// already in flight; give the console listener a moment to drain.
		await sleep(2000);
		check(bHas('[BridgeGeneric] Resolved: xplor.PlayState'),
			'B4: getDefinitionByName resolved xplor.PlayState');

		// B5: readState BEFORE the teleport — still on the title screen, so the
		// path reads resolve to null (no live Player yet). Must still be
		// well-formed JSON carrying both path-read keys.
		const rsBefore = await page.evaluate(() => window.__gameWindow().__swfBridge.game.readState());
		let before = null;
		try { before = JSON.parse(rsBefore); } catch (e) {}
		console.log('[driver] readState (pre-teleport) -> ' + rsBefore);
		check(before !== null && ('player_x' in before) && ('player_y' in before),
			'B5: inbound readState() -> JSON with player_x/player_y');

		// B6: the config-driven TELEPORT. Queue exactly what the flashPanel
		// adapter queues: robotkitty.json's teleport.pre_invocations (strip the
		// LogoState bitmap, construct a fresh xplor.PlayState into FlxG.state),
		// then the path writes with $x/$y substituted.
		console.log('[driver] queueing teleport: pre_invocations + path writes -> (' + TP.x + ', ' + TP.y + ')');
		await page.evaluate((a) => {
			const w = window.__gameWindow();
			const items = (a.tp.pre_invocations || []).slice();
			for (const wr of a.tp.writes) {
				items.push({ path: wr.path, value: wr.value === '$x' ? a.x : (wr.value === '$y' ? a.y : wr.value) });
			}
			w.__swfBridge.queueItems(items);
		}, { tp: cfg.teleport, x: TP.x, y: TP.y });

		// Wait for the write to land AND be re-reported outbound.
		await until(page, (x) => window.__stateChanges.some(
			(s) => s.name === 'player_x' && s.value === x), TP.x, 60000,
			'stateChanged(player_x, ' + TP.x + ')');
		const changes = await page.evaluate(() => window.__stateChanges);
		const firstX = changes.find((s) => s.name === 'player_x');
		check(firstX !== undefined && typeof firstX.value === 'number',
			'B6: stateChanged("player_x", <number>) reported after PlayState construction');
		check(bHas('[BridgeGeneric] PathWrite: .x = ' + TP.x) &&
			bHas('[BridgeGeneric] PathWrite: .y = ' + TP.y),
			'B7: teleport path writes applied (Player.x/y written on the live instance)');

		// B8: re-report — read the live state back inbound and confirm the
		// written x landed (x does not drift without input; y falls under
		// gravity, so only x is graded for equality).
		const rsAfter = await page.evaluate(() => window.__gameWindow().__swfBridge.game.readState());
		let after = null;
		try { after = JSON.parse(rsAfter); } catch (e) {}
		console.log('[driver] readState (post-teleport) -> ' + rsAfter);
		check(after !== null && after.player_x === TP.x,
			'B8: readState() re-report shows player_x == ' + TP.x + ' (got ' + (after && after.player_x) + ')');
		check(after !== null && typeof after.player_y === 'number',
			'B9: readState() re-report shows a live numeric player_y (' + (after && after.player_y) + ')');
		check(!bLines.some((l) => l.indexOf('PAGEERROR') !== -1), 'B10: no page errors');

		await page.close();
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
