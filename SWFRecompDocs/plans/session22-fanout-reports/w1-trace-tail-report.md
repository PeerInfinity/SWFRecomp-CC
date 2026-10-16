# w1-trace-tail: the unclaimed trace tail (session 22, wave 1)

**New files (all under `session22-fanout-reports/`):**
- this report
- `w1-trace-tail-prototype-1-strbuf.patch`: `bug_483783`, append-in-place strings
- `w1-trace-tail-prototype-2-gotosweep-construct.patch`: `action_execution_order_test6`
- `w1-trace-tail-prototype-3-regexp-u16-captures.patch`: `pcre_find_fixedlength`

All three patches `git apply --check` clean on `origin/master` (`be8f4b62`).
The source tree was reverted after each measurement.

**Setup.** Cloud box. `SETUP_STATUS` shows apt, Pillow and Dawn all OK. Upstream corpus and `/root/ruffle`
are both at **`45366370e`**, the same as the coordinator. Every row was run one at a time with
`--mode=graphics --verbose` and `SWFRECOMP_COMPILE_TIMEOUT=2400`. Every row reproduces the board's
match/expected/actual counts.

"Ours-only" means line indices where we differ from the graded file and Ruffle does not. It is
computed with `verify_output.py`'s own `_diff_indices`, the promotion rule.

## 0. Verdicts and priced flips, ranked by cheapest flip

| # | row | verdict | flip | cost | ours-only / our diff | what decides it |
|---|---|---|---|---|---|---|
| 1 | `from_gnash/misc-ming.all/action_order/action_execution_order_test6` (KF) | **GO: prototyped** | **+1 → `ruffle_matched`** | **XS: 1 condition** | 3 → **0** | The goto sweep dropped `onClipEvent(construct)` for clips placed and removed inside that same sweep (§1). 63 canaries unchanged. Both modes. |
| 2 | `from_avmplus/regress/bug_483783` (the `runtime_error`) | **GO: prototyped** | **+1 → `pass`** | **S** (~45 lines, 3 files) | crash → PASS, run time 1.3 s | Append-in-place string buffers (avmplus `String::append`). **No GC change is needed** (§2). |
| 3 | `from_avmplus/recursion/pcre_find_fixedlength` (KF) | **GO: prototyped** | **+1 → `pass`** | **S/M** (vendored libregexp: u16 capture indices) | 1 → **0** | "Documented ceiling, not fixable" is refuted. The 255 limit is an operand width in the bytecode (§3). 40 regex canaries unchanged. |
| 4 | `avm2/external_interface` | **GO** | +1 → `pass` | M | 102 / 105 | The expected output is Ruffle's **test-harness provider** (`tests/tests/external_interface/`). The AVM1 twin already passes through a git-tracked `test_harness.c`, and AVM2 needs the same thing (§4). |
| 5 | `fonts/embed_name_lookup` | **GO (M, rules fully derived)** | +1 → `pass` | M (recompiler + runtime) | 156 / 242 | Two mechanisms: the font-name registry, and "embedded font missing → width 0". The full rule table is derived from the fixture (§5). |
| 6 | `audio/aac`, `audio/g711` | **GO-L (one mechanism, two rows)** | +2 → `pass` | M/L | 21, 6: every diff is `computeSpectrum is not a function` | `SoundMixer.computeSpectrum` is absent, and there is no NetStream audio tap (§6). |
| 7 | `from_gnash/misc-swfc.all/movieclip_destruction_test3` / `_test4` (KF) | **HOLD (probe first)** | +2 → rm if it is one mechanism | M? | 9 / 26 | The s20 "B5 deferred removeMovieClip" premise is incomplete. Our first defect is earlier: the attached chain's frame-8 scripts land **after** the root frame-9 check (§7). |
| 8 | `action_execution_order_test11` | NO-GO (≥2 mechanisms, exact pass needed) | 0 | M/L | 6 / 32 | Child `onLoad` timing during the parent's advance, plus nested DoAction order (§8) |
| 9 | `action_execution_order_extend_test` (KF) | NO-GO | 0 | L | 15 ours-only | ≥3 mechanisms: user `onLoad` never called, user `onUnload` missing, enterFrame order (§8) |
| 10 | `ActionOrderTest3/4/5` (KF) | NO-GO | 0 | L | 58 / 54 / 37 | A nested registerClass sprite's loop re-creation (ctor / static unload / dynamic load) drifts every iteration (§8) |
| 11 | `action_order/PlaceAndRemove` (KF, no `.ruffle.txt`) | NO-GO | 0 | L | exact pass only | Ruffle **panics** (`known_failure.panic`). The goto-placed child must never be constructed, and the "Done" count is a frame-count identity (96 vs our 15) (§8) |
| 12 | `MovieClip-v8` (KF) | NO-GO (now itemised) | 0 | L | **27** | Seven independent SWF8 mechanisms, all required (§9) |
| 13 | `avm1/globals_monkeypatch` (KF) | NO-GO (arc) | 0 | L | **205** (was 198) | Upstream made `output.ruffle.txt` better (diff 9 → 2), so our bill went **up** (§10) |
| 14 | `misc-ming.all/GradientFillTest` (KF, no `.ruffle.txt`) | NO-GO | 0 | L+ | exact pass only, 155 lines | Exact Flash gradient readback in every mode (linear, radial, focal, spread). The diffs span many sample families (§10) |
| 15 | `from_shumway/bitmapdata/getpixel-from-embedded` (KF, no `.ruffle.txt`) | NO-GO, **measured** | 0 | — | 1 / 2 | Neither libjpeg fancy upsampling (= ours, `220a06`) nor replicate (`200b06`) gives Flash's `200d04` (§10) |

