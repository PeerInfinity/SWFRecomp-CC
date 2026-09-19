# Session 20 · wave 1 · `w1-drift` — upstream-drift audit + ignore-list re-test

**Agent:** `w1-drift` (main tree, **read-only**: no source edits, no commits, no `download_tests.sh`).
**Sources of truth:** `~/CC/ruffle` at `f2aaf0703` (re-confirmed live against
`git ls-remote origin master` during this session — upstream master has **not** moved since the
pull), and `ruffle-tests/tests/swfs/**/_results/results_graphics.json` read fresh
(run `35163868554` @ `2973513c4`, `metadata.timestamp` `2026-09-17T00:25:59Z`).
All local runs: `SWFRECOMP_COMPILE_TIMEOUT=2400`, strictly sequential, `--diff --verbose`,
no-graphics (mode parity is complete per `BRIEFS_COMMON.md`). Logs: `<scratchpad>/w1-drift/`.

---

## 0. HEADLINE

1. **The projected CI name-set delta is EMPTY.** Every drift event the brief asked me to hunt
   already landed upstream *before* the graded run downloaded the corpus. Verified two ways
   (commit timestamps, and a 4 527-row name-set diff that reconciles to **zero** unexplained rows).
   **Nothing in the next CI run's name set will move for upstream reasons** unless Ruffle merges
   something between now and the dispatch. Projection, not a verdict — the CI name-set diff confirms it.
2. **`goto_framescript_queued` is a GO and it is a 4-row cluster at (mostly) ONE mechanism.**
   Priced: **+4 effective** (`swf9`, `swf10`, `swf13`, `goto_framescript_queued_same_frame`), one
   file (`SWFModernRuntime/src/avm2/avm2_display.c`), ~25 LOC + one struct field, plus a second
   ~3-line version gate. This is the cheapest yield on the board by a wide margin.
3. **7 stale ignore entries to prune, free.** Plus 1 entry that upstream drift made *inert*.
4. **3 refutations**, including one that has now cost three sessions in a row (§5).

---

## 1. PART A — projected CI name-set delta: **EMPTY**

### 1.1 The table

| class | count | names |
|---|---|---|
| NEW TEST (denominator +) | **0** | — |
| DELETED TEST (denominator −) | **0** | — |
| EXPECTED-OUTPUT REWRITE | **0** | — |
| TOLERANCE CHANGE (`test.toml`) | **0** | — |
| `known_failure` TOGGLE | **0** | — |

**Caveat, stated explicitly:** this is a *projection* to the next CI dispatch. It is exact as of
upstream master `f2aaf0703`, confirmed live by `git ls-remote` at the time of writing. Anything
Ruffle merges between now and the dispatch is unmodelled. The confirmation is the CI name-set diff
after the run, not this table.

### 1.2 Method and the reconciliation that proves it

* `git diff --name-status 0631814db..f2aaf0703 -- tests/` — the *entire* upstream test-tree delta
  in the range is **21 files in 4 commits**, listed in §1.3. Nothing else changed.
* Upstream test-dir name set (`-name test.swf`, the exact predicate `download_tests.sh` uses):
  **4 437 at `0631814db` → 4 440 at `f2aaf0703`**, the only difference being the
  `goto_framescript_queued` restructure (§2).
* Graded name set from the 24 `results_graphics.json` files (nested suites included — the
  `from_gnash/*.all/` and `from_gnash/misc-ming.all/displaylist_depths/` results live in their own
  `_results/` dirs): **4 527 rows**, exactly the baseline total.
* **Reconciliation:** 4 527 graded − 95 `regression` (ours) = 4 432 upstream-derived rows.
  Upstream 4 440 − 8 = 4 432. The 8 are all standing, documented exclusions, **not drift**:
  * 7 dirs that ship no `output.txt` and so are never discovered:
    `avm1/__framework__`, `avm1/shared_object`, `avm1/shared_object_self_ref`, `avm2/shared_object`,
    `avm2/large_preload_from_bytes/{large_bytearray,nested_load}`, `avm2/large_preload_from_url/large_bytearray`.
  * `from_gnash/misc-swfc.all/gotoFrameFromInterval` — hand-excluded in
    `.github/workflows/ruffle-tests.yml` (`--exclude=gotoFrameFromInterval`), as s18/s19 established.
  All 8 are present at **both** `0631814db` and `f2aaf0703`.
  **Graded-but-not-upstream: zero rows.**
