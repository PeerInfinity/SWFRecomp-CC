# w2-arraysort — the Flash-exact quicksort arc, and what actually landed

## NEW FILES (stage these by name — `git add -u` will drop them)

- `SWFRecompDocs/plans/session20-fanout-reports/w2-arraysort-1-sparse-sort-ownership.patch`
- `SWFRecompDocs/plans/session20-fanout-reports/w2-arraysort-2-global-array-rebind.patch`
- `SWFRecompDocs/plans/session20-fanout-reports/w2-arraysort-report.md` (this file)

Both patches touch only `SWFModernRuntime/src/actionmodern/action.c`, no new source files,
runtime-only (no `--recompile` needed to land them). Verified: `git apply` of 1→2 from
pristine `master` reproduces my worktree byte-for-byte (md5 match). Worktree:
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/s20-arraysort` (detached at `870b48fb9`).

---

## 1. Verdict first

| item | verdict |
|---|---|
| **The funded arc — port avmplus `ArraySort::qsort`** | **REFUTED AND ABANDONED, at hour one, as instructed.** The faithful port matches Flash on **neither** leg. It is strictly *worse* than what we ship today. Not landed. |
| **`array.as:317`** (`pop(); return -1` ⇒ length 0) | **STILL PASSES.** Unchanged, verified on all four rows. The trade the user refused was not made. |
| **`array.as:324`** (`length == 4`) | **still FAILS** — `obtained: 0` |
| **`array.as:325`** (`"2,3,4,1"`) | **still FAILS** — `obtained: ""` |
| **M1** — sparse-sort own-property loss | **LANDED, verified, matches my wave-1 prediction exactly** |
| **M4** — `new Array()` under a rebound `_global.Array` | **LANDED, verified** (my wave-1 *pricing* of it was wrong — §5.4) |
| **Realised flips** | **ZERO.** M3 gates every row and M3 is unsolved. |

**Net corpus effect: 0 status changes, 0 regressions, +14 matching lines** (v5 +2, v6 +4,
v7 +4, v8 +4 — the ours-only lines each mechanism clears, plus the Ruffle-shared `tmp`
enumeration lines M1 drags along with them). Every one of `array-v5/-v6/-v7/-v8` is `output_mismatch` before and
after. **No `pass → ruffle_matched` move anywhere.**

### 1.1 The three lines the brief asked me to verdict, verbatim from the AFTER logs

`:317` appears as an unprefixed CONTEXT line on all four rows — it matches — while `:324`/`:325`
are still `-/+` pairs. This is the check the brief made the bar, and it is the check I ran on
every leg:

```
array-v5   110  PASSED: trysortarray.length == 0 [./array.as:317]      <- context = MATCHES
array-v6   140  PASSED: trysortarray.length == 0 [./array.as:317]      <- context = MATCHES
array-v7   143  PASSED: trysortarray.length == 0 [./array.as:317]      <- context = MATCHES
array-v8   143  PASSED: trysortarray.length == 0 [./array.as:317]      <- context = MATCHES

array-v6 - 143  PASSED: trysortarray.length == 4 [./array.as:324]
         + 143  FAILED: expected: 4 obtained: 0 [./array.as:324]
         - 144  PASSED: trysortarray.toString() == "2,3,4,1" [./array.as:325]
         + 144  FAILED: expected: "2,3,4,1" obtained:  [./array.as:325]
