# w2-avm1-hitarea — wave-2 implementation report (AVM1 `MovieClip.hitArea`)

Session 18, base `8f68a5fea`, isolated worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-ae7b49dfde79ce599`. No commits, no pushes.
All runs no-graphics unless marked, `SWFRECOMP_COMPILE_TIMEOUT=2400`, `--diff --verbose`, never
more than 2 concurrent jobs. Logs: `<scratch>/w2-avm1-hitarea/`.

## NEW files (coordinator stages by name)

- `SWFRecompDocs/plans/session18-fanout-reports/w2-avm1-hitarea.patch`
- `SWFRecompDocs/plans/session18-fanout-reports/w2-avm1-hitarea-report.md` (this file)

No new source files, no new headers, no new TU. **One** source file touched:
`SWFModernRuntime/src/actionmodern/action.c` — runtime only. No recompiler change, so no
`Recompiled*` invalidation; no CMakeLists / Emscripten / `verify_output.py` source-list change.
CI mode: shared runtime code, no `#ifdef NO_GRAPHICS`-only arms touched → **`graphics`** is the
right per-change dispatch (the baseline for these tests is identical in both modes, see §5).

---

## 0. Verdict

**GO — +3 passes, one more than the brief priced (+2).**

| test | before | after | verdict |
|---|---|---|---|
| `from_shumway/avm1/hitarea` | `output_mismatch` 2/4 | **PASS** | **+1** |
| `avm1/hitarea_remove_sibling` | `output_mismatch` 3/4 | **PASS** | **+1** |
| `avm1/hitarea_lazy_getter` | `output_mismatch` 0/6 | **PASS** | **+1** (the "second mechanism" — it landed) |
| `avm1/hitarea_remove_owner_drag` | `output_mismatch` 3/10 | `output_mismatch` **5/10** | second arc, +2 matching lines, no flip |
| `avm1/hitarea_sweep` | `output_mismatch` 1/33 (20 actual) | `output_mismatch` **3/33** (37 actual) | second arc, no flip |

Canaries: **28/31 avm1 + 4/4 from_shumway/avm1 + 89/89 `regression` all unchanged**, plus 4/4 in
`--mode=graphics`. The only two avm1 canary rows that are not `pass` are the two second-arc hitarea
tests themselves and `movieclip_hittest_shapeflag`, which was already failing at baseline and is
byte-for-byte unchanged (§5).

`from_shumway/avm1/hitarea` reaches **`pass`**, not `ruffle_matched`: the stale
`output.ruffle.txt` disposition trap was real and is handled — see §1.

---

## 1. Disposition trap — confirmed and handled

The coordinator had already pruned `from_shumway/avm1/hitarea/output.ruffle.txt` from the main
tree; I re-checked my copied test dir and it was absent there too (I `rm -f`'d it anyway before
the first run). The test's local `test.toml` carries no `known_failure`, so grading is against
`output.txt` only and `pass` is the reachable verdict. **The trap was not hypothetical**: the
partial fix I had after the first slice emitted exactly a 3-line output, which is what the stale
oracle contained.

Dispositions checked before implementing (grep by test name over
`avm1/_investigation/ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`,
`RUFFLE_COMPAT_TWEAKS.md`, `FLASH_BUGS_REPLICATED.md`, `ruffle-tests/ignored_tests.txt`,
per-suite `ignored_tests.txt`): **no hitarea test appears in any of them.** Nothing needs adding
to those docs for this patch — every flip is a real Flash-parity fix, not a compat tweak.

---

## 2. What landed — two mechanisms, one file

### M1 — pick-time `hitArea` resolution (new code, ~200 lines, self-localized)

New static block in `action.c`, inserted immediately before `actionDispatchMCPress`, all symbols
`static` and `ng_`/`mc_`-prefixed so it cannot collide with w2-avm1-function's Function/arguments
region or w2-avm1-goto's `swf.c`:

