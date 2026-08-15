# wave1-avm1-child — the AVM1-child-under-AVM2 remainder (session 16, wave 1)

**Agent:** `w1-avm1-child` (wave-1, read-only diagnosis).
**Baseline:** HEAD `cd04f80b9`; grading run `31748059158` at `3db858cbc`
(graphics / full / images=true).
**Probe worktree (scratch, detached, NOT for merging as-is):**
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/b9a79013-0abe-4a85-a932-4fb7420dc877/scratchpad/wt-avm1child`
**Probe patch (86 lines, measured, three legs):**
`SWFRecompDocs/plans/session16-fanout-reports/wave1-avm1-child-probe.patch`
(no new files; touches `SWFModernRuntime/src/actionmodern/action.c` and
`SWFModernRuntime/src/avm2/avm2_display.c` only).

---

## 1. Verdict table

| # | mechanism | tests it owns | flips | verdict | owner files | size |
|---|---|---|---|---|---|---|
| **A** | **Loader-inserted AVM1 root depth = `-0xF000` internal / `-77824` as AVM1 sees it** | `mixed_avm/avm2_loads_avm1` (2 of its 5 lines) | 0 alone, **part of a +1** | **GO — measured** | `action.c::actionBootAvm1ChildUnderAvm2` | **1 line** |
| **B** | **`addChild(AVM1Movie)` → ArgumentError #2180 when the ROOT swf version > 9** | `avm2_loads_avm1` (2 lines), `avm2_loads_avm1_v10` (2 lines) | 0 alone, **part of a +1** | **GO — measured** | `avm2_display.c::validate_add` | **~12 lines** |
| **C** | **AVM1 mouse-broadcast bridge** (stage mouse → AVM1 `Mouse`/`mc.onMouseX` dispatchers) | `avm2_loads_avm1` (last line) | **+1 with A+B** (`avm2_loads_avm1` **PASSES**, measured) | **GO — measured** | `avm2_display.c::input_deliver` + new `action.c` fn | **~73 lines** |
| **D** | **cross-VM LocalConnection (AVM2 `send` → AVM1 `connect` listener)** | `avm2_loads_avm1_v9`, `avm2_loads_avm1_v10` — the *only* line left on each after A+B | **+2** | **GO — high confidence, not built** | `avm2_net.c` LC registry (`lc_send`/`lc_tick`, :1428-1830) + `action.c` LC (:2773-3160) + `actionTickAvm1ChildrenUnderAvm2` | ~120-200 lines |
| **E** | **cross-VM hit test + AVM1 timers under AVM2** | `avm2/mouse_pick_avm1_root` (1 line), `avm2/mouse_pick_loader_avm1` (37) | 0 in one session | **NO-GO** | `avm2_display.c` pick walk, `action.c` hit test, tick hook | session-sized |
| **F** | **cross-VM focus / Tab traversal / `Selection` broadcast** | `avm2/selection_onsetfocus_mixed_avm` (5), `avm2/focus_events_mixed_avm_edittext` (48), part of `mouse_pick_loader_avm1` | 0 in one session | **NO-GO** | `avm2_display.c` focus (`update_focus_on_press`, `g_stage_focus`, tab order) + `action.c` Selection | session-sized |
| **G** | `mixed_avm/avm1_loads_avm2` (reverse direction) | 1 test | 0 | **NO-GO — build-system arc** | `ruffle-tests/verify_output.py:2332-2340` | build arc |
| **H** | `avm2/avm1_root` | 1 test | 0 (ceiling is `ruffle_matched`, not pass) | **NO-GO + RUFFLE_VS_FLASH candidate** | — | — |
| — | **REFUTED members** | `avm2/loader_try_click_root`, `import_assets/avm1_imports_avm1`, `from_shumway/avm1movie` | — | not in this cluster (§5) | — | — |

**Recommended wave-2 slots (two, independent):**

1. **`w2-avm1-child-depth-2180-mouse`** — legs A+B+C, **86 lines, already
   written and measured, +1 flip (`mixed_avm/avm2_loads_avm1` → PASS),
   zero regressions on 5 canaries.** The patch in this directory is
   apply-ready modulo dropping the two `WAVE-1 PROBE` comment markers.
2. **`w2-avm1-child-localconnection`** — leg D, **+2 flips**
   (`avm2_loads_avm1_v9`, `avm2_loads_avm1_v10`). Touches `avm2_net.c` and a
   different region of `action.c` (the AVM1 LC block at :2773) than slot 1
   (the `#ifdef SWF_AVM2` child block at :23800-24140), so the two can run
   concurrently in separate worktrees.

