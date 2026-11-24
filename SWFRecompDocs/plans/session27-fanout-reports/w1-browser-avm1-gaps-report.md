# s27 w1-browser-avm1-gaps: browser-WASM AVM1 no-op arms

**Slot:** `w1-browser-avm1-gaps` (wave 1, diagnosis plus a measured prototype). **Branch:** `fanout/w1-browser-avm1-gaps`.
**Base:** `origin/master` `ae7f50cb`. Corpus: `download_tests.sh avm1` (784 tests installed).

**New files (all under `session27-fanout-reports/`):**
- `w1-browser-avm1-gaps-report.md`: this report.
- `w1-browser-avm1-gaps-prototype.patch`: `git diff origin/master -- SWFModernRuntime tools ruffle-tests/verify_output.py`.
- `w1-browser-avm1-gaps-fixtures/`: 3 regression fixtures plus a shared `avm1asm.py`:
  - `avm1_browser_gated_textfield/`
  - `avm1_browser_gated_depth/`
  - `avm1_browser_gated_color/`

  Each holds `create_test_swf.py`, `test.toml` and `output.txt`. `test.swf` is gitignored here, as in the s26 fixture dirs. Regenerate it with `python3 <dir>/create_test_swf.py <dir>/test.swf`; the generators are deterministic. The `output.txt` files are provisional; see LOCAL ORACLE REQUESTS.

  Untracked leftovers from local runs (`RecompiledScripts/`, `RecompiledTags/`, `_results/`, `__pycache__/`) are not committed. My `rm` of them was refused in this session.

## Verdicts

| Item | Verdict | Evidence |
|---|---|---|
| `gate_inventory.py` cannot see no-op arms | **GO, done** (in the patch) | New categories `browser-stub` and `browser-thin`. Selftest OK. `--verify-cpp`: 1067 pairs, 0 mismatches. On master it flags **15 stub + 9 thin** sites. |
| A native way to run browser `#else` arms | **GO, new tool** (in the patch) | `SWF_BROWSER_ARMS_TU=action.c` in `verify_output.py`. It compiles `action.c` the way the browser does, inside the CI graphics binary. It reproduces every symptom in the brief natively (17 of 20 probe rows fail before the patch). |
| `createTextField`: CallFunction and CallMethod forms | **GO** (prototype) | Fixes 5 harness rows (see the table below). |
| `getInstanceAtDepth`: CallFunction and CallMethod forms | **GO** (prototype) | Fixes `movieclip_get_instance_at_depth` and the fixture rows. |
| `getRGB` returns undefined (S) | **GO** (prototype) | Fixture row `getRGB=3368601`. It fully flips `color` together with `Color.setTransform`. |
| `getBounds` returns 6710886 (M) | **GO, priced S, not M** | Two parts, both one-gate edits:<br>1. The whole 236-line real body sat in one `#if NG‖OR` block that fell through to the sentinel.<br>2. The browser-only arm of `actionGetVariableImpl` never set `child_mc->display_obj`, so getBounds/transform could not find the clip's sprite display list.<br>Fixes `movieclip_getbounds`, `movieclip_invalid_get_bounds_1/_5`, `transform` and the fixture row. |
| Other cheap no-op arms the inventory found | **GO** on 11 more | These are no-ops today in the browser:<br>- bare `createEmptyMovieClip`<br>- `mc.duplicateMovieClip`<br>- `setNewTextFormat`<br>- `removeTextField`<br>- `Color.setTransform`<br>- `swapDepths` (2 display-list updates)<br>- `_width`/`_height` setters<br>- `transform.concatenatedMatrix`, `.concatenatedColorTransform` and `.pixelBounds` |
| `actionGetVariableImpl` browser-only name lookup (`action.c` master `:50837`) | **GO** (prototype, flagged) | A bisect found it. The browser arm uses a case-sensitive `findDisplayObjectByName`, has no pending-removal / shape-alias / SWF5-button rules, and **never sets `display_obj`**. The CI arm is a superset, reads the same shared `display_list`, and its callees (`ng_findDisplayEntryByName`, `ng_isScriptableAtDepth`) are unconditional in `tag_stubs.c`. Collapsing to the CI arm flips `movieclip_getbounds` and `transform`. Because GetVariable is the hottest path, REQUEST 2 must confirm this before landing. |
| Residual row `duplicate_movie_clip` | **HOLD**, needs a browser oracle | A bisect found it: `actionCloneSprite`'s browser-only `actionDrainActionQueueByKind(AQ_KIND_LOAD)` (`action.c:65579` on master). It pairs with browser `tag.c`'s `queue_clip_load_events`, which uses `AQ_KIND_LOAD` and which the harness does not compile. So this is most likely a harness artifact. Completion mechanism: LOCAL ORACLE REQUEST 2. |

