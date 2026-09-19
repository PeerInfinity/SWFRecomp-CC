# Session 20 · wave 2 · `w2-goto-framescript` — the `goto_framescript_queued` family

## NEW FILES (stage these BY NAME — `git add -u` drops them)

```
SWFRecompDocs/plans/session20-fanout-reports/w2-goto-framescript-report.md
SWFRecompDocs/plans/session20-fanout-reports/w2-goto-framescript-1-queued-goto-carries-stopplay.patch
SWFRecompDocs/plans/session20-fanout-reports/w2-goto-framescript-2-isplaying-swf13-gate.patch
```

Modified files (covered by `git add -u`):

```
SWFModernRuntime/include/avm2/avm2_globals.h      (+4 / -0)
SWFModernRuntime/src/avm2/avm2_display.c          (+51 / -24)
```

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-accf333fd43661d66`
(branched from `574207007`). Scratch + all logs: `<scratchpad>/w2-goto-framescript/`.

---

## 0. HEADLINE — **GO, +4 effective realised, 0 regressions**

| test | baseline | after | oracle targeted | why that oracle |
|---|---|---|---|---|
| `avm2/goto_framescript_queued_same_frame` | `output_mismatch` 3/4 | **`pass`** | `output.txt` | no `known_failure`, no `output.ruffle.txt` — Flash and Ruffle agree |
| `avm2/goto_framescript_queued/swf9` | `output_mismatch` 11/52 | **`pass`** | `output.txt` | `known_failure` was DROPPED by `7e8e2de8a`; no `output.ruffle.txt` exists |
| `avm2/goto_framescript_queued/swf10` | `output_mismatch` 15/59 | **`pass`** | `output.txt` | same — `known_failure` dropped by `7e8e2de8a` |
| `avm2/goto_framescript_queued/swf13` | `output_mismatch` 17/59 | **`ruffle_matched`** | `output.txt` targeted, `output.ruffle.txt` reached | still `known_failure` upstream; see §3 — the residual is a **third** mechanism Ruffle has not fixed either |

**+4 effective** (3 → `pass`, 1 → `ruffle_matched`; all four were 0 effective in the baseline).
Not one of these is a `pass → ruffle_matched` move, so standing rule 3 is not tripped: every
row strictly gained. `swf13` is the one row that stops at `ruffle_matched`, and §3 prices the
remaining 3 lines honestly — **0 further effective points, HIGH blast radius, NO-GO**.

Sibling's price of **+4 effective for ~25 LOC in one file** is **CONFIRMED** (actual: 27 added
lines of logic in `avm2_display.c` + 4 of comment/field in `avm2_globals.h`). Both mechanism
locations were correct to the line. Two of the sibling's sub-claims are refuted (§5).

---

## 1. Premises attacked — what held and what did not

I re-derived both mechanisms from `~/CC/ruffle` at `f2aaf0703` before touching anything, and
measured all four baselines locally rather than trusting the board.

* **M2 location — HELD exactly.** `avm2_display.c::mc_goto_frame` (line 3248 pre-patch) had
  `if (stop) ext->playing = 0; else ext->playing = 1;` above the `executing_frame_script`
  branch. Upstream `7e8e2de8a` ("avm2: Queue play/stop action alongside the frame for queued
  gotos") moves exactly that `match goto_info.stop_or_play` out of `goto_frame` and into
  `goto_frame_now`, and widens `queued_goto_frame: Option<FrameNumber>` to
  `queued_goto: Option<GotoInfo>`. Our runtime is a faithful port of the *pre*-fix code.
* **M1 location — HELD exactly.** `avm2_display.c:17134` registered the `isPlaying` getter
  unconditionally; `avm2_globals.c:3676` already carries `min_swf = 13` for it, but that field
  is **describe-only by design** (its own comment says so: *"no graded test calls a gated member
  on an under-versioned SWF"*). `goto_framescript_queued/swf9` and `/swf10` are now exactly that
  test, so the comment's premise has expired.
* **M2 is the whole tail — HELD.** Measured: `swf13`'s divergence starts at line 4 and the
  ~40-line `! exitFrame` / `! frameConstructed` run after line 11 is one stall, not 40 leads.
  With M2 alone, `swf13` went 17/59 → 59/59-against-Ruffle in one step.
* **Sibling §2.4 ("the SWF≤9 queued arm skips `inner_goto_frame`") — REFUTED.** See §5.1.
* **Sibling's "`swf9` is the lowest-confidence of the four" — REFUTED.** `swf9` passes on
  M2+M1 with no third rule; it was the *cheapest* of the four, not the riskiest (§5.1).

---

## 2. Mechanisms and exact patch scope

### Patch 1 — `w2-goto-framescript-1-queued-goto-carries-stopplay.patch` (M2)

Port of upstream `7e8e2de8a`. Three edits, all inside my two declared ranges:

1. **`SWFModernRuntime/include/avm2/avm2_globals.h`** (+4, at `Avm2DisplayObjectExt`): new
   `uint8_t queued_goto_stop` beside the existing `int32_t queued_goto_frame` — the
   `stop_or_play` half of Ruffle's `GotoInfo`. Appended next to its partner field, so no
   struct-layout surprise for unrelated code.
2. **`avm2_display.c`, new `static mc_goto_frame_now()`** placed immediately above
   `run_local_frame_scripts` (line ~2554, i.e. *before* the flush site that needs it, and far
   from both sibling owners). It is Ruffle's `goto_frame_now`: apply `playing`, then
   `run_goto` for a real goto or the inlined `no_op_goto` (clear the queue,
   `avm2_display_inner_goto_frame`, `skip_next_enter_frame` for SWF≤9) for a same-frame goto.
   This **de-duplicates three copies** of that same body that existed at the flush site and in
   both arms of `mc_goto_frame`.
3. **`avm2_display.c`, flush site (~2588) and `mc_goto_frame` (~3236)** now both call it;
   `mc_goto_frame` stores `queued_goto_stop` alongside `queued_goto_frame`, and its SWF≤9
   same-frame arm calls `mc_goto_frame_now` (Ruffle MC:913 post-fix) instead of hand-rolling
   half of it. Init added at `display_native_init` (~13646).

**One behavioural change beyond the literal upstream diff, called out explicitly:** the old
flush site's no-op arm did **not** set `skip_next_enter_frame` for SWF≤9, while
`mc_goto_frame`'s own no-op arm did. Unifying on `mc_goto_frame_now` makes both match
`run_inner_goto_frame`'s SWF≤9 early return (`frame_lifecycle.rs:129`), which is what **both
pre- and post-fix** Ruffle do. It is covered by the sweep (§4: `swf_9_goto_in_construct_frame`,
`swf_9_goto_in_enter_frame`, `goto_methods_swfver10`, `all_classes/display/swf9`).

### Patch 2 — `w2-goto-framescript-2-isplaying-swf13-gate.patch` (M1)

One hunk, `avm2_display.c:17134`: wrap the `isPlaying` getter registration in
`if (ctx->swf_version >= 13)`. Below SWF13 the member does not exist, so the shared fixture's
unqualified `isPlaying` raises a `ReferenceError` (an `Error` subclass) out of `findpropstrict`,
and the fixture's own `catch (e:Error)` prints the short `frame: N` form that `swf9`/`swf10`
expect. Version data taken from `avm2_globals.c`'s `dtd_m_MovieClip` (`min_swf` 13) rather than
invented; memory `version-gate-new-api-surface`.

The two patches are **independent and ordered**: patch 1 alone gives `same_frame` → `pass` and
`swf13` → `ruffle_matched`; patch 2 alone gives nothing (it needs M2's timeline behaviour to
make `swf9`/`swf10`'s `frame:` values right). Applied in order they reproduce my worktree
exactly — verified with `git apply --reverse --check` on the concatenation (rc=0).

---

## 3. `swf13`'s residual 3 lines — **NO-GO**, and the mechanism is named

`swf13` is `known_failure = true` upstream and **stays that way**: `7e8e2de8a` fixed only half
of it. `diff output.txt output.ruffle.txt` is exactly 3 lines:

| line | Flash (`output.txt`) | Ruffle (`output.ruffle.txt`) = ours now |
|---|---|---|
| 4 | `frame: 1, isPlaying: false` | `frame: 1, isPlaying: true` |
| 16 | `frame: 4, isPlaying: true` | `frame: 4, isPlaying: false` |
| 59 | `frame: 11, isPlaying: true` | `frame: 11, isPlaying: false` |

I did **not** fix toward Ruffle's output; I ported the mechanism and landed on it. Our
`isPlaying` is `programmatically_played && playing` and our `gotoAndPlay` sets
`programmatically_played` before `mc_goto_frame` — both are line-for-line what Ruffle does
(`movie_clip.rs:324`, `movie_clip.rs:360`). The residual is therefore upstream's, not a
short-cut of mine.

**I reverse-engineered the Flash rule from all 59 lines plus `same_frame`.** Two rules, and only
both together, fit every observation:

* **(A)** `set_programmatically_played()` must be deferred *with* the queued play (Ruffle and we
  both apply it at `gotoAndPlay` call time). Fixes line 4.
* **(B)** a **deferred stop halts the playhead but does not clear the `isPlaying` observable**.
  Fixes lines 16 and 59.

(B) is load-bearing and is what makes this expensive. Proof the playhead really does stop (i.e.
(B) is not just "drop the queued stop"): `swf13` uses only **4** of its `num_ticks = 20` — I
counted outer ticks from the `! frameConstructed` / `! exitFrame` nesting (tick 3 alone nests
four inner gotos and emits five `! exitFrame`, lines 47-51). Sixteen ticks remain after line 59,
and frame 12's unconditional `trace("We should not be here!")` never appears. So the clip *is*
stopped at frame 11 while `isPlaying` reports `true`. Implementing (B) means splitting
`ext->playing` into an *advance* flag and a *reported* flag across every reader in
`avm2_display.c`.

**Verdict: NO-GO.** Completion mechanism is named above ((A) + (B), the `playing` split).
Price: **0 effective points** — `ruffle_matched` already counts as an effective pass — against a
high-blast-radius change to the hottest AVM2 timeline flag. Worse, **(A) without (B) is a net
loss**: it would flip line 4 away from Ruffle without reaching Flash, dropping the row from
`ruffle_matched` back to `output_mismatch`. Both or neither.

This belongs in `avm2/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`-adjacent territory but I
did not file it, because we currently match *Ruffle*, not Flash — it is a live (if unprofitable)
lead, not an accepted diff. Left for the coordinator to place.

---

## 4. Regression sweep — **43 tests, 0 deltas**

Method: `SWFRECOMP_COMPILE_TIMEOUT=2400`, strictly sequential (`-P 1` equivalent), `--verbose
--diff --recompile`, no-graphics (mode parity is complete per the common brief), test dirs
`cp -r`'d into my worktree's canonical suite paths — **never `--tests-dir` at the main tree**.
No `git stash` was used anywhere; the A/B for the patch split is `diff -u` + `git apply -R`.

**On actual-output diffing (memory `local-regression-sweep-stash-diff`):** every test in the
sweep set is an *exact-match* status in the baseline — 42 `pass` (byte-identical to
`output.txt`) and 1 `ruffle_matched` (byte-identical to `output.ruffle.txt`). For such rows,
status identity **is** output identity, so a second "before" leg would have burned ~40 minutes
of shared machine to re-derive what the baseline already pins. I deliberately included no
`output_mismatch` row, where that shortcut would be invalid.

Selection (everything that gotos, plays, stops, or reads `isPlaying`, plus the SWF≤9 arm and the
describe path M1 touches):

* **avm2, 37**: `goto_button_nested_framescript`, `goto_in_constructframe`,
  `goto_in_scene_last_frame`, `goto_methods`, `goto_methods_swfver10`,
  `goto_nested_construct_sibling`, `goto_nested_framescript`, `goto_on_orphan`,
  `movieclip_goto_during_frame_script`, `movieclip_goto_overwrite`,
  `movieclip_goto_scene_last_frame_int`, `movieclip_goto_scene_last_frame_label`,
  `movieclip_gotoandplay`, `movieclip_gotoandstop`, `movieclip_gotoandstop_children`,
  `movieclip_gotoandstop_framescripts{1,2,_self}`, **`movieclip_gotoandstop_queueing`**,
  `movieclip_next_frame`, `movieclip_prev_frame`,
  `movieclip_displayevents_{constructframegoto,enterframegoto,exitframegoto,stopped}`,
  `movieclip_properties`, `movieclip_constr`, `movieclip_frameconstruct_skipped`,
  `orphan_removeobject`, `orphan_movie_complex`, **`versioned_isplaying`**,
  **`swf_9_goto_in_construct_frame`**, **`swf_9_goto_in_enter_frame`**,
  `all_classes/display/{swf9,swf12,swf13}`, `instantiation_on_enterframe_gotoandstop`.
* **regression suite, 6** (`--tests-dir=ruffle-tests/tests/swfs/regression`):
  `avm2_goto_catchup_scale`, `avm2_timeline_solid`, `avm2_timeline_text`,
  `avm2_child_simplebutton`, `avm2_agi_shell`, `root_enterframe_cross_swf_version`.

**Result: 42 `PASS` + 1 `RUFFLE_MATCHED` — identical to the graded baseline, row for row.**
The two rows that most directly probe the changed semantics, `movieclip_gotoandstop_queueing`
and `movieclip_goto_overwrite`, both still pass. `versioned_isplaying` (SWF **12**, defines its
own non-override `isPlaying` getter) still passes with the builtin gone below 13 — it resolves
as a plain class trait. `all_classes/display/swf9` and `swf12` still pass, confirming the
describe path was already hiding the member via `min_swf` and does not need the vtable entry.
Logs: `<scratchpad>/w2-goto-framescript/sweep_after/`.

Relevant standing memories re-checked and unbroken: `avm2-timeline-rewind-survives`,
`sprite-current-frame-is-next-not-displayed`, `manual-nav-must-sync-mc-currentframe`,
`avm2-goto-catchup-walk-gate` (the sweep's `avm2_goto_catchup_scale` covers the last).

### Per-test before/after, headline rows

```
goto_framescript_queued_same_frame   MISMATCH 3/4  ->  PASS
goto_framescript_queued/swf9         MISMATCH 11/52 -> PASS
goto_framescript_queued/swf10        MISMATCH 15/59 -> PASS
goto_framescript_queued/swf13        MISMATCH 17/59 -> RUFFLE_MATCHED (59/59 vs Ruffle)
```

Baseline diffs (measured locally, not copied from the board):

```
same_frame:  -  4  isPlaying: true          swf13:  -  4  frame: 1, isPlaying: false
             +  4  isPlaying: false                 +  4  frame: 1, isPlaying: true
                                                    -  8  frame: 2, isPlaying: true
