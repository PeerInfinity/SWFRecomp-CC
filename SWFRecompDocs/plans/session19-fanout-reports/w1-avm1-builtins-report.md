# w1-avm1-builtins — wave-1 diagnosis (AVM1 builtin objects: avm1, from_gnash/actionscript.all, misc-ming.all)

Session 19, HEAD `254145a5b`. Read-only: no source edits, no commits.
All runs local, **no-graphics**, sequential (`-P 1`), `SWFRECOMP_COMPILE_TIMEOUT=2400`, `--diff --verbose`.
Logs + per-test actual outputs: `<scratchpad>/w1-avm1-builtins/{log_*.txt,act_*.txt,analyze.py}`.
Scratch probe SWFs (MTASC-built): `<scratchpad>/w1-avm1-builtins/probes/`.

---

## 0. Verdict table (lead with this)

| # | Lead | Verdict | Priced flips | Cost / blocker |
|---|---|---|---|---|
| **G1** | `avm1/new_class_prototype_getter` — `addProperty` on a function whose `own_props` is NULL silently returns `false` | **GO (small, proven)** | **+1 pass** | ~3 lines in `action.c` (lazily allocate `func->own_props` before the function-receiver builtin dispatch). Proven with an A/B probe: pre-creating `own_props` makes the test's exact expected output appear. |
| **G2** | `from_gnash/actionscript.all/array-v6/-v7/-v8` → `ruffle_matched` | **GO (medium)** | **+3 effective** | 4 mechanisms, **not** the 21/50/50-line diffs. Only **4 / 32 / 32** line indices are *ours-only* vs Ruffle. M2 (26 of the 32 on v7/v8) is a **one-flag-set defect I located exactly**; M1/M3/M4 (4 lines, shared with v6) still need diagnosis. |
| **G3** | `from_gnash/actionscript.all/MovieClip-v6/-v7` → `ruffle_matched` | **GO (medium)** | **+2 effective** | only **14** ours-only lines each, **11 of them one mechanism** (our run ends before the trailing `loadVariables`/`onData` + `onUnload` block). Plus 3 one-liners. MovieClip-v8 is NOT in this slice (41 ours-only). |
| **G4** | `avm1/set_property_values/swf5` + `swf6` + `swf7` | **GO (large) — the "unfixable float blocker" is REFUTED** | **+3 pass** | 123 identical diff lines per variant, all in `actionSetProperty` coercion + the `_x`/`_y` read quantizer. The blocker needs a **twips saturation at read time**, not `double` storage. Hot-path change ⇒ CI-gated. |
| N1 | `from_gnash/actionscript.all/TextField-v6/-v7/-v8` | **NO-GO** | 0 | 36 / 39 / 39 ours-only lines over ≥8 unrelated mechanisms. The ACCEPTED `restrict` diff is **not** the blocker (see §6). |
| N2 | `MovieClip-v8` | **NO-GO (this session)** | 0 | 41 ours-only: the 14 of G3 **plus** 27 SWF8-only lines (filters array identity/length, `transform`/`Matrix` `toString`, `getBounds` ±1, blendMode). |
| N3 | `avm1/globals_monkeypatch` | **NO-GO (arc) — re-sized upward** | 0 | upstream drift took it from 100 → **228** expected lines; 189 differ, ≥8 sub-mechanisms. `ruffle_matched` buys nothing (Ruffle is 7 lines off Flash). |
| N4 | `misc-ming.all/GradientFillTest` | **NO-GO — structurally unpromotable** | 0 | no `output.ruffle.txt` and `known_failure.ruffle_check = false` ⇒ `ruffle_matched` is impossible by construction. **98 of the 155 diff lines are lines we already PASS** (verdict matches, the echoed hex value differs) ⇒ only *exact* pixel identity with Flash can flip it. |
| N5 | `misc-ming.all/DrawingApiTest` | **HOLD (12+2)** | 0 now | our 14 diffs are **completely disjoint** from Ruffle's 14 ⇒ all 14 must land. 12 are `hitTest` shape precision (`DRAWING_API_HITTEST_PLAN`); 2 are a separate small bug: `delete this.onEnterFrame` returns **false**, so the handler is never removed and the line is emitted 3× instead of 1× (our output is 95 lines vs 93). |
| N6 | `misc-ming.all/NetStream-SquareTest` | **HOLD (24 lines, 3 mechanisms)** | 0 now | ours-only 24 of 125: (a) `NetStream.prototype` must own `bufferLength/bufferTime/time/bytesLoaded/bytesTotal` as accessors, (b) those accessors must coerce/reject junk writes (`stream.bufferTime = 20` must read back `2`; assigning a string must still read `number`), (c) `Video` must expose **no** `hitTest`/`getBounds`. Self-contained but 3 mechanisms for 1 test. |

