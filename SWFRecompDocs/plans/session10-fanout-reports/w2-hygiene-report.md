# wave-2 `w2-hygiene` — per-item ledger

Worktree: `.claude/worktrees/agent-a305ff2ed22991185`, based on `b007ee50d`.
All baselines re-derived from the per-suite `_results/results_graphics.json`,
all stamped `git_sha = feb8882b09e238e91ab6444099d6cca237e3a4f9`.
No commits, no pushes. Patch: `w2-hygiene.patch`.

**Headline:** measured **+2 tests** (`heavy_tesselation`, `e12_1`), **27/27
canaries green, zero regressions**, **219 stale ignore entries pruned** across
7 lists. Item 3 landed at **half size**: one of the two requested
ACCEPTED_DIFFS entries is **not warranted** — writing it would have wrongly
dispositioned a live, fixable 4-line target. Item 1 needed a **larger** timeout
than the brief assumed (300 s, not 120 s; 120 s was measured to still fail).
Details below.

| item | status | measured effect |
|---|---|---|
| 1 recompile timeout | DONE | `heavy_tesselation` `recomp_fail` → **PASS** (+1) |
| 2 `e12_1` dxns + QName | DONE | `e12_1` `output_mismatch` → **PASS** (+1); 27/27 canaries green |
| 3 ACCEPTED_DIFFS | HALF | `eforin_001`/`eforin_002` entry written; `PerspectiveProjectionClass` **refuted** |
| 4 ignore prune | DONE | 219 entries removed, 7 lists; 0 graded movement (by design) |

---

## Item 1 — harness recompile timeout — **DONE, verified PASS**

| | |
|---|---|
| Baseline | `visual/simple_shapes/heavy_tesselation` = `recomp_fail`, `phases.recomp = 30.145` (the cap) |
| Change | `ruffle-tests/verify_output.py:1907` default `30` → **`300`** |
| Result | **PASS** `[r=176.55s c=268.47s x=0.01s]` |

### Shape chosen: raised default, NOT a per-test `test.toml` key

The report offered both. The per-test key is **not durable**:
`ruffle-tests/download_tests.sh:159` copies `test.swf output.txt test.toml
input.json` verbatim from the upstream corpus, so any `recompile_timeout` key
added to a mirrored test's `test.toml` is silently clobbered on the next
re-sync. (This is also why no corpus `test.toml` uses the existing
`mock_date_time` override — grep finds zero.) That rationale is recorded in
the code comment. The `SWFRECOMP_RECOMPILE_TIMEOUT` env override is kept, and
the timeout is not removed.

### Why 300 and not the report's ~120 — measured, and it matters

The report's "recompiles in 54.5 s" is a **wall clock on an idle machine**. I
first implemented 120 s and **the test still timed out at 120.27 s**. Direct
measurement of the recompile alone (`/usr/bin/time -v`, exit 0):

```
User time (seconds): 104.24
System time (seconds): 14.32
Percent of CPU this job got: 57%
Elapsed (wall clock) time: 3:25.11
```

**≈119 s of CPU**, 205 s wall at load-18 on 8 cores. The verified end-to-end
run then reported `r=176.55s`. So the same work spans 55 s → 205 s of wall
clock purely with machine contention: any cap near the CPU figure is a
load-dependent flake generator. 300 s keeps a real cap (a runaway recompile is
still killed) with ~2.5x headroom over the slowest known-good corpus test.
Raising it costs wall clock only on runs that were going to fail anyway.

**Expected effect on CI: +1 (`visual` suite), and the `recomp_fail` bucket
leaves the histogram.**

---

## Item 2 — `e12_1` (dxns + single-arg QName) — **DONE, canaries below**

No recompiler change; runtime only; no cmake rebuild needed (`verify_output.py`
compiles the runtime per test).

| baseline | |
|---|---|
| `from_avmplus/e4x/Statements/e12_1` | `output_mismatch`, 3 of 17 lines differ |

