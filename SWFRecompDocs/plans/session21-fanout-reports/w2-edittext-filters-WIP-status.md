# w2-edittext-filters — WIP handoff (local agent stopped 2026-09-28 ~18:55 PT, moved to a cloud session)

The local agent was stopped mid-canary so the work could move to a cloud session (the shared box was
at load 7-8 and the 100-test A/B needed ~3 h). Nothing below is canaried yet.

- `w2-edittext-filters-WIP.patch` — the agent's latest implementation (`p12`, 18:10), 3 files:
  `action.h` (+6), `action.c` (+35), `tag.c` (+106/−8). Applies cleanly to master `b57ecb2f3`+.
  The agent's last message before the stop confirmed it was waiting on its BEFORE capture — i.e. it
  considered p12 the candidate.
- `w2-edittext-filters-WIP-canary-list.txt` — the 100-test A/B list the agent built
  (standing render canary set + every EditText image test + AVM1 filter image tests + caret rows).

Headline measurements (local Dawn, graphics mode; outliers per comparison):

| comparison | base (b57ecb2f3) | WIP a1 | WIP p12 |
|---|---:|---:|---:|
| cache_as_bitmap/edittext_hscroll .01 | 96 fail | 0 pass | **0 pass** |
| cache_as_bitmap/edittext_hscroll .02 | 0 pass | 0 pass | 0 pass |
| cache_as_bitmap/edittext_selection .01 | 366 fail | 0 pass | **0 pass** |
| cache_as_bitmap/edittext_selection .02 | 315 fail | 30 fail | 30 fail |
| cache_as_bitmap/edittext_selection .03 | 373 fail | 171 fail | 171 fail |
| edittext/edittext_border_filters | 821 fail | 821 fail | **0 pass** |
| cache_as_bitmap/edittext_scroll .01/.02 | 566/570 fail | 875/876 fail | **714/714 fail — WORSE** |

So p12 = +3 flips, with one worsened fail→fail band (`edittext_scroll`) that must be explained
(correct-upstream-of-an-unfixed-defect, or a real error) before landing.
