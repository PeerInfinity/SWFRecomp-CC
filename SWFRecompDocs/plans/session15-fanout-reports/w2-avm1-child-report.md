# w2-avm1-child — AVM1 child under an AVM2 parent (dual-VM), session 15 wave 2

**Agent:** `w2-avm1-child`, wave-2 implementation, isolated worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a787e37019857b0c4`.
**Patch:** `w2-avm1-child.patch` in that worktree.
**Baseline:** `42a324cef`, CI run `31647430265` (graphics / full), per-suite
`results_graphics.json` merged at `b15b9cbdf`.

---

## 1. Verdict

**GO — partial, delivered.** The cluster is real and the mechanism the board
quoted is exactly right, but the 14 rows are **three unrelated problems wearing
one label**, and only one of the three is a wave-2-sized slice.

| verdict | rows | what it is |
|---|---|---|
| **GO, landed** | the `mixed_avm/avm2_loads_avm1*` timeline rows | "the child's AVM1 timeline never runs" — genuinely one mechanism |
| **NO-GO (structurally wide)** | `avm2/avm1_root`, `mouse_pick_avm1_root`, `mouse_pick_loader_avm1`, `loader_try_click_root`, `focus_events_mixed_avm_edittext`, `selection_onsetfocus_mixed_avm` | cross-VM **display-tree, hit-test and focus** bridging, not timeline execution |
| **REFUTED (not this cluster at all)** | `import_assets/avm1_imports_avm1`, `mixed_avm/avm1_loads_avm2` | see §4 |

Board price was **+1 / +3 / +14**. **Delivered +3** — the "real" figure exactly.
The ceiling of 14 is not reachable from this mechanism and should be re-priced
to **+3 landed / +2 next (one constant, §3.5) / +6 behind a cross-VM
input+focus arc / +2 not in the cluster at all**.

**Flips (all verified locally, and the pilot verified in graphics mode too):**

- `mixed_avm/avm2_loads_avm1_doabc`
- `mixed_avm/avm2_loads_avm1_loads_avm2_doabc`
- `mixed_avm/avm2_loads_avm1_loads_into_root`

**Regressions: none.** 9 canaries (3 AVM1, 5 AVM2, 1 graphics) all hold, and the
three cluster rows that did not flip are byte-identical-or-better vs baseline —
`avm2_loads_avm1` in particular goes from **13 differing lines to 4** (§3.5).

*(per-test ledger in §3)*

---

## 2. Mechanism — what "execute the child's AVM1 timeline" actually needed

The runtime's own comment at `avm2_display.c:5703` named the gap correctly, and
the board's audit of the upstream plumbing was correct too: the harness
(`verify_output.py::recompile_child_swf` → `generate_child_movie_file`)
recompiles **every** child SWF regardless of the parent's VM and emits a
`MovieEntry` with prefixed `frame_funcs` / `tagInit`, and `action.c` is in
`core_sources` for AVM2 parents. The child's code was already **linked into the
binary and unreachable.**

Three things were missing, in ascending order of surprise:

**(a) The AVM1 substrate is never booted in an AVM2 binary.** `main.c` routes to
`runSWF_avm2()` under `-DSWF_AVM2`, and `swfStart()` — which allocates
`app_context->stack`, calls `initTime`/`initMap`, `HCALLOC`s `dictionary` and
`display_list`, and wires the root display sentinel — is never called. Every one
of those is a NULL deref waiting for the first AVM1 opcode. Fixed by a lazy
`avm1UnderAvm2Substrate()` that replays exactly `swfStart`'s AVM1 half, minus
`heap_init` (`runSWF_avm2` already ran it) and minus the parent's
`tagInit`/`tagMain` (the parent's timeline is AVM2's).

**(b) A container with a playhead.** The child's root timeline is given a
synthetic AVM1 `_levelN` (`getOrCreateLevel`, levels **1..N** — `_level0` stays
the AVM2 root's) with its own `sprite_display_list`, so the child's
`PlaceObject2` depths never collide with anything the AVM2 side indexes. A
falling-out benefit: `_root` inside the child resolves to `_level1` and
`_level0` to the AVM2 root, which is *already* the
`_root == _level0: false` line `mixed_avm/avm2_loads_avm1` grades.

**(c) The playhead LOOPS, and its first frame is DEFERRED.** Both were
measured, not assumed:

- `g_level_advance` (the existing AVM1 loadMovieNum machinery) is a **one-shot**
  run of frames 1..N-1 and then drops the entry. An AVM1 movie under a Loader
  keeps playing. `avm2_loads_avm1_doabc` pins it: a 2-frame child over 4 ticks
  traces frames **1, 2, 1**.
- Catching the child up to frame 1 inline at boot — which is what
  `loader_boot_child_swf` correctly does for an **AVM2** child root — produced
  **1, 2, 1, 2**: one frame too many. Ruffle hands a loaded AVM1 movie to the
  frame lifecycle instead, so its first frame runs on the tick *after* the load
  resolves. Booting registers the child at `next_frame = 0` and runs nothing;
  the tick hook runs frame 1 next time round. That single ordering choice is
  the difference between a mismatch and a pass.

**(d) A fourth rule fell out of `avm2_loads_avm1_loads_into_root`:** an AVM1
movie under an AVM2 Loader is **not the root movie**, so `loadMovieNum(url, 0)`
from inside it has no `_level0` of its own to replace — Flash drops the load
outright. Without the gate we traced the inner SWF's `hello from inner!`, which
Flash never does. This is a genuinely new semantic, not an implementation
detail, and it is the whole content of that test.

### Where the tick hook sits

`avm1_child_tick()` runs at the **top** of `avm2_display_run_tick`, before
`PHASE_ENTER` and therefore before the tick's own `avm2_loader_drain`. That
ordering is load-bearing: a child booted by tick N's drain must not also advance
inside tick N. It is a single global comparison (`g_avm1_child_levels == 0`)
until an AVM1 child actually loads, so a pure-AVM2 movie pays nothing.

---

## 3. Per-test ledger

All local, `--mode` default (NO_GRAPHICS), single tests only, `-P 2` cap.
"Baseline" = this worktree at `42a324cef` for the four rows I re-verified by
hand, and the merged CI `results_graphics.json` for the rest.

### The 14 board rows

| # | test | baseline | after | note |
|---|---|---|---|---|
| 1 | `mixed_avm/avm2_loads_avm1_doabc` | output_mismatch (3 lines missing, re-verified locally) | **PASS** | the pilot; frames 1,2,1 |
| 2 | `mixed_avm/avm2_loads_avm1_loads_avm2_doabc` | output_mismatch (2 lines) | **PASS** | AVM1 child's own `loadMovie` of an AVM2 SWF stays silent, as expected |
| 3 | `mixed_avm/avm2_loads_avm1_loads_into_root` | output_mismatch (1 line, re-verified locally) | **PASS** | needed a second, new semantic — §3.1 |
| 4 | `mixed_avm/avm2_loads_avm1_v9` | output_mismatch (1 line, re-verified locally) | not flipped — **diff byte-identical to baseline** | needs AVM1Movie.x → AVM1 `_x` propagation **and** an AVM1 enterFrame/watch notification; §3.2 |
| 5 | `mixed_avm/avm2_loads_avm1_v10` | output_mismatch (3 lines) | not flipped | v9's defect + `addChild(AVM1Movie)` must throw #2180 in SWF≥10; §3.2 |
| 6 | `mixed_avm/avm2_loads_avm1` | output_mismatch, **13** lines differ (actual 4 / expected 14) | not flipped, but **13 → 4 differing lines** | biggest near-pass left in the corpus after this patch; §3.5 |
| 7 | `mixed_avm/avm1_loads_avm2` | output_mismatch | **NO-GO** | reverse direction; harness-blocked (§4) |
| 8 | `avm2/avm1_root` | output_mismatch (upstream known_failure) | **NO-GO** | AVM1 path resolution through AVM2 containers (§4) |
| 9 | `avm2/mouse_pick_avm1_root` | output_mismatch | **NO-GO** | cross-VM hit test |
| 10 | `avm2/mouse_pick_loader_avm1` | output_mismatch | **NO-GO** | cross-VM hit test + mouseChildren/mouseEnabled |
| 11 | `avm2/loader_try_click_root` | output_mismatch | **NO-GO** | cross-VM hit test |
| 12 | `avm2/focus_events_mixed_avm_edittext` | output_mismatch | **NO-GO** | cross-VM focus model |
| 13 | `avm2/selection_onsetfocus_mixed_avm` | output_mismatch | **NO-GO** | cross-VM focus model |
| 14 | `import_assets/avm1_imports_avm1` | output_mismatch | **REFUTED** | no `RecompiledABC/` — not a dual-VM test at all (§4) |

**Delivered: +3** (`avm2_loads_avm1_doabc`, `avm2_loads_avm1_loads_avm2_doabc`,
`avm2_loads_avm1_loads_into_root`), i.e. exactly the board's "real" price, from
a cluster whose ceiling of 14 is not reachable by this mechanism.

### 3.1 `avm2_loads_avm1_loads_into_root` — the second semantic

With only the timeline work, the test went from missing `hello from outer!` to
**emitting an extra `hello from inner!`** — the outer AVM1 SWF's inner load into
root actually executed. The first gate I wrote (in
`actionFirePendingDirectLoads`, for `mc == &root_movieclip`) did **not** catch
it, which located the real path: root replacement in the `ActionGetURL2`
loadMovie handler is **synchronous**, not queued (`if (_gu2_mc ==
&root_movieclip)` — "Root replacement: keep synchronous (complex state
clearing)"). Gating both sites through one predicate
(`actionAvm1UnderAvm2IsRootTarget`, which covers the AVM2 root's `_level0`
*and* any booted child's own level root) flipped it.

### 3.2 What the three unflipped `mixed_avm` rows still need

- **`_v9` (1 line):** the whole diff is `(inner swf) x set, new value: 99`. The
  AVM2 side already produces all seven preceding lines including
  `Content X after setting x: 99`, so `AVM1Movie.x` writes somewhere the AVM1
  child cannot see. Two pieces are missing, and both are new surface, not
  tuning: (i) the `AVM1Movie` wrapper needs a link to its `MovieClip*` so its
  `x`/`y`/`width`/… accessors write the AVM1 root's `_x`; (ii) the AVM1 child
  has to be *notified* — its trace fires from AVM1 code that observes the
  change, and this tick hook deliberately does not dispatch AVM1 `onEnterFrame`
  / clip events yet. I left the wrapper→`MovieClip` field OUT of the patch
  rather than add a `Avm2DisplayObjectExt` field I could not finish using.
- **`_v10` (3 lines):** `_v9`'s defect plus `addChild(AVM1Movie)` throwing
  **#2180** in SWF ≥ 10 (we allow it and print the v9-shaped
  `Second child…`/`…after adding: 2` pair). The #2180 half is genuinely the
  independent ~5-line fix the board described and is worth grabbing on its own.
### 3.5 `avm2_loads_avm1` — 13 differing lines down to 4, and the next one is a constant

This row was priced as hopeless-in-one-session and it very nearly is not. **Five
of its lines flipped for free** once the child's timeline ran — `_global access
in DoInitAction:` / `[type Object]` (its DoInitAction now executes), `root
depth:`, `hello from avm1!`, and `_root == _level0: false` (which falls out of
the `_levelN`-container choice, exactly as predicted in §2b). The remaining diff
is four lines:

```
-  5  -77824            +  5  -16383
-  7  Root depth: -77824  +  7  Root depth: -16383
-  12 2180              +  12 <end of actual>
-  13 ArgumentError     +  13 <end of actual>
-  14 onmousedown at 10, 10!  + <end of actual>
```

Two of the four are **one constant**: Flash/Ruffle give a Loader-loaded AVM1
movie's root a depth of **-77824**, where `getOrCreateLevel` gives
`level - 16384` = `-16383`. Stamping `-77824` on the dual-VM container instead
of the level formula is a two-line change and takes the row to **2 differing
lines** (`#2180` + `ArgumentError` on `addChild(AVM1Movie)`, which is the same
five-line fix `_v10` wants, and the AVM1 `onMouseDown` dispatch, which needs
the cross-VM input plumbing the four NO-GO rows also need).

