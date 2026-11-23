# s26 w2-robustness-land: growable registries, VAL may_alias, -fno-strict-aliasing, caps, two crash leads

Base: `origin/master` `7dcf5623` (code unchanged since `697669e5f`). Cloud box: SETUP_STATUS all OK (apt, Pillow, Dawn).
Downloaded: `avm1 from_gnash from_shumway avm2` (+ `visual text fonts` for the canary), upstream Ruffle master
`3e98d9ba6` at run time. Ruffle source read at `3e98d9ba6` (blobless clone).

**New files**
- `SWFRecompDocs/plans/session26-fanout-reports/w2-robustness-land-report.md` (this file)
- `SWFRecompDocs/plans/session26-fanout-reports/w2-robustness-land.patch` (`git diff --binary origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt docs/recompiler ruffle-tests/tests/swfs/regression`; includes the 7 fixture dirs with binary `test.swf`; verified with `git apply --check -R`)
- `ruffle-tests/tests/swfs/regression/avm1_many_defs_registry/{create_test_swf.py,test.toml,test.swf,output.txt}` (w1 fixture; golden = coordinator oracle `ruffle-0ddd12b6a`, byte-identical)
- `ruffle-tests/tests/swfs/regression/avm1_pixelbounds_dynamic_child/{create_test_swf.py,test.toml,test.swf,output.txt}` (w1 fixture; golden = coordinator oracle)
- `ruffle-tests/tests/swfs/regression/avm1_cxform_override_overflow/{create_test_swf.py,test.toml,test.swf,output.txt}` (NEW; PNG golden = LOCAL ORACLE REQUEST)
- `ruffle-tests/tests/swfs/regression/avm1_filter_list_overflow/{…}` (NEW; trace golden predicted from Ruffle source, LOCAL ORACLE REQUEST)
- `ruffle-tests/tests/swfs/regression/avm1_long_text_layout/{…}` (NEW; trace predicted + PNG = LOCAL ORACLE REQUEST)
- `ruffle-tests/tests/swfs/regression/avm1_many_functions_registry/{…}` (NEW; trace predicted, LOCAL ORACLE REQUEST)
- `ruffle-tests/tests/swfs/regression/avm1_func2_param_register_oob/{…}` (NEW; trace predicted from Ruffle source, LOCAL ORACLE REQUEST)


## Verdicts (GO unless noted)

| # | Item | Verdict | Trace flips (CI) | Pixel |
|---|---|---|---|---|
| 1 | w1 prototype (9 growable registries + `transformPixelBoundsGetter` `makeF64`) rebased onto `7dcf5623` | **GO**, applied clean (no conflicts with s26 landings) | `regression/avm1_many_defs_registry` new→PASS; `avm1_pixelbounds_dynamic_child` new→PASS (passes before too) | — |
| 2 | `VAL()` = `may_alias` typedef macro (`action.h`) | **GO**. 951 `VAL(` sites, all single-token types (`double` 354, `u64` 334, `float` 128, `u32` 112, `u16` 23, `u8` 9, `s16`/`s32` 4, `s8` 1); no use inside another macro takes a non-type first arg; scanned every 2nd arg for top-level binary operators (the added parens would change `VAL(T, p + 4)`): **0 runtime/include sites** (only `SWFRecomp/src/action/action.cpp:214,1525`, which has its own `VAL` and is untouched). `variables.c`'s duplicate `#define VAL` removed. w1 probe re-run: gcc -O2 old macro `t1=0 t2=0` (store dropped) → new macro `t1=3f800000 t2=3f800000`; clang accepts it (`-fsyntax-only` clean). | 0 | 0 |
| 3 | `-fno-strict-aliasing` on every build path | **GO** (table §3) | 0 | 0 (canary md5) |
| 4a | `MAX_CXFORM_OVERRIDES` 256 → growable | **GO**, fixture `avm1_cxform_override_overflow` | 0 (trace `f1`/`f2` unchanged) | **pixel A/B moves** (before: children 257–300 render stale blue; after: all white) |
| 4b | filter side tables 32/32 → growable, pointer-stable | **GO**, fixture `avm1_filter_list_overflow` | new→PASS (before `c40 n=1`) | render unchanged (both trees blur+tint all 40: the per-entry `tagSetFilter` fields carry the render) |
| 4c | `MAX_TF_PARAGRAPHS` 32 / `MAX_LAYOUT_LINES` 256 → inline + heap | **GO**, fixture `avm1_long_text_layout` | new→PASS (before `maxscroll=249`, after `293`) | **pixel A/B moves** (paragraph 293+ left-aligned before, centred after) |
| 4d | `MAX_FUNCTIONS` 2048 → growable | **GO**, fixture `avm1_many_functions_registry` | new→PASS (before: `ERROR: Function registry full` once per dropped function, `f2499()` and `typeof f2499` undefined) | — |
| 5a | DefineFunction2 param register ≥ RegisterCount smashes the C stack | **GO** (recompiler), fixture `avm1_func2_param_register_oob` | new→PASS (before **RUNTIME_ERROR** `*** stack smashing detected ***`, both modes) | — |
| 5b | `from_gnash/misc-swfc.all/gotoFrameFromInterval` OOM runaway | **GO** (diagnosed + fixed: int32 timer delay) | CI-excluded: 0 unless the exclude is lifted, then **runtime_error → ruffle_matched** | — |
| 5c | shumway `esc` #1009 (optional) | **NO-GO (time-boxed)**: line 1 is a wall-clock line (`388 bytes in 78 ms`), so the row cannot flip; priced 0 by w1-trace-tail-audit. Completion: an AVM2 script-init null-deref probe in a later robustness slot. | 0 | — |

