# w2-avm2-timeline — session 18 wave 2 (AVM2 timeline pair)

Worktree `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a2b2b8a98f1bdeb74`,
base `8f68a5fea`. Runtime-only patch; the main tree's `SWFRecomp/build` was copied
(valid per the wave-2 rules). No commits, no pushes.

## NEW FILES (coordinator stages these by name)

* `SWFRecompDocs/plans/session18-fanout-reports/w2-avm2-timeline.patch`
* `SWFRecompDocs/plans/session18-fanout-reports/w2-avm2-timeline-report.md` (this file)

No new source files. **Files touched: `SWFModernRuntime/src/avm2/avm2_display.c` only**
(+100 / −18). No `.h`, no CMake/Emscripten/`verify_output.py` source-list change.

---

## 1. Verdicts

| lead | test | before | after | verdict |
|---|---|---|---|---|
| L1 | `timeline/frame_script_cleanup_goto2` | `output_mismatch` 12/34 | **`pass` 34/34** | **GO — +1 flip** |
| L2 | `avm2/orphan_removeobject` | `output_mismatch` 340/636 | **`pass` 636/636** | **GO — +1 flip** |
| rider | `timeline/missing_frame_scripts` | `output_mismatch` 12/22 | `output_mismatch` 12/22 | **no delta — L2 does NOT subsume S4 (refuted)** |

**Net: +2 trace flips, 0 regressions across an 80-test canary sweep.**
Both flips also verified under `--mode=graphics`.

Baseline of record for the "before" column: the merged no-graphics results at
`f0fd711c7` (`ruffle-tests/tests/swfs/<suite>/_results/results.json`, an ancestor of
HEAD), read fresh per suite — not copied from any brief.

---

## 2. What actually landed, and where the brief was wrong

The patch is four edits in `avm2_display.c`. **Neither of the two edits the brief
named as the fix is load-bearing.** Both leads were real; both mechanisms were
mis-stated.

### L1 — `frame_script_cleanup_goto2`: it is NOT the `mark_frame_work` line

The brief (from `w1-trace-display-report.md` §2 L1) says: `addFrameScript`'s
`PHASE_FRAME_SCRIPTS` arm pushes to the cleanup queue but never calls
`avm2_display_mark_frame_work`, so descendants stay `walk_clean` and the
`no_op_goto` walk skips them; "one line".

**Measured, at HEAD, with that one line added: no change at all.** Actual output
stayed 29 lines, 12/34, byte-identical to baseline. Instrumenting
`mc_add_frame_script` (`AVM2_GOTO_PROF=2`, temporary `[AFS]` print) showed why:
at the moment `Main.frame1` registers scripts on the four descendants they are
**already `wc=0` (dirty)**. There was nothing for the mark to clear. The print
also showed the real signature: `pend=0` on every one of them.

The actual mechanism is one level down, in **`node_quiescent`**
(`avm2_display.c:1562`), the predicate that decides whether the frame-script walk
may *certify* a subtree `walk_clean` on its way out:

* Ruffle arms `has_pending_script` **unconditionally** when a clip advances a
  frame (`run_frame_internal` → `set_has_pending_script(true)`).
* We arm it **lazily** — `check_has_pending_script`, called at the end of
  `construct_frame_obj` and only in `PHASE_CONSTRUCT`, and only if a script for
  the current frame *already exists*.
* So a clip whose script is registered **later in the same frame** (the whole
  point of this fixture: `Main.frame1` calls `addScripts()` on four already-visited
  descendants) sits at `has_pending_script == 0` while the very next
  `PHASE_CONSTRUCT` visit *would* arm it. `node_quiescent` read only
  `has_pending_script`, judged the node quiescent, and set `walk_clean = 1`.
* The outer walk therefore **re-cleaned the four descendants after** `Main.frame1`
  dirtied them, and `Container.frame1`'s `no_op_goto` — which runs from
  `run_frame_script_cleanup`, i.e. after that walk — found `dirty_kids == 0` on
  `Container` and skipped its whole subtree. Exactly the five lines
  `Child frame1 / GrandChild addFrameScript / GrandChild frame1 / LeafChild frame1 /
  GrandChild frame1`.

