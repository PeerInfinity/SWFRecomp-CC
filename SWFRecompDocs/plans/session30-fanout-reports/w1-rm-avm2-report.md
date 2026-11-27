# s30 w1-rm-avm2: AVM2 `ruffle_matched` pool re-priced against FP32, plus 9 measured S rules

Wave 1, cloud. Branch `fanout/w1-rm-avm2`. Code base `origin/master` = `f4edebdc` (the s30 scaffold; code = s29 FINAL
`2d40d3799`). Corpus downloaded 2026-11-27 at upstream Ruffle master **`66f9073de`** (same as BRIEFS_COMMON).
Categories: `avm2 from_avmplus from_shumway timeline fonts visual mixed_avm`. Graphics mode on lavapipe
(`SETUP_STATUS`: apt, Pillow and Dawn OK). Every measurement below is `--mode=graphics`. Each rule was built in its
own git worktree (`git worktree add` of `origin/master` + that rule only), so no two gates shared a runtime build.
`-P ≤ 2` per sweep. No recompiler change, so no `--recompile` was needed (every leg compiled from a clean test dir).

**New files**
- `SWFRecompDocs/plans/session30-fanout-reports/w1-rm-avm2-report.md` (this file)
- `SWFRecompDocs/plans/session30-fanout-reports/w1-rm-avm2-prototype.patch` = `git diff origin/master -- SWFModernRuntime`
  (all 9 rules; 5 files, runtime only). Sources are reverted on the branch: the commit holds only these two files.

## Verdicts (lead)

**GO: prototype = 9 rows `ruffle_matched → pass`. Priced losses: 3, all from L1′, none toward Ruffle-on-a-Flash-
golden: 2 are harness timing (tick budget / input timing), 1 is a soft-NO-GO platform row. Net +9 −3; without L1′,
+8 −0. All 9 flipped rows are `known_failure` upstream.** Each rule's gate is all-baseline apart from its own ledger lines.

| # | rule (owner file → functions touched) | rm → pass | size |
|---|---|---|---|
| R1 | SWF ≤ 9 goto run in the frame-script phase joins the frame-script cleanup queue (`avm2_display.c`: new `swf9_goto_cleanup_push`; `run_goto`) | `timeline/swf_9_frame_script_dynamic_goto` | S |
| R2 | SWF ≤ 9 goto-placed children are constructed in the frame-script walk before the parent's script (`avm2_display.c`: new `swf9_construct_goto_children`; `run_local_frame_scripts`) | `timeline/swf_9_event_goto_frame_script` (and `avm2/swf_9_goto_in_construct_frame` 8 → 1 diff line, stays rm: premise 5) | S |
| L1′ | fetched child SWF root constructed in the next tick's Construct phase (`avm2_display.c`: `loader_deliver`, `avm2_loader_run_exit_frame`, `loaderinfo_reset_stream`, `avm2_display_run_tick`; new `avm2_loader_boot_pending_fetches`; trailing field `Avm2LoaderInfoExt.boot_at_construct`) | `from_shumway/as3-loader/LoaderTest` | S |
| M1 | a RemoveObject tag that removes an AS3 mask nulls the maskee's `mask` (`avm2_display.c` `run_remove_op`) | `from_shumway/MaskTest-3` | S |
| BA | avmplus bugzilla 558863: SWF ≤ 10 `x in ByteArray` throws #1069 for a missing non-index name (`avm2_ops.c` `avm2_op_in`) | `from_avmplus/regress/bug_558863_swf10` | S |
| RE | PCRE: a multiline `^` does not match after a newline that ends the subject (`third_party/quickjs-libregexp/libregexp.c` `lre_exec_backtrack`, `REOP_line_start_m`) | `from_avmplus/regress/bug_479786` | S |
| PI | avmplus `MathUtils::parseInt` power-of-two re-read past 2^53, ported bug for bug (`avm2_value.c`: new `pow2_digit`, `avmplus_pow2_parse`; `avm2_string_to_int`) | `from_avmplus/as3/Math/e15_1_2_2` | S |
| FTE-1 | `createTextLine(prev)` invalidates and unlinks prev's old successor chain (`avm2_text.c` `tb_do_create_text_line`) | `avm2/textblock_releaselines` | S |
| FTE-2 | a surrogate pair is one atom; a GraphicElement is one U+FDEF char in a TextLine's raw text (`avm2_text.c`: new `g_fte_line_text`, `line_text_of`, `tl_atom_index_of`; `ce_text_of`, `tb_do_create_text_line`, `tb_recreate_text_line`, `tl_get_has_tabs`, `tl_get_atom_index_at_char_index`) | `avm2/textline_atom_index_at_char_index` | S |

