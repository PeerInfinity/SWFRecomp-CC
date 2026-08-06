# wave1-trace-b8b-b9 — scoping report (session 11)

Agent: `w1-trace-b8b-b9`. HEAD `b4c983ea4`. Baseline CI run 30713776612 @
`c4496a4c8` (trace 4188/4424, pixels 217/566). **Read-only on source; no
commits.** Every status below was re-measured at HEAD unless marked
"(baseline json)".

Headline: **both leads are GO for wave 2 this session.** Neither is arc-sized.
B8b is smaller than session 10 believed and its stated blocker is **REFUTED**.

---

## Lead B8b — "lazy script inits" / DoABC + SymbolClass load order

### Verdict summary

| Session-10 claim | Verdict |
|---|---|
| "rewrite of the step-3/4 contract" | **REFUTED** — it is an *additive* frame-scoping of two tag classes; the boot contract for frame-1 tags can stay byte-identical. |
| "the `from_avmplus` drivers pin the current order" | **REFUTED** — **0 of 1573** from_avmplus SWFs carry a DoABC or SymbolClass tag beyond frame 1, and **1560 of 1573** have a *lazy* DoABC2. The safe slice cannot reach them at all. |
| "avmplus drivers eagerly init" (this brief) | **REFUTED** — the avmplus driver SWFs set `DoAbc2Flag::LAZY_INITIALIZE`; Ruffle runs **no** eager script for them. They only work today because their ABC has one script, which the SymbolClass root lookup would initialize anyway. |
| "it is a real batch on its own (est. M–L)" (w2-symbols §B8b) | **CONFIRMED as M, one worktree agent.** Not an arc. |
| target list = 2 tests | **REFUTED / extended** — a third failing test, `avm2/delayed_symbolclass`, is the same mechanism. |

### The actual contract (Ruffle, verified in source)

`core/src/display_object/movie_clip.rs:4248-4258` states it in comments and
`run_abc_and_symbol_tags` (:4263-4395) implements it. **The first time a given
frame executes:**

1. every `DoAbc`/`DoAbc2` tag **in that frame** is parsed + loaded
   (`Avm2::do_abc`, `core/src/avm2.rs:504-548`). No script initializer runs.
   A non-`LAZY_INITIALIZE` tag returns its *final* script as an "eager script",
   held back;
2. every `SymbolClass` row **in that frame**, in order, is resolved via
   `lookup_class_for_character` → the domain lookup triggers the lazy init of
   whichever script defines that class;
3. only then do the held-back eager final-script initializers run.

Call sites: `movie_clip.rs:1438` (normal frame tag pass, after `decode_tags`,
i.e. after AS3 PlaceObjects are *queued* but before they drain) and
`movie_clip.rs:1749` (**inside the goto frame walk** — skipped frames still run
their abc/symbol tags).

### What we do today

`SWFModernRuntime/src/avm2/avm2_main.c::runSWF_avm2`:
* **step 1** (:424-433) loads **all** ABC files at boot. `avm2_abc_load`
  (:189-229) registers every script trait name in the domain immediately, so
  every definition in every ABC is reachable from tick 0.
* **step 2** (:435-460) picks the root class from the flat binding list.
* **step 3** (:462-478) eager-inits the **last script of every ABC file**,
  unconditionally — the `LAZY_INITIALIZE` flag is never even read.
* **step 4** (:480-567) builds the stage. Non-root SymbolClass rows are only
  consulted at *timeline instantiation* (`avm2_display.c:1526`, `:1585`), never
  as a load-time "resolve the class name" step.

The recompiler throws away both pieces of information the contract needs:
* `SWFRecomp/src/swf.cpp:6237-6250` — the DoABC2 `Flags` u32 is **skipped**
  (`abc_data = p` past Flags+Name); the LAZY bit is discarded.
* `SWFRecomp/src/swf.cpp:4745-4776` — SymbolClass rows are pushed into a flat
  `symbol_class_bindings` vector with **no frame index**.
* `RecompiledABC/abc_registry.c` therefore emits a flat
  `avm2_generated_abc_files[]` + `avm2_generated_symbol_classes[]` with no
  frame association (`SWFRecomp/src/abc/abc_emit.cpp:3966-3983`).

### Blast radius — measured statically over the WHOLE corpus