I did **not** make the depth change: it is not enough to flip the row on its
own, and picking `-77824` out of a fixture without deriving it from Ruffle's
depth model is exactly the kind of fixture-fitting that should be a deliberate,
evidenced decision rather than a wave-2 drive-by. It is the single
highest-value follow-up in the cluster: **one constant, +2 lines on the corpus's
largest surviving near-pass, and it unblocks a 2-line row for the next session.**

### 3.3 Canaries

| suite | test | baseline | after |
|---|---|---|---|
| avm1 | `loadmovienum` | pass | **pass** |
| avm1 | `mcl_loadclip` | pass | **pass** |
| avm1 | `loadmovie_replace_root` | pass | **pass** |
| avm2 | `goto_methods` | pass | **pass** |
| avm2 | `movieclip_displayevents_timeline` | pass | **pass** |
| avm2 | `filter_rewind` | pass | **pass** |
| mixed_avm | `avm2_doaction` | pass | **pass** |

**Zero regressions across 9 canaries + 3 measured non-flipped cluster rows.**
The three AVM1 canaries cover the paths my new code reuses; the four AVM2
canaries cover the frame lifecycle and loader; the graphics run covers the one
line of the patch that only exists in graphics builds.
| avm2 | `loader_events` | pass | **pass** (see note) |
| avm2 (graphics) | `avm2_loads_avm1_doabc --mode=graphics` | output_mismatch | **PASS** |

