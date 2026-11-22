# w1-attach-order: attach-tick frame-1 order, action_order family, MovieClip-v8 (s24 wave 1)

Cloud worker, branch `fanout/w1-attach-order`, base `origin/master` `df126b80` (code = s24 baseline lineage, includes
`161ecf124`). Categories downloaded: `avm1 from_gnash` (upstream Ruffle master **`bcac30c19`**, same as the s24 baseline
CI run). Box: `SETUP_STATUS` all OK (apt, Pillow, Dawn). All runs below are `--mode=graphics` unless marked.

**New files (all under `session24-fanout-reports/`):**
- `w1-attach-order-report.md` (this file)
- `w1-attach-order-prototype.patch` — `git diff origin/master -- SWFModernRuntime SWFRecomp`; applies cleanly
  (`git apply --check`). Every hunk is gated by an env var for A/B (`SWFR_NO_ATTACH_TAGORDER`, `SWFR_NO_MCV8`,
  `SWFR_NO_PIXB`, `SWFR_NO_ARRNAT`); **wave 2 must drop the `getenv` gates**.
- `w1-attach-order-probe/attach_tagorder{,_nonroot}/` — the PlaceObject-BEFORE-DoAction fixture (test.swf, test.toml,
  output.txt = Ruffle exporter oracle, see §1.3).
- `w1-attach-order-probe/array_native_own_method/` — generator for the §3 line-560 probe.
- `*.swf` is gitignored, so the SWFs are NOT committed; regenerate with
  `python3 w1-attach-order-probe/attach_tagorder/make_probe_swf.py <dir>/attach_tagorder/test.swf` (md5 `82368d06`),
  `… make_probe_swf.py <dir>/attach_tagorder_nonroot/test.swf nonroot`, and
  `python3 w1-attach-order-probe/array_native_own_method/make_probe_swf.py <out.swf>`.

## Verdicts

| # | Item | Verdict | Priced flips | Cost |
|---|---|---|---|---|
| 1 | Attach-tick frame-1 TAG order (CI modes) | **GO-XS as a correctness fix, +0 corpus** (prototype measured) | **0 corpus rows** (62 attachMovie-bearing rows byte-identical A/B); +2 new `regression/` fixtures with an existing Ruffle oracle | ~20 lines, `tag.c` + `tag_stubs.c` |
| 1b | Same, browser-WASM live queue | HOLD (no corpus row, needs browser harness) | 0 | S–M, see §1.5 |
| 2 | action_order family (6 rows) | **NO-GO confirmed, diff shapes unchanged** | 0 | — |
| 3 | `from_gnash/actionscript.all/MovieClip-v8` | **GO-S, +1 `ruffle_matched` (prototype measured)** | **`MovieClip-v8`: output_mismatch → RUFFLE_MATCHED, graphics AND no-graphics** | ~95 lines, all `action.c`, 5 independent mechanisms |

**Total priced: +1 effective (`MovieClip-v8`), proven by prototype; 0 collateral moves on a 43-row argued sweep.**
Item 1 is +0 corpus but a tractable fidelity fix with two oracle-backed fixtures; fund it only bundled (it rides
naturally in any slot touching the attach pump).

Rule-3 check: `MovieClip-v8` is `known_failure = true`, currently `output_mismatch`, so `→ ruffle_matched` is a GAIN, not
the forbidden `pass → ruffle_matched`. Every fixed line moves to Flash's text (`output.fp23.txt`), never to Ruffle's
where they differ (§3.2). The prototype brings our check count to 1041 passed / 36 failed (Flash 1061/16, Ruffle 999/78).

---

## 1. Attach-tick frame-1 order

### 1.1 Mechanism (owner)

CI modes (`NO_GRAPHICS || OFFSCREEN_RENDER`):
- `ng_attachMovie` (`SWFModernRuntime/src/libswf/tag_stubs.c:410`) runs the clip's frame 0 placement-only
  (`catch_up_mode = 1` + goto-catchup): children are placed with `sprite_needs_init` set, no scripts run.
