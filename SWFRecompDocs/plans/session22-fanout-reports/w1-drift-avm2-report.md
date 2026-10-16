# w1-drift-avm2: upstream drift (AVM2 + fonts), harness semantics, and the ignore-list re-test

Session 22, wave 1, cloud worker. Branch `fanout/w1-drift-avm2`, based on `origin/master` at `be8f4b62`.
Corpus: `download_tests.sh avm2 fonts avm1 from_avmplus from_gnash from_shumway`, run at upstream Ruffle
**`45366370e`** (`git ls-remote` master, same as the coordinator's sync). Ruffle source: blobless clone at `/root/ruffle`.
Box: `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe). Every run below is `--mode=graphics --verbose`.

**New files in this commit (wave 1, no source changes):**
- `SWFRecompDocs/plans/session22-fanout-reports/w1-drift-avm2-report.md` (this file)
- `SWFRecompDocs/plans/session22-fanout-reports/w1-drift-avm2-prototype.patch`: `git diff origin/master -- SWFModernRuntime`,
  one file (`avm2_display.c`, +39/−3), applies cleanly to `origin/master`. It carries the two measured
  prototypes below. The source tree is reverted.

---

## 1. Price table (every added or modified non-AVM1 test in `0dacba55f..45366370e`)

"CI 10-03" is the graphics/full run at `4c450f076` (results `846adcc6b`). Rows marked ABSENT were added
upstream after that run, so CI has never graded them. Book their flips as **new rows**, not recovered yield.

| Test | CI 10-03 | Now (master) | match/exp | KF / ruffle.txt | Mechanism (owner) | Price | Verdict |
|---|---|---|---|---|---|---|---|
| `avm2/goto_queued_invalid/swf9` | fail 2/32 | fail | 2/32 | KF / yes | invalid goto in a frame script is not a no-op (`avm2_display.c:8095`) | **measured: 1 line** | **GO → PASS (prototype)** |
| `avm2/goto_queued_invalid/swf10` | fail 2/34 | fail | 2/34 | no | same, plus `gotoAndPlay(999)` re-arming the last frame's script (`avm2_display.c:3153`) | **measured: +8 lines** | **GO → PASS (prototype)** |
| `avm2/goto_queued_invalid/swf11` | fail 2/43 | fail | 2/43 | no | same two, plus the #2109 text for `undefined` (`avm2_display.c:8013`) | **measured: +1 line** | **GO → PASS (prototype)** |
| `avm2/mouse_pick_scroll_rect` | ABSENT | fail | 3/27 | no | AVM2 mouse pick ignores the container's `scrollRect` (`avm2_display.c:14884` `mouse_pick`) | **measured: ~20 lines** | **GO → PASS (prototype)** |
| `avm2/mouse_pick_scroll_rect_button` | ABSENT | fail | 3/5 | no | same (SimpleButton arm) | same patch | **GO → PASS (prototype)** |
| `avm2/mouse_pick_scroll_rect_loader` | ABSENT | fail | 1/5 | no | same (Loader container) | same patch | **GO → PASS (prototype)** |
| `avm2/collator_flags` | ABSENT | fail (`ReferenceError #1065 Collator`) | 0/111 | no | **no `flash.globalization.Collator` class at all**; only `CurrencyParseResult` exists in that package (`avm2_globals.c:7299`) | small (~120 LOC with the next two) | **GO (wave 2)** |
| `avm2/collator_locale_ids_windows` | ABSENT | fail (same) | 0/120 | no | same, plus `LocaleID`/`CollatorMode` constants, `getAvailableLocaleIDNames()` (fresh unfixed `Vector.<String>`), ctor validation #2007/#1508 with native frames `Collator/ctor()` + `Collator()` | +~60 LOC | **GO (wave 2)** |
| `avm2/collator_compare_basic` | ABSENT | fail (same) | 0/93 | KF / yes | same, plus `compare`/`equals` collation (see §1.3) | +~80 LOC | **GO (wave 2), Flash-correct, beats Ruffle** |
| `avm2/html_text_img_parsing` | fail 118/175 | fail (exp. now **600**) | ~244/600 | KF / yes (505 lines) | `<img>` parse/serialize missing in the AVM2 HTML parser (`avm2_text.c:1337` `spans_from_html`, `:2264` `spans_to_html`) | medium (~150 LOC, a port of Ruffle's `8cbada89a` `text_format.rs`) | **GO (wave 2) → ruffle_matched** (the full pass needs 95 `Error #2044 Unhandled IOErrorEvent` lines from real img loads: HOLD) |
| `avm2/textline_metrics` | ABSENT | fail | 0/20 | no | `TextLine.ascent/descent/totalAscent/totalDescent` stubbed 12/3 (`avm2_text.c:8010-8013`, `:7289`) | medium (DefineFont4 OpenType metrics + plumbing) | **GO-maybe (wave 2)** |
| `fonts/device_font_name_case` | ABSENT | fail | 1/13 | no | AVM1 TextField measurement ignores `[fonts.*]` device faces; every name measures the same width | high | **HOLD** |
| `avm2/textblock_recreateline` | ruffle_matched (139⊆140, exp 180) | **ruffle_matched** (exp 178) | — | KF / yes | upstream dropped device-font metric lines (`9f5c81d56`). Ours = Ruffle-like (recreateTextLine doesn't reset DisplayObject state) | medium, **0 effective** | **NO-GO** (already effective) |

**Effective yield on the table: +6 measured (prototype), +3 Collator, +1 html_text_img (ruffle_matched), +1 textline_metrics if
funded = up to +11.** Of these, `goto_queued_invalid/*` (3) and `html_text_img_parsing` (1) are rows CI already grades
(recovery). The other 7 are rows CI has not graded yet, so they show up as new rows in the next run's total.

### 1.1 `goto_queued_invalid/swf9..11`: what Flash encodes, and the measured prototype

Upstream `e092c78c2` ("Ignore invalid goto targets inside frame scripts") + tests `edef34c13`. Flash behaviour:
inside a running AVM2 frame script, a goto whose resolved frame is **0** (literally `0`, `'0'`, `undefined`, `{}`,
`-Infinity`: every value that coerces to frame 0 / an unknown label in SWF<11) is a **complete no-op**: no
jump to frame 1, and no stop/play either. The clip keeps playing. Ours jumped to frame 1 and stopped, so the
run stalls at `currentFrame=1` (2/32 matching).

The prototype has three edits, all in `SWFModernRuntime/src/avm2/avm2_display.c`:

1. `mc_goto_with_args` (before `:8095`): `if (frame == 0 && ext->executing_frame_script) return;` placed before
   `mc_set_programmatically_played`. This is Ruffle `movie_clip.rs:454`. **swf9 passes with this alone.**
2. `run_goto` (`:3153`): re-arm `queued_script_frame` only when the goto **hit its target** (`clamped == frame`) **or
   SWF ≤ 9**. Ruffle's `run_goto` (`display_object/movie_clip.rs:1872`): *"gotoAndStop(9999) displays the final
   frame, but actions don't run!"* Its `run_frame_internal` (the only writer of `queued_script_frame`) is skipped when
   `!hit_target_frame`. In swf10, `gotoAndPlay(999)` lands on frame 6, Flash does **not** run frame 6's script,
   and the next tick wraps to frame 1. **Attack on the Ruffle port:** applying Ruffle's rule unconditionally
   turns swf9 `PASS → RUFFLE_MATCHED`, because Flash *does* run frame 6's script in SWF9 (expected
   line 29 `Entered frame 6`, which is exactly the line Ruffle gets wrong; swf9 is `known_failure` upstream). Hence the
   `swf_version <= 9` arm. This is a deliberate Flash-over-Ruffle choice: **wave 2 must add it to
   `RUFFLE_VS_FLASH_DIFFERENCES.md`** (AVM2 section).
3. `mc_goto_with_args` (`:8013`): `frame:Object`. Coercing `undefined` to `Object` yields `null`, so the SWF11
   #2109 message reads `Frame label null not found in scene null.` (ours said `undefined`).

Measured (graphics, lavapipe): swf9 / swf10 / swf11 all **PASS**. **Collateral sweep (45 rows):** every avm2 test
whose name matches `goto|framescript|frame_script|scene|nextframe|prevframe` (list in §6). **45/45 unchanged** against
CI 10-03 (43 pass, 2 ruffle_matched). Edit 2 also changes gotos past the last frame that happen **outside** frame
scripts in SWF10+. No corpus row in the sweep moved, but **run CI `categories=full`** (AVM2 runtime) before landing.

### 1.2 `mouse_pick_scroll_rect{,_button,_loader}`: Flash behaviour and the measured prototype

Upstream `387ea68a4` ("Clip mouse events to scrollRect viewport"). Flash: the viewport of a container's `scrollRect`
clips **mouse picking**, not just rendering. A point outside the viewport misses the container's whole subtree, so the
event goes to the Stage. Ruffle puts `global_in_scroll_rect` on the three child-walking pick paths: MovieClip/Sprite,
LoaderDisplay, Avm2Button. TextField and Stage are not touched.

The prototype adds `pick_in_scroll_rect()` (inverse `display_l2g_matrix`, inclusive `Rectangle::contains`, and a singular
matrix counts as outside). It is called at the top of `mouse_pick` for every non-TextField, non-Stage object. Measured:
**all three PASS.** Collateral: every avm2 SWF that contains the string `scrollRect` (23 rows; static scan of
decompressed SWF bytes). The 20 non-headline rows are **20/20 unchanged** (all pass; the pixel rows' image checks also
pass). The only rows that run this code with input are the three headliners plus `stage3d_texture`/`stage3d_raytrace`,
which still pass.

**Sibling note (`w1-crossvm`):** `mouse_pick_scroll_rect_loader` flips with this generic patch. No mixed-AVM or
loader-specific mechanism is needed: the Loader is an ordinary container on our `render_list` path.

### 1.3 Collator: what Flash encodes (`3c54f0728`, `ab1168095`, `062f5c7a3`, `0b00bc8f4`, `8aaf96ab3`)

Today all three tests die at the first `new Collator`: `ReferenceError #1065`. A wave-2 slot needs:

- **`flash.globalization.Collator`** (final, native-backed): ctor `(requestedLocaleIDName:String, initialMode:String =
  "sorting")` delegating to a private native `ctor` (stack traces must read `at flash.globalization::Collator/ctor()` then
  `at flash.globalization::Collator()`). Null id gives #2007 `Parameter requestedLocaleIDName must be non-null.`, checked
  **before** mode. Null mode gives #2007 `initialMode`. Any mode other than exactly `"sorting"`/`"matching"` (case- and
  space-sensitive) gives `ArgumentError #1508 The value specified for argument initialMode is invalid.` The locale ID is
  stored verbatim (Windows behaviour; `"i-default"`, `"de-DE@collation=phonebook"`, `""` all round-trip).
- Six Boolean flags, `ignoreCase, ignoreCharacterWidth, ignoreDiacritics, ignoreKanaType, ignoreSymbols,
  numericComparison`, with setters doing a Boolean coerce. Defaults: sorting = all false; **matching = first five true,
  `numericComparison` false.** `lastOperationStatus` = `"noError"`. `actualLocaleIDName` (Ruffle returns the requested ID).
- `static getAvailableLocaleIDNames()`: a **new** non-fixed `Vector.<String>` per call (not `===`, and mutations don't
  leak back). Its contents aren't graded beyond non-empty; `["en-US"]` like Ruffle is fine.
- `CollatorMode` (`SORTING="sorting"`, `MATCHING="matching"`), `LocaleID.DEFAULT = "i-default"`, and
  `LastOperationStatus.NO_ERROR`. None of these classes exist today.
- **`compare`/`equals`**: null args give #2007 `Parameter string1/string2 must be non-null.` (string1 checked first),
  frame `Collator/compare()` / `Collator/equals()`. `compare` returns −1/0/1. **Flash (Windows) ordering**, verified
  against all 93 expected lines: compare a primary key first (Latin-1 letters folded to their base letter, then
  case-folded). Then **diacritics always count: `ignoreDiacritics` and MATCHING do NOT make `e`==`é`** (expected
  `e vs é: -1 false` in every config). Then case: lowercase sorts before uppercase unless `ignoreCase`. This reproduces
  `é vs z: -1` and `résumé vs rf: -1`, the two lines where Ruffle's codepoint compare is wrong (`collator_compare_basic`
  is `known_failure` upstream, so the pass beats Ruffle: allowed, Flash-correct).

