# s24 wave 2: `w2-avm2-small-natives` (L3 + L4 + L5 of `w1-avm2-tail`), landable patch

**NEW files** (all under `session24-fanout-reports/`; there are no new source files)
- `SWFRecompDocs/plans/session24-fanout-reports/w2-avm2-small-natives-report.md` (this report)
- `SWFRecompDocs/plans/session24-fanout-reports/w2-avm2-small-natives.patch`, the landable patch. It applies on `origin/master` @ `4a939d65`; `git apply --check -R` passes against the branch tip.

**Patch scope** = `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt docs/recompiler ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_COMPAT_TWEAKS.md`.
- `verify_output.py` and `render_canary_tests.txt` are untouched.
- `docs/recompiler/guest_loader.js` and the COMPAT_TWEAKS doc are added to the standard scope, because the brief requires both changes (§2, §1).
- **Coordinator: the patch touches `docs/recompiler/`, so after it lands run `gh workflow run deploy-pages.yml --ref master`** (standing authorization in CLAUDE.md), or the browser keeps the 12/3 stubs. Both new loader hooks are optional, so an old bundle with a new host, or the reverse, still loads.

**Box.** `SETUP_STATUS` all OK (apt, Pillow, Dawn on lavapipe). Upstream tests: `download_tests.sh avm2 mixed_avm from_avmplus` (and, for the canary, `avm1 visual fonts text from_shumway`) took Ruffle master **`bcac30c19`**, the s24 baseline SHA. All four headline BEFORE rows match the s24 baseline `avm2/_results/results_graphics.json` exactly (status and line counts), so local trace runs are CI-grade here.

---

## 0. Verdict: GO. The measured ledger is exactly the brief's ledger

### EXPECTED-FLIP LEDGER (the coordinator checks CI against this)

| Axis | Test | Before (clean `origin/master`) | After (patch) | Mode |
|---|---|---|---|---|
| trace | `avm2/weird_number_bound_methods` (known_failure) | output_mismatch 9/12 | **pass** 12/12 | graphics **and** no-graphics |
| trace | `avm2/primitive_bound_methods` (known_failure) | output_mismatch 5/11 | **ruffle_matched** 10/11 | graphics **and** no-graphics |
| trace | `avm2/textline_metrics` | output_mismatch 0/20 | **pass** 20/20 | graphics **and** no-graphics |
| trace | `avm2/worker_terminate` | output_mismatch 1/56 (3 actual lines) | **pass** 56/56 | graphics **and** no-graphics |
| pixel | none | — | — | none of the four rows has `[image_comparisons]` |

- That is **+3 pass and +1 ruffle_matched = +4 effective** per mode.
- **0 other moves**: 70 rider rows are identical in status *and* line counts, and the 102-test render canary is md5-identical across all 160 PNGs.
- Both known_failure rows move from fail to effective, so this is not a `pass → ruffle_matched` regression.
- None of the four rows is in any `ignored_tests.txt`, so there is nothing to prune.

**CI shape.** Use `mode=graphics categories=full`: the patch touches AVM2 runtime and recompiler emission, and `from_avmplus` is in `full`.
- No no-graphics-only code was touched: `avm2_main.c` gets the same call in both loops, and there is no `swf_core.c`, `tag_stubs.c` or `#ifdef NO_GRAPHICS` arm.
- So per CLAUDE.md fan-out policy, the NG leg belongs only on the FINAL grading run. I ran the four headline rows in NG locally anyway; table above.

---

## 1. L3: primitive-receiver bound-method cache (`avm2_ops.c`, `avm2_gc.c`, `avm2_gc.h`)

This is the prototype as measured, plus cleanup:
- `bind_method_entry` now sends non-OBJECT receivers through a 1024-slot direct-mapped side cache. The key is (prop entry, atom kind, atom key), modelling the avmplus receiver atom:
  - Booleans are keyed by value.
  - An int-valued Number (not −0) uses the int atom, so `(0.0).f === (0).f`.
  - −0, NaN and other non-integral doubles are never cached.
  - A String is keyed by its `Avm2String*` pointer.
