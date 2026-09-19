# Session 20 · wave 2 · `w2-avm1-nearflips` — two refuted verdicts, two hygiene items

## NEW FILES (stage these by name — `git add -u` will silently drop them)

```
SWFRecompDocs/plans/session20-fanout-reports/w2-avm1-nearflips-report.md
SWFRecompDocs/plans/session20-fanout-reports/w2-avm1-nearflips-1-xmlgetbytes.patch
SWFRecompDocs/plans/session20-fanout-reports/w2-avm1-nearflips-2-geturl.patch
SWFRecompDocs/plans/session20-fanout-reports/w2-avm1-nearflips-3-ignore-prune.patch
SWFRecompDocs/plans/session20-fanout-reports/w2-avm1-nearflips-4-imagetriage-wording.patch
```

**Worktree:** `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-afc64f6e81dc579c3`
(branched from `master` @ `574207007`). Scratch: `<scratchpad>/w2-avm1-nearflips/`.

**MODIFIED files (5, all four patches together reproduce the worktree byte-for-byte —
verified by applying each patch to a pristine `git archive HEAD` copy):**

```
SWFModernRuntime/src/actionmodern/action.c            (patches 1 + 2, disjoint regions)
ruffle-tests/ignored_tests.txt                        (patches 1 + 2, disjoint hunks)
ruffle-tests/tests/swfs/avm2/ignored_tests.txt        (patch 3)
ruffle-tests/tests/swfs/from_shumway/avm1/ignored_tests.txt (patch 3)
scripts/image_triage.py                               (patch 4)
```

---

## 0. HEADLINE — verdicts, priced

| item | verdict | realised movement | graded value |
|---|---|---|---|
| **1 `avm1/xml_getbytes`** | **GO — FLIP** | `output_mismatch` 9/17 → **`pass` 17/17** | **+1 effective**, and it un-hides one ignored row |
| **2 `avm1/geturl`** | **PARTIAL GO — NOT a flip** | `output_mismatch` 4/7 (4 actual lines) → `output_mismatch` **6/7** (7 actual lines) | **0**. Residual is one platform-identity constant; NO-GO with a named completion mechanism (§3.4) |
| **3 ignore-list prune** | **GO — hygiene, 0 points** | 7 stale entries + 1 inert entry removed; 6 of the 7 were **hidden wins** | **0 graded**; +6 visible avm2 rows, +1 from_shumway row |
| **4 `image_triage.py` wording** | **GO — tooling, 0 points** | the 2 entries it flagged now print "ALREADY noted … NO ACTION" | **0 graded**; ≈1 wave-1 slot per session |

**Regression sweep: 35 test runs, ZERO regressions** (§5). Nothing else moved.

Both of the two refutations I was handed held up, but **neither was priced correctly**, and
in opposite directions: `xml_getbytes` was cheaper than advertised (a real flip, ~20 lines),
`geturl` was more expensive (~75 lines, and it *still* does not flip). Details in §6.

---

## 1. ITEM 1 — `avm1/xml_getbytes`: **GO, FLIP**

### 1.1 Mechanism

Not networking — a **phase** error, exactly as `w1-drift` §3.3 said. Our `XML.load`
wrote the byte counters **at request time**; Ruffle writes them **at response time**.

Ruffle splits the write across two files:

* `core/src/avm1/globals/xml.rs:541-565` (`spawn_xml_fetch`, **before the fetch**) —
  defines `_bytesLoaded = 0` and `_bytesTotal = undefined`, both
  `Attribute::DONT_DELETE | DONT_ENUM`, unconditionally.
* `core/src/loader.rs:1070-1090` (the response future, **immediately before `onData`**) —
  `_bytesTotal = length` always, and `_bytesLoaded = length` only when `length > 0`.

We did all of it in `builtin_xml_load`, and only on a successful registry hit. That put
`27/27/27/27` where Flash reports `0 / undefined / 0 / undefined`, and left the deferred
dispatch with nothing to write — so `onData`'s probe read `undefined ×4` where Flash
reads `27 ×4`. **The values were right and the timing was inverted**, which is the
`mcl_load_timing` shape the brief predicted.

The second half of the mechanism is the flags. The fixture's `onData` opens with

```as
delete xml._bytesLoaded;
delete xml._bytesTotal;
```

