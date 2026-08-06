# Session 13 · wave 2 · `w2-hygiene` — disposition hygiene bundle

**Agent:** `w2-hygiene` (main tree, docs/config only) · **Date:** 2026-08-06
**Base:** `10931d62e` (master) · **Baselines used for every verification:**
trace `_results/results_graphics.json` and image
`_results/image_results_graphics.json` at `1f8396f57`, CI run `31090651530`.
**No commit made** — the coordinator reviews and commits.

Doc-source reports: `wave1-board-audit.md` §4.2/§4.3/§5 L8,
`wave1-trace-singles.md` item 4, `wave1-gfx-charid0.md` §5/§7.

---

## 0. Files touched (5)

| file | what changed |
|---|---|
| `ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md` | +1 Category-2 entry, Category 9 rewritten + 1 new entry, Category 11 +1 entry + 1 staleness refresh, **new Category 13** (2 entries), 6 summary-table rows added / 2 corrected |
| `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` | `loader_load`/`bom` ignore-scope correction (new sub-entry), **new** `ruffle::isDependent()` entry |
| `ruffle-tests/tests/swfs/from_gnash/_investigation/ACCEPTED_DIFFS.md` | `simple_loop_test` staleness note + 2 summary-table rows corrected |
| `ruffle-tests/tests/swfs/avm2/ignored_tests.txt` | +4 suite-local entries (`loader_load`, `bom`, `dependent_strings`, `verify_method_info_duplicate`) with rationale block; s11 swz block cross-referenced to Category 13 |
| `ruffle-tests/ignored_tests.txt` | **comment-only**: the `netstream_play_flv` rationale carried the refuted "decoder fixed-point" mechanism. No entry added or removed. |

`scripts/image_triage.py` was **not** modified — see §7.

---

## 1. Image-comparison check (tasks 1–2 gate)

Read every candidate's `test.toml` directly:

| test | `[[image_comparisons]]`? | consequence |
|---|---|---|
| `avm2/loader_load` | **no** (`num_frames = 10`, `log_fetch = true`) | suite-local ignore safe |
| `avm2/bom` | **no** (`num_ticks = 1`) | suite-local ignore safe |
| `avm2/dependent_strings` | **no** (`num_ticks = 1` + `# NOTE: this is a Ruffle-only test.`) | suite-local ignore safe |
| `avm2/verify_method_info_duplicate` | **no** (`num_ticks = 2`, `known_failure = true`) | suite-local ignore safe |
| `avm2/verify_method_info_oob` | **no** | irrelevant — it **passes**, not listed |

None of the five carries image comparisons, so no ignore entry was skipped on
image-axis grounds, and none of them belongs in the **global**
`ruffle-tests/ignored_tests.txt` (a global entry is also an image-axis
disposition — that file's header, traps 1–2). All four live entries went into the
suite-local `avm2/ignored_tests.txt`, per the s11 precedent at its tail.

---

## 2. Task 1 — `avm2/loader_load` + `avm2/bom`

Re-verified at the baseline: both `output_mismatch`. Both were already fully
ruled in `RUFFLE_VS_FLASH_DIFFERENCES.md` §"AVM2 dynamic-property enumeration
order: `URLVariables.toString`" and in **no** ignore list.

- The existing entries did **not** mention an ignore-list decision — worse, the
  section closed with "it is **not** added to `ignored_tests.txt`". That sentence
  was correct about the global list and wrong about the suite-local one. It is
  now replaced by a dated sub-entry **"Ignore-list scope for `loader_load` /
  `bom`"** that states both halves explicitly, records the measured cost (gap 2 /
  gap 3 = the two cheapest-looking rows in the corpus; the s13 board audit
  re-costed them before noticing the ruling), and carries
  `<!-- image-axis: none -->` so its image-heavy prose cannot be mis-read by
  `image_triage.py` as a pixel disposition.
- Both names added to `avm2/ignored_tests.txt`.

## 3. Task 2 — `avm2/dependent_strings`

New `RUFFLE_VS_FLASH_DIFFERENCES.md` entry (84 expected / 83 actual / 46
matching, 38 differing lines). Evidence read first-hand from `Test.as`:

```actionscript
namespace ruffle = "__ruffle__";
try { trace(text.ruffle::isDependent()); } catch(e) { trace(); }
```

`isDependent()` is a Ruffle-internal debug hook onto its **rope-string**
representation (owned buffer vs dependent slice), with no Flash equivalent; the
graded `output.txt` is a transcript of Ruffle's concat/substr allocation
heuristics. We throw → the test's own `catch` traces a blank line → every
boolean row blanks while every string row matches (confirmed against the stored
diff). Flash would produce our output, not Ruffle's. Entry states that
explicitly, plus the suite-local-only ignore rationale. Added to
`avm2/ignored_tests.txt`.

## 4. Task 3 — `verify_method_info_{duplicate,oob}` — **half refuted**