---

## 1. G1 — `new_class_prototype_getter` — **GO, mechanism proven**

Upstream test added 2026-09-08 (ruffle `1e81117b4`, *"avm1: Don't call getters when accessing `C.prototype` during `new C()`"*). Expected 6 lines, we emit 5; the getter never fires.

**Mechanism.** `testCls.addProperty("prototype", getter, null)` on a *function* receiver goes through
`actionCallMethod`'s function-receiver arm (`SWFModernRuntime/src/actionmodern/action.c:69388-69498`), which resolves
`addProperty` on `Function.prototype → Object.prototype` and then calls

```c
ActionVar result = mfunc->advanced_func(app_context, args, num_args, registers, (void*) func->own_props);
```

`builtin_object_addProperty` (`action.c:4854`) starts with `if (this_obj == NULL || arg_count < 3) return ret;` —
and a plain `var f = function(){}` has **`own_props == NULL`** until something writes a property on it, so the call
returns `false` and installs nothing. Everything downstream is already correct: `actionGetMember` has the
`prototype`-getter arm (`action.c:55122-55133`) and `new` reads `prototype_obj` directly (matching Ruffle's
`callee.prototype()` = `get_data`, which ignores getters).

**A/B proof** (`<scratchpad>/w1-avm1-builtins/probes/ncpg_{a,b}`, MTASC, SWF8, same source except one line):

| probe | source difference | result |
|---|---|---|
| `ncpg_a` | none | `addProperty returned false`, then Flash-wrong output — byte-identical failure shape to the real test |
| `ncpg_b` | one extra `testCls["dummy"] = 1;` before the `addProperty` | **PASS** — `prototype getter called!` / `name by getter` / `constructor called!` / `stored name`, i.e. the real test's exact expected output |

**Patch scope (wave 2).** Lazily allocate `func->own_props` before the `advanced_func` call in that arm (the
precedent is `action.c:68729-68736`, the `Function.prototype.call/apply` thisArg path, which already does exactly
this). Blast radius: any builtin `Object.prototype` method invoked on a function receiver
(`watch`, `unwatch`, `hasOwnProperty`, `isPropertyEnumerable`, `addProperty`) — today they all silently no-op on a
fresh function. Canaries: `avm1/function_*`, `avm1/watch*`, `avm1/object_properties*`, and the `regression` suite.

---

## 2. G2 — `array-v6/-v7/-v8` → `ruffle_matched` — **GO, and s18's "unreachable" is REFUTED**

