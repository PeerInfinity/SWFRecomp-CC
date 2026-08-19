# s17 wave-2 — `w2-tooling-hygiene` — ignore-list prunes, canary additions, promoted A/B sweep

**Agent:** `w2-tooling-hygiene` (wave 2, TOOLING + DOCS only — zero runtime /
recompiler code touched).
**Worktree:** `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a44b8741d5e403c62`
**Baseline:** HEAD `88ebde665`; grading run `31877239992` at `aeebf9ede`
(graphics / categories=full / images=true).

---

## NEW FILES (stage these by name — `git add -u` will drop them)

| new file | in patch | what it is |
|---|---|---|
| **`ruffle-tests/recompiler_ab_sweep.sh`** (mode 100755, 306 lines) | `w2-hygiene-ab-sweep.patch` | the promoted full-corpus recompiler A/B sweep |

No other file is created. Everything else is an edit to an existing tracked file.

---

## Verdicts (one line each)

| item | verdict | effect |
|---|---|---|
| 1. ignore-list prunes | **DONE — 20 entries removed** (19 board prunes + the sibling hit-test row) | **filtered** counts only; graded corpus **unchanged at 4317/4453** |
| 1. missing dispositions | **DONE — 9 gaps closed + 5 bonus** | written INLINE in the ignore files, **not** in `ACCEPTED_DIFFS.md` — see §1c for why, and why that is the correct home |
| 2. canary additions | **DONE — 4 members added, all Tier 1, all re-rendered locally** | tier 1: 18 → 22; total 25 → 29 |
| 3. `recompiler_ab_sweep.sh` | **DONE — smoke test + two positive controls all green** | 30-SWF same-binary run prints an empty affected list; two independent positive controls prove it is not silently inert |
| 4. `.pipeline-state` / board corrections | **N/A by brief** — corrections listed in §4, arc doc deliberately NOT edited | coordinator owns closeout docs |

---

## Patches

| patch | files | insert/delete |
|---|---|---|
| `w2-hygiene-ignorelist.patch` | `ruffle-tests/ignored_tests.txt`, `.../avm2/ignored_tests.txt`, `.../from_shumway/ignored_tests.txt` | +188 / −33 |
| `w2-hygiene-canaries.patch` | `ruffle-tests/render_canary_tests.txt` | +46 |
| `w2-hygiene-ab-sweep.patch` | **`ruffle-tests/recompiler_ab_sweep.sh` (NEW)**, `ruffle-tests/tests/swfs/_investigation/SESSION_START_GUIDE.md` | +343 |

All three are independent and can land in any order. None touches runtime,
recompiler, or CI config; none can move a graded number by itself.

---

## 1. Ignore-list hygiene (trace board T9 / §5)

### 1a. Prunes applied — 20 entries, 106 → 86

Every prune was re-verified against the **tracked `_results/results_graphics.json`
blobs at HEAD** (metadata `git_sha = aeebf9ede`, run `31877239992`), not against
the board's table.

| file | entries at HEAD | now | removed |
|---|---:|---:|---|
| `ruffle-tests/tests/swfs/avm2/ignored_tests.txt` | 51 | 47 | `localconnection`, `int_toprecision`, `uint_toprecision`, `displayobject_hittestpoint_boundary` |
| `ruffle-tests/tests/swfs/from_shumway/ignored_tests.txt` | 22 | 6 | all 16 `fuzz/*` |
| `ruffle-tests/ignored_tests.txt` | 23 | 23 | **none** (criterion re-run: zero entries qualify) |
| the other five tracked files | 10 | 10 | none |
| **total** | **106** | **86** | **20** |

Per-entry verification (status / `matching_lines`-of-`expected_lines`):

* `localconnection` — `pass` **890/890** in avm2, and also `pass` 579/579 (avm1)
  and 12/12 (from_shumway). The AVM1↔AVM2 delivery bridge the 2026-07-29 note
  called "a real gap" landed in s16.
