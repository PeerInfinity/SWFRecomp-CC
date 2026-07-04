> **AUDIT OUTCOME (2026-07-04):** Phase A implemented (compile-time glyph synthesis); residual garble = accepted font-file-mismatch diff.

# Device-Font Rendering — `_sans` / `_serif` / `_typewriter`

**Document Version:** 0.1

**Created:** 2026-05-14

**Status:** ✅ Phase A implemented (compile-time glyph synthesis from a bundled
NotoSans via stb_truetype). The driving `text-bind` diff is now an **accepted
diff**, not a blocker. See the status banner below. Phases B/C (runtime glyph
shapes / full Unicode rasterization) remain future work.

> **STATUS UPDATE 2026-06-02 — read before treating this as open.**
>
> Phase A landed: `swf.cpp` synthesizes glyph outlines for zero-glyph
> `_sans`/`_serif`/`_typewriter` fonts from the bundled
> `SWFRecomp/assets/NotoSans.ttf` (`g_device_font` via `stb_truetype`), and
> those glyphs now tessellate via libtess2 (`a0e5d431d`).
>
> **The original driver — `from_shumway/avm1/text-bind` rendering "blocked" /
> "garbled" — is RESOLVED as an accepted device-font-fixture diff** (root-caused
> 2026-06-02; `0d504cea5` updated `ACCEPTED_DIFFS.md` + `ignored_tests.txt`).
> Our synthesized device-font layout **matches Ruffle's default fallback** (their
> bundled `notosans.subset.ttf.gz` is byte-identical to our `assets/NotoSans.ttf`,
> 1.069 em). `text-bind` diverges only because that test ships its OWN custom
> NotoSans subset (0.7656 em) + a `fonts.conf` that Ruffle's oracle honors and we
> don't resolve at recompile time → ~14px vertical offset. The
> `textfield_glyph_render_cb` baseline math (`y = field_top + ascent*scale +
> gutter`) is correct; **do not "fix the ascent"** (that was measuring against the
> test's custom-font oracle, not Ruffle's default).
>
> Full root-cause: `tools/divergence/PROGRESS.md` follow-up **#12** and the
> `tessellation-libtess2-migration` auto-memory. The Phase B/C design below is
> still valid as future work (e.g. real Unicode coverage).

