# w1-trace-tail — unclaimed trace tail (session 21, wave 1)

New files: this report only. No source edits in the main tree. Two throwaway prototypes ran in a
scratchpad worktree, which has since been removed. Their diffs are quoted in §2.2 and §3.1.

Every row was run at HEAD `263427d08` with `--mode=graphics --diff --verbose`, one at a time,
`SWFRECOMP_COMPILE_TIMEOUT=2400`. All 13 rows reproduce the board's match/expected/actual counts
exactly, so no row has moved since the baseline run. "Ours-only" below means the line indices
where we differ from `output.txt` and Ruffle does not, computed with `verify_output.py`'s own
`_diff_indices`. That set is the whole bill for a `known_failure` row to reach `ruffle_matched`.

## 0. Verdicts and priced flips

| # | row | verdict | flip | cost | what decides it |
|---|---|---|---|---|---|
| 1 | `avm2/simplebutton_childevents_multichild` | **GO: prototyped** | **+1** (→ `ruffle_matched`) | **XS: 1 line** | Proven. A one-line prototype reaches `RUFFLE_MATCHED`, and 20 button canaries are unchanged (§2) |
| 2 | `timeline/missing_frame_scripts` | **GO: S4 pinned and prototyped** | **+1** (→ `pass`) | S (runtime hunk) + S (recompiler `has_end_tag`) | Proven. Prototype run = `PASS`; 4 orphan canaries pass (§3) |
| 3 | `avm2/sound_load_multiple` | **GO** | **+1** (→ `pass`, prune the ignore entry) | S/M | Ruffle's 3-state machine, checked by hand against all 9 cases (§4) |
| 4 | `avm2/textline_atom_index_at_char_index` | **GO** | **+1** (→ `ruffle_matched`) | S | 2 mechanisms. Ruffle's formula is 4 lines (§5) |
| 5 | `avm1/hitarea_remove_owner_drag` | **GO (M, canary-heavy)** | **+1** (→ `pass`) | M | G5 topmost pick. Still exactly one spurious line (§6) |
| 6 | `from_gnash/misc-ming.all/NetStream-SquareTest` | **GO (M)** | **+1** (→ `ruffle_matched`) | M | 24 ours-only lines = **2** mechanisms, not the 3 on record (§7) |
| 7 | `from_gnash/actionscript.all/MovieClip-v6`, `-v7` | **HOLD → GO as one slot** | **+2** | M/L | 14 ours-only lines each = 4 mechanisms. All 4 must land (§8) |
| 8 | `from_gnash/actionscript.all/MovieClip-v8` | NO-GO | 0 | — | 41 ours-only lines: row 7's 14 plus 27 SWF8-only lines (§8) |
| 9 | `avm1/set_property_values/swf4` | **NO-GO (policy trade, now measured)** | 0 (+1 possible only by trading rule 3) | — | 23 ours-only lines: 21 are the SWF4 abandon-the-set rule `swf4opcode` pins, 2 are `_name` bool text (§9) |
| 10 | `avm1/globals_monkeypatch` | NO-GO (arc) | 0 | — | Unchanged: 39/246/158, 198 ours-only (§10) |
| 11 | `from_gnash/misc-swfc.all/movieclip_destruction_test3` / `_test4` | NO-GO | 0 | — | s20 B5, re-verified byte-identical in counts (§10) |

**Priced wave-2 yield: +6 effective for rows 1-6, plus +2 for row 7 if a slot can take all four
of its mechanisms. Rows 1-4 are the cheap core: +4, all small, one file each (the recompiler hunk
in row 2 excepted), and two of them are already proven by prototype.**

Suggested slotting. File ownership is the constraint:
- **Slot A, `avm2_display.c`:** rows 1 and 2. They are separate hunks, lines 12961 and 3778-3792.
  Row 2 also needs the recompiler `has_end_tag` plumbing, and therefore `categories=full` in CI.