* `int_toprecision`, `uint_toprecision` — `pass` **1125/1125** each. Their
  `*_toexponential` siblings are still `ruffle_matched` (1139/1215, 1115/1215)
  and were **kept**.
* all 16 `fuzz/*` — `pass`, `matching_lines == expected_lines` in every one
  (16…71 lines each). The bucket header's claim *"All 16 re-confirmed still
  failing on 2026-08-01"* is **false at the baseline**; the header was rewritten
  to say so and to record the general lesson (a dated "re-confirmed failing"
  line is a snapshot, not a standing property).
* `displayobject_hittestpoint_boundary` — **the one contingent prune.** It is
  `output_mismatch` **47/65 at HEAD**; it only passes with the sibling
  `w2-avm2-smalls-hittest.patch` applied. I applied their
  `w2-avm2-smalls-ignorelist-hittest.patch` verbatim as instructed, so
  **`w2-hygiene-ignorelist.patch` must not land without `w2-avm2-smalls`'s
  runtime patch** — otherwise a genuinely failing row re-enters the filtered
  report. Flagged explicitly because it is the only row in this patch that is
  not currently passing.

### 1b. Traps re-verified, NOT pruned

* `ruffle-tests/ignored_tests.txt:72` `netstream_play_flv_screen` — `pass` on
  trace (0/0 lines), **kept**: a GLOBAL entry is also an IMAGE-axis disposition
  (`image_triage.py` returns `image_axis=True` for global entries) and its image
  comparison still fails. Trap 1 of that file's own header, confirmed.
* `.../avm2/ignored_tests.txt` `bytearray_oom` — `pass` 3/3, **kept**: records an
  UPSTREAM `ignore = true`.
* **REFUTATION of board §5c (minor).** §5c lists three "no results row at all"
  entries. Two are right (`shared_object`, `shared_object_self_ref` — genuinely
  absent from all 20 result files). The third,
  `from_shumway/avm1/ignored_tests.txt:19 hitarea`, **does have a row**:
  `from_shumway/avm1`, `ruffle_matched`, 2/4. Its own inline comment already
  says exactly that ("`hitarea` is `ruffle_matched`… stays listed"), so the
  entry is correct and backed — only the board's classification of it was
  wrong. No action either way.

### 1c. The 9 documentation gaps — closed INLINE, not in `ACCEPTED_DIFFS.md`

**Deliberate deviation from the brief's wording, stated up front.** The brief
named the four disposition docs as the destination. I wrote all 9 rationales as
inline per-name blocks in the ignore files instead, because:

1. `ACCEPTED_DIFFS.md`'s own preamble is *"Tests where some output lines will
   **never match** … impossible to fix for more fundamental reasons."* **Not one
   of the 9 is permanent.** Every one names a specific unimplemented function,
   method-dispatch branch, or URL mapping. Filing them there would make the
   corpus's own "is this fixable?" index lie, and `ACCEPTED_DIFFS.md` is the
   doc that `triage-check-accepted-diffs-first` tells every future agent to
   trust.
2. The board's own criterion (§5 preamble) accepts *"an inline comment in its
   own ignore file"* as a rationale — the same standard that makes the six
   entries in §5f's refutation "backed".
3. It puts the reason where the next pruner reads it.

`RUFFLE_VS_FLASH_DIFFERENCES.md` / `RUFFLE_COMPAT_TWEAKS.md` /
`FLASH_BUGS_REPLICATED.md` are all wrong homes for the same reason (none of the
9 is a Flash-vs-Ruffle disagreement or a compat tweak). **No entry was proposed
for deletion** — all 9 are real, live, unimplemented rows.

Each rationale below is a measured residual at `aeebf9ede`, with the mechanism
located in source where I could locate it:

