# w2-setprops-2 — `from_gnash/misc-swfc.all/swf4opcode` `pass → ruffle_matched`: MINE, fixed, no trade-off

**Verdict: it was my commit `ad66b9c74`, it is a one-token fix, and the three
`set_property_values` flips are unaffected. Nothing is traded.**

**Patch**: `SWFRecompDocs/plans/session19-fanout-reports/w2-setprops-2-swf4fix.patch`
(one file, `SWFModernRuntime/src/actionmodern/action.c`; one condition + a comment block).
Built on **current master `8072df940`**. New files: none.

---

## 1. Culprit confirmed by A/B — `c87cd20f9` eliminated

Worktree at `8072df940`, `from_gnash/misc-swfc.all/swf4opcode`:

| tree | result |
|---|---|
| current master `8072df940` | `RUFFLE_MATCHED` (the regression, reproduced) |
| master **minus** `ad66b9c74`'s `action.c` diff | **`PASS`** |
| master, my patch split: **read-quantizer half only** | `PASS` |
| master, my patch split: **`actionSetProperty` half only** | `RUFFLE_MATCHED` |

So it is mine, and specifically the `actionSetProperty` coercion rewrite — not the twips read
quantizer. `c87cd20f9` and `8072df940` are ruled out: reverting only my hunks on top of them
restores `PASS`.

## 2. Correction to the diagnosis in the request

The request read the *disposition* of the test (`output.txt` vs `output.ruffle.txt`) rather than
our actual output, and that over-states the damage. Diffing **our** actual against Flash's
`output.txt` gives **7 differing lines, not 13**:

```
/mc1.x  /mc1.y  /mc1.xscale  /mc1.yscale  /mc1.alpha  /mc1.visible  /mc1.rotation
```

all reading `0`. The colon forms — `/mc1:_xscale`, `/mc1:_yscale`, `/mc1:_alpha`,
`/mc1:_visible` — **still match Flash** (`undefined`); we never regressed those. The SWF4
dot-vs-colon name mapping was never broken.

## 3. Mechanism — one line of SWF4 string coercion

Instrumented `actionSetProperty` (printf to **stdout**; note `verify_output.py` discards the
runtime's *stderr*, which is why a first stderr probe showed zero calls and nearly sent me down a
"the opcode is never reached" blind alley). The interleaved trace at `swf4opcode.sc:239`:

```
SPVDBG tgt=/mc1 idx=0 type=0 str='100'          dnum=100
SPVDBG tgt=/mc1 idx=0 type=0 str='not a number' dnum=0        <-- should not have set anything
FAILED: expected: 100 obtained: 0 [swf4opcode.sc:239]
```

`setProperty("/mc1", _x, "not a number")` in a **SWF4** movie:

* **Flash** — the string is not a number, the set is abandoned, `_x` keeps `100`.
* **Ruffle** — `string_to_f64` runs `parse_float_impl` in *non-strict* mode for SWF<5 and then
  folds the NaN to **`0.0`** (`core/src/avm1/value.rs:970`). `property_coerce_to_number` sees a
  non-NaN number and stores `0`. This is why the test is `known_failure = true` and carries an
  `output.ruffle.txt`.
* **Us, before `ad66b9c74`** — `strtod` prefix parse with "no digits consumed ⇒ no-op": matched
  Flash by construction.
* **Us, after `ad66b9c74`** — I routed *all* strings through `varToDoubleSWF(..., g_swf_version)`
  to get the SWF5+ strict parse that `set_property_values/swf5-7` needs. For SWF4 that same
  helper applies Ruffle's non-strict NaN→0 fold, so an unparseable string became a real `0`.

I imported Ruffle's SWF4 rule together with its SWF5+ rule, and the SWF4 half is Ruffle being
wrong about Flash.

**Fix** (`spvCoerceToF64`): use the SWF-version-aware parser for **SWF5+ only**; for SWF<5 fall
through to `coerceVarToNumber`, whose string branch is exactly the old prefix-`strtod`-with-NaN
behaviour.

```c
-	if (value->type == ACTION_STACK_VALUE_STRING)
+	if (value->type == ACTION_STACK_VALUE_STRING && g_swf_version >= 5)
 		return varToDoubleSWF(app_context, value, g_swf_version);
 	return coerceVarToNumber(app_context, value);
```

SWF4 still *prefix*-parses (`"10x"` is 10 there); only SWF5+ makes it NaN. The two rules were
never in conflict — I had simply conflated them.

## 4. Ledger (all runs on `8072df940` + this patch, no-graphics, sequential)

