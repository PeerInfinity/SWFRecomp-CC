# Wave-1 — timeline-order arc (`w1-timeline-order`), session 17

Read-only diagnosis. No source edits, no commits. HEAD `88ebde665`.
All measurements are local `--mode=graphics --diff --verbose` single-test runs
with `SWFRECOMP_COMPILE_TIMEOUT=2400`, cross-checked against the CI baseline
(`origin/ruffle-test-results` `results_graphics.json`, run `31877239992`).

## 0. Headline

**The board's "timeline-order arc, 12 rows, worth a solo session" is not one arc.
It is 8 unrelated mechanisms, 4 of them already NO-GO'd with evidence in prior
sessions, 1 already dispositioned, and 2 genuinely new and independently
shippable.** Two slices are GO tonight; the rest should be struck from the board
or carried with the completion mechanism named below.

| Verdict | Slice | Rows | Priced flip |
|---|---|---|---|
| **GO (take first)** | **S1** AVM2 `fscommand("quit")` must end the tick loop | `avm2/button_nested_frame_simple` | **+1**, ~6 lines, one file, no cache invalidation |
| **GO (bigger, riskier)** | **S2** AVM1 sprite `frames_loaded` ≠ declared header frame count | `avm1/looping_child_swf{5,9,32}` (+ probable rider `avm1/shared_stack`) | **+3 (+1 rider)**, recompiler + runtime, both CI modes |
| HOLD (pair required) | **S3** AVM2 `has_end_tag` loop rule + **S4** AVM2 orphan one-tick stall | `timeline/missing_frame_scripts` | +1 only if both land |
| **NO-GO** | S5 action_order `test11` / `extend_test` (D1/D2 pipeline arc) | 2 | 0 — re-verified, unchanged since s14/s15 |
| **NO-GO** | S6 `ActionOrderTest3/4/5` | 3 | 0 — blocked plans, 3 reverted attempts, `ruffle_matched` unreachable |
| **NO-GO** | S7 `action_execution_order_test6` | 1 | 0 — needs D1 **and** a construct-filter change |
| **NO-GO** | S8 `action_order/PlaceAndRemove` | 1 | 0 — 2 mechanisms + Ruffle panics ⇒ only exact 96-line Flash parity scores |
| **STRIKE** | `register_class/RegisterClassTest4` | 1 | already in `ACCEPTED_DIFFS.md` **and** `from_gnash/misc-ming.all/ignored_tests.txt` since 2026-05-08 |

**Recommendation for tonight's wave-2 agent: take S1.** It is the only row on
this board whose *entire expected output already matches ours byte-for-byte* —
27/27 lines — with the failure being purely 12 trailing lines we should never
have produced. It is one file, no recompiler change, no `Recompiled*`
invalidation, and it has an exact Ruffle authority
(`tests/framework/src/runner.rs:250`). If the agent has slot left, S2 second.

---

## 1. Re-baseline of the rows the board flagged as stale — REFUTED

Leg C (s16) warned that the stored `results_graphics.json` rows for
`ActionOrderTest3/4` and `RegisterClassTest4` might be stale. Re-run locally at
HEAD `88ebde665` in graphics mode:

| Row | stored `results_graphics.json` | local re-run at HEAD | verdict |
|---|---|---|---|
| `action_order/ActionOrderTest3` | 4/62, actual 73 | 4 matching, actual 73 | **not stale** |
| `action_order/ActionOrderTest4` | 10/64, actual 105 | 10 matching, actual 105 | **not stale** |
| `action_order/ActionOrderTest5` | 6/51, actual 58 | 6 matching, actual 58 | not stale |
| `action_order/PlaceAndRemove` | 15/96, actual 45 | 15 matching, actual 45 | not stale |
| `action_order/action_execution_order_extend_test` | 7/32, actual 28 | 7 matching, actual 28 | not stale |
| `action_order/action_execution_order_test6` | 0/24, actual 20 | 0 matching, actual 20 | not stale (content changed, see §7) |
| `avm1/looping_child_swf{5,9,32}` | 38/141, actual 207 | 38 matching, actual 207 | not stale |
| `avm2/button_nested_frame_simple` | 27/27 matching, actual 39 | identical | not stale |
| `timeline/missing_frame_scripts` | 12/22, actual 27 | identical | not stale |

**Where leg C's "stale" impression came from:** the *other* file. The checked-in
`_results/results.json` (the no-graphics stem) is from `0a99be1a9`, **9 days and
~15 commits older** than `results_graphics.json`, and it disagrees materially
(`ActionOrderTest3` actual 83 vs 73, `ActionOrderTest4` 94 vs 105,
`looping_child_swf5` 375 vs 207). It is commit drift, not a mode divergence.
Standing lesson, consistent with `ci-baseline-is-results-graphics-not-results`:
**never price a row off `results.json`.**

