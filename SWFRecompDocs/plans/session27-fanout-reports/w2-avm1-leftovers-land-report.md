# s27 w2-avm1-leftovers-land: land the AVM1 leftovers, re-targeted to FLASH

**New files**
- this report; `w2-avm1-leftovers-land.patch` = `git diff --binary origin/master -- SWFModernRuntime ruffle-tests/verify_output.py
  ruffle-tests/render_canary_tests.txt <the 8 new regression dirs>` (sources: `action.c` +~465/−226 and `tag.c` +22; no
  `verify_output.py` / canary-list change; `--binary` because it carries the 8 `test.swf`; proven with `git apply --check -R`);
- 8 regression fixtures, `ruffle-tests/tests/swfs/regression/`:
  `avm1_edittext_path_variable_scope/`, `avm1_edittext_path_variable_same_frame/`, `avm1_resolve_dotted_getvariable/`,
  `avm1_set_new_text_format_size/`, `avm1_swf6_case_insensitive_builtins/`, `avm1_swf7_case_sensitive_builtins/`,
  `avm1_mc_button_unified_pick/` (+`input.json`), `avm1_edittext_cut_copy_selection/` (+`input.json`).
  Each holds `create_test_swf.py`, `test.swf` (regenerates byte for byte), `test.toml`, `output.txt`; all but the SWF7 twin also
  carry `avm1asm.py` (the twin's generator calls the SWF6 one). Each docstring names its golden's source.
- 4 HELD fixtures (not in `regression/`, Flash oracle pending), `session27-fanout-reports/w2-avm1-leftovers-land-held/`:
  `avm1_bare_depth_methods_v7_gate/`, `avm1_bare_depth_methods_v7_gate_swf7/` (lead 3), `avm1_edittext_maxchars_clips_insertion/`
  (+`input.json`, lead 6), `avm1_set_new_text_format_instance/` (item-4 deferral twin). Their `output.txt` is analytic (Ruffle source).
  Committed with `git add -f` (`test.swf` is gitignored outside `regression/`); the `_swf7` twin's generator calls the SWF6 one.

Base: `origin/master` `53540ff02`. Baseline JSONs = master's `_results` = **`da51f878f`** (the wave-0 graphics/full/images run HAD
published, so it is the baseline; `results.json` no-graphics = `81d32b9b2`). Corpus: `download_tests.sh avm1 from_gnash from_shumway`,
2026-11-24 (upstream `1e604fa87`). Box: SETUP_STATUS all OK (Dawn on lavapipe). Graphics unless stated.

## Verdicts (lead)

| # | item | verdict | Flash says | fixture: master → patch (graphics, same box) |
|---|---|---|---|---|
| 1 | unified mouse pick (handler clips vs DefineButtons) | **GO, landed as prototyped** (no Flash input oracle) | — (Ruffle-runner request stands) | `avm1_mc_button_unified_pick` 6/21 → **pass** |
| 2 | EditText path-variable `:` separator + parent scope | **GO, landed** | Flash == Ruffle (direct mode) | `avm1_edittext_path_variable_scope` 6/10 → **pass** |
| 2r | …retry registers the late binding | **REFUTED by Flash, hunk DROPPED** | `s.t5.text=L` (never late-binds) | (same row) |
| 2b | same-frame target (w1 HOLD, ghost `mc`) | **GO, new hunk** (`tfVarWalkClipPath`) | Flash binds to the real child | `avm1_edittext_path_variable_same_frame` 6/11 → **pass** |
| 3 | `__resolve` through dotted paths | **GO, reworked to Flash** (w1 HOLD) | target segments NEVER resolve; GetVariable's final segment DOES | `avm1_resolve_dotted_getvariable` 0/13 → **pass** |
| 4 | `setNewTextFormat` size/font deferral | **NO-GO as prototyped; deferral hunks DROPPED.** Replaced by a Flash-proven gate: a plain-object argument is ignored | plain `{size,font}` object: nothing changes (Flash and Ruffle exporter) | `avm1_set_new_text_format_size` 2/5 → **pass** |
| 5 | Cut/Copy/Paste on the selection | **GO, landed as prototyped** (no Flash clipboard oracle) | — (Ruffle-runner request stands) | `avm1_edittext_cut_copy_selection` 2/9 → **pass** |
| 6 | SWF≤6 case-insensitive builtin arms | **GO, landed** | Flash == golden (direct mode) | `avm1_swf6_case_insensitive_builtins` 34/42 → **pass** |
| L2 | SWF7 case leak (MovieClip arms, number methods) | **GO, new** | Flash == golden | `avm1_swf7_case_sensitive_builtins` 37/40 → **pass** |
| L3 | SWF6 bare `getNextHighestDepth`/`getInstanceAtDepth` | **GO, landed code; fixture HELD** for Flash | pending | held `avm1_bare_depth_methods_v7_gate` 4/6 → pass; `_swf7` twin pass → pass |
| L6 | maxChars clips the insertion, not the tail | **GO, landed code; fixture HELD** for Flash typing | pending | held `avm1_edittext_maxchars_clips_insertion` mismatch (2 extra `changed` lines) → pass |