and then expects `27` from all four probes — i.e. the `delete` must be a **no-op**.
`PROPERTY_FLAGS_DONTENUM` in this codebase is `WRITABLE | CONFIGURABLE`, and
`deleteProperty` (`object.c:1184`) honours `CONFIGURABLE`, so our properties *were*
deletable. `PROPERTY_FLAG_WRITABLE` alone is the DONT_ENUM | DONT_DELETE pair.

### 1.2 Patch scope — `w2-avm1-nearflips-1-xmlgetbytes.patch`

* `action.c` `aq_dispatch_xml_load` (~20298, +18 lines): write `_bytesTotal` and
  `_bytesLoaded` from `d->content_length` immediately before the `onData` fire.
* `action.c` `builtin_xml_load` (~20362, +17/−6): move the counters to the request
  phase as `0` / `undefined`, **unconditionally** (Ruffle's `spawn_xml_fetch` runs
  before the fetch, so a missing file still gets both own properties — `XML.as:945`
  does `hasOwnProperty('_bytesLoaded')` right after `load()`), flags
  `PROPERTY_FLAG_WRITABLE`.
* `ruffle-tests/ignored_tests.txt`: prune `xml_getbytes` (now `pass`), and replace the
  bucket's category claim — the bucket is now empty, with an explicit "do not re-add a
  name on the strength of the header alone".

No new files, no recompiler change, no header change. ~35 changed lines total.

### 1.3 Before / after

| test | before (graded `35163868554` @ `2973513c4`, and re-measured locally) | after |
|---|---|---|
| `avm1/xml_getbytes` | `output_mismatch` **9/17**, 17 actual | **`pass` 17/17** |

---

## 2. ITEM 2 — `avm1/geturl`: **PARTIAL GO, and the last line is a NO-GO**

### 2.1 The premise was wrong, and so was the replacement premise

The standing rationale said the root's variables *"live in the global `var_array`/`var_map`
**with no insertion order to walk**"*. **Refuted twice over:**

1. `SWFModernRuntime/lib/c-hashmap/map.c` keeps every live entry on a linked list
   **in insertion order** (`struct hashmap { … struct bucket* first; struct bucket* last; }`,
   and `hashmap_iterate` walks `m->first`). A forward iterate + backwards emit **is**
   AVM1's reverse-insertion enumeration. The order was there all along.