swf10:       -  2  frame: 1                         +  8  frame: 2, isPlaying: false
             +  2  frame: 1, isPlaying: false    (then a ~40-line stall — one bug)
```

---

## 5. Refutations

### 5.1 The SWF≤9 arm does **not** "skip `inner_goto_frame`" — and `swf9` was the easiest row

The sibling's §2.4 says our `swf_version <= 9` queued arm *"returns without the `no_op_goto` /
`avm2_display_inner_goto_frame` that both pre- and post-fix Ruffle run there"*, and prices
`swf9` at medium-**low** confidence needing a third rule.

`avm2_display_inner_goto_frame` (`avm2_display.c:2707`) opens with
`if (ctx->swf_version <= 9) return;  // caller sets skip_next_enter_frame instead` — which is
precisely `run_inner_goto_frame`'s own SWF≤9 early return (`frame_lifecycle.rs:129-134`). So the
old arm's `queued_goto_frame = -1; skip_next_enter_frame = 1; return;` **was** `no_op_goto` for
SWF≤9, exactly, and matched pre-fix Ruffle. Nothing was skipped.

Confirmed empirically twice: (a) the baseline `swf9` diff is clean through line 11 — the
`! frameConstructed` placement the sibling worried about was **already right**, the only
divergence being the long-vs-short `isPlaying` form; (b) `swf9` reaches `pass` on M2+M1 with no
third rule, and was the *last* row to need any thought, not the first.

