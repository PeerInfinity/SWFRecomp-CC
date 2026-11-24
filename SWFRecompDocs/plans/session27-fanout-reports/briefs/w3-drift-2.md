**Upstream drift round 2** `1e604fa87..origin/master` (at least `9a8618af1` "Test various patterns of malformed AVM1 bytecode", `2c6d3c4fe` "Add avm2/goto_isplaying test", `31d5a45e5` "isPlaying after nextScene and prevScene", `d607dca2e` "isPlaying after queued nextFrame and prevFrame"; re-fetch, more may have landed). Categories: `avm1`, `avm2`.

s27 interim #3 graded the new rows: `avm1/malformed_actions/constant_pool_overlong`, `constant_pool_overspill`, `push_overspill` **output_mismatch** (the other malformed_actions rows pass), and `avm2/goto_framescript_queued_next_prev`, `goto_isplaying`, `goto_scene_isplaying` **ruffle_matched** (check `known_failure` and `output.ruffle.txt`: ruffle_matched on a KF row is Ruffle's own failure).

1. Name-status the drift; pre-label expected moves.
2. The 3 malformed-bytecode rows: what does Flash do with an over-long constant pool / a pool or push that spills past the action's length (read the test's README / Ruffle's commit and `core/src/avm1/` reader)? Price and prototype in the recompiler (`SWFRecomp/src/action/action.cpp` parsing) and/or runtime. Malformed bytecode must never crash: run each under ASan once.
3. The 3 AVM2 `isPlaying` rows: if output.txt is Flash's and we match Ruffle's wrong output, price the Flash behaviour (isPlaying after queued nextFrame/prevFrame, nextScene/prevScene).
Measured prototypes land directly (both modes for shared code).