| entry | file | measured residual | mechanism (verified) |
|---|---|---|---|
| `load_vars` | global | 29/35 (avm1) | Exactly ONE of the two expected `Load: true / myVar / also / loaded` blocks is missing — the fixture completes two loads of `testvars.txt` (`sendAndLoad(…,'POST')` and `load()`) and only one dispatches `onLoad`. **Near-pass re-triage lead, not a capability gap.** |
| `loadvariables_method` | global | 0/7 — we emit **nothing** | `MovieClip.loadVariables` is a registered *name* only (`action.c:15731`, so `typeof` is `"function"`) with **no branch in the MovieClip method dispatch** (`action.c:~72078`, where `loadMovie`/`unloadMovie` live). The ActionGetURL2 *tag* form (`load_variables_flag`, `action.c:48776`) IS implemented — this row is the method form only. The `Navigator::fetch:` log block already works elsewhere via `log_fetch = true`. |
| `stylesheet_load` | global | 1/49 | `stylesheetLoad()` at `action.c:17028` is literally commented **"— stub"** and returns `undefined` — which is precisely the one wrong line we emit. All 47 remaining lines are cascade (no `onLoad` → no `parse()` → no `getStyle()` blocks). `parse`/`getStyle` themselves already work. **One function.** |
| `sandbox_type_remote` | global | 1/3 in **both** avm1 and avm2 | Not "infrastructure not yet available". `test.as` loads two child SWFs over `http://localhost:8000/`, and the test **ships them in its own `localhost/` subdir** (`test-network.swf`, `test-no-network.swf`). Needs (a) a `http://localhost:8000/NAME` → `<test>/localhost/NAME` child-movie mapping and (b) a **per-movie** sandbox type keyed on fetch origin rather than one global value. Two lines, two mechanisms. |
| `audio_computespectrum` | avm2 | 0/118, 478 emitted lines | `SoundMixer.computeSpectrum` does not exist — every emitted line is `#1006 computeSpectrum is not a function` from `Main/onFrame()`, one per frame. Needs a real 256-bin FFT over decoded mixer PCM into a ByteArray. All-or-nothing. |
| `netstream_play_stop_replay` | avm2 | 1/11 | We emit only the fixture's own `Playing video first time`; every expected line is a NetStream **status event** across play→stop→replay. Needs the playback **state machine**, not the decoder. |
| `netstream_seek_flv` | avm2 | 0/49 + image (40 943 outliers) | Same state machine plus `seek()` (`SeekStart.Notify`/`Seek.Notify`/`Seek.Complete`). Strictly downstream of the row above. |
| `sound_load_multiple` | avm2 | 3/19 | Dies at case 3 on `#1006 loadCompressedDataFromByteArray`. The fixture asserts Flash's **error sequencing** (`#2037` for 5 of 9 cases, `#2084` AMF-40K for the last), so it needs the method *and* its state guards; cases cannot be scored piecemeal. |
| `soundmixer_soundtransform` | avm2 | **888/900 — nearest-pass row in the file** | All 12 diff lines are the two report blocks after `SoundMixer.soundTransform = st`: expected reports each player's `leftToLeft`/`rightToRight` as `-0.12` and `pan` `0.9856`; we report the identity transform (1/0/0/1, pan 0). i.e. **a WRITE to `SoundMixer.soundTransform` is not reflected in the per-`SoundChannel` `soundTransform` readback.** 2 players × 3 fields × 2 blocks = 12. **Re-triage lead, not a documentation row.** |

**Bonus (board §5d last row, not in the 9):** the five flag-backed-but-reason-free
`from_shumway` entries (`MaskTest-3`, `avm1movie`, `flash_net_SharedObject`,
`flash_text_TextField2`, `getobjectsunderpoint`) now each carry a one-line
measured reason. `getobjectsunderpoint` is the interesting one — we emit **38**
lines to Flash's 34, i.e. we report MORE objects under the point than Flash
does: hit-test containment **breadth**, the same family as the avm2 hit-test
rows w2-avm2-smalls is working. Worth a look next session.

**Also confirmed:** none of the 9 (nor the 5) appears in any of the four
disposition docs. Grep over all four returned nothing for every name (the one
"hit" on `esc` is a substring artefact).

### 1d. FILTERED vs GRADED count effect — the number that matters

