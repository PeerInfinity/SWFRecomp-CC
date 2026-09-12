# w1-loaders — session 19 wave 1: loaders, MovieClipLoader timing, loaded-child gaps

Read-only diagnosis. No source edits, no commits. Every corpus row below was RE-RUN at HEAD
(`254145a5b` + the device-lost render commit), no-graphics, sequential,
`SWFRECOMP_COMPILE_TIMEOUT=2400`. Scratch (fixtures, oracles, actuals, logs):
`<scratchpad>/w1-loaders/` — `btnfix/`, `mclfix/`, `mclfix2/` (source + build scripts + Ruffle
exporter traces), `fx/` (runnable scratch test dirs), `act/`, `log/`.

## 1. Verdicts, priced

| lead / row | verdict | flips | size |
|---|---|---|---|
| **L3 loaded child's `SimpleButton` has no states** (brief lead 3) | **GO — CONFIRMED by a built fixture** | **0 corpus** (+1 new `regression/` fixture) | ~6 lines, 1 function |
| **L9+L9b `avm2/loader_events_2`** (LoaderInfo `unload` + the duplicate root `added`) | **GO** | **+1 effective** (output_mismatch 2/35 → **ruffle_matched**, exact) | ~10 lines, 2 sites |
| **L1a MCL: `onLoadInit` before the root's `onEnterFrame` + the child's double step** (brief lead 1, narrow half) | **GO** | **0 corpus** (+1 new fixture; oracle in hand) | ~30 lines, 2 files |
| **L1b MCL: "the load lands a tick late"** (brief lead 1, delivery half) | **NO-GO — REFUTED** (§4.1) | would move `from_shumway/avm1/moviecliploader` **pass → ruffle_matched** = a rule-3 regression | — |
| **L2 `onLoadStart` doesn't see Ruffle's initial-loading state** (brief lead 2) | **GO (low value)**, and its stated RISK is **refuted** (§4.2) | **0 corpus** (+1 fixture) | ~5 lines |
| `mixed_avm/avm2_loads_avm1_events` | **HOLD** | +1 effective only with **three** mechanisms (§3.3) | session-sized |
| `from_shumway/as3-loader/events/loader-events` | **HOLD** — new sub-lead named (§3.4) | 0 (diff-line) | — |
| `mixed_avm/avm1_loads_avm2` | **NO-GO** (harness/build arc, re-verified at HEAD) | — | build arc |
| `from_shumway/as3-loader/LoaderLoadBytesTest` | **NO-GO** (s18 N2 stands: `DefineBinaryData` → SWF recompile arc) | — | recompiler arc |
| `avm2/mouse_pick_loader_avm1` | **NO-GO for this family** (s17/s18 leg F + AVM1-button legs, unmoved) | — | — |

Baseline statuses re-confirmed at HEAD (all `output_mismatch` except where noted):
`avm2/loader_events_2` 2/35, `avm2/mouse_pick_loader_avm1` 16/42,
`from_shumway/as3-loader/LoaderLoadBytesTest` 1/4, `.../events/loader-events` 5/36,
`mixed_avm/avm1_loads_avm2` 3/7, `mixed_avm/avm2_loads_avm1_events` 7/26;
`from_shumway/avm1/moviecliploader` **pass**, `from_gnash/actionscript.all/MovieClipLoader-v5..v8`
**pass**, `regression/avm1_mcl_holder_totalframes` **pass**. No upstream drift seen in this family.
Disposition check (rule 2): none of these rows is in `ACCEPTED_DIFFS.md`, `RUFFLE_COMPAT_TWEAKS.md`,
`FLASH_BUGS_REPLICATED.md` or any `ignored_tests.txt`; `mouse_pick_loader_avm1` appears in
`RUFFLE_VS_FLASH_DIFFERENCES.md` only as an example of `avm1_root` machinery, not as a disposition.

## 2. L3 — a loaded child's `SimpleButton` has no states: CONFIRMED, with an oracle

The brief asked to confirm or refute a code-reading lead. **Confirmed, reproduced, oracled.**