Script: `scratchpad/scan_abc.py` (read-only, not added to the repo) walked all
**4943** `*.swf` under `ruffle-tests/tests/swfs` (FWS/CWS/ZWS-LZMA). 4939
parsed; the 4 misses are the known decoys
(`avm1/movieclip_state_values/no correct file (image|text).swf`,
`from_shumway/as3-loader/bug1157243/{empty,invalid}`) — same four session 10
found. 3075 SWFs carry a DoABC and/or SymbolClass tag.

**Exactly 9 SWFs in the entire corpus have any DoABC or SymbolClass tag beyond
frame 1.** That is the complete population a frame-scoping change can touch:

| Test | ABC tags (frame,lazy) | SymbolClass (frame,#rows) | Status @HEAD |
|---|---|---|---|
| `avm2/doabc_and_symbolclass_script_init_normal` | (1,eager),(2,eager) | (1,1),(2,1),(3,1) | **output_mismatch 1/6** (re-measured) |
| `avm2/doabc_and_symbolclass_script_init_goto` | (1,eager),(2,eager) | (1,1),(2,1),(3,1) | **output_mismatch 1/7** (re-measured) |
| `avm2/delayed_symbolclass` | (1,lazy) | (1,1),(2,1),(4,1) | **output_mismatch 16/28** (re-measured) |
| `avm2/goto_in_scene_last_frame` | (1,lazy),(2,eager) | (1,1) | **PASS** (re-measured) ← highest-risk canary |
| `avm2/displayobject_name` | (1,lazy) | (1,1),(2,2) | pass (baseline json) |
| `avm2/displayobject_parent` | (1,lazy) | (1,1),(2,2) | pass (baseline json) |
| `avm2/displayobject_root` | (1,lazy) | (1,1),(2,2) | pass (baseline json) |
| `avm2/displayobject_visible` | (1,lazy) | (1,1),(2,2) | pass (baseline json) |
| `from_shumway/timeline/timeline_loop` | (1,lazy) | (1,1),(2,1) | pass (baseline json) |

Per-suite: `avm2` 8 of 1265, `from_shumway` 1 of 117, **`from_avmplus` 0 of
1573**, everything else 0.

Lazy/eager split across the 3075: 2863 all-lazy, 204 all-eager, 7 mixed, 1 no
ABC. Cross-referencing the 3029 cached `RecompiledABC/abcN_tables.c` script
counts: 1546 lazy+multi-script, 1286 lazy+single-script, 171 eager+single,
26 eager+multi. (Relevant only if someone tries the *maximal* fix — see
"do NOT do this" below.)

### Mechanism proof — `doabc_and_symbolclass_script_init_normal`

Tag layout decoded from the SWF (`scratchpad/tags2.py`):

```
F1: DoABC2 'New DoABC' LAZY=False   +  SymbolClass 0:New   + ShowFrame
F2: DoABC2 'merged'    LAZY=False   +  SymbolClass 1:C     + ShowFrame
F3:                                    SymbolClass 2:B     + ShowFrame
```

`abc0` = 1 script (class `New`). `abc1` = 5 scripts, in order
`0:Test, 1:A, 2:B, 3:C, 4:Z` (decoded from `abc1_scripts[]` trait
`name_mn` → multiname → string; `abc1_tables.c:102-134`). Last script = `Z`.
Each script initializer traces its class name.

Expected vs actual @HEAD:

```
expected                                   actual
1  New                                     New
2  New constructor                         Z
3  Test inaccessible … #1065 …             C
4  C                                       B
5  Z                                       New constructor
6  B                                       Test inaccessible … #1065 …
```

Replay the Ruffle contract by frame and you get the expected list **exactly**:
F1 → load abc0, resolve `New` (script init → "New"), eager last script of abc0
is that same script (no-op); root ctor → "New constructor"; frame-1 script →
`#1065`. F2 → load abc1 (deferred!), resolve `C` → script 3 init → "C"; then
abc1's eager last script → "Z". F3 → resolve `B` → script 2 init → "B".
**6/6.**

`_goto` is the same movie driven through `gotoAndStop`, which is why Ruffle
needs the second call site (`movie_clip.rs:1749`). Its actual @HEAD has two
extra symptoms — a spurious `Test` line and
`#1065: Variable e is not defined` inside the catch handler. Both are
downstream of the same root cause: because we load abc1 at boot, its script
traits are already in the domain, so the frame-1
`getDefinitionByName("Test")` **succeeds** (triggering `Test`'s script init →
"Test") instead of throwing, and the try-body then takes a path it should never
take. Deferring abc1's *load* to frame 2 removes the domain entry at frame 1
and the probe throws the expected `Variable Test is not defined`. High
probability the whole `_goto` diff collapses; treat the `e` line as a
*consequence*, not a second defect, but **re-measure before claiming +1**.

`avm2/delayed_symbolclass` (not on session 10's list): our first four lines are
`SecondFrameChild`/`FourthFrameChild` class+script initializers running at
boot; expected has them at their frames (2 and 4). Same mechanism, same fix.

### Sized plan — ONE worktree agent, M, two commits

**Largest safe slice (recommended, and it is enough to flip all three
targets):** defer **only** DoABC files and SymbolClass rows that live in frames
≥ 2. Frame-1 tags keep today's exact boot behaviour (step 1 load + step 3
eager-last-script + root binding + step 4 build_stage). Blast radius is then
*provably* the 9 SWFs above — every other movie's emitted tables and runtime
path are unchanged.

Recompiler:
1. `SWFRecomp/src/abc/abc_timeline.cpp` — this is already an independent second
   pass over the raw tag stream with a root `Timeline` whose `frames.size()` is
   the current 0-based frame index (`:692-714`). Record, in that pass, the
   frame index of every tag 82/72 (plus its `Flags & 1` LAZY bit) and of every
   SymbolClass row. Emit two small additive arrays
   (`avm2_generated_abc_frames[] {frame, lazy}` and
   `avm2_generated_symbol_class_frames[]`) alongside the existing tables.
   *Alternative site:* the main loop in `swf.cpp` has `next_frame_i - 1`
   available at both tag sites (:4745, :6212), but `abc_timeline.cpp` is
   cleaner because the AVM2 timeline frame numbering already lives there.
2. Nothing in `abc_registry.c`'s existing shape needs to change → old generated
   caches stay valid modulo a `--recompile`.

Runtime:
3. New `avm2_run_frame_tags(Avm2Context*, uint32_t frame_idx)` in
   `avm2_main.c`, idempotent per frame (a bitmask = Ruffle's
   `take_eager_tags`): (a) `avm2_abc_load` every ABC whose recorded frame ==
   `frame_idx`; (b) for each SymbolClass row of that frame, resolve the class
   name through `find_root_class_globals` + `avm2_domain_find` — **look up
   only, never construct** (B8a's rule stands); (c) `avm2_script_ensure_init`
   the last script of each non-lazy ABC of that frame.
4. `runSWF_avm2` steps 1/3 become "run `avm2_run_frame_tags(ctx, 0)`" for the
   frame-0 subset only; all frame ≥ 1 ABCs are simply not loaded yet.
5. Call sites in `avm2_display.c`: in `run_frame_internal` (:1927) right after
   the per-depth queue is built and **before** removals/places drain (mirrors
   `movie_clip.rs:1438`), gated on `obj == ctx->root`; and in the goto frame
   walk (near `:2747`, the `frame_op_starts[f-1]…[f]` loop) once per walked
   frame (mirrors `movie_clip.rs:1749`).

Est. ~100 lines recompiler + ~150 lines runtime.

**Do NOT take the maximal fix in the same batch.** Making frame-1 also follow
"resolve all SymbolClass rows before the eager last-script init", and/or
honouring `LAZY_INITIALIZE`, changes which scripts get initialized at all for
up to 1572 multi-script ABCs (a symbol row naming a class in a *non-last*
script would newly run that script's initializer, emitting trace lines we do
not emit today). That half is a genuine `categories=full` gamble with no
measured target; it buys nothing the three targets need.

### Predicted flips, risk, canaries

* Predicted: **+1 certain** (`doabc_..._normal`, mechanism reproduces the
  expected 6 lines exactly), **+2 probable** (`doabc_..._goto`,
  `delayed_symbolclass`). Range **+1 … +3**.
* Mandatory canaries (all currently green, all in the 9):
  `avm2/goto_in_scene_last_frame` (**the** canary — a real eager DoABC in
  frame 2; re-measured PASS at HEAD today), `avm2/displayobject_{name,parent,
  root,visible}`, `from_shumway/timeline/timeline_loop`. Plus B8a's own
  regression set (`avm2/subclass_superclass_linked_symbol`,
  `avm2/symbol_class_conflict`) because the new symbol-resolution step sits
  next to it.
* Structural risk to watch: a frame ≥ 2 SymbolClass row must be resolved
  *before* that frame's PlaceObject for the same character executes.
  `avm2_display.c:1526/1585` resolves a placed char's class from the flat
  generated table at instantiation time, so *finding* the class is unaffected —
  only the timing of the defining script's initializer moves. That is what
  keeps the four `displayobject_*` canaries safe.
* CI: `graphics`, `categories=full` (AVM2 runtime + recompiler emission —
  standing policy), `images=false`. Recompiler is touched → local re-runs need
  `--recompile`.
* Dispositions: none of the 9 is in `ACCEPTED_DIFFS.md`,
  `RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`,
  `FLASH_BUGS_REPLICATED.md`, or any `ignored_tests.txt` (re-checked).

**GO for wave 2 this session.**

---

## Lead B9 — device fonts declared in `test.toml`

### Census (all re-measured or from baseline json @ `c4496a4c8`)

17 test.tomls in the corpus declare `[fonts.*]`; 4 also declare
`[font_sorts.*]`. Status of every one:

| Test | declares | status | note |
|---|---|---|---|
| `fonts/device_font_kerning` | TestFont | **output_mismatch 0/4** (re-measured) | **B9 target** |
| `fonts/device_font_glyph_fallback` | TestFontA/B + `font_sorts` | **output_mismatch 29/36** (re-measured) | **B9 target** |
| `fonts/device_font_list` | TestFontA/B | **output_mismatch 6/64** (re-measured) | **B9 target** |
| `avm2/edittext_device_transform_layout` | TestFont | output_mismatch 160/288 | B9 **+ 2nd mechanism**; in `avm2/ignored_tests.txt` (still counts unfiltered) |
| `visual/edittext/edittext_device_transform_basic` | TestFont | output_mismatch 12/24 | B9 **+ 2nd mechanism** |
| `visual/edittext/edittext_device_transform_metrics` | TestFont | output_mismatch 20/40 | B9 **+ 2nd mechanism** |
| `visual/edittext/edittext_device_transform_negative` | TestFont | output_mismatch 60/120 | B9 **+ 2nd mechanism** |
| `from_gnash/actionscript.all/TextField-v6/-v7/-v8` | Noto Sans | output_mismatch 467/545, 476/570, 478/571 | **NOT B9 riders — REFUTED**, see below |
| `from_gnash/misc-mtasc.all/TextFieldTest` | Noto Sans | ruffle_matched | not a font diff |
| `avm2/bitmapdata_draw`, `avm2/bitmapdata_drawwithquality`, `visual/cache_as_bitmap/text`, `visual/fonts/device-font`, `visual/fonts/leading_device_font`, `from_shumway/avm1/text-bind` | Noto Sans / Tinos / TestFontGap* | **pass** (trace) | image-axis only |

**REFUTATION (yield).** Session 10's triage listed the
`edittext_device_transform_*` trio as "*possible* riders" and the `TextField-v*`
tests were never checked. Measured: the three gnash `TextField-v6/7/8` diffs are
entirely `PASSED:`→`FAILED:` on
`TextField.prototype.hasOwnProperty('background'|'autoSize'|…)` — virtual
property placement on the prototype, **zero font content**. They declare Noto
Sans only so Ruffle's render is stable. Remove them from the B9 board.

### Mechanism — fully specified, and the target numbers are verified arithmetic

Harness: `ruffle-tests/verify_output.py` has **no** handling of `[fonts.*]` /
`[font_sorts.*]` at all (the only "fonts" occurrence, :704, is the suite-dir
name). Every declared TTF is ignored.

Runtime: `SWFModernRuntime/src/avm2/avm2_text.c::resolve_font` (:2532-2563)
tries the embedded table then falls unconditionally to **one** hard-coded
metrics-only face, `noto_device_font` (:2483: `"Noto Sans"`, em 20480,
ascent 21931, descent 5973, leading 3413). There is no name-keyed device
registry, no font-list parsing and no kerning.

Ruffle, for comparison:
* `tests/framework/src/test.rs:109-145` reads the TTF bytes and registers each
  as a **device** face keyed `FontQuery(Device, family, bold, italic)`;
  `font_sorts` builds a per-family fallback chain.
* `core/src/font.rs:246-281 FontFace::new` — `ascent = face.ascender()`,
  `descent = -face.descender()`, `leading = face.line_gap()`,
  `scale = units_per_em`.
* `core/src/html/layout.rs:563-600` — device font names are a **comma-separated
  list**; each entry is `.trim()`-ed and matched case-insensitively; the first
  family that resolves wins for the whole span. Missing glyphs do **not** walk
  the list — they walk the `font_sorts` chain of the chosen family.
* `core/src/font.rs:888-902` — `kerning_enabled = has_kerning_info() &&
  (font_type().is_device() || params.kerning)`: **device fonts always kern**,
  regardless of `TextFormat.kerning`.

Verified against the actual TTFs (fontTools):

| Test | TTF facts | expected | arithmetic |
|---|---|---|---|
| `device_font_kerning` | upem 1000, adv a/b/c/d = 1000, `kern` pairs a→b +1000, b→c −500, c→d +500 | `LM width: 50` ×2 (both kerning=false and =true) | 4×1000 + (1000−500+500) = 5000 units = 5 em × size 10 = **50** ✓ — and it only comes out right if kerning is applied for the `kerning=false` field too, i.e. font.rs:889 |
| `device_font_glyph_fallback` | TestFontA hhea 500/−500, adv a,c = 1000 (no `b`); TestFontB hhea 800/−200, adv b,c = 1500; `font_sorts.a = [a,b]` | `ascent=5 descent=5 height=10`, char0 `w=10`, char1 `x=12` | 500/1000×10 = 5 ✓; 1000/1000×10 = 10 ✓; 2+10 = 12 ✓ (char 1 uses the sort chain → TestFontB) |
| `device_font_list` | TestFontA adv a,c = 1600; TestFontB adv b,c = 1500 | `Char N is TestFontA` when `getCharBoundaries(N).width == 32`, `…TestFontB` when `== 30`, at size 20 | 1600/1000×20 = **32** ✓, 1500/1000×20 = **30** ✓. The 16 missing lines are exactly the ones we cannot emit today (Noto gives ≈11.6). |

`LineMetrics.leading` in the expected output is the **TextFormat** leading
(0), not the font's `line_gap` — do not wire the TTF line gap into it.
(`device_font_glyph_fallback` expects `leading=0` while both TTFs have
lineGap 100.)

### Sized plan — ONE worktree agent, M, three components, two commits

1. **Harness** (`ruffle-tests/verify_output.py`, ~40 lines): parse
   `[fonts.X] {family, path, bold, italic}` and
   `[font_sorts.X] {family, bold, italic, sort=[keys]}`; pass to the recompiler
   as repeatable CLI flags. Fully inert for the 4400+ tests that declare none.
2. **Recompiler** (`SWFRecomp/src/swf.cpp` + `abc/abc_timeline.cpp`, ~200
   lines): stb_truetype is already vendored and already linked
   (`SWFRecomp/lib/stb/stb_truetype.h`, used at `swf.cpp:66-111` /
   `2355-2530`), and the existing zero-glyph-DefineFont synth path already does
   *exactly* TTF → code table + advance table + ascent/descent (+ flattened
   outlines at :2417-2527). Reuse it per declared face and emit a new
   `avm2_generated_device_fonts[] (Avm2FontData)` + a kern-pair table + a
   font-sort table. `Avm2FontData`
   (`SWFModernRuntime/include/avm2/avm2_abc.h:394-416`) already carries name,
   bold/italic, em_square, ascent/descent/leading, codes, advances and optional
   outlines — **no struct redesign needed**, only a kern side-table.
3. **Runtime** (`avm2_text.c::resolve_font` + the layout loop, ~150 lines):
   on the device path, split the format font name on `,`, trim, match
   case-insensitively against `avm2_generated_device_fonts`; first hit wins;
   full miss → today's `noto_device_font`. Per-glyph fallback via the sort
   chain. Apply kerning unconditionally for device faces.

**Two implementation gotchas that will silently produce wrong numbers:**
* `stbtt_GetGlyphKernAdvance` (`stb_truetype.h:2610`) prefers **GPOS** over
  `kern` (`if (info->gpos) … else if (info->kern) …`). Ruffle reads the `kern`
  table only (`font.rs:261-269, 327-340`). `device_font_kerning`'s TTF happens
  to carry identical values in both, so it passes either way — but use
  `stbtt__GetGlyphKernInfoAdvance` (kern-only) to match Ruffle for anything
  else.
* `stbtt_GetFontVMetrics` returns raw hhea. ttf_parser (`lib.rs:1499-1580`)
  falls back to OS/2 typo, then OS/2 win, **when the hhea value is 0** — which
  fires on `device_font_kerning`/`device_font_list`'s TestFont(A) whose
  `hhea.descender` is 0 but `OS/2.sTypoDescender` is −200. Replicate that
  ladder.

### Predicted flips, risk, canaries

* **+3 trace, high confidence**: `fonts/device_font_kerning`,
  `fonts/device_font_glyph_fallback`, `fonts/device_font_list` — every expected
  number is reproduced by the arithmetic above.
* **No flip** for the four `edittext_device_transform_*` tests from B9 alone.
  They need a **second, separate mechanism** (see below); B9 alone converts
  their scale-1 rows to matching and leaves the scaled rows wrong — a
  line-count improvement with no status change.
* Risk is naturally gated: with no declared fonts the generated device table is
  empty and `resolve_font` behaves byte-identically. The only unconditional
  change is the comma-split, which is a no-op against an empty table.
* Canaries: the 6 currently-`pass` font-declaring tests
  (`avm2/bitmapdata_draw`, `avm2/bitmapdata_drawwithquality`,
  `visual/cache_as_bitmap/text`, `visual/fonts/device-font`,
  `visual/fonts/leading_device_font`, `from_shumway/avm1/text-bind`) plus
  `from_gnash/misc-mtasc.all/TextFieldTest` (`ruffle_matched` — must not become
  `pass`-shaped noise or regress) and a handful of plain AVM2 EditText tests.
* **Pixel-axis note for the graphics agents:** these tests all declare *device*
  fonts, and once real metrics land, `visual/fonts/device-font`,
  `visual/fonts/leading_device_font` and `fonts/device_font_kerning`'s
  `output.expected.png` comparisons will shift. Rendering device glyph
  *outlines* is still T3 (`wave1-gfx-text-phase.md §A.3`) — B9 buys metrics,
  not pixels. Expect image-comparison churn; images do not gate pass/fail.
* Dispositions: none of the B9 targets is in any disposition doc.
  `avm2/edittext_device_transform_layout` is in `avm2/ignored_tests.txt`
  (filtered-only; the unfiltered 4424 denominator still counts it).

**GO for wave 2 this session** (fonts trio only).

### Adjacent, fully-specified, cheap: the device-font layout scale

Not part of B9 as chartered, but it is the *other half* of the four
`edittext_device_transform_*` tests (220 diff lines) and it is now pinned:

`core/src/display_object/edit_text.rs:767-770`
```rust
fn device_font_scale_x(self) -> f32 { let m = self.local_to_global_matrix(); m.d / m.a }
```
used by `layout_to_local_matrix` (:774-790), `local_width_to_layout_width`
(:802-808) and `layout_width_to_local_width` (:810-817). Device text cannot be
scaled independently in x/y, so the layout space is pre-divided by `m.d/m.a`.

Check against `edittext_device_transform_basic`'s expected output: scaleX=1 →
`w=8`; scaleX=2 → `w=4` (8 × 1/2); scaleX=1,scaleY=2 → `w=16` (8 × 2/1);
scaleX=2,scaleY=2 → `w=8`. Exact match. Our output is a constant `w=6`
(Noto) at every scale — both mechanisms missing.

This is ~40 lines in `avm2_text.c`'s layout/`getCharBoundaries`/
`getLineMetrics` conversions, no-op whenever `a == d` (all uniformly-scaled
text), and only gradeable once B9's fonts land. **Recommendation: give it to
the same wave-2 agent as a second commit** — +4 more tests
(`avm2/edittext_device_transform_layout`,
`visual/edittext/edittext_device_transform_{basic,metrics,negative}`) for a
combined B9 ceiling of **+7 trace / ~354 diff lines**, the largest single
line-count on the trace board.

---

## Wave-2 dispatch recommendation

| Batch | Agent | Files | Predicted | CI |
|---|---|---|---|---|
| B8b (safe slice) | 1 worktree | `abc_timeline.cpp`, `avm2_main.c`, `avm2_display.c` | +1 … +3 | graphics, `categories=full` |
| B9 + device-font scale | 1 worktree | `verify_output.py`, `swf.cpp`, `abc_timeline.cpp`, `avm2_text.c` | +3 … +7 | graphics, `categories=full` |

The two batches are disjoint except that both touch `abc_timeline.cpp`
(B8b adds frame arrays, B9 adds a device-font table) — different emit
functions, but sequence them or expect a trivial merge. Both touch the
recompiler → every local verification needs `--recompile`.