- The GC root is now a named, declared function, `avm2_gc_mark_roots_bound_cache()` (`avm2_gc.h`), called from `gc_collect` next to the media roots. It replaces the prototype's inline `extern`.
- **Pointer-key safety, verified.** Each cached closure stores its receiver in `fn_receiver`, and `avm2_gc.c:555` marks it. So a cached string cannot be freed and its address recycled while its slot is live. A collision evicts, and the full key is compared, so it never aliases.
- Also fixed: the `&&`/`||` precedence warning in `pbm_key`.
- **Doc.** `avm2/_investigation/` has no compat-tweaks file, so I added the entry to `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_COMPAT_TWEAKS.md`: "AVM2 bound methods on String receivers: one closure per string *pointer*". It covers the pointer-equal-string (Ruffle `ValueKey`) rationale, the unexplained Flash line 2, and the companion `weird_number_bound_methods` Flash pass.

## 2. L4: DefineFont4 typo metrics as a real table (recompiler + runtime + browser host)

The prototype's weak-symbol read under `#if !defined(DYNAMIC_HOST)` is gone. It is replaced by a real table that mirrors `avm2_generated_device_fonts` end to end.

| Piece | Change |
|---|---|
| `avm2_abc.h` | New `typedef struct Avm2Cff4FontData { const char* name; uint8_t bold, italic; int16_t typo_ascender, typo_descender; uint16_t units_per_em; }`. `avm2_generated_cff4_fonts` / `_count` sit in **both** extern blocks, next to the device fonts: pointer + `uint32_t` under `DYNAMIC_HOST`, `const` array + `const uint32_t` otherwise |
| `abc_timeline.cpp` | `TAG_DEFINE_FONT4 = 91` (renamed from `_PROTO`). The scanner case now bounds-checks each 16-byte table record (`rec + 16 > flen` → stop) before `memcmp`. The main movie (`symbol_prefix` empty, beside `emitDeviceFonts`) emits `const Avm2Cff4FontData avm2_generated_cff4_fonts[]` plus the count, and C-escapes the font name (quote, backslash, non-printables as octal). An empty table still defines both symbols |
| `avm2_text.c` | `tl_metric` reads the table directly in every build. Guard: `count == 0`, which is NULL-safe under DYNAMIC_HOST until set. **Style match added:** a face whose bold/italic matches `fontWeight == "bold"` / `fontPosture == "italic"` wins; otherwise the first face with that name. Anything else falls back to 12 / 3 as before |
| `host_main_graphics.c` | Defines the DYNAMIC_HOST pointer + count, plus a **separate** `EMSCRIPTEN_KEEPALIVE setAvm2Cff4Fonts(fonts, count)`. I kept `setAvm2Tables`' signature unchanged so mismatched host and bundle versions still link and run. `build_graphics_host.sh` exports every defined `T` symbol via `llvm-nm`, so no export list needs editing |
| `guest_main_graphics.c` | `get_avm2_cff4_fonts` / `get_avm2_cff4_font_count` exports (`export_name`), beside the device-font getters |
| `docs/recompiler/guest_loader.js` | After `_setAvm2DrawTables`: `if (host._setAvm2Cff4Fonts && g.get_avm2_cff4_fonts) host._setAvm2Cff4Fonts(...)` |

**What I checked for the browser path.** As the brief allows, I did not run a deploy build. Instead:
1. `gcc -fsyntax-only -DDYNAMIC_HOST -DSWF_AVM2 -DUSE_WEBGPU -D__EMSCRIPTEN__` (with a stub `emscripten.h`) on the patched `host_main_graphics.c` and `avm2_text.c`: **0 errors**. A negative control (a misspelt symbol in the host file) does produce an error, so the check is live.
2. `gcc -fsyntax-only -DSWF_AVM2` on the patched `guest_main_graphics.c`, against a real `--recompile` output (`avm2/textline_metrics/Recompiled{Scripts,Tags,ABC}`): **0 errors**. The same check on that row's generated `RecompiledABC/abc_timeline.c`, which now contains `{ { "TestFont", 0, 0, 800, -200, 1000 }, }`: 0 errors.
3. `node --check docs/recompiler/guest_loader.js`: OK.
4. Grep: nothing else hand-writes main-movie AVM2 tables. Only `abc_timeline.cpp`/`abc_devicefont.cpp` emit them, and only the two wasm wrappers plus `guest_loader.js` bridge them. So no other link needs the new symbols.
5. Native `--recompile` on every row I ran, in both legs. The SWFRecomp binary was rebuilt for each leg; I confirmed the AFTER canary's AVM2 rows had regenerated `abc_timeline.c` containing `avm2_generated_cff4_font_count`.