```

**The board should now read: the array ladder is ONE mechanism (M3) from +3, not three.**
That is the deliverable — the ladder's residual went from 4/6/6 ours-only lines across three
mechanisms down to 2/3/3: M3 alone on `array-v5`/`-v6`, and M3 plus one newly-isolated line on
`array-v7`/`-v8` (§5.3). The two cheap mechanisms are permanently off the critical path.

---

## 2. Why the avmplus port was abandoned — with executable evidence

I did not hand-wave this. I transcribed `core/ArrayClass.cpp:637` `ArraySort::qsort` verbatim
(the `recurse:` label, the `size < 4` explicit cases, the midpoint-pivot `swap(pivot, lo)`,
both `do/while` scan loops, the `(right - 1 - lo) >= (hi - left)` smaller-partition-first
branch, the `stk[33]` frame stack), drove it with a comparator that pops a simulated live
array exactly as `testCmpBogus5/6` do, and ran it.
Harness: `<scratch>/w1-gnash-array/qs/qs.c` and `search.c`.

```
array.as:324 (+1 case)  cmp=+1  ncmp=7  index=[2,3,0,1]  avmplus writeback -> len=4 [3,4,1,2]
array.as:317 (-1 case)  cmp=-1  ncmp=6  index=[3,1,0,2]  avmplus writeback -> len=4 [4,2,1,3]
```

Flash wants `len=0` for the `-1` leg and `len=4 / "2,3,4,1"` for the `+1` leg. The port gives
**length 4 for both**, and the wrong contents for both. It loses `:317` (which we currently
pass) **and does not win `:324/:325`** (which Ruffle currently passes). Landing it would have
been a pure loss.

**And it cannot be rescued by changing the write-back rule.** Both legs enter the sort with
identical `len` and `iFirstAbsent` (4) and leave it with identical post-pop live length (0) —
the harness prints both. So any write-back that is a function of those quantities necessarily
produces the *same* length for both legs: avmplus's own rule (write `iFirstAbsent` elements)
gives 4/4, a live-length-bounded rule gives 0/0. **Flash's 0-vs-4 split is unreachable from
avmplus's qsort under any write-back rule.** That is a closed-form argument, not a search.

**Root cause of the bad premise, and how far it travelled.** `adobe/avmplus` is Tamarin — the
**AVM2** VM. It contains no ActionScript-1 Array implementation at all (the only `AVM1` strings in `core/` are in
`ByteArray.as`/`ObjectEncoding.as`, describing the AMF0 *wire format*). `array-v5..v8` are
SWF 5–8, i.e. **AVM1**. So `ACCEPTED_DIFFS.md`'s phrase *"Flash's in-place avmplus sort"* —
which is where the premise entered the record — is itself wrong. One unchecked phrase,
written once, then propagated through **four** documents and a funding decision:
`ACCEPTED_DIFFS.md` → the `actionscript.all/ignored_tests.txt` rationale → the
`action.c:66266` source comment → my own wave-1 report §1 → this brief's option (a). Nobody
re-derived it, including me; I proposed the arc in wave 1 on the strength of the same phrase.
The avmplus clone is the right oracle for the AVM2 corpus; it is simply the wrong oracle for
an AVM1 test, and the only thing that surfaced that was compiling the code and running it.

### 2.1 The one genuinely new lead the search produced

Because I had the harness, I swept five algorithm families × three write-back models against
the observed split (`search.c`). One family reproduces Flash's **length** split:

```
bubble-full  in-place  (-1) -> len=0 []            <- matches Flash leg A
bubble-full  in-place  (+1) -> len=4 [0,0,0,0]     <- matches Flash's LENGTH, not contents
```

and a single in-place bubble **pass** over a snapshot reproduces the **contents**
(`[2,3,4,1]`). No other family produced the 0/4 split at all — notably *no* quicksort did,
which is itself evidence that the "Flash-exact quicksort" framing is wrong. My model clears
popped slots on `pop()`; if AVM1's `pop()` only decrements `length` and leaves the element
buffer intact (which ours does), an in-place bubble-family sort reading the raw buffer is the
first candidate that could carry both length *and* contents.

**This is a derive-the-algorithm-from-observations arc, not a port, and it is multi-session.**
Concrete stopping point if anyone picks it up: get `(-1) → len 0` and `(+1) → len 4,
"2,3,4,1"` out of `search.c` *before* touching `action.c`. If a variant does both, it is worth
landing; if two sessions of harness work do not, M3 should be re-dispositioned as permanent
rather than "not yet attempted". I did not start it — the brief's instruction was to report
the stopping point rather than burn the slot.

---

## 3. What landed

### 3.1 Patch 1 — M1, sparse-sort own-property preservation

`callArrayMethod`, the "Standard sort: Flash QuickSort" block. We model "index *i* is an own
property" as `elements[i].type != ACTION_STACK_VALUE_HOLE` (the array `hasOwnProperty` branch,
and `actionEnumerate2`'s array arm). The in-place quicksort permutes HOLEs *into* originally-set
slots, silently destroying their own-ness. Flash writes sorted values to their destination
indices as new own properties and leaves the **source** indices own-with-value-undefined.

The patch snapshots the non-HOLE index set before sorting and afterwards promotes any snapshot
member the permutation turned into a HOLE to a typed `UNDEFINED`. It re-reads `arr->elements`
and clamps to `min(n, arr->length)` afterwards — deliberately, so that a comparator that popped
the array mid-sort cannot have slots resurrected past the live length. **That clamp is what
keeps `array.as:317` passing**, and I verified it rather than assuming it.

**Prediction check (the brief asked me to hold myself to this).** Wave-1 predicted the for-in
order would come out `15,16,4` because `enum_keys` insertion order is `["4","16","15"]` and
`actionEnumerate2` is LIFO. Measured after the patch, on `array-v6`:

```
:260  tmp.length == '3'   PASS      :262  tmp[1] == '16'  PASS
:261  tmp[0] == '15'      PASS      :263  tmp[2] == '4'   PASS
```

**Prediction correct, including the order** — which is the point: the for-in sequence was
derived from the `enum_keys` insertion order plus `actionEnumerate2`'s LIFO before the patch
existed, so the mechanism is *understood*, not merely patched until the diff went quiet.

`:246` `gaparray.hasOwnProperty('4')` passes and `:247` `!gaparray.hasOwnProperty('0')` still
passes — holes that were never own stay untouched, which is the other half of the rule.

### 3.2 Patch 2 — M4, `new Array()` under a rebound `_global.Array`

`actionNewObject`'s Array arm. `array.as:1763-1777` does `h = function(){}; h.prototype = 8;
_global.Array = h; ar = new Array();` and requires `typeof(ar.__proto__) == "number"`. We
hard-dispatch on the literal name (`strcmp(ctor_name, "Array")`), mint a native `ASArray` and
call `initArrayProto`, never consulting the rebound constructor. The patch reads `_global`'s
own `"Array"` property and, if it is a function whose own `prototype` is a non-object,
propagates that value verbatim as the array's `__proto__` — the same rule the
`new Object(primitive)` wrapper arm already implements for String/Number/Boolean.

`array.as:1777` now **PASSES**. `:1772` (the `ar = []` `InitArray` path) still fails and is
deliberately left alone: it is inside Ruffle's diff set, so it is free, and fixing it means
touching `actionInitArray` as well for no scoring gain.

---

## 4. Measured per-row residuals (worktree, no-graphics, sequential, `SWFRECOMP_COMPILE_TIMEOUT=2400`)

Ours-only = `diff_indices(ours, expected) \ diff_indices(ruffle, expected)` computed with
`verify_output`'s own helpers (`<scratch>/w1-gnash-array/subset.py`).

| test | ours-only BEFORE | ours-only AFTER | remaining, by mechanism |
|---|---|---|---|
| `array-v5` (IGN) | not separately measured¹ | **2** | M3 only (`:324`, `:325`) |
| `array-v6` | 4 | **2** | M3 only |
| `array-v7` | 6 | **3** | M3 (2) + `:253` (1) |
| `array-v8` | 6 | **3** | M3 (2) + `:253` (1) |

Raw diff counts moved `21→17` (v6), `24→20` (v7/v8), `9→7` (v5). Status unchanged on all four.

¹ I measured `array-v5`'s ours-only set only in the AFTER leg. Its before-leg raw diff count
is the baseline inventory's `551/560` (9 diffs); the `ACCEPTED_DIFFS.md` entry names `:324`/`:325`
as its ours-only pair and my after-measurement confirms exactly that pair survives, so the set did
not grow. I did not spend a second full rebuild to pin the before number because `array-v5` is an
IGN row and the flip arithmetic does not depend on it.

### 4.1 Strictly monotone — zero new diff lines on any row

Diff-line index sets, before vs after, on the three graded rows (the `array-v5` before-leg is
footnote 1). **No row gained a single new differing line**; every change is a removal:

| test | fixed indices | NEW indices |
|---|---|---|
| `array-v6` | 126, 128, 131 (M1), 635 (M4) | **none** |
| `array-v7` | 124, 125, 132 (M1), 645 (M4) | **none** |
| `array-v8` | 124, 125, 132 (M1), 645 (M4) | **none** |

This is the check that matters most for a change inside `Array.sort`: the patches cannot have
traded one line for another anywhere in a 644/654-line trace.

**`array-v5` moved, and that is expected, not a regression.** My wave-1 brief flagged it as a
"must not move" canary. It moved in the *right* direction (551→553 matching lines) because M1
and M4 apply to it too, and its ours-only set is **still exactly `{324, 325}`** — it remains
`output_mismatch` and remains un-promotable for precisely the documented M3 reason. Worth
noting for the board: **the day M3 lands, `array-v5` promotes as well**, so the prize is +3
graded rows plus an ignore-list prune, not +3.

---

## 5. Refutations — including two of my own

1. **"The Flash-exact in-place avmplus quicksort is the completion mechanism for M3"**
   (`ACCEPTED_DIFFS.md`, the `action.c:66266` comment, my own wave-1 report §1(a), and this
   brief). **Refuted, executably.** avmplus's qsort matches Flash on neither leg, and avmplus
   is AVM2-only so it was never the right source. See §2.
2. **"`~/CC/avmplus` is the behaviour oracle for these rows."** True for the AVM2 corpus, false
   here. The coordinator's refutation of *my* "offline-unavailable" premise was correct — the
   clone exists and I used it — but the source being available does not make it the right
   oracle.
3. **My wave-1 M1 bucketing was slightly wrong.** I bucketed `array.as:249`, `:250` and `:253`
   together as one mechanism on v7/v8. M1 clears `:249` and `:250`; **`:253`
   (`gaparray.hasOwnProperty('2')`) survives** and is a separate, unidentified mechanism — Flash's
   own-set after the SWF7+ sort is `{0,1,2,4,16}`, which is not explained by
   sources ∪ destinations (`{0,1,4,16}`). So the v7/v8 flip needs M3 **and** `:253`; only v5/v6
   are a pure one-mechanism wait. I priced v7/v8 one mechanism too cheap in wave 1.
4. **My wave-1 M4 pricing was wrong in its reasoning, right in its size.** I wrote "~15 lines,
   in-tree template at `action.c:57496`". The template's *guard* (`prototype_obj == NULL`, read
   via `actionGetVariable`) does **not** transfer: `actionGetVariable("Array")` answers from the
   builtin constructor table and never sees a script's `_global.Array = h` rebind — I proved this
   with a probe that printed the engine constructor pointer on every call while `_global`'s own
   `"Array"` property held the user function. The working fix reads `_global`'s own property
   directly. Same size, different mechanism. **Anyone who had taken my wave-1 sentence literally
   would have written a guard that never fires** — which is exactly what my first attempt did.
5. **My wave-1 lead "M4 is the same mechanism as `avm1/globals_monkeypatch`" is now sharper, and
   still stands.** The shared root is confirmed: the AVM1 name-resolution path prefers the builtin
   table over `_global`'s own properties. That is a real, general defect with a wide blast radius;
   I fixed only the one call site (`actionNewObject`'s Array arm) rather than the resolver,
   deliberately, because changing resolution order is a corpus-wide change and not this slot's job.

---

## 6. Documentation — exact drop-in replacement text

**I did not edit `from_gnash/_investigation/` or the ignore list myself, as agreed.** Everything
below is drop-in: the ruling's *conclusion* (never adopt the snapshot sort) is preserved
verbatim in each; only its *reason* changes.

### 6.1 `SWFModernRuntime/src/actionmodern/action.c` — the standard-sort comment

This block sits immediately above `{ ActionVar* _qbuf = arr->elements;` in `callArrayMethod`.
At `master` it is lines 66262-66277; **after patch 1 it is unchanged and still immediately
above that line**, so apply this replacement after both patches land.

REPLACE (13 comment lines, from `// Sorts the LIVE array in place.` through
`// actionscript.all ignored list.`) WITH:

```c
		// --- Standard sort: Flash QuickSort (iterative, leftmost pivot) ---
		//
		// Sorts the LIVE array in place. A comparator that mutates the array
		// mid-sort (gnash array.as testCmpBogus5/6: `trysortarray.pop(); return ±1`)
		// is documented Flash sort UB: Flash produces DIFFERENT results per return
		// value — length 0 for `return -1` (array.as:317), length 4 / "2,3,4,1" for
		// `return +1` (array.as:324/325). We replicate 317 by sorting in place; we
		// do NOT replicate 324/325.
		//
		// Do NOT switch to a snapshot-and-write-back sort to "fix" 324/325: that
		// matches Ruffle but DIVERGES from Flash on 317 (Ruffle gets 317 wrong too).
		// Project policy is to match Flash over Ruffle on genuine conflicts.
		//
		// The completion mechanism is NOT "a Flash-exact in-place avmplus quicksort".
		// That framing was wrong and is retired (s20, w2-arraysort): adobe/avmplus is
		// Tamarin — the AVM2 VM — and contains no ActionScript-1 Array at all, while
		// array-v5..v8 are SWF 5-8 (AVM1). ArraySort::qsort (ArrayClass.cpp:637) was
		// transcribed verbatim and driven by a popping comparator: it yields length 4
		// on BOTH legs ("4,2,1,3" for -1, "3,4,1,2" for +1), so it loses 317 AND fails
		// to win 324/325. Nor can a different write-back rule rescue it — both legs
		// enter with identical len/iFirstAbsent (4) and leave with identical post-pop
		// live length (0), so any write-back that is a function of those gives the
		// SAME length for both, and Flash's 0-vs-4 split is unreachable.
		//
		// Open lead: of 5 algorithm families x 3 write-back models swept, only an
		// IN-PLACE BUBBLE-family sort reproduces the 0-vs-4 length split (no quicksort
		// does), and a single bubble pass over a snapshot reproduces the "2,3,4,1"
		// contents. Gate any future attempt on a harness reproducing BOTH legs before
		// touching this code. array-v5's residual sort-UB diff is documented in
		// from_gnash/_investigation/ACCEPTED_DIFFS.md and the test is on the
		// actionscript.all ignored list.
```