**Priced corpus flips: 0** (unchanged from w1). Every GO is a correctness fix pinned by a fixture. **8 new regression rows** (all
pass in both modes) are the expected-flip ledger below.

## Premise attacks on this brief (the oracle reading)

1. **The `--wrapped` captures are NOT valid goldens for 3 of the 5 "Flash refutes" fixtures.** `--wrapped` loads the SWF as an
   `AVM1Movie` child of an AS3 host (README: "`_level0` differs … use it only for self-contained content"). Every refutation that
   depends on `_root`/`_parent`/depth is that artifact, and the coordinator's own `flash.direct.txt` (the projector running the
   SWF as root, exactly like testutils) shows it:
   - `path_variable_scope` / `_same_frame`: **direct == the Ruffle golden** on every binding line (`s.mc.foo=F`, `_root.pv=P`, …).
     The only real Flash refutation is the **last line**, `s.t5.text=L` (Ruffle predicted `X`).
   - `swf6_case_insensitive_builtins`: direct reads `getDepth -16384` (== golden). `-77824` is the loaded-child depth.
   - Both fixtures finish their traces inside `num_frames` (10 / 11 lines, no per-frame trace), so direct mode is an exact cut.
     For the SWF6 case fixture (which traces every frame) the golden is direct's first 42 lines, which equal `--wrapped` except
     the two `getDepth` rows.
2. **`resolve_dotted_getvariable`:** direct == wrapped, so this refutation is real. Flash: no `__resolve` for target segments at all
   (`o.b.c` = empty, no `resolve b`/`resolve prim`; SetVariable `o.w.c` resolves nothing; the single `resolve w` comes from the
   following `GetMember o.w`), but `__resolve("zz")` for the final segment. Master resolved both; Ruffle resolves only the
   intermediates. Neither matched Flash.
3. **`set_new_text_format_size` is Flash-invalid for its own premise.** It passes a **plain object** (`InitObject {size, font}`),
   not a TextFormat. Flash ignores it, and so does the Ruffle exporter (`ruffle.txt`: `nsize=12` throughout; the w1 "Ruffle-source"
   golden mis-derived this). So it can neither confirm nor refute item 4's deferral. What it does prove: **master accepts a plain
   object and resizes the field** (`nsize=40`, `w/h` changed, `size0=40` after `text=`), Flash doesn't. Landed fix = that gate.
   - `font0=Times` vs `Times New Roman` is the **Linux projector's** default device-font name. Every corpus golden (Windows Flash)
     reads `Times New Roman` (`avm1/edittext_default_format`, `edittext_default_format_empty`, `clone_sprite_edittext`, gnash
     `TextFieldHTML-v6/7/8`). The landed golden is Flash's trace with that one platform token swapped back; the docstring says so.
   - The deferral of a REAL TextFormat's size/font (w1 item 4 hunks) is **HELD**: it needs a Flash run of a `new TextFormat()`
     twin (LOCAL ORACLE REQUESTS). The w1 prototype patch still carries those hunks verbatim (`tf_snf_*`).

## Mechanisms and the landed hunks (all `SWFModernRuntime/src/actionmodern/action.c` unless noted)

**Item 1 (as w1)**: `actionDispatchMCPress`, `actionDispatchMCMouseMove` consume the DefineButton pick that `tag.c`
`ng_update_button_states` now publishes (`g_btn_last_pick_obj/_sprite/_seq`, new `ng_btn_last_pick`); new static
`ng_defbutton_won_pick`; forward decl of `ng_roll_pick_topmost`. Button wrappers (`is_button_mc`) keep their own path.