* Byte comparison of the local mirror against upstream `f2aaf0703`: of every
  `output.txt` / `output.ruffle.txt` / `test.toml` / `test.swf` in the tree, **0 differ, 0 missing**.
  The local corpus is exactly upstream, and so is what CI downloads.

### 1.3 Every drift event in the range, with the timing that makes it a non-event

CI's corpus download for the graded run happened *before* `metadata.timestamp`
`2026-09-17T00:25:59Z` (the run lasted 3 297 s, so the download was ≈ `2026-09-16T23:31Z`).
Upstream master at that moment was `74ade973` (`git rev-list -1 --before=…`). **All four
test-touching commits in the range are ancestors of `74ade973`:**

| upstream commit | committed (UTC) | effect | already graded? |
|---|---|---|---|
| `d5b707265` | 2026-09-11 23:07 | deletes flat `avm2/goto_framescript_queued`; adds `swf9`/`swf10`/`swf13` (all three `known_failure`) | **yes** |
| `7e8e2de8a` | 2026-09-15 23:27 | core fix; drops `known_failure` + `output.ruffle.txt` from `swf9`/`swf10`; **rewrites `swf13/output.ruffle.txt`** | **yes** |
| `b20e2fdf9` | 2026-09-15 23:27 | adds `avm2/goto_framescript_queued_same_frame` (4 lines, no `known_failure`) | **yes** |
| `74ade9734` | 2026-09-16 15:38 | `avm1: Resolve TextFormat dynamically` — rewrites `avm1/globals_monkeypatch` `Test.as`/`test.swf`/`output.txt` (**228 → 246 lines**) + `output.ruffle.txt` | **yes** |

Independent confirmation that the graded run saw the *new* files, not the old ones:
* the inventory grades `globals_monkeypatch` at **39/246** — 246 is the post-`74ade973` count
  (pre- was 228);
* the inventory carries `KF`/`RTXT` on `swf13` only, and **not** on `swf9`/`swf10` — exactly the
  post-`7e8e2de8a` state;
* the graded set contains the three `swfN` rows and `…_same_frame`, and does **not** contain a flat
  `avm2/goto_framescript_queued` row.

`git log --since="2026-09-17T00:26Z" f2aaf0703 -- tests/` returns **nothing**. There has been no
upstream test change at all since the graded run's download.

### 1.4 Two real consequences of the drift that are *not* name-set moves

**(a) A stale local test dir that CI does not have.** `download_tests.sh` without `--clean` never
removes anything, so our mirror still holds the deleted flat test:

```
ruffle-tests/tests/swfs/avm2/goto_framescript_queued/{test.swf,test.toml,output.txt,output.ruffle.txt}
```

Those four files are the **only** local-only files inside a graded suite other than the known
project addition `avm1/external_interface/test.toml`. They make `avm2/goto_framescript_queued`
discoverable **locally but never in CI** — a sibling agent running that bare name gets a test that
no longer exists upstream, against a 6-line expectation upstream replaced with 52–59 lines.
*Recommended housekeeping (I deleted nothing): remove those four files.*

**(b) An ignore-list entry that drift made inert.** `ruffle-tests/tests/swfs/avm2/ignored_tests.txt:184`
is `goto_framescript_queued`, filed under "Upstream `known_failure` = true". The name it matches no
longer exists, so it now dispositions nothing, while its **three replacements are un-ignored and
visible in the filtered avm2 report** (+ a fourth, `…_same_frame`). That is a filtered-report
movement caused purely by upstream drift — **do not book it as a regression**. If the cluster is
not fixed, the honest replacement is `goto_framescript_queued/swf13` only (the one variant Ruffle
still fails); `swf9`, `swf10` and `…_same_frame` are **not** `known_failure` and must stay visible.

---

## 2. PART A — `goto_framescript_queued`: **GO**, +4 effective, two mechanisms

### 2.1 What upstream actually did