**Priced losses (all from L1′):** `avm2/loader_try_click_root` pass → mismatch (input.json delivers every click at
the end of tick 1, before the child boots; flash_fixes `input.json` + `Wait` candidate).
`avm2/xml_appendchild_swf_v21` pass → mismatch (`num_ticks = 1`: the child's 2 traces would come in tick 2; a
flash_fixes `kind: toml` `num_ticks = 2` candidate, though no FP32 capture exists, so ORACLE 0 is needed first).
`from_shumway/as3-loader/events/loader-events` rm → mismatch (platform-split row with a Windows golden; its diff vs
both FP32 captures is unchanged). **Land L1′ only together with those two harness fixes, or hold it.** Without L1′
the patch is +8 / −0.

**NO-GO / HOLD, re-priced (completion mechanism in the pool table):** `loader_events_2` (L2, S–M: the Loader drain
moves to right after the enterFrame broadcast). `swf_9_goto_in_construct_frame` and `clipDepth` (FP32 goldens run past
`num_ticks`; ORACLE 3). The button-state lifecycle rows (M). Typed nulls (L). `avm1movie` (L). `textblock_line_changes`
and `_recreateline` (M). The device-font family (soft NO-GO, host fonts). `array_sort_swf10_*`: not a valid swap on
current evidence; a toml host-emulation key gives +1/0 (section below, ORACLE 1).

## Premise attacks (first-class)

1. **"AVM2 frame/event lifecycle is M–L, NO-GO here" (s28 bucket M, s29 re-price) is refuted for 3 of its 7 rows.**
   The SWF ≤ 9 goto rows are two separate S rules (R1, R2), both visible in Ruffle's own source as places where
   `run_inner_goto_frame` returns early for SWF ≤ 9. `LoaderTest` is a third S rule (L1). The bucket's other rows
   are real M: `loader_events_2` needs a second loader-timing rule (L2, below), `simplebutton_childevents_*` and
   `frame_script_button_order` are button-state lifecycle, `avm2_loads_avm1_events` is the AVM1-child tick.
2. **s29's single "smallest separable rule" for the `swf_9_*` rows was really two rules.** s29 proposed one rule:
   "a goto landing during a construct or frame-script phase queues the target's script to the tail of the current
   pass". The goldens need two independent mechanisms. R1 is the cleanup-queue push (frame-script phase only).
   R2 constructs the goto-placed children during the frame-script walk, before the parent's script. The
   `addedToStage` and `frameConstructed` gotos in `swf_9_event_goto_frame_script` and `swf_9_goto_in_construct_frame`
   happen OUTSIDE the frame-script phase, so R1 cannot reach them. R2 alone flips `event_goto`. It takes
   `goto_in_construct_frame` from 8 diff lines to 1, and even reproduces FP's doubled `MyChild framescript 0`.
3. **The FTE bucket (K) is not uniformly M.** Two of its four rows are S: `textblock_releaselines` (one cut-tail
   rule) and `textline_atom_index_at_char_index` (surrogate pair = one atom, plus GraphicElement = U+FDEF in line
   text). `textblock_line_changes` and `textblock_recreateline` stay M.
4. **Several pool rows had no per-row price of record.** These were the `from_shumway` AVM2 rows (s28 w1b-rm-avm2
   covered avm2/from_avmplus/mixed only) and three avmplus regress rows. Four of them are S rules, measured here:
   `bug_558863_swf10`, `bug_479786`, `e15_1_2_2` and `MaskTest-3`. Each comes from avmplus source or a single-tag
   SWF fact.
5. **Two FP32 goldens run one tick past their `num_ticks`.** These are `swf_9_goto_in_construct_frame` (20 lines; the
   Ruffle file has 18) and `from_shumway/timeline/nav/clipDepth` (8 vs 6). The test author's FP capture ran longer
   than Ruffle's tick budget. `construct_frame`'s golden even ends mid-tick, on `MyContainer enterFrame` with no
   `MyOtherChild onEnterFrame` after it. Measured with R2 at `num_ticks = 4`: we print that line plus 5 more. So no
   tick count gives the golden exactly. The residual 1 line is golden truncation, not a mechanism (ORACLE 3).

## The rules (mechanism, owner, every function touched)

### R1 — SWF ≤ 9: a goto run during the frame-script phase re-queues the target's frame script (S)
- **Golden fact** (`timeline/swf_9_frame_script_dynamic_goto`, FP32): `NodeChild frame1` runs inside the
  frame-script cleanup drain, between `LeafChild 2 frame1` and `LeafChild 3 frame1`. It calls
  `child.gotoAndStop(2)` on a clip that is NOT executing a script. FP runs `LeafChild 2 frame2` right after
  `LeafChild 3 frame1`, i.e. it appends it to the same cleanup queue. Ruffle (and we) run it in the next tick's pass,
  after `Main frame2`.
- **Why:** for SWF ≤ 9, `run_inner_goto_frame` is a no-op that only sets `skip_next_enter_frame`
  (`frame_lifecycle.rs`, our `avm2_display_inner_goto_frame`). So nothing runs the target frame's script until the
  next Construct phase re-marks it pending.