2. `w1-drift` §3.3's replacement premise — *"the real gap is that GetURL2/POST never
   collects root variables at all"* — is only half right. `avm1_collect_form_values`
   existed and worked; it walked **`mc->dynamic_props` only**. For a **non-root** clip
   that is the whole variable store (which is why `loadvariables_method` passes). For the
   **root** it is the wrong store: a scopeless `DefineLocal`/`SetVariable` at root falls
   through to the global `var_array`/`var_map` (`actionDefineLocal`'s "Fall back to global
   variable table" arm), while `dynamic_props` holds only the **load-time** properties.

### 2.2 …and there was a third layer nobody had named

Even after wiring up `var_map`, `$version` was still absent. `$version` is set on
`root_movieclip.dynamic_props` inside **`ensureGlobalInit`**, which is **lazy**. `geturl`'s
entire script is `DefineLocal ×2` + `GetURL2` — it never touches a global, so at the moment
of the `getURL` the root has **no `dynamic_props` object at all**. Ruffle defines `$version`
on the root object at SWF load (`core/src/context.rs:432`), so it is always there. The fix
forces the (idempotent) init from the root arm of the collector, which only exists in
`LOG_FETCH` builds.

### 2.3 Patch scope — `w2-avm1-nearflips-2-geturl.patch`

All inside `#if SWF_LOG_FETCH_ENABLED`, i.e. **compiled only into the 24 `log_fetch = true`
tests** — the whole block vanishes from every production and every other test build.

* `action.c` ~36123: forward-declare `ensureGlobalInit` (defined at ~42706).
* `action.c` ~36148, +60 lines: `struct Avm1RootVarState` + `avm1_root_var_cb`
  (forward `hashmap_iterate` into a 32-slot array, skipping the uninitialised
  `getVariable()` sentinel) + `avm1_root_var_enumerable` (a var_map entry mirrored onto
  `root.dynamic_props` as DontEnum is not enumerable — the same rule
  `enum_varmap_callback` applies for `for..in`).
* `action.c` ~36223, +40/−0 in `avm1_collect_form_values`: a root-only arm that forces
  `ensureGlobalInit`, emits the var_map entries **backwards**, then falls through to the
  existing `dynamic_props` walk with a dedup against what it already emitted.
* `ruffle-tests/ignored_tests.txt`: `geturl` **stays ignored**, with the refuted rationale
  replaced by the measured one and the completion mechanism for the last line.

Ordering rule, stated explicitly in the code comment: Ruffle keeps all of the root's
variables on **one** object, so reverse-insertion puts the script-time variables (later)
before the load-time ones (earlier). We split them across two stores, so the walk is
**var_map reversed, then `dynamic_props` reversed**. `geturl` pins exactly that:
`value2`, `value1`, `$version`.

### 2.4 Before / after, and the NO-GO

| test | before | after |
|---|---|---|
| `avm1/geturl` | `output_mismatch` **4/7**, **4** actual lines (zero `Param:` lines) | `output_mismatch` **6/7**, **7** actual lines |

The single remaining diff:

```
-  Param: $version=LNX 32,0,0,0      (expected)
+  Param: $version=WIN 32,0,0,0      (ours)
```

**NO-GO on flipping that token, and it is not a cheap call disguised as an expensive one.**
Evidence:

* Ruffle hard-codes `Manufacturer::Linux` in its **default** `SystemProperties`
  (`core/src/system_properties.rs:287`) on **every** host — `LNX` is not a Linux-CI
  artifact, it is Ruffle's universal default.
* We deliberately present a **Windows** player, consistently, in four places:
  `action.c:147` `u16_WIN_ver`, `action.c:149` `"Macromedia Windows"`,
  `System.capabilities.os = "Windows XP"`, and `avm2_globals.c:7385 version = "WIN 32,0,0,0"`.
  Flipping only `$version` would make it disagree with our own `capabilities.os`.
* There is already a standing project decision that treats this as unmatched:
  `SWFRecompDocs/status/2026-05-24-divergence-harness-findings.md` lists `$version=` under
  **"Known noise filters"** — *"Pure platform metadata; can never match."*
* **Nothing else in the corpus observes any of the four constants.** `grep -rn "WIN 32"`
  over every `output.txt` returns **0 hits**; `"LNX 32"` returns exactly one — this line.

**Completion mechanism** (for whoever takes it): flip all four constants to Ruffle's Linux
defaults **together**, record it in
`ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_COMPAT_TWEAKS.md`, and prune `geturl`
from `ruffle-tests/ignored_tests.txt`. Worth **+1 effective**. It is a project-identity
decision (real SWFs sniff `$version` for platform), not a local fix, which is why I did not
take it unilaterally — and the corpus cannot see the downside, so the corpus cannot price it.

---

## 3. ITEM 3 — ignore-list prune: **GO, hygiene, 0 graded points**

### 3.1 All seven re-verified locally before pruning

An ignore entry is a claim to re-test, so I ran every one of them in this worktree rather
than trusting the graded JSON. Both agree:

| entry | file:line | graded (`35163868554` @ `2973513c4`) | **re-run locally 2026-09-18** |
|---|---|---|---|
| `displayobject_scrollrect` | `avm2:154` | `pass` | **PASS** (28.15 s) |
| `all_classes/events/swf9` | `avm2:170` | `pass` 1030/1030 | **PASS** |
| `all_classes/events/swf10` | `avm2:166` | `pass` 1638/1638 | **PASS** |
| `all_classes/events/swf11` | `avm2:167` | `pass` 1750/1750 | **PASS** |
| `all_classes/events/swf12` | `avm2:168` | `pass` 1814/1814 | **PASS** |
| `all_classes/events/swf30` | `avm2:169` | `pass` 2353/2353 | **PASS** |
| `hitarea` | `from_shumway/avm1:19` | `pass` 4/4 | **PASS** (73.52 s) |

The five `all_classes/events/swf*` rows sit in the *"Upstream `known_failure` = true"*
bucket, so they are **hidden wins**: we match the Flash oracle where Ruffle fails.
`hitarea`'s entry is self-refuting — it says *"`hitarea` is `ruffle_matched` … so it is a
real remaining divergence and stays listed"*, and it is no longer `ruffle_matched`.
That list is now **empty** (kept as a file so its prune history survives).

### 3.2 The inert entry

`avm2/ignored_tests.txt:184` `goto_framescript_queued` — removed, with a comment recording
**why it must not be re-added**: upstream `d5b707265` deleted the flat test and replaced it
with `/swf9`, `/swf10`, `/swf13`, and `b20e2fdf9` added `…_same_frame`; after `7e8e2de8a`
only `/swf13` is still `known_failure`. The name has **no row** in the graded results, which
confirms it dispositions nothing. **I did not touch the four replacement rows** — they are
`w2-goto-framescript`'s work.

### 3.3 Not pruned, re-confirmed

`netstream_play_flv_screen` (trace `pass`, **image comparison still fails**) and
`bytearray_oom` (records an **upstream `ignore = true`**) — both left in place, as briefed.

### 3.4 The filtered pipeline still works — measured, not assumed

`ruffle-tests/filter_results.py` re-run against the graded baselines with the edited lists.
Deltas are exactly the seven prunes plus `xml_getbytes`, and nothing else moved:

| suite | ignored_count | filtered total | filtered effective |
|---|---|---|---|
| `avm2` | 46 → **40** (−6) | 1229 → **1235** | 1217 → **1223** |
| `from_shumway/avm1` | 1 → **0** | 46 → **47** | 46 → **47** |
| `avm1` | 20 → **19** (−1, `xml_getbytes`) | 714 → **715** | 710 → 710 |

**Read the `avm1` row carefully and do not book it as a regression.** Against the *baseline*
JSON, un-ignoring `xml_getbytes` adds a row that was still `output_mismatch` at
`2973513c4`, so the filtered effective count does not move. Patch 1 makes it `pass`; the two
land in the same commit, so the next graded run shows `+1` on both total and effective.
I restored the three `results_graphics_filtered.json` artifacts afterwards
(`git checkout --`) — CI publishes those, and regenerating them from a stale baseline
would be wrong.

---

## 4. ITEM 4 — `scripts/image_triage.py`: **GO, tooling, 0 graded points**

`image_triage.py:911-912` printed *"worth a one-line note in its doc"* for **every**
stale disposition, unconditionally. Both entries it currently flags already carry that note
in their section **heading**, and `avm1 display_object_properties` explicitly pre-refutes
the request in its own body. Session 14 was sent down this path once; session 20 spent part
of a wave-1 brief on it again.

**Fix (minimal, no restructuring):**

* `_STALE_NOTE_RE` next to the existing axis regexes — `STALE` / `NOT FAILING` /
  `now PASSES` / `now 0 px`, case-insensitive.
* `scan_disposition_doc.record()` carries a `stale_noted` flag per entry, OR-ed across
  **all three** entry shapes (heading, body, summary-table row) and independent of the
  axis/`explicit` logic.
* New `Dispositions.stale_noted(suite, test)` — same first-doc-wins name precedence as
  `lookup`, so the answer describes the entry `lookup` returned.
* `stale_dispositions()` appends the flag as a 5th tuple field; `emit_text` and
  `emit_markdown` split the section into **"with NO stale note — worth a one-line note"**
  and **"ALREADY noted as stale — NO ACTION, do not re-raise"**.

**Verified two ways** (read-only, against the main tree's docs and the wave-0
`image_triage.json`):

```
== DISPOSITIONED BUT NOT FAILING (2) — the entry is stale on the image axis ==
  -- 2 ALREADY noted as stale in the doc — NO ACTION, do not re-raise:
     avm1/display_object_properties  {'pass': 1}  <- ACCEPTED_DIFFS (avm1): … **STALE: now PASSES**
     from_gnash/misc-ming.all/loop/simple_loop_test  {'pass': 7}  <- … **STALE: all 7 fram…
```

and that the flag **discriminates** rather than always firing: of the **80** entries across
the disposition docs, exactly **6** carry a stale note (`bitmap_filters`,
`display_object_properties`, `movieclip_state_values`, `number_patterns`,
`simple_loop_test`, `string_paths_reference_launder`); `avm1/date` correctly returns
`False`. So a genuinely un-noted stale entry still gets the original request.

---

## 5. REGRESSION SWEEP — 35 runs, 0 regressions

All runs in this worktree, `SWFRECOMP_COMPILE_TIMEOUT=2400`, **sequential**, `--verbose`,
test dirs `cp -r`'d into the worktree's canonical suite paths with `--recompile` on first
use. No `git stash` at any point (A/B legs were not needed — see the note below).
Mode: no-graphics; mode parity is complete per `BRIEFS_COMMON.md`.

**avm1 (15) —** everything touching XML/LoadVars/getURL/AMF/log_fetch:

| test | before | after |
|---|---|---|
| `xml_getbytes` | `output_mismatch` 9/17 | **`pass` 17/17** ← the flip |
| `geturl` | `output_mismatch` 4/7, 4 actual | `output_mismatch` **6/7, 7 actual** ← improved |
| `load_vars` | `output_mismatch` 29/35, 30 actual | `output_mismatch` 29/35, 30 actual — **byte-identical** to `w1-drift`'s measurement |
| `xml`, `xml_load`, `loadvars_tostring`, `loadvariables`, `loadvariables2`, `loadvariables_method`, `geturl_target_normalize`, `geturl_opcode_target_normalize`, `amf_array_serialization`, `localconnection_top_level`, `netconnection_send_remote`, `xml_socket_connect_null` | `pass` | **`pass`** (12/12) |

**from_gnash (8)** — every SWF in the corpus that mentions `_bytesLoaded` / `_bytesTotal`
(found by grepping the `test.swf` binaries, not by name):

`XML-v5/v6/v7/v8` and `LoadVars-v6/v7/v8` are `ruffle_matched`, which is a **subset**
match — the status can survive an output change — so I compared the recorded metrics, not
the verdict. `actual_lines`, `matching_lines` **and** `ours_diff_count` are **identical on
all seven** (449/439/10, 486/483/3, 486/483/3, 486/462/24, 148/146/6 ×3).
`misc-ming.all/loading/LoadVarsTest`: `pass` 36/36 → `pass` 36/36.

**regression suite (5)** — `--tests-dir=ruffle-tests/tests/swfs/regression`:
`lv_cross_swf_version`, `lv_ondata_type1_args`, `xml_onload_type1_args`,
`onload_type1_args`, `avm1_mcl_load_tick` — **all PASS**.

**item-3 candidates (7) + `from_shumway/avm1/loadevent`** — all **PASS** (§3.1).

*Why no before-leg for most of it:* a test that is `pass` after the change and `pass` in the
baseline has actual output equal to `output.txt` on both sides, so its output is unchanged by
construction. The before-leg only matters where status can hide an output change — the seven
`ruffle_matched` gnash rows and `load_vars` — and those are compared on line metrics above.

**Blast radius, stated honestly.** Item 2 is entirely inside `#if SWF_LOG_FETCH_ENABLED`
(`-DLOG_FETCH`, set only for the 24 `log_fetch = true` tests), and within that only the
`send_vars_method != 0` paths reach the changed function — `geturl` and
`loadvariables_method`, both covered above. Item 1 is in the AVM1 `XML.load` path only;
`LoadVars.load` has its own counters (`action.c:41172`) and was **not** touched.

---

## 6. REFUTATIONS

### 6.1 Both handed-down refutations hold — but both were MISPRICED, in opposite directions

`w1-drift` §3.3 called `xml_getbytes` and `geturl` *"two near-flip leads … each 1 mechanism /
≤8 lines"*. Measured:

| lead | predicted | actual | flips? |
|---|---|---|---|
| `xml_getbytes` | "8 lines, near-flip" | ~35 lines across **two** call sites + a property-flag change | **YES** |
| `geturl` | "3 lines of output; the enumeration machinery already exists" | ~75 lines, **three** layers (wrong store → lazy `$version` → platform constant) | **NO** |

The general lesson, offered for the closeout: **a diff-line count prices the symptom, not
the mechanism.** `xml_getbytes` showed 8 bad lines and needed two sites; `geturl` showed 3
missing lines and needed three layers, and its last line is not a bug at all.

### 6.2 "That is ordinary AVM1 `for..in` order, which we already implement" — **refuted**

`w1-drift` §3.3 argued the expected `Param:` order *"is plain reverse-insertion with
`$version` last … ordinary AVM1 `for..in` order, which we already implement (the
`for (i in _root)` tests pass)"*. The order is right; **the claim that our `for..in`
produces it is not.** `actionEnumerate2`'s MOVIECLIP arm (`action.c:49176-49295`) pushes
children, **then var_map, then `dynamic_props` + prototype**, and the LIFO pop reverses that
— so `for (i in _root)` yields **`$version` FIRST**, then the script variables. The form-value
order needs the opposite. That is why patch 2 orders the two stores explicitly instead of
reusing the enumeration. (See §7.1 — this may be a real divergence, and I am flagging it as a
lead rather than claiming it, because no corpus test appears to pin it.)

### 6.3 My own brief's framing of item 2 as a "near-flip" — **refuted**

The brief said *"the residual is probably something else entirely"* and asked me to stop if
the real blocker was expensive. The residual **was** something else entirely, twice over
(§2.1, §2.2), and the final blocker is not expensive in lines — it is **3 lines of
constants** — but it is expensive in *scope*: it reverses a documented project stance and
changes platform identity for all content to satisfy one Ruffle-default string. I landed the
mechanism and left the constant. §2.4 has the completion mechanism.

### 6.4 `image_triage.py` — the root cause was real and is now closed

`w1-drift` §5.2 located it exactly; I only had to make the check discriminate (§4). The one
thing worth adding: the flag is computed from the entry **body**, not the heading, so it also
catches entries that carry the note only in the summary-table row.

---

## 7. NEW UNCLAIMED LEADS

1. **`for (i in _root)` may enumerate `$version` at the wrong end.** `actionEnumerate2`
   yields `dynamic_props` (load-time: `$version`) **before** var_map (script-time
   variables); Ruffle holds both on one object, so reverse-insertion puts `$version`
   **last**. `geturl`'s expected output is direct evidence of Ruffle's order for the same
   variable set. I found no corpus test that pins a `for..in` over `_root` containing both a
   load-time and a script-time name, so this is unproven — but it is a one-test probe
   (`regression/` fixture, oracle = the Ruffle exporter) and, if real, a two-line swap of the
   two push blocks. **Do not take it blind**: the current order was presumably tuned against
   something.
2. **`$version` / `capabilities` platform identity is a 4-constant, +1-effective decision
   nobody owns** (§2.4). It needs an owner, not an agent slot.
3. **`LoadVars.load` has its own copy of the byte-counter logic** (`action.c:41172`, and the
   completion write at `41095-41100`). I did not touch it and nothing regressed, but it now
   differs from the XML path: it writes `_bytesLoaded = 0` / `_bytesTotal = undefined` at
   request time (correct) and the real counts at completion (correct) — **but with
   `PROPERTY_FLAGS_DONTENUM`, i.e. still deletable.** Ruffle uses
   `DONT_DELETE | DONT_ENUM` for LoadVars too (`load_vars.rs:270-280`). No test covers a
   `delete this._bytesLoaded` inside a LoadVars `onData`; a `regression/` fixture would
   settle it, and the fix is the same one-token flag change as patch 1.
4. **`ruffle-tests/tests/swfs/from_shumway/avm1/ignored_tests.txt` is now empty.** If the
   project would rather delete empty suite lists than keep them for their prune history,
   that is a one-line policy call — I kept the file deliberately.
5. **Stray `RecompiledScripts/` directories at non-test levels** —
   `avm2/all_classes/RecompiledScripts` and `avm2/all_classes/events/RecompiledScripts` are
   artifacts at directory levels that hold no `test.swf`. Harmless, but they are the kind of
   thing that makes a future `--prune` mode for `download_tests.sh` (w1-drift §7.6) harder to
   write safely.

---

## 8. FILES TOUCHED

5 modified (listed at the top), 5 created (the 4 patches + this report). No commits, no
pushes, no `git stash`, no `--tests-dir` pointed at the main tree, no full-suite run.
Logs and scripts: `<scratchpad>/w2-avm1-nearflips/`
(`after_avm1.{log,json}`, `after_gnash.{log,json}`, `after_regr.{log,json}`,
`item3_avm2.{log,json}`, `item3_shumway.{log,json}`, `xml_after.log`, `geturl_base.log`,
`geturl_after.log`, `prune_ignores.py`, `global_ignore.py`, `patch2.py`, `patch3.py`,
`split_patch.py`, `split_global.py`, `verify_patches.sh`).