**Not covered:** child-movie (`symbol_prefix`) DefineFont4 faces. As with device fonts, the table is player-level and main-movie only, so a TextLine in a loaded child SWF that uses an embeddedCFF face keeps 12/3. No corpus row grades that (the L4 sweep includes `loader_load` and `mixed_avm/avm1_loads_avm2`; both unchanged).

## 3. L5: Worker / WorkerDomain (`avm2_globals.c`, `avm2_globals.h`, `avm2_main.c`)

- The pending-worker drain `avm2_worker_poll(ctx)` is declared in `avm2_globals.h`. I put it next to `avm2_register_external`, away from the netstream sibling's media/netstream block at ~878–896.
- It has **its own call in `avm2_main.c` at both sites**, right after `avm2_display_run_tick(ctx)` and immediately before `avm2_media_poll(ctx)`:
  - the browser `emscripten` loop (~794);
  - the native tick (~887).

  This keeps the prototype's ordering (drain, then media poll). **`avm2_media.c` / `avm2_net.c` are not touched.**
- The prototype's `worker_throw_frame` wrapper, whose frame argument was unused, is replaced by direct `avm2_throw_error(..., "%s", msg)` calls.
- **Robustness addition:** the batch being announced now lives in a static `g_worker_batch[]`, which `avm2_gc_mark_roots_worker` marks. A worker queued only by C therefore stays rooted while its `workerState` handlers run. The collector runs only between ticks today, so this is defensive. I re-ran the L5 rows after the edit: `worker_terminate` pass (graphics + NG), `abstract_classes` pass, `sound_play` pass, `from_avmplus/ecma3/Expressions/instanceof_002` pass.

## 4. Sweeps against clean `origin/master` (same box, `--recompile`, graphics; categories=full shape)

Both legs ran with the same lists. BEFORE was the clean tree plus a rebuilt master SWFRecomp; AFTER was the patch plus a rebuilt SWFRecomp.

| Sweep | Rows | Moves outside ledger | Notes |
|---|---|---|---|
| L3 (bound methods) | 39: `avm2/{weird_number_bound_methods, primitive_bound_methods, error_throwerror, function_unbound_this}` + `from_avmplus` MethodClosure ×2, `Error1004MethodInvokedOnIncompatibleObj`, Dictionary ×2, `e4x/Types/e9_1_1_1`, Boolean `ecma4_*` ×10, Number `e15_7_4_2*`/`_3*` ×8, String `e15_5_4_2*`/`_3*` ×6, Array ×4, `ecma3/Expressions/instanceof_002` | 0 | all 35 from_avmplus rows pass → pass, same line counts |
| L4 (DefineFont4) | 27: every `avm2/textline_*` (12), `textblock_*` (6), `font_*` (7), `loader_load`, `mixed_avm/avm1_loads_avm2`. This includes all tag-91 SWFs: `font_enumeratefonts`, `textline_atom_index_at_char_index`, `textline_splitting_basic`, `textline_validity` | 0 | the ruffle_matched rows (`textblock_line_changes` 437/481, `textblock_recreateline` 42/178, `textblock_releaselines` 748/752, `textline_atom_index_at_char_index` 37/40) are unchanged. `loader_load` 126/128 and `avm1_loads_avm2` 3/7 are unchanged (both standing NO-GO / RvF) |
| L5 (Worker) | `worker_terminate`, `abstract_classes`, `sound_play`, `instanceof_002` | 0 | with an empty queue the drain is a no-op |
| No-graphics headlines | the 4 ledger rows | — | same flips as graphics (ledger table) |
| **Regression suite** | 8: `avm2_gc_string_survives_collect`, `avm2_gc_string_concat_reclaim`, `avm2_gc_dynprop_tombstone_purge` (new GC root), `avm2_typed_value_ops`, `avm2_findprop_this_resolution` (bound-method path), `avm2_static_text`, `avm2_timeline_text`, `avm2_parent_child_static_text` (timeline emission + child tables) | 0 | all pass → pass |
| **Render canary** | full `render_canary_tests.txt`: 102 tests / 160 PNGs, `--recompile --tier all` | 0 | **IDENTICAL 160, DIFFERS 0**, no trace or image status changes. I did not append a member: the change class is script-visible metrics and bound-method identity, with no render path, and no canary member reads TextLine ascent/descent |

