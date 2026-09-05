# ruffle-image-results

Failing image comparisons from the most recent `ruffle-tests.yml` run
dispatched with `images=true`.

**This branch is rebuilt from scratch and force-pushed on every image run.**
It has no history and must never be merged into `master`. Passing renders are
not published.

- `index.md` — human-readable table: test, comparison, outliers vs budget,
  max channel difference, magnitude band, links to the PNGs.
- `index.json` — the same data, machine-readable.
- `images/<suite>/<test>/<cmp>.actual.png` — what we rendered.
- `images/<suite>/<test>/<cmp>.difference.png` — per-channel absolute
  difference, RGB brightened x4, alpha 0 where every channel matched.

The expected PNGs are not copied here; they live in the test directories on
`master` as `<cmp>.expected.png`.

Renders are graded on CI's lavapipe software Vulkan. Local Dawn/WSL2 renders
are not pixel-identical to it and are advisory only.

Run: https://github.com/PeerInfinity/SWFRecomp-CC/actions/runs/33945288707
