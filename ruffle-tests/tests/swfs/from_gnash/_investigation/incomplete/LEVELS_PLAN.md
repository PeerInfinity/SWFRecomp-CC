# levels Plan (gnash/misc-mtasc)
<!-- TESTS: levels -->

Test: `ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/levels/`
Status (CI at 82a6ea07): `output_mismatch`, 11/68 (16.2%). Test has `known_failure = true` with `output.ruffle.txt` sidecar.

## Test shape

```
levels/
├── test.swf          (parent; mtasc-compiled)
├── level5.swf        (loaded into _level5 via loadMovieNum)
├── level87.swf       (_level87)
├── level99.swf       (_level99)
├── output.txt        (68 lines — what Flash produces)
├── output.ruffle.txt (62 lines — what Ruffle produces; 4 extra FAILs due to frameno timing)
└── test.toml         (num_frames = 30, known_failure = true)
```

The parent uses `loadMovieNum("levelN.swf", N)` to populate three level slots, then each level SWF executes test assertions via the MTASC Dejagnu harness.

## Diffs — two distinct problem clusters

### Cluster A — our diffs beyond Ruffle (blocks ruffle_matched promotion)

After level5 passes `_level0.frameno >= 1` (fails in both our and Ruffle's output), our run also fails:

```
level5.as:35  FAILED: expected: "-16379" , obtained: "0"
level5.as:38  FAILED: expected: "_level5" , obtained: "_level0._level5"
```

Ruffle passes both of these. We fail them, which prevents `ruffle_matched` auto-promotion even though the rest of our diff is a subset of Ruffle's.

Hypotheses:

1. **`_level5._depth` returns 0 instead of -16379.** Expected: `level - 16384 = 5 - 16384 = -16379`. The MTASC test is reading a `_depth`-like property on the level root. Our level-system may not stamp the MC's `depth` field with the transformed value. Grep for `-16384`, `loadMovieNum`, and `_level` in `SWFModernRuntime/src/actionmodern/action.c` and `SWFModernRuntime/src/libswf/*.c`. Fix should be a single-line addition in the _level creation path.

2. **`_level5._target` returns `"_level0._level5"` instead of `"_level5"`.** Our levels are being treated as children of _level0 rather than as independent level roots. The `_target` getter must recognize a level-root MC and emit `"_levelN"` without walking up to _level0.

After Cluster A is fixed, our diff becomes a subset of Ruffle's and the test promotes to `ruffle_matched` (filtered pass).

### Cluster B — test truncation / output length

Expected 68 lines; we produce 14. After the level5 block ends, no output at all from level87 or level99. This suggests:

- `loadMovieNum(..., 87)` or `loadMovieNum(..., 99)` isn't actually loading the SWF, OR
- The loaded SWF runs but can't find/call the Dejagnu check functions (similar to the inlined-Dejagnu blocker on misc-ming/misc-swfc), OR
- Execution terminates prematurely after a failed assertion.

Check by running with `--verbose` and looking for actual load events, then compare against Ruffle's behavior (62 lines produced with 4 FAIL entries — Ruffle clearly loads all three levels).

## Suggested fix order

1. Fix `_depth` and `_target` for level-root MCs (Cluster A). Small, gets us to `ruffle_matched` immediately.
2. Separately, figure out why level87/99 don't load or produce output (Cluster B). Larger.

## Related

- Existing AVM1 `complete/LOADMOVIE_PLAN.md` covers `loadMovieNum` + `_level` on the AVM1 suite. The core loadMovie path works (32/35 AVM1 loadMovie tests pass). This specific Gnash test exposes a depth/target edge case that didn't surface in the AVM1 suite.
- `ruffle_matched` promotion mechanism: see `complete/RUFFLE_KNOWN_FAILURE_HANDLING_PLAN.md` in the gnash tree. Once Cluster A is fixed, `verify_output.py` should auto-promote.
