# Session prompt: fix the six probe-confirmed browser-WASM bugs

Paste everything below this line into a fresh session. Run this on **Fable**
— browser-WASM runtime arms are the historically-subtle area this project
reserves for it.

---

Fix the **six confirmed browser-WASM bugs** from the probe adjudication
(commit `3a4515f27`). Read first:

- `SWFRecompDocs/reference/browser-wasm-gate-inventory.md` — "Probe
  adjudication" evidence + the flagged tables (each bug's exact site).
- `SWFRecomp/tests/wasm_probes/README.md` — group D probes; each bug
  already has its regression test, currently KNOWN_RED.

**Acceptance per bug:** its probe flips KNOWN_RED → green (edit
`probe.toml`), the full probe suite passes with the remaining known-reds
unchanged, and native behavior is untouched (graphics CI zero regressions —
these fixes live in browser-only arms, so CI is the native regression guard;
the probe run is the only browser verification, CI cannot see it).

## Verified facts that shape the fixes (2026-07-23 recon — don't re-derive)

- **The MovieClip struct fields are NOT mode-gated** — `display_obj`,
  `last_transform_id`, `as_set_flags`, `ng_textfield_idx`, `cx_*` are
  unconditional members (`include/actionmodern/action.h` ~55-80). The
  `#if NO_GRAPHICS||OFFSCREEN_RENDER` blocks you'll touch gate *code*, not
  data. (The gated designated-initializer entries elsewhere just make
  zero-init explicit.)
- `markTransformedByScript` (action.c:72) is an **ungated** static inline
  and a safe no-op when `mc->display_obj == NULL` (typical in browser).
- **Precedent for the whole class:** commit `aaaf111b4` fixed
  `set_property_x` by un-gating `as_set_flags` writes — browser rendering
  already honors `mc->x/y/xscale/...` + `as_set_flags` via
  `apply_as_transform` and the `dynamic_xform_slot` path (see the field's
  comment in action.h). "Widen the gate so the mc-field writes happen" is
  a proven, render-visible fix shape in browser-WASM.
- `alpha_cxform_read`'s probe showed the browser RENDER is correct and only
  the AS read is stale — so the browser render path knows the effective
  cxform; find where it gets it and read from the same source.
- `var_textfield_sync` probed GREEN because an un-gated TextField binding
  registry exists in browser — relevant to the TextFormat fix below.

## The six bugs, easiest → hardest (do them in this order)

1. **`typeof_textfield_button`** (action.c 43511, 43545 — browser says
   `"movieclip"` for textfields/buttons, Flash/Ruffle say `"object"`).
   Both gated blocks read only ungated fields (`is_button_mc`,
   `MC_IS_TEXTFIELD` → `ng_textfield_idx`, `g_swf_version`). Expected fix:
   remove/widen both gates. Verify `MC_IS_TEXTFIELD`'s macro (action.c
   ~26168) is visible at those sites in browser builds. Do this one first
   to establish the fix→rebuild-probe→re-run loop.
2. **`alpha_cxform_read`** (action.c 26084 — `_alpha` reads 100 where
   placement CXFORM says 50). Native reads via `mc->display_obj`; in
   browser that's likely NULL. Trace how the browser renderer obtains the
   placement cxform (probe proves it does) and give `mcReadAlpha` a
   browser arm reading the same source (`display_list` and its `cxform_id`
   fields are written by shared tag.c code — check what's populated in
   browser before assuming).
3. **`transform_matrix_set`** (action.c 9072 setter + 9146
   colorTransform setter). The 9072 body writes only ungated mc fields +
   `markTransformedByScript` — candidate for a straight un-gate; check
   whether the tint half (9146 → `setLocalCTRaw`) and its helpers are
   linkable in browser builds, and where browser rendering picks up
   `mc->cx_*` for dynamic tints (the probe's un-tinted box says today it
   doesn't — that may be the real other half of this fix).
4. **`color_gettransform`** (action.c 10907 — returns identity). Once
   `Color.setTransform`'s browser write path exists (item 3), the getter
   can fall back to `mc->cx_*` when there's no display entry; mirror the
   native code's own dynamic-MC fallback branch which does exactly that.
5. **`textformat_from_field`** (action.c 17312 — `getTextFormat` returns
   undefined fields). 187-line native-only block keyed on the
   `ng_textfields` registry (`tf_idx`). The green `var_textfield_sync`
   probe proves a browser textfield registry exists — determine whether it
   IS `ng_textfields` (then widen the gate) or a parallel structure (then
   bridge the metadata). Don't guess: read how browser EditText setup
   registers fields.
6. **`getproperty_timeline_x`** (action.c 43212–43292 — `_x`/`_y` read 0
   for a timeline-tweened clip; browser `mc->x/y` NEVER track timeline
   MOVE tags). The deep one. Native reads display-entry truth
   (`syncTransformIfNeeded` + `ng_getTransformXY_d`). In browser,
   `display_list[depth].transform_id` is written by shared tag.c code —
   the question is whether the CPU-side `transform_data` table (baked
   slots) is available in browser builds to decode tx/ty from (beware:
   a graphics-native comment in tag.c warns the CPU table only holds
   BAKED slots — dynamic runtime slots are GPU-only; timeline MOVE tags
   use baked slots, so this may be sufficient). If a clean browser read
   path exists, also apply it to `_xscale`/`_yscale`/`_rotation`
   (sites 43246–43292) with the same `as_set_flags` precedence the native
   arm uses. If it turns into an architecture project, fix `_x`/`_y`
   first, flip the probe, and file the rest with evidence — don't force it.

Cross-cutting: every new browser arm must respect the same
`as_set_flags`-wins-over-timeline precedence the native arms implement,
or you'll break the already-green `set_property_x` probe.

## Workflow

Per bug: edit → `./SWFRecomp/scripts/build_wasm_probes.sh <slug>` (needs
`source emsdk/emsdk_env.sh`) → `xvfb-run -a <venv-python>
tools/wasm_probe_runner.py --probe <slug>` (venv per
`SWFRecompDocs/guides/browser-test-harness-usage.md`; runner captures via
in-page toDataURL so xvfb is fine) → green → flip `known_red` off.

Then, before the pipeline:
- Full probe suite run — everything green except the untouched known-reds
  (`settarget_failure_flag`, `clone_clip_actions`, `droptarget_scripted`).
- A quick browser game sanity check (e.g. `tools/browser-test/probe.py
  glaiel/Pong` renders and runs) — these files feed shipped games.
- Native spot checks: a few single tests over the touched opcodes
  (`--test=...` only — **never full suites locally**).

Pipeline per `.claude/pipeline-handoff.md`: commit (standard trailer), push,
full graphics-mode CI, watch, merge results, report regressions by name.
Expectation: **zero native deltas** — any CI movement means a widened gate
leaked into native paths; fix or narrow before finishing.

## Bookkeeping on completion

- Gate inventory: flip each fixed site's triage cell and tail entry to
  `fixed (<commit>, probe green)`.
- `wasm_probes/README.md` + `wasm-probe-suite.md`: group D statuses.
- If a fix reveals the browser sprite/display model lacks something
  structural (likely on bug 6), record it as evidence in the inventory
  tail rather than improvising architecture in this session.
