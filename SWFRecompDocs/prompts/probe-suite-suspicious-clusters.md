# Session prompt: probe the browser-WASM suspicious clusters

Paste everything below this line into a fresh session.

---

Extend the **existing** WASM probe suite (`SWFRecomp/tests/wasm_probes/`) to
adjudicate the **suspicious clusters** from the browser-WASM gate inventory
(`SWFRecompDocs/reference/browser-wasm-gate-inventory.md`, "Triage pass" tail
section — 21 sites in 10 clusters where browser-WASM silently no-ops with no
parallel path found). Each new probe turns one cluster's verdict from
`suspicious` into either **`bug`** (probe red, with a repro) or
**`intentional`** (probe green — a hidden equivalent path exists).

**Hard scope boundary: DO NOT modify runtime sources**
(`SWFModernRuntime/src/`, `SWFRecomp/src/`). Reds are the deliverable, not
things to fix — they go back to a runtime-fix session with the probe as its
regression test. Tooling changes under `tools/` are allowed (one is
requested below).

## Infrastructure — already built, use it (verified 2026-07-23)

- `SWFRecomp/tests/wasm_probes/` holds 8 working probes; read its
  `README.md` first — per-probe layout (`test.xml` swfmill source,
  `config.toml`, `test_info.json`, `probe.toml`, `golden.png`), the
  KNOWN_RED convention, and the probe table you'll extend.
- Build: `source emsdk/emsdk_env.sh` then
  `./SWFRecomp/scripts/build_wasm_probes.sh [<slug>|--force]`
  (chains swfmill → SWFRecomp → `build_test.sh ... wasm --graphics` →
  deploy to `docs2/examples/wasm_probes/<slug>/`). `swfmill` is at
  `/usr/bin/swfmill`.
- Run/diff: `xvfb-run -a <venv-python> tools/wasm_probe_runner.py
  [--probe <slug>] [--capture-golden]`. The old venv at
  `/tmp/pong-probe/venv` is gone — recreate per
  `SWFRecompDocs/guides/browser-test-harness-usage.md` (python3 -m venv +
  `pip install playwright Pillow`). xvfb works here because the runner
  captures via in-page `canvas.toDataURL()`, NOT compositor screenshots —
  do not "upgrade" it to Playwright screenshots (those capture blank; see
  the browser-wasm-test-capture memory doc if curious).
- Ruffle reference goldens: `tools/capture_ruffle_golden.sh <slug>`
  (needs `~/CC/ruffle/target/release/exporter`; build with
  `cargo build --release -p exporter` if absent). For these gap probes,
  **Ruffle is the semantics oracle** — use `golden_source = "ruffle"` in
  `probe.toml` like the existing B-group probes.
- Chrome adapter is SwiftShader — functional checks only, never perf.
- Two clusters already have probe evidence: `settarget_failure_flag`
  (KNOWN_RED) covers the invalid-tellTarget half of the GetProperty
  cluster, and `clone_clip_actions` (KNOWN_RED) covers clone clip-events.
  Don't duplicate them; cite them.

## Task 0 — runner enhancement: console/trace capture

`tools/wasm_probe_runner.py` is golden-image-only. Add page-console capture:
record every console message during the run into the per-probe section of
`report.json`, and if a probe directory contains `expected_trace.txt`,
assert captured trace lines against it (exact match, same pass/fail
semantics as the pixel diff; KNOWN_RED applies to both). Several clusters
below are string-valued (`typeof`, `_droptarget`) — a red probe should show
the wrong *string*, not just wrong pixels. Keep the runner's existing CLI
and report format backward-compatible.

## New probes — one per cluster

Design rules (match the existing probes): single-frame or few-frame,
deterministic, settle within `settle_seconds`; encode each checked value
BOTH ways — `trace()` it (Task 0) AND branch it into a visual verdict
(e.g. green marker at a position iff the value matches Flash semantics,
red elsewhere) so the pixel diff catches it even alone. Author in swfmill
XML like the others; MTASC (`~/CC/mtasc/bin/mtasc`, see CLAUDE.md for
flags) is an acceptable fallback for AS2-heavy probes — check the built
SWF's bytecode does what you intend either way.