Owner: a new block next to `CurrencyParseResult` in `avm2_globals.c` (`:7130-7310`), with no new TU. Risk: none
outside these three rows (the classes don't exist today).

### 1.4 `html_text_img_parsing` (AVM2): `8cbada89a` + `d587c9763`

Flash: `<img>` in `htmlText` inserts **one placeholder space** into `text`. It serialises back as
`<FONT SIZE="2"><IMG SRC=… WIDTH HEIGHT ID ALIGN VSPACE HSPACE> </FONT>` inside the run: integers truncated, an invalid
numeric attribute dropped, `align` normalised to left/right (`middle` becomes `left`), entities decoded in `src`/`id`.
Flash also tries to **load** each `src` and reports 95 × `Error #2044: Unhandled IOErrorEvent:. text=Error #2035: URL Not
Found.` at the end. Ruffle omits those 95 lines (its 505-line `output.ruffle.txt` = Flash's first 505 lines exactly).
Our 356 differing lines are **all** in the img mechanism (TEXT=/HTML= rows plus the 5 FIRST/SECOND summary rows) or
in the 95-line tail.

Price: port Ruffle's `text_format.rs` img handling into `avm2_text.c` `spans_from_html`/`spans_to_html` to reach
`ruffle_matched` (+1 effective). The AVM1 parser in `action.c` is a **separate** port (the `w1-drift-avm1` sibling
has `avm1/html_text_img_parsing{,_swf5,_swf6,_swf7}`). **Fund both ports in one wave-2 slot** so the two parsers share
one reading of Ruffle's rules. The full pass needs img Loader creation plus an unhandled-IOErrorEvent report per img
(→ HOLD, mechanism: per-img Loader in the TextField, async `Error #2044` print at tick end).

### 1.5 `textline_metrics`: `39c0179b7` (+ `d4b72ed81`/`9f5c81d56`)

Flash: `TextLine.ascent/descent` are the **laid-out line's** metrics. `totalAscent/totalDescent` equal them for a
single-run line. The test embeds `TestFont` as **DefineFont4** (`OTTO`, CFF), `fsSelection=0x80`
(**USE_TYPO_METRICS**), typo asc/desc **800/−200**/1000 upem (hhea is 800/**0**, so a wave-2 worker must use the typo
values, the same as ttf-parser's `ascender()`/`descender()` rule). Expected `ascent = 0.8·size`, `descent = 0.2·size`
for every content, including empty-ish lines (`\t`, `\n`, ` `) at the element format's size.

Ours returns the constants 12/3. Price: resolve the TextLine's ElementFormat size + FontDescription (`fontName`,
`EMBEDDED_CFF`) to a DefineFont4 face, read OS/2 typo (or hhea when bit 7 is clear), scale by size/upem. There is no
DefineFont4 metric reader today. Collateral: any other test reading `TextLine.ascent` (`textblock_*` rows: upstream
**removed** their device-font metric lines in `9f5c81d56`, so they should be insensitive). A device-font TextLine
(no DefineFont4) needs a rule too: Ruffle uses the fallback layout's device face. Keep 12/3 there to stay
byte-identical, and say so. **GO-maybe**: 1 new row for ~100 LOC.

### 1.6 `fonts/device_font_name_case`: `727e6e5dc` + `b8793d8a6` + `67b7297b8`

Flash: a device-font name resolves **case-insensitively** but otherwise **exactly**. A prefix/suffix/interior space
doesn't match, and a **single** name is not whitespace-trimmed (only comma-separated list entries are trimmed: `b8793d8a6`,
which also "fixed" this test's `output.txt`). The test is **AVM1** (Rascal `test.as`) with two `[fonts.*]` TTFs.

Refutation of a premise I started from: the device-TTF infrastructure exists (s21 `abc_devicefont.cpp`
`emitDeviceFonts`), but it is emitted only from the **AVM2** timeline path (`SWFRecomp/src/abc/abc_timeline.cpp:2258`).
The AVM1 measurement (`action.c:28756`, `info.device_font`) never sees `[fonts.*]`, so every name, valid or not,
measures the same width (`A=true, B=true` on every line). Price: emit device faces for AVM1 SWFs, plus AVM1 font-name
resolution with Flash's matching rules. That touches gnash `TextField-v6..8` and `misc-mtasc TextFieldTest` (also
`[fonts.*]`), so the canary + pixel blast radius is real. **HOLD**: completion mechanism = an AVM1 device-font slot
(the recompiler emits the table for AVM1 too; `action.c` measurement looks up by case-folded exact name). 1 row.

### 1.7 `textblock_recreateline`: drift only

Upstream `9f5c81d56` removed device-font-dependent metric lines (expected 180 → 178). Still **ruffle_matched**. The
remaining 69 Flash-vs-Ruffle lines are DisplayObject state (`blendMode`, `alpha`, `rotation`, `filters`…) that Flash
**resets** on `recreateTextLine` and Ruffle (and we) keep. A full pass is +0 effective: **NO-GO** (an unclaimed lead
for a polish slot).

---

## 2. Harness semantics: Ruffle `tests/framework` @`45366370e` vs `ruffle-tests/verify_output.py`

**Refutation of the brief's premise:** the framework changes in range are smaller than the brief says.
`git diff 0dacba55f 45366370e --stat -- tests/framework` is 30 lines. Only **one is semantic**: `ae8286d69` (NaN == NaN in
`Approximations::compare`). `77c855f76` adds `(line:column)` to error text only. **`947eb957e` changes no framework
code**: it switches four **AVM1** `test.toml`s (`point`, `rectangle`, `matrix`, `as_setup_error`) from `num_frames = 1` to
`num_ticks = 1`. The rest is the `SwfMovie → SwfMovieData` rename.

To price each gap I wrote a Ruffle-faithful comparator (a port of `runner/trace.rs` `test()` + `approx::relative_eq` +
Rust `str::lines`/`parse::<f64>`; scratch, not committed). I graded our **actual** output (`--save-actual`) for all
**47** corpus rows with `[approximations]` against it.

| # | Gap | Ruffle | Ours (`verify_output.py`) | Corpus rows | Verdicts moved |
|---|---|---|---|---|---|
| H1 | NaN in approx compare (`ae8286d69`) | NaN≈NaN passes | `float('nan')` compare → False (`_lines_approx_equal` `:1166`) | only reachable on a line that differs textually *and* has NaN captures. None of the 47 | **0** |
| H2 | `bare_numbers` gating | whole-line f64 compare **only if `bare_numbers = true`** | whole-line `float()` compare for **any** `[approximations]` | 17 rows are `number_patterns`-only (lenient for us) | **0** (re-graded, 46/46 pass both ways) |
| H3 | pattern fallthrough | first pattern that matches both lines **decides** (a fail is a fail) | on failure, tries the next pattern | 1 row with 2 patterns (`avm2/perspective_projection`) | **0** |
| H4 | default tolerances | `relative_eq!` defaults: epsilon **and** max_relative = `f64::EPSILON` | 0 / 0 (stricter by ~1 ulp) | 47 | **0** (none fails on a 1-ulp gap) |
| H5 | Rust vs Python float parse | no whitespace/underscores | Python `float()` accepts both | 47 | **0** |
| H6 | approx line count | must be equal, else the whole test fails | per-line | 47 | 0 (a count mismatch fails both ways) |
| H7 | exact compare is byte-exact on the **whole** text | trailing/leading blank lines count | strips leading+trailing blank lines from both (`compare_output` `:3831`, `filter_output`) | **243** expected files end in a blank line, **15** start with one, **156** are empty (414 rows; 401 pass) | **unpriced, sampled 0**: 2 lead-blank rows (`avm1/global_array`, `avm2/place_multiple`) emit the blank trace correctly in raw stdout. A strict check is impossible today because boilerplate blank lines are interleaved with trace output on stdout |
| H8 | `\r` handling | expected: only `\r\n`→`\n`; a lone `\r` stays in the line | expected via `read_text()` (**universal newlines: a lone `\r` becomes a line break**), actual decoded raw | **1** file with a lone CR: `from_avmplus/ecma3/GlobalObject/encodeURI` (pass) | **0** today; a latent asymmetry |
| H9 | NUL bytes | stripped from **actual** | not stripped | 0 expected files contain NUL | 0 (NUL-tracing tests would differ runtime-side anyway) |
| H10 | `ignore = true` | test not run | graded | **9** rows: 8 pass (`avm2/bytearray_oom`, `filereference_save_and_load`[KF], `bitmap_pixelsnapping`, `from_avmplus` `AMFSerializer`, `ByteArray_bug662851_32bit/_64bit`, `StatClassSameNamePackage`, `ecma3/Exceptions/bug127913`[KF]); 1 fail (`avm2/number_tostring`, already in our ignore list) | honoring it: graded −9, pass −8, fail −1. **Every reason is Ruffle-side** (OOM, stack overflow, "how to compile this", backend pixel variance; `number_tostring` is Flash nondeterminism). **Recommend: don't honor it.** These are Flash-correct passes. Keep `number_tostring` in our own ignore list |
| H11 | `known_failure.panic` / `.ruffle_check = false` | Panic: trace not checked; ruffle_check=false: just must fail | any table counts as KF (`_test_is_known_failure` `:3790`) | 10 rows; only `ASnative-v5..8` ship a `.ruffle.txt`, and there the flag is **macOS-subtest-scoped** | **0** |
| H12 | tick vs frame | `num_ticks` → `Player::tick(1/fps)` (frame cadence follows a script-set `stage.frameRate`, `is_playing`, audio skew, sockets); `num_frames` → `run_frame()` | both are a plain frame count (`get_num_frames` `:1033`) | 2264 `num_ticks` rows. Only one has a runtime `frameRate =` assignment (`avm2/flash_ui_mouse_cursor`), and it is `MouseCursorData.frameRate`, not the stage | **0** |
| H13 | tomllib vs Ruffle `toml` | TOML 1.1 multi-line inline tables parse | `tomllib` throws on 3 avm1 `test.toml`s (`as2_super_and_this_v8`, `as2_super_via_manual_prototype`, `action_to_integer`); KF/approx readers then fall back to "no flags" | 3 | **0** (none carries `known_failure`/`approximations`/`ignore`) |

**Same-shape gap as s21's ANY/ALL, found in the ignore filter (not in Ruffle's framework):**
**H14: the root `ruffle-tests/ignored_tests.txt` is AVM1-authored but `filter_results.py:96-109` applies it to every
suite by bare name.** Collisions in `results_graphics`: `avm2/date` (**pass**, silently removed from the filtered
totals because of the AVM1 `date` ACCEPTED_DIFFS entry), `avm2/sandbox_type_remote` (fail, ignored only through the root
AVM1 entry at `:195`, with no AVM2-side disposition), and `avm2/netstream_play_flv` (redundant: also in
`avm2/ignored_tests.txt:103`). Price: **+1 effective in the filtered view** (`avm2/date`) and +1 visible fail
(`avm2/sandbox_type_remote`, unless it gets its own avm2 entry; the root comment's two-mechanism analysis applies
to both VMs). The graded/unfiltered number does not move (arc §22.5: ignore lists never touch it).

**Proposed patch scopes (harness):**
- **P-H14 (small, GO):** in `filter_results.py`, scope the root list to the `avm1` suite, or accept `suite/name`
  qualified entries and qualify the three colliders. Expected: `avm2/date` reappears as a filtered pass.
  `avm2/sandbox_type_remote` needs a deliberate `avm2/ignored_tests.txt` line or stays a visible fail.
- **P-H1..H6 (optional parity, 0 verdicts):** make `_lines_approx_equal` Ruffle-exact (NaN equality, gate whole-line
  parse on `bare_numbers`, first-matching-pattern decides, `f64::EPSILON` defaults, Rust float grammar). Re-grade the 47
  rows. My comparator says all 46 passes survive and `from_shumway/esc` stays failing. This is worth doing only to stop
  future drift from hiding behind leniency. It is not yield.
- **P-H7/H8 (diagnostic first):** read `expected` with `newline=""` and normalise only `\r\n` (fixes the latent H8
  asymmetry). For H7, route traces to an unambiguous channel (e.g. a `SWF_TRACE_FILE` sink in the runtime) so the
  harness can record a `ruffle_strict` field next to the verdict. Then one CI run prices the 414 blank-line rows exactly,
  without changing a verdict.
- **H10, H11, H12, H13: no change.**

---

## 3. Ignore-list re-test (33 IGN rows from `wave0-trace-inventory.txt`, clean `origin/master`, graphics, sequential)

**Result: 33/33 still fail, and every row is byte-stable in line stats against the 10-03 inventory** (same
match/expected/actual for all 33, including the `UPM` rows `avm1/global_*_decls`, `avm1/globals_swf5` and gnash
`argstest-v6..8`, whose upstream modifications didn't change their expected line counts). **No prunes proposed.**
Ignore files were not edited.

Hygiene findings (no prunes):
- `avm2/sandbox_type_remote` and `avm2/netstream_play_flv` are ignored through the **root** AVM1 list (H14 above).
  `netstream_play_flv` is double-listed (root `:268` and `avm2/ignored_tests.txt:103`).
- `avm2/date` (pass) is hidden from filtered totals by the root `date` entry (`:228`), as in H14.

---

## 4. Wave-2 slots I'd fund

1. **`w2-goto-scrollrect` (GO, +6, cheap):** land `w1-drift-avm2-prototype.patch` as is (both mechanisms,
   `avm2_display.c` only). Before/after on the 6 headliners plus the 45 + 20 sweep lists. Add the swf9 Flash-vs-Ruffle
   entry (§1.1 edit 2) to `RUFFLE_VS_FLASH_DIFFERENCES.md`. CI: `graphics`, `categories=full`. Regression-suite fixture:
   the corpus rows are Flash-oracled, so no new fixture is strictly needed. If one is wanted, a scrollRect-pick +
   `gotoAndStop(9999)` SWF needs a Flash/Ruffle oracle (see LOCAL ORACLE REQUESTS).
2. **`w2-collator` (GO, +3):** `Collator` + `CollatorMode` + `LocaleID` + `LastOperationStatus` per §1.3, in
   `avm2_globals.c`. Self-contained, with zero collateral.
3. **`w2-html-img` (GO, +1 AVM2 ruffle_matched, plus the AVM1 rows the sibling prices):** port `8cbada89a` into both
   HTML parsers (`avm2_text.c` and `action.c`) in one slot.
4. **`w2-textline-metrics` (GO-maybe, +1):** DefineFont4 typo-metric reader + TextLine ascent/descent (§1.5). Fund only if
   a text slot already has capacity.
5. **`w2-harness-ignore-scope` (small, +1 filtered):** P-H14. The coordinator can do it locally; it needs no runtime build.

Not funded: `device_font_name_case` (HOLD, AVM1 device-font slot), `textblock_recreateline` (0 effective),
full-pass `html_text_img_parsing` (needs img loads).

---

## 5. New unclaimed leads

- **`textblock_recreateline` full pass:** Flash resets DisplayObject state on `recreateTextLine` (69 lines). It
  would beat Ruffle (KF). 0 effective, +1 raw pass.
- **AVM2 device-font name matching:** the AVM2 `[fonts.*]` lookup should follow the same Flash rules as §1.6
  (case-insensitive, exact, no trim for single names). Not exercised by any AVM2 corpus row I found; unverified.
- **H8 latent asymmetry** (universal-newline read of `output.txt`) will misgrade any future Flash output with a lone `\r`.
- **`from_gnash/misc-swfc.all/sound` (IGN, ACC):** 7/7 expected lines all match, plus 5 extra actual lines. If the
  extras are a known Flash-silent warning, a `log_warnings`-style filter might flip it. I did not check this against
  `ACCEPTED_DIFFS.md`'s rationale.

## LOCAL ORACLE REQUESTS

1. *(optional, for a `regression/` fixture only)* A Ruffle exporter trace of `avm2/goto_queued_invalid/swf10/test.swf`,
   8 ticks, with `timeline_debug`, to confirm the "hit target" rule on a non-frame-script `gotoAndStop(9999)`.
   Not blocking: the corpus rows are Flash-oracled and pass with the prototype.

---

## 6. Evidence appendix

- Headline runs (master): all 13 rows above `MISMATCH`, except `textblock_recreateline` `RUFFLE_MATCHED`. The three
  Collator rows have stderr `AVM2 uncaught error: ReferenceError: Error #1065: Variable Collator is not defined.`
- Prototype runs: `goto_queued_invalid/swf9|10|11` PASS; `mouse_pick_scroll_rect{,_button,_loader}` PASS.
  Intermediate measurements: edit 1 alone gives swf9 PASS / swf10 + swf11 MISMATCH. Edit 2 without the SWF≤9 arm gives swf9
  RUFFLE_MATCHED (a regression, rejected).
- Goto sweep (45, all unchanged): `doabc_and_symbolclass_script_init_goto goto_button_nested_framescript
  goto_framescript_queued/{swf9,swf10,swf13} goto_framescript_queued_same_frame goto_in_constructframe
  goto_in_scene_last_frame goto_methods goto_methods_swfver10 goto_nested_construct_sibling goto_nested_framescript
  goto_on_orphan instantiation_on_enterframe_gotoandstop movieclip_addframescript movieclip_addframescript_error
  movieclip_currentscene movieclip_displayevents_{clickgoto,clickgoto2,constructframegoto,enterframegoto,exitframegoto}
  movieclip_goto_during_frame_script movieclip_goto_overwrite movieclip_goto_scene_last_frame_{int,label}
  movieclip_gotoandplay movieclip_gotoandstop movieclip_gotoandstop_children movieclip_gotoandstop_framescripts{1,2,_self}
  movieclip_gotoandstop_queueing movieclip_next_scene movieclip_prev_scene movieclip_queued_noop_goto_{swf9,swf10}
  movieclip_scenes scene_constr swf_10_queued_goto_scripts_construct swf_9_goto_in_construct_frame
  swf_9_goto_in_enter_frame swf_9_goto_in_enter_frame_simple swf_9_queued_goto_scripts swf_9_queued_goto_scripts_construct`.
- scrollRect sweep (20, all unchanged pass): `stage3d_texture_bytearray pixelbender_effect_smudge stage3d_bitmap
  pixelbender_images pixelbender_effect_twirl edittext_autosize_lazy_bounds_props pixelbender_effect_glassDisplace
  bitmap_subclass_properties stage3d_texture graphics_bitmap_fill displayobject_scrollrect bitmapdata_copychannel
  stage3d_raytrace pixelbender_effect_tintype stage_properties2 pixelbender_effect_glassDisplace_shaderfilter
  bitmap_subclass stage_overriden_setters pixelbender_effect_BlurredFocus stage3d_errors_atf`.
- Approximation rows re-graded with the Ruffle-faithful comparator: 47 rows. 46 PASS both ways. `from_shumway/esc`
  FAIL both ways (2 vs 13 lines).
