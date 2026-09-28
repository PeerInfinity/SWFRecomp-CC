# w2-arraysort-m3: the array sort-UB split is solved, and array-v5..v8 all promote

## NEW FILES (stage these by name, because `git add -u` drops them)

- `SWFRecompDocs/plans/session21-fanout-reports/w2-arraysort-m3-report.md` (this file)
- `SWFRecompDocs/plans/session21-fanout-reports/w2-arraysort-m3.patch`

There are no new source files. The patch edits three tracked files:
- `SWFModernRuntime/src/actionmodern/action.c`: only the standard-sort block in `callArrayMethod` (the `sort` method, without the UNIQUESORT or RETURNINDEXEDARRAY flags).
- `ruffle-tests/tests/swfs/from_gnash/actionscript.all/ignored_tests.txt`: the `array-v5` entry is pruned because its own PRUNE CRITERION is now met.
- `ruffle-tests/tests/swfs/from_gnash/_investigation/ACCEPTED_DIFFS.md`: the `array-v5` entry is marked RESOLVED, with the old text kept as history.

The change is runtime-only. Landing it needs no `--recompile`. The patch was built from worktree `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-ab5549fbce3bd8255`, based on `263427d08`. `git apply --check -R` against the worktree is clean.

---

## 1. Verdict: GO, with four priced flips

| test | CI baseline (graphics run `35780999591`) | after (worktree, local) |
|---|---|---|
| `from_gnash/actionscript.all/array-v5` | output_mismatch 553/560 (on the ignore list) | **ruffle_matched**, 555/560. The ignore entry is pruned. |
| `from_gnash/actionscript.all/array-v6` | output_mismatch 627/644 | **ruffle_matched**, 629/644 |
| `from_gnash/actionscript.all/array-v7` | output_mismatch 634/654 | **ruffle_matched**, 640/654 (both no-graphics and **graphics**) |
| `from_gnash/actionscript.all/array-v8` | output_mismatch 634/654 | **ruffle_matched**, 640/654 |

The priced yield is **+4 effective**: the brief's +2 for v5/v6 on M3 alone, plus +2 for v7/v8. The v7/v8 rows needed M3 **and** `array.as:253`. The same rule fixes `:253`, so no second mechanism was needed. array-v5 is +1 in the graded count only once its ignore entry is removed, which the patch does. The coordinator should read the actual number with `corpus_status_diff.py` after CI.

On all four rows, `:317` (`pop(); return -1` → length 0), `:324` (length 4) and `:325` ("2,3,4,1") are **all PASSED**. On v7/v8, `:253` (`gaparray.hasOwnProperty('2')`) is also PASSED. The remaining diff lines on every row (`:444`, `:1394`, `:1628-1636`, `:1763-1793`, and the Dejagnu counters) are inside Ruffle's diff set, which is why the runner grades `RUFFLE_MATCHED`.

Rule 3 (known_failure): these rows have `known_failure = true`. The moves are `output_mismatch → ruffle_matched`, not `pass → ruffle_matched`, so none of them is a regression. We match **Flash** on `:317`, `:324/325` and `:253`. Ruffle fails `:317` and `:253`. The policy "match Flash over Ruffle" holds on every line.

## 2. The mechanism: sort a snapshot, write back only the changed positions

Flash's AVM1 `Array.sort` behaves like this:
1. It sorts a **snapshot** of the elements using the same leftmost-pivot quicksort that Ruffle's `core/src/avm1/globals/array.rs::qsort` uses. Our partition code already had the same shape.
2. It tracks which original index each slot came from.
3. It writes back **only the positions whose origin changed** (`origin[i] != i`). Positions that did not change are never touched.

Ruffle does steps 1 and 2 but writes back **every** position, which is its only error. Our old code sorted the live array in place, which gave the wrong answer in the opposite direction.

What this one rule produces:

| observation | Flash | this model | Ruffle (write all) | old ours (in place) |
|---|---|---|---|---|
| `:317` `pop(); return -1` | len 0 | identity permutation, nothing written: **len 0** | len 4 | len 0 |
| `:324/325` `pop(); return +1` | len 4, "2,3,4,1" | rotation, all 4 positions written, array re-grown: **len 4, "2,3,4,1"** | len 4, "2,3,4,1" | len 0, "" |
| `:305` bogus2 `return 1` | rotate left by 1 | same | same | same |
| `:297` testCmp call count | 7 | **7** | 7 | 7 |
| SWF6 sparse `gaparray.sort()` own-property set (`:245-248`) | {4,15,16} | **{4,15,16}** | all 17 | {4,15,16} (via the s20 M1 hack) |
| SWF7+ own-property set (`:249-253`) | {0,1,2,4,16} | **{0,1,2,4,16}** | all 17 | {0,1,4,16}: **`:253` fails** |

