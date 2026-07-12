# Session prompt — AVM2 Stage 6: TextField/EditText engine (+ Stage-5 stragglers)

**STATUS: COMPLETE (2026-07-12).** All 13 Stage-5 stragglers + 62 text
tests pass: **75/85 candidates** (72 pass + 3 ruffle_matched; exit >=60
met) at `45a507da5`..`415205ed7`. The 10 misses are triaged in
`STAGE6_CANDIDATES.txt` (7 = flash.text.engine TextBlock/TextLine
family — the natural follow-up tranche; 2 = Loader infrastructure;
1 = device-font TTF metric parity). CI baseline run 29180816425:
**avm2 727/1201 + 21 RM = 748 effective (62.3%)**, +91 over Stage 5's
657, zero pass->fail regressions in ANY suite, wasm-link-smoke green.

You are implementing **Stage 6** of the AVM2 plan
(`SWFRecompDocs/plans/avm2-support-plan.md`): the flash.text engine —
TextField property surface, TextFormat, htmlText parsing, and enough of
a text LAYOUT engine (font advances, line breaking) to answer the
metric getters (textWidth/textHeight/numLines/getLineMetrics/
getCharBoundaries). This is the largest remaining coherent unlock on
the trace-test metric (72 of the 544 remaining failures are the text
family). A warm-up tranche knocks out 13 Stage-5 stragglers first.

Read the plan first, then
`ruffle-tests/tests/swfs/avm2/_investigation/CURRENT_STATUS.md`, then
the memories `avm2-stage5-display` / `avm2-e4x-engine` /
`avm2-stage4-tranche3` (gotcha lists — the Stage-5 one is load-bearing
for any display work), then skim the code seams below.

Stage 5 landed at `f662d9b9a`..`5499f0e2a`. CI baseline: **avm2
639/1201 + 18 ruffle_matched = 657 effective (54.7%)**, run
29174330330; zero regressions anywhere; wasm-link-smoke green.

## Goal

Candidate list (95 names, all failing at the baseline):
`ruffle-tests/tests/swfs/avm2/_investigation/STAGE6_CANDIDATES.txt`
— text family 72 (edittext_* 60, textfield_* 4, font_* 5,
textformat_* + text_* 3), Stage-5 stragglers 13. Tests needing
input.json (16) or image comparison (4) are excluded up front.

Exit: **≥60 of the 95 candidates passing in CI; every miss triaged**;
zero pass→fail regressions anywhere (the avm2 657-effective baseline
must stay green). If you stop at a tranche boundary, refresh THIS
prompt with precise resume state (the Stage-3/4/5 convention) and
record the CI baseline you reached.

## Code seams (what exists today)

- `SWFModernRuntime/src/avm2/avm2_display.c` — flash.text.TextField
  (extends InteractiveObject) and StaticText exist as structural stubs;
  TextField has only a `text` getter/setter fed by `tf_text` on
  `Avm2DisplayObjectExt` (avm2_globals.h), which `instantiate_child` /
  `button_create_state` seed from `Avm2CharInfo.init_text`.
  `add_getset()` there REPLACES inherited accessors in place — use it
  for all overrides. `display_native_init` is the alloc hook (concrete
  classes must set it explicitly — the DO/IO/DOC hooks throw 2012).
- `SWFRecomp/src/abc/abc_timeline.cpp` — the AVM2 static-table second
  pass. Its DefineEditText parser currently extracts ONLY bounds +
  initial text (HTML pre-stripped to plain text at emit time — you
  will likely want to emit BOTH raw html and plain now) and discards
  flags/font/color/layout. Extend `Avm2CharInfo` (avm2_abc.h) or add a
  parallel `Avm2EditTextData` table with: all flag bits (wordWrap,
  multiline, password, readOnly, autoSize via HasLayout?, border, html,
  useOutlines, noSelect, wasStatic), font id + height, text color,
  maxLength, layout (align/margins/indent/leading), variable name.
  Keep emission additive and AVM2-gated (the Stage-2 lesson).
- **Fonts**: the scanner classifies DefineFont* as OTHER and skips
  them. For layout math you need per-glyph advances + code tables +
  ascent/descent/leading + em square. The AVM1 recompiler already
  parses all of this (`SWFRecomp/src/swf.cpp` font_advance_tables /
  font_code_tables / font_em_square / font_ascent members) — but the
  AVM2 scanner is deliberately independent; either parse DefineFont2/3
  in abc_timeline.cpp (advances + codes are enough; skip shapes) or
  plumb the swf.cpp maps through TimelineEmitInfo. Emit an
  `avm2_generated_fonts` table.
- Do NOT touch `SWFModernRuntime/src/actionmodern/action.c` or the
  AVM1 EditText engine — port from Ruffle instead.
