# w2-rider-actionorder — session 13 wave 2

**Agent:** wave-2 rider `w2-rider-actionorder` (trace axis).
**Board leads:** `session13-fanout-reports/wave1-board-audit.md` §5 **L1**
(`from_gnash` `action_order` execution ordering, "+2 trace, riders to +4") and
**L5** (`avm1/remove_different_level`, "+1").
**Worktree:** `.claude/worktrees/agent-ad77dd902a308b66b` at `10931d62e`.
**Deliverable:** `w2-rider-actionorder.patch` (2 files, +61/−5). Nothing
committed.

---

## 0. TL;DR

| target | before | after | how |
|---|---|---|---|
| `avm1/remove_different_level` | `output_mismatch` (3 exp / 2 act) | **PASS** | runtime: `_levelN` roots never had `onEnterFrame` dispatched |
| `from_gnash/misc-ming.all/action_order/action_execution_order_test` | `output_mismatch` (19/18/7) | **RUFFLE_MATCHED** | harness: `known_failure` inside `[subtests.fpN]` was invisible to `_test_is_known_failure` |
| `.../action_execution_order_test11` | `output_mismatch` (32/32/26) | unchanged — **NOT ATTEMPTED, arc-sized** | see §3: it needs the tick pipeline restructured, not an ordering tweak |

**Net expected CI movement: +2 effective (1 `pass`, 1 `ruffle_matched`), 0
regressions** — verified against 29 canaries (§4). The only other test the
harness fix could reach (`from_gnash/misc-ming.all/PrototypeEventListeners`)
was run and does **not** promote, so there is no hidden movement.

**The headline is a refutation.** L1's framing ("5 siblings already pass, so the
machinery exists; only the sibling/nesting order at one point is wrong; one
ordering rule, two tests") is wrong on both tests, in opposite directions:

- `action_execution_order_test` is **not an ordering bug at all**. Our output is
  **byte-identical to Ruffle's own** `output.fp10.ruffle.txt`, and upstream
  marks the graded `fp10` subtest `known_failure = true`. The only defect was in
  our harness. The remaining line (`as in frame2 of mc_blu`) is Flash-only
  behaviour that Ruffle does not reproduce either.
- `test11` is **not one rule** — it is the whole AVM1 frame pipeline. Ruffle
  runs one walk over `clip_exec_list` in which each clip's clip-event dispatch
  and its own timeline advance are **adjacent**; we run an all-clips
  enter-frame pass and then an all-clips advance pass. Three of test11's five
  assertions depend on that adjacency. Evidence in §3.

---

## 1. `avm1/remove_different_level` (+1, real pass)

### Diagnosis

`child.as` (loaded with `loadMovieNum("child.swf", 1)`):

```as
createEmptyMovieClip("mc", 1);
mc.onUnload = function() { trace("onUnload"); };
mc.removeMovieClip();
trace(mc);                       // -> "_level1.mc"  (removal is deferred)
this.onEnterFrame = function() { // `this` == the _level1 root
   delete this.onEnterFrame;
   trace(mc);                    // -> "undefined"   <-- we never got here
};
```

We produced lines 1–2 and stopped. The handler was installed on the `_level1`
root's `dynamic_props` and simply never fired.

Root cause is an eligibility-gate mismatch, not scope or `this` binding:

- `getOrCreateLevel` (`action.c:21178`) mints a synthetic `MovieClip` for
  `_levelN` (N > 0) and registers it in `child_mc_cache`, so
  `actionDispatchEnterFrameHandlers` **does** visit it.
- `actionFirePendingDirectLoads`' `is_level` branch (`action.c:23761`) lazily
  attaches a **synthetic `DisplayObject`** to that MC so the child SWF's tags
  place into the level's own display list instead of the parent's.
- `actionDispatchEnterFrameHandlers` then takes the `mc->display_obj != NULL`
  arm and requires `dobj->enterframe_eligible`. That flag is armed **only** by
  `set_enterframe_eligible_recursive(display_list, max_depth)`
  (`tag.c:4551`), which walks display lists. A level's synthetic
  `DisplayObject` **is in no display list**, so the flag is 0 forever and the
  MC is `continue`d on every tick.

So a `_levelN` root could never run `this.onEnterFrame` — a general defect, not
a quirk of this one test.

### Fix (`SWFModernRuntime/src/actionmodern/action.c`, 3 hunks)

Route level roots through the **dynamic-MC gate** (`mc->mc_enterframe_eligible`)
that `createEmptyMovieClip`-style MCs already use — it has exactly the right
semantics (skip the creation/load tick, fire on every tick after):