**Priced flips.** CI cannot see any of these rows: they are browser-only, so **trace and pixel yield in CI is 0 by construction**. I checked this by preprocessing `action.c` before and after the patch under all three CI define sets:
- graphics: `USE_WEBGPU OFFSCREEN_RENDER NDEBUG`;
- graphics plus images: the same set plus `HEADLESS_RENDER_ENABLED`;
- no-graphics: `NO_GRAPHICS`.

The output is md5-identical in all three (`0741e678…` graphics, `9af8db12…` no-graphics). Only the browser define set `-DUSE_WEBGPU` changes (`59d39cf3` → `7a359c5f`). The patch therefore cannot move a CI row, and the native legs need no canary.

Yield in the in-browser player, measured with the native harness: **16 of the 17 rows that failed before now pass**, all 3 new fixtures pass, and a 13-row no-regression sweep adds 1 more flip (`focus_remove`) with 0 regressions. The real browser build has not been run (no emsdk in the cloud); see LOCAL ORACLE REQUEST 2.

## 1. `gate_inventory.py`: no-op arm detection

Design (all in `tools/gate_inventory.py`):

- `Code` now keeps each line's text. `text_seen()` returns the lines a config *definitely* compiles (undecidable arms are skipped).
- `substantive()` drops lines that never do real work, matched by `TRIVIAL_LINE_RES`:
  - braces;
  - `break;` and bare or constant `return`;
  - `(void)x;`;
  - `FREE(args)` / `free(p)`;
  - `pushUndefined(app_context);`, `PUSH_UNDEFINED`, `PUSH(ACTION_STACK_VALUE_UNDEFINED, 0)`;
  - `builtin_handled = 1;`;
  - `x = 0/NULL/false;`.
- Each config's row gains a `substantive` count (it is also in `--json`).
- **`browser-stub`**: the browser has code but 0 substantive lines, **and** it takes a different top-level arm than a native config that has 3 or more substantive lines.
- **`browser-thin`**: the browser arm has 1–3 substantive lines while a native arm on a different arm has 8 or more. These are triage candidates, which is how the twip-truncating `_width`/`_height` setters surfaced.
- Both categories sit in `CATEGORY_ORDER` after `browser-none-partial`. Both are flagged in the text report, and in the markdown "Flagged" section once regenerated.
- A new selftest fixture site (`createMovieClip…` / `#else FREE+pushUndefined`) classifies as `browser-stub`.

I did not regenerate `SWFRecompDocs/reference/browser-wasm-gate-inventory.md`. It dates from `595667b57` (July), and regenerating it is a 600-line doc churn. To regenerate:

```bash
python3 tools/gate_inventory.py --markdown SWFRecompDocs/reference/browser-wasm-gate-inventory.md
```

### The full inventory on `origin/master` (before the patch)

`python3 tools/gate_inventory.py` on master: 455 sites in total.

| Category | Sites |
|---|---:|
| `browser-none` | 114 |
| `browser-none-partial` | 44 |
| `browser-stub` | **15** |
| `browser-thin` | **9** |
| `browser-only` | 104 |
| `native-asym` | 48 |
| `depends` | 28 |
| `browser-unreachable` | 11 |
| `all-configs` | 82 |

