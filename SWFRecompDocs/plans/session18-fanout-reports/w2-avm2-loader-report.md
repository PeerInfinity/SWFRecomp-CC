# w2-avm2-loader — session 18 wave 2: loaded-child boot order + loadBytes event ordering

Agent `w2-avm2-loader`, isolated worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a769df571adcf4019`, base
`8f68a5fea`. Runtime-only change; `SWFRecomp/build` copied from the main tree.

## NEW files delivered

* `SWFRecompDocs/plans/session18-fanout-reports/w2-avm2-loader.patch` (NEW)
* `SWFRecompDocs/plans/session18-fanout-reports/w2-avm2-loader-report.md` (NEW, this file)

**No new source files.** The patch touches exactly one existing file:
`SWFModernRuntime/src/avm2/avm2_display.c` (+53 / −21), in two functions —
`loader_boot_child_swf` and `avm2_loader_run_exit_frame`. Both are inside the
brief's declared "loader/executor regions"; no sibling agent's regions are
touched.

---

## 1. Verdicts, priced

| lead | verdict | flips |
|---|---|---|
| **L3** loaded child's frame-1 children placed AFTER its root ctor | **GO — LANDED** | **+1** (`avm2/loader_try_click_root` 0/16 → **16/16 pass**) |
| **L7** `loadBytes` init/complete must land a frame after the boot | **GO — LANDED** | **+1** (`avm2/large_preload_from_bytes` 41/51 → **51/51 pass**) |
| L3's "+1 likely" — `avm2/loader_duplicate_class` | **REFUTED as a flip** (§5.1) | 0 (3/48 → **32/48**; residual is a DIFFERENT mechanism) |

**Net: +2 firm trace flips, 0 status regressions across an 87-test canary set.**

---

## 2. The patch, mechanism first

### L3 — `loader_boot_child_swf`: enter_frame before construct_frame

Ruffle's `movie_loader_complete` (`core/src/loader.rs:2086-2096`) is explicit:

```rust
mc.post_instantiation(uc, None, Instantiator::Movie, false);
if mc.movie().is_action_script_3() {
    mc.enter_frame(uc);        // timeline advance + this frame's PlaceObject tags
    mc.construct_frame(uc);    // <- the root class constructor runs HERE
}
mc.base().set_skip_next_enter_frame(true);
// ... loader.insert_at_index(uc, dobj, 0);
```

`MovieClip::enter_frame` (`movie_clip.rs:2540-2580`) unqueues and executes the
frame's place tags; `construct_frame` (`:2583-2600`) is what calls
`construct_as_avm2_object`, i.e. the root's own class constructor. So a loaded
root's ctor *always* sees a populated frame-1 display list.

Ours ran the two in the opposite order: `display_run_constructor_catching`
first, `run_frame_internal` + `flush_queued_places` only after
`insert_at_index`. The patch hoists that block above the ctor. Nothing else
moves — `insert_at_index`, `construct_frame_obj` and `run_frame_scripts_obj`
stay exactly where they were, so the in-tree invariant "the ctor must observe a
null stage and a null parent" still holds (parent/stage are set by
`insert_at_index`, still after the ctor), and `loader_loadbytes_events`' pinned
`Framescript frame 1` position between `addedToStage` and the identity checks is
unchanged (verified: still 30/30 pass).

Why the fix *works* rather than merely reordering: the placed children get their
AVM2 objects from `sprite_ctor_init` (our `Sprite.constructChildren`) during the
root ctor's `super()`, and `construct_frame_obj` → `set_on_parent_field` is what
binds each named child to its field on the parent. With the places ahead of the
ctor, that whole chain now runs *inside* `super()`, before the ctor body — which
is exactly Ruffle's documented "before calling `super()`, `this.numChildren`
shows a non-zero number but `getChildAt(0)` returns null" note.

`avm2/loader_try_click_root`'s `Loadable.as` is that case in one line:
`this.mouseDisabled.mouseEnabled = false;`. At HEAD it threw
`TypeError #1009 ... (accessing field: mouseEnabled) at Loadable()` five times,
each setting `lx->errored` and dropping the load, so all 16 click lines reported
`[object Stage] (null)`. After: 16/16.

### L7 — `avm2_loader_run_exit_frame`: a loadBytes SWF's boot and its init/complete are a frame apart

The brief called it "one-position rotation in the tick/executor drain" and w1
asked for instrumentation rather than assumption. No instrumentation was needed —
Ruffle names the frame boundary directly:

* `movie_loader_data` for `from_bytes` (`loader.rs:1825-1842`) preloads, fires
  the second `progress`, and pushes a **post_frame_callback** to
  `movie_loader_complete`.