### 6.2 `from_gnash/_investigation/ACCEPTED_DIFFS.md` — the `array-v5` entry

**(a)** In **Root cause**, REPLACE `This is documented Flash sort UB: Flash's in-place avmplus
sort produces *different* results depending on the comparator's return value —` WITH:

```
This is documented Flash sort UB: Flash produces *different* results depending on
the comparator's return value —
```

(The phrase "Flash's in-place avmplus sort" is the error this whole arc traced back to:
avmplus is the AVM2 VM and has no AS1 Array; these tests are AVM1.)

**(b)** In **Decision**, REPLACE the sentence `Reproducing Flash on BOTH 317 and 324/325 would
require a Flash-exact in-place AVM1 quicksort (high effort, the residual sort-UB nobody fully
nails); not pursued.` WITH:

```
Reproducing Flash on BOTH 317 and 324/325 remains open, but the long-standing
"Flash-exact in-place avmplus quicksort" framing is RETIRED (session 20,
`SWFRecompDocs/plans/session20-fanout-reports/w2-arraysort-report.md` §2).
adobe/avmplus is Tamarin — the AVM2 VM — and contains no ActionScript-1 Array;
array-v5..v8 are SWF 5-8, i.e. AVM1. `ArraySort::qsort` was transcribed verbatim
and driven by a popping comparator: it returns length 4 on BOTH legs, losing 317
without winning 324/325, and no write-back rule can rescue it (both legs enter
with identical len/iFirstAbsent and leave with identical post-pop live length).
The surviving lead is an in-place BUBBLE-family sort over a non-clearing `pop()`:
alone among 5 algorithm families it reproduces the 0-vs-4 length split, and a
single bubble pass over a snapshot reproduces "2,3,4,1". Not pursued further;
gate any attempt on a harness reproducing both legs first.
```