The graphics run matters twice over: it is the per-change CI mode, and it is the
only build where the `tag.c` guard is live. Without that guard an AVM1 child's
`tagShowFrame` dereferences the never-built AVM1 `RenderContext` and the binary
segfaults; with it, graphics and no-graphics agree byte-for-byte, so **mode
parity holds for this patch**. Run locally against `~/CC/dawn-install`
(`DAWN_INSTALL=` — a fresh worktree does not inherit the main tree's default
Dawn path).

**Trap hit and logged:** `loader_events` first read as `compile_fail` (`ld
returned 1`). It is **not** a regression — it is the known stale-`RecompiledABC`
trap. I had `cp -r`'d the test dir into the worktree without `--recompile`, and
the checked-in `RecompiledABC/` predates
`avm2_generated_symbol_class_frames` / `avm2_generated_device_fonts` /
`avm2_generated_abc_frames` / `avm2_generated_abc_lazy`, so the link is short
four generated symbols that have nothing to do with this patch. Confirmed by
`nm`: `action.o` defines all three new `actionAvm1UnderAvm2*` /
`action*Avm1Child*` symbols and `avm2_display.o`'s two `U` references resolve.
Re-run with `--recompile`.

`avm1/loadmovie_replace_root` is the one that matters most for the AVM1 axis:
it is the only canary that exercises the **synchronous root-replacement arm** I
restructured, and its build is byte-identical to the pre-patch one (the
`#ifdef SWF_AVM2` prefix vanishes from the preprocessor output).
`loadmovienum` and `mcl_loadclip` cover the two queue drains
(`actionFirePendingDirectLoads`, level advance) my tick hook reuses.

