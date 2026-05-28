# WASM Probe Suite

Hand-built minimal SWFs that each exercise one specific browser-WASM-graphics
behavior. Each probe is single-frame, deterministic, and verified by
golden-image comparison against a reference PNG capture.

Plan: `SWFRecompDocs/plans/wasm-probe-suite.md`.

## Per-probe layout

```
wasm_probes/<slug>/
├── test.xml           # swfmill source (checked in)
├── config.toml        # recompiler config (checked in)
├── test_info.json     # canvas size + opcode/description metadata (checked in)
├── probe.toml         # optional harness config — settle time, thresholds,
│                      #   known_red flag, golden_source (checked in)
├── golden.png         # reference capture at canvas's intrinsic resolution
│                      #   (checked in)
├── golden_ruffle.png  # optional Ruffle-reference capture for B-group
│                      #   known-red probes (checked in)
├── test.swf           # built by build_wasm_probes.sh (gitignored)
├── RecompiledScripts/ # generated (gitignored)
├── RecompiledTags/    # generated (gitignored)
└── build/             # generated (gitignored)
```

## Build

```bash
source emsdk/emsdk_env.sh
./SWFRecomp/scripts/build_wasm_probes.sh                  # build/deploy all
./SWFRecomp/scripts/build_wasm_probes.sh leaf_shared_slot # one probe
./SWFRecomp/scripts/build_wasm_probes.sh --force          # rebuild everything
```

The script chains `swfmill xml2swf` → `SWFRecomp config.toml` →
`build_test.sh ... --graphics` → `deploy_example.sh ... --graphics`. Probes
deploy to `docs2/examples/wasm_probes/<slug>/`.

## Run / diff against golden

```bash
xvfb-run -a /tmp/pong-probe/venv/bin/python tools/wasm_probe_runner.py
xvfb-run -a /tmp/pong-probe/venv/bin/python tools/wasm_probe_runner.py --probe leaf_shared_slot
xvfb-run -a /tmp/pong-probe/venv/bin/python tools/wasm_probe_runner.py --capture-golden
```

The harness drives a headed Chrome, navigates to each probe's `demo.html`
page, clicks Run, waits `settle_seconds` (default 1.5s), captures the canvas
via `canvas.toDataURL()` (intrinsic 320×240 pixels), and diffs against
`golden.png`. KNOWN_RED probes (gap probes whose graphics-WASM output
deliberately diverges from the Ruffle reference) are reported separately
and don't fail the run.

Exit code is non-zero iff any non-KNOWN_RED probe fails.

## Probes

| Slug | Group | Verifies |
|------|-------|----------|
| `leaf_shared_slot` | C — future-proofing | Recompiler doesn't dedupe matrices; per-PlaceObject2 transform_data rows are independent. |
| `clone_basic` | A — regression | `actionCloneSprite` widening (`7fd96e6f2`). |
| `remove_basic` | A — regression | `actionRemoveSprite` + numeric-target coercion (`2d792bde3`). |
| `set_property_x` | A — regression | `actionSetProperty` `as_set_flags` un-gate (`aaaf111b4`). |
| `settarget_empty_to_child` | A — regression | `getMovieClipByTarget("")` un-gate (`aaaf111b4`). |
| `case_insensitive_settarget_swf5` | B — known-red | SWF≤6 case-folding gap in `findDisplayObjectByName`. |
| `settarget_failure_flag` | B — known-red | Missing `g_settarget_invalid` flag-tracking in browser-WASM. |
| `clone_clip_actions` | B — known-red | `ng_queue_placement_clip_events` stub no-ops on cloned sprites. |