* `Player::run_frame` (`player.rs:2067-2078`) runs `run_all_phases_avm2` — which
  ends with `broadcast_frame_exited` → `LoadManager::run_exit_frame`
  (`frame_lifecycle.rs:163-165, 189-195`) — and only **then** drains
  `post_frame_callbacks`, with `std::mem::take`, so a callback pushed from
  inside a callback runs at the end of the *next* frame.
* `movie_loader_complete`'s AVM2 arm (`loader.rs:2192-2206`) deliberately does
  **not** fire init/complete for a MovieClip: *"This is fired after we process
  the movie's first frame, in `MovieClip.on_exit_frame`"*. That is
  `try_fire_loaderinfo_events`, reached from `LoadManager::run_exit_frame` — i.e.
  the NEXT frame's exit.

So Ruffle's per-tick shape is
`exitFrame -> run_exit_frame (init/complete of things booted last tick) ->
post_frame_callbacks (this tick's boots)`. Ours booted **and** fired in the same
`avm2_loader_run_exit_frame` pass. The patch consumes `pending_boot`, boots, and
`continue`s — the entry is re-tracked so its init/complete fire one drain later.

The re-track is deliberately placed **before** the boot: the child's own ctor may
start another `loadBytes` (it does, in this fixture), and that new entry must
land *after* ours on the active list so the outer loader's `complete` precedes
`Constucted nested_load/test.swf`. That single line of ordering is what makes the
fixture come out 51/51 rather than 49/51.

Before → after on `avm2/large_preload_from_bytes` (positional):

```
  40 LargeSWF loader.contentLoaderInfo.parameters = [object Object]
- 41 exitFrame in Test                       <- was missing
  42 loader.contentLoaderInfo === loader.content.loaderInfo : true
  ..  init / complete
  46 Constucted nested_load/test.swf         <- was two lines later
  47 exitFrame in Test
```

`lx->errored` no longer needs its own `continue`: an errored entry is skipped by
the `if (lx == NULL || lx->errored) continue;` guard at the top of the next
pass, so `loader_error_in_root_ctor` still passes (verified).

---

## 3. Verification ledger

Method: a full baseline leg at `8f68a5fea` (unpatched worktree, `--recompile`,
`--save-actual`) for every canary that was **not** already passing, then the
patched leg over the whole set. A previously-passing test that still passes *is*
byte-identical to expected, so `pass -> pass` is the byte-identity bar for those.
`SWFRECOMP_COMPILE_TIMEOUT=2400`, `-P 2` while the machine was shared,
`--verbose`, no-graphics unless noted. Logs and both legs' saved actuals live in
`<scratchpad>/w2-avm2-loader/{base,after,gfx}/`.

### 3.1 Headline

| test | before | after |
|---|---|---|
| `avm2/loader_try_click_root` | 0/16, 26 actual lines, 5x `#1009` | **pass 16/16** |
| `avm2/large_preload_from_bytes` | 41/51 | **pass 51/51** |
| `avm2/loader_duplicate_class` | 3/48 (46 actual) | output_mismatch, **32/48** (48 actual) — no flip, §5.1 |

### 3.2 Canary set — 87 tests, no status regression

**78 pass / 8 output_mismatch / 1 ruffle_matched.** Every one of the 76 canaries
that passed at baseline still passes; the two extra passes are the flips above.

* every `avm2/loader_*` and `avm2/loaderinfo_*` (44 tests, incl.
  `loader_loadbytes_events`, `loader_loadbytes_url`, `loader_error_in_root_ctor`,
  `loader_events`, `loader_method`, `loader_reuse`, `loader_bitmap_transparency`,
  `loaderinfo_quine`, `delayed_symbolclass`, `simplebutton_symbolclass`,
  `large_preload_from_url`, `large_preload_image_from_bytes`,
  `loader_noninteractive_try_click_root`) — all pass
* `from_shumway/as3-loader/*` (12) — `LoaderTest2`, `LoaderLoadBytesTest2`,
  `bug1093712/loader`, `bug1157243/{empty,invalid}`, `loaderinfo/Preloader`,
  `loaderinfo/loaded-content-properties` pass; `LoaderTest` stays
  `ruffle_matched`, byte-identical
* `mixed_avm/*` (12) — all 10 baseline-passing still pass
* `import_assets/*` (3) — all pass
* `regression` suite (18: the whole `avm1_child_timeline_*` /
  `avm1_parent_child_*` / `avm2_parent_child_*` Multi-SWF fixture family plus
  `avm1_parent_as3_child_payload`, `avm1_root_identity_and_playhead`,
  `avm2_loader_stub`, `avm2_embed_bytearray`, `avm2_agi_shell`) — all pass

### 3.3 Byte-identity on the canaries that were already failing