`register_class/RegisterClassTest4` re-ran to `output_mismatch` with exactly the
diff its disposition describes (line 3/4 swap: we emit
`load _level0.mc.Segments c: 0` **before** `2 0`, i.e. Ruffle's placement, while
Flash puts it after — so the diff-index sets differ and `ruffle_subset_match`
cannot promote). It is not re-priced, because it is in
`from_gnash/_investigation/ACCEPTED_DIFFS.md` (Category 1) **and** in
`from_gnash/misc-ming.all/ignored_tests.txt` since 2026-05-08. Editing it moves
the graded number by exactly zero. It should be removed from §17.4.

---

## 2. Row → mechanism map

| Row | Suite path | Mech id | Current (graphics) | Mechanism |
|---|---|---|---|---|
| `button_nested_frame_simple` | `ruffle-tests/tests/swfs/avm2/button_nested_frame_simple` | **M1** | 27/27 match, 39 actual vs 27 expected | AVM2 tick loop ignores `fscommand("quit")`; 2 whole spare ticks |
| `looping_child_swf5` | `ruffle-tests/tests/swfs/avm1/looping_child_swf5` | **M2** | 38/141, 207 actual | AVM1 sprite frame count is the **declared** DefineSprite header field, not the ShowFrame count; plus the `NextFrame::Same` trailing-partial-frame fall-through |
| `looping_child_swf9` | `…/avm1/looping_child_swf9` | **M2** | 38/141, 207 | identical SWF matrix, SWF v9 |
| `looping_child_swf32` | `…/avm1/looping_child_swf32` | **M2** | 38/141, 207 | identical SWF matrix, SWF v32 |
| `missing_frame_scripts` | `ruffle-tests/tests/swfs/timeline/missing_frame_scripts` | **M3 + M4** | 12/22, 27 actual | (M3) AVM2 `determine_next_frame` omits `!has_end_tag`; (M4) script-created orphan clip loses one tick of advance right after creation |
| `action_execution_order_test11` | `…/from_gnash/misc-ming.all/action_order/action_execution_order_test11` | **D1+D2** | 26/32 | flat-global vs per-subtree LIFO advance + per-clip EF/advance adjacency (s14 §3) |
| `action_execution_order_extend_test` | `…/action_order/action_execution_order_extend_test` | **D1 + onLoad-method** | 7/32 | D1 **plus** onLoad/onUnload *method* dispatch for timeline sprites, whose gate holds `test12` at `ruffle_matched` (s15 §3 F1) |
| `ActionOrderTest3` | `…/action_order/ActionOrderTest3` | **M5** | 4/62 | sprite-rewind identity + inter-tag UNLOAD; also emits ~2× the expected `onEnterFrame` count |
| `ActionOrderTest4` | `…/action_order/ActionOrderTest4` | **M5** | 10/64 | same, plus the construct/load cycle over-runs to `ctor: 10` |
| `ActionOrderTest5` | `…/action_order/ActionOrderTest5` | **M5** | 6/51 | same family |
| `action_execution_order_test6` | `…/action_order/action_execution_order_test6` | **M6 + D1** | 0/24 | goto-sweep place+remove CONSTRUCT suppression **and** D1 interleave |
| `PlaceAndRemove` | `…/action_order/PlaceAndRemove` | **M6′ + loop rate** | 15/96 | same-frame place+remove must suppress CONSTRUCT/DoAction **and** we only complete 15 of 96 cycles |
| `RegisterClassTest4` | `…/register_class/RegisterClassTest4` | — | dispositioned | ACCEPTED_DIFFS + ignore list |

Note the shorthand correction: the seven "from_shumway action_order" rows in the
brief are actually **`from_gnash/misc-ming.all/action_order/…`**, and
`extend_test` / `test6` / `test11` are
`action_execution_order_extend_test` / `_test6` / `_test11`.

---

## 3. S1 — AVM2 `fscommand("quit")` must end the tick loop — **GO**

### Mechanism (M1)

Ruffle's test runner, `~/CC/ruffle/tests/framework/src/runner.rs:250`:

```rust
for command in self.fs_commands.try_iter() {
    match command {
        FsCommand::Quit => { self.remaining_iterations = 0; }
```

`test()` runs **after** `do_tick()`, so the semantics are exactly *"finish the
current tick, then stop"* — not "stop mid-tick".