**Priced wave-2 yield:**
- **+3 proven by prototype** (rows 1-3): all small, and each lives in a different file.
- **+2 priced GO-M** (rows 4-5).
- **+2 at M/L** (row 6).
- Row 7 is a probe.

**Rule-3 check.** All three prototypes move only toward Flash's file:
- Row 1 reaches `ruffle_matched` with 0 ours-only lines.
- Rows 2-3 reach exact `pass`.
- None of the 63 + 40 + 10 canaries moved, so nothing went `pass → ruffle_matched`.
- `pcre_find_fixedlength` is KF, and it moves to `pass`, not to rm.

---

## 1. `action_execution_order_test6`: GO XS (+1 rm, prototyped)

**Measured at HEAD.** 0/24 lines match, 20 actual. Ours differ on 24 lines and Ruffle on 21, leaving
**3 ours-only lines (indices 0, 1, 4)**. We never print `mc1 Construct called` / `mc2 Construct called` in pass 1.

**Mechanism.**
- Frame 1's script is `x1 = ""; gotoAndPlay(frame 8)`. That goto **sweeps** frames 2-7.
- During the sweep, mc1 and mc2 are placed with `onClipEvent(construct/load/unload)` (frame 2) and removed (frame 4). mc3 is placed (frame 5) and removed (frame 7).
- Flash's pass 1 is `C1, C2, C3, L1, L2, U1, U2, L3, U3`. Its `x1` reads `1+2+3+4+5+6+7+8+9+`.
- We already fire the swept Load and Unload events in exactly Flash's order. We drop **only** the
  CONSTRUCT entries:
  - Instrumentation shows `queue_clip_construct_events` queues all three (`tag.c:9461`).
  - `aq_drain` then skips them, because their entries are `queued_in_catchup` and the clip is `avm1_removed`
    (`SWFModernRuntime/src/actionmodern/action_queue.c:166-176`).
  - The comment there says the skip exists so "place+remove in same goto sweep remains canceled". This fixture is Flash's
    proof that it must not cancel `construct`.
- Instrumented counters also ruled out a suppress-depth leak: `actionDrainSuppressEnter`/`Leave` balance.

**Prototype** (`-2-gotosweep-construct.patch`) makes `AQ_KIND_CLIP_CONSTRUCT` always fire
chronologically. One condition.

