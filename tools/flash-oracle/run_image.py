#!/usr/bin/env python3
"""Capture a Flash Player image of a Ruffle-layout test dir.

    run_image.py <test_dir> -o out.png [--ticks N[,M..]] [--quality low|medium|high|best]
                 [--swf test.swf] [--verbose] [--compare expected.png --tolerance T]

Reads num_ticks/num_frames and player_options.with_renderer.quality from
test.toml. See tools/flash-oracle/README.md for the tick model.
"""
import argparse
import base64
import os
import re
import shutil
import sys
import tempfile
import tomllib
import zlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import flashenv  # noqa: E402
from PIL import Image  # noqa: E402

HERE = os.path.dirname(os.path.abspath(__file__))
WRAPPER = os.path.join(HERE, "capture", "CaptureWrapper.swf")


def load_toml(test_dir):
    p = os.path.join(test_dir, "test.toml")
    if not os.path.exists(p):
        return {}
    with open(p, "rb") as f:
        return tomllib.load(f)


XGRAB = os.path.join(HERE, "xgrab", "xgrab")


def grab_screen(denv, out_ppm, settle=0.7):
    """Screenshot the Xvfb root; return (PIL image, window-tree text)."""
    import subprocess
    import time
    time.sleep(settle)
    r = subprocess.run([XGRAB, out_ppm], env=denv, capture_output=True, text=True)
    return Image.open(out_ppm).convert("RGB"), r.stderr


def capture(test_dir, ticks=None, quality=None, swf_name=None, verbose=False,
            max_duration=None, keep=False, screen=False, windows=False):
    toml = load_toml(test_dir)
    if ticks is None:
        n = toml.get("num_ticks") or toml.get("num_frames") or 1
        ticks = [int(n)]
    if quality is None:
        wr = toml.get("player_options", {}).get("with_renderer", {})
        quality = wr.get("quality", "high") if isinstance(wr, dict) else "high"
    swf = os.path.join(test_dir, swf_name or "test.swf")
    info = flashenv.swf_info(swf)
    w, h = int(round(info["width"])), int(round(info["height"]))
    if windows:
        os.makedirs(flashenv.WIN_ROOT + "/work", exist_ok=True)
        work = tempfile.mkdtemp(prefix="flashcap-", dir=flashenv.WIN_ROOT + "/work")
        # Windows can't load from the WSL fs: stage the test dir alongside.
        stage_dir = os.path.join(work, "test")
        shutil.copytree(test_dir, stage_dir)
        swf = os.path.join(stage_dir, swf_name or "test.swf")
    else:
        work = tempfile.mkdtemp(prefix="flashcap-")
    try:
        # The child SWF is copied next to the wrapper so relative loads of
        # the child's own assets resolve against its original dir instead:
        # we load it by absolute file URL.
        wrapper = os.path.join(work, "wrapper.swf")
        flashenv.patch_swf_header(WRAPPER, wrapper, info["rect"], info["rate"])
        cfg = {
            "swf": ("file:///" + flashenv.winpath(swf).replace("\\", "/")) if windows
                   else "file://" + os.path.abspath(swf),
            "width": w, "height": h, "bg": info["bg"],
            "quality": quality, "ticks": ",".join(map(str, ticks)),
            "verbose": "1" if verbose else "0",
            "hold": "1" if screen else "0",
        }
        with open(os.path.join(work, "capture_config.txt"), "w") as f:
            f.write("".join(f"{k}={v}\n" for k, v in cfg.items()))
        if windows:
            if screen:
                raise SystemExit("--screen is Linux/Xvfb only")
            env = flashenv.WinPlayerEnv(trust_paths=[work])
        else:
            env = flashenv.PlayerEnv(trust_paths=[work, os.path.abspath(test_dir)])
        frame_s = 1.0 / max(info["rate"], 1)
        md = max_duration or (5.0 + max(ticks) * frame_s * 3)
        shot = {}

        def on_marker(denv):
            ppm = os.path.join(work, "screen.ppm")
            shot["image"], shot["tree"] = grab_screen(denv, ppm)

        log = env.run(wrapper, max_duration=md, max_idle=md, cwd=work,
                      done_marker="#FLASHCAP HOLD" if screen else "#FLASHCAP DONE",
                      on_marker=on_marker if screen else None)
        reason = env.stop_reason
        if not keep:
            env.cleanup()
    finally:
        if not keep:
            shutil.rmtree(work, ignore_errors=True)
    images = decode_log(log)
    if screen:
        images["screen"] = shot
    return images, log, reason, info, quality


def toml_quality(toml):
    """test.toml player_options.with_renderer.quality (default "high")."""
    wr = toml.get("player_options", {}).get("with_renderer", {})
    return wr.get("quality", "high") if isinstance(wr, dict) else "high"


def drawing_area(tree):
    """The projector's GTK drawing area in an xgrab tree dump: the largest
    viewable child of the "Adobe Flash Player" toplevel, as (x, y, w, h).
    It can be larger than the visible stage: the menubar keeps it >= ~296 px
    wide (and ~100 px high) while the toplevel shrinks to the stage width and
    clips it. Picking "the smallest window >= w x h" instead (the s27 rule)
    chose the 20x72 toplevel - its menubar - for stages under ~296x100."""
    best = None
    in_top = False
    for line in tree.splitlines():
        m = re.search(r"abs=(-?\d+),(-?\d+) size=(\d+)x(\d+)", line)
        if not m:
            continue
        depth = (len(line) - len(line.lstrip(" "))) // 2
        if depth == 1:
            in_top = "name=Adobe Flash Player" in line
            continue
        if in_top and depth == 2:
            x, y, ww, hh = map(int, m.groups())
            if best is None or ww * hh > best[2] * best[3]:
                best = (x, y, ww, hh)
    return best


