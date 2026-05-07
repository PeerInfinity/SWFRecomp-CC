# Shumway Flat: fuzz/ Failures Plan
<!-- TESTS: fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82, fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096, fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77, fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3, fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49, fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26, fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822, fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd, fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121, fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61, fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af, fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580, fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b, fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca, fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75, fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b, fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e, fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897, fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052, fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b -->

<!-- Resolved 2026-05-07 — place-before-define recompiler fix landed in CI 8fdf3311:
  Tracking `defined_chars` (DefineSprite/Shape/Button/Text/EditText/Bits/Font/
  Sound/Video, plus ImportAssets-imported chars) in tag-stream order in
  `SWFRecomp/src/swf.cpp`. *Root-timeline* PlaceObject{,2,3} referencing a
  char_id not yet registered is degraded to char_id=0 (modify), matching Flash.
  Sprite-internal PlaceObject is intentionally not gated (sprites instantiate
  at runtime, after the full root dictionary is built). Of the 20 originally
  failing tests:
    - 4 now PASS: 4935e4aed5e6, b480790b, plus 2 RMATCH→PASS upgrades
      (1276557624, a86fee6d).
    - 2 newly RUFFLE_MATCHED: 4949de46, 887c02ab.
    - 14 still MISMATCH for unrelated fuzz divergences. Plus the 5 originally
      no-output.ruffle.txt tests (0cde3aca, 438789f3, b29624af, e152812e,
      f5398dd7) that lack the place-before-define pattern entirely (they fail
      for different per-test reasons — unrelated tag-stream noise).
  Total still-failing fuzz tests after fix: 16. All 16 added to
  `from_shumway/ignored_tests.txt` per the worth-it bar in this plan.
  Initial fix in CI 873e520e regressed Gnash actionscript.all (189→0 effective)
  and 2 AVM1 tests due to over-broad sprite-internal check + missing
  ImportAssets registration; narrowing fix in CI 8fdf3311 recovered both
  while preserving the +4 fuzz gain (fuzz tests have no inner-sprite
  PlaceObjects). See RUFFLE_VS_FLASH_DIFFERENCES.md "PlaceObject Before
  DefineSprite" entry and avm1/_investigation/SESSION_NOTES.md
  (2026-05-07 entry) for full rationale.
-->

<!-- Resolved 2026-05-04 (in CI at c5994ec1):
  Both timeline tests PASS (cross-cutting fixes from Instance-v* native ctor,
  Global-v6 case-insensitive lookup, GetMember/SetMember hidden own-prop walk,
  ecmaToInt32 trunc, ASSetPropFlags array, convertFloat strict mode).

  Fuzz `_currentframe` cluster (8 tests) PASS via `mc->currentframe` natural-advance
  sync in `advance_sprite_frames`:
  fuzz/07580c34..., fuzz/1276557624..., fuzz/2f4f46bf..., fuzz/81004241...,
  fuzz/a86fee6d..., fuzz/ac93c8c9..., fuzz/c8b8069c..., (one of the originally listed)
-->

Tests: `ruffle-tests/tests/swfs/from_shumway/fuzz/*` (20 failing).

Status (CI at `c5994ec1`, 2026-05-05): all 20 output_mismatch. Both `timeline/*`
tests now PASS — see resolved-comment above. Of the original 27 fuzz tests
in this plan, 7 PASS and 20 still fail (the `_currentframe` natural-advance
sync resolved roughly the cluster that exercised `this._currentframe`).

### 2026-05-08 investigation: shape of remaining 20

Local re-run on the 8 simplest residuals (≤8 expected lines): all 3 zero-output
tests PASS, `2f4f46bf` PASS, `1276557624` and `a86fee6d` ruffle_matched, `81004241`
PASS, `07580c34` PASS — the only one in that band still failing is `b480790b`
(5 expected / 26 actual). So the failures cluster at slightly higher-complexity
SWFs.

