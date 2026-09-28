# w1-mixedavm-tail — session 21 wave 1 (main tree read-only, scratch prototypes only)

Files written by this agent (docs only, no source edits in the main tree):

    SWFRecompDocs/plans/session21-fanout-reports/w1-mixedavm-tail-report.md
    SWFRecompDocs/plans/session21-fanout-reports/w1-mixedavm-tail-proto-links.patch   (prototype, NOT for merge as-is; `git apply --check` clean on HEAD 263427d08)

All runs were sequential under load (load average 12–17), with `SWFRECOMP_COMPILE_TIMEOUT=2400` and `--verbose`.
Prototypes were built in private scratch roots (`<scratchpad>/w1-mixedavm-tail/mini{,2}`: a copy of
`SWFModernRuntime`, the main tree's `SWFRecomp/build/SWFRecomp`, and the test dirs copied in), never in the main tree.

## 0. Verdicts and flip prices

| row | baseline (graphics, re-run today) | verdict | flip | cost |
|---|---|---|---|---|
| `text/links_in_scrolled_text` | 0/1 | **GO. Premise refuted twice.** It needs 3 small runtime mechanisms, not "line model / wrap-aware hit test". The prototype **PASSES in both modes.** | **+1** | S (runtime-only, AVM1) |
| `from_shumway/as3-loader/LoaderLoadBytesTest` | 1/4 | **GO. The standing NO-GO ("recompiler arc") is REFUTED.** It needs one harness change. **PASSES in both modes** when the embedded SWF is extracted. | **+1** | S (`verify_output.py` only) |
| `avm2/selection_onsetfocus_mixed_avm` | 0/5 (emits nothing) | **NO-GO.** It is **not** "one mechanism", as the board claims (§3). It needs 4. | 0 | session-sized (leg F) |
| `avm2/focus_events_mixed_avm_edittext` | 0/49 | **NO-GO** (leg F). The RVF flag is stale/misapplied (§2). | 0 | session-sized |
| `avm2/mouse_pick_loader_avm1` | 16/42 | **NO-GO**. 3 mechanisms, unchanged since s19. The RVF flag is misapplied (§2). | 0 | session-sized |
| `mixed_avm/avm2_loads_avm1_events` (KF) | 5/26 | **HOLD**. The diff vs `output.ruffle.txt` is byte-for-byte s20 §4.1's (child-frame and `init` ordering). | 0 | cross-VM load-tick rotation |
| `from_shumway/as3-loader/events/loader-events` (KF) | 5/36 | **HOLD**. The diff vs `output.ruffle.txt` is exactly s20 §4.2's 3 defects. | 0 | counter + rotation + httpStatus |
| `mixed_avm/avm1_loads_avm2` | not touched | NO-GO of record. Nothing found here covers it. | — | — |

**Wave-2 GO total: +2 effective** (`links_in_scrolled_text`, `LoaderLoadBytesTest`). The two are independent:
one is AVM1 runtime (`action.c`/`ng_shared.c`), the other is harness only (`verify_output.py`). Neither touches a sibling's file
(`w2-arraysort-m3` owns only the Array-sort path of `action.c`; this change is in the TextField scroll/asfunction code,
~20 000 lines away).

---

## 1. GO: `text/links_in_scrolled_text`

### 1.1 Oracle first

I appended AVM1 traces of `text1.{scroll,maxscroll,bottomScroll,textHeight,hscroll,maxhscroll,_height,_y,textWidth,length}` to
the fixture's DoAction (scratch `patchswf.py`). I ran the result through the Ruffle exporter with the fixture's input (`RUFFLE_INPUT_FILE`),
and through our runtime:

```
            Ruffle   ours(HEAD)
scroll         8        9
maxscroll      8        9
bottomScroll  14       15
textHeight   397      426
length       740      740      <- s16's "738 units, char_idx 740 past the end" is STALE
Success!     yes      no
```

### 1.2 Three mechanisms. All three are necessary, and together they are sufficient.

1. **`maxscroll` uses a line-count formula plus a phantom last line.** Owners are `action.c:55338` (`computeScrollProperty`
   uniform-font path: `maxscroll = total_lines - visible_lines + 1`) and `action.c:55374` (`recomputeMaxScroll`, the one the
   `scroll` setter clamps with, which has the same formula). Ruffle `edit_text.rs::maxscroll` is pixel-based:
   `target = text_size.height - (bounds.height - 2*GUTTER)`, then the first line with `offset_y >= target`. Also,
   `html/layout.rs:374`: **`text_size` skips an empty last line for NON-input fields only.** Our mixed-font twin
   `ng_computeScrollMixedFont` (`ng_shared.c:1945`) already has the pixel formula, but it uses `full_text_height`, which
   includes the phantom line that the trailing `</p>` newline creates. For this field that gives 9 instead of 8.
   Our line metrics are right. Instrumented: 571-twip pitch, 530.x vs Ruffle's 530, so s16's "line-height estimate is short"
   branch is refuted.
   *Prototype:* route the uniform path and `recomputeMaxScroll` through `ng_computeScrollMixedFont` (with `run_count = 0`),
   and use `reported_text_height` for `target` unless `tf_is_editable()`. After that, scroll/maxscroll/bottomScroll = 8/8/14,
   which matches Ruffle exactly.
2. **The hit test ignores `scroll`/`hscroll`.** This is s16's HELD patch `w2-smalls-links_in_scrolled_text.patch`, which still
   applies cleanly. With (1) in place, the click resolves to char 708, inside run 27 `[707,710) href='asfunction:callback'`.
3. **NEW, never named before: `handle_asfunction` cannot find root-timeline functions.** `action.c:78174`: for a TextField on
   `_root`, `container == &root_movieclip`, whose `dynamic_props` is **NULL**. Root timeline vars live in the global `var_map`,
   so `callback` is never found and the function returns silently (instrumented: `func=(nil)`). `avm1/asfunction` passes only
   because its field sits inside a `container` sprite.
   *Prototype:* when `container == &root_movieclip`, fall back to
   `hasVariable(name) ? getVariable(name) : NULL` before `_global`.

### 1.3 Prototype evidence (scratch root, not main tree)

- `text/links_in_scrolled_text`: **PASS no-graphics, PASS `--mode=graphics`.**
- Sweep of 27 AVM1 text/scroll/caret/asfunction rows, run with the prototype (`--recompile`): every row that passes in CI still
  passes. `avm1/`: `asfunction`, `edittext_scroll`, `edittext_hscroll`, `clone_sprite_edittext{,_dynamic}`, `swf4_vars`,
  `textfield_props_swf6/7/8`, `edittext_drag_select`, `edittext_place_caret`, `edittext_input_newlines`,
  `edittext_text_height_leading`, `edittext_newlines`, `edittext_focus_selection`. `text/`: all 4
  `text_caret_placement_*`. Also `from_shumway/acid/acid-textfield-scroll` and `regression/avm1_parent_child_text`.
- Rows that are not `pass` at base were checked with a **byte-for-byte A/B of actual output** (base runtime vs prototype, same
  mode, `--save-actual`). This covers the `ruffle-matched-hides-regression` trap. Results:
  `avm1/edittext_onscroller` (ruffle_matched), `avm1/textfield_props_swf5` (ruffle_matched),
  `from_gnash/actionscript.all/TextField-v6/v7/v8` (output_mismatch, ACC+KF) and `regression/avm1_parent_child_text` are
  all **IDENTICAL**.

### 1.4 Wave-2 scope (S)

`action.c` (`computeScrollProperty` uniform branch, `recomputeMaxScroll`, `handle_asfunction`, and the 3 hit-test call sites
from the s16 patch), `ng_shared.c` (`ng_computeScrollMixedFont` target plus an `is_input` **parameter**; the prototype's
`g_ng_scroll_is_input` global is a shortcut, so replace it) and `tag.h`. Do not merge the prototype as-is: it has `PROTO`
markers and the global.

Open questions for wave 2:
- Should `textHeight` (uniform `ng_computeTextHeight`, which counts the phantom line: 426 vs 397) move too? It is NOT needed for
  the flip, and it has a larger blast radius, so leave it out and name it as a lead.
- `tf_is_editable` returns 1 when `type` is unset. Check that every `DefineEditText` field gets `type` stamped before
  `maxscroll` is read, or gate on the EditText ReadOnly flag instead.
- Canary: `text/text_caret_placement_scroll` (s16's pairing) plus the sweep list above. Scratch list:
  `<scratchpad>/w1-mixedavm-tail/sweep_list.txt`.

---

## 2. The RVF flags on `focus_events_mixed_avm_edittext` and `mouse_pick_loader_avm1` are MISAPPLIED

`RUFFLE_VS_FLASH_DIFFERENCES.md` has **no entry for either test**. They appear once, at `:523-524`, inside the `avm2/avm1_root`
entry, as examples of "the session-sized machinery" that entry's `pass` ceiling would need. Neither test has
`known_failure` or `output.ruffle.txt`, and Ruffle passes both, so both are graded against a Flash `output.txt` that Ruffle
itself matches. **There is no Ruffle-vs-Flash divergence on these rows.** The inventory's RVF flag should be dropped. It was a
grep hit, not a disposition.

## 3. NO-GO: `avm2/selection_onsetfocus_mixed_avm`. It is NOT "one mechanism".

Ruffle oracle (exporter, `RUFFLE_LOCAL_FETCH_DIR` recipe, fixture `input.json`) reproduces `output.txt` exactly.
I disassembled `avm1.swf` (scratch `avm1dis.py`). The listener is
`onSetFocus(oldf,newf){ if (oldf==txt || newf==txt) trace(oldf+" "+newf); }`. I then patched the `return` out and re-ran the
oracle:

```
null null                      <- 3 AVM2-only focus changes (AVM2 objects cross as null)
null null
null null
txt.onSetFocus: null
null _level-61440.txt          <- suppressed in the real test
txt.onKillFocus: null
_level-61440.txt null          <- suppressed in the real test
```

So in the real test, **`txt` resolves to `undefined` inside the listener.** `null==undefined` prints the AVM2-only changes,
and the changes involving the text field are suppressed. Ruffle's `Avm1::notify_system_listeners` runs with
`active_clip = stage.root_clip()`, the **AVM2** root, so unqualified lookups miss the AVM1 child's `txt`. The row needs:
(a) AVM2 tab order descending into `AVM1Movie` and including AVM1 EditText (`avm2_display.c:16118 fill_tab_order`);
(b) a focus slot that can hold an AVM1 object (`g_stage_focus` is `Avm2Object*`; `update_focus_on_press` at `:15932` drops AVM1
picks); (c) the AVM1 `Selection` broadcast plus `onSetFocus`/`onKillFocus` fired from AVM2 focus changes, with AVM2 objects
mapped to `null` (today only `action.c:76974 selection_do_focus_change`, AVM1-only); (d) **the new one: the system-listener
scope quirk above.** It is still the cheapest *probe* of leg F, but it costs 4 mechanisms, not 1.

## 4. NO-GO: `focus_events_mixed_avm_edittext` (0/49) and `mouse_pick_loader_avm1` (16/42). Mechanisms by owner.

- **M-pick (shared by both): the AVM1Movie wrapper absorbs clicks meant for AVM2 siblings and the Stage.**
  `avm2_display.c:14961-14975`: the non-button arm ORs `point_in_self()` (the wrapper's bounds, which are the loaded
  movie's stage rect) with the AVM1 content walk. Evidence: every first click in `focus_events` reports
  `mouseFocusChange: [object Loader]` where Flash reports `[object TextField]` (a click on AS3 `as3Input1` at 300,30, under the
  top-most loader). In `mouse_pick_loader_avm1`, lines 6-7/16-17/28-29 (`rect_mc`, `Stage`) are answered by `Loader`.
  Dropping the OR is a plausible slice, but s17 kept it because the AVM1 walk may miss content, and it flips nothing alone.
  **Diff-line lead only.**
- **M-button: AVM1 button `onRelease` under AVM2** (`avm1 button clicked` ×4 in `mouse_pick_loader_avm1`, which in Flash
  *replaces* the AS3 `click` line).
- **M-focus: leg F**, the same (a)-(c) as §3 (`input_txt.onSetFocus/onKillFocus`, `Selection.onSetFocus: …` ×18 in
  `focus_events`).
- Completion: `mouse_pick_loader_avm1` needs M-pick + M-button + M-focus. `focus_events_mixed_avm_edittext` needs M-pick +
  M-focus + tab order into AVM1 (the tail `KeyDown Tab` block). Its `Selection.onSetFocus: undefined undefined` lines show
  the listener fires for AVM2-only changes. The listener there traces `oldf._name`, so it does not need §3's scope quirk.

## 5. HOLD rows (KF): re-verified, nothing moved

- `mixed_avm/avm2_loads_avm1_events`: `diff(ours, output.ruffle.txt)` = `child` printed before the root's `frame N` and the
  `frame 2/3/4` placement. That is s20 §4.1 (a)+(b), unchanged. Completion: route the AVM1-child boot through the
  `pending_boot` → next-drain rotation, after the tick's `enterFrame`.
- `from_shumway/as3-loader/events/loader-events`: `diff(ours, output.ruffle.txt)` = missing `root loader: httpStatus 1293`,
  `construct/added/run frame 1 in null` where Ruffle has `instance3`/`instance5` (the loaded root never gets
  `set_default_instance_name`), and the `run frame 1` placement. That is s20 §4.2, unchanged. Completion: counter +
  rotation + httpStatus. All 3 are required, and the ceiling is `ruffle_matched`.

## 6. GO: `from_shumway/as3-loader/LoaderLoadBytesTest`. The NO-GO of record is refuted.

s17/s18/s19/s20 all priced it as "recompiler arc: `DefineBinaryData` → SWF recompile". **It is not a recompiler arc.**
`loader_loadbytes` already size-matches payloads against the child-movie registry. `avm2/loader_loadbytes_events` and
`avm2/large_preload_from_bytes` embed SWFs the same way (`[Embed(mimeType='application/octet-stream')]`) and **pass**,
only because a byte-identical copy of the embedded SWF also sits on disk next to the test (`loadable.swf`,
`large_bytearray/test.swf`), and `find_child_swfs` (`verify_output.py:1109`) picks those up. `LoaderLoadBytesTest` ships no
`Loadee.swf`.

**Proof:** I extracted the `DefineBinaryData` (tag 87, char 1, 821 bytes, `FWS`) payload to `Loadee.swf` in a scratch
copy of the test dir and ran the unmodified runtime and recompiler: **PASS no-graphics, PASS `--mode=graphics`.**

**Wave-2 scope (S, harness-only):** in `find_child_swfs`, scan `test.swf` for tag-87 payloads with an `FWS/CWS/ZWS`
signature. Write each one to a generated file (a skip-listed generated dir, like the `Recompiled*` outputs). **Dedupe by
content hash against children already found on disk.**

**Blast radius, measured:** a whole-corpus scan finds exactly 4 SWF-bearing `DefineBinaryData` tags:
- `avm2/loader_loadbytes_events` — has an on-disk twin, so the dedupe skips it.
- `avm2/large_preload_from_bytes` — 2 payloads, both with on-disk twins under `large_bytearray/`, so the dedupe skips them.
- `LoaderLoadBytesTest` — the only new child.

Check that the generated file's registry key/filename cannot collide with the movie_id ordering of the existing children
(sort extracted children after on-disk ones). If the in-browser recompiler should ever gain the same behaviour, it needs a
matching change (`docs/recompiler/`); this is not needed for CI.

---

## 7. Refutations

1. **`links_in_scrolled_text` "needs a wrap-aware `ng_getCharIndexAtPoint`" (`avm2/_investigation/CURRENT_STATUS.md:206`)
   is REFUTED.** The field has WordWrap off (s16 decoded the flags), and wrap plays no part.
2. **s16 §5 "the residual is the vertical line model / line height short by one line" is REFUTED.** Line metrics match
   Ruffle to 1 twip. The residual is the phantom-line `maxscroll` formula (Ruffle's non-input `text_size` rule) plus the
   `asfunction` root lookup, a third mechanism nobody had reached because the click never landed on the link.
3. **s16's "738 u16 units, char_idx 740 past the end" is STALE.** `length` is 740 in both runtimes today.
4. **`LoaderLoadBytesTest` "recompiler arc" (s17 Row 5, s18 N2, s19, s20 §5) is REFUTED.** It is harness-only, see §6.
   s17's own completion mechanism ("register the tables keyed by payload size") already exists. Only the file is missing.
5. **s20's "`selection_onsetfocus_mixed_avm`: 5 lines, all one mechanism" is REFUTED.** It is 4 mechanisms, including a
   system-listener scoping quirk that no report had named (§3).
6. **The inventory's RVF flags on `focus_events_mixed_avm_edittext` / `mouse_pick_loader_avm1` are MISAPPLIED** (§2).

## 8. New unclaimed leads

- **`handle_asfunction` root lookup** (§1.2 #3) is a live bug for *any* `asfunction:` link in a root-placed TextField, not
  just this test. A `regression/` fixture with the Ruffle exporter as oracle is warranted once it lands.
- **AVM1 `textHeight` counts the phantom trailing-`</p>` line** in the uniform path (`ng_computeTextHeight`: 426 vs Ruffle
  397 here). The mixed path already excludes it, but it does so for input fields too, while Ruffle keeps it for input
  fields. This is latent. The only corpus observer found is this scratch probe.
- **AVM1Movie stage-rect pick fallback** (`avm2_display.c:14961-14975`) is the one mechanism shared by
  `focus_events_mixed_avm_edittext` and `mouse_pick_loader_avm1`. It is diff-line only, but it is the first slice of any
  leg-F funding.
- **Ruffle system-listener scope quirk**: `notify_system_listeners` runs AVM1 broadcaster callbacks with `active_clip = _level0`.
  If our AVM1 `Selection`/`Mouse`/`Key` broadcasts run listeners in the defining clip's scope, pure-AVM1 content could
  diverge too. It is unmeasured, so probe it with a pure-AVM1 fixture before believing it.

## 9. Reproduction (scratch, `<scratchpad>/w1-mixedavm-tail/`)

- `avm1dis.py <swf>` is a minimal AVM1 DoAction disassembler.
- `patchswf.py <in> <out> obj.prop,...` appends `trace("obj.prop="+obj.prop)` to the first DoAction.
- `probe/links_probe/` holds the oracle probe (Ruffle trace in `ruffle_trace.txt`). `sel_oracle/` holds the selection oracle
  runs (`trace*.txt`).
- `mini/` is the prototype root (links). `mini2/` is the base-runtime root plus the extracted `Loadee.swf`.
  `sweep_proto.txt` holds the sweep results and `ab_mini*_*.txt` the A/B actuals.
