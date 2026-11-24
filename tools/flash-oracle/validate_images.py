#!/usr/bin/env python3
"""Capture Ruffle-layout image tests in Flash and compare to their goldens.

    validate_images.py <test_dir>... [--json out.json]

Uses each test.toml's [image_comparisons.<name>] tolerance / max_outliers
(Ruffle semantics: outliers are counted per CHANNEL) and the last-frame
trigger only. Prints one line per test.
"""
import argparse
import json
import os
import sys
import tomllib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import run_image  # noqa: E402


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("tests", nargs="+")
    ap.add_argument("--json")
    ap.add_argument("--save-dir")
    ap.add_argument("--windows", action="store_true")
    ap.add_argument("--screen", action="store_true",
                    help="compare the Xvfb screenshot instead of draw() (Linux only)")
    a = ap.parse_args()
    rows = []
    for d in a.tests:
        with open(os.path.join(d, "test.toml"), "rb") as f:
            toml = tomllib.load(f)
        comps = toml.get("image_comparisons", {})
        name, comp = next(iter(comps.items()))
        checks = comp.get("checks") or [comp]
        tol = checks[0].get("tolerance", 0)
        maxo = checks[0].get("max_outliers", 0)
        golden = os.path.join(d, f"{name}.expected.png")
        row = {"test": d, "tolerance": tol, "max_outliers": maxo}
        try:
            images, log, reason, info, quality = run_image.capture(
                d, screen=a.screen, windows=a.windows)
            row.update(stop=reason, quality=quality)
            shot = images.pop("screen", None)
            if shot is not None and "image" in shot:
                w, h = int(round(info["width"])), int(round(info["height"]))
                crop, _ = run_image.crop_stage(shot, w, h)
                row["draw_vs_screen"] = run_image.compare(crop, None, 0, other=next(iter(images.values()))) if crop else "no window"
                if crop is not None:
                    images = {0: crop}
            if not images:
                row["error"] = "no capture"
            else:
                img = next(iter(images.values()))
                if a.save_dir:
                    img.save(os.path.join(a.save_dir, d.strip("/").replace("/", "__") + ".png"))
                row.update(run_image.compare(img, golden, tol))
                row["pass"] = row.get("outliers", 1 << 60) <= maxo
                row["exact"] = run_image.compare(img, golden, 0).get("outliers")
        except Exception as e:  # noqa: BLE001
            row["error"] = repr(e)
        rows.append(row)
        print(json.dumps(row), flush=True)
    if a.json:
        with open(a.json, "w") as f:
            json.dump(rows, f, indent=1)


if __name__ == "__main__":
    main()