### 5.2 "~25 LOC in ONE file" — it is two files

Minor, but it matters at merge: M2 needs a field on `Avm2DisplayObjectExt`, which lives in
`SWFModernRuntime/include/avm2/avm2_globals.h`, not `avm2_display.c`. The header is not claimed
by `w2-evenodd` or `w2-gfx-text-smalls`, so there is still no collision — but the coordinator
should stage the header too.

### 5.3 Sibling §1.4(a) undercounts the stale local files — and one of them is a trap

The report says *four* stale files at `ruffle-tests/tests/swfs/avm2/goto_framescript_queued/`.
There are **five**: `test.swf`, `test.toml`, `output.txt`, `output.ruffle.txt` and **`test.fla`**
(4 922 bytes). All are untracked (`git ls-files` returns nothing) and absent from CI.

**Recommendation: delete all five.** Two concrete hazards, both live today:
1. The dir is discoverable locally as the test `goto_framescript_queued`, whose `test.toml`
   still says `known_failure = true` and whose `output.txt` is the **6-line pre-restructure**
   expectation upstream deleted in `d5b707265`. A future agent running that bare name gets a
   verdict on a test that does not exist.
2. Its `output.txt` sits in the *parent* of `swf9`/`swf10`/`swf13`, so a `grep -r` for the
   family's expected lines returns the obsolete file first.