### 2a — `avm2_call_function_obj` had no dxns handling
`SWFModernRuntime/src/avm2/avm2_class.c` (~:1129). Confirmed the report's
claim that this is the *other* of exactly two `Avm2Activation act;`
construction sites, and the one script-level `function` declarations and
closures go through. Added the same save / reset-if-`SET_DXNS` / restore
bracket that `avm2_call_method_ref` already had, keyed off
`fnobj->fn_method`.

### 2b — single-arg `QName` must capture the DXNS
`SWFModernRuntime/src/avm2/avm2_nsqname.c`, `qname_construct`, `argc < 2`
branch: `uri = empty;  // public namespace` →
`const Avm2String* d = avm2_dxns_uri(ctx); uri = (d != NULL) ? d : empty;`
(ECMA-357 §13.3.2 step 4b). The `"*"` any-namespace arm is untouched. With no
`default xml namespace` in effect `ctx->dxns` is NULL, so this still yields
`""` in the common case — which is why the 18 single-arg-QName canaries are
inert under it.

### Two small correctness riders in the same hunk
* `AVM2_METHOD_SET_DXNS = 1 << 6` named in the `avm2_abc.h` flag enum; both
  call sites now use it instead of a bare `(1u << 6)`.
* Corrected a **false comment** at `avm2_main.h:49-53`: it claimed dxns "is
  restored on exception unwinds via the try-frame snapshot". There is no such
  snapshot (`grep dxns` finds nothing in `avm2_error.c`). The comment now says
  so, and names both call sites.

### Result: **`from_avmplus/e4x/Statements/e12_1` → PASS** (was `output_mismatch`, 14/17)

**+1, measured.** Both halves were needed and both landed.

### Canary results — **27 run, 27 PASS, zero regressions**

All 27 were `pass` at baseline and are `pass` after the change. Ran more than
the brief's "representative 6" because the runtime change touches a hot path
(every function call now reads a method flag).

`from_avmplus` (15/15 PASS) — the single-arg-`QName` and DXNS canaries the
leads report named:

```
[ 1/15] e4x/Expressions/e11_1_1 ..... PASS      [ 9/15] e4x/Types/e9_1_1_9 ..... PASS
[ 2/15] e4x/Expressions/e11_3_1 ..... PASS      [10/15] e4x/XML/e13_4_4_22 ..... PASS
[ 3/15] e4x/Expressions/e11_5_1 ..... PASS      [11/15] e4x/XML/e13_4_4_28 ..... PASS
[ 4/15] e4x/QName/e13_3_1 ........... PASS      [12/15] e4x/XML/e13_4_4_34 ..... PASS
[ 5/15] e4x/QName/e13_3_2 ........... PASS      [13/15] e4x/XML/e13_4_4_35 ..... PASS
[ 6/15] e4x/QName/e13_3_4_2 ......... PASS      [14/15] e4x/XML/e13_4_4_4 ...... PASS
[ 7/15] e4x/QName/e13_3_5 ........... PASS      [15/15] e4x/XMLList/e13_5_4_17 . PASS
[ 8/15] e4x/Statements/e12_1 ........ PASS  <-- THE TARGET (was output_mismatch)
Total 15, Pass 15 (100.0%), Fail 0
```

`avm2` (12/12 PASS):

```
[ 1/12] error_geterrormessage ................... PASS   (DXNS canary)
[ 2/12] flash_xml_namespace ..................... PASS   (DXNS canary)
[ 3/12] qname_as_lazy_name_attribute_multiname .. PASS
[ 4/12] qname_constr ............................ PASS
[ 5/12] qname_enumeration ....................... PASS
[ 6/12] qname_indexing .......................... PASS
[ 7/12] qname_tostring .......................... PASS
[ 8/12] qname_valueof ........................... PASS
[ 9/12] string_relational_compare ............... PASS   (item-4 prune evidence)
[10/12] verify_dxns_without_flag ................ PASS   (DXNS canary)
[11/12] xml_descendants ......................... PASS   (DXNS canary)
[12/12] xml_socket .............................. PASS   (item-4 prune evidence)
Total 12, Pass 12 (100.0%), Fail 0
```

