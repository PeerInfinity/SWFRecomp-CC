# The child-movie char-id offset: from a regex list to a value-keyed wrapper

**Date:** 2026-09-03 · **Arc:** Multi-SWF (loaded children), slice 1
**Baseline:** `01d212824` · **Brief:** `SWFRecompDocs/prompts/child-charid-wrapper-prompt.md`

## The problem

A loaded child SWF's character ids are shifted by `movie_id * 1000` so they
cannot collide with the parent's dictionary. `generate_child_movie_file`
(`ruffle-tests/verify_output.py`) did that with **one `re.sub` per emitted call
name** — a hand-maintained list. Any char-id-carrying emission the list did not
name kept its RAW id and silently disagreed with every emission that was
offset, and the failure mode is a lookup that finds nothing rather than a
crash. Four of the list's regexes were dead (they named calls the recompiler no
longer emits) and roughly a dozen live char-id calls were unoffset while the
calls they must agree with were offset.

## What this slice did

Every character id the recompiler writes into generated C now goes through
`CHARID(...)` — the identity macro `#define CHARID(x) (x)` in
`SWFModernRuntime/include/libswf/tag.h`, emitted by the one-line helper
`charId()` in `SWFRecomp/src/swf.cpp`. The harness does **one** substitution
keyed on that token, and the whole regex block (four dead entries included) is
gone.

49 emission sites were wrapped: every char-id call argument, plus the two
data-table struct fields. Four of those the oracle found *after* the first
pass — see "What the oracle caught" below, which is the whole reason the slice
had to build one. Generated C is behaviourally identical for every
single-movie SWF — `CHARID(7)` is `(7)`, and it is still a constant expression
in the static initialisers that build the `FramePlacement` tables (checked with
`gcc -fsyntax-only`, below).

## The brief's two premises, checked

Both held.

1. **`tag.h` names its char-id parameters.** It does, and the oracle now
   derives the argument positions from it rather than restating them.
2. **`swf.cpp` emits `FramePlacement` char ids as bare struct-initialiser
   fields.** It did (`SWFRecomp/src/swf.cpp`, the `sprite_definitions <<
   "\t{ "` block), into `sprite_definitions`, which is appended to `tag_main`
   — so the harness had that text and offset none of it. A child sprite's
   loop-back placement table therefore described its objects by ids that could
   never match the offset ids those objects were placed under.

## Where the brief was wrong, and what changed because of it

### §1: "The oracle does not cover struct-initialiser fields — nothing mechanical can."

It can, and it does. Struct field indices are as derivable from the headers as
argument positions are: the oracle parses `typedef struct { ... } Name;`, finds
fields named as char ids, and checks positional initialisers of that type in
the generated C. `FramePlacement` field 1 and `SpriteFrameScriptEntry` field 0
are both covered mechanically. The manual audit is still written down below,
because "which aggregates does the recompiler emit at all" is not something the
oracle can answer — but the *char-id-ness* of their fields is.

### §1: the audit missed a second struct

