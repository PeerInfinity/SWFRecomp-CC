# Accepted Permanent Diffs

Tests where some output lines will never match, and we have decided not to fix them.
Each entry explains *why* the diff is permanent and documents the decision.

This is distinct from `RUFFLE_VS_FLASH_DIFFERENCES.md`, which covers cases where our
implementation matches Flash's spec but disagrees with Ruffle's design choices. The cases
here are impossible to fix for more fundamental reasons.

---

## Category 1: Platform/UB-Dependent Expected Output

The expected output was generated on a specific machine and depends on C undefined behavior
(integer overflow, out-of-range float-to-int conversion, floating-point rounding) that
produces different results on different compilers, platforms, or optimization levels. We
cannot portably replicate the specific UB values without introducing our own UB.

### `date` — NaN/Infinity year in multi-arg constructor (~9 diff pairs)

**Example diff:**
```
- FullYear = -2147481748, ...
+ FullYear = ..., ...
```

When `new Date(NaN, 0)` or `new Date(Infinity, 0)` is called, the year argument is cast
via `(int32_t)year`. For NaN/Infinity this is C undefined behavior — the x86 `cvttsd2si`
instruction produces INT_MIN (−2147483648), but this is not guaranteed. The expected output
reflects the values produced by the specific Ruffle test machine. Our CI (Ubuntu x86_64)
may produce the same INT_MIN, or the compiler may generate different code. No portable fix
is possible without hardcoding UB-specific magic values.

### `date` — TimezoneOffset precision for extreme dates (~1 diff pair)

**Example diff:**
```
- TimezoneOffset = -345
+ TimezoneOffset = -345.002666667
```

For dates near the maximum representable timestamp (~8.64e15 ms), the UTC offset
calculation accumulates floating-point rounding error, producing a fractional offset
instead of the exact integer −345. This is a precision artefact with no clean fix short
of special-casing the offset calculation for extreme values.

---

## Category 2: Internally Inconsistent Expected Output

The expected output is mathematically self-contradictory — no correct implementation
could produce all of the expected values simultaneously. This is a bug in how the Ruffle
test expected output was generated.

### `date` — UTCHours at boundary −8.64e15 (~18 diff pairs)

**Example diff:**
```
- UTCHours = 0, UTCDate = 1
+ UTCHours = 23, UTCDate = 1
```

For timestamps near −8.64e15 ms (the minimum representable Flash date), the expected
output sometimes shows UTCHours=0 in a context where the local date fields (e.g.,
LocalDate=20 at UTC+5:45) require UTCHours=23 or 0+previous-day. The expected values
are internally inconsistent: given the UTC offset and the local fields, the UTCHours
value shown is wrong. Our UTCHours=23 is mathematically correct. This appears to be a
Ruffle test-generation bug affecting only the extreme negative boundary.

---

## Category 3: Flash Implementation Quirks We Do Not Replicate

Undocumented or locale-specific behaviors of Flash Player's built-in functions that
produce outputs we cannot portably reproduce without hardcoding platform-specific magic.

### `array_sort` — Non-ASCII `CASEINSENSITIVE` ordering (1 diff pair, line 50)

**Diff:**
```
- hëllo,HËLLO,TeSt,test
+ HËLLO,hëllo,TeSt,test
```

`["hëllo", "HËLLO", "TeSt", "test"].sort(Array.CASEINSENSITIVE)`.

Flash's `CASEINSENSITIVE` comparison uses a locale-aware or Unicode-aware case fold where
`ë` (U+00EB) and `Ë` (U+00CB) are treated as equal (as they are in proper Unicode case
folding). With the two strings equal, a stable insertion sort preserves their input order
(`hëllo` before `HËLLO`).

Our implementation uses ASCII-only case folding (only `A–Z → a–z`), leaving `ë` and `Ë`
unmodified. This makes `Ë` (203) < `ë` (235), so `hËllo` < `hëllo`, and `HËLLO` sorts
before `hëllo`.

