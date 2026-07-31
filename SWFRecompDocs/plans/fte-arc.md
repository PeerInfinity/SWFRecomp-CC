# FTE arc (flash.text.engine) — scoping

**Status**: scoped 2026-07-31 (pre-implementation). Census **20 candidates**
(18 direct FTE ~1,240 graded lines + `visual/definefont4` +
`avm2/abstract_classes` as a gated rider), predicted **+15**. Oracle:
Ruffle @ `437be1498`; every rule below verified against recorded
`output.txt` (FP ground truth). Only 2 upstream `known_failure`s —
`content_element_basic` and `textline_validity` — and BOTH are beatable
(§3.6, §3.7).

## 1. The pattern — the OPPOSITE of the filters arc

FTE classes validate **eagerly in the setters**: `null` → TypeError
**#2007** ("Parameter X must be non-null"), unknown enum string →
ArgumentError **#2008**, all enums case-SENSITIVE. There is no value-bag/
round-trip split. The shared primitive (get-string-non-null → #2007,
enum-match → #2008) ALREADY EXISTS in our passing FontDescription
implementation (avm2_text.c:4912+, with all FTE constant classes
registered) — extend it, don't duplicate. Constructors are AS-side and
assign THROUGH the public setters in a graded order; 9 of 18 tests grade
stack traces, so the shader-P1 class-split constraint applies arc-wide:
ctor frames must show `set <prop>()` inside `<Class>()`, TextBlock's
justifier setter must appear as `setTextJustifier()`, the createTextLine
native as `DoCreateTextLine()`, and FP's `Error.throwError` intrinsic
adds an `at Error$/throwError()` frame wherever it's used (TabStop /
ElementFormat / TextLine setters, TextBlock/createTextLine).

## 2. The layout core is a `\n` splitter — NOT text measurement

`createTextLine` in Ruffle (text_block.rs:321-455) splits on `\n` ONLY —
`width` is stored as `specifiedWidth` and NEVER consulted for breaking;
`\r` and `\r\n` are NOT breaks; the break includes its `\n`; a trailing
empty segment produces no line ("a\n" → 1 line, "\na" → 2 at indices
0,1). No graded line in any of the 18 tests reads textWidth/textHeight/
ascent/descent/atomCount — **our glyph/device-font machinery is NOT a
dependency**. Line creation must succeed with a completely unresolvable
font (several tests use device "_serif"). Load-bearing details:
- `rawTextLength` = the WHOLE block's text length, not the line's (11
  for a one-line "Hello World").
- `textLineCreationResult` is **null before the first call**, then
  `success`, then `complete` when content is exhausted; null/"" content
  → no line, straight to `complete`.
- `previousLine`/`nextLine` wired on creation of the NEXT line;
  `line.textBlock === block` identity holds.
- Error taxonomy in ORDER (TextBlock.as:85-101): content null → return
  null (no throw, before all checks); bad previousLine (validity !=
  "valid" or wrong block) → #2004; width < 0 or > 1000000
  (TextLine.MAX_LINE_WIDTH) → #2004; element with null elementFormat →
  **#2175 TRACED (not thrown)** with frames `DoCreateTextLine()` /
  `createTextLine()` / caller, then return null — emit this trace
  DIRECTLY at the site (our general uncaught-error tracing is reverted;
  do not resurrect it for this); content shrank past previousLine →
  result "complete", return null.

## 3. Per-class rules (each verified in the named test's output.txt)