Driven by `from_shumway/avm1/text-bind` investigation
(`.claude/next-session-prompt.md` 2026-05-13 entry:
"variable-bound TF now reaches render path … Visual
rendering still blocked on device-font support
(`_sans` → NotoSans.ttf)").

---

## Table of contents

1. [Executive summary](#executive-summary)
2. [Symptom that motivated this plan](#symptom-that-motivated-this-plan)
3. [Reference behavior — Flash / Ruffle](#reference-behavior--flash--ruffle)
4. [Current state — SWFRecomp](#current-state--swfrecomp)
5. [Gap analysis](#gap-analysis)
6. [Phase A — Compile-time ASCII synthesis for zero-glyph fonts](#phase-a--compile-time-ascii-synthesis-for-zero-glyph-fonts)
7. [Phase B — Built-in runtime glyph shapes (ASCII baked into runtime)](#phase-b--built-in-runtime-glyph-shapes-ascii-baked-into-runtime)
8. [Phase C — Runtime TrueType rasterization (Unicode)](#phase-c--runtime-truetype-rasterization-unicode)
9. [Test strategy](#test-strategy)
10. [Risk register](#risk-register)
11. [Open questions](#open-questions)

---

## Executive summary

SWFs can declare a font by *name only* — `DefineFont3` (or
`DefineFont2`) with `name="_sans"` (or `_serif` /
`_typewriter`) and an empty `<glyphs/>` table. Flash and
Ruffle both interpret this as "render with a host system
font of this family"; in test mode Ruffle uses a configured
TTF (e.g. `NotoSans.ttf`, declared in `test.toml` under
`[default_fonts]` / `[fonts.*]`). We emit `tagDefineFontInfo`
for the name but produce **zero glyph shapes**, so the
runtime falls back to the built-in Noto Sans (advance widths
only, no triangles) and `textfield_glyph_render_cb` exits
with `g_size == 0` for every glyph — nothing is drawn.

The plan is sequenced cheapest-first:

- **Phase A — Compile-time ASCII synthesis.** Extend the
  existing `SWFRECOMP_DEVICE_FONT_FALLBACK` path in the
  recompiler to also fire on zero-glyph `DefineFont2/3`
  whose name is non-empty. Seed `font_code_tables[font_id]`
  with ASCII 32..126, harvest advances + vertical metrics
  from `NotoSans.ttf` via `stb_truetype`, then run the
  existing tessellation loop. Smallest possible delta; fixes
  the single image-comparison test that exercises this path;
  zero runtime changes.
- **Phase B — Built-in runtime glyph shapes.** Pre-bake
  the same 95 ASCII Noto Sans glyph triangles into
  `ng_shared.c` next to the existing advance table.
  Extend `textfield_glyph_render_cb` to read shape bytes
  from the baked-in array when font lookup resolves to the
  built-in font. Lets the runtime cover dynamic
  `createTextField` / runtime-set strings without re-running
  the recompiler. Still ASCII-only.
- **Phase C — Runtime TrueType rasterization.** Bundle
  `stb_truetype` into the runtime, ship `NotoSans.ttf`
  alongside the runtime binary, rasterize/tessellate glyphs
  on demand at first use, cache by codepoint. Full Unicode
  support; matches Ruffle's runtime model. This is the
  *eventual* destination — Phases A/B are bridges that fix
  test parity sooner.

Phases A and B are recompiler-only / runtime-only and don't
depend on each other; they could land in either order, or A
alone could ship and stay in place if Phase C is prioritized
next. Phase C subsumes both: when it lands, the synthesized
ASCII glyphs from A become redundant (could be removed in a
follow-up) and the built-in advance/shape tables from B
become a startup-cost optimization (could be kept or
dropped).

---

## Symptom that motivated this plan

`from_shumway/avm1/text-bind` (run mode `graphics`):

- Trace: empty `output.txt`, our actual is empty → PASS.
- Image: `output.expected.png` shows "SUCCESS" in magenta
  (`#d662c6`) at size 42; our `output.actual.png` is
  completely blank; `output.difference.png` shows exactly
  the expected glyph outlines as the delta. 1378 outliers
  exceed limit of 100, max difference 158.

The SWF contains:

- `DefineFont3 objectID=1 name="_sans"` with empty
  `<glyphs/>` (pure device-font reference).
- `DefineEditText objectID=2` (`fontRef=1`, color
  `#d662c6`, size 42, `variableName="_root.testField"`,
  initialText `<font face="_sans" size="42" …>FAILED</font>`).
- `DoAction`: `this.testField = "SUCCESS"`.
- `PlaceObject2` at depth 1, then 5 `ShowFrame`s, then
  replace at frame 5.

Phase A/B/C of the [textfield variable binding plan][1]
(landed 2026-05-13) makes the orphan TextField walk pick up
the placement and resolve `_root.testField` → "SUCCESS".
The glyph callback receives `font_id = 1`. `ng_find_font_with_metrics(1)`
correctly falls back to the built-in Noto Sans (no metrics
on font 1 → fallback to `font_id == 0`, built-in). The
built-in's code table contains 'S' at index 51. But the
glyph *shape* lookup at `tag.c:2766` reads
`glyph_data[4 * 51]` — and this SWF's `glyph_data` array
is `glyph_data[1][1]` (zero glyphs emitted by the
recompiler), so the read returns zero. `g_size == 0` →
nothing is rendered.

[1]: textfield-variable-binding-plan.md

---

## Reference behavior — Flash / Ruffle

### Flash Player

Per SWF spec 19 §11 ("DefineFontInfo"): `_sans`,
`_serif`, `_typewriter` are reserved aliases the player
maps to the host system's sans-serif, serif, and
monospace fonts respectively. The player rasterizes glyphs
from the host font at render time, with metrics drawn from
the host font's TTF tables. A `DefineFont3` with `name="_sans"`
and empty glyphs is a valid way to declare "use a system
sans font for any DefineEditText that points at me".

### Ruffle

`ruffle/core/src/font.rs`: `Font` has variants for
`Embedded` (SWF-provided glyphs) and `Device` (host-font
delegation). Each variant carries its own glyph rasterizer.

`ruffle/render/wgpu/src/backend.rs::draw_text` calls into
the glyph rasterizer; for `Device` it goes through the
backend's text shaping (cosmic-text, fontdb, etc.).

For tests, Ruffle's test runner registers
`default_fonts.sans` / `default_fonts.serif` /
`default_fonts.typewriter` (from `test.toml`) into the
text engine before running the SWF. The `text-bind` test's
`test.toml` ships:

```toml
[default_fonts]
sans = ["Noto Sans"]

[fonts.noto_sans]
family = "Noto Sans"
path = "NotoSans.ttf"
```

So `_sans` → Noto Sans family → the per-test `NotoSans.ttf`
file. Ruffle rasterizes "SUCCESS" using that font and
matches the expected image.

### Key semantics

- **Device-font resolution is per-render-frame, not per-tag.**
  Flash doesn't bake `_sans` glyphs into the SWF; it draws
  them fresh every frame from whatever system font is
  current. (Implication for us: a static
  compile-time-baked glyph set is a fine approximation as
  long as the strings stay within the baked range.)
- **Unicode coverage matches the host font.** Real Flash on
  desktop renders any Unicode codepoint Noto Sans (or the
  host equivalent) supports. Tests in our suite that
  exercise this are rare and would be the trigger for
  Phase C.
- **Metrics matter for layout.** Even when individual
  glyphs are missing, the text engine still uses ascent /
  descent / advance to position the caret, draw the
  selection bar, etc. We already approximate this through
  the built-in font's advance table, which is why earlier
  TextField tests pass on trace despite the empty render
  path.

---

## Current state — SWFRecomp

Refs: `SWFRecomp/src/swf.cpp` (font tag parsing + device
font fallback), `SWFModernRuntime/src/libswf/ng_shared.c`
(font registry + built-in Noto Sans advance table),
`SWFModernRuntime/src/libswf/tag.c::textfield_glyph_render_cb`
(glyph render path).

### Recompiler

- `SWF_TAG_DEFINE_FONT_2` / `SWF_TAG_DEFINE_FONT_3`
  (`swf.cpp:1714`):
  - Parses flags, font name, `num_entries`.
  - When `num_entries > 0`, reads the glyph offset table,
    interprets each glyph's shape (filling `font_glyph_entries`
    with `(tri_offset, tri_size)`), reads the code table
    (filling `font_code_tables[font_id]`), reads the
    optional layout section (filling `font_advance_tables[font_id]`
    + ascent / descent / leading).
  - **When `num_entries == 0`, none of the above runs.**
    `font_code_tables[font_id]` is never created.
- Device-font fallback (`swf.cpp:1908`):
  - Gated on `font_code_tables.count(font_id) &&
    deviceFontFallbackEnabled() && loadDeviceFont()`.
  - Both gates fail for zero-glyph fonts: the count check
    is false, and `SWFRECOMP_DEVICE_FONT_FALLBACK` is
    default-off.
  - Iterates `num_entries`, fills `font_glyph_entries[i]`
    triangles from stb_truetype + earcut for any glyph
    whose `second == 0`.
- `SWF_TAG_DEFINE_FONT_INFO` (`swf.cpp:2787`): no-op
  (`cur_pos += tag.length; break;`).
- Emit (`swf.cpp:2070`):
  - `tagDefineFontInfo(app_context, id, name, bold, italic)`
    always emitted when `font_names[font_id]` exists.
  - `tagDefineFontMetrics(...)` and `tagDefineFontGlyphBase(...)`
    only emitted when `font_advance_tables[font_id]` and
    `font_code_tables[font_id]` both non-empty (gated at
    `swf.cpp:2096`).

### Runtime

- `ng_record_font(font_id, name, bold, italic)`
  (`ng_shared.c:446`): appends to `ng_fonts[]` with
  `has_metrics = 0`.
- `ng_record_font_metrics(font_id, ascent, descent, leading,
  em_square, code_table, advance_table, glyph_count)`
  (`ng_shared.c:458`): sets `has_metrics = 1` and copies
  tables.
- `ng_ensure_builtin_font` (`ng_shared.c:359`): on first
  use, registers a built-in font at `font_id = 0` named
  "Noto Sans" with the hard-coded advance table for ASCII
  32..126. **No glyph shapes** — the `code_table` /
  `advance_table` are populated but the rendering pipeline
  reads triangles from the per-SWF `glyph_data` /
  `shape_data` arrays, which the built-in doesn't
  participate in.
- `ng_find_font_with_metrics(font_id)` (`ng_shared.c:394`):
  if `font_id` is missing or has no metrics, falls back
  to the built-in.
- `textfield_glyph_render_cb` (`tag.c:2519`): uses
  `font_idx` to look up advance / metrics, but reads
  triangles from `glyph_data[4 * global_idx]` /
  `shape_data[g_offset + v]` — both of which are SWF-baked
  arrays, indexed via `glyph_base + glyph_idx`.

The runtime side is already permissive: it asks for a font,
gets a fallback when the requested one has no metrics,
proceeds with layout using fallback advance widths. The
breakage is only in glyph shape access, which has no
fallback path. Phase A fixes this by ensuring the
*recompiler* emits a real glyph entry for the requested
font_id; Phase B fixes it by giving the *runtime* its own
glyph shape source; Phase C replaces both with on-demand
rasterization.

---

## Gap analysis

| Behavior | Flash / Ruffle | SWFRecomp | Effect |
|---|---|---|---|
| Zero-glyph `DefineFont2/3` registered | Yes (named device-font ref) | Yes (`font_names[font_id]` set, nothing else) | Font name visible to scripts |
| ASCII glyph shapes available at render | Yes (host system font) | **No** (`glyph_data` empty) | Blank canvas for any text using this font |
| Non-ASCII glyph shapes available | Yes (full Unicode via host font) | **No** | Latin-only tests possibly affected; CJK definitely fails |
| Per-glyph advance widths | Yes (host font metrics) | Built-in advance table fallback | Layout positions roughly correct; tab stops, hit-test bounds approximate |
| Vertical metrics (ascent / descent / leading) | Yes (host font tables) | Built-in metrics fallback | Baseline / line-height roughly correct |
| Runtime `createTextField` + dynamic text | Renders via host font | Renders nothing (same glyph-data gap) | All `createTextField` tests that render text are affected; we currently rely on those tests not having image expectations |
| Variable change → TF text → glyph rerender | Yes (re-rasterizes from host font) | No glyph data to draw | Bound-variable changes don't render even if bytes update |

Phase A closes rows 2, 5, 6 (for the static-glyph-set
intersection) and row 7 (within ASCII). Phase B extends
row 6 to dynamic `createTextField`. Phase C closes row 3.

---

## Phase A — Compile-time ASCII synthesis for zero-glyph fonts

**Goal:** every zero-glyph `DefineFont2/3` with a non-empty
name produces a full ASCII 32..126 glyph set (shapes,
advances, ascent / descent / leading) drawn from
`NotoSans.ttf` via the existing stb_truetype + earcut path.

**Scope:** recompiler only (`SWFRecomp/src/swf.cpp`). No
runtime changes. Static synthesis — the glyph set is fixed
at compile time and limited to printable ASCII (which
covers `text-bind` and matches the vast majority of test
strings in our corpus).

### Changes

1. **Detect the zero-glyph device-font case.** Right after
   the existing tag-parse block (`swf.cpp:1902`, where
   `cur_pos = font_tag_start + font_tag_length;` after the
   non-zero-glyph branch), add a synthesis pre-step:

   ```cpp
   // Phase A: device-font glyph synthesis for zero-glyph DefineFont2/3.
   // SWFs that declare a font by name only (DefineFont3 with empty <glyphs/>,
   // font name like "_sans") rely on the player providing system glyphs at
   // render time. Synthesize ASCII 32..126 from NotoSans.ttf at compile time.
   bool is_zero_glyph_synth = false;
   if ((tag.code == SWF_TAG_DEFINE_FONT_2 || tag.code == SWF_TAG_DEFINE_FONT_3) &&
       num_entries == 0 &&
       font_names.count(font_id) && !font_names[font_id].empty() &&
       loadDeviceFont())
   {
       int ttf_ascent_em = 0, ttf_descent_em = 0, ttf_linegap_em = 0;
       stbtt_GetFontVMetrics(&g_device_font, &ttf_ascent_em,
           &ttf_descent_em, &ttf_linegap_em);
       float swf_em = font_em_square.count(font_id) ? font_em_square[font_id] : 1024.0f;
       float ttf_scale = swf_em / 1000.0f;  // Noto Sans EM = 1000

       const u16 FIRST_CP = 32;
       const u16 LAST_CP  = 126;
       num_entries = LAST_CP - FIRST_CP + 1;  // 95

       font_code_tables[font_id].clear();
       font_advance_tables[font_id].clear();
       font_code_tables[font_id].reserve(num_entries);
       font_advance_tables[font_id].reserve(num_entries);
       for (u16 cp = FIRST_CP; cp <= LAST_CP; cp++) {
           font_code_tables[font_id].push_back(cp);
           int adv_em = 0, lsb = 0;
           stbtt_GetCodepointHMetrics(&g_device_font, cp, &adv_em, &lsb);
           font_advance_tables[font_id].push_back((s16)(adv_em * ttf_scale));
       }
       font_ascent [font_id] = (s16)( ttf_ascent_em  * ttf_scale);
       font_descent[font_id] = (s16)(-ttf_descent_em * ttf_scale);  // stb returns negative
       font_leading[font_id] = (s16)( ttf_linegap_em * ttf_scale);

       // Pre-fill glyph entry tracking — the fallback loop below fills triangles.
       font_glyph_entries.assign(num_entries, {0, 0});
       font_glyph_path_entries.assign(num_entries, {0, 0});

       is_zero_glyph_synth = true;
   }
   ```

2. **Drop the env-var gate for the synthetic case.** Change
   the device-font-fallback condition at `swf.cpp:1908`:

   ```cpp
   if (font_code_tables.count(font_id) &&
       (is_zero_glyph_synth || deviceFontFallbackEnabled()) &&
       loadDeviceFont())
   ```

   The env-var gate (`SWFRECOMP_DEVICE_FONT_FALLBACK`, off
   by default) was added so SWFs with deliberately-empty
   embedded glyphs render as nothing, matching Ruffle. That
   gate stays for non-synthetic cases. The synthetic case
   was never previously hit and has no compatibility risk.

3. **No emission-side changes needed.** Once
   `font_advance_tables[font_id]` and
   `font_code_tables[font_id]` are populated, the existing
   `tagDefineFontMetrics(...)` / `tagDefineFontGlyphBase(...)`
   emission (`swf.cpp:2096`) fires automatically. The
   existing glyph_data emission loop (`swf.cpp:2058`) runs
   for `num_entries = 95` and emits the synthesized
   triangles' offsets / sizes.

### Acceptance criteria

- `from_shumway/avm1/text-bind` `output.actual.png` shows
  "SUCCESS" in magenta at the correct position, passes the
  test's `tolerance = 128, max_outliers = 100` /
  `tolerance = 64, max_outliers = 600` checks.
- The 9 sibling tests that use `tagDefineFontInfo` for `_sans`
  / `_serif` / `_typewriter` (`avm1/click_block`,
  `avm1/text_blocks_clicks`, `avm1/tell_target`,
  `avm1/remove_movie_clip`, `from_gnash/misc-ming.all/DefineEditTextTest`,
  `from_shumway/avm1/lookup`, `from_shumway/avm1/textfield/textfield-text-setters`,
  `from_shumway/avm1/doactionorder/doactionorder` — all
  trace-only) stay passing.
- No regressions on the 17 graphics-passing
  `avm1/edittext_*` and `avm1/textfield_*` tests
  (representative subset).
- `tagDefineFontGlyphBase` emission position quirk
  (currently emits to `context.tag_main` not `tag_init`,
  pre-existing) stays untouched — Phase A doesn't fix it
  and runtime tolerates it.

### Out of scope

- `createTextField` rendering (no embedded font ID; runtime
  goes straight to the built-in path). Phase B.
- Glyphs outside ASCII 32..126 (CJK, accented Latin,
  symbols). Phase C.
- Bold / italic variants (stb_truetype only loads one face
  from NotoSans.ttf). Phase C, with a font collection.

---

## Phase B — Built-in runtime glyph shapes (ASCII baked into runtime)

**Goal:** the runtime can render text in its built-in font
without help from the recompiler. Covers
`createTextField`-driven TextFields whose font isn't
declared anywhere in the SWF tag stream.

**Scope:** runtime only
(`SWFModernRuntime/src/libswf/ng_shared.c`,
`SWFModernRuntime/src/libswf/tag.c::textfield_glyph_render_cb`).

### Changes

1. **Pre-bake Noto Sans ASCII triangles.** One-time
   generator script (`SWFRecomp/scripts/generate_noto_sans_baked.py`)
   runs stb_truetype + earcut on `assets/NotoSans.ttf` for
   ASCII 32..126, emits a header `builtin_noto_sans_glyphs.h`
   containing:

   ```c
   typedef struct {
       u16 tri_offset;
       u16 tri_size;
   } BuiltinGlyphEntry;

   static const BuiltinGlyphEntry builtin_noto_sans_glyph_entries[95] = { … };
   static const float builtin_noto_sans_glyph_verts[/* ~5000 */][2] = { … };
   ```

   Generated header checked in to the repo
   (`SWFModernRuntime/src/libswf/builtin_noto_sans_glyphs.h`).
   ~100KB. Generator script idempotent; no build-time
   dependency on running stb_truetype again.

2. **Extend `ng_fonts[builtin_idx]`** with optional
   `builtin_glyph_table` pointer. When non-NULL, the
   render path reads triangles from there instead of the
   per-SWF `glyph_data` / `shape_data`. Initialized in
   `ng_ensure_builtin_font`.

3. **Glyph render path switch.** In
   `textfield_glyph_render_cb`, after `font_idx` is
   resolved, check if `ng_fonts[font_idx].is_builtin`. If
   so, read `(tri_offset, tri_size)` from
   `builtin_noto_sans_glyph_entries[glyph_idx]` and verts
   from `builtin_noto_sans_glyph_verts[tri_offset + v]`
   instead of `shape_data[g_offset + v]`. Same scaling /
   color / transform logic.

4. **Phase A coexistence.** With Phase A landed, the
   recompiler emits real glyphs for the SWF's font_id and
   the render path never falls back to the built-in for
   that font_id. Phase B kicks in only for `font_id == 0`
   (built-in) cases — i.e. `createTextField` / runtime-only
   paths. Both can coexist.

### Acceptance criteria

- `createTextField` tests with rendered text content show
  glyphs in `output.actual.png` (none in the current suite
  have image expectations — Phase B is mostly a hedge for
  future tests, plus it lets us delete the static synthesis
  in Phase A if Phase C never lands).
- No regressions on Phase A's set.
- `from_shumway/avm1/text-bind` continues to pass (Phase A
  path is unchanged by Phase B).

### Out of scope

- Same as Phase A: ASCII-only, no bold / italic / Unicode.

---

## Phase C — Runtime TrueType rasterization (Unicode)

**Goal:** the runtime rasterizes glyphs from
`NotoSans.ttf` on demand at any Unicode codepoint. Matches
Ruffle's `Device` font model. *Eventual destination.*

**Scope:** runtime only. Bundles stb_truetype.h into
`SWFModernRuntime/lib/` (single-header, ~7KLOC). Ships
NotoSans.ttf next to the runtime binary (already in
`SWFRecomp/assets/NotoSans.ttf`; install to runtime asset
dir at build time).

### Changes

1. **`ng_runtime_font.c`** new module wrapping stb_truetype:
   - `ng_runtime_font_init()` — loads `NotoSans.ttf` once
     at startup. Searches paths analogous to
     `SWFRecomp/src/swf.cpp::loadDeviceFont`.
   - `ng_runtime_font_get_glyph(codepoint)` — returns
     triangles + path data, lazily tessellating on first
     access. Caches by codepoint (LRU + dense ASCII).
   - `ng_runtime_font_get_metrics()` — returns ascent /
     descent / leading / em_square.
   - `ng_runtime_font_get_advance(codepoint)` — returns
     advance width.

2. **Glyph render path uses runtime font when font_idx
   resolves to the built-in.** Same switch point as Phase B
   but with on-demand cache lookup instead of baked-in
   table. Triangle data emitted directly into the
   renderer's vertex buffer (no intermediate `shape_data`
   array required).

3. **Recompiler `loadDeviceFont` retained.** Phase A's
   recompiler-side synthesis still works (the resulting
   `glyph_data` is just unused if Phase C is also active).
   Optionally remove Phase A in a follow-up cleanup pass —
   not required.

4. **Recompiler glyph path retained for SWF-embedded
   fonts.** Phase C only affects the built-in / device-font
   render branch. Real embedded fonts (`DefineFont2/3` with
   non-zero glyphs) continue to go through the existing
   per-SWF `glyph_data` / `shape_data` arrays.

### Acceptance criteria

- All Phase A / B tests stay green.
- Tests with non-ASCII text using `_sans` (none in current
  suite; add one as a regression test) render correctly.
- Runtime memory budget stays under existing ceiling
  (NotoSans.ttf is ~1.6MB; glyph cache bounded).
- Build-time test of Phase C disabled at compile time (a
  `-DNG_NO_RUNTIME_FONT` switch falls back to Phase B's
  baked table) so resource-constrained targets aren't
  forced to ship 1.6MB of font data.

### Out of scope

- Bold / italic / multiple weights (would need
  NotoSans-Bold.ttf etc., or a font collection). Future
  Phase C+ if a test demands it.
- Subpixel anti-aliasing / hinting (stb_truetype is
  serviceable but not LCD-aware). Renderer-level concern,
  separate plan.
- Font fallback chain for missing codepoints
  (Tofu-rendering U+25A1 for missing glyphs is fine).

---

## Test strategy

Per-phase, run the **per-test** runner only (CI handles
full sweeps).

### Phase A smoke set

- **Driver:** `from_shumway/avm1/text-bind` (image, must
  pass).
- **`_sans` siblings (trace-only, must stay passing):**
  `avm1/click_block`, `avm1/text_blocks_clicks`,
  `avm1/tell_target`, `avm1/remove_movie_clip`,
  `from_gnash/misc-ming.all/DefineEditTextTest`,
  `from_shumway/avm1/lookup`,
  `from_shumway/avm1/textfield/textfield-text-setters`,
  `from_shumway/avm1/doactionorder/doactionorder`.
- **Embedded-font regression check (5-test sample, must
  stay green):** `avm1/edittext_autosize`,
  `avm1/edittext_bullet`, `avm1/edittext_html_align_swf8`,
  `avm1/edittext_font_size`, `avm1/textfield_test`.

### Phase B smoke set

- All Phase A tests (regression).
- Any `createTextField` test with image expectations
  (currently none — Phase B is forward-looking).

### Phase C smoke set

- All Phase A + B tests (regression).
- Add a non-ASCII test: place an EditText with `_sans` and
  bind a variable containing accented Latin / a CJK string;
  expect Noto Sans glyphs.

### Regression-check protocol

After each phase lands, run the per-phase smoke set, then
sweep an additional 10-test mixed battery covering text /
edittext / textfield tests. CI runs the full suite —
locally we only sample. Reset `.pipeline-state` to `idle`
only when the change is ready to push.

### CI-only validation

Full-suite numbers come from the `ruffle-tests.yml`
workflow dispatch in `--mode=graphics` and the default
mode. Phase A only affects graphics-mode rendering for
zero-glyph fonts; the default mode (`NO_GRAPHICS`)
numbers are unchanged.

---

## Risk register

| # | Risk | Phase | Mitigation |
|---|---|---|---|
| 1 | `loadDeviceFont` doesn't find `NotoSans.ttf` from the test directory (recompiler `cwd` = test dir, no `assets/NotoSans.ttf` relative path matches) | A | The `/proc/self/exe`-relative paths in `loadDeviceFont` resolve to `SWFRecomp/assets/NotoSans.ttf` regardless of cwd. Already verified for the env-var-gated path. |
| 2 | Synthetic ASCII overlaps a SWF-defined glyph at the same `font_id` and triggers a double-emit | A | Synthesis branch is gated on `num_entries == 0`. If the SWF embeds any glyphs the existing code path runs; synthesis is skipped. |
| 3 | Font size mismatch between Noto Sans (1000 EM) and SWF Font3 (20480 EM) yields incorrect glyph dimensions | A | Existing `ttf_scale = swf_em / 1000.0f` formula handles this; advance widths use the same scale. Tested in the existing env-var-gated path. |
| 4 | Stb_truetype + earcut produces visibly different glyph shapes from Ruffle's text engine (font shaping, hinting, etc.), causing image diff outliers near the tolerance threshold | A | text-bind's tolerance is generous (128 / 100 + 64 / 600). If we trip it, the diff goes into `ACCEPTED_DIFFS.md` (cf. existing `movieclip_hittest_shapeflag` entry for Noto Sans vs Flash device font outlines). |
| 5 | `font_glyph_entries` / `font_glyph_path_entries` are declared `std::vector<…>` with default-constructed empty state — pre-filling with `.assign(95, {0,0})` is safe but easy to overlook | A | Code review checkpoint. Single call site. |
| 6 | `tagDefineFontGlyphBase` emission writes to `context.tag_main` instead of `tag_init` (pre-existing quirk at `swf.cpp:2135`), so after Phase A every `_sans` SWF will get a stray `tagDefineFontGlyphBase` call in the middle of a frame_func | A | Pre-existing. The runtime handler is order-tolerant. Phase A only exposes it more often; doesn't introduce it. Consider fixing in a follow-up. |
| 7 | Generator script for Phase B drifts from the recompiler's stb_truetype+earcut path → built-in font glyphs render slightly differently from Phase A's synthesized ones | B | Share the tessellation routine between the recompiler and the generator (extract to a header in `SWFRecomp/lib/`). |
| 8 | Phase C runtime stb_truetype increases startup latency on cold cache | C | Lazy per-codepoint init. Defer NotoSans.ttf load until first device-font render request. ASCII commonly used → first few glyphs warm the cache. |
| 9 | Phase C NotoSans.ttf bundling bloats runtime binary (1.6MB) | C | Compile-time switch `-DNG_NO_RUNTIME_FONT` (falls back to Phase B baked table, ASCII-only). Default on; embedded / WASM builds can disable. |
| 10 | `_sans` vs `_serif` vs `_typewriter` should map to *different* font files. Phase A always uses NotoSans regardless of declared name | A, B, C | Acceptable for current corpus (all `_sans`); reopen if a `_serif` / `_typewriter` test surfaces. Phase C is the natural place to add a font-name-to-file mapping. |

---

## Open questions

- **OQ-1.** Does Ruffle's test runner honor the `[fonts.*]`
  table from `test.toml` strictly (only Noto Sans is
  available for `_sans`) or fall back to host fonts if no
  entry is provided? Phase A assumes Noto Sans is *always*
  the right answer. If Ruffle's test runner falls through
  to host fonts on test.toml miss, we may produce
  unexpected diffs on tests with no `[fonts.*]` entry.
  Verify by sampling a couple of `_sans` tests with no
  font config.

- **OQ-2.** Should Phase A's synthesis trigger on `_sans`
  / `_serif` / `_typewriter` only, or any zero-glyph
  font with a name? Current draft says "any non-empty
  name". If an SWF declares a custom-named device font
  ("Helvetica" with empty glyphs, expecting host
  Helvetica), Phase A would substitute Noto Sans, which
  may visibly differ. Lower risk than not rendering at
  all; flag in `ACCEPTED_DIFFS.md` if it bites.

- **OQ-3.** Phase B vs Phase C choice — do we want to land
  Phase B at all, or skip it and jump from A → C? Phase B
  duplicates Phase C's coverage for ASCII at the cost of a
  generator script + a baked header file. If Phase C lands
  quickly, Phase B is just dead weight. Recommendation:
  defer Phase B; land A, then C when prioritized; skip B
  unless C is blocked for >1 release.

- **OQ-4.** Should the synthesized advance widths match
  Ruffle's rendered text exactly? Differences propagate to
  bounding-box / hit-test results (cf. existing
  `ACCEPTED_DIFFS.md::movieclip_hittest_shapeflag`). Phase
  A doesn't change this; we'll keep accepting the existing
  diff entry.

- **OQ-5.** What's the right place for the
  recompiler-side stb_truetype loader given Phase C will
  also need one in the runtime? Possible refactor: lift
  `loadDeviceFont` + the tessellation routine into a
  shared `lib/font_utils.{h,c}` consumed by both sides.
  Not blocking — independent cleanup if it pays off.

---

## Sequence

Phase A first — smallest delta, unblocks the only
image-comparison test that exercises this path, zero
runtime changes. Phase C is the eventual destination
(per user note); land it when prioritized. Phase B is
**optional** — only worth doing if Phase C is delayed
and a future test exercises runtime-only device-font
rendering. If Phase A reveals issues (image tolerance
trips, glyph shape mismatch with Ruffle, etc.), capture
in the test's `ACCEPTED_DIFFS.md` entry; don't bloat
Phase A scope to chase exact pixel parity.
