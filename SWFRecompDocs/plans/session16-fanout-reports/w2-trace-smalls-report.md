# w2-trace-smalls — session 16, dual-axis fan-out #8 (WAVE 2, worktree)

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a67464a268863eda4`
Base: `cd04f80b9`. Every flip and canary measured with `--mode=graphics` (the CI mode).
Brief of record: `wave1-trace-board.md` lead **L3** (trace-smalls #2), plus one
relayed row from `wave1-avm1-child.md` §5.2 (`import_assets/avm1_imports_avm1`).

> **NEW FILES: none.** Every hunk edits an already-tracked file. Six files touched
> in total (listed per patch in §3). Nothing to `git add` beyond `git add -u` on
> those six paths.

---

## 1. Verdicts — **+4 flips**, four independent patches

| # | row | verdict | before → after |
|---|---|---|---|
| 1 | `avm2/delayed_symbolclass` | **GO — LANDED** | `output_mismatch` (8/28) → **PASS** |
| 2 | `from_shumway/acid/acid-morph` | **GO — LANDED** | `output_mismatch` (2/6) → **PASS** |
| 3 | `from_shumway/as3-loader/LoaderTest2` | **GO — LANDED** | `output_mismatch` (1/7) → **PASS** |
| 4 | `import_assets/avm1_imports_avm1` (relayed) | **GO — LANDED** | `output_mismatch` (1 spurious line) → **PASS** |
| 5 | `text/links_in_scrolled_text` | **HOLD — do not merge** (0 flips; §5) | `output_mismatch` → `output_mismatch` |
| 6 | `avm2/method_association` | **NO-GO this wave** — needs the recompiler (§6) | — |
| 7 | `avm2/scope_optimizations` | **NO-GO this wave** — needs the recompiler (§7) | — |

Board pricing was floor +2 / real +3 / ceiling +6 for L3's six rows. Delivered
**+3 of the six** plus the relayed AVM1 row = **+4**. Two of L3's rows
(`method_association`, `scope_optimizations`) are confirmed real but both are
**recompiler-emission** work, and `links_in_scrolled_text`'s "STRONG, 1 line"
pricing is **refuted** — see §5.

**All four merged patches are runtime-only** (`SWFModernRuntime/`), so the merged
CI run does *not* need `categories=full`; `categories=all`, `mode=graphics`,
`images=false` is sufficient.

---

## 2. Patches (in this worktree, `SWFRecompDocs/plans/session16-fanout-reports/`)

| patch | files | rows |
|---|---|---|
| `w2-smalls-delayed_symbolclass.patch` | `SWFModernRuntime/src/avm2/avm2_main.c` | 1 |
| `w2-smalls-acid-morph.patch` | `SWFModernRuntime/src/avm2/avm2_display.c` | 2 |
| `w2-smalls-LoaderTest2.patch` | `SWFModernRuntime/src/avm2/avm2_display.c` | 3 |
| `w2-smalls-avm1_imports_avm1.patch` | `SWFModernRuntime/src/actionmodern/action.c`, `.../action_queue.c` | 4 |
| `w2-smalls-links_in_scrolled_text.patch` | `SWFModernRuntime/include/libswf/tag.h`, `.../actionmodern/action.c`, `.../libswf/ng_shared.c` | 5 — **HELD** |

Verified mechanically (`scratchpad/check_patches.sh`): **each patch applies alone
to a pristine `cd04f80b9` checkout**, and all five applied in sequence reproduce
this worktree byte-for-byte. The two `avm2_display.c` patches touch disjoint
regions (the picker at :12034-12105 vs `loader_boot_child_swf` at :5470) and the
two `action.c` patches are ~40 000 lines apart, so any subset merges cleanly.

**Sibling-collision check.** `avm2_display.c` is also owned by the L1/L2 sibling,
but only for `point_transform_native` (:3794-3825), the `flash.geom` descriptor
tables (:14043-14059) and `round_to_i32` (:601) — none of which appear in either
of my hunks. The morph sibling owns `tag.c` and the recompiler's morph/flattening
emission: untouched. The `w2-avm1-child` slot owns the AVM1 `#ifdef SWF_AVM2`
child block (`action.c` :23800-24140) and `avm2_net.c`: untouched.

---

## 3. Row by row