- **Change** (`avm2_display.c`): new `swf9_goto_cleanup_push`, called from the SWF ≤ 9 arm at the tail of
  `run_goto`. In `PHASE_FRAME_SCRIPTS`, if the landed frame has a frame script, it does `fs_cleanup_push` +
  `avm2_display_mark_frame_work`. It is de-duplicated against the queue, so a queued self-goto being flushed
  (already pushed by `mc_goto_frame`) is not pushed twice. The drain (`run_frame_script_cleanup`) resets
  `last_queued_script_frame`, runs the script, and records the frame. The next tick's construct-phase re-mark is
  then not "fresh", so the script never runs twice.
- **Measured:** `swf_9_frame_script_dynamic_goto` rm → pass. Gate below (G1).

### R2 — SWF ≤ 9: goto-placed children are constructed in the frame-script walk, before the parent's script (S)
- **Golden facts** (FP32): `swf_9_event_goto_frame_script` (`gotoAndStop(3)` from the root's `addedToStage`):
  `MyChild Constructor` comes before `Main frame3`. `swf_9_goto_in_construct_frame` (`gotoAndStop(2)` from a
  `frameConstructed` handler): `Calling/Called MyChild super` come AFTER the root's `Stopping Test at frame 2`
  (so NOT at goto time) and before `MyContainer framescript 1`. Then `MyChild framescript 0` runs twice: once from
  the walk, once from the cleanup queue, because its constructor called `addFrameScript(0)` during the
  frame-script phase.
- **Why:** an SWF ≤ 9 goto has no nested frame, so the children it places stay unconstructed. Ruffle constructs them
  only for a QUEUED goto (`run_local_frame_scripts`: `if self.swf_version() <= 9 { self.construct_frame(context) }`)
  or at the next Construct phase.
- **Change** (`avm2_display.c`): new `swf9_construct_goto_children`, called at the top of
  `run_local_frame_scripts`. In `PHASE_FRAME_SCRIPTS` for SWF ≤ 9, each unconstructed render-list child (skipping
  `manual_frame_construct`, and nothing while `running_construct_frame`) gets `construct_frame_obj` +
  `check_has_pending_script`. Existing helpers only.
- **Measured:** `swf_9_event_goto_frame_script` rm → pass. `swf_9_goto_in_construct_frame` stays rm: 8 → 1 diff line,
  the truncated-golden line of premise attack 5.

### L1′ — a fetched child SWF's root is constructed in the NEXT tick's Construct phase (S, with 2 priced losses)
- **Golden facts** (FP32): `from_shumway/as3-loader/LoaderTest`: `loading progress 821,821`, `enterFrame`,
  `from loadee: loaded`, `loadee initialized`. FP constructs the loadee root in the next tick, after `enterFrame`.
  We (= Ruffle) construct it inside the progress drain, before that `enterFrame`. `loader_events_2` shows the same:
  `frame N`, `child`, `child added`, … `init`. `avm2/loaderinfo_child_progress` (passes today) pins WHERE in that
  tick: `child constructor`, then `child exitFrame`, then `loader init`. So the root is built in the Construct
  phase, and its first exitFrame precedes init/complete at the tick's exit flush.
- **Refuted first try (L1, measured):** booting at the next exit flush and firing init/complete in the same pass.
  It flipped `LoaderTest` but broke `loaderinfo_child_progress` (`child exitFrame` landed after `complete`) and
  `loader_try_click_root`. It also moved `loader-events` rm → mismatch. 47 of the 73 Loader rows were gated before
  the refutation; no other moves.
- **Change** (`avm2_display.c`): `loader_deliver` no longer calls `loader_boot_child_swf` for a fetch. It parks the
  tables in `pending_boot` (the loadBytes path already does this) and sets a new trailing field
  `boot_at_construct = 1` on `Avm2LoaderInfoExt` (reset in `loaderinfo_reset_stream`). A new
  `avm2_loader_boot_pending_fetches` (forward-declared next to `avm1_child_tick`) boots every parked fetch at the
  start of the Construct phase in `avm2_display_run_tick`, right after `timer_run_overdue_pass`.
  `avm2_loader_run_exit_frame` re-tracks a still-parked fetch instead of booting it. The loadBytes arm is unchanged.
- **Measured:** `LoaderTest` rm → pass; `loaderinfo_child_progress` stays pass. `loader_events_2` stays rm at 6 diff
  lines, and its residual is now a pure frame-number shift (L2, below). **Priced losses (G4):**
  `avm2/loader_try_click_root` pass → mismatch. Its `input.json` has no `Wait`, so every click is delivered at the
  end of tick 1, before the child exists. The golden's clicks were human-paced in the capture, long after the load;
  disposition = a flash_fixes `input.json` with one leading `Wait` (corpus convention mismatch), or ACCEPTED.
  `avm2/xml_appendchild_swf_v21` pass → mismatch: `num_ticks = 1` ends the run before the child boots (needs
  `num_ticks = 2` via a toml fix, after ORACLE 0 confirms FP's child traces land in tick 2).
  `from_shumway/as3-loader/events/loader-events` rm → mismatch: a platform-split soft-NO-GO row (Windows-FP32
  golden). It sits at 34 diff lines vs the Windows golden and 38 vs the Linux FP32 capture, the same counts as
  before. It is graded as a loss, but moves neither away from nor toward Flash.

### M1 — a RemoveObject tag that removes an AS3 mask clears the maskee's `mask` (S)
- **Golden fact** (`from_shumway/MaskTest-3`, FP32): frame 1 sets `s.mask = getChildAt(0)` (a timeline Shape at
  depth 1). Frame 2's only tag is `RemoveObject2 depth=1`. FP then traces `s.mask` as `null`. Frame 3 assigns a
  never-added Sprite as mask and FP traces `[object Sprite]`, so "mask not on the display list" is NOT the rule. The
  timeline removal breaks the pair.
- **Change** (`avm2_display.c`): `run_remove_op`, timeline-removal arm only (not the script-locked arm, not
  `removeChild`). If the removed child has a `maskee` whose `mask` is this child, null both links before
  `full_remove_child`.
- **Not covered (no corpus row):** goto-driven removals (`run_goto`'s `full_remove_child` calls) and script
  `removeChild` of a mask. ORACLE 4 asks FP32 for both.

### BA — avmplus bugzilla 558863: SWF ≤ 10 `name in byteArray` throws for a non-index name it lacks (S)
- **Golden fact** (`from_avmplus/regress/bug_558863_swf10`, FP32 `PASSED`): `0..2 in b` true, `3 in b` false, and
  `true`, `"xy"`, `{}`, `5.5`, `-5` THROW. `bug_558863_swf11` (passes) needs them to answer false.
- **Change** (`avm2_ops.c` `avm2_op_in`, final arm): if `swf_version < 11`, the receiver is a ByteArray, the name is
  not a uint index and `avm2_has_public_property` says no, throw ReferenceError #1069 (the sealed-miss text used by
  `getproperty` misses).

### RE — PCRE multiline `^` never matches after a newline that ends the subject (S)
- **Golden fact** (`from_avmplus/regress/bug_479786`, FP32 `PASSED`):
  `"foo\n     bar\n\n    baz\n".replace(/^ */gm, " * ")` has no trailing ` * `. avmplus is PCRE, where
  circumflex in multiline mode does not match after a trailing newline. QuickJS libregexp follows ECMAScript, which
  does.
- **Change** (`third_party/quickjs-libregexp/libregexp.c` `lre_exec_backtrack`, `REOP_line_start_m` arm):
  `cptr == cbuf_end` (and not at the subject start) → no match. Only AVM2 uses libregexp (`avm2_regexp.c`).

### PI — avmplus `MathUtils::parseInt` power-of-two re-read, ported with its bugs (S)
- **Golden fact** (`from_avmplus/as3/Math/e15_1_2_2`, FP32): `parseInt("1234567890123", 32)` is
  `38390726480134180`, which is the true value / 32. avmplus re-reads power-of-two radices once the chain reaches 2^53.
  Its `while (++end < len)` tail skips the digit after the rounding digit, so the result is short one radix factor.
- **Change** (`avm2_value.c`): new `pow2_digit` and `avmplus_pow2_parse` (a line-for-line port of the
  `result >= 0x20000000000000` block, with out-of-range reads as "no digit"). They are called from
  `avm2_string_to_int` after the existing chain/exact computation for a power-of-two radix ≥ 2^53. Below 2^53
  nothing changes. Radix 8/4/2/16 goldens in the same row and in the gate (`parse_int`, `0x1000000000000081`, the
  60-digit base 2) still pass, so the port agrees with the old exact path wherever avmplus is exact.

### FTE-1 — `createTextLine(prev)` on a line that already had a successor cuts the old tail (S)
- **Golden fact** (`avm2/textblock_releaselines`, FP32): after `block.createTextLine(line4, 1000)` (line4 already had
  `line5` after it), `line5` reads `validity: invalid`, `previousLine: null`, `nextLine: null`, and
  `textBlock` is still set. We kept it valid and linked to line4.
- **Change** (`avm2_text.c` `tb_do_create_text_line`, the `pl != NULL` link arm): walk `pl->next_line`'s old chain,
  set each to `"invalid"` and null its prev/next, then link the new line.

### FTE-2 — atoms: a surrogate pair is one atom; a GraphicElement is one char of the line's raw text (S)
- **Golden facts** (`avm2/textline_atom_index_at_char_index`, FP32): in `"A😀B"` chars 1 and 2 map to atom 1
  and char 3 to atom 2. In `[TextElement "ab", GraphicElement, TextElement "cd"]` char 4 is atom 4 (5 chars, so the
  graphic occupies one). `GroupElement.text` still omits it (`groupelement_text` passes).
- **Change** (`avm2_text.c`): new `g_fte_line_text` flag + `line_text_of`. While a TextBlock builds or reads its line
  text, `ce_text_of` returns U+FDEF for a GraphicElement (`tb_do_create_text_line`, `tb_recreate_text_line`'s re-split,
  `tl_get_has_tabs`). `GroupElement.text` and every other `ce_text_of` caller are unchanged. New `tl_atom_index_of`
  (code-point walk from `begin_index`) is called from `tl_get_atom_index_at_char_index` after the existing range
  check. Not changed: `atomCount` still reports `rawTextLength` (FP would say 3 for the surrogate line; no golden
  grades it).

## Gates (graphics; "before" = the s30 CI baseline `results_graphics.json` on master, which my origin/master pool run reproduced row for row)

| gate | rows | rule(s) built | result |
|---|---|---|---|
| G1/G2: every AVM2 SWF ≤ 9 row in `avm2/ timeline/ mixed_avm/ from_shumway/` (60, incl. `swf_9_*`, `goto_*/swf9`, `movieclip_queued_noop_goto_swf9`, `swf_9_queued_goto_scripts*`, `frame_script_construct`, `swf_9_frame_script_cleanup_goto*`, `swf_9_goto_in_enter_frame*`, `timeline_events_fp9`, `all_classes/*/swf9`) | 60 | R1 alone, then R1+R2 | R1: only `dynamic_goto` moves (rm → pass). R1+R2: + `event_goto` (rm → pass), `goto_in_construct_frame` stays rm (8 → 1). Every other row at baseline (55 pass, the 2 standing mismatches `verify_method_info_duplicate`, `esc`) |
| G3: ByteArray (`bug_558863_swf10/_swf11`, `as3/ByteArray/*` ×5, `avm2/bytearray`, `_errors`, `_tostring`) | 10 | BA | +1 (`_swf10`), 9/9 baseline pass |
| G3b: every corpus row with an `m`-flag regex + regexp neighbours (`regexp_constr`, `regexp_test`, `regexp_toString`, `as3/RegExp/*` ×3, `esplit_001/002`) | 9 | RE | +1 (`bug_479786`), 8/8 baseline pass |
| G3c: parseInt / string → number (`parse_int`, `is_finite`, `is_nan`, `coerce_string_precision`, `GlobalObject/e15_1_2_2_1/_2`, `Number/e15_7_1/_2`, `TypeConversion/e9_3_1_*`, `JSON/adhoc`, `Statements/e12_10_1`, `regress/bug_564839`) | 15 | PI | +1 (`e15_1_2_2`), 14/14 baseline pass |
| G4: Loader. Every row that fetches a child SWF (42); plus the first L1 attempt over 47 of all 67 Loader rows | 42 | L1′ | +1 (`LoaderTest`). `loaderinfo_child_progress`, `loader_events`, `loader_loadbytes_events`, `large_preload_*`, `loader_error_in_root_ctor`, `loaderinfo_more`, `loader_reuse`, `loaderinfo_quine` and 30 more stay at baseline. **3 losses:** `loader_try_click_root` and `xml_appendchild_swf_v21` pass → mismatch, `loader-events` rm → mismatch (see L1′). `avm1_root` (standing mismatch) loads an AVM1 child, a path L1′ does not touch. `loader_events_2` stays rm |
| G5: masks (`avm2/*mask*`, `mouse_pick_*mask*`, `displayobjectcontainer_getobjectsunderpoint`, `remove_dobj`, `MaskTest`, `-2`, `-3`, 10 `visual/*mask*` image rows) | 23 | M1 | +1 (`MaskTest-3`). Trace 22/22 baseline, and all 19 image comparisons have the CI baseline's exact outlier counts (0/38/99/90/7162/115; so the local render is CI-grade for these rows) |
| G6: FTE (every `flash.text.engine` row: 33) | 33 | FTE-1 + FTE-2 | +2 (`textblock_releaselines`, `textline_atom_index_at_char_index`); 29 baseline pass; `textblock_line_changes`, `_recreateline` stay rm; `groupelement_text` passes |
| G7: `regression/avm2_*` near the changes (`goto_catchup_scale`, `loader_stub`, `child_simplebutton`, `simplebutton_click`, `parent_child_*` ×4, `timeline_*` ×4, `findprop_this_resolution`, `typed_value_ops`, `embed_bytearray`, `localconnection_domain`, `static_and_store_slots`, `strbuf_stale_prefix`) | 18 | R1+R2+BA+RE+PI+M1+L1+FTE | 18/18 pass |
| Pool, frozen combined patch (R1+R2+BA+RE+PI+M1+old L1) | 58 | | exactly the ledger: 7 rm → pass (dynamic_goto, event_goto, LoaderTest, MaskTest-3, bug_558863_swf10, bug_479786, e15_1_2_2); `loader-events` rm → mismatch (L1, also L1′); 50 stay rm |
| Final patch as delivered (all 9 rules, L1′), the moving rows | 16 | all | 16/16 as the ledger says: the 9 GO rows pass; `goto_in_construct_frame`, `loader_events_2`, `textblock_line_changes`, `_recreateline`, `avm2_loads_avm1_events` stay rm; `loader-events` mismatch (priced); `loaderinfo_child_progress` pass |

## Pool re-price (all 58 AVM2-VM rm rows of `s30-baseline-trace-rm.txt`, measured on `origin/master`)

All 58 reproduce as `ruffle_matched` on origin/master in graphics mode (= the s30 baseline; no drift).
"diff" = `<`/`>` line count of `diff ours golden` (blank lines dropped). It counts a changed line twice, so it is not
the same unit as TP's positional "idx" count.

| bucket / owner | rows (diff) | price → completion mechanism |
|---|---|---|
| **GO here** | `swf_9_frame_script_dynamic_goto` (2), `swf_9_event_goto_frame_script` (2), `LoaderTest` (2), `MaskTest-3` (2), `bug_558863_swf10` (2), `bug_479786` (2), `e15_1_2_2` (2), `textblock_releaselines` (8), `textline_atom_index_at_char_index` (6) | S, measured (above) |
| M. frame/event lifecycle (rest) | `swf_9_goto_in_construct_frame` (8 → 1 with R2), `loader_events_2` (6), `simplebutton_childevents_multichild` (20), `simplebutton_childevents_script_order` (2), `timeline/frame_script_button_order` (1), `mixed_avm/avm2_loads_avm1_events` (12) | construct_frame: golden truncation (premise 5; ORACLE 3), after R2. loader_events_2: **L2, S–M**: move the Loader drain from the tick tail to right after the enterFrame broadcast (next to `timer_run_overdue_pass`), so a ctor-time `load()` resolves after the NEXT tick's enterFrame while a reload issued in a load handler still resolves in the same pass. On top of L1, the residual is exactly that one-tick shift of the first fetch (diff measured with L1: only `frame N` lines move). Gate = the 73 Loader rows of G4. Button rows: M (button-state children's frameConstructed/exitFrame and their frame-script pass; FP does not run a state container's construction-time `addFrameScript(0)` in the cleanup queue). avm2_loads_avm1_events: M (AVM1-child tick order) |
| K. FTE (rest) | `textblock_line_changes` (88), `textblock_recreateline` (69) | M: TextLine lifecycle on recreate (DisplayObject state reset, validity on content change). FTE-1 does not move them (G6) |
| N. type representation | `coerce_to_primitive_side_effects_with_nulls` (8), `primitive_bound_methods` (2), `array_sort_swf10_64bit` | typed nulls L (a second null kind in `Avm2Value`); bound-method identity L. Sort64: see the flash_fix question below |
| L. classic TextField layout | `edittext_tab_stops` (12), `edittext_set_text_same_after_edits` (96), `acid-textfield` (10) | M (unchanged) |
| device-font metrics (soft NO-GO) | `fonts/device_font_no_ink` (28), `flash_text_TextField` (5), `edittext_device_transform_layout` (40), `visual/edittext/edittext_device_transform_metrics` (16), `_negative` (82) | host fonts (flash_fixes README rule 4). Completion: FP32 captures on the CI image's fonts |
| Q. misc runtime | `bounds_mode` (12), `gradient_values_readback` (24), `matrix3d_recompose_edge_cases` (16), `blend_transform` (2, render owner), `dictionary_weak_keys` (2, GC), `bug_535446` (8), `length_mods` (10), `bug_539328` (6), `setNotification` (12) | unchanged (s28 Q). `bug_539328` re-read: FP spells a file-private (PrivateNs) class `::IBar` in describeType; S–M, but every getQualifiedClassName/coercion message for a file-private helper class is in its blast radius |
| new: avmplus/Shumway AVM2 misc | `pixelBounds` (2), `clipDepth` (6), `getobjectsunderpoint` (9), `acid-shapes-testing` (24), `acid-text-x` (2) | pixelBounds: an off-list object's `transform.pixelBounds` is 5× its 100 px rect in FP (one sample, S once probed: ORACLE 5). clipDepth: `getObjectsUnderPoint` must drop points clipped out by a timeline clip layer (M), plus the golden runs 1 tick past `num_ticks` (premise 5; a `kind: toml` num_ticks fix, ORACLE 3). getobjectsunderpoint: M (removed/orphan shapes are returned; FP returns none). acid-shapes-testing: one mechanism, 12 lines `x=9.3 w=18.7` vs FP `9.35 / 18.65` (a 1-twip bounds edge, S–M, lead N4). acid-text-x: S once probed (s29 ORACLE 2) |
| O3 verifier | `slot_holes_fail` (2), `slot_id_exceeds_trait_count` (3) | S–M (s29 N2; goldens already flash-fixed to FP32 #1107) |
| debug player | `coerce_property` (2: FP heap address), `error_1034_debug_string` (38) | untestable address; M debug-player value stringification |
| R. platform (soft NO-GO) | `Number/cos` (2), `html_text_img_parsing` (95; w1-drift-smalls), `soundchannel_soundcomplete` (10), `soundchannel_position` (126), `uncaught_errors_stringified` (14), `loader-events` (34), `flash_text_TextField2` (9), `flash_net_SharedObject` (2: host path) | unchanged: Windows-FP32 goldens, Linux FP32 differs |
| S. FP crash | `displayobjectcontainer_stopallmovieclips_nonconstructed` (12) | NO-GO by design (ACCEPTED candidate) |
| L. `avm1movie` | `from_shumway/avm1movie` (11) | L (unchanged): the AVM1 child never reaches init/complete/hitTest/bounds in our AVM1Movie wrapper (9 missing lines), plus `this` printing `_level1` where FP prints `_root` |
| `sprite_dropTarget` (19) | | untestable: input-driven (s28) |

**Prices that changed vs s28/s29:** the 9 GO rows (M/L/unpriced → S, measured). `swf_9_goto_in_construct_frame`
went M → "R2 + golden truncation". `loader_events_2` went M → S–M (L1 measured + L2 named). `textblock_releaselines` and
`textline_atom_index_at_char_index` went M → S. `bug_539328` is newly scoped (blast radius named).

## `array_sort_swf10_32bit` / `_64bit` flash_fix question (register §1a)

- **Facts:** the two `test.swf` are byte-identical (md5 `92e259984ee6…`). `_32bit` passes today against a 32-bit
  player's golden. `_64bit` is rm, and TP (s28) has Linux FP32 (x86_64) == the `_64bit` golden. s28's measured
  `w1b-rm-avm2-sort64.patch` (64-bit atom compare in `cmp_numeric_values`) flips `_64bit` and loses `_32bit`.
- **Is "swap `_32bit/output.txt` to FP32's 64-bit output" a valid flash_fixes entry?** **Not on current evidence.** The
  README needs a reproducible FP32 capture (rule 1: Linux == Windows) and keeps host-dependent goldens as they are
  (rule 4). The `_32bit` golden is not wrong Flash. It is a 32-bit Flash Player's output: the row exists to pin
  exactly that platform split, and Ruffle's own TODO says so. If the Windows projector is a 32-bit binary, WIN prints
  the `_32bit` golden and LNX prints the `_64bit` one. The swap would then violate rule 1 and rule 4.
- **What to capture (ORACLE 1):** run `avm2/array_sort_swf10_32bit/test.swf` on BOTH projectors (trace, direct, 1 frame)
  and record line 1, plus the bitness of each projector binary (`file flashplayerdebugger`,
  `file flashplayer_32_sa_debug.exe`).
  - WIN == LNX == `87000000,-273000000,-270000000,287000000,-245000000`: the swap is valid (rule 1 holds). Land it
    with sort64: **+1/0**.
  - WIN prints the 32-bit line (expected): NOT a valid swap. The +1/0 still exists another way: a `kind: "toml"`
    flash_fixes entry on `_32bit` adds a project-only host-emulation key (precedent: s29 `mock_timezone`), e.g.
    `mock_avm2_atom_bits = 32`. `verify_output.py` turns it into `-DAVM2_ATOM_BITS=32`. sort64 becomes the default,
    because the grading host is Linux x86_64 and FP32 there is 64-bit. Cost: S (one toml key, one `#if` in
    `cmp_numeric_values`). The goldens stay untouched.

## Not run / limits

- No-graphics mode: not run. Nothing touched `swf_core.c`, `tag_stubs.c` or a `NO_GRAPHICS` arm; every change is in
  AVM2 runtime files shared by both builds. **CI for landing: `categories=full`, graphics** (AVM2 runtime; the
  from_avmplus rows are in `full`).
- No render canary: the only render-reachable change is M1 (a mask link after a timeline removal). The 9 image rows
  in the mask gate (G5: `visual/cache_as_bitmap/*mask*`, `blend_modes/{masked_layer_cached_children,shader_as_mask}`)
  kept their image verdicts. Wave 2 should add the canary.
- `regression/avm2_*`: 18 rows near the changes, 18/18 pass (G7, built with the first L1 rather than L1′; none of
  the 18 loads a child SWF). The other ~40 (filters, GC, layer groups, morph, JSON/E4X bounds) cannot reach any
  changed function and were not run.
- The final-patch run covers only the moving rows. The other pool rows were measured with the combined patch minus
  FTE and with L1 instead of L1′. Each rule touches distinct functions; the only shared file region is
  `avm2_display.c`, where the four rules edit four different functions.

## RvF entries to add (coordinator; append at EOF of RUFFLE_VS_FLASH_DIFFERENCES.md)

1. SWF ≤ 9 goto during the frame-script phase: FP runs the target frame's script at the tail of the same cleanup
   drain (`swf_9_frame_script_dynamic_goto`); Ruffle runs it next tick.
2. SWF ≤ 9 goto-placed children are constructed in the frame-script walk before the parent's frame script
   (`swf_9_event_goto_frame_script`, `swf_9_goto_in_construct_frame`); Ruffle constructs them next tick.
3. A fetched child SWF's root is constructed in the tick of its init/complete, after enterFrame (`LoaderTest`,
   `loader_events_2`); Ruffle constructs it in the progress tick.
4. A timeline RemoveObject of an AS3 mask nulls the maskee's `mask` (`MaskTest-3`); Ruffle keeps it.
5. avmplus bugzilla 558863 (SWF ≤ 10 `in` on ByteArray throws) (`bug_558863_swf10`); Ruffle answers false (issue 21224).
6. PCRE multiline `^` vs ECMAScript (`bug_479786`).
7. avmplus parseInt power-of-two re-read bug (`e15_1_2_2`).
8. FTE: createTextLine after a line with a successor invalidates and unlinks the old tail (`textblock_releaselines`).
9. FTE: surrogate pair = one atom; GraphicElement = one U+FDEF char in a TextLine's raw text
   (`textline_atom_index_at_char_index`).

## New unclaimed leads

- **N1 (S–M, +1): L2 loader drain position** (above). It is the only thing left on `loader_events_2` after L1.
- **N2 (S): `atomCount`** should count code points (surrogate line = 3); no golden grades it yet.
- **N3 (S–M): `bug_539328` describeType `::IBar`** for PrivateNs classes; check getQualifiedClassName's blast radius
  first.
- **N4 (S–M): `acid-shapes-testing`**: 12 lines of one bounds value (`x=9.35, w=18.65` FP vs `9.3 / 18.7`). Likely a
  stroke-inclusive bounds rounding edge on one shape.
- **N5 (M): `clipDepth`**: `getObjectsUnderPoint` honouring timeline clip layers, plus a toml `num_ticks = 4`.
- **N6:** M1's goto-removal and `removeChild` variants (ORACLE 4), so the rule can cover every removal path.

## LOCAL ORACLE REQUESTS

0. **FLASH (decides L1′): `avm2/xml_appendchild_swf_v21` and `avm2/loaderinfo_child_progress`, trace, direct, 3 frames,
   2 captures each** (both test dirs ship their child SWF). Expect `child constructor` → `child exitFrame` →
   `loader init` (child_progress), and the `[loadable.swf]` lines after frame 1 (xml_appendchild). File I/O timing is
   wall-clock in FP, so treat a split between captures as nondeterminism, not a refutation.

1. **FLASH: `avm2/array_sort_swf10_32bit` (test.swf, identical to `_64bit`), trace, direct, 1 frame, on BOTH Linux and
   Windows projectors.** Record line 1 and each projector binary's bitness. This decides between the swap and the toml
   key (section above).
2. **FLASH (optional, confirms R1/R2 generality): `timeline/swf_9_frame_script_dynamic_goto` and
   `swf_9_event_goto_frame_script`, trace, direct, 2 captures each.** Expect == golden. No new fixture is needed: the
   corpus goldens are already FP32 (TP).
3. **FLASH: `avm2/swf_9_goto_in_construct_frame` and `from_shumway/timeline/nav/clipDepth`, trace, direct, run ≥ 6 frames
   (or `num_frames = 6`).** Question: what FP prints after the golden's last line. If the FP32 output at 4 ticks is a
   clean prefix of a longer run, propose a flash_fixes `kind: "toml"` `num_ticks` fix (clipDepth: 4) and/or an
   `output.txt` swap at a clean tick boundary (construct_frame).
4. **FLASH (needs a local AS3 build; script below): mask removal variants.** Frame 1: `s.mask = timelineShape`, and
   `s2.mask = scriptShape` (added with addChild). Frame 2: `removeChild(scriptShape)`, then trace `s2.mask`. Frame 3: a
   goto that removes `timelineShape` (gotoAndStop to a frame without it), then trace `s.mask`. Decides whether M1 also
   covers goto removals and script removals.
5. **FLASH (needs a local AS3 build): off-list `transform.pixelBounds`.** For a not-added Sprite with `drawRect(x, y, w, h)`
   over (0,0,100,100), (10,20,30,40), and scaleX = 2: trace `transform.pixelBounds` before and after `addChild`.
   Decides the 5× rule (`pixelBounds`).