Together: **+3 trace**, i.e. the entire `mixed_avm` AVM2→AVM1 family goes green
(`avm2_loads_avm1`, `_v9`, `_v10`, on top of s15's `_doabc`,
`_loads_avm2_doabc`, `_loads_into_root`). After that the *only* mixed_avm row
left is `avm1_loads_avm2`, which is a harness/build arc.

---

## 2. The cluster, enumerated at HEAD

Method: parsed every `.swf` in the corpus (header + `FileAttributes` AS3 flag +
DoABC/DoAction tag presence) and kept every test directory holding BOTH an AVM1
and an AVM2 movie. 14 such directories exist; cross-referenced with
`results_graphics.json` for status.

| test | status @ HEAD | differing lines | mechanism (this report) |
|---|---|---|---|
| `mixed_avm/avm2_loads_avm1` | output_mismatch | 5 | **A (2) + B (2) + C (1)** → PASS, measured |
| `mixed_avm/avm2_loads_avm1_v9` | output_mismatch | 1 | **D** |
| `mixed_avm/avm2_loads_avm1_v10` | output_mismatch | 3 | **B (2) + D (1)** |
| `mixed_avm/avm2_loads_avm1_doabc` | pass | — | s15 |
| `mixed_avm/avm2_loads_avm1_loads_avm2_doabc` | pass | — | s15 |
| `mixed_avm/avm2_loads_avm1_loads_into_root` | pass | — | s15 |
| `mixed_avm/avm1_loads_avm2` | output_mismatch | 4 | **G** (harness) |
| `mixed_avm/avm1_loads_avm2_doaction` | pass | — | — |
| `avm2/avm1movie_addcallback_call` | pass | — | — |
| `avm2/avm1_root` | output_mismatch | 46 | **H** |
| `avm2/mouse_pick_avm1_root` | output_mismatch | 1 | **E** |
| `avm2/mouse_pick_loader_avm1` | output_mismatch | 37 | **E + F** |
| `avm2/focus_events_mixed_avm_edittext` | output_mismatch | 48 | **F** |
| `avm2/selection_onsetfocus_mixed_avm` | output_mismatch | 5 | **F** |
| `from_shumway/avm1movie` | ruffle_matched | 12 ⊆ 12 | already effective; **regression canary** |

The s15 board's 14-row list contained two rows that are **not** dual-VM at all
(`avm2/loader_try_click_root`, `import_assets/avm1_imports_avm1`) and omitted
`from_shumway/avm1movie` and `avm2/avm1movie_addcallback_call`. Corrected list
above.

---

## 3. Leg-by-leg evidence

### A. The depth constant, derived (not fitted)

Ruffle, `core/src/loader.rs`:

```rust
const LOADER_INSERTED_AVM1_DEPTH: i32 = -0xF000;          // :61  (= -61440)
...
if matches!(vm_data, MovieLoaderVMData::Avm2 { .. }) && !movie.is_action_script_3() {
    mc.post_instantiation(uc, None, Instantiator::Movie, false);
    mc.set_depth(LOADER_INSERTED_AVM1_DEPTH);              // :1781
    mc.set_avm1movie(uc);
}
```