- **Slot B, `avm2_media.c` and `avm2_text.c`:** rows 3 and 4. Independent of each other and of
  slot A.
- **Slot C, `action.c` AVM1 input or NetStream:** row 5 or row 6. Do not give one slot both. Both
  sit in `action.c`, but far apart (76501 vs 39790), and row 5 needs about 55 mouse canaries.
- Row 7 is its own slot, or waits.

**Rule-3 check (KF rows).** Rows 1, 4, 6 and 7 are `known_failure` and carry `*.ruffle.txt`. Every
fix proposed here moves toward Flash's `output.txt`. None of them adopts Ruffle-only output: each
ours-only line is one where Ruffle already equals Flash, and the fix makes us equal Flash there
too. Nothing proposed can move a `pass` row to `ruffle_matched`. Row 9 is the single exception, and
that is exactly why it is NO-GO: its only `ruffle_matched` route is adopting Ruffle's SWF4 store-0
rule, which moves `swf4opcode` from `pass` to `ruffle_matched`.

---

## 1. Premise attacks: what fell

1. **"S4 = the orphan clip loses one tick" (s17 → s19; cause "not pinned" for 4 sessions)
   is wrong.**
   - The orphan does not lag relative to Flash, and "Container frame N" is not being reported
     at the wrong tick in the ordinary sense.
   - Our **FRAME_SCRIPTS phase runs the stage before the orphans**. Ruffle's `run_all_phases_avm2`
     (`core/src/frame_lifecycle.rs`) runs **orphans first in all three phases**: Enter, Construct
     and FrameScripts.
   - Because of that inversion, a clip created by a stage frame script runs its frame-1 script in
     the same tick (Flash runs it next tick). The next tick is then an empty skip tick (Ruffle's
     `set_skip_next_enter_frame(true)`, which we already copy), and every later tick prints
     `Main frameN` before `Container frameN` instead of after it.
   - Moving one loop fixes it (§3). The skip-next-enter-frame rule was already correct.
2. **"simplebutton_childevents_multichild: the exact allocation order must be read off
   `avm2_button.rs`" (s20, priced M).** The rule is simpler than an ordering question.
   - Ruffle's `create_state` builds an **empty state Sprite for a state with zero records**. That
     Sprite consumes an `instanceN` name in `fire_state_events`.
   - We `return NULL` (`avm2_display.c:12961`).
   - This fixture's `MyButton` has records only in UP (`btn_0_recs`), so Flash spends 3 names on
     empty over/down/hit wrappers. That is exactly the "+3 per pass" drift s20 measured. XS, not M.
3. **"set_property_values/swf4's `ruffle_matched` route is closed by the swf4opcode conflict"
   (s20).** This is true, but the pricing behind it was wrong.
   - s20 measured "173 lines short of Ruffle", which counts lines of *content* compared with
     Ruffle's output. Promotion is not decided that way: it is an index-subset test against Flash's
     file.
   - Measured under the rule that actually decides: **23 ours-only lines** out of 1397. 21 of them
     are the abandon-the-set rule (the conflict). The other **2 are an independent bug**:
     `setProperty(_name, true)` in SWF4 must stringify as `1`/`0`, and we print `true`/`false`.
   - So the trade is exactly "+1 effective for a rule-3 regression on `swf4opcode`, plus a 2-line
     fix". That is a policy decision with a known price, not an unknown arc.
   - The *Flash* route is genuinely an arc. See §9.
4. **"NetStream-SquareTest: 3 mechanisms" (s19 N6).** It is 2. Cluster (b), "the accessors must
   coerce/clamp: `bufferTime = 20` reads back 2", is not coercion.
   - Ruffle declares `bufferLength`, `bufferTime`, `time`, `bytesLoaded` and `bytesTotal` as
     **getter-only** prototype properties (`avm1/globals/netstream.rs:37-41`).
   - A write therefore goes nowhere, and the read returns the native state that `setBufferTime(2)`
     set. Clusters (a) and (b) are one mechanism.