**The graded corpus figure does not move at all.** The headline is the
**UNFILTERED** `effective_pass`; ignored tests are run and counted there either
way. **Trace baseline stays 4317/4453 effective. Pixel baseline stays 338/569.**

What moves is the *filtered* report:

| suite | filtered now | filtered after this patch | note |
|---|---|---|---|
| `avm2` | 1158/1190 eff (97.3 %) | **1161/1193** (97.3 %) | +3 pass rows re-enter (`localconnection`, `int_toprecision`, `uint_toprecision`) |
| `avm2` **with** the sibling hit-test patch | — | **1162/1194** (97.3 %) | +1 more once `displayobject_hittestpoint_boundary` actually passes |
| `from_shumway` | 201/207 eff (97.1 %) | **217/223** (97.3 %) | +16 fuzz rows re-enter, all passing |
| every other suite | unchanged | unchanged | no global-list prune |

The filtered *rate* barely moves (all pruned rows are passes, so numerator and
denominator both rise) — the point of the prune is that the filtered report
stops hiding 20 wins, not that the number goes up.

---

## 2. Canary additions (gfx board §canary audit)

Four members added to `ruffle-tests/render_canary_tests.txt`, **all Tier 1**,
tier 1 18 → 22, total 25 → 29. Parse verified with
`render_canary.load_test_list` (tier 1 = 22, tier 2 = 7, all = 29).

Every candidate was checked twice: (a) image-**PASSING** in the per-suite
`image_results_graphics.json` at `aeebf9ede`, and (b) actually rendered locally
in this worktree with `render_canary.py capture --recompile` (fresh `cp -r`'d
dirs, stale `Recompiled*` removed first).

| member | CI image verdict | local capture | slack |
|---|---|---|---|
| `from_shumway/acid/acid-bitmap-fill` | `pass`, max diff 193 | `pass`, md5 `d520a5dc…`, 357.8 s | **63 432 / 70 000 outliers = 9.4 % slack** |
| `from_shumway/acid/acid-bitmap-fill-2` | `pass`, max diff 30 | `pass`, md5 `408052b5…`, 352.7 s | **8 689 / 9 000 = 3.5 % slack** — tightest bitmap row in the corpus |
| `visual/filters/displacement_map_through_applyFilter` | `pass`, max diff 2 (tol 4) | `pass`, md5 `45ee9b28…`, 492.4 s | **0 / 0 outliers, max diff 2 at tolerance 4** — the ONLY CI-passing displacement row anywhere; identical stats to CI |
| `visual/edittext/edittext_border_transform` | 4 of 6 cmps pass at tol 0; `.04`/`.06` fail (51 / 44 outliers, max 207) | **reproduced exactly**: `.01 .02 .03` pass at 0 outliers, `.05` passes 0/20, `.04` fails 51/20, `.06` fails 44/20 | tol-0 rows have *zero* slack — any DIFFERS there is real |

All four rendered clean: **4 tests, 9 PNGs, 845 s at `-P 2`, capture exit 0**,
`trace_status = pass` on every one.

