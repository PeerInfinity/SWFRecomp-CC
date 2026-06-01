// mem_test.js — Playwright driver for the memory-poke (configure/readState)
// iframe-boundary probe under BOTH Ruffle and SWFRecomp. Loads mem_parent.html
// in headed google-chrome, clicks Run (which mounts both game iframes and calls
// configure/readState across the boundary), then asserts integrity per runtime.
//
// What each assertion proves:
//   configOk  — configure(json) echoed the full config back intact (IN size+UTF)
//   state     — readState() returned parseable JSON across the boundary
//   fieldsOk  — all scalar fields present, correct types
//   nestedOk  — nested object + array preserved
//   utfOk     — non-ASCII field (café→☃) round-tripped on the OUT direction
//   cfgLenOk  — the AS callback saw the full configure arg (length matches)

const { chromium } = require('playwright');

const URL = process.env.HARNESS_URL || 'http://127.0.0.1:8089/mem_parent.html';
const CHROME = process.env.CHROME || '/usr/bin/google-chrome';
const T = 60000;

(async () => {
	const browser = await chromium.launch({
		executablePath: CHROME,
		headless: false,
		args: ['--enable-unsafe-webgpu', '--ignore-gpu-blocklist', '--no-sandbox'],
	});
	let results = {};
	try {
		const page = await browser.newPage();
		page.on('console', (m) => console.log('  [page]', m.text()));
		page.on('pageerror', (e) => console.log('  [page] PAGEERROR:', e.message));

		await page.goto(URL, { waitUntil: 'load' });
		await page.click('#btn-run');   // parent mounts both game iframes

		// SWFRecomp's graphics renderer needs a user gesture inside the iframe to
		// init WebGPU. Click the game page's start button with a real (trusted)
		// click in the iframe's own document. (Ruffle autoplays — no gesture.)
		try {
			const swfBtn = page.frameLocator('#if-swf').locator('#swf-run');
			await swfBtn.waitFor({ state: 'attached', timeout: 15000 });
			await swfBtn.click({ timeout: 15000 });
			console.log('  [driver] clicked SWFRecomp iframe start button (gesture)');
		} catch (e) {
			console.log('  [driver] could not click SWF iframe start button:', e.message);
		}

		await page.waitForFunction(
			() => window.__probeResults && window.__probeResults.ruffle && window.__probeResults.swfrecomp,
			null, { timeout: T }).catch(() => {});
		await page.waitForTimeout(300);
		results = await page.evaluate(() => window.__probeResults || {});
	} finally {
		await browser.close();
	}

	console.log('\n=== PROBE RESULTS ===');
	console.log(JSON.stringify(results, null, 2));

	let failures = 0;
	const check = (cond, msg) => { if (!cond) { console.log('FAIL:', msg); failures++; } else { console.log('PASS:', msg); } };

	['ruffle', 'swfrecomp'].forEach((rt) => {
		const r = results[rt];
		console.log(`\n--- ${rt} ---`);
		if (!r) { check(false, `${rt}: produced a result`); return; }
		if (r.error) console.log(`  error: ${r.error}`);
		if (r.parseError) console.log(`  parseError: ${r.parseError}`);
		check(r.configOk === true, `${rt}: configure() echoed config intact, size+UTF (${r.configLen} chars)`);
		check(!!r.state, `${rt}: readState() returned parseable JSON across the boundary`);
		check(r.fieldsOk === true, `${rt}: all scalar fields present + correct types`);
		check(r.typesOk === true, `${rt}: JS types correct (number/boolean/string/object)`);
		check(r.nestedOk === true, `${rt}: nested object + array preserved`);
		check(r.utfOk === true, `${rt}: non-ASCII field (café→☃) round-tripped`);
		check(r.cfgLenOk === true, `${rt}: AS callback saw the full configure arg (cfg_len matches)`);
	});

	console.log(failures > 0 ? `\nRESULT: FAIL (${failures} failed assertion(s))` : '\nRESULT: PASS');
	process.exit(failures > 0 ? 1 : 0);
})().catch((e) => { console.error('harness error:', e); process.exit(2); });
