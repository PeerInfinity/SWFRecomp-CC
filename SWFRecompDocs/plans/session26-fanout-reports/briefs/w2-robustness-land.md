**Land the runtime-robustness prototype, plus the aliasing hardening and the remaining capacity caps.** Categories: `avm1`, `regression`, `from_gnash`, `from_shumway` (+ `avm2` for the build-flag A/B).

Read `SWFRecompDocs/plans/session26-fanout-reports/w1-runtime-robustness-report.md` in full and start from `w1-runtime-robustness-prototype.patch`. Rebase it onto current origin/master. Several s26 patches have landed in `tag.c` and `action.c` since its base `ec07cc9e`; the local `n-pixel-pass` session is fixing `tag.c ng_attached_run_tree`, so don't touch that function.

**Oracle goldens (coordinator-run, exporter `0ddd12b6a`):**
- `SWFRecompDocs/plans/session26-fanout-reports/w1-local-oracles/robustness/avm1_many_defs_registry.ruffle-0ddd12b6a.txt`
- `…/avm1_pixelbounds_dynamic_child.ruffle-0ddd12b6a.txt`

Both are byte-identical to your predictions. Commit them as each fixture's `output.txt`, together with the generated
`test.swf` (`regression/` tracks `test.swf`).

**Then:**
1. Make `VAL()` a may_alias typedef macro (report §4 recommendation 1). Check every `VAL(type,` use inside other macros.
2. Add `-fno-strict-aliasing` to EVERY build path in the report's §4 table:
   - `verify_output.py` native and wasm;
   - `SWFRecomp/scripts/*.sh`;
   - `wasm_wrappers/bundle/build.sh`;
   - `docs/recompiler/pipeline_graphics.js`;
   - CMake.

   Grep-prove the WASM paths you can't build.
3. The other caps from the report's "New unclaimed leads", each growable and each with a fixture:
   - `MAX_CXFORM_OVERRIDES` 256 restore-stack (pixel; 2-frame tinted container with 300 children);
   - filter side tables 32/32;
   - `MAX_TF_PARAGRAPHS` 32 / `MAX_LAYOUT_LINES` 256;
   - `MAX_FUNCTIONS` 2048.
4. Two crash-class leads from sibling reports:
   - A malformed DefineFunction2 whose register index is ≥ `register_count` smashes the C stack in recompiled
     `func2_*`. Ruffle ignores out-of-range register writes. Clamp or ignore in the recompiler; see
     `w1-avm1-dispatch-scope-report.md` "New unclaimed leads".
   - `from_gnash/misc-swfc.all/gotoFrameFromInterval` (CI-excluded) grows memory until the OOM killer takes it in
     about 17 s, both before and after the s26 patches. Diagnose; it is a runaway, not just a wrong answer. Both
     `w1-trace-tail-audit-report.md` and the dispatch-scope report name it.
   - Optional: shumway `esc`'s AVM2 #1009 in a script-init class constructor (`w1-trace-tail-audit-report.md` leads).

**Gate:** the report's 172-test sweep plus the regression suite, both modes, identical outside your ledger.

**No-graphics:** `ng_shared.c` is shared; run every headline in both modes.

**CI note for the coordinator:** the flag changes ccache keys, so the first run recompiles everything.

**Siblings:**
- `w2-loaded-shell-phase2` edits `ng_shared.c` `ng_enumerateChildren` and `tag_stubs.c`;
- `w2-tail-bitmap-draw` edits `tag.c` (`ng_getBitmapByIndex` next to `ng_registerBitmapMetadata`, whose table you
  make growable). Coordinate by keeping your changes to the table decl and the register function.
