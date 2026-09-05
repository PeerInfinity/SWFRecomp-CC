# w1-trace-avm1 — wave-1 diagnosis (AVM1 trace: avm1, from_gnash, from_shumway/avm1, mixed_avm)

Session 18, HEAD `8f68a5fea`. Read-only; no source edits, no commits.
All local runs: no-graphics unless marked, `SWFRECOMP_COMPILE_TIMEOUT=2400`, `--diff --verbose`,
never more than 2 concurrent single-test jobs. Logs: `<scratch>/w1-trace-avm1/{hitarea_avm1,gnash1,kf1,gfx1,shum,gfi}.log`.

---

## 0. Verdict table (lead with this)

| # | Lead | Verdict | Priced flips | Cost |
|---|---|---|---|---|
| **G1** | **swf.c pre-advance orphaned action-queue drain** | **GO** | **+1 graphics-effective** — `from_gnash/misc-swfc.all/gotoFrameFromInterval2` `output_mismatch → ruffle_matched`; **closes the corpus's ONE graphics/no-graphics parity gap** | ~5 lines, one file (`SWFModernRuntime/src/libswf/swf.c`) |
| **G2** | **`from_gnash/actionscript.all/Function-v6/-v7/-v8`** | **GO (medium)** | **+3** (one identical 8-line diff set on all three) | 3 sub-mechanisms in `action.c`; all 8 lines required for any flip |
| **H1** | **AVM1 `MovieClip.hitArea` (new upstream family)** | **HOLD — slice it** | **+2 realistic** (`from_shumway/avm1/hitarea`, `avm1/hitarea_remove_sibling`); +1 more (`hitarea_lazy_getter`) behind a second mechanism | new pick-time property resolve; `hitarea_sweep` / `hitarea_remove_owner_drag` are a separate arc |
| N1 | `mixed_avm/avm1_loads_avm2` | **NO-GO** | 0 | harness/build blocker, re-verified at HEAD |
| N2 | `action_order/PlaceAndRemove` | **NO-GO** | 0 | s17 diagnosis re-verified byte-identical |
| N3 | `action_order/action_execution_order_test11` | **NO-GO** | 0 | s17 diagnosis re-verified byte-identical |
| N4 | `array-v6/-v7/-v8`, `MovieClip-v6/-v7/-v8` | **NO-GO** | 0 | 21–67 missing lines each, multi-phase `incomplete/` plans, `ruffle_matched` unreachable |
| N5 | `misc-swfc.all/movieclip_destruction_test3/4` | **NO-GO** | 0 | blocked on `SPRITE_REWIND_IDENTITY`; 13 / 32 missing lines |
| N6 | `avm1/globals_monkeypatch` | **NO-GO (arc, not slice)** | 0 | 62 missing lines, one deep mechanism |
| **R1** | `misc-ming.all/GradientFillTest` | **NO-GO + PLAN REFUTED** | 0 | the plan's "off-by-low-bit / gamma" root cause is **wrong for the current residual** |

**Drift found (§7):** 8 local-only stale test dirs, 32 stale `output.ruffle.txt` oracles (one of them a live
mis-grading trap), and one on-disk-but-ungraded test that **genuinely hangs**.

---

## 1. G1 — the ONE mode-parity gap, fully explained — **GO**

### Reproduced

| mode | verdict | actual |
|---|---|---|
| no-graphics | `RUFFLE_MATCHED` | 23 lines, byte-identical to `output.ruffle.txt` |
| **graphics** (`--mode=graphics`, local Dawn) | `output_mismatch`, 2/23 | **24 lines** |

Our graphics output is Ruffle's 23 lines with **one extra root frame executed**:

```
  19  Entering unreachable frame 7 !                      [gotoFrameFromInterval2.sc:81]   <- ours only
  20  FAILED: _root._currentframe: expected: "6" , obtained: "7"                            <- ours (Ruffle+Flash: PASSED == 6)
  22  #passed: 0   (Ruffle 1, Flash 2)
  23  #failed: 2   (Ruffle 1, Flash 0)
```

Everything before line 19 is identical to Ruffle's oracle in both modes. So the whole 21-line "gap"
in the inventory is **one surplus natural frame advance**, nothing else.

### Mechanism — named by the code itself

`SWFModernRuntime/src/libswf/swf_core.c:1533-1548`, immediately before its natural-advance block:

