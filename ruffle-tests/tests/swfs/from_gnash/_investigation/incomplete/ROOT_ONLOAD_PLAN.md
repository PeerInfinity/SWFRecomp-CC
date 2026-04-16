# trace-as2/root_onload Plan (gnash/misc-swfmill)
<!-- TESTS: trace-as2/root_onload -->

Test: `ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/trace-as2/root_onload/`
Status (CI at 82a6ea07): `output_mismatch`, 2/4 (50%). Test has `known_failure = true` with `output.ruffle.txt` sidecar.

## Test shape (reverse-engineered)

Three scripts, three traces, plus a root `onLoad` handler installed but never explicitly called:

| Script | Trace | Location |
|--------|-------|----------|
| `script_0` | `CC.` | inside `sprite_1_frame_0` (inner sprite) |
| `script_1` | `C.`  | inside `sprite_2_frame_0` (outer sprite, which places sprite_1 at depth 1) |
| `script_2` | `R.`  | root's `frame_0` DoAction — also runs `actionDefineFunction("onLoad", ...)` which traces `L.` |

Root frame_0 sequence:
```
tagPlaceObject2(..., sprite=2, depth=1)   -- places sprite_2, which nests sprite_1
tagFlushPendingEnterFrame
script_2()                                -- traces "R." and defines onLoad
tagShowFrame
tagFlushPendingEnterFrame
quit_swf = 1
```

Expected (Flash): `CC.`, `C.`, `R.`, `L.`
Ruffle: `CC.`, `C.`, `R.` (no `L.`)
Ours: `R.`, `C.`, `CC.`, `L.` (correct contents, wrong order for the first three)

## Two distinct issues

### Issue 1 — sprite-nested-DoAction order is inverted

Expected order is deepest-first:
1. sprite_1 (inner) — `CC.`
2. sprite_2 (outer) — `C.`
3. root — `R.`

We produce top-down instead: `R.`, `C.`, `CC.`. This suggests our implementation runs root's DoAction before the newly-placed sprite's initial DoInitAction / first-frame script. Flash does the opposite: when a frame places a sprite, that sprite's (and any nested sprite's) first-frame DoAction runs *before* the parent's remaining frame DoAction.

Note: this contradicts the "place before DoAction" pattern we've already fixed for AVM1 tests (`execution_order*`, `goto_execution_order2` — see AVM1 `complete/` plans). Those tests pass. Something about this specific test pattern — sprite-within-sprite placed by outer sprite's init, vs. root placing sprite directly with script_2 running after — trips a corner case.

Hypothesis: when the parent (root) executes `script_2` *after* tagShowFrame runs the just-placed sprite's first frame, the nested sprite's script hasn't yet run because it was deferred. Our deferred-script flush may fire in the wrong order, top-down instead of bottom-up. Check `g_defer_sprite_init` / `ng_run_deferred_sprite_init_*` in `swf_core.c`/`tag.c` (referenced in memory.md "3-phase goto execution ordering").

### Issue 2 — Ruffle doesn't call root `onLoad`, we do

Good news: our matching Flash here (firing `_root.onLoad` after frame 0 completes) is actually more correct than Ruffle. But since the test carries `known_failure = true` with `output.ruffle.txt` showing 3 lines (no `L.`), Ruffle's own CI doesn't verify the 4th line. We don't need to fix anything here — if we match Flash exactly, we pass the unfiltered test; if we don't, we'd match Ruffle's output and get `ruffle_matched` promotion.

Since our actual diff has the four right *contents* but wrong *order*, fixing issue 1 alone would make us match Flash exactly (4/4 PASS).

## Suggested fix order

1. Investigate sprite init execution order for the *root places sprite + script_2* pattern. Find the divergence from the AVM1 `execution_order*` tests that pass. Might be a single line-of-code tweak in the deferred-init ordering.
2. If issue 1 resolves the test entirely, no further work needed. If we end up matching Ruffle instead of Flash (3/4 lines, no `L.`), document the discrepancy and promote via `ruffle_matched`.

## Related

- AVM1 tests already fixed for similar ordering: `execution_order3`, `goto_execution_order2`, `on_construct`, `register_and_init_order`. Our runtime generally gets this right. This specific test exposes a remaining corner case when the *root*'s DoAction is what triggers the nested-sprite placement.
- `known_failure` mechanism: see `complete/RUFFLE_KNOWN_FAILURE_HANDLING_PLAN.md`.
