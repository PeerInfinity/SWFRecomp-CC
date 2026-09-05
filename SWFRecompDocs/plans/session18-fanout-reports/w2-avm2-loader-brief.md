# w2-avm2-loader — wave 2: loaded-child boot order + loadBytes event ordering (+2 firm, +1 likely)

Read `BRIEFS_COMMON.md` (incl. wave-2 rules) and `SIBLING_FILE_MAP.md`, then the diagnosis of
record: `w1-trace-display-report.md` §2 L3 and L7, §3 (LoaderInfo `unload` HOLD, instance-name
counter HOLD — do NOT take the counter), §4 (`LoaderLoadBytesTest` NO-GO), §5. Context: the
Multi-SWF arc (2026-09-03/04, `SWFRecompDocs/status/child-*.md`) owns the child-boot code — read
`child-timeline-advance.md` and `child-placed-clip-uninit.md` before editing. Isolated worktree.

## Scope
1. **L3 — a loaded child's root class ctor runs BEFORE its frame-1 children exist**
   (`loader_boot_child_swf` runs the ctor before `run_frame_internal` / `flush_queued_places`).
   Ruffle places frame-1 children first. Targets: `avm2/loader_try_click_root` 0/16 → pass (5×
   `#1009` currently drop the load) and `avm2/loader_duplicate_class` 3/48 → pass likely (two
   misplaced lines + a `#1034`; the report's §5 says it is 3 lines of content, not 45 — grade with
   `--save-actual` positional compare).
2. **L7 `avm2/large_preload_from_bytes` 41/51 → pass:** pure ordering — `exitFrame` must precede
   the loadBytes init/complete block (one-position rotation in the tick/executor drain).

## Verification
Headline: the 3 tests. Canaries — child-boot order is blast-radius-heavy: every PASSING
`avm2/loader_*` test (there are ~25; run them ALL), `avm2/loaderinfo_*`, `from_shumway/as3-loader/*`
passing tests, `mixed_avm/*` passing tests, `import_assets/*` (3), and the `regression` suite's
loader/child tests (grep README for load|child|Loader — the Multi-SWF fixtures
`avm1_parent_child_*` included; read READMEs before calling a flip a regression). Byte-identical
`--diff` before/after is the bar. Run 4 in `--mode=graphics`. `-P 2`, compile timeout 2400,
`--recompile` on first use.

## Deliverables
`SWFRecompDocs/plans/session18-fanout-reports/w2-avm2-loader.patch` + `w2-avm2-loader-report.md`
(NEW files first; ledger; refutations; unclaimed leads incl. the `unload` HOLD if you learn more).
Copy to the main tree if allowed. Runtime-only → copying `SWFRecomp/build` is valid.