- `aq_dispatch_pending_attach_init` (`tag_stubs.c:218`) later re-runs `pai->func` in script-only mode
  (`tag_stubs.c:291`): the clip's own DoAction runs; every `tagPlaceObject2` is a no-op
  (`libswf/tag.c:10374`, `if (g_script_only_mode) return;`).
- Only AFTER the whole frame does `process_sprite_needs_init_public(app_context, mc)` (`tag_stubs.c:313`) run the
  children's frame 1. So the clip's DoAction always precedes its children, whatever the tag order.

Ruffle runs the attached clip's frame-1 tags in order; a child's frame 1 is queued when its PlaceObject instantiates it,
so `PlaceObject; DoAction` prints child first (oracle-checked in s24, `browser-attached-timeline-report.md` §1).

### 1.2 Prototype (measured)

In `tagPlaceObject2`'s script-only early return: when inside the attach-init replay
(`g_attach_init_active` and a new `g_attach_tagorder_parent` set by `aq_dispatch_pending_attach_init` around
`pai->func`), and the entry at `depth` is a sprite with `sprite_needs_init`, run
`process_sprite_init_at_depth(app_context, g_attach_tagorder_parent, depth)` right there (with `g_script_only_mode`
dropped to 0 around the call, restored to 1 after). The later `process_sprite_needs_init_public` pass then skips the
child (its `sprite_needs_init` is cleared). ~20 lines; the AttachInit/DeferredSpriteInit brackets are already active
around `pai->func`, so the child init sees the same gate state as the old post-frame pass.

It is not "instantiate the child at its PlaceObject inside the replay" as the board feared: placement already happened
in phase 1; only the child's *init* needed moving, and the replay already walks the PlaceObject tags. **Not invasive.**

Not covered by the prototype: `tagPlaceObject2Ratio` / `tagPlaceObject3` in the replay (they have no script-only
early return of their own; check whether an attached clip's frame-1 PlaceObject3 child would double-init before
wave 2 ships it — no corpus row exercises it).

### 1.3 Fixture and oracle — NO new oracle needed

The s23 probe `session23-fanout-reports/w2-attached-timeline-probe/make_probe_swf.py` **is already the
DoAction-AFTER-PlaceObject variant** (`stopper`/`multi` frame 1 = `place(...) + doaction(...)`; md5 `82368d06…`),
and its Ruffle exporter trace `output.ruffle-exporter-45366370e.txt` (34 lines, 8 frames) is the oracle. I packaged
it as `w1-attach-order-probe/attach_tagorder/` (root) and `_nonroot/` (generator's `nonroot` arg, same expected
file: the s24 report states root and non-root are byte-identical in Ruffle — wave 2 should get that confirmed for the
nonroot SWF specifically, see LOCAL ORACLE REQUESTS).

| fixture | before (graphics) | after (graphics) | after (no-graphics) |
|---|---|---|---|
| `attach_tagorder` | MISMATCH (lines 2-5: `s stopper f1`/`kid2 anim f1`, `m multi f1`/`kid3 anim f1` swapped) | **PASS** | **PASS** |
| `attach_tagorder_nonroot` | MISMATCH (same 4 lines) | **PASS** | **PASS** |
| `regression/avm1_attached_clip_natural_timeline{,_nonroot}`, `_goto_play{,_nonroot}`, `avm1_attach_clipevent_enterframe` | pass | pass (graphics, in sweep) | pass |

Wave 2: land them as `regression/avm1_attached_clip_tagorder{,_nonroot}` (copy the s23 generator into the fixture dir)
and update the "DoAction BEFORE PlaceObject" caveat in `avm1_attached_clip_natural_timeline/create_test_swf.py`.

### 1.4 Which corpus rows depend on it: none (measured)

A/B on the same binary (env gate), 62 rows: every avm1 / from_gnash / regression `test.swf` whose decompressed body
contains `attachMovie` (49) plus regression `avm1_child_timeline_*`, `avm1_parent_child_*`, `avm1_attach*`,
`onunload_type1_*`. **62/62 byte-identical** diff output (47 PASS, 7 RUFFLE_MATCHED, 3 MISMATCH unchanged:
`globals_monkeypatch`, `movieclip_hittest_shapeflag`, `MovieClip-v8`; 5 image-only rows unchanged). None of the six
action_order rows contains `attachMovie` at all (§2), so the fix cannot touch them either.

