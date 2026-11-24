**Land the AVM1 leftovers prototype, re-targeted to FLASH** (w1-avm1-leftovers). Categories: `avm1`, `from_gnash`, `from_shumway`, `regression`.

Start from `session27-fanout-reports/w1-avm1-leftovers-prototype.patch` (`action.c` +342/−210, `tag.c` +22) and its fixtures. **The coordinator ran Flash Player 32 on every fixture** (`SWFRecompDocs/plans/session27-fanout-reports/w1-local-oracles/w1-avm1-leftovers/<fixture>/flash.wrapped.txt`; read `SWFRecompDocs/plans/session27-fanout-reports/w1-local-oracles/README.md` "Batch 2"). The analytic/Ruffle goldens are WRONG on 5 of them:
- `avm1_edittext_path_variable_scope` / `_same_frame`: Flash reads `undefined` where Ruffle binds (`s.mc.foo=undefined`, `_root.pv=undefined`, …). First check that the fixture is valid for Flash (SWF version, DefineEditText flags, variable-path syntax Flash accepts), then match Flash.
- `avm1_resolve_dotted_getvariable`: Flash never calls `__resolve` for the intermediate segment `b` (`o.b.c = ` empty); it calls it for the final `zz` and prints `o.zz = [object Object]`. So master's existing behaviour may be closer to Flash than the Ruffle derivation. Match Flash.
- `avm1_set_new_text_format_size`: Flash's default font reads `Times` (not `Times New Roman`), and the size stays 12 after `setNewTextFormat` + `text=`. Re-examine item 4 against this: it may be a NO-GO.
- `avm1_swf6_case_insensitive_builtins`: Flash == golden except `getDepth` = −77824 (−16384 expected). Check the fixture's depth arithmetic, then match.
- `avm1_swf7_case_sensitive_builtins`: Flash == golden.
- `avm1_mc_button_unified_pick` and `avm1_edittext_cut_copy_selection` need mouse/clipboard input, which neither oracle can replay. Their goldens stay analytic + Ruffle-runner (LOCAL ORACLE REQUEST: Ruffle test runner, `num_frames` ≥ input steps).

1. For every item, keep the hunk only if its fixture then matches FLASH (or, for the two input fixtures, the Ruffle runner). Drop or rework hunks that Flash refutes, and name each refutation.
2. Land the fixtures under `regression/` with **Flash's trace** as `output.txt` (check the `--wrapped` cut against `num_frames`).
3. Re-run the w1 argued sweep (299 rows; at least the item-1 mouse set, items 4–5 text set, item 6 case set and the regression suite) in graphics, plus no-graphics for the mouse and case sets.
4. If time remains, take leads 2 (SWF7 case leak, fixture already matches Flash), 3 (SWF6 version gate on bare `getNextHighestDepth`/`getInstanceAtDepth`) and 6 (maxChars clips the insertion). For each new behaviour, put a fixture under LOCAL ORACLE REQUESTS (FLASH).

Siblings in `action.c`: `w2-draw-cx-text` (`rasterizeMovieClipToBitmap`), `w2-applyfilter-cm` (`bitmapDataApplyFilter`), `w2-timers-land` (watch table, `actionGetMemberImpl` dead branch), `w2-loaded-shell-land` (loaded-movie lookup arms in `actionGetMemberImpl`/`resolveSlashPathToMC`), `w2-exec-order-land` (`actionDispatchEnterFrameHandlers`). Name every function you touch.
