# Starve probe: proves the web audio output plays silence (never replays) on a
# main-thread stall, and that the mix cadence (audio_mix calls x frames) is
# unchanged. Usage: starve_probe.py URL [blockMs]
import sys, json
from playwright.sync_api import sync_playwright
url = sys.argv[1]; block = int(sys.argv[2]) if len(sys.argv) > 2 else 1500
ARGS = ['--no-sandbox', '--autoplay-policy=no-user-gesture-required', '--enable-unsafe-webgpu',
        '--ignore-gpu-blocklist', '--enable-unsafe-swiftshader', '--use-angle=swiftshader',
        '--use-vulkan=swiftshader', '--enable-features=Vulkan']
JS = r"""
async (blockMs) => {
  const t0w = performance.now();
  while (!(window._swfAudioOut && Module._audio_fill_buffer && Module.HEAPF32)) {
    if (performance.now() - t0w > 20000) return {error: 'no audio out', path: window._swfAudioPath};
    await new Promise(r => setTimeout(r, 100));
  }
  const ctx = window._swfAudioCtx, out = window._swfAudioOut;
  await ctx.resume();
  // Tag every mixed chunk with a sample counter (after the real mix runs).
  const orig = Module._audio_fill_buffer; let n = 0; const calls = [];
  Module._audio_fill_buffer = function (frames) {
    const p = orig(frames); calls.push([performance.now(), frames]);
    const h = Module.HEAPF32, o = p >> 2;
    for (let i = 0; i < frames; i++) { const v = ((n++) % 1000000) / 1000000 + 1e-7; h[o + 2*i] = v; h[o + 2*i + 1] = v; }
    return p;
  };
  const src = `class Rec extends AudioWorkletProcessor{constructor(){super();this.buf=[];this.port.onmessage=()=>{this.port.postMessage(this.buf);this.buf=[]}}
    process(inp){const c=inp[0]&&inp[0][0];if(c){this.buf.push(Float32Array.from(c))}else this.buf.push(null);return true}}registerProcessor('rec',Rec);`;
  await ctx.audioWorklet.addModule(URL.createObjectURL(new Blob([src], {type: 'text/javascript'})));
  const rec = new AudioWorkletNode(ctx, 'rec');
  out.disconnect(); out.connect(rec); rec.connect(ctx.destination);
  // Steady-state cadence window (no stall).
  await new Promise(r => setTimeout(r, 1000));
  const c0 = calls.length, t0 = performance.now();
  const a0 = ctx.currentTime;
  await new Promise(r => setTimeout(r, 20000));
  const cadence = (calls.length - c0) / ((performance.now() - t0) / 1000);
  const cadenceAudioClock = (calls.length - c0) / (ctx.currentTime - a0);
  const steady = await new Promise(r => { rec.port.onmessage = e => r(e.data); rec.port.postMessage(0); });
  let steadyZero = 0; for (const q of steady) { if (!q) continue; for (const v of q) if (v === 0) steadyZero++; }
  const framesSet = [...new Set(calls.map(c => c[1]))];
  // Stall.
  const callsBefore = calls.length, aStall0 = ctx.currentTime; const tb = performance.now(); while (performance.now() - tb < blockMs) {}
  const tStallEnd = performance.now();
  await new Promise(r => setTimeout(r, 1000));
  const cadenceThroughStall = (calls.length - callsBefore) / (ctx.currentTime - aStall0);
  const burst = calls.filter(c => c[0] >= tStallEnd && c[0] < tStallEnd + 30).length;
  const got = await new Promise(r => { rec.port.onmessage = e => r(e.data); rec.port.postMessage(0); });
  const vals = []; for (const q of got) { if (!q) { for (let i = 0; i < 128; i++) vals.push(0); continue; } for (const v of q) vals.push(v === 0 ? 0 : Math.round((v - 1e-7) * 1000000)); }
  // A replay = a run of >=16 consecutive +1 steps starting at or below the max counter already heard.
  let back = 0, zero = 0, replays = [], maxSeen = -1, run = 0, runStart = -1, longestZero = 0, curZero = 0;
  for (let i = 1; i < vals.length; i++) {
    const d = vals[i] - vals[i-1];
    if (vals[i] === 0) { zero++; curZero++; longestZero = Math.max(longestZero, curZero); } else curZero = 0;
    if (d < 0 && vals[i] !== 0) back++;
    if (d === 1 && vals[i] !== 0) { if (run === 0) runStart = vals[i-1]; run++; if (run === 16) { if (runStart <= maxSeen && maxSeen - runStart < 500000 && replays.length < 20) replays.push([i, runStart, maxSeen]); } }
    else { if (run >= 16) maxSeen = Math.max(maxSeen, vals[i-1]); run = 0; }
  }
  return {path: window._swfAudioPath, state: ctx.state, cadencePerSec: +cadence.toFixed(2), cadencePerAudioSec: +cadenceAudioClock.toFixed(3), steadyZeroSamples: steadyZero, framesPerCall: framesSet, cadenceThroughStallPerAudioSec: +cadenceThroughStall.toFixed(3),
          callsDuringStall: calls.filter(c => c[0] >= tb && c[0] < tStallEnd).length, burstAfterStall: burst,
          samples: vals.length, zeroSamples: zero, longestZeroRunMs: +(longestZero / 44.1).toFixed(1), rawBackSteps: back, replays};
}
"""
with sync_playwright() as p:
    b = p.chromium.launch(args=ARGS)
    pg = b.new_page()
    pg.on('console', lambda m: print('  [console]', m.text[:200]) if 'audio' in m.text.lower() else None)
    pg.goto(url)
    print(json.dumps(pg.evaluate(JS, block)))
    b.close()
