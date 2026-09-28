# w2-mixed: session 21 wave 2. Both GO rows delivered, **+2 effective**, 0 regressions

## New files (stage by name). There are no new `.c`/`.h` TUs.

    SWFRecompDocs/plans/session21-fanout-reports/w2-mixed-1-links-scrolled.patch
    SWFRecompDocs/plans/session21-fanout-reports/w2-mixed-2-loadbytes-extract.patch
    SWFRecompDocs/plans/session21-fanout-reports/w2-mixed-report.md

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/w2-mixed` (branch `s21-w2-mixed`, base `1b7a987cf`). Nothing is
committed. Both patches are independent, and `git apply --check` is clean against main-tree master `6913e27a7`.

| patch | files | row | before → after (both modes) |
|---|---|---|---|
| `w2-mixed-1-links-scrolled.patch` | `SWFModernRuntime/src/actionmodern/action.c`, `src/libswf/ng_shared.c`, `include/libswf/tag.h` | `text/links_in_scrolled_text` | output_mismatch 0/1 → **pass** (no-graphics and `--mode=graphics`) |
| `w2-mixed-2-loadbytes-extract.patch` | `ruffle-tests/verify_output.py` | `from_shumway/as3-loader/LoaderLoadBytesTest` | output_mismatch 1/4 → **pass** (no-graphics and `--mode=graphics`) |

CI: patch 1 is AVM1 runtime, so `mode=graphics categories=all` covers it. Patch 2 is harness-only. Neither needs `categories=full`.
The per-test graphics results are proven locally.

## Patch 1: `links_in_scrolled_text` (the diagnosis is in `w1-mixedavm-tail-report.md` §1)

This productionizes the wave-1 prototype. There are no PROTO markers, and the global flag is gone.

1. **`maxscroll`/`bottomScroll` use one pixel formula for every field.** `computeScrollProperty` now always goes through
   `ng_computeScrollMixedFont`, with `run_count = 0` for uniform-font fields. That replaces `lines - visible + 1`.
   `recomputeMaxScroll` (the `scroll`-setter clamp) now delegates to the getter, so the clamp and the getter can no longer
   disagree.
2. **`ng_computeScrollMixedFont` gains an `int is_input` parameter** (declared in `tag.h`). Following Ruffle
   `html/layout.rs`, `text_size` drops an empty last line for non-input fields only. So `target` uses
   `reported_text_height` for non-input fields and `full_text_height` for input fields.
   - The new helper `tf_is_input_type()` is strict: it requires `type == "input"`. An unset type counts as dynamic.
     `tf_is_editable` (unset counts as editable) is left untouched for the caret paths.
   - The `textHeight` caller passes `0`; only the height is read there.
3. **The scroll-aware link hit test** is s16's held patch. `ng_getCharIndexAtPoint` gains `scroll_lines`, and it has three
   call sites, all TextField-specific:
   - the caret branch of `actionMouseClickFocus`;
   - `tf_char_index_at_mouse`;
   - `actionTextFieldDragEnd`.

   **The general AVM1 pick loop is not touched** (sibling `w2-tt-c`). The `actionMouseClickFocus` hunk is only the
   `ng_getCharIndexAtPoint(...)` call inside its focused-TextField caret block, not the hit loop above it.
4. **The `asfunction:` callback lookup finds `_root` timeline variables.** In `handle_asfunction`, when the field's container
   is `&root_movieclip`, the lookup tries the global `var_map` (`hasVariable` first, because `getVariable` creates the slot
   on a miss) before `_global`.

## Patch 2: embedded-SWF extraction in `verify_output.py`

- `embedded_swf_payloads(swf)` parses `test.swf` (FWS/CWS/ZWS) and returns every `DefineBinaryData` (tag 87) whose payload
  starts with a SWF signature.
- `find_child_swfs(test_dir, extract_dir=None)` works as follows:
  - With `extract_dir`, it writes each payload to `extract_dir/embedded_binarydata_<charid>.swf`, rewriting only if the
    bytes differ.
  - It **appends** these files after the on-disk children, so existing movie ids do not change.
  - It **skips any payload that is sha256-identical to an on-disk child.**
- Both call sites (`compile_native` and the wasm build path) pass `extract_dir=build_dir`.
- **Where the file goes:** `build_dir` is the per-run tmp build directory. Nothing is written into the test tree, so
  `git status` stays clean (verified: the worktree shows only the 4 modified tracked files), and there is nothing to
  gitignore or accidentally commit.
- **Idempotent:** every run starts from a fresh tmp dir, and the write is also content-compared. Re-running
  `find_child_swfs` twice on the same dir gives identical lists.
- **CI path:** every job in `ruffle-tests.yml` invokes `verify_output.py`, which is the only caller of
  `find_child_swfs` (grepped `ruffle-tests/*.py`, `scripts/`, workflows). So CI gets the same extraction automatically.
- **Blast radius, checked directly:**

  | test | children before | children after |
  |---|---|---|
  | `LoaderLoadBytesTest` | `[]` | `[embedded_binarydata_1.swf]` |
  | `avm2/loader_loadbytes_events` | on-disk twin present | unchanged (deduped) |
  | `avm2/large_preload_from_bytes` | on-disk twin present | unchanged (deduped) |
  | `LoaderTest2` | — | unchanged (no embedded SWF) |

  The whole corpus has only these 4 SWF-bearing `DefineBinaryData` tags (wave-1 scan).

## Tests run (worktree, copied test dirs, `--recompile`, sequential, `SWFRECOMP_COMPILE_TIMEOUT=2400`)

**No-graphics, 41 rows. Every row's status matches its CI status except the two intended flips:**
- **avm1 (17):** `asfunction`, `edittext_scroll`, `edittext_hscroll`, `clone_sprite_edittext{,_dynamic}`, `swf4_vars`,
  `textfield_props_swf6/7/8`, `edittext_drag_select`, `edittext_place_caret`, `edittext_input_newlines`,
  `edittext_text_height_leading`, `edittext_newlines`, `edittext_focus_selection` are PASS. `edittext_onscroller` and
  `textfield_props_swf5` are RUFFLE_MATCHED, as at base.
- **text (5):** `links_in_scrolled_text` is **PASS (flip)**. All 4 `text_caret_placement_*` are PASS.
- **from_gnash (3):** `TextField-v6/v7/v8` are MISMATCH, as at base (ACC+KF).
- **from_shumway (4):** `as3-loader/LoaderLoadBytesTest` is **PASS (flip)**. `LoaderLoadBytesTest2`, `LoaderTest2` and
  `acid/acid-textfield-scroll` are PASS.
- **avm2 (4):** `loader_loadbytes_events`, `large_preload_from_bytes`, `loader_bytes_unknown_content` and
  `bytearray_bad_symbol_class_other_movie` are PASS.
- **regression (8):** `avm1_parent_child_text`, `avm1_mcl_load_tick`, `avm1_parent_as3_child_payload`,
  `avm2_child_simplebutton`, `avm2_parent_child_render`, `avm2_parent_child_symbol_stride` and `avm2_static_text` are PASS.

**Graphics:** both headline rows are PASS.

**Byte-for-byte A/B against the base runtime** (wave-1 base actuals, same mode). This covers every row that is not `pass`,
plus the text-adjacent ones: `edittext_onscroller`, `textfield_props_swf5`, gnash `TextField-v6/v7/v8`,
`acid-textfield-scroll` and `regression/avm1_parent_child_text` are **all IDENTICAL**. So there is no hidden content change
behind a `ruffle_matched` or `output_mismatch` status.

## Residual risk and new leads

- Patch 1 changes `maxscroll`/`bottomScroll` for every uniform-font AVM1 field whose window holds a fractional line. That
  change is correct per Ruffle, but CI's full `all` run is the real check. The local sweep covered every corpus SWF that
  names `maxscroll`/`bottomScroll`/`asfunction` (wave-1 byte scan).
- The mixed-font `textHeight` still drops the empty last line for input fields too (Ruffle keeps it). The uniform
  `ng_computeTextHeight` still counts the phantom line (426 vs Ruffle's 397). Both are latent and not graded by any corpus
  row found. They are not changed here.
- `handle_asfunction` `_root` lookup: a `regression/` fixture using the Ruffle exporter as oracle would pin it. None is
  added here, because the corpus row `text/links_in_scrolled_text` now grades it.