## 2. Row 1: `avm2/simplebutton_childevents_multichild`, GO XS (+1, prototyped)

**Measured at HEAD.** 33/152 lines match, 132 actual. Ours differ on 119 lines and Ruffle on 101,
leaving **18 ours-only**. All 18 are `instanceN` names: we print `instance6/7/5/4/10/9` where Flash
and Ruffle print `instance9/10/8/7/16/15`.

**Mechanism.** The generated `abc_timeline.c` for this test contains two buttons:
- `btn_0_recs` (char 3, `MyButton`): one record, MySprite in state flag `1` = UP only.
- `btn_1_recs` (char 5): two MySprites in UP.

Ruffle `core/src/display_object/avm2_button.rs::create_state` handles a state by child count:
- Exactly one child: that child becomes the state.
- **Anything else, including zero**, builds a `state_sprite`. `fire_state_events` then calls
  `post_instantiation` on it, which calls `set_default_instance_name` and consumes a counter number.

Our `button_create_state` (`SWFModernRuntime/src/avm2/avm2_display.c:12961`) has
`if (n == 0) return NULL;`, so an empty over/down/hit state is NULL and consumes no name. It also
reads back as `null` from `overState` and its siblings.

### 2.1 Prototype (scratchpad worktree at `263427d08`, no-graphics)

```diff
-	if (n == 0) return NULL;
+	/* Ruffle create_state builds an (empty) state Sprite when a state has 0 records */
```

With n == 0 the code falls through to the existing wrapper path. The loop runs zero times, and
`button_construct_states` names the wrapper exactly where Ruffle does.

### 2.2 Results under the prototype

| test | baseline | with change |
|---|---|---|
| `simplebutton_childevents_multichild` | output_mismatch | **RUFFLE_MATCHED** (ours-only 18 → 0) |
| `simplebutton_childevents_script_order` (IGN, KF) | ruffle_matched | ruffle_matched. Our diff = Ruffle's 4 lines; its **53 `instanceN` lines all match Flash** under the change |
| `simplebutton_childevents`, `_symbolclass`, `_structure`, `_childprops`, `_childevents_nested`, `_childevents_sprite`, `_childshuffle`, `_constr_childevents`, `_multi_children`, `_constr`, `_constr_params`, `_added_to_stage`, `_mouseenabled`, `button_nested_frame`, `button_nested_frame_simple`, `button_hittest`, `button_bounds`, `mouse_pick_button_mode`, `goto_button_nested_framescript` | pass (19) | **pass (19)** |

**Wave-2 remaining work:**
- Confirm in `--mode=graphics`. The render walk now meets empty wrapper states; they draw nothing,
  but check.
- A/B `script_order` on raw output against a baseline run.
- Re-grade `from_shumway/as3-loader/events/loader-events`, which s20 said shares the name-counter
  mechanism.
- Check `render_canary_tests.txt` coverage for SimpleButton.

**Ignore list.** `simplebutton_childevents_multichild` stays listed in `avm2/ignored_tests.txt:199`
(known_failure bucket); the prune criterion there is `pass`. The effective metric counts ignored
rows, so the +1 is real either way.

## 3. Row 2: `timeline/missing_frame_scripts`, GO (+1, prototyped to PASS)

**Measured at HEAD.** 12/22, 27 actual, identical to s17-s19.

- **S3 (unchanged diagnosis).** `Spawn` (char 13) has 2 ShowFrames and **no End tag**. Ruffle
  treats that as `NextFrame::Same` when it wraps, so Spawn stops on frame 2 forever. Ours loops:
  5 extra `Spawn frame1/frame2/stopped` lines.
  - Owner: `avm2_display.c:2179 determine_next_frame`, plus the recompiler `has_end_tag` plumbing.
  - The plumbing is `abc_timeline.cpp` `Timeline`/`scanStream` and an emission field, plus
    `avm2_abc.h` `Avm2TimelineData`. That is a struct change, so every `RecompiledABC` regenerates.
  - Recipe: `session17-fanout-reports/wave1-timeline-order.md` §5. Blast radius is 1 corpus test;
    s17 lists 9 canaries.
