# RETIRED (2026-07-17) — Function-Dispatch Consolidation is COMPLETE

This living session prompt is retired. The Function-Dispatch Consolidation —
all stages (0–5) plus the full normalization pass (b), including the
value-over-effort remainder — is **done**. Every dispatcher funnels through
`invokeFunctionValue`, the legacy `invokeSpecialFunction` is deleted, and
`tools/divergence/gates/check_dispatch_funnel.py` is GATE-GREEN.

- **Source of truth / full history:** `SWFRecompDocs/plans/function-dispatch-consolidation-plan.md`
  (Status header + the "Pass-(b) remainder landing note (2026-07-17, fifth
  session)" at the end of §4).
- **Per-dispatcher dossiers:** `SWFRecompDocs/plans/dispatch-stage4-dossiers.md`.
- **Regression guards:** `ruffle-tests/tests/swfs/regression/` (README documents each).

The pass-(b) remainder was drained on 2026-07-17: six commits landed
(`efec1fa20` root-enterFrame version switch, `da78adfd8` onUnload t1 local
frame, `e5e392601` convertFloat t1 this push, `730462ce8` sort-comparator t2
captured scopes, `393b217a4` watch Site-C userData/D6, `2579ee250` lv_url_encode
migration + invokeSpecialFunction deletion). Five low-value candidates were
documented NO with evidence (sound-family `arguments` — probe-disproven; watch
D1/D8 — pending a Flash oracle; LV grandparent-caller; MC-arm t1
`g_event_this_mc`). No work is owed.

The full original prompt text is preserved in git history (see this file before
this commit).
