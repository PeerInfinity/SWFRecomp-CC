# w2-loaders — session 19 wave 2: the three GO items from `w1-loaders-report.md`

Worktree `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a6bd1c9f0084e76da`, branch
`worktree-agent-af491cbcaed487092`, base `e36bca73e`. No commits, no pushes. Three independent
patches, each of which applies to a clean `e36bca73e` on its own and to the others in any order
(verified: 1→2→3 and 3→2→1 both apply clean).

All runs: no-graphics, sequential, `SWFRECOMP_COMPILE_TIMEOUT=2400`, `--verbose`, test dirs copied
into this worktree and `--recompile`d on first use. Mode parity is complete, so no-graphics is the
triage mode; a graphics-mode confirmation of the headline + the new fixtures is recorded in §5.

## 0. Deliverables and NEW FILES (stage these by name)

Patches (in `SWFRecompDocs/plans/session19-fanout-reports/`, in this worktree and copied to the
main tree):

| patch | files touched | lines |
|---|---|---|
| `w2-loaders-1-loaderevents.patch` | `SWFModernRuntime/src/avm2/avm2_display.c` | +31 −3 |
| `w2-loaders-2-simplebutton.patch` | `SWFModernRuntime/src/avm2/avm2_display.c` + the 8 new `regression/avm2_child_simplebutton` files | +16 −0 code |
| `w2-loaders-3-mcltick.patch` | `SWFModernRuntime/src/actionmodern/action.c`, `SWFModernRuntime/include/actionmodern/action.h`, `SWFModernRuntime/src/libswf/swf_core.c`, `SWFModernRuntime/src/libswf/swf.c` + the 7 new `regression/avm1_mcl_load_tick` files | +154 −11 code |

**New files.** They are **inside patches 2 and 3** — the patches were generated with `git add -N` +
`git diff --binary`, so `git apply` recreates the `.swf` binaries byte-for-byte (verified with
`cmp` after a clean re-apply). The `regression` suite is git-tracked, so these still have to be
STAGED BY NAME after applying (`git add <path>`; never `git add -A`):

    ruffle-tests/tests/swfs/regression/avm2_child_simplebutton/README.md            (patch 2)
    ruffle-tests/tests/swfs/regression/avm2_child_simplebutton/Test.as              (patch 2)
    ruffle-tests/tests/swfs/regression/avm2_child_simplebutton/Child.as             (patch 2)
    ruffle-tests/tests/swfs/regression/avm2_child_simplebutton/create_test_swf.py   (patch 2)
    ruffle-tests/tests/swfs/regression/avm2_child_simplebutton/test.swf             (patch 2)
    ruffle-tests/tests/swfs/regression/avm2_child_simplebutton/child.swf            (patch 2)
    ruffle-tests/tests/swfs/regression/avm2_child_simplebutton/output.txt           (patch 2)
    ruffle-tests/tests/swfs/regression/avm2_child_simplebutton/test.toml            (patch 2)
    ruffle-tests/tests/swfs/regression/avm1_mcl_load_tick/README.md                 (patch 3)
    ruffle-tests/tests/swfs/regression/avm1_mcl_load_tick/Parent.as                 (patch 3)
    ruffle-tests/tests/swfs/regression/avm1_mcl_load_tick/create_test_swf.py        (patch 3)
    ruffle-tests/tests/swfs/regression/avm1_mcl_load_tick/test.swf                  (patch 3)
    ruffle-tests/tests/swfs/regression/avm1_mcl_load_tick/child.swf                 (patch 3)
    ruffle-tests/tests/swfs/regression/avm1_mcl_load_tick/output.txt                (patch 3)
    ruffle-tests/tests/swfs/regression/avm1_mcl_load_tick/test.toml                 (patch 3)

No new `.c`/`.h` TUs, so `verify_output.py`'s source list, `CMakeLists` and the Emscripten build
need no edit. Both `output.txt` files are the local Ruffle exporter's trace byte for byte (the
fixtures and oracles are w1's, in `<scratchpad>/w1-loaders/{btnfix,mclfix}/`); neither was ever
generated from our own output. `avm1_mcl_load_tick/child.swf` is reproduced **byte-identical** by
its `create_test_swf.py` (checked with `cmp`).

## 1. Verdicts