| test | base vs after actual |
|---|---|
| `avm2/loader_applicationDomain` | **identical** (0 lines both legs; ACCEPTED_DIFFS, AOT ceiling) |
| `avm2/loader_events_2` | **identical** |
| `avm2/loader_load` | **identical** |
| `from_shumway/as3-loader/LoaderLoadBytesTest` | **identical** |
| `from_shumway/as3-loader/LoaderTest` | **identical** |
| `mixed_avm/avm1_loads_avm2` | **identical** |
| `mixed_avm/avm2_loads_avm1_events` | **identical** |
| `avm2/loader_duplicate_class` | changed — 3 → **32** matching (improvement) |
| `from_shumway/as3-loader/events/loader-events` | changed — 9 → 5 *positional* matches; an alignment artifact of removing two genuinely-spurious lines, §5.2 |

### 3.4 Graphics mode

Four tests re-run with `--mode=graphics` (local Dawn, `DAWN_INSTALL=~/CC/dawn-install`
— a worktree does NOT inherit the default `../dawn-install` path, so the env var is
required there):

| test | `--mode=graphics` |
|---|---|
| `avm2/loader_try_click_root` | **pass** (the flip holds in the CI grading mode) |
| `avm2/large_preload_from_bytes` | **pass** (the flip holds) |
| `avm2/loader_loadbytes_events` | **pass** (unchanged) |
| `avm2/loader_events` | **pass** (unchanged) |

---

## 4. Patch scope (exact)

`SWFModernRuntime/src/avm2/avm2_display.c` only.

1. `loader_boot_child_swf` (~`:5915`): the
   `uint8_t saved_phase = ctx->frame_phase; if (cext->timeline != NULL) { if
   (cext->playing) run_frame_internal(...); flush_queued_places(...); }` block
   moves from after `insert_at_index` to before `cext->constructed = 1` and the
   ctor. Comments rewritten to name Ruffle's `enter_frame`/`construct_frame`
   pairing. No other statement moves.
2. `avm2_loader_run_exit_frame` (~`:6275`): the `pending_boot` arm re-tracks the
   entry (`loader_track_active`) **before** `loader_boot_child_swf` and then
   `continue`s, instead of falling through to
   `loaderinfo_fire_init_and_complete` in the same pass. `if (lx->errored)
   continue;` is dropped as redundant.

No struct fields added, no new statics, no header changes, no new files, no
CMake / Emscripten / `verify_output.py` source-list change.

**Sibling overlap check:** `w2-avm2-timeline` edits `addFrameScript`
(~`:7921`) and `orphan_cleanup` (~`:181`); `w2-avm2-new-smalls` edits
`addFrameScript`'s entry, the MovieClip region and the Mouse/cursor globals;
`w2-avm2-stage` edits the Stage region (~`:12570`+); `w2-gfx-strokes` edits
`gfx_stroke_join`/`gfx_build_stroke` (~`:8176`); `w2-matrix3d` edits the
Vector3D region. None of those is within 1000 lines of either hunk — this patch
should merge cleanly with all of them.

---

## 5. Refutations and corrections (attacking my own brief)

### 5.1 `avm2/loader_duplicate_class` is NOT an L3 flip — its residual is symbol-class binding

The brief priced it "+1 likely ... two misplaced lines + a `#1034`". The `#1034`
is not a consequence of the boot order at all: it is present **at HEAD, in the
same position**, and it survives the fix. What L3 does buy is alignment —
3/48 → 32/48 matching, actual line count 46 → 48 — because the ctor now runs
after the place and the error acquires its two real stack frames.

The residual, graded positionally against the after-leg actual, is exactly three
expected lines and one mechanism:

```
exp 4  this.childFromDomainChild = [object MovieClip]
exp 5  Child name: [object MovieClip]
act 4  TypeError: Error #1034: Type Coercion failed: cannot convert
       flash.display::MovieClip@00000000000 to DuplicateClass.
act 5      at flash.display::MovieClip()
act 6      at loader_domain_child_fla::MainTimeline()
exp 19 this.childFromOtherDomain = [object MovieClip]   (missing)
```

`loader_domain_child.swf`'s root is `loader_domain_child_fla::MainTimeline`, and
its frame-1 child is a character bound by `SymbolClass` to `DuplicateClass`. We
instantiate that character as a bare `flash.display.MovieClip`, so (a) the
`DuplicateClass` constructor — which is what prints
`this.childFromDomainChild = ...` and `Child name: ...` — never runs, and (b)
assigning the bare clip to `MainTimeline`'s compiler-generated
`DuplicateClass`-typed instance field throws `#1034`. Note that the same
`new DuplicateClass()` *from script* works two lines later
(`clip = [object DuplicateClass]`), so the class itself resolves fine in the
child's domain: **only the timeline-placed character misses its SymbolClass
binding in a loaded child movie.**