`SpriteFrameScriptEntry` (`SWFModernRuntime/include/actionmodern/sprite_frame_scripts.h`)
has `char_id` as field 0 and is emitted by `swf.cpp` into `tag_main`. The brief
and the earlier audit both named only `FramePlacement`. It is dead code today
(the child's `tagInitSpriteFrameScripts` call is stripped by the harness), but
it is wrapped now so the rule has no exceptions.

### §1: keying on the value means **0 must be excluded**

Not in the brief, and a bug the old regex list already had. `0` is not a
character id — it is the "no character" sentinel in *every* one of these
positions: a `PlaceObject2`/`FramePlacement` with `char_id == 0` is a Modify
tag (`ng_loopback_entry_survives` does `if (f0[k].char_id == 0) continue;`, and
tag.h's own comment says "Modify-only tags (char_id=0) ignore is_replace"),
`tagDefineButton`'s `hit_char_id == 0` means no hit shape, and the empty
`FramePlacement` / `SpriteFrameScriptEntry` arrays are 0-filled sentinels. Real
SWF character ids start at 1.

The old list's `tagPlaceObject2\w*` regex rewrote `..., 0,` to `..., 1000,`,
turning every Modify place in a loaded child into a place of character 1000. It
went unnoticed because it never reached a graded test. The new substitution
skips 0 explicitly, with the reasoning in the comment.

### §2: `tagSetSpriteLabels` was NOT broken

The brief and the BACKLOG both listed the sprite-metadata quartet as
half-applied. Three of the four are; **labels are not**. The test's `cA:` row
(a child sprite's `gotoAndStop("two")`) reads `2` at the baseline as well as
after the fix.

`tagSetSpriteLabels` is emitted **without** `app_context`
(`tagSetSpriteLabels(char_id, labels, count)`), so the list's regexes — every
one of which anchored on `\(app_context,` — could never have matched it either
way, and the id it registers under is raw in the parent too. The store is a
flat array searched linearly by `char_id`, and the parent in this test has no
sprite at the child's raw id, so the child's raw registration is simply the
only entry with that key and the lookup finds it. **It works by accident**: two
movies with sprites at the same raw id would shadow each other, first
registration winning. Still worth fixing, and now fixed by construction, but
the "provably inconsistent today" claim applies to placements / frame counts /
no-end-tag, not to labels.

## The regression test

`ruffle-tests/tests/swfs/regression/avm1_parent_child_sprite_meta`, written
first and watched fail on the baseline. A hand-built child SWF and an
MTASC-built parent carry the **same three sprites at different char ids**, so
the parent row is a control and the child row is the discriminator. Each row is
read through the same code path.

| row | baseline | fixed | reads |
|---|---|---|---|
| `pU:` | n | n | parent inner clip ever `onUnload`'d |
| `cU:` | **y** | **n** | child inner clip ever `onUnload`'d — `tagSetSpritePlacements` |
| `pA:` | 2 | 2 | parent `gotoAndStop("two")` |
| `cA:` | 2 | 2 | child `gotoAndStop("two")` — `tagSetSpriteLabels` (see above) |
| `pB:` | y | y | parent sprite B reached frame 2 |
| `cB:` | **n** | **y** | child sprite B reached frame 2 — `tagSetSpriteFrameCounts` + `tagSetSpriteNoEndTag` |

Baseline diff (`01d212824`):

```
     1  armed
     2  pU:n
-    3  cU:n
+    3  cU:y
     4  pA:2
     5  cA:2
     6  pB:y
-    7  cB:y
+    7  cB:n
     8  done
```

Sprite A is a well-formed 2-frame looper with a label on frame 2 and a named
nested MC that frame 1 re-places, so the MC must survive every loop-back with
its identity. Sprite B's header underdeclares its frame count (1 vs two
ShowFrames) and its body carries no End record, so it only reaches frame 2 —
where its own nested clip is placed — if `tagSetSpriteFrameCounts` corrected
the count, and only *stays* there if `tagSetSpriteNoEndTag` parked it.

### What the test does NOT cover

- **`FramePlacement.char_id` itself.** `ng_loopback_entry_survives` skips the
  char-id comparison entirely for MovieClip children
  (`if (!existing_is_mc && f0[k].char_id != (u16)e->char_id) continue;` —
  deliberate Ruffle `survives_rewind` parity), and non-MC entries (shapes,
  static text) have no AS-visible identity to lose when they fail to survive.
  So the struct field's raw-ness is not reachable from a trace test today; the
  test pins the **registration key** (`tagSetSpritePlacements`'s `sprite_id`,
  which is what makes the whole table unreachable), and the struct field is
  covered by the oracle and by inspection. If the MC exemption is ever
  narrowed, that field becomes observable and deserves a row.
- **The other unoffset calls** in the old inventory —
  `tagDoInitActionGuarded`, `tagPlaceObject3`,
  `tagReplaceObject2RatioWithClipActions`, `tagDefineEditTextProps`,
  `tagDefineText`, `tagCSMTextSettings`, `tagDefineFontGlyphBase/Info/Metrics`,
  `tagDefineVideoStream`, `tagVideoFrame`, `tagImportCharacter`,
  `tagDefineButton`'s `hit_char_id`. All are wrapped and all now move with the
  rest, but none has a test in front of it. The mechanism is what makes them
  safe, not a per-call test; that was the point of taking the mechanism.

## The completeness oracle

`scripts/check_charid_wrapping.py`. Everything it checks is **derived from the
runtime headers**, not restated:

- **Call arguments** — every prototype in `tag.h` whose parameter list names a
  parameter in `CHARID_PARAM_NAMES` (`char_id`, `sprite_id`, `font_id`,
  `sound_id`, `text_id`, `hit_char_id`, `local_char_id`) contributes
  `(function, arg index)` pairs. A bare integer literal at one of those
  positions in the generated C is an offender. 71 call names today (including
  runtime-only `ng_*` accessors that generated C never calls — being
  over-inclusive is the safe direction).
- **Data-table fields** — every `typedef struct { ... } Name;` in the scanned
  headers with a char-id-named field contributes `(type, field index)`.
  Positional initialisers of that type are checked the same way.
  `FramePlacement` field 1, `SpriteFrameScriptEntry` field 0, and the
  runtime-only `PendingSpriteScriptEntry` field 1, which is never emitted.
- **Macro aliases**, resolved mechanically to a fixpoint rather than listed:
  the recompiler emits `tagDefineSprite`, which reaches `tagDefineSpriteEx`
  through a variadic arity-dispatch macro. Without alias resolution the oracle
  would have been blind to every `tagDefineSprite` call — the single most
  important one. A positional forwarder inherits the callee's char-id index at
  the position of the forwarded parameter; a variadic macro that passes
  `__VA_ARGS__` through inherits its callees' indices directly.

**Positive control** (an oracle that never fires proves nothing): stripping
`CHARID(...)` back to bare literals from the new test's generated
`movie_child.c` makes it report **17 offenders** — every call position and both
struct-field positions, `FramePlacement` field 1 and `SpriteFrameScriptEntry`
field 0 included:

```
$ sed -E 's/CHARID\(([0-9]+)\)/\1/g' movie_child.c > unwrapped.c
$ scripts/check_charid_wrapping.py unwrapped.c
CHARID oracle: 17 offender(s) in 1 file(s)
  unwrapped.c:19: tagPlaceObject2() arg 2 is the bare literal 1001 (want CHARID(1001))
  ...
  unwrapped.c:60: FramePlacement initialiser field 1 is the bare literal 1003 (want CHARID(1003))
  unwrapped.c:110: SpriteFrameScriptEntry initialiser field 0 is the bare literal 0 (want CHARID(0))
```

`CHARID_PARAM_NAMES` is a whitelist and not an `_id$` pattern on purpose:
tag.h is full of ids that are **not** character ids and must not be offset —
`transform_id`, `cxform_id`, `codec_id`, `movie_id`, `clip_depth`,
`glyph_base`, `frame_idx`.

### A second mode: check the EMITTER, not the output

`--emitter` reads `SWFRecomp/src/swf.cpp` instead of generated C. It pulls
every function name the recompiler *writes* out of the C++ string literals
(turning `\t` escapes into spaces first, or the tab in `"\ttagDefineSound("`
glues onto the name), intersects that with the char-id call names the headers
declare — **31 today** — and reports any emission statement that never calls
`charId()`.

This exists because the generated-C mode has a blind spot the brief did not
anticipate: **it can only see what the SWFs it was pointed at happen to
emit**. An emission site no sampled SWF reaches is invisible to it. The
emitter mode enumerates the complete set from the source, so it is independent
of any corpus sample and runs in a fraction of a second.

Positive control: reverting six `charId(` calls in a copy of `swf.cpp` makes it
name all six by line.

**The two modes are complementary, not redundant**, and the slice needed both:

- `--emitter` enumerates the complete set of char-id **calls** from the source,
  so no sample can hide one. It cannot see a **struct-initialiser row**, which
  is a plain string literal, not a call.
- the generated-C mode sees struct rows (that is the half the old regex list
  structurally could not reach) but only for what the SWFs it was given emit.

Each caught something the other missed in this very slice: `--emitter`'s class
of miss was `ng_record_char_path` (found by the sweep, then generalised into
`--emitter` so the next one is found without a sample), and the generated-C
mode's was the `SpriteFrameScriptEntry` table's trailing `{ 0, 0, NULL }`
sentinel row, which `--emitter` is blind to by construction.

Where it runs:

- **`generate_child_movie_file` hard-fails** on any offender, with the call
  site and the value, before it does the substitution. That is the
  correctness-critical path: a missed emission site cannot reach a multi-SWF
  test as a silent id disagreement.
- **Standalone**: `scripts/check_charid_wrapping.py --tree <build dir>`, or
  `--list-positions` to print what the headers say the char-id positions are.

It deliberately does **not** run for every single-movie test: the check costs a
parse of `tagMain.c` and buys nothing there, because a single-movie SWF's ids
are never re-based. Broad coverage came from a one-off sweep instead (below),
and the arc's later slices can re-run the standalone script.

## What the oracle caught

It was not decoration. Sweeping ~450 corpus SWFs through the recompiler and
checking every generated `tagMain.c` found **four emission sites the manual
pass had missed**, in two families:

- **`ng_record_char_path` / `ng_record_morph_path` / `ng_record_char_winding`**
  — the shape-recording calls emitted alongside `tagDefineShape`. An entire
  family, nowhere in the old regex list either, so a loaded child's vector
  hit-test paths and non-zero-winding flags were registered under RAW ids
  while the shapes themselves were offset.
- **The button-state `tagPlaceObject2`** (the synthesized placement inside a
  `tagDefineButton` state function) — a fifth `tagPlaceObject2` emission site
  distinct from the four the manual pass found.

`ng_record_*` is exactly the shape of miss the brief was worried about: not a
`tag*` call at all, so it does not look like a tag emission, and it is
invisible unless the SWF has a shape with recorded path data. The generated-C
sweep only found it because the sample happened to include such SWFs — which
is why `--emitter` was added afterwards to enumerate the set from the source
instead of from a sample.

A second sweep, after those four were wrapped, found a fifth: the
`SpriteFrameScriptEntry` table's trailing **sentinel row** `{ 0, 0, NULL }` in
the non-empty case (the empty-table sentinel had been wrapped, its
non-empty twin had not). 40 of the 426 sampled SWFs hit it. `--emitter` cannot
see that one — a struct row is a string literal, not a call — which is the
clearest evidence that both modes have to exist.

## The struct audit (what was checked, not assumed)

Every aggregate the recompiler emits as a C initialiser, and whether it carries
a character id:

| emitted aggregate | shape | char-id field |
|---|---|---|
| `frame_func frame_funcs[]`, `…_frame_funcs[]`, `…_state_funcs[]` | function pointers | no |
| `FrameLabelEntry frame_label_data[]`, `…_frame_labels[]` | `{const char* label; size_t frame;}` | no |
| `SpriteFrameScriptEntry sprite_frame_scripts_data[]` | `{size_t char_id; size_t frame_idx; fn;}` | **field 0** — wrapped |
| `ClipAction …_clip_actions[]` | `{u32 event_flags; frame_func action;}` | no |
| `ButtonAction …_actions[]` | `{u16 condition; frame_func action;}` | no |
| `FramePlacement …_placements[]` | `{u16 depth; u16 char_id; u16 ratio; u8 is_remove; u8 has_clip_actions;}` | **field 1** — wrapped |
| `u16 …_frame_starts[]` | cumulative placement offsets | no |
| `u16 text_char_codes[]` | glyph code points | no |
| `static const u16 font_N_codes[]`, `static const s32 font_N_advances[]` | glyph code points / advances | no |
| `u32 shape_data[][4]`, `float transform_data[][16]`, `float color_data[][4]`, `float uninv_mat_data[]`, `u8 gradient_data[][4]`, `u8 bitmap_data[]`, `u32 glyph_data[][1]`, `u32 text_data[]`, `float cxform_data[]`, `float morph_end_shape_data[][2]`, `float morph_end_color_data[][4]`, `u8 sound_data[]`, `u8 video_data[]`, `float path_data[][3]`, `const float stage_to_ndc[16]` | raw payload / geometry | no |

`text_data` was checked specifically: it holds **global glyph indices** into
`glyph_data`, not character codes and not char ids
(`SWFRecomp/src/swf.cpp`, "text_data stores global glyph indices").

## Verification

1. **The test flips.** `output_mismatch` at `01d212824`, `pass` after — the
   diff is quoted above.
2. **`gcc -fsyntax-only -std=c17 -Wall -Werror=return-type`** over the
   generated `movie_child.c` / `tagMain.c` / `draws.c` / `constants.c` of the
   new test: no errors, and only the two pre-existing warnings the previous
   slice recorded (`-Wmissing-braces` on the transform arrays, and the
   `MAX_STRING_ID` redefinition note). `verify_output.py` compiles with `-w`
   and would have shown neither. This is also the arm that proves
   `CHARID(7)` is a constant expression in a static initialiser: the
   `FramePlacement` tables are file-scope `static` arrays.
3. **Oracle sweep.** See below.
4. **Local sweep.** See below.
5. **CI.** See below.

### Oracle sweep (verification 3)

`--emitter`, over `SWFRecomp/src/swf.cpp`:

```
CHARID oracle (emitter): clean — every char-id call SWFRecomp/src/swf.cpp emits goes through charId(
```

Generated-C mode, over a corpus sweep: **426 SWFs recompiled** (the whole
`regression` suite, a seeded 300-test sample across every other suite, and
every loose child SWF sitting beside one of those tests), **1278 generated
files checked**:

```
recompiled 426 SWFs (0 would not recompile), checked 1278 generated files
CHARID oracle: CLEAN
```

The two earlier passes of that same sweep are what found the five missed sites
(4 + the sentinel row) described above — this is the third, after all of them
were wrapped.

## CI

**`mode=graphics`, `categories=full`, `images=false` — run `33782702750`** at
`06856ff7c`, conclusion **success**, results merged.

`scripts/corpus_status_diff.py 06856ff7c WORKTREE --per-suite` (baseline = this
slice's own commit, carrying the previous slice's merged results):

```
=== intersection: 4484 tests (06856ff7c -> WORKTREE, results_graphics) ===
  output_mismatch    124 ->   124 (+0)
  pass              4124 ->  4124 (+0)
  ruffle_matched     235 ->   235 (+0)
  runtime_error        1 ->     1 (+0)
  effective         4359 ->  4359 (+0)
GAINS 0 | REGRESSIONS 0 | OTHER STATUS MOVES 0
```

Zero regressions and an unmoved histogram — no test changed status in either
direction, which is what an emission change touching every SWF's generated C
should look like when `CHARID(x)` is `(x)`. The suites that actually exercise
loaded children:

- `regression` **75/75 pass**, with all three multi-SWF tests green:
  `avm1_parent_child_sprite_meta` (new), `avm1_parent_child_bitmap`,
  `avm1_parent_as3_child_payload`.
- `mixed_avm` 10 pass / 2 `output_mismatch` — unchanged from the baseline
  (`avm1_loads_avm2` is one of the two and was already mismatching).
- `import_assets` 3/3 pass — the suite that exercises `tagImportCharacter`,
  one of the calls the old list never offset.
- `avm1` 689 pass / 23 `output_mismatch` / 18 `ruffle_matched`.

`mode=no-graphics` was NOT dispatched: this change touches no
no-graphics-only code (`swf_core.c`, `tag_stubs.c`, or a bare `NO_GRAPHICS`
arm), only the recompiler and a shared header. The weekly canary covers it.

The +1 test / +1 effective versus the previous slice's 4483 / 4358 is this
slice's new regression test.

## Residuals

- **The AVM1 and AVM2 child-id strides disagree — and always have.** Every
  child, AVM1 or AVM2, is recompiled with `char_id_base = movie_id * 10000`
  (`ruffle-tests/verify_output.py`, the `recompile_child_swf` call), which the
  recompiler applies only to the **ABC/AVM2** emissions — the SymbolClass
  registry (`SWFRecomp/src/abc/abc_emit.cpp`) and the AVM2 timeline tables
  (`abc/abc_timeline.cpp`). The tag side of the same child is then shifted by
  `movie_id * 1000` by the harness. So an AS3 child's `SymbolClass` binding
  names character `10001` while its `tagDefineSprite` defines `1001`. Nothing
  cross-references the two today (AVM2 does not read the AVM1 dictionary), and
  `regression/avm1_parent_as3_child_payload` passes either way — but the two
  mechanisms should be one. The natural end state is for `char_id_base` to
  reach the tag pipeline too (it would fall out of `charId()` in three lines)
  and for the harness to stop substituting at all. Not this slice: it changes
  every AVM2 child's ids and needs its own failing test.
- **`FramePlacement.char_id` has no trace-visible consequence** while
  `ng_loopback_entry_survives` exempts MovieClip children from the char-id
  comparison. Noted above under what the test does not cover.