`d5b707265` **replaced** one 6-line flat test with **three SWF-version variants of one richer
fixture** (`swf9`, `swf10`, `swf13`; shared `Test.as` in the parent dir, 12 frame scripts driving
`gotoAndPlay`/`gotoAndStop`/`play`/`stop` with `frameConstructed`/`exitFrame` listeners), then
`b20e2fdf9` added a **genuinely new, separate** 4-line test `goto_framescript_queued_same_frame`.
So of the four failing rows: **three are restructured** (one old test → three variants) and **one
is new**. The inventory's four rows are correct and are all graded against current expectations.

### 2.2 Mechanism M2 — a queued AVM2 goto must queue its `play`/`stop` too (all 4 rows)

Ruffle `7e8e2de8a` moved the `stop_or_play` application out of `goto_frame` and into
`goto_frame_now`, so that when a goto is deferred (issued while an AVM2 frame script is running)
the `play()`/`stop()` side effect is deferred with it.

**Our runtime is a direct port of the *pre*-fix code.** `SWFModernRuntime/src/avm2/avm2_display.c`,
`mc_goto_frame` (~3236):

```c
	if (stop) ext->playing = 0;
	else ext->playing = 1;
	if (frame < 1) frame = 1;
	avm2_display_mark_frame_work(ctx, obj);
	if (ext->executing_frame_script)
	{ ... ext->queued_goto_frame = frame; ... }
```

— the assignment happens unconditionally, *before* the queued branch. That is the exact line
Ruffle moved. The flush site at ~2588 takes only `queued_goto_frame` and carries no stop/play.

**Measured, this session** (`goto_framescript_queued/swf13`, warm cache):

```
     3  // gotoAndPlay(2)
-    4  frame: 1, isPlaying: false      <- Flash: play() is DEFERRED
+    4  frame: 1, isPlaying: true       <- ours: applied immediately
     5  // stop()
     6  frame: 1, isPlaying: false
     7  ! frameConstructed
-    8  frame: 2, isPlaying: true       <- Flash: the queued goto's play() runs LAST and wins
+    8  frame: 2, isPlaying: false      <- ours: the later stop() won, clip is stopped
```

Line 8 is the whole test. Because we end frame 1 **stopped**, the timeline never advances again and
every remaining line degenerates into an endless `! exitFrame` / `! frameConstructed` stream. The
`15/59`, `17/59`, `11/52` match counts on the board are *one* bug's cascade, not 40 independent diffs.

`goto_framescript_queued_same_frame` isolates the same mechanism in **one line**:

```
     3  // gotoAndStop(2);
-    4  isPlaying: true
+    4  isPlaying: false
```

### 2.3 Mechanism M1 — `MovieClip.isPlaying` is not version-gated (`swf9` + `swf10` only)

The shared `Test.as` does:

```as3
try   { trace("frame: " + currentFrame + ", isPlaying: " + isPlaying); }
catch (e:Error) { trace("frame: " + currentFrame); }   // "Below SWFv13, isPlaying is inaccessible."
```

`swf9`/`swf10` expect the **short** form on every one of their ~13 `frame:` lines. We print the long
form, i.e. `isPlaying` resolves below SWF13 when it must throw:

```
-    2  frame: 1                       (swf10 expected)
+    2  frame: 1, isPlaying: false     (ours)
```