This is the `avm2_display_char_for_class` / `g_symbol_map` "main-movie-only"
seam that `SWFRecompDocs/status/child-movie-bitmap-registry.md` describes for
embedded assets, surfacing on the display-character path. It is its own slot,
not part of L3. Completion mechanism: make the per-character class lookup
consult the *placing* movie's `symbol_classes` table (the child's
`Avm2MovieTables`), the way `loader_boot_child_swf` already does for the root
binding at `avm2_display.c:5859-5900`. Expected payoff: the whole 48/48.

### 5.2 The `loader-events` "regression" is an alignment coincidence — and the change is CORRECT

`from_shumway/as3-loader/events/loader-events` drops from 9 to 5 *positional*
matches. The only content change is that two lines disappear:

```
- added instance3     (was our line 13)
- added instance4     (was our line 20)
```

Those were **spurious**. Both fired because the loaded root's frame-1 children
used to be placed *after* `insert_at_index`, i.e. while the root was already
inside the Loader and therefore on the stage, so each child's `added` event
bubbled all the way to the fixture's stage-level `added` listener. Ruffle places
them before the insert, so they never reach it — and the expected output has
exactly **one** `added` per loaded movie (`added instance4`, `added instance2`),
never two. Our actual line count moves 37 → 35 against 36 expected.

The 4 lost "matches" are the two-line shift knocking `child 2 loader: open 0` /
`progress 0` / `progress 8700` and `added instance4` out of coincidental
alignment; none of them was semantically matched. This row is `known_failure`
upstream and is dominated by the L10 instance-name counter (we say `instance2`
where both oracles say `instance3`, from line 4 onward) plus a whole-frame
event-order gap; it stays `output_mismatch` in both legs.

**Corollary for the coordinator:** do not read this row's line delta as a
regression.

### 5.3 The brief's "one-position rotation in the tick loop" was the right shape, the wrong location

L7 is **not** a reorder of `broadcast_named("exitFrame")` vs
`avm2_loaderinfo_run_exit_frame` — that pair is already in Ruffle's order
(`avm2_display.c:3640-3647`). The escape was one level down, inside
`avm2_loader_run_exit_frame`, where the boot and the fire shared a pass.

### 5.4 `loader_error_in_root_ctor` does not need the explicit `errored` bail

Dropping `if (lx->errored) continue;` from the `pending_boot` arm looks like it
leaks an errored entry onto the active list for one extra tick. It does — and
that is harmless: the next pass's `if (lx == NULL || lx->errored) continue;`
drops it without firing either event. Verified: `loader_error_in_root_ctor`
still passes 4/4.

### 5.5 A harness trap worth recording

`ruffle-tests/tests/swfs/avm2/loader_loadbytes_url` is partially **git-tracked**
(its `RecompiledScripts`/`RecompiledTags` and `test.local.toml` are in the repo,
its `test.swf` is gitignored). A fresh worktree therefore contains a *stub*
directory that a `cp -r` of "the dirs I need" silently skips, and the test then
reports `RECOMP_FAIL: SWF file 'test.swf' not found` — which is a harness
artifact, not a verdict. Re-copied and re-run: **pass**.

---

## 6. New unclaimed leads

* **Timeline-placed characters in a loaded child SWF never get their
  `SymbolClass` class** (§5.1). One fixture pays 16 lines
  (`avm2/loader_duplicate_class`, 32/48 → likely 48/48) and it is the display
  half of the same seam the Multi-SWF arc closed for bitmaps/ByteArrays/sounds.
  Bounded: the per-character class lookup already has the child's
  `Avm2MovieTables` in hand at `instantiate_child` time.
* **`from_shumway/as3-loader/events/loader-events` is now a two-mechanism row,
  both named**: L10's instance-name counter (three short — w1-trace-display §3)
  and a frame-boundary gap where our `root loader: progress` never fires and the
  child-loader `open`/`progress` pair lands a frame early. Re-grade it after L10
  lands, before pricing the second half.
* **`--save-actual` + a positional compare should be the default triage tool for
  the loader family.** Three of the four rows I touched were mis-priced by the
  `--diff` display: `loader_duplicate_class` looked like a 45-line defect and is
  3; `large_preload_from_bytes` looked like 10 and is 1 ordering rule;
  `loader-events` looks like a 4-line regression and is a 2-line improvement. A
  ~15-line script over `output.txt` + `.actual` settles each in seconds
  (`<scratchpad>/w2-avm2-loader/side.py`, `match.py`).
* **`LoaderInfo.unload` (w1's L9) HOLD — nothing learned that changes it.** I did
  not touch `loader_unload`; `loader_events_2` and
  `mixed_avm/avm2_loads_avm1_events` are byte-identical before and after this
  patch, so w1's grading of them against `output.ruffle.txt` still stands.
