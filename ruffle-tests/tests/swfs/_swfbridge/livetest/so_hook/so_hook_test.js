// so_hook_test.js — Playwright driver for the AVM2 SharedObject host-hook
// contract (SWFRecompDocs/guides/avm2-sharedobject-host-hook.md). Two pages:
//   page 1: load -> null at boot; flush -> store(bytes); clear -> store(null);
//           getLocal after clear -> no 2nd load; avm2_so_reload in place (an
//           AS3 alias of so.data sees the restored values); reload failure
//           arms (garbage bytes, unknown name) return 0 and leave data alone;
//           avm2_so_flush_all -> store(bytes).
//   page 2: load answers page 1's flushed bytes (as base64) -> boot sees them.
const { chromium } = require('playwright');

const BASE = process.env.HARNESS_BASE || 'http://127.0.0.1:8093';
const CHROME = process.env.CHROME || '/usr/bin/google-chrome';
const HEADLESS = process.env.HEADLESS === '1';
const sleep = (ms) => new Promise((r) => setTimeout(r, ms));

let failures = 0;
const check = (c, m) => { console.log((c ? 'PASS: ' : 'FAIL: ') + m); if (!c) failures++; };

async function open(browser, answer) {
	const lines = [];
	const page = await browser.newPage();
	page.on('console', (m) => { lines.push(m.text()); if (/\[(as3|host)\]|err/.test(m.text())) console.log('  [page]', m.text()); });
	page.on('pageerror', (e) => { lines.push('PAGEERROR: ' + e.message); console.log('  [page] PAGEERROR:', e.message); });
	await page.addInitScript((a) => { window.__soLoadAnswer = a; }, answer);
	await page.goto(BASE + '/harness.html', { waitUntil: 'load' });
	await page.waitForFunction(() => { const b = document.getElementById('btn-run'); return b && !b.disabled; }, null, { timeout: 60000 });
	await page.click('#btn-run');
	return { page, lines };
}

async function waitLine(lines, re, fromIdx, ms) {
	const t0 = Date.now();
	while (Date.now() - t0 < ms) {
		for (let i = fromIdx; i < lines.length; i++) if (re.test(lines[i])) return lines[i];
		await sleep(100);
	}
	return null;
}

(async () => {
	const args = ['--enable-unsafe-webgpu', '--ignore-gpu-blocklist', '--no-sandbox'];
	if (HEADLESS) args.push('--enable-unsafe-swiftshader', '--use-angle=swiftshader', '--enable-features=Vulkan', '--use-vulkan=swiftshader');
	const browser = await chromium.launch({ executablePath: CHROME, headless: HEADLESS, args });
	try {
		// ---------------- page 1 ----------------
		console.log('\n=== page 1: empty host ===');
		const p1 = await open(browser, null);
		const t1 = await waitLine(p1.lines, /\[as3\] tick10 /, 0, 60000);
		check(!!t1, 'page 1 reached tick10');
		const log1 = await p1.page.evaluate(() => window.__soLog);
		const loads = log1.filter((e) => e.op === 'load');
		const stores = log1.filter((e) => e.op === 'store');
		check(loads.length === 1 && loads[0].name === 'sohook' && loads[0].localPath === '/', 'exactly ONE load(name="sohook", localPath="/") across getLocal / clear / getLocal');
		check(loads.length === 1 && loads[0].key === 'localhost//sohook', 'load carries full key ' + (loads[0] && loads[0].key));
		check(p1.lines.some((l) => /\[as3\] boot keys=0 /.test(l)), 'null load -> empty data at boot');
		check(p1.lines.some((l) => /\[as3\] flush=flushed/.test(l)), 'flush() still returns "flushed"');
		check(stores.length === 2 && stores[0].b64 && stores[0].isU8, 'flush -> store(Uint8Array) (' + (stores[0] && stores[0].len) + ' bytes)');
		check(stores.length === 2 && stores[1].b64 === null, 'clear -> store(null)');
		check(p1.lines.some((l) => /\[as3\] same=true afterclear keys=0 /.test(l)), 'getLocal after clear -> cached cleared object, no host bytes');
		const saved = stores[0] && stores[0].b64;

		// reload failure arms first (data must stay {temp:99}).
		const bad = await p1.page.evaluate(() => {
			const r = {};
			window.__soLoadAnswer = new Uint8Array([0x0a, 0xff, 0xff, 0xff, 0xff, 0x01]);
			r.garbage = Module.ccall('avm2_so_reload', 'number', ['string', 'string'], ['sohook', '/']);
			window.__soLoadAnswer = null;
			r.nobytes = Module.ccall('avm2_so_reload', 'number', ['string', 'string'], ['sohook', '/']);
			r.unknown = Module.ccall('avm2_so_reload', 'number', ['string', 'string'], ['never', '/']);
			return r;
		});
		check(bad.garbage === 0 && bad.nobytes === 0 && bad.unknown === 0, 'reload -> 0 on garbage / null / never-getLocal\'d ' + JSON.stringify(bad));
		let mark = p1.lines.length;
		const tBad = await waitLine(p1.lines, /\[as3\] tick\d+ /, mark, 20000);
		check(tBad && /aliasIsData=true keys=1 temp=99;/.test(tBad), 'failed reloads left data untouched: ' + tBad);

		// successful in-place reload.
		const ok = await p1.page.evaluate((b) => {
			const bin = atob(b); const u8 = new Uint8Array(bin.length);
			for (let i = 0; i < bin.length; i++) u8[i] = bin.charCodeAt(i);
			window.__soLoadAnswer = u8;
			return Module.ccall('avm2_so_reload', 'number', ['string', 'string'], ['sohook', '/']);
		}, saved);
		check(ok === 1, 'reload(sohook, "/") -> 1');
		mark = p1.lines.length;
		const tOk = await waitLine(p1.lines, /\[as3\] tick\d+ /, mark, 20000);
		check(tOk && /aliasIsData=true keys=4 counter=7;list=\[1,2,3\];name=seed;nested=\{a:x,b:true\};$/.test(tOk), 'in-place restore seen through the AS3 alias: ' + tOk);

		// flush-all.
		const fa = await p1.page.evaluate(() => {
			const n0 = window.__soLog.length;
			const n = Module.ccall('avm2_so_flush_all', 'number', [], []);
			return { n, added: window.__soLog.slice(n0) };
		});
		check(fa.n === 1 && fa.added.length === 1 && fa.added[0].op === 'store' && fa.added[0].b64 === saved,
			'flush_all -> 1 store of the restored data (bytes identical to the page-1 flush)');
		await p1.page.close();

		// ---------------- page 2 ----------------
		console.log('\n=== page 2: host answers the saved bytes (base64) ===');
		const p2 = await open(browser, saved);
		const b2 = await waitLine(p2.lines, /\[as3\] boot /, 0, 60000);
		check(b2 && /keys=4 counter=7;list=\[1,2,3\];name=seed;nested=\{a:x,b:true\};/.test(b2), 'fresh page restores flushed data at boot: ' + b2);
		const log2 = await p2.page.evaluate(() => window.__soLog);
		check(log2.length === 1 && log2[0].op === 'load', 'page 2: one load, no stores (it never flushed)');
		check(!p1.lines.concat(p2.lines).some((l) => l.indexOf('PAGEERROR') !== -1), 'no page errors');
		console.log('saved AMF3 bytes (base64): ' + saved);
		await p2.page.close();
	} finally {
		await browser.close();
	}
	console.log(failures === 0 ? '\nALL PASS' : '\n' + failures + ' FAILURE(S)');
	process.exit(failures === 0 ? 0 : 1);
})();