Two of these double as item-4 evidence: `string_relational_compare` and
`xml_socket` are pruned from the global ignore list and both confirm `pass`
locally in the `avm2` suite (`string_relational_compare` was also run and
passed in `avm1`).

---

## Item 3 — new ACCEPTED_DIFFS entries — **ONE of two written; the other is REFUTED**

### 3a — `eforin_001` / `eforin_002` — **entry written, claim confirmed and strengthened**

Wrote **Category 12: Implementation-Defined `for...in` Enumeration Order** in
`ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md`, plus 2 summary-table
rows, plus a **new** `ruffle-tests/tests/swfs/from_avmplus/ignored_tests.txt`
(the suite had none; `filter_results.py` picks it up automatically because it
looks for `ignored_tests.txt` beside `_results/`).

Evidence I re-derived (all from the results file's stored outputs + the test
sources), which goes beyond the triage note:

* **Every line on both sides is `PASSED!`** — the assertions all succeed in
  both engines; *only the emission order differs*. That is the diagnostic that
  identifies this class, and I put it in the doc.
* `eforin_001` (4 of 16 lines): literal
  `{ length:4, company:"netscape", year:2000, 0:"zero" }` →
  avmplus `0, company, year, length`; Ruffle `year, company, length, 0`; ours
  `0, year, company, length`; insertion order `length, company, year, 0`.
  **Three engines, three orders, none of them insertion order.**
* `eforin_002` (10 of 10 lines) — the report treated this only as a "sibling";
  it is the same mechanism and **the stronger case**: object built by
  successive assignment (`Test.as:22-26`) so insertion order is
  `value, valueOf, toString, toNumber, toBoolean`, which is **exactly ours**.
  avmplus gives `toString, value, toNumber, toBoolean, valueOf`, Ruffle gives
  `toBoolean, value, toString, valueOf, toNumber`. Our order is the *most*
  defensible of the three (ES2015 `OrdinaryOwnPropertyKeys`).
* `ruffle_matched` is unreachable: promotion needs our diff set ⊆ Ruffle's, and
  Ruffle's order differs from ours as well as from avmplus's.

### 3b — `PerspectiveProjectionClass` — **NO ENTRY WRITTEN. The premise is false.**

**Do not file this, and put it back on the board.** The wave-1 axis-2 "trap"
rests on `focalLength` being a mutually-exclusive f32-vs-double expectation.
It is not — **the test explicitly tolerates it**. Its own `test.toml`:

```toml
[approximations]
number_patterns = [
# Both FP 32,0,0,465 (for Linux) and FP 32 (for Windows) produced slightly different numbers in some environment. However, the original trace from mozilla/shumway is respected in the output file.
    'focalLength: ([0-9.]+)'
]
max_relative = 0.0000001
```

Our `480.2455444336` vs expected `480.2455317428` is a **relative difference
of 2.64e-8**, inside the declared `1e-7`. Same for `209.7749023438` vs
`209.7749077943` (2.60e-8). Both **already match**. Confirmed arithmetically,
and confirmed structurally: the result row says `matching_lines: 16` of 20,
i.e. 4 diffs — if the two focalLength lines really differed there would be 6.