Fix: `node_quiescent` now ORs in the arming condition
(`frame_scripts[current_frame]` is an object), so it mirrors
`check_has_pending_script` instead of only its consequence. That single edit is
what flips the test — confirmed by A/B (below). It converges: once the script has
run, `last_queued_script_frame == queued_script_frame` and the node is quiescent
again, so no node is pinned dirty. `queued_script_frame` is written from
`current_frame` at both frame-change sites (`:2250`, `:3061`), so the two indices
never diverge.

`AVM2_NO_WALK_SKIP=1` passed the fixture because with the gate off,
`construct_frame_obj` visits every node and `check_has_pending_script` arms them
all — that is the same fact seen from the other side, not a different one.

### L2 — `orphan_removeobject`: the retain rule is necessary but NOT sufficient

The brief's rule is correct and was ported: Ruffle `cleanup_dead_orphans`
(`orphan_manager.rs:65-92`) retains an orphan only if it is still parentless **and**
`placed_by_avm2_script`. Ported into `orphan_cleanup` (`:220`).

That alone took the row from **340/636 to 603/636** — it removed the five extra
`Running child framescript` lines and stopped the `currentFrame` *climb* (was 3
then 4) — but **not a flip**: 33 lines still read `child.currentFrame = 3` where
Flash freezes the orphan at 2.

The residual was a second, unnamed divergence in the same phase.
`OrphanManager::each_orphan_obj` **clones the orphan list before iterating**, so a
clip that becomes an orphan *while a phase is running* is not visited until the
next frame. Our five orphan loops re-read the live count, so a clip orphaned
mid-phase (here: an orphan `MyChild`'s own `RemoveObject` tag orphaning its
`timelineGrandchild`, during the orphan Enter walk) got advanced **in the very
frame it was removed in**. Snapshotting the bound (`orphan_walk_bound()`, one
helper, five loops) is the other half; with both, the row is 636/636 `pass`.

### Amortisation kept (perf)

The brief allowed dropping the `g_orphan_reparented < 64` amortisation gate. I did
not: `orphan_cleanup` runs per **inner goto**, and `avm2-goto-catchup-walk-gate`
exists because Elephant Quest issues thousands of those per frame — an
unconditional O(orphans) scan there re-introduces the quadratic. Instead
`placed_by_avm2_script` is **monotonic** (0 → 1, never cleared: 12 write sites, all
`= 1`), so a retained entry can never turn dead on its own. The retain pass is
therefore needed only after a *non-script-placed* orphan was added
(`g_orphan_tag_pending`, incremented in `orphan_add`) or after re-parentings
accumulated. Steady-state cost per inner goto is unchanged.
`regression/avm2_goto_catchup_scale` (the O(n²) guard) still passes.

### The two edits that are guards, not flips

