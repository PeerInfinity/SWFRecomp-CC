#!/usr/bin/env python3
"""Render the graphics image-comparison dashboard as one static HTML page.

This is the ONLY HTML generator for image results. It reads the CI-published
per-suite instrument

    ruffle-tests/tests/swfs/<suite>/_results/image_results_<stem>.json

(written by `scripts/build_image_report.py` from a `mode=graphics images=true`
run, merged to master via the `ruffle-test-results` branch) and emits a
self-contained page: overall + per-suite counts, the outlier-magnitude
histogram, the near-miss band, family clusters, and a per-comparison table with
expected-vs-actual-vs-difference thumbnails for every FAILING comparison.

**Image comparisons never gate trace pass/fail.** A test's status comes from
the trace comparison alone; almost every `[image_comparisons]` test ships an
empty output.txt and trace-passes no matter what the pixels look like. This
page is the only place render correctness is observed. See
`SWFRecompDocs/plans/graphics-image-baseline.md`.

Roll-up correctness is delegated, deliberately:
  * `build_image_report.near_miss_band` / `NESTED_SUITES` — from_shumway/avm1
    lives inside from_shumway, whose own run already graded those tests; a
    naive glob over `_results/` double-counts them.
  * `image_baseline_report.load` / `family_of` — the same nested-suite guard
    and the same FAMILIES clustering the markdown baseline uses, so the page
    and the doc can never disagree.

Where the pixels come from
--------------------------
Expected PNGs live in the repo (`<test>/<cmp>.expected.png`). Actual and
difference PNGs live ONLY on the force-pushed `ruffle-image-results` branch
(failing comparisons only — passing renders are never published). Two ways to
reach them:

  --images-dir DIR   A checkout/export of that branch (either the branch root
                     or its `images/` subdir). PNGs are COPIED into
                     --asset-dir, so the deployed page is self-contained and
                     nothing is committed to master. This is what the Pages
                     build does.
  --raw-base URL     Fall back to raw.githubusercontent.com links. Tradeoff:
                     the branch is force-pushed on every image run, so raw
                     links go stale mid-cache — a viewer can see this run's
                     numbers next to a previous run's pixels. Only use when
                     copying is impractical.

If neither resolves (branch missing, stale, or not fetched), the page still
builds: the table renders without thumbnails and carries a visible note. The
build must never fail because the images branch is unavailable.

Usage:
    # CI / Pages build — self-contained, images copied in
    python3 scripts/generate_image_dashboard.py \
        --out=docs/image-dashboard/index.html \
        --asset-dir=docs/image-dashboard/img \
        --images-dir=/tmp/imgbranch

    # No images branch to hand — table only, with the degraded-mode note
    python3 scripts/generate_image_dashboard.py --out=/tmp/dash.html

    # Local advisory run (see ruffle-tests/run_image_tests.py)
    python3 scripts/generate_image_dashboard.py \
        --local-json=ruffle-tests/image_results.json \
        --out=ruffle-image-results.html
"""

import argparse
import html
import json
import os
import shutil
import sys
from collections import Counter, defaultdict
from datetime import datetime, timezone
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent
SWFS_ROOT = PROJECT_ROOT / "ruffle-tests" / "tests" / "swfs"

sys.path.insert(0, str(PROJECT_ROOT / "scripts"))
from build_image_report import near_miss_band  # noqa: E402
from image_baseline_report import family_of, load  # noqa: E402

RAW_EXPECTED_PREFIX = "master/ruffle-tests/tests/swfs"
RAW_ACTUAL_PREFIX = "ruffle-image-results/images"


# ---------------------------------------------------------------------------
# data
# ---------------------------------------------------------------------------

def collect_rows(stem):
    """Every comparison row from the per-suite CI instrument, plus per-suite
    report headers. Nested duplicate suites are excluded by `load`."""
    reports = load(stem)
    rows = []
    for rep in reports:
        for row in rep["results"]:
            row = dict(row)
            if row["status"] == "fail":
                row["band"] = near_miss_band(row)
            row["family"] = family_of(row["suite"], row["test"])
            rows.append(row)
    return reports, rows