The last row is the one to notice. The s20 report called `:253` an "unidentified mechanism". It is the same write-back rule: the quicksort's first partition swaps a hole from index 0 into index 2. That write makes index 2 an own property whose value is undefined. The s20 M1 own-property patch (which promoted "was own, now a hole" to undefined) is **subsumed** by this rule and has been removed.

### 2.1 Hard gate: both legs reproduced in a standalone harness before touching `action.c`

The harness is `<scratchpad>/w2-arraysort-m3/m3.c`: about 90 lines of C, with a live array whose `pop()` does not clear the buffer. It runs Ruffle's qsort over a snapshot, tracks origins, and switches between two write-back models. Its output with the changed-only model:

```
:317 bogus5 pop;-1 (want len=0)                    len=0 []
:324/325 bogus6 pop;+1 (want len=4 2,3,4,1)        len=4 [2,3,4,1]
:295/297 testCmp (Flash calls=7)                   [But,alphabet,Different,capitalization] ncmp=7
:301/:305/:309/:313 bogus1..4                      all match Flash's expected strings
gaparray v6 (want [15]=16 [16]=4 own={4,15,16})    own={4,15,16}
gaparray v7 (want [0]=16 [1]=4 own={0,1,2,4,16})   own={0,1,2,4,16}
```

With the write-everything model (`m3 all`), the same harness reproduces Ruffle exactly: len 4 on `:317`, and all 17 indices own. So the only variable is the write-back rule. The gate passed within the first hour, and no search was needed.

## 3. Refutations