**(c)** In **Decision**, REPLACE `The remaining array-v5 diffs (260/263/1630/1636) are separate
clusters both engines also miss vs Flash.` WITH:

```
The remaining array-v5 diffs (1630/1636) are separate clusters both engines also
miss vs Flash. (`array.as:260`/`:263` were fixed in session 20 by the sparse-sort
own-property patch; array-v5's complete diff is now seven lines — 324, 325, 444,
1630, 1636 and the two Dejagnu counter lines — of which only 324/325 are
ours-only.)
```

### 6.3 `from_gnash/actionscript.all/ignored_tests.txt` — the `array-v5` block

**`array-v5` STAYS on the list.** Its ours-only set is still non-empty and still not a subset
of Ruffle's, so the file's own prune criterion ("remove iff `pass`") is not met. REPLACE the
comment block above `array-v5` WITH:

```
# array-v5 — sort-mutating-comparator UB.
# A comparator that pops the array mid-sort yields DIFFERENT Flash results per
# return value: `pop(); return -1` → length 0 (array.as:317), `pop(); return +1`
# → length 4 / "2,3,4,1" (array.as:324/325). We sort in place and match Flash on
# 317 but NOT 324/325. Ruffle uses a snapshot-and-write-back sort that gets
# 324/325 right but 317 WRONG (length 4) — a genuine Ruffle-vs-Flash conflict.
# Per project policy we match Flash, so our diff is NOT a subset of Ruffle's (we
# pass 317 where Ruffle fails; Ruffle passes 324/325 where we fail) -> no
# ruffle_matched promotion.
# The old "needs a Flash-exact in-place avmplus quicksort" note is RETIRED (s20):
# avmplus is the AVM2 VM and has no AS1 Array; the verbatim port loses 317 without
# winning 324/325. Open lead is an in-place bubble-family sort. See
# SWFRecompDocs/plans/session20-fanout-reports/w2-arraysort-report.md §2.
# PRUNE CRITERION: this entry becomes removable the moment 324/325 match — at that
# point array-v5's ours-only set is empty and it promotes to ruffle_matched.
# Remaining non-ours-only diffs: 1630/1636 (both engines miss these vs Flash).
# See _investigation/ACCEPTED_DIFFS.md Category 1 and
# _investigation/incomplete/ARRAY_V5_PLAN.md.
```

