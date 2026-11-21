You are a CLOUD WORKER in SWFRecomp-CC corpus fan-out session 23 (dual-axis #15), slot `w1-glyph-precision`, wave 1 (DIAGNOSIS, measured prototypes welcome). Run autonomously to completion: nobody will answer questions, and messages sent to you may never arrive. Do not spawn subagents.

The user has approved you pushing to the scratch branch `fanout/w1-glyph-precision` (and ONLY that branch; never master, never force-push). Your report on that branch is your only deliverable.

FIRST: read `SWFRecompDocs/plans/session23-fanout-reports/BRIEFS_COMMON.md` (in this repo, on origin/master) and follow its Setup, Standing rules and Delivery sections exactly. Your branch is `fanout/w1-glyph-precision`; your report is `SWFRecompDocs/plans/session23-fanout-reports/w1-glyph-precision-report.md` (plus an optional `w1-glyph-precision-prototype.patch`). Also read `CLAUDE.md`.

---- YOUR TASK ----
**AVM1 embedded-glyph precision + text-row watch (pixels).** Board: `graphics-fanout-playbook.md` §21 (session 23). Categories: `visual avm1 avm2 from_gnash` (only what you need).

1. `morph_test1` frame2-6 + `Video-EmbedSquareTest` (6 comparisons): the same 4 xtrace pixels fail on each (`session22-fanout-reports/w1-pixel-smalls-report.md` lead 1). Find the mechanism (AVM1 embedded glyph outline precision? the AVM2 analogue was fixed in s22 by `w2-glyph-subunit`) and prototype it.
2. `edittext_scroll .02`: the board says it needs a port of Ruffle's device glyph build. Price it and say whether a cheaper mechanism exists.
3. `avm2/bitmapdata_draw`: the tol-128 check 753/600 is the last failing check (1-px text baseline; the golden is a Flash capture, and Ruffle's model puts the baseline where we do). Is there a Flash rule we can match without breaking the Ruffle-golden rows? Flash-over-Ruffle applies, but do not trade a passing row.
4. **Watch / attribute**: `from_gnash/misc-ming.all/shape_test` worsened 16074 → 17911 outliers in s22's final run (still failing). Attribute it with an A/B of the s22 patches (candidates: the stroke re-expansion in `w2-hairline-device-width`, the filter capture change in `w2-filter-fixes`, `w2-float-verts`). Also re-measure the zero-headroom rows (`fallback_preferences`, `fills_and_lines`, `edittext_border_filters`) and report their margins.

Prove cloud fidelity on one row first (before-render md5 == CI actual PNG on `origin/ruffle-image-results`, which the baseline images run `44922638965` force-pushes mid-session; re-fetch and name the run). Siblings: `w1-filter-label` owns EditText label pixels inside filter rows; say plainly if your mechanism is theirs.