Every stub and thin arm, triaged (line numbers are master's):

| # | Site | Function / builtin | Cat | Browser arm | Triage | In patch |
|---|---|---|---|---|---|---|
| 1 | `action.c:10572` | `transformConcatMatrixGetter` | stub | `(void)app_context` → undefined | bug | yes |
| 2 | `action.c:10595` | `transformConcatCTGetter` | stub | same | bug | yes |
| 3 | `action.c:10620` | `transformPixelBoundsGetter` | stub | same | bug | yes |
| 4 | `action.c:12277` | `colorGetRGB` | thin | `return undef` | bug (brief's S item) | yes |
| 5 | `action.c:34920` | `mcSetEffectiveWidth` | thin | `mc->width = v` | bug: no xscale change, no TextField twip rule | yes |
| 6 | `action.c:34975` | `mcSetEffectiveHeight` | thin | `mc->height = v` | bug, same | yes |
| 7 | `action.c:39354` | `ng_drawing_art_contains_local` | thin | `return 0` | bug, but its caller `ng_update_drag_droptarget` is itself `browser-none`, so it is out of reach alone | no (lead) |
| 8 | `action.c:68758` | CallFunction `createTextField` | stub | `FREE; pushUndefined` | bug (brief) | yes |
| 9 | `action.c:69029` | CallFunction `createEmptyMovieClip` | stub | same | bug | yes |
| 10 | `action.c:69341` | CallFunction `getInstanceAtDepth` | stub | same | bug (brief) | yes |
| 11 | `action.c:76751` | CallMethod `createTextField` | stub | same | bug (brief) | yes |
| 12 | `action.c:77354` | CallMethod `duplicateMovieClip` | stub | same | bug, the most game-visible after createTextField | yes |
| 13 | `action.c:77794` | CallMethod `setNewTextFormat` | stub | same | bug | yes |
| 14 | `action.c:78732` | CallMethod `getInstanceAtDepth` | stub | same | bug (brief) | yes |
| 15 | `tag.c:6710` | `ng_upgrade_attached_standalone_initialized` | stub | `(void)include_attached` | paired with the browser frame loop, not cheap | no |
| 16 | `tag.c:11659` | `tagPlaceObject2` cxform re-init | stub | `(void)app_context` | paired with browser-only arm `tag.c:11381` | no |
| 17 | `tag.c:12229` | `tagPlaceObject2` → `ng_on_place_object2` plus INIT/CONSTRUCT queue | stub | same | paired with browser-only arm `tag.c:12185`; see "New leads" | no |
| 18 | `tag.c:12809` | `tagSetClipActions` → same | stub | same | paired with `tag.c:12779` | no |
| 19 | `render_webgpu.c:2813` | `render_webgpu_poll` | stub | `return 0` (events come by callback) | **false positive**: the "native" arm is SDL windowed | no |
| 20 | `avm2_error.c:48` | `avm2_stack_guard_init` | thin | emscripten stack API | false positive | no |
| 21 | `swf.c:932` | `tagMain` attached-clip pump | thin | `ng_advance_attached_clip_playheads` | intentional (s24) | no |
| 22 | `tag.c:527` | `CALL_FRAME` | thin | `exec_sprite_frame` | intentional | no |
| 23 | `tag.c:13861` | `tagRemoveObject` | thin | `pending_remove = 1` | intentional (documented re-run protection) | no |
| 24 | `tag.c:14048` | `tagRemoveObject2` | thin | same | intentional | no |

The bisect (below) found four more no-op sites that live in `browser-none` rather than as stubs, because they have no `#else` and fall through to shared code:

| Site (master) | Function / builtin | Effect in the browser |
|---|---|---|
| `action.c:78874–79256` | CallMethod **`getBounds`** body | 236 lines, falls through to the 6710886.35 sentinel |
| `action.c:76723` | CallMethod `removeTextField` | does nothing |
| `action.c:12194` | `colorSetTransform` | does nothing |
| `action.c:78609`, `:78712` | `swapDepths` display-list update | `ng_swapDisplayDepths` / `ng_updateDisplayDepth` never run |

`tools/gate_inventory.py` already flags all of these as `browser-none` (114 sites). The stub categories are what was missing.

Every other line number in this report refers to the patched file unless it says "master".

## 2. The browser-arm harness (`SWF_BROWSER_ARMS_TU`)

**Premise attacked:** the brief says verification needs either a host-graphics native build or the coordinator's emsdk. Neither is true for `action.c`:

- There is no host-graphics native build. `build_graphics_host.sh` is emcc-only, and `USE_WEBGPU` without `OFFSCREEN_RENDER` on Linux pulls in SDL3.
- `action.c` never touches `WebGPURenderContext`. That struct is the only shared type whose layout depends on `OFFSCREEN_RENDER` (`render_webgpu.h:242/246`), and `action.c` neither includes it nor accesses it.

So `action.c` compiled with the browser's defines links into the CI graphics binary with no ABI split. `verify_output.py` (in the patch):

- `SWF_BROWSER_ARMS_TU=action.c[,…]` drops `-DOFFSCREEN_RENDER` and `-DHEADLESS_RENDER_ENABLED` for the named TUs in `--mode=graphics` only.
- A weak shim TU (`zz_browser_arm_shim.c`) supplies 7 symbols. `action.c` defines them only under `NG‖OR`, the CI TUs still reference them, and in the real browser `graphics_stubs.c` supplies them:
  - `g_settarget_none`, `g_settarget_invalid`, `g_settarget_explicit_root`;
  - `g_clone_depth_already_unbiased`;
  - `actionRewindCleanup`, `actionRenameMovieClip`, `actionGetFocusRectInfo`.

  The shim is written only when the env var is set.

**Fidelity limit (stated, measured):** only `action.c`'s arms are browser arms. `tag.c`, `swf.c`, `tag_stubs.c` and `graphics_stubs.c` stay CI-graphics. So a row that depends on `tag.c`'s or `swf.c`'s browser frame-loop arms can mis-grade. `action.c`'s 21 browser-only (`!NG && !OR`) arms are exactly the ones that pair with those frame-loop arms; see section 4.

**Link closure for the real browser build.** I compiled the browser TU set (the `build_graphics_host.sh` list) with gcc under `-DUSE_WEBGPU -D__EMSCRIPTEN__`, using stub emscripten headers. `render_webgpu.c` is the one TU that does not build that way. Then I diffed `action.o`'s undefined symbols before and after the patch:

- The patch adds exactly 6 new external references: `ng_duplicateMovieClip`, `ng_findRootChildAtSWFDepth`, `ng_getColorTransform`, `ng_setColorTransform`, `ng_swapDisplayDepths`, `ng_updateDisplayDepth`.
- All 6 are defined **unconditionally** in `tag_stubs.c` (lines 2961, 1652, 1860, 1879, 2278, 2164), which the browser build compiles.
- No symbol is missing from the browser link that was not already missing before.
- For the record, ungating *every* `NG‖OR` gate in `action.c` would need just 2 browser-undefined symbols: `g_defer_sprite_init` and `ng_compute_droptarget`.

## 3. Prototype: what it does and the measured result

The patch deletes 18 `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)` gates in `action.c`. It keeps their native arm and removes any `#else`. It also collapses one `#if !NG && !OR … #else` site (`actionGetVariableImpl`) onto its CI arm. No logic changes. It does this mechanically with a gate-tree editor (`ungate.py`, scratch), not by hand. The functions touched in `action.c`:

- `transformConcatMatrixGetter`, `transformConcatCTGetter`, `transformPixelBoundsGetter`;
- `colorSetTransform`, `colorGetRGB`;
- `mcSetEffectiveWidth`, `mcSetEffectiveHeight`;
- `actionCallFunction`: the `createTextField`, `createEmptyMovieClip` and `getInstanceAtDepth` arms;
- `actionCallMethod`: the `removeTextField`, `createTextField`, `duplicateMovieClip`, `setNewTextFormat`, `swapDepths` (×2), `getInstanceAtDepth` and `getBounds` arms;
- `actionGetVariableImpl`: the display-object-by-name arm.

None of this is in `tag.c`, `ng_shared.c` or `swf.c`.

Harness legs. All rows are `--mode=graphics` with `SWF_BROWSER_ARMS_TU=action.c`. **A** = master `action.c` (what the browser does today); **B** = patched (the delivered patch, called B3 in the scratch logs).

| Test | A (browser today) | B (patched) |
|---|---|---|
| avm1/`movieclip_create_text_field` | mismatch, image FAIL | **pass**, image PASS |
| avm1/`movieclip_get_instance_at_depth` | mismatch | **pass** |
| avm1/`movieclip_invalid_get_bounds_1` | mismatch | **pass** |
| avm1/`movieclip_invalid_get_bounds_5` | mismatch | **pass** |
| avm1/`color` | mismatch, image FAIL | **pass**, image PASS |
| avm1/`create_empty_movie_clip` | mismatch | **pass** |
| avm1/`duplicate_movie_clip_drawing` | mismatch | **pass** |
| avm1/`textfield_properties` | mismatch | **pass** |
| avm1/`movieclip_depth_methods` | mismatch | **pass** |
| avm1/`textfield_asbroadcaster` | mismatch | **pass** |
| regression/`avm1_create_text_field_depth` | mismatch | **pass** |
| regression/`avm1_set_new_text_format_color` | mismatch | **pass** |
| regression/`avm1_pixelbounds_dynamic_child` | mismatch | **pass** |
| regression/`avm1_bare_mc_method_scope` | mismatch | **pass** |
| avm1/`movieclip_getbounds` | mismatch | **pass** (needs the GetVariable collapse) |
| avm1/`transform` | mismatch | **pass** (same) |
| avm1/`duplicate_movie_clip` | mismatch | mismatch (16 diff lines; section 4, HOLD) |
| avm1/`textfield_props_swf8`, regression/`avm1_dynclip_color_transform`, `avm1_textfield_x_bounds_offset` | pass | pass |
| fixture `avm1_browser_gated_textfield` | 7/7 lines wrong | **pass** |
| fixture `avm1_browser_gated_depth` | 6/7 wrong | **pass** |
| fixture `avm1_browser_gated_color` | 3/3 wrong | **pass** |

**No-regression sweep** (harness, A vs B): 13 unrelated, name-lookup-heavy rows. 0 regressions, and 1 more flip, `focus_remove` (0 → 1):
- `button_children`, `button_order`, `button_v6`;
- `clip_events`;
- `define_function_case_sensitive`, `get_variable_in_scope`;
- `focus_remove`, `function_base_clip_removed`, `hitarea_remove_sibling`, `focusrect_property_swf5`;
- `attach_movie`, `target_path`, `movieclip_hittest`.

The browser-only GetVariable arm was case-sensitive and dropped the pending-removal rule. `focus_remove` is consistent with that.

Native legs for the 3 fixtures pass under `--mode=graphics`, no-graphics, and the patched harness. Every other native row is unchanged, by the preprocessor proof above.

How the extra sites were found: I ungated *every* `NG‖OR` gate in `action.c` (65 left after the first pass) and ran the harness. That leg also flipped `color`, `textfield_properties` and `movieclip_depth_methods`. A greedy minimal-subset bisect at `-O0` named the gates needed:
- `color`: `Color.setTransform`.
- `textfield_properties`: `removeTextField`.
- `movieclip_depth_methods`: the 2 swapDepths sites.

These are in the patch. No other `NG‖OR` gate in `action.c` is needed for any probed row.

## 4. `action.c`'s browser-only arms (1 GO, 1 HOLD)

Even with every `NG‖OR` gate in `action.c` ungated, `movieclip_getbounds`, `transform` and `duplicate_movie_clip` still failed in the harness. They all pass once `action.c`'s 21 `!defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` arms are also deleted (measured).

A minimal-subset bisect over those 21 arms named exactly one arm per row:
- `getbounds` and `transform`: `actionGetVariableImpl:50837` (master). It is in the patch; see Verdicts.
- `duplicate_movie_clip`: `actionCloneSprite:65579` (master). HOLD.

The text below applies to the HOLD row and to the other 19 arms.

Those arms are the browser's frame-loop side of `action.c`: `actionPlay`/`actionStop`/`actionGotoFrame`/`actionGoToLabel`/`actionSetTarget` arms, `actionCloneSprite:65579`, `mcReadAlpha`, and `mc_get_pixel_aabb_ng:81432/81582` (master). Each pairs with a browser-only arm in `tag.c` or `swf.c` that the harness does not compile. So the harness **cannot** tell whether these 3 rows are real browser bugs or harness artifacts.

**Completion mechanism:** LOCAL ORACLE REQUEST 2 runs `duplicate_movie_clip` in the real browser build.
- If it fails there, `actionCloneSprite:65579` plus browser `tag.c` `queue_clip_load_events` own it (priced S–M).
- If it passes, it is a harness artifact and closes.

The same request validates the GetVariable collapse on `movieclip_getbounds` and `transform`.

## 5. Fixtures (exporter golden request)

Each fixture only uses semantics that a corpus row already locks against a Flash golden:
- `movieclip_create_text_field`, `movieclip_getbounds`;
- `movieclip_get_instance_at_depth`, `create_empty_movie_clip`, `duplicate_movie_clip`;
- `color`, `transform`.

So the native `output.txt` is credible, but it came from SWFRecomp. **The rule needs an outside oracle before promotion to `regression/`** (REQUEST 1). Rows:

- **`avm1_browser_gated_textfield`** (SWF8):
  - bare `createTextField` returns the field in SWF8;
  - x/y/w/h and depth;
  - method form;
  - TextField `_width`/`_height` stay direct twip dimensions (`xs=100`);
  - `setNewTextFormat` → `getNewTextFormat` round trip;
  - `getBounds(_root)` of a text field.
- **`avm1_browser_gated_depth`** (SWF8):
  - bare `createEmptyMovieClip`;
  - `getInstanceAtDepth` in both forms, including a miss;
  - `duplicateMovieClip` return value, depth, the copied-dprops rule and the depth slot;
  - `_width` on an empty clip collapses both scales to 0.
- **`avm1_browser_gated_color`** (SWF8):
  - `Color.setRGB`/`getRGB` on a nested dynamic clip;
  - `transform.concatenatedMatrix` (`a=2 tx=10 ty=5` through a 200%-xscale parent);
  - `concatenatedColorTransform` (`rm=0 ro=51 go=102 bo=153`).

Run them natively:

```bash
F=SWFRecompDocs/plans/session27-fanout-reports/w1-browser-avm1-gaps-fixtures
python3 ruffle-tests/verify_output.py --tests-dir=$F --test=avm1_browser_gated_depth --mode=graphics --diff --verbose
SWF_BROWSER_ARMS_TU=action.c python3 ruffle-tests/verify_output.py --tests-dir=$F --test=avm1_browser_gated_depth --mode=graphics --diff --verbose
```

## Wave-2 scope (if the coordinator lands it)

1. Apply the prototype patch. In `action.c` it is just gate deletions, and it covers the sites in section 3. Rebuild the browser bundle; no new files.
2. Move the 3 fixtures into `ruffle-tests/tests/swfs/regression/` once REQUEST 1 confirms `output.txt`. Add README rows. Replace `../avm1asm.py` with the fixture-local copy convention `avm1_create_text_field_depth` uses.
3. Commit the harness (`verify_output.py`) and the inventory tool. Optionally regenerate the gate-inventory doc.
4. **CI needs nothing.** The CI preprocessed output is byte-identical, so per-change CI is a formality: graphics `all`, no images.

Sibling overlap:
- `w1-avm1-leftovers` edits `action.c` builtins. My hunks are pure gate-line deletions (18 `#if`, 15 `#else…#endif` blocks, 3 `#endif`), so they rebase trivially.
- I touched no text layout (`w1-text-wordwrap`).

## Refutations and corrections to the brief

- "`gate_inventory.py` can't see no-op arms": true. Fixed. The s26 report's claim that it classed them `all-configs` is confirmed.
- "`getBounds` returns 6710886 (M)": the cause is not a missing browser implementation. A complete native implementation was gated off by one `#if` with a sentinel fallthrough, so the price is **S**. One corpus row (`movieclip_getbounds`) still needs the HOLD item.
- "Make the browser arm compile under a host-graphics native build if one exists": none exists. The harness plus the gcc browser-TU link closure is a stronger check for `action.c` than a syntax-only build would be.
- "`createTextField` … no-ops": they are, and the family is larger than the brief lists:
  - the bare `createEmptyMovieClip`;
  - `duplicateMovieClip` (method form);
  - `removeTextField`;
  - `Color.setTransform`;
  - `swapDepths`'s display-list half;
  - `_width`/`_height`;
  - three `transform` getters.

  All were dead in the browser.

## New unclaimed leads

- **Browser placements never run `ng_on_place_object2` and the INIT/CONSTRUCT/REGISTER_CTOR queue.** These are the stubs at `tag.c` (master) `:12229` (`tagPlaceObject2`) and `:12809` (`tagSetClipActions`). The browser has its own browser-only arms instead (`tag.c:12185`, `:12779`). It is unknown whether those reproduce the batch order of the s20+ work (every INIT, then every CONSTRUCT, then every REGISTER_CTOR). Price: M, needs a browser oracle. Probe it with an `onClipEvent(initialize)`/`construct` plus `registerClass` ordering fixture.
- **Display-list cxforms are not initialised in the browser** (`tag.c:11659` stub skips `ng_on_place_object2`'s cxform init). So `ng_getColorTransform` can read zeros for a *timeline-placed* clip with a PlaceObject cxform. In that case `getRGB` without a prior `setRGB` may differ in the browser. The fixture uses a dynamic clip only. Price: S to probe.
- **`ng_drawing_art_contains_local`** (thin, `action.c:39354`) plus its `browser-none` caller `ng_update_drag_droptarget`: `_droptarget` over Drawing-API art is dead in the browser. Price: S–M.
- **110 `browser-none` sites remain** after the patch (`actionGotoFrame`×4, `actionSetVariable`×4, `resolveSlashPathToMC`×4, `tagSetInstanceName`×5, …). The reference doc's triage column is from July. This patch's harness can now *measure* each `action.c` one. Suggested follow-up: run the harness over the avm1 suite in CI. That needs a workflow input that sets `SWF_BROWSER_ARMS_TU=action.c`, as a browser-proxy leg. It is the first CI-visible browser signal this project would have.
- **Harness extension:** `tag.c` cannot join the harness as is, because `tag.c` and `swf.c` share frame-loop state. A two-TU version (`tag.c` plus `graphics_stubs.c` in browser mode) gives 23 multiple-definition clashes against `tag.c`/`ng_shared.c` (measured); it needs a link-order or weak-symbol shim. Price: M.

## LOCAL ORACLE REQUESTS

1. **Ruffle exporter traces for the 3 fixtures** (frame-script traces, no timers):
   ```bash
   F=SWFRecompDocs/plans/session27-fanout-reports/w1-browser-avm1-gaps-fixtures
   for d in avm1_browser_gated_textfield avm1_browser_gated_depth avm1_browser_gated_color; do
     python3 $F/$d/create_test_swf.py $F/$d/test.swf
     exporter -s -f 1 --trace-log $F/$d/ruffle.txt $F/$d/test.swf /tmp/$d.png
     diff $F/$d/output.txt $F/$d/ruffle.txt
   done
   ```
   Need: the diff for each. Identical means the fixture is promotable as is. Any difference: archive `ruffle.txt` for the wave-2 worker. The `tfB w=10.05 h=3.95` and `dup … e3 marker=undefined` rows are the ones worth a careful look.
2. **Real browser-WASM run of the patched runtime** (emsdk). Apply `w1-browser-avm1-gaps-prototype.patch`, then use the existing probe harness (`tools/browser-test/child_probe/README.md`; it builds childless fixtures too):
   ```bash
   git apply SWFRecompDocs/plans/session27-fanout-reports/w1-browser-avm1-gaps-prototype.patch
   F=SWFRecompDocs/plans/session27-fanout-reports/w1-browser-avm1-gaps-fixtures
   for d in avm1_browser_gated_textfield avm1_browser_gated_depth avm1_browser_gated_color; do
     bash tools/browser-test/child_probe/build_child_probe.sh $d $F/$d
     python3 tools/browser-test/child_probe/run_child_probe.py $d
   done
   # the HOLD rows (corpus SWFs; copy each test dir to a scratch dir first if the script wants repo-relative):
   for t in movieclip_getbounds transform duplicate_movie_clip movieclip_create_text_field color; do
     bash tools/browser-test/child_probe/build_child_probe.sh $t ruffle-tests/tests/swfs/avm1/$t
     python3 tools/browser-test/child_probe/run_child_probe.py $t
   done
   ```
   Need: the trace diff against `output.txt` for each, with and without the patch (two builds).
   - The fixtures should go from failing on every line to passing. That confirms the native harness legs.
   - The 3 HOLD rows settle section 4.

   The coordinator owns the Pages deploy afterwards.
