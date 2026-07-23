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
│                      #   known_red flag, golden_source, trace_prefix,
│                      #   ruffle_skipframes (checked in)
├── expected_trace.txt # optional trace expectation; exact match against the
│                      #   page's console output (checked in)
├── golden.png         # reference capture at canvas's intrinsic resolution
│                      #   (checked in)
├── golden_ruffle.png  # optional Ruffle-reference capture for B-group
│                      #   known-red probes (checked in)
├── ruffle_trace.txt   # Ruffle's own trace() output for the same SWF,
│                      #   written by capture_ruffle_golden.sh (checked in)
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

The venv is disposable; recreate it anywhere per
`SWFRecompDocs/guides/browser-test-harness-usage.md` (`python3 -m venv` +
`pip install playwright Pillow`; Chrome comes from `/usr/bin/google-chrome`,
so `playwright install` is not needed).

```bash
VENV=/path/to/venv/bin/python
xvfb-run -a $VENV tools/wasm_probe_runner.py
xvfb-run -a $VENV tools/wasm_probe_runner.py --probe leaf_shared_slot
xvfb-run -a $VENV tools/wasm_probe_runner.py --capture-golden
```

The harness drives a headed Chrome, navigates to each probe's `demo.html`
page, clicks Run, waits `settle_seconds` (default 1.5s), captures the canvas
via `canvas.toDataURL()` (intrinsic 320×240 pixels), and diffs against
`golden.png`. KNOWN_RED probes (gap probes whose graphics-WASM output
deliberately diverges from the Ruffle reference) are reported separately
and don't fail the run.

Exit code is non-zero iff any non-KNOWN_RED probe fails.

xvfb works here because the capture is an in-page `canvas.toDataURL()`, not a
compositor screenshot. Do not "upgrade" it to Playwright screenshots — those
come back blank.

## Trace channel

Every console message the page emits is recorded into the run's
`report.json` (`console`), and the subset that counts as probe output is
recorded as `trace`. Set `trace_prefix = "PROBE:"` in `probe.toml` and have
the SWF `trace()` lines carrying that marker; without a prefix every
`console.log` line counts, which sweeps in the runtime's own banner and the
`[HEAP]` line.

If a probe directory contains `expected_trace.txt`, the captured trace lines
must exact-match its non-empty lines. A trace mismatch fails the probe
exactly like a pixel mismatch, and `known_red` absorbs both the same way.
`--capture-golden` refreshes an `expected_trace.txt` that already exists but
never creates one, so a probe with no trace contract cannot silently acquire
whatever it happened to print.

Expectations are authored from the **Ruffle oracle**, not from our own
output: `tools/capture_ruffle_golden.sh` writes `<probe>/ruffle_trace.txt`
alongside the PNG (`exporter --trace-log`). Every gap probe below was
cross-checked three ways — Ruffle, NO_GRAPHICS native, and graphics-native —
before its browser result was called a bug.

## Probes

Group A/B/C are the original three; **group D** is the gate-inventory
adjudication set — one probe per suspicious cluster in
`SWFRecompDocs/reference/browser-wasm-gate-inventory.md`.

| Slug | Group | Status | Verifies |
|------|-------|--------|----------|
| `leaf_shared_slot` | C — future-proofing | green | Recompiler doesn't dedupe matrices; per-PlaceObject2 transform_data rows are independent. |
| `clone_basic` | A — regression | green | `actionCloneSprite` widening (`7fd96e6f2`). |
| `remove_basic` | A — regression | green | `actionRemoveSprite` + numeric-target coercion (`2d792bde3`). |
| `set_property_x` | A — regression | green | `actionSetProperty` `as_set_flags` un-gate (`aaaf111b4`). |
| `settarget_empty_to_child` | A — regression | green | `getMovieClipByTarget("")` un-gate (`aaaf111b4`). |
| `case_insensitive_settarget_swf5` | B — Ruffle parity | green | SWF≤6 SetTarget case-folding via `swf_name_match`. Originally hypothesized as known-red; landed green after the probe surprise-passed. |
| `settarget_failure_flag` | B — Ruffle parity | green | `g_settarget_*` flag-tracking after a failed SetTarget. **Was** known-red; the gate was widened and `probe.toml` cleared, so this row is now a regression guard, not a gap. |
| `clone_clip_actions` | B — Ruffle parity | green | Cloned sprites inherit `onClipEvent(load)`. **Was** known-red; likewise fixed and promoted. |
| `alpha_cxform_read` | D — gate inventory | **red** | `_alpha` of a placement-CXFORM-faded clip. browser reads 100, Flash/Ruffle/native read 50 (`mcReadAlpha`, action.c:26084). |
| `color_gettransform` | D — gate inventory | **red** | `Color.setTransform({rb:255})` then `getTransform().rb`. browser reads 0 *and* renders the box un-tinted — both halves of the round-trip are gated (`colorGetTransform`, action.c:10907). |
| `getproperty_timeline_x` | D — gate inventory | **red** | `_x`/`_y` of a purely timeline-moved clip on frame 3. browser reads **0, 0**; Flash/Ruffle/native read 200, 100 (display-truth arms, action.c:43212–43292). The widest-blast-radius red of the set. |
| `textformat_from_field` | D — gate inventory | **red** | `field.getTextFormat().size`/`.align`. browser reads `undefined`/`undefined`, Flash/Ruffle/native read 12/`left` (`createTextFormatFromField`, action.c:17312). |
| `transform_matrix_set` | D — gate inventory | **red** | `mc.transform.matrix = new flash.geom.Matrix(...)` and `.colorTransform = ...`. browser discards both — box neither moves nor tints (action.c:9072, 9146). |
| `typeof_textfield_button` | D — gate inventory | **red** | SWF6+ `typeof` of a textfield and of a button. browser says `movieclip` for both, Flash/Ruffle/native say `object` (action.c:43511, 43545). |
| `droptarget_scripted` | D — gate inventory | red, **does not adjudicate** | `_droptarget` after a scripted `startDrag`/`stopDrag` with no pointer input. browser reads `""` — and so does **Ruffle**, so the red here is native-vs-browser, not Flash-vs-browser. See the caveat row below. |
| `delete_child_mc` | D — gate inventory | green | `delete child` on a timeline child returns false and leaves `typeof` `"movieclip"`. The gated assignment at action.c:43861 is redundant with the unconditional `success = false` above it — the gate is a genuine no-op. |
| `var_textfield_sync` | D — gate inventory | green | `var bound = "CHANGED"` refreshes the bound EditText. browser matches on **both** `text` and `length`, so the field's property bag really tracks the write and the gated `ng_syncVarToTextFields` call in `actionDefineLocal` has an equivalent un-gated path. |