1. `g_levels_high_water` + `actionIsLoadedLevelRootMC(MovieClip*)` next to
   `g_levels[]`. The scan is bounded by the high-water mark, which is **0 for
   any content that never calls `loadMovieNum`/`loadClip`** — so the change is
   provably inert (identical machine behaviour) for the overwhelming majority
   of the corpus.
2. `actionDispatchEnterFrameHandlers`: a level root with a `display_obj` takes
   the `mc_enterframe_eligible` arm instead of the `enterframe_eligible` arm.
3. `actionMarkDynamicMCsEnterFrameEligible`: also arm level roots (they carry a
   `display_obj`, so the existing `display_obj == NULL` loop skipped them).

Deliberately **not** done: arming the synthetic `dobj->enterframe_eligible`
from `actionAdvancePlayingLevels`. That only runs while the level still has
frames left to play, and `child.swf` is a single-frame movie whose entry is
dropped immediately — it would not have fixed this test and would have made
the behaviour depend on the level's frame count.

### Result

```
[1/1] remove_different_level... PASS [r=0.00s c=170.03s x=0.02s]
Total tests: 1   Pass: 1 (100.0%)
```

---

## 2. `action_execution_order_test` (+1 effective, harness)

### Diagnosis

`test.toml`:

```toml
num_frames = 30
[subtests.fp9]   output_path = "output.fp9.txt"    player_options.version = 9
[subtests.fp10]  output_path = "output.fp10.txt"   known_failure = true
                 player_options.version = 10
```

`resolve_expected_filename` grades the **highest-version** variant → `fp10`
(19 lines). Our actual (18 lines) is missing `as in frame2 of mc_blu`, which
positionally shifts the remaining 11 lines — hence the misleading `7/19`
matching count.

