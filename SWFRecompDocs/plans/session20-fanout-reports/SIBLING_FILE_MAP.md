# Session 20 — sibling file map (who is editing what)

Updated by the coordinator as agents launch. **Wave-1 agents edit nothing.** Wave-2 agents:
check this table before you touch a file a sibling owns; self-localize (wrapper functions,
trailing struct fields, `static` symbols) and say so in your report.

| agent | wave | files it may edit | notes |
|---|---|---|---|
| w1-drift | 1 | — (read-only) | upstream drift audit + ignore-list re-test |
| w1-gnash-actionorder | 1 | — (read-only) | `from_gnash/misc-ming.all/action_order/*` cluster |
| w1-avm1-globals | 1 | — (read-only) | avm1 `global*_decls` / `globals_*` cluster |
| w1-gnash-array | 1 | — (read-only) | gnash `array-v5..v8`, `MovieClip-v6/-v7`, `argstest-*`, `TextField-*` |
| w1-stage3d | 1 | — (read-only; may prototype in a THROWAWAY worktree) | Stage3D A′ stencil/colorMask + B textures/RTT |
| w2-coerce | 2 | `SWFModernRuntime/src/actionmodern/action.c` (`propertyCoerceToNumber` / `spvPropertyCoerceToNumber` and their call sites ONLY) | huge file; stay in those functions |
| w2-evenodd | 2 | `SWFModernRuntime/src/avm2/avm2_display.c` (`gfx_line_style` / `gfx_finalize_path` region), AVM1 drawing-API equivalent if separate | |
| w2-gfx-text-smalls | 2 | device-face lookup (font/text TU) + EditText border quad emission | two independent fixes, keep as two patches |

## Shared, always-conflicting files
- `ruffle-tests/render_canary_tests.txt` — every graphics agent appends at EOF. Expected;
  the coordinator resolves with `git apply --3way` and keeps all blocks.
- `SWFRecompDocs/plans/session20-fanout-reports/` — namespace your own files by agent label.
