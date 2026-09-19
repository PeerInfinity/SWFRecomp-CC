# w1-gnash-actionorder — wave-1 diagnosis (session 20)

Read-only. **No source edits, no commits.** Measured at HEAD `4b05de6ef` → `574207007` (the only
commit in between is `574207007`, docs-only: the s20 boards and common brief — no source file
changed, so every measurement below is at the baseline code). All runs are single-test, sequential, one job at a time,
`SWFRECOMP_COMPILE_TIMEOUT=2400`, `--tests-dir=ruffle-tests/tests/swfs/from_gnash … --diff --verbose`
(no-graphics; mode parity is complete per the common brief, and every row below is a pure
trace/ordering row with no render dependency). Logs:
`<scratchpad>/w1-gnash-actionorder/out_*.txt`.

---

## 0. HEADLINE — THE BRIEF'S PREMISE IS REFUTED. FUND NO WAVE-2 SLOT FOR THIS FAMILY.

The brief's inference was: *"this is the largest single-suite cluster the s20 board does NOT name,
which makes it the most likely place for unclaimed cheap yield."* The inference is exactly inverted.

**These rows are the most-adjudicated family in the corpus.** They are absent from
`polish-sweep-arc.md` §20.5 **because sessions 17–19 struck them**, not because nobody looked:

| Session | Artefact | What it did to these rows |
|---|---|---|
| s13 | `session13-fanout-reports/w2-rider-actionorder-report.md` | first wave-2 attempt on the family |
| s14 | `session14-fanout-reports/wave1-avm1-tick.md` | **DEFER** on `test11`; priced the whole arc at **+1**; enumerated an 8-mechanism blast radius |
| s15 | `session15-fanout-reports/w2-action-order-report.md` | **NO-GO, no patch, zero source edits**; killed the board's "+2 ceiling" |
| s17 | `session17-fanout-reports/wave1-timeline-order.md` §6–7 | **NO-GO ×4** (S5 `test11`/`extend`, S6 `ActionOrderTest3/4/5`, S7 `test6`, S8 `PlaceAndRemove`) + **STRIKE** on `RegisterClassTest4`; board edit applied at `polish-sweep-arc.md:2277` |
| s18 | `session18-fanout-reports/w1-trace-avm1-report.md` N2/N3/N5 | **NO-GO** incl. `movieclip_destruction_test3/4` |
| s19 | `session19-fanout-reports/w1-avm1-display-report.md` §7 | **re-verified byte-identical at HEAD `254145a5b`**, 9 of my 11 rows, one session ago |
| s19 | `session19-fanout-reports/w1-avm1-builtins-report.md` N5 | `DrawingApiTest` **HOLD (12+2)** — and it is not an action-order row |

**Priced flips available in this family: 0.** Not "0 cheaply" — 0 at any wave-2 budget, because two
of the eight core rows cannot reach `ruffle_matched` structurally (no sidecar at all) and the other
six need mechanisms whose prior attempts were each reverted for a named regression.

**Second refutation: they are not one or few shared mechanisms.** Eight core rows decompose into
**five** mechanisms, and two of those five are *sign-opposite to each other* (one wants events
suppressed, the other wants the same class of events fired). Even inside the single "one plan"
bucket B4, `ActionOrderTest3` fails by **under-placing** (10 refused placements) while
`ActionOrderTest4` fails by **over-cycling** (ctor count 4 → 7, zero refusals). Any wave-2 brief
that treats "the action_order cluster" as one owner is mis-scoped by construction.

**Third refutation — the brief's own drop-fast instruction was right:** `DrawingApiTest` does **not**
share the display-list-ordering mechanism. It is 12 `hitTest`-precision lines plus a 2-line `delete`
bug. Dropped from the family in §5.

---

## 1. Verdicts — GO/NO-GO with priced flips by test name

