"""Compare a leg's summary.txt (per-comparison PASS/FAIL + outliers) with CI baseline image_results_graphics.json."""
import json, re, sys, os, glob
leg = sys.argv[1]
R = '/home/user/SWFRecomp-CC/ruffle-tests/tests/swfs/'
base = {}
for f in glob.glob(R + '**/_results/image_results_graphics.json', recursive=True):
    pre = f[len(R):].split('/_results/')[0]
    for r in json.load(open(f))['results']:
        base[(pre + '/' + r['test'], r['comparison'])] = (r['status'], r.get('outliers'))
rows = []
for line in open(leg + '/summary.txt'):
    t = line.split(' ')[0]
    for m in re.finditer(r'image:([^\]]+)\] (PASS|FAIL)[^:]*: (?:Image check passed: |Image comparison failed: )?(\d+)?', line):
        cmp, st, n = m.group(1), m.group(2).lower(), m.group(3)
        b = base.get((t, cmp))
        rows.append((t, cmp, st, int(n) if n else None, b))
moved = [r for r in rows if r[4] and (r[4][0] == 'pass') != (r[2] == 'pass')]
cnt = [r for r in rows if r[4] and r[4][1] is not None and r[3] is not None and r[4][1] != r[3]]
miss = [r for r in rows if not r[4]]
print('comparisons', len(rows), 'status moves', len(moved), 'count moves', len(cnt), 'no baseline', len(miss))
for r in moved: print('MOVE', r[0], r[1], r[4][0], '->', r[2], r[4][1], '->', r[3])
for r in cnt:
    if r not in moved: print('COUNT', r[0], r[1], r[2], r[4][1], '->', r[3])
for r in miss: print('NOBASE', r[0], r[1], r[2], r[3])