**Result: graphics `RUFFLE_MATCHED`, no-graphics `RUFFLE_MATCHED`** (mode parity holds: the file is
shared).
- Pass 1 is now byte-exact Flash.
- Pass 2 now also gains Flash's missing `mc3 Construct called`.
- The remaining 5 diff lines are mechanism (b) below. All of them are inside Ruffle's diff set.

**Canaries: 63 rows, statuses unchanged against `results_graphics`.**
- All 17 `action_order/*` rows.
- `displaylist_depths_test*` ×11.
- `DepthLimitsTest`, `consecutive_goto_frame_test`, `goto_frame_test`, `gotoFrame2Test`, `multi_doactions_and_goto_frame_test`, `unload_movieclip_test1`, `duplicate_movie_clip_test{,2}`.
- `misc-swfc` `gotoFrameFromInterval2`, `gotoFrameLabelAsFunction`, `movieclip_destruction_test1..4`.
- 21 avm1 `goto_*` / `clip_event*` / `on_construct` / `movieclip_onconstruct` / `button_goto` / `unload_clip_event` rows.
- Raw outputs of the other 7 failing action_order / destruction rows are **byte-identical**.

**Exact-pass remainder (not needed for the flip): mechanism (b).** Flash pass 2 runs
`L1, A1, L2, A2`: each clip's `onLoad`, then that clip's frame-1 DoAction. We run `L1, L2, A1, A2`.

**CI.** `action_queue.c` is shared runtime. Run `mode=graphics` with the default `categories=all`. Run a
`no-graphics` leg too, because it is the shared queue.

## 2. `bug_483783`: GO S (+1 pass, prototyped). The s16/s21 NO-GO is refuted

**Measured.** `RUNTIME_ERROR: heap_alloc(76392) failed - out of memory`. The test is
`for (j < 3000000) myString += "a"`.

**Mechanism.**
- `avm2_string_concat` (`SWFModernRuntime/src/avm2/avm2_value.c:142`) copies `a` into a fresh block on every `+=`.
- That makes the loop O(n²) bytes. The 4 GB arena is exhausted at about 76 k characters, because 76k²/2 ≈ 2.9 GB.
- The AVM2 GC only collects between ticks (`avm2_gc.c` header), and the loop runs in one script-init.

**The standing verdict was "needs dependent strings + a GC single-block-free change".**
- The **GC half is unnecessary.** Even with a perfect mid-method collector, O(n²) copying is 4.5 TB of `memcpy`.
- With append-in-place, the whole run needs ~6 MB of buffer (doubling) plus 3 M headers ≈ 150 MB. It fits with no collection at all.

**Prototype** (`-1-strbuf.patch`, 3 files):
- `Avm2String` gains a trailing `cap` field and two flags:
  - `AVM2_STR_GC_BUF`: an append buffer, never user-visible, whose `len` is the frontier.
  - `AVM2_STR_GC_DEP`: a header whose bytes live in a BUF.
- When the result is ≥ 4096 bytes, `avm2_string_concat` appends `b` in place if `a` is a DEP header that ends at its buffer's frontier and the buffer has room. Otherwise it allocates a new buffer with 2× capacity.
- It always returns a fresh DEP header, so earlier values never change length.
- `avm2_gc_mark_string` marks a DEP header **and** its owning BUF (`((Avm2String*)s->utf8) - 1`). By-value copies already reach the BUF through the existing range lookup.

**Result:** `PASS`, run time 1.27 s.

**The one real risk, which wave 2 must own.** Older prefix headers lose their `utf8[len] == '\0'`
invariant. The next append overwrites that byte.
- Reads never go out of bounds: the buffer is always NUL-terminated at its frontier.
- But a C-string consumer (`strcmp`/`strtod`/`%s` on `->utf8`; 27 direct sites in `src/avm2`, more indirect ones) would see the **longer** string.
- The 4096-byte threshold confines this to long strings.
- I instrumented the buffer path. It is hit by **only `bug_483783`** among the 10 string canaries I ran: `regress/bug_703238` and ecma3 `String/e15_5_4_{12_4,11_4,5_5,7_1,11_6}`, `e15_5_3_2_3`, `toLocaleUpperCase3` and `concat`. All of them still pass.