Built `<scratchpad>/w1-loaders/btnfix/` (`build.py`, needs `~/CC/flex-sdk/bin/mxmlc`): an mxmlc
parent `Loader.load`s an mxmlc child into which the script injects `DefineShape 1` (20px red),
`DefineShape 2` (40px blue), `DefineButton2 3` (up = shape 1; over = shapes 1+2, i.e. the
multi-record wrapper arm; down = shape 2; hit = shape 1) and a root `PlaceObject2` of char 3.
The parent prints each state.

| | Ruffle exporter (oracle) | ours |
|---|---|---|
| `child0:` | `flash.display::SimpleButton` | same |
| `up:` | `flash.display::Shape w=20 h=20` | **null** |
| `over:` | `flash.display::Sprite w=40 h=40 kids=2` | **null** |
| `down:` | `flash.display::Shape w=40 h=40` | **null** |
| `hit:` | `flash.display::Shape w=20 h=20` | **null** |
| `button w=` | `20 h=20` | **0 h=0** |

Oracle recipe (memory `mcl_load_timing`): `RUFFLE_LOCAL_FETCH_DIR=<d>
RUFFLE_MOVIE_URL=https://armorgames.com/test.swf ~/CC/ruffle/target/release/exporter test.swf out
-s -f 6 --trace-log ruffle.txt`, both SWFs under `<d>/armorgames.com/`.

**Mechanism** (exactly as the brief says): `button_data_for_char`
(`SWFModernRuntime/src/avm2/avm2_display.c:12447`) scans `avm2_generated_buttons` only.
`class_for_char` already answers `SimpleButton` for a child's `DefineButton2` (its `chars` row falls
through `char_info`), so the object exists but `button_create_state` gets `bd == NULL` and returns
NULL for all four states. **Fix = the same `g_child_movies` fall-through `char_info` /
`timeline_for_char` / `class_for_char` / `avm2_display_char_is_defined` already have** (a child's
`Avm2MovieTables.buttons` exists and `offsetCharIds` in `SWFRecomp/src/abc/abc_timeline.cpp:1818`
already shifts BOTH `ButtonDef.char_id` and every `ButtonRec.char_id` by `char_id_base`, so the bare
id keys correctly). Everything downstream of the lookup already falls through: `class_for_char` (with
the `movie_scope` s19 added), `resolve_shape_geom` (per-movie `shape_vert_base`), `timeline_for_char`,
`char_info`.

- **Files**: `avm2_display.c`, `button_data_for_char` only (+ nothing else; `movie_scope` threading
  through `button_create_state` already landed today).
- **Fixture needed**: `regression/avm2_child_simplebutton` — copy `btnfix/{test.swf,child.swf}`,
  `output.txt` = `btnfix/ruffle.txt` (byte for byte), `test.toml` `num_frames = 6`, plus `build.py`
  as its `create_test_swf.py`. Ready to lift as-is.
- **Risk to passing loader tests**: the only corpus child SWF with a `DefineButton2` is
  `from_shumway/as3-loader/LoaderTest2/Loadee2.swf` (scanned every child SWF in `avm2`, `mixed_avm`,
  `from_shumway/as3-loader`, `import_assets`, `timeline`, `regression`; the only other hit is
  `avm2/mouse_pick_loader_avm1/avm1.swf`, an **AVM1** child, a different code path). `LoaderTest2`
  passes and traces no button/child-name lines. Canary: `LoaderTest2`, `avm2/simplebutton_*`,
  `avm2/loader_*`, `regression/avm2_parent_child_*`.
- Sibling note: `nondisplay_class_for_char`'s ungraded scope arm (today's closeout §8) is the same
  family and is graded by a different fixture; don't bundle.

## 3. The board rows

### 3.1 `avm2/loader_events_2` — GO, +1 effective, two named mechanisms and nothing else

Graded against `output.ruffle.txt` (rule 3: `known_failure = true`, so `ruffle_matched` is the
honest ceiling; it is `output_mismatch` today, so this is a gain, not a drift), our actual is missing
**exactly four lines**, and they are two mechanisms:

```
 8: child added: target=[object Child], currentTarget=[object Child], eventPhase=2, bubbles=true   (L9b)
15: unload: target=[object LoaderInfo], ...                                                        (L9)
16: child unload: target=[object LoaderInfo], ...                                                  (L9, same dispatch)
24: child added: ... (the second load's copy of L9b)
```

Nothing else differs — so **L9 + L9b together flip the row to `ruffle_matched`**.

* **L9 `unload`.** Ruffle `loaderinfo_object.rs:266-284`: `LoaderInfo::unload` dispatches a bare
  `"unload"` event on the LoaderInfo **iff `loader.child_by_index(0)` is Some**, and does it BEFORE
  resetting the stream and removing the content child. Called from three places
  (`loader.rs:93` = `load`, `:266` = `loadBytes`, `:319` = `unload`). Ours
  (`avm2_display.c` `loader_drop_content`, reached from the same three sites, `:6613/:6653/:6704`)
  goes straight to `full_remove_child` + `loaderinfo_reset_stream`. Fix: dispatch the event at the
  top of `loader_drop_content` when content exists. ~5 lines.
* **L9b the duplicate `added`.** Not a Flash quirk to replicate blind — Ruffle's mechanism is named:
  `on_construction_complete` → `fire_added_events` (`display_object.rs:2404`) dispatches a
  **parentless** `added` on the loaded root at the end of its own construction, before
  `insert_at_index` dispatches the second one (which bubbles to the Loader and brings
  `addedToStage`). Our `on_construction_complete` (`avm2_display.c:2501`) gates on
  `ext->parent != NULL` — Ruffle's gate is only "parent is not an `SimpleButton`" — and
  `loader_boot_child_swf` never calls it for the loaded root anyway. Fix: after the root ctor
  returns successfully in `loader_boot_child_swf`, dispatch `added` (bubbles, no parent → no bubble
  path, and no `addedToStage` because it is not on stage). ~4 lines.
* **Blast radius of L9b is one test.** Of every corpus test with a child SWF, only four have a `.as`
  mentioning `Event.ADDED`: `avm2/loader_events` (listener on a *script-added* circle, not the root),
  `avm2/loader_loadbytes_events` (ADDED_TO_STAGE only), `avm2/loader_events_2` and
  `mixed_avm/avm2_loads_avm1_events` (AVM1 child, no AVM2 root object). So only `loader_events_2`
  can see the extra dispatch. **This is what makes L9+L9b a flip lead rather than a diff-line lead.**
* Canary: every `avm2/loader_*`, `loaderinfo_*` (esp. `loaderinfo_loadurl`, which calls
  `loader.unload()` and passes today — it registers no UNLOAD listener, checked), `mixed_avm/*`,
  `from_shumway/as3-loader/*`, `import_assets`, `regression`.

### 3.2 Which corpus test grades `LoaderInfo.unload`? (the brief's open question)

**Exactly two, both `known_failure`:** `avm2/loader_events_2` and `mixed_avm/avm2_loads_avm1_events`
(grep over every `output*.txt` in `avm2`, `mixed_avm`, `from_shumway`, `import_assets`, `timeline`,
`swf`: the only other `unload` strings are `avm2/all_classes/display/swf9..swf30`'s *method-listing*
rows, which already pass, and `avm2/loaderinfo_loadurl`'s own `trace("Loader.unload()")`). There is
no non-KF grader. `loader_events_2` flips with L9b as well; `avm2_loads_avm1_events` needs two more
mechanisms (§3.3).

### 3.3 `mixed_avm/avm2_loads_avm1_events` — HOLD, +1 only with three mechanisms

Versus `output.ruffle.txt` (26 lines vs our 25), the residual is:

1. **`unload`** (L9 above) — one line.
2. **The AVM1 child's first frame runs too early.** Ruffle: `added AVM1Movie`, then `frame 1` (the
   AVM2 root's `enterFrame`), then `child` (the AVM1 child's frame-1 trace). Ours fires `child`
   before `frame 1`. Same family as L1a below, on the cross-VM path (`avm1_child_boot`).