| patch | verdict | corpus flips | new fixtures |
|---|---|---|---|
| 1 loader events (`unload` + the parentless `added`) | **GO — DELIVERED** | **+1 effective**: `avm2/loader_events_2` `output_mismatch` → `ruffle_matched` | — |
| 2 loaded-child `SimpleButton` states | **GO — DELIVERED** | 0 (as priced) | `regression/avm2_child_simplebutton` |
| 3 MCL L1a (`onLoadInit` after `enterFrame` + no double step) | **GO — DELIVERED** | 0 (as priced) | `regression/avm1_mcl_load_tick` |

Every w1 pricing claim I re-tested **survived**. The one w1 claim I could refute is narrower than a
lead (§4.3). One real defect was found and fixed in my own patch-3 implementation before delivery
(§4.2) — w1's mechanism description was one step short.

## 2. Patch 1 — `w2-loaders-1-loaderevents.patch`

Two dispatches in `avm2_display.c`:

* **`loader_drop_content`** now reads the content child once, dispatches a bare non-bubbling
  `unload` on the LoaderInfo when it is non-NULL, and removes that captured child afterwards —
  Ruffle `loaderinfo_object.rs:265-279` (re-read at `0631814db`; the guard really is
  `loader.child_by_index(0).is_some()`, and the dispatch really does precede both the stream reset
  and the removal). The removal is re-checked after the dispatch, because a handler may unload the
  Loader itself.
* **`loader_boot_child_swf`** dispatches a bubbling `added` on the loaded root after its
  constructor returns and before `insert_at_index`. Ruffle's `fire_added_events`
  (`display_object.rs:2404-2418`) gates only on "my parent is not a SimpleButton", so a
  **parentless** object still fires it — and fires no `addedToStage`, since it is not on the stage.
  Our `on_construction_complete` additionally requires `ext->parent != NULL` and is never reached
  for a loaded root anyway (`cext->constructed` is set before the ctor), so the dispatch is local
  rather than a change to the shared gate — deliberately, to keep the blast radius at one call
  site.

**Ledger**

| test | before | after |
|---|---|---|
| `avm2/loader_events_2` | `output_mismatch` (31 lines vs 35) | **`ruffle_matched`** — our actual is now **byte-identical to `output.ruffle.txt`** |
| `avm2/loader_events` | pass | pass |
| `avm2/loader_loadbytes_events` | pass | pass |
| `avm2/loaderinfo_loadurl` | pass | pass |
| `avm2/loader_try_click_root` | pass | pass |
| `avm2/large_preload_from_bytes` | pass | pass |
| `avm2/loader_load` | `output_mismatch` (baseline) | `output_mismatch`, **unchanged** — its diff is URLVariables property order, a different mechanism |
| `from_shumway/as3-loader/LoaderTest2` | pass | pass |
| `from_shumway/as3-loader/events/loader-events` | `output_mismatch` | `output_mismatch`, actual **byte-identical to w1's baseline actual** |
| `mixed_avm/avm2_loads_avm1_events` | `output_mismatch` | `output_mismatch`, **+1 correct line** (`unload`) — exactly w1 §3.3's prediction that two more mechanisms remain |
| `regression/avm2_loader_stub` | pass | pass |
| `regression/avm2_parent_child_render` | pass | pass |
| `regression/avm2_parent_child_symbolclass_domain` | pass | pass |

**Blast radius, re-derived independently (w1's claim confirmed, and widened before it was
confirmed).** I grepped `avm2`, `mixed_avm`, `from_shumway`, `import_assets`, `timeline`, `swf`,
`visual` and `regression` for `Event.ADDED` **and** the string literals `"added"` / `'added'`
(w1 grepped only the constant). That found two files w1's list did not: `avm2/loaderinfo_events`
and `from_shumway/as3-loader/events/loader-events`. Both are harmless and for different reasons:

* `avm2/loaderinfo_events/Main.as` listens for `"added"` on **itself**, but that movie is the
  ROOT — it has no child SWF and never enters `loader_boot_child_swf`. It passes, before and after.
* `loader-events`' `LoaderEvents.as` listens for `Event.ADDED` on the **parent** root. The new
  dispatch is parentless, so it has no bubble path to that listener; the run confirms a
  byte-identical actual.