### Caveats on the group-D probes

- **`droptarget_scripted` cannot be trusted as a bug report.** Ruffle derives
  `_droptarget` from its mouse-driven `update_drag`, which never runs when
  nothing moves the pointer, so the Ruffle reference reads `""` — the same as
  browser-WASM. Our NO_GRAPHICS/graphics-native builds synthesize `/b` from
  the virtual hotspot instead, which is why the probe is red. It stays
  KNOWN_RED so the evidence is preserved, but the cluster's verdict in the
  gate inventory is *couldn't-probe*, not *bug*. Adjudicating it needs
  pointer injection in the runner, which the Ruffle exporter can't mirror.
- **Text probes render offstage.** `typeof_textfield_button`,
  `var_textfield_sync` and `textformat_from_field` place their EditText below
  the visible stage. Device-font glyph rasterization differs between Ruffle
  and us for reasons that have nothing to do with these gates, and an onstage
  field would have made every one of them red for the wrong reason. The
  verdict is carried by marker position plus the trace channel.
- **Verdict encoding.** Boolean checks are written to a marker as
  `(condition) / 0.005` — 200 when true, 0 when false — rather than via
  `_visible`. `_visible` has its own browser-WASM history, and a gate that
  no-ops leaves a marker visible, which would read as a false green.
- **`droptarget_scripted` uses the bare name `a`, not `/a`.** `actionEndDrag`
  looks the dragged clip up by the tail after the last `.` of the drag target
  name; a leading-slash path has no `.`, so the lookup misses and
  `_droptarget` is never written on *any* build. That is a separate
  native-side quirk, not the gate under test.

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
- Action element names are swfmill's own, not the SWF spec's. The ones the
  group-D probes needed, with their opcodes: `New` 0x40 (NewObject),
  `DeclareObject` 0x43 (InitObject), `DeclareArray` 0x42 (InitArray),
  `SetLocalVariable` 0x3C (DefineLocal), `DeclareLocalVariable` 0x41,
  `DeleteAll` 0x3B (Delete2), `Delete` 0x3A, `Duplicate` 0x4C
  (PushDuplicate), `StopDrag` 0x28 (EndDrag), `AddTyped` 0x47 (Add2),
  `ConcatenateString` 0x21 (StringAdd), `EqualTyped` 0x49 (Equals2),
  `LogicalNOT` 0x12, `Divide` 0x0D, `NewMethod` 0x53, `GetTarget` 0x45.
  There is no AVM1 multiply element — `x / 0.005` stands in for `x * 200`.
  Anything swfmill doesn't recognise is dropped silently, so round-trip and
  grep for the element after every `xml2swf`.
- A `<ColorTransform2>` multiply term is an 8.8 fixed-point **integer**:
  `factorAlpha="128"` is 0.5. `factorAlpha="0.5"` round-trips as 0.
- `<DefineEditText>` wants `initialText` as an attribute, not a child
  element.
- `<DefineButton2>` with an empty `<conditions/>` writes ActionOffset=0, and
  **Ruffle then never instantiates the button** — its instance name resolves
  to `undefined`. Give every button at least one `<Condition>` or any probe
  that touches it is comparing against a broken reference.