| Bucket | Rows (test names) | Priced flips | Verdict | Completion mechanism (required for every HOLD/NO-GO) |
|---|---|---:|---|---|
| **B1** phase-global frame pipeline ("Track B") | `action_execution_order_test11`; the residual swap in `_test6`; bug 2 of `_extend_test` | **0** | **NO-GO** | A dedicated session, not a fan-out slot: collapse phases 1/2/4 into a per-clip `{enterFrame; advance; own DoAction}` walk behind a runtime A/B flag, move the **recompiler-emitted** `tagFlushPendingEnterFrame` call site, re-derive or delete all 8 interlocking mechanisms listed in s14 §5, then full-corpus A/B in **both** CI modes (every `Recompiled*` cache invalidates). |
| **B2** timeline-sprite `onLoad`/`onUnload` **method** dispatch gate | bug 1 of `_extend_test` | **0** (and a named **−1 risk**) | **NO-GO** | Step 0 is *not* code: obtain Gnash's `action_execution_order_extend.c` to pin the fire/no-fire rule (Flash fires `mc_red.onLoad`, does **not** fire `mc_blu.onLoad`; Ruffle fires both). Only then widen the `tag.c:772-788` gate — which is the landed `ACTION_EXECUTION_ORDER_TEST12` fix currently holding `misc-swfc.all/action_execution_order_test12` at `ruffle_matched`; widening it *is* that fix rolled back. And even a perfect B2 cannot flip the row without B1. |
| **B3** place+remove cancellation: same-**frame** vs same-**goto-sweep** | `PlaceAndRemove`; `action_execution_order_test6` | **0** | **NO-GO** | Per-entry tracking of "this placement was cancelled by its paired RemoveObject in the same sweep" in the `aq_drain` filter — **not** a predicate flip (the 2026-05-08 flip `281f30b3` regressed `reverse_execute_PlaceObject2_test2` pass 10/10 → `ruffle_matched` 7/10 and was reverted in `4c61f111`). Then `PlaceAndRemove` *additionally* needs the fixture to complete 96 cycles in 30 ticks (we complete 15), and `_test6` additionally needs B1. |
| **B4** sprite loop-back / inter-tag UNLOAD identity | `ActionOrderTest3`, `ActionOrderTest4`, `ActionOrderTest5` | **0** | **NO-GO** | `blocked/INTER_TAG_UNLOAD_PLAN.md` Phases 2+4 (fire UNLOAD on the sprite loop-back display-list clear; queue dynamic `onUnload` for sprite-internal replacements) landing **together with** `blocked/SPRITE_REWIND_IDENTITY_PLAN.md`, validated against the `loop_test6` / `action_execution_order_test12` / `reverse_execute_PlaceObject2_test2` guardrails. Three attempts (2026-04-29, 2026-05-03 ×2) each bought **+1/+2 matching lines** on these three rows; the plan's own standing instruction is to stop repeating that trade. |
| **B5** `removeMovieClip` deferral + hard-reference clearance | `movieclip_destruction_test3`, `movieclip_destruction_test4` | **0** | **NO-GO** | `MOVIECLIP_VN_PLAN` Phase 6/7 (a removed clip's hard references become `undefined`; post-removal `getDepth()` returns the biased `-32768 - d - 1`) **plus** deferring `removeMovieClip` to the end of the calling frame script so the sprite's final frame completes; `_test4`'s missing sprite-frame traces sit behind the same blocked `SPRITE_REWIND_IDENTITY_PLAN` as B4. 13 and 32 missing lines respectively. |
| **B6** dispositioned / mis-filed | `register_class/RegisterClassTest4`; `DrawingApiTest` | **0** | **STRIKE** (RCT4) / **HOLD, wrong family** (DrawingApi) | RCT4: in `from_gnash/_investigation/ACCEPTED_DIFFS.md` **and** `from_gnash/misc-ming.all/ignored_tests.txt` since 2026-05-08 — `filter_results.py` applies both lists, so it is **0 on the published filtered rate**. (It is still in `corpus_status_diff.py`'s raw `effective` count, which applies no ignore list — that is why it is on the wave-0 inventory. Never price a disposition off that number.) DrawingApi: see §5. |

**Family total: 0 flips.** Recommended coordinator action: leave these rows off the board (they
already are), and if anyone re-adds them, attach this table's completion-mechanism column.

---

## 2. Fresh re-verification at the s20 baseline — zero drift, and zero movement since 2026-05

Every row re-run by me at HEAD. Actual-line counts are identical to the wave-0 inventory, and the
diffs I compared line-for-line against the s14/s15/s17/s19 transcripts are **byte-identical**.

| Row | inventory (match/exp, actual) | my re-run (actual lines) | diff vs prior transcript |
|---|---|---|---|
| `misc-ming.all/action_order/ActionOrderTest3` | 4/62, 83 | 83 ✔ | identical (runaway tail) |
| `…/ActionOrderTest4` | 10/64, 94 | 94 ✔ | identical (runaway tail) |
| `…/ActionOrderTest5` | 6/51, 58 | 58 ✔ | identical |
| `…/PlaceAndRemove` | 15/96, 45 | 45 ✔ | identical (`moo N` + forbidden CONSTRUCT line per cycle) |
| `…/action_execution_order_extend_test` | 7/32, 28 | 28 ✔ (`--save-actual`) | identical; assertion-level breakdown in §4.3 |
| `…/action_execution_order_test11` | 26/32, 32 | 32 ✔ | **byte-identical** to s14/s15/s17/s19: same 8/9 `mc21 onLoad` ↔ `mc1 onEnterFrame` swap, same `doActionOrder 0+2+1+3+4+5+`, same `asOrder` |
| `…/action_execution_order_test6` | 0/24, 20 | 20 ✔ | identical (cycle-1 CONSTRUCTs missing; LOADs present) |
| `…/register_class/RegisterClassTest4` | 7/42, 54 | 54 ✔ | identical |
| `misc-swfc.all/movieclip_destruction_test3` | 5/18, 16 | 16 ✔ | identical |
| `misc-swfc.all/movieclip_destruction_test4` | 8/40, 24 | 24 ✔ | identical |
| `misc-ming.all/DrawingApiTest` | 81/93, 95 | 95 ✔ | identical |

Method note for the "actual lines" column: for the eight rows whose actual output is **longer** than
expected, the aligned `--diff` output's last index *is* the actual line count. For the three rows
whose actual is **shorter** (`_extend_test`, `movieclip_destruction_test3`, `_test4`) the alignment
pads, so I re-ran them with `--save-actual` and counted the captured file: **28 / 16 / 24** — exactly
the inventory's `ACT` column. No row drifted.

**The stronger observation:** the per-row match counts in the 2026-05-15 plan documents
(`eb8206f8` baselines: PlaceAndRemove 15/96, `_test6` 0/24, `_test11` 26/32,
`movieclip_destruction_test3` 5/18, `_test4` 8/40) are the **same numbers we measure today**, four
months and ~20 sessions later. This family is not "stale, worth a re-price" — it is *frozen*, and
every session that re-priced it got 0.

### Disposition check (common-brief rule 2), done for all 11 rows by name

Grepped `avm1/_investigation/{ACCEPTED_DIFFS,RUFFLE_VS_FLASH_DIFFERENCES,RUFFLE_COMPAT_TWEAKS,FLASH_BUGS_REPLICATED}.md`,
`from_gnash/_investigation/ACCEPTED_DIFFS.md`, `ruffle-tests/ignored_tests.txt` and every per-suite
`ignored_tests.txt`:

- `RegisterClassTest4` → `from_gnash/_investigation/ACCEPTED_DIFFS.md:231` + `:772` **and**
  `from_gnash/misc-ming.all/ignored_tests.txt:36`.
- `DrawingApiTest` → `avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md:203` (the `getBounds`
  stroke-expansion entry; per s19 it is already reflected in the 81/93 and explains why our diff set
  is disjoint from Ruffle's — it is not itself a blocker).
- The other nine rows: **no entry anywhere.** Their `KF` flags are upstream `known_failure`, i.e.
  Ruffle fails them too (rule 3): the reachable target is `ruffle_matched`, every fix must aim at
  Flash's `output.txt`, and **no `pass → ruffle_matched` move is proposed anywhere in this report.**

### Structural promotion facts (why "partial credit" does not exist here)

| Row | `test.toml` | Sidecar | Consequence |
|---|---|---|---|
| `action_execution_order_test11` | `num_frames = 30` only | **none** | all-or-nothing: 31/32 scores exactly what 26/32 scores |
| `PlaceAndRemove` | `known_failure.panic = "Gotos must start from the correct tag position for frame 1"`, subtests fp9/fp10 | **no `output.ruffle.txt`** | `ruffle_matched` structurally unavailable; only exact 96-line Flash parity scores |
| `ActionOrderTest3/4/5`, `_test6` | `known_failure = true` | `output.ruffle.txt` present | `ruffle_matched` reachable *in principle*, but s17 §7 showed our diff-index sets are **not subsets** of Ruffle's on any of the four (Ruffle's T3/T4 diffs are a pure 40-line tail; ours start at line 4) |
| `_extend_test` | `known_failure = true`, fp9/fp10 subtests | `output.fp{9,10}.ruffle.txt` | subset promotion needs **both** B1 and B2 |

---

## 3. Mechanisms, in runtime-code terms (bucket by owner, not by symptom)

### B1 — the frame pipeline runs phases globally; Flash/Ruffle interleave per clip
Our tick is: *(1)* advance sprite frames → *(2)* flush enterFrame → *(4)* advance deferred nested
sprites, with a presync hack so phase 2 can observe phase 4's `_currentframe`. Flash runs, per clip
in reverse-instantiation order, `{enterFrame; advance; that clip's own DoAction}` adjacently.
- `SWFModernRuntime/src/libswf/tag.c::advance_sprite_frames` / `advance_nested_sprite_frames`
  (`g_advance_defer_nested`), the just-placed guard (`placed_at_tick == g_tick_count`).
- `tag.c::dispatch_enterframe_clip_actions` + the `ClipEFRebaseFrame` flat gather.
- `tagFlushPendingEnterFrame` — its **call site is emitted by the recompiler** between each frame's
  Place/Remove tags and the script drain (`RecompiledTags/tagMain.c`, every `frame_N`); moving it is
  a `SWFRecomp/src/` change that invalidates every `Recompiled*` cache in the corpus.
- `presync_nested_sprite_currentframe` (`swf.c:937`, `swf_core.c:1073/:1197`) exists **only** to
  paper over the phase split; memory `nested-cf-presync`.
- Ruffle authority: `core/src/avm1/runtime.rs:489-525` (`clip_exec_list`, LIFO head-push, forward
  traversal in `Avm1::run_frame`).
Symptom fingerprint: `test11`'s `doActionOrder` `0+2+1+…` vs `0+1+2+…` and the two-line
`mc21 onLoad` ↔ `mc1 onEnterFrame` swap.

### B2 — `onLoad`/`onUnload` as *methods* never dispatch for plain timeline-placed sprites
`actionDispatchMCOnLoad` (`action.c:~31885`) is reached only via `aq_dispatch_mc_onload`
(attachMovie / createEmptyMovieClip) and `actionDispatchRootOnLoad`. A sprite placed by a
PlaceObject tag is never queued through `actionQueueMCOnLoad`, so `mc_red.onLoad = f` is silent.
`onEnterFrame` methods are unaffected (separate path, `actionDispatchEnterFrameHandlers`).
The gate that would have to widen is `tag.c:772-788`, i.e. the landed `test12` fix.

### B3 — cancellation model is inverted in **both** directions
`SWFModernRuntime/src/actionmodern/action_queue.c:151-160` (`aq_drain`): entries queued during
catch-up (`queued_in_catchup=1`) are dropped when the clip is `avm1_removed`/`pending_removal` at
drain time; `tag.c:2770-2787` documents the paired `goto_commands` aggregation that `RegisterClassTest3`
depends on.
- `action_execution_order_test6` wants those events **to fire** (Flash fires all placements'
  CONSTRUCT+LOAD even when a later tag in the same goto sweep removes the clip). At HEAD the LOAD
  half already fires; only the three cycle-1 **CONSTRUCT** events are still dropped.
- `PlaceAndRemove` wants the opposite: a Place and its Remove **inside one frame's tag list** must
  suppress both CONSTRUCT and the sprite's DoAction. We fire them — hence `moo N` and
  `FAILED: This MovieClip should never be constructed` on every cycle.
A single predicate cannot serve both; the discriminator is *same-frame pair* vs *same-goto-sweep
pair*, which is per-entry state the queue does not carry.

### B4 — a sprite's loop-back does not free the depth or fire UNLOAD with identity preserved
`blocked/INTER_TAG_UNLOAD_PLAN.md` + `blocked/SPRITE_REWIND_IDENTITY_PLAN.md`. Downstream of it,
`tag.c:9390-9412` refuses a PlaceObject onto an occupied depth and prints the *graded*
`Warning: Failed to place object at depth N.` line (that print is deliberate Ruffle `avm_warning`
parity — `avm1/placeobject_occupied_depth` expects two of them — so it is **not** stray debug output).

### B5 — `removeMovieClip` is not deferred, and removed clips stay live in script context
`movieclip_destruction_test3`: the sprite's own frame script calls `removeMovieClip`; we abort the
rest of that frame script, so `_root.x = 300` and two `as_order` appends never happen
(`as_order` `0+` vs `0+1+2+`), `getDepth()` returns `10` instead of the biased `-32779`, and
`typeof(nestedMovieClip)` stays `movieclip`. `_test4` is the same plus missing sprite-frame DoAction
traces on dynamic clones during a `gotoAndPlay` + `removeMovieClip` sequence.

---

## 4. New evidence I added (this is the part prior reports do not have)

### 4.1 Line-class histograms sharpen — and then break — s17's "double onEnterFrame" sub-signature

s17 §7 recorded, without numbers, that "we emit roughly twice the expected `onEnterFrame` count" on
`ActionOrderTest3/4/5` and called it "the cheapest single thread to pull". Measured at HEAD
(`<scratchpad>/w1-gnash-actionorder`, histogram of normalised line classes over the aligned diff):

| Row | `onEnterFrame` expected → ours | other headline class deltas |
|---|---|---|
| `ActionOrderTest3` | **7 → 17** | `static unload: undefined` **1 → 12**; `Warning: Failed to place object at depth 1.` **0 → 10**; `ctor: N` 4 → 2; `dynamic load: N` **4 → 0** |
| `ActionOrderTest4` | **6 → 16** | `ctor: N` 4 → **7**; `dynamic load: N` 4 → **7**; `dynamic unload: N` 3 → **7**; `static load: undefined` 1 → **8**; **zero** place warnings |
| `ActionOrderTest5` | **6 → 16** | `ctor: N` 3 → 2; `dynamic load: N` 3 → 2; no runaway tail (58 lines total) |

All three fixtures are `num_frames = 30`, so ~16 dispatches is *not* "one per tick"; the handler
outlives its expected lifetime by roughly 10 extra cycles on each. But the **signs differ**:

- T3 **under-places**: depth 1 is never freed, the next cycle's PlaceObject is refused ten times, so
  `ctor:` and `dynamic load:` events for cycles 2+ never happen and the stale clip's static unload
  handler fires 12× with `undefined` (its variables are already gone).
- T4 **over-cycles**: no refusals at all; we construct/load/unload *more* times than Flash.

**This refutes the "one thread to pull" framing inside the bucket.** T3 and T4 are the same plan's
targets but opposite failure signs, which is precisely why three implementation attempts each bought
only +1/+2 lines: a change that frees the depth helps T3 and worsens T4, and vice versa. Anyone
re-opening B4 should treat "the depth is still occupied at loop-back" (T3) and "the loop-back
re-runs a cycle Flash does not" (T4) as two sub-mechanisms and fix them under one identity model,
not as one ordering knob.

### 4.2 s19's `g_scope_app_context` lead **landed**, and this family did not move
s19 §8.1 found that a local set inside a constructor running before any function call was silently
dropped (`setVariableOnLocalScope` passing a NULL `g_scope_app_context`), affecting exactly
`_test6`, `_test11` and `PlaceAndRemove`, priced **0 flips**, with the note *"it should be fixed
before anyone re-prices that family"*. It was fixed in **`3cce6a1f7` (2026-09-11)**
(`action.c:42579`, `if (g_scope_app_context == NULL) g_scope_app_context = app_context;`), which is
an **ancestor of the s20 baseline `2973513c4`**. So the precondition s19 attached to re-pricing this
family is satisfied, this report *is* that re-price, and the answer is still **0**. The 0-flip price
on that lead was correct; close it.

### 4.3 `_extend_test` requires reproducing a Flash-side assertion **failure** — priced, spelled out
Captured actual (`--save-actual`, 28 lines) against `output.fp10.txt` (32 lines), assertion by
assertion — this is the concrete form of s17's "y5/y2 assertion inversions" note:

| assert | Flash (`output.fp10.txt`) | ours | owner |
|---|---|---|---|
| `_root.x1` | PASSED | PASSED | — |
| `…c:165` (`x2`) | PASSED `as_in_root` | **FAILED**, got `as_in_mc_blu` | B1 (ordering) |
| `_root.y1` | PASSED `mc_red onLoad called` | **FAILED**, got empty | B2 (method `onLoad` never fires) |
| `y1bis`, `y2`, `y3`, `y4` | PASSED | PASSED | — |
| `…c:182` (`y5`) | **FAILED** — Flash itself obtains `mc_blu onEnterFrame called` | **PASSED** `as_in_root` | B1, *inverted* |
| `_root.y6` | PASSED `mc_blu onUnload called` | **FAILED**, got `as_in_root` | B2 (method `onUnload` never fires) |
| tally | `#passed: 13 / #failed: 1` | `#passed: 11 / #failed: 3` | |

The `y5` row is the one worth recording: **to match `output.txt` we must make an assertion that
currently passes start failing, with Flash's exact wrong value.** Any wave-2 agent who "fixes" the
ordering in the obvious direction will make `y5` *more* right and the row *less* matched. That, plus
the missing trace lines `mc_red load executed` / `mc_blu user-defined UNLOAD executed`, is why B2
alone cannot promote the row even if the fire/no-fire rule were pinned.

---

## 5. `DrawingApiTest` — dropped from this family (the brief invited this)

It shares no mechanism with any bucket above. 81/93 match, 95 actual; our 14 differing indices are
**completely disjoint** from Ruffle's 14, so all 14 must land for `ruffle_matched` (s19 N5). Of those,
12 are `hitTest`-on-drawn-shape precision (`incomplete/DRAWING_API_HITTEST_PLAN.md`, 3 phases) and 2
are a separate `delete` bug. **HOLD stands; priced 0; completion mechanism = the hitTest plan's three
phases *plus* the delete bug, together.** Drop it from any "action-order" framing.

---

## 6. New unclaimed leads

1. **`delete this.onEnterFrame` returns `false` on a MovieClip** (carried from s19 builtins §7 lead 3,
   still unowned at HEAD; I narrowed it but did not close it). Evidence assembled this session:
   - There is **no** special storage for MC event handlers: every read site in `action.c`
     (`:38160`, `:38221`, `:38297`, `:38349`) goes through plain `dynamic_props` / the global var map.
   - `actionDelete`'s MOVIECLIP arm (`action.c:54310-54333`) calls
     `deleteProperty(app_context, (ASObject*)mc->dynamic_props, …)` and returns its bool;
     `deleteProperty` (`object.c:1170`) returns `false` on exactly two conditions — *property not
     found*, or *`PROPERTY_FLAG_CONFIGURABLE` clear*.
   - In the fixture the handler is installed by `a.onEnterFrame = function(){…}`
     (`DrawingApiTest/RecompiledScripts/script_1.c:4200-4208`: GetVariable `"a"` → SetMember) and
     deleted from inside that same handler by GetVariable `"this"` → Delete
     (`script_defs.c:938-946`, inside `func_anonymous_6`).
   - So the bug is a **target mismatch between SetMember's write and Delete's read**, or a missing
     `CONFIGURABLE` flag on the SetMember write. One `gdb` break on `deleteProperty` with this test
     pins which. **Still 0 flips alone** — the 12 hitTest lines dominate the row — so take it only as
     a correctness item (the `delete this.onEnterFrame; this.nextFrame()` idiom is a real preloader
     pattern; see the comment at `action.c:34440`).
2. **Doc hygiene that a closeout agent can fix for free** (three stale statements a future session
   would otherwise re-derive from):
   - `incomplete/ACTION_EXECUTION_ORDER_TEST6_PLAN.md:57` still says the LOAD entries are filtered
     out. They are not — the LOADs fire at HEAD (s17 board edit #5 was never applied; my run
     re-confirms). Only the cycle-1 CONSTRUCTs remain.
   - `blocked/INTER_TAG_UNLOAD_PLAN.md`'s baselines (`ActionOrderTest3` 6/62) predate today's
     **4/62**; its RCT4-veto note is also superseded by the disposition.
   - `blocked/ACTION_EXECUTION_ORDER_EXTEND_PLAN.md` describes the promotion path without the `y5`
     inversion (§4.3): its "insert the four missing lines in the right positions" recipe is
     necessary but not sufficient, because one currently-passing assertion has to start failing.
   - `incomplete/SPRITE_EXEC_LIST_LIFO_PLAN.md` already carries an s14 correction header; its
     `<!-- TESTS: -->` list is still fine.
3. **A graded `printf` is load-bearing.** `Warning: Failed to place object at depth %zu.`
   (`tag.c:9410`, `:9843`, `:10271`) goes to **stdout and is graded as trace output** — intentionally
   (Ruffle `avm_warning` parity, `avm1/placeobject_occupied_depth` expects it). Recording it here
   because it reads like stray debug output in a diff and one future agent will try to delete it: do
   not. Its presence is also the cheapest *signal* that a depth was not freed (§4.1).

---

## 7. What I did not do

- I did not re-derive s17 §7's subset analysis (why `ruffle_matched` is unreachable for
  `ActionOrderTest3/4/5` and `_test6`); I re-checked the sidecar/`test.toml` facts it rests on and
  they hold.
- I did not attempt any fix, A/B or instrumented build (wave-1 is read-only, and every candidate fix
  in this family has a named revert history).
- I ran no full suite: **14 single-test runs** (the 11 board rows with `--diff --verbose`, plus three
  `--save-actual` re-runs to count short outputs), sequential, one job at a time, never more than one
  `verify_output.py` process alive.
- I did not re-run in `--mode=graphics`: mode parity is complete (common brief §baseline) and every
  row here is a trace/ordering row with no render dependency. If a future agent disputes a number,
  the graphics re-run is ~2 min per row.
