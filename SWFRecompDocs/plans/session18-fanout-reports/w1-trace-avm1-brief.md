# w1-trace-avm1 — wave 1 diagnosis: AVM1-side trace failures (avm1, from_gnash, from_shumway/avm1, mixed_avm)

Read `BRIEFS_COMMON.md` first. Read-only: no source edits. Deliverable:
`SWFRecompDocs/plans/session18-fanout-reports/w1-trace-avm1-report.md`. Scratch dir: `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/w1-trace-avm1/`.

## Your board
**Head — new upstream hitArea family (added 2026-09-01, `~/CC/ruffle` commit `228774af1`; never diagnosed):**
- `avm1/hitarea_lazy_getter` 6 exp / 0 match (we emit 3 lines)
- `avm1/hitarea_remove_owner_drag` 10 / 3
- `avm1/hitarea_remove_sibling` 4 / 3
- `avm1/hitarea_sweep` 33 / 1 (we emit 20)
- `from_shumway/avm1/hitarea` 4 / 2 (older test, same feature — `MovieClip.hitArea`)
Read the upstream commit (`git -C ~/CC/ruffle show 228774af1 --stat` and the core/src/avm1 diff)
to learn the semantics Ruffle implemented; find our `hitArea` handling in
`SWFModernRuntime/src/actionmodern/action.c` (grep `hitArea`/`hit_area`).

**Recurring, undispositioned, not known_failure:**
- `from_gnash/misc-ming.all/action_order/PlaceAndRemove` 96 / 15 (we emit 45)
- `from_gnash/misc-ming.all/action_order/action_execution_order_test11` 32 / 26 — s17 report
  `session17-fanout-reports/wave1-timeline-order.md` has prior diagnosis (M5/M6 NO-GO) — read it,
  re-verify against HEAD, do not re-derive.
- `from_gnash/misc-ming.all/GradientFillTest` 278 / 123 (test.toml has `approximations`) — s17
  `w2-gfx-smalls-report.md` touched it; check what is left.
- `mixed_avm/avm1_loads_avm2` 7 / 3 (we emit 3 — truncation or early stop); prior notes in
  `polish-sweep-arc.md` (grep the name). The Multi-SWF arc (2026-09-03/04) changed child-movie
  loading substantially — re-verify from scratch.
- `from_gnash/misc-swfc.all/gotoFrameFromInterval2` 23 / 2 — RUFFLE_VS_FLASH-flagged and
  graphics-vs-no-graphics divergent (the ONE parity gap; BACKLOG has it). Only confirm whether the
  graphics-mode result differs locally (`--mode=graphics`) and why; do not implement.

**known_failure upstream (Ruffle fails these too; output.txt is Flash) — small-gap ones worth pricing:**
- `from_gnash/actionscript.all/Function-v6` 271/263, `Function-v7` 272/264, `Function-v8` 272/264 (8 lines each — same 8?)
- `from_gnash/actionscript.all/array-v6` 644/623, `array-v7` 654/604, `array-v8` 654/604
- `from_gnash/actionscript.all/MovieClip-v6` 936/901, `-v7` 969/934, `-v8` 1087/1020
- `from_gnash/misc-swfc.all/movieclip_destruction_test3` 18/5, `_test4` 40/8
- `avm1/globals_monkeypatch` 100/38
For KF rows: check whether `output.ruffle.txt` exists (then `ruffle_matched` is the reachable
target) and whether the gnash `_investigation/` docs already disposition the residual lines.

**Do NOT touch (dispositioned/blocked):** `set_property_values/*` (memory-documented float
blocker, `avm1/_investigation/blocked/SET_PROPERTY_VALUES_PLAN.md`), anything flagged IGN/ACCEPTED
in the inventory unless you find the disposition is stale.

## Method
Same as every wave-1 brief: run each test locally (`-P 2`, compile timeout 2400, `--verbose`),
read diff + stderr, find the mechanism, cluster, price flips honestly (full-pass flips only),
check dispositions, verdict GO/HOLD/NO-GO with files + LOC + canaries. Attack the brief.
Sibling agents: w1-trace-new (new AVM2 tests), w1-trace-display (AVM2 display/timeline/loader),
w1-trace-numerics (AVM2 numerics/strings/sound). `mixed_avm/avm2_loads_avm1_events` (KF) belongs
to w1-trace-display.