```c
// A goto issued from a timer/event callback (setInterval, etc.) queues the
// target frame's DoAction via ng_executeGotoCatchUp's drain-suppressed
// funcs[target] call. ... A gotoAndPlay's is_playing=1 then survives into the
// natural advance below before the target frame's own stop() runs,
// over-advancing one frame. ... Key test: from_gnash/misc-swfc.all/gotoFrameFromInterval2.
{
    extern size_t actionActionQueuePending(void);
    if (actionActionQueuePending() > 0)
        actionDrainAllInPriorityOrder(app_context);
}
```

`swf.c` (the graphics / `OFFSCREEN_RENDER` frame loop) **has no such drain**:

```
$ grep -n "actionActionQueuePending\|actionDrainAllInPriorityOrder" swf.c swf_core.c
swf.c:928:      // ...actionDrainAllInPriorityOrder at the top of root frame_funcs[...]   (comment only)
swf_core.c:1545: extern size_t actionActionQueuePending(void);
swf_core.c:1546: if (actionActionQueuePending() > 0)
swf_core.c:1547:     actionDrainAllInPriorityOrder(app_context);
```

`swf.c`'s `processTimers` runs at ~:1390-1394 and its advance block at :1445-1478; the orphaned
`SCRIPT` entry the timer-callback goto leaves behind is therefore never drained before `is_playing`
is consulted at :1477 (`else if (is_playing) next_frame += 1;`).

### Patch scope

Port `swf_core.c:1544-1548` verbatim into `swf.c` between the timer/MCL drains (~:1396-1408) and the
`if (manual_next_frame)` block at :1409. ~5 lines + comment, one file, no recompiler change, no
`Recompiled*` invalidation.

### Risk and canaries (wave-2 must run these)

Draining the action queue one step earlier in the **graphics** loop touches every graphics-mode
timeline test. Required before delivery: `--mode=graphics` on `misc-swfc.all/gotoFrameFromInterval2`
(target), `misc-swfc.all/gotoFrameLabelAsFunction` + `action_execution_order_test12` (adjacent
swfc timing), `avm1/default_names` and `from_shumway/avm1/text-bind` (the two tests the surrounding
`swf.c` comments name), plus a `--tests-dir=ruffle-tests/tests/swfs/regression` pass. This is a
graphics-mode CI dispatch, not a no-graphics one.

### Honest pricing caveat

`gotoFrameFromInterval2` is `known_failure = true` with an `output.ruffle.txt`, so the reachable
target is `ruffle_matched`, not `pass` — Flash's 23-line `output.txt` also wants the `asOrder`
assertion to PASS, which neither Ruffle nor we do. **+1 effective, not +1 pass.** Its value is
mostly that it retires a standing parity caveat in `CLAUDE.md` / MEMORY (`from_gnash/misc-swfc.all/gotoFrameFromInterval2`
is *the* named exception to graphics/no-graphics parity).

---

## 2. G2 — `Function-v6 / -v7 / -v8` — **GO (medium)**

### The brief asked "8 lines each — same 8?" — **YES, confirmed identical**

All three tests produce byte-identical diff shapes at HEAD (263/271, 264/272, 264/272). Three real
sub-mechanisms plus two derived summary lines:

| # | line(s) | expected (Flash) | ours | mechanism |
|---|---|---|---|---|
| **F1** | 122–124 (v6) / 123–125 (v7,v8) | `expected: 5 obtained: 0`, then two `obtained: ` / `obtained: undefined` | `obtained: 2`, then `obtained: callee`, `obtained: caller` | the `arguments` object must have **zero enumerable properties**; we expose `callee` and `caller` to `for-in`. Fix = `DontEnum` on those two. |
| **F2** | 256–257 / 257–258 | `PASSED: uf.p === "hi"`, `PASSED: uf.__proto__ === _global.Function.prototype` | both `FAILED` | a user-defined function's `__proto__` must be `_global.Function.prototype` and inherit from it. (`uf.prototype.constructor === uf` at :1092 and `f instanceOf _global.Function` at :1080 already PASS, so only the `__proto__` link is missing.) |
| **F3** | 81 / 82 | `PASSED: stringInstance.__proto__ != undefined` | `FAILED` | **riskiest**: Ruffle fails this line too. Note line 83 `stringInstance.__proto__ == String.prototype` already PASSES for us, so the two lines are internally inconsistent in our implementation and F3 needs a real read of the `__proto__` accessor on a String instance, not a guess. |
| — | 269–270 / 270–271 | `#passed: 256/257`, `#failed: 7` | `253/254`, `10` | derived Dejagnu totals, follow automatically |

**All 8 must land for any flip** (a `-vN` gnash test scores only on exact parity). Payoff **+3**.

