#!/usr/bin/env python3
"""Golden-provenance sweep: capture a Ruffle-layout image test in Flash at
EVERY numeric image_comparisons trigger and grade each comparison.

    sweep_goldens.py <test> --root SWFS_ROOT --out-dir D [--screen | --direct]

Unlike validate_images.py (first comparison, last tick only) this grades
all comparisons and all their `checks` (Ruffle semantics: per-channel
outliers > tolerance, pass iff <= max_outliers for every check).
`trigger = "fs_command"` comparisons are reported untestable.
--screen grabs the Xvfb window instead of draw(): one projector run per
trigger tick (the hold happens only at the last captured tick).
Writes <out-dir>/<test with / -> __>[.screen].json and the Flash PNGs as
<out-dir>/png/<test>__<comparison>[.screen].png.
"""
import argparse
import json
import os
import sys
import tomllib

import shutil
import subprocess
import tempfile
import time

import numpy as np
from PIL import Image

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import run_image  # noqa: E402
import flashenv  # noqa: E402


def direct_screen(d, settle):
    """Run test.swf as the REAL root (no wrapper) and grab the Xvfb window
    after `settle` seconds. Tick is NOT pinned: valid only for content that
    is static after its last trigger. For AVM2 tests that touch `stage` in
    their constructor (null in a Loader child) and stage-sized tests."""
    swf = os.path.abspath(os.path.join(d, "test.swf"))
    info = flashenv.swf_info(swf)
    w, h = int(round(info["width"])), int(round(info["height"]))
    env = flashenv.PlayerEnv(trust_paths=[os.path.abspath(d)])
    xinfo = os.path.join(env.root, "xinfo")
    e = dict(os.environ, HOME=env.root, LC_ALL="C")
    inner = 'echo "$DISPLAY $XAUTHORITY" > "$0"; exec "$1" "$2"'
    child = subprocess.Popen(["xvfb-run", "-a", "-s", "-screen 0 1280x1024x24", "sh", "-c", inner,
                              xinfo, flashenv.DEFAULT_PLAYER, swf], env=e, cwd=os.path.abspath(d),
                             stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, start_new_session=True)
    try:
        time.sleep(settle)
        denv = flashenv.PlayerEnv._display_env(e, xinfo)
        ppm = os.path.join(env.root, "s.ppm")
        img, tree = run_image.grab_screen(denv, ppm, settle=0)
        crop, _ = run_image.crop_stage({"image": img, "tree": tree}, w, h)
        log = env.read_log()
    finally:
        try:
            os.killpg(child.pid, 9)
        except ProcessLookupError:
            pass
        child.wait()
        env.cleanup()
    return crop, log


def grade(img, golden_path, checks):
    exp = np.asarray(Image.open(golden_path).convert("RGBA"), dtype=np.int16)
    act = np.asarray(img.convert("RGBA"), dtype=np.int16)
    if exp.shape != act.shape:
        return {"size_mismatch": [list(exp.shape), list(act.shape)]}
    d = np.abs(exp - act)
    out = {"max_difference": int(d.max()),
           "diff_pixels": int((d.max(axis=2) > 0).sum()),
           "pixels": int(d.shape[0] * d.shape[1]),
           "checks": []}
    ok = True
    for c in checks:
        tol = c.get("tolerance", 0)
        maxo = c.get("max_outliers", 0)
        o = int((d > tol).sum())
        out["checks"].append({"tolerance": tol, "max_outliers": maxo, "outliers": o,
                              "outlier_pixels": int((d.max(axis=2) > tol).sum())})
        ok = ok and o <= maxo
    out["pass"] = ok
    out["exact"] = out["max_difference"] == 0
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("test")
    ap.add_argument("--root", required=True)
    ap.add_argument("--out-dir", required=True)
    ap.add_argument("--screen", action="store_true")
    ap.add_argument("--direct", action="store_true",
                    help="run the SWF as root, screenshot after it settles (tick unpinned)")
    ap.add_argument("--settle", type=float, default=2.5)
    a = ap.parse_args()
    d = os.path.join(a.root, a.test)
    with open(os.path.join(d, "test.toml"), "rb") as f:
        toml = tomllib.load(f)
    last = int(toml.get("num_ticks") or toml.get("num_frames") or 1)
    comps = toml.get("image_comparisons", {})
    stem = a.test.replace("/", "__")
    sfx = ".screen" if a.screen else (".direct" if a.direct else "")
    os.makedirs(os.path.join(a.out_dir, "png"), exist_ok=True)
    rec = {"test": a.test, "mode": "screen" if a.screen else ("direct" if a.direct else "draw"), "num_ticks": last,
           "comparisons": {}}
    want = {}
    for name, comp in comps.items():
        trig = comp.get("trigger", last)
        if not isinstance(trig, int):
            rec["comparisons"][name] = {"trigger": trig, "untestable": f"trigger={trig}"}
            continue
        want[name] = trig
    ticks = sorted(set(want.values()))
    images = {}
    stops = []
    try:
        if a.direct:
            fps = max(flashenv.swf_info(os.path.join(d, "test.swf"))["rate"], 1)
            crop, log = direct_screen(d, a.settle + (max(ticks) / fps if ticks else 0))
            stops.append("direct")
            rec["log_tail"] = log.splitlines()[-6:]
            if crop is not None:
                # One grab stands in for every trigger (static content only).
                images = {t: crop for t in ticks}
        elif a.screen:
            for t in ticks:
                imgs, log, reason, info, q = run_image.capture(d, ticks=[t], screen=True)
                stops.append(reason)
                shot = imgs.pop("screen", None)
                w, h = int(round(info["width"])), int(round(info["height"]))
                if shot and "image" in shot:
                    crop, _ = run_image.crop_stage(shot, w, h)
                    if crop is not None:
                        images[t] = crop
        elif ticks:
            images, log, reason, info, q = run_image.capture(d, ticks=ticks)
            stops.append(reason)
            if not images:
                rec["log_tail"] = log.splitlines()[-8:]
    except Exception as e:  # noqa: BLE001
        rec["error"] = repr(e)
    rec["stop"] = stops
    for name, t in want.items():
        r = {"trigger": t}
        golden = os.path.join(d, f"{name}.expected.png")
        if not os.path.exists(golden):
            r["untestable"] = "no golden png"
        elif t not in images:
            r["error"] = "no capture"
        else:
            img = images[t]
            img.save(os.path.join(a.out_dir, "png", f"{stem}__{name}{sfx}.png"))
            r.update(grade(img, golden, comps[name].get("checks") or [comps[name]]))
        rec["comparisons"][name] = r
    with open(os.path.join(a.out_dir, stem + sfx + ".json"), "w") as f:
        json.dump(rec, f, indent=1)
    summ = {n: ("PASS" if c.get("pass") else ("EXACT" if c.get("exact") else
            c.get("untestable") or c.get("error") or f"{c.get('diff_pixels')}px/max{c.get('max_difference')}"))
            for n, c in rec["comparisons"].items()}
    print(a.test, rec["mode"], json.dumps(summ), flush=True)


if __name__ == "__main__":
    main()
