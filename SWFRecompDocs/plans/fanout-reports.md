# Moved: the fan-out session report directories

The per-session report directories `SWFRecompDocs/plans/session{7..30}-fanout-reports/` and
`session9-graphics-setup-reports/` moved to the public history repo on 2026-11-28 (repo-cleanup slice S1):
**<https://github.com/PeerInfinity/SWFRecomp-CC-history/tree/master/SWFRecompDocs/plans>**

The files keep the same relative paths there. Main-repo citations read
`SWFRecomp-CC-history:SWFRecompDocs/plans/sessionN-fanout-reports/<file>`.

**Future fan-out sessions write their report directory in the history repo, not here** (decision D3). The coordinator
tools and the brief template are in [`tools/coord/`](../../tools/coord/README.md).

One stub for all 24 directories instead of a `README.md` in each, so `plans/` doesn't keep 24 placeholder dirs.
