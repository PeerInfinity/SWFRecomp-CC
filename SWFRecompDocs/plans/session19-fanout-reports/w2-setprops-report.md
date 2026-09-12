# w2-setprops — `set_property_values/swf5+6+7`: GO, +3 pass. Both parked reasons refuted.

**Branched from** `2a63dccc5` (master tip at start of work; the brief's `e36bca73e` had already moved).
**Worktree**: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a91140e73fa864ceb`
**Patch**: `SWFRecompDocs/plans/session19-fanout-reports/w2-setprops.patch` — **two tracked files**:
`SWFModernRuntime/src/actionmodern/action.c` (the fix) and `ruffle-tests/render_canary_tests.txt`
(one covering canary member added; see §5c — the standing set was blind to this change class).
**New files**: none.
**Functions touched** (for sibling de-confliction with `w2-avm1-sort` / `w2-avm1-events`, which also edit `action.c`):
`actionSetProperty` (cases 0, 1, 6, 7, 13, 16, 17, 18 + the value-coercion prologue), `actionGetProperty`
(cases 0/1 read expression only), plus three new `static` helpers next to `clampToI32`
(`spvTwipsQuantizePixels`, `spvCoerceToF64`, `spvPropertyCoerceToNumber`) and the macro
`SPV_COORD_SENTINEL`. Six other `_x`/`_y` READ expressions changed to call the new quantizer
(`actionGetVariable`'s `_x`/`_y`, `actionGetMember`-ish name path, `getMCBuiltinProperty`). No
existing symbol renamed; `propertyCoerceToNumber` (the SetMember-by-name path that
`w2-avm1-events` may touch) is deliberately **left untouched**.

---

## 1. Verdict first

| test | before | after |
|---|---|---|
| `avm1/set_property_values/swf5` | `output_mismatch` 1620/1743 | **PASS** (1743/1743) |
| `avm1/set_property_values/swf6` | `output_mismatch` 1620/1743 | **PASS** (1743/1743) |
| `avm1/set_property_values/swf7` | `output_mismatch` 1620/1743 | **PASS** (1743/1743) |
| `avm1/set_property_values/swf4` | `output_mismatch` 349/1571 | `output_mismatch` 349/1571 (unchanged, as briefed) |

**+3 effective.** All 123 mismatching lines per variant are gone; there is no residue and nothing
to add to a disposition doc for this family.

---

## 2. The two refutations, re-verified independently (this was the brief's first ask)

### 2a. "swf6/swf7 are ACCEPTED" — **CONFIRMED FALSE** (the w1 agent is right)

`grep -n set_property` over `ruffle-tests/ignored_tests.txt`, every per-suite `ignored_tests.txt`
(`avm2`, `from_avmplus`, `from_shumway`), and all four AVM1 disposition docs
(`ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`,
`FLASH_BUGS_REPLICATED.md`) returns **nothing** for any variant. `swf5/test.toml` carries no
`known_failure` and there is no `output.ruffle.txt`, so a full PASS was always the only promotion
route — and was always reachable.

### 2b. "float storage of `mc->x` makes `-107374182.4` unreachable" — **CONFIRMED FALSE**

Verified two ways before touching code.

*Arithmetically* (`<scratchpad>/w2-setprops/f.c`, gcc -O2):

```
INT_MIN/20.0        = -107374182.4
(float) that        = -107374184        (exact: 107374184/8 = 13421773, ulp is 8 there)
round(f * 20.0)     = -2147483680
saturate to i32     = -2147483648
/ 20.0              = -107374182.4      <-- exact, in double
```

*Against the oracle* (`~/CC/ruffle`, pulled to `0631814db`): Flash/Ruffle do not store pixels at
all — `_x`/`_y` are S32 twips.
`core/src/avm1/object/stage_object.rs:333-345` maps **any** infinity to `-Infinity` and then calls
`Twips::from_pixels`, and `swf/src/types/twips.rs:102` is `(pixels * 20.0) as i32` — a Rust
float→int cast, i.e. **saturating**, so `+Inf` and `-Inf` both land on `i32::MIN`. The value
`-107374182.4` is not a 9-significant-figure float at all; it is `i32::MIN / 20` reconstructed from
an integer. The blocker was a category error: it priced *pixel* precision for a value that only
ever exists as *twips*.

Consequence: the fix is a **saturation in the read quantizer**, plus writing the sentinel on the
setter side. `float` storage is untouched, the transform chain is untouched, the renderer is
untouched. `SET_PROPERTY_VALUES_PLAN.md`'s "far out of scope" `double`-widening arc is dead.

Both refutations hold, so I implemented.

---

## 3. Mechanism — what actually changed (all against Ruffle source, not guesswork)

### 3a. Read side (shared, 8 call sites)

`spvTwipsQuantizePixels(px)` replaces the bare `round(px*20.0)/20.0` at every `_x`/`_y` read:
`actionGetVariable`'s `_x`/`_y`, `actionGetProperty` cases 0/1, the `dx`/`dy` pair in the
SetMember-adjacent reader, and `getMCBuiltinProperty`'s `_x`/`_y`. It clamps the twips product to
`[INT32_MIN, INT32_MAX]` before dividing, and passes NaN through unchanged (Ruffle's twips can
never hold NaN, and mapping it would have been a gratuitous behaviour change). **Only values
beyond ±107374182.4 px move** — that is the entire observable blast radius of the shared half.

### 3b. Coercion prologue in `actionSetProperty` (SetProperty opcode only)

Old: an ad-hoc per-type ladder with `!isfinite → no-op` for props 0-10/12, a **prefix** `strtod`
for strings, and plain `atof` for everything else (so `_highquality`/`_soundbuftime`/`_focusrect`
read `"z10"` as 0 instead of no-op).
New: `spvPropertyCoerceToNumber` = Ruffle's `property_coerce_to_number` (stage_object.rs:701)
exactly — undefined/null no-op, **NaN** no-op, and **±Infinity flows through** to the setter;
strings go through the existing SWF-version-aware **strict** parser `varToDoubleSWF`
(= `parse_float_impl(strict)` for SWF5+, so `"10x"` is NaN, not 10). The same gate now also covers
the f64 properties 16/18/20/21, matching each Ruffle setter's own null/undefined + NaN guard.

### 3c. Per-property infinity handling (this is the "quirk map", and it is all Ruffle-sourced)

| prop | Ruffle | ours now |
|---|---|---|
| `_x` / `_y` | `is_infinite → -Infinity`, then saturating `from_pixels` | store `SPV_COORD_SENTINEL` = `(float)(INT32_MIN/20.0)`; read side recovers `-107374182.4` |
| `_xscale` / `_yscale` | stored raw | `inf` stored as-is → reads back `Infinity` / `-Infinity` |
| `_rotation` | `degrees %= 360.0` → NaN | `normalizeRotation` already `fmodf`s → NaN (only the gate had to let it through) |
| `_alpha` | `is_infinite → 0.0`, then `Fixed8::from_f64` = `(n*256.0) as i16` | `inf → 0`; **truncating** cast, clamped to i16 range |
| `_visible` | `n != 0.0` | `dnum != 0.0` (so `±Inf` is visible; NaN can no longer reach it) |
| `_highquality` | `>1.5 → BEST`, `==0 → LOW`, else HIGH | unchanged helper, now reached by `±Inf` |
| `_soundbuftime` | `clamp_to_i32()` → `INT32_MIN` for out-of-range **and** infinities | dropped the `isfinite` gate that swallowed them |
| `_focusrect` | stage branch: Object→0, else `coerce_to_f64`, NaN→ignore | strict parse instead of prefix `strtod` |
| `_name` | `coerce_to_string` of **any** value, with `Number(NaN) → 0` in SWF7+ | full `varToStringBuf` coercion + the SWF<7 `undefined → ""` rule + the SWF7 NaN quirk |

Two of these were the largest line buckets and neither is what the plan said:

* **`_alpha` (27 lines)** — `roundf` → truncate-toward-zero. `Fixed8::from_f64` is a Rust
  `as i16`, which truncates. `roundf` made every value one 1/256 step too large
  (`-5 → -5.078125` instead of Flash's `-4.6875`) and, because the test resets to `1` between
  probes, **poisoned every following block's read2 baseline** (`1.171875` where Flash has
  `0.78125`). That is why one wrong rounding mode cost 27 lines.
* **`_name` (22 lines)** — we only assigned when the value was already a `string`, so each numeric /
  boolean / undefined / null block left the *previous* block's name in place (hence the `[type Object]`
  ghosts in our actual). Ruffle coerces any type.

The SWF7-only quirk `Number(NaN) → 0` for `_name` (`stage_object.rs:526`) is why `swf6` and `swf7`
expected outputs differ at exactly two lines; it is implemented, and `swf7` passes.

---

## 4. Scope discipline — what I deliberately did NOT change

* **`propertyCoerceToNumber` (action.c:15410) is untouched.** That is the `SetMember`-by-name path
  (`mc._x = v`, `_alpha = v` in a `with` block). It rejects `±Infinity` as well as NaN, which is
  **wrong** against Ruffle — but fixing it widens the blast radius from "the SetProperty opcode"
  to "every property write in every game". Same for that path's `_alpha` `roundf`. Listed as an
  unclaimed lead in §7 with the exact divergence.
* `_width` / `_height` (cases 8/9) now let `±Inf` reach `mcSetEffectiveWidth`, which is
  Ruffle-faithful (`set_width` takes the infinity too) and produces an infinite scale rather than a
  crash. The test's `_level0` has no content so all 24 `_width`/`_height` lines were, and remain,
  `0`.
* No renderer, recompiler, header, or build-system change. No new file.

---

## 5. Tests run (all `--mode=no-graphics`, sequential, `SWFRECOMP_COMPILE_TIMEOUT=2400`)

### 5a. Headlines — see §1. Diff buckets before the patch (reproduced independently of w1, script at
`<scratchpad>/w2-setprops/bucket.py`): `_alpha` 27, `_name` 22, `_soundbuftime` 17,
`_highquality` 11, `_x` 8, `_y` 8, `_xscale` 8, `_yscale` 8, `_rotation` 8, `_visible` 5,
`_focusrect` 1 = **123**, identical index sets across swf5/6/7 — matching w1's count exactly.
After: 0.

### 5b. Sweep — **51 tests, ZERO moves**

Raw rows: `<scratchpad>/w2-setprops/sweep_results.txt`, `sweep2_results.txt`, `reg.log`.

**`regression` suite, all 92 tests** (`--tests-dir=ruffle-tests/tests/swfs/regression --recompile`):
`pass: 92/92 | vs prev: no changes`. This is the strongest single signal in the sweep — it is the
only suite whose `_results` baseline travels in git, so the runner's own
`vs prev` diff is authoritative, and it reports no status and no line-count movement anywhere.

**`avm1`, 36 property / coordinate tests** — every one was `pass` in the baseline
`results_graphics.json` and every one still passes. Directly in the blast radius:
`focusrect_property_swf5` / `_swf6` / `_swf7`, `focusrect_swf5`, `focusrect_swf6`,
`focusrect_focuslost` (the `_focusrect` setter I rewrote), `getproperty`, `getproperty_swf4`,
`getproperty_swf5`, `stage_object_properties`, `stage_object_properties_get_var`,
`stage_object_properties_swf6`, `display_object_properties`, `stage_property_representation`,
`button_properties_special_cases`, `textfield_properties`, `nan_scale` (NaN coercion),
`default_names`, `movieclip_name_from_timeline`, `conflicting_instance_names` (the `_name`
setter), `local_to_global`, `transform`, `matrix`, `as_transformed_flag`,
`mouse_pos_with_scale_factor`, `movieclip_getbounds`, `movieclip_hittest`,
`movieclip_depth_methods`, `edittext_width_height`, `edittext_scroll`, `add_property`,
`object_properties`, `array_properties`, `prototype_properties`, `tab_ordering_properties`,
`init_array_invalid`.

**`from_gnash`, 9 geometry / property tests**: `misc-ming.all/matrix_test` RUFFLE_MATCHED,
`misc-ming.all/place_object_test` RUFFLE_MATCHED, `misc-ming.all/PlaceObject2Test` PASS,
`misc-ming.all/ButtonPropertiesTest` RUFFLE_MATCHED, `actionscript.all/MovieClip-v5`
RUFFLE_MATCHED, `actionscript.all/Global-v5` PASS, `actionscript.all/Global-v6` RUFFLE_MATCHED —
all seven absent from the wave-0 failing inventory, i.e. effective before and effective after.
`MovieClip-v6` and `MovieClip-v7` are `output_mismatch` **at baseline**
(`wave0-trace-inventory.txt:72-73`) and were re-run with `--json` to read exact counts:

| test | baseline (wave-0 inventory) | after |
|---|---|---|
| `from_gnash/actionscript.all/MovieClip-v6` | 901/936, act=921 | **901/936, act=921** |
| `from_gnash/actionscript.all/MovieClip-v7` | 934/969, act=954 | **934/969, act=954** |

Byte-identical, so the two AVM1 property mega-tests are unmoved.

**`from_shumway/avm1`, 8 tests**: `depth`, `target`, `operations` PASS;
`property-paths/property-paths-6`, `property-paths/property-paths-7`,
`propertycase/propertycase`, `propertycase/propertycase-preserving-6`,
`propertycase/propertycase-preserving-7` PASS. (My first pass named the *parent* directories
`property-paths` and `propertycase`, which have no `test.swf`, and got `RECOMP_FAIL` — a
test-name artifact of mine, not a result. Re-run against the five leaf names: all PASS.)

### 5c. Render canary — **22/22 IDENTICAL**, and the standing set was BLIND to this change class

Two A/B captures (`capture after` → `git apply -R` → `capture before` → re-apply → `compare`;
never `git stash`), local Dawn, `-P 1`, md5 bar.

**Run 1 — the four standing members that could plausibly see it**
(`avm1/focusrect_swf5` 12 cmps, `avm1/color`, `avm1/mask_with_drawing`,
`from_shumway/timeline/timeline_as2_5` 7 cmps):

```
21 comparisons   IDENTICAL 21   DIFFERS 0   APPEARED 0  VANISHED 0  NO_RENDER 0
TRACE STATUS CHANGES: (none)      IMAGE STATUS CHANGES: (none)
```

**Coverage audit (the brief's "audit the canary against YOUR change class") — and it failed.**
Grepping the built `RecompiledScripts` of those four members for the opcodes this patch actually
changes gives `actionSetProperty = 0` and `actionGetProperty = 0` in **all four**. Their property
writes are all SetMember-form, which this patch does not touch. So the 21/21 IDENTICAL above
proves only that the shared `_x`/`_y` read-quantizer helper is pixel-neutral — it is **not**
evidence about the setter rewrite.

Widening the audit to the whole corpus (`<scratchpad>/w2-setprops/coverage.py`): of **374**
tests carrying `[image_comparisons]`, exactly **one** emits `actionSetProperty` —
`from_shumway/doubleAndRegister` (`setProperty(_x, 200)`, tolerance 0, 1 comparison). It is the
only pixel-axis coverage the SetProperty opcode has anywhere. (Lower bound: the audit can only
read tests that have already been built locally.)

**Run 2 — that covering member, A/B:**

```
1 comparison    IDENTICAL 1    DIFFERS 0
image verdict: PASS at tolerance 0 on BOTH legs
```

**Canary set change (in the patch):** `from_shumway/doubleAndRegister` added to
`ruffle-tests/render_canary_tests.txt` as a Tier-1 member, with the audit recorded in the comment,
so the next agent who touches `actionSetProperty` is not blind the way I was.

**Honest limit of the canary result.** No corpus image test writes `_alpha`, `_visible`,
`_rotation` or the scales through the SetProperty *opcode*, so the pixel axis has no coverage of
the `_alpha` Fixed8 rounding-mode change. What bounds it instead: the change moves the stored
Fixed8 multiplier by at most one 1/256 step, and it moves it **onto** `Fixed8::from_f64`, which is
what Ruffle — and therefore the CI image baseline — computes. Any pixel move would be toward the
golden. See risk 2.

---

## 6. Housekeeping the coordinator needs (LIST ONLY — I edited no disposition doc)

Nothing needs to be *added* to a disposition doc or an ignore list. Four **stale "unpromotable"
claims** should be retracted:

1. `ruffle-tests/tests/swfs/avm1/_investigation/blocked/SET_PROPERTY_VALUES_PLAN.md` — the whole
   "The hard blocker (swf5/6/7): float precision on `_x`/`_y` ← Infinity" section is wrong
   (§2b above). The file should move out of `blocked/` and be rewritten as a closed entry, or
   deleted with a pointer to this report. Its quirk map is also partly stale: the string
   strict-parse and `_focusrect` sub-fixes had already landed, and its `_alpha` line-count (54)
   and root cause ("`roundf` → truncating cast" is right, but it attributes 54 lines) no longer
   match the corpus (27).
2. `ruffle-tests/tests/swfs/avm1/_investigation/NEW_UPSTREAM_AVM1_TRIAGE.md:102-104` — the three
   **BLOCKED / "Unpromotable"** rows for swf5/6/7, and line 116's
   "`set_property_values/swf5-7` — **BLOCKED/unpromotable** … Don't re-investigate."
   That last sentence is what kept the family parked for three sessions; it should go.
3. `ruffle-tests/tests/swfs/avm1/_investigation/BLOCKER_SUMMARY.md:13-22` (the
   `set_property_values/swf{5,6,7}` blocker entry) and `:258` (the summary-table row
   `SET_PROPERTY_VALUES_PLAN | 4 | 0/4 promotable`, now `3/4`).
4. Memory `set-property-values-float-blocker` — the mechanism claim is wrong and it is cited by
   the brief; it should be rewritten as "`_x`/`_y` are S32 twips; saturate the read quantizer"
   (or replaced by a pointer to this report).

`FAILING_TESTS_BY_FEATURE{,_FILTERED}.md` will self-correct on the next generation.
`ruffle-tests/ignored_tests.txt` needs **no** change (the family was never in it — correctly).

---

## 7. Risks

1. **Highest-blast-radius item is the read quantizer**, and it is also the safest: it only moves
   values outside ±107374182.4 px, which no real coordinate reaches. Sweep + canary below.
2. **`_alpha` truncation is a pixel-visible change** for SWF4/5-era content that sets `_alpha`
   through the SetProperty *opcode* (implicit-`this` `_alpha = n` in a frame script). It changes the
   Fixed8 multiplier by at most one 1/256 step, toward Flash/Ruffle. A canary DIFFERS here would be
   the fix working, not a regression — read it with that prior.
3. **Strict string parse is a behaviour change for sloppy content**: `setProperty(_x, "10px")` used
   to move the clip to 10 and is now a no-op. That is what Flash and Ruffle do (SWF5+ strict
   `parse_float_impl`), and the SetMember path has done the strict thing for a while, so the two
   paths are now *less* divergent, not more.
4. `±Inf` now reaches `mcSetEffectiveWidth`/`Height`, producing an infinite scale instead of a
   no-op. Ruffle-faithful, but it is the one place where an infinity can now propagate into a
   transform. No corpus test exercises it.
5. CI should run **`mode=graphics`, `categories=all`** — the change is shared AVM1 runtime, not
   no-graphics-only. `images=false` (the `_alpha` question is answered by the local canary A/B,
   not by a baseline republish).

---

## 8. New unclaimed leads

* **`propertyCoerceToNumber` rejects `±Infinity`** (action.c:15410), so the SetMember path
  (`mc._x = 1/0`, `_alpha = 1/0`, `_visible = 1/0`, `_rotation = 1/0`) no-ops where Flash/Ruffle
  set the twips sentinel / 0 / true / NaN. Same file, same mechanism as this patch, ~10 lines —
  but it is the hot path for every game, so it wants its own CI cycle and its own regression
  fixture. There is **no corpus test** covering it today (which is why it survived), so the lead
  comes with "write the fixture from the Ruffle exporter first".
* **SetMember `_alpha` still uses `roundf`** (action.c:~45951) — same Fixed8 truncation bug as
  case 6, same reasoning, same blast-radius caveat. The two paths now disagree by one 1/256 step;
  that disagreement is itself a latent divergence-harness signal.
* **`_width`/`_height` write path uses `floor(fabs(v)*20)/20` while the read path rounds** — the
  same "quantize on write vs quantize on read" asymmetry this brief exposed for `_x`/`_y`. Ruffle
  truncates on write and never rounds on read. Not reachable by `set_property_values` (its
  `_level0` is empty), so it needs a purpose-built fixture.
* **The pixel axis has almost no coverage of the SetProperty opcode**: 1 test out of 374
  image-comparison tests in the entire corpus (§5c). If anyone plans further work on
  `actionSetProperty`'s numeric setters, the honest prerequisite is a `regression/` fixture with
  `[image_comparisons]` that writes `_alpha` / `_visible` / `_rotation` through the opcode, with
  the expected PNG taken from the Ruffle exporter. Cheap to build, and it closes a real hole.
* `set_property_values/swf4` (349/1571) is untouched and remains the separate SWF4
  property-*addressing* gap; it has `output.ruffle.txt`, so `ruffle_matched` is its cheap route,
  not a full PASS.
