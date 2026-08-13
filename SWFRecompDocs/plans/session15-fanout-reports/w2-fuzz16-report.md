# w2-fuzz16 — session 15 wave-2: the 16th fuzz row (`e152812e2cfc`)

**Agent:** wave-2 `fuzz16` (implementation, isolated worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a90c679fda2991cc3`).
**Base:** `42a324cef` (master HEAD at session start).
**Baseline audited:** the graded CI run `31647430265` at `bf585e448`, read from the
per-suite `_results/results_graphics.json` files (all five carry
`git_sha = bf585e4486b64a263abbd336a51f3baf3cd00a03`).
**Board item:** polish-sweep-arc §15.3 — "depth-1015 placement warning, +1
self-contained"; diagnosis of record = session-14 `w2-fuzz-triage-report.md` §5.

---

## 0. TL;DR — GO

- **GO. +1 effective, exact `pass` (not `ruffle_matched`), 0 regressions in 85
  tests.** `from_shumway/fuzz/e152812e2cfc…` flips `output_mismatch → pass`.
  `from_shumway/fuzz` goes **29/30 → 30/30 effective**; the suite is now clean.
- **Patch is 1 file, 1 condition, 32 lines (28 of them comment):**
  `SWFModernRuntime/src/libswf/tag.c`, inside `tagPlaceObject2` only — the
  "Phase 3" occupied-depth refusal gate at ~line 8591. No other function touched,
  no header, no recompiler.
- **Mechanism (M3, as predicted by s14 §5 and confirmed against Ruffle source):**
  Ruffle's `instantiate_child` warns on `has_child_at_depth(depth)` —
  *character-identity-agnostic*. Our gate additionally required a **different**
  character, so a Place of the *same* character at an occupied depth from a later
  frame never warned. Widened with three replay-excluding guards (§2).
- **The brief's premise is REFUTED (§4).** The brief expected "adjacent territory"
  to the s14 `ASF_SORT_CAP` depth-index-vs-count bug. It is not: the residual gap
  has nothing to do with depth magnitude, the 512 cap, or sorting. Depth 1015 is
  simply the fuzzer's random draw; the same bug fires identically at depth 3.
- **The recommended tick-simulator was not needed (§5).** s14 had already reduced
  the row to one missing line; reading the recompiled `RecompiledTags/tagMain.c`
  (a 10-second grep for `1015`) gave the whole story — two `Move=0` Place tags at
  depth 1015, same char, main frames 8 and 18.

---

## 1. Baseline re-verification

Re-ran the target at `42a324cef` with `--recompile` before touching anything:

```
[1/1] e152812e2cfc… MISMATCH
-   31  Warning: Failed to place object at depth 1015.
```

42 lines produced against 43 expected; the **only** difference is the missing
line 31, everything after it matching with a one-line shift. Exactly the state
s14 §5 recorded. Baseline JSON agrees: `shumway/fuzz/e152812e2cfc… =
output_mismatch`, and the other 29 fuzz rows `pass`.

## 2. The fix

### 2.1 What the SWF does

`RecompiledTags/tagMain.c` for this test:

```c
void frame_7 (…) { …; tagPlaceObject2(app_context, 1015, /*char*/1, /*xform*/2, 0, 0, /*is_replace*/0); … }
void frame_17(…) {     tagPlaceObject2(app_context, 1015, /*char*/1, /*xform*/8, 0, 0, /*is_replace*/0);   }
```

Two `Move=0, HasCharacter=1` Place tags, **same character 1**, same depth 1015,
ten root frames apart, on a straight forward-playing timeline (no goto, no loop —
the movie ends on `getURL("FSCommand:quit")` at frame 24).

### 2.2 What Ruffle does

`core/src/display_object/movie_clip.rs:1494-1498`:

```rust
fn instantiate_child(self, context, id, depth, place_object) -> Option<DisplayObject<'gc>> {
    if self.has_child_at_depth(depth) {
        context.avm_warning(&format!("Failed to place object at depth {depth}."));
        return None;
    }
```

`has_child_at_depth` takes no character id. Both call sites reach it for
`PlaceObjectAction::Place(id)`: the tag-stream path (`place_object`, line 4442)
and `run_goto`'s command replay (line 1828, where a forward — non-rewind — Place
onto an occupied depth falls through to the same arm).

### 2.3 What we did

`tagPlaceObject2`'s Phase-3 gate required
`display_list[depth].char_id != char_id`. That clause is a *proxy* for "this is
not a replay of an already-executed tag" — same-char re-Place is overwhelmingly a
replay (root loop-back, goto catch-up, browser-WASM frame-func re-run), and a
spurious warning is a stdout line, i.e. a graded artefact. The proxy is right
almost always and wrong exactly here.

The patch keeps the proxy and adds one narrowly-guarded alternative:

```c
int ng_same_char_forward_replace =
    (display_list[depth].char_id == char_id
     && display_list[depth].place_gen != g_place_gen
     && display_list[depth].placed_at_frame < current_frame
     && !catch_up_mode);
if (char_id != 0 && !is_replace
    && display_list[depth].char_id != 0
    && (display_list[depth].char_id != char_id || ng_same_char_forward_replace)
    && display_list[depth].placed_at_frame <= current_frame
    && !ng_depth_has_pending_finalize(depth)
    && !g_loopback_replay
    && !catch_up_backward)
```

Guard-by-guard, each one asserting "real forward tag-stream execution":

| guard | why |
|---|---|
| `place_gen != g_place_gen` | a same-generation repeat belongs to the within-frame gate ~line 9040, which already warns. `g_place_gen` advances in `tagShowFrame`, so this means "the occupant came from a different root frame". |
| `placed_at_frame < current_frame` (**strict**) | the occupant came from a strictly *earlier* root frame. A loop-back replay re-runs frame 0 with `current_frame == placed_at_frame`, so it can never satisfy this — a second, independent barrier to the loop case on top of `g_loopback_replay`. |
| `!catch_up_mode` | Ruffle's `run_goto` collects `goto_commands` into a **per-depth map**, so a catch-up spanning N Place tags at one depth executes ONE place. We replay every frame's tag stream, so without this we would over-warn. `catch_up_backward` was already excluded; this covers the forward direction too. |

Note the deliberate asymmetry: `!catch_up_mode` makes us **strictly more
conservative than Ruffle** (Ruffle does warn on a forward goto onto an occupied
depth). That is the safe direction — under-warning leaves a row short, over-warning
injects a line into the graded artefact and regresses unrelated tests. Recovering
the goto case is the residual work noted in §6.

The refusal path is unchanged: clear `g_pending_clip_actions` /
`g_pending_clip_action_count` / `g_pending_instance_name`, `return` without
placing. Behaviourally that matches what the row already did (s14 §5: "our
*placement behaviour* is already right; only the diagnostic is absent") — before
the patch the same-char cross-generation tag fell through to the
`is_replace_of_existing` hot-swap path, which for an identical char is a no-op.

## 3. Results

### 3.1 Headline

| test | before | after |
|---|---|---|
| `from_shumway/fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | `output_mismatch` (42/43 lines) | **`pass`** (exact Flash match) |

`from_shumway/fuzz`: **29/30 → 30/30 effective** (30 `pass`, 0 `ruffle_matched`,
0 mismatch). The block s14 opened is now fully closed.

### 3.2 Canary sweep — 85 tests, 1 change, 0 regressions

Run locally in the worktree, `-P 2` per the shared-machine cap, no-graphics mode.
Every result compared against the `bf585e448` per-suite baseline JSON, not against
memory. **The only status change in 85 tests is the target.**

| canary set | tests | after | vs baseline |
|---|---:|---|---|
| **all 30 `from_shumway/fuzz`** (the s14 canary set) | 30 | 30 `pass` | 29 unchanged, **1 flip** `output_mismatch→pass` |
| `avm1` execution-order + depth + placeobject family | 13 | 13 `pass` | unchanged |
| `from_gnash/misc-ming.all` place/replace family | 5 | 2 `pass`, 3 `ruffle_matched` | unchanged |
| `from_gnash/misc-ming.all/loop` (all 11) | 11 | 8 `pass`, 3 `ruffle_matched` | unchanged |
| `from_gnash/misc-ming.all/displaylist_depths` (all 11) | 11 | 8 `pass`, 3 `ruffle_matched` | unchanged |
| `from_shumway/avm1` depth + duplicateMovieClip + doactionorder leaves | 7 | 7 `pass` | unchanged |
| `regression` suite — timeline / frame-event / mask subset | 8 | 8 `pass` | unchanged |
| **total** | **85** | | **1 change, 0 regressions** |

The `ruffle_matched` rows are baseline-`ruffle_matched`, checked individually
against the `bf585e448` JSON (`place_object_test`, `place_object_test2`,
`replace_buttons1test`, `loop_test6/7/10`, `displaylist_depths_test`/`2`/`3`) —
none is a `pass → ruffle_matched` demotion.

Full canary roster, by name:

- **fuzz (30):** all sha256 dirs under `from_shumway/fuzz`.
- **avm1 (13):** `execution_order1..4`, `goto_execution_order`,
  `goto_execution_order2`, `placeobject_occupied_depth`, `rewind_depth`,
  `depth_replacement_audio_unloading`, `movieclip_depth_methods`,
  `movieclip_get_instance_at_depth`, `bad_placeobject_clipaction`,
  `placeobject_all_event_flags`.
- **gnash misc-ming (27):** `place_object_test`, `place_object_test2`,
  `replace_buttons1test`, `replace_shapes1test`, `replace_sprites1test`;
  `loop/loop_test`..`loop_test10` + `simple_loop_test`;
  `displaylist_depths/displaylist_depths_test`..`_test11`.
- **shumway avm1 (7):** `depth`, `duplicateMovieClip/{dontremove,duplicateMovieClip,name-coercion,samedepth}`,
  `doactionorder/{doactionorder,symbolclass}`.
- **regression (8):** `enterframe_type1_args`, `mc_event_type1_args`,
  `onunload_type1_args`, `onunload_type1_local_frame`,
  `root_enterframe_cross_swf_version`, `avm2_goto_catchup_scale`,
  `mask_nested_intersect`, `mask_sibling_union`.

The three highest-risk families for this patch are all in the set and all
unchanged: the ones that *already expect* this warning
(`avm1/placeobject_occupied_depth`, gnash `place_object_test*`), the ones that
re-place at occupied depths during loop-back (`loop/*`), and the ones that
re-place during goto catch-up (`goto_execution_order*`, `avm2_goto_catchup_scale`).

## 4. Refutation: the brief's "adjacent territory" premise

> *"the s14 ASF_SORT_CAP bug was depth-index-vs-count above depth 512 — the
> depth-1015 warning row is likely adjacent territory."*

**Refuted, cleanly.** The residual gap is unrelated to `ASF_SORT_CAP`, to the 512
threshold, to `max_depth`, and to `advance_sprite_frames` altogether. It lives in
`tagPlaceObject2`'s character-identity guard, and it is depth-agnostic: the same
two-Place-tags-same-char-same-depth pattern misses the warning at depth 3 exactly
as at depth 1015. The `1015` in the expected-output string is the fuzzer's random
draw, nothing more — s14's own §5 already said so ("the character is the *same*
and the generations differ"), and the brief's framing came from the *test name in
the row label*, not from that diagnosis. This is the
[[worklist-labels-name-symptoms-not-owners]] trap in miniature: the row label
("depth-1015 placement warning") names the symptom string, and reading it as a
depth-magnitude claim points at the wrong file.

Practical consequence: had I started at `ASF_SORT_CAP` I would have burned the
slot. **Reading s14's §5 first, exactly as the brief instructed, is what made this
a 30-minute fix.** The brief's *priority* was right and its *mechanism gloss* was
wrong — the same split s14 §7 flagged for the parent block.

## 5. Method note: the simulator was correctly skipped

The brief recommended s14's fixture-fitted Python tick-simulator. It was not
needed and would have been a detour: the row's gap was already a *single known
line*, so there was nothing about expected timeline order left to derive. The
cheap step that did the work was **reading the recompiled tag stream**
(`grep -n 1015 RecompiledTags/*.c` → two `tagPlaceObject2` calls with identical
char id), which converts "why no warning?" into "which gate clause excludes
same-char?" in one hop. Generalisable rule: **the simulator earns its keep when
the gap is an ordering/count question; when the gap is one known string, go to the
generated C.**

## 6. Residual / follow-up

- **Forward goto over an occupied depth still under-warns.** Ruffle's `run_goto`
  hits `instantiate_child` (and therefore warns) for a non-rewind Place onto an
  occupied depth; our `!catch_up_mode` guard suppresses that. Taking it needs the
  per-depth dedup Ruffle applies to `goto_commands` — our engine replays each
  intermediate frame's tag stream, so a naive lift would emit N warnings where
  Ruffle emits one. No corpus row is currently known to demand it; recording it so
  the next owner does not re-derive the reasoning.
- **No disposition-doc change needed.** Checked `ACCEPTED_DIFFS.md`,
  `RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`,
  `FLASH_BUGS_REPLICATED.md` and `ruffle-tests/ignored_tests.txt` before
  implementing — `e152812e2cfc` appears in none of them, and the fix reaches exact
  Flash agreement, so nothing to add.

## 7. Merge notes

| file | function(s) touched | mechanism |
|---|---|---|
| `SWFModernRuntime/src/libswf/tag.c` | **`tagPlaceObject2` only**, the Phase-3 occupied-depth refusal gate (one added local `ng_same_char_forward_replace` + one widened clause, ~line 8591) | M3 |

- **Self-localisation / sibling overlap.** The patch adds a uniquely-named local
  (`ng_same_char_forward_replace`) and edits one `if` condition. It does **not**
  touch `advance_sprite_frames`, `advance_nested_sprite_frames`,
  `dispatch_enterframe_clip_actions_recursive`, `tagShowFrame`, any action-queue
  drain, or `action.c` at all — so no textual overlap with **w2-watch-order**
  (watch/virtual-setter dispatch in `action.c`) or **w2-action-order** (AVM1
  tick/action ordering). The two other `Warning: Failed to place object` sites in
  `tag.c` (the within-generation gate ~line 9040 and the `tagPlaceObject2Ratio`
  copy ~line 9470) are deliberately **left alone**: neither is on this row's path,
  and widening them has its own blast radius.
- **Recompiler untouched** → generated C is byte-identical, `Recompiled*` caches
  corpus-wide stay valid, no `--recompile` semantics required beyond a normal run.
- **Suggested CI:** `mode=graphics`, `categories=all`. Shared AVM1 timeline
  runtime, not a `NO_GRAPHICS`-only arm; the weekly no-graphics canary covers the
  other side.
- **Blast radius.** The new branch is reachable only for a SWF that executes two
  `Move=0 / HasCharacter=1` PlaceObject2 tags for the *same* character at the
  *same* depth on *different* root frames, in normal forward play (no loop-back,
  no goto catch-up, no pending finalize at that depth). Authoring tools emit
  `Move=1` for a re-place, so this is an authoring-error shape — which is precisely
  why Flash warns about it. Empirically: 85 tests spanning every place/replace/
  loop/goto family in the corpus, and only the target changed.

## 8. Deliverables

- Patch: `w2-fuzz16.patch` (worktree root; copied to the main tree).
- This report: `SWFRecompDocs/plans/session15-fanout-reports/w2-fuzz16-report.md`.