**Wave-2 scope:**
- Either audit the C-string consumers, or add a `avm2_string_cstr()` that copies when `utf8[len] != 0`.
- Run a hit census in CI (a counter behind an env var) over `categories=full` before landing.
- Optionally move `cap` into the BUF's inline bytes, so the header does not grow by 8 bytes per string.

## 3. `pcre_find_fixedlength`: GO S/M (+1 pass, prototyped). "Ceiling, not fixable" is refuted

**Measured.**
- 19/20 lines. Ruffle differs on 7 lines; **ours-only is 1 line, index 4**.
- On that line, `(?<=((((…500…(blah)…))))hello`.match() must return `hello` plus 500 captures of `blah`. We return `hello`.

**Mechanism.**
- libregexp's capture indices are **u8 operands**: `save_start/save_end` take 1 byte, `save_reset` takes 2, and the header capture count is 1 byte. `CAPTURE_COUNT_MAX` is 255.
- Our wrapper demotes plain `(` to `(?:` above 255 groups so that the pattern still compiles (`avm2_regexp.c:565`). That drops every group.
- The arc doc called this "a documented ceiling: libregexp stores capture indices as bytes". That is an encoding width, not a ceiling.

**Prototype** (`-3-regexp-u16-captures.patch`):
- u16 operands for `save_start`/`save_end`/`save_reset` (opcode sizes 3/3/5).
- A 10-byte header with a u16 capture count.
- Every reader and emitter updated, including the 2 top-level `save_*` 0 emitters and the 2 `save_reset` insertion sites.
- `CAPTURE_COUNT_MAX` raised to 1024. Back-references keep u8 indices and raise a parse error above 255.
- The wrapper's `RE_MAX_CAPTURES` raised to 1024. The demote threshold follows it.
- Validated first with a standalone harness (5 patterns, including the 501-group lookbehind).

**Result:** `PASS`. Lines 3 and 5, Flash's own FAILED lines, are now byte-exact.

**Canaries:** 40 regex-using rows, all unchanged against `results_graphics`:
- all `from_avmplus/recursion/*`
- `as3/RegExp/*`
- avmplus String `match`/`replace`/`search`/`split` users
- `avm2/regexp_*`

**Wave-2 fixes owed** before landing:
1. The named-group back-reference path clamps a >255 index to 255 (`dbuf_putc(capture_index > 255 ? 255 : …)`). It must be a parse error instead.
2. **A latent bug that exists today:** `re_find`'s `capture[RE_MAX_CAPTURES*2]` (`avm2_regexp.c:695`) is not sized for libregexp's *registers*. `lre_get_alloc_count` = 2·captures + registers. A ~250-group pattern with counted quantifiers writes past the stack array. The prototype sizes it `*2 + 256`.

**CI:** this is AVM2 runtime, so `categories=full`.

## 4. `avm2/external_interface`: GO M (+1 pass)

The fixture has **no `test.toml`**. Upstream runs it from `tests/tests/external_interface/tests.rs::external_interface_avm2` with `ExternalInterfaceTestProvider` (`mod.rs`):
- `ping` → `"Pong!"`
- `trace` → `"Traced!"`
- `reentry` calls back into `callWith`.
- After the first preloaded tick, the harness injects 5 host calls (`parrot` ×2, `freestanding`, `removeMe`, `callWith`) and traces their Rust `Debug` form.

We emit only the "not available" path: 7 lines against 105.

**Precedent:**
- `avm1/external_interface` passes through a **git-tracked `test_harness.c`** (408 lines) that emulates the same provider.
- `verify_output.py:2873/3325` already compiles any `test_harness.c` it finds.

**Scope:**
- `ruffle-tests/tests/swfs/avm2/external_interface/test_harness.c`: provider plus host injection.
- A provider hook in `avm2_external.c`:
  - make `available` true under the harness
  - route `call()` to the provider
  - expose a host→AS3 dispatcher that takes structured values (Object/List/Number/Bool/Null) instead of today's string-first `avm2_ei_dispatch`