Our AVM1 loop already implements this: `SWFModernRuntime/src/libswf/swf.c:524-540`
has a dedicated `g_force_quit` gate ("FSCommand:quit was called in a prior tick
— exit as soon as nothing is still asking to run"). **The AVM2 loop has no quit
check of any kind**: `SWFModernRuntime/src/avm2/avm2_main.c:840-881` is a bare
`for (size_t tick = 0; tick < max_ticks; tick++)` with no `break`.
`SWFModernRuntime/src/avm2/avm2_globals.c:6733-6752` (`global_fscommand`) does
set both `quit_swf` and `g_force_quit` — nothing reads them on this path.

### Evidence

`avm2/button_nested_frame_simple` (`num_ticks = 3`, `MyContainer()`'s ctor ends
with `fscommand("quit")`). Our first **27 of 27** expected lines are identical,
including the four `frameConstructed` / four `exitFrame` passes the goto
produces inside tick 1. The 12 extra lines are two complete extra ticks:

```
+ 28  Main enter frame: [Event type="enterFrame" …]
+ 29  Main frame constructed: […]
+ 30  Child framescript 2
+ 31  Child framescript 2
+ 32  Main exit frame: […]
+ 33  Main enter frame: […]        ← second spare tick
…
+ 39  Main exit frame: […]
```

`Main enter frame` **never appears anywhere in the expected file** — it is the
signature of a tick that should not exist.

### Refutation of the board's framing

§17.4 prices this row as *"two spare tick cycles past `num_ticks = 3` **and**
child framescripts firing twice — two distinct timeline-core defects."*
**The second half is wrong.** Expected lines 16–19 already contain

```
Child framescript 1: myField = 0
Child After set: myField = 2
Child framescript 1: myField = 0
Child After set: myField = 2
```

twice, because `MyContainer` holds **two** `MyChild` instances (`otherChild` and
`myOtherChild`, both constructed at expected lines 6–9). There is **one** defect
on this row, not two, and it is not in the framescript machinery at all.

### Patch scope

`SWFModernRuntime/src/avm2/avm2_main.c`, inside the tick loop after
`avm2_try_pop_frame(&top)` (≈ line 869):

```c
{ extern int g_force_quit; if (g_force_quit) break; }   /* + declaration */
```

~6 lines with the comment. **No recompiler change, no `Recompiled*`
invalidation, `graphics` mode only.**

**Sibling overlap (checked against `SIBLING_FILE_MAP.md`):** `w2-avm2-smalls`
also edits `avm2_main.c` — but for *"super get/set/call coercion #1034"*, i.e.
the AVM2 method-dispatch helpers, not the tick loop at :840-881. Keep the edit
inside `runSWF_avm2`'s loop body and the two files will merge clean. `avm2_globals.c`
(where `g_force_quit` is already set) is untouched by any sibling.

### Blast radius (measured, not estimated)

Scan of every `test.swf` in the AVM2-side suites (`avm2`, `timeline`,
`mixed_avm`, `visual`, `stage3d`, `from_shumway`, `from_avmplus`, `text`, `swf`,
`audio`, `fonts`, `import_assets`) for SWFs whose tag stream contains **both**
`fscommand` and `quit`: **48 tests**, of which **41 are currently `pass` or
`ruffle_matched`** and must stay green.

### Regression canaries (must stay green)

| Test | Baseline | Why |
|---|---|---|
| `from_shumway/fscommand1` | pass | the dedicated fscommand fixture |
| `from_shumway/timeline/timeline_loop` | pass | AVM2 timeline that quits from a looping root |
| `from_shumway/timeline/scene/Scene_1_MainTimeline` | pass | scene navigation + quit |
| `timeline/frame_script_cleanup` | pass | framescript lifecycle + quit |
| `timeline/frame_script_construct` | pass | construct-order + quit |
| `avm2/register_script_refresh` | pass | quit from a re-registered script |
| `regression/avm2_timeline_solid`, `regression/avm2_goto_catchup_scale` | pass | standing regression-suite timeline rows |

The full 41-row list is reproducible with the scanner in
`scratchpad/w1timeline/scan_sprites.py`'s sibling one-liner (§9).

**Residual risk:** a currently-green row that calls `fscommand("quit")` early and
whose expected output nevertheless continues. Ruffle truncates in exactly the
same place, and all these expectations come from Ruffle/Flash, so the risk is
low — but the 41-row canary sweep is mandatory, not optional.

---

## 4. S2 — AVM1 sprite `frames_loaded` vs declared header count — **GO, with risk**

### The fixture is a purpose-built 24-cell probe of one Ruffle function

`avm1/looping_child_swf{5,9,32}` (identical content, SWF versions 5 / 9 / 32,
identical 141-line expected output) place **24 sibling sprites at root depths
1–24 in root frame 0** and never remove them. The root has 10 frames and traces
`stop` + `stop()` on frame 9. Each sprite is a distinct cell of

```
(DefineSprite header frame count 0..3) × (ShowFrame tags present 0/1/2) × (End tag y/n)
```

| char | header `decl` | ShowFrames | End tag | trailing DoAction after last ShowFrame |
|---|---|---|---|---|
| 1,2 | 0,1 | 0 | yes | – |
| 3,4 | 0,1 | 0 | **no** | – |
| 5,6,7 | 0,1,2 | 1 | yes | – |
| 8,9,10 | 0,1,2 | 1 | **no** | – |
| 11,12,13,14 | 0,1,2,3 | 1 | yes | **yes** |
| 15,16,17,18 | 0,1,2,3 | 1 | **no** | **yes** |
| 19,20,21 | 1,2,3 | 2 | yes | – |
| 22,23,24 | 1,2,3 | 2 | **no** | – |

### The rule (Ruffle, exact)

`~/CC/ruffle/core/src/display_object/movie_clip.rs`:

- `frames_loaded()` (:3314) = `preload_progress.cur_preload_frame - 1`, i.e. the
  **ShowFrame count**. `preload` (:596-604): *"If this clip did not have any show
  frame tags, treat the end-of-clip as a ShowFrame"* → a 0-ShowFrame sprite
  reports `frames_loaded == 1`. The DefineSprite **header** count is never
  consulted for playback.
- `determine_next_frame()` (:1340):
  ```rust
  if …preload not finished… || self.current_frame() < self.frames_loaded()  { Next }
  else if self.frames_loaded() <= 1 || !has_end_tag                          { Same }
  else                                                                       { First }
  ```
- `run_frame_internal()` (:1360): `NextFrame::Same => self.stop(context)` and
  then **falls through** and still decodes tags from `tag_stream_pos`. That is
  what runs a trailing partial frame **exactly once**, on the tick after the last
  real frame, before the clip goes silent forever.

### The model reproduces all 141 expected lines

Hand-simulated tick by tick:

- **tick 1** — all 24 placed; each runs its own frame 1 inline at placement
  (`instantiate_child` → `run_frame_avm1`), so the order is **FIFO 1…24**
  (expected lines 1–24). ✔
- **tick 2** — exec-list LIFO (`clip_exec_list` head insertion), so **24…11**
  emit `frame 2` (lines 25–38). Chars 11–18 reach it via the `Same` fall-through
  (their trailing DoAction), chars 19–24 via `Next`. Chars 1–10 have no second
  DoAction. ✔
- **tick 3+** — only chars **21, 20, 19** loop: they are the only cells with
  `frames_loaded == 2` **and** an End tag. 22/23/24 have 2 ShowFrames but no End
  tag → `Same`. 11–18 have `frames_loaded == 1` → `Same`. ✔ (expected lines
  39–141, LIFO 21,20,19 per tick.)
- The root is the **oldest** entry in the exec list, so its `stop` trace lands
  *after* the sprite group on tick 10 — matching expected line 63. ✔

The DefineSprite header count is irrelevant everywhere: chars 19/20/21 declare
1/2/3 and behave identically.

### Our side

`SWFRecomp/src/swf.cpp` emits `tagDefineSprite(id, frame_funcs, DECLARED, len)`
— the third argument is the **raw header field**
(`tagDefineSprite(19, …, 1, 72)`, `tagDefineSprite(21, …, 3, 72)`), and that
value becomes `ch->sprite_frame_count`, which
`SWFModernRuntime/src/libswf/tag.c::advance_sprite_frames` (:1645-1660) uses for
the wrap:

```c
if (ch->sprite_frame_count > 0 && obj->sprite_current_frame == frame) {
    if (frame + 1 >= ch->sprite_frame_count && !ch->sprite_has_end_tag)
        ng_sprite_park_no_end_tag(obj);
    else
        obj->sprite_current_frame = (frame + 1) % ch->sprite_frame_count;
}
```

`sprite_has_end_tag` / `tagSetSpriteNoEndTag` already exist and are correctly
emitted (`swf.cpp:6294-6300`) — **the End-tag half of the rule is already
implemented on the AVM1 side.** What is missing is the frames-loaded/declared
split. The AVM2 side already has exactly this split
(`avm2_display.c:1918 frames_loaded()` = `timeline->frame_count`
vs `:1928 total_frames()` = `timeline->declared_frames`, with the comment
*"totalFrames = the DECLARED header/DefineSprite count verbatim … (swf_wrong_frame_count
reports 1 while the playhead runs to 5)"*). **Port that split to AVM1.**

Three sub-rules are needed, not one:
1. `sprite_frames_loaded` = ShowFrame count (min 1); keep the declared count for
   AS-visible `_totalframes`.
2. `frames_loaded <= 1 || !has_end_tag` → stop, **and still run the trailing
   partial frame once** (`NextFrame::Same` fall-through).
3. A 1-frame clip must not re-run its frame script every tick (our steady state
   currently re-traces chars 6 and 7 forever).

### Blast radius — the strongest isolation evidence on this board

Corpus-wide SWF scan (all 12 suites, every `test.swf`, sprites decoded from the
tag stream):

- Sprites with a **trailing partial frame after ≥1 ShowFrame** (the cells where
  our frame count exceeds Ruffle's `frames_loaded`): **exactly 3 tests
  corpus-wide — `avm1/looping_child_swf{5,9,32}`.** Nothing else.
- Sprites where `declared != max(ShowFrames, 1)` at all: 63 tests, but **55 of
  them are `decl = 0, ShowFrames = 0`**, where both the old and new rules give a
  single non-looping frame — inert by construction.
- The genuinely live canaries are the handful below.

### Regression canaries (must stay green)

| Test | Baseline | Sprite cell |
|---|---|---|
| `avm1/target_paths/swf4` | pass | sprite 2: `decl=2, ShowFrames=1` |
| `avm1/target_paths/swf5` | ruffle_matched | same |
| `avm1/target_paths/swf6` | ruffle_matched | same |
| `from_gnash/misc-swfmill.all/zeroframe_definesprite` | ruffle_matched | sprite 3: `decl=2, ShowFrames=0` |
| `avm2/zero_frame_clip`, `avm2/swf_wrong_frame_count` | pass | the AVM2 declared-vs-loaded fixtures |
| `avm1/placeobject_occupied_depth`, `avm1/attach_movie_stop`, `avm1/clip_constructors`, `avm1/on_construct`, `avm1/register_and_init_order`, `avm1/init_object_order` | pass | `decl=0` sprites |
| `regression/enterframe_type1_args`, `root_enterframe_cross_swf_version`, `mc_event_type1_args`, `onload_type1_args`, `onunload_type1_args` | pass | standing AVM1 lifecycle battery |
| `from_gnash/misc-ming.all/action_order/action_execution_order_test1` / `_test5` | pass | timing/order guards from the s14 canary list |

### Probable rider (unverified): `avm1/shared_stack`

`avm1/shared_stack`'s only sprite is `decl = 1, ShowFrames = 2` — our declared-count
model therefore treats it as a 1-frame clip that never advances. The upstream
triage row reads *"Stops at the child's frame 2; child frames don't run"*
(`avm1/_investigation/NEW_UPSTREAM_AVM1_TRIAGE.md:89`), which is exactly that
signature. **This contradicts `avm1/_investigation/CURRENT_STATUS.md:31`, which
files `shared_stack` under "the AVM1 value stack shared across clips within a
tick … a cheap standalone fix".** Wave 2 should grade `shared_stack` before and
after S2 — if it moves, the arc is +4 and a doc row needs correcting.

### Cost / risk

**Sibling overlap:** `w2-gfx-cab-pixelsnap` also edits `SWFRecomp/src/swf.cpp`
(~:4313, PlaceObject3 BitmapCache) and `SWFModernRuntime/src/libswf/tag.c`
(display-entry structs / `compose_children`). S2's edits are at `swf.cpp`
~:6280-6400 (the DefineSprite tail) and `tag.c::advance_sprite_frames`
(~:1140-1660) — disjoint regions, but coordinate the `tag.h`/`swf.h` struct
additions (both slices add fields).

Recompiler emission changes (a new per-sprite ShowFrame count) invalidate every
`Recompiled*` cache corpus-wide → **both CI modes** (`graphics` **and**
`no-graphics`), and the runtime edit is in `advance_sprite_frames`, the single
most regression-prone function in `tag.c`. Realistic outcome: a large
diff-line gain on 3 all-or-nothing rows; the flip needs all three sub-rules
landed together. Price it as **+3 with a real chance of +0 flips and a big
diff-line move** — the s16 lesson (*a diff-line lead is not a flip lead*) applies
directly.

**Refutations logged here:**
- `avm1/_investigation/NEW_UPSTREAM_AVM1_TRIAGE.md:86-88` files the
  `looping_child_swf*` trio under **"Multi-SWF child-frame execution"**
  (*"Child SWF frames/labels don't advance/label correctly"*). **Wrong.** These
  SWFs load nothing; there is no child SWF anywhere in the fixture. The row also
  appears in `avm1/_investigation/CURRENT_STATUS.md:31` under the same wrong
  heading. Both should be re-filed under the sprite frame-count rule.
- s14's `wave1-avm1-tick.md` §4 sibling scan missed these three entirely, which
  is why the action_order arc was priced "+1, +1 conditional". The
  `frames_loaded` family is a *different* mechanism worth 3–4 rows and does not
  need Track A or Track B.

---

## 5. S3 + S4 — `timeline/missing_frame_scripts` — **HOLD (needs both)**

Current: 12/22 matching, 27 actual. Two independent defects; neither flips the
row alone.

### S3 (M3) — AVM2 `determine_next_frame` omits `!has_end_tag`

`SWFModernRuntime/src/avm2/avm2_display.c:1934-1940`:

```c
static int determine_next_frame(const Avm2DisplayObjectExt* ext)
{
    if ((uint32_t) ext->current_frame < frames_loaded(ext)) return NEXT_FRAME_NEXT;
    if (frames_loaded(ext) <= 1) return NEXT_FRAME_SAME;      /* <- missing || !has_end_tag */
    return NEXT_FRAME_FIRST;
}
```

The fixture: `SymbolClass` maps char 12 → `MyContainer`, char 13 → `Spawn`.
Decoded from the SWF: **char 12 has 2 ShowFrames and an End tag; char 13 has 2
ShowFrames and NO End tag.** Expected output has `Spawn frame1` (tick 1) and
`Spawn frame2` (tick 2) and then Spawn is silent for the whole movie, while
`Container` loops frame1/frame2 to the end — precisely `!has_end_tag → Same`.
We loop Spawn forever and even reach `Spawn stopped` (expected has no such line).

**Sibling overlap:** `avm2_display.c` is the most contested file in s17 —
`w2-crossvm-legE`, `w2-gfx-cab-pixelsnap`, `w2-gfx-drawgraphicsdata`,
`w2-gfx-filters-cut2`, `w2-scrollrect` and `w2-avm2-smalls` all touch it.
`determine_next_frame` (:1934) and the orphan phases (:3468-3513) fall outside
every one of their named regions, so S3/S4 should merge clean.

Patch scope: `SWFRecomp/src/abc/abc_timeline.cpp` (`Timeline` gains a
`has_end_tag`, `scanStream` records whether the sprite body terminated on
`TAG_END`, emission at :1937 gains a field), `SWFModernRuntime/include/avm2/avm2_abc.h`
(`Avm2TimelineData` gains `uint8_t has_end_tag;` — **struct change, regenerates
every `RecompiledABC`**), and the two-token change above. ~10 lines.

**Blast radius = 1 test.** Corpus-wide scan of every AVM2-side `test.swf`:
`timeline/missing_frame_scripts`'s char 13 is the **only** multi-frame sprite
without an End tag in the entire AVM2-side corpus. Every other End-tag-less
sprite (`avm2/movieclip_frameconstruct_skipped`, `avm2/place_and_lookup/swf9`
and `/swf10`, `avm2/swf_{9,10}_queued_goto_scripts_construct`,
`avm2/stage_framerate_nan`, `timeline/clip_action_no_key_code`,
`swf/convolution_filter_big_matrix`, `visual/edittext/edittext_bounds_vs_position`,
`visual/focus_highlight/focus_highlight_avm1_button`) has ≤1 frame, where
`frames_loaded <= 1` already returns `SAME` and the new clause is a no-op.
Those 9 are the canary set; all are currently `pass`.

### S4 (M4) — AVM2 orphan clip loses one tick right after script creation

`Spawn.frame1` does `this.secretChild = new MyContainer()` — a symbol-linked
MovieClip that is **never added to the display list** (an orphan). Expected:

| tick | expected | ours |
|---|---|---|
| 1 | `Container Constructor` / `addFrameScript` / `Container frame1` | identical ✔ |
| 2 | `Container frame2` | **nothing** |
| 3 | `Container frame1` | `Container frame2` |
| 4 | `Container frame2` | `Container frame1` |

We are one tick behind for the rest of the movie. Owner:
`SWFModernRuntime/src/avm2/avm2_display.c::avm2_display_run_tick` orphan phases
(`enter_frame` :3468-3471, `construct_frame` :3485-3489,
`run_frame_scripts` :3509-3513) plus the `g_orphan_dirty` / `walk_skip_on()`
gating and `run_frame_internal`. **Exact cause not pinned** — wave 2 must
instrument the orphan's `current_frame`/`playing` across ticks 1→2. Likeliest
suspects: the orphan is created mid-tick and its first advance is consumed by
the same-tick framescript run, or `orphan_dirty_push` misses it for one tick.

Completion mechanism for the HOLD: pin S4's cause. S3 alone changes 5 lines of
output and flips nothing.

---

## 6. S5 — action_order `test11` + `extend_test` — **NO-GO (inherited, re-verified)**

Diagnosis of record: `session14-fanout-reports/wave1-avm1-tick.md` (DEFER) and
`session15-fanout-reports/w2-action-order-report.md` (NO-GO, no patch). Both
survive re-audit at HEAD:

- `test11` is **26/32 at HEAD, and its diff is byte-identical to the transcripts
  in both s14 and s15** — the same two-line 8/9 swap (`mc21 onLoad` vs
  `mc1 onEnterFrame`), the same `doActionOrder` `0+2+1+3+4+5+`, the same
  `asOrder` string. `test.toml` is `num_frames = 30`
  and nothing else — no `known_failure`, no `output.ruffle.txt`, so 31/32 scores
  the same as 26/32. Track A (flat-global LIFO advance) flips nothing on its own;
  Track B collapses phases 1/2/4 and moves a **recompiler-emitted**
  `tagFlushPendingEnterFrame` call site, invalidating every `Recompiled*` cache.
- `extend_test` is **7/32** and needs onLoad/onUnload *method* dispatch for
  timeline-placed sprites, whose gate (`tag.c:772-788`) is the landed
  `ACTION_EXECUTION_ORDER_TEST12` fix currently holding
  `misc-swfc.all/action_execution_order_test12` at `ruffle_matched`. Widening it
  is that fix rolled back. Its local diff at HEAD confirms all three s15 legs are
  still open (`mc_red load executed` missing, `mc_blu enterFrame` position,
  `y5`/`y2` assertion inversions).

Completion mechanism (unchanged from s15 §5): a dedicated day, the games
divergence harness in the loop, Track B behind a runtime A/B flag, and step 0 =
obtain the Gnash `action_execution_order_extend.c` source to pin the onLoad
fire/no-fire rule before touching `tag.c:772-788`.

---

## 7. S6/S7/S8 — the rest of `action_order` — **NO-GO**

### `ActionOrderTest3/4/5` (M5)

Plan-target of two **blocked** plans:
`from_gnash/_investigation/blocked/INTER_TAG_UNLOAD_PLAN.md` and
`blocked/SPRITE_REWIND_IDENTITY_PLAN.md`. Three separate implementation attempts
(2026-04-29, 2026-05-03 ×2) each bought **+1 or +2 matching lines** on these
three rows while costing **−10/−11 lines on `RegisterClassTest4`**, and the
standing instruction in the plan is *"If RegisterClassTest4 regresses with no
plan-target gain in matching-lines, revert and stop — that's the third
repetition of the same trade and the answer is somewhere else."*

`ruffle_matched` promotion is **unreachable**, and this is worth stating
precisely because all three carry `known_failure = true` + `output.ruffle.txt`:

- `ActionOrderTest3`: Ruffle = Flash's 62 lines **plus** 40 more (the
  construct/unload cycle continues to `ctor: 12`). Ruffle's diff-index set is a
  pure tail; ours is early reordering from line 4 onward. Not a subset.
- `ActionOrderTest4`: identical shape (64 → 104).
- `ActionOrderTest5`: Ruffle is **51 lines and differs from Flash by only three
  `dynamic load: N` position swaps** plus the 3 assertion lines they invert. Our
  diff is ~45 indices wide. Not a subset.

New quantified sub-signature worth recording: **we emit roughly twice the
expected `onEnterFrame` count** on all three (expected 7, Ruffle 7; our diffs
show 11–15 `onEnterFrame` lines among the mismatched lines alone). If anyone
re-opens this family, that is the cheapest single thread to pull — it is a
double-dispatch, not an ordering, defect.

### `action_execution_order_test6` (M6 + D1)

`incomplete/ACTION_EXECUTION_ORDER_TEST6_PLAN.md`'s recorded root cause is
**partly stale**: it says the `aq_drain` filter (`action_queue.c:151-160`) drops
both the CONSTRUCT *and* the LOAD entries for placements cancelled in a goto
sweep. At HEAD the LOADs fire — our actual now opens
`mc1 Load / mc2 Load / mc1 Unload / mc2 Unload / mc3 Load / mc3 Unload`. What is
still missing is the three **CONSTRUCT** events of cycle 1 (`check_result`
obtained `4+5+6+7+8+9+1+2+4+5+x+xx+`, expected `1+2+3+4+5+6+7+8+9+1+2+4+x+5+xx+`).
The remaining `…1+2+4+5+x+xx+` vs `…1+2+4+x+5+xx+` swap is the **D1** per-clip
`{Load; own frame script}` interleave, i.e. the Track-B mechanism. Two
mechanisms, one of them Track B ⇒ NO-GO. `ruffle_matched` is unreachable: Ruffle
emits only 12 lines (it drops cycle 1 entirely), we emit 20 with cycle-1
Load/Unload present, so our index set is not a subset.
Prior attempt (`281f30b3`, reverted `4c61f111`) regressed
`reverse_execute_PlaceObject2_test2` from `pass 10/10` to `ruffle_matched 7/10`.

### `PlaceAndRemove` (M6′)

15/96, **45 actual lines**. Two defects: (a) we emit `moo N` +
`FAILED: This MovieClip should never be constructed` for every same-frame
Place+Remove pair that Flash suppresses, and (b) we complete only **15 of the 96
cycles** in the fixture's 30 ticks. The test has no `output.txt` at all — only
`output.fp9.txt` (91 lines) and `output.fp10.txt` (96 lines), all `Done` — and
`test.toml` carries `known_failure.panic = "Gotos must start from the correct
tag position for frame 1"` with **no `output.ruffle.txt`**, so `ruffle_matched`
is structurally unavailable and only exact 96-line Flash parity scores. Two
mechanisms with a 51-line deficit and no partial credit ⇒ NO-GO.

Note the sign inversion worth keeping on file: **test6 wants events to FIRE for
place+remove pairs cancelled across a goto sweep, PlaceAndRemove wants them
SUPPRESSED for pairs inside one frame's tag list.** Our model has both
backwards. A unified fix keyed on *same-frame pairing* rather than
*same-goto-sweep pairing* is the shape a future arc should take — but the
2026-05-08 attempt at exactly that regressed `reverse_execute_PlaceObject2_test2`,
so it needs per-entry cancellation tracking, not a predicate flip.

---

## 8. Ranked slice list

| # | Slice | Mech | Rows | Priced | Files | Cache invalidation | CI modes | Verdict |
|---|---|---|---|---|---|---|---|---|
| 1 | AVM2 fscommand-quit ends tick loop | M1 | `avm2/button_nested_frame_simple` | **+1** | `avm2_main.c` (~6 lines) | none | graphics | **GO** |
| 2 | AVM1 `frames_loaded` split + `Same` fall-through | M2 | `avm1/looping_child_swf{5,9,32}` (+ `shared_stack`?) | **+3 (+1?)** | `SWFRecomp/src/swf.cpp`, `tag.c::advance_sprite_frames`, `libswf/swf.h` | **full corpus** | graphics **and** no-graphics | **GO (risk: 3 sub-rules, all-or-nothing rows)** |
| 3 | AVM2 `has_end_tag` + orphan tick stall (must pair) | M3+M4 | `timeline/missing_frame_scripts` | +1 | `abc_timeline.cpp`, `avm2_abc.h`, `avm2_display.c` | all `RecompiledABC` | graphics | HOLD — pin M4 first |
| 4 | action_order D1/D2 pipeline | D1/D2 | `test11`, `extend_test` | 0 | five interlocking mechanisms + recompiler | full corpus | both | NO-GO |
| 5 | sprite-rewind identity / inter-tag UNLOAD | M5 | `ActionOrderTest3/4/5` | 0 | blocked plans | — | — | NO-GO |
| 6 | goto-sweep vs same-frame place+remove | M6 | `test6`, `PlaceAndRemove` | 0 | `action_queue.c` + D1 | — | — | NO-GO |

### Board edits this report implies (for the closeout agent)

1. `polish-sweep-arc.md` §17.4: **delete** `RegisterClassTest4` from the
   timeline-order row (dispositioned 2026-05-08, in the ignore list).
2. §17.4: split the row into `S1` (+1, cheap), `S2` (+3, medium), `S3+S4` (+1,
   paired), and the four NO-GOs; the "12 rows, worth a solo session" framing
   over-counts by 7.
3. §17.4's "two distinct timeline-core defects" on `button_nested_frame_simple`
   is **one** defect (§3).
4. `avm1/_investigation/NEW_UPSTREAM_AVM1_TRIAGE.md:86-89` and
   `CURRENT_STATUS.md:31`: re-file `looping_child_swf{5,9,32}` (and probably
   `shared_stack`) out of "Multi-SWF child-frame execution" into the sprite
   frame-count rule.
5. `incomplete/ACTION_EXECUTION_ORDER_TEST6_PLAN.md`: the LOAD half of its
   recorded root cause is closed; only CONSTRUCT + D1 remain (§7).
6. Leg C's "stored rows may be stale" note: refuted for graphics; the stale file
   is `results.json` (no-graphics, `0a99be1a9`).

---

## 9. Method notes / reusable artefacts

- Scratchpad: `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/ab0a66b8-…/scratchpad/w1timeline/`
  - `swfdump.py` / `swfdump2.py` / `swfdump3.py` — SWF tag-stream dumpers that
    print, per DefineSprite, the **declared header frame count**, the **ShowFrame
    count**, whether the body terminates on an **End tag**, and how many tags
    trail the last ShowFrame. This is what turned `looping_child` from "chaotic
    ordering test" into "24-cell matrix over three named rules" in one command.
  - `scan_sprites.py` — the same decoder run over every `test.swf` in the corpus.
    Both blast-radius numbers in §4 and §5 come from it, and both came back
    dramatically smaller than a "timeline core" label suggests (3 tests and
    1 test respectively).
- **The s14 tick-simulator method paid again.** No instrumented build was needed
  for any of M1/M2/M3: Ruffle's `determine_next_frame` + `preload` + the test
  runner's `FsCommand::Quit` arm, read against the decoded tag stream, predict
  the expected files line for line.
- **Check `test.toml` for `known_failure` + a `output.ruffle.txt` sidecar before
  pricing any gnash row.** Half this board's rows have them, and whether
  `ruffle_matched` is reachable is decided by *diff-index subset*, not by how
  close the two files look: `ActionOrderTest5` is 51-vs-51 lines with Ruffle and
  still unreachable, while `PlaceAndRemove` has no sidecar at all.
- Local single-test `--mode=graphics` runs do **not** rewrite
  `_results/results_graphics.json` (the `ci-single-test-run-clobbers-results`
  fix holds); they do rewrite `results.json`. Read baselines from the graphics
  stem only.
