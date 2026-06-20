# set_property_values/{swf4,swf5,swf6,swf7} — coercion grind, swf5-7 unpromotable

**Status:** BLOCKED (swf5/6/7 cannot reach full PASS) / large grind (swf4).
**Diagnosed:** 2026-06-19. ~30 min investigation; do not re-derive from scratch.

## What the test does

`test.as` is a generated coercion matrix: for ~20 stage-object properties
(`_x`, `_y`, `_xscale`, `_yscale`, `_alpha`, `_visible`, `_width`, `_height`,
`_rotation`, `_name`, `_highquality`, `_focusrect`, `_soundbuftime`, `_quality`,
…) it runs, for many input values (`2`, `-5`, `1.5`, `0`, numeric strings,
`"10x"`/`"z10"`/`"abc"`/`""`, booleans, `undefined`, `null`, `0/0`, `1/0`,
`-1/0`, plain `Object`, and an object with tracing `valueOf`/`toString`), the
block:

```
setProperty(P, 0);  setProperty(P, VALUE);  trace(getProperty(P));   // read1
setProperty(P, 1);  setProperty(P, VALUE);  trace(getProperty(P));   // read2
obj={valueOf/toString};  setProperty(P, obj);  trace(getProperty(P)); // read3 (+ "valueOf"/"toString" trace)
```

So each block probes how `setProperty` coerces/clamps each value type per
property, including the no-op cases (read1/read2 stay at the reset value).

## Results (CI sha d3d57c25e, 2026-06-19)

| Variant | Match | `output.ruffle.txt`? | Ceiling |
|---------|-------|----------------------|---------|
| swf4 | 350/1571 (22%) | **present** → `ruffle_matched` reachable | separate, larger SWF4 property-addressing gap |
| swf5 | 1620/1743 (93%) | absent → needs **full PASS** | **blocked** (see below) |
| swf6 | 1620/1743 (93%) | absent → needs **full PASS** | **blocked** |
| swf7 | 1620/1743 (93%) | absent → needs **full PASS** | **blocked** |

## The hard blocker (swf5/6/7): float precision on `_x`/`_y` ← Infinity

`setProperty(_x, 1.0/0.0)` and `setProperty(_x, -1.0/0.0)` must read back
**`-107374182.4`** = `INT_MIN / 20` (Flash stores `_x`/`_y` as S32 twips;
`(S32)(±Inf * 20)` = `INT_MIN` on x86 `cvttsd2si`; getter returns twips/20).

`MovieClip.x`/`.y` are **`float`** (`include/actionmodern/action.h:29`). The read
path is `round((double)mc->x * 20.0) / 20.0` (`action.c:~42401/42417`).
`-107374182.4` needs 9 significant figures; `float` ulp near 1.07e8 is ~8, so the
nearest float reads back as **`-107374184`**, not `-107374182.4`. Unfixable
without widening `mc->x/.y` (and the whole transform/render/recompiler chain) to
`double` — far out of scope. That's 12 permanently-mismatched lines per variant
(6 `_x` + 6 `_y`), so swf5/6/7 can never fully match. **Do not add to the ignore
list** — the *other* ~111 lines are real, fixable behavior; ignoring would hide
fixable work and the test still wouldn't "pass".

## The fixable ~111 lines (decoded quirk map)

All in `actionSetProperty` (`action.c:~54298`) value-coercion + the matching
getters. The current blanket "non-finite → no-op for props 0-10,12"
(`action.c:54356-54397`) is **too broad** — only NaN is a universal no-op; ±Inf
must flow through per-property. By property (diff-line counts are
expected-mismatch pairs):

- **_alpha (54)** — biggest win. Quantize via 8.8 fixed-point with **truncation
  toward zero**, not `roundf` (`action.c:54429`): `(int16_t)(v*256.0/100.0)`.
  e.g. `-5`→`-12`→`-4.6875` (we give `-13`→`-5.078125`); `1`→`2`→`0.78125`
  (we give `3`→`1.171875`, which poisons every block's read2 baseline). NaN →
  no-op; ±Inf → stored `0` (cast of Inf→int16 low bits = 0).
- **_name (44)** — case 13 only sets when value is a `string`; Flash coerces
  **any** type to string (`2`→"2", `true`→"true", `undefined`→"", `null`→
  "null", `NaN`→"NaN", `Inf`→"Infinity"). Isolated, low-risk.
- **_soundbuftime (34)** — string strict-parse + `±Inf → INT_MIN` (`-2147483648`);
  currently `isfinite` gate no-ops Inf (`action.c:54526`).
- **_highquality (22)** — string strict-parse (`"10x"` must no-op, we set 2) +
  baseline.
- **_x / _y (16 each)** — string strict-parse fixes the `"10x"` lines; the
  Inf lines (6 each) are the **unfixable** float-precision ones above.
- **_xscale / _yscale (16 each)** — string strict-parse + `±Inf → store Inf`
  (read back "Infinity"/"-Infinity"); we no-op it.
- **_rotation (16)** — string strict-parse + `±Inf → store, read back NaN`
  (`normalizeRotation(Inf)` must yield NaN via fmod); NaN-input → no-op.
- **_visible (10)** — NOT a no-op property: `NaN → false`, `±Inf → true`
  (compute `num != 0 && !isnan(num)`); currently caught by the 0-10 no-op gate.
- **_focusrect (2)** — string strict-parse (`"10x"` → no-op/0).

### Root sub-fixes (each helps multiple properties / other tests)

1. **String → numeric strict parse**: after `strtod`, skip trailing whitespace;
   if `*end != '\0'`, value is NaN (→ no-op). Today `strtod("10x")` returns 10
   (prefix parse) so we wrongly set 10. Touches `action.c:54380-54391`. Flash-
   correct ECMA `ToNumber`. Helps every numeric property's `"10x"` line.
2. **Replace blanket `!isfinite → no-op`** with **NaN-only no-op**, and route
   ±Inf per-property (twips S32 cast for _x/_y/_soundbuftime, store-as-is for
   scale, fmod→NaN for rotation, fixed-point→0 for alpha, `!=0` for visible).
3. **_alpha**: `roundf` → truncating cast.
4. **_name**: full `toString` coercion of any value type.

## Why not done this session

The fixable changes sit on the **shared `actionSetProperty` / `actionGetProperty`
hot path** (every test that sets `_x/_y/_alpha/_visible/_name/...`). Regression
risk is real and can't be validated with single-test local runs → CI-gated,
likely multi-cycle. And because of the float blocker above, even a perfect job
leaves swf5/6/7 as `output_mismatch` (no promotion) — only swf4's
`ruffle_matched` is reachable, and swf4 has a *separate, larger* SWF4 property-
addressing gap (22%) not addressed by any of the above. Net: high blast radius,
zero swf5-7 promotions. Sub-fixes 1/3/4 are genuinely correct and worth landing
opportunistically alongside other property work (they benefit games/other tests),
but they don't justify a dedicated CI cycle on their own.