- **S4 (new diagnosis): frame-scripts phase order.** In `avm2_display_run_tick`, `avm2_display.c`
  lines 3778-3792 run `run_frame_scripts_obj` over the stage's render list first and the orphans
  second. Ruffle runs orphans first (`frame_lifecycle.rs`, `run_all_phases_avm2`). Our Enter and
  Construct phases already put orphans first; only FrameScripts is inverted.

### 3.1 Prototype

Scratchpad worktree, runtime only. S3 was *simulated* by an env-gated `NEXT_FRAME_SAME` for
char 13, since `has_end_tag` needs the recompiler.

```diff
 	ctx->frame_phase = PHASE_FRAME_SCRIPTS;
-	{ stage render_list loop: run_frame_scripts_obj }
 	for (orphan_walk_bound loop) { ... run_frame_scripts_obj(ctx, o); }
+	{ stage render_list loop: run_frame_scripts_obj }
 	run_frame_script_cleanup(ctx);
```

| run | result |
|---|---|
| S3 (simulated) + S4 | **PASS 22/22** |
| S4 alone | MISMATCH. Output is `output.txt` **plus exactly the 5 extra Spawn lines**, so S3 and S4 are independent and jointly sufficient |
| `avm2/orphan_movie_complex`, `orphan_movie_reorder`, `orphan_removeobject`, `goto_on_orphan` (S4 applied) | **PASS ×4** (all pass at baseline) |

**Wave-2 blast radius for S4.** Any AVM2 movie where an orphan and a stage clip both have frame
scripts in the same tick. That covers Loader content, which becomes an orphan until attached, and
script-created unattached MovieClips.
- Canary set: the 4 orphan tests above; the `timeline/frame_script_*` and `swf_9_frame_script_*`
  families (all pass or ruffle_matched at baseline); `avm2/loader_*`; the `from_shumway/as3-loader`
  rows.
- CI: `categories=full` is required anyway, because S3 is recompiler emission.

## 4. Row 3: `avm2/sound_load_multiple`, GO S/M (+1 pass)

**Measured at HEAD.** 3/19, 7 actual. Our output is `1, Passed, 2, Passed, 3, TypeError #1006
loadCompressedDataFromByteArray is not a function`. Cases 1 and 2 already disagree: Flash throws
#2037 on a second `load()`.

**Mechanism.** Port Ruffle's `SoundLoadingState {New, Loading, Loaded}` from
`avm2/globals/flash/media/sound.rs` and `avm2/object/sound_object.rs`:

- **`load()`:** throw `#2037` unless the state is New. `load(null)` is a no-op. Otherwise start the
  load and set Loading. The `new Sound(request)` constructor path must also set Loading.
- **`loadCompressedDataFromByteArray(bytes, len)`:**
  - If already Loaded, return.
  - Read `len` bytes from `bytes` at its position, advancing the position. If the read fails,
    throw **`ArgumentError #2084`**. The table entry already exists at `avm2_error.c:1004`, and it
    is Flash's actual choice for a short read.
  - Otherwise dispatch a synchronous `progress` event and set Loaded. The duration can come from
    `mp3_duration_ms` over the copied bytes.
- **`loadPCMFromByteArray`:** if already Loaded, return. Otherwise set Loaded (Ruffle stubs it the
  same way).
- **Late URL completion:** a URL load that finishes after Loaded must not overwrite the sound
  (`loader.rs:1483`).

Checked by hand against all 9 cases of `Test.as`. They give exactly `output.txt`: cases 1, 2, 3
and 5 → #2037; 4, 6, 7 and 8 → Passed; 9 → #2084; then `Finished`.