The audit's L8 item 3 asks for both to be ignore-listed ("duplicate gap 1, oob
gap 4"). **`avm2/verify_method_info_oob` is `status = pass` in the baseline
results file** (1 expected / 1 actual / 1 matching). Listing a passing test hides
a win and directly violates the 2026-08-01 prune criterion for these files, so
**only `verify_method_info_duplicate` was treated**. The `rider-already-green`
memory rule applies verbatim: I checked the rider's baseline status before acting
on the board row.

Treatment (evidence is strong in s10 `wave1-trace-leads.md` §"VERDICT" and s11
`w2-triage-batch-report.md` §B2, so no local run was needed):

- New **ACCEPTED_DIFFS Category 2** entry (Internally Inconsistent Expected
  Output) — the inconsistency is *across two tests* built from one SWF by a
  one-byte patch, exactly like the existing `native_objects_swf6` entry, which is
  also a cross-test inconsistency. It tabulates `output.txt` /
  `output.ruffle.txt` / our actual for both tests, shows why emitting the
  trailing `#1065` flips `_duplicate` and demotes `_oob` `pass → ruffle_matched`
  (the `ruffle-matched-hides-regression` trap), and records that no parse-stage
  discriminator exists (both errors come out of the same `abc_parser.cpp`
  `readMethodBody` loop).
- The entry states in bold that `_oob` is **not** ignore-listed and why.
- `verify_method_info_duplicate` added to `avm2/ignored_tests.txt`;
  `verify_method_info_oob` **not** added.

## 5. Task 4 — ACCEPTED_DIFFS **Category 13** (AOT ceiling, Flex `.swz`)

Added verbatim-in-substance from `wave1-trace-singles.md` item 4: category
preamble (AOT recompiler ⇒ a runtime-fetched SWF can never define classes; this
is a ceiling, not a bug) plus the two entries
`avm2/loader_applicationDomain` (4 of 4) and `avm2/swz` (2 of 2), each with the
expected/actual block, the suite-local-only rationale, and
`<!-- image-axis: none -->`. Two summary-table rows appended.

**No ignore-list change for these two** (already suite-local-listed in s11, as
the audit says) except the requested one-line cross-reference appended to that
block: `# Documented in avm1/_investigation/ACCEPTED_DIFFS.md Category 13`.

## 6. Task 5 — Category 9 mechanism correction (video)

The old preamble blamed "different fixed-point arithmetic internally" in the
decoders and put the drift at "1–3 levels in solid regions". Replaced with a
dated **mechanism correction** block naming the real term — `sws_scale`'s
YUV→RGB conversion in `video_codec.c::decode_via_libavcodec` (chroma
interpolation + rounding) — and carrying the measured table from
`wave1-gfx-charid0.md` §5:

| test | via `sws_scale` | via Ruffle's exact BT.601 |
|---|---:|---:|
| `vp6` / `vp6_dispsize` | 449 774, max 3 | **0, byte-exact** |
| `vp6_alphaoffset` | — | **0, byte-exact** |
| `vp6a` | — | 118, max 1 (`tolerance = 1` ⇒ passes) |
| `h263` | 392 707, max 4 | 10 808, max 2 |

so the entry now states that **libavcodec's VP6F/VP6A decode is bit-identical to
Ruffle's** and the VP6 family is exact *as of the session-13 video patch* — i.e.
phrased as a property of the fix, for the coordinator to land alongside it.

Also added: **`visual/video/colorconversion/h263`** entry (10 808 outlier
channels, max 2; the full `idct_algo` sweep; why FAAN is a CI-determinism hazard;
image-axis scope marker), and an explicit "**NOT dispositioned:**
`visual/video/deblocking`" paragraph — its gap (missing `h263-rs-deblock` +
`MAX_EMBEDDED_VIDEO_STREAMS = 8` dropping streams 9–12) is implementable, so it
stays live work. The `netstream_play_flv` entry's mechanism sentence was
rewritten the same way, flagged as *not re-measured post-patch* (expect a band
move, not a flip). Matching comment fix in `ruffle-tests/ignored_tests.txt`.

`h263` is **not** added to any ignore list: its trace test passes, and the
image-axis disposition is already supplied to `image_triage.py` by the scope
marker.

## 7. Task 7 — `simple_shapes/masks` reclassification — encoded as a doc entry, **no code change**