3. **`init`/`httpStatus`/`complete` must land a frame later.** Ruffle fires them after the child has
   run its first frame (`movie_loader_complete`'s AVM2 arm fires init/complete *itself* only when
   `dobj.as_movie_clip().is_none()`; for a movie it waits for `MovieClip.on_exit_frame` →
   `try_fire_loaderinfo_events`). Ours fires them in the load's own frame. This is the AVM1-child
   twin of s18's L7 (which fixed the `loadBytes` case for AS3 children).

All three are needed for `ruffle_matched`; any two leave the row `output_mismatch`. Completion
mechanism for (2)+(3): route an AVM1 child load through the same `pending_boot` → next-drain
rotation `avm2_loader_run_exit_frame` already does for AS3 children, and boot the AVM1 level after
the tick's `enterFrame` broadcast.

### 3.4 `from_shumway/as3-loader/events/loader-events` — HOLD, and s18's pricing has moved

New at HEAD (s18's L10 pricing said "we say `instance2` where the oracles say `instance3`"): we now
print **`null`**, not a wrong number, for a loaded root's `name` —
`construct null, parent: null` / `added null` / `run frame 1 in null` where Ruffle says
`instance3`/`instance5`. `loader_boot_child_swf` never calls `set_default_instance_name` on the
loaded root. That is a *separate, cheaper* sub-lead than the global counter A/B (L10), it is worth
~5 of this row's lines, and it should be A/B'd against the counter work rather than folded into it.
Two more mechanisms remain on the row: a missing `root loader: httpStatus 1293`, and `run frame 1 in
<child>` running inside the boot (s18's L3/L7 work) where Ruffle runs it in the frame-script phase.
Still a diff-line lead, not a flip lead, and it is `known_failure`.

## 4. The MCL leads — measured, with two refutations

Two scratch fixtures, both with a Ruffle-exporter oracle and our actual:

* `mclfix/` — **1-frame MTASC loader** (so `loadClip` takes the `_this_tick` bucket), a hand-built
  3-frame AVM1 child tracing `c1/c2/c3`, `_root.onEnterFrame` tracing `t<N> h.cf=<_currentframe>`,
  and all four MCL handlers.
* `mclfix2/` — the same, with a second loader frame (`loader frame 2`), i.e. the `_next_tick`
  deferral bucket that `from_shumway/avm1/moviecliploader` exercises.

| | Ruffle (oracle) | ours |
|---|---|---|
| 1-frame loader | `c1, t1 h.cf=1, onLoadInit cf=1, c2, t2 h.cf=2, c3, t3 h.cf=3, t4..t6` | `c1, onLoadInit cf=1, c2, t1 h.cf=2, c3, t2 h.cf=3, t3..t6` |
| 2-frame loader | `onLoadStart..onLoadComplete, c1, t1 h.cf=1, loader frame 2, onLoadInit, c2, t2, c3, t3..` | `t1 h.cf=0, loader frame 2, onLoadStart..onLoadComplete, c1, onLoadInit, c2, t2, c3, t3..` |

(Both traces are 14/15 lines on both sides; the difference is pure ordering.)

### 4.1 REFUTATION: the delivery half of lead 1 has two *contradicting* oracles — do not fix it

The brief asks to "move the load tick AND drop the double step together". The 2-frame fixture shows
our delivery (start/progress/complete + the movie's frame 1) is one tick later than Ruffle's — but
that deferral is *Flash's* behaviour and is exactly what `from_shumway/avm1/moviecliploader` grades:
its `output.txt` (Flash) puts `loader frame 2` BEFORE `onLoadStart`, while its `output.ruffle.txt`
puts `loadee frame 1` before `loader frame 2`. **We pass that test today because we follow Flash.**
Moving delivery to Ruffle's tick converts it `pass → ruffle_matched` on a `known_failure = true`
test — a regression under BRIEFS_COMMON rule 3, for zero effective gain. So:

* **Do NOT touch the two-bucket delivery deferral** (`builtin_mcl_loadClip`'s
  `defer_to_next_tick` + `actionPromotePendingMCLLoads`); it is load-bearing and Flash-correct.
* A `regression/` fixture built on the **2-frame** loader would encode Ruffle's delivery tick and
  must NOT be created. Use the **1-frame** fixture, whose Ruffle order is reachable without touching
  delivery.

### 4.2 L1a — GO on the narrow half: `onLoadInit` after `enterFrame`, and single-stepping the child

With delivery left alone, the 1-frame fixture's whole Ruffle trace is reachable by two changes:

1. **Split Phase 3 out of the drain.** `actionFirePendingLoadInits`
   (`action.c`, Phase 1 events → Phase 2 `init_func` + `frame_funcs[0]` → Phase 3 `onLoadInit`) fires
   Phase 3 in the same pass, inside `tagShowFrame`. Queue Phase 3 for the NEXT tick and drain it in
   `libswf/swf_core.c` **immediately before `actionAdvancePlayingLevels`** (`swf_core.c:1462`) — that
   slot is after the tick's `actionDispatchEnterFrameHandlers` (`:1220`) and before the child's
   advance, which is precisely Ruffle's `t1, onLoadInit, c2`. Draining at the existing end-of-tick
   MCL site (`:1517`) would give `t1, c2, onLoadInit` — wrong; the position matters.
2. **Drop the double step for MCL targets**: `actionRegisterLevelAdvance` (`action.c:24329`) passes
   `start_armed = 1`, so the loaded movie runs `frame_funcs[0]` (Phase 2) *and* one driver advance in
   the load tick. Pass `start_armed = 0` for MCL clip targets (direct `loadMovie` clip targets
   already do; leave `_levelN` alone — no fixture grades it and it widens the blast radius).

`swf.c` (graphics) carries the same two call sites and must be changed in lockstep (mode parity).

**Refutation of the entry's own claim in BACKLOG / `action.c:24232`** ("moviecliploader … only reaches
`loadee frame 2` because of the double step"): under 1+2 *with delivery unchanged*, that test's
sequence becomes tick2 = `loader frame 2`, start, complete, `loadee frame 1`; tick3 = `onLoadInit`,
`loadee frame 2` — still Flash's expected order, with `num_frames = 3` ticks. So the double step is
compensating for the **Phase-3 position**, not for the delivery tick, and 1 and 2 must land
*together* (dropping 2 alone deletes `loadee frame 2` from tick 2 with nothing to replace it).
This is the one claim in this report I could not settle without editing source: wave 2 must A/B
exactly this test first (it is 3 ticks wide and the tightest constraint in the family).

* **Flips: 0.** No corpus test reads a frame property or an `onEnterFrame` position across an MCL
  load. Payoff is the fixture plus unblocking `holder.gotoAndStop`/second-load work that inherits
  the armed hack.
* **Fixture**: `regression/avm1_mcl_load_tick` from `mclfix/` (`Parent.as`, the hand-built 3-frame
  child, `output.txt` = `mclfix/ruffle.txt`, `num_ticks = 8`). It discriminates both halves: revert
  (1) and `onLoadInit` moves above `t1`; revert (2) and `c2`/`t1` swap.
* **Canary (tick-budget sensitive — these are the ones that can break)**:
  `from_shumway/avm1/moviecliploader` (3 ticks, Flash order), `avm1/loadmovie_fail`
  (`num_frames = 1`), `avm1/string_paths_eval2` (`num_frames = 5`, `stop()` + chained
  `setTimeout`), `avm1/loadmovie_var_persistence` (`num_ticks = 6`, chained `loadClip` from
  `onLoadInit` — a one-tick Phase-3 delay stretches the whole chain),
  `from_gnash/actionscript.all/MovieClipLoader-v7/v8` (30 frames, chained loads through the
  handlers), the 25-test `avm1/{mcl_*,loadmovie*,unloadmovie*,load_cancel_*}` battery, and
  `regression/avm1_mcl_holder_totalframes` + the `avm1_child_timeline_*` family.

### 4.3 L2 — the brief's stated risk is REFUTED; the lead itself is real but worth 0

The brief: "Gnash `MovieClipLoader-v5..v8` assert on `getProgress()` bytes inside handlers, so say
exactly which of their lines move." Read them:

* **v5 and v6 assert nothing at all** — their entire `output.txt` is 6 lines ending
  `#total tests run: 0`. They cannot move.
* **v7 and v8** (165 lines, `#total tests run: 145`) have their `getProgress` assertions inside
  **`onLoadProgress`**, not `onLoadStart`: `prog.bytesLoaded == bytesLoaded`,
  `prog.bytesTotal == bytesTotal`, `progcount == 2`, `progcopy.* == *`. All are *relative* to the
  handler's own arguments. Their `onLoadStart` handler asserts only `arguments.length == 1`,
  `target+"" != ""`, `target == expected.target` — **no bytes, no frame counts**. And their loads are
  `vars.txt` / `green.jpg` / a missing URL, not SWFs.
* So modelling Ruffle's initial-loading state — write `totalframes`/`framesloaded`/`byte_size` 0
  during Phase 1's `onLoadStart` and install the real values between `onLoadStart` and
  `onLoadProgress` (the Pre-phase writes move down one step) — **moves no gnash line**.

Value: 0 corpus flips (no corpus test reads any of these inside `onLoadStart`; re-confirmed today's
closeout's grep), so it needs its own fixture; Ruffle's measured row is
`start cf:0 tf:0 fl:0 bl:0 bt:0` (closeout `avm1-mcl-holder-totalframes.md` §2). Cheap and safe, but
bundle it with L1a rather than spending a slot on it.

## 5. Other refutations / corrections

* **`mixed_avm/avm1_loads_avm2` re-verified from scratch at HEAD**: 3/7, actual = our three AVM1
  parent lines, the AVM2 child never runs. The blocker is still `verify_output.py:2477`
  (`if is_avm2 and child_abc.exists():`) — an AVM1 parent does not compile `src/avm2` at all. Nothing
  in the s19 loader work touches it. NO-GO, build arc (s15 `w2-avm1-child-report.md` §3.4 sizes it).
* **`from_shumway/as3-loader/LoaderLoadBytesTest`** — s18's N2 re-confirmed by inspection: the loadee
  is `[Embed(mimeType='application/octet-stream')]`, emitted as raw bytes in
  `avm2_generated_binaries`; nothing recompiles it and `find_child_swfs` only sees on-disk SWFs.
  3 lines of payoff behind a recompiler+harness arc. NO-GO.
* **`avm2/mouse_pick_loader_avm1` 16/42 re-confirmed**; s17 leg F + AVM1-button dispatch + the
  `AVM1Movie` stage-rect fallback, all three needed, still a diff-line lead. Not this family's slot.
* **A pricing correction for whoever takes L9**: the `unload` dispatch alone is worth **0 flips**.
  Both of its graders need extra mechanisms (L9b for `loader_events_2`; §3.3's two for
  `avm2_loads_avm1_events`). Sending `unload` on its own is a diff-line change.

## 6. New unclaimed leads

* **A loaded root never gets a default instance name** (`name` reads `null`, oracles say
  `instanceN`) — `loader_boot_child_swf` skips `set_default_instance_name`. ~5 lines of
  `from_shumway/as3-loader/events/loader-events`, and it interacts with L10's global counter
  (A/B them together, cheap half first).
* **`root loader: progress`/`httpStatus` events on a URL load of a child SWF** are missing a line
  each in `loader-events` (`root loader: httpStatus 1293`), unexamined here.
* **`nondisplay_class_for_char`'s child-domain arm is still ungraded** (today's closeout §8); a child
  whose timeline places a bitmap bound to a `BitmapData` subclass, loaded into a fresh domain,
  would grade it — the same fixture shape as `btnfix/` with a `DefineBitsLossless` instead of a
  button.
* **`symbol_char_is_placed` (`avm2_main.c:359`) is main-movie-only** by the same pattern L3 fixes
  (it scans `avm2_generated_timelines`/`avm2_generated_buttons` with no `g_child_movies`
  fall-through). Unprobed; it gates the "is this symbol placed" decision for a child's characters.
* **A scratch-dir test tree works as a fixture harness**:
  `verify_output.py --tests-dir=<scratchpad>/w1-loaders/fx --test=<name>` runs a hand-built
  parent+child pair without touching the corpus. Three ready-made ones are in `fx/`
  (`avm2_child_button`, `avm1_mcl_tick`, `avm1_mcl_tick2`), each with its Ruffle oracle as
  `output.txt`.
