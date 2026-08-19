# Wave-2 — `w2-timeline-s1s2` — S1 (AVM2 fscommand-quit) + S2 (AVM1 frames_loaded split)

Session 17, dual-axis fan-out #9. Worktree `agent-a9ec06aac1dd3a346`, HEAD `88ebde665`.
Diagnosis of record: `wave1-timeline-order.md` §3 (S1) and §4 (S2).
All measurements: local `--mode=graphics --diff --verbose`, `SWFRECOMP_COMPILE_TIMEOUT=2400`,
batches capped at `-P 2`. Baselines read from the graphics stem of
`origin/ruffle-test-results` (run `31877239992`), never `results.json`.

## NEW FILES (coordinator: stage these by name)

**No new source files.** Both patches modify existing files only. The three
deliverables below are new files under `SWFRecompDocs/plans/session17-fanout-reports/`:

- `w2-timeline-s1.patch`
- `w2-timeline-s2.patch`
- `w2-timeline-s1s2-report.md` (this file)

No new headers, so the `verify_output.py:2154` explicit-source-list trap (s16) does
not apply. `SWFModernRuntime/include/libswf/tag.h` gains one declaration and
`include/libswf/swf.h` two struct fields — both are existing, already-copied headers.

---

## 0. Verdicts

| Slice | Verdict | Priced | Delivered | Patch |
|---|---|---|---|---|
| **S1** AVM2 `fscommand("quit")` ends the tick loop | **GO — landed** | +1 | **+1** (`avm2/button_nested_frame_simple` → `pass`) | `w2-timeline-s1.patch` (1 file, +20) |
| **S2** AVM1 sprite `frames_loaded` split + `NextFrame::Same` fall-through | **GO — landed** | +3 (+1 rider) | **+4** (`avm1/looping_child_swf{5,9,32}` + rider `avm1/shared_stack`, all → `pass`) | `w2-timeline-s2.patch` (5 files, +121/−7) |

**Combined: +5 trace flips, 0 regressions across 77 graded rows.**
Final confirmation on the **combined** tree (both patches applied, recompiler
rebuilt): `avm2/button_nested_frame_simple` PASS, `avm1/looping_child_swf5` PASS,
`avm1/shared_stack` PASS, `from_shumway/fscommand1` PASS.
Wave 1's pricing survived intact on both slices, and the S2 rider it flagged as
"probable, unverified" is confirmed.

Two of wave 1's *cost* claims are refuted (§4.4): S2 does **not** invalidate the
corpus-wide `Recompiled*` cache (50 tests change, not ~1450), and its runtime edit
is provably a no-op for every sprite that does not change (§4.2).

---

## 1. S1 — AVM2 `fscommand("quit")` must end the tick loop

### 1.1 Premise audit — wave 1 confirmed, with one correction of my own

Re-verified locally at HEAD before touching anything:

| Claim (wave 1 §3) | Verdict |
|---|---|
| `avm2/button_nested_frame_simple` is 27/27 matching, 39 actual | **Confirmed** (`output_mismatch`, 27/27, actual 39) |
| The 12 extra lines are exactly two spare ticks | **Confirmed** — lines 28–32 and 33–39, each opening with `Main enter frame`, a string that appears nowhere in `output.txt` |
| The §17.4 framing "child framescripts firing twice" is a second defect | **Confirmed refuted** — expected lines 16–19 already contain the pair twice, because `MyContainer` holds two `MyChild` instances |
| `avm2_main.c:840-881` has no quit gate | **Confirmed** — bare `for (tick…)`, no `break` |
| `avm2_globals.c::global_fscommand` sets `quit_swf` **and** `g_force_quit` | **Confirmed** (`avm2_globals.c:6738-6744`) |
| Ruffle authority `runner.rs` drains fs_commands *after* the tick | **Confirmed** — and the fixture proves the "finish the tick" semantics: `fscommand("quit")` is the **last statement of `MyContainer`'s constructor** (`MyContainer.as:29`), which traces at expected lines 23–24, yet expected lines 25–27 (`frameConstructed` + two `exitFrame`) still follow |