| slug (suggested) | cluster (inventory sites) | probe sketch |
|---|---|---|
| `transform_matrix_set` | transform setters — action.c 9072, 9146 | SWF8: `mc.transform.matrix = new Matrix(1,0,0,1,80,40)`; box should move; also set `transform.colorTransform` tint. Trace `mc._x` after. |
| `color_gettransform` | action.c 10907 | `new Color(mc).setTransform({rb:255})` then `getTransform()` — trace the returned `rb`/`ra`; branch marker on correctness. |
| `textformat_from_field` | action.c 17312 | EditText with known format; `tf = field.getTextFormat()`; trace `tf.size`, `tf.font`, `tf.align`. |
| `getproperty_timeline_x` | GetProperty display-truth — action.c 43212–43292 | Timeline-tween a clip (PlaceObject2 moves across frames, no AS writes); on a later frame trace `_x`/`_y` and place a marker at the read position — stale `mc->x` reads 0/initial. |
| `typeof_textfield_button` | action.c 43511, 43545 | SWF6+: `typeof(textfield)` and `typeof(button)` — trace both; Flash says `"object"`. |
| `delete_child_mc` | action.c 43861 | `delete mc` on a timeline child — trace the returned boolean (Flash: `false`) and `typeof(mc)` after (still `"movieclip"`). |
| `alpha_cxform_read` | action.c 26084 | Place a clip with a placement CXFORM alpha≈50%; trace `mc._alpha` (Flash: ~50, stale path: 100). |
| `droptarget_scripted` | drag — action.c 32895, 70182 | Two overlapping clips at origin; `startDrag(a)` then `stopDrag()` scripted (no mouse); trace `a._droptarget` (Flash: path of clip under the point, e.g. `/b`; gap: empty string). |
| `var_textfield_sync` | action.c 42849 | EditText with `variable="bound"`; frame script `var bound = "CHANGED";` — golden shows the new text rendered; also trace `field.text`. |

Deferred, document but don't build: **ByteArray charset** (avm2_bytearray.c
— AVM2 uses a different browser harness; log under the AVM2 backlog) and
**focus rect** (action.c 71861 — needs Tab-key injection the runner lacks;
note it as a runner follow-up).

## Verdict wiring (the actual deliverable)

For each probe: build → capture Ruffle golden → run browser-WASM → classify.

- **Red** (diverges from Ruffle/Flash): mark KNOWN_RED like the existing
  gap probes, and in the gate inventory change the cluster's sites from
  `suspicious` to `bug (probe: <slug>)` — edit both the table cells AND
  the "Triage pass" tail section (the tail is authoritative; cells are
  regenerated but preserved via `_harvest_triage`).
- **Green** (browser matches): change to `intentional (probe: <slug>
  green — equivalent path exists)`, and say in the tail what the hidden
  path is if you found it.
- **Also sanity-run each probe SWF through the native side**
  (`verify_output.py`-style single test or the graphics build) if quick —
  a probe that's red on native too is testing the wrong thing (native is
  parity-verified); rework it.

Update: `wasm_probes/README.md` probe table,
`SWFRecompDocs/plans/wasm-probe-suite.md` status header (note which
clusters are now adjudicated), and the gate inventory as above.

## Constraints

- No runtime source changes (repeated because it's the one rule that
  matters). Tools + probes + docs only.
- **Never run full test suites locally** (CLAUDE.md rule).
- Commit per the standard pipeline trailer. No CI dispatch — probes are
  not CI-observable (browser-only, no runner in CI).
- Environment gotchas: set `DISPLAY=:0` explicitly if driving headed
  Chrome (the shell doesn't inherit it); serve over `http://localhost`
  (WebGPU needs a secure context); recreate the venv.
- If a probe can't be made deterministic or its SWF can't express the
  behavior (swfmill limitation), say so in the README table rather than
  shipping a flaky probe — an honest gap beats a lying green.

## Final report

Per cluster: verdict (bug / intentional / couldn't-probe), the evidence
(trace lines + pixel diff), and for reds a one-line hypothesis of the
missing browser path (file:line of the gated site from the inventory).
The reds become the work list for a Fable runtime-fix session.