**Owner:** `SWFModernRuntime/src/avm2/avm2_media.c`.
- A trailing `uint8_t load_state` goes on `Avm2SoundObjExt` (`:440`).
- Edit `sound_load` (`:735`), `sound_ctor`/`sound_start_url_load` (`:496`/`:517`), and register the
  two new methods next to `"load"` at `:1769`.
- ByteArray access goes through `avm2_bytearray_ext_of`.

**One Ruffle-parity decision to take explicitly.** In Ruffle, `load()` on a SymbolClass-embedded
sound throws #2037, because `set_sound` sets Loaded. Ours deliberately no-ops (comment at `:738`).
This fixture does not grade it: leave the embedded arm alone, or grade it with a regression fixture
against the exporter.

**Canaries:** every other `avm2/sound_*` row, including `sound_constructor_with_args`, the id3 rows
and `soundchannel_*`.

**Disposition:** prune `sound_load_multiple` from `avm2/ignored_tests.txt:107`, together with its
rationale block at `:80-87`. That block is an accurate open-bug note, and its criterion is met on
pass.

## 5. Row 4: `avm2/textline_atom_index_at_char_index`, GO S (+1 ruffle_matched)

**Measured at HEAD.** 21/40, 37 actual. Ours differ on 19 lines and Ruffle on 3, so **16 lines are
ours-only**. Ruffle's own diff set is {22, 23, 38}: surrogate-pair indices and the graphic
element's atom.

1. **`getAtomIndexAtCharIndex` is registered as `tl_const_im1`** (`avm2_text.c:7803`). That accounts
   for 9 of the 16 ours-only lines.
   - Ruffle (`TextLine.as:89-95`): `idx = charIndex - textBlockBeginIndex`, and the result is -1 if
     `idx < 0 || idx >= rawTextLength`.
   - Our `textBlockBeginIndex`/`rawTextLength` are already right. The line split of "ab\ncd"
     matches, and Flash's line-1 values 0/1 at charIndex 3/4 follow from begin 3, length 2.
2. **Spurious #2175 on a `GroupElement`.** That is 7 lines: the whole "graphic element" block
   collapses into an error trace. `tb_do_create_text_line` (`avm2_text.c:7533`) tests
   `ce->element_format == NULL` on the **top-level** content element. A `GroupElement` has no
   format of its own.
   - Ruffle's rule (`text_block.rs:586-612 handle_content_element`):
     - Recurse into the group.
     - Require a format only on a TextElement **whose text is non-null**.
     - A GraphicElement contributes no text.
   - Either text model (Ruffle's, where the graphic adds no text so `(4)` → -1, or Flash's
     U+FDEF, where `(4)` → 4) satisfies the subset rule, because index 38 is in Ruffle's diff set.
   - Keep the split-tail #2175 path: its bare `TextElement` has text and no format, so it still
     throws.

**Canaries:** the FTE rows, i.e. `avm2/textblock_*`, `content_element_basic`,
`element_format_constructor_order`, `groupelement*` and `textline_*`, especially
`textblock_recreateline` (flipped in s20).

## 6. Row 5: `avm1/hitarea_remove_owner_drag`, GO M (+1 pass)

**Measured at HEAD.** 2/10, 11 actual. The line-index metric understates how close this is: our
output is `output.txt` plus **one** spurious `rollover Z` at line 3. That is s19 R3, unchanged.

**Mechanism: G5, a single topmost AVM1 pick** (Ruffle `movie_clip.rs:2994-3120 mouse_pick_avm1`).
`actionDispatchMCMouseMove` (`action.c:76501`) decides `now_inside` per clip independently, in
`child_mc_cache` creation order, so btnZ (depth 1) and btnRm (depth 2) both roll over at (100,100).

The completion recipe:
- Compute ONE picked button-mode clip for the move, then set `now_inside = (mc == picked)` for
  button-mode clips.