**My correction to wave 1's patch sketch.** Wave 1 proposed the gate "inside the
tick loop after `avm2_try_pop_frame(&top)` (≈ line 869)". That position sits
*between* `avm2_try_pop_frame` and the `heap_peak_since_mark_bytes` accounting, so
breaking there would silently drop the quitting tick from the
`AVM2_HEAP_STATS` worst-transient statistics. The gate is placed at the **end of
the loop body** instead, after the accounting. Same semantics, no telemetry hole.

**Mode symmetry (the brief asked explicitly).** The gate is **identical in both CI
arms and is not graphics-only.** `g_force_quit` has exactly two definitions —
`libswf/graphics_stubs.c:51` (compiled in `--mode=graphics`) and
`libswf/swf_core.c:35` (compiled in no-graphics) — and `verify_output.py`
(:2179-2189) links exactly one of them into every AVM2 build. The `extern int`
declaration resolves in both. Nothing in the gate is inside `#ifdef
OFFSCREEN_RENDER`.

### 1.2 Patch

`SWFModernRuntime/src/avm2/avm2_main.c`, +20 lines (17 of them comment), one hunk
at the tail of `runSWF_avm2`'s tick loop:

```c
{
    extern int g_force_quit;
    if (g_force_quit) break;
}
```

`quit_swf` is deliberately **not** read: the recompiler emits `quit_swf = 1` as an
ordinary end-of-movie marker, and reading it would truncate every non-looping
movie — the exact bug `libswf/swf.c:468-471` documents on the AVM1 side.

No recompiler change, no `Recompiled*` invalidation.

**Sibling overlap:** `w2-avm2-smalls` and `w2-crossvm-legE` also touch
`avm2_main.c`/`avm2_display.c`, but for super-dispatch coercion and the AVM1-child
tick respectively. This hunk is inside `runSWF_avm2`'s loop body; textual overlap is nil.

### 1.3 S1 ledger — 17/17 green, +1

| Test | Baseline (graphics CI) | After S1 |
|---|---|---|
| **`avm2/button_nested_frame_simple`** | `output_mismatch` 27/27, actual 39 | **`PASS` 27/27** ✅ **FLIP** |
| `from_shumway/fscommand1` | pass | pass |
| `from_shumway/timeline/timeline_loop` | pass | pass |
| `from_shumway/timeline/scene/Scene_1_MainTimeline` | pass | pass |
| `from_shumway/timeline/scene/Scene_6_GotoAndPlay_FrameScene` | pass | pass |
| `from_shumway/timeline/scene/Scene_7_NextPrevScene` | pass | pass |
| `from_shumway/flash_events_Event` | pass | pass |
| `from_shumway/as3-loader/LoaderTest2` | pass | pass |
| `timeline/frame_script_cleanup` | pass | pass |
| `timeline/frame_script_construct` | pass | pass |
| `timeline/frame_script_cleanup_goto` | pass | pass |
| `timeline/swf_9_frame_script_cleanup_goto2` | pass | pass |
| `timeline/frame_script_button_order` | ruffle_matched | ruffle_matched |
| `avm2/register_script_refresh` | pass | pass |
| `avm2/mouse_over_while_dragging` | pass | pass |
| `regression/avm2_timeline_solid` | pass | pass |
| `regression/avm2_goto_catchup_scale` | pass | pass |

16 canaries drawn from wave 1's 41-row `fscommand`+`quit` blast radius (the M1 set
plus 8 more from the scanner list, biased toward AVM2 timeline/scene navigation,
which is where a premature loop exit would show first). All measured on a tree
carrying **S1 only** — S2 was not applied until this batch completed, so the
attribution is exact.

**Canary blind spot:** the graded 17 cover the AVM2-timeline and shumway-runner
families. The 24 ungraded green rows in the blast radius are mostly
`from_shumway/as3-loader/*` and `timeline/swf_9_frame_script_*`, of which four
representatives are in the table above and all held.

---

## 2. S2 — AVM1 sprite `frames_loaded` vs the DefineSprite header count

