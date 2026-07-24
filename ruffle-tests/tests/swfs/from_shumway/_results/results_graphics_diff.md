# Ruffle Test Results Diff

**Previous:** `2cf4014fd672` (2026-07-24T22:06:49.422577+00:00)
**Current:** `17c19040c9cd` (2026-07-24T23:01:01.359964+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 159 | 152 | -7 |
| Total | 229 | 222 | -7 |
| Pass rate | 69.4% | 68.5% | -0.9% |
| Mismatched lines | 943 | 943 | 0 |

## Missing Tests — Shard Failure (7)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 7 were previously passing
- 0 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `timeline/scene/Scene_1_MainTimeline` | pass | 70/70 |
| `timeline/scene/Scene_2_MovieClipTimeline` | pass | 70/70 |
| `timeline/scene/Scene_3_GotoAndStop_LabelScene` | pass | 15/15 |
| `timeline/scene/Scene_4_GotoAndStop_FrameScene` | pass | 15/15 |
| `timeline/scene/Scene_5_GotoAndPlay_LabelScene` | pass | 15/15 |
| `timeline/scene/Scene_6_GotoAndPlay_FrameScene` | pass | 40/40 |
| `timeline/scene/Scene_7_NextPrevScene` | pass | 7/7 |

</details>