**Item 2**: new statics `tfVarPathSep` (right-most `:` or `.`), `tfVarScopeClip` (parent, climbed past buttons), `tfVarResolveTarget`;
used in `actionNotifyPropertyChange`, `actionTryBindTextFieldVariable` (path branch) and `ng_syncTextToVar`.
**Dropped vs w1:** the retry-path `actionRegisterTextFieldBinding` call. `actionTryBindTextFieldVariable` keeps master's
`if (!set_initial_value) return 1;` (comment cites the Flash row).

**2b (new)**: `tfVarResolveTarget` first tries new static **`tfVarWalkClipPath`**, which walks a clip-only target (`mc`,
`_root.s.mc`, `_parent`, `this`) over `child_mc_cache` by parent + name (case-insensitive ≤ SWF6, removed/pending-removal clips
skipped, lowest depth wins). Only when a segment is not a clip child (or starts with `_` other than `_root`/`_parent`) does it fall
back to the GetVariable route.
- Measured root cause: during `s`'s frame-1 construction, `GetVariable "mc"` with context `s` returned a **different MovieClip** than
  `s`'s placed child (pointer probe: `res=…26c0`, child `mc`=`…ea50`), i.e. a ghost; and `_root.s.mc` was undefined (not yet
  name-reachable from root). The walk finds both. The underlying `actionGetVariable` ghost is **not** fixed (see leads).

**Item 3 (reworked)**: new global `g_path_walk_no_resolve`; `findResolveMethod` returns NULL while it is set. Set around:
- `actionGetVariableImpl`'s fallback dotted-path walk (intermediate segments only, beside the existing `g_path_walk_level0_undef`);
- `actionGetVariableImpl`'s colon/slash walk (target segments; the final `GetMember(prop)` runs outside it);
- `actionSetVariable`'s slash walk and its non-slash `GetVariable(target)` (the WHOLE target, final target segment included).
GetVariable's final segment still resolves (master already did that = Flash).
- Residual: a getter (`addProperty`) running inside an intermediate GetMember inherits the flag (same pre-existing shape as
  `g_path_walk_level0_undef`). The `actionSetVariable` dot-path at the `_dl_dot_path` slash-to-dot rewrite and the later
  `last_dot` GetVariable branch were not wrapped (not reached by the fixture; unprobed).

**Item 4 (reworked)**: `actionCallMethod` `setNewTextFormat` arm (`NO_GRAPHICS || OFFSCREEN_RENDER`) acts only when
`args[0]` is an object with `native_type == NATIVE_TEXTFORMAT` (set by `new TextFormat`, native `super()`, and the
`getTextFormat`/`getNewTextFormat` builders). All w1 `tf_snf_*` code and its 3 hooks (`actionSetMember` `text` and `htmlText` arms,
`tf_replace_selection`) are removed. The browser `#else` arm is unchanged.

**Item 5 (as w1)**: new statics `tf_selected_range`, `tf_is_password`, `tf_replace_selection` (body moved out of
`actionTextFieldInput`); `actionTextControlCopy`, `actionTextControlCut`, `actionTextControlPaste` rewritten on top
(`actionTextControlSelectAll`, `actionTextFieldImeCommit`, `apply_restrict_filter` hunks are context/moves from the w1 patch).

**Item 6 (as w1)**: `swf6CanonBuiltinName` + 3 tables; entry lines in `actionCallFunction`, `callArrayMethod`,
`callStringPrimitiveMethod`.

**Lead 2 (new)**: new static `mcArmCaseMiss` + table `k_mc_arm_names` (the 54 names the MovieClip/TextField `strncasecmp` arms of
`actionCallMethod` compare). In `actionCallMethod`, right after the registered-class bypass block, a SWF7+ (`EFFECTIVE_SWF_VERSION()`)
name that matches an arm only case-insensitively jumps to `_mc_user_dispatch` (user/proto lookup, case-sensitive) → undefined.
Number/Boolean primitive arm (after `_mc_user_dispatch`): a SWF7+ case variant of `toString`/`valueOf`/`hasOwnProperty` goes to
`primNumBoolCallProtoMethod` instead of the `strncasecmp` arms.