`ruffle_matched` promotion is an **index-subset** test, not an equality test
(`verify_output.py:3506-3514` + `:4481-4503`): our diff indices against Flash's `output.fpN.txt` must be a
**subset** of Ruffle's. s18 §N4 priced these off the raw missing-line counts (21/50/50) and concluded
`ruffle_matched` was unreachable "by a wide margin". Measured at HEAD (graded file `output.fp24.txt`,
selected by `resolve_expected_filename`'s highest-`player_options.version` rule):

| test | ours diff | Ruffle diff | **ours-only (the real bill)** |
|---|---|---|---|
| array-v6 | 21 | 34 | **4** |
| array-v7 | 50 | 32 | **32** |
| array-v8 | 50 | 32 | **32** |

Four mechanisms cover all of it:

| # | lines | symptom | status |
|---|---|---|---|
| **M2** | v7/v8: L137 + the 25-line block L190-L233 (**26 lines each**) | `typeof(testCmpThis) == 'undefined'` → we say `movieclip`; then the timeline variable `b` holds the number **5** from `array.as:455` onward, so every `pop/shift/splice/slice/concat` assertion on `b` fails | **ROOT-CAUSED, see below** |
| M1 | v6 L126; v7/v8 L124,125,128 | `gaparray.hasOwnProperty('4'/'16'/'2')` false on explicitly-set sparse indices | plan Phase 3. **Does not reproduce in isolation** (my probe: `hasOwnProperty('4')` on a hand-built gap array returns `true`) — context-dependent, needs the real fixture |
| M3 | v6 L143,144; v7/v8 L146,147 | a sort between `array.as:322` and `:324` **empties** `trysortarray` (length 4 → 0); Flash leaves it at `2,3,4,1` | undiagnosed; looks like "sort with a bogus/invalid comparator must leave the array untouched" |
| M4 | 1 line each (`array.as:1777`) | `ar.__proto__ = 8` ⇒ `typeof` must be `"number"`, we say `object` | also **does not reproduce in isolation** (my probe returns `number` for both an Array and an Object) — depends on the surrounding `constructor`/`__proto__`/`delete` sequence |

### M2 root cause (exact, and the code comments name the bug themselves)

`_invoke_sort_comparator` (`action.c:64374-64434`) exists — per its own header comment — so that a comparator's
`setVariableByName` writes land in a fresh local frame "instead of polluting the globals the test under sort expects
to keep (e.g. `randomComparator(a, b)` would otherwise clobber global `a` and `b`)". But only the **type-1** arm got
the flags:

```c
if (comparator->function_type == 2) {
    InvokeOpts opts = { .flags = INV_CAPTURED_SCOPE };                       // <-- no INV_LOCAL_SCOPE, no this bind
    result = invokeFunctionValue(app_context, comparator, NULL, args, 2, &opts);
} else {
    InvokeOpts opts = { .flags = INV_CAPTURED_SCOPE | INV_LOCAL_SCOPE |
                                 INV_BASE_CLIP | INV_BIND_THIS };
    result = invokeFunctionValue(app_context, comparator, &undef_this, args, 2, &opts);
}
```

The comment at `:64386-64390` even records that the type-2 arm "originally preserved the old bare call (flags = 0)"
and that only `INV_CAPTURED_SCOPE` was added later. So a **type-2** comparator gets **no local frame** and **no
`this` bind**.

Why that is exactly the v7/v8-vs-v6 split — verified in the generated code:

```
array-v6/RecompiledScripts: 64 × DefineFunction      (Ming emits function1 for SWF6)
array-v7/RecompiledScripts: 64 × DefineFunction2     (function2 for SWF7+)
```

and Ming's function2 bodies bind their parameters **by name**, not into registers
(`array-v7/RecompiledScripts/script_defs.c:1265-1300`, `func2_testCmp_12`):

```c
setVariableByName("arguments", &_args_var);
if (0 < arg_count) { setVariableByName("x", &args[0]); }
if (1 < arg_count) { setVariableByName("y", &args[1]); }
```

and `script_defs.c:1809` is literally `func2_randomComparator_19`, whose params bind `"a"` and `"b"`
(`:1832`, `:1839`) — the exact function the helper's own comment warns about. With no local frame those writes hit
the root timeline, so `_root.b` becomes a sorted element (5) and stays that way for the rest of the test; and with
no `this` bind the comparator sees the root MovieClip, which is `array.as:296`.

**Patch scope (wave 2):** give the type-2 arm `INV_LOCAL_SCOPE` (and `&undef_this` + `INV_BIND_THIS`, matching
Flash/Ruffle's "comparator is called as a plain function"). One flag-set edit. **Mandatory canaries:**
`regression/sort_comparator_captured_scope`, `regression/sort_comparator_type1_args` (both named in that comment),
the whole `regression` suite, plus `avm1/array_sort*`, `avm1/sort*`, `from_gnash/actionscript.all/array-v5`
(IGN but line-tracked) and `Function-v6/-v7/-v8`.

**Honest pricing.** M2 alone flips nothing (it clears 26 of 32 lines on v7/v8). The flip set is M1+M2+M3+M4:
**+3 effective** (`output_mismatch → ruffle_matched` on all three). M1/M3/M4 are 4 lines but 3 distinct
undiagnosed mechanisms, and two of them did not reproduce in isolated probes — budget real diagnosis time, not
"4 lines of work". A v6-only slice (M1+M3+M4, skipping M2) is **+1** and is the cheapest single flip if M2 turns
out to be risky.

---

## 3. G3 — `MovieClip-v6/-v7` → `ruffle_matched` — **GO; also refutes s18 §N4**

Graded file `output.fp23.txt`. Same subset arithmetic:

| test | ours diff | Ruffle diff | ours-only |
|---|---|---|---|
| MovieClip-v6 | 35 | 60 | **14** |
| MovieClip-v7 | 35 | 64 | **14** |
| MovieClip-v8 | 67 | 68 | 41 |

**11 of the 14 are one mechanism: our run stops early.** Our output is 921 lines against 936 expected (954/969 on
v7); everything from `MovieClip.as:660` onward is missing:

```
PASSED: this._target == '/hardref3/hardref3child' [./MovieClip.as:660]
_level0.hardref3.hardref3child.onUnload called
onData called, dataLoaded: 0
PASSED: arguments.length == 0 [./MovieClip.as:2207]
PASSED: _root.var2 == 'val2' [./MovieClip.as:2214]
PASSED: _root.var3 == 'val3\n' [./MovieClip.as:2215]
… (same block again with dataLoaded: 1) …
#total tests run: 927
```

The test dir ships **`vars.txt`** (`var2=val2&var3=val3\n`), so this is the `loadVariables`/`MovieClipLoader`
`onData` round trip plus the `hardref3child` `onUnload`: our `onData` handler never fires (twice), the unload
never traces, and the Dejagnu tail never prints. One coherent mechanism, 11 lines, on **both** v6 and v7 (and v8).

The other three are one-liners, identical on v6/v7/v8:

| line | expected | ours |
|---|---|---|
| `MovieClip.as:2097` | `retCaller == _root.meth` | `undefined` (empty on v6) — `arguments.caller` for an MC method |
| `MovieClip.as:2191` | `propinspect == 0` | `1` — one extra enumerable property on the inspected MC |
| `MovieClip.as:2590` | `mc.toString() == undefined` | `[object Object]` — `toString` on a removed/unloaded MC must be `undefined` |

**Pricing: +2 effective** (v6 + v7) for 4 mechanisms, one of which (the `onData` tail) carries 11 of the 14 lines
and is shared with v8. **v8 is not in the slice**: it needs 27 more lines across `filters` array identity and
length semantics, `transform`/`Matrix.toString() == undefined`, `getBounds` ±1 twips, `Transform` property
enumeration order (we also leak an `__mc__` property into `props.toString()`), and blendMode.

---

## 4. G4 — `set_property_values/swf5,6,7` — the brief's question answered, and the blocker refuted

### 4a. The brief's premise is wrong: swf6/swf7 are **not** ACCEPTED

`ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`, `FLASH_BUGS_REPLICATED.md`,
`ruffle-tests/ignored_tests.txt` and every per-suite `ignored_tests.txt` contain **no `set_property_values` entry at
all**. The wave-0 inventory's `ACC` flag on swf6/swf7 is a **false positive**: its name matcher matched the bare
words `swf6`/`swf7` occurring in unrelated recursion-test entries (`ACCEPTED_DIFFS.md:767`, `:803`). swf5, swf6 and
swf7 are in exactly the same disposition state (none), and the only doc that discusses them is
`avm1/_investigation/blocked/SET_PROPERTY_VALUES_PLAN.md` (Blocker 10).

### 4b. They are the same test, line for line

The three variants' mismatching **line-index sets are identical** (123 lines, `set(m5) ^ set(m6) == ∅`); the
expected files differ only in `_visible`'s `1/0` vs `true/false` rendering, and our actual tracks that correctly.
So there is no swf5-specific gap: it is one fix for three tests.

### 4c. The float blocker is **REFUTED** — it needs a twips saturation, not `double` storage

The plan and memory `set-property-values-float-blocker` say `setProperty(_x, ±Infinity)` must read back
`-107374182.4 = INT_MIN/20`, that `MovieClip.x` is `float` (~7 sig figs) so it reads back `-107374184`, and that
the only fix is widening the whole transform chain to `double` ("far out of scope"). That reasoning skips the
actual model: **Flash and Ruffle store `_x`/`_y` as S32 twips**, and Ruffle's own setter is

```rust
// ~/CC/ruffle core/src/avm1/object/stage_object.rs:333-345
let x = if x.is_infinite() { f64::NEG_INFINITY } else { x };
this.set_x(Twips::from_pixels(x));           // saturating cast → i32::MIN
```

Our read path is `round((double)mc->x * 20.0) / 20.0`, replicated at `action.c:45319`, `:47033` (`case 0/1` of
`actionGetProperty`), `:55497` and `:60061`. Add the S32 saturation that the twips model implies:

```
twips = round((double)mc->x * 20.0);  if (twips < INT32_MIN) twips = INT32_MIN;  else if (twips > INT32_MAX) twips = INT32_MAX;
value = twips / 20.0;
```

`float` holds the overflow sentinel `(float)(INT_MIN/20.0) = -107374184` exactly; `-107374184 * 20 = -2147483680`
clamps to `INT_MIN`, and `INT_MIN/20.0` is exactly `-107374182.4` in double. No storage widening, no renderer
change, ~4 call sites (or one shared helper). The setter side then routes `±Inf` (and any out-of-range product) to
that sentinel, matching x86 `cvttsd2si`'s indefinite-integer result that Flash exhibits.

### 4d. What the other 111 lines are (re-measured at HEAD; the plan's quirk map still holds)

Per-property mismatch counts for `swf5` (identical for 6/7), from `<scratchpad>/w1-avm1-builtins/spv5_bucket.txt`:

| property | lines | family |
|---|---|---|
| `_alpha` | 27 | 8.8 fixed-point must **truncate toward zero**, not `roundf` (`action.c:54429`); `±Inf → 0`; NaN → no-op |
| `_name` | 22 | must `toString`-coerce **any** type (we only accept `ACTION_STACK_VALUE_STRING`, case 13) |
| `_soundbuftime` | 17 | string strict-parse + `±Inf → INT_MIN` |
| `_highquality` | 11 | string strict-parse + NaN no-op |
| `_x`, `_y` | 8 + 8 | 4 are `"10x"` strict-parse; 12 are the ±Inf lines of §4c |
| `_xscale`, `_yscale` | 8 + 8 | strict-parse + `±Inf` stored as-is (`Infinity`/`-Infinity`) |
| `_rotation` | 8 | strict-parse + `±Inf → NaN` via fmod |
| `_visible` | 5 | not a no-op property: `NaN → false`, `±Inf → true` |
| `_focusrect` | 1 | strict-parse |

**Pricing: +3 pass.** Blast radius is narrower than the plan implies: `actionSetProperty` (`action.c:59122`) is the
**SetProperty opcode only** (emitted once, `SWFRecomp/src/action/action.cpp:835`), not the `mc._x = v` SetMember
path — so games and the bulk of the corpus are untouched; the read-side saturation is the shared part and only
changes values beyond ±107374182 px. Still a CI-gated change (the whole corpus's `setProperty()` users).

---

## 5. NO-GO rows, each with its completion mechanism

### N1 `TextField-v6/-v7/-v8`
36 / 39 / 39 ours-only lines. Distinct mechanisms visible in one pass: TextField↔variable binding back-propagation
chains (`TextField.as:754-772`), `tf.length` after `replaceSel`, `softref.getDepth()`, `textWidth`/`textHeight` under
`_xscale`/`_yscale` and `wordWrap` (we report 0), `createTextField` clips addressed as `_root[3]`,
`replaceText` + `Selection.getBeginIndex/getEndIndex` index arithmetic (8 lines), `_name`/`_target` after a rename,
a TextField-as-`this` object identity block (`tfmo`), and `TextField.as:1254`. **Completion mechanism:** the 13-phase
`incomplete/TEXTFIELD_VN_PLAN.md`, as an arc.

### N2 `MovieClip-v8` — see §3; needs G3 **plus** an SWF8 filters/transform arc.

### N3 `avm1/globals_monkeypatch` — upstream drift doubled it
Expected grew 100 → **228** lines (ruffle `0b4c47bfe`, `017ee8c9a`, `56e4fb9d3`, `3ee9acff9`, `ad7b6c124` —
"Always resolve `MovieClip` / `flash.geom.*` dynamically in built-ins"). We emit 144 lines, 39 match, 189 differ.
The new bulk is `flash.geom`: every builtin that mints a `Rectangle`/`Matrix`/`Transform`/`ColorTransform`/`Point`
must resolve it by walking `_global.flash.geom.X` **through user getters** (the expected output traces
`flash getter called!` / `geom getter called!` / `Rectangle getter called!` / `new MyRectangle(...) called!`) —
17 such chains. Plus the s18 surfaces (engine-minted prototypes via `_global.<Name>`, filters, attachMovie'd
clip/Button/TextField/Video class names, the "weird prototypes" prologue). `ruffle_matched` is worthless here:
Ruffle differs from Flash on **7** lines only (all `MyArray` vs `Array`). **Completion mechanism:** a dedicated
`_global`-indirection arc for engine-minted objects; explicitly not a wave-2 slice.

### N4 `GradientFillTest` — structurally unpromotable, and the diff is mostly cosmetic
`test.toml` has **no `known_failure = true`** (only `known_failure.ruffle_check = false`) and there is no
`output.ruffle.txt`, so `_test_is_known_failure` is false ⇒ `ruffle_matched` can never be awarded; only an exact
278/278 match counts. Of the 155 differing lines: **98 are lines where our verdict is already `PASSED`** (the test's
own "is near to" tolerance passes) and only the echoed hex value differs, 21 are raw pixel-dump lines, and **36 are
real tolerance failures**. So even a pixel-perfect-within-tolerance renderer leaves ~119 diff lines. It is a
render-exactness test, not an AVM1 test. (s18's refutation of `GRADIENTFILLTEST_PLAN`'s "low-bit/gamma" root cause
stands; I did not re-derive it.)

### N5 `DrawingApiTest` — HOLD
81/93 match; our 14 diffs are **disjoint** from Ruffle's 14 (the `getBounds` full-thickness RVF entry explains why:
we deliberately match Flash where Ruffle doesn't, and Ruffle matches Flash on the hitTests where we don't). All 14
must land: 12 `hitTest`-on-drawn-shape precision lines (`incomplete/DRAWING_API_HITTEST_PLAN.md`, 3 phases) **plus**
a separate 2-line bug — `delete this.onEnterFrame` returns **false**, the handler is never removed, and the test
prints `FAILED: delete this.onEnterFrame returned false` on each subsequent frame (our output is 95 lines vs 93).
That 2-line bug is independently cheap and is listed as an unclaimed lead.

### N6 `NetStream-SquareTest` — HOLD
91/216 match, 125 diffs, but only **24 ours-only**, in three clusters: (a) 5 lines —
`NetStream.prototype.hasOwnProperty('bufferLength'|'bufferTime'|'time'|'bytesLoaded'|'bytesTotal')` must be true
(the properties must be prototype accessors, not instance fields); (b) 17 lines — those accessors must coerce:
writing a string/bool/undefined must still read back `number`, and `stream.bufferTime = 20` must read back `2`
(clamp/validation); (c) 2 lines — a `Video` display object must expose **no** `hitTest`/`getBounds`. None of this is
the "NetStream timing" story in `incomplete/NETSTREAM_SQUARETEST_PLAN.md` — that plan's Phase 1/2/3 framing is
**not** what blocks promotion; the property surface is. Worth a re-write of that plan's premise.

---

## 6. Dispositions checked (rule 2)

Grepped every board test name against `avm1/_investigation/{ACCEPTED_DIFFS,RUFFLE_VS_FLASH_DIFFERENCES,RUFFLE_COMPAT_TWEAKS,FLASH_BUGS_REPLICATED}.md`,
`from_gnash/_investigation/*.md`, `ruffle-tests/ignored_tests.txt` and all per-suite ignore lists.

- **`set_property_values/swf5,6,7`** — no entry anywhere; the inventory's `ACC` flag is a substring false positive (§4a).
- **`TextField-v6/-v7/-v8`** — the ACCEPTED entry (`from_gnash/_investigation/ACCEPTED_DIFFS.md:441`) covers exactly
  2 lines per version (`tf.restrict = ""` → `null`, `TextField.as:550-551`). I verified those two lines are
  **also in Ruffle's diff set** (Ruffle's `output.fp13-17.ruffle.txt:264-265` is byte-identical to our actual), so
  the accepted diff does **not** block a `ruffle_matched` promotion. The blockers are the other 36-39 lines.
  Neither test is in any ignore list.
- **`array-v5`** is IGN/ACC; **array-v6/-v7/-v8 are not** (`from_gnash/actionscript.all/ignored_tests.txt` lists
  only `array-v5` among these).
- **`DrawingApiTest`** — RVF entry (`RUFFLE_VS_FLASH_DIFFERENCES.md:203`) is the `getBounds` stroke-expansion one and
  is already reflected in the current 81/93; it explains the disjointness, it is not a blocker to revisit.
- **rule 3** — `array-v*`, `MovieClip-v*`, `TextField-v*`, `globals_monkeypatch`, `DrawingApiTest`,
  `NetStream-SquareTest` are all upstream `known_failure = true` with per-fp `*.ruffle.txt` sidecars, so the
  reachable target is `ruffle_matched` and every fix above moves us **toward Flash's `output.txt`**, never toward
  Ruffle's output. No `pass → ruffle_matched` move is proposed anywhere in this report.
  `new_class_prototype_getter` and `set_property_values/*` have **no** sidecar ⇒ exact pass is the only target.

---

## 7. Refutations (the deliverable the brief asked for)

1. **"swf6/swf7 are ACCEPTED, swf5 is not"** — false. None of the three is dispositioned; the inventory flag is a
   substring artifact. And the three are line-index-identical, so there is no swf5-specific question at all.
2. **"`set_property_values/swf5-7` can never pass (float precision)"** (plan + `BLOCKER_SUMMARY.md` Blocker 10 +
   memory `set-property-values-float-blocker`) — refuted: the read-back is a **twips S32 saturation**, which `float`
   storage supports exactly. The doc, the blocker entry and the memory all need updating.
3. **"`ruffle_matched` is unreachable for `array-v*` / `MovieClip-v*`"** (s18 `w1-trace-avm1-report.md` §N4, which
   priced them from missing-line counts without running them) — refuted by measurement: promotion is an
   index-subset test and the bills are **4** (array-v6) and **14** (MovieClip-v6/-v7), not 21/35.
4. **`ARRAY_V6_V8_PLAN` Phase 3 ("sparse `hasOwnProperty`") and the `__proto__`-as-number line** do **not**
   reproduce in isolated probes — both return the correct answer on a hand-built fixture. Whatever the mechanism is,
   it is contextual; don't let a wave-2 agent price them as "one-line fixes".
5. **`NETSTREAM_SQUARETEST_PLAN`'s "NetStream timing" premise** is not what blocks that test; the promotion-blocking
   lines are all property-surface/coercion (§N6).
6. **`GradientFillTest` is not a tolerance problem** — 98 of its 155 diff lines are already-`PASSED` lines whose
   echoed value differs, and the test can never be `ruffle_matched` by construction (§N4).

---

## 8. New unclaimed leads

1. **Builtin `Object.prototype` methods silently no-op on a function with no `own_props`** (§1). `addProperty` is
   just the one the new test caught; `watch`, `unwatch`, `hasOwnProperty`, `isPropertyEnumerable` take the same
   `(void*) func->own_props` argument and get `NULL`. Blast radius unknown, likely > 1 test.
2. **Type-2 sort comparators run with no local frame and no `this` bind** (§2, M2). Beyond the gnash tests this
   means *any* SWF7+ content whose comparator parameters share a name with a timeline variable corrupts that
   variable — a real-content hazard, not just a test artifact.
3. **`delete this.onEnterFrame` returns `false` on a MovieClip** (§N5) and the handler keeps firing. 2 lines on
   `DrawingApiTest`, but it is a plain correctness bug in `Delete` on MC event handlers.
4. **`MovieClip.as:2207-2215` `loadVariables`/`onData` tail never runs** (§3) — 11 lines on each of
   MovieClip-v6/-v7/-v8, and a `vars.txt` fixture is already in the test dir. Whoever takes G3 owns it; if G3 is
   skipped this is still the single highest-line-count AVM1 gnash mechanism on the board.
5. **`props.toString()` on a `Transform` leaks an internal `__mc__` property** into AVM1 enumeration
   (`MovieClip-v8` L811). Internal bookkeeping visible to scripts — worth a grep for other `__`-prefixed internals
   on enumerable property lists.
6. **Our `NetStream` instance properties are plain fields, not prototype accessors** (§N6, cluster a) — the same
   shape as several other "prototype must own it" gaps; may generalize to `Video`, `Sound`, `NetConnection`.

---

## 9. What I ran

| test | dir | mode | result |
|---|---|---|---|
| `new_class_prototype_getter` | `avm1` | no-gfx | mismatch 6 exp / 5 act / 1 match |
| `set_property_values/swf5`, `/swf6` | `avm1` | no-gfx | mismatch 1620/1743 each, identical index sets |
| `globals_monkeypatch` | `avm1` | no-gfx | mismatch 39/228, 144 actual |
| `array-v6`, `-v7`, `-v8` | `from_gnash/actionscript.all` | no-gfx | mismatch 623/644, 604/654, 604/654 |
| `MovieClip-v6`, `-v7`, `-v8` | `from_gnash/actionscript.all` | no-gfx | mismatch 901/936, 934/969, 1020/1087 |
| `TextField-v6`, `-v7`, `-v8` | `from_gnash/actionscript.all` | no-gfx | mismatch 467/545, 476/570, 478/571 |
| `DrawingApiTest` | `from_gnash/misc-ming.all` | no-gfx | mismatch 81/93 (95 actual; 14 differing indices over the 95-line union) |
| `GradientFillTest` | `from_gnash/misc-ming.all` | no-gfx | mismatch 123/278 |
| `NetStream-SquareTest` | `from_gnash/misc-ming.all` | no-gfx | mismatch 91/216 (201 actual) |
| probes `ncpg_a`/`ncpg_b` | scratch | no-gfx | mismatch / **PASS** (the G1 A/B) |
| probes `sort6`/`sort7` | scratch | no-gfx | comparator `this` = movieclip in both (MTASC emits register params ⇒ no name leak; consistent with M2) |
| probe `arrprobe` | scratch | no-gfx | sparse `hasOwnProperty` and `__proto__ = 8` both already correct in isolation (refutation 4) |

Every per-test line count matches the wave-0 baseline inventory exactly, so no-graphics mode parity holds for this
family and no upstream drift was found in it (the only drift on my board is `globals_monkeypatch`'s expected file,
§N3 — a changed expected total, i.e. upstream movement, not a regression).
