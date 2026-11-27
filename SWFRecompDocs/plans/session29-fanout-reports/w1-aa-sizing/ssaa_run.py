# s29 w1-aa-sizing: run verify_output with run_binary patched to render N*N
# jittered frames (SSAA_OFS env, -DSSAA_PROBE build) and box-average them.
import sys, os
from pathlib import Path
sys.path.insert(0, str(Path.cwd() / 'ruffle-tests'))
import verify_output as V
from PIL import Image
import numpy as np
orig = V.run_binary
def jit(build_dir, event_file=None, extra_env=None):
    N = int(os.environ.get('SSAA_N', '0'))
    if N <= 0:
        return orig(build_dir, event_file=event_file, extra_env=extra_env)
    build_dir = Path(build_dir)
    acc = {}; res = None
    keep = os.environ.get('SSAA_KEEP')
    for j in range(N):
        for i in range(N):
            if os.environ.get('SSAA_X0') is not None:
                x0 = float(os.environ['SSAA_X0']); y0 = float(os.environ.get('SSAA_Y0', '0'))
                dx = 0.5 - (i + x0) / N; dy = 0.5 - (j + y0) / N
            elif os.environ.get('SSAA_POS8'):
                dx = 0.5 - i / N; dy = 0.5 - j / N   # sample at pixel + i/N
            else:
                dx = (i + 0.5) / N - 0.5; dy = (j + 0.5) / N - 0.5
            for p in build_dir.glob('*.png'): p.unlink()
            env = dict(extra_env or {}); env['SSAA_OFS'] = f'{dx},{dy}'
            r = orig(build_dir, event_file=event_file, extra_env=env)
            if res is None: res = r
            for p in build_dir.glob('*.png'):
                a = np.asarray(Image.open(p).convert('RGBA'), dtype=np.uint32)
                acc.setdefault(p.name, []).append(a)
                if keep:
                    os.makedirs(keep, exist_ok=True)
                    Image.open(p).save(Path(keep) / f'{p.stem}.{i}{j}.png')
    for p in build_dir.glob('*.png'): p.unlink()
    for name, arrs in acc.items():
        if len(arrs) != N * N or any(a.shape != arrs[0].shape for a in arrs):
            print(f'SSAA: {name} only {len(arrs)} frames', file=sys.stderr)
        s = sum(arrs)
        if os.environ.get('SSAA_FLOOR'):
            avg = (s // len(arrs)).astype(np.uint8)
        else:
            avg = ((s + (len(arrs) // 2)) // len(arrs)).astype(np.uint8)
        Image.fromarray(avg, 'RGBA').save(build_dir / name)
    return res
V.run_binary = jit
sys.argv[0] = 'ruffle-tests/verify_output.py'
V.main()
