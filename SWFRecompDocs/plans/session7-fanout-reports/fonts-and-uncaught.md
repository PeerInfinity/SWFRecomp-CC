# Fonts scoping + uncaught-error re-land re-measurement

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-ac64f04cc32d4e748`
Base commit: `46dcf3a06` (docs: polish session 6 closeout — 4129/4422).
Nothing committed, nothing pushed. Local experimental state only.

---

# TASK A — "name-only font characters" (DefineFont4 / glyph-less DefineFont3)

## A.0 Headline: the premise does not survive the census

The feature-priority map records this as "DefineFont4 and glyph-less
DefineFont3 tags never reach `avm2_generated_fonts`, blocking 2-3 font
tests." Measured against the corpus, both halves are wrong:

1. **Glyph-less `DefineFont3` DOES already reach `avm2_generated_fonts`.**
   `SWFRecomp/src/abc/abc_timeline.cpp:1379` handles `TAG_DEFINE_FONT2` /
   `TAG_DEFINE_FONT3` and is explicitly written for the zero-glyph case
   ("A 0-glyph device font omits the remaining tables (Ruffle read.rs)",
   line 1401). It pushes a `FontDef` carrying `font_id`, `name`, `bold`,
   `italic`, `has_layout`, `em_square` and an empty glyph/code table. The
   AVM1 side (`SWFRecomp/src/swf.cpp:2352`) goes further and *synthesises*
   ASCII 32..126 from NotoSans for such a font, but that is a rendering
   nicety, not a metadata gap.

2. **`DefineFont4` (tag 91) is parsed by NEITHER recompiler.** There is no
   `SWF_TAG_DEFINE_FONT_4 = 91` constant in `SWFRecomp/include/tag.hpp` at
   all, no case in `swf.cpp`, and no case in `abc_timeline.cpp`. So the
   JPEG precedent ("check `swf.cpp` first, the AVM1 scanner already solved
   it") explicitly **does not repeat here** — this is the one font tag the
   older scanner never learned either.

3. **DefineFont4 blocks nothing that is currently failing.** I parsed the
   tag stream of every `*.swf` under every test directory in the corpus
   (4021 tests, script kept at
   `…/scratchpad/census.py` / `census_all.py`) and cross-joined against
   `_results/results_graphics.json`:

   | tests containing a `DefineFont4` | status |
   |---|---|
   | `avm2/font_enumeratefonts` | **pass** |
   | `avm2/textline_splitting_basic` | **pass** |
   | `avm2/textline_validity` | **pass** |
   | `visual/definefont4` | **pass** (0-byte expected; image-graded) |

   Four tests in the whole corpus, all four already passing.
   Glyph-less `DefineFont2/3` appears in 8 failing tests, and in every one
   of them it is a **device font declaration** (`_sans` ×6,
   `Times New Roman` ×1) that `abc_timeline.cpp` already records; those
   tests fail on focus events / device-font metrics, not on the font
   character existing.

**Conclusion: implementing DefineFont4 parsing is worth +0 corpus today.**
It is a prerequisite for `visual/definefont4`'s *image*, not for any trace.

## A.1 What the three "font tests" actually need

`results_graphics.json` (baseline `46dcf3a06`) — every non-passing test with
`font` in its name:

| suite | test | status | lines | signature |
|---|---|---|---|---|
| avm2 | `font_enumeratefonts_order` | output_mismatch | 0/9 | `ArgumentError #1508` |
| avm2 | `font_registerfont` | output_mismatch | 8/129 | — |
| avm2 | `edittext_getcharboundaries_missing_embedded_font` | ruffle_matched | 4/7 | — |
| fonts | `device_font_glyph_fallback` | output_mismatch | 29/36 | — |
| fonts | `device_font_kerning` | output_mismatch | 0/4 | — |
| fonts | `device_font_list` | output_mismatch | 6/48 | — |
| visual | `definefont4` | pass (0-byte) | 0/0 | `TypeError #1009 … getEffectiveLineHeight` |

