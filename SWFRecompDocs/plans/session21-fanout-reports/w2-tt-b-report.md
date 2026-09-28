# w2-tt-b: Sound load-state machine + TextLine atom index (session 21, wave 2)

**New files (stage by name; `git add -u` drops them):**
- `ruffle-tests/tests/swfs/regression/avm2_sound_bytes_and_group_format/Test.as`
- `ruffle-tests/tests/swfs/regression/avm2_sound_bytes_and_group_format/build_swf.sh`
- `ruffle-tests/tests/swfs/regression/avm2_sound_bytes_and_group_format/output.txt`
- `ruffle-tests/tests/swfs/regression/avm2_sound_bytes_and_group_format/test.toml`
- `ruffle-tests/tests/swfs/regression/avm2_sound_bytes_and_group_format/test.swf`
- `ruffle-tests/tests/swfs/regression/avm2_sound_bytes_and_group_format/sound.mp3`

The patches are `w2-tt-b-1-sound.patch` (`avm2_media.c` + avm2 `ignored_tests.txt`) and
`w2-tt-b-2-textline.patch` (`avm2_text.c` + regression `README.md` row). They are independent
and apply cleanly to `835d9f539`. **The new regression fixture needs both patches**, because it
grades the sound half and the text half. Worktree:
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-ab3225a30581e8b60` (uncommitted).

## 0. Verdicts

| row | verdict | before (baseline) | after (local, graphics) |
|---|---|---|---|
| `avm2/sound_load_multiple` | **GO** | output_mismatch 3/19 (ignored) | **PASS** 19/19. Ignore entry pruned with a dated note |
| `avm2/textline_atom_index_at_char_index` | **GO** | output_mismatch 21/40 | **RUFFLE_MATCHED** |

**Priced yield: +2 effective.** `sound_load_multiple` leaves the ignore list, so the filtered
count gains +1 as well.

**Rule-3 check (KF).** `textline_atom_index_at_char_index` is `known_failure`. Our remaining diff
is Ruffle's own 3 lines: 23/24 (the surrogate pair) and 39 (the graphic element). The move is
`output_mismatch` → `ruffle_matched`, not `pass` → `ruffle_matched`. No `pass` canary moved
(§3), so no KF row drifted onto Ruffle-only output.

## 1. Premise attacks

Both w1 premises held at HEAD `835d9f539`: same counts, same mechanisms. Refinements:

- **Sound:** the w1 report says "`load(null)` is a no-op". In Ruffle the #2037 state check runs
  BEFORE the null check, so `load(null)` on a Loading or Loaded sound still throws. The port
  keeps that order.
- **Sound, the embedded arm:** we kept the "leave alone" decision. `load()` on a
  SymbolClass-embedded sound is still a silent no-op. Ruffle throws #2037 there. No fixture
  grades that case.
  - The byte-array loaders return early on an embedded sound. That matches Ruffle exactly,
    because its `set_sound` marks embedded sounds Loaded.
- **TextBlock:** the new #2175 walk follows Ruffle's `handle_content_element` in full. The
  report said to keep the "split-tail" #2175 path. It is kept (a text-bearing unformatted
  element still traces #2175). One side effect: a *null-text* unformatted TextElement no longer
  traces #2175. That is Ruffle's rule ("FP just completely ignores the element"), and
  `textblock_createline_errors` still passes.

## 2. Mechanism and patch scope

**`avm2_media.c`, Sound:**
- Adds a trailing `uint8_t load_state` to `Avm2SoundObjExt`: New / Loading / Loaded, from
  Ruffle's `SoundLoadingState`.
- `sound_ctor` URL arm and `sound_load`: set Loading. `load()` throws `Error #2037` unless the
  state is New, and `load(null)` is then a no-op.
- New `loadCompressedDataFromByteArray`:
  - A no-op once Loaded.
  - `TypeError #2007` on a null argument.
  - `ArgumentError #2084` on a short read, leaving the position untouched.
  - Otherwise it copies the bytes, advances the position, and sets `ext_loaded`, `data_size`,
    the mp3 duration and Loaded.
  - It then dispatches a synchronous `progress`, and runs the ID3 walk over the private copy.
    `ext_data` is scoped to that call, so it never points into the GC heap afterwards.