So there is **no oracle conflict with `avm2/perspective_projection`**, and
`avm2_display.c:9729`'s deliberate `(double)(float)` narrowing is not under
threat either way. (For the record, that avm2 test pins the f32 value on **12**
lines, not 10, plus the whole ~180-line `FOV to FL` block, e.g.
`28647.1640625` — exactly f32-representable. It just isn't in conflict.)

The 4 real diffs are all genuine, fixable behaviour:

| # | expected | ours |
|---|---|---|
| 1 | `perspectiveProjection returns a clone: true` | `false` |
| 2 | `Initial root projectionCenter: (x=250, y=187.5)` | `(x=250, y=250)` |
| 3 | `changed root fieldOfView: 100` | `55` |
| 4 | `changed root focalLength: 209.7749077943` | `480.2455444336` |

Diffs 3 and 4 are one mechanism (a write to the root's
`perspectiveProjection.fieldOfView` does not persist — consistent with diff 1,
the getter not returning a clone / not writing back). So this is plausibly a
**2-mechanism, 4-line, +1 near-pass**, not a permanent diff. It should go back
into the live pool for a future wave.

---

## Item 4 — ignore-list prune — **DONE**

Criterion (the leads report's, and the conservative one): an entry is stale iff
its status in the owning suite's `_results/results_graphics.json` at
`feb8882b0` is **exactly `pass`**. `ruffle_matched` entries were **kept** — we
match Ruffle but not Flash there, which is a real remaining divergence and a
legitimate thing to filter. A dated header comment stating the date, the
criterion, and the bucket arithmetic went into every file touched.

### Exact counts I measured (not the brief's)

| list | before | removed | after | notes |
|---|---|---|---|---|
| `avm2/ignored_tests.txt` | 223 | **172** | 51 | 173 were `pass`; `bytearray_oom` kept |
| `from_shumway/ignored_tests.txt` | 46 | **24** | 22 | |
| `from_shumway/avm1/ignored_tests.txt` | 3 | **2** | 1 | `hitarea` (`ruffle_matched`) kept |
| `from_gnash/actionscript.all/ignored_tests.txt` | 7 | **3** | 4 | `getvariable-v5/v7/v8` |
| `from_gnash/misc-ming.all/ignored_tests.txt` | 2 | **1** | 1 | `opcode_guard_test` |
| `from_gnash/misc-swfc.all/ignored_tests.txt` | 2 | **0** | 2 | re-triaged, both still fail; note added |
| **GLOBAL** `ruffle-tests/ignored_tests.txt` | 43 | **17** | 26 | see traps below |
| **total removed** | | **219** | | |

Verification: re-running the measurement over the pruned tree leaves exactly
**2** "stale" rows — `avm2/bytearray_oom` and global `netstream_play_flv_screen`
— both deliberate keeps, both documented in place.

### Reconciliation with the brief's "249"

The brief's 249 = 197 (avm2) + 24 (avm1) + 28 (from_shumway). Those counted
`pass + ruffle_matched` as "now passing":

* avm2 197 = 173 `pass` + 24 `ruffle_matched`. I pruned 172 (`bytearray_oom` held).
* "avm1 24 of 43" is the **global** list (43 entries), not an avm1-suite list —
  there is no `avm1/ignored_tests.txt`. Of its 43, **18** are `pass` everywhere
  and 2 never appear in results. I pruned 17.
* from_shumway 28 = 24 `pass` + 4 `ruffle_matched`. I pruned 24.

### Three findings that changed what I pruned

1. **A GLOBAL entry is also an IMAGE-axis disposition.** `scripts/image_triage.py`
   returns `image_axis=True` for `test in ignored_global`, but
   `image_axis=False` ("TRACE-axis triage, kept on the board") for a
   *suite-local* list. So `netstream_play_flv_screen` — trace `pass`, image
   comparison **still failing**, and the entry that dispositions it — **must
   not be pruned** even though it meets the trace criterion. I checked all 18
   global candidates against `image_results_graphics.json`; it is the only one
   with any image comparison. Both traps are now written into the file header
   so the next pruner does not repeat this.
2. **`shared_object` / `shared_object_self_ref` have NOT stopped existing.**
   The brief says they no longer exist. The directories are present in the
   mirror *and* upstream at `~/CC/ruffle/tests/tests/swfs/avm1/`; they ship
   `output1.txt`/`output2.txt` and **no `output.txt`**, so `discover_tests()`
   skips them and they never reach any results file. The entries are inert;
   I kept them (the comment explaining the two-run format is the only record
   of why they are unrunnable) and documented the distinction.
3. **`date` cannot be pruned.** avm1 `output_mismatch`, avm2 `pass`. The global
   list has no per-suite scoping, so the entry stays and its 4 live
   ACCEPTED_DIFFS entries stay accurate. The brief listed it among "3
   now-passing avm2 tests"; only the avm2 half passes.

### Disposition docs edited in the same change (required by the brief)

* **`string_relational_compare`** (now `pass` in **both** avm1 and avm2) —
  `RUFFLE_VS_FLASH_DIFFERENCES.md` §"String Relational Comparison" marked
  **RESOLVED**. Its premise was wrong: it claimed Flash compares by UTF-16
  code unit and defended our code-unit comparison as Flash-correct. AVM1
  stores UTF-8 and Flash's relational operators compare those bytes =
  **code-point** order; Flash and Ruffle agreed and *we* were the outlier. The
  runtime now compares by code point in `u16_cmp`
  (`SWFModernRuntime/src/actionmodern/action.c:284-292`), whose own comment
  records the same reasoning. Superseded text retained for traceability.
* **`string_paths_reference_launder`** (now `pass` per the results file; I
  started a local re-run but stopped it to stay within the 2-process budget
  on the contended machine) — `ACCEPTED_DIFFS.md`
  Category 7 marked **RESOLVED**, summary-table row struck through. Its error
  was inferring "Ruffle `known_failure` ⇒ no valid reference"; the test is
  graded against Flash's `output.txt`, which is a perfectly good oracle
  (memory `t2`: *known_failure upstream = Ruffle NOT oracle*). We now match
  Flash where Ruffle does not. Kept as a worked example of that inference
  being wrong.
* **`xml_socket`** (now `pass` in both suites) — no disposition-doc entry
  exists; pruned from the global list with an inline note.
* **`from_shumway/avm1/text-bind`** — pruned from the suite-local trace list
  (trace passes). Its *image* rationale stays live in `ACCEPTED_DIFFS.md` and
  the summary table; `image_triage.py` never treated the suite-local entry as
  an image disposition anyway, so the pixel board is unaffected.

### What this does and does not move

Nothing graded. The headline 4176/4424 is the **unfiltered** `effective_pass`
summed over top-level suite result files, and ignored tests are run and counted
there either way. It moves the *filtered* report only, e.g. avm2 filtered
907/997 (91.0%) → 1080/1170 (92.3%). The pixel board is unaffected (finding 1
above is precisely the case where it would not have been).

---

## Patch layout

`w2-hygiene.patch` is one `git diff`; the four items are disjoint by file:

| item | files |
|---|---|
| 1 | `ruffle-tests/verify_output.py` |
| 2 | `SWFModernRuntime/include/avm2/avm2_abc.h`, `include/avm2/avm2_main.h`, `src/avm2/avm2_class.c`, `src/avm2/avm2_nsqname.c` |
| 3 | `.../avm1/_investigation/ACCEPTED_DIFFS.md` (Category 12 + 2 table rows), **new** `.../from_avmplus/ignored_tests.txt` |
| 4 | the 6 other `ignored_tests.txt`, plus the RESOLVED edits in `ACCEPTED_DIFFS.md` / `RUFFLE_VS_FLASH_DIFFERENCES.md` |

Items 3 and 4 both touch `ACCEPTED_DIFFS.md`, but in non-adjacent hunks
(Category 12 + 2 appended table rows vs the Category-7 strike-through and its
table row).

## Notes for the merger

* Item 2 is the only runtime change → CI should be `mode=graphics` with
  **`categories=full`** (it touches AVM2 runtime and the target lives in
  `from_avmplus`, which `categories=all` does not run).
* Item 4 changes only filter inputs; it cannot move an unfiltered number. If a
  filtered number moves *down* after merge, that is a real regression
  surfacing, not the prune.
* `SWFRecomp/build/` was copied into this worktree for item 2 and is not part
  of the patch.