### 6.4 `_investigation/incomplete/ARRAY_V6_V8_PLAN.md`

Phase 3 → **completed** (note that its stated root cause — *"the densification put it in the
elements array but not in `arr->props`"* — was wrong; the real model is the HOLE permutation,
recorded in patch 1's comment). Phase 4 should be split: `:324`/`:325` belong to the M3 /
ARRAY_V5 entry, `:260`/`:263` are fixed. The "Local CI baseline (commit `eb8206f8`,
2026-05-15)" table is four sessions stale — current ours-only is 2 / 3 / 3 on v6 / v7 / v8.

---

## 6.5 M3 — brief for the next slot (scoping only; NOT started)

**Do not fund this as a "port" again.** The task is to derive an algorithm from observations.

- **Target, both legs, non-negotiable:** `(-1)` ⇒ `trysortarray.length == 0` (`array.as:317`)
  **and** `(+1)` ⇒ `length == 4`, `toString() == "2,3,4,1"` (`:324`/`:325`). A change that wins
  324/325 and loses 317 is a **failure**, not a partial win — that is the trade the user
  explicitly refused, and 317 currently passes on all four rows.
- **Hard gate before any `action.c` edit:** get both legs out of
  `<scratch>/w1-gnash-array/qs/search.c` (harness preserved; 5 algorithm families × 3
  write-back models already wired, with the target printed at the top of its output).