I deleted nothing outside my worktree. This is main-tree housekeeping, not a patch.

### 5.4 The inert ignore entry can now simply be pruned

`ruffle-tests/tests/swfs/avm2/ignored_tests.txt:184` is `goto_framescript_queued`, filed under
"Upstream `known_failure` = true". The sibling proposed narrowing it to
`goto_framescript_queued/swf13`. With this patch that is no longer the right move either:
**all four rows are effective passes**, so there is nothing for the entry to hide and the file's
own criterion (prune when the status is not `ruffle_matched`… and keep `ruffle_matched`) is
ambiguous for a `known_failure`-bucket row that we now `ruffle_match`. My read: **prune line 184
outright** — `swf13`'s `ruffle_matched` is a legitimate, visible result and the filtered avm2
report should show it. Unlike the corpus files this one **is git-tracked**, so I left it alone
rather than conflict with whoever else is editing ignore lists this session.

---

## 6. NEW UNCLAIMED LEADS

1. **Flash's `isPlaying` survives a deferred stop (§3).** Rules (A)+(B) above, fully derived from
   `swf13`'s 59 lines. 0 effective points, high blast radius — filed so session 21 does not
   re-derive it. If anyone *does* take it, take both rules or neither.
2. **`min_swf` in `avm2_globals.c`'s describe tables is now under-used.** Its comment
   ("DESCRIBE-ONLY by design … no graded test calls a gated member on an under-versioned SWF")
   is now false — `goto_framescript_queued/swf{9,10}` is exactly that test, and M1 had to hand-
   duplicate the version number in `avm2_display.c`. A systematic pass that drives *registration*
   off the same table would (a) de-duplicate M1, (b) plausibly fix other under-versioned-member
   tests, and (c) risk turning passing negative tests red — see memory
   `version-gate-new-api-surface`. Worth one wave-1 slot to *size* (how many table rows have
   `min_swf > 0` and a real vtable entry?) before anyone implements it.