- New src/avm2/*.c files go into verify_output.py `compile_native`'s
  avm2 list (the one allowed edit there).

## Ruffle reference (local at ~/CC/ruffle)

- `core/src/avm2/globals/flash/text/text_field.rs` (1773) +
  `TextField.as` — the full AS3 property surface incl. error codes
  (2005/2006/2008) and defaultTextFormat semantics.
- `core/src/display_object/edit_text.rs` (3685) — EditText state:
  text_spans (FormatSpans), autosize relayout, bounds_x/y quirks,
  selection, scroll (bottomScrollV etc.), the intrinsic-bounds +1px
  gutter (GUTTER = 2px each side — the AVM1 side replicated this;
  see RUFFLE_COMPAT_TWEAKS.md).
- `core/src/html/text_format.rs` (1856) — TextFormat + FormatSpans +
  the html parser/writer (htmlText roundtrip rules, condenseWhite,
  entity handling, font tag attribute quirks).
- `core/src/html/layout.rs` (1454) — the layout engine: LayoutBox
  lines, word wrap breaking, advances in twips
  (`font.get_glyph_advance`? — see `core/src/font.rs` for scaling:
  advances are in EM-square units scaled by height/em), leading,
  align/margins/indent. Port the MEASUREMENT paths only (no
  rendering): line breaking + per-line width/height + char x-positions
  feed textWidth/textHeight/numLines/getLineMetrics/getCharBoundaries/
  getLineIndexOfChar and autoSize bounds updates.
- `core/src/avm2/globals/flash/text/text_format.rs` + TextFormat.as;
  `Font.as` + font.rs for flash.text.Font (font_* tests:
  enumerateFonts, hasGlyphs, fontName/Style/Type).

## Suggested tranche order (commit + local-batch at each checkpoint)

0. **Stage-5 stragglers (13)**: FIRST fix the static-slot-write bug —
   `INSTANCE = this` inside a ctor doesn't reach the class object's
   static slot (Main.INSTANCE reads back null;
   simplebutton_symbolclass's 1009s). Suspect the FindProperty scope
   walk for SET on class-scope statics in avm2_ops.c. That likely
   unblocks several simplebutton_* event tests; then chase the
   remaining button event-order diffs, movieclip_next/prev_scene,
   goto_button_nested_framescript, goto_nested_construct_sibling,
   place_object_replace_2 (per-type Replace re-instantiation rules:
   Ruffle replace_with re-instantiates MovieClips, swaps in place for
   shapes/texts), movieclip_frameconstruct_skipped (ctor-failure flag:
   children stay unconstructed after the root ctor throws — check what
   "Main allocated" traces from before deciding the model).
1. **TextFormat + defaultTextFormat + property surface** (~25 tests:
   edittext_default_format*, _align, _leading, _letter_spacing,
   _font_size, edittext_tf_*, textformat_*): TextFormat class (all
   props nullable), TextField get/setTextFormat span model (a single
   uniform span is enough until htmlText lands), the big property
   surface (type/border/background/colors/selectable/wordWrap/
   multiline/maxChars/restrict-as-data/displayAsPassword/autoSize
   values/scroll props as data), appendText/replaceText.
2. **Layout engine** (~20 tests: autosize family, textWidth/Height,
   numLines, line_methods, getlinemetrics, getcharboundaries*,
   get_line_index_of_char, bounds_scale, word_wrap): font tables →
   advance math → line breaking → metrics getters + autoSize bounds
   (remember the 2px gutters and the AVM1 +1px width tweak precedent).
3. **htmlText** (~15 tests: edittext_html*, entity, condensewhite,
   roundtrip, font_size_swf12/13): port text_format.rs's parser/writer
   semantics; SWF-version gates (the swf12 vs swf13 font-size tests).
4. **flash.text.Font + misc** (font_* 5, remainder): Font class,
   embedded-font enumeration from the emitted font table,
   hasGlyphs; StaticText getters if cheap.
5. Triage the misses; refresh STAGE6_CANDIDATES.txt statuses.

## Constraints & conventions (unchanged)

- Trunk-based; commit directly to `master`; autonomous commit/push/CI
  authorized (CLAUDE.md). Standard trailer. Full pipeline per
  `.claude/pipeline-handoff.md` at the end (no-graphics mode — the text
  work is AVM2-only); confirm zero pass→fail across ALL suites and
  wasm-link-smoke green.
- Conflict boundary: own `SWFRecomp/src/abc/`, `SWFRecomp/include/abc/`,
  `SWFModernRuntime/{src,include}/avm2/`, `RecompiledABC/` paths.
- Do NOT run the full avm2 suite locally. Single tests:
  `python3 ruffle-tests/verify_output.py --test=NAME
  --tests-dir=ruffle-tests/tests/swfs/avm2 --diff`. Batch loop greping
  `^Pass:` over the candidate list is ~5-8 s/test warm.
- Keep the honest-failure property: unimplemented paths abort with a
  named message, never silently mis-execute.

## Gotchas from Stage 5 you must not trip over

- REBUILD the recompiler after any SWFRecomp change
  (`cd SWFRecomp/build && make -j8`); verify_output only rebuilds the
  runtime side.
- vtable accessor OVERRIDES must replace in place (`add_getset` in
  avm2_display.c does this) — appends never shadow inherited entries.
- Timeline-placed TextFields are `instantiated_by_timeline` → their
  `name` setter throws 2078; they're auto-named instanceN (1-based
  counter) unless the PlaceObject names them.
- The full Stage-5 gotcha list lives in `avm2-stage5-display` (memory)
  and the resume-state section of
  `SWFRecompDocs/prompts/avm2-stage5-frames.md` — read both.
- Expected outputs may embed FP's exact float formatting — use the
  existing avm2_format_number, and check test.toml `[approximations]`
  before chasing 1-ulp diffs.
- Several edittext tests were runtime_error→output_mismatch conversions
  during E4X (they run to completion but print nothing useful) — their
  diffs start from line 1; read the WHOLE expected output before
  implementing.

## End-of-session bookkeeping

- Stage-6 landing note in `avm2-support-plan.md` §5 (add the stage
  bullet; promote to DONE or record partial tranche state).
- Update `avm2/_investigation/CURRENT_STATUS.md` (new CI baseline,
  what landed, misses triaged).
- Update the `avm2-stage5-display` / direction memories (Stage-6
  status; what's next — likely the input.json harness, Loader/
  LoaderInfo, or BitmapData).
- If partial, refresh THIS prompt with precise "resume here" state; if
  complete, mark it COMPLETE at the top (Stage-1/2/3/4/5 convention).