### 1.5 Browser-WASM (HOLD)

The browser runs frame 0 live (`tag_stubs.c` `#if !defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` arm,
~`:575-600`): the DoAction gate QUEUES the clip's script, and the children's frame 0 is built afterwards by
`advance_sprite_frames`, so the child's DoAction is queued behind the parent's regardless of tag order. A fix there
needs the child's frame-0 build at its PlaceObject inside the live `funcs[0]` run. No corpus row grades the browser;
needs the local emsdk + browser harness. Completion mechanism: same idea as §1.2 applied in the live arm; verify with
the browser probe harness from `browser-attached-timeline-report.md`.

## 2. action_order family — NO-GO confirmed, shapes unchanged

Ran all six locally (graphics). CI result triples (matching/actual/expected) and the md5 of each row's
`actual_output` excerpt in `results_graphics.json` are **identical across every results commit from `cf1aaac5`
(2026-09-11, before `3cdde8be0`) through `60038ddd` (2026-11-22)**, and none of the six SWFs contains `attachMovie`
(decompressed-body grep), so the attach pump changes cannot reach them.

| row | m/a/e | one-line NO-GO (mechanism) |
|---|---|---|
| `ActionOrderTest3` | 4/83/62 | nested registerClass sprite's loop re-creation (ctor / static unload / dynamic load) drifts every iteration (s22 §8) — unchanged |
| `ActionOrderTest4` | 10/94/64 | same family as Test3 — unchanged |
| `ActionOrderTest5` | 6/58/51 | same family as Test3 — unchanged |
| `PlaceAndRemove` | 15/45/96 | Ruffle panics (no `.ruffle.txt`); goto-placed child must never be constructed + frame-count identity "Done" (96 vs 15) — unchanged |
| `action_execution_order_extend_test` | 7/28/32 | 28 actual vs 32 expected lines: the onEnterFrame/onUnload/root-script interleave of the extend probes (KF; no attach) — unchanged |
| `action_execution_order_test11` | 26/32/32 | `doActionOrder` `0+2+1+…` and `asOrder` interleave — unchanged |

(The local `ActionOrderTest3` run printed the same 62-vs-83 shape.) Completion mechanism as recorded in
`session22-fanout-reports/w1-trace-tail-report.md` §8 / `wave1-timeline-order.md`; nothing new.

## 3. `MovieClip-v8` — GO-S, +1 ruffle_matched (prototyped)

### 3.1 How the row grades

- `test.toml` has 8 `[subtests]`; `verify_output.py` grades the highest version, **`output.fp23.txt`** (no
  `output.txt` exists). Ruffle's file: `output.fp23.ruffle.txt`. Both 1087 lines.
- `ruffle_matched` = our differing line **indices** are a subset of Ruffle's (`ruffle_subset_match`,
  `verify_output.py:3908`). Content on Ruffle-shared indices does not matter.
- Baseline: 42 differing lines = 40 check lines + the 2 `#passed/#failed` summary lines (both Ruffle-shared). The
  brief's "43 failing checks" = our `#failed: 43` (Flash fails 16 itself: 27 ours-only FAILED + 13 lines where Flash
  also FAILS but with a different obtained text).

### 3.2 The 40 lines bucketed

**Ruffle-shared (21 lines + 2 summary) — no work needed for `ruffle_matched`** (would need Flash-exact work for a pass;
not priced): negative `_yscale` via `transform.matrix` (678/679/682/683, `:1520-1529`), `mcm` counters ×12
(946-957, `:2257-2305`), `blendMode` invalid read-backs 981/983/984/985 (`:2376-2384`; Flash prints `multiply` / empty
string, Ruffle `normal`/`hardlight`), `mc.toString()=="false"` (1071, `:2596`), `_root.var1` ×2 (1077/1082, `:2209`).

**Ours-only (17 lines) — all 17 fixed by the prototype, 5 mechanisms:**

