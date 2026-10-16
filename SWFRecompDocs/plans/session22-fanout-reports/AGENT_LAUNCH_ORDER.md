# Session 22 — worker launch-order / id map

Mode: CLOUD-FIRST (user, 2026-10-16) — every slot is a cloud session in env "SWFRecomp fan-out"
(`env_01QSs9FrDsLyis2RzQXg1UrW`), Opus, delivering on branch `fanout/<slug>`. Coordinator local.
Baseline: trace 4476 eff / 4551 (results `846adcc6b`, run on `4c450f076`); pixels 433/587
(images run `36515003936`). Upstream Ruffle synced `0dacba55f → 45366370e`.

## Wave 1 (diagnosis, 8 cloud workers — the concurrency cap)

| # | slug | axis | task | session id |
|---|---|---|---|---|
| 1 | w1-drift-avm1 | trace | AVM1 + gnash upstream drift (matrix/point/rectangle/context_menu rewrites, html img, AsBroadcaster) || session_017xPdvNzD1QpqzmWFhA57de (launched 22:03-22:06 UTC) |
| 2 | w1-drift-avm2 | trace | AVM2/fonts drift + harness semantics (num_ticks, NaN approx, ignore=true) + ignore re-test || session_014EjHH1tFvHsTTfCCHkmjPV (launched 22:03-22:06 UTC) |
| 3 | w1-crossvm | trace | cross-VM focus/pick/load-tick (6 rows) || session_01JQNgzi4t3ZGaDTvM1T8xmi (launched 22:03-22:06 UTC) |
| 4 | w1-trace-tail | trace | non-drift tail (MovieClip-v8, action_order, bug_483783 runtime_error, …) || session_01734S8K85eFhPCKDv96jBos (launched 22:03-22:06 UTC) |
| 5 | w1-stroke-staircase | pixel | 1-px stroke staircase parity, measured prototype || session_01XtPiAcw52mKcDbppWVpxJ5 (launched 22:03-22:06 UTC) |
| 6 | w1-offstage-filter | pixel | filter-layer bounds/edges, cab_mask_filters || session_01XoYMLVMtoh9SnQQwDhA41J (launched 22:03-22:06 UTC) |
| 7 | w1-pixel-smalls | pixel | near-passes + smalls; image-side ignore=true || session_01Tx6MKHzYM21omW2dfQGpry (launched 22:03-22:06 UTC) |
| 8 | w1-pixel-catastrophic | pixel | blank/unrelated/missing/wrong-fill clusters || session_01Fjmpo6LuUS5wfQZkUVsJaz (launched 22:03-22:06 UTC) |

**Pre-labelled DRIFT for the next CI read (w1-drift-avm1):** hidden pass→fail `avm1/as_broadcaster`,
`avm1/array_constructor` (→ SEGFAULT on new test); ruffle_matched→fail gnash `AsBroadcaster-v6..v8`,
`array-v6..v8`; deleted upstream `as_broadcaster_initialize`, `as_broadcaster_undef`,
`avm1/html_text_img_parsing`. None of these is a code regression.

## Wave 2 (implementation, cloud)

| slug | from | ledger (expected) | session id |
|---|---|---|---|
| w2-array-global | w1-drift-avm1 S2 | array_constructor, gnash array-v6..v8 | session_016pAABBwk2wbPvc3rNN3pCE |
| w2-as-core | w1-drift-avm1 S1 | as_broadcaster, AsBroadcaster-v6..v8, context_menu, context_menu_item, context_menu_swf6, as_setup_error | session_01CFASq4VYcgHb1361oQ9iiP |
| w2-crossvm | w1-crossvm slots 1-3 | mouse_pick_scroll_rect(+_loader,_button), mouse_pick_loader_avm1, avm2_loads_avm1_events (rm) | session_01WJfTLXUUuxzstmVBA8k32L |
| w2-queue-regex | w1-trace-tail A | action_execution_order_test6 (rm), pcre_find_fixedlength | session_014xtNST7fsKSbQ6RVBmTLTy |
| w2-goto-collator | w1-drift-avm2 slots 1(goto)+2 | goto_queued_invalid/swf9..11, collator_flags, collator_locale_ids_windows, collator_compare_basic | session_01HGTgTnncXGJ4Bi7uRJykNT |