### `ruffle_matched` is unreachable here — and my own first check of that was wrong

Correction worth recording: I initially concluded "no `output.ruffle.txt` ⇒ no `ruffle_matched`".
That is **false** for `from_gnash/actionscript.all` — those tests carry per-FP-version sidecars
(`output.fp13-18.ruffle.txt`, `output.fp24.ruffle.txt`, `output.fp9-14.ruffle.txt`), and
`verify_output.py:4452-4457` derives the ruffle oracle name from the resolved expected name.

The correct reason `ruffle_matched` is unreachable is the **diff-set shape**: Ruffle is 28–31 lines
off Flash on `Function-v*` (ours: 8), and Ruffle's diff indices (75, 76, 81, 122–126, 188–193, …)
are **not a superset** of ours — we already get 75/76 and 188–193 right. Drifting to `ruffle_matched`
would be a regression under the standing `ruffle-matched-trap` rule. Flash parity is the only target.

---

## 3. H1 — AVM1 `MovieClip.hitArea` — **HOLD, sliceable**

### Root cause (single, proven)

`grep -rn "hitArea\|hit_area" SWFModernRuntime/src SWFRecomp/src` finds **exactly one** hit:
`avm2_globals.c:3879` (AVM2 `Sprite.hitArea`). **AVM1 `MovieClip.hitArea` is not implemented at all** —
the property is stored as an ordinary dynamic prop and never read during picking.

Every one of the five rows is that one fact:

| test | exp/match | our output says |
|---|---|---|
| `avm1/hitarea_sweep` | 33/1 | `chain via own`, `textfield via own`, `mask via own`, `throw via own`, `delete via own`, `overwrite via own`, `xfown at old` — literally "the owner's own shape picked" on every probe; the hit-area-only zones (`invisible`, `zero scale`, `tfmask`) emit nothing |
| `avm1/hitarea_lazy_getter` | 6/0 | `readback: _level0.decoy` (no `setter consumed …`), then `rollover own` |
| `avm1/hitarea_remove_owner_drag` | 10/3 | `rollover Z` before `rollover Rm`; `removing owner` and `dt: /btnZ` never emitted |
| `avm1/hitarea_remove_sibling` | 4/3 | `ready / rollover Y / armed / rollover Y` — expected 4th line is `removing sibling` |
| `from_shumway/avm1/hitarea` | 4/2 | `undefined / _level0.hit / 1` — the `rollover` line is missing |

### Ruffle's semantics (authority: `~/CC/ruffle` `03fc070fa`, 66 lines in `movie_clip.rs` + 16 in `player.rs`)

- `hitArea` is resolved by an **ordinary AVM1 property get** (prototype chain + user getters) on
  **every button-mode pick**, before any bounds check.
- Resolved value must be a display object; anything else ⇒ the owner's own shape picks. A throwing
  getter ⇒ same.
- An **invisible hit area still hits**; an **invisible owner's** does not. `SKIP_MASK` but **not**
  `SKIP_INVISIBLE` for the hit area.
- `_droptarget` / context-menu picks (`require_button_mode == false`) **resolve the property but
  ignore its value**.
- Mid-pick removal takes effect on the **next** pick for the owner (`dt: /btnRm` still reports the
  removed clip), but a **sibling** removed mid-pick is excluded for the rest of that pick.
- `Player::update_drag` needs a re-entrancy guard (a getter can call `stopDrag()`).

### Where it goes in our tree

Our AVM1 picking is **AABB-based, not shape-based**, and it funnels through
`mc_get_pixel_aabb_ng` (`SWFModernRuntime/src/actionmodern/action.c:74126`), whose consumers are:
`actionMCMouseInsidePick` (:74566), `actionDispatchMCMouseMove` (:74592, the rollover loop),
`mc_has_button_mode_ancestor_with_mouse` (:74578), the button-state loops (:74466, :74493), the
click/focus walks (:75868, :75913, :75968), the AVM1-child pick (:24917-24947), and `tag.c:4402/4424`.
`_droptarget` is separate: `ng_compute_droptarget` (`tag.c:8016`), refreshed by
`actionRefreshDropTargetIfDragged` (`action.c:35191`).

A first slice is therefore: resolve `hitArea` for each button-mode clip and, when it yields a
MovieClip, use **that** clip's AABB in the button-mode pick path only.

### Two structural gaps the slice must also close (this is why it is HOLD, not GO)