def crop_stage(shot, w, h, center=False):
    """Crop the stage out of a root screenshot: the top-left w x h of the
    drawing area (the wrapper and the pin stub set top-left align), or its
    centre for an unpinned direct root (show-all, centre align)."""
    best = drawing_area(shot["tree"])
    if best is None or best[2] < w or best[3] < h:
        return None, None
    x, y = best[0], best[1]
    if center:
        x, y = x + (best[2] - w) // 2, y + (best[3] - h) // 2
    return shot["image"].crop((x, y, x + w, y + h)).convert("RGBA"), (x, y)


def decode_log(log):
    images = {}
    cur = None
    for line in log.splitlines():
        m = re.match(r"#FLASHCAP BEGIN tick=(\d+) w=(\d+) h=(\d+)", line)
        if m:
            cur = (int(m[1]), int(m[2]), int(m[3]), [])
            continue
        if cur and line.startswith("#FLASHCAP D "):
            cur[3].append(line[12:])
        elif cur and line.startswith("#FLASHCAP END"):
            t, w, h, parts = cur
            raw = zlib.decompress(base64.b64decode("".join(parts)))
            # getPixels gives ARGB big-endian per pixel
            argb = Image.frombytes("RGBA", (w, h), raw)
            a, r, g, b = argb.split()
            # The capture BitmapData is opaque, but Windows Flash's draw()
            # leaves alpha < 255 under scrollRect'd content (RGB is right;
            # measured on visual/scroll_rect_culling). Force opaque.
            a = a.point(lambda _: 255)
            images[t] = Image.merge("RGBA", (r, g, b, a))
            cur = None
    return images


def compare(actual, expected_path, tolerance=0, other=None):
    exp = (other if other is not None else Image.open(expected_path)).convert("RGBA")
    act = actual.convert("RGBA")
    if exp.size != act.size:
        return {"size_mismatch": (exp.size, act.size)}
    ea, aa = exp.tobytes(), act.tobytes()
    outliers = 0
    maxd = 0
    px = 0
    for i in range(0, len(ea), 4):
        bad = False
        for c in range(4):
            d = abs(ea[i + c] - aa[i + c])
            if d > maxd:
                maxd = d
            if d > tolerance:
                outliers += 1
                bad = True
        px += bad
    return {"outliers": outliers, "outlier_pixels": px, "max_difference": maxd}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("test_dir")
    ap.add_argument("-o", "--output", required=True)
    ap.add_argument("--ticks")
    ap.add_argument("--quality")
    ap.add_argument("--swf")
    ap.add_argument("--verbose", action="store_true")
    ap.add_argument("--max-duration", type=float)
    ap.add_argument("--compare")
    ap.add_argument("--tolerance", type=int, default=0)
    ap.add_argument("--log", help="write the raw flashlog here")
    ap.add_argument("--windows", action="store_true",
                    help="use the Windows projector via WSL interop (C:\\flashplayer)")
    ap.add_argument("--screen", action="store_true",
                    help="also screenshot the projector window at the last capture tick "
                         "(written as <out>.screen.png; the stage is frozen, not quit)")
    a = ap.parse_args()
    ticks = [int(t) for t in a.ticks.split(",")] if a.ticks else None
    images, log, reason, info, quality = capture(a.test_dir, ticks, a.quality, a.swf,
                                                 a.verbose, a.max_duration, screen=a.screen,
                                                 windows=a.windows)
    shot = images.pop("screen", None)
    if a.log:
        with open(a.log, "w") as f:
            f.write(log)
    if a.verbose:
        print("\n".join(l for l in log.splitlines() if not l.startswith("#FLASHCAP D ")))
    if not images:
        print(f"no capture (stop={reason}); log tail:\n" + "\n".join(log.splitlines()[-20:]),
              file=sys.stderr)
        sys.exit(1)
    base, ext = os.path.splitext(a.output)
    for t, img in sorted(images.items()):
        out = a.output if len(images) == 1 else f"{base}.tick{t}{ext}"
        img.save(out)
        msg = f"tick {t}: {out} {img.size[0]}x{img.size[1]} quality={quality} stop={reason}"
        if a.compare:
            msg += f" vs {a.compare}: {compare(img, a.compare, a.tolerance)}"
        print(msg)
    if shot is not None:
        w, h = int(round(info["width"])), int(round(info["height"]))
        out = f"{base}.screen{ext}"
        if "image" not in shot:
            print("screen: no screenshot taken", file=sys.stderr)
        else:
            crop, at = crop_stage(shot, w, h)
            if crop is None:
                shot["image"].save(f"{base}.screenroot{ext}")
                print(f"screen: no {w}x{h} window found; root saved. tree:\n{shot['tree']}")
            else:
                crop.save(out)
                last = images[max(images)]
                print(f"screen: {out} (window at {at}) vs draw(): {compare(crop, a.output if len(images) == 1 else f'{base}.tick{max(images)}{ext}')}")
                if a.compare:
                    print(f"screen vs {a.compare}: {compare(crop, a.compare, a.tolerance)}")


if __name__ == "__main__":
    main()
