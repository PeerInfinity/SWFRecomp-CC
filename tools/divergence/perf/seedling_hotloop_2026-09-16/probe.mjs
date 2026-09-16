// Hot-loop probe: runs one or more Seedling wasm builds headless (logic-only
// Chromium — the device is lost at the first present, the AVM runs unchanged),
// records every frame's CPU (swf_perf_report's elapsed_ms) with its end
// timestamp, console lines stamped with the frame count, and optionally a CDP
// sampling profile. Runs are serial under ONE box-lock hold.
//
// usage: node probe.mjs <out.json> <frames> <dir>[:profile] [<dir> ...]
import { createServer } from 'node:http';
import { readFileSync, writeFileSync, existsSync, statSync } from 'node:fs';
import { join, extname, basename } from 'node:path';
const AP = '/home/robert/CC/Archipelago-CC';
const { chromium } = await import(`${AP}/node_modules/playwright/index.mjs`);
const { HEADLESS_LOGIC_ONLY_ARGS } = await import(`${AP}/scripts/procgen/headlessChromium.js`);
const { takeBoxLock } = await import(`${AP}/scripts/procgen/boxLock.js`);

const [outPath, framesArg, ...dirs] = process.argv.slice(2);
const FRAMES = Number(framesArg);
takeBoxLock({ name: 'swfrecomp-seedling-hotloop-1 probe', kind: 'measure', waitSec: 600 });

const MIME = { '.html': 'text/html', '.js': 'text/javascript', '.wasm': 'application/wasm' };
let root = null;
const server = createServer((req, res) => {
    const p = join(root, decodeURIComponent(req.url.split('?')[0]));
    if (!existsSync(p) || !statSync(p).isFile()) { res.writeHead(404); res.end(); return; }
    res.writeHead(200, { 'Content-Type': MIME[extname(p)] || 'application/octet-stream' });
    res.end(readFileSync(p));
});
await new Promise((r) => server.listen(0, '127.0.0.1', r));
const port = server.address().port;

const INIT = `(() => {
  const S = globalThis.__swfPerf = { cpu: [], iv: [], rp: [], bad: [], cap: 1e7, i: 0, frames: 0,
    uncapped: false, ui: null, pre: null, bU: null, last: 0, lastT: 0, warmup: 30, throttleMs: 250 };
  S.T = [];
  const push = S.cpu.push.bind(S.cpu);
  S.cpu.push = (v) => { S.T.push(performance.now()); return push(v); };
})();`;

const results = [];
for (const spec of dirs) {
    const [dir, mode] = spec.split(':');
    root = dir;
    const html = 'game.html';
    const browser = await chromium.launch({ headless: true, args: [...HEADLESS_LOGIC_ONLY_ARGS] });
    const page = await browser.newPage();
    const lines = [];
    page.on('console', (m) => {
        const t = m.text();
        lines.push([null, t]);
    });
    page.on('pageerror', (e) => lines.push([null, `PAGEERROR ${e.message}`]));
    await page.addInitScript(INIT);
    await page.goto(`http://127.0.0.1:${port}/${html}`);
    await page.waitForFunction(() => window.__runtimeReady === true, null, { timeout: 120000 });
    let cdp = null;
    const t0 = Date.now();
    await page.click('#btn-start');
    const clickT = await page.evaluate(() => performance.now());
    let profStartPerf = null;
    let lastFrames = 0;
    for (;;) {
        await new Promise((r) => setTimeout(r, 250));
        const f = await page.evaluate(() => (globalThis.__swfPerf ? globalThis.__swfPerf.cpu.length : 0));
        // stamp console lines that arrived since the last poll with the frame count
        for (const l of lines) if (l[0] === null) l[0] = f;
        if (mode === 'profile' && cdp === null && f >= 520) {
            cdp = await page.context().newCDPSession(page);
            await cdp.send('Profiler.enable');
            await cdp.send('Profiler.setSamplingInterval', { interval: 100 });
            await cdp.send('Profiler.start');
            profStartPerf = await page.evaluate(() => performance.now());
        }
        if (f >= FRAMES) break;
        if (Date.now() - t0 > 600000) { console.error(`timeout at frame ${f}`); break; }
        lastFrames = f;
    }
    let profile = null;
    if (cdp) profile = (await cdp.send('Profiler.stop')).profile;
    const perf = await page.evaluate(() => ({ cpu: __swfPerf.cpu, T: __swfPerf.T, rp: __swfPerf.rp,
        gpu: globalThis.__swfGpu ? { lost: __swfGpu.lost, stalls: __swfGpu.stalls } : null,
        digest: globalThis.__swfDigest || null }));
    await browser.close();
    const cpu = perf.cpu;
    let k = 0; for (let i = 1; i < cpu.length; i++) if (cpu[i] > cpu[k]) k = i;
    const name = basename(dir);
    const r = { name, dir, frames: cpu.length, clickT, gpu: perf.gpu, maxK: k, maxCpu: cpu[k],
        big: cpu.map((c, i) => [i, c]).filter(([, c]) => c > 300).map(([i, c]) => [i, +c.toFixed(1)]),
        cpu: cpu.map((c) => +c.toFixed(2)), T: perf.T.map((t) => +t.toFixed(1)), lines, digest: perf.digest,
        profStartPerf };
    if (profile) {
        const pp = outPath.replace(/\.json$/, `.${name}.cpuprofile`);
        writeFileSync(pp, JSON.stringify(profile));
        r.profile = pp;
    }
    results.push(r);
    console.log(JSON.stringify({ name, frames: r.frames, gpu: r.gpu, maxK: k, maxCpu: +cpu[k].toFixed(1), big: r.big }));
}
server.close();
writeFileSync(outPath, JSON.stringify(results));
