# w1-trace-numerics — wave 1 diagnosis: AVM2 numerics / strings / sound / E4X / avmplus trace failures

Read `BRIEFS_COMMON.md` first. Read-only: no source edits. Deliverable:
`SWFRecompDocs/plans/session18-fanout-reports/w1-trace-numerics-report.md`. Scratch dir: `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/w1-trace-numerics/`.

## Your board (suite `avm2` unless noted)
| test | exp | match | note |
|---|---|---|---|
| `number_tostring` | 1050 | 882 | NOT known_failure; 168 lines — cluster them by format class (radix? precision? exponent?) |
| `number_to_string` | 353 | 237 | known_failure — compare with the row above; shared mechanism? |
| `number_convert_errors` | 871 | 40 | known_failure; 831 lines — find the single rule that owns most of them, or NO-GO |
| `primitive_keys` | 54 | 33 | new 2026-08-23 |
| `xml_duplicate_attribute` | 14 | 7 | new 2026-08-21 |
| `from_avmplus/e4x/Expressions/e11_1_4` (suite `from_avmplus`) | 34 | 14 | we emit 37 lines for 34 expected — over-emitting; s17 UNOWNED |
| `from_avmplus/regress/bug_483783` (suite `from_avmplus`) | 1 | 0 | the ONLY `runtime_error` in the corpus — read its stderr (rule: runtime-error is the cheapest axis) |
| `simplebutton_soundtransform` | 887 | 829 | 58 lines; s17 UNOWNED: "a SoundTransform property-surface sweep" |
| `soundmixer_soundtransform` | 900 | 888 | 12 lines from passing; ignore-listed (host-I/O bucket) — s17 said "should be re-triaged, not documented" |
| `dependent_strings` | 84 | 46 | RUFFLE_VS_FLASH-flagged — confirm the disposition covers all 38 lines |
| `bom` | 9 | 6 | RUFFLE_VS_FLASH-flagged — confirm scope |
| `textline_atom_index_at_char_index` | 40 | 21 | known_failure (FTE) |
| `textblock_recreateline` | 180 | 41 | known_failure (FTE) |
| `from_avmplus/as3/Array/insertremove` | 30870 | 30766 | known_failure; memory says fix belongs in insertAt/removeAt hole shifting — 104 lines, price it |
| `from_avmplus/recursion/pcre_find_fixedlength` | 20 | 19 | known_failure; documented ceiling (capture indices stored as bytes) — confirm still true, else price |
| `vector3d_near_equals` | 80 | 67 | new 2026-08-15 (w1-trace-new may also look — coordinate via report) |

Do NOT touch: `eforin_001/002` (ACCEPTED), `verify_method_info_duplicate` (ACCEPTED),
`audio_computespectrum`/`audio/aac`/`audio/g711` (real FFT over decoded PCM, s17 NO-GO —
but state in one line whether a deterministic-output computeSpectrum stub could pass any of
the three; check what lines the tests actually print), `sound_load_multiple`
(`loadCompressedDataFromByteArray`, host-I/O bucket).

## Method
Run each test locally (`-P 2`, `SWFRECOMP_COMPILE_TIMEOUT=2400`, `--verbose`), read diff +
stderr, find the mechanism, cluster, price FULL-pass flips honestly (a diff-line lead is not
a flip lead), check dispositions and `output.ruffle.txt` where present, verdict GO/HOLD/NO-GO
with files + LOC + canary list (already-passing siblings: e.g. the `from_avmplus/ecma3/Number`
directory for number formatting; `avm2/number_*` passing tests). Attack the brief. Sibling
agents: w1-trace-new, w1-trace-avm1, w1-trace-display.