`diff` of our actual against `output.fp10.ruffle.txt` is **empty**: we reproduce
Ruffle exactly, and `output.fp10.ruffle.txt` is itself byte-identical to
`output.fp9.txt`. The missing line is genuine Flash behaviour (mc_blu's frame-2
action runs before its parent mc_red's frame-2 action removes it) that Ruffle
does not reproduce, which is why upstream marks the `fp10` subtest
`known_failure`.

The harness never consulted that oracle: `_test_is_known_failure(test_dir)`
read `known_failure` **only at the top level** of `test.toml`. The
`ruffle_matched` promotion is gated on it, so the `output.fpN.ruffle.txt` name
that `verify_output.py` already knows how to derive (main(), "For subtests, the
matching Ruffle-actual is named output.fpN.ruffle.txt") could never be read.

### Fix (`ruffle-tests/verify_output.py`, 2 hunks)

`_test_is_known_failure(test_dir, expected_filename=None)` also returns True
when the `[subtests.NAME]` table **whose `output_path` is the file we actually
graded against** sets `known_failure`. Call site passes `expected_filename`.

Conservative by construction: it can only promote an already-**failing** test to
`ruffle_matched`, never demote a pass, and only when a matching
`output.<same-stem>.ruffle.txt` exists **and** our diff set is a subset of
Ruffle's.

### Blast radius — measured, not assumed

Scanning all 4 400+ `test.toml` files for `[subtests.*].known_failure`:

| test | top-level `known_failure` | baseline status | effect |
|---|---|---|---|
| `from_gnash/actionscript.all/ASnative-v{5,6,7,8}` (`macos`) | **yes** (already) | — | none (top-level arm already covered them) |
| `from_gnash/misc-swfmill.all/trace-as2/arguments` (`fp10`) | no | **pass** | none (fix only runs on failures) |
| `from_gnash/misc-ming.all/PrototypeEventListeners` (`fp11`) | no | `output_mismatch` (32/12/1) | **run in §4: does NOT promote** (our diff set ⊄ Ruffle's) |
| `from_gnash/misc-ming.all/action_order/action_execution_order_test` (`fp10`) | no | `output_mismatch` | **→ `ruffle_matched`** |

Exactly **7** subtest-scoped `known_failure` entries exist corpus-wide, across
**7** test directories. There is no wider exposure.

### Result

```
Total tests: 1   Pass: 0   Ruffle-matched: 1 (100.0%)   Effective pass: 1
```

---

## 3. `action_execution_order_test11` — diagnosed, NOT attempted (arc item)

### The id map (decoded from `RecompiledScripts/`, so it is exact)

`doActionOrder`: `0` root frame-0, `1` mc12, `2` mc21, `3` mc11, `4` mc2,
`5` mc1.
`asOrder`: `0` root DoAction · `1/2` mc1/mc2 onLoad · `3/4` mc2/mc1 onEnterFrame
· `5/6` mc11 onLoad/onEnterFrame · `8/10` mc21 onLoad/onEnterFrame ·
`14/15` mc12 onLoad/onEnterFrame · `20…24` unloads (mc11, mc12, mc1, mc21, mc2)
· `25…29` DoActions (mc12, mc21, mc11, mc2, mc1).

Clip topology (from `RecompiledTags/tagMain.c`): root frame 1 places
`mc1`=char 6 (depth 2) then `mc2`=char 8 (depth 3); mc1's frame 1 places
`mc11`=char 4, mc1's frame 3 places `mc12`=char 5; mc2's frame 2 places
`mc21`=char 7.

### What the expected `asOrder` says, segmented per tick

```
tick 1  0
tick 2  1  2                          mc1.load, mc2.load
tick 3  3  4  5                       mc2.EF, mc1.EF, mc11.load
tick 4  6  3  8  4                    mc11.EF, mc2.EF, mc21.LOAD, mc1.EF
tick 5  10 6  3  4  14                mc21.EF, mc11.EF, mc2.EF, mc1.EF, mc12.load
tick 6  15 25 10 26 6 27 3 28 4 29    (EF, own DoAction) x 5, newest clip first
tick 7  20 21 22 23 24                unloads
```

Two structural facts fall straight out:

1. **Tick 6 pairs each clip's enter-frame with its own frame DoAction**
   (`15,25` = mc12; `10,26` = mc21; `6,27` = mc11; `3,28` = mc2; `4,29` = mc1),
   walking clips newest-first.
2. **Tick 4 puts `mc21.load` (8) between mc2's EF (3) and mc1's EF (4)** — mc2's
   *advance*, which places mc21, happens after mc2's own EF and before the next
   clip in the walk is touched at all.

That is precisely Ruffle's model. `Avm1::run_frame`
(`core/src/avm1/runtime.rs:519`) walks `clip_exec_list` (LIFO by instantiation)
and calls `MovieClip::run_frame_avm1` (`core/src/display_object/movie_clip.rs:450`),
which is literally:

```rust
let is_load_frame = !self.0.contains_flag(MovieClipFlags::INITIALIZED);
if is_load_frame { self.event_dispatch(context, ClipEvent::Load); ... }
else             { self.event_dispatch(context, ClipEvent::EnterFrame); }
if self.playing() { self.run_frame_internal(context, true, true, false); }
```

— dispatch **then** advance, **per clip**, in one walk. A child placed by
`run_frame_internal` gets its `run_frame_avm1` invoked inline
(`movie_clip.rs:1563`), which is where `mc21.load` slots in mid-walk.

### Our model

We split those into two full passes:

- `tagFlushPendingEnterFrame` (`tag.c:4577`) → `set_enterframe_eligible_recursive`,
  `dispatch_enterframe_clip_actions`, `actionDispatchEnterFrameHandlers` —
  **all** clips' enter-frame events.
- `advance_sprite_frames` (`tag.c:1122`) — **all** clips' timeline advance,
  queueing DoActions into `AQ_KIND_SCRIPT` for a later FIFO drain.

Our actual `asOrder`, segmented the same way:

```
tick 4  6  3  4  8            mc21.load falls to the END of the tick
tick 5  10 6 3 4 14 26        mc21's DoAction fires a TICK EARLY
tick 6  25 27 15 10 6 3 4 28 29
```

`enterFrameOrder` and `loadOrder` and `unloadOrder` all **pass** — our
enter-frame walk order (newest-first via reverse `child_mc_cache`) is already
right. The two failing assertions are exactly the two that need
dispatch/advance adjacency.

### Verdict

Fixing test11 means merging our two passes into a single exec-list walk with
per-clip `(dispatch clip event, advance that clip's timeline)` — i.e. rewriting
the AVM1 tick. That is an arc, not a rider fix, and it would move the ordering
of every timeline test in the corpus. **The 5 sibling canaries and the whole
`timeline` suite would be exactly the wrong things to gamble.** Not attempted;
recorded here so the next session prices it correctly.

`doActionOrder` is worth one extra note: the *only* divergence is `1` vs `2`
(mc12 vs mc21, children of **different** parents). A naive "flip
`advance_sprite_frames` to forward instantiation order" would not fix it — the
issue is *when* mc21's frame-2 script fires relative to mc12's placement tick,
which is the same adjacency problem.

### Riders (L1's "riders to +4") — measured, all far from pass

| test | exp/act/match | note |
|---|---|---|
| `action_execution_order_test6` | 24/20/**0** | not near |
| `action_execution_order_extend_test` | 32/28/7 | not near |
| `ActionOrderTest3` | 62/73/4 | not near |
| `ActionOrderTest4` | 64/105/10 | not near |
| `ActionOrderTest5` | 51/58/6 | not near |
| `PlaceAndRemove` | 96/45/15 | not near |

None is a near-pass; all sit in the same dispatch/advance-adjacency family.
**L1's "+2 core, riders to +4" should be re-booked as "+1 effective (done) and
one AVM1-tick-pipeline arc".**

---

## 4. Canary ledger

All runs local, `verify_output.py --test=…` (no-graphics default), from the
worktree, 2-way parallel. Machine shared with ~8 agents at load ≈ 25, so every
non-`PASS` was re-run sequentially before being believed.

**29 canaries, zero movement.** Every one holds its `1f8396f57` baseline
status exactly.

### Gate A — the 5 (actually 9) `action_order` siblings the brief named as a hard gate

| test | baseline | after patch |
|---|---|---|
| `action_execution_order_test1` | pass | **pass** |
| `action_execution_order_test2` | pass | **pass** |
| `action_execution_order_test3` | pass | **pass** |
| `action_execution_order_test4` | ruffle_matched | **ruffle_matched** |
| `action_execution_order_test5` | pass | **pass** |
| `action_execution_order_test7` | pass | **pass** |
| `action_execution_order_test8-v5` | pass | **pass** |
| `action_execution_order_test8-v6` | pass | **pass** |
| `action_execution_order_test9` | pass | **pass** |
| `multi_doactions_and_goto_frame_test` | pass | **pass** |

(The gate is trivially safe here — nothing in the patch touches frame-action
ordering. Run anyway because the brief made it a hard gate.)

### Gate B — every level / multi-SWF / unload path the runtime hunk can reach

| test | baseline | after patch |
|---|---|---|
| `avm1/loadmovienum` | pass | **pass** |
| `avm1/loadmovienum_cross_version_prototype` | pass | **pass** |
| `avm1/unloadmovienum` | pass | **pass** |
| `avm1/loadmovie` | pass | **pass** |
| `avm1/loadmovie_method` | pass | **pass** |
| `avm1/loadmovie_replace_root` | pass | **pass** |
| `avm1/loadmovie_var_persistence` | pass | **pass** |
| `avm1/localconnection_top_level` | pass | **pass** |
| `avm1/mcl_unloadclip` | pass | **pass** |
| `avm1/load_cancel_via_unloadmovie` | ruffle_matched | **ruffle_matched** |
| `avm1/root_onload` | pass | **pass** |
| `avm1/string_paths_unload` | pass | **pass** |
| `avm1/unload` | pass | **pass** |
| `avm1/unload_clip_event` | pass | **pass** |
| `avm1/unload_nested_child` | pass | **pass** |
| `avm1/clip_events` | pass | **pass** |
| `avm1/clip_event_propagation_order` | pass | **pass** |

### Gate C — enter-frame dispatcher regression tests

| test | baseline | after patch |
|---|---|---|
| `regression/root_enterframe_cross_swf_version` | pass | **pass** |
| `regression/enterframe_type1_args` | pass | **pass** |

### Harness-fix blast radius, verified by run

| test | baseline | after patch |
|---|---|---|
| `from_gnash/misc-ming.all/PrototypeEventListeners` | output_mismatch | **output_mismatch** (unchanged) |

The only other corpus test the harness fix can reach does **not** promote — its
diff set is not a subset of Ruffle's (Ruffle produces 25 of 32 expected lines,
we produce 12). So the harness change moves **exactly one** test. No bonus +1.

---

## 5. Merge risks

- **Runtime hunk is level-scoped and self-disabling.** `g_levels_high_water` is
  0 until `getOrCreateLevel` mints a level, so for content without
  `loadMovieNum`/`loadClip` the added code is a `for` loop that never
  iterates and a branch that is never taken. The behavioural surface is
  "`_levelN` roots now get `onEnterFrame` dispatched from the tick after
  their load".
- **File contention.** `action.c` hunks are at `:21174` (`g_levels`
  declarations), `:21216` (`getOrCreateLevel`) and `:35329`/`:35466`
  (enter-frame dispatch). Sibling agents this session were editing `action.c`
  around `:70653` (setMask area) and adding an ImportAssets preload helper
  near `:34580` — **no overlap**. No `tag.c`, `swf.cpp` or render-loop code
  touched.
- **`verify_output.py`** is a shared harness file. The change is additive, has
  one call site, and cannot demote a passing test. If another wave-2 agent also
  edits `verify_output.py`, the hunks are in `_test_is_known_failure`
  (`:3288`) and `main()` (`:4251`).
- **Recompiler untouched**, so the pre-built `SWFRecomp/build` copied from the
  main repo stays valid; CI needs no special handling.
- **CI mode:** `graphics` (per-change default). The runtime hunk is in
  `action.c`, shared by all modes; the enter-frame dispatcher is not
  `#ifdef`-split, so graphics and no-graphics take the same path. `categories=all`
  suffices (no AVM2 emission touched) — but note `from_gnash` and the misc
  group are needed to *see* the `action_execution_order_test` flip, so
  `categories=full` is the run that demonstrates both.