**Gate result.** 220 tests × 2 modes = **440 rows** (the w1 172-test sweep minus the `--test`-unaddressable
`bitmap_data_thorough`, i.e. 39 avm1 + all 134 regression dirs; plus the 7 fixtures; plus 40 argued extra tests across
avm1/from_gnash/from_shumway/avm2 for the new caps, timers, func2 and the flag A/B). Before = clean `origin/master` in a
separate worktree, after = this patch, same box. **Only the 5 ledger fixtures move (10 rows); 430 rows byte-identical**
(saved actual output, status line, every `[image:...]` line). Canary: §6.

## 1. Patch scope (functions touched; for `n-pixel-pass` / sibling merge)

- `SWFModernRuntime/include/actionmodern/action.h`: `VAL` + 10 `VAL_ma_*` typedefs.
- `SWFModernRuntime/src/actionmodern/variables.c`: duplicate `#define VAL` removed.
- `SWFModernRuntime/src/actionmodern/action.c`: function-registry decl block (`function_registry` pointer +
  `function_registry_room()`; `MAX_FUNCTIONS` now expands to it, so all 80 `function_count < MAX_FUNCTIONS` append
  guards are untouched); `transformPixelBoundsGetter` (w1, `makeF64`).
- `SWFModernRuntime/src/actionmodern/timer.c`: new static `timerDelayToInt32`; `actionTimerSetInterval` both arms.
- `SWFModernRuntime/src/actionmodern/registered_class.c`: w1 (`registerClassForSymbolVersion` + table decls).
- `SWFModernRuntime/src/libswf/ng_shared.c`: w1 registries (list in the w1 report §2) + new static
  `ng_layout_lines_grow`, `ng_computeScrollMixedFont` line tables. **Not** `ng_enumerateChildren` (w2-loaded-shell-phase2).
- `SWFModernRuntime/src/libswf/tag.c`: w1 (`tagDoInitActionGuarded`, `tagSetSpriteLabels`, `ng_registerBitmapMetadata`
  + its table decl only, for w2-tail-bitmap-draw); cxform-override stack decl + `cxform_overrides_push`; filter side
  tables (`getOrCreateExtFilter`, `ng_getExtFilterDataByDepth`, `getOrCreateFilterList`, `ng_getFilterListDataByDepth`);
  new `TfParagraph` / static `tf_pars_room` + `textfield_glyph_render_cb` paragraph table. **Not** `ng_attached_run_tree`.
- `SWFModernRuntime/include/libswf/tag.h`: `ng_table_grow` prototype (w1).
- `SWFRecomp/src/action/action.cpp`: DefineFunction2 register-param binding (one `else if` arm).
- Build flags: `SWFModernRuntime/CMakeLists.txt`, `SWFRecomp/CMakeLists.txt`, 7 `SWFRecomp/scripts/*.sh` +
  `wasm_wrappers/bundle/build.sh`, `ruffle-tests/verify_output.py`, `docs/recompiler/pipeline_graphics.js`.
- `ruffle-tests/render_canary_tests.txt`: 2 tier-2 members appended at EOF.