`avm2/font_enumeratefonts` — named in the worklist as *the* DefineFont4
blocker — **passes today** (41/41). It was recovered by `3dd78effc`, the
runtime work-around in `avm2_text.c:7889-7901` that accepts a symbol-bound
class naming a non-placeable character. Its expected output also wants
`fonts.length == 1` (the DefineFont3 only), i.e. the DefineFont4 must
**not** be enumerated — matching Ruffle's filter.

### The real blocker for both remaining font tests: CHILD-MOVIE font tables

Tag dumps (`…/scratchpad/tags.py`):

- `avm2/font_enumeratefonts_order/test.swf` — six `DefineFont3`, **55 bytes,
  `nglyphs=1`, `flags=0x84` (HasLayout|WideCodes)**. Not glyph-less, not
  CFF; they are parsed correctly today. `font.swf` (the child) carries a
  seventh, `TestFont4`, also a normal DefineFont3.
  `Test.as` does `Font.registerFont(getDefinition("FontSwf_TestFont4"))`
  **on a class from the loaded child SWF**.
- `avm2/font_registerfont/test.swf` — **no font tags at all**; the only font
  (`Noto Sans`, DefineFont3, 193 glyphs) lives in the child `font.swf`.
  `Test.as` and `FontMain.as` both call `Font.enumerateFonts()`, and the
  expected output distinguishes the two callers: `[test.swf]` sees 0 fonts
  before the load and 1 after (the globally registered one), `[fonts.swf]`
  sees 1 (its own embedded) then 2.

Both are therefore the same gap, and it is **not** a name-only-font gap:

* `SWFModernRuntime/src/avm2/avm2_text.c:2241` `font_by_id()` loops
  **only** `avm2_generated_fonts` (the main movie). A class defined in a
  loaded child SWF resolves to a char id via
  `avm2_display_char_for_class()`, `font_by_id()` misses, and
  `font_register_font()` falls through to `#1508` — the exact signature
  `font_enumeratefonts_order` reports, thrown before its first `trace`,
  which is why it scores 0/9.
* `avm2_text.c:7835` `font_enumerate_fonts()` enumerates
  `g_registered_fonts + avm2_generated_fonts` — always the **main** movie,
  never the caller's.

The plumbing is already there: `Avm2MovieTables`
(`SWFModernRuntime/include/avm2/avm2_abc.h:570`) has
`const Avm2FontData* fonts; uint32_t font_count;`, `abc_timeline.cpp:2401`
emits `row("fonts", …)` into every child's table, and child font ids are
shifted by `char_id_base` at emission (`abc_timeline.cpp:1721`), so a bare
id is still a unique key. `avm2_display.c:271` already keeps
`g_child_movies[]`. Nothing in the recompiler needs to change.

## A.2 Fix design

Ruffle is the spec here
(`~/CC/ruffle/core/src/avm2/globals/flash/text/font.rs:93-165`):

```rust
fonts.append(&mut library.global_fonts());                    // registered
if let Some(library) = library_for_movie(caller_movie_or_root()) {
    for font in library.embedded_fonts() {
        if font.has_layout() && font.font_type() == FontType::Embedded { … }
    }
}
fonts.sort_unstable_by(lowercase_name)
```
```rust
// registerFont: class_symbol(class) -> (movie, id); Character::Font in THAT movie
```

### Step 1 (small, ~20 lines, runtime only) — child-movie `font_by_id`

`avm2_display.c`: export the child list that is already there.

```c
uint32_t avm2_display_child_movie_count(void);
const Avm2MovieTables* avm2_display_child_movie(uint32_t i);
```

`avm2_text.c: font_by_id()` — after the main-movie loop, walk the children
the same way `timeline_for_char()` (`avm2_display.c:274`) already does.