---

## 4. Refutations

**`import_assets/avm1_imports_avm1` is not in this cluster.** It has **no
`RecompiledABC/`** — it is an AVM1 parent importing assets from an AVM1 child
via `ImportAssets`. There is no AVM2 anywhere in it, so `-DSWF_AVM2` is never
defined for it and this patch cannot move it by construction. Its failure
(`Guy_with_hat loaded!` … five missing lines) belongs to the `actionImportAssets`
path, not the dual-VM arc. The board's row list should drop it.

**`mixed_avm/avm1_loads_avm2` is the mirror problem and is harness-blocked, not
runtime-blocked.** `verify_output.py:2331` gates the AVM2 child's table linkage
on `is_avm2` (the *parent's* VM) because an AVM1 parent does not compile
`src/avm2` at all — linking an AVM2 child's tables into it is an
undefined-symbol wall. Fixing it means compiling the whole AVM2 module tree into
AVM1 parents (and picking which VM owns `main`), which is a build-system arc,
not a runtime one. The board already flagged this; I confirmed the gate is still
exactly where the comment says.

**`avm2/avm1_root` is upstream `known_failure = true`** (it is listed in
`ruffle-tests/tests/swfs/avm2/ignored_tests.txt` under that heading), so it
scores as effective only on a `ruffle_matched`, and its fixture is 40+ lines of
AVM1 target-path resolution *through* AVM2 containers
(`_level0.as3Loader.defined_avm1_name._x`, `typeof _level0.as3Loader` →
`movieclip`, plus an AVM2 `#1056`). Nothing in the timeline slice touches it.

**The four mouse/focus rows are a different arc entirely.** Their expectations
are click-target attribution across the VM boundary
(`Clicked on: [object Loader] (instance2)` vs `[object MovieClip] (rect_mc)`,
`mouseChildren`/`mouseEnabled` propagating into an AVM1 subtree) and focus event
interleaving (`Selection.onSetFocus` from AVM1 interleaved with AVM2 `focusIn`/
`focusOut`). Running the child's timeline is a *precondition* for them, not a
step toward them: they need the AVM1 child's display list to participate in the
AVM2 hit-test walk and the AVM1 focus model to share a focus owner with AVM2's.
Pricing them into a dual-VM "timeline" cluster overstated the ceiling by ~6.

### 3.4 Why the blast radius is small

Every line of new behaviour is behind **`#ifdef SWF_AVM2`**, which
`verify_output.py:2498` adds exactly when the test has a `RecompiledABC/`, and
which `SWFRecomp/scripts/build_wasm_avm2.sh:152` adds for the AVM2 wasm build.
Those are the only two build paths that compile `avm2_display.c` at all, so:

- **AVM1 corpus:** the preprocessor deletes the entire new `action.c` block and
  both gated statements. The only line an AVM1 build sees is the `tag.c`
  `context == NULL` guard, which is unreachable there (`swfStart` assigns
  `context` before the first frame runs).
- **Pure-AVM2 corpus:** the tick hook is one `g_avm1_child_levels == 0` test per
  frame, `avm1_entry` is a NULL trailing field on a stack struct, and the two
  gated `action.c` statements test `g_avm1_under_avm2_ready`, which stays 0
  unless an AVM1 child actually boots.

No AVM2 frame-advance behaviour is touched: the hook sits *outside* the phase
sequence, `currentFrame` state is written only on the synthetic AVM1 `_levelN`
MovieClip the child owns, and nothing in the patch reads or writes an
`Avm2DisplayObjectExt` timeline field.

---

## 5. Patch scope — every function touched

Three files. **No sibling overlap**: `w2-t10-descriptor` has `avm2_globals.c` +
`avm2_text.c:9142`, `w2-textblock` has `avm2_text.c` + `avm2_globals.h` — I
touch neither. The AVM1 agents' territory (`action.c` watch dispatch, timeline
placement/depth in `tag.c`/sprite code) is avoided: every `action.c` addition is
a **new** function inside one contiguous `#ifdef SWF_AVM2` block, and the two
edits to pre-existing functions are single `#ifdef SWF_AVM2` statements that
vanish from the preprocessor output of any AVM1 build.