Pointer stability. Filter lists: `display_list[].filter_chain` and `g_current_filter_list` point into entries, so
each list/ext entry is `calloc`ed and only the pointer table grows. (The ext-filter setters `tagSetFilterColorMatrix /
Convolution / Gradient` have **no callers** anywhere in `SWFRecomp/src` or the runtime: that table is dead today; made
growable anyway for consistency.) The cxform stack stores `DisplayObject*` and is only indexed. Text tables are
function-local (inline 32 / 256, heap past that, freed at every exit), so a nested render cannot clobber them.

## 2. Per-test before/after (clean origin/master vs patch, same box, BOTH modes identical unless noted)

| Test | Before | After |
|---|---|---|
| regression/avm1_many_defs_registry | MISMATCH (8 probe lines: btnN movieclip/200, fontN tw=0, vidN movieclip, sndN undefined, expN undefined, clsN undefined, bmpN undefinedxundefined, lblN cf=1) | **PASS** (golden = coordinator exporter `0ddd12b6a`) |
| regression/avm1_pixelbounds_dynamic_child | PASS | PASS (golden = exporter) |
| regression/avm1_cxform_override_overflow (graphics PNG md5) | trace PASS; PNG `03412734…` (44 stale blue squares) | trace PASS; PNG `8975dc2f…` (all white) |
| regression/avm1_filter_list_overflow | MISMATCH `c1 n=2 c40 n=1` | **PASS** |
| regression/avm1_long_text_layout | MISMATCH `maxscroll=249`, `scroll=249`; PNG `d031e71f…` (left-aligned) | **PASS** `maxscroll=293`, `scroll=293 bottomScroll=300`; PNG `e107f1b4…` (centred) |
| regression/avm1_many_functions_registry | MISMATCH (`2499` and `function` → `undefined`; stderr `ERROR: Function registry full` per dropped function) | **PASS** |
| regression/avm1_func2_param_register_oob | **RUNTIME_ERROR** `*** stack smashing detected ***` | **PASS** |
| from_gnash/misc-swfc.all/gotoFrameFromInterval (CI-excluded) | runaway: RSS 1.6→6.9 GB in 5 s, OOM-killed | **RUFFLE_MATCHED**, runs in < 1 s, both modes (18/23 Flash lines) |

## 3. `-fno-strict-aliasing`, every path (grep-proven; no emsdk / wasi-sdk on this box)

| Path | Where |
|---|---|
| `verify_output.py` native (CI trace + graphics) | `common_flags`, after `opt_level` |
| `verify_output.py` wasm | `emcc_args` `"-O2", "-fno-strict-aliasing"` |
| `build_test.sh` | both emcc arms (`-O2 -fno-strict-aliasing`) + native gcc arm |
| `build_graphics_host.sh` | `EMCC_FLAGS` compile array |
| `build_wasm_avm2.sh` | per-TU compile (`"${o}" -fno-strict-aliasing -c`) |
| `wasm_wrappers/bundle/build.sh` (deploy-pages) | per-TU compile (`"${o}" -fno-strict-aliasing -c`) |
| `build_wasm_runtime_lib.sh`, `build_wasm_test.sh` | `CFLAGS` arrays |
| `profile_game_native.sh` | `COMMON_FLAGS` |
| `docs/recompiler/pipeline_graphics.js` | in-browser clang args |
| CMake | `SWFModernRuntime` and `SWFRecomp` targets (`target_compile_options`) |

All `.sh` pass `bash -n`; `pipeline_graphics.js` passes `node --check`. Native legs measured (the whole sweep ran with
the flag). **Not built here: every emcc / wasi / in-browser path** (no emsdk in the cloud box) — first exercised by the
coordinator's deploy-pages `dry_run=true` (CLAUDE.md) or a `--wasm` single test. **CI note:** the flag changes every
compile command, so the first CI run after landing is a full ccache miss. **Deploy note:** `docs/recompiler/` changed →
a deploy-pages dispatch is due after landing (standing approval).

The flag + VAL A/B is folded into the gate (the after leg has both): **0 movers** outside the ledger across avm1,
regression, from_gnash, from_shumway and 8 avm2 rows (`bytearray, number_autoconv, math, string_case, int_edge_cases,
uint_toexponential, json_parse, bitmapdata_colortransform`). Cost per w1 §4: +0.26 % `.text`, compile time unchanged.

## 4. The two crash leads

### 4a. DefineFunction2 register parameter ≥ RegisterCount (`SWFRecomp/src/action/action.cpp`, param-binding loop)