def rows_from_local(path):
    """Adapt run_image_tests.py's image_results.json into the same row shape.

    A local run records outliers/max_diff parsed out of verify_output's message
    text and nothing else — no `excess_outliers`/`total_channels`, so the
    magnitude band is `unknown` for every failure and the histogram degrades to
    a single bucket. That is honest: a local Dawn render is advisory, not this
    measurement (see the module docstring of run_image_tests.py).
    """
    data = json.loads(Path(path).read_text())
    rows = []
    for t in data.get("tests", []):
        name = t.get("test", "")
        suite, _, rest = name.partition("/")
        test = rest or name
        for cmp_name, r in (t.get("image_comparisons") or {}).items():
            row = {
                "suite": suite,
                "test": test,
                "comparison": cmp_name,
                "status": r.get("status", "unknown"),
                "message": r.get("message", ""),
                "trace_status": t.get("trace_status"),
                "known_failure": False,
                "outliers": r.get("outliers"),
                "max_diff": r.get("max_diff"),
                "has_ruffle": bool(r.get("has_ruffle")),
            }
            if row["status"] == "fail":
                row["reason"] = "pixel_mismatch"
                row["band"] = "unknown"
            row["family"] = family_of(suite, test)
            rows.append(row)

    per_suite = defaultdict(Counter)
    for row in rows:
        per_suite[row["suite"]]["comparisons"] += 1
        per_suite[row["suite"]][row["status"]] += 1
    reports = [{
        "metadata": {"suite": s, "git_sha": data.get("metadata", {}).get("git_sha"),
                     "timestamp": data.get("metadata", {}).get("timestamp"),
                     "stem": "local"},
        "comparisons": c["comparisons"], "pass": c["pass"], "fail": c["fail"],
        "skip": c["skip"], "no_render": 0,
        "pass_rate": round(100 * c["pass"] / c["comparisons"], 1) if c["comparisons"] else 0,
    } for s, c in sorted(per_suite.items())]
    return reports, rows


# ---------------------------------------------------------------------------
# images
# ---------------------------------------------------------------------------

def _images_root(images_dir):
    """Accept either the branch root (which has an `images/` subdir) or the
    `images/` dir itself."""
    if not images_dir:
        return None
    p = Path(images_dir)
    if (p / "images").is_dir():
        p = p / "images"
    return p if p.is_dir() else None


def attach_images(rows, out_path, images_dir, asset_dir, raw_base, local):
    """Populate row['imgs'] = {kind: url}. Returns a stats dict for the page's
    provenance note. Never raises on a missing/partial images source."""
    root = _images_root(images_dir)
    asset_dir = Path(asset_dir) if asset_dir else None
    out_dir = out_path.parent
    stats = Counter()
    mode = "none"

    if local:
        mode = "local"
    elif root is not None:
        mode = "copy" if asset_dir else "link"
    elif raw_base:
        mode = "raw"

    def rel(p):
        return os.path.relpath(p, out_dir).replace("\\", "/")

    for row in rows:
        imgs = {}
        suite, test, cmp_name = row["suite"], row["test"], row["comparison"]
        want_actual = row["status"] == "fail"

        if mode == "local":
            # Everything sits next to the test itself after a local run.
            d = SWFS_ROOT / suite / test
            for kind in ("expected", "actual", "difference"):
                if (d / f"{cmp_name}.{kind}.png").exists():
                    imgs[kind] = rel(d / f"{cmp_name}.{kind}.png")
            if row.get("has_ruffle"):
                for kind in ("ruffle", "ruffle.difference"):
                    if (d / f"{cmp_name}.{kind}.png").exists():
                        imgs[kind] = rel(d / f"{cmp_name}.{kind}.png")
        elif mode == "raw":
            imgs["expected"] = (f"{raw_base}/{RAW_EXPECTED_PREFIX}/{suite}/{test}/"
                                f"{cmp_name}.expected.png")
            if want_actual:
                for kind in ("actual", "difference"):
                    imgs[kind] = (f"{raw_base}/{RAW_ACTUAL_PREFIX}/{suite}/{test}/"
                                  f"{cmp_name}.{kind}.png")
            stats["raw"] += 1
        elif mode in ("copy", "link"):
            src_expected = SWFS_ROOT / suite / test / f"{cmp_name}.expected.png"
            sources = {}
            if want_actual and src_expected.exists():
                sources["expected"] = src_expected
            if want_actual:
                for kind in ("actual", "difference"):
                    p = root / suite / test / f"{cmp_name}.{kind}.png"
                    if p.exists():
                        sources[kind] = p
            for kind, src in sources.items():
                if mode == "copy":
                    dest = asset_dir / suite / test / f"{cmp_name}.{kind}.png"
                    dest.parent.mkdir(parents=True, exist_ok=True)
                    shutil.copy2(src, dest)
                    imgs[kind] = rel(dest)
                else:
                    imgs[kind] = rel(src)

        if imgs.get("actual"):
            stats["with_actual"] += 1
        if row["status"] == "fail":
            stats["failures"] += 1
        if imgs:
            row["imgs"] = imgs

    stats["mode"] = mode
    return stats