| symbol | role |
|---|---|
| `NgHitAreaEntry` / `s_hit_area_tbl` | per-pick `{owner, area}` side table |
| `mc_is_avm1_gone_ng` | `avm1_removed \|\| pending_removal` predicate |
| `ng_hit_area_snapshot_alive` / `s_hit_alive_snap` | lazily-taken alive-at-pick-start snapshot |
| `mc_removed_during_pick_ng` | "was alive at pick start, gone now" |
| `ng_resolve_hit_area` | one ordinary AVM1 `hitArea` get on a clip, inside a throw-swallowing `setjmp` frame |
| `ng_hit_order_cmp` | depth-DESCENDING order (index desc as tiebreak) |
| `mc_hit_area_pick_begin` | the pre-pass |
| `mc_hit_pixel_aabb_ng` | `mc_get_pixel_aabb_ng` with the hit-area substitution |

Wiring (4 call sites, all in the AVM1 AS2 mouse dispatchers):

- `actionDispatchMCMouseMove`: `mc_hit_area_pick_begin` at entry; `mc_get_pixel_aabb_ng` →
  `mc_hit_pixel_aabb_ng`; `continue` on `mc_removed_during_pick_ng`.
- `actionDispatchMCPress`: same three.
- `actionDispatchMCRelease`: `pick_begin` + `mc_hit_pixel_aabb_ng`.

`actionMCMouseInsidePick` (used by `tag.c`'s button-state loops and by
`mc_has_button_mode_ancestor_with_mouse`) is deliberately **left on the owner's own AABB**: those
callers do not open a pick, so consuming the side table there would read a stale entry from the
previous pick. Named as a known gap in §6.