| lines | mechanism | owner (origin/master) | fix | cost |
|---|---|---|---|---|
| 486, 487 (`:970/:982` getBounds xMax 101), 745, 746 (`:1668/:1669` `_width/_height` 20/30) | Drawing-API stroke bounds: Flash pads by **half** thickness in SWF ≥ 8, **full** in SWF ≤ 7 (gnash comment "SWF8 results are more correct (half-thickness added on each side)"; v6/v7 expect 102/30/40). Ruffle always uses half (`core/src/drawing.rs` `stretch_bounds`, `radius = stroke_width / 2`) and so FAILS v6/v7 — we pass those, keep it. | `action.c:76317` (lineTo), `:76342` (curveTo), `:64808/:64826` (CallFunction twins) | `if (g_swf_version >= 8) h *= 0.5f;` | XS |
| 989 (`:2392`, FAILED in Flash too: must print `obtained: darken`) | `blendMode = 0xffffffff`: `(int)4294967295.0` is UB (x86 → INT_MIN → `&0xFF` = 0 → `normal`). Flash/Ruffle wrap f64→u8 (`f64_to_wrapping_u8` → 255, invalid → no-op, stays `darken`) | `action.c:55096` | `fmod(trunc(d),256)` wrap | XS |
| 811 (`:1829` props enumeration) | Transform instance props inserted in the wrong order (enumerates `…concatenatedMatrix,colorTransform…`) and the internal `__mc__` slot is ENUMERABLE (leaks into `for-in`) | `action.c:9733-9738` `createTransformObject` | insert `matrix, concatenatedMatrix, colorTransform, …`; `__mc__` with `PROPERTY_FLAGS_DONTENUM` | XS |
| 847, 848 (`:1903/:1904`) | `flash.geom.Transform = 1` ⇒ `_root.transform` is `undefined` (Ruffle builds it via `instantiate_class_as_script`) | `action.c:59571` GetMember `transform` arm | `if (!flashGeomClassAvailable("Transform", 9)) push undefined` (helper already exists, `:9754`) | XS |
| 826-846 ×8 (`:1857-1898` `pixelBounds`, FAILED in Flash too: obtained must be `(x=28, y=25, w=804, h=847)` etc. — Ruffle's obtained text equals Flash's) | `transformPixelBoundsGetter` (`action.c:10520`) unions only the timeline DL (`ng_localBoundsOfDL`, `:10535`): misses drawing-API content and dynamic children. Ruffle: `pixelBounds` == `clip.getBounds()` in world space (`core/src/avm1/globals/transform.rs` `GET_PIXEL_BOUNDS`). A second gap: our `getBounds` engine folds only a dynamic child's OWN drawing (`action.c:75607`), missing grandchildren — here `container.draw3` (stroked, local y=5). | `action.c:10520-10570` | prototype: call `mc.getBounds()` via `actionCallMethod` and union each live dynamic child's `getBounds(mc)` (recursive), then the existing concat-matrix AABB | S (prototype is a local fix; see lead L2 for the engine-level one) |
| 560 (`:1194` `ch.toString()` after `_global.Array` rebound) | NOT filters-specific. Reproduced with a plain literal: `_global.Array = function(){}; ch=[1,2]; ch.toString = backup.prototype.toString; ch.toString()` → `undefined` (Ruffle/Flash: `1,2`). The array CallMethod own-override arm invokes the native via `invokeFunctionValue` without publishing `g_current_executing_func`; `builtin_array_method` names itself from that global, sees NULL, returns undefined. (Without the rebound the native fast path `callArrayMethod` hides the bug.) | `action.c:71563` (array own-method arm of `actionCallMethod`) | set `g_current_executing_func = func` around the invoke for natives (the `toLowerCase` dispatcher at `:16700` already does exactly this) | XS |

### 3.3 Measurements

- Headline: `MovieClip-v8` graphics **RUFFLE_MATCHED** (`#passed: 1041 / #failed: 36`), no-graphics **RUFFLE_MATCHED**.
  Without the 560 fix it stays MISMATCH with exactly 1 ours-only index; each other bucket was measured
  incrementally (stroke+blend+transform: 17 → 9 ours-only; pixelBounds: 9 → 1; array native: 1 → 0).
