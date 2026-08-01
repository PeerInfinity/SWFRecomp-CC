# w2-singles — wave-2 batches B2 / B3 / B6

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a4878af5fe2239f2a`
(base `b007ee50d`). Patch: `w2-singles.patch` (2 files, +137 / −26).
No commits, no pushes. All runs are default no-graphics unless noted.

Files touched:
- `SWFModernRuntime/src/avm2/avm2_text.c` — B2 (`style_transform`, `ss_transform`)
- `SWFModernRuntime/src/avm2/avm2_display.c` — B3 (`statictext_get_text` +
  registration), B6 (`doc_get_objects_under_point` walk)

---

## Ledger — targets

| Batch | Test | Baseline (re-measured) | After | Δ |
|---|---|---|---|---|
| B2 | `avm2/stylesheet_parse_color` | output_mismatch (4 lines) | **pass** | +1 |
| B2 | `avm2/stylesheet_transform` | output_mismatch (4 lines) | **pass** | +1 |
| B3 | `avm2/statictext_text` | output_mismatch (8/8 lines `undefined`) | **pass** | +1 |
| B3 | `from_shumway/acid/acid-text-2` | output_mismatch (1 line) | **pass** | +1 |
| B6 | `from_shumway/hittesting/hittesting` | output_mismatch (2 lines) | **pass** (full, not ruffle_matched) | +1 |
| B6 (bonus, not a listed target) | `from_shumway/getobjectsunderpoint` | output_mismatch | **ruffle_matched** | +1 |

Predicted +5, measured **+6**. All re-measured with an explicit `--tests-dir`
and `--recompile`.

---

## B2 — CSS StyleSheet value parsing (+2)

**Four** sub-fixes in `avm2_text.c`, not the three in the brief — the fourth
(`fontFamily`) only surfaced once the suite-ambiguity trap was cleared and the
*real* `avm2/stylesheet_transform` was measured. All verified against Ruffle's
`avm2/globals/flash/text/style_sheet.rs` + `StyleSheet.as`:

1. **Hex colour is trim-then-cap, not cap-then-hex.** The old gate was
   `cs->len <= 7` *and* every remaining char a hex digit. Ruffle's
   `inner_parse_color` is `strip_prefix('#')` → **`trim_end()`** →
   `len <= 6` → `u32::from_str_radix(16)` whole-string. The failing values are
   `#ff0000 ` / `#ff0000\t ` (a CSS declaration keeps the value's trailing
   whitespace), which the length cap rejected. The *spec brief said "parseInt
   semantics, no length cap"* — that is wrong and would have broken the
   `#6666666 → 0` and `#ff0000 0 → 0` lines. Trailing-trim + a 6-digit cap is
   what the oracle actually encodes, and it satisfies all 23 cases.