For `UNLOAD` the only listeners anywhere are `avm2/loader_events_2` (parent + child),
`mixed_avm/avm2_loads_avm1_events`, and `from_shumway/flash_net_URLLoader` — whose listener is on a
`URLLoader`, not a Loader's LoaderInfo, and is untouched.

## 3. Patch 2 — `w2-loaders-2-simplebutton.patch`

`button_data_for_char` gains the `g_child_movies` fall-through that `char_info`,
`timeline_for_char`, `statictext_for`, `shape_geom_for_in` and `avm2_display_char_is_defined`
already carry (`t->buttons` / `t->button_count`; a child's `ButtonDef.char_id` and every
`ButtonRec.char_id` are already shifted by `char_id_base`, so the bare-id key is correct).

**Ledger** — 0 corpus flips, as priced; the deliverable is the fix plus the fixture.

| test | before | after |
|---|---|---|
| `regression/avm2_child_simplebutton` **(new)** | `output_mismatch` (4 × `null` + `button w=0 h=0`) | **PASS** |
| `from_shumway/as3-loader/LoaderTest2` (the only corpus child SWF with a `DefineButton2`) | pass | pass |
| `avm2/simplebutton_structure` | pass | pass |
| `avm2/simplebutton_symbolclass` | pass | pass |
| `avm2/simplebutton_childevents` | pass | pass |
| `avm2/simplebutton_constr` | pass | pass |
| `avm2/simplebutton_multi_children` | pass | pass |
| `regression/avm2_parent_child_render` | pass | pass |

The fixture is a true discriminator: with the patch reverted (and the fixture in place) it produces

    up: null / over: null / down: null / hit: null / button w=0 h=0