**Yield: `avm2/font_enumeratefonts_order` 0/9 → 9/9 (a full pass).**
Verified by hand against the expected order: registered
`[Test Font3, TestFont1, TestFont4(child)]` + root embedded
`[testfont5, TeStfONt6, TestFont7, TestFont2, Test Font3, TestFont1]` = 9
entries, case-insensitively sorted → exactly the 9 expected lines (the
space in `Test Font3` sorts first, `TestFont4` from the child lands between
`TestFont2` and `testfont5`).

### Step 2 (medium, ~60 lines, runtime only) — caller-scoped enumeration

`avm2_display.c`: add
```c
const Avm2MovieTables* avm2_display_movie_for_abc(const Avm2AbcFileData* f);
```
scanning each child's `tables->abc_files[]` for a pointer match; `NULL`
means the main movie. `font_enumerate_fonts()` takes `act->file` (already
threaded — `avm2_function.c` passes `act->file` to
`avm2_coerce_to_type_mn`) and enumerates that movie's `fonts` instead of
the globals. Keep the existing `has_layout` filter — it is Ruffle's
`has_layout() && font_type() == Embedded`, and it is also what keeps a
future DefineFont4 out of the list.

`font_register_font()` should additionally de-duplicate
`g_registered_fonts` by `Avm2FontData*` — `font_registerfont` registers the
same child font twice (two `Loader.load`s of `font.swf`) and expects the
list length to stay at 2.

**Yield: `avm2/font_registerfont` 8/129 → likely a full pass**; it exercises
nothing else. Risk: `font_enumeratefonts` (currently 41/41) and
`edittext_*` tests read the same helper — the main movie's behaviour must
be byte-identical when `movie_for_abc()` returns NULL, which it is by
construction.

### Step 3 (optional, ~50 lines, recompiler) — real DefineFont4 characters

Only worth doing as part of a TLF/CFF push, since it is +0 on its own.

`tag.hpp`: `SWF_TAG_DEFINE_FONT_4 = 91`.
`abc_timeline.cpp`: a case next to `TAG_DEFINE_FONT2/3` reading
`FontID(u16), Flags(u8), FontName(null-terminated STRING), CFFData[]`
(note: unlike DefineFont2/3 the name is **NUL-terminated, not
length-prefixed**; flag bit 0 = HasFontData, bit 1 = Italic, bit 2 = Bold).
Emit a `FontDef` with `has_layout = 0`, `glyph_count = 0`, plus a new
`font_type` byte (`0 = embedded, 1 = embeddedCFF`) on `Avm2FontData`, and
register a `CharInfo` so `avm2_display_char_is_defined()` is true.
Runtime: `font_get_type` (`avm2_text.c:7799`, currently a hard-coded
`"embedded"`) returns `"embeddedCFF"` for those; the
`avm2_text.c:7889-7901` `#1508` work-around can then be deleted in favour
of a real lookup. Actually *rendering* CFF glyphs (what
`visual/definefont4` grades) is a separate, much larger job — the test dies
in TLF at `#1009 … getEffectiveLineHeight` long before glyph rasterisation.

### Recommended order

Step 1 alone is the cheapest +1 in the font area and carries essentially no
risk. Step 2 is the +1 after it. Step 3 should be deferred until someone
picks up TLF; the census says it buys nothing before then.

---

# TASK B — uncaught-error tracing re-land, re-measured

## B.0 Correction to the brief

The brief names `d1c307c51` as "the re-land commit, since reverted". It is
not: `d1c307c51` is the *first* revert (of `3b401b5f9`, 2026-07-26). The
re-land was `1ca0ab117` (2026-07-30) and it was reverted by **`ac2325c6f`**
the same day. `SWFRecompDocs/plans/uncaught-error-worklist.md` §4 says so
explicitly ("Re-landing is this revert's inverse").

So the correct experiment is `git revert -n ac2325c6f`, which is what I
ran. It applied cleanly (one auto-merge hunk, no conflicts), and it is
**runtime-only** — `avm2_error.c` (+17: `print_uncaught` writes the coerced
error plus its `__stacktrace_tail` to stdout) and `avm2_function.c` (+18:
pop the callee frame around `avm2_coerce_to_type_mn` so a `#1034` from a
parameter is attributed to the CALLER). No recompiler change, so the
recompiler rebuild is irrelevant to the measurement (I built it anyway —
this is a fresh worktree).

