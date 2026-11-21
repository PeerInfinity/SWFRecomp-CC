# w2-attached-timeline: attached clips run their natural timeline in CI modes (session 23, wave 2)

**New files on this branch:**
- `SWFRecompDocs/plans/session23-fanout-reports/w2-attached-timeline-report.md` (this report)
- `SWFRecompDocs/plans/session23-fanout-reports/w2-attached-timeline.patch` (`git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`)
- `SWFRecompDocs/plans/session23-fanout-reports/w2-attached-timeline-probe/` (the hand-assembled probe SWF for the oracle request; it is **not** a fixture):
  - `make_probe_swf.py`: the generator (pure Python, no compiler needed)
  - `attach_probe.swf` is **not committed** (`*.swf` is gitignored). Regenerate it with `python3 make_probe_swf.py attach_probe.swf`; the output is deterministic, md5 `82368d06ec8857af7de5e3baf69b6258`
  - `output.ours.txt`: our output with this patch

No new `.c` or `.h` files and no `regression/` fixture, because there is no oracle in the cloud (see LOCAL ORACLE REQUESTS). Source changes are committed and are identical to the patch.

**Environment:**
- Cloud box; `SETUP_STATUS` is all OK.
- Upstream tests at **`0ddd12b6a`**, downloaded with `download_tests.sh avm1 from_gnash from_shumway timeline`.
- Ruffle source is a blobless clone at the same SHA.
- Every A/B below was run on this box:
  - **BEFORE** is a clean `origin/master` (`0d9d2ff0`) worktree at `/tmp/claude-0/base`.
  - **AFTER** is the same tree with this patch applied.
  - Both legs used copies of the same test directories.
- **No upstream drift was hit:** every row in the sweep has the same expected-line total in both legs.

---

## 0. Verdicts and EXPECTED-FLIP LEDGER

