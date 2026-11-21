You are a CLOUD WORKER in SWFRecomp-CC corpus fan-out session 23 (dual-axis #15), slot `w1-filter-label`, wave 1 (DIAGNOSIS, measured prototypes welcome). Run autonomously to completion: nobody will answer questions, and messages sent to you may never arrive. Do not spawn subagents.

The user has approved you pushing to the scratch branch `fanout/w1-filter-label` (and ONLY that branch; never master, never force-push). Your report on that branch is your only deliverable.

FIRST: read `SWFRecompDocs/plans/session23-fanout-reports/BRIEFS_COMMON.md` (in this repo, on origin/master) and follow its Setup, Standing rules and Delivery sections exactly. Your branch is `fanout/w1-filter-label`; your report is `SWFRecompDocs/plans/session23-fanout-reports/w1-filter-label-report.md` (plus an optional `w1-filter-label-prototype.patch`). Also read `CLAUDE.md`.

---- YOUR TASK ----
**Filter label residuals (pixels).** Board: `graphics-fanout-playbook.md` §21 "Left on the board (session 23)". Categories: `visual avm1 avm2` (only what you need).

Rows: `glow`, `glow_without_composite_source`, `drop_shadow` each fail at **3 outliers / 0 budget**: one EditText label pixel, the comma of "K,I". `bevel_*` ×3 and `glow_with_alpha_strength` fail at 24/18 (label pixels). The board says these 7 rows are "within reach of a depth-0 text glyph fix". (Find the exact test paths with `find ruffle-tests/tests/swfs -path '*filters*'`.)

1. Prove cloud fidelity first: render one row's before-image and check its md5 against CI's actual PNG on `origin/ruffle-image-results` (BRIEFS_COMMON "Your box"). Note: the fresh baseline images run `44922638965` will force-push that branch during your session; re-fetch if the file you need is missing, and say which run you compared against.
2. Locate the failing pixels (diff the before render vs the golden; tools: `scripts/image_triage.py`, Pillow). Confirm they are all text-glyph pixels, and find the mechanism: glyph outline precision (s22 found integer-twip / font-unit `lround` quantization in several glyph paths; see `session22-fanout-reports/w2-glyph-subunit-report.md`, `w2-float-verts-report.md`), EditText layout position, or AA at the glyph edge.
3. Deliver a measured prototype that flips as many of the 7 as possible, with a render-canary md5 A/B (`ruffle-tests/render_canary.py`) showing what else moves. Attack the premise: if the label pixels are NOT one mechanism across the 7 rows, split the pricing.

Siblings: `w1-padded-filter` owns filter-layer bounds/edges (`drop_shadow_angles`, `displacement_map`, `bevel` y=305 edge row); `w1-glyph-precision` owns AVM1 embedded-glyph precision in `morph_test1` / `Video-EmbedSquareTest` / `edittext_scroll`. If your mechanism turns out to be theirs (or vice versa), say so plainly in the report: the coordinator will merge the slots.