against the oracle's `Shape w=20 h=20 / Sprite w=40 h=40 kids=2 / Shape w=40 h=40 / Shape w=20 h=20
/ button w=20 h=20`. The `over` row is two button records on purpose — it is the only row that
exercises the multi-record auto-Sprite wrapper.

## 4. Patch 3 — `w2-loaders-3-mcltick.patch`

### 4.1 What it does

1. **Phase 3 is split out of the drain.** `actionFirePendingLoadInits` no longer fires
   `onLoadInit`/`onLoadError`; it parks each load in a new `g_pending_load_inits` queue, stamped
   with `g_tick_count`. `actionDrainPendingLoadInits` fires only entries stamped with an EARLIER
   tick, and is called immediately **before** `actionAdvancePlayingLevels` in `swf_core.c`, in both
   of `swf.c`'s advance sites (mode parity), and in the AVM1-under-AVM2 tick in `action.c`.
   `actionDrainPendingLoadInitsFinal` fires everything on the final tick, where no next tick exists.
   Three exit-condition gates learned about the queue (`actionHasPendingLoadInits`), so a parked
   handler keeps the player ticking exactly like a pending load does.
2. **`actionRegisterLevelAdvance` passes `start_armed = 0`.** MCL targets no longer take the
   same-tick double step. A `_levelN` target of a *direct* `loadMovieNum` still starts armed —
   untouched, as the brief asked.

### 4.2 The one thing w1 got wrong, and it is load-bearing

w1 §4.2 says "queue Phase 3 for the NEXT tick and drain it in `swf_core.c` immediately before
`actionAdvancePlayingLevels`" as if the call-site move *were* the next-tick deferral. It is not.
The drain that queues Phase 3 for a one-frame loader is **`tag.c:7245`, inside `tagShowFrame`**,
which runs during the frame script — i.e. EARLIER in the same tick than `swf_core.c:1462`. A
position-only change therefore fires `onLoadInit` in the load's own tick, one line too early:

    loadClip / onLoadStart / onLoadProgress / onLoadComplete / c1 / onLoadInit cf=1 / t1 h.cf=1 / c2
                                                                   ^^^^^^^^^^^^^^^^ above `t1`

The **tick stamp** is what makes it "next tick". Measured with a temporary `g_tick_count` trace;
with the stamp the fixture passes byte for byte.

A second implementation defect the fixture did not catch, and a corpus test did: three loop-exit
gates (`swf_core.c`'s top-of-tick `quit_swf` gate and the two past-last-frame gates, plus `swf.c`'s
`quit_swf` gate) list `g_pending_mcl_load_count == 0` as a reason to stop. With Phase 3 deferred,
`avm1/mcl_loadclip_properties` (`num_ticks = 2`) broke out of the loop at the top of tick 2 with
the handler still parked and **lost `onLoadInit` entirely** (pass → output_mismatch). All four
gates now also consult `actionHasPendingLoadInits()`. This is the reason to run the whole battery
and not just the headline.

### 4.3 Refutation / confirmation of w1's own open claim

w1 §4.2 flagged one claim it could not settle without editing source: that the double step is
compensating for the **Phase-3 position**, not for the delivery tick, so `from_shumway/avm1/
moviecliploader` survives both changes. **Confirmed by measurement**: that test still PASSES with
patch 3 applied (it was the brief's designated HOLD trigger). The refuted half is the inverse
reading of the `armed` field's own comment in `action.c` ("moviecliploader … only reaches
`loadee frame 2` because of it, which says our MCL load itself completes a tick later than
Flash's") — the tick-later delivery is real and is *Flash's*, but it is not what the double step
was paying for. The comment has been rewritten accordingly.

**L1b stays REFUTED and untouched**: `builtin_mcl_loadClip`'s `defer_to_next_tick` and
`actionPromotePendingMCLLoads` are not modified by this patch, and the new fixture is built on the
one-frame loader precisely so it cannot encode Ruffle's delivery tick.

### 4.4 Ledger

| test | before | after |
|---|---|---|
| `regression/avm1_mcl_load_tick` **(new)** | `output_mismatch` | **PASS** |
| `from_shumway/avm1/moviecliploader` (HOLD trigger) | pass | **pass** |
| `avm1/loadmovie_fail` (`num_frames = 1`) | pass | pass |
| `avm1/string_paths_eval2` | pass | pass |
| `avm1/loadmovie_var_persistence` (chained `loadClip` from `onLoadInit`) | pass | pass |
| `avm1/mcl_loadclip_properties` (`num_ticks = 2`) | pass | pass — **and this is the test that caught the exit-gate bug in §4.2** |
| `regression/avm1_mcl_holder_totalframes` | pass | pass |
| the 27-test `avm1/{mcl_*,loadmovie*,loadmovienum*,unloadmovie*,load_cancel_*}` battery | 23 pass + 4 `ruffle_matched` | **identical, test for test** |
| `from_gnash/actionscript.all/MovieClipLoader-v7` / `-v8` | `ruffle_matched` | `ruffle_matched` |
| `regression/avm1_child_timeline_{advance,frame1_stop,holder_stop,loop}` | pass ×4 | pass ×4 |

The four baseline `ruffle_matched` rows that stayed `ruffle_matched` are
`avm1/mcl_replace_root_swf7_to_swf5`, `.../swf7_to_swf6`, `avm1/load_cancel_via_unloadclip` and
`avm1/load_cancel_via_unloadmovie` — checked against `results_graphics.json` so a
`pass → ruffle_matched` drift could not hide. **39 tests run for patch 3; 39 match their baseline.**

The fixture discriminates both halves, as designed:

| applied | trace |
|---|---|
| both (shipped) | `c1, t1 h.cf=1, onLoadInit cf=1, c2, t2 h.cf=2, c3, t3 h.cf=3` = the oracle |
| Phase-3 split only (`start_armed` back to 1) | `c1, c2, t1 h.cf=2, onLoadInit cf=2, c3` |
| neither (baseline) | `c1, onLoadInit cf=1, c2, t1 h.cf=2, c3, t2 h.cf=3` |

## 5. Stacking, graphics mode, and how they interact

**Patches 1 and 3 both touch tick/event ORDER, and they do not interact.** With all three stacked,
every test that either patch touches produces the same verdict AND the same bytes as with that
patch alone:

| test (all three applied) | result | vs single-patch |
|---|---|---|
| `avm2/loader_events_2` | `ruffle_matched` | same, and still byte-identical to `output.ruffle.txt` |
| `regression/avm2_child_simplebutton` | PASS | same |
| `regression/avm1_mcl_load_tick` | PASS | same |
| `from_shumway/avm1/moviecliploader` | pass | same |
| `avm1/mcl_loadclip_properties` | pass | same |
| `mixed_avm/avm2_loads_avm1_events` | `output_mismatch` | same, and byte-identical to the patch-1-only actual |

The reason there is no interaction: patch 3's queue is AVM1-only (`MovieClipLoader`), and the one
place the two paths meet — the AVM1-under-AVM2 tick in `action.c` — is a pure insertion of the
Phase-3 drain ahead of an existing `actionAdvancePlayingLevels`, with no AVM1 MCL load in
`avm2_loads_avm1_events` to park.

**Graphics mode (`--mode=graphics`, the CI grading mode, local Dawn).** Patch 3 edits `swf.c`, so
this is not optional. All five re-runs agree with no-graphics:

    regression/avm1_mcl_load_tick        PASS
    regression/avm2_child_simplebutton   PASS
    avm2/loader_events_2                 RUFFLE_MATCHED
    from_shumway/avm1/moviecliploader    PASS
    avm1/mcl_loadclip_properties         PASS

**Patch independence.** Applying 1→2→3 and 3→2→1 to a clean `e36bca73e` both succeed with the same
final diffstat (199 insertions, 14 deletions across 5 files), so the coordinator can land them as
three commits in any order. Patches 1 and 2 both edit `avm2_display.c` but in hunks ~6 000 lines
apart (`button_data_for_char` at ~12 447; `loader_drop_content` / `loader_boot_child_swf` at
~5 690 / ~6 135).

**Sibling-overlap note.** Patch 2's only edit is inside `button_data_for_char`; patch 1's are
inside `loader_drop_content` and `loader_boot_child_swf`. Nothing is reformatted, no shared helper
is changed, and no new file-scope symbol is added to `avm2_display.c`. A sibling editing
Stage3D/other AVM2 slices in that file should not conflict textually. Patch 3 adds three new
file-scope statics and two new exported functions in `action.c`/`action.h`, all named
`*PendingLoadInits` / `g_pending_load_init*`.

**CI recommendation.** Patch 3 touches `swf_core.c` AND shared runtime code, so per CLAUDE.md's
"when in doubt for shared runtime code, run both": dispatch `mode=graphics` and `mode=no-graphics`.
Patches 1 and 2 are AVM2 runtime emission-adjacent, so `categories=full` is the right call for
them; `images=false` throughout (no render-path change).

## 6. New unclaimed leads

* **`mixed_avm/avm2_loads_avm1_events` is now ONE mechanism short of two, not three.** Patch 1
  delivered w1 §3.3's item (1); items (2) (the AVM1 child's first frame runs before the AVM2 root's
  `enterFrame`) and (3) (`init`/`httpStatus`/`complete` a frame late) remain, and both have the
  same completion mechanism w1 named: route an AVM1 child load through the `pending_boot` →
  next-drain rotation that `avm2_loader_run_exit_frame` already does for AS3 children. Worth +1
  effective. Note that item (2) is the **cross-VM twin of patch 3**: the AVM1-under-AVM2 tick now
  has the Phase-3 drain slot wired in, so half the plumbing exists.
* **`_levelN` targets of a direct `loadMovieNum` still start ARMED** — the last user of the
  `start_armed = 1` arm. Nothing in the corpus grades it (that is why the brief said to leave it),
  but it is now the only place the old double step survives, and it is almost certainly wrong for
  the same reason the MCL one was. A `regression/avm1_level_load_tick` fixture shaped like
  `avm1_mcl_load_tick` but using `loadMovieNum(..., 1)` would settle it; ~5 lines if it confirms.
* **The Phase-3 queue is capped at `MAX_PENDING_MCL_LOADS` (16) and silently drops the overflow**
  (`if (g_pending_load_init_count >= MAX_PENDING_MCL_LOADS) break;`). The pre-existing load queues
  have the same cap, so this is not a new class of bug, but it is now possible to have 16 parked
  Phase-3 entries AND 16 pending loads at once. Unprobed; no corpus test comes close.
* **`symbol_char_is_placed` (`avm2_main.c:359`) is still main-movie-only**, by exactly the pattern
  patch 2 fixes — w1 §6 named it and I did not touch it (it is a different decision point and
  wants its own fixture). Same for `nondisplay_class_for_char`'s child-domain arm.
* **A loaded root never gets a default instance name** (`name` reads `null` where the oracles say
  `instanceN`): `loader_boot_child_swf` skips `set_default_instance_name`. I confirmed the symptom
  is unchanged by patch 1 (`from_shumway/as3-loader/events/loader-events`' actual is byte-identical
  before and after). Still ~5 lines of that row, and it should be A/B'd against L10's global
  counter, cheap half first.