## B.1 The query, re-run (the doc's own protocol)

`status IN (pass, ruffle_matched) AND error_signature != null` over all
`_results/results_graphics.json` at `46dcf3a06`:

| suite | test | status | expected/actual/matching | signature |
|---|---|---|---|---|
| avm2 | `away3d_advanced_shallow_water_demo` | **pass** | 0/0/0 | `#1065 ContextMenuEvent is not defined` |
| visual | `definefont4` | **pass** | 0/0/0 | `#1009 … (accessing field: getEffectiveLineHeight)` |
| avm2 | `array_access_oob_interpreter` | ruffle_matched | 1/0/0 | `#1081 Property 0 not found on Array` |
| avm2 | `coerce_property` | ruffle_matched | 36/33/33 | `#1034 … to Test.as$38.Second` |
| avm2 | `sprite_dropTarget` | ruffle_matched | 19/19/15 | `#1009` |
| from_avmplus | `as3/RegExp/replace` | ruffle_matched | 7/5/5 | `#1009` |
| from_avmplus | `e4x/XML/bug_564468` | ruffle_matched | 10/6/3 | `#1090 XML parser failure` |
| from_avmplus | `ecma3/JSON/Classes` | ruffle_matched | 6/5/5 | `#1006 toJSON is not a function` |
| from_shumway | `avm1movie` | ruffle_matched | 13/5/5 | `#1009` |

**Unchanged from worklist §7**: exactly two `pass` tests at risk, both with
`expected_lines == 0`, and the same seven `ruffle_matched` ones (which §4.5
established can only keep their status, because Ruffle traces the same line
and its reference output already contains it).

## B.2 The GAIN side has moved too — and the doc never priced it

The worklist only ever re-ran the *risk* query. Running the mirror-image
query — **failing** tests with a non-null `error_signature` whose expected
output contains an uncaught-error-shaped line (`^\w*Error: Error #…` or a
`\tat …` stack tail) — turns up materially more than the doc's "+2"
(script: `…/scratchpad/q3.py`):

| gap (exp−match) | suite | test | status | lines | note |
|---|---|---|---|---|---|
| 1 | avm2 | `verify_illegal_opcode` | output_mismatch | 0/1 | expected output IS the `VerifyError #1011` line, nothing else |
| 2 | avm2 | `uncaught_error_basic` | output_mismatch | 0/2 | doc's known gain |
| 2 | avm2 | `loader_method` | output_mismatch | 83/85 | doc's known gain |
| 2 | from_avmplus | `ecma3/Exceptions/exception_011_rt` | output_mismatch | 1/3 | missing lines are `undefined` + `\tat global$init()` |
| 3 | avm2 | `bitmapdata_zero_size` | output_mismatch | 5/8 | missing tail is `ArgumentError #2015` + 2 stack frames |
| 3 | avm2 | `coerce_property` | ruffle_matched | 33/36 | missing tail is a `#1034` + frames |
| 4 | avm2 | `loader_load` | output_mismatch | 124/128 | 2 of 4 missing lines are the trace |

Everything with a bigger gap (`event_handler_exception` 1/11,
`uncaught_errors_stringified` 1/18, `accessibilityimplementation` 0/18,
`avm1_root` 0/58, `external_interface` 3/105) gains lines but cannot flip.

## B.3 Local measurements

Method: `git revert -n ac2325c6f` in a clean worktree at `46dcf3a06`,
recompiler built by hand (`cmake --build SWFRecomp/build -j4`), then
`python3 ruffle-tests/verify_output.py --tests-dir=… --test=… --diff`,
at most two at a time. Default (NO_GRAPHICS) mode; mode parity is complete
so this is comparable to the `results_graphics.json` baseline.