- **Picking order:**
  - A button-mode ancestor wins over its descendants (Ruffle returns self before recursing). The
    existing `mc_has_button_mode_ancestor_with_mouse` already encodes this half.
  - Otherwise, at the first divergent ancestor level, the higher depth wins.
  - Non-button-mode clips do **not** occlude (the `check_non_interactive = !require_button_mode`
    arm).
  - **`ng_hit_order_cmp` (`:76273`) is NOT a correct key**: it compares own depth only, which is
    wrong across parents. A proper render-order key is needed.
- The traced lines survive this change. Walking the fixture's mouse script by hand:
  - The dragged clip (depth 3, has `onPress`) is topmost under the pointer during the whole drag.
    That is harmless: rollover never fires with the button down unless the clip was pressed.
  - The drop-target pick (`ng_update_drag_droptarget`) still runs btnRm's getter, which produces
    the two `dt:` lines.
  - The final hover at (100,100) lands outside the parked drag clip (115-145, 105-135), so it
    rolls over btnZ.

**Canary set.** 62 non-AVM2 corpus rows have `MouseMove` input (including `regression/avm2_simplebutton_click` and this row). All are `pass` except this row and 7
`ruffle_matched` KF rows; A/B those 7 on raw output:
- `edittext_onscroller`
- gnash `ButtonEventsTest`, `ButtonPropertiesTest`, `DefineTextTest`, `DragDropTest`,
  `PrototypeEventListeners`, `key_event_test`

The full list is reproducible with `grep -l MouseMove */input.json */*/input.json` under
`tests/swfs`. Include `from_shumway/avm1/nested-button`, `rollover` and `mouse-transparency`.

**Out of scope for this slice:**
- `tag.c`'s independent `ng_update_button_states` hover machine for DefineButtons.
- The press-side `actionDispatchMCPress`, which also fires on every containing clip.

Name both as the next G5 steps rather than widening the slice.

## 7. Row 6: `from_gnash/misc-ming.all/NetStream-SquareTest`, GO M (+1 ruffle_matched)

**Measured at HEAD.** 91/216, 201 actual. Ours differ on 125 lines and Ruffle on 108, leaving
**24 ours-only**. All 24 are aligned PASSED/FAILED lines, so fixing them cannot shift alignment.

- **M1, 22 lines: NetStream prototype getter-only accessors.**
  - Ruffle `avm1/globals/netstream.rs:37-41` declares `bufferLength`, `bufferTime`, `bytesLoaded`,
    `bytesTotal` and `time` as `property(getter)` on `NetStream.prototype`.
  - So `hasOwnProperty` on the prototype is true (5 lines), `typeof` is always `number` (lines
    6-7, 53-55 and 66-69), and writes do nothing.
  - `bufferTime` reads the native value that `setBufferTime` sets, so `stream.bufferTime = 20`
    still reads 2 (lines 57-63). `bufferLength` returns buffer_time too (a Ruffle stub, and it is
    what matches here).
  - Owner: `action.c` NetStream class setup around `:39790-39850`. `setBufferTime` is an
    `addStubMethodToProto` stub at `:39841`. Needs a per-instance native buffer_time.
- **M2, 2 lines: `Video` exposes no `hitTest`/`getBounds`.** A timeline Video must not inherit
  `MovieClip.prototype`.
  - Ruffle `video.rs` declares only its own methods.
  - Ours resolves them through the MovieClip fallback.
  - Owner: the Video display-object → prototype mapping. The pattern is the TextField/`ng_textfield_idx`
    distinction.

**Canaries:** the other `NetStream`/`Video` rows, i.e. avm1 `netstream_*`/`video_*` and gnash
`misc-ming.all/Video*`. The `incomplete/NETSTREAM_SQUARETEST_PLAN.md` premise ("timing") is still
wrong, as s19 said.

## 8. Rows 7-8: `MovieClip-v6/-v7/-v8`, v6+v7 is one M/L slot (+2); v8 NO-GO

**Measured at HEAD.** v6 is 901/936, 935 actual; v7 is 934/969, 968 actual; v8 is 1020/1087,
1086 actual.