1. **Pick order.** `actionDispatchMCMouseMove` iterates `child_mc_cache` **forward** (creation order)
   and fires a rollover on *every* clip whose AABB contains the mouse. Ruffle returns the single
   **topmost** hit, depth-descending. `hitarea_remove_sibling` depends on this: `btnX` (depth 2) must
   have its getter run **before** `btnY` (depth 1) is evaluated, so the removal lands first.
2. **Removed clips must be excluded** from the rest of the pick (Ruffle's new `if (self.avm1_removed()) return None;`).

### Second mechanism, needed only for `hitarea_lazy_getter`

`MovieClip.prototype.addProperty("hitArea", getter, setter)` does not dispatch from a MovieClip
receiver: the test's `btn.hitArea = decoy` produced no `setter consumed …` line and the readback
returned the stored value. The MC branch of `actionSetMember` **does** have an addProperty walk
(`action.c:52805-52870`) — but it starts at `mc->dynamic_props` and `break`s when `__proto__` is
absent, with **no fall-back to `MovieClip.prototype`**. The precedent that this is the missing arm is
`action.c:47341-47350` (`instanceof`), which has exactly that fall-back:
`// Fallback: if no dynamic_props __proto__, use MovieClip.prototype`. The GetMember twin is at
`action.c:46450`. *Unverified beyond this inference* — a wave-2 agent should confirm with a scratch
fixture before editing. `hitarea_lazy_getter` is the only test in the whole avm1 suite that calls
`MovieClip.prototype.addProperty`, so this arm is otherwise untested.

### Honest pricing

- **Slice 1 (+2):** `from_shumway/avm1/hitarea` (needs only "hit area covers the pointer ⇒ rollover")
  and `avm1/hitarea_remove_sibling` (needs slice 1 + depth-descending topmost pick + removed-clip
  exclusion).
- **+1 more** (`hitarea_lazy_getter`) if the prototype-accessor fall-back above lands with it.
- **NOT slice 1:** `hitarea_sweep` (33 lines: shape-level hit tests, MovieClip-vs-TextField mask
  semantics, transforms mutated inside the getter, two drags, a `stopDrag()` re-entrancy guard) and
  `hitarea_remove_owner_drag` (10 lines: `_droptarget` resolving-but-ignoring the property, plus
  removal-takes-effect-next-pick). Those two are a second slice at best, and our AABB picking model
  is the wrong substrate for the shape/mask half of `sweep`.

### Disposition trap to fix first

`ruffle-tests/tests/swfs/from_shumway/avm1/hitarea/output.ruffle.txt` is **stale**: upstream deleted
it in `03fc070fa` (and dropped `known_failure`, which our local `test.toml` already reflects). It
still contains Ruffle's pre-fix 3-line output — exactly the output a *partial* hitArea fix would
produce. Leaving it in place risks scoring a half-done fix as `ruffle_matched` on a test upstream now
expects to **pass**. Delete it locally before any wave-2 work on this family.

---

## 4. NO-GO rows (each with its completion mechanism)

### N1 `mixed_avm/avm1_loads_avm2` — harness/build blocker, re-verified

Local: 3/7, actual 3 lines. We emit the AVM1 parent's three lines and the loaded AVM2 child's script
never runs (`[object Stage]`, `[object LoaderInfo]`, `true`, `AVM2 load success!` all missing).

The brief asked for a from-scratch re-verify after the Multi-SWF arc. The blocker is **unchanged and
is not in the runtime** — `ruffle-tests/verify_output.py:2450-2462`:

```python
# Only when the PARENT is an AVM2 test. An AVM1 parent does not
# compile src/avm2 at all (is_avm2 gates the whole module tree),
# so linking an AVM2 child's tables into it is an undefined-symbol
# wall — that is `mixed_avm/avm1_loads_avm2`, and it belongs to the
# dual-VM arc, not here.
if is_avm2 and child_abc.exists():
```

The Multi-SWF arc (slices 1–11, 2026-09-03/04) moved char-id re-basing, asset tables, advance/loop
and render — none of which reaches this gate. **Completion mechanism:** compile the whole `src/avm2`
module tree into AVM1 parents and decide which VM owns `main` — a build-system arc (s15
`w2-avm1-child-report.md` §3.4 sizes it), not a runtime slice.

### N2 `action_order/PlaceAndRemove` — s17 re-verified byte-identical

96 expected / 15 matching / **45 actual** at HEAD — identical to the s17 and s15 transcripts. Both
defects still present: (a) `moo N` + `FAILED: This MovieClip should never be constructed` emitted for
every same-frame Place+Remove pair Flash suppresses, (b) only 15 of 96 cycles complete in 30 ticks.
No `output.txt` (only `output.fp9.txt` / `output.fp10.txt`), **no `*.ruffle.txt` sidecar of any kind**
(verified by directory listing), and `known_failure.panic` — so `ruffle_matched` is structurally
unavailable and only exact 96-line parity scores. Two mechanisms, 51-line deficit, zero partial
credit. **Completion mechanism:** the unified same-frame-pairing cancellation model in s17 §7 (per-entry
cancellation tracking, not a predicate flip — the 2026-05-08 predicate flip regressed
`reverse_execute_PlaceObject2_test2`).

### N3 `action_order/action_execution_order_test11` — s17 re-verified byte-identical

32/26 at HEAD. Same two-line 8/9 swap (`mc21 onLoad` vs `mc1 onEnterFrame`), same
`doActionOrder 0+2+1+3+4+5+`, same `asOrder`. Needs D1 **and** D2 (flat-global vs per-subtree LIFO
advance + per-clip EF/advance adjacency), one of which moves a recompiler-emitted call site and
invalidates the whole `Recompiled*` corpus.

**New observation not in the s17 report** — this test emits on stderr:

```
ERROR: heap_alloc() called before heap_init()
ERROR: Failed to allocate property name
```

A property-name allocation happens before the runtime heap is initialised. It does not change the
verdict (the trace diff is unchanged), but "heap used before init" is a real defect and is listed as
an unclaimed lead in §8.

### N4 `array-v6/-v7/-v8` and `MovieClip-v6/-v7/-v8`

Not run (deliberately: they are 644–1087-line, `num_frames = 30` fixtures and the pricing is decidable
without them). Missing lines at HEAD: array 21/50/50, MovieClip 35/35/67. Each family has a written
multi-phase `incomplete/` plan (`ARRAY_V6_V8_PLAN` — 5 phases, 2 completed, 3 pending;
`MOVIECLIP_VN_PLAN` — 17 phases). `ruffle_matched` is unreachable for the same diff-set-shape reason
as `Function-v*`, and by a wider margin:

| family | our missing lines | Ruffle-vs-Flash diff lines (per fp variant) |
|---|---|---|
| `array-v6/-v7/-v8` | 21 / 50 / 50 | 30–34 |
| `MovieClip-v6/-v7/-v8` | 35 / 35 / 67 | 60–84 |

Reaching `ruffle_matched` would mean *breaking* 25–50 lines we currently get right.
**Completion mechanism:** the remaining phases of the two written plans, as a dedicated arc.

### N5 `misc-swfc.all/movieclip_destruction_test3 / _test4`

test3: 18/5 (13 missing). test4: 40/8 (32 missing). Both diffs are **deferred-removal ordering**:
`nestedMovieClip removed at frame 10` and `actions here should not be executed` never appear,
`typeof(nestedMovieClip)` is `movieclip` where Flash says `undefined`, `_root.as_order` is `0+` vs
`0+1+2+`, and test4's brothers 1/3 survive their sibling's removal. `_investigation/CURRENT_STATUS.md`
routes both to `MOVIECLIP_DESTRUCTION_TEST3_PLAN` (3 phases: deferred `removeMovieClip`, depth bias
after removal, hard-reference clearance) and `MOVIECLIP_DESTRUCTION_TEST4_PLAN`, which is **blocked on
`blocked/SPRITE_REWIND_IDENTITY_PLAN.md`**. Ruffle is only 3–6 lines off Flash on both, so
`ruffle_matched` costs essentially the same 13/32 lines as `pass` — take `pass`.

### N6 `avm1/globals_monkeypatch` — an arc, not a slice

100 expected / 38 matching. One coherent mechanism, but a very wide one: **every engine-created
object must resolve its prototype through the current `_global.<Name>` at creation time**, not from a
cached builtin. Failing surfaces span object/array/function literals, `String.split()`,
`Array.slice()`, `ASnative(...)`, `attachMovie` (`clip.className: MovieClip` vs `MyMovieClip`, and the
same for nested clip / Button / TextField / Video), and the whole `flash.filters` set
(`current.filters[N].className: BevelFilter` vs `MyBevelFilter`) — plus the "weird prototypes" prologue
(`Object = 5`, `delete Object` ⇒ `{}: object without __proto__`).

`ruffle_matched` buys nothing: Ruffle differs from Flash on **7 lines only** (all `MyArray` vs
`Array`), so matching Ruffle costs 93 of the same lines a full pass costs. **Completion mechanism:**
a dedicated `_global`-indirection arc for engine-minted prototypes; not a wave-2 slice.

---

## 5. R1 — `GradientFillTest`: the plan's root cause is **REFUTED**

`incomplete/GRADIENTFILLTEST_PLAN.md` (2026-05-19) states the residual is *"consistent low-bit drift…
gamma-correction, sRGB-vs-linear, or stop-position interpolation precision"* with examples like
`8d→d0`, `b→d`, `7f→81`. **That description no longer matches the failure.** At HEAD (278 expected /
123 matching):

```
- 258  0xfa3a00,0xfa3a00,0xfa3a00,0xbbbb00,0xbbbb00,0xbbbb00,0x3afa00,0x3afa00,0x3afa00
+ 258  0xf20d00,0xf20d00,0xf20d00,0x7e8100,0x7e8100,0x7e8100,0xaf500,0xaf500,0xaf500
- 269  0xfa420b,0xfa420b,0xfa420b,0xdddd7f,0xdddd7f,0xdddd7f,0xf6fff4,0xf6fff4,0xf6fff4
+ 269  0xf20d00,0xf20d00,0xf20d00,0x7e8100,0x7e8100,0x7e8100,0xaf500,0xaf500,0xaf500
```

Two observations that kill the precision hypothesis:

1. **Magnitude.** The harness's own reported distances are 38, 45.7, 48.3, 54.7, 84.2, **336**, **345**,
   **339** against `Allowed tolerance: 32`. A ±1–2 ramp step cannot produce 336.
2. **Two different expected squares render identically for us.** Lines 258 and 269 are different
   gradient configurations in Flash (`0xfa3a00…` vs `0xfa420b…`) and we emit the *same nine values*
   for both. That is a whole-configuration divergence — a gradient variant (spread/interpolation
   method, focal point, or per-square matrix) being ignored and falling back to a previous/default
   configuration — not sampling precision.
   Corroborating asymmetry earlier in the run: Flash gives `0xc3ff` on both sides of a symmetric
   probe; we give `0xbbff` on one side and `0xc9ff` on the other (phase-shifted ramp).

Verdict **NO-GO** for a trace flip (155 missing lines, 1 test, and now demonstrably more than one
mechanism). But the test is a genuinely useful asset for the **pixel** agents: it is an AVM1
`beginGradientFill` + `BitmapData.getPixel` oracle with exact expected colours at fixed grid points,
i.e. a numeric gradient ground truth that the PNG-diff pipeline does not provide. Note also (from s17
`w2-gfx-smalls-report.md`) that its **image** comparison passes with only 12 % slack — the trace and
image axes disagree about this test and only the trace axis is red.

The plan file's `status_note` should be rewritten; I did not edit it (wave-1 is read-only).

---

## 6. Dispositions checked (rule 2)

Grepped every test name on my board against `avm1/_investigation/{ACCEPTED_DIFFS,RUFFLE_VS_FLASH_DIFFERENCES,RUFFLE_COMPAT_TWEAKS,FLASH_BUGS_REPLICATED}.md`,
`from_gnash/_investigation/*.md`, `ruffle-tests/ignored_tests.txt` and all four per-suite
`ignored_tests.txt`. Results:

- `misc-swfc.all/ignored_tests.txt` contains only `sound` and `matrix_accuracy_test1` — **not**
  `gotoFrameFromInterval` or `gotoFrameFromInterval2`.
- No board row of mine is in any ignore list or disposition doc. The inventory's `[RUFFLE_V]` flag on
  `gotoFrameFromInterval2` reflects the mode-parity note in `CLAUDE.md`/BACKLOG, not an
  ACCEPTED/RUFFLE_VS_FLASH entry, and it does not block G1 (which targets `ruffle_matched`).
- Correct `known_failure` handling per rule 3: `Function-v*`, `array-v*`, `MovieClip-v*`,
  `movieclip_destruction_test3/4`, `globals_monkeypatch`, `gotoFrameFromInterval2` are all upstream
  `known_failure = true`; each was checked for a ruffle sidecar (including the per-FP
  `output.fpN.ruffle.txt` form) and the reachable target stated explicitly above.
- `set_property_values/*` untouched as instructed.

---

## 7. Upstream drift (rule 12) — three findings, none of them regressions

### 7.1 The 8 "new" `*_special_recursion_*` avm1 dirs are **stale local duplicates, not new tests**

The coordinator's mid-task list named
`virtual_property_special_recursion_{swf6,swf7,double_swf6,double_swf7}` and
`watch_special_recursion_{swf6,swf7,double_swf6,double_swf7}` as brand-new dirs on disk but absent
from `_results/results_graphics.json`.

They are **renames**, not additions. Upstream `975f9d5b0` (*"tests: Remove 'special' from property
recursion tests"*) renamed all 8 to `*_recursion_*`, a pure 36-file rename with 0 content change.
`~/CC/ruffle` has only the new names. Our mirror has **both**, because `download_tests.sh` without
`--clean` never removes a directory.

The renamed siblings are **already graded** in the baseline:

| test | status |
|---|---|
| `virtual_property_recursion_swf6` | `ruffle_matched` (8/6/5) |
| `virtual_property_recursion_swf7` | `pass` |
| `virtual_property_recursion_double_swf6` | `pass` |
| `virtual_property_recursion_double_swf7` | `pass` |
| `watch_recursion_swf6` | `ruffle_matched` (18/18/17) |
| `watch_recursion_swf7` | `pass` |
| `watch_recursion_double_swf6` | `ruffle_matched` (46/46/42) |
| `watch_recursion_double_swf7` | `pass` |

Content check: 4 of the 8 stale dirs are byte-identical to their renamed twin; the other 4 differ
**only** in `output.ruffle.txt` / `known_failure` (upstream `e0e5b27ae`, *"avm1: Add per-property
recursion limit"*, later refreshed the Ruffle oracle and dropped `known_failure` on the two
`double_swf7` variants). Every `output.txt` is identical.

**Action:** delete the 8 `*_special_recursion_*` dirs from the local mirror. **CI is unaffected** — the
runner starts from a clean checkout (these dirs are gitignored) and `download_tests.sh` installs only
what upstream currently has, which is why they never appeared in `results_graphics.json`. There is no
denominator change and nothing to re-grade. I started a run over them and killed it once the rename
was proven, to avoid burning shared-machine time on duplicates.

### 7.2 Thirty-two stale `output.ruffle.txt` oracles — one of them a live trap

Systematic audit (every `*.ruffle.txt` under `avm1`, `avm2`, `from_shumway`, `from_gnash`,
`mixed_avm`, `timeline`, `text`, `swf`, `import_assets`, `audio`, `fonts`, `visual`, `stage3d` whose
upstream counterpart no longer exists): **32 files**, again pure non-clean-sync residue.

Cross-referenced against the baseline results, **26 of the 32 sit on tests we currently `pass`** (so
no false effective pass today), 6 are the `*_special_recursion_*` duplicates from §7.1, and exactly
one is live:

- **`from_shumway/avm1/hitarea/output.ruffle.txt`** — deleted upstream in `03fc070fa` when Ruffle
  implemented `hitArea` and the test started passing. Its content is Ruffle's *pre-fix* 3-line output,
  which is precisely what a partial hitArea implementation would emit. See §3 "Disposition trap".

Full list is reproducible with the audit snippet in `<scratch>/w1-trace-avm1/`. **Action:** prune all
32 locally (a `--clean` sync would do it, but `--clean` also wipes `_investigation/` and `_results/`,
so prune by name instead). CI is unaffected.

### 7.3 `from_gnash/misc-swfc.all/gotoFrameFromInterval` is on disk, ungraded, and **hangs**

The sibling of my `gotoFrameFromInterval2` row. It is the *only* dir under `misc-swfc.all` that is on
disk but missing from `_results/results_graphics.json` (21 test dirs on disk, `total_available: 20`).
It has a complete fixture (`test.swf`, `output.txt` 23 lines, `output.ruffle.txt` 32 lines,
`test.toml` `num_frames = 30`, `known_failure = true`).

**It times out, and the timeout is real, not shared-machine load:**

| run | conditions | result |
|---|---|---|
| batch (2 concurrent jobs) | no-graphics | `TIMEOUT [r=0.05s c=100.53s x=32.72s]` |
| **solo re-run** | no-graphics, nothing else running | `TIMEOUT [r=0.00s c=0.73s x=31.81s]` |

`verify_output.py` caps execution at 10 s (`"runtime timeout (>10s)"`, :4261); we run 3× over it with
a warm compile cache. This is a genuine non-terminating loop, not a slow test. Expected output ends
with `__END_OF_TEST__`; we never get there.

I could not resolve *why* CI did not grade it (`download_tests.sh` installs every dir containing a
`test.swf`, with no filtering, and CI clones ruffle `master` fresh at run time). **Flag for the
coordinator:** if the next CI run does pick it up, the corpus gains a `timeout` row (denominator +1,
fail +1) *and* ~10 s × 2 modes of wall clock. Worth deciding deliberately rather than discovering it
as a "regression". Not my brief to fix; listed as an unclaimed lead in §8.

---

## 8. New unclaimed leads

1. **`gotoFrameFromInterval` hangs** (§7.3). A genuine infinite loop in an AVM1 `setInterval` +
   `gotoAndPlay` fixture, confirmed solo. Closely related to G1's mechanism (same `.sc` family, same
   timer-callback-goto interaction). Whoever takes G1 should look at this immediately after — it may
   be the same drain, or it may be a distinct livelock. Owner: unassigned.
2. **`heap_alloc() called before heap_init()`** on `action_execution_order_test11` (§N3). Two stderr
   lines, `Failed to allocate property name` follows. Silent today; a property name is being allocated
   before the runtime heap exists. Owner: unassigned. Cheapest next step is a breakpoint on
   `heap_alloc` with `heap_init`'s flag clear.
3. **MovieClip prototype-chain virtual properties have no `MovieClip.prototype` fall-back** (§3,
   second mechanism). `action.c:52805` (set) and `:46450` (get) walk `mc->dynamic_props.__proto__` and
   stop when it is absent; `action.c:47349` (`instanceof`) has the fall-back the other two lack. Only
   `hitarea_lazy_getter` exercises it today, so the blast radius is unknown and possibly larger than
   one test. Needs a scratch fixture to confirm before anyone edits.
4. **`GradientFillTest` as a numeric gradient oracle for the pixel agents** (§5). Exact expected
   colours at fixed grid points for many `beginGradientFill` configurations; the image comparison
   passes with 12 % slack while the trace comparison is 123/278, so it is a strictly sharper
   instrument than the PNG diff for gradient work. Should be handed to whoever owns the gradient
   pixel family.
5. **AVM1 rollover picking is not a topmost pick** (§3, gap 1). `actionDispatchMCMouseMove`
   (`action.c:74592`) fires `onRollOver` on *every* button-mode clip whose AABB contains the pointer,
   in creation order, with an ad-hoc ancestor filter — Ruffle returns the single topmost hit,
   depth-descending. This is independent of `hitArea` and is a latent source of duplicate/misordered
   rollovers in real content. Nothing on the current board depends on it except
   `hitarea_remove_sibling`, but it is a model-level divergence worth its own row.

---

## 9. What I ran

| test | dir | mode | verdict |
|---|---|---|---|
| `hitarea_lazy_getter` | `avm1` | no-gfx | mismatch 6/0 |
| `hitarea_remove_owner_drag` | `avm1` | no-gfx | mismatch 10/3 |
| `hitarea_remove_sibling` | `avm1` | no-gfx | mismatch 4/3 |
| `hitarea_sweep` | `avm1` | no-gfx | mismatch 33/1 |
| `hitarea` | `from_shumway/avm1` | no-gfx | mismatch 4/2 |
| `avm1_loads_avm2` | `mixed_avm` | no-gfx | mismatch 7/3 |
| `gotoFrameFromInterval` | `from_gnash/misc-swfc.all` | no-gfx | **timeout** (×2, incl. solo) |
| `gotoFrameFromInterval2` | `from_gnash/misc-swfc.all` | no-gfx | **ruffle_matched** |
| `gotoFrameFromInterval2` | `from_gnash/misc-swfc.all` | **graphics** | mismatch 23/2 — **parity gap reproduced** |
| `PlaceAndRemove` | `…/misc-ming.all/action_order` | no-gfx | mismatch 96/15, 45 actual |
| `action_execution_order_test11` | `…/misc-ming.all/action_order` | no-gfx | mismatch 32/26 |
| `Function-v6 / -v7 / -v8` | `from_gnash/actionscript.all` | no-gfx | mismatch, 8-line diff each |
| `movieclip_destruction_test3` | `from_gnash/misc-swfc.all` | no-gfx | mismatch 18/5 |
| `movieclip_destruction_test4` | `from_gnash/misc-swfc.all` | no-gfx | mismatch 40/8 |
| `globals_monkeypatch` | `avm1` | no-gfx | mismatch 100/38 |
| `GradientFillTest` | `from_gnash/misc-ming.all` | no-gfx | mismatch 278/123 |

Not run, priced from stored results + written plans + oracle-distance arithmetic (stated as such in
§N4): `array-v6/-v7/-v8`, `MovieClip-v6/-v7/-v8`.
