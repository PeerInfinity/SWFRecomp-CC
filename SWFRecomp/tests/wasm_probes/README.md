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

| Slug | Group | Status | Verifies |
|------|-------|--------|----------|
| `leaf_shared_slot` | C — future-proofing | green | Recompiler doesn't dedupe matrices; per-PlaceObject2 transform_data rows are independent. |
| `clone_basic` | A — regression | green | `actionCloneSprite` widening (`7fd96e6f2`). |
| `remove_basic` | A — regression | green | `actionRemoveSprite` + numeric-target coercion (`2d792bde3`). |
| `set_property_x` | A — regression | green | `actionSetProperty` `as_set_flags` un-gate (`aaaf111b4`). |
| `settarget_empty_to_child` | A — regression | green | `getMovieClipByTarget("")` un-gate (`aaaf111b4`). |
| `case_insensitive_settarget_swf5` | B — Ruffle parity | green | SWF≤6 SetTarget case-folding via `swf_name_match`. Originally hypothesized as known-red; landed green after the probe surprise-passed. |
| `settarget_failure_flag` | B — known-red | red | Missing `g_settarget_invalid` flag-tracking in browser-WASM after failed SetTarget. |
| `clone_clip_actions` | B — known-red | red | `ng_queue_placement_clip_events` stub no-ops on cloned sprites; inherited `onClipEvent(load)` doesn't fire on the duplicate. |

## Capturing a Ruffle reference (B-group / known-red probes)

`tools/capture_ruffle_golden.sh [<slug>]` invokes `~/CC/ruffle/target/
release/exporter` to render `test.swf` at the probe's intrinsic canvas
size (read from `test_info.json`'s `metadata.width`/`metadata.height`) into
`<probe>/golden_ruffle.png`. Override `RUFFLE_EXPORTER=/path/to/exporter`
to use a different build. Build the exporter with `cd ~/CC/ruffle && cargo
build --release -p exporter`.

The probe.toml's `golden_source = "ruffle"` selects `golden_ruffle.png` as
the comparison target for that probe. Pair it with `known_red = true` for
gap probes whose graphics-WASM output is *expected* to diverge from
Ruffle — the harness reports them in a separate "red as expected"
section. A KNOWN_RED probe that suddenly passes flips to "surprise pass"
and prompts manual promotion (clear `known_red` in probe.toml).

## swfmill encoding gotchas

- swfmill 0.3.6 silently drops unrecognized XML elements (returns success,
  emits the SWF without them). After every `xml2swf`, run
  `swfmill swf2xml test.swf - | grep <element>` to verify the structure
  survived. The first probes hit this with `<CloneSprite/>` (correct name
  is `<DuplicateSprite/>`) and again with `<clipActions>` (correct name
  is `<events>` containing `<Event flags1="..." flags2="...">`).
- Top-level XML comments (`<!-- ... -->` before `<swf>`) make swfmill
  reject the file as "not a swfml file." Put commentary inside the `<swf>`
  element.
- swfmill's reference.html (`/usr/share/doc/swfmill/reference.html`) is
  incomplete on PlaceObject2's sub-elements. Trust round-trips, not the
  docs.