Machine caveat: another agent was running graphics-mode tests out of the
main checkout throughout (load average 13-16). The first `visual/definefont4`
run reported `compile_fail` — a FALSE result: `abc0_methods.c` (a 400 KB
DoABC) blew the runner's default 300 s per-file gcc timeout. Re-run with
`SWFRECOMP_COMPILE_TIMEOUT=2400`.

| test | baseline (CI, `46dcf3a06`) | with the trace | delta |
|---|---|---|---|
| `avm2/uncaught_error_basic` | output_mismatch 0/2 | **PASS** | **+1** |
| `avm2/loader_method` | output_mismatch 83/85 | **PASS** | **+1** |
| `avm2/away3d_advanced_shallow_water_demo` | **pass** (0-byte expected) | output_mismatch, 6 spurious lines | **−1** |
| `visual/definefont4` | **pass** (0-byte expected) | output_mismatch, 24 spurious lines | **−1** |
| `avm2/verify_illegal_opcode` | output_mismatch 0/1 | output_mismatch 1/1, 2 actual | 0 (near-miss, see below) |
| `from_avmplus/ecma3/Exceptions/exception_011_rt` | output_mismatch 1/3 | output_mismatch 2/3 | 0 (near-miss) |
| `avm2/bitmapdata_zero_size` | output_mismatch 5/8 | output_mismatch **7/8** | 0 (near-miss) |
| `avm2/coerce_property` | ruffle_matched | ruffle_matched | 0 |
| `avm2/array_access_oob_interpreter` | ruffle_matched | ruffle_matched | 0 |

### The two regressions — unchanged from worklist §7, both still 0-byte-expected

```
--- away3d_advanced_shallow_water_demo (expected vs actual) ---
+    1  ReferenceError: Error #1065: Variable ContextMenuEvent is not defined.
+    2  	at uk.co.soulwire.gui::SimpleGUI/initContextMenu()
+    3  	at uk.co.soulwire.gui::SimpleGUI()
+    4  	at Advanced_ShallowWaterDemo/initGUI()
+    5  	at Advanced_ShallowWaterDemo/init()
+    6  	at Advanced_ShallowWaterDemo()

--- definefont4 (expected vs actual) ---
+    1  TypeError: Error #1009: … (accessing field: getEffectiveLineHeight)
+    2  	at flashx.textLayout.compose::TextFlowLine/getLineLeading()
   … 22 more TLF frames down to definefont4_fla::MainTimeline()
```

Neither blocker moved since §7: away3d is still one missing class
(`ContextMenuEvent`) and definefont4 is still TLF's
`getEffectiveLineHeight`. Both remain a chain — closing one link only
reveals the next.

### THREE new one-line fixes the trace makes visible (this is the finding)

None of these is a regression: all three tests fail today with or without
the trace. But with the trace on, each is a single cosmetic line from a
full pass, and all three live in `callstack_snapshot` /
`print_uncaught`, i.e. inside the re-land's own blast radius.

**1. `avm2/bitmapdata_zero_size` — 5/8 → 7/8, one character of diff:**
```
     6  ArgumentError: Error #2015: Invalid BitmapData.
-    7  	at flash.display::BitmapData/get width()
+    7  	at flash.display::BitmapData/width()
     8  	at bitmap_fla::MainTimeline/frame1()
```
A stack frame for an accessor must render as `get width()` / `set x()`.
`callstack_snapshot` prints the bare method name. One `if` on the frame's
accessor kind.

**2. `avm2/verify_illegal_opcode` — 0/1 → 1/1 correct + one spurious line:**
```
     1  VerifyError: Error #1011: Method Test() contained illegal opcode 10 at offset 0.
+    2  	at Test()
```
`avm2_error.c:426` snapshots the call stack inside `error_init`, and our
#1011 is raised with `Test()` already pushed. Flash raises a verification
error *before* the frame exists, so its `getStackTrace()` is empty.
Suppress the tail for verifier-raised errors.