**Semantics implemented** (authority: `~/CC/ruffle` `movie_clip.rs::hit_area` /
`player.rs::mouse_pick_avm1`, per w1's §3):

1. `hitArea` is resolved by an ordinary property get — own props, `__proto__` chain, then
   `MovieClip.prototype` — so user getters run, on **every** button-mode pick, before any bounds
   check.
2. A `MovieClip` result **replaces** the owner's own shape as its hit region. Anything else
   (undefined, a non-clip, a removed clip, itself, **or a getter that throws**) leaves the owner on
   its own shape.
3. The resolution walk is **depth-descending (topmost first)**.
4. A clip a getter removes mid-pick is excluded from the rest of that pick.
5. The getter runs **once per pick**, not once per consumer (the side table).

### M2 — `MovieClip.prototype` accessor fall-back in the MC `GetMember` / `SetMember` arms

This is w1's "second mechanism", and w1 flagged it *unverified*. **It is confirmed, and w1's
diagnosis was right about the place but incomplete about the cause** — see §3.

Four small edits:

- `actionGetMember` MC arm: after the `dynamic_props.__proto__` walk, fall back to
  `g_movieclip_constructor.prototype_obj`, **accessors only**, and only when the clip has no
  **own** property of that name (`_mc_ap == NULL`) so an own value still shadows the prototype.
- `actionSetMember` MC arm: same fall-back for the setter walk, accessors only.
- Both arms additionally *materialize* `mc->dynamic_props` when it is `NULL` **and** a
  `MovieClip.prototype` accessor of that name exists, so `this` binds to the clip.

**Accessors only** is what bounds the blast radius. I verified every `prop->getter = ` site in
`action.c` (5 of them: `:4909`, `:62117`, `:67308`, `:67799`, `:73443`) is a user-level
`addProperty` implementation — the runtime installs **no** builtin accessor on
`MovieClip.prototype`; its builtins are plain function values and undefined-valued stubs
(`scrollRect`, `opaqueBackground`). So the fall-back can only fire for content that itself calls
`MovieClip.prototype.addProperty(...)`, which w1 established is `hitarea_lazy_getter` and nothing
else in the avm1 suite.

---

## 3. Refutations / corrections to the wave-1 diagnosis

**R1 — "the depth-descending topmost pick is required for `hitarea_remove_sibling`" is FALSE as
stated.** w1 §3 listed two structural gaps as prerequisites for that test: (1) depth-descending
pick order, (2) removed-clip exclusion. Only (2) is load-bearing. Because the `hitArea`
resolution is a **pre-pass over all button-mode clips that completes before any rollover fires**,
`btnY` is already removed by the time the dispatch loop reaches it *whatever order the pre-pass
used*. I implemented depth-descending anyway (it is Ruffle's order and it is what decides the
outcome when two clips both install side-effecting getters), but the flip does not depend on it.
This matters for pricing: the expensive half of w1's "why it is HOLD, not GO" was not needed.

**R2 — "`MovieClip.prototype.addProperty` does not dispatch from a MovieClip receiver because the
walk `break`s when `__proto__` is absent" is only half the cause.** The missing `MovieClip.prototype`
fall-back is real, but adding it alone did **not** fix `hitarea_lazy_getter`. The clip in that test
has **no `dynamic_props` object at all** at the moment of `btn.hitArea = decoy` (it is btn's first
write), so the entire `if (mc->dynamic_props != NULL)` block — walk and fall-back together — is
skipped. The fix needs the materialization step as well. First measured attempt (fall-back only):
`readback: _level0.clipA` started working (GetMember) but `setter consumed …` was still missing and
the pick resolved to the stored `decoy`. Full fix: PASS.

**R3 — the lead "AVM1 rollover picking is not a topmost pick — every AABB-containing button-mode
clip fires" is CONFIRMED, and this patch does NOT change it.** `actionDispatchMCMouseMove` still
fires `onRollOver` on every button-mode clip whose (possibly substituted) AABB contains the
pointer. `hitarea_remove_owner_drag` is the standing proof: `btnZ` and `btnRm` occupy the *same*
rect, Flash reports only `rollover Rm`, and we still emit `rollover Z` first. Converting that loop
to a single topmost pick is a much larger, much riskier change than this slice (it would alter
event delivery for every AVM1 title with overlapping button clips), and it is **not** needed for
any of the three flips. NO-GO for this slice; see §6 for its completion mechanism.

**R4 — a deliberate deviation from Ruffle, stated up front.** Ruffle stops its pick at the first
(topmost) hit, so a lower clip's `hitArea` getter never runs once a higher clip hits. Our pre-pass
resolves *every* button-mode clip's `hitArea`, because our dispatch is not a topmost pick (R3) and
a clip that will fire needs its hit region resolved. Observable only when two clips both install
side-effecting `hitArea` getters; the depth-descending **order** is exact. Documented in the code
comment.

---

## 4. Second-arc tests — before/after, as the brief asked

Both are w1's "separate arc (shape-based picking)". I graded them, did not chase them.

### `avm1/hitarea_remove_owner_drag` — 3/10 → 5/10, no flip

```
expected                    before                      after
1  ready                    ready                       ready
2  dt: (none)               dt: (none)                  dt: (none)
3  rollover Rm              rollover Z      <-- R3      rollover Z      <-- R3
4  armed                    rollover Rm                 rollover Rm
5  drag start               armed                       armed
6  removing owner           drag start                  drag start
7  dt: /btnRm               dt: /btnRm                  removing owner  <-- NEW, correct line
8  dt: /btnZ                drag end                    dt: /btnZ       <-- now matches
9  drag end                 rollover Z                  drag end        <-- now matches
10 rollover Z               rollover Rm                 rollover Z      <-- now matches
```

The getter now fires and `removing owner` is emitted (M1 working through a `_droptarget`-adjacent
path). Two blockers remain, both outside this slice: the R3 topmost pick (line 3), and
`_droptarget` reporting the *just-removed* owner on the pick that removed it (`dt: /btnRm`) —
Ruffle's "removal takes effect on the NEXT pick for the owner", which lives in
`ng_compute_droptarget` (`tag.c:8016`) / `actionRefreshDropTargetIfDragged` (`action.c:35191`),
not in the mouse-move pick at all.

### `avm1/hitarea_sweep` — 3/33 baseline

Baseline (read fresh from `_results/results.json` at HEAD): 33 expected, **1** matching, 20 actual
lines. After: 33 expected, **3** matching, **37** actual — the whole probe sequence now runs. The
head of the output is right (`ready`, `chain via b`, `invisible`) and then two spurious lines shift
the alignment:

```
expected 4  zero scale          actual 4  owner invisible   <- an INVISIBLE OWNER's hit area must NOT hit
expected 5  textfield via tf    actual 5  zero scale
expected 6  tfmask              actual 6  textfield via tf
                                actual 7  mask via hit      <- MovieClip-vs-TextField mask semantics
```

So the substitution itself is working across the sweep's probes; what is missing is Ruffle's
visibility rule (`SKIP_INVISIBLE` applies to the owner but not to the hit area) and the mask rules.
This is w1's correct call: the sweep needs
shape-level hit tests, MovieClip-vs-TextField mask semantics, transforms mutated inside the getter,
two drags and a `stopDrag()` re-entrancy guard. Our AABB picking model is the wrong substrate for
the shape/mask half. **NO-GO, arc not slice.**

---

## 5. Canary ledger

Baselines are read fresh from the main tree's `_results/results.json` **and**
`results_graphics.json` at HEAD `8f68a5fea` (identical in both modes for every row below — no
mode-parity risk in this family). Bar: a currently-passing canary must still pass, so its `--diff`
output is byte-identical (empty) before and after.

### Headline (no-graphics)

| test | suite | before (CI baseline) | after | Δ |
|---|---|---|---|---|
| `hitarea` | from_shumway/avm1 | `output_mismatch` 2/4, 3 actual | **PASS** 4/4 | **flip** |
| `hitarea_remove_sibling` | avm1 | `output_mismatch` 3/4 | **PASS** 4/4 | **flip** |
| `hitarea_lazy_getter` | avm1 | `output_mismatch` 0/6, 3 actual | **PASS** 6/6 | **flip** |
| `hitarea_remove_owner_drag` | avm1 | `output_mismatch` 3/10 | `output_mismatch` **5/10** | +2 lines, no flip |
| `hitarea_sweep` | avm1 | `output_mismatch` **1**/33, 20 actual | `output_mismatch` **3**/33, 37 actual | +2 lines, no flip |

### Canaries — all PASS, byte-identical (28/31 avm1 + 4/4 shumway + 89/89 regression)

| group | tests | before | after |
|---|---|---|---|
| `avm1/button_*` | `button_children`, `button_goto`, `button_key_events`, `button_keypress`, `button_keypress_vs_press`, `button_order`, `button_properties_special_cases`, `button_v5`, `button_v6` | 9 pass | **9 pass** |
| `avm1/drag*` | `drag_drop`, `drag_over_from_outside`, `drag_over_without_startdrag` | 3 pass | **3 pass** |
| `avm1/focus*` (sample 4) | `focus_keyboard_press`, `focus_mouse`, `focus_mouse_rollout`, `focus_remove` | 4 pass | **4 pass** |
| `avm1/hittest*` | `hittest_lockroot`, `hittest_morph`, `hittest_morph_input`, `hittest_winding_rule` | 4 pass | **4 pass** |
| `avm1/mouse_*` | `mouse_events`, `mouse_events_visible_enabled`, `mouse_hover_events_while_dragging`, `mouse_listeners`, `mouse_pos` | 5 pass | **5 pass** |
| `avm1/movieclip_hittest*` | `movieclip_hittest` | pass | **pass** |
| `from_shumway/avm1` mouse tests | `mouse-transparency`, `nested-button`, `rollover` (the three with `input.json`; `hitarea` is the 4th and is a target) | 3 pass | **3 pass** |
| `regression` (whole suite) | 89 tests | 89 pass | **89 pass**, `[diff] pass: 89/89 \| vs prev: no changes` |

`avm1/movieclip_hittest_shapeflag` was **already failing** at baseline and is **unchanged**:
332/338 matching lines before and after (identical count in `results.json`,
`results_graphics.json` and my run), and the baseline's stored `actual_output` fragment carries
the same `hitTest(300, 400, true) -> false` line my run's diff reports. It is `MovieClip.hitTest`
(shape_hit_test.c), which this patch does not touch.

### `--mode=graphics` (brief asked for 3; ran 4, incl. 2 targets)

| test | before | after |
|---|---|---|
| `avm1/hitarea_lazy_getter` | `output_mismatch` 0/6 | **PASS** |
| `avm1/hitarea_remove_sibling` | `output_mismatch` 3/4 | **PASS** |
| `avm1/mouse_events` | pass | **pass** |
| `avm1/drag_drop` | pass | **pass** |

(Graphics needs `DAWN_INSTALL=/home/robert/CC/dawn-install` exported explicitly in a worktree —
`verify_output.py` otherwise looks for `<worktree-parent>/dawn-install`. Not a code issue, but it
costs a wasted run if you forget.)

### One real regression found and fixed mid-slice — worth recording

The first working version of M1 **broke `hitarea_sweep` harder than it found it**: with the getter
now actually invoked, the sweep's deliberately-throwing `hitArea` getter longjmp'd straight out of
`actionDispatchMCMouseMove`, and the movie died with
`Warning: Uncaught exception, boom` — 1/33 → 1/33 but **20 actual lines → 2**. Ruffle discards a
throwing getter's error (`.ok()`) and lets the owner pick on its own shape. Fixed by bracketing
the getter call in a `setjmp` frame that swallows the throw and returns "no hit area", copying
`filerefOwnField`'s existing precedent at `action.c:39154`. After the fix the sweep runs its whole
37-line probe sequence (1/33 → 3/33). **Lesson for anyone touching a pick path: the moment you
start calling user code from inside input dispatch, you own its exceptions.**

---

## 6. Known gaps this slice does NOT close (each with its completion mechanism)

1. **Topmost pick (R3).** `actionDispatchMCMouseMove` fires on every containing button-mode clip.
   *Completion mechanism:* replace the per-clip `mc_mouse_inside` model with a single
   `mouse_pick_avm1`-style result (one topmost hit per pick) and derive RollOver/RollOut from the
   previous vs current picked object, as Ruffle does. That reorders/suppresses events for every
   AVM1 title with overlapping button clips — it needs its own slice and its own canary wave.
2. **`_droptarget` resolving-but-ignoring `hitArea`, and next-pick removal semantics.** Ruffle
   resolves the property on `require_button_mode == false` picks too, discards the value, and lets a
   mid-pick removal take effect only on the following pick. *Completion mechanism:* call
   `mc_hit_area_pick_begin` from `ng_compute_droptarget`/`actionRefreshDropTargetIfDragged` and give
   the owner a one-pick grace before exclusion.
3. **`actionMCMouseInsidePick` / `tag.c` button-state loops ignore `hitArea`.** *Completion
   mechanism:* give those call sites their own `pick_begin`, or hoist the pre-pass to the frame's
   single input-processing entry point so one table serves every consumer in a frame.
4. **Invisible-owner / `SKIP_MASK` rules and shape-level hit tests** (the `hitarea_sweep` arc).
   *Completion mechanism:* route AVM1 picking through `shape_hit_test.c` instead of AABBs.
5. **A getter that calls `stopDrag()` mid-pick** needs Ruffle's `Player::update_drag` re-entrancy
   guard. Not reachable from the three flipped tests.

---

## 7. Cost / risk notes

- Per mouse pick the pre-pass costs one `child_mc_cache` scan, a `qsort` of the button-mode
  candidates, and one `findPropertyStructWithPrototype("hitArea")` per candidate. It is **not**
  gated behind a "does anything use hitArea" flag — the lookup is cheap and gating it would make
  the mechanism silently mode-dependent. If a title ever shows this on a profile, the gate is a
  one-line addition at `mc_hit_area_pick_begin`'s top.
- The removed-mid-pick exclusion is inert for content with no `hitArea` **accessor**: the alive
  snapshot is taken lazily, immediately before the first user getter of the pick, so if no getter
  runs `mc_removed_during_pick_ng` returns 0 for everything. That is deliberate — it keeps the one
  genuinely behaviour-changing rule (excluding a clip removed during a pick) from touching any
  existing content.
- `realloc`-backed buffers only ever grow and are reused across picks; no per-pick allocation in
  the steady state.

---

## 8. New unclaimed leads

- **`hitArea` on TextField owners.** `mc_hit_area_pick_begin` skips text fields (they get no roll
  events at all in our dispatch). `hitarea_sweep`'s `textfield via tf` / `tfmask` lines are exactly
  that case; whether Flash lets a TextField own a hit area is worth an oracle read before anyone
  prices it.
- **The `GetMember` MC arm resolves prototype accessors before own PLAIN values.** The pre-existing
  `__proto__`-chain walk has this shape (my fall-back copies it, and I added an `_mc_ap == NULL`
  guard so at least *own* values win). A clip with a real `__proto__` chain (registerClass) that
  stores a plain own value shadowed by a prototype accessor of the same name would still resolve to
  the accessor. No test in the corpus exercises it; it is a latent correctness bug in the existing
  code, not something this patch introduced.
- **`isPropertyHiddenAtVersion` is not applied by the pre-existing `GetMember` `__proto__` walk**
  (it is by the `SetMember` one). I applied it in both of my fall-backs. Harmonizing the existing
  walk is a one-line change nobody has priced.