`regs[]` is sized `max(preload count, RegisterCount, max body register + 1)` — the **parameter** registers were never
counted, yet each was bound with `regs[<param reg>] = args[i]`. A param register just past the array overwrites the
stack protector canary (fixture: r3 with RegisterCount 3 → `*** stack smashing detected ***`); farther ones (r200) silently
corrupt caller frames. Ruffle (`core/src/avm1/function.rs` param loop → `Activation::set_local_register`,
`activation.rs:2500`) ignores a write past `local_registers`, so the parameter is simply unbound. The recompiler now emits a
comment instead of the store when `param reg >= RegisterCount` (also covers RegisterCount 0, where Ruffle's
`local_registers` is empty and the write is also dropped). Well-formed SWFs emit byte-identical code (the sweep).

### 4b. `gotoFrameFromInterval` runaway (`SWFModernRuntime/src/actionmodern/timer.c`)

Diagnosis (gdb on the live runaway: `memcpy ← u16_concat ← actionAdd2 ← func_callback_20 ← processTimers`): frame 7's
DoInitAction does `setInterval(callback, 0.0001)` twice (`0x3F1A36E2EB1C432D`). We stored the raw double, so every
tick `processTimers` fired up to its 10 000-iteration safety cap, and the callback appends to `_root.asOrder` per fire →
300 k fires in 30 ticks, O(n²) string memory (~1.3 GB/s). Ruffle coerces the delay with `coerce_to_i32`
(`avm1/globals.rs` `create_timer`) and then clamps to 10 ms (`timer.rs` `MIN_INTERVAL`), ≤ 10 fires per update
(`MAX_TICKS`). Fix (narrow): ECMA ToInt32 on the delay (`timerDelayToInt32`, both setInterval/setTimeout arms) → 0 → the
existing zero-delay arm (fire once, deactivate). Result: completes in < 1 s, `ruffle_matched` (our diff ⊆ Ruffle's).
Deliberately NOT ported: Ruffle's 10 ms floor and 10-fires/update cap, and "delay 0 repeats" (ours deactivates) — each
reorders timer firing for every short-interval test (`avm1/set_interval` has `setTimeout(tick, null)`), and the
remaining residual of this test is exactly that (see leads). The 40-test extra set includes all 5 corpus timer tests
in reach (`set_interval, timeout, timer_run_actions, string_paths_timer`, shumway `avm1/setinterval`,
gnash `gotoFrameFromInterval2`): unchanged.

**Coordinator action:** `.github/workflows/ruffle-tests.yml:869-880` can drop `--exclude=gotoFrameFromInterval`
(it no longer hangs; its comment says it is excluded as a 30 s runaway). Doing so adds one CI row graded `ruffle_matched`.

## 5. EXPECTED-FLIP LEDGER (coordinator: check CI against this)

**Trace axis** (both legs; `ng_shared.c`/`tag.c`/`registered_class.c`/`timer.c`/`action.c` are shared):
- NEW rows, PASS: `regression/avm1_many_defs_registry`, `regression/avm1_pixelbounds_dynamic_child`,
  `regression/avm1_cxform_override_overflow`, `regression/avm1_filter_list_overflow`,
  `regression/avm1_long_text_layout`, `regression/avm1_many_functions_registry`,
  `regression/avm1_func2_param_register_oob`. (The 5 newest goldens are predicted from Ruffle source + our after
  output; see LOCAL ORACLE REQUESTS. If the exporter disagrees, replace `output.txt`; the fix is still a cap removal.)
- Only if the workflow exclude is removed: `from_gnash/misc-swfc.all/gotoFrameFromInterval` new row, `ruffle_matched`.
- **Everything else: no movement.**

**Pixel axis** (graphics only):
- `regression/avm1_cxform_override_overflow` and `regression/avm1_long_text_layout`: new `[image:output]` rows that
  report `SKIP - No expected image` until the exporter PNGs land (LOCAL ORACLE REQUESTS). Expected to PASS once they do
  (solid axis-aligned squares on a pixel grid; text glyphs are square outlines).
- Everything else: md5-identical (canary §6).

## 6. Render canary

`render_canary.py capture` over the standing `render_canary_tests.txt` (132 tests, 196 PNGs, `--recompile`,
graphics/lavapipe): before = clean `origin/master` worktree, after = this patch.
**IDENTICAL 196 / DIFFERS 0 / APPEARED 0 / VANISHED 0; no trace-status or image-status change.** The standing set
cannot see the overflow class, so two tier-2 members are appended at EOF (`avm1_cxform_override_overflow`,
`avm1_long_text_layout`); their A/B md5s are in §2 (both move, as intended). Fidelity vs CI PNGs not checked
(A/B-only verdicts; no absolute pixel claim is made).

## Refutations / premise checks

- Brief: "check every `VAL(type,` use inside other macros." The only `VAL(type,` hits are the `#define` lines themselves
  (runtime `action.h`, `variables.c`; recompiler `swf.cpp`, `field.cpp`, `action.cpp` — host-side, untouched). The
  stack macros (`PUSH`, `STACK_TOP_VALUE`, …) use `VAL(u32/u64/…, &STACK[..])` with literal types; all fine.
- Brief: "Clamp or ignore" the func2 register. **Ignore** is Ruffle's behaviour (no clamping anywhere); clamping to the
  last register would clobber a real local.
- Brief: "`gotoFrameFromInterval` is a runaway, not just a wrong answer." Confirmed and located; it is a sub-millisecond
  interval, not a goto loop. The goto part of the test is fine.
- Filter side tables: the ext table (32) is unreachable (no callers) — the w1 lead overstated it; only the list table
  (32) is live, and only for multi-filter / ColorMatrix lists (a single simple filter is carried by the per-entry
  fields, so 40 blurred clips render identically before and after — measured). The live effect is the `filters`
  getter (trace) and chained filters.

## Not done / completion mechanisms

- WASM builds not executed (no emsdk): coordinator deploy-pages `dry_run=true` after landing.
- 5 fixture goldens + 2 PNG goldens: LOCAL ORACLE REQUESTS below.
- `esc` #1009: NO-GO above.
- w1 lead 5 (`MAX_INIT_ACTION_MOVIES` ≥ 9 loaded movies fixture): not built (the w1 per-movie rows already fix it); a
  9-loadMovie `#initclip` fixture is the completion mechanism.

## New unclaimed leads

1. **Timer semantics vs Ruffle/Flash** (`timer.c` `processTimers`/`actionTimerSetInterval`): `setInterval(f, 0)`
   deactivates after one fire (Ruffle: repeats at the 10 ms floor); no 10 ms floor; per-update cap 10 000 vs Ruffle's 10.
   It is the whole residual of `gotoFrameFromInterval` (Flash expects `asOrder == x0xx1x234`, i.e. several fires).
   Needs an argued timer sweep (every corpus setInterval/setTimeout test) before landing; M.
2. **func2 register READS past RegisterCount** go to the global register file (`actionPushRegister`); Ruffle (player
   version ≤ 10) returns `undefined` when the function has local registers (`activation.rs:2470`). XS, game-exposure only.
3. **Remaining fixed caps** (w1 table, unchanged here): `MAX_SCROLL_CROPS`/`MAX_TEXT_CULLED` 64, `MAX_LAZY_PROTOS` 128,
   `MAX_PROTO_STUB_FUNCS` 192, `MAX_WATCH_ENTRIES` 64, `MAX_EI_CALLBACKS` 32, `MAX_CLONE_DEPTH_ENTRIES` 128,
   `MAX_TIMERS` 64. Same pattern (`ng_table_grow`) if one is ever hit.
4. Dead code: `tagSetFilterColorMatrix/Convolution/Gradient` + `getOrCreateExtFilter` (no callers).

## LOCAL ORACLE REQUESTS

Exporter `0ddd12b6a`; each SWF is committed (regenerate with `python3 create_test_swf.py`).
1. `regression/avm1_filter_list_overflow/test.swf`: `exporter -s -f 1 --trace-log out.txt`. Predicted
   `c1 n=2 c40 n=2` / `c40 blurX=4`.
2. `regression/avm1_many_functions_registry/test.swf`: `-f 1`. Predicted `0` / `2499` / `function`.
3. `regression/avm1_func2_param_register_oob/test.swf`: `-f 1`. Predicted `7` / `undefined` / `undefined` / `done`
   (Ruffle drops the r3 param write; `b` is never a local; r2 is an unset local).
4. `regression/avm1_long_text_layout/test.swf`: `-f 1 --trace-log out.txt … output.expected.png`. Predicted
   `maxscroll=293` / `scroll=293 bottomScroll=300`; commit the PNG as `output.expected.png` (expected: 8 rows of
   centred square glyphs).
5. `regression/avm1_cxform_override_overflow/test.swf`: `-f 2 … output.expected.png`; trace `f1`/`f2`; commit the PNG
   (expected: 300 white squares on black).