| # | Item | Verdict | Flip |
|---|---|---|---|
| 1 | `from_gnash/misc-swfc.all/movieclip_destruction_test3` (KF) | **GO, done** | fail 5/18 → **pass 18/18**, both modes. Flash fp10-exact; `output.fp10.ruffle.txt` differs at lines 9 and 11, so this cannot be `ruffle_matched` |
| 2 | `from_gnash/misc-swfc.all/movieclip_destruction_test4` (KF) | **GO, done** (wave 1 had it on HOLD; §2.4's completion mechanism is implemented) | fail 8/40 → **pass 40/40**, both modes. Flash-exact; `output.ruffle.txt` differs at lines 20, 21 and 25 |
| 3 | Part 3's generality ("removed-but-alive by its own onUnload runs its queued frame action") | **Not contradicted, but only one witness** | 0. Instrumented over 102 rows: it fires **only** in test3 (§3) |
| 4 | Generalisation beyond the prototype: children of **stopped** and **1-frame** attached clips play, and attached roots run **newest-first** | **GO** (Flash/Ruffle semantics, no corpus witness) | 0 corpus flips. A probe SWF shows it working (§1.4); oracle requested |

### EXPECTED-FLIP LEDGER (for the coordinator's CI check)

| Axis | Test | Expected CI move |
|---|---|---|
| trace | `from_gnash/misc-swfc.all/movieclip_destruction_test3` | `output_mismatch` → **`pass`** (graphics and no-graphics) |
| trace | `from_gnash/misc-swfc.all/movieclip_destruction_test4` | `output_mismatch` → **`pass`** (graphics and no-graphics) |
| pixel | (none) | No image row should move. Neither headliner has `[image_comparisons]`. The only two image-compared rows whose SWF calls attachMovie (`from_shumway/doubleAndRegister`, `avm1/netstream_play_flv_screen`) are md5-identical |

**Anything else that moves in CI is outside the ledger.**

**Suggested CI:**
- graphics `full` (the pump is in the shared Phase-1 frame loop) **plus** a no-graphics `all` leg.
- The pump code sits in `NO_GRAPHICS || OFFSCREEN_RENDER` arms, which `swf_core.c` also calls.
- `action.c` and `action_queue.c` are shared by every build, so the per-change graphics run covers them.

---

## 1. What the patch does (3 files, +235/−15)

### 1.1 `tag.c`: the natural-timeline pump (CI modes only, `#if NO_GRAPHICS || OFFSCREEN_RENDER`)

All new code is **static**. The only edits to existing functions are the body of `ng_advance_attached_clip_playheads`'s loop and two stamp calls inside `ng_record_attached_playable`.

- **`ng_attached_run_tree(obj, lvl, mc)`** is the productionised `w1_attached_post_order`, with no getenv gate.
  - It runs children first (post-order), newest placement first (`place_seq` descending, the same order `advance_sprite_frames` uses), then the clip itself.
  - Each object is advanced alone through a 1-entry scratch display list fed to `advance_sprite_frames`, with `g_advance_defer_nested=1`.
  - The attached root's frame runs under its own MovieClip context (its `display_obj` has no `instance_name`).
  - Queued payloads are repointed with `actionQueueRebaseSpriteObjPayloads`.
  - It converts the root's playhead between "shown frame" and "next frame" semantics.
- **Child MovieClip lookup is parent-scoped** (`ng_attached_child_mc`: a `child_mc_cache` entry with `parent == self`, then a global-name fallback). The prototype used the global name lookup only, so two attached clips with same-named children could have cross-wired.
- **Generalisation 1: a stopped attached clip's children still play.** The outer `!sprite_is_playing` skip is gone; `run_tree` skips only the *self* step. Flash runs every display-list clip's timeline independently.
- **Generalisation 2: a 1-frame attached clip is flagged too** (`ng_record_attached_playable` now sets `attached_playable` for `fc <= 1` without touching `sprite_is_playing`). This means a 1-frame container's animated children play. These are the most common HUD and enemy-holder shapes in games, and both were frozen before this patch.
- **Generalisation 3: attached roots run newest-attached first.**
  - Ruffle `avm1/runtime.rs:500` runs `clip_exec_list`, and `add_to_exec_list` (`:543`) prepends, so the newest instantiated clip runs first and root runs last.
  - `ng_stamp_attach_seq` gives the standalone attached `display_obj` a `place_seq` from the existing `g_place_seq` counter. The pump collects the eligible roots and sorts them by that stamp, descending.
  - The struct is in no display list, so no list walk ever reads the stamp.
  - The stamp is needed because `child_mc_cache` reuses freed slots, so reversing the cache order does not give creation order.
- **Unchanged:** the attach tick is still skipped via promotion, and a clip with a pending `sprite_manual_next_frame` is still skipped.

### 1.2 `action.c`: unload order and the test4 lookup (all builds)

- **`queueSubtreeOnUnloadsPostOrder`** (new static):
  - Full post-order, with children in ascending depth (render-list) order. Every child unloads its own subtree first, then the clip itself. This is Ruffle `MovieClip::avm1_unload` (`movie_clip.rs:2810`); the prototype only swapped the parent and its direct children.
  - It is used by **both** removeMovieClip forms: the method form `mc.removeMovieClip()` in `actionCallMethod`, and the global form `removeMovieClip(t)` in `actionRemoveSprite`. Both previously queued the parent first, then the children pre-order.
  - `queueChildOnUnloads` is kept for its other callers.
- **`actionMcHasOwnOnUnload`** (new, exported for `action_queue.c`).
- **`mcRemovedParentKeptChild`** (new static) plus one guarded call in GetMember's MovieClip arm, after the existing `as_created` scan.
  - It runs when the receiver is `avm1_removed && display_obj == NULL` (the deferred-removal branch cut the display link).
  - It resolves a named child through `child_mc_cache` (`parent == mc`, not `INT_MIN`), but **only** if that child's subtree defines an onUnload (`mcOrDescendantHasOnUnload`).
  - That gate is what separates sc:142 (brother6's child mc31 has onUnload → `movieclip`, depth −16382) from sc:124 (brother4's child has none → `undefined`).
  - It cannot resurrect `ul4`'s stripped `hul5`/`hul6` (`MovieClip.as`): those have no onUnload in their subtree.
  - This is the §2.4 completion mechanism, and it lands as `pass`, not the Ruffle variant. Keeping `display_obj`, which was the rejected wave-1 attempt, is **not** what this does.

### 1.3 `action_queue.c`: the keep-alive dispatch rule (all builds)

`aq_removed_but_self_kept_alive(mc)` (new static) is consulted only when the existing `aq_sprite_ctx_removed` would drop the queued sprite script.

- **It keeps the script when:** the clip is `pending_removal`, not `INT_MIN`, has its **own** onUnload, and has no removed or pending ancestor.
- **Otherwise it drops it,** exactly as before.

This is prototype part 3 without the gate, and with `pending_removal` required (the deferred branch always sets it for an own-onUnload clip).

### 1.4 The probe: generalisations 1–3 are visible (no corpus row sees them)

`w2-attached-timeline-probe/make_probe_swf.py` generates the probe (SWF8):
- The root's frame 1 does `attachMovie` of `holder` (1 frame, with child `kid`), `stopper` (3 frames; frame 1 `stop()`s; child `kid2`) and `multi` (3 frames, playing; child `kid3`).
- `kid*` are 3-frame clips that trace `this._name + " anim f" + _currentframe`.

| Build | Tick 2 onward |
|---|---|
| clean master | **nothing.** Only the attach-tick frame-1 lines and `root f2`, so every attached timeline is frozen. This reproduces the w1 finding |
| this patch | `kid3 f2, m f2, kid2 f2, kid f2, root f2`, then `kid3 f3, m f3, kid2 f3, kid f3`, looping. This is exactly the order predicted from Ruffle's exec list: newest-first, child before parent (child instantiated after parent), root last |

`stopper` itself stays on frame 1.

---

## 2. Per-test before/after (same box, clean master vs patch)

| Test | Mode | Before | After |
|---|---|---|---|
| `misc-swfc.all/movieclip_destruction_test3` | graphics | output_mismatch 5/18 (16 actual) | **pass 18/18** |
| | no-graphics | output_mismatch 5/18 | **pass 18/18** |
| `misc-swfc.all/movieclip_destruction_test4` | graphics | output_mismatch 8/40 (24 actual) | **pass 40/40** |
| | no-graphics | output_mismatch 8/40 | **pass 40/40** |

test4 with parts 1–3 but without §1.2's lookup is 38/40: the two sc:142/143 lines, which matches wave 1.

### Sweep (graphics AND no-graphics; statuses + matching/expected/actual line counts)

| Set | Rows | Graphics | No-graphics |
|---|---|---|---|
| Every avm1/from_gnash/from_shumway/timeline row whose decompressed SWF contains `attachMovie`, plus avm1/gnash rows with unload/remove/destruct in the name | 78 (avm1 53, gnash 21, shumway 4, **timeline 0**: no timeline row's SWF calls attachMovie) | 76 identical + the 2 ledger rows | same |
| Every remaining avm1/gnash/shumway/timeline row whose SWF contains `onUnload` (with or without `removeMovieClip`; for part 3) | 24 | 24 identical | 24 identical |
| `regression/`, all rows | 104 | 104 identical | 104 identical |
| **Total** | **206** | **204 identical, 2 = ledger** | **204 identical, 2 = ledger** |

**BEFORE-leg mode parity:** graphics and no-graphics are per-row identical on all 182 base rows. The BEFORE baseline is 177 pass, 17 ruffle_matched and 12 output_mismatch.

**Rows covered include:**
- `attach_movie*` and `attachMovie{Test,LoopingTest}`
- `attachImported` / `attachExtImported`
- `register_and_init_order` and `registerClassTest*`
- `removed_clip_halts_script`, `unload*`, `unloadmovie`, `unload_clip_event`, `clip_events`, `new_child_in_unload_test`
- `MovieClip-v5..v8`, `Sound-v5..v8`
- `place_and_remove_object*`, `movieclip_destruction_test1/2`
- the whole action_order family
- `from_shumway/avm1/{duplicateMovieClip,haxe/flocons1,moviecliploader,nativeinheritance}` and `doubleAndRegister`
- regression `avm1_attach_clipevent_enterframe`, `avm1_child_timeline_*`, `onunload_type1_*` and `avm1_parent_child_*`

### Graphics render canary

- **Standing canary members in the suites on this box** (avm1 8, from_shumway 13, regression 6), plus `avm1/netstream_play_flv_screen`: 28 tests and **63 PNGs, all IDENTICAL**. No trace or image status changes.
- `render_canary.py capture` ran BEFORE in the base worktree and AFTER in the patched worktree, then `compare`.
- The standing set cannot see this change class: only `doubleAndRegister` calls attachMovie. I **appended `avm1/netstream_play_flv_screen` at EOF**, the corpus's only other image-compared attachMovie row, with a provenance comment. A true covering member needs the probe with `[image_comparisons]` once it has an oracle.
- The avm2, visual, fonts and text canary members were not run: they were not downloaded, and none of them calls attachMovie or AVM1 removal.

---

## 3. Part 3's generality: attacked, not contradicted, one witness

**Corpus census:**
- Every avm1/gnash/shumway/timeline row whose SWF contains `onUnload` (41 rows), and every attachMovie row (§2), 102 non-regression rows in total.
- Each was run with temporary instrumentation (no-graphics) logging whenever the keep rule returns 1, and whenever `mcRemovedParentKeptChild` resolves something.

| Rule | Fires in |
|---|---|
| Keep rule | **only** `movieclip_destruction_test3` (`nestedMovieClip`, once) |
| Lookup | **only** `movieclip_destruction_test4` (`brother6.mc31`, twice) |

Nothing else in the corpus exercises either rule, so nothing contradicts them, and nothing beyond these two rows corroborates them.

**Why I did not narrow the rule further:**
- It already excludes the cases the fixture shows are dropped:
  - An ancestor removed (mc11 in test3).
  - Alive only because of a descendant's onUnload: such a clip has no own onUnload, so the rule does not apply.
  - Already finalised (`INT_MIN`).
- The one shape not pinned down is a clip removed by **timeline RemoveObject** (`actionMarkMCPendingRemoval` also sets `pending_removal`) with its own onUnload and a frame action queued the same tick. The rule treats it like `removeMovieClip`. No corpus row has this shape; an oracle row is requested below.
- If Flash disagrees there, narrow the rule by recording the removal source: a trailing `MovieClip` field set in the two removeMovieClip deferred branches.

**fp9/fp10:**
- The harness grades `output.fp10.txt`; fp9 and Ruffle both drop mc1's `4+` action.
- Flash-over-Ruffle: kept, per the brief.

---

## 4. Browser-WASM `advance_attached_clip_natural`: should it follow? (lead, not changed)

> **Done in s24:** see `browser-attached-timeline-report.md`. The browser now shares the pump. That slice also found
> that the pump's shown/next playhead conversion (§1.1) mis-stepped after gotoAndPlay, and that non-root
> registration aliases double-advanced their children in the CI modes. Both are fixed there.

**Not touched.** It remains a separate, name-gated (`pfx*`) / explicit-`gotoAndPlay` one-shot that runs placement tags only:
- It never runs DoActions, children, or 1-frame or stopped containers.
- It self-removes `pfx*` particles on wrap instead of running their final-frame `removeMovieClip`.

**Recommendation: yes, it should eventually route through `ng_attached_run_tree`,** so that the browser matches CI. Three blockers belong to that slot:
1. **The per-instance morph-ratio limitation** documented in that function (`tag.c` ≈2660): re-running placement tags on attached morph particles draws corrupted geometry.
2. **The N-game "timeIndicator `bar`" explosion** noted at the v1 broad auto-advance (`tag_stubs.c` ≈775). This is very likely the very frame-script/ordering hazard this patch addresses, so it should be retested under it.
3. **A perf A/B** on Windows real-GPU Chrome, per `CLAUDE.md`.

`ng_attached_run_tree` is compiled only in CI modes today. Exposing it to the browser means moving its `#if` and dropping the particle special case.

**Also note:** the action.c and action_queue.c parts (unload order, keep rule, removed-parent lookup) are build-independent and already apply in browser-WASM.

---

## 5. Not finished, and how each completes

1. **`regression/` fixture:** not written, because there is no oracle. Completion: LOCAL ORACLE REQUEST 1 below. With its trace (plus a render, if possible), the probe becomes `regression/avm1_attached_clip_natural_timeline` and is also the true canary covering member.
2. **The timeline-RemoveObject variant of the keep rule:** completion is ORACLE REQUEST 2. Narrow the rule only if Flash or Ruffle drops the action.
3. **Ordering between attached roots and timeline-placed clips** in the same tick: the attached pump runs as a block in Phase 1, while Ruffle interleaves by instantiation order. No corpus row observes it. ORACLE REQUEST 1 can be extended (see there) if wanted.

## New unclaimed leads

1. **Browser-WASM attached timelines** (§4). This is game-visible: attached HUD and enemy clips in browser builds still freeze. Lead for a games slot, after the morph-ratio renderer work.
2. **`actionQueueChildUnloadsFiltered`** (`action.c` ≈24609) still queues non-survivors pre-order (own handler, then the `queueChildOnUnloads` subtree). That is the RemoveObject and loop-rewind path. If Flash is post-order there too (Ruffle's `avm1_unload` is the same function for every removal path), it should use `queueSubtreeOnUnloadsPostOrder`. No corpus row noticed my change to the two removeMovieClip sites, so this is unpriced.
3. **Corpus coverage of attached timelines is nearly nil.** 206 rows, and only the two gnash destruction tests observe any of this. The probe shows the behaviour, so the payoff is in games: flasharchive/glaiel divergence-harness spot-checks of games that animate attachMovie'd HUDs.

## LOCAL ORACLE REQUESTS

1. **Attached-clip natural timeline fixture.**
   - **SWF:** generate it with `python3 SWFRecompDocs/plans/session23-fanout-reports/w2-attached-timeline-probe/make_probe_swf.py attach_probe.swf` (md5 `82368d06ec8857af7de5e3baf69b6258`; not committed, since `*.swf` is gitignored). SWF8, 30 fps, 3 root frames, the last of which does `stop()`.
   - **Need:** the Ruffle exporter trace for 6 ticks (Flash if available).
   - **What it settles:**
     - (a) Children of a 1-frame and of a stopped attached clip play.
     - (b) The per-tick order `kid3, m, kid2, kid, root`, i.e. Ruffle's newest-first exec list.
   - **Our output:** `output.ours.txt` (26 lines).
   - **If it matches:** add it as `regression/avm1_attached_clip_natural_timeline` with `num_ticks = 6`. Add `[image_comparisons]` only if the coordinator adds visible shapes; the probe currently has none.
2. **Timeline-RemoveObject keep-alive (optional).** A minimal SWF8:
   - Root frame 1 places a 3-frame sprite `c` at depth 1 and sets `c.onUnload = function(){ trace("unload " + this._name); }`. `c`'s frame 2 traces `"c f2 ran"`.
   - Root frame 2 has a `RemoveObject2` for depth 1 **and** `c`'s frame-2 action would be queued in the same tick.
   - **Need:** whether `c f2 ran` is printed (Flash fp10 preferred; Ruffle acceptable as a lower bound).
   - **If it is not printed:** narrow `aq_removed_but_self_kept_alive` to removeMovieClip-removed clips (§3).