### 3.1 `avm2/delayed_symbolclass` — the boot path ignores `LAZY_INITIALIZE`

Baseline diff is a pure 2-line *shift*, exactly as the board said — our lines 1-2
are `In SecondFrameChild class initializer` / `… script initializer`, Flash emits
them at lines 7-8, after `Called complete event!`:

```
-    1  In constructor                              +    1  In SecondFrameChild class initializer
-    2  Finished constructor                        +    2  In SecondFrameChild script initializer
-    3  Called frameConstructed                     +    3  In constructor
```

**The deferred-SymbolClass machinery already exists and is already correct.**
`avm2_run_frame_tags` (`avm2_main.c`:452) loads a frame's DoABC tags, resolves
that frame's SymbolClass rows, then runs the held-back eager scripts, and
`avm2_display_build_stage` deliberately resolves **frame-0 rows only**. The ABC
registry for this test is right too (`abc_frames = {0}`, `abc_lazy = {1}`,
`symbol_class_frames = {0, 1, 3}`).

The defect is one step earlier. `runSWF_avm2` step 3 eager-inits **every** ABC's
last script *regardless of the LAZY bit* — the "SAFE SLICE" comment at
`avm2_main.c`:388 says so explicitly and asserts honouring LAZY "buys nothing".
That is wrong: Ruffle's `run_abc_and_symbol_tags` holds back **no** eager script
for a `DoABC2` carrying `LAZY_INITIALIZE`; every script of such an ABC waits for
a definition lookup. Here the ABC's *last* script is `SecondFrameChild`'s, so we
ran its class + script initializers at boot.

**Fix (17 lines, `runSWF_avm2` only):** skip the eager last-script init for a
frame-0 ABC whose LAZY bit is set. Gated on `root_class != NULL` — the char-0
root binding is what guarantees step 4 performs at least one domain lookup, so a
lazy movie can never end up with *no* script running. With the gate, the
corpus-wide reach is the 113 frame-0-lazy movies I enumerated (of 2268 ABC
registries), 31 of them multi-script; canaries in §4 cover 13 of those 31 plus
5 single-script ones.

### 3.2 `from_shumway/acid/acid-morph` — the board's "transposed pair" is a morph hit test

Baseline: lines 3 and 4 differ (`true,false,false,true,false,false` expected,
`true,false,true,false,false,false` ours). The board read that as "one predicate
pair evaluated in the wrong order". **Refuted.** The six lines are three
`hitTest()` calls (frame 1, `currentFrame == 25`, `currentFrame >= 30`), each
tracing `morph.hitTestPoint(100,100,true)` then `morph.hitTestPoint(300,300,true)`.
Nothing is transposed — the **second** call is simply answered against the wrong
geometry.

`has_pick_geometry` (`avm2_display.c`:12034) excluded morph shapes outright
(`ext->shape_vert_count > 0 && !ext->is_morph_shape`), so a `MorphShape` fell
back to the bounding box, and `point_in_self` AABB-rejected against
`char_self_bounds`, which for a morph character is the **start** shape's rect
(the recompiler emits one bounds rect per character). Mid-tween that box is both
too permissive at (100,100) and too small at (300,300).

**Fix (three edits, all in the picker region):**
1. `has_pick_geometry` — a morph shape *does* carry real geometry.
2. `shape_contains_local` — new morph arm that ratio-lerps each triangle between
   `shape_data` (START, float bits) and `morph_end_shape_data` (END, floats)
   with Ruffle's weights (`b = ratio`, `a = 1 - b`) and `lerp_twips`'
   round-to-whole-twips, then runs the existing barycentric test. This is the
   same math `avm2_cpu_raster_morph` already uses to *draw* the shape.
3. `point_in_self` — for a morph shape, skip the static-bounds AABB reject; the
   lerped-triangle test is both necessary and sufficient. Every non-morph object
   keeps Ruffle's `world_bounds().contains(point)` guard.

The image comparison on this test still fails with the *same* numbers as
baseline (4308 outliers) — the render half of acid-morph is the morph sibling's
axis and is untouched here; image results never gate trace pass/fail.

### 3.3 `from_shumway/as3-loader/LoaderTest2` — the loaded root's places are queued and never flushed