- A `Debug` formatter. The AVM1 harness's `ev_format` is the template.

There is no rule-3 exposure: the row is not KF.

## 5. `fonts/embed_name_lookup`: GO M (+1 pass), the rules are derived from the fixture

**Fixture.** I wrote a 60-line Python SWF tag walker (scratchpad only, not committed) to list every font tag. Each name AA..CZ is probed three ways, normal / lowercase / bold, through `embedFonts` + `textWidth`.
- Font 23 renders at **40** and font 24 at **17** (TestFont vs TestFont2).
- **0** = no usable font. Note that a DefineFont v1 has no advances, so even when found it gives 0.

**Derived Flash rules** (every one of the 78 names fits):
1. A **DefineFont2/3's own name** registers it: AB, AC, AE, AF, AM, AO, BD, BG… = 40.
2. **DefineFontName does NOT register**: AD, AG, AQ, AS, AZ = 0.
3. **DefineFontInfo / DefineFontInfo2 add a name** to an already-defined font: AN, AP, AT, AV, AX, BA, BE, BF, BH, BI = 40. The font's own name keeps working.
4. A FontInfo or Export for a character id **not yet defined is ignored**: BS–BX = 0, CO → 27 = 40, CS → 31 = 40.
5. Among FontInfo names, the **first registration wins**: CC, CE, CG = 40 (23 first). CD, CF, CH = 17 (24 first). CM = 40 (DefineFont2 25 before info 26).
6. An **ExportAssets name wins over every other kind of name**:
   - CI and CJ: info 23 first, then export 24 → 17.
   - CQ: DefineFont2 29 'CQ', then export of 30 as 'CQ' → 17.
   - CV: export of 36 beats font 35's own name → 17, for bold as well.
7. An **export of a non-font hides the name**: CU (export of DefineShape 34 as 'CU') → 0.
8. **Bold matching uses the DefineFont2 flag, not the DefineFontInfo flags**:
   - CX: info 35 (bold=0), info 36 (bold=1). Normal → 17 (font 36, whose DefineFont2 is not bold); bold → 40 (font 35, whose DefineFont2 is bold).
   - CY is the same.
9. **Embedded font not found → `textWidth` 0**. Today we fall back to the device font, which gives 22 (63 lines `0 → 22`).
10. Lookup is case-insensitive: `aa` == `AA`, which we already do (`ng_shared.c:677`).

**Current state.**
- The recompiler emits a single `tagDefineFontInfo(id, name)` per font: 29 calls for 38 fonts. It drops DefineFont2/3 names, the second and later FontInfo names, and ExportAssets names.
- The runtime registry is one name per font (`ng_findFontIdByName`, `ng_shared.c:674`).

**Scope:**
- The recompiler emits every name event, in tag order, with its kind.
- The runtime keeps a two-tier map (export-name map checked first, then a first-wins name map keyed on name+bold), plus rule 9.

**Risk:** rule 9 changes `embedFonts` fields that name a missing font, so games are affected. Canary the `fonts/*`, `text/*` and avm1 `edittext_*` rows, plus the image canary list.

## 6. `audio/aac`, `audio/g711`: GO-L (+2, one mechanism)

Every diff line is `TypeError: Error #1006: computeSpectrum is not a function`. `computeSpectrum` does not exist anywhere in `src/`.

What the fixture actually checks:
- It is **phase-agnostic**. It fits a 444 Hz phasor to the 256-sample window and requires the reconstruction to match within 0.05.
- It also requires the amplitude to be `1/8 × 5` (with −3 dB for stereo), after doubling for Flash's "every second sample" stretch.

So the timing of the window does not matter. The mixed sample *values* and *volume* do.

**Scope:**
- `SoundMixer.computeSpectrum(ba, false)`: 512 floats, L then R, every second sample of the last 1024 mixed at 44.1 kHz.
- A headless mixer tap over NetStream FLV audio:
  - G.711 A-law/µ-law: a table decode.
  - AAC: libavcodec, which `video_codec.c` already links. The WASM build is not graded.

