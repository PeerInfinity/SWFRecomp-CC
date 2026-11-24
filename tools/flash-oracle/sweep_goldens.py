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


def direct_screen(d, settle, pin=True, quality=None, fonts=()):
    """Run test.swf as the REAL root (no wrapper) and grab the Xvfb window
    after `settle` seconds. Tick is NOT pinned: valid only for content that
    is static after its last trigger. For AVM2 tests that touch `stage` in
    their constructor (null in a Loader child) and stage-sized tests.
    pin: start from the window-pin stub (README "Direct-mode window pin") in a
    staged copy of the test dir, so the test runs at 1:1 from its frame 1."""
    swf = os.path.abspath(os.path.join(d, "test.swf"))
    info = flashenv.swf_info(swf)
    w, h = int(round(info["width"])), int(round(info["height"]))
    stage_tmp = tempfile.mkdtemp(prefix="flashpin-")
    if pin:
        d = os.path.join(stage_tmp, "test")
        shutil.copytree(os.path.dirname(swf), d)
        swf = os.path.join(d, "test.swf")
        root = flashenv.pinned_root(swf, d, quality=quality)
        gate = flashenv.PinGate(d)
    else:
        root, gate = swf, None
    env = flashenv.PlayerEnv(trust_paths=[os.path.abspath(d)], fonts=fonts)
    xinfo = os.path.join(env.root, "xinfo")
    e = dict(os.environ, HOME=env.root, LC_ALL="C")
    inner = 'echo "$DISPLAY $XAUTHORITY" > "$0"; exec "$1" "$2"'
    child = subprocess.Popen(["xvfb-run", "-a", "-s", "-screen 0 " + flashenv.XVFB_SCREEN, "sh", "-c", inner,
                              xinfo, flashenv.DEFAULT_PLAYER, root], env=e, cwd=os.path.abspath(d),
                             stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, start_new_session=True)
    try:
        t0 = time.monotonic()
        while gate is not None and not gate.released:
            if os.path.exists(xinfo):
                gate.poll(flashenv.PlayerEnv._display_env(e, xinfo))
            time.sleep(0.05)
        time.sleep(max(0.0, settle - (time.monotonic() - t0)) + (0.5 if pin else 0))
        denv = flashenv.PlayerEnv._display_env(e, xinfo)
        ppm = os.path.join(env.root, "s.ppm")
        # Pinned narrow stages run Stage.align = TL: the stage is top-left.
        # Otherwise the area is stage-sized at 1:1 (centre == top-left).
        tl = pin and info["width"] < flashenv.NARROW_STAGE
        img, tree = run_image.grab_screen(denv, ppm, settle=0)
        crop = crop_centered({"image": img, "tree": tree}, w, h, top_left=tl)
        # Second grab 1 s later: a static stage makes the unpinned tick moot.
        img2, tree2 = run_image.grab_screen(denv, ppm, settle=1.0)
        crop2 = crop_centered({"image": img2, "tree": tree2}, w, h, top_left=tl)
        static = (crop is not None and crop2 is not None
                  and np.array_equal(np.asarray(crop), np.asarray(crop2)))
        log = env.read_log()
    finally:
        try:
            os.killpg(child.pid, 9)
        except ProcessLookupError:
            pass
        child.wait()
        env.cleanup()
        shutil.rmtree(stage_tmp, ignore_errors=True)
    return crop, log, static, (gate.released if gate else None)


def crop_centered(shot, w, h, top_left=False):
    """Direct-mode crop. Unpinned, the root runs show-all with default (centre)
    align, so a stage narrower than the drawing area (the menubar keeps it
    >= ~296 px wide) is centred in it, and clipped by the stage-wide toplevel.
    Pinned, the stub's Stage.align = TL puts it top-left at 1:1."""
    return run_image.crop_stage(shot, w, h, center=not top_left)[0]


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
    ap.add_argument("--no-pin", action="store_true", help="--direct without the window pin")
    ap.add_argument("--quality", help="override test.toml with_renderer.quality (draw/screen/direct); "
                    "a golden can be Flash at its DEFAULT high quality while test.toml says low")
    ap.add_argument("--windows", action="store_true",
                    help="draw mode on the Windows projector (strictly one run at a time)")
    a = ap.parse_args()
    d = os.path.join(a.root, a.test)
    with open(os.path.join(d, "test.toml"), "rb") as f:
        toml = tomllib.load(f)
    last = int(toml.get("num_ticks") or toml.get("num_frames") or 1)
    comps = toml.get("image_comparisons", {})
    stem = a.test.replace("/", "__")
    sfx = ".screen" if a.screen else (".direct" if a.direct else (".win" if a.windows else ""))
    if a.quality:
        sfx += "." + a.quality
    os.makedirs(os.path.join(a.out_dir, "png"), exist_ok=True)
    rec = {"test": a.test, "mode": "screen" if a.screen else ("direct" if a.direct else
                                                         ("draw-win" if a.windows else "draw")),
           "num_ticks": last, "quality": a.quality,
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
            crop, log, rec["static"], rec["pin"] = direct_screen(d, a.settle + (max(ticks) / fps if ticks else 0), pin=not a.no_pin,
                                                                       quality=a.quality or run_image.toml_quality(toml),
                                                                       fonts=flashenv.toml_fonts(d, toml))
            stops.append("direct")
            rec["log_tail"] = log.splitlines()[-6:]
            if crop is not None:
                # One grab stands in for every trigger (static content only).
                images = {t: crop for t in ticks}
        elif a.screen:
            for t in ticks:
                imgs, log, reason, info, q = run_image.capture(d, ticks=[t], screen=True, quality=a.quality)
                stops.append(reason)
                shot = imgs.pop("screen", None)
                w, h = int(round(info["width"])), int(round(info["height"]))
                if shot and "image" in shot:
                    crop, _ = run_image.crop_stage(shot, w, h)
                    if crop is not None:
                        images[t] = crop
        elif ticks:
            images, log, reason, info, q = run_image.capture(d, ticks=ticks, windows=a.windows, quality=a.quality)
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
    print(a.test, rec["mode"], ("static " if rec.get("static") else "") + json.dumps(summ), flush=True)


if __name__ == "__main__":
    main()