| test | before my work | after `ad66b9c74` (the regression) | **with this fix** |
|---|---|---|---|
| `from_gnash/misc-swfc.all/swf4opcode` | `pass` | `ruffle_matched` | **`pass`** |
| `avm1/set_property_values/swf5` | `output_mismatch` 1620/1743 | `pass` | **`pass` 1743/1743** |
| `avm1/set_property_values/swf6` | `output_mismatch` 1620/1743 | `pass` | **`pass` 1743/1743** |
| `avm1/set_property_values/swf7` | `output_mismatch` 1620/1743 | `pass` | **`pass` 1743/1743** |
| `avm1/set_property_values/swf4` | `output_mismatch` | `output_mismatch` | **`output_mismatch`** (see §5) |

**No trade-off: all four requested rows plus `swf4opcode` are simultaneously at their best
state.** The two goals were never mutually exclusive.

## 5. `set_property_values/swf4`'s line count — read it carefully

Its status never changes (`output_mismatch`, 0 effective, `known_failure` with an
`output.ruffle.txt`), but the positional `matching_lines` number moves and is easy to misread:

* wave-0 baseline (`627830f2a`): **349**
* my patch measured at `2a63dccc5`: **349**
* current master `8072df940`, this fix **reverted**: **345**
* current master `8072df940`, this fix **applied**: **346**

So this fix is **+1**, and the 349 → 345 drift happened between `2a63dccc5` and `8072df940` —
i.e. in `c87cd20f9` / `8072df940`, not in my work. Flagging it as someone else's line-metric
drift on a KF test, not as an alarm.

The metric itself is nearly meaningless here (1743 actual vs 1571 expected lines — the streams
are misaligned, and this fix changes 100 lines of which 22 become correct and 21 become
incorrect *positionally*). The content check is the one that matters, and it is unambiguous —
`setProperty(_x, "abc")` in SWF4:

```
Flash output.txt : 0 / 1        (reset value survives = no-op)
ours, with fix   : 0 / 1        <-- matches Flash
ours, without    : 0 / 0        <-- Ruffle's answer
```

## 6. Sweep (19 SWF4-surface tests + 11 property tests, zero moves)

* `avm1` SWF4 family, all PASS: `add_swf4`, `divide_swf4`, `equals_swf4`, `equals_swf4_alt`,
  `lessthan_swf4`, `lessthan_swf4_alt`, `logical_ops_swf4`, `swf4_actions_bool`,
  `swf4_actions_coercion_order`, `swf4_bool`, `swf4_function_calls`, `swf4_vars`,
  `getproperty_swf4`.
* `from_gnash/misc-swfc.all` (the suite the regression came from): `opcode_guard_test2`,
  `stackscope`, `submoviegetvar`, `hello` PASS. `action_execution_order_test10` and
  `movieclip_destruction_test1` are `ruffle_matched` — **not** a hidden regression: both are
  `known_failure = true` with an `output.ruffle.txt` and emit **zero** `actionSetProperty` calls,
  so `ruffle_matched` is their baseline state and this change cannot reach them.
  `matrix_accuracy_test1` is `output_mismatch`, which is its wave-0 baseline
  (`wave0-trace-inventory.txt:98`, 10/18, flagged `IGN,ACC`).
* Property neighbours on the changed helper, all PASS: `focusrect_property_swf5/6/7`,
  `focusrect_swf5`, `focusrect_swf6`, `getproperty`, `getproperty_swf5`,
  `stage_object_properties`, `nan_scale`, `display_object_properties`.

Not re-run: the 92-test `regression` suite and the render canary. Justification — this patch
narrows a condition to `g_swf_version >= 5`, so its entire effect is confined to SWF<5 movies
taking the `SetProperty` **opcode** path, and it restores the exact pre-`ad66b9c74` behaviour
there. Both were green on the wider patch in the first report (§5b/§5c) and neither contains a
SWF4 `setProperty` movie. Say the word if you want them anyway.

## 7. What the disposition docs should now say (list only — I edited none)

* **New entry for `RUFFLE_VS_FLASH_DIFFERENCES.md`** (or the `from_gnash` equivalent):
  *SWF4 `setProperty` with an unparseable string.* Flash abandons the set; Ruffle's non-strict
  `string_to_f64` folds NaN to 0 and stores 0. We follow Flash. Test:
  `from_gnash/misc-swfc.all/swf4opcode` (`swf4opcode.sc:239/259/278/298/318/338/359`), which is
  already `known_failure = true` with an `output.ruffle.txt`, so the corpus encodes it — but the
  *reason* is worth writing down, because it is exactly the trap that caught me.
* Everything listed in the first report's §6 still stands unchanged.

## 8. Process note worth keeping

My original sweep ran `from_gnash/actionscript.all` and `misc-ming.all` but **not**
`misc-swfc.all`, and ran no SWF4 test other than `getproperty_swf4` — which does not use the
`SetProperty` opcode. A change to a *version-gated* coercion helper needs a sweep picked by **SWF
version**, not only by feature name. That is the generalisable lesson, and it is why this one got
through a 51-test sweep.