**Lead 3 (new)**: `actionCallFunction` bare `getNextHighestDepth` / `getInstanceAtDepth` arms gain `g_swf_version >= 7 &&`
(the CallMethod arms already had it; Ruffle `VERSION_7`). In SWF6 the name falls through to the normal unknown-function path.

**Lead 6 (new)**: `tf_replace_selection`: when inserting (`ins_len > 0`) into a field with `maxChars > 0`, room =
`maxChars - (len - selection_len)` (Ruffle `available_chars`); room ≤ 0 → return (no edit, no `onChanged`); else the insertion is
clipped to room. The old post-hoc tail truncation is removed. Cut (`ins_len == 0`) is unaffected.

**`SWFModernRuntime/src/libswf/tag.c`**: `ng_update_button_states` (+publish), new `ng_btn_last_pick` + 3 statics (w1 hunk, unchanged).

**Not touched**: `swf.c`, `swf_core.c`, `tag_stubs.c`, `ng_shared.c`, `timer.c`, `render_webgpu.c`, the recompiler,
`verify_output.py`, `render_canary_tests.txt`.

**Sibling overlap**: none of the functions above is in another wave-2 slot's list (`rasterizeMovieClipToBitmap`,
`bitmapDataApplyFilter`, the watch table / `actionGetMemberImpl` `efd` branch, the loaded-movie arms of `actionGetMemberImpl` /
`resolveSlashPathToMC` / `actionGetVariableImpl`, `actionDispatchEnterFrameHandlers`). **Closest contact:** `w2-loaded-shell-land`
edits loaded-movie arms of `actionGetVariableImpl`; my 3 hunks there are the dotted/colon path walks (flag set/restore lines only),
not the loaded-movie arms. `w2-timers-land` owns the watch table; I add a global `g_path_walk_no_resolve` next to
`findResolveMethod` (~line 9290) and touch nothing in `actionGetMemberImpl`.

## Per-test before/after (clean `origin/master` vs this patch, same box, graphics; `matching/expected`)

| test | master | patch | patch no-graphics |
|---|---|---|---|
| regression/avm1_edittext_cut_copy_selection | 2/9 mismatch | **pass** | pass |
| regression/avm1_edittext_path_variable_same_frame | 6/11 mismatch | **pass** | pass |
| regression/avm1_edittext_path_variable_scope | 6/10 mismatch | **pass** | pass |
| regression/avm1_mc_button_unified_pick | 6/21 mismatch | **pass** | pass |
| regression/avm1_resolve_dotted_getvariable | 0/13 mismatch | **pass** | pass |
| regression/avm1_set_new_text_format_size | 2/5 mismatch | **pass** | pass |
| regression/avm1_swf6_case_insensitive_builtins | 34/42 mismatch | **pass** | pass |
| regression/avm1_swf7_case_sensitive_builtins | 37/40 mismatch | **pass** | pass |
| held/avm1_bare_depth_methods_v7_gate | 4/6 mismatch | pass | — |
| held/avm1_bare_depth_methods_v7_gate_swf7 | pass | pass | — |
| held/avm1_edittext_maxchars_clips_insertion | mismatch (2/2 + 2 extra lines) | pass | — |
| held/avm1_set_new_text_format_instance | 4/5 mismatch | 4/5 mismatch (item-4 HOLD) | — |

(The unmodified w1 prototype on the same box, against the Flash goldens: cut_copy, unified_pick, swf6 pass; scope 1 mismatching
line (`t5`, the Flash refutation); same_frame 5; set_new_text_format 2; resolve 20 (misaligned); swf7 3.)
Held twin `avm1_set_new_text_format_instance` (real TextFormat; analytic golden): master 4/5, patch 4/5 — the one miss is
`unchanged w=false h=false`, i.e. exactly the item-4 deferral this patch does NOT land.

## Argued sweep (patch vs the CI baseline rows: status AND matching-line count)