and `core/src/avm1/globals.rs:864` `pub const AVM_DEPTH_BIAS: i32 = 16384;`
with `:880` `let depth = display_object.depth().wrapping_sub(AVM_DEPTH_BIAS);`
for `getDepth`. So the AVM1-visible depth is
`-0xF000 - 16384 = -61440 - 16384 = **-77824**`. Our `MovieClip::depth` already
stores the *AVM1-biased* value (`getOrCreateLevel` writes `level_num - 16384`,
matching Ruffle's `activation.rs:2880 level.set_depth(level_id)` + the same
bias), so the fix is a single assignment of `-0xF000 - 16384` in
`actionBootAvm1ChildUnderAvm2`, immediately after `getOrCreateLevel`.

**Independent corroboration that this is the right constant:** the
`avm2/avm1_root` fixture ships Ruffle's own output as `output.ruffle.txt`, and
Ruffle names the loaded AVM1 root **`_level-61440`** there — i.e. Ruffle prints
`_level{internal_depth}` and the internal depth really is `-0xF000`. Two
independent Ruffle artefacts (one source constant, one recorded trace) agree.

Measured: `avm2_loads_avm1` lines 5 and 7 flip from `-16383` to `-77824`.
`getOrCreateLevel`'s level bookkeeping is by `g_levels[]` pointer identity, not
by depth, so nothing else keys off the value (canaries confirm).

### B. #2180 on `addChild(AVM1Movie)`

Ruffle `core/src/avm2/globals/flash/display/display_object_container.rs:42`,
inside `validate_add_operation`, *after* the `#3783` Stage check and *before*
`#2024`:

```rust
if !proposed_child.movie().is_action_script_3() && activation.context.root_swf.version() > 9 {
    return Err(make_error_2180(activation));
}
```

Two details the fixtures pin and that a naive implementation gets wrong:

* the version tested is the **root** SWF's, not the child's. `avm2_loads_avm1`
  (root v17) and `_v10` (root v10) throw; `_v9` (root v9) does **not** — and
  `_v9`'s expected output really does contain
  `Second child of main MC after adding: [object AVM1Movie]` /
  `Num children of main MC after adding: 2`. Use `avm2_generated_swf_version`.
* the only AVM2-visible AVM1 DisplayObject in our model is the `AVM1Movie`
  wrapper, so `class_is_a(child->cls, g_avm1movie_class)` is the faithful
  translation of `!movie().is_action_script_3()`.

Measured: `avm2_loads_avm1` 12/13 (`2180` / `ArgumentError`) appear;
`avm2_loads_avm1_v10` goes **3 differing lines → 1**.

### C. The mouse bridge is a BROADCAST, not a hit test

`avm2_loads_avm1`'s last line is `onmousedown at 10, 10!`. Its `avm1.swf`
string pool is `[..., 'onMouseDown', 'onmousedown at ', '_xmouse', '_ymouse',
...]` — this is `mc.onMouseDown`, which in AVM1 fires **regardless of mouse
position** (our own comment at `action.c:73385` says exactly that). So no
cross-VM hit testing is needed for this line: it needs the AVM2 input pump to
(i) write `app_context->mouse.stage_x/y` (which is what `mc_get_local_mouse`
reads for `_xmouse`) and (ii) call the existing AVM1 dispatchers
(`actionDispatchMouse{Down,Up,Move}` + `actionDispatchMC*`) inside the AVM1
version/globals/context swap.

Seam: `avm2_display.c::input_deliver` (:12926) — three call sites, one per
`IN_MOUSE_{MOVE,DOWN,UP}`, each gated on `g_avm1_child_levels != 0` so a
pure-AVM2 movie pays one integer compare.

Measured: **`mixed_avm/avm2_loads_avm1` → PASS** with A+B+C.

### D. `_v9`/`_v10`'s last line is LocalConnection, NOT `AVM1Movie.x`

**This refutes the s15 report's §3.2 diagnosis.** s15 priced the
`(inner swf) x set, new value: 99` line as "`AVM1Movie` transform accessors →
the AVM1 root's `_x` plus an AVM1 enterFrame/clip-event notification". The
fixtures say otherwise. String pools:

