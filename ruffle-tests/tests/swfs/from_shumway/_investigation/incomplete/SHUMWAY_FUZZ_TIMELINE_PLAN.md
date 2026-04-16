# Shumway Flat: fuzz/ + timeline/ Failures Plan
<!-- TESTS: fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da, fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82, fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0, fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229, fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096, fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77, fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3, fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49, fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26, fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822, fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd, fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121, fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61, fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0, fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af, fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883, fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580, fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732, fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b, fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca, fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75, fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69, fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b, fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e, fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897, fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052, fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b, timeline/timeline_as2_1, timeline/timeline_as2_5 -->

Tests: `ruffle-tests/tests/swfs/from_shumway/fuzz/*` (27 failing) and `ruffle-tests/tests/swfs/from_shumway/timeline/timeline_as2_{1,5}` (2 failing).

Status (CI at 82a6ea07): all 29 output_mismatch. Part of the flat Shumway suite's growth from 47 → 92 tests.

## `fuzz/` sub-tree (27 tests)

Each `fuzz/<sha256>/` directory holds a single test.swf with a short expected output (1-6 lines of small integers). The directory names are SHA-256 hashes suggesting these are fuzzer-generated SWFs — likely Shumway's own fuzzer output preserved as regression cases.

### Typical failure shape

Our actual output is consistently *longer* than expected — we loop more times than Flash/Shumway does for the same SWF.

Example `fuzz/07580c34...`:

```
expected (6 lines):        actual (48 lines):
4                          4
1                          1
2                          1
3                          1
7                          7
4                          1
                           1
                           ...continues 4, 1, 1, ... repeatedly
```

The expected sequence `4, 1, 2, 3, 7, 4` is replaced in our output by `4, 1, 1, 1, 7, 1, 1, 1, ...` — suggesting the same bytecode path gets re-entered many times instead of advancing through the frame sequence or through a loop counter.

### Hypotheses

1. **Frame-loop / `_currentframe` advancement bug.** If our runtime keeps traces of "we're on frame N" but doesn't advance a counter that Flash uses to break out of a loop, we'll loop forever (or until `num_frames` is hit). The presence of `num_frames = 50` in the toml supports this — the fuzz tests run 50 frames, and our output tends to show one "iteration" per frame instead of the expected compact run.
2. **ActionScript loop-control opcode bug** (`ActionIf`, `ActionJump`, `ActionDecrement`, etc.). Fuzz tests often exploit edge cases in branch/jump handling.
3. **Stack under/overflow interpretation.** Fuzzer inputs often push ill-formed stack sequences and the runtime's behavior differs from Flash's.

### Attack strategy

Fuzz tests are not a good *investigation* starting point — they stress many opcodes at once and the SWFs aren't human-readable. However, if a single core bug (e.g., `ActionJump` with a negative offset) is the root cause for several, fixing it could unblock a large fraction of the 27 at once.

Recommended:

1. Pick the shortest-expected fuzz test (`2f4f46bf...` expects 1 line of output) and decompile its SWF (using `ffdec` or similar) to see the bytecode.
2. Look for a shared pattern: if several tests use the same 2-3 opcodes, the fix likely sits in one of them.
3. If the root cause is one of the common opcodes, fix and re-run — check how many fuzz tests pass after.
4. Accept that some fuzz tests may not be worth chasing individually; they're fuzzer noise, not human-written correctness regressions.

### Worth-it bar

Given:

- Fuzz tests are machine-generated and not mapped to any user-facing feature.
- They form the single largest undocumented failure cluster (27) in the Shumway flat suite.
- A partial fix could unblock many at once.

These deserve exactly one investigation pass looking for a shared root cause. If no single fix explains >3-4 tests, the remaining tests can be left as known noise and optionally moved to an ignored list. An `ignored_tests.txt` for Shumway flat could carry any unexplained fuzz/* entries; they'd still show up in unfiltered stats but stop cluttering filtered results.

## `timeline/` sub-tree (2 tests)

Timeline navigation / gotoAndPlay ordering. Both tests are small (3-4 expected lines).

### `timeline/timeline_as2_1` (0/3)

```
expected:       actual: (empty — 0 lines emitted)
Frame 1
Frame 5
Frame 2
```

The test uses `gotoAndPlay(5)` from frame 1, causing traces at frames 1 → 5 → (loops back to) 2. Our run produces no output at all — either the frame script isn't executing, or it fails silently, or the goto target is wrong (frame 5 but frame 5 has no trace code in our run).

### `timeline/timeline_as2_5` (3/4)

```
expected:          actual:
gotoAndPlay        gotoAndPlay
stop               play            <- order swapped
play               stop
end                <missing>
```

Two issues:

1. **Order of `stop` vs `play` swapped.** Flash fires `stop` (from one frame) before `play` (from a later frame), but we fire them in opposite order. Suggests deferred-action queueing or frame-execution order bug.
2. **Missing `end` line.** The test probably has a later frame (or onEnterFrame) that traces `end` when the sequence completes. We never reach it — perhaps because `play` has already advanced us past the relevant frame, or `stop` is still suppressing timeline advancement.

Both issues are consistent with the broader "deferred DoAction / sprite-init execution order" topic that surfaces in:

- `from_gnash/_investigation/incomplete/ROOT_ONLOAD_PLAN.md` (same plan tree, written 2026-04-16).
- AVM1 `complete/SESSION_NOTES.md` (execution_order*/goto_execution_order2 fixes).

Likely these 2 timeline tests will fall out as part of the same investigation that fixes `trace-as2/root_onload` in the Gnash misc-swfmill suite.

## Priority

1. **`timeline/*`** — 2 tests, small, probably cheap, likely co-fixable with existing ordering work. **Start here.**
2. **`fuzz/*`** — 27 tests, speculative. One investigation pass. If no shared fix emerges, add unexplained entries to an ignored list rather than grinding individually.

## Related

- `from_gnash/_investigation/incomplete/ROOT_ONLOAD_PLAN.md` — same sprite/root DoAction ordering topic.
- AVM1 `complete/FRAME_NAVIGATION_PLAN.md`, `complete/SESSION_NOTES.md` — prior fixes for goto ordering.
- Shumway `complete/SHUMWAY_AVM1_PLAN.md` — completed plan for the 23 original sub-suite tests; does not cover fuzz/ or timeline/.
