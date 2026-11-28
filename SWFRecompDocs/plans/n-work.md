# Moved: the N game work (`SWFRecompDocs/plans/n-*`)

All of the N work under `plans/` moved to the public history repo on 2026-11-28 (repo-cleanup slice S2b, ruling D8d):
**<https://github.com/PeerInfinity/SWFRecomp-CC-history/tree/master/SWFRecompDocs/plans>**

- the 18 ladder reports `n-*-report.md`;
- the 3 CANCELLED procgen plans `n-level-generator-plan.md`, `n-portals-plan.md`,
  `n-physics-js-reimplementation-plan.md` (the arc was cancelled 2026-11-26; its code stays in this repo);
- the provenance captures and parked fixtures `n-stroke-snap-captures/`, `n-join-disc-captures/`,
  `n-exec-order-sibling-fixture/`, `n-levels-5plus-hairline-fixture/`. The regression fixtures built from them carry
  their own goldens in `ruffle-tests/tests/swfs/regression/`.

The files keep the same relative paths there. Main-repo citations read `SWFRecomp-CC-history:SWFRecompDocs/plans/n-<name>`.
The live N harnesses stay in `ruffle-tests/tests/swfs/_swfbridge/livetest/n_*` and `tools/divergence/game_drive/`.

One stub for the whole set, as S1 did for the fan-out report dirs, so `plans/` doesn't keep placeholder dirs.