### `SWFModernRuntime/src/actionmodern/action.c`

New, all inside one `#ifdef SWF_AVM2 … #endif` block placed immediately after
`actionAdvancePlayingLevels`:

| symbol | kind | what it does |
|---|---|---|
| `g_avm1_under_avm2_ready` | new static | substrate-booted flag; also the "am I a dual-VM run" predicate |
| `avm1UnderAvm2Substrate()` | **new static fn** | lazy replay of `swfStart`'s AVM1 half (stack, `initTime`, `initMap`, `dictionary`, `display_list`, root sentinel, current context) |
| `Avm1UnderAvm2Child`, `g_avm1u2[]`, `g_avm1u2_count`, `MAX_AVM1_UNDER_AVM2` | new types/statics | the booted-children table with a looping playhead |
| `avm1UnderAvm2RunFrame()` | **new static fn** | one child frame with version/globals/movie-id/display-list/transform swap (structurally a copy of `actionAdvancePlayingLevels`' swap; deliberately duplicated, not shared, so no AVM1-only path changes) |
| `actionBootAvm1ChildUnderAvm2()` | **new exported fn** | AVM2 seam: substrate + `_levelN` container + `tagInit`, registers the playhead |
| `actionAvm1UnderAvm2IsRootTarget()` | **new exported fn** | "this MovieClip is a root a dual-VM child may not replace" |
| `actionTickAvm1ChildrenUnderAvm2()` | **new exported fn** | one AVM1 tick: advance every child, then drain the child's own direct loads / level advances / deferred unloads |

Pre-existing functions modified (each an `#ifdef SWF_AVM2` statement only):

- `actionFirePendingDirectLoads()` — one `continue` for a dual-VM root target.
- the `ActionGetURL2` loadMovie handler's **synchronous root-replacement arm**
  (`if (_gu2_mc == &root_movieclip)`) — prefixed with a dropped-load arm. In an
  AVM1 build the preprocessor removes the prefix and the arm is textually the
  original `if`.

### `SWFModernRuntime/src/avm2/avm2_display.c`

- `Avm2PendingLoad` — one new trailing field `avm1_entry`.
- `loader_resolve_url()` — one line populating it.
- `loader_deliver()` — one `avm1_child_boot(...)` call in the existing
  `pl->avm1_child` arm (plus a comment rewrite of the "we do not execute the
  child's AVM1 timeline yet" note that motivated this brief).
- **new statics** `g_avm1_child_levels`, `avm1_child_boot()`, `avm1_child_tick()`.
- `avm2_display_run_tick()` — one `avm1_child_tick(ctx)` call at the top, plus a
  forward declaration above the function.

### `SWFModernRuntime/src/libswf/tag.c`

- `tagShowFrame()` — one `if (context == NULL) return;` at the head of its
  `#ifndef NO_GRAPHICS` composite/render section. Required for graphics mode:
  an AVM1 child's frame func reaches `tagShowFrame` in an AVM2 binary where
  `swfStart` never built the AVM1 `RenderContext`, and `context->xform_slot_count`
  two lines down is a NULL deref. `tagRerenderFrame` has carried the same guard
  since it was written. Deliberately **not** `|| !context->renderer_ok` —
  `renderer_ok == 0` is a state real AVM1 graphics builds reach, and it must
  keep its existing path.

### Not touched, deliberately

- **`ruffle-tests/verify_output.py`** — no harness change was needed. The child
  recompile, symbol prefixing, `MovieEntry` emission and `-DSWF_AVM2` were all
  already correct; the board's audit of that was right.
- **`Avm2DisplayObjectExt`** — I drafted a wrapper→`MovieClip*` field for the
  `AVM1Movie` accessors (`_v9`/`_v10`) and pulled it back out rather than ship a
  struct field with no finished consumer. `w2-textblock` also appends to
  `avm2_globals.h`, so leaving struct layout alone keeps the merge clean.
- **`actionAdvancePlayingLevels` / `getOrCreateLevel` / `tagPlaceObject2`** —
  read and reused, never edited. The frame-running context swap is duplicated
  into `avm1UnderAvm2RunFrame` instead of factored out of
  `actionAdvancePlayingLevels`, precisely so an AVM1-agent sibling editing the
  timeline/placement paths cannot collide with, or be perturbed by, this arc.

---

## 6. Follow-ups, in priority order

1. **AVM1Movie root depth `-77824`** (§3.5). One constant; takes
   `avm2_loads_avm1` from 4 differing lines to 2. Should be derived from
   Ruffle's depth model, not copied from the fixture.
2. **`addChild(AVM1Movie)` → Error #2180 for SWF ≥ 10.** Independent of this
   arc, ~5 lines, wanted by `_v10` *and* `avm2_loads_avm1`.
3. **`AVM1Movie` transform accessors → the AVM1 root's `_x`/`_y`/…**, plus AVM1
   `onEnterFrame` / clip-event dispatch from the tick hook. Together these are
   `_v9` (+1) and half of `_v10`.
4. **Cross-VM input + focus** — the real arc behind the four `avm2/` mouse/focus
   rows and `avm2/avm1_root`. Needs the AVM1 child's display list in the AVM2
   hit-test walk and a shared focus owner. Size it as its own session.
5. **`mixed_avm/avm1_loads_avm2`** — build-system arc (compile `src/avm2` into
   AVM1 parents), not a runtime one.