# ---------------------------------------------------------------------------
# page
# ---------------------------------------------------------------------------

CAVEAT = ("Image comparisons never gate trace pass/fail. A test's status comes "
          "from the trace comparison alone, and almost every test carrying "
          "[image_comparisons] ships an empty output.txt — so it trace-passes "
          "no matter what a single pixel looks like. This dashboard is the "
          "only place render correctness is observed. Do not average these "
          "numbers with the trace pass rate, and do not read a rise in one as "
          "progress on the other.")

TEMPLATE = r"""<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>SWFRecomp — Graphics image-comparison dashboard</title>
<style>
  :root {
    --bg:#15161a; --fg:#e8e8ea; --muted:#9092a0; --card:#1e1f25; --card2:#25262e;
    --border:#32333d; --accent:#4a9eff;
    --pass:#3fa845; --fail:#e05252; --skip:#8a7fd0; --warn:#d4a017;
  }
  body.light { --bg:#f7f7f9; --fg:#1b1c20; --muted:#61636f; --card:#fff;
               --card2:#f0f0f4; --border:#dcdce4; --accent:#1565c0; }
  * { box-sizing:border-box; }
  body { margin:0; background:var(--bg); color:var(--fg);
         font:14px/1.5 -apple-system,BlinkMacSystemFont,"Segoe UI",Roboto,sans-serif; }
  a { color:var(--accent); }
  .wrap { max-width:1500px; margin:0 auto; padding:0 20px 60px; }
  header.page { border-bottom:1px solid var(--border); background:var(--card);
                padding:20px 0 16px; margin-bottom:20px; }
  header.page .wrap { padding-bottom:0; }
  header.page h1 { margin:0 0 6px; font-size:20px; }
  .vintage { color:var(--muted); font-size:12.5px; }
  .vintage code { color:var(--fg); }
  .banner { border-left:3px solid var(--warn); background:var(--card2);
            padding:10px 14px; margin:14px 0; font-size:13px; border-radius:0 4px 4px 0; }
  .banner.degraded { border-left-color:var(--fail); }
  .banner b { color:var(--warn); }
  .banner.degraded b { color:var(--fail); }
  h2 { font-size:15px; text-transform:uppercase; letter-spacing:.06em;
       color:var(--muted); margin:28px 0 10px; font-weight:600; }
  .tiles { display:flex; flex-wrap:wrap; gap:10px; }
  .tile { background:var(--card); border:1px solid var(--border); border-radius:6px;
          padding:10px 16px; min-width:120px; }
  .tile .n { font-size:24px; font-weight:600; font-variant-numeric:tabular-nums; }
  .tile .k { color:var(--muted); font-size:11px; text-transform:uppercase;
             letter-spacing:.05em; }
  .grid { display:grid; grid-template-columns:repeat(auto-fit,minmax(360px,1fr)); gap:20px; }
  table { border-collapse:collapse; width:100%; font-size:12.5px; }
  th,td { text-align:left; padding:5px 9px; border-bottom:1px solid var(--border);
          vertical-align:top; }
  th { color:var(--muted); font-weight:600; font-size:11px; text-transform:uppercase;
       letter-spacing:.04em; white-space:nowrap; }
  td.n, th.n { text-align:right; font-variant-numeric:tabular-nums; }
  tbody tr:hover { background:var(--card2); }
  .bar { display:inline-block; height:9px; background:var(--accent); border-radius:2px;
         vertical-align:middle; min-width:1px; }
  .clickable { cursor:pointer; }
  .clickable:hover td:first-child { text-decoration:underline; }
  code, .mono { font-family:ui-monospace,"SF Mono",Consolas,monospace; }
  .controls { position:sticky; top:0; z-index:5; background:var(--bg);
              padding:10px 0; border-bottom:1px solid var(--border);
              display:flex; flex-wrap:wrap; gap:8px; align-items:center; }
  .chip { padding:3px 10px; border:1px solid var(--border); border-radius:12px;
          background:var(--card); cursor:pointer; font-size:12px; user-select:none;
          white-space:nowrap; }
  .chip.active { background:var(--accent); color:#fff; border-color:var(--accent); }
  .chip .c { opacity:.7; margin-left:4px; font-size:11px; }
  select, input[type=search] { padding:4px 8px; background:var(--card); color:var(--fg);
       border:1px solid var(--border); border-radius:4px; font-size:12px; max-width:260px; }
  button.btn { padding:4px 10px; background:var(--card); color:var(--fg);
       border:1px solid var(--border); border-radius:4px; cursor:pointer; font-size:12px; }
  .lab { color:var(--muted); font-size:11px; text-transform:uppercase;
         letter-spacing:.05em; }
  .suite-h { margin:22px 0 4px; font-size:14px; font-weight:600; }
  .suite-h .sub { color:var(--muted); font-weight:400; font-size:12px; margin-left:8px; }
  .st { padding:1px 7px; border-radius:9px; font-size:10.5px; font-weight:700;
        text-transform:uppercase; letter-spacing:.04em; color:#fff; }
  .st-pass { background:var(--pass); } .st-fail { background:var(--fail); }
  .st-skip { background:var(--skip); } .st-unknown { background:var(--muted); }
  .kf { color:var(--warn); font-size:10.5px; text-transform:uppercase; }
  tr.figrow > td { border-bottom:1px solid var(--border); padding-top:0; }
  .figs { display:flex; gap:6px; flex-wrap:wrap; margin:0 0 4px; }
  .figs figure { margin:0; text-align:center; border:1px solid var(--border);
                 background:#0d0d10; padding:3px; border-radius:3px; }
  .figs img { display:block; max-width:230px; max-height:230px; image-rendering:pixelated;
              background:repeating-conic-gradient(#202027 0% 25%,#282830 0% 50%) 50%/14px 14px; }
  body.light .figs figure { background:#fff; }
  body.light .figs img { background:repeating-conic-gradient(#eaeaee 0% 25%,#dcdce2 0% 50%) 50%/14px 14px; }
  .figs figcaption { color:var(--muted); font-size:9.5px; padding-top:3px;
                     text-transform:uppercase; letter-spacing:.05em; }
  .msg { color:var(--muted); font-size:11.5px; }
  .empty { color:var(--muted); padding:36px; text-align:center; font-style:italic; }
  .foot { color:var(--muted); font-size:12px; margin-top:36px;
          border-top:1px solid var(--border); padding-top:12px; }
  @media (max-width:700px){ .figs img { max-width:140px; max-height:140px; } }
</style>
</head>
<body>
<header class="page"><div class="wrap">
  <h1>Graphics image-comparison dashboard</h1>
  <div class="vintage">__VINTAGE__</div>
</div></header>
<div class="wrap">

<div class="banner"><b>Not a pass/fail metric.</b> __CAVEAT__</div>
__DEGRADED__

<h2>Corpus totals</h2>
<div class="tiles" id="tiles"></div>

<div class="grid">
  <div>
    <h2>Per suite</h2>
    <table id="suite-table"><thead><tr>
      <th>suite</th><th class="n">cmps</th><th class="n">pass</th><th class="n">fail</th>
      <th class="n">skip</th><th class="n">no&nbsp;render</th><th class="n">pass&nbsp;rate</th>
    </tr></thead><tbody></tbody></table>
  </div>
  <div>
    <h2>Outlier-magnitude histogram</h2>
    <p class="msg">Failures binned by <code>excess_outliers</code> — channels past
    that test's OWN <code>max_outliers</code> budget — as a fraction of the image's
    total channels. Every tolerance in the corpus was recorded against real Flash
    output and they differ wildly, so excess is comparable across tests where raw
    difference is not. Click a band to filter.</p>
    <table id="band-table"><thead><tr>
      <th>band</th><th class="n">failures</th><th class="n">share</th><th></th>
    </tr></thead><tbody></tbody></table>
    <p class="msg" id="nearmiss"></p>
  </div>
</div>

<h2>Failure families</h2>
<p class="msg">Clustered by test-name/feature keyword (the same FAMILIES table the
markdown baseline uses). A family is a hypothesis about which subsystem owns the
cluster, not a diagnosis. Click a family to filter.</p>
<table id="family-table"><thead><tr>
  <th>family</th><th class="n">failures</th>
  <th class="n">near-miss (&le;100 ch over)</th><th class="n">catastrophic (&ge;50%)</th>
</tr></thead><tbody></tbody></table>

<h2>Comparisons</h2>
<div class="controls">
  <span class="lab">Status</span>
  <span class="chip active" data-status="all">All</span>
  <span class="chip" data-status="fail">Fail</span>
  <span class="chip" data-status="pass">Pass</span>
  <span class="chip" data-status="skip">Skip</span>
  <select id="f-suite"><option value="all">every suite</option></select>
  <select id="f-family"><option value="all">every family</option></select>
  <select id="f-band"><option value="all">every band</option></select>
  <input type="search" id="f-search" placeholder="filter by test name…">
  <select id="f-sort">
    <option value="suite">sort: suite, then test</option>
    <option value="excess">sort: excess outliers (desc)</option>
    <option value="near">sort: closest to passing</option>
    <option value="maxdiff">sort: max_diff (desc)</option>
  </select>
  <label class="lab"><input type="checkbox" id="f-thumbs" checked> thumbnails</label>
  <button class="btn" id="reset">reset</button>
  <button class="btn" id="theme">&#9728;</button>
  <span class="lab" id="shown"></span>
</div>
<div id="rows"></div>

<div class="foot">
  <p>__FOOTNOTE__</p>
  <p>Generated by <code>scripts/generate_image_dashboard.py</code> from the
  per-suite <code>_results/image_results___STEM__.json</code> instrument.
  Interpretation, tolerances and the standing caveats:
  <a href="https://github.com/PeerInfinity/SWFRecomp-CC/blob/master/SWFRecompDocs/plans/graphics-image-baseline.md">graphics-image-baseline.md</a>.</p>
</div>
</div>

<script>
const DATA = __DATA__;
const ROWS = DATA.rows, SUITES = DATA.suites;
const $ = s => document.querySelector(s);

const nf = n => (n === null || n === undefined) ? "—" : n.toLocaleString();
const tot = DATA.totals;

$("#tiles").innerHTML = [
  ["comparisons", tot.comparisons, ""],
  ["pass", tot.pass, "var(--pass)"],
  ["fail", tot.fail, "var(--fail)"],
  ["skip", tot.skip, "var(--skip)"],
  ["no render", tot.no_render, "var(--muted)"],
  ["known_failure fails", tot.known_failure, "var(--muted)"],
  ["pass rate", (100*tot.pass/(tot.comparisons||1)).toFixed(1)+"%", "var(--accent)"],
].map(([k,v,c]) => `<div class="tile"><div class="n" style="color:${c||"inherit"}">${
   typeof v === "number" ? nf(v) : v}</div><div class="k">${k}</div></div>`).join("");

$("#suite-table").tBodies[0].innerHTML = SUITES.map(s =>
  `<tr class="clickable" data-suite="${s.suite}"><td class="mono">${s.suite}</td>
   <td class="n">${s.comparisons}</td><td class="n">${s.pass}</td>
   <td class="n">${s.fail}</td><td class="n">${s.skip}</td>
   <td class="n">${s.no_render}</td><td class="n">${s.pass_rate}%</td></tr>`).join("")
  + `<tr><td><b>total</b></td><td class="n"><b>${tot.comparisons}</b></td>
     <td class="n"><b>${tot.pass}</b></td><td class="n"><b>${tot.fail}</b></td>
     <td class="n"><b>${tot.skip}</b></td><td class="n"><b>${tot.no_render}</b></td>
     <td class="n"><b>${(100*tot.pass/(tot.comparisons||1)).toFixed(1)}%</b></td></tr>`;

const bandMax = Math.max(1, ...DATA.bands.map(b => b[1]));
$("#band-table").tBodies[0].innerHTML = DATA.bands.map(([b,n]) =>
  `<tr class="clickable" data-band="${b}"><td class="mono">${b}</td><td class="n">${n}</td>
   <td class="n">${(100*n/(tot.fail||1)).toFixed(1)}%</td>
   <td><span class="bar" style="width:${Math.round(140*n/bandMax)}px"></span></td></tr>`).join("");
$("#nearmiss").innerHTML = DATA.nearmiss;

$("#family-table").tBodies[0].innerHTML = DATA.families.map(f =>
  `<tr class="clickable" data-family="${f.name.replace(/"/g,'&quot;')}">
   <td>${f.name}</td><td class="n">${f.failures}</td>
   <td class="n">${f.near}</td><td class="n">${f.cat}</td></tr>`).join("");

for (const s of SUITES) $("#f-suite").add(new Option(`${s.suite} (${s.comparisons})`, s.suite));
for (const f of DATA.families) $("#f-family").add(new Option(`${f.name} (${f.failures})`, f.name));
for (const [b,n] of DATA.bands) $("#f-band").add(new Option(`${b} (${n})`, b));

const state = {status:"all", suite:"all", family:"all", band:"all", search:"",
               sort:"suite", thumbs:true};

const FIGS = [["expected","expected"],["actual","actual (ours)"],
              ["difference","difference"],["ruffle","ruffle"],
              ["ruffle.difference","diff vs ruffle"]];

function figHTML(r) {
  if (!state.thumbs || !r.imgs) return "";
  const f = FIGS.filter(([k]) => r.imgs[k]).map(([k,cap]) =>
    `<figure><a href="${r.imgs[k]}" target="_blank" rel="noopener">
      <img loading="lazy" src="${r.imgs[k]}" alt="${cap}"
       onerror="this.closest('figure').remove()"></a>
     <figcaption>${cap}</figcaption></figure>`).join("");
  return f ? `<div class="figs">${f}</div>` : "";
}

function rowHTML(r) {
  const budget = (r.outliers === undefined || r.outliers === null)
    ? "—" : `${nf(r.outliers)} / ${nf(r.max_outliers)}`;
  // Thumbnails go in their own full-width row rather than inside the test cell,
  // so a three-panel comparison never squeezes the numeric columns.
  const figs = figHTML(r);
  return `<tr>
    <td class="mono">${r.test}${r.comparison === "output" ? "" :
      ` <span class="msg">[${r.comparison}]</span>`}
      ${r.known_failure ? ' <span class="kf">known_failure</span>' : ""}
      <div class="msg">${r.message || ""}</div></td>
    <td><span class="st st-${r.status}">${r.status}</span>
      ${r.reason && r.reason !== "pixel_mismatch" ? `<div class="msg">${r.reason}</div>` : ""}</td>
    <td class="n">${budget}</td>
    <td class="n">${nf(r.excess_outliers)}</td>
    <td class="n">${nf(r.max_diff)}</td>
    <td class="n">${nf(r.tolerance)}</td>
    <td class="msg">${r.band || ""}</td>
    <td class="msg">${r.family}</td>
    <td class="msg">${r.trace_status || ""}</td>
  </tr>` + (figs ? `<tr class="figrow"><td colspan="9">${figs}</td></tr>` : "");
}

const HEAD = `<thead><tr><th>test</th><th>status</th>
  <th class="n">outliers&nbsp;/&nbsp;budget</th><th class="n">excess</th>
  <th class="n">max_diff</th><th class="n">tol</th><th>band</th><th>family</th>
  <th>trace</th></tr></thead>`;

function refresh() {
  const q = state.search.toLowerCase();
  let rs = ROWS.filter(r =>
    (state.status === "all" || r.status === state.status) &&
    (state.suite === "all" || r.suite === state.suite) &&
    (state.family === "all" || r.family === state.family) &&
    (state.band === "all" || r.band === state.band) &&
    (q === "" || (r.suite + "/" + r.test).toLowerCase().includes(q)));

  const byName = (a,b) => (a.suite+a.test+a.comparison).localeCompare(b.suite+b.test+b.comparison);
  if (state.sort === "excess") rs = rs.slice().sort((a,b) => (b.excess_outliers??-1)-(a.excess_outliers??-1) || byName(a,b));
  else if (state.sort === "near") rs = rs.slice().sort((a,b) =>
      (a.excess_outliers??Infinity)-(b.excess_outliers??Infinity) || byName(a,b));
  else if (state.sort === "maxdiff") rs = rs.slice().sort((a,b) => (b.max_diff??-1)-(a.max_diff??-1) || byName(a,b));
  else rs = rs.slice().sort(byName);

  $("#shown").textContent = `${rs.length} of ${ROWS.length} comparisons`;
  const out = [];
  if (!rs.length) out.push('<div class="empty">no comparisons match the current filters</div>');
  else if (state.sort === "suite") {
    let cur = null, buf = [];
    const flush = () => { if (cur !== null) out.push(
      `<div class="suite-h" id="suite-${cur.replace(/\//g,"-")}">${cur}
        <span class="sub">${buf.length} shown</span></div>
       <table>${HEAD}<tbody>${buf.join("")}</tbody></table>`); };
    for (const r of rs) {
      if (r.suite !== cur) { flush(); cur = r.suite; buf = []; }
      buf.push(rowHTML(r));
    }
    flush();
  } else {
    out.push(`<table>${HEAD}<tbody>${rs.map(rowHTML).join("")}</tbody></table>`);
  }
  $("#rows").innerHTML = out.join("");
}

document.querySelectorAll("[data-status]").forEach(c => c.addEventListener("click", () => {
  document.querySelectorAll("[data-status]").forEach(x => x.classList.remove("active"));
  c.classList.add("active"); state.status = c.dataset.status; refresh();
}));
const bind = (sel, key) => $(sel).addEventListener("change", e => { state[key] = e.target.value; refresh(); });
bind("#f-suite","suite"); bind("#f-family","family"); bind("#f-band","band"); bind("#f-sort","sort");
$("#f-search").addEventListener("input", e => { state.search = e.target.value; refresh(); });
$("#f-thumbs").addEventListener("change", e => { state.thumbs = e.target.checked; refresh(); });
$("#reset").addEventListener("click", () => {
  Object.assign(state, {status:"all", suite:"all", family:"all", band:"all", search:"", sort:"suite"});
  $("#f-suite").value = $("#f-family").value = $("#f-band").value = "all";
  $("#f-sort").value = "suite"; $("#f-search").value = "";
  document.querySelectorAll("[data-status]").forEach(x =>
    x.classList.toggle("active", x.dataset.status === "all"));
  refresh(); window.scrollTo({top:0});
});
$("#theme").addEventListener("click", () => {
  document.body.classList.toggle("light");
  $("#theme").innerHTML = document.body.classList.contains("light") ? "&#9790;" : "&#9728;";
});

function jump(patch) {
  Object.assign(state, patch);
  if (patch.suite !== undefined) $("#f-suite").value = patch.suite;
  if (patch.family !== undefined) $("#f-family").value = patch.family;
  if (patch.band !== undefined) { $("#f-band").value = patch.band; state.status = "fail";
    document.querySelectorAll("[data-status]").forEach(x =>
      x.classList.toggle("active", x.dataset.status === "fail")); }
  refresh();
  document.getElementById("rows").scrollIntoView({behavior:"smooth", block:"start"});
}
document.querySelectorAll("#suite-table tr[data-suite]").forEach(tr =>
  tr.addEventListener("click", () => jump({suite: tr.dataset.suite})));
document.querySelectorAll("#band-table tr[data-band]").forEach(tr =>
  tr.addEventListener("click", () => jump({band: tr.dataset.band})));
document.querySelectorAll("#family-table tr[data-family]").forEach(tr =>
  tr.addEventListener("click", () => jump({family: tr.dataset.family, status:"fail"})));

refresh();
</script>
</body>
</html>
"""


