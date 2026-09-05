# w2-avm1-hitarea — wave 2: AVM1 `MovieClip.hitArea` slice 1 (+2 priced, +1 behind a second mechanism)

Read `BRIEFS_COMMON.md` (incl. wave-2 rules) and `SIBLING_FILE_MAP.md`, then the diagnosis of
record: `w1-trace-avm1-report.md` §3 (H1: root cause, Ruffle's semantics from `~/CC/ruffle`
commit `03fc070fa`, "where it goes in our tree", the two structural gaps, the second mechanism,
and the DISPOSITION TRAP). Isolated worktree; no commits.

## Scope
Implement AVM1 `MovieClip.hitArea` (feature currently absent): resolve the `hitArea` property at
button-mode pick time, depth-descending TOPMOST pick, removed-clip exclusion — per the report.
Targets: `from_shumway/avm1/hitarea` 2/4 → pass and `avm1/hitarea_remove_sibling` 3/4 → pass.
Then, if within budget, the second mechanism for `avm1/hitarea_lazy_getter` 0/6: the
MovieClip-prototype virtual-property fall-back the report locates at `action.c:52805`/`:46450`
(mirror the `instanceof` fall-back at `:47349`) — state its blast radius explicitly and canary
it. `hitarea_sweep` (33 lines) and `hitarea_remove_owner_drag` are a second arc (shape-based
picking) — grade them before/after and report the deltas; do not chase them.

**Disposition trap (do this FIRST in your worktree copy):** `from_shumway/avm1/hitarea/output.ruffle.txt`
is a STALE oracle (deleted upstream when Ruffle fixed hitArea); it contains exactly the 3-line
output a partial fix emits and would falsely score `ruffle_matched`. Delete it from your copied
test dir and grade against `output.txt` only. (The coordinator is pruning it in the main tree.)

Files: `SWFModernRuntime/src/actionmodern/action.c` — mouse pick / button-mode hit test /
virtual-property regions. Siblings: w2-avm1-function (Function/arguments/enumeration regions of
`action.c`), w2-avm1-goto (`swf.c`). Self-localize with new static helpers.

## Verification (per-test before/after)
Headline: the 5 hitarea tests. Canaries — mouse picking is blast-radius-heavy: `avm1/button_*`,
`avm1/mouse_*`, `avm1/hittest*`, `avm1/movieclip_hittest*` (passing), `avm1/rollover*`/`onrollover*`,
`avm1/drag*`/`startdrag*`, `avm1/focus*` (sample 4), `from_shumway/avm1/*` passing tests that use
the mouse (grep `mouse|press|release|rollOver` in their .as/README), and the `regression` suite's
AVM1 mouse/button tests. Bar: byte-identical `--diff` output before/after. Run 3 canaries in
`--mode=graphics`. `-P 2`, compile timeout 2400, `--recompile` on first use of copied dirs.

## Deliverables
`SWFRecompDocs/plans/session18-fanout-reports/w2-avm1-hitarea.patch` + `w2-avm1-hitarea-report.md`
(NEW files first; ledger; the lead "AVM1 rollover picking is not a topmost pick — every
AABB-containing button-mode clip fires" — say whether your topmost pick changes that and what it
did to the canaries). Copy to the main tree if allowed. Runtime-only → copying
`SWFRecomp/build` is valid.