- **Strongest lead:** in-place bubble family over a **non-clearing `pop()`**. `bubble-full`
  in-place already gives `(-1)→len 0` / `(+1)→len 4`; contents are wrong only because the
  harness clears popped slots, whereas our `ASArray::pop` decrements `length` and leaves the
  element buffer intact. Add a "raw buffer read past `length`" model and re-sweep. A single
  bubble pass over a snapshot already yields `[2,3,4,1]`.
- **Dead ends, do not retry:** every quicksort variant (avmplus midpoint-pivot and our
  leftmost-pivot), under snapshot+full-writeback, snapshot+live-length-writeback, and in-place.
  None produces the split.
- **Prize:** `array-v5` + `array-v6` promote on M3 alone (+2, one of them an ignore-list prune);
  `array-v7`/`-v8` need M3 **plus** `:253` (§5.3) for +2 more.

---

## 7. Regression sweep

Method: stash-diff over **actual output**, run sequentially in the worktree against copied test
dirs (never `--tests-dir` at the main tree), `SWFRECOMP_COMPILE_TIMEOUT=2400`.
Scope chosen for blast radius — every AVM1 array/sort path, the two `regression` comparator
fixtures named in `_invoke_sort_comparator`'s own comment, the gnash `Function-vN`/`Instance-vN`
rows (Instance-vN is the test the `new Object(primitive)` prototype template exists for, i.e.
M4's nearest neighbour), and the whole `regression` suite.

### 7.1 Results — clean

| group | tests | result |
|---|---|---|
| `regression` suite (full) | **95** | **95/95 PASS**, `vs prev: no changes` on every row and on the final summary |
| `avm1` array/sort battery | 18 | **18/18 PASS** — `array_sort`, `array_sort_random`, `array_call_method`, `array_concat`, `array_constructor`, `array_enumerate`, `array_length`, `array_properties`, `array_prototyping`, `array_reverse`, `array_shift`, `array_slice`, `array_splice`, `array_trivial`, `array_unshift`, `global_array`, `init_array_invalid`, `object_prototypes` |
| `avm1` M4 neighbours | 1 | `new_class_prototype_getter` **PASS** |
| `from_gnash/actionscript.all` | 6 | `Function-v6/-v7/-v8`, `Instance-v6/-v7/-v8` — **6/6 PASS** |
| `from_gnash` array ladder | 4 | `array-v5/-v6/-v7/-v8` — `output_mismatch` before **and** after, strictly fewer diff lines (§4.1) |

**`pass → ruffle_matched` moves: NONE.** Every row above that was `pass` is still `pass`; the
four array rows were `output_mismatch` on both legs and neither promoted nor demoted. There is
no row anywhere in the sweep whose status changed in either direction.

The `regression` suite's own runner prints a `vs prev` diff per test against its stored
`_results/results.json`; it reported **`no changes` on all 95** plus the final summary line, which
is an independent check on top of the raw PASS counts. `regression` includes the two fixtures
`_invoke_sort_comparator`'s comment names as its canaries (`sort_comparator_captured_scope`,
`sort_comparator_type1_args`) and the whole `*_type1_args` family that exercises AVM1 argument
binding through sorts, watches and callbacks.

**Six `RECOMP_FAIL` rows are worktree artifacts, not regressions** — see §9.

---