2. **Unrecognised `display` clears the field.** `StyleSheet.as` does a plain
   `result.display = formatObject.display`, and TextFormat's `display` setter
   drops the field on an unknown value — so `display: "invalid"` must read
   back `null`, not `format_default()`'s `"block"`. Added the `else
   f.present &= ~TFP_DISPLAY` arm (same idiom already used at `avm2_text.c:584`).
3. **`transform(<truthy non-object>)` throws #1069.** `StyleSheet.as` guards
   only `if (!formatObject) return null;` and then *reads* `formatObject.color`
   — on a sealed receiver (the test passes `5`) that raises #1069. Old code
   returned `null` for anything that was not an object. Now: falsy → `null`
   (covers `null`/`undefined`/`0`/`""`), truthy non-object → `avm2_throw_1069`.
4. **`fontFamily` must DROP empty list entries, separator included.** Not in
   the brief. `"a b c, d e   f  ,  ,  g h"` must rejoin as
   `"a b c,d e   f  ,g h"`; we emitted `"...,,g h"`. Ruffle's
   `html/style_sheet.rs::parse_font_list` writes the `','` only when the
   accumulator is already non-empty, and appends only non-empty values. Our
   loop unconditionally emitted a separator per iteration. Restructured to
   map-then-test-then-emit (leading-space trim and trailing-space retention
   are unchanged — `"d e   f  "` keeps its trailing spaces, and the oracle
   pins that).

**AVM1 parity: deliberately NOT changed.** The brief asked to mirror the hex
fix into `action.c:16157 stylesheetTransform`. Ruffle implements AVM1 and AVM2
colour parsing *differently on purpose*: `avm1/globals/style_sheet.rs`
`parse_color` requires **exactly 6** hex digits with **no trim**
(`if stripped.len() != 6 { return None }`). Our AVM1 copy already matches that
(`cv->str_size == 7`). Porting the AVM2 trim into AVM1 would have been a
regression against `avm1/stylesheet*`. Noted here instead of applied.

## B3 — `StaticText.text` (+2)

`flash.text.StaticText` had no `text` getter, so all reads were `undefined`.
Implemented as a glyph walk over the already-emitted recompile tables:
`Avm2StaticTextData{char_id, glyph_start, glyph_count}` →
`avm2_generated_static_glyphs[]` → `Avm2FontData.codes` (glyph index →
character code), UTF-8 encoded.

Ported Ruffle's `display_object/text.rs::Text::text` rules exactly, and the
test's expectations pin each one:
- glyph whose `font_id` is absent from the font table → the **whole** walk
  yields `null` (Ruffle's `get_font(font_id)?`), even for glyphs already
  collected — `statictext_text` lines 3/4/7/8 are exactly this case
  (font ids 0 and 50 do not exist in the movie);
- glyph index past the font's `glyph_count` → skipped;
- empty result (no glyphs, or the placed char is not a DefineText — one of the
  8 fields has no `Avm2StaticTextData` at all) → `null`, not `""`;
- `codes == NULL` (device-fallback font, no code table) → `null`.

Registration is `add_getset(ctx, statictext, "text", statictext_get_text, NULL)`
— getter only, no setter (StaticText.text is read-only).

## B6 — `getObjectsUnderPoint` and SimpleButton (+1, full pass)

**The brief's diagnosis was inverted, and it matters.** The claim was "the
hitTestState child is being reported". Re-measuring the baseline showed the
opposite: the two failing lines are the `length === 1` / `length === 2` ones
(a point over the **up** state), and the `length === 0` lines over the
hitTestState-only point were *already* green. A SimpleButton's state children
live in `btn_up`/`btn_over`/`btn_down`/`btn_hit`, **not** `render_list`, and a
button's own self-bounds are empty — so the walk reported *nothing at all* for
buttons.

First attempt (reverted): a `SimpleButton` branch in `hit_test_shape_obj`
delegating to `btn_up`, i.e. a faithful port of Ruffle's
`avm2_button.rs::hit_test_shape`. That reports the **button node**, which gives
`length == 1` for both buttons → scored `ruffle_matched`, because Ruffle has
the same bug (its own `// FIXME: different result at
from_shumway/hittesting/hittesting "two-layer button"` sits in
`display_object_container.rs:510`).

Landed fix: in `doc_get_objects_under_point` only, push the **current-state
child subtree** (`btn_up`) onto the walk stack. Flash reports the leaf
graphics, not the button:
- one-layer button → its single Shape → `length == 1`;
- two-layer button → the wrapper Sprite has no graphics of its own (not
  reported) and its two layers are → `length == 2`;
- `btn_hit` is never pushed → the hitTestState-only point still yields 0.

All 18 lines match → **full `pass`**, strictly better than `ruffle_matched`.
`hit_test_shape_obj`, `mouse_pick`, and every button render/state path are
untouched.

---

## Canary results

**107 tests run, 105 `pass` + 2 `ruffle_matched`, 0 fail — zero regressions.**

| Group | n | Result |
|---|---|---|
| `regression` suite (ALL of it) | 70 | 70 pass |
| `avm2` CSS/StyleSheet (`stylesheet`, `stylesheet_parse_color`, `stylesheet_transform`, `edittext_stylesheet{,_custom_tag,_display}`) | 6 | 6 pass |
| `avm1` CSS/StyleSheet (`stylesheet`, `stylesheet_transform`, `edittext_stylesheet`) + `from_shumway/stylesheet` | 4 | 4 pass |
| `avm2` StaticText (`static_text`, `statictext_text`) | 2 | 2 pass |
| `avm2` hit-test / picking (`button_hittest`, `displayobject_hittest{object,point,point_root}`, `movieclip_hittest`, `hittest_morph`, `bitmapdata_hittest`, `mouse_pick_*` ×6) | 13 | 13 pass |
| `avm2` `simplebutton_*` | 12 | 12 pass |
| `avm2/displayobjectcontainer_getobjectsunderpoint` | 1 | pass |
| `from_shumway` (`hittesting/{hittesting,mask-hit-test}`, `getobjectsunderpoint`, `avm1movie`, `acid/acid-text{,-2}`) | 6 | 4 pass + 2 ruffle_matched |

Both `ruffle_matched` rows match their pre-existing baseline status
(`from_shumway/avm1movie` was already `ruffle_matched`;
`from_shumway/getobjectsunderpoint` **improved** from `output_mismatch` — see
below).

### Bonus: `from_shumway/getobjectsunderpoint` also flips (+1, unclaimed)

Not a listed target. Baseline `output_mismatch`; B6 takes it to
`ruffle_matched`. Its `output.txt` independently confirms the B6 model —
"*button's up state is hit, but not the parents: count: 1 / elements:
[object Shape]*". (It does not reach a full `pass`: it also asserts
`hits[0].parent: null`, and we set the up-state child's `parent` to the button
in `button_construct_states`. Separate mechanism, left alone.)

### Graphics-mode spot checks

`--mode=graphics` (native Dawn, `~/CC/dawn-install`):
`avm2/statictext_text` **pass**, `from_shumway/hittesting/hittesting` **pass**.
Mode parity holds.

### Two harness traps hit while canarying — worth recording

1. **`--test=NAME` without `--tests-dir` silently picks the wrong suite.**
   My first "pass" for `stylesheet_transform` was **`avm1/stylesheet_transform`**
   (that test exists in avm1 *and* avm2, and the AVM1 one was already green).
   The real `avm2/stylesheet_transform` was still failing at that point. Every
   number in this report was re-measured with an explicit `--tests-dir`.
   (Memory `verify-test-name-suite-ambiguity` — it bit again.)
2. **Copied test dirs carry stale `RecompiledABC`.** 10 canaries reported
   `compile_fail`, reproducible sequentially, with `ld returned 1`. Not a
   parallel-load artifact and not a real build break: the dirs copied from the
   main tree predate `avm2_movie_tables.c` and therefore define neither
   `avm2_generated_statictexts` nor `avm2_generated_static_glyphs`. B3's getter
   is the first *unconditional* (NO_GRAPHICS-visible) reference to
   `avm2_generated_static_glyphs`, which turned a latent staleness into a link
   error. All 10 pass with `--recompile`; fresh recompiler output always emits
   the dummy `avm2_generated_static_glyphs[1]` (`abc_timeline.cpp:2192`), so CI
   is unaffected.

---

## Merge risks / notes for the integrator

- **B6 vs `w2-button`**: the only `avm2_display.c` hunk B6 adds is inside
  `doc_get_objects_under_point` (a 19-line block appended after the existing
  `render_list` push loop). It reads `ext->btn_up` and
  `ctx->builtins.simple_button_class` — both pre-existing. It does **not**
  touch `avm2_render_node`, `button_construct_states`, `btn_state_get/set`, or
  `hit_test_shape_obj`. Textually distant from the render walk; should merge
  clean.
- **If `w2-button` introduces a "current button state" field** (e.g. a
  `btn_state` enum so over/down states can display), B6's `next->btn_up`
  should become "the child for the current state" — one line, and the comment
  in the patch says so. Behaviour is identical while Up is the only state ever
  displayed.
- B3 reads the **global** `avm2_generated_static_glyphs` / `avm2_generated_fonts`
  tables, consistent with the existing `statictext_for` / `resolve_static_text`
  at `avm2_display.c:426/443`. If per-movie (child-SWF) static-text tables are
  ever wired up, both sites need updating together.
- B2's `ss_transform` now throws where it previously returned `null`. The only
  new throw path is a *truthy non-object* argument; `null`/`undefined`/`0`/`""`
  still return `null`, and `setStyle` always passes a real object
  (`shallow_copy`), so the internal caller is unaffected.
- No recompiler (`SWFRecomp/`) change → no cmake rebuild needed. **But** see
  canary trap 2: B3 makes `avm2_generated_static_glyphs` a hard link-time
  dependency of every NO_GRAPHICS AVM2 build, so any *pre-existing* checked-in
  `RecompiledABC` older than `avm2_movie_tables.c` will now fail to link
  instead of silently working. CI recompiles from scratch and is fine; a local
  worktree with copied test dirs needs `--recompile`.
- B2's `fontFamily` fix changes `StyleSheet.transform(...).font` for lists with
  empty entries. Canaried across every CSS/StyleSheet test in avm1, avm2 and
  from_shumway (10 tests, all pass).