| set (why) | rows | mode | movers |
|---|---|---|---|
| **regression suite**, every non-`avm2*` row (pre-existing, incl. `avm1_button_textfield_path_binding`, both `set_new_text_format` rows, `avm1_edittext_html_*`) | 136 | graphics | **0** (4 rows postdate `da51f878f`, all pass) |
| **Item 1 mouse set**: every avm1/gnash/shumway row whose `input.json` has a Mouse event | 64 | graphics + no-graphics | **0 / 0** |
| **Items 4–5 / L6 text set**: every corpus SWF whose (decompressed) bytes hold `setNewTextFormat` or `maxChars` (42), every row with TextInput/TextControl input (19) | 61 | graphics | **0** |
| **Item 6 case set**: every SWF≤6 corpus SWF holding a non-exact case variant of a name in the 3 canonicalization tables (scanner; superset of w1's 121) | 125 | graphics + no-graphics | **0 / 0** |
| **Lead 2**: every SWF7+ corpus SWF holding a non-exact case variant of a `k_mc_arm_names` name | 13 | graphics + no-graphics | **0 / 0** |
| **Lead 3**: every SWF≤6 corpus SWF naming `getNextHighestDepth`/`getInstanceAtDepth` | 8 | graphics + no-graphics | **0 / 0** |
| **Item 3**: every corpus SWF naming `__resolve` | 20 | graphics | **0** |
| **Item 2/2b**: path/binding rows (`textfield_variable`, `get_variable_in_scope`, `set_variable_scope`, `string_paths_variable_alias`, `string_paths_variable_scopes`, `with_variable_scopes`, gnash `TextField-v5..8`, `DefineEditTextTest`, `DefineEditTextVariableNameTest`) | 12 | graphics | **0** |
| **total distinct** | 401 graphics / 198 no-graphics corpus + 8 new | | **0** |

Baselines: graphics `results_graphics.json` at `da51f878f`; no-graphics `results.json` at `81d32b9b2`. The scanner decompresses
CWS/ZWS before matching, so rows with compressed bodies are included (w1's raw-byte scan missed some).

**Render canary** (`render_canary.py capture/compare`, md5, runtime-only change so no `--recompile`): the 22 standing-canary
members that intersect the sweep sets (`avm1/edittext_stylesheet`, `edittext_tag_indent`, `focusrect_mouse_swf8`,
`netstream_play_flv_screen`, shumway `3_joystick`, and 17 `regression/` render rows): **29/29 PNGs IDENTICAL, 0 trace/image status
changes.** The full 738-row canary was not run (≈5 h for two legs on 4 CPUs); the change class is AVM1 logic, no render code. No
canary member was appended: none of the 8 new rows has `[image_comparisons]`, so the canary cannot see them; their trace rows
are the guard.

## EXPECTED-FLIP LEDGER (what CI should show after this patch)

Trace axis (graphics and no-graphics; `regression` suite): **8 NEW rows, all `pass`** —
`avm1_edittext_cut_copy_selection`, `avm1_edittext_path_variable_same_frame`, `avm1_edittext_path_variable_scope`,
`avm1_mc_button_unified_pick`, `avm1_resolve_dotted_getvariable`, `avm1_set_new_text_format_size`,
`avm1_swf6_case_insensitive_builtins`, `avm1_swf7_case_sensitive_builtins`.
Corpus trace axis: **no movers expected** (0/401 + 0/198 above). Any corpus pass→fail is a regression of this patch.
Pixel axis: **no movers expected**; none of the 8 new rows has `[image_comparisons]`.

Golden provenance of the 8: Flash 32 direct (`path_variable_scope`, `_same_frame`, `swf6_case`), Flash 32 (`resolve_dotted`,
`swf7_case`), Flash 32 with the Linux font token swapped (`set_new_text_format_size`), analytic + Ruffle-runner pending
(`mc_button_unified_pick`, `edittext_cut_copy_selection`).

## Refutations (named)
- **w1 item 2, bug 3 ("the retry never binds")**: Flash 32 never late-binds either (`s.t5.text=L`). Hunk dropped.
- **w1 item 3 HOLD**: resolved against BOTH Ruffle and master — Flash resolves only GetVariable's final segment.
- **w1 item 4 ("trace-visible deferral")**: the fixture's premise was a plain object; Flash ignores it. Deferral NO-GO until a
  TextFormat-instance Flash capture; the real bug found is the missing TextFormat type check.
- **This brief's 4 "Flash reads undefined" / `-77824` refutations**: `--wrapped` artifacts; `flash.direct.txt` == Ruffle there.
- **w1 golden for item 4 "Ruffle: nsize=40"**: the Ruffle exporter (`ruffle.txt`) says 12; the analytic derivation was wrong.

## Not finished / completion mechanisms
- **Item 4 deferral (real TextFormat)**: HOLD → Flash capture of a `new TextFormat()` twin (request 2). If Flash keeps the existing
  text's size until `text=` (as Ruffle), land the w1 `tf_snf_*` hunks (w1 prototype patch) with that twin.
- **Lead 3 / lead 6 fixtures**: code is landed; fixtures HELD until Flash confirms (requests 3, 4). If Flash disagrees, revert the
  named hunk (`actionCallFunction` `g_swf_version >= 7 &&` gates / the `tf_replace_selection` maxChars block) — each is
  self-contained.
- **Items 1 and 5**: goldens stay analytic; Ruffle-runner confirmation (request 1).
- **`actionGetVariable` ghost child during construction (2b root cause)**: only the binding path is fixed. Any frame-1 script that
  names a same-frame sibling of a nested sprite may still hit the ghost (lead A below).
- **w1 lead 5** (the two other `.`-only path-variable sites, `actionSetMember`'s `child_mc_cache` scan and
  `tfDynamicRebindVariable`): not taken.

## New unclaimed leads
A. **Ghost child in `actionGetVariable` during sprite construction** (M): `GetVariable "mc"` from context `s` while `s`'s frame 1 is
   being built returns a NEW clip instead of `s`'s placed `mc`, and `_root.s` is not yet name-reachable. `tfVarWalkClipPath` is the
   pattern; the general fix belongs in `actionGetVariableImpl`'s child lookup / `findOrCreateMovieClip`. Probe: a DoAction inside a
   nested sprite's frame 1 reading a same-frame sibling.
B. **`setTextFormat` (and other TextFormat consumers) with a plain object**: Ruffle checks `NativeObject::TextFormat` there too;
   ours accepts any object. Same XS gate; needs a Flash capture.
C. **Item 3 residual SetVariable branches** (`_dl_dot_path` rewrite, `last_dot` branch) not wrapped in `g_path_walk_no_resolve`.
D. **Flash never late-binds a path-variable field** (`t5`): Flash does not bind it even when the target appears one frame later.
   Whether it binds after N frames or on the next `text=` is unknown; our retry still resolves (without registering). A longer
   Flash run of the `_scope` fixture (e.g. `num_frames = 8`, read `s.t5.text` each frame) would pin it.

## LOCAL ORACLE REQUESTS
1. **Ruffle test runner (input)**: `regression/avm1_mc_button_unified_pick` (`num_frames = 22`) and
   `regression/avm1_edittext_cut_copy_selection` (`num_frames = 6`); compare with the committed `output.txt`.
2. **FLASH, trace, direct**: `w2-avm1-leftovers-land-held/avm1_set_new_text_format_instance/` (`num_frames = 1`; the
   `new TextFormat()` twin of `regression/avm1_set_new_text_format_size`). Expected (Ruffle): `nsize=40` after setNewTextFormat,
   `unchanged w=true h=true`, `size0=40 font0=_serif` after `text=` (Linux Flash will print `Times` for the default font: swap it
   to `Times New Roman`). If Flash agrees, land the w1 `tf_snf_*` hunks with this fixture; if Flash says `unchanged w=false`, our
   current immediate-apply is right and item 4 closes NO-GO.
3. **FLASH, trace, direct**: `w2-avm1-leftovers-land-held/avm1_bare_depth_methods_v7_gate/` and `…_swf7/` (`num_frames = 1`).
   Expected = their `output.txt` (SWF6: every getNextHighestDepth/getInstanceAtDepth row undefined, with SWF6's empty string for
   undefined; SWF7: `number 6`, `movieclip _level0.c1`, `[type Function]`). If equal, move both dirs to `regression/`.
4. **FLASH, trace, direct, typing**: `w2-avm1-leftovers-land-held/avm1_edittext_maxchars_clips_insertion/` with
   `run_trace.py <dir> --type XYZ --type-after "ready"`. Expected: `ready: ABCD caret=1`, `changed #1: AXBCD caret=2`, and nothing
   more (Y and Z dropped). If equal, move the dir to `regression/` (it already has `input.json` for our runner).