**3. `from_avmplus/ecma3/Exceptions/exception_011_rt` — 1/3 → 2/3:**
```
     2  undefined
-    3  	at global$init()
+    3  <end of actual>
```
The thrown value is `undefined`, not an Error, so it has no
`__stacktrace_tail` and `print_uncaught` prints nothing after it. Flash
still prints the frame the throw escaped from, so the printer needs to fall
back to the CURRENT call stack for non-Error values.

Each is worth +1, and all three are strictly *unlocked* by the re-land —
they are unreachable while the trace is reverted.

### `verify_illegal_opcode` — a new, cheap +1 sitting next to the re-land

With the trace on, the diff is now one spurious line:

```
     1  VerifyError: Error #1011: Method Test() contained illegal opcode 10 at offset 0.
-    2  <end of expected>
+    2  	at Test()
```

We print the right error and then a stack tail Flash does not have.
`avm2_error.c:426` snapshots the call stack in `error_init`, and our #1011
is raised with `Test()` already on the stack; Flash/Ruffle raise a
verification error *before* the method frame exists, so `getStackTrace()`
is empty. Suppressing the tail for verifier-raised errors (or raising #1011
before the frame push) turns this into a pass. It is a **gain the re-land
unlocks**, not a regression — the test fails today either way.

## B.4 Current balance

| | tests | detail |
|---|---|---|
| **gains** | **+2** | `uncaught_error_basic`, `loader_method` (both now full passes) |
| **regressions** | **−2** | `away3d_advanced_shallow_water_demo`, `visual/definefont4` |
| `ruffle_matched` risk set | **0** | 2 of 7 spot-checked, both kept `ruffle_matched`; §4.5's argument (Ruffle traces the same line, so its reference already contains it) holds |
| **net** | **0** | |

So the re-land is **+2 / −2 = net zero today**, up from the doc's
last-recorded −3 (§4) and matching §7's prediction of +2/−2. It is no
longer *negative* — but on its own it is not positive either.

**With the three one-line fixes in B.3 it becomes +5 / −2 = net +3**, and
those three fixes cannot be made or verified without it.

## B.5 Recommendation — HOLD, then land as a bundle

Do **not** land `revert of ac2325c6f` on its own: net 0 is not worth
re-opening a change that has now been reverted twice.

Land it as **one commit bundling the three stack-formatting fixes**
(`get`/`set` accessor frames, no stack for verifier-raised errors, current
stack for non-Error throws). That is a measured **+3 with the same two
regressions**, and every one of the three is inside the code the re-land
touches — so the bundle is self-contained and independently verifiable.

Optionally close one of the two regressions first to make it +4:
`away3d`'s `ContextMenuEvent` is an ordinary missing constant-bag class
(cheap on its own, but the demo is a chain and the next link is unknown).
`definefont4` needs TLF's `getEffectiveLineHeight` and is not cheap.
Neither is a precondition for the bundle being net-positive.

**Two protocol notes for whoever lands it:**
- The doc's own §7 lesson ("re-run the query, never price from the doc")
  needs a mirror clause: **re-run the GAIN query too.** The `+2` in every
  version of this document was carried forward unmeasured since
  2026-07-26, and the failing-side census (B.2) found three more candidates
  that had accumulated since.
- CI dispatch for this is `mode=graphics`, `categories=full` (it touches
  AVM2 runtime and the risk set spans `from_avmplus`).

## B.6 Worktree state (nothing committed, nothing pushed)

- `git revert -n ac2325c6f` is **staged but uncommitted** in
  `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-ac64f04cc32d4e748`
  (`avm2_error.c` +17, `avm2_function.c` +18).
- `SWFRecomp/build/` was configured and built there (fresh worktree).
- The specific test fixtures used were copied in from the main checkout
  (`ruffle-tests/tests/swfs/**` is gitignored, so a fresh worktree has
  none); `.agentlogs/` holds every run's raw output. Both are untracked.
- Master is untouched.