### 2.1 Premise audit — wave 1 confirmed, and the mechanism is worse than described

Wave 1's 24-cell decode of `looping_child_swf5` reproduces exactly
(`declared × ShowFrames × End-tag` matrix, chars 1–24). Confirmed independently
with my own decoder.

What wave 1 **under-stated**: the current code does not merely mis-count frames,
it reads **past the end of the generated frame-function array**. The recompiler
emits `sprite_<id>_frame_funcs[]` with one entry per *generated frame function*
but hands `tagDefineSprite` the **header** count, and `advance_sprite_frames`
(`tag.c:1562`) bounds its indexing with that header count:

```c
if (frame < ch->sprite_frame_count && ch->sprite_frame_funcs[frame] != NULL)
    CALL_FRAME(app_context, obj, ch->sprite_frame_funcs[frame]);
```

For char 7 (`declared = 2`, one generated function) that calls
`sprite_7_frame_funcs[1]` — one past the end — and jumps to whatever function
pointer the linker put next. The baseline actual output shows exactly that: at
tick 2 we emit `sprite 9, frame 1`, `sprite 6, frame 1`, `sprite 7, frame 1` —
*other sprites' frame-0 functions*, called through an out-of-bounds array read.
`avm2/stage_framerate_nan` declares **44314** frames for a one-function sprite.
So S2 is also an out-of-bounds-read fix, not only a semantics fix.