Baseline diff is one line, `testSymbol present: false` vs `true`. The board's
framing ("a symbol exported by the loaded child SWF is not visible through the
loader's `applicationDomain`") is **wrong**: `testSymbol` is not an exported
symbol at all. Recompiling `Loadee2.swf` by hand shows it is a `DefineButton2`
(char `base+2`) **placed on the loadee root's frame 1 with an instance name**:

```c
{ 0, 13, 1, 1002, 1, 0, 0, "testSymbol", ... }   // flags 13 = HAS_CHAR|HAS_MATRIX|HAS_NAME
```

so the value the fixture reads is the ordinary `set_on_parent_field` binding.

Instrumented run (env-gated `fprintf`s, since removed): the loaded root's
`run_frame_internal` fires with `timeline != NULL, playing = 1, frame_idx = 0`,
but **no named child is ever placed**. Reason: `run_frame_internal` only *queues*
this frame's places (Ruffle's per-depth `QueuedTagList`); `flush_queued_places`
is what actually creates them — and it is called from exactly one place,
`enter_frame_obj`. `loader_boot_child_swf` calls `run_frame_internal` directly
and never flushes, so the loaded root has no frame-1 children while the load's
own `complete` handler runs. (It then sets `skip_next_enter_frame = 1`, which
delays the flush by another whole tick.)

**Fix (self-localized to `loader_boot_child_swf`, 8 lines):** pair
`run_frame_internal` with `flush_queued_places`, exactly as `enter_frame_obj`
does. No reflow of the loader state machine, no signature changes. **Function
named for the sibling that owns Loader timing: `loader_boot_child_swf`
(`avm2_display.c`:5467).**

### 3.4 `import_assets/avm1_imports_avm1` — relayed row, `ImportAssets` must not play the imported timeline

`wave1-avm1-child.md` §5.2 handed this off as "one spurious leading line,
`Hello from right_eye.swf`". Confirmed and fixed.

`actionImportAssets` replays the imported movie's `frame_0` to register its
character definitions (bounds for `attachMovie`, etc.), under `catch_up_mode = 1`
and `g_tag_skip_mode = 1`. But the recompiler guards each queued root DoAction
with `if (!catch_up_mode || g_tag_skip_mode)` — so setting *both* flags makes the
guard **true** and the imported movie's own frame-1 DoAction runs. Flash's
`ImportAssets` imports symbols only; the imported timeline never plays.

**Fix (10 lines):** a new file-scope flag `g_import_assets_frame0` in
`action_queue.c`, checked at the top of `actionQueueScript`, set around the
`entry->frame_funcs[0](app_context)` replay in `actionImportAssets`. The imported
movie's `DoInitAction` scripts are unaffected — those run from
`entry->init_func`, which is why `Right eye loaded!` still appears.

Image comparison for this test failed at baseline with 17922 outliers / max 255
and fails identically after; unchanged axis.

---

## 4. Canary ledger

Baselines are the graded CI run (`31748059158` @ `3db858cbc`), read out of each
suite's `_results/results_graphics.json` in the main tree — the authoritative
per-test status the merged run will be diffed against. All canaries were run in
this worktree with all four merged patches applied (plus the held one, which is a
no-op for every row below).