| row | ours diff | Ruffle diff | ours-only |
|---|---|---|---|
| v6 | 35 | 60 | **14** |
| v7 | 35 | 64 | **14** |
| v8 | 67 | 68 | **41** |

This is exactly s19's post-patch-3 state. Nobody has taken it since. The 14 lines are four
mechanisms, **all required**:

1. **Descendant `onUnload` of a deferred-removed clip never fires.** This is 2 lines and it also
   misaligns 9 more.
   - `hardref3` is removed but kept alive at `-32849`, because its child has `onUnload` (memory
     `removemovieclip-descendant-onunload-defer`).
   - Flash fires `_level0.hardref3.hardref3child.onUnload` one frame later, just before `onData`.
     Preceding it is `PASSED: this._target == '/hardref3/hardref3child'` from inside the handler.
   - We never finalise the deferred removal. Inserting these 2 lines realigns the whole
     `onData` tail.
   - The `'val1'` and `#passed`/`#failed` residue is free: Ruffle fails those too.
2. `MovieClip.as:2097`: `retCaller == _root.meth`. `arguments.caller` returns empty.
3. `MovieClip.as:2191`: `propinspect == 0`. A for-in enumerates one property that Flash hides.
4. `MovieClip.as:2590`: `mc.toString() == undefined` on a clip given a non-MovieClip prototype.
   We return `[object Object]`. Likely a native `toString` that must return undefined for a
   wrong-typed `this`. Confirm from the recompiled script before implementing.

Items 2-4 are unlocated one-liners and each needs its own probe, so this is M/L for +2. **v8 is
NO-GO.** It carries the same 14 plus 27 SWF8-only lines: `filters` array identity/length, the
`transform` `toString` and its `__mc__` leak (`:1829`), `getBounds` rects, blendMode `darken`
(`:2392`) and `_width`/`_height` of a drawing (`:1668`).

## 9. Row 9: `avm1/set_property_values/swf4`, NO-GO (the trade is now measured)

**Measured at HEAD.** 346/1571, 1743 actual. Ours differ on 1397 lines, Ruffle on 1396, leaving
**23 ours-only**.

- **21 lines are Flash's SWF4 abandon-the-set rule.** Examples: `"z10"` → keep 1 (Flash, us);
  `_alpha "undefined"` → keep 0.78125.
  - Ruffle stores 0 instead. Because Ruffle's output is misaligned with Flash by then, its 0
    happens to equal Flash's line at those indices.
  - The only way to gain these lines is to adopt Ruffle's store-0 rule, which is a rule-3
    regression on `from_gnash/misc-swfc.all/swf4opcode` (s19 `w2-setprops-2`,
    `RUFFLE_VS_FLASH_DIFFERENCES.md:599-611`).
- **2 lines are an independent bug** (indices 1213 and 1219). `setProperty(_name, true/false)` in
  SWF4 must stringify the boolean as `1`/`0`; we print `true`/`false`. It is worth fixing on its
  own merits, but it flips nothing.
- **The Flash route (exact pass) is an arc.**
  - Flash's SWF4 `new Object()` fails with the debugger line `Warning: Object is not a function`.
    It appears 100 times, then `Warning: Reached warning limit of 100`. So `obj` is undefined and
    no `valueOf` is ever called.
  - Beyond that, a block-by-block comparison with the obj lines neutralised still leaves **74 of
    295 blocks** with semantic diffs:
    - SWF4 `"10x"` abandons the set in `setProperty`. We prefix-parse it to 10.
    - SWF4 `_xscale` quantisation: 2 → `1.9989013671875`, and `-5` → `4.998779296875`.
    - Other SWF4-specific cases.
  - **Correction to a doc of record:** `RUFFLE_VS_FLASH_DIFFERENCES.md:604-606` says "SWF4 keeps
    prefix-parsing (`"10x"` is 10 there)" as Flash behaviour. Flash's own oracle here shows
    `setProperty(_x,"10x")` → 0, then 1: the set is abandoned. The prefix-parse claim may still
    hold for arithmetic, but not for `setProperty`. Those lines are inside Ruffle's diff set, so
    this changes no pricing.