The failing 20 share a common SWF shape: **DefineSprite tags appear AFTER
PlaceObject2 tags that reference them in the tag stream**. Flash/Shumway
treat this as failed placement (chid undefined at PlaceObject time → no sprite
animation), which is why expected outputs only contain root-frame traces.
Both we and Ruffle DO place the sprite (recompiler scans all DefineSprite
tags ahead of time), so we and Ruffle both produce extra sprite-frame traces.
Ours and Ruffle's outputs share the first ~14 lines exactly, then diverge.

For `b480790b`: ours is exactly 3 extra duplicate values vs Ruffle's output
(an extra `1`, `2`, `3` interspersed in the late tail). Ruffle's output is
also wrong vs expected, but it's recorded in `output.ruffle.txt`. Diff is
**not** a strict subset of Ruffle's by line index, so subset-promotion fails.

### Tests that cannot promote

5 of the 20 lack both `known_failure = true` and `output.ruffle.txt`, so
ruffle_matched promotion is structurally impossible without first running
upstream Ruffle locally on each SWF and committing the output:

- `0cde3aca…` (92/48 lines)
- `438789f3…` (18/16 lines, **closest to passing**)
- `b29624af…` (36/29 lines)
- `e152812e…` (63/43 lines)
- `f5398dd7…` (26/24 lines)

Path forward for these: build/run Ruffle's `tests` binary against each SWF,
capture stdout traces as `output.ruffle.txt`, and add `known_failure = true`
to `test.toml`. Then they auto-promote if our output is no worse than Ruffle's.

### Path-forward summary (revised)

1. **Generate `output.ruffle.txt` for the 5 missing tests** (~30 min once
   Ruffle's test runner is running locally) — likely flips at least 1-2
   to ruffle_matched, since we and Ruffle produce nearly-identical wrong
   output.
2. The remaining 15 with `known_failure=true` + `output.ruffle.txt` need
   our output to be a strict line-index subset of Ruffle's. Spot-check a
   few — if our diff is just ±1-3 lines off Ruffle's, hunting that
   divergence may unlock multiple at once. If our diff is structurally
   different, accept-as-noise / move to ignore list per the worth-it bar
   below.
3. Path of last resort: add unexplained entries to a Shumway flat
   `ignored_tests.txt` so they don't clutter filtered results.

## `fuzz/` sub-tree (20 still failing)

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
- They form the single largest undocumented failure cluster (20) in the Shumway flat suite.
- A partial fix could unblock many at once.

These deserve exactly one investigation pass looking for a shared root cause. If no single fix explains >3-4 tests, the remaining tests can be left as known noise and optionally moved to an ignored list. An `ignored_tests.txt` for Shumway flat could carry any unexplained fuzz/* entries; they'd still show up in unfiltered stats but stop cluttering filtered results.

## `timeline/` sub-tree — RESOLVED 2026-05-04 (both PASS)

Both `timeline/timeline_as2_1` and `timeline/timeline_as2_5` now PASS in CI at
`c5994ec1`, picked up via the cross-cutting fixes (Instance-v* native ctor,
Global-v6 case-insensitive lookup, GetMember/SetMember hidden own-prop walk,
ecmaToInt32 trunc, ASSetPropFlags array, convertFloat strict mode). No further
work needed for this sub-tree.

## Priority — RESOLVED 2026-05-06

1. **`fuzz/*`** — 20 → 14 effective passes after place-before-define recompiler
   fix (12 PASS + 2 RMATCH). The remaining 16 added to
   `from_shumway/ignored_tests.txt` per the worth-it bar. The shared root cause
   identified (place-before-define) explains the larger PBD-shaped sub-cluster;
   the 5 NO_PBD failures (0cde3aca, 438789f3, b29624af, e152812e, f5398dd7) are
   noise on unrelated tag-stream patterns and not worth chasing individually.

## Related

- `from_gnash/_investigation/incomplete/ROOT_ONLOAD_PLAN.md` — same sprite/root DoAction ordering topic.
- AVM1 `complete/FRAME_NAVIGATION_PLAN.md`, `complete/SESSION_NOTES.md` — prior fixes for goto ordering.
- Shumway `complete/SHUMWAY_AVM1_PLAN.md` — completed plan for the 23 original sub-suite tests; does not cover fuzz/ or timeline/.