## 8. Next mechanisms, in priority order

1. **M3 — the sort-UB split.** Gates `array-v5` and `array-v6` completely and `array-v7`/`-v8`
   jointly with `:253`. Worth **+3 graded rows plus an ignore-list prune**. Full scoping brief:
   **§6.5**. Not started, by agreement.
2. **`:253` — `gaparray.hasOwnProperty('2')`, SWF7+ only.** One line on `array-v7`/`-v8`, and
   **an unidentified mechanism, named as unidentified rather than folded into M1** (§5.3).
   Flash's own-set after the SWF7+ sort is `{0,1,2,4,16}`; sources ∪ destinations gives only
   `{0,1,4,16}`, so index 2 becomes own through something else — most likely the ECMA
   `{defined | undefined | missing}` three-way partition, in which an own-but-undefined slot
   sorts after the defined values and before the holes. Cheap to confirm: dump `enum_keys`
   order around `array.as:211`. The observable to match is Flash's for-in order `0,1,16,2,4`
   ⇒ insertion order `4,2,16,1,0`.
3. **The AVM1 `_global` indirection defect (general form).** `actionGetVariable` answers
   builtin class names from the constructor table and never consults `_global`'s own
   properties — proved with a probe that printed the engine constructor pointer on every call
   while `_global`'s own `"Array"` held the user function. The general fix is the completion
   mechanism for `avm1/globals_monkeypatch` (s19 §N3) and would subsume patch 2's workaround.
   Corpus-wide blast radius — an arc, and it needs its own CI leg.

---

## 9. Scope and hygiene

- **Files edited:** `SWFModernRuntime/src/actionmodern/action.c` only, in two disjoint regions —
  `actionNewObject`'s Array arm (~L57449) and `callArrayMethod`'s standard-sort block
  (~L66278/L66384). Both are clear of the three sibling reservations named in my brief
  (`propertyCoerceToNumber` ~15499-15600 and its call sites ~46519/~59801; the `XML.load`/`getURL`
  paths; the hitTest/mask paths). No textual overlap.
- **No new source files**, so no `verify_output.py` source-list / CMakeLists / Emscripten edits
  are needed.
- **Known cost of patch 2, flagged deliberately.** Every `new Array(...)` now does one `_global`
  variable lookup plus one `getProperty` on the global object. This is the `ActionNewObject`
  path only — array *literals* (`ActionInitArray`) are untouched, and literals are what
  AVM1 game code overwhelmingly uses — so the hot path is unaffected. If a profile ever shows
  it, the clean mitigation is a dirty-flag set when anything writes `_global.Array`, checked
  before the lookup; I did not add one speculatively. Patch 1 costs one `n`-byte allocation and
  two `O(n)` passes per `sort()`, both dwarfed by the sort itself.
- **`avm1/{external_interface,global_instance_decls,global_proto_decls,global_proto_decls_delete}`
  and `avm1/{_investigation,_results}` report `RECOMP_FAIL` in my sweep. These are worktree
  artifacts, not regressions**: those four directories ship tracked `RecompiledScripts/` +
  `test.toml` but their `test.swf` is gitignored (CI downloads it), so a fresh worktree has no
  SWF to recompile — I verified `test.swf` is MISSING in all four. They fail identically at
  baseline and are outside my change's reach. (`global_proto_decls*` also belong to
  w1-avm1-globals' family, not mine.)
- I did **not** edit `action.c:66266-66278`'s comment, `ACCEPTED_DIFFS.md`, the ignore list or
  `ARRAY_V6_V8_PLAN.md`, although §6 says they are now wrong. They are all statements about M3,
  which is still open, and I would rather the coordinator rewrite them once with the M3 ruling
  than have me half-update them inside a patch that does not resolve M3.
- Worked entirely in `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/s20-arraysort`; test dirs
  copied into its canonical suite paths; `--recompile` on first use; never `--tests-dir` at the
  main tree; no `git stash`; no commits or pushes.