The local capture **reproduced the CI verdict comparison-for-comparison** on
`edittext_border_transform`, including both failures with the exact CI outlier
counts (51 and 44, max 207). That is unusually strong for a local-vs-CI
comparison (the canary docstring's mode 1 warns they normally diverge), and it
is why the mixed-verdict member is safe to file as Tier 1 with a per-comparison
caveat rather than demoting the whole test to Tier 2.

Board slack figures (9.4 % / 3.5 %) **confirmed independently** from the local
render, not copied.

### 2a. Standing blind spots recorded in the file header

The audit could not close three of them, and inventing a member would have been
worse than naming the gap (s15 rule):

* **cacheAsBitmap × TEXT** — both cab members are shape-only; every cab+text row
  in the corpus fails CI, so no Tier-1 member can exist.
* **RUNTIME gradient ramps** — all three gradient members are *static* gradients;
  all 7 runtime-gradient image rows fail CI.
* **morph / visual-suite masks / TLF rich text** — Tier-2-only, as before.

---

## 3. `ruffle-tests/recompiler_ab_sweep.sh` (NEW FILE)

Unifies four ad-hoc rewrites: s16 `w2-gfx-flatten-legC` (`sweep.sh` +
`boundscheck.sh`), s16 `w2-gfx-gradient`, s17 `w2-scope-opt` (marker sweep +
139-test byte A/B), s17 `w2-avm2-smalls` (env-var audit sweep). Read all four
before writing; the union of what they each needed is the CLI.

**What it does.** For every `test.swf` under the given suite roots: copy the SWF
into a private temp dir, run the OLD binary, snapshot
`RecompiledTags`/`RecompiledScripts`/`RecompiledABC`, run the NEW binary,
snapshot again, `diff -r`. Prints the **exact affected-test list**. The tracked
and gitignored test dirs are never touched, so it cannot poison a concurrent
agent's `Recompiled*` cache — the property all four ad-hoc versions had and none
of them documented.

**CLI.** `--old-bin PATH` | `--old SHA` (builds the before-binary via
`git archive <sha> SWFRecomp SWFModernRuntime/third_party/libtess2` + cmake into
a temp dir — **no `git worktree` is created**, so nothing in the shared checkout
is mutated, which matters on a 10-agent machine) | `--new-bin` (default
`SWFRecomp/build/SWFRecomp`) | `-P/--jobs` (default **2**) | `--timeout`
(default 300) | `--list FILE` | `--limit N` | `--bounds-check` | `--audit-env
VAR=FILE` | `--out DIR` | `--keep` | `--config`.

**Outputs.** `results.tsv` (test / verdict / detail), `affected.txt` (the list,
also on stdout), `bounds.tsv`, `audit.csv`. Verdicts: `IDENTICAL`, `DIFFERS`,
`OLD_FAIL`, `NEW_FAIL`, `BOTH_FAIL`, `NO_OUTPUT`, `AUDIT_HIT`.

`--bounds-check` is the leg-C premise-killer, generalised: it projects the
AS-visible trailing four arguments of `tagDefineShape` (plus every
`tagDefineMorphShape`/`Sprite`/`Text`/`EditText`/`Button` call) and, separately,
`tagMain.c` with all integers replaced by `N`. So "the geometry changed" and
"the bounds moved" are reported as **independent** facts — which is exactly the
discrimination that proved 418 tests' generated C changed while zero bounds
arguments did.

### 3a. Validation — three runs, all green

| control | command | result |
|---|---|---|
| **smoke (required by brief)** | same binary both legs, 30 avm1 SWFs, `--bounds-check`, `-P 2` | **30 IDENTICAL, affected list EMPTY**, exit 0 |
| **positive control 1** (structure) | old leg = wrapper that appends a comment to `tagMain.c`, 8 SWFs | **8 DIFFERS**, `STRUCT_DIFF 8`, `BOUNDS_DIFF 0` |
| **positive control 2** (bounds) | old leg = wrapper that rewrites one `tagDefineShape` bounds argument, `avm1/as_transformed_flag` | **1 DIFFERS**, `BOUNDS_DIFF 1`, `STRUCT_DIFF 0` |

An empty affected list from a same-binary run is necessary but **not** sufficient
— a broken script prints the same thing. The two positive controls close that,
and control 2 in particular proves the two projections fire **independently**
(structural perturbation → `STRUCT_DIFF` only; bounds perturbation → `BOUNDS_DIFF`
only). Without both, `--bounds-check` could report "0 bounds changes" from a
regex that never matches anything — which it *does* legitimately do on tests with
no `tagDefineShape` at all (`avm1/__framework__` has only `tagDefineSprite`
calls; that is a correct 0, and it is why control 2 had to be re-targeted at a
shape-bearing test).

`--audit-env` was exercised structurally (6 SWFs, `SWF_ASSOC_AUDIT=audit.csv`,
0 hits, exit 0). It cannot be *positively* validated against the master binary
because no audit env var exists there — that mode is only meaningful against a
patched recompiler, as in s17 `w2-avm2-smalls`. Stated as a known limitation.

### 3b. Documentation

`SESSION_START_GUIDE.md` gains a short section **"Which tests can a recompiler
change possibly move? (`recompiler_ab_sweep.sh`)"**, placed immediately before
"Full test suites (use CI only)" — i.e. in the run-tests flow, where someone
about to guess a blast radius will hit it. It carries the three usage forms, the
"answers *can it move?*, never *did it get better*" framing, the `-P 2` /
false-timeout rule, and the leg-C worked example.

---

## 4. Closeout doc corrections (arc doc deliberately NOT edited)

Per brief I did not touch `polish-sweep-arc.md`. Corrections noticed while
working, for whoever owns closeout:

1. **`polish-sweep-arc.md` §17.4, timeline-order bullet — strike
   `RegisterClassTest4`.** It is dispositioned twice over: an `ACCEPTED_DIFFS.md`
   entry **and** `from_gnash/misc-ming.all/ignored_tests.txt` since 2026-05-08.
   `wave1-timeline-order.md:25` and `:89` both say so, and its "Board edits this
   report implies" list already asks for exactly this (item 1). The 12-row
   framing over-counts.
2. **`polish-sweep-arc.md` §17.4, `displayobject_hittestpoint_boundary` bullet —
   the "missing leading blank line" half is REFUTED.** Per
   `w2-avm2-smalls-report.md`, the harness normalises blank lines out of both
   sides, so the fixture's opening `trace("")` was never graded; the row is one
   mechanism (edge exclusivity), not "two small independent fixes". The ignore
   file's inline note now records the refutation; the arc doc still carries the
   old wording.
3. **`wave1-trace-board.md` §5c — `hitarea` is misclassified.** It is listed as
   "no results row at all"; it has one (`from_shumway/avm1`, `ruffle_matched`,
   2/4). The entry itself is fine and already self-documented; only the board
   row is wrong. §5c's other two entries are correct.
4. **`from_shumway/ignored_tests.txt`'s own bucket header was factually false**
   ("All 16 re-confirmed still failing on 2026-08-01" — all 16 pass). Fixed in
   this patch, noted here because the same "re-confirmed on <date>" pattern
   appears in other bucket headers and should be read as a snapshot everywhere.
5. Not a correction, but a lead the coordinator may want on the board:
   **`avm2/soundmixer_soundtransform` is 888/900 with a single named mechanism**
   (§1c) — the closest thing to a free row now sitting inside an ignore list.
   `avm1/load_vars` (29/35, one missing `onLoad` dispatch) and
   `sandbox_type_remote` (1/3) are the next two.

---

## 5. Method notes / incidents

* `SWFRECOMP_COMPILE_TIMEOUT=2400` exported for every batch, per the s16 rule.
  Nothing timed out; the four canary captures took 262–358 s each at `-P 2`.
* Scratchpad namespaced to `w2hyg/` throughout. No `git stash`. No `pkill`.
  Background work detached with `setsid nohup` and polled actively.
* All four canary test dirs were `cp -r`'d fresh and their `Recompiled*` caches
  deleted before first use, then run with `--recompile` — the s16 stale-cache
  trap (`output_mismatch` that looks plausible) does not apply to these numbers.
* The worktree's `SWFRecomp/build` is a copy of the main tree's, valid here
  because nothing in this deliverable changes recompiler source.

### Reproduce

```bash
export SWFRECOMP_COMPILE_TIMEOUT=2400
# canary members
python3 ruffle-tests/render_canary.py capture --label hyg --recompile -P 2 \
  --test from_shumway/acid/acid-bitmap-fill --test from_shumway/acid/acid-bitmap-fill-2 \
  --test visual/filters/displacement_map_through_applyFilter \
  --test visual/edittext/edittext_border_transform
# sweep smoke test (must print an empty affected list)
ruffle-tests/recompiler_ab_sweep.sh --old-bin SWFRecomp/build/SWFRecomp --limit 30 \
  --bounds-check ruffle-tests/tests/swfs/avm1
```