I read `scripts/image_triage.py` first. **It has no keyed override list.** Its
only disposition mechanism is doc-driven: `DISPOSITION_DOCS` (avm1
ACCEPTED_DIFFS, avm1 RUFFLE_VS_FLASH, from_gnash ACCEPTED_DIFFS) scanned by
`scan_disposition_doc()`, where a **qualified** name in an entry heading matches
across suites regardless of the doc's own scope, and an
`<!-- image-axis: … -->` marker is authoritative over the keyword heuristic.
That is "the way the script already encodes other dispositions", and the audit
§4.2 says so too ("fix by disposition entry"). So the ruling is encoded as a new
**Category 11** entry in the avm1 ACCEPTED_DIFFS naming
`visual/simple_shapes/masks` and `visual/simple_shapes/masks_equal_clipdepth`,
with the s12 pixel-pair evidence (776 mismatching pixels, whole-stage bbox,
saturated-colour swaps only ⇒ `MSAA_SAMPLES = 1`), the "no `DoABC`, no
`setMask`, no `scrollRect` ⇒ defects B/C cannot reach it" argument, and a
standing invariant that the marker covers only these two `output` comparisons.

**Verified by executing the tool's own resolver** (not by inspection):

```
visual/simple_shapes/masks [output]                -> hard=True  (ACCEPTED_DIFFS avm1)
visual/simple_shapes/masks_equal_clipdepth [output]-> hard=True
visual/video/colorconversion/h263 [output]         -> hard=True
visual/video/colorconversion/vp6 [output]          -> None  (still live, correct)
visual/video/deblocking [output]                   -> None  (still live, correct)
from_gnash/…/simple_loop_test [frame1]             -> hard=True  [in scope: frames 1-2 only]
from_gnash/…/simple_loop_test [frame3]             -> None       (still live work, correct)
avm2/{loader_load,bom,dependent_strings,verify_method_info_duplicate} -> trace-axis, kept on board
```

Hard rows are dropped from `rankable()`, so both `masks` rows leave the head of
`same_geometry_wrong_fill` and appear under "DISPOSITIONED FAILING COMPARISONS".
**Note for the coordinator:** this *excludes* them from the ranked board rather
than *relabelling* their cluster to `hairline_edge_drift`. Relabelling would need
new logic (a keyed cluster override), which the brief said to avoid; the
practical effect the audit asked for — "stop ranking them at the head" — is
achieved.

## 8. Task 6 — the two stale entries

1. **`avm1/display_object_properties`** — the entry was *already* marked
   "STALE: now PASSES" in s9 (baseline `375373786`), so nothing was mis-stated.
   Re-verified at the current baseline (`status = pass`, `excess_outliers = 0`)
   and added a dated re-confirmation line + refreshed the summary-table row to
   cite `1f8396f57` / run `31090651530`.
2. **`from_gnash …/loop/simple_loop_test`** — the audit says the "frames 1–2"
   scope now passes. Measured: **all seven comparisons (`frame1`…`frame7`) pass
   with `outliers = 0`.** So *both* halves of the entry are stale — the accepted
   hairline residual (was 121–724 px) **and** the "NOT accepted, live work"
   frames 3–7 timeline-phase off-by-one (was 7442–21600 px). Added a status note
   saying exactly that, struck both summary-table magnitude columns, and
   deliberately **kept the `<!-- image-axis: frames 1-2 only -->` marker** so a
   future frame-3 failure is still classified as live work rather than silently
   accepted.

---

## 9. Skipped / not done, with reasons

| item | reason |
|---|---|
| ignore-listing `avm2/verify_method_info_oob` | **it passes** at the baseline; listing it would hide a win. The audit's L8 item 3 is half wrong. |
| ignore-listing `visual/video/colorconversion/h263` | trace side passes; the only ignore list that would carry an image-axis disposition is the global one, and that would also drop a passing trace row from filtered results. The ACCEPTED_DIFFS scope marker already dispositions the pixel axis. |
| ignore-listing `avm2/{loader_applicationDomain,swz}` | already suite-local-listed in s11 (per brief). |
| dispositioning `visual/video/deblocking` | its residual is implementable (deblock filter port + `MAX_EMBEDDED_VIDEO_STREAMS` 8→16); recorded as explicitly NOT dispositioned inside Category 9 so a future session does not file it as accepted. |
| any edit to `polish-sweep-arc.md` / `graphics-fanout-playbook.md` | out of scope per brief §8 (coordinator owns board errata). Note that §13.3's "s11 hygiene never applied" line and §11's masks line are now both stale in the coordinator's direction. |
| any C/C++/Python source edit | none needed; see §7. |
| local test runs | none required — every claim was verified against the merged baseline results files, the test `test.toml`/`Test.as` sources, or the tool's own resolver. No suite run, no CI dispatch. |

## 10. Verification commands

```bash
# statuses / line counts / image comparisons, all from merged baseline results
python3 - <<'PY'
import json
d=json.load(open('ruffle-tests/tests/swfs/avm2/_results/results_graphics.json'))
...
PY

# disposition resolution, using image_triage.py's own Dispositions class
python3 - <<'PY'
import importlib.util; from pathlib import Path
spec=importlib.util.spec_from_file_location("it","scripts/image_triage.py")
m=importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
D=m.Dispositions(Path('ruffle-tests/tests/swfs'), Path('ruffle-tests'))
print(D.lookup("visual","simple_shapes/masks","output"))
PY
```
