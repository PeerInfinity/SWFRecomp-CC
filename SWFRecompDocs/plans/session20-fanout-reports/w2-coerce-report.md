# w2-coerce — ONE AVM1 display-property coercion gate: SetMember / `with`-scope / SetVariable now agree with the SetProperty opcode

**Worktree**: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a4f0acd56be3a70d3`
**Base**: `ff94b2338` (the worktree's actual base — a docs-only commit on top of
the brief's `4b05de6ef`; `action.c` is byte-identical at both).
**Sibling collision**: none. Only `SWFModernRuntime/src/actionmodern/action.c` is
touched, inside `propertyCoerceToNumber` / `spvPropertyCoerceToNumber` and their
call sites (`actionSetVariable`, `actionSetMember`'s MOVIECLIP arm,
`setMCBuiltinProperty`, `actionSetProperty` cases 0/1), exactly as the file map
allots. No other agent edits this file.

---

## NEW FILES — the coordinator must stage these BY NAME (`git add -u` drops them)

```
ruffle-tests/tests/swfs/regression/avm1_display_prop_coercion/test.swf
ruffle-tests/tests/swfs/regression/avm1_display_prop_coercion/output.txt
ruffle-tests/tests/swfs/regression/avm1_display_prop_coercion/test.toml
ruffle-tests/tests/swfs/regression/avm1_display_prop_coercion/DisplayPropCoercion.as
SWFRecompDocs/plans/session20-fanout-reports/w2-coerce-1-one-gate.patch
SWFRecompDocs/plans/session20-fanout-reports/w2-coerce-2-alpha-fixed8.patch
SWFRecompDocs/plans/session20-fanout-reports/w2-coerce-3-twips-truncate.patch
SWFRecompDocs/plans/session20-fanout-reports/w2-coerce-4-focusrect.patch
SWFRecompDocs/plans/session20-fanout-reports/w2-coerce-report.md
```

`ruffle-tests/tests/swfs/regression/_results/*` is deliberately **NOT** part of
the delivery — my local suite run rewrote it; let CI regenerate it. The new
fixture will show up as a new row on the next run.

---

## 1. Verdict first

**GO on patches 1 + 2 + 3. Patch 4 is OPTIONAL (no isolating test) — drop it if
you want zero unproven risk.**

**Priced corpus flips: ZERO — and that was the honest expectation.** This arc is
the "0-flip, engine-wide correctness" case the s19 playbook says is worth
landing: it is not visible to the corpus because **no upstream test writes a
display property through SetMember or a `with`-scope with anything but a plain
in-range number**. It is visible to every AVM1 game, because `mc._x = ...` is a
SetMember in essentially all compiled AS.

| deliverable | result |
|---|---|
| **NEW** `regression/avm1_display_prop_coercion` | **18 of 36 lines wrong → PASS, byte-identical to the Ruffle oracle** |
| all 27 avm1 property/coordinate tests | status unchanged (26 `pass`, 1 `ruffle_matched`) |
| `avm1/set_property_values/swf5,6,7` (s19's flips) | still **PASS** |
| `avm1/set_property_values/swf4` | `output_mismatch`, **actual byte-identical before/after** — NOT my mechanism (§5) |
| `from_gnash` MovieClip-v5/v6/v7, Color-v6, swf4opcode | status unchanged; v6/v7 actual **byte-identical** before/after |
| regression suite (96 tests, incl. the new fixture) | **96/96 pass, `vs prev: no changes`** |

**Corpus target verdict — `avm1/set_property_values/swf4` is NOT mine.** §5.

---

## 2. Patches (apply in order — 2 and 3 edit lines that 1 introduces)

| # | file | what it fixes | isolating evidence |
|---|---|---|---|
| **1** | `w2-coerce-1-one-gate.patch` (365 lines) | **One coercion gate.** Deletes the duplicate `propertyCoerceToNumber`; `actionSetVariable`, `actionSetMember`'s MOVIECLIP arm and `setMCBuiltinProperty` all use `spvPropertyCoerceToNumber`, plus per-property `±Infinity` handling copied from `actionSetProperty`. | fixture rows `_x inf`, `_x undefined`, `_x null`, `_x '10x'`, `_x valueOf42`, `_alpha inf`, `_alpha undefined`, `_alpha '10x'`, `_visible inf`, `_rotation inf/undefined`, `_xscale inf/'10x'/undefined` |
| **2** | `w2-coerce-2-alpha-fixed8.patch` (62) | **`_alpha` quantizer.** `roundf` → Ruffle's `Fixed8::from_f64` = truncate-toward-zero + saturate, at the three non-opcode sites. | fixture rows `_alpha -5` (`-5.078125` → `-4.6875`), `_alpha 33.3` |
| **3** | `w2-coerce-3-twips-truncate.patch` (93) | **`_x`/`_y` quantize on WRITE by truncation** (`Twips::from_pixels` is `(px*20.0) as i32`), in all FOUR paths. Replaces `floor` (SetMember) and quantize-on-read-by-`round` (everywhere else). **Beyond the brief** — this is a divergence where *both* of the brief's paths were wrong. | fixture row `_x -10.53` (`-10.55` → `-10.5`) |
| **4** | `w2-coerce-4-focusrect.patch` (31) | `actionSetVariable`'s `_focusrect` **numeric branch was dead code** — it read the shared lazily-resolved `dval`, which `RESOLVE_NUM_PROP()` is never called on in that arm, so it was always `NAN` and a bare numeric `_focusrect = 1` silently did nothing. Also routes its string branch through the same strict parser `actionSetProperty` case 17 uses. | **none** — `_focusrect` via bare SetVariable is not expressible in MTASC and no corpus test covers it. `focusrect_property_swf5` / `focusrect_swf5` still PASS, which is a non-regression signal only. |

**Serial-apply verified**: extracting `action.c` at `ff94b2338` and applying
1 → 2 → 3 → 4 with `patch -p1` reproduces the tested worktree file **byte for
byte**, so the merge order above is the one that works. (The worktree carries
four local `wip1..wip4` commits purely to cut those diffs; they are never
pushed and the coordinator should ignore them and use the `.patch` files.)

All four were validated as a stack, not individually — the box was shared with
seven other agents and a per-patch leg would have cost four more full compiles.
The fixture rows above are what lets the coordinator attribute a regression to
one patch during serial merge.

---

## 3. Premise verification — the brief's claim is HALF TRUE and its labels are SWAPPED

The brief called `propertyCoerceToNumber` "the opcode path" and
`spvPropertyCoerceToNumber` "the SetMember path". It is the other way round, and
there are **four** paths, not two. Verified by resolving the enclosing function
of every call site (pre-patch line numbers):

| path | entry | coercion used | reached by |
|---|---|---|---|
| A | `actionSetProperty` (`:59728`), gate at `:59801` | `spvPropertyCoerceToNumber` — the Ruffle-exact one (s19) | `setProperty(t, _x, v)` opcode |
| B | `actionSetVariable` (`:46140`), gate at `:46519` | `propertyCoerceToNumber` — rejected `±Infinity`, lenient `strtod`, no `valueOf` | a root frame script's bare `_x = v` |
| C | `actionSetMember` (`:50963`), MOVIECLIP arm `:52366` | `varToDoubleSimple` + an ad-hoc `isnan \|\| NULL \|\| UNDEFINED` test | **`mc._x = v` — the hot path** |
| D | `setMCBuiltinProperty` (`:60699`) | `varToDoubleSimple` and **no validity gate at all** | `with(mc){ _x = v }` (via `actionSetVariable:46431`) and `attachMovie` initObject (`applyInitObjectPropToMC:60768`) |

* **"The SetMember path still rejects `±Infinity`" — FALSE for the SetMember path
  (C), TRUE for the SetVariable path (B).** C does not reject it: it lets the
  infinity through into `floor(inf*20)/20`, stores `+inf` in `mc->x`, and the
  read quantizer saturates it to **`+107374182.35`** — the *opposite sign* from
  Ruffle's `-107374182.4`. D does the same. A rejection would have been the
  milder bug. Measured, not argued: the pre-patch fixture prints
  `_x inf: 107374182.35`.
* **"still uses `roundf` for `_alpha`" — TRUE of B, C and D** (`:46564`,
  `:52415`, `:60739`). Pre-patch fixture: `_alpha -5: -5.078125`, Ruffle
  `-4.6875`.
* **The `:15568` comment the brief flagged ("defers `±Infinity` to the
  per-property setter, which handles it per-property") is ACCURATE — for path A.**
  `actionSetProperty`'s cases 0/1/6/7/16/18 really do handle each infinity. What
  the comment got wrong is its parenthetical, which called
  `propertyCoerceToNumber` "the SetMember-by-name path" — it is not; C never used
  it. **No per-property setter on B/C/D handled an infinity**, so deleting the
  rejection alone would have regressed them (`_alpha = 1/0` would have reached an
  `int16_t` cast of an infinity, which is UB in C). That is why patch 1 removes
  the gate *and* adds the per-property arms in one step.

### The biggest find is not in the brief at all

**Path D has no validity gate**, so a NaN/undefined/unparseable value was written
straight into the MovieClip. Pre-patch fixture rows:

```
with(m){ _x = undefined }        ->  NaN        (Ruffle: no-op, stays 7)
with(m){ _x = null }             ->  0          (Ruffle: no-op)
with(m){ _rotation = undefined } ->  NaN        (Ruffle: no-op)
with(m){ _xscale = undefined }   ->  NaN        (Ruffle: no-op)
with(m){ _alpha = undefined }    ->  0          (Ruffle: no-op)
with(m){ _x = {valueOf:42} }     ->  NaN        (Ruffle: 42)
```

`with(mc){ _x = ... }` is the Pacman/ghost movement path named in memory
`browser-wasm-visible-and-nonroot-attach-render`; a NaN there poisons the
transform permanently. Same helper serves `attachMovie(..., {_x: v})`.

---

## 4. Oracle — Ruffle has exactly ONE gate and ONE setter per property

`~/CC/ruffle` at `f2aaf0703`:

* `core/src/avm1/object/script_object.rs:287` — **SetMember** on a display object
  looks the name up in `display_properties()` and calls `property.set(...)`.
* `core/src/avm1/activation.rs:1991` — **SetProperty** looks the *index* up in the
  same `DisplayPropertyMap` and calls the same `property.set(...)`.
* `set_variable` → `Object::set` → the same place.

All three land in the same `set_x` / `set_alpha` / `set_visible` in
`stage_object.rs`, whose only coercion is `property_coerce_to_number`
(`stage_object.rs:260`): *undefined and null do not set; **NaN** does not set;
everything else, **including ±Infinity**, reaches the setter.*

| setter | rule | line |
|---|---|---|
| `set_x` / `set_y` | `is_infinite → -Infinity`, then `Twips::from_pixels` | 332, 353 |
| `set_x_scale` / `set_y_scale` | stored raw (`Infinity` reads back) | 372, 391 |
| `set_alpha` | `is_infinite → 0.0`, then `set_alpha(v/100)` → `Fixed8::from_f64` | 300 |
| `set_visible` | `n != 0.0` on the **f64** | 316 |
| `set_rotation` | `degrees %= 360.0` (an infinity gives NaN) | 484 |
| `set_high_quality` / `set_sound_buf_time` | null/undefined early-return, then `coerce_to_f64`, NaN-guard, `clamp_to_i32` for the latter | 563, 652 |

The two quantizers are Rust `as` casts — **truncate toward zero, saturate, never
round**:

* `swf/src/types/twips.rs:102` — `Twips::from_pixels(px) = (px * 20.0) as i32`
* `swf/src/types/fixed.rs:73` — `Fixed8::from_f64(n) = (n * 256.0) as i16`

`Value::coerce_to_f64` → `string_to_f64` → `parse_float_impl(s, strict)` with
`strict = swf_version >= 5` (`value.rs:968`), confirming s19's `spvCoerceToF64`
shape, including its SWF4 carve-out.

---

## 5. Corpus target: `avm1/set_property_values/swf4` is NOT this mechanism

Read the test, not the status. It is `known_failure = true` **with** an
`output.ruffle.txt`, and it exercises the **SetProperty opcode**, not SetMember.

* Against Flash (`output.txt`, 1571 lines) the gap is structural: Flash's SWF4
  `setProperty` does **not** call `valueOf` on an object — it traces
  `Warning: Object is not a function` and stores `0`. We call `valueOf` (1743
  lines, Ruffle's shape). That is a SWF4 **object-coercion** gap plus a warning
  line we do not emit.
* Against Ruffle (`output.ruffle.txt`, 1743 lines) we are **173 lines** short,
  and all 173 are the SWF4 unparseable-string rule: Ruffle's non-strict
  `string_to_f64` folds NaN to `0.0` and stores 0; Flash abandons the set. **We
  deliberately follow Flash there** because `from_gnash/misc-swfc.all/swf4opcode`
  (also `known_failure`, also with an `output.ruffle.txt`) pins Flash's answer —
  s19 already paid for that choice (`w2-setprops-2-swf4fix`). Chasing
  `ruffle_matched` here would re-regress `swf4opcode`.
* Empirically: its actual output is **byte-identical before and after my patch**.

**Completion mechanism for this row**: SWF4 object coercion (no `valueOf`, emit
the `Warning:` line) would move it toward `output.txt`; it is a different arc and
it conflicts with nothing I touched. The `ruffle_matched` route is closed by the
`swf4opcode` conflict and should be recorded as such.

---

## 6. The fixture (new) — `regression/avm1_display_prop_coercion`

MTASC-compiled (`DisplayPropCoercion.as`, SWF8), expected output captured from
`~/CC/ruffle/target/release/exporter` at `f2aaf0703` — **an oracle outside
SWFRecomp**, per the wave-2 rule. Guard values (7 / 77) differ from every value
under test so a *no-op* is distinguishable from a wrong-but-equal parse (my first
draft used 10 and `_x = "10x"` was non-discriminating).

36 rows over SetMember and `with`-scope: `±Infinity`, `undefined`, `null`,
`"10x"` (strict parse), `"25"`, a `valueOf` object, `-10.53` / `10.53` (twips
quantizer), `_alpha` −5 / 33.3 / 12.5 (Fixed8 quantizer), `_visible`,
`_rotation`, `_xscale`.

```
before:  18 of 36 lines wrong   (MISMATCH)
after:   0                      (PASS, byte-identical to the Ruffle oracle)
```

Full before-diff, all of it real-engine divergence:

```
_x inf:            107374182.35 -> -107374182.4      (sign flip!)
_y inf:            107374182.35 -> -107374182.4
_x '10x':          10           -> 7   (no-op; strict parse)
_x valueOf42:      7            -> 42  (valueOf now honoured)
_x -10.53:         -10.55       -> -10.5
_alpha -5:         -5.078125    -> -4.6875
_alpha '10x':      10.15625     -> 76.953125 (no-op)
_xscale '10x':     10           -> 77        (no-op)
with _x inf:       107374182.35 -> -107374182.4
with _x undefined: NaN          -> 7
with _x null:      0            -> 7
with _x '10x':     10           -> 7
with _x valueOf42: NaN          -> 42
with _alpha -5:    -5.078125    -> -4.6875
with _alpha undefined: 0        -> 76.953125
with _alpha '10x': 10.15625     -> 76.953125
with _rotation undefined: NaN   -> 7
with _xscale undefined:   NaN   -> 77
```

---

## 7. Tests run — per-test before/after (no-graphics, sequential `-P 1`, `SWFRECOMP_COMPILE_TIMEOUT=2400`)

Baselines are `ruffle-tests/tests/swfs/avm1/_results/results_graphics.json` at
`2973513c4` (read fresh, not copied from a brief) and, for `from_gnash`,
`wave0-trace-inventory.txt` + the s19 `w2-setprops` report. Raw logs:
`<scratchpad>/w2-coerce/{before,after}/`.

### 7a. Headline / new

| test | before | after |
|---|---|---|
| `regression/avm1_display_prop_coercion` (NEW) | 18/36 lines wrong | **PASS 36/36** |
| `avm1/set_property_values/swf5` | pass | pass |
| `avm1/set_property_values/swf6` | pass | pass |
| `avm1/set_property_values/swf7` | pass | pass |
| `avm1/set_property_values/swf4` | output_mismatch | output_mismatch, **actual byte-identical** |

### 7b. avm1 property / coordinate sweep — 27 tests, **zero status moves**

`pass` before and after: `stage_object_properties`, `stage_object_properties_swf6`,
`stage_object_properties_get_var`, `as_transformed_flag`, `movieclip_default_state`,
`clone_sprite_edittext`, `nan_scale`, `display_object_properties`, `getproperty`,
`getproperty_swf4`, `getproperty_swf5`, `focusrect_property_swf5`, `focusrect_swf5`,
`edittext_width_height`, `movieclip_getbounds`, `local_to_global`, `transform`,
`matrix`, `default_names`, `conflicting_instance_names`,
`button_properties_special_cases`, `textfield_properties`, plus the four
`set_property_values/*` rows above.

`movieclip_library_state_values`: `ruffle_matched` before → `ruffle_matched`
after (it is on `ruffle-tests/ignored_tests.txt:206`; unchanged, so no
`pass → ruffle_matched` drift).

`focusrect_property_swf5` and `focusrect_swf5` are the only coverage patch 4 has;
both still PASS.

### 7c. from_gnash — 7 tests, zero moves

| test | before | after |
|---|---|---|
| `actionscript.all/MovieClip-v5` | ruffle_matched | ruffle_matched |
| `actionscript.all/MovieClip-v6` | output_mismatch (901/936) | output_mismatch, **actual byte-identical** |
| `actionscript.all/MovieClip-v7` | output_mismatch (934/969) | output_mismatch, **actual byte-identical** |
| `actionscript.all/Color-v6` | pass | pass |
| `misc-swfc.all/swf4opcode` | pass | **pass** (s19's Flash-vs-Ruffle SWF4 choice is intact) |
| `misc-ming.all/matrix_test` | ruffle_matched | ruffle_matched |
| `misc-ming.all/place_object_test` | ruffle_matched | ruffle_matched |

The three failing rows are the strongest single signal: their **actual output is
byte-identical before and after**, so this patch moves no line on any test that
was already failing, in either direction.

### 7d. `regression` suite — **96/96 PASS, `vs prev: no changes`**

Run in one invocation so the runner's own `vs prev` diff (the only suite whose
`_results` baseline travels in git) is authoritative:

```
Total tests:     96
Pass:            96 (100.0%)
Fail:            0
Final diff vs previous results:
  [diff] pass: 96/96  |  vs prev: no changes
```

This is the strongest single non-regression signal available locally: 95
pre-existing hand-written behaviour locks (closures, the three watch arms,
cross-SWF-version switches, timeline / child-movie, AVM2 slots and rendering)
plus my new fixture, all green, with no status **and** no line-count movement
anywhere. Log: `<scratchpad>/w2-coerce/after/regression_suite.log`.

`ruffle-tests/tests/swfs/regression/_results/{results,results_previous}.json`
were rewritten by that run; I reverted them with `git checkout --`, so they are
not part of the delivery.

### 7e. Not run

* **Render canary / `--mode=graphics`.** Mode parity has been complete since
  s18 (`CLAUDE.md`), and this change is pure AVM1 runtime logic. But patch 3 is
  **pixel-relevant**: it can move a clip by up to 1 twip (0.05 px) for a
  fractional coordinate written through any of the four paths. That move is
  *toward* Ruffle, i.e. toward the image baseline, and image comparisons do not
  gate pass/fail. **Recommendation: CI `mode=graphics`, `categories=all`,
  `images=false`.** If the coordinator wants pixel evidence for patch 3, the
  cheap version is a canary A/B over `avm1/mask_with_drawing` +
  `from_shumway/doubleAndRegister` (the latter added to
  `render_canary_tests.txt` by s19 precisely for this change class).
* Per-patch isolation legs (see §2).

---

## 8. Refutations and corrections of record

1. **The brief's two function labels are swapped** (§3). Anyone reading
   `spvPropertyCoerceToNumber` as "SetMember" will edit the opcode path.
2. **"The SetMember path rejects ±Infinity" is false** — it *accepts* it and
   produces a positive sentinel where Ruffle produces a negative one (§3).
3. **The `:15568` comment was correct about its own function.** The thing to fix
   was its claim about *which* path `propertyCoerceToNumber` served.
4. **The `_alpha` `roundf` bug is threefold, not twofold** — B, C **and** D.
5. **Both of the brief's paths were wrong about `_x` quantization**, in different
   ways (`floor` vs quantize-on-read-by-`round`); Ruffle truncates on write.
   Oracle row: `mc._x = -10.53` → `-10.5`, ours was `-10.55` on every path.
6. **`set_property_values/swf4` is a different arc** and its `ruffle_matched`
   route is closed by a conflict with `swf4opcode` (§5).
7. **No disposition-doc entry is needed.** Every behaviour I changed is sourced
   from Ruffle (§4) and confirmed against the Ruffle exporter, so nothing here is
   a `RUFFLE_COMPAT_TWEAKS.md` "unclear, chosen to match Ruffle" case. I edited
   no disposition doc. Nothing needs adding to `ignored_tests.txt`.
   *If* the coordinator drops patch 3, no doc entry is needed either — the
   divergence simply stays open, and it should be re-listed as a lead.

---

## 9. New unclaimed leads

* **`actionSetMember`'s `_visible` arm still has its own object-`valueOf` ladder**
  that treats an object whose `valueOf` returns an object as `0` (false). Ruffle's
  `coerce_to_f64` gives NaN there → no-op. Deliberately left alone (it carries a
  "matches Flash Player" comment that predates me and no test pins it), but it is
  now the only display property in that function that does not use the one gate.
* **`actionSetProperty` case 6 does not sync `mc->cx_aa` / `mcSyncAlphaToDisplayObj` /
  the display-entry CT alpha**, while the SetMember and SetVariable `_alpha` arms
  all do. So `setProperty(mc, _alpha, v)` and `mc._alpha = v` leave the engine in
  different states for `Color.getTransform()` and for the renderer. One of the two
  is wrong; I did not touch it because it is a *state-sync* divergence, not a
  coercion one.
* **`_width`/`_height` write path** uses `floor(fabs(v)*20)/20` while the read
  path rounds — the same write/read asymmetry patch 3 closes for `_x`/`_y`.
  Ruffle truncates. Still unreachable by `set_property_values` (its `_level0` is
  empty); the fixture could be extended with a drawn shape.
* **`_focusrect` via a bare SetVariable has no test anywhere** (§2, patch 4). A
  hand-assembled SWF (the `regression/` suite already contains several) is the
  only way to cover it, since MTASC cannot emit a bare `_focusrect = 1`.
* **`_soundbuftime` / `_highquality` on the SetMember path** still use
  `coerceVarToNumber` (lenient) rather than the strict `spvCoerceToF64` that the
  opcode uses. Harmless today (both end in a NaN guard), but it is the last
  lenient-vs-strict split left in that function.
* **The pixel axis still has almost no SetProperty/SetMember coverage** — s19
  measured 1 image-comparison test out of 374 that emits `actionSetProperty`.
  A `regression/` fixture with `[image_comparisons]` writing `_x` at a fractional
  coordinate would give patch 3 its own pixel lock.