`avm2_display.c:17118` registers the getter unconditionally:
`avm2_builtin_add_getter(ctx, movieclip, "isPlaying", mc_get_is_playing);`
The version data already exists next door — `avm2_globals.c:3676` has
`{ "isPlaying", DT_DESC_ACCESSOR, "Boolean", 0, NULL, 13, ... }` (cf. `currentFrameLabel`'s `10`).
Gating the registration on `ctx->swf_version >= 13` yields a `ReferenceError` (an `Error` subclass),
which the fixture's own `catch` turns into the expected short form. Memory: `version-gate`.

### 2.4 A third, smaller rule `swf9` alone needs

`swf9`'s expected output differs from `swf10`'s only by *where* `! frameConstructed` sits relative
to the post-goto `frame: N` line (Ruffle's SWF≤9 `skip_next_enter_frame` path). We have a
`swf_version <= 9` arm at ~3253, but it **returns without** the `no_op_goto` /
`avm2_display_inner_goto_frame` that both pre- and post-fix Ruffle run there. Worth an explicit look
during the fix; it is the reason `swf9` is the lowest-confidence of the four.

### 2.5 Pricing — attacked

| row | baseline | needs | verdict | confidence |
|---|---|---|---|---|
| `avm2/goto_framescript_queued_same_frame` | `output_mismatch` 3/4 | **M2 only** | → `pass` | **high** — one line, mechanism named and located |
| `avm2/goto_framescript_queued/swf13` | `output_mismatch` 17/59, `KF` | **M2 only** | → `pass` | medium-high — M2 fixes the head; the tail is cascade |
| `avm2/goto_framescript_queued/swf10` | `output_mismatch` 15/59 | **M2 + M1** | → `pass` | medium |
| `avm2/goto_framescript_queued/swf9` | `output_mismatch` 11/52 | **M2 + M1 + §2.4** | → `pass` | medium-low |

* **Do not read the tail line-counts as four independent leads.** Only the first two diff lines of
  each row are load-bearing; everything after is the stall.
* **`swf13` is `known_failure` with an `output.ruffle.txt` — and Ruffle STILL gets our line 4 wrong.**
  `diff swf13/output.txt swf13/output.ruffle.txt` is exactly 3 lines, one of which is
  `frame: 1, isPlaying: false` vs `true` — the same line we fail. Fixing M2 correctly puts us
  **ahead of Ruffle** on this test. Per standing rule 3, target `output.txt`; a `pass` here is a
  legitimate "we match Flash where Ruffle does not" win, and settling for `ruffle_matched` would
  be the wrong ceiling.
* **File ownership:** `avm2_display.c` already has two wave-2 owners. The three ranges M1/M2 need
  (~2580-2600 flush, ~3236-3280 `mc_goto_frame`, ~17118 getter registration) are disjoint from
  w2-evenodd (`gfx_*` ~8695/9212) and w2-gfx-text-smalls (~18630-18665). A third owner is safe if
  told to stay in those three ranges.
* **Scope:** one struct field (`queued_goto_stop`) + ~25 lines in `mc_goto_frame` / the flush site,
  plus ~3 lines for M1. No new files, no recompiler change.

---

## 3. PART B — the ignore lists

`ruffle-tests/ignored_tests.txt` (22 live entries) + 7 per-suite lists (61 more) = **83 live
entries**. Of those: 33 are `ruffle_matched` everywhere they appear (kept by criterion), 9 are
`pass` everywhere (7 prunable — see below), 3 have no results row at all.
Cross-referenced every entry against the graded `results_graphics.json` for the suites the entry
actually applies to (global list → all; suite-local → its own subtree only).
Script + full output: `<scratchpad>/w1-drift/ignore_xref.txt`.

### 3.1 Stale entries to prune — **7, free**

Criterion is each file's **own** documented one (`ruffle-tests/ignored_tests.txt` header 2026-08-01;
`avm2/ignored_tests.txt` header): prune iff the status is exactly **`pass`** in every results file
that contains the name. `ruffle_matched` entries stay by design.

| file:line | entry | status now | note |
|---|---|---|---|
| `avm2/ignored_tests.txt:154` | `displayobject_scrollrect` | **pass** | the inline note still describes a scrollRect residual that is gone |
| `avm2/ignored_tests.txt:166-170` | `all_classes/events/swf9`, `swf10`, `swf11`, `swf12`, `swf30` | **pass** ×5 | in the "upstream `known_failure`" bucket: **5 hidden wins** — we match Flash where Ruffle fails |
| `from_shumway/avm1/ignored_tests.txt:19` | `hitarea` | **pass** | the entry's own text says "`hitarea` is `ruffle_matched` … stays listed". It is no longer `ruffle_matched`. |

**Not prunable, for the record (checked, do not re-raise):**
* `ruffle-tests/ignored_tests.txt:122` `netstream_play_flv_screen` — trace `pass`, but the image
  comparison still **fails** (44 751 excess, `max_diff` 235, re-read from
  `avm1/_results/image_results_graphics.json`). Header trap 1 holds; **keep**.
* `avm2/ignored_tests.txt:206` `bytearray_oom` — `pass`, but records an **upstream** `ignore = true`
  decision, deliberately kept by the 2026-08-01 prune. **Keep.**
* `ruffle-tests/ignored_tests.txt:142-143` `shared_object`, `shared_object_self_ref` — inert by
  design (no `output.txt` upstream), kept as documentation. **Keep.**
* 33 further `ruffle_matched` entries across the lists — kept by criterion (5 global, 23 avm2,
  5 from_shumway).

### 3.2 Made inert by drift — 1

`avm2/ignored_tests.txt:184` `goto_framescript_queued`. See §1.4(b) for what it should become.

### 3.3 Eight claims re-tested — what they actually do today

Selected for weakest / most time-limited rationale. All run locally this session.

| entry | stated rationale | **measured today** | verdict on the claim |
|---|---|---|---|
| `avm1/xml_getbytes` (global:104) | bucket header: *"require network connections or XML HTTP loading"* — a **category claim**, no per-name measurement | `output_mismatch` **9/17**. The 8 bad lines are a pure **phase** error: at *"loading requested"* we already report `27/27/27/27` where Flash reports `0 / undefined / 0 / undefined`; at *"received data"* we report `undefined ×4` where Flash reports `27 ×4`. Values correct, timing inverted. | **REFUTED.** Nothing to do with networking. One mechanism (`XML.load` byte counters populate too early and are cleared on completion), 8 lines, **near-flip**. |
| `avm1/geturl` (global:50) | *"wants Param:/Body: form values — the root timeline's variables in enumeration order — which live in the global `var_array`/`var_map` with no insertion order to walk"* | `output_mismatch` **4/7**. URL/Target/Method all correct; we emit **zero** `Param:` lines. Expected order is `value2=2`, `value1=string`, `$version=…` — i.e. plain **reverse-insertion** order with the pre-existing `$version` last. | **LIKELY REFUTED.** That is ordinary AVM1 `for..in` order, which we already implement (the `for (i in _root)` tests pass). The real gap is that GetURL2/POST never collects root variables at all. 3 lines, one mechanism. |
| `avm1/form_loader_encoding_4` (global:95) | none — sat under a bucket header the 2026-08-18 pass already declared *"no longer true of any of the three below"*, and never got a per-name reason | **`RUFFLE_MATCHED`** (effective pass) | Rationale is **absent**, status is `ruffle_matched` → **keep** by criterion, but it needs a one-line per-name reason like its bucket siblings got. |
| `avm1/load_vars` (global:96) | *"A near-pass re-triage lead, not a capability gap"* — one of the two `testvars.txt` loads never dispatches `onLoad` | `output_mismatch` **29/35**; our output stops after 30 lines, missing exactly the second `Load: true / myVar / also / loaded` block | **HOLDS, verbatim.** Still the near-pass it says it is. |
| `avm1/sandbox_type_remote` (global:170) | *"needs (a) an `http://localhost:8000/NAME` → `<test>/localhost/NAME` mapping and (b) a per-movie sandbox type … grade it before writing it off"* | `output_mismatch` **1/3**; line 1 correct, both child-SWF lines absent | **HOLDS, verbatim.** Two lines, two mechanisms, exactly as written. |
| `avm1/stylesheet_load` (global:97) | *"`stylesheetLoad()` … is a literal stub … which is the single wrong line we emit … this is one function"* | `output_mismatch` **1/49**; first divergence is `undefined` where Flash prints `true`, everything after is cascade | **HOLDS, verbatim.** |
| `avm2/soundchannel_position` (avm2:108) | *"now sit directly on the mechanism above and are the obvious next probe"* | see §3.4 | see §3.4 |
| `avm2/soundchannel_soundcomplete` (avm2:109) | same | see §3.4 | see §3.4 |

**Net:** of 8 claims, **2 refuted** (`xml_getbytes`, `geturl`), 4 confirmed verbatim, 1 (`form_loader_encoding_4`)
missing a rationale entirely. The two refuted entries are the only ones whose *stated category* was
wrong; both are small, named, near-flip mechanisms, and neither belongs in any disposition doc.

### 3.4 The two `soundchannel` entries — measurement unchanged for five sessions

| entry | 2026-08-12 note | today | 
|---|---|---|
| `avm2/soundchannel_position` | "(66/140) … the obvious next probe" | `ruffle_matched`, **66/140**, actual 138 |
| `avm2/soundchannel_soundcomplete` | "(6/16) … the obvious next probe" | `ruffle_matched`, **6/16**, actual 6 |

The measurements are **byte-identical to the note written five sessions ago** — the "obvious next
probe" was never taken. Priced honestly: both are already `ruffle_matched`, i.e. already counted as
effective passes, so fixing them is worth **0 effective points**; the only gain is
`ruffle_matched → pass`. That is why nobody took it, and it is the right call. **Keep both entries,
and update their note to say the probe is deliberately deferred for zero effective yield** rather
than leaving a five-session-old "obvious next" pointing at nothing.

---

## 4. PART B — the four disposition docs' conditional entries

Checked the two the brief named against the current image baseline
(`d8da5a18c`, run `34666689502`, 2026-09-12) read fresh from the per-suite
`image_results_graphics.json`:

| comparison | measured now | doc |
|---|---|---|
| `avm1/display_object_properties [output]` | **pass**, `outliers 0` / `excess_outliers 0`, `max_diff 79`, tolerance 90 | `avm1/_investigation/ACCEPTED_DIFFS.md:836` + summary table row 1245 |
| `from_gnash/misc-ming.all/loop/simple_loop_test [frame1..frame7]` | **all 7 pass**, `outliers 0`, **`max_diff 0`** (byte-exact) | `from_gnash/_investigation/ACCEPTED_DIFFS.md:672` + summary rows 748-749 |

Both measurements are confirmed. **The requested edits are not needed — see §5.2.**

---

## 5. REFUTATIONS

### 5.1 "Today's pull did MORE than that to this family" — true of the clone, false as drift

My brief frames the `goto_framescript_queued` restructure and
`goto_framescript_queued_same_frame` as things "today's `git pull` did", implying un-graded drift
the next CI run will surface. It is drift **of the local `~/CC/ruffle` clone**, which was seven days
stale. It is **not** drift of the corpus: CI downloads every suite fresh each run (nothing under
`ruffle-tests/tests/swfs/` is git-tracked — `git ls-files` on `avm1/globals_monkeypatch` returns
nothing), and the graded run's download at ≈`2026-09-16T23:31Z` already contained all of it. The
board's four rows are correct, current, and were graded against the *post*-restructure expectations.
The genuine consequence of the clone lag is the opposite of what the brief expects: four **stale
local files** CI does not have (§1.4a) and one **inert ignore entry** (§1.4b).

### 5.2 The two "stale image-axis disposition entries" are already noted — three times over

`scripts/image_triage.py` reported these as "worth a one-line note in their doc". **Both docs
already carry that note, prominently, in the section heading itself:**

* `from_gnash/_investigation/ACCEPTED_DIFFS.md:672` — heading ends
  **"— STALE: all 7 frames now PASS"**, followed by a status note (s13) *and* a re-confirmation (s14).
* `avm1/_investigation/ACCEPTED_DIFFS.md:836` — heading ends **"— STALE: now PASSES"**, with three
  dated status notes.

The `avm1` entry goes further and **pre-refutes this exact request**, because session 14's wave-1
board audit §5 raised it once already:

> "Session 14's wave-1 board audit §5 listed this entry and `from_gnash …/simple_loop_test` as
> 'stale and still unapplied'; that half is **refuted** — both were applied by session 13's hygiene
> pass and only needed the baseline citation moved forward. `image_triage.py` will keep listing them
> under 'DISPOSITIONED BUT NOT FAILING'; **that is the tool working as designed, not an outstanding
> edit.**"

So this is the **third** session in which the same non-task has been put on an agent's plate.
**Root cause, located:** `scripts/image_triage.py:911-912` prints, unconditionally,

```python
p(f"\n== DISPOSITIONED BUT NOT FAILING ({len(stale)}) — the entry is stale "
  f"on the image axis; worth a one-line note in its doc ==")
```

It never checks whether the doc already *has* the note, so it manufactures a fresh "outstanding
edit" every time it runs.

**Recommended edits (both tiny, neither is yield):**
1. `scripts/image_triage.py:911-912` — have the section check the entry's doc text for an existing
   `STALE` / `NOT FAILING` marker and print *"already noted in its doc — no action"* for those,
   reserving the current wording for entries that genuinely lack a note. **This is the only edit
   that actually saves a session**, and by the evidence it saves roughly one wave-1 slot per session.
2. *(Optional, cosmetic)* bump the baseline citation in both entries from
   `fb36ba110` / run `31130292354` to `d8da5a18c` / run `34666689502`, and add for
   `simple_loop_test` that all seven frames are now `max_diff = 0` (the entry's last re-confirmation
   already says this). Zero yield; it will go stale again. Do (1) instead.

### 5.3 "Pick the ~8 whose rationale is weakest" assumed the rationales are weak — mostly they are not

Six of the eight ignore-list rationales I re-tested reproduce **verbatim**, down to the exact line
counts, some of them five sessions old. The ignore lists in this project are in much better shape
than the brief's framing assumes; the two s19 flips were the exception, not the rule. The **two**
that did break (§3.3) are both cases where a *bucket header* made a category claim that no per-name
measurement ever supported — which is the pattern worth hunting, not "ignored entries" in general.

---

## 6. PRICING — in sessions saved

| finding | value |
|---|---|
| Projected name-set delta is empty (§1) | **~1 session saved.** The closeout can attribute 100 % of the next CI diff to this session's changes, with no drift subtraction and no "read it fresh and argue about it" round-trip. |
| `goto_framescript_queued` = 1 mechanism, not 4 leads (§2) | **~1-2 sessions saved.** The board's 11/52, 15/59, 17/59, 3/4 look like four separate AVM2 timeline investigations; they are one 25-line port of an upstream commit we can read. |
| 7 stale ignore entries (§3.1) | **0 graded points**, ~0.2 session: 5 of them are wins the filtered report was hiding. |
| Inert ignore entry + 4 stale local files (§1.4) | **~0.5 session saved** — prevents a future agent burning a slot on a test that no longer exists upstream, exactly the s18 failure mode. |
| `xml_getbytes` + `geturl` refuted (§3.3) | **2 near-flip leads** created, each 1 mechanism / ≤8 lines; and ~0.3 session saved by not treating them as "needs networking". |
| `image_triage.py` wording (§5.2) | **~1 wave-1 slot per session**, recurring. |
| `soundchannel_*` (§3.4) | 0 points; the value is the explicit *"don't bother"* that stops a seventh session re-costing it. |

---

## 7. NEW UNCLAIMED LEADS

1. **`avm1/xml_getbytes` — XML load byte-counter phase (9/17 → likely `pass`).** Two symptoms, one
   area: the counters are populated before the load-requested probe, and cleared before the
   data-received probe. 8 lines. Unclaimed by any wave-2 agent.
2. **`avm1/geturl` — GetURL2/POST never collects root variables (4/7 → likely `pass`).** Emit
   `Param: k=v` for each `_root` variable in `for..in` order, `$version` last, into the existing
   `utils.c swf_log_navigate` block that already prints URL/Target/Method correctly. 3 lines of
   output; the enumeration machinery already exists.
3. **`avm2_display.c` SWF≤9 queued-goto arm skips `inner_goto_frame` (§2.4).** Our port diverges
   from **both** pre- and post-`7e8e2de8a` Ruffle there. Even if `swf9` is dropped from the cluster,
   this is a latent AVM2 timeline divergence for every SWF9 movie.
4. **`avm1/form_loader_encoding_4` has no per-name rationale** (§3.3). The 2026-08-18 pass gave one
   to its three bucket-mates and missed it. One line of doc.
5. **Nobody is watching the `output.ruffle.txt` half of drift.** s19 §A2 made the case; this session
   it happens to be clean (0 differing files). A standing `ruffle_matched` row can flip to
   `output_mismatch` with **no change from us** when upstream rewrites an `output.ruffle.txt` —
   `7e8e2de8a` rewrote `swf13`'s this very range. Worth a 20-line check in
   `scripts/corpus_status_diff.py`, not a per-session agent.
6. **`download_tests.sh` leaves deleted upstream tests behind forever** (§1.4a), and `--clean` is
   banned because it wipes `_investigation/` and `_results/`. The gap is a `--prune` mode that
   removes only test dirs absent from the fresh sparse checkout. This is the third session a stale
   dir has shown up (s18 found four, s19 found them gone, s20 finds one new one).

---

## 8. FILES TOUCHED

**None.** Read-only audit, no source edits, no commits, no `download_tests.sh` invocation.
Deliverable is this file. Scratch: `<scratchpad>/w1-drift/` (`ignore_xref.txt`, `graded_names.txt`,
`upstream_*.txt`, `runs/*.log`, `swf9.log`, `swf10.log`, `swf13.log`).