- **Completion mechanism, if the user ever wants it:** a policy ruling that accepts the
  `swf4opcode` `pass → ruffle_matched` trade, plus the 2-line `_name` fix = +1 effective.
  Otherwise, a SWF4 `setProperty` semantics arc (the list above) for an exact pass.

## 10. Rows 10-11: re-verified NO-GOs (not re-derived)

- **`avm1/globals_monkeypatch`.** 39/246, 158 actual; ours differ on 207 lines and Ruffle on 9, so
  198 are ours-only. That is identical to s20: expected is still 246, so there has been no upstream
  drift since s20. The s19 N3 `_global`-indirection-arc verdict stands.
- **`movieclip_destruction_test3`.** Graded file `output.fp10.txt`: 5/18, 16 actual, 9 ours-only.
- **`movieclip_destruction_test4`.** 8/40, 24 actual, 26 ours-only.
- Both destruction rows keep the same signature: `nestedMovieClip removed at frame 10` and
  `actions here should not be executed` are missing, and `getDepth()` returns 10 where Flash
  returns -32779. That is s20 `w1-gnash-actionorder` B5.
  - Completion mechanism: `MOVIECLIP_VN_PLAN` Phase 6/7, plus deferring `removeMovieClip` to the
    end of the calling frame script.
  - These two are listed in that family's NO-GO, but they are **not** members of the struck
    `action_order` rows. The strike at `polish-sweep-arc.md:2269-2277` names action_order ×7,
    `missing_frame_scripts`, `looping_child_swf*` and `button_nested_frame_simple` as the
    "timeline-order arc". So **`missing_frame_scripts` sits inside a "worth its own solo session"
    bullet from s17**, and §3 shows it is now two small hunks, not a session.

## 11. Evidence

- Saved actual outputs and logs for all 13 rows:
  `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/95edbfc6-8c64-421c-a520-00c101a9b3ea/scratchpad/w1-trace-tail/*.actual.txt`
  and `*.log`.
- `ooi.py` in the same directory computes the ours-only set with verify_output's own functions.
- Prototype diffs: `exp_s4_order_plus_s3sim.diff` and `exp_button_empty_state.diff`. Experiment
  logs: `exp2_*` (orphans / S4), `exp3_*` and `exp4_*` (buttons).
- Dispositions checked (rule 2) for every row, across all `ignored_tests.txt` files and the
  avm1/avm2/gnash `_investigation/*.md` docs:
  - `sound_load_multiple` and `simplebutton_childevents_multichild` are in `avm2/ignored_tests.txt`.
  - `set_property_values` has the `RUFFLE_VS_FLASH_DIFFERENCES.md` swf4opcode entry.
  - None of the others is dispositioned.
- No upstream drift on any of the 13 rows: every expected line total equals the board.

## 12. New unclaimed leads

1. **The FRAME_SCRIPTS orphan/stage inversion (§3) is corpus-wide, not a one-test fix.** Any
   Loader-content or script-created orphan with a frame script is affected. After it lands, re-grade
   the `from_shumway/as3-loader` rows and `avm2/loader_*`; some may move.
2. **Empty SimpleButton states now yield a Sprite (§2).** `upState`/`overState`/`downState`/
   `hitTestState` getters will return a Sprite instead of `null` for empty states, which matches
   Ruffle. Check the render walk and hit-testing on an empty `hitTestState`: it must hit nothing.
3. **SWF4 `setProperty(_name, bool)` → `1`/`0`** (§9). A 2-line correctness fix with no flip.
4. **`RUFFLE_VS_FLASH_DIFFERENCES.md:604-606` overstates SWF4 prefix-parsing** (§9). Flash
   abandons `setProperty(_x,"10x")`. Correct the doc wording.
5. **G5 press-side and DefineButton hover** (§6). These are the next steps after the move-side
   topmost pick.
