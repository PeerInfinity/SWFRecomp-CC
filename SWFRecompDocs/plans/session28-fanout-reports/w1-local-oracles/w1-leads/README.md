# w1-leads local Flash oracles (s28 coordinator, 2026-11-25; FP32 LNX, direct)

| request | file(s) | result |
|---|---|---|
| 1 `avm1_hittest_root_stale_matrix` | `.pinned.txt`, `.nopin.txt` | pinned == no-pin. vs ours: **shapeFlag=true hitTest is stale in the same frame** after a `_root._x`, `c._x` or `_root._xscale` change (phases B, D, F, G; lines 5/13/22 + G), while the bounds test and `localToGlobal` use the live matrix; the next frame (C, E) is fresh. No single model of the 3 in the slot report fits all phases — the wave-2 worker fits it |
| 2 `avm1/movieclip_hittest_shapeflag` | `.pinned.txt`, `.nopin.txt` | pinned == no-pin. FP32 ≠ golden on lines **35/37/39 only** (`false` vs `true`: the second donut block, after `_root._x/_xscale` in the same frame). Lines 71, 171–177, 296 (our ACCEPTED Cat 8) == golden. **flash_fixes candidate** once our model matches |
| 3 `avm1_onunload_setvar_scope` | `.pinned.txt` | Flash: `in handler: n=2 this=_level0.a this.n=undefined`, `_root.n=2` — the handler resolves `n` through its captured scope (ours: dying clip) |
| 4a `avm1_sprite_goto_script_overflow` | `.pinned.txt` | == ours with the queue prototype, byte for byte |
| 4b `avm1_remove_unload_finalize_overflow` | `.pinned.txt` | == ours with the queue prototype |
| 4c `avm1_loadvars_ondata_overflow` | `.pinned.txt` | counts == (20/20); Flash prints `frame 2` BEFORE the 20 onData lines (ours: after) |
