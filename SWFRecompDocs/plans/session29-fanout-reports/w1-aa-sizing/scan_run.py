# s29 w1-aa-sizing: Flash-HIGH scanline-rule emulation (per w1-text-pixels):
# 4 sub-rows at y+j/4, NX x-subsamples at (i+.5)/NX (~exact x coverage);
# two-colour pixels re-quantised to n/16 coverage, written floor((c0*(256-16n)+c1*16n)/256).
import sys, os
from pathlib import Path
sys.path.insert(0, str(Path.cwd() / 'ruffle-tests'))
import verify_output as V
from PIL import Image
import numpy as np
orig = V.run_binary
NX = int(os.environ.get('SCAN_NX', '16')); NY = 4
QMODE = os.environ.get('SCAN_Q', 'floor')
def compose(F):
    F = np.stack(F).astype(np.int32)              # K,H,W,4
    K = F.shape[0]
    c0 = F[0]
    diff = (F != c0[None]).any(-1)                # K,H,W
    first = diff.argmax(0)
    c1 = np.take_along_axis(F, first[None, ..., None].repeat(4, -1), 0)[0]
    is0 = ~diff
    is1 = (F == c1[None]).all(-1)
    two = (is0 | is1).all(0)
    f = is1.sum(0) / K
    f = np.where(diff.any(0), f, 0.0)
    if QMODE == 'round': n = np.floor(f * 16 + 0.5)
    elif QMODE == 'none': n = f * 16
    else: n = np.floor(f * 16 + 1e-9)
    q = (c0 * (256 - 16 * n[..., None]) + c1 * 16 * n[..., None]) / 256
    q = np.floor(q) if QMODE != 'none' else np.floor(q + 0.5)
    avg = (F.sum(0) + K // 2) // K
    out = np.where(two[..., None], q, avg)
    return np.clip(out, 0, 255).astype(np.uint8), two
def jit(build_dir, event_file=None, extra_env=None):
    build_dir = Path(build_dir); acc = {}; res = None
    for j in range(NY):
        for i in range(NX):
            dx = 0.5 - (i + 0.5) / NX; dy = 0.5 - j / NY - float(os.environ.get('SCAN_YEPS', '0'))
            for p in build_dir.glob('*.png'): p.unlink()
            env = dict(extra_env or {}); env['SSAA_OFS'] = f'{dx},{dy}'
            r = orig(build_dir, event_file=event_file, extra_env=env)
            if res is None: res = r
            for p in build_dir.glob('*.png'):
                acc.setdefault(p.name, []).append(np.asarray(Image.open(p).convert('RGBA'), dtype=np.uint8))
    for p in build_dir.glob('*.png'): p.unlink()
    for name, F in acc.items():
        if len(F) != NX * NY or any(a.shape != F[0].shape for a in F):
            print(f'SCAN: {name} only {len(F)} frames', file=sys.stderr); F = [a for a in F if a.shape == F[0].shape]
        out, two = compose(F)
        Image.fromarray(out, 'RGBA').save(build_dir / name)
    return res
V.run_binary = jit
sys.argv[0] = 'ruffle-tests/verify_output.py'
V.main()