`avm1/shared_stack` (wave 1's "probable rider, unverified") is the mirror-image
cell: `declared = 1`, two ShowFrames, no End tag → the clip was treated as a
1-frame clip and skipped by the `sprite_frame_count <= 1` guard at `tag.c:1444`,
so the child's frame 2 never ran. Its baseline diff is exactly that signature
(11/16, actual 12, missing `in child frame 2/1` and `2/2`). **Confirmed and
flipped.** Wave 1 is right that `avm1/_investigation/CURRENT_STATUS.md:31`
mis-files it under "the AVM1 value stack shared across clips within a tick";
the value stack was never the problem.

### 2.2 The model, in our indices

Three numbers per sprite, where wave 1's report used two:

| Name | Meaning | Used for |
|---|---|---|
| `sprite_declared_frames` | DefineSprite header `frameCount`, verbatim | AS-visible `_totalframes` / `_framesloaded` only |
| `sprite_loaded_frames` (`L`) | Ruffle `frames_loaded` = ShowFrame count, floored at 1 | loop-vs-stop decision |
| `sprite_frame_count` (`N`) | generated frame functions (`= L`, or `L+1` when tags trail the last ShowFrame) | array bound, stepping, gotos |

`advance_sprite_frames`'s next-frame rule becomes Ruffle's `determine_next_frame`
plus the `NextFrame::Same` fall-through, expressed on the 0-based index of the
frame we just ran:

```
frame >= L                 -> park          (we just ran the trailing partial; it runs once)
frame + 1 < L              -> frame + 1     (NextFrame::Next)
L <= 1 || !has_end_tag     -> Same: step into the trailing partial if one exists,
                              else the pre-existing park / (frame+1)%N behaviour
otherwise                  -> 0             (NextFrame::First)
```

**This is provably identical to the old code for every sprite where the three
numbers agree** (`L == N == declared`): `frame >= L` is unreachable, `frame+1 < L`
gives `(frame+1)%N`, the `L<=1 || !end` arm reduces verbatim to the old
`frame+1>=N && !end ? park : (frame+1)%N`, and the last arm gives `0 == (frame+1)%N`.
That equivalence is what bounds the blast radius (§2.4).

Hand-check against the 24-cell fixture: chars 1–10 emit frame 1 only; 11–18
(`L=1`, `N=2`) emit frame 2 once via the fall-through then go silent; 19–21
(`L=2`, End tag) loop forever; 22–24 (`L=2`, no End tag) emit frame 2 once and
park. That is expected lines 1–141 exactly, and all three tests now `PASS`.

### 2.3 Patch

5 files, +121/−7:

| File | Change |
|---|---|
| `SWFModernRuntime/include/libswf/swf.h` | 2 trailing fields on the DefineSprite arm of the `Character` union |
| `SWFModernRuntime/include/libswf/tag.h` | declaration of `tagSetSpriteFrameCounts` |
| `SWFModernRuntime/src/libswf/tag.c` | `tagDefineSpriteEx` sets the two new defaults; new `tagSetSpriteFrameCounts`; `totalframes`/`framesloaded` read `sprite_declared_frames`; the next-frame rule above |
| `SWFModernRuntime/src/libswf/tag_stubs.c` | attachMovie's `totalframes`/`framesloaded` read `sprite_declared_frames` |
| `SWFRecomp/src/swf.cpp` | count ShowFrames while parsing the DefineSprite body; emit `tagSetSpriteFrameCounts(app_context, id, N, L)` after `tagSetSpriteNoEndTag`, **only when the header disagrees with the body** |

**No arity change to any existing runtime entry point.** The brief flagged the s16
morph precedent — it does not apply here. `tagDefineSprite`'s variadic macro
(`tag.h:179-182`) and its 4th argument are untouched; the split arrives through a
*new* call. I also checked `docs/recompiler/runtime_headers/`: that mirror is
regenerated by `SWFRecomp/scripts/deploy_wasm_demo.sh` and is **already stale**
(it lacks `tagSetSpriteNoEndTag`, landed long ago, and `sprite_has_end_tag`), so it
imposes no sync obligation and nothing in the build reads it. Flagging it as
pre-existing doc drift rather than touching it.

**AS-visible behaviour is deliberately frozen.** `_totalframes` and `_framesloaded`
keep reading the declared header field exactly as today, so the patch cannot move
any test through the AS surface — only through playback. (Ruffle reports
`_framesloaded = frames_loaded`, i.e. the ShowFrame count; changing that too would
be more Ruffle-correct but would touch 50 tests' AS-visible values for zero priced
gain, so it is left as a named follow-up in §5.)

**Sibling overlap:** `w2-gfx-cab-pixelsnap` edits `swf.cpp` ~:4313 (PlaceObject3
BitmapCache) and `tag.c`'s display-entry structs / `compose_children`. My swf.cpp
hunks are at ~:5195, ~:5245 and ~:6300 (the DefineSprite body parser and tail);
my `tag.c` hunks are in `tagDefineSpriteEx`, `process_sprite_needs_init`'s
counter write, and `advance_sprite_frames`'s tail. My `swf.h` fields are **trailing
fields on the DefineSprite union arm**, per the self-localization rule, so a
sibling adding fields to the display-entry structs will not collide.

### 2.4 Blast radius — full-corpus recompiler A/B (the brief's mandate)

Method: every `test.swf` under `avm1/`, `from_gnash/`, `from_shumway/`,
`regression/`, `timeline/` (1457 tests) recompiled twice into fresh temp dirs —
once with the pre-patch `SWFRecomp`, once with the post-patch one — and the whole
generated tree SHA-256'd. Script: `scratchpad/w2timeline/ab_sweep.py`.

> **Methodology trap worth recording.** The first A/B reported **85** changed
> tests. 33 of those were an artefact of my own harness: `SWFRecomp` locates
> `assets/NotoSans.ttf` relative to `argv[0]` (`swf.cpp:74-89`), so the baseline
> binary I had copied into the scratchpad silently lost device-font glyph
> tessellation and emitted a different `shape_data[]`. **Any A/B that stages an
> old recompiler binary must reproduce the `build/` + `../assets/` layout**, not
> just copy the ELF. Re-run with `baseroot/{build,assets}` in place: **52**.

Of those 52, **2 are pre-existing recompiler nondeterminism, not my change**:
`avm1/edittext_newline_stripping` and `from_shumway/3_joystick` emit a raw heap
pointer into the 4th column of `shape_data[]` (`0x72037570` vs `0x62B7C570`).
Running the *same* binary twice on the same SWF reproduces the difference
(`scratchpad/w2timeline/determinism.sh`), so it is unrelated. Both are graded below
anyway and both hold.

**True changed set: 50 tests**, matching a pure-SWF prediction computed
independently (`scratchpad/w2timeline/predict.py`) — and matching wave 1's
"63 tests corpus-wide" once the 13 AVM2-side suites it counted are added back
(50 + 13 = 63, exact agreement).

Every changed test's generated-C delta was diffed line by line
(`scratchpad/w2timeline/verify_diffs.py`): **the delta is nothing but added
`tagSetSpriteFrameCounts(...)` lines** — zero removals, zero new/removed files —
for all 50.

Composition of the 50:

| Class | Count | Emitted call | Runtime effect |
|---|---|---|---|
| `declared = 0`, no ShowFrame or one | 43 | `(id, 1, 1)` | playback count 0 → 1; inert except that a no-End-tag clip is now `stop()`ed on its allocation tick (Ruffle-correct) |
| `declared > N` (**out-of-bounds read today**) | 4 | e.g. `(2, 1, 1)` | OOB call through `frame_funcs[declared-1]` eliminated |
| `declared < N` | 1 | `(1, 2, 2)` | `shared_stack`: clip no longer mis-classified as 1-frame |
| trailing partial frame (`N = L+1`) | 3 | `(…, 2, 1)` etc. | the `NextFrame::Same` fall-through — the three headline rows |

**This refutes wave 1's cost estimate.** §4 priced S2 as "invalidates every
`Recompiled*` cache corpus-wide → both CI modes". It invalidates **50 of ~4450
tests' generated C**; every other test recompiles byte-identically. The CI-mode
question is separate and unchanged: the runtime half touches `tag.c`/`tag_stubs.c`,
which both arms compile, so **run both modes** — but for coverage, not for cache.

### 2.5 S2 ledger — 61 rows graded, 4 flips, 0 regressions

**Flips (all four → `PASS`):**

| Test | Baseline | After S2 |
|---|---|---|
| `avm1/looping_child_swf5` | `output_mismatch` 38/141, actual 207 | **`PASS` 141/141** ✅ |
| `avm1/looping_child_swf9` | `output_mismatch` 38/141, actual 207 | **`PASS` 141/141** ✅ |
| `avm1/looping_child_swf32` | `output_mismatch` 38/141, actual 207 | **`PASS` 141/141** ✅ |
| `avm1/shared_stack` | `output_mismatch` 11/16, actual 12 | **`PASS` 16/16** ✅ (rider confirmed) |

**Held (unchanged status), 57 rows.** Every row of the A/B changed set that is a
graded test, plus non-emitting sanity canaries from the brief's M2 list:

*OOB-fix rows:* `avm1/target_paths/swf4` pass→pass, `swf5` ruffle_matched→ruffle_matched,
`swf6` ruffle_matched→ruffle_matched, `from_gnash/misc-swfmill.all/zeroframe_definesprite`
ruffle_matched→ruffle_matched, `avm2/stage_framerate_nan` pass→pass.

*`declared=0` rows (43-test class), graded 34:* `attach_movie_stop`, `clone_sprite_types`,
`placeobject_occupied_depth`, `place_and_lookup`, `do_init_action_child`,
`removed_target_clip_scope`, `set_target_2_swf5`, `sound_nested_clips`,
`sound_owner_tostring_fail`, `clip_constructors`, `on_construct`,
`register_and_init_order`, `init_object_order`, `native_objects_swf6`,
`native_objects_swf7`, `native_objects_swf8`, `tab_ordering_tabbable`,
`array_sort_random`, `as2_oop`, `as2_super_and_this_v6`, `as2_super_and_this_v8`,
`as2_super_via_manual_prototype`, `bitmap_data_copypixels`,
`coerce_to_primitive_resolve`, `edittext_newline_stripping`, `extends_chain`,
`extends_native_type`, `loadmovie_registerclass`, `localconnection`,
`movieclip_init_object`, `netconnection_send_remote`, `resolve_different_root`,
`stylesheet`, `timer_run_actions`, `watch`, `xmlnode_proto` (all avm1);
`from_shumway/3_joystick`, `from_shumway/avm1/doactionorder/symbolclass`,
`timeline/clip_action_no_key_code`, `regression/avm2_timeline_solid`,
`regression/avm2_timeline_gradients`, `regression/avm2_timeline_stroke_gradient`,
`avm2/zero_frame_clip`, `avm2/movieclip_frameconstruct_skipped`,
`avm2/place_and_lookup/swf9`, `avm2/swf_9_queued_goto_scripts_construct`,
`swf/convolution_filter_big_matrix`, `visual/filters/bevel_inner`,
`visual/edittext/edittext_bounds_vs_position` — every one holds its baseline status.

*Non-emitting sanity rows (M2 list):* `avm2/swf_wrong_frame_count` pass→pass,
`regression/enterframe_type1_args` pass→pass, `regression/mc_event_type1_args` pass→pass.

**Apparent failures investigated — all pre-existing, none caused by S2:**

- `avm1/native_objects_swf6` — `output_mismatch` 114/115 before **and** after, same
  single diff line (`new TextField(): non-object: undefined`). Unchanged.
- Four rows report a failing **image** comparison. Image comparisons never gate
  trace pass/fail, and all four trace as `PASS` — but three of them also carry an
  emitting sprite, so I measured the pixel axis directly rather than assuming.
  **Method:** `git apply -R w2-timeline-s2.patch`, full recompiler rebuild, re-run
  with `--recompile`, then re-apply and rebuild (never `git stash` — `refs/stash`
  is shared across worktrees). Local Dawn is byte-deterministic, so this is a
  valid same-machine A/B:

  | Test | pre-S2 (local) | post-S2 (local) | CI baseline row |
  |---|---|---|---|
  | `visual/filters/bevel_inner` | 48134 outliers, max 254 | **48134, max 254** | 66782 |
  | `visual/edittext/edittext_bounds_vs_position` | 1077 outliers, max 255 | **1077, max 255** | 1080 |
  | `avm1/bitmap_data_copypixels` | 840 outliers, max 1 | **840, max 1** | 840 |
  | `from_shumway/3_joystick` | 307 outliers, max 255 | **307, max 255** | 307 |

  **S2's pixel delta is exactly zero on all four.** The two rows that differ from
  the stored CI numbers (66782→48134, 1080→1077) differ *before* the patch too —
  it is local-vs-CI Dawn, precisely the comparison
  `graphics-fanout-playbook.md` warns never to make against a golden PNG. No
  pixel-axis movement is expected from either patch.

**Ungraded from the changed set:** `avm1/__framework__` (no `output.txt`/`test.toml`
— not a graded test) and `avm1/shared_object` (in `ruffle-tests/ignored_tests.txt`
since it never appears in results). Both non-rows. Of the 13 AVM2-side emitting
tests, 7 are graded above; the 6 ungraded (`avm2/place_and_lookup/swf10`,
`avm2/swf_10_queued_goto_scripts_construct`, `visual/filters/bevel_full`,
`bevel_outer`, `glow_with_alpha_strength`) are byte-for-byte the same
`declared = 0 → (id, 1, 1)` class as their graded twins.

---

## 3. What CI should run

- **Both modes.** S1's gate is mode-symmetric by construction but is new control
  flow in the shared AVM2 loop; S2's runtime half lives in `tag.c`/`tag_stubs.c`,
  which `graphics` and `no-graphics` both compile. Per the CLAUDE.md rule for
  shared runtime code: run `graphics` per-change and let the change ride the
  `no-graphics` canary, or dispatch both if a slot is free.
- **`categories=all` is sufficient.** Neither patch touches AVM2 recompiler
  emission or the ABC pipeline, so `full` is not required. (S1 does touch the AVM2
  *runtime* tick loop; the 41-row `fscommand` blast radius is entirely inside the
  classic five suites plus `timeline`, which `all` covers.)
- **`images=false`.** Neither patch renders anything new; the two image failures
  above are pre-existing baseline rows.

---

## 4. Findings worth carrying forward

1. **`declared > generated` is an out-of-bounds function-pointer call, not just a
   wrong count** (§2.1). Four corpus tests hit it today, one of them with a header
   claiming 44314 frames. Fixed here as a side effect; worth a line in the
   architecture notes because the same shape (recompiler emits an array, runtime
   bounds it with a *different* number from the SWF header) may exist elsewhere.
2. **The recompiler is not byte-deterministic for SWFs with device-font text.**
   `avm1/edittext_newline_stripping` and `from_shumway/3_joystick` bake a raw heap
   pointer into `shape_data[]`'s 4th column; two runs of the same binary on the
   same SWF differ. It appears to be an opaque grouping key so compiled behaviour
   is presumably unchanged, but it defeats any generated-C hashing (and would
   defeat a content-addressed recompile cache). Repro:
   `scratchpad/w2timeline/determinism.sh <test>`.
3. **Staging an old recompiler binary requires its asset layout** (§2.4 box).
   `swf.cpp:74-89` probes `assets/`, `../assets/`, `SWFRecomp/assets/` and
   `argv[0]/../assets/`. A bare `cp` of the ELF into a scratch dir produces a
   *silently different* recompiler. This inflated my first A/B from 52 to 85.
4. **Doc rows to correct** (for the closeout agent), extending wave 1's list:
   - `avm1/_investigation/NEW_UPSTREAM_AVM1_TRIAGE.md:86-89` and
     `CURRENT_STATUS.md:31` — re-file `looping_child_swf{5,9,32}` **and
     `shared_stack`** out of "Multi-SWF child-frame execution" / "AVM1 value stack
     shared across clips"; both are the sprite frame-count rule. All four now pass.
   - `polish-sweep-arc.md` §17.4 — S1 and S2 are done (+5); the remaining rows are
     wave 1's S3+S4 (HOLD) and the four NO-GOs.

---

## 5. Follow-ups this patch deliberately does not take

- **`_framesloaded` should be Ruffle's `frames_loaded`, not the header count.**
  The plumbing now exists (`sprite_loaded_frames`); the one-line change is
  `tag.c`'s `child_mc->framesloaded = (int)ch->sprite_loaded_frames`. Held back
  because it moves an AS-visible value on ~50 tests for no priced gain.
  **Completion mechanism:** grade the 50-row A/B changed set with that one line
  flipped; if it is clean, it is a free correctness win.
- **Wave 1's S3+S4 (`timeline/missing_frame_scripts`) remain HOLD**, untouched
  here. S3 (`!has_end_tag` in AVM2 `determine_next_frame`) is the exact AVM2 twin
  of the rule S2 just landed on the AVM1 side, and is now cheaper to write than
  wave 1 estimated — but it still flips nothing without S4, whose cause wave 1
  could not pin. **Completion mechanism unchanged:** instrument the orphan clip's
  `current_frame`/`playing` across ticks 1→2.

---

## 6. Reproduction artefacts

Scratchpad `/tmp/claude-1000/.../scratchpad/w2timeline/`:

| File | Purpose |
|---|---|
| `ab_sweep.py` | corpus-wide recompiler A/B (binary → `{test: sha256}`) |
| `ab_old2.json` / `ab_new.json` | the two hash sets (1457 tests each) |
| `changed.txt` | the 52 hash-differing tests |
| `verify_diffs.py` | per-test generated-C diff, asserts "only `tagSetSpriteFrameCounts` added" |
| `predict.py` | pure-SWF prediction of the changed set (independent cross-check) |
| `determinism.sh` | same-binary twice, proves finding #2 |
| `showdiff.sh` | one-test old-vs-new generated-C diff |
| `pixab_tests.txt` + `logs/pixpre_*.log` | the pre-S2 leg of the pixel A/B in §2.5 |
| `apply_s2.py` | the S2 edits as anchored replacements (`S2_CHECK=1` for a dry run) |
| `logs/{base,s1,s2,s2b,s2c}_*.log` | every graded run's full `--diff --verbose` output |