* `avm2_loads_avm1_v9/avm1.swf`: `['connection', 'LocalConnection',
  'mixed_avm_v9-connection', 'connect', 'setX', '(inner swf) x set, new value: ']`
* `avm2_loads_avm1_v9/test.swf`: `[..., 'LocalConnection', 'send',
  'mixed_avm_v9-connection', 'onXSet', 'status', 'statusEventListener', ...]`

The AVM2 parent sets `content.x = 99` (that line, `Content X after setting x: 99`,
**already passes**) and then *tells* the AVM1 child over a LocalConnection
channel; the AVM1 child's `setX` method is what traces. No transform
propagation and no AVM1 event dispatch is involved.

Our runtime says so itself, at `avm2_net.c:1453`:

> *"Not modelled: the AVM1 half of the registry. Our AVM1 LocalConnection
> (action.c) keeps its own channel map, so an AVM1<->AVM2 send finds no
> listener."*

Why it is tractable: **both halves already use AMF0 on the wire** (`avm2_amf.c`
`wire_mode = 1`; `action.c:2792` "LocalConnection is a WIRE channel: each
argument is serialized to AMF0 at send() time"), and the two channel-key
builders are structurally identical — `lc_connect_key`/`lc_send_key`
(`avm2_net.c:1522-1543`) and `lc_build_key` (`action.c:2812-2846`) both emit
`superdomain:name` lowercased, with a bare `_name` passed through. For
`mixed_avm_v9-connection` both produce `localhost:mixed_avm_v9-connection`.
So the bridge is: on an AVM2 `send` with no AVM2 listener, consult the AVM1
channel map and hand the already-serialised AMF0 argument buffers to the AVM1
queue (and symmetrically for the reverse). One extra piece:
`actionTickAvm1ChildrenUnderAvm2` currently drains direct loads, level advances
and unloads but **not** `processLocalConnectionMessages` — that has to be added.

Priced **+2** (`_v9`, `_v10`), GO, ~120-200 lines. Not built in wave 1.

---

## 4. The NO-GO clusters, with completion mechanisms

### E. Cross-VM hit test — and a second, unreported blocker

`avm2/mouse_pick_avm1_root` is a 1-line diff and looks tempting. It is not.
Its `avm1.as` is:

```actionscript
var clip = this.createEmptyMovieClip("clip", 1);
var mcl = new MovieClipLoader();
var interval = setInterval(checkLoadComplete, 4);
mcl.loadClip("avm1_child.swf", clip);
```

`clip.onRelease` is only assigned from inside the `setInterval` callback — and
`actionTickAvm1ChildrenUnderAvm2` deliberately excludes AVM1 timers
(`action.c:24067`: *"Timers deliberately stay out … processTimers wants a frame
budget this loop has no honest value for"*). So this row needs **AVM1
`setInterval` under AVM2** *and* **cross-VM hit testing** *and* the rule that a
click landing on AVM1 content does **not** produce an AVM2 `click` on the Stage
(expected line 1 is `avm1 child clicked` with no accompanying
`Clicked on: [object Stage]`). Verified inert: with the wave-1 probe applied the
row is byte-identical to baseline.

`avm2/mouse_pick_loader_avm1` additionally wants hit attribution to bubble to
the **Loader** (`Clicked on: [object Loader] (instance2)`) and
`mouseChildren`/`mouseEnabled` on an AVM2 `Sprite` to re-target hits that land
inside the AVM1 subtree. That is the AVM2 pick walk descending into an AVM1
display list.

**Completion mechanism:** an AVM1 child's display list must be reachable from
the AVM2 pick walk (`avm2_display.c` `update_mouse_state` / hover resolution)
with a single "this subtree is AVM1, attribute the hit to the AVM1Movie's
Loader" rule, plus AVM1 timers in the tick hook. Size it as its own session.

### F. Cross-VM focus

`avm2/selection_onsetfocus_mixed_avm` produces **zero** lines for us today, and
**all five** of its expected lines originate in the AVM1 child
(`Selection.addListener(this)` + a `txt` TextField). Three of them are
`null null` — i.e. Flash broadcasts AVM1 `Selection.onSetFocus` on **every**
focus change, passing `null` when the object involved is AVM2 — and the last
two require the AVM1 child's TextField to be in the **Tab traversal order** of
the AVM2 focus manager. `focus_events_mixed_avm_edittext` (48 lines) is the
same three requirements at full interleave, with AVM1 `onSetFocus`/`onKillFocus`
per-field callbacks ordered against AVM2 `focusIn`/`focusOut`.

**Completion mechanism:** (i) AVM2 focus changes broadcast into AVM1's
`Selection` listener list with null-for-AVM2 arguments; (ii) AVM1 child
interactive objects registered in the AVM2 tab-order walk; (iii) AVM1
`onSetFocus`/`onKillFocus` dispatch on the AVM1 side. All three are needed for
even the 5-line row, so there is no cheap slice. Own session.

### G. `mixed_avm/avm1_loads_avm2` — unchanged from s15

`verify_output.py:2339` still gates the AVM2 child's table linkage on `is_avm2`
(the *parent's* VM), with the comment naming this exact test. An AVM1 parent
never compiles `src/avm2`, so linking an AVM2 child's tables into it is an
undefined-symbol wall. Build-system arc, not a runtime one. **NO-GO stands.**

### H. `avm2/avm1_root` — ceiling is `ruffle_matched`, and it is a
RUFFLE_VS_FLASH row

`test.toml` has `known_failure = true`, and the directory ships Ruffle's own
trace as `output.ruffle.txt`. Diffing the two fixtures shows Ruffle is wrong on
~30 of the 58 lines, in a *specific* way: Ruffle calls the loaded AVM1 root
**`_level-61440`** and gives it a `_level-61440/…` target path, where Flash
calls it **`_root`** with an empty target (`child_via_mcl._target:
/child_via_mcl`) and reports `_level-61440: undefined`. Ruffle also can't see
`_level0.as3Loader` at all (`undefined` for nine consecutive lines) where Flash
resolves AVM1 target paths *through* AVM2 containers
(`_level0.as3Loader.defined_avm1_name._x: 10`).

Consequences for the board:
* The best score this row can reach is `ruffle_matched`, never `pass` — and
  `ruffle_matched` requires our differing-line set to be a **subset** of
  Ruffle's, which is a strange target to optimise for.
* Our current `_level1` naming matches **neither** oracle. Adopting Ruffle's
  `_level{internal_depth}` naming would move us toward `ruffle_matched` but
  **away** from Flash, and would be a `_level-61440` regression risk for
  `avm2_loads_avm1`'s `_root == _level0: false` line.
* Recommendation: **add an entry to
  `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`**
  documenting the `_level-61440` vs `_root` divergence and that we deliberately
  follow neither name today, and leave the row alone.

---

## 5. Refutations (rows the s15 board mis-assigned)

1. **`avm2/loader_try_click_root` is not a dual-VM test.** Both `test.swf`
   (v15) and `loadable.swf` (v43) have the `FileAttributes` AS3 bit set and
   carry DoABC. It is AVM2-loads-AVM2. Its 26-line diff belongs to the AVM2
   click/hit-test arc and cannot be moved by anything in this cluster. Drop it
   from the cluster.
2. **`import_assets/avm1_imports_avm1` is not dual-VM** (confirmed again: no
   `RecompiledABC/`). *New*, and cheap: its whole diff is **one spurious
   leading line**, `Hello from right_eye.swf` — the *imported* SWF's own
   DoAction executes, which Flash does not do for `ImportAssets`. Every other
   line matches. That is a 1-line-diff, single-mechanism row for the
   `actionImportAssets` owner; hand it to a trace-smalls slot, not here.
3. **`from_shumway/avm1movie` is already effective** (`ruffle_matched`,
   12 diffs ⊆ Ruffle's 12) and is therefore a **regression risk**, not a gain
   (per the `ruffle-matched-hides-regression` rule). It must be a canary for
   any patch in this arc — it was for mine, and it held.
4. **s15's `_v9`/`_v10` mechanism claim is wrong** (see §3D): the line is
   cross-VM LocalConnection, not `AVM1Movie` transform propagation. The
   `Avm2DisplayObjectExt` wrapper→`MovieClip*` field s15 drafted and pulled
   back out should **not** be resurrected for these rows.
5. **The s15 follow-up "the depth change is not enough to flip the row on its
   own" is correct but understated the package.** Depth alone flips 2 lines;
   depth + #2180 + a 30-line mouse broadcast flips the whole test. The three
   legs are 86 lines together and were built and measured in wave 1.

---

## 6. Measured ledger (probe worktree, `--mode=graphics`, sequential)

| test | HEAD | + A | + A,B | + A,B,C |
|---|---|---|---|---|
| `mixed_avm/avm2_loads_avm1` | 5 lines differ | 3 | 1 | **PASS** |
| `mixed_avm/avm2_loads_avm1_v10` | 3 | — | **1** | 1 |
| `mixed_avm/avm2_loads_avm1_v9` | 1 | — | 1 | 1 |
| `mixed_avm/avm2_loads_avm1_doabc` | pass | — | pass | **pass** |
| `avm2/avm1movie_addcallback_call` | pass | — | pass | **pass** |
| `from_shumway/avm1movie` | ruffle_matched | — | ruffle_matched | **ruffle_matched** |
| `avm2/mouse_pick_avm1_root` | 1 | — | — | **1 (unchanged)** |
| `avm2/selection_onsetfocus_mixed_avm` | 5 | — | — | **5 (unchanged)** |

Zero regressions. Note that legs A and B produce **no test flip on their own** —
they are only worth landing as part of the A+B+C package (or with D, which
finishes `_v10`).

**Blast radius:** leg A is inside the existing `#ifdef SWF_AVM2` child block, so
AVM1-only builds never see it. Leg B is a class check that can only fire when a
`AVM1Movie` instance exists, and `avm1movie_mint` is only reachable from
`loader_deliver`'s AVM1 arm. Leg C is gated on `g_avm1_child_levels != 0` — one
integer compare per mouse event for pure-AVM2 content, and the file is not
compiled at all for AVM1 tests. **Canary blind spot:** none of this is exercised
by the render canary (no pixel effect); the covering graded tests are the six
`mixed_avm/avm2_loads_avm1*` rows plus the two canaries above.

---

## 7. Handover notes for wave 2

* The probe patch is at
  `SWFRecompDocs/plans/session16-fanout-reports/wave1-avm1-child-probe.patch`
  and applies cleanly to `cd04f80b9`. It creates **no new files**. Before
  landing, strip the two `WAVE-1 PROBE` comment markers and give
  `actionMouseAvm1ChildrenUnderAvm2` a real doc comment (the version/globals/
  movie-id swap it performs is the same one `avm1UnderAvm2RunFrame` uses and
  should say so).
* The mouse bridge currently swaps to `g_avm1u2[0]`'s version/globals for the
  whole dispatch. With one AVM1 child (every test in the corpus) that is exact;
  with several it should swap per child. Worth a comment, or a per-child loop,
  before merge.
* Leg C's `ms->clicked` / `ms->released` / `ms->moved` writes mirror
  `input_events.c`; nothing in an AVM2 build reads them today, but leaving them
  keeps the AVM1 state machine self-consistent if `dispatch_clip_event_*` is
  ever added to the bridge.
* Slot-2 (LocalConnection) must add `processLocalConnectionMessages` to
  `actionTickAvm1ChildrenUnderAvm2`; that function is in slot-1's territory, so
  sequence the two or have slot 2 rebase.