def build_page(reports, rows, stem, img_stats, images_dir, raw_base, local):
    fails = [r for r in rows if r["status"] == "fail"]
    tot = Counter()
    for r in rows:
        tot[r["status"]] += 1
    tot["comparisons"] = len(rows)
    tot["no_render"] = sum(1 for r in fails if r.get("reason") == "no_render")
    tot["known_failure"] = sum(1 for r in fails if r.get("known_failure"))

    bands = Counter(r.get("band", "unknown") for r in fails)
    famc = Counter(r["family"] for r in fails)
    famband = defaultdict(Counter)
    for r in fails:
        famband[r["family"]][r.get("band", "unknown")] += 1

    near = sum(1 for r in fails
               if r.get("band", "").startswith(("a_epsilon", "b_tiny")))
    eps = bands.get("a_epsilon (<=100 channels over)", 0)
    nearmiss = (f"<b>{near} of {len(fails)} failures ({100*near/len(fails):.1f}%) are "
                f"within 0.1% of channels of passing</b>, and {eps} are within 100 "
                f"channels. A small near-miss band means the pixel gap is mostly "
                f"<i>structural</i>, not antialiasing noise — treat the epsilon band "
                f"as lavapipe-vs-Ruffle AA drift until something else implicates it, "
                f"and the large/catastrophic bands as signal."
                ) if fails else "No failures."

    # Data vintage: the run these numbers came from, not when the page was built.
    shas = {rep["metadata"].get("git_sha") for rep in reports if rep["metadata"].get("git_sha")}
    times = sorted(t for t in (rep["metadata"].get("timestamp") for rep in reports) if t)
    sha = (shas.pop() if len(shas) == 1 else
           (f"{len(shas)} differing SHAs — results are MIXED" if shas else "unknown"))
    vintage = []
    vintage.append(f"Data from commit <code>{html.escape(str(sha)[:12])}</code>")
    if times:
        vintage.append(f"results written <code>{html.escape(times[-1][:19])}Z</code>")
    if len(shas) > 1:
        vintage.append('<b style="color:var(--fail)">suites disagree on commit — '
                       'this page mixes runs</b>')
    vintage.append(f"stem <code>image_results_{html.escape(stem)}</code>")
    vintage.append(f"page built <code>{datetime.now(timezone.utc).isoformat(timespec='seconds')}</code>")
    vintage.append('graded on CI <b>lavapipe</b> (software Vulkan, deterministic); '
                   'local Dawn renders are advisory only')

    degraded = ""
    mode = img_stats.get("mode")
    if mode in ("none",) or (img_stats["failures"] and not img_stats["with_actual"]
                             and mode != "raw"):
        degraded = ('<div class="banner degraded"><b>No rendered images available.</b> '
                    'The <code>ruffle-image-results</code> branch was not fetched, is '
                    'empty, or does not match these results, so this page shows counts '
                    'and statistics only. Re-run '
                    '<code>ruffle-tests.yml -f mode=graphics -f images=true</code> and '
                    'redeploy Pages to restore the thumbnails.</div>')
    elif mode == "raw" or (img_stats["failures"] and
                           img_stats["with_actual"] < img_stats["failures"]):
        missing = img_stats["failures"] - img_stats["with_actual"]
        if mode == "raw":
            degraded = ('<div class="banner"><b>Images served from '
                        'raw.githubusercontent.com.</b> The '
                        '<code>ruffle-image-results</code> branch is force-pushed on '
                        'every image run, so these links can go stale mid-cache — a '
                        'thumbnail may be from a later run than the numbers beside '
                        'it.</div>')
        else:
            degraded = (f'<div class="banner"><b>{missing} of {img_stats["failures"]} '
                        f'failing comparisons have no rendered PNG here.</b> The '
                        f'<code>ruffle-image-results</code> branch is force-pushed per '
                        f'run and may be older or newer than these results; those rows '
                        f'render as table entries only.</div>')

    footnote = ("Expected PNGs come from the test directories on <code>master</code>; "
                "actual and difference PNGs come from the force-pushed "
                "<code>ruffle-image-results</code> branch, which publishes FAILING "
                "comparisons only — a passing render is never saved, which is why "
                "passing rows have no thumbnails.")
    if mode == "copy":
        footnote += (" Both were copied into this site at build time, so the page is "
                     "self-contained and nothing is committed to <code>master</code>.")

    data = {
        "totals": dict(tot),
        "suites": [{"suite": rep["metadata"]["suite"], "comparisons": rep["comparisons"],
                    "pass": rep["pass"], "fail": rep["fail"], "skip": rep["skip"],
                    "no_render": rep["no_render"], "pass_rate": rep["pass_rate"]}
                   for rep in sorted(reports, key=lambda r: -r["comparisons"])],
        "bands": sorted(bands.items()),
        "families": [{"name": n, "failures": c,
                      "near": famband[n]["a_epsilon (<=100 channels over)"],
                      "cat": famband[n]["f_catastrophic (>=50%)"]}
                     for n, c in famc.most_common()],
        "nearmiss": nearmiss,
        "rows": rows,
    }

    return (TEMPLATE
            .replace("__CAVEAT__", html.escape(CAVEAT))
            .replace("__VINTAGE__", " &middot; ".join(vintage))
            .replace("__DEGRADED__", degraded)
            .replace("__FOOTNOTE__", footnote)
            .replace("__STEM__", html.escape(stem))
            .replace("__DATA__", json.dumps(data)))


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--stem", default="graphics",
                    help="Read _results/image_results_<stem>.json (default: graphics)")
    ap.add_argument("--local-json",
                    help="Instead of the CI instrument, adapt run_image_tests.py's "
                         "image_results.json (local advisory run)")
    ap.add_argument("--out", default="docs/image-dashboard/index.html",
                    help="Output HTML path")
    ap.add_argument("--images-dir",
                    help="Checkout/export of the ruffle-image-results branch (its root "
                         "or its images/ subdir)")
    ap.add_argument("--asset-dir",
                    help="Copy the PNGs the page needs here (makes the site "
                         "self-contained). Without it, --images-dir is linked in place.")
    ap.add_argument("--raw-base",
                    help="Fallback base URL for raw.githubusercontent.com links, e.g. "
                         "https://raw.githubusercontent.com/PeerInfinity/SWFRecomp-CC. "
                         "Used only when --images-dir is absent. Links go stale when "
                         "the branch is force-pushed.")
    args = ap.parse_args()

    if args.local_json:
        reports, rows = rows_from_local(args.local_json)
        stem = "local"
    else:
        reports, rows = collect_rows(args.stem)
        stem = args.stem
        if not reports:
            print(f"::error::no image_results_{args.stem}.json found under {SWFS_ROOT}",
                  file=sys.stderr)
            return 1

    out = Path(args.out)
    out.parent.mkdir(parents=True, exist_ok=True)
    stats = attach_images(rows, out, args.images_dir, args.asset_dir, args.raw_base,
                          local=bool(args.local_json))
    out.write_text(build_page(reports, rows, stem, stats, args.images_dir,
                              args.raw_base, bool(args.local_json)))

    tot = Counter(r["status"] for r in rows)
    print(f"{out}: {tot['pass']}/{len(rows)} comparisons pass "
          f"({tot['fail']} fail, {tot['skip']} skip) across {len(reports)} suites; "
          f"images mode={stats['mode']}, "
          f"{stats['with_actual']}/{stats['failures']} failures have a rendered PNG")
    return 0


if __name__ == "__main__":
    sys.exit(main())