3. **`mc_goto_frame_now` now exists and is the single AVM2 goto entry point.** Three copies of
   the no-op-goto body collapsed into one. Any future AVM2 goto work (e.g. the
   `avm2-goto-catchup-walk-gate` arc) has one place to edit instead of three.
4. **`download_tests.sh --prune` (sibling §7.6, seconded).** This is now the third stale-dir
   sighting in three sessions and §5.3 shows the count in the sibling's report was already low
   by one. The fix is a mode that removes only test dirs absent from the fresh sparse checkout,
   leaving `_investigation/` and `_results/` alone.

---

## 7. FILES TOUCHED

```
SWFModernRuntime/include/avm2/avm2_globals.h                                    (patch 1)
SWFModernRuntime/src/avm2/avm2_display.c                                        (patches 1 + 2)
SWFRecompDocs/plans/session20-fanout-reports/w2-goto-framescript-report.md       (new)
SWFRecompDocs/plans/session20-fanout-reports/w2-goto-framescript-1-*.patch       (new)
SWFRecompDocs/plans/session20-fanout-reports/w2-goto-framescript-2-*.patch       (new)
```

No commits, no pushes. Test dirs copied under `ruffle-tests/tests/swfs/{avm2,regression}/` in the
worktree are untracked corpus mirrors and must not be staged. Sibling ranges
(`gfx_finalize_path` ~8695, `gfx_line_style` ~9212, `avm2_render_textbox` ~18630-18665) were not
touched; no message to the coordinator was needed.