- `array_native_own_method` probe: `lit call: undefined → 1,2`, `filters call: undefined → [object Object]`.
- **Collateral sweep, 43 rows, A/B all gates off vs on, graphics:** every avm1/from_gnash/regression SWF (by
  decompressed-body grep) with `blendMode`, `pixelBounds`, SWF≥8 + `transform`, SWF≥8 + `lineStyle`; core
  `avm1/array_*` rows (14) + `regression/array_method_type1_args`; `MovieClip-v5/6/7`. **42/43 byte-identical**
  (incl. `avm1/transform`, `avm1/movieclip_blend_mode_property`, `stylesheet_transform`, `MovieClip-v5/6/7` all still
  rm); the one move is the headline. Only one corpus SWF≥8 row draws strokes and reads bounds (the headline), so the
  half-thickness change has no other corpus exposure here (from_shumway / misc categories not downloaded — CI covers).

### 3.4 Wave-2 scope

All in `action.c`, self-contained hunks (no sibling file overlap noted in this slot): the 4 stroke sites, the blendMode
wrap, `createTransformObject` order/flags, the GetMember `transform` guard, `transformPixelBoundsGetter`, the array
own-method arm. Drop the `getenv` gates. Graphics + no-graphics on `MovieClip-v8` and `MovieClip-v5/6/7`; graphics
canary (the stroke change alters drawing bounds, which feed `_width`/`hitTest`, not rendering — confirm md5
identity). `categories=all` CI is enough (AVM1 only).

## Refutations

- **"Fix needs the child instantiated at its PlaceObject inside the attach replay (not cheap)"** (§24.4) — refuted on
  cost: placement already runs in phase 1; only the child's *init* must move, into the existing script-only replay's
  PlaceObject no-op. ~20 lines, measured. Refuted on value too: **no corpus row depends on it** (62-row A/B).
- **"Request an oracle for a DoAction-AFTER-PlaceObject variant"** — unnecessary: the s23 probe SWF is that variant
  and already has a Ruffle exporter trace.
- **"MovieClip-v8 has 43 failing checks to price"** — the lever is `ruffle_matched`, which needs only the 17 ours-only
  indices, not the 40 differing lines; and "MovieClip-v8 unchanged NO-GO (7 mechanisms)" — after s23 filters it is 5
  mechanisms, all XS/S, and the 1194 "Array-ctor override" check is really a native-method-as-own-property dispatch
  bug, unrelated to filters.
- **"`pixelBounds` y/h is a rounding problem"** (implied by s22 §9's "obtained text must match") — it is missing
  content (drawing + grandchildren), not rounding; with full content our values are byte-equal to Flash's.

## New unclaimed leads

- **L1** — same missing-`g_current_executing_func` pattern may exist on the other own-method native-invoke arms
  (`action.c:66673`, `:70827`, `:71278`, `:77428` call `invokeFunctionValue` too). Probe with the §3 probe shape on an
  Object / String / MovieClip receiver (`o.toString = Array.prototype.join`, etc.). No corpus row measured.
- **L2** — `getBounds` engine (`action.c:75607`) folds only a dynamic child's own drawing, not its descendants:
  `_root.getBounds()` with a stroked `container.draw3` is wrong by the grandchild's extent. The prototype patches
  `pixelBounds` locally; the engine-level fix would also move `getBounds`/`getRect`/`_width` reads — sweep first.
- **L3** — the attach-order fix for `tagPlaceObject2Ratio` / `tagPlaceObject3` children in the replay, and the
  browser live arm (§1.5).

## LOCAL ORACLE REQUESTS

1. Ruffle exporter trace, `--frames 8`, for
   `SWFRecompDocs/plans/session24-fanout-reports/w1-attach-order-probe/attach_tagorder_nonroot/test.swf`, to confirm
   it equals `attach_tagorder/output.txt` (the s23 oracle was recorded for the root variant only; the s24 report says
   the two are byte-identical in Ruffle for the DoAction-first fixtures, not this SWF). If it differs, its output
   becomes that fixture's `output.txt`.
2. (Optional) Ruffle exporter trace of `w1-attach-order-probe/array_native_own_method/test.swf`, `--frames 1`, to pin
   expected text for a regression fixture (expected: `lit call: 1,2`, `filters call: [object Object]`, lengths 2/1).