This shares `computeSpectrum` with the ignored `avm2/audio_computespectrum`.

The s18 "needs a real FFT" reason stays refuted (FFTMode is not used).

## 7. `movieclip_destruction_test3/4`: HOLD (probe before funding)

**The s20 premise is incomplete.** The verdict of record is "B5: defer `removeMovieClip` to end of the calling frame
script". In our run:
- `_root.as_order` is `0+` at the root frame-9 check, where Flash has `0+1+2+`.
- The `nestedMovieClip removed at frame …` and `actions here should not be executed` notes **never print**.
- Yet `mcARef.getDepth() == -32779` **passes** two frames later, so the removal did happen.
- The attachMovie'd 8-frame chain (`mc1` → `mc11` → `mc111` → `mc1111`, scripts dispatched through `sprite_frame_scripts_data`) runs its frame-8 scripts later than the root's frame-9 script, and their `note()` output is lost.

Ruffle passes those lines: diffs 4 and 6 against ours 13 and 32.

**Probe for wave 2:** trace the attach-time first frame (Ruffle runs an attached clip's frame 1 at attach), then the order of children vs root in the tick. If that is the whole story, the existing deferred-unload depth (−32769−depth, which we already produce) may be enough. In that case it is **+2 rm for M**. Otherwise B5 is still owed on top.

## 8. The `action_order` family (STRUCK s17): what is still true

- **The strike holds** for `test11` (pass needed; 3 diff blocks):
  - (i) `mc21 onLoad` must fire inside mc2's advance, before `mc1 onEnterFrame`.
  - (ii) nested DoAction order (`0+2+1` vs `0+1+2`).
  - (iii) `asOrder`, which interleaves both.
- **The strike holds** for `extend_test`. It has 15 ours-only lines in at least 3 groups:
  - the user-assigned `mc_red.onLoad` is never called (`y1` obtained `''`)
  - the user `onUnload` lines are missing
  - root frame-3 timing
- **The strike holds** for `ActionOrderTest3/4/5`: we emit extra `onEnterFrame` lines and `ctor: 1` lands about 8 lines late. The nested registerClass sprite's loop re-instantiation drifts.
- **The strike holds** for `PlaceAndRemove`. Ruffle panics on it (`known_failure.panic = "Gotos must start from the correct tag position for frame 1"`). Only an exact pass counts, and the expected output is 96× `Done` against our 15 (`Done` / `moo N` / `FAILED` per tick).
- **`test6` is the exception:** see §1.

## 9. `MovieClip-v8`: the 27 ours-only lines, itemised

| lines | mechanism |
|---|---|
| 485-486 | `getBounds().xMax` 102 vs 101 (`MovieClip.as:970/982`) |
| 544-560 (10) | `filters`: the setter must drop non-BitmapFilter entries (`[1,3,4,5]` → length 0, `"boh!"` dropped). The getter returns fresh clones (`tmp1[0] !== tmp2[0]`) |
| 744-745 | `draw._width/_height` 30/40 vs 20/30 (`:1668`): stroke included in a drawing's bounds |
| 810 | `transform` property enumeration order |
| 825-845 (8) | `pixelBounds` y/h, ours `y=68,h=804` vs Flash `y=25,h=847`. These are FAILED lines in Flash too, so the *obtained* text must match |
| 846-847 | `_root.transform.toString()` and `.matrix.toString()` must be `undefined` |
| 988 | `blendMode` read-back must give `darken`, not `normal` (`:2392`) |

There are 7 independent mechanisms and all of them are required. NO-GO for one slot. The
filters block (10 lines) is the largest and also the cleanest single sub-slot, but it flips nothing alone.

## 10. Re-verified NO-GOs, with fresh evidence

- **`globals_monkeypatch`.**
  - Upstream changed only `output.ruffle.txt`; expected is still 246 lines.
  - Ruffle now differs on just 2 lines, so our ours-only count **rose** from 198 to 205.
  - The families: object-literal / `new Object` prototypes through `_global.Object`, and native results built through `_global.flash.geom.*` lookups (`geom getter called!` ×20, `flash getter called!` ×20, `Point getter called!` ×11), plus about 10 classes.
  - It is drift-flagged `UPM` (ruffle.txt only), so it is not a status drift.
- **`GradientFillTest`.** Readback hex differs in every gradient family: linear (`0xb0bff` vs `0xd0dff`), radial/focal, pad/reflect/repeat. With KF and no `.ruffle.txt`, only an exact pass counts.
- **`getpixel-from-embedded`.**
  - I extracted the JPEG (DefineBits/JPEG2, 140×140, 4:2:0, gd-jpeg/IJG q90).
  - Pillow (libjpeg-turbo, ISLOW, fancy upsampling) gives `220a06` at (100,100), which is **exactly ours**.
  - ffmpeg planes with replicate upsampling give `200b06`. Flash is `200d04`.
  - No standard decoder configuration reproduces Flash, so this stays a disposition: add it to `from_shumway/_investigation` ACCEPTED, platform JPEG decoder.
  - Side note: our `_test_is_known_failure` treats `known_failure.ruffle_check = false` (a table) as truthy. Harmless here, because there is no `.ruffle.txt`.

## 11. Wave-2 slots I would fund

| slot | files | rows (expected flips) | cost | CI |
|---|---|---|---|---|
| **A: queue + regex** | `action_queue.c`; `third_party/quickjs-libregexp/*` + `avm2_regexp.c` | `action_execution_order_test6` (rm), `pcre_find_fixedlength` (pass) = **+2** | XS + S | graphics `full`, plus a no-graphics leg (the queue is shared) |
| **B: string append buffers** | `avm2_value.c`, `avm2_gc.c`, `avm2_value.h` | `bug_483783` (pass) = **+1** | S, plus the NUL-invariant audit and hit census | graphics `full` |
| **C: AVM2 EI test provider** | new `avm2/external_interface/test_harness.c`, `avm2_external.c` | `avm2/external_interface` (pass) = **+1** | M | graphics `full` |
| **D: font name registry** | recompiler font-tag emission, `ng_shared.c`, text layout fallback | `fonts/embed_name_lookup` (pass) = **+1** | M | graphics `all`, plus the `fonts`/`text` misc group and the image canary |
| E (optional): computeSpectrum + NetStream audio tap | `avm2_media.c`, `video_codec.c` | `audio/aac`, `audio/g711` = **+2** | M/L | graphics `full` with the misc group |
| F (probe only): attached-chain frame timing | `tag.c` / attach path | `movieclip_destruction_test3/4` = +2 if one mechanism | probe S, then M | graphics `all` |

A + B + C + D = **+5**, of which **+3 are already proven by prototype**.

## 12. New unclaimed leads

1. **`test6` exact pass**: Flash runs per-clip `onLoad`, then that clip's frame-1 DoAction (`L1, A1, L2, A2`). We batch the loads first. That is a corpus-wide ordering rule, so check `action_order` `test11` with it.
2. **`re_find` capture array under-sized for registers** (`avm2_regexp.c:695`). Latent stack overflow on large-group patterns with counted quantifiers, present on master today.
3. **`_test_is_known_failure` treats `known_failure.ruffle_check = false` / `known_failure.panic = "…"` tables as KF.** That is correct for `panic`. For `ruffle_check = false` the intent is "don't verify Ruffle fails", so check that it does not mask a gradeable `pass`.
4. **Embedded font missing → device fallback** (§5 rule 9) is wrong against Flash for every `embedFonts=true` field naming an absent font. That has game-visible rendering consequences beyond this row.
5. **The goto-sweep skip filter** (`action_queue.c:166`) still cancels `CLIP_INIT` and `REGISTER_CTOR` for swept place+remove. No corpus row tests that against Flash. The `test6` evidence suggests Flash fires all of the placement-time events.

## LOCAL ORACLE REQUESTS

None. Every row here grades against Flash's own `output.txt` or the upstream harness source, and nothing needed a fresh Ruffle run.