- New `loadPCMFromByteArray`: Ruffle's stub. Loaded unless already Loaded.
- `media_poll_simulated`: a queued URL load that drains after the sound is Loaded is dropped
  with no events (`loader.rs` `load_sound_avm2`). Otherwise the drain sets Loaded.
- Adds `#include <stdlib.h>`.

**`avm2_text.c`, TextLine / TextBlock (TextLine atom functions plus the #2175 check only; no
caret or device-font code touched):**
- `getAtomIndexAtCharIndex` is now `tl_get_atom_index_at_char_index`, Ruffle's `TextLine.as`
  formula: `charIndex - textBlockBeginIndex`, or -1 outside `[0, rawTextLength)`. It was
  `tl_const_im1`.
- `tb_do_create_text_line`: the top-level `element_format == NULL` test becomes
  `tb_content_has_null_format`:
  - it recurses into GroupElement children;
  - a GraphicElement is never checked;
  - a text element needs a format only when its text is non-null.

## 3. Tests run

All runs were local, `--mode=graphics`, sequential, with `SWFRECOMP_COMPILE_TIMEOUT=2400`, on
worktree copies with `--recompile`.

| test | baseline (results_graphics) | after |
|---|---|---|
| sound_load_multiple | output_mismatch 3/19 | **PASS** |
| textline_atom_index_at_char_index | output_mismatch 21/40 | **RUFFLE_MATCHED** |
| content_element_basic, element_format_clone, element_format_constructor_order, element_format_properties | pass | pass |
| groupelement_text | ruffle_matched | ruffle_matched |
| sound_constructor_with_args, sound_embeddedprops, sound_play, sound_rootless, sound_valueof | pass | pass |
| soundchannel_position, soundchannel_soundcomplete | ruffle_matched | ruffle_matched |
| soundchannel_soundtransform, soundchannel_soundtransform_exists, soundchannel_stop | pass | pass |
| soundmixer_buffertime, soundmixer_soundtransform, soundmixer_stopall, soundtransform | pass | pass |
| text_engine_groupelement, textblock_createline_errors, textblock_createline_fte, textblock_properties | pass | pass |
| textblock_line_changes, textblock_recreateline, textblock_releaselines | ruffle_matched | ruffle_matched |
| textline_has_tabs | output_mismatch 42/47 | output_mismatch 42/47 (unchanged) |
| textline_inapplicable_properties, textline_name, textline_raw_text_length, textline_splitting_basic, textline_throwerror, textline_validity | pass | pass |
| id3_info, displayobject_early_init (the other Sound users in the corpus) | pass | pass |
| regression/avm2_parent_child_symbol_stride (uses Sound) | pass | pass |
| **regression/avm2_sound_bytes_and_group_format (new)** | FAIL: dies at row A with #1006, checked by A/B with the runtime diff reverted | **PASS** |

**About the new fixture:**
- It is built with mxmlc (`build_swf.sh`). Its expected output is the **Ruffle exporter's trace**
  (the binary was rebuilt 2026-09-28 12:44).
- One splice: Ruffle sends the traced #2175 block to its ERROR log, not its trace log. Those six
  lines were copied verbatim from that log into the place where Flash prints them. The Flash
  form is pinned by `avm2/textblock_createline_errors`.
- The GraphicElement row does not print `rawTextLength`, because Flash (U+FDEF, 5) and Ruffle (4)
  disagree there.

**CI suggestion:** graphics mode, `categories=full` (AVM2 runtime).

## 4. New unclaimed leads

1. **Embedded-sound `load()` → #2037** (Ruffle's behaviour) is still a deliberate no-op here. A
   one-line flip if a fixture (or the exporter) confirms Flash agrees.
2. **GraphicElement text model.**
   - Flash counts a graphic as one U+FDEF char. Ruffle and we count nothing.
   - This is the last `ours`/Ruffle line (39) of `textline_atom_index_at_char_index`, plus line
     38's surrogate atoms (23/24). A real atom model (surrogate pair = 1 atom) plus U+FDEF would
     take the row to `pass`.
   - Probe `groupelement_text` first: changing `GraphicElement.text` from "" to U+FDEF would
     change its fold.
3. **`loadCompressedDataFromByteArray` sounds cannot really play in graphics builds.** They take
   the simulated-channel path (duration countdown), like URL sounds. There is no mixer
   registration of the bytes.