1. **"An in-place bubble-family sort over a non-clearing `pop()`" (the brief's strongest lead, from s20 §2.1): refuted as unnecessary.** The algorithm was never the problem. The leftmost-pivot quicksort that both we and Ruffle already run produces the Flash contents on every leg. Only the write-back rule differed.
2. **"Flash's 0-vs-4 split is unreachable from a quicksort under any write-back rule" (s20 §2): wrong for the leftmost-pivot qsort.** The s20 argument assumed a write-back that depends only on length and `iFirstAbsent`. A write-back that depends on the permutation separates the two legs: the `-1` leg is the identity and the `+1` leg is a rotation. That argument does still hold for avmplus's midpoint-pivot qsort, which was the wrong oracle anyway.
3. **"`:253` is a separate, unidentified mechanism" (s20 §5.3 and §8.2): refuted.** It is M3.
4. **The brief's pricing of v7/v8 as "M3 plus `:253`": correct in shape, but both turn out to be one mechanism.** The +2 for v7/v8 comes from this same patch.

## 4. The patch

In `callArrayMethod`, the standard-sort block is replaced. It used to sort in place over `arr->elements`, and M1 then re-owned holes afterwards. It now works as follows:

- It allocates `_qbuf` (a snapshot, n ActionVars), `_qorig` (n u32 origins) and the range stack. Snapshot slots at or past `arr->capacity` are treated as holes, because `arr.length = N` can exceed capacity.
- The partition loop is **unchanged**: same scans, same comparator calls, same `n*4+100` guard against non-converging comparators, same `g_execution_halted` checks. Every swap now moves the origin together with the value (`_QS_SWAP`). DESCENDING still reverses after the sort, and origins reverse with it.
- **Write-back:** for each `i` with `_qorig[i] != i`:
  - A hole in the snapshot is written as UNDEFINED, so the position becomes own with value undefined.
  - If `i` is at or past the live length (the comparator popped), the position is first re-grown through `setArrayElement(undefined)`. That call fills any gap with holes, bumps the length and tracks the key. The raw value is then written.
  - If `i` is within the length and was a hole, the key is added to `arrayTrackKey`, but only when the array already has `enum_keys`. Without that, for-in would skip the new own index.
  - Writes are raw copies, as the old in-place swaps were. For a comparator that does not mutate the array, this is an exact, refcount-neutral permutation.

**Side benefit:** the comparator now receives pointers into a private buffer. The old code cached `_qbuf = arr->elements` and handed out pointers into it, so a comparator that pushed to the array (and forced a `realloc`) left the sort reading freed memory. **Known residual:** a comparator that *overwrites* an element holding an owned heap string (`arr[i] = …`) frees that string while the snapshot still holds a copy of it. This is pathological, and it is no worse than the old code's dangling pivot copy. It is noted in the report only, not in the code.

**Cost:** one n×16-byte and one n×4-byte allocation per sort, plus one O(n) comparison pass at write-back. Unchanged positions are never written, so the write-back does less work than before.

The UNIQUESORT and RETURNINDEXEDARRAY paths use an index sort and are untouched. `sortOn` is untouched.

## 5. Tests run

All runs were in the worktree, with test directories copied into canonical suite paths and `--recompile` on first use. They ran sequentially with `SWFRECOMP_COMPILE_TIMEOUT=2400` on a machine at load average about 17. Logs and actual output are in `<scratchpad>/w2-arraysort-m3/`.

| group | tests | result (after) | baseline |
|---|---|---|---|
| gnash array ladder | array-v5/-v6/-v7/-v8 (no-graphics), plus array-v7 (**graphics**) | all **ruffle_matched** | all output_mismatch |
| `regression` sort/array fixtures | sort_comparator_captured_scope, sort_comparator_type1_args, array_method_type1_args, array_element_type1_args | 4/4 PASS | pass |
| avm1 array/sort battery | array_sort, array_sort_random, array_enumerate, array_call_method, array_prototyping, array_reverse, array_properties, global_array, object_prototypes | 9/9 PASS | pass |
| avm1 dense-sort users | bitmap_data_thorough/compare, bitmap_data_thorough/getPixel | 2/2 PASS | pass |
| gnash `.sort(` users (grep of `testsuite/actionscript.all/*.as`) | case-v6, case-v7, Function-v6 | PASS | pass |
| | Global-v6 201/210, String-v6 368/377, XMLNode-v6 204/207 | ruffle_matched, with matching lines **identical** to the CI baseline | ruffle_matched, same counts |

There were no status moves other than the four headline rows. There is no `pass → ruffle_matched` move anywhere, and no matching-line count decreased.

Not run: the full `regression` suite (95 tests). I ran only the four sort/array fixtures, because the machine was heavily loaded and array compiles took about 10 minutes each. The behaviour change applies only to calls to the standard `sort` method, so CI `all` covers the rest. No new `regression/` fixture was added: the corpus already contains Flash-oracle expected output for this exact behaviour (the gnash `output.txt` is Flash's).

## 6. Documentation changes (included in the patch)

- `from_gnash/actionscript.all/ignored_tests.txt`: the `array-v5` block is replaced by a dated removal note, following the file's own convention for pruned entries.
- `from_gnash/_investigation/ACCEPTED_DIFFS.md`: the `array-v5` heading is struck through as RESOLVED 2026-09-28, a resolution note sits above the old record, and the history is kept. The file has no summary-table row for array-v5, so no table edit was needed.
- **Not edited (coordinator's call):**
  - `from_gnash/_investigation/CURRENT_STATUS.md`.
  - `incomplete/ARRAY_V5_PLAN.md` and `incomplete/ARRAY_V6_V8_PLAN.md`. Both can move to `complete/` for their sort phases.
  - The arc doc `polish-sweep-arc.md` §21.5 (the M3 bullet is closed).
  - The s20 `action.c` comment replacement text from s20 §6.1 is obsolete: the new block carries its own comment.

## 7. New unclaimed leads

1. **`array.as:1394` (`a.length == 4`, v6+) and `:444` (`c.length == 3`, v5/v6).** Both engines miss these against Flash, so they are "free" under ruffle_matched. They may be cheap real fixes: if any of their operations call `sort`, the same write-back family might apply. Not investigated.
2. **`:1628-1636` `traceProps` enumeration order.** This is a for-in order divergence that both engines share. The sort now tracks keys for holes that become own, so an enumeration-order model might be within reach. Not investigated.
3. **The UNIQUESORT and RETURNINDEXEDARRAY index-sort path** still writes back all n positions when it commits. By the same Flash rule, it should probably write only changed positions. No corpus row is known to exercise this with a mutating comparator or a sparse array, so it has no yield; it is a correctness note only.
4. **`sortOn`** probably shares Flash's sort core and write-back rule. Its code was not audited.