| test | baseline | after | note |
|---|---|---|---|
| `avm2/abstract_classes` | pass | **pass** | lazy, 1 script |
| `avm2/bitmapdata_applyfilter_blur` | pass | **pass** | lazy, 2 scripts |
| `avm2/describe_type_basic` | pass | **pass** | lazy, 2 scripts |
| `avm2/describe_type_json` | pass | **pass** | lazy, 6 scripts |
| `avm2/displayobject_mask` | pass | **pass** | lazy, 2 scripts (image check also passed, 0 outliers) |
| `avm2/error_stack_trace` | pass | **pass** | lazy, 3 scripts |
| `avm2/hittest_morph` | pass | **pass** | morph picker |
| `avm2/matrix3d` | pass | **pass** | lazy |
| `avm2/morph_shape` | pass | **pass** | morph picker |
| `avm2/number_convert_edge_cases` | pass | **pass** | lazy (s15 flip, regression risk) |
| `avm2/sub_super_same_field` | pass | **pass** | lazy, 5 scripts (s15 flip) |
| `avm2/symbol_class_conflict` | pass | **pass** | lazy, 2 scripts (needed `--recompile`, §4.1) |
| `from_avmplus/ecma3/String/e15_5_4_8_2` | pass | **pass** | lazy, 4 scripts |
| `from_avmplus/regress/bug_550958` | pass | **pass** | lazy, 4 scripts |
| `from_shumway/acid/acid` | pass | **pass** | lazy, 2 scripts; image 8669/9100 OK |
| `from_shumway/timeline/timeline_loop` | pass | **pass** | lazy, 2 scripts; image OK |
| `visual/definefont4` | pass | **pass** | lazy, **209 scripts** — the worst case for §3.1 |
| `visual/cache_as_bitmap/morph` | pass | **pass** | morph |
| `visual/cache_as_bitmap/edittext_hscroll` | pass | **pass** | hscroll |
| `visual/edittext/edittext_caret_empty` | pass | **pass** | caret |
| `regression/avm2_morph` | pass | **pass** | morph |
| `avm1/hittest_morph` | pass | **pass** | AVM1 morph hit test |
| `avm1/hittest_morph_input` | pass | **pass** | AVM1 morph hit test |
| `avm1/edittext_hscroll` | pass | **pass** | hscroll |
| `avm1/edittext_place_caret` | pass | **pass** | caret |
| `text/html_entity_parsing` | pass | **pass** | text |
| `import_assets/avm1_non_swf_import` | pass | **pass** | ImportAssets |
| `import_assets/empty_url` | pass | **pass** | ImportAssets |
| `text/text_caret_placement_align` | pass | **pass** | §5 patch's blast radius (needed `--recompile`) |
| `text/text_caret_placement_leading` | pass | **pass** | §5 patch's blast radius |
| `text/text_caret_placement_scroll` | pass | **pass** | **the** scroll+caret canary for §5 |
| `text/text_caret_placement_translated_bounds` | pass | **pass** | §5 patch's blast radius |
| `from_shumway/button1` | pass | **pass** | needed `--recompile`, §4.1 |

**32 canaries green, zero regressions.** Six of them needed a re-run — §4.1.

### 4.1 A false-failure class worth recording: copied test dirs need `--recompile`

Six canaries first came back `COMPILE_FAIL` ("collect2: ld returned 1") or, for
`text_caret_placement_translated_bounds`, an `output_mismatch` in which **every**
caret landed at column 0. Both are the same artifact, and neither is a
regression:

```
/usr/bin/ld: avm2_display.o: undefined reference to `avm2_generated_symbol_class_frames'
/usr/bin/ld: avm2_text.o:   undefined reference to `avm2_generated_device_fonts'
/usr/bin/ld: avm2_main.o:   undefined reference to `avm2_generated_abc_frames' / `..._abc_lazy'
```

These symbols come from the test's own generated tables. I `cp -r`'d the canary
directories in from the main tree but — unlike my six headline tests — ran them
**without `--recompile`**, so they linked against stale generated C from a
different recompiler state. The standing wave-2 rule ("pass `--recompile` on
FIRST use of each copied dir") applies to *canaries* too, not just headline rows.

Proof it is not my patch: `text_caret_placement_translated_bounds` produces the
**identical** column-0 diff with `w2-smalls-links_in_scrolled_text.patch` reverted
(`git apply -R`, full rebuild, same 4 diff lines). Re-run with `--recompile`, **all six pass**
(`text_caret_placement_align/leading/scroll/translated_bounds`,
`avm2/symbol_class_conflict`, `from_shumway/button1`). Nothing in these four
patches can affect glyph advances or the AVM2 generated-table externs.

---

## 5. `text/links_in_scrolled_text` — **HOLD**, and the board's pricing is refuted

Board: *"1 / 1, expects `Success!`, we emit a **blank line** — the trace fires
with an empty string. STRONG."* Two corrections:

1. We do not emit a blank line. `results_graphics.json` records
   `actual_lines: 0` — **nothing traces at all**; the harness renders an empty
   actual as one blank line.
2. It is not one line of work. Measured, with instrumentation:

```
[dbg] dragend was_click=0 focused=(nil) mx=210.000000 my=263.000000 nmc=1
[dbg] field 0 aabb 118.000000 73.400002 391.000000 279.950012
[dbg] char_idx=740 scroll=8 hs=100.000000 run=(nil) href='(null)' runs=30
```

The click *does* reach the field (its stage AABB is right) and the run table
*does* hold the 30 style runs including the `<a href="asfunction:callback">`
one. The failure is the character index: the fixture's plain text is **738**
u16 units (14 `<p>` paragraphs, `wordWrap = 0` — I decoded the `DefineEditText`
flags, `0xad3b`: HasText, Multiline, ReadOnly, HasTextColor, HasFont, HasLayout,
NoSelect, Border, HTML, UseOutlines, and **WordWrap off**), so `char_idx = 740`
is past the end and `tf_find_run_at_index` returns NULL — no `asfunction` fires.

The held patch is the necessary *first* half and is correct as far as it goes:
AVM1 `TextField.scroll` / `.hscroll` are author-set view offsets that our glyph
renderer never applies, and the hit-test path did not add them back either, so a
click in a scrolled field mapped to the wrong line and column. It threads a
`scroll_lines` argument through `ng_getCharIndexAtPoint` (0 for every unscrolled
field in the corpus, hence a strict no-op elsewhere) and adds `hscroll` to the
local x at all three call sites. With it, `scroll` reads 8 and `hscroll` 100 as
intended.

**Residual (why it is HELD):** the click lands one line too low, on the *empty
15th line* our HTML→text conversion produces for the trailing `</p>` (that
trailing `\n` is deliberate — `action.c`:22462 documents Flash doing the same for
multiline HTML fields), which also inflates `maxscroll` to 8. Closing the row
needs the vertical line model reconciled end to end: line height from the real
`Segoe UI Black` metrics, the visible-line count for a 204.55 px field, and
whether the phantom last line participates in `maxscroll` — i.e. the
`ng_computeScroll*` family, not the hit test.

**Completion mechanism:** grade `maxscroll` and `bottomScroll` for this exact
field against Flash first (`scroll` must clamp to the value that puts paragraph
14 at view line 7). If Flash's `maxscroll` here is 7, the phantom line must be
excluded from the scroll window and this patch then carries the rest of the row;
if it is 8, the line-height estimate in `ng_getCharIndexAtPoint` is short by one
line's worth and that is the fix. Either way it is a text-layout row, not a
hit-test row — it should go to whoever owns `ng_shared.c`'s line model, with
`text/text_caret_placement_scroll` as the paired canary.

I am delivering the patch so that work does not start from zero, but **it flips
nothing on its own and should not be merged this session.**

---

## 6. `avm2/method_association` — NO-GO this wave (recompiler), with the shape corrected

Expected is 5 lines (`1107 / 1107 / 1034 / Passed / Passed`); we print `Passed`
×4. The board reads that as "missing #1107 ×2 + #1034". Decoding
`RecompiledABC/abc0_methods.c` and `abc0_tables.c` gives the precise shape — and
it explains the **fifth** line, which a naive reading cannot (the ctor makes only
four `test1..test4` calls, each tracing exactly once):

| call | what the ABC does | avmplus | our behaviour |
|---|---|---|---|
| `test1` | `NewFunction method[1]` where method 1 **is `Test/test1` itself** (already bound to an instance trait) | **verify-time** VerifyError #1107, thrown before `test1`'s own `try` — propagates to the ctor → `1107` | runs fine → `Passed` |
| `test2` | `CallStatic method[4]`, a **free** method_info bound to no trait | **verify-time** #1107 → ctor → `1107` | runs fine → `Passed` |
| `test3` | `NewObject{}` then `CallStatic method[1]` (`Test/test1`) | **runtime** TypeError #1034 coercing `this` to `Test`; caught by **test3's own** `catch`, which traces `e.errorID` → `1034`; test3 returns normally so the ctor also traces → `Passed` | no coercion → `Passed` only |
| `test4` | `NewFunction method[4]` twice in a loop (legal) | `Passed` | `Passed` |

So `1034` and the second `Passed` are **both** test3 — that is the missing fifth
line, and it is why the row cannot flip on the #1107 half alone.

**Why it is not runtime-only.** The #1034 half *is* runtime-only and cheap:
`avm2_op_callstatic` (`avm2_ops.c`:3212) already reads
`act->file->method_env_class[method_index]`, the callee's declaring class, so
coercing `recv` to it and throwing #1034 is a few lines. The #1107 half is not:
avmplus raises it when the *method is verified*, i.e. before the method's own
`try` frame exists. Our generated bodies call `avm2_try_push_frame` at the top,
so throwing from inside the body puts the error in the callee's own `catch`,
which traces `Error should be verify-time` — the wrong output. The throw must be
emitted **ahead of** `avm2_try_push_frame`, which only the recompiler can do.

**Completion mechanism (two commits, priced +1 together):**
1. `SWFRecomp/src/abc/abc_emit.cpp` — build the set of method_infos referenced by
   any class/instance trait (method/getter/setter), by any `iinit`/`cinit`, and
   by any script init ("bound"). Then, per body: `NewFunction m` with `m` bound,
   or `CallStatic m` with `m` unbound ⇒ emit
   `avm2_throw_verify_error(act, 1107)` as the body's first statement, before
   `avm2_try_push_frame`.
2. `SWFModernRuntime/src/avm2/avm2_ops.c` — `avm2_op_callstatic` coerces the
   receiver to `method_env_class[method_index]` and throws TypeError #1034 on
   failure.

Neither alone flips the row. Sibling row `avm2/verify_method_info_duplicate`
(`output_mismatch` at baseline) is in the same family and should be graded in the
same slot. Because (1) is recompiler emission, that slot's CI run wants
`categories=full`.

---

## 7. `avm2/scope_optimizations` — NO-GO this wave (recompiler), mechanism confirmed

Expected `Without coerce: / 0 / With coerce: / [class field]`; we print `0` for
both. The board's diagnosis is **correct** and I can now name the exact opcode
window (`abc0_methods.c`, `Test/Test`, method 10):

```
17: FindPropStrict Subclass      # second block
18: ConstructProp  Subclass      -> a Subclass instance
19: Coerce         mn[8] Superclass
20: PushScope                    # scope entry's STATIC type is Superclass
21: FindPropStrict trace
22: FindPropStrict mn[4] field   <- must NOT bind to the scope object
23: GetPropertyStatic mn[4] field
```

`Superclass` declares no `field` trait, so avmplus's verifier skips that scope
entry at compile time and the lookup falls through to the global class `field`
(`[class field]`). Without the `Coerce` (ops 5-10) the entry's static type is
`Subclass`, which *does* have the slot, giving `0`. We resolve findpropstrict
against the runtime object in both cases, so both print `0`.

**Completion mechanism (recompiler-only, ~1 slot):** in `abc_emit.cpp`, track a
per-stack-slot static class set by `Coerce <class multiname>`; when `PushScope`
consumes that slot, remember the scope entry's static class. At
`FindPropStrict`/`FindProperty`, walk the local scope entries from the top down
and *reduce the `scope_n` argument* past every trailing entry whose static class
is **sealed** (non-dynamic), fully known in this ABC, and provably lacks the
looked-up name in its own + inherited traits. No runtime struct change, no
`Avm2ScopeEntry` field, no new opcode — just a smaller `scope_n` in the emitted
`avm2_op_findpropstrict_ic` call. The sealed-class restriction is what keeps it
sound (`with` scopes are `is_with = 1` and must never be skipped).

I did not take it because it is recompiler-side (my worktree's `SWFRecomp/build`
is a copy of the main tree's, valid only for runtime-only patches) and it is a
verifier feature for +1 — the four runtime rows were the better use of the slot.

---

## 8. Reproduction

```bash
export DAWN_INSTALL=~/CC/dawn-install SWFRECOMP_COMPILE_TIMEOUT=2400
python3 ruffle-tests/verify_output.py --test=delayed_symbolclass --mode=graphics --diff
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/from_shumway/acid \
        --test=acid-morph --mode=graphics --diff
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/from_shumway/as3-loader \
        --test=LoaderTest2 --mode=graphics --diff
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/import_assets \
        --test=avm1_imports_avm1 --mode=graphics --diff
```

`from_shumway/acid` and `from_shumway/as3-loader` are **not** in
`verify_output.py`'s `SUITE_DIRS`, so both need an explicit `--tests-dir`; bare
`--test=acid-morph` resolves to the wrong suite and errors out.