### Per-test before/after (graphics; clean `origin/master` vs patch, same box)

| Row | Before | After |
|---|---|---|
| `avm2/weird_number_bound_methods` | output_mismatch 9/12 | **pass 12/12** |
| `avm2/primitive_bound_methods` | output_mismatch 5/11 | **ruffle_matched 10/11** |
| `avm2/textline_metrics` | output_mismatch 0/20 | **pass 20/20** |
| `avm2/worker_terminate` | output_mismatch 1/56 | **pass 56/56** |
| `avm2/abstract_classes` | pass 132/132 | pass 132/132 |
| `avm2/error_throwerror` | pass 103/103 | pass 103/103 |
| `avm2/function_unbound_this` | pass 51/51 | pass 51/51 |
| `avm2/sound_play` | pass 19/19 | pass 19/19 |
| `avm2/font_description_clone` / `font_embedded` / `font_enumeratefonts` / `_filter` / `_order` / `font_hasglyphs` / `font_registerfont` | pass 14 / 24 / 41 / 4 / 9 / 40 / 129 | identical |
| `avm2/textblock_createline_errors` / `_createline_fte` / `_properties` | pass 23 / 9 / 118 | identical |
| `avm2/textblock_line_changes` / `_recreateline` / `_releaselines` | ruffle_matched 437/481, 42/178, 748/752 | identical |
| `avm2/textline_atom_index_at_char_index` | ruffle_matched 37/40 | identical |
| `avm2/textline_has_tabs` / `_inapplicable_properties` / `_name` / `_raw_text_length` / `_splitting_basic` / `_throwerror` / `_validity` | pass 47 / 10 / 1 / 30 / 76 / 30 / 162 | identical |
| `avm2/loader_load` | output_mismatch 126/128 | identical |
| `mixed_avm/avm1_loads_avm2` | output_mismatch 3/7 | identical |
| 35 `from_avmplus` L3 rows | pass (all) | pass (all), identical line counts |
| 8 `regression` rows | pass (all) | pass (all) |

No-graphics: the four headline rows move exactly as in graphics (ledger table).

## 5. Refutations / premise checks

- **Weak symbols would have been a silent browser divergence**: confirmed. The prototype's `#if !defined(DYNAMIC_HOST)` read meant the WASM bundle always took the 12/3 stubs. With the table and loader hook it reads the same data natively and in the browser, once Pages is redeployed.
- **"The bound-method cache could alias a recycled string address"**: refuted. The receiver is GC-reachable from the cached closure (§1).
- **Sibling overlap.**
  - I do not touch `avm2_net.c`, `avm2_media.c` or `avm2_bitmap.c`.
  - In `avm2_main.c` I add only the two one-line drain calls.
  - In `avm2_globals.h` my hunk sits next to `avm2_register_external` (~226), roughly 650 lines from the netstream sibling's prototype hunk (~878), so a serial apply should be conflict-free.
  - `avm2_globals.c` hunks: the Worker block (~7395) and `avm2_gc_mark_roots_globals` (~6543). The bitmap-encode sibling owns `avm2_bitmap.c`, not this file.

## 6. Not finished / follow-ups (each with its completion mechanism)

1. **Pages redeploy.** The browser recompiler only picks up L4 after `deploy-pages.yml` rebuilds `SWFRecomp.wasm` and the runtime snapshot. Mechanism: the coordinator dispatches `gh workflow run deploy-pages.yml --ref master` after landing; `-f dry_run=true` first if desired.
2. **No in-browser end-to-end run of L4.** I checked the build-path consistency by compiling (§2), not by running a `deploy_wasm_demo.sh` build, as the brief allowed. Mechanism: one browser run of `avm2/textline_metrics` through the Pages recompiler after the redeploy should show 8/2, 16/4, 32/8 rather than 12/3.
3. **Child-movie DefineFont4 faces** (main-movie-only table, §2). Mechanism: if a row ever needs it, add a `cff4_fonts` / `cff4_font_count` pair to `Avm2MovieTables` (trailing fields) and register it per movie in Loader's SWF arm.

## New unclaimed leads

- None beyond `w1-avm2-tail`'s list. The `primitive_bound_methods` Flash line 2 mystery is recorded in RUFFLE_COMPAT_TWEAKS.md and remains an avmplus source read.

## LOCAL ORACLE REQUESTS

None.
