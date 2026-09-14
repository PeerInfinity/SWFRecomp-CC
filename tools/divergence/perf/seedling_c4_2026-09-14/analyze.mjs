// C4 probe analysis: self/inclusive time inside one frame's window.
import { readFileSync } from 'node:fs';
const [prefix, frameArg, topN = '40'] = process.argv.slice(2);
const prof = JSON.parse(readFileSync(`${prefix}.cpuprofile`, 'utf8'));
const meta = JSON.parse(readFileSync(`${prefix}-perf.json`, 'utf8'));
const { cpu, T } = meta.perf;
let k = frameArg === 'max' ? cpu.indexOf(Math.max(...cpu)) : Number(frameArg);
const fEnd = T[k], fStart = T[k] - cpu[k];
const startMark = meta.marks.find((m) => m.label === 'profiler-start');
const off = prof.startTime / 1000 - startMark.pageNow; // profile ms = page ms + off
const byId = new Map(prof.nodes.map((n) => [n.id, n]));
const parent = new Map();
for (const n of prof.nodes) for (const c of n.children || []) parent.set(c, n.id);
let t = prof.startTime;
const times = prof.samples.map((_, i) => (t += prof.timeDeltas[i]));
const lo = (fStart + off) * 1000, hi = (fEnd + off) * 1000;
const self = new Map(), incl = new Map();
let total = 0, n = 0;
const stackOf = (id) => { const s = []; for (let x = id; x !== undefined; x = parent.get(x)) s.push(byId.get(x).callFrame.functionName || '(anon)'); return s; };
const stacks = [];
for (let i = 0; i < prof.samples.length - 1; i++) {
    if (times[i] < lo || times[i] >= hi) continue;
    const w = (times[i + 1] - times[i]) / 1000;
    const st = stackOf(prof.samples[i]);
    total += w; n++;
    self.set(st[0], (self.get(st[0]) || 0) + w);
    for (const f of new Set(st)) incl.set(f, (incl.get(f) || 0) + w);
    stacks.push({ w, st });
}
const fmt = (m) => [...m].sort((a, b) => b[1] - a[1]).slice(0, Number(topN)).map(([f, ms]) => `${ms.toFixed(1).padStart(9)} ms ${(100 * ms / total).toFixed(1).padStart(5)}%  ${f}`).join('\n');
console.log(`frame k=${k} cpu=${cpu[k].toFixed(1)} ms, window page ${fStart.toFixed(0)}–${fEnd.toFixed(0)}; ${n} samples, ${total.toFixed(1)} ms sampled`);
console.log(`neighbours: cpu[k-1]=${cpu[k-1]?.toFixed(1)} cpu[k+1]=${cpu[k+1]?.toFixed(1)}; frames>1s: ${cpu.map((c, i) => [i, c]).filter(([, c]) => c > 1000).map(([i, c]) => `${i}:${c.toFixed(0)}`).join(' ')}`);
console.log('\n## SELF\n' + fmt(self));
console.log('\n## INCLUSIVE\n' + fmt(incl));
export { stacks };
if (process.env.DUMP) { const fs = await import('node:fs'); fs.writeFileSync(process.env.DUMP, JSON.stringify({ total, stacks: stacks.map((s) => [s.w, s.st]) })); }
