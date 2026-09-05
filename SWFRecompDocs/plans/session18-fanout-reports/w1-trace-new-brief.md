# w1-trace-new — wave 1 diagnosis: NEW upstream AVM2 tests (arrived 2026-08-15..09-03), never diagnosed

Read `BRIEFS_COMMON.md` first. Read-only: no source edits. Deliverable:
`SWFRecompDocs/plans/session18-fanout-reports/w1-trace-new-report.md`. Scratch dir: `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/w1-trace-new/`.

## Your board (all `avm2` unless noted; exp/match = expected/matching lines at baseline)
| test | exp | match | notes |
|---|---|---|---|
| `matrix3d_append_prepend_scale` | 86 | 0 | new 2026-08-15; actual emits 46 lines — truncation? s17 landed Matrix3D f32 + number-format (`session17-fanout-reports/w2-matrix3d-classes-report.md`) — read it first |
| `matrix3d_interpolate` | 21 | 0 | new 2026-08-15; `#1009 null object` — probably `Matrix3D.interpolate`/`interpolateTo` missing |
| `matrix3d_copy_from` | 19 | 15 | |
| `matrix3d_copy_to_matrix3d` | 19 | 15 | |
| `vector3d_near_equals` | 80 | 67 | new 2026-08-15 |
| `flash_ui_mouse_cursor` | 35 | 1 | new 2026-09-03; `#1065 MouseCursorData is not defined` — class + `Mouse.registerCursor`/`Mouse.cursor` surface |
| `movieclip_addframescript_error` | 9 | 0 | new 2026-08-28; we emit 0 lines |
| `bitmapdata_applyfilter_identity` | 4 | 2 | new 2026-08-22 |
| `bitmapdata_copypixels_alpha_combine` | 13 | 2 | new 2026-08-22 |
| `bitmapdata_copypixels_alpha_merge` | 9 | 3 | new 2026-08-22, **known_failure** upstream (rule 3) |
| `fonts/embed_name_lookup` (suite `fonts`) | 242 | 86 | new 2026-08-21 |
| `primitive_keys` | 54 | 33 | new 2026-08-23 |
| `xml_duplicate_attribute` | 14 | 7 | new 2026-08-21 |

Also: the coordinator will message you a list of test dirs that exist on disk after today's
sync but are ABSENT from `_results/results_graphics.json` (brand-new upstream, never graded).
Run each once (`--diff --verbose`) and report its status; they are ungraded yield or drift.

## Method
1. For each test: run locally (`-P 2` max, `SWFRECOMP_COMPILE_TIMEOUT=2400`), read the diff and
   stderr, read the test's `Test.as`/`test.toml`/`output.txt` and, where useful, upstream Ruffle's
   implementation under `~/CC/ruffle/core/src/avm2/globals/` (use `git -C ~/CC/ruffle log -p`
   on the test dir to see the commit that added it — the PR usually names the behaviour).
2. Name the mechanism per test; cluster shared mechanisms (e.g. one missing class, one
   coercion rule). Price flips: which tests reach FULL pass with which change; which rows
   stay blocked by a second mechanism (say so).
3. Check dispositions (rule 2) even though these are new — a sibling test may already be
   dispositioned for the same behaviour.
4. Verdict per cluster: GO (name files/functions + estimated LOC + a headline canary list of
   already-passing siblings that exercise the same code) / HOLD (completion mechanism) / NO-GO.

Sibling agents this wave: w1-trace-avm1 (AVM1 hitArea + gnash), w1-trace-display (AVM2 display/
timeline/loader/focus), w1-trace-numerics (AVM2 numerics/strings/sound/e4x). If a test of yours
turns out to belong to their family, note it and move on; do not diagnose their rows.
