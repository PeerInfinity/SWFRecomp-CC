# w1-gnash-array — wave-1 diagnosis: the `from_gnash/actionscript.all` per-version ladders

Read-only. No source edits, no commits. All measurements taken at HEAD `4b05de6ef` on
`master`, clean tree, `--mode` default (no-graphics; mode parity is complete per the
common brief), `SWFRECOMP_COMPILE_TIMEOUT=2400`, one test at a time.

**Method note (reproducible).** `ruffle_matched` is an *index-subset* test
(`verify_output.py:3506`), so the only number that prices these rows is **ours-only**
= `diff_indices(ours, expected) \ diff_indices(ruffle, expected)`. I re-derived it for
every row by reconstructing our actual output from the `--diff` markers and running
`verify_output`'s own `_diff_indices` / `ruffle_subset_match` against the graded
expected file (script: `<scratch>/w1-gnash-array/subset.py`). Cross-check: the
reconstructed `ours` count equals the marker count on all 13 rows.

---

## 1. Verdicts and priced flips (lead with this)

| test | verdict | flips | bill |
|---|---|---|---|
| `array-v6`, `array-v7`, `array-v8` | **CONDITIONAL GO — +3 effective**, gated on one policy adjudication | **+3** | M1 (small, exactly located) + M4 (small, in-tree template) + **M3 = a documented deliberate no-fix** |
| `MovieClip-v6`, `MovieClip-v7` | **NO-GO this session** (the brief's "2-line mechanism" is refuted) | 0 | **4** mechanisms; 3 of them are flagged high-risk/large by `MOVIECLIP_VN_PLAN.md` itself |
| `MovieClip-v8` | **NO-GO — re-confirmed, with a fresh residual list** | 0 | the v6/v7 four **plus** 27 SWF8-only lines in 6 more clusters |
| `TextField-v6/-v7/-v8` | **NO-GO** | 0 | 36 / 39 / 39 ours-only over **~11** unrelated clusters |
| `argstest-v6/-v7/-v8` | **NO-GO — structurally unpromotable**, not merely expensive | 0 | our actual is *longer* than expected, so promotion is arithmetically impossible |
| `array-v5` | IGN/ACC, must-not-move canary | — | unchanged by anything proposed here |

### Cheapest single mechanism on this board — nomination

**M1 — "an AVM1 `Array.sort` must not clear the *source* index's own-ness when it
relocates a value."** One localized edit in the standard-sort commit path
(`SWFModernRuntime/src/actionmodern/action.c`, the "Standard sort: Flash QuickSort"
block, ~L66262–66390), with a **fully predicted** expected output including
enumeration order (see §3.1). It is the cheapest, best-understood, lowest-risk
mechanism anywhere in this family.

**But be honest about what M1 buys alone: zero flips.** It clears 1 ours-only line on
`array-v6` and 3 on `array-v7`/`-v8`. The **cheapest flip package** on this board is
the whole array ladder — M1 + M4 + an M3 ruling — for **+3**.

### The one decision I need from the coordinator (M3)

`array-v6/-v7/-v8` each carry exactly **2** ours-only lines (`array.as:324/325`) that
are the **same defect as the `array-v5` ACCEPTED_DIFFS entry**, and the project has
already ruled on it — the ruling is pasted verbatim into the runtime source at
`action.c:66266-66278`:

> `…Do NOT switch to a snapshot-and-write-back sort to "fix" 324/325: that matches
> Ruffle but DIVERGES from Flash on 317 (Ruffle gets 317 wrong too). Project policy is
> to match Flash over Ruffle on conflicts…`

Two ways out, both the coordinator's call, not an engineer's:

- **(a) Flash-exact in-place avmplus quicksort** — the ACCEPTED_DIFFS entry's own named
  completion mechanism ("high effort, the residual sort-UB nobody fully nails").
  Reproduces `317` *and* `324/325`. This is an **arc**, not a wave-2 slice, and it needs
  the avmplus `ArrayClass` sort source (not available offline here).
- **(b) A scoped policy waiver**: adopt Ruffle's snapshot-and-write-back sort. Costs
  exactly one Flash-correct line (`array.as:317`) on four tests, **changes no status**
  on v6/v7/v8 (317 is already inside Ruffle's diff set there), and unlocks the +3.
  It would also very likely promote the IGN `array-v5` row (then prunable ⇒ **+4**),
  and it requires rewriting `ACCEPTED_DIFFS.md`'s array-v5 entry, its policy note, the
  `actionscript.all/ignored_tests.txt` rationale and the `action.c` comment. **I do not
  recommend (b) on my own authority** — it is a deliberate Flash-divergence and the
  existing note explicitly forbids it — but it is the only route to +3 this session, so
  the board deserves to see it priced.

**If neither (a) nor (b) is taken, the array ladder is NO-GO and its completion
mechanism is (a).** In that case the whole 13-row family yields **0 flips** and wave 2
should spend its budget elsewhere; M1 and M4 remain worth landing as correctness fixes
(4 + 3 matched lines, no flips).

---

## 2. Per-version residual tables

Graded expected file = highest `player_options.version` subtest (`resolve_expected_filename`).
**No upstream drift**: every expected line count below is identical to the s19 inventory.

### 2.1 `array-vN` — graded `output.fp24.txt`

| test | expected | matching | ours diff | ruffle diff | **ours-only** |
|---|---|---|---|---|---|
| `array-v5` (IGN) | 560 | 551 | — | — | (not re-measured; must not move) |
| `array-v6` | 644 | 623 | 21 | 34 | **4** |
| `array-v7` | 654 | 630 | 24 | 32 | **6** |
| `array-v8` | 654 | 630 | 24 | 32 | **6** |

| mech | `array-v6` | `array-v7`/`-v8` | gate | owner |
|---|---|---|---|---|
| **M1** sparse-sort own-property loss | L126 (`array.as:246`) — **1** | L124,125,128 (`:249,:250,:253`) — **3** | v7/v8's `array.as` has more `OUTPUT_VERSION > 5` assertions in the same block | §3.1 |
| **M3** sort-mutating-comparator UB | L143,144 (`:324,:325`) — **2** | L146,147 — **2** | none (identical on all versions, incl. v5) | §3.3 — **policy no-fix** |
| **M4** `_global.Array` rebound to a user function | L635 (`:1777`) — **1** | L645 — **1** | none | §3.2 |

`M2` (the type-2 sort-comparator calling convention) is **gone** — s19's
`w2-avm1-sort-2-comparator.patch` landed and `array-v7`/`-v8` moved `604/654 → 630/654`
exactly as predicted. **Consequence the board has not absorbed: v6 and v7/v8 now need
the *identical* three mechanisms.** s19's "array-v6 is the cheapest flip in the family"
is obsolete — the ladder is now one indivisible 3-mechanism bundle worth +3.

### 2.2 `MovieClip-vN` — graded `output.fp23.txt`

| test | expected | matching | our lines | ours diff | ruffle diff | **ours-only** |
|---|---|---|---|---|---|---|
| `MovieClip-v6` | 936 | 901 | 935 | 35 | 60 | **14** |
| `MovieClip-v7` | 969 | 934 | 968 | 35 | 64 | **14** |
| `MovieClip-v8` | 1087 | 1020 | 1086 | 67 | 68 | **41** |

`v6` and `v7` ours-only sets are **line-for-line identical** (four mechanisms):

| mech | lines | symptom |
|---|---|---|
| **U1** descendant `onUnload` never fires | 11 (2 real + 9 realignment + 1 spurious) | `MovieClip.as:660` handler + `_level0.hardref3.hardref3child.onUnload called` are missing; the 12 tail lines then sit two indices low, and the Dejagnu counter reads 926 instead of 927 so we emit an extra `FAILED: Tests run 926 (expected 927)` line |
| **U2** `arguments.caller` for an MC method | 1 (`:2097`) | `retCaller == _root.meth` → empty |
| **U3** dotted-`SetVariable` target precedence | 1 (`:2191`) | `propinspect == 0` → 1 |
| **U4** `mc.toString()` after assignment | 1 (`:2590`) | expects `undefined`, we give `[object Object]` |

`MovieClip-v8` = U1–U4 **plus 27 SWF8-only lines** in six more clusters:
`umc.getBounds().xMax == 101` (`:970,:982`, 2); the `filters` array identity/length
block (`:1142-1199`, 11); `draw._width/_height` (`:1668-1669`, 2); `Transform`
property-enumeration order (`:1829`, 1 — and we leak an internal into
`props.toString()`); the `getBounds`/`getRect` twips cluster (`:1857-1898`, 8 — Flash
itself FAILs these and the expected text embeds Flash's wrong numbers; we are off by
1–2 twips, Ruffle matches Flash); `transform`/`matrix` `toString() == undefined`
(`:1903-1904`, 2); `blendMode` (`:2392`, 1).

### 2.3 `TextField-vN` — graded `output.fp13-17.txt`

| test | expected | matching | ours diff | ruffle diff | **ours-only** |
|---|---|---|---|---|---|
| `TextField-v6` | 545 | 467 | 78 | 69 | **36** |
| `TextField-v7` | 570 | 476 | 94 | 85 | **39** |
| `TextField-v8` | 571 | 478 | 93 | 84 | **39** |

Ours-only clusters (v6 / v7-v8): `:43` + `:461` (v7/v8 only, TextField instance
identity, 2); `:372` `tf.length` after `replaceSel` (1); `:754-783` TextField↔variable
back-propagation chain (6–7); `:808` `softref.getDepth()` (1); four raw trace lines —
`textWidth`/`textHeight` under `_xscale`/`_yscale` and `wordWrap` (we report the
unscaled value) (3–4); `:978`,`:1119` (v8 only, 2); `:1046-1056` clips addressed as
`_root[3]` (6); `:1077-1110` `replaceText`/`replaceSel` + `Selection.getBeginIndex/
getEndIndex` arithmetic (11); `:1207/:1209` `_name`/`_target` after a rename (2);
`:1238-1248` the `tfmo` TextField-as-`this` identity block (5); `:1254` (v6/v7 only, 1).
**≈11 unrelated mechanisms per version.** The ACCEPTED `tf.restrict = ""` pair
(`:550/:551`) is **not** in the ours-only set — Ruffle fails it identically, so it is
free and is *not* the blocker. **Completion mechanism: the 13-phase
`_investigation/incomplete/TEXTFIELD_VN_PLAN.md`, as an arc.**

### 2.4 `argstest-vN` — graded `output.fp32.txt` — structurally unpromotable

| test | expected | ruffle lines | ruffle diff | our lines | our diff |
|---|---|---|---|---|---|
| `argstest-v6` | 2192 | 1273 | 2115 | 2661 | 2582 |
| `argstest-v7` | 2061 | 1195 | 1995 | 2661 | 2552 |
| `argstest-v8` | 2434 | 1553 | 2294 | 3023 | 2849 |

This is stronger than "expensive". `_diff_indices` ranges over
`max(len(actual), len(expected))`, so **every index ≥ 2192 in our 2661-line output is
in our diff set and cannot possibly be in Ruffle's** (Ruffle's set tops out at 2191).
While our output is longer than expected, `ruffle_matched` is arithmetically
unreachable — no amount of per-line fixing changes that until the ~470-line over-emission
is gone. The ACCEPTED_DIFFS entry (recursive native-object enumeration over unimplemented
`PrintJob`/`MovieClipLoader`/`LocalConnection`/`textRenderer`/`System.IME` prototypes)
stands. **Completion mechanism: implement those native objects' real property surfaces
so the recursive for-in descent stops multiplying — an arc, and low value.**

---

## 3. Mechanisms, with exact code locations

### 3.1 M1 — `Array.sort` destroys the source index's own-ness  (**the nomination**)

**What the test does.** `array.as:200-211`: `gaparray = []; gaparray[4] = '4';
gaparray[16] = '16';` (length 17, own = {4,16}), then **`gaparray.sort()`** — I confirmed
the call in the emitted bytecode: `array-v6/RecompiledScripts/script_2.c:11427-11433`
pushes `str_270 "gaparray"` + `str_145 "sort"` + `actionCallMethod`, between the
`:210` and `:213` assertions.

**Flash's semantics.** The sort writes the two values to their destination slots as
*new* own properties and **leaves the source keys own**. Own set becomes {4,15,16} on
SWF6 (holes sort first) and {0,1,2,4,16} on SWF7+ (holes sort last) — hence
`gaparray[4] == undefined` (`:223`) **and** `hasOwnProperty('4')` (`:246`) both PASS,
while `!hasOwnProperty('0')` also PASSes.

**Our defect.** We model an array's own-index set as "`elements[i]` is not
`ACTION_STACK_VALUE_HOLE`":
- `action.c:65925-65947` — the array `hasOwnProperty` branch is literally
  `elem != NULL && elem->type != ACTION_STACK_VALUE_HOLE`.
- `action.c:48898-48937` — `actionEnumerate2`'s array arm walks insertion-ordered
  `arr->enum_keys` but **additionally** requires `arr->elements[idx].type != HOLE`.

The in-place quicksort permutes HOLEs *into* index 4, so index 4 silently stops being
an own property.

**Fix shape (wave 2).** In the "Standard sort: Flash QuickSort" block
(`action.c` ~L66262–66390, after the sort and after the DESCENDING reverse): snapshot
the non-HOLE index set before sorting; afterwards, any index that was non-HOLE before
and is HOLE after becomes a typed `ACTION_STACK_VALUE_UNDEFINED` (own, enumerable).
Indices that were already holes are untouched.

**Predicted output, fully.** `enum_keys` insertion order is `["4","16","15"]`;
`actionEnumerate2` is LIFO ⇒ for-in yields `15,16,4`, which is exactly the expected
`tmp[0]='15'`, `tmp[1]='16'`, `tmp[2]='4'`, `tmp.length=='3'` (`:260-263`). So M1 also
recovers 4 Ruffle-shared lines on v6 (and the `:265-270` equivalents on v7/v8) for free.
Canaries: `avm1/array_sort`, `array_sort_random`, `array_enumerate`, `array_properties`,
`array_shift`, `array_splice`, `regression/sort_comparator_*`, and
`from_gnash/actionscript.all/array-v5` (**must not move**).

### 3.2 M4 — `new Array()` must honour a non-object `_global.Array.prototype`

**What the test does** (reconstructed from `array-v6/RecompiledScripts/script_2.c:76445-
77070`; strings resolved from `script_defs.c`): `backup = _global.Array; delete
_global.Array; _global.Array = 8;` → `:1763`; then `h = <function>; h.prototype = 8;
_global.Array = h; ar = []` → `:1771-1773`; then **`ar = new Array()`** (`NewObject`
with ctor name `"Array"`) → `:1777` asserts `typeof(ar.__proto__) == "number"`.

**Our defect.** `actionNewObject` (`action.c:57301`) hard-dispatches on the *literal
name*: `if (strcmp(ctor_name, "Array") == 0)` (`:57402`) mints a native `ASArray` and
calls `initArrayProto` (`:57451`). It never consults the live `_global.Array`, so the
user function `h` and its primitive `prototype` are ignored.

**Fix shape — there is already an in-tree template.** The `new Object(primitive)`
wrapper arm at `action.c:57496-57540` does *exactly* this for `String`/`Number`/
`Boolean`: it re-reads the constructor through `actionGetVariable` (the same path
`String.prototype = X` writes), and if the ctor's own `prototype` is a non-OBJECT it
sets the wrapper's `__proto__` to that value verbatim (`_ow_stored_proto`). Transplant
the same block to the Array arm after `initArrayProto`. ~15 lines, precedent-backed.

`:1772` (`ar = []`, the `InitArray` path) is **free** — Ruffle fails it too — so a
`NewObject`-only fix is sufficient for promotion; doing `InitArray` as well is
Flash-correct and also safe.

### 3.3 M3 — sort-mutating-comparator UB  (**deliberate no-fix; verify before re-litigating**)

`array.as:317` (`pop(); return -1`) → Flash length **0**; we match, Ruffle does not.
`array.as:324/325` (`pop(); return +1`) → Flash length **4** / `"2,3,4,1"`; Ruffle
matches, we do not. Measured on all three versions today (see §2.1). This is
`from_gnash/_investigation/ACCEPTED_DIFFS.md:500-540` ("array-v5 — sort-mutating-
comparator UB") verbatim, the rationale block at
`from_gnash/actionscript.all/ignored_tests.txt` (the `array-v5` entry), and the source
comment at `action.c:66266-66278`. See §1 for the two exits.

### 3.4 U1 — the `hardref3` descendant `onUnload` that never fires

The brief's inherited "−32849 depth" claim **is real and I verified it**:
`MovieClip-v6/output.fp23.txt:390` is `PASSED: hardref3.getDepth() == -32849
[./MovieClip.as:714]` and **we pass that line today**. The shifted depth is
`-(swf_depth)-1-16384` with `swf_depth = 16464` (AS depth 80, matching `:689`
`hardref3.getDepth() == 80`). `MOVIECLIP_VN_PLAN.md` §F1 records the deferral itself as
DONE (`db12e096c`).

What is missing is the *firing*: expected lines 922-923 (`PASSED: this._target ==
'/hardref3/hardref3child' [./MovieClip.as:660]` and `_level0.hardref3.hardref3child.
onUnload called`) never appear anywhere in our 935-line output. Ruffle emits both, at
the first frame boundary after the frame-1 DoAction — i.e. immediately before the
`loadVariables` `onData` rounds s19's patch 3 added.

The machinery all exists and is already wired for *this exact clip*:
- `queueChildOnUnloads` (`action.c:25845`) — recursive, `child->parent == mc`.
- Called unconditionally from both removal paths: `actionRemoveSprite`
  (`action.c:60353`) and the `actionCallMethod` MOVIECLIP `removeMovieClip` arm
  (`action.c:74168`).
- `mcOrDescendantHasOnUnload` (`action.c:25864`) — whose comment names
  `gnash MovieClip.as hardref3` explicitly — drives the deferral.
- `stripNonSurvivingDeferredChildren` (`action.c:25890`) then runs (hardref3 has no own
  `onUnload`, so `_rmc_self_unload == 0`) and calls `actionDeferDpropsRelease` on
  non-surviving children.
- Drain: `actionFirePendingUnloads` (`action.c:25925`), filtered to `is_unload=1`.

So the queued handler is either never enqueued (parent-pointer / `depth == INT_MIN`
filter in `queueChildOnUnloads`) or is enqueued and then dropped (dprops release, or the
`is_unload` filter). **One `printf` at `action.c:74168` + one at the drain decides it in
minutes** — I did not instrument because wave 1 makes no edits. Landing U1 re-aligns 12
of the 14 ours-only lines on v6/v7 (and on v8), which is the single largest line
movement available in this family.

### 3.5 U2 / U3 / U4 — already diagnosed, already flagged as expensive

`_investigation/incomplete/MOVIECLIP_VN_PLAN.md` §"Update 2026-07-02" diagnoses all
three and marks them **"Diagnosed, deferred (risk exceeds 1-line payoff)"**:
- `:2097` — `arguments.caller` through the `meth` builtin frame; the plan says *"prefer
  refactoring the String-arm dispatch into a shared helper first"* (~200 lines).
- `:2191` — ming compiles `mc._x = 1` as dotted `SetVariable("mc._x")`; our
  `resolveFlashPathToMC` walks display-list children before script variables. The plan
  says *"high regression risk against the avm1/target_paths Ruffle-parity architecture;
  don't attempt casually."*
- `:2590` — needs native `Boolean.prototype.toString` identity surviving a
  `mc.toString = …` assignment, dprops-first `toString` dispatch on MOVIECLIP
  receivers, and a per-class Boolean "relay" emulation.

**That is why `MovieClip-v6/-v7` is NO-GO, not "one 2-line mechanism away".**

---

## 4. Refutations (the deliverable the common brief asks for)

1. **"`MovieClip-v6`/`-v7` are held by a 2-line mechanism." — REFUTED.** They are held by
   **four**. U1 is the 2-line mechanism and it is worth 12 of the 14 ours-only lines, but
   U2/U3/U4 survive it and all three are flagged high-risk/large by the plan of record.
   s19's own report said this correctly in §4b ("one remaining ours-only cluster… 2590,
   2191, 2097"); the board's summary line dropped it. **`MovieClip-v6/-v7` is a *worse*
   wave-2 target than `array-v6/-v7/-v8`, not a better one** — the brief's ranking is
   inverted.
2. **"`array-v7`/`-v8` need 3 more mechanisms." — CONFIRMED** (M1, M3, M4; 6 ours-only
   lines), **and extended**: `array-v6` needs the *same* three. s19's "array-v6 is the
   cheapest flip in the family" was true only while M2 was unlanded; post-`w2-avm1-sort`
   the ladder is one indivisible bundle. Do not price v6 separately.
3. **"M3 is undiagnosed" (s19 §2 table). — REFUTED.** M3 is fully diagnosed, has been for
   months, and is a *deliberate* no-fix: `ACCEPTED_DIFFS.md:500`, the `array-v5`
   ignore-list rationale, and a 13-line comment inside the sort itself
   (`action.c:66266-66278`) that pre-emptively forbids the obvious "fix". Any wave-2
   agent handed "3 more mechanisms" would have burned hours rediscovering a closed ruling.
4. **"M1 does not reproduce in isolation — context-dependent, needs the real fixture"
   (s19 §2). — REFUTED.** It reproduces deterministically; the probe was simply missing
   the step that causes it. `hasOwnProperty('4')` on a hand-built gap array *is* true —
   it only goes false after `gaparray.sort()` permutes a HOLE into slot 4. One
   `a=[];a[4]='4';a[16]='16';a.sort();trace(a.hasOwnProperty('4'))` reproduces it.
5. **`ARRAY_V6_V8_PLAN.md` Phase 3's root cause is wrong.** It says *"probably the index 4
   isn't being recorded as 'own' because the densification put it in the elements array
   but not in `arr->props`."* It is in `enum_keys` and it *was* own; the sort overwrote
   it with a HOLE, and both `hasOwnProperty` (`action.c:65940`) and `actionEnumerate2`
   (`action.c:48937`) gate on the HOLE tag. Also, Phase 4 lumps `:324/:325` (the
   policy-blocked sort UB) together with `:260/:263` (M1 fallout) — two different owners.
6. **`MOVIECLIP_VN_PLAN.md` §F2's "soft-reference rebinding is the ONLY thing keeping
   MovieClip-v6/v7/v8 from `ruffle_matched`" is STALE.** Lines 416-435 (the
   `sr62`/`sr63`/`hardref4` block) are **not** in the ours-only set on any of v6/v7/v8
   today. The promotion gate is now U1–U4 (+ the SWF8 clusters on v8). F2's "ROI is
   modest, do not prioritize" conclusion survives; its gating claim does not.
7. **The wave-0 inventory's `RTXT` flag is a false negative for this whole family.** It
   looks for a bare `output.ruffle.txt`; 12 of my 13 rows ship per-Flash-version
   `output.fpNN.ruffle.txt` sidecars instead. Only `array-v5` is flagged RTXT, yet every
   row here is `known_failure = true` **with** a usable Ruffle oracle. Anyone pricing off
   the flag would wrongly conclude `ruffle_matched` is unavailable.
8. **Ignore-list membership does NOT remove a row from the number of record.**
   `scripts/corpus_status_diff.py` has no ignore filtering, and `verify_output.py` never
   reads `ignored_tests.txt` — only the generated markdown reports
   (`scripts/generate_ruffle_comparison.py`, `generate_failing_by_feature.py`) filter. So
   `argstest-v6/-v7/-v8` and `array-v5` *do* sit in the 4527 denominator and a flip on
   them *would* count. (They are still NO-GO on merit — see §2.4.)
9. **Rule 13 drift check: none.** Every graded expected line count (644/654/654,
   936/969/1087, 545/570/571, 2192/2061/2434) is byte-identical to the s19 inventory. No
   upstream movement to mis-book as yield.
10. **Rule 3 check: no `pass → ruffle_matched` risk anywhere in this report.** All 13 rows
    are `output_mismatch` at baseline; every mechanism proposed (M1, M4, U1–U4) moves us
    **toward Flash's `output.txt`**. The one proposal that would move us toward *Ruffle's*
    output is M3-exit-(b), and it is flagged as a policy question precisely for that reason.

---

## 5. Evidence index

- Per-test `--diff --verbose` logs: `<scratch>/w1-gnash-array/{array,MovieClip,TextField,argstest}-v*.log`
- Subset analyses: `<scratch>/w1-gnash-array/*.subset.txt`; script `subset.py`
- Runs are sequential, one at a time, `SWFRECOMP_COMPILE_TIMEOUT=2400`; run log
  `<scratch>/w1-gnash-array/progress.txt` (19:35–19:59, all rc=0).
- Dispositions checked by name for all 13 rows against
  `avm1/_investigation/{ACCEPTED_DIFFS,RUFFLE_VS_FLASH_DIFFERENCES,RUFFLE_COMPAT_TWEAKS,FLASH_BUGS_REPLICATED}.md`,
  `from_gnash/_investigation/ACCEPTED_DIFFS.md`, `ruffle-tests/ignored_tests.txt`,
  `from_gnash/actionscript.all/ignored_tests.txt`. Hits: `array-v5` (IGN+ACC),
  `argstest-v6/-v7/-v8` (IGN+ACC), `TextField-v6/-v7/-v8` (ACC, 2 free lines only —
  **not** a blocker). `array-v6/-v7/-v8` and `MovieClip-v6/-v7/-v8` carry **no**
  disposition entry of any kind.

---

## 6. New unclaimed leads

1. **A single `_global.<Name>` indirection arc would serve three separate board rows.**
   M4 here, s19's N3 `avm1/globals_monkeypatch` (expected grew to 228 lines; "every
   builtin that mints a Rectangle/Matrix/Transform/ColorTransform/Point must resolve it
   by walking `_global.flash.geom.X` through user getters"), and the existing
   `String`/`Number`/`Boolean` wrapper precedent at `action.c:57496` are the same
   mechanism at three call sites. `actionNewObject`'s name-`strcmp` dispatch
   (`action.c:57402+`) is the shared root. Worth costing as one arc rather than three
   one-liners. (Cf. memory `avm2-builtin-class-mints-never-looks-up` — the AVM2 twin.)
2. **`MovieClip.as:2590` may be M4-shaped.** "A user-assigned non-function/non-object on
   a special slot must not fall back to the builtin" describes both `ar.__proto__ = 8`
   and `mc.toString = <non-function>`. If the M4 fix generalises, U4 could come along
   for free — which would leave `MovieClip-v6/-v7` needing only U1+U2+U3. Cheap to test
   once M4 lands.
3. **`MovieClip-v8` `:1857-1898` is a self-contained 8-line twips-rounding cluster.**
   Expected embeds Flash's own FAILED values; Ruffle reproduces them exactly and we are
   1–2 twips off in `getBounds`/`getRect` under rotation/scale. Memory
   `ruffle-geometry-is-integer-twips` is the likely lever. It flips nothing alone (v8
   needs 10 mechanisms) but it is the kind of cluster that shows up elsewhere.
4. **U1 is a real correctness bug beyond the corpus**: a `removeMovieClip`'d clip that is
   kept alive *because a descendant defines `onUnload`* never fires that descendant's
   `onUnload`. Any content relying on child-cleanup callbacks silently leaks. Worth a
   `regression/` fixture with a Ruffle-exporter oracle regardless of the corpus verdict.
5. **The three `incomplete/` plans I touched are stale and mislead**: `ARRAY_V6_V8_PLAN.md`
   (baseline table from 2026-05-15; Phase 3 root cause wrong; Phase 4 conflates two
   owners), `MOVIECLIP_VN_PLAN.md` (§F2 gating claim no longer true), and the wave-0
   inventory's RTXT flag. A doc-only pass would stop the next session re-deriving all of
   this. Zero flips, but it has now cost three boards.