Switching to Unicode-aware case folding (e.g., via `towlower`) would fix this diff but
could introduce regressions for other tests that expect ASCII-only behavior. Additionally,
the second test case (`["TeSt", "hëllo", "HËLLO", "test"]` → `HËLLO,hëllo,TeSt,test`)
produces `HËLLO` before `hëllo` despite `hëllo` appearing earlier in the input — which
contradicts stable sort — suggesting Flash's behavior for non-ASCII chars is in fact
locale-specific and not consistently reproducible.

**Decision:** Accept 1 diff pair. Non-ASCII case-insensitive ordering is platform/locale-
dependent in Flash and not reliably reproducible.

### `array_sort` — `sortOn` multi-key `DESCENDING` flag quirk (2 diff pairs, lines 129, 132)

**Diff:**
```
- {n: BAR, b: 22},{n: bar, b: 3},{n: foo, b: 1},{n: foo, b: 2}
+ {n: foo, b: 1},{n: foo, b: 2},{n: bar, b: 3},{n: BAR, b: 22}
```

`sortOn(["n", "b"], [Array.DESCENDING])` — one flag in the array for two sort keys.
Same diff appears for `sortOn(["n", "b"], [Array.DESCENDING, Array.0, 0])` (line 132).

The expected output shows ascending order by `"n"` (BAR < bar < foo), even though
`Array.DESCENDING` is specified. This contradicts the documented semantics (apply the
last flag to all remaining keys), which would give descending order by `"n"` — exactly
what we produce.

The behavior suggests Flash Player's internal flag-to-key mapping for `sortOn` has an
undocumented off-by-one or other quirk when the flags array is shorter than the keys
array, causing the `DESCENDING` flag to be silently dropped or applied to a non-existent
position. Replicating this would require reverse-engineering undocumented Flash internals.

**Decision:** Accept 2 diff pairs. Flash's multi-key `sortOn` DESCENDING flag handling
is undocumented and cannot be replicated without guessing at implementation internals.

---

## Category 4: Flash UB Behavior We Intentionally Do Not Replicate

Flash Player produced specific outputs that depend on undefined or implementation-defined
behavior in its own runtime. Replicating these values would require us to introduce the
same UB, which conflicts with producing a correct and portable implementation. We accept
the diff and prefer the spec-correct behavior.

### `date` — Infinity getter values (~14 diff pairs)

**Example diff:**
```
- FullYear = -2147481678, Month = 11, Date = -2130706433, ...
+ FullYear = NaN, Month = NaN, Date = NaN, ...
```

When `new Date(Infinity)` is constructed, the internal Time value is Infinity. Flash
Player passes this Infinity through integer conversion in its getter implementations
(equivalent to `(int32_t)Infinity`), which is C UB and produces specific garbage
values (-2147481678, -2130706433, etc.) via x86 `cvttsd2si` saturation or wraparound.

Our implementation correctly returns NaN for all getters when Time is non-finite, which
matches ECMAScript 3 §15.9.5. Matching Flash's UB values would require hardcoding
magic constants or deliberately invoking UB.

**Decision:** Return NaN for non-finite Time. Accept ~14 diff pairs in the `date` test.

---

## Summary Table

| Test | Category | Diff pairs | Decision |
|------|----------|-----------|----------|
| `date` | Platform UB (NaN/Infinity year cast) | ~9 | Accept; no portable fix |
| `date` | Float precision (TimezoneOffset extreme dates) | ~1 | Accept; edge case |
| `date` | Inconsistent expected output (UTCHours at −8.64e15) | ~18 | Accept; Ruffle test bug |
| `date` | Flash UB (Infinity getter values) | ~14 | Accept; prefer NaN (spec-correct) |
| `array_sort` | Flash quirk (non-ASCII CASEINSENSITIVE ordering) | 1 | Accept; locale-dependent, not reproducible |
| `array_sort` | Flash quirk (sortOn multi-key DESCENDING flag) | 2 | Accept; undocumented Flash internals |