1. **ElementFormat** — 17-arg ctor, order: fontDescription, fontSize,
   color, alpha, textRotation, dominantBaseline, alignmentBaseline,
   baselineShift, kerning, **trackingRight, trackingLeft** (swapped!),
   locale, breakOpportunity, digitCase, digitWidth, ligatureLevel,
   typographicCase. Ctor assigns in EXACTLY that order and stops at the
   first throw (element_format_constructor_order grades which #2008
   fires first). fontDescription: ctor null-guards (defaults to `new
   FontDescription()`) but the SETTER rejects null (#2007). alpha:
   clamp [0,1], NaN→0, never throws. fontSize: <0 → #2004, NaN→0, +Inf
   ok, −Inf → #2004. baselineShift: NO clamp, NaN/±Inf round-trip.
   tracking{Left,Right}: NaN→0, ±Inf stored. color: uint, no
   validation. locale: non-null only, ZERO content validation.
   dominantBaseline: the 7 TextBaseline values MINUS useDominantBaseline
   (#2008); alignmentBaseline: all 7. textRotation here ALLOWS "auto".
   `locked`: plain bool, NO enforcement graded, clone() unlocks.
   clone() deep-clones fontDescription.
2. **TabStop** — ctor (alignment="start", position=0,
   decimalAlignmentToken=""), assigns in order, frames graded.
   alignment ∈ start/center/end/decimal. position: <0 → #2004, **NaN
   ACCEPTED and round-trips** (unlike fontSize!), +Inf ok, −Inf #2004.
3. **TextBlock** — defaults: applyNonLinearFontScaling true, textJustifier
   defaults to a SpaceJustifier, content/firstLine/lastLine/
   firstInvalidLine null. Ctor order: content → tabStops → textJustifier
   → lineRotation → baselineZero → baselineFontDescription/Size →
   applyNonLinearFontScaling. baselineZero: TextBaseline minus
   useDominantBaseline. lineRotation: TextRotation MINUS "auto".
   bidiLevel: int, <0 → #2004. baselineFontSize: <0 → #2004, NaN ok.
   textJustifier null → #2007 with frame `setTextJustifier()`.
   **tabStops: getter returns a FRESH Vector copy every call but the
   TabStop ELEMENTS are shared by reference** (graded: push doesn't
   grow; ts.position mutation visible both ways). Empty Vector traces "".
4. **ContentElement** — abstract via qualified-name check, message
   `Error #2012: ContentElement class cannot be instantiated.` (NO `$`),
   and FP adds `at Error$/throwError()` (§3.6). Defaults: userData
   undefined, textBlock null, textBlockBeginIndex **-1**, elementFormat/
   eventMirror/groupElement/rawText/text null, textRotation rotate0.
   textRotation REJECTS "auto" (unlike ElementFormat's).
5. **TextElement / GroupElement** — text=null stores null (traces
   "null"). replaceText: bounds (neg or >len either index) → #2006;
   **begin>end is LEGAL** → duplication ("yello"(2,1,"i") → "yeiello").
   GroupElement is pure Vector algebra: setElements(null) → empty,
   else COPIES; **replaceElements(b,b,null) → returns null with NO
   bounds check at all** (50,50,null succeeds); else bounds → #2006;
   returns spliced-out Vector ("" when empty). splitTextElement: bounds
   #2006 → non-TextElement #2004 → splitIndex bounds #2006; the new
   tail element has NO elementFormat (which then feeds the #2175 path!).
   GroupElement.text = concatenation of children (rawTextLength 11
   depends on it).
6. **content_element_basic (beat the known_failure)**: the ONLY delta vs
   Ruffle is the missing `at Error$/throwError()` frame. Emit that
   frame → full pass, not ruffle_matched.
7. **TextLine + validity (beat the known_failure)**: TextLine is a real
   DisplayObject extending DisplayObjectContainer — `textline_name`
   grades `name == "instance1"`, so it consumes the shared instanceN
   counter and the INTERNAL fallback text object must NOT consume one.
   Five setter overrides throw #2181 (contextMenu, focusRect,
   tabChildren, tabEnabled, tabIndex), printed as `Error: Error #2181:
   The TextLine class does not implement this property or method.`
   (IllegalOperationError toString says "Error"); getters return
   null/null/false/false/-1. Validity state machine (162 lines,
   verbatim): buckets Valid/Invalid/Static/PossiblyInvalid/
   UserInvalid(anything else); setting exact "possiblyInvalid" → #2008
   always; "static" allowed from anywhere; current static → only
   static; current invalid → only invalid|static; otherwise ARBITRARY
   strings stored verbatim ("INVALID", "unknown" are legal values);
   null → #2007. **The invalidation trigger Ruffle misses: ANY write to
   TextBlock.content (even re-assigning the same element) flips all
   existing lines of that block to "invalid"** — implement it → full
   pass on textline_validity.
8. **Justifier clones**: SpaceJustifier min/max/optimumSpacing;
   EastAsianJustifier needs composeTrailingIdeographicSpaces (API 674 —
   visible at these SWF versions). lineJustification/justificationStyle
   NOT validated (Ruffle TODO; tests don't grade validation there).

## 4. Census and tranches

### T1 — value objects + validation core · predicted +8 of 9 · MEDIUM
element_format_properties 235, element_format_constructor_order 64,
element_format_clone 44, tabstop_properties 105, text_element_basic 34,
content_element_basic 50 (beat KF), text_engine_groupelement 64,
space_justifier_clone 12, east_asian_justifier_clone 8. Hedge: one
stack-frame-shape miss.

### T2 — TextBlock + TextLine + the layout core · predicted +6 of 8 · MEDIUM-LARGE
textblock_properties 118, textblock_createline_errors 23,
textblock_createline_fte 9, textline_splitting_basic 76,
textline_validity 162 (beat KF), textline_inapplicable_properties 10,
textline_throwerror 30, textline_name 1. Hedges: the #2175
traced-not-thrown emission and the instance-counter interaction.
Trap: splitting/validity/createline_fte SWFs embed DefineFont4 (91) and
DefineFont3(75)+DefineFontName(88) — the tag reader must ingest or skip
them without erroring; glyphs never needed for traces.

### T3 — riders · predicted +1 of 3 · SMALL (gated)
- `visual/definefont4`: 0-byte expected trace; the SWF carries the
  ENTIRE TLF in one DoABC + 2 DefineFont4 tags. Passing = running 5
  frames with zero uncaught output. §5 of the oracle report enumerates
  the exact 30 classes and ~35 members TLF references — every one must
  EXIST and return a type-correct value (Ruffle passes with getAtom*
  sentinels, recreateTextLine returning its arg, lastLine → firstLine).
  Take AFTER T1+T2; the member checklist is the spec.
- `abstract_classes` 132: a GENERAL #2012 test over 45 classes (only 2
  FTE rows; ContentElement explicitly excluded). Currently 0/132 — the
  `<Name>$ class cannot be instantiated` mechanism itself is missing.
  CENSUS FIRST: count how many of the 45 classes exist in our runtime;
  implement the abstract gate (+`$` message + `at Test()` frame) and
  take the test ONLY if the existence census says it's reachable; else
  record per-class gaps and move on.
- The away3d follow-on (#1009 null .width in Stage3D land) is NOT this
  arc.

**Arc prediction: +15 of 20.**

## 5. Canaries

`text_engine_fontdescription` 27/27 + `font_description_clone` 14/14
(the existing FontDescription must not move — T1 extends its validation
primitive), `key_input_*` (1812+126+384 lines — they reference FTE names
but pass; verify they're not FTE-dependent before worrying),
`error_geterrormessage` 779 (error-table neighbour), the avm2 text/
edittext families, and after T2 the display-list instance-name counter
tests (any test tracing instanceN names). Standard pipeline;
mode=graphics categories=full.

## 6. Postmortems

### T1 — value objects + validation core · predicted +8 of 9, **shipped 9 of 9**
Commit `f89fa6cd4`; CI `30591520622` (graphics/full): **+9, zero
regressions, status histogram flat**, corpus 4062 → 4071/4422, avm2
1035 → 1044.

What §1–§3 got right: the eager-setter model, the constructor-through-
setters ordering (including trackingRight-before-trackingLeft), and the
per-property numeric quirks all held exactly as scoped. `content_element_basic`
beat its known_failure on the single predicted delta — the missing
`at Error$/throwError()` frame.

Two corrections to the scoping:

1. **§1 over-generalised `Error.throwError`.** It claimed the frame appears
   on "TabStop / ElementFormat / TextLine setters". `output.txt` says
   otherwise: ElementFormat's and TabStop's setters report their `set <prop>()`
   frame *directly*, with no throwError above it — visible because both
   tests print `getStackTrace()` (tabstop) or its first two lines
   (element_format), and the throwError frame would be first if it existed.
   The frame is real for **ContentElement's #2012**, **TextLine's #2181**
   and **TextBlock.createTextLine's #2004** only. Reading the graded output
   before writing the setter is what caught it; the spec's prose would have
   produced 3 wrong tests.

2. **A vtable bug the arc did not predict, and would have silently lost 2
   tests to.** `avm2_builtin_class` copies the super's ivtable entries
   FIRST, and property lookup is first-match-wins. So a builtin subclass
   that re-registers an inherited member does not override it — it appends
   an entry that can never be reached. Both justifier `clone()` overrides
   resolved to `TextJustifier.clone()` (which returns null), so
   `sj.clone() as SpaceJustifier` was null and both clone tests died on
   #1009. Fixed with `fte_override_method` / `fte_override_getset`, which
   rewrite the inherited entry's payload in place. This is a general trap
   for any future builtin class hierarchy, not an FTE quirk.

### T2 — TextBlock + TextLine + the layout core · predicted +6 of 8, **shipped 8 of 8**
Commit `cebf30b89`.

§2's central claim — the layout core is a `\n` splitter, and our glyph /
device-font machinery is not a dependency — was exactly right, and it is
what made this tranche small. Both hedges evaporated: the traced-not-thrown
#2175 is three lines once you construct the error at the site (its
construction-time stack snapshot IS the graded frame list), and the
instance-counter interaction is a non-issue precisely *because* we build
no internal fallback text object. Ruffle allocates an EditText per line for
measurement; we skip it, so the shared counter number goes to the TextLine
and `textline_name` gets its "instance1" for free. Building the fallback
would have been the bug.

`textline_validity` beat its known_failure on the predicted rule (any write
to `TextBlock.content` invalidates the block's lines). Worth restating
because it is counterintuitive: `validity` is **not** an enum-validated
property. Arbitrary strings are legal values stored verbatim; only three
rules constrain it (exact `"possiblyInvalid"` never settable; from
`"static"` only `"static"`; from `"invalid"` only `"invalid"` or
`"static"`).

Structural note: `TextLine` is a real `DisplayObjectContainer`, so its class
shell has to live in `avm2_display.c` (it needs the concrete display alloc
hook and the display ext, Loader-style, with `Avm2TextLineExt` leading with
`Avm2DisplayObjectExt`). `avm2_text.c` wires the FTE surface onto it through
`avm2_text_init_textline_class`, mirroring the existing
`avm2_text_init_textfield_class` split. Keeping the whole ext in one
conservatively-scanned blob avoided adding a GC mark hook.

Three numeric setters now exist with three different NaN policies, and the
arc's §3 warning against generalising was well placed:
`ElementFormat.fontSize` scrubs NaN→0, `TabStop.position` keeps it,
`TextBlock.baselineFontSize` keeps it. All three reject negatives with #2004.

### T3 — riders · predicted +1 of 3, **shipped 0, and the prediction was
based on a misread baseline**

- **`visual/definefont4` was ALREADY PASSING** at the arc's baseline
  (`2db1eeb94`, status `pass`, 0/0 lines). §4 listed it as a candidate;
  it never was one. It passes because the expectation is a 0-byte trace and
  TLF dies early with `#1065 Variable ContentElement is not defined` — an
  uncaught error, which goes to stderr and leaves the trace file empty. The
  image comparison does not gate pass/fail in this harness.

  That inverts the item: T3's definefont4 work is a **regression check, not
  a gain**. With FTE present, TLF no longer dies at ContentElement and runs
  further into code we have never exercised — if any of it traced (our own
  #2175 emission being the obvious candidate), the test would flip
  pass → fail. Verified locally after T1+T2: still passes. The 30-class /
  ~35-member checklist is therefore moot as a *target*; what mattered was
  that nothing new reaches stdout.

  Consequence for the gate: `GraphicElement` and `FontMetrics` were
  deliberately **not** added. No test grades either, and each one pushes TLF
  further into unexercised code — pure regression risk against a test that
  already passes. Recorded as gaps below.

- **`avm2/abstract_classes` is unreachable.** Census of its 43 listed
  classes: **14 do not exist** in our runtime — `Accessibility`,
  `AVM1Movie`, `DRMManager`, `DRMPlaybackTimeWindow`, `DRMVoucher`,
  `GameInputControl`, `IME`, `MessageChannel`, `Multitouch`,
  `SecurityDomain`, `StageVideo`, `TextLineMirrorRegion`, `TextSnapshot`,
  `Worker`. The test builds a single array literal from all of them, so the
  FIRST missing name (`Accessibility`, which is also first in the array)
  kills the constructor and the test scores 0/132. No partial credit is
  available: it is all-or-nothing on 14 unrelated subsystems
  (accessibility, DRM, workers, IME, multitouch, text snapshots).

  §4 also claimed "the `<Name>$ class cannot be instantiated` mechanism
  itself is missing". It is not — `avm2_display.c`'s
  `display_native_init_abstract` and `morphshape_native_init` have produced
  exactly that message for the display bases for some time. What was missing
  was classes, not the gate.

  The two FTE-owned rows are now complete: `TextLine`'s #2012 gate landed
  with T2 (conditional, since the layout core must be able to allocate one),
  and `TextLineMirrorRegion` is added here as an empty abstract final class.
  `ContentElement` is explicitly excluded by the test.

  Remaining gaps for whoever takes `abstract_classes` later: the 13
  non-FTE classes above. It needs its own scoping — the work is 13 class
  stubs across six unrelated subsystems, none of which this arc owns.

### Arc result: **+17 of 20** (predicted +15)

18 of 18 direct FTE tests pass, including both upstream `known_failure`s
(`content_element_basic`, `textline_validity`). The two riders yielded
nothing: `definefont4` was already green, `abstract_classes` is blocked on
14 missing non-FTE classes.

### Lessons

- **The graded `output.txt` overrules the scoping prose, and it is cheap to
  check.** §1's throwError claim was wrong for two whole classes; five
  minutes reading `element_format_properties`' expected output settled it
  before a line of C was written.
- **A "candidate" test that already passes is a regression risk wearing a
  gain's clothes.** Always read the baseline status of a rider before
  budgeting yield for it — and once you know it is already green, the
  correct move is to add LESS, not more.
- **First-match-wins vtables make builtin overrides silent no-ops.** Any
  future builtin class that re-declares an inherited member needs
  `fte_override_*`-style in-place replacement. The failure mode is not a
  crash; it is the base implementation quietly winning.
- **Not building the thing Ruffle builds was the right call twice**: no
  internal fallback EditText (it would have stolen the graded instance
  name), and no GraphicElement/FontMetrics (they would have pushed a
  passing test into unexercised code).