* `avm2_display_mark_frame_work` in `addFrameScript`'s `PHASE_FRAME_SCRIPTS` arm
  (the brief's L1 line). A/B leg `ab1` (patch minus this line):
  `frame_script_cleanup_goto2` still **PASS**. Kept anyway — `node_quiescent` only
  stops a node being *certified* clean; it cannot clear a `walk_clean` that was set
  before the registration, and that node would then be skipped by every later walk.
  The `else` arm already pairs the state change with this call.
* `run_frame_script_cleanup` drains with a real pop-front instead of a read index.
  Ruffle's queue is a `VecDeque`/`pop_front` and the drain is re-entrant:
  `run_inner_goto_frame` **clears** the queue (`g_fs_cleanup_count = 0`) and the
  inner walk then pushes fresh entries, which a read index already past the front
  silently discards. A/B leg `ab2` (patch minus this hunk):
  `frame_script_cleanup_goto2` still **PASS**, so this fixture does not exercise it.

Both are kept because **the 80-test canary sweep was run against exactly this
source**; dropping either now would deliver a patch that differs from the one that
was canaried. Each is individually removable if the coordinator prefers the
2-edit minimum.

---

## 3. Patch scope (exact)

`SWFModernRuntime/src/avm2/avm2_display.c`, five hunks:

1. `:125` + `:169` — new `static uint32_t g_orphan_tag_pending`, incremented in
   `orphan_add` when the arriving orphan is not `placed_by_avm2_script`.
2. `:137` / `:1511` — new `static uint32_t orphan_walk_bound(void)` (forward decl +
   definition next to `walk_skip_on`); the five orphan loops (`PHASE_ENTER` in
   `avm2_display_run_tick`, and the construct / frame-script pair in both
   `avm2_display_inner_goto_frame` and `avm2_display_run_tick`) snapshot it.
3. `:220` `orphan_cleanup` — Ruffle `cleanup_dead_orphans` retain rule
   (`parent == NULL && placed_by_avm2_script`), armed by `g_orphan_tag_pending` or
   the existing 64-reparenting gate, plus a second `orphan_dirty_compact()` so the
   dirty list cannot name a just-dropped entry.
4. `:1562` `node_quiescent` — `has_pending_script || would_arm`.
5. `:2615` `run_frame_script_cleanup` — pop-front drain.
6. `:8004` `mc_add_frame_script` — one `avm2_display_mark_frame_work` inside the
   `PHASE_FRAME_SCRIPTS` arm only.

**Sibling collision check:** `w2-avm2-new-smalls` also edits `mc_add_frame_script`
(a `#2001` argc check at the function ENTRY, before the `for` loop). My hunk is
inside the `PHASE_FRAME_SCRIPTS` arm of the loop body — no textual overlap.
Everything else I touch (`orphan_*`, `node_quiescent`, `run_frame_script_cleanup`)
is named by no other agent in `SIBLING_FILE_MAP.md`.

---

## 4. Canary ledger

80 canaries, no-graphics, `-P 2`, `SWFRECOMP_COMPILE_TIMEOUT=2400`, `--verbose
--diff --save-actual`. "before" = merged baseline `results.json` at `f0fd711c7`
(status + `matching_lines`); "after" = this worktree. For a row that passes on both
sides the outputs are byte-identical by construction (both equal `output.txt`);
failing rows are compared by positional matching-line count against the saved
actual.

Raw board: `<scratchpad>/w2-avm2-timeline/out/after/` (per-test `.log` + `.actual`),
comparison script `<scratchpad>/w2-avm2-timeline/compare.py`.

| group | tests | result |
|---|---|---|
| `timeline/*` (whole suite) | 17 | 14 unchanged, **+1 flip** (`frame_script_cleanup_goto2`), `missing_frame_scripts` unchanged 12/22, 3 `ruffle_matched` unchanged |
| `avm2/orphan_*`, `goto_on_orphan` | 4 | **+1 flip** (`orphan_removeobject`); `orphan_movie_complex` 80/80, `orphan_movie_reorder` 111/111, `goto_on_orphan` 15/15 all unchanged `pass` |
| `avm2/goto_*` | 8 | unchanged (7 `pass`, `goto_framescript_queued` `ruffle_matched` 1/6 — unchanged, no `pass → ruffle_matched` drift anywhere) |
| `avm2/movieclip_*` (goto / addFrameScript / displayevents) | 16 | unchanged (15 `pass`, `movieclip_addframescript_error` `output_mismatch` 0/9 before and after — it emits nothing in both legs, so no `.actual` is written) |
| `avm2/filter_rewind` | 1 | `pass` unchanged |
| `from_shumway/timeline/**` | 21 | all `pass`, all unchanged (incl. `scene/*` 7, `events/*` 2, `timeline_as2_*` 5, `timeline_loop`, `timeline_name_0`) |
| `regression` (AVM2 timeline + goto + child-timeline + button) | 15 | all `pass`, all unchanged — incl. **`avm2_goto_catchup_scale`** (the walk-gate O(n²) guard), `avm2_timeline_{solid,gradients,stroke_gradient,text}`, `avm2_parent_child_{render,static_text,symbol_stride}`, `enterframe_type1_args`, `avm2_simplebutton_click`, `avm2_static_text`, `avm1_child_timeline_{advance,frame1_stop,holder_stop,loop}` |

**Changed rows: 3.** Two are the intended flips. The third
(`movieclip_addframescript_error`) is `output_mismatch → output_mismatch`, flagged
only because my script could not read a matching-line count for an empty actual —
not a change.

**Graphics mode** (`--mode=graphics`, `DAWN_INSTALL=~/CC/dawn-install`):
`timeline/frame_script_cleanup_goto2` **PASS**, `avm2/orphan_removeobject` **PASS**,
`timeline/frame_script_cleanup` **PASS**, `avm2/orphan_movie_complex` **PASS** —
mode-consistent with no-graphics on all four.

**A/B legs** (single test each, `frame_script_cleanup_goto2`):
`ab1` = patch − `mark_frame_work` line → PASS; `ab2` = patch − pop-front drain →
PASS. Both confirm those two edits are guards, not the flip.

---

## 5. Refutations

1. **The brief's L1 patch is not the L1 fix.** `avm2_display_mark_frame_work` in
   the `PHASE_FRAME_SCRIPTS` arm changes nothing on this fixture: the four
   descendants are already dirty when the script is registered. The gate hole is in
   `node_quiescent`'s re-clean, which is a *different* half of the same gate and
   was not in the diagnosis. Anyone auditing the other "state changed but
   `walk_clean` not cleared" sites (`w1-trace-display-report.md` §6) should audit
   the **re-clean predicate** with the same energy — a mark that a later walk
   immediately undoes is worth nothing.
2. **`AVM2_NO_WALK_SKIP=1` passing does not localise the bug to a missing mark.**
   Turning the gate off also turns on `check_has_pending_script` for every node,
   because that call sits at the end of the gated `construct_frame_obj`. The env-var
   A/B says "the gate is involved", not "the gate is missing a mark". This cost a
   full build cycle here; note it for the free-triage-axis lead in §6 of the w1 report.
3. **L2 is two mechanisms, not one.** The named Ruffle rule
   (`cleanup_dead_orphans`) is worth 340 → 603 lines and **zero flips** on its own.
   The flip needs `each_orphan_obj`'s list *clone* as well. The w1 report's "one
   mechanism … ~10 lines" is half right.
4. **`missing_frame_scripts` is NOT subsumed by L2** (w1 §3 speculated it might be).
   Graded before and after: unchanged, 12/22, `Spawn` still loops and still reaches
   `Spawn stopped`. Instrumented `orphan_add`/`orphan_cleanup` (temporary
   `AVM2_ORPHAN_DEBUG` print, reverted) on this fixture: the **only** object that
   ever joins the orphan list in the whole run is `MyContainer`, with
   `placed_by_script=1` — i.e. correctly retained. `Spawn` **never becomes an orphan
   at all**, so no orphan-retention rule can reach it. S4 should be re-labelled: it
   is a main-timeline advance/removal defect (S3's family), not an orphan-phase one.
   Completion mechanism: find why the main timeline's `RemoveObject` for `Spawn`
   never runs — start at `determine_next_frame`'s `!has_end_tag` arm
   (`avm2_display.c:1934`), which S3 already names.
5. **Dropping the amortisation gate was not required** and would have been a
   regression risk on the goto-catchup path; the monotonicity of
   `placed_by_avm2_script` makes an armed-pass equivalent to Ruffle's per-frame
   retain at O(1) steady-state cost.

---

## 6. New unclaimed leads

* **The lazy `has_pending_script` arming is a latent divergence beyond this
  fixture.** Ruffle arms on every frame advance; we arm only if a script for that
  frame already exists, and only from `PHASE_CONSTRUCT`. `node_quiescent` now
  compensates for the *walk gate*, but any other consumer of
  `has_pending_script` still sees the lazy value. Arming it unconditionally in
  `run_frame_internal`/`run_goto` (where `queued_script_frame` is already written)
  would remove the compensation entirely — a bounded change worth one A/B.
* **The other four orphan-loop call sites now snapshot; nothing else does.**
  `run_frame_scripts_obj` and `construct_frame_obj` iterate `ext->render_list`
  live while scripts may `addChild`/`removeChild` into it. Ruffle iterates a
  cloned render list in several of those places too. Worth a systematic pass —
  the `orphan_removeobject` residual was exactly this class of bug.
* **`avm2/movieclip_addframescript_error`** (0/9, emits nothing) is unaffected by
  anything here and remains as w1 L8 described it — it needs the `#2001` argc throw
  (`w2-avm2-new-smalls` owns that) *plus* `getStackTrace` native frames (shared with
  w1 L6). One owner for both halves is still the cheap route.
* **`timeline/frame_script_button_order`** (`ruffle_matched` 13/14) and
  **`timeline/swf_9_frame_script_dynamic_goto`** (`ruffle_matched` 31/34) are the two
  remaining near-miss rows in the `timeline` suite; neither moved here and neither
  is on any s18 board.
