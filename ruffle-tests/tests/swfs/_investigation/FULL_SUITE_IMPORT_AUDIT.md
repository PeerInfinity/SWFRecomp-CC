# Full Ruffle Suite Import — Audit (Step 1)

Date: 2026-07-24. Upstream: ruffle-rs/ruffle `75c3cec57` (2026-07-24).
Direction: import the FULL Ruffle test set, then build a coverage-gap →
feature-priority map (user, 2026-07-23).

## What we mirror today vs upstream

Upstream `tests/tests/swfs/` has **14 categories, ~4347 tests**. We mirror 4.

| Category | Upstream | Local | State |
|---|---|---|---|
| avm1 | 719 | 722 | synced (locals keep a few upstream-deleted dirs) |
| avm2 | 1221 | 1220 | synced (1 new upstream test since last sync) |
| from_gnash | 404 | 404 | synced |
| from_shumway | 229 | 92 | **AVM1 half only — 137 AVM2 tests filtered out** |
| from_avmplus | **1574** | 0 | **not mirrored** |
| visual | 142 | 0 | not mirrored |
| timeline | 17 | 0 | not mirrored |
| text | 11 | 0 | not mirrored |
| mixed_avm | 11 | 0 | not mirrored |
| fonts | 6 | 0 | not mirrored |
| audio | 5 | 0 | not mirrored |
| stage3d | 5 | 0 | not mirrored |
| swf | 5 | 0 | not mirrored |
| import_assets | 3 | 0 | not mirrored |

Total not-yet-imported: **2778 + 137 shumway-AVM2 ≈ 2915 tests** (vs ~2440
currently mirrored). Current AVM2 standing for context: 829 pass +
26 ruffle_matched of ~1216.

## Why each gap exists

- `download_tests.sh` has a hardcoded category table (avm1, avm2,
  from_shumway, from_gnash). Everything else was simply never added.
- `from_shumway` runs through the default `keep_avm=avm1` filter
  (`swf_is_avm2.py`), a leftover from the AVM1-only era. The avm2 category
  already inverts the filter, so the mechanism exists — from_shumway just
  needs a "keep both" mode (or a second category entry).

## Character of the unmirrored categories

- **from_avmplus (1574, 100% AVM2, 74 known_failure)** — the Adobe
  Tamarin/avmplus acceptance suite. Breakdown: ecma3 800 (44 kf), as3 509
  (11 kf), e4x 177 (8 kf), regress 55 (9 kf), misc 14, mops 13, recursion 6.
  All but 1 are trace-based (real output.txt). This is *exactly* the
  language/builtin coverage instrument the feature-priority map wants.
- **from_shumway AVM2 (137)** — trace-based, just filter-flipped away.
- **visual (142: 88 AVM1 / 54 AVM2, 6 kf)** — **130 of 142 are image-only**
  (empty output.txt, `[image_comparisons]` + `with_renderer`). Under our
  TRACE-only gating policy (image comparisons never gate pass/fail) these
  would all trivially "pass". Importing them is a policy decision about
  image gating, not a trace-coverage win.
- **timeline (17: 14 AVM2)** — all trace-based. Frame/timeline semantics.
- **text (11: 7 AVM2)** — 9 trace-based, 2 image-only.
- **mixed_avm (11)** — movies loading AVM1↔AVM2 content into one player.
  We have no dual-VM-in-one-movie support; park until that exists.
- **fonts (6), audio (5), swf (5), import_assets (3)** — small; about half
  trace-based. import_assets/swf are AVM1. audio needs `with_audio`,
  fonts need `[default_fonts]`/noto discovery.
- **stage3d (5, all AVM2)** — needs Stage3D/Context3D, unimplemented; park.

## Harness readiness (verify_output.py)

Already supported: `num_frames`/`num_ticks`, `[approximations]` (epsilon +
number_patterns), `input.json` injection, `known_failure`,
`[image_comparisons]` (non-gating), `[player_options]` viewport.

Not yet handled (usage counts upstream, all categories): `log_fetch` (24),
`with_default_font`/`[default_fonts]`/`[fonts.*]` (~35), `[required_features]`
(10: lzma, jpegxr), `sleep_to_meet_frame_rate` (7), `with_audio` (16),
`with_video` (14). None block from_avmplus (which is plain trace tests);
audit per-test during import.

## Recommended import order

1. **from_avmplus** — add to download_tests.sh (`keep_avm=avm2`), run full
   CI baseline both modes, seed `_investigation` docs. Biggest coverage
   instrument by far; feeds the feature-priority map directly (ecma3
   builtins, as3 classes, e4x).
2. **from_shumway AVM2 subset** — add "keep both" filtering; +137 tests in
   an already-wired category.
3. **timeline + text + swf + import_assets + audio + fonts** (~47 tests,
   ~30 trace-gating) — one batch, one CI run.
4. **visual** — only after deciding whether image comparisons should gate
   for a dedicated visual suite (they deliberately don't elsewhere).
5. **mixed_avm, stage3d** — parked; require dual-VM movies / Stage3D.

CI note: from_avmplus alone is +1574 tests (~+64% suite size) — check shard
counts/timeouts in `ruffle-tests.yml` before the first full dispatch, and
run the import baseline in BOTH modes (corpus import = "when in doubt run
both").

## Import status (2026-07-24): COMPLETE — full corpus mirrored, no filtering

Same-day follow-up (user direction): mirror the FULL upstream test set with
no AVM-generation filtering at all. `download_tests.sh` now knows all 14
upstream categories and installs every test directory; the old
`swf_is_avm2.py` keep-avm filter is deleted (the pipeline detects AVM1 vs
AVM2 per SWF at recompile time via `RecompiledABC/`, so mixed suites just
work — from_shumway now installs all 229 including its 137 AVM2 tests).
The nine small categories (timeline, text, swf, import_assets, audio,
fonts, visual, mixed_avm, stage3d — ~215 tests) are wired into CI as the
`misc` group (shard tags `misc_<name>`, one results dir each).

Caveats now that everything is in:
- **visual** is 130/142 image-only — under trace-only gating those grade on
  incidental trace output (often trivially). Their value is recompiler
  smoke coverage (e.g. `visual/blend_modes` is a `recomp_fail` today).
- **mixed_avm** (dual-VM movies) and **stage3d** will mostly fail until
  those capabilities exist — they are roadmap markers, not regressions.
- Suites without filtering may gain a few upstream strays (e.g. avm1 picks
  up its AVM2-header oddballs) — they surface as "Added Tests" in diffs.

## Which tests run when (selection policy, adopted 2026-07-24)

- `all` — the classic five suites (avm1, avm2, regression, from_shumway,
  from_gnash). **Unchanged meaning; still the per-change default.** Note
  from_shumway inside `all` now includes its AVM2 half.
- `full` — the complete corpus: `all` + from_avmplus + the misc group.
- `from_avmplus` / `misc` / per-suite selectors — targeted runs.

| Situation | Dispatch |
|---|---|
| Per-change default | `categories=all`, `mode=graphics` (unchanged) |
| Change touches AVM2 runtime/recompiler emission | `categories=full`, `mode=graphics` |
| Weekly Sunday canary | `categories=full`, `mode=no-graphics` (widest run) |
| Corpus imports, milestones, workflow/infra changes affecting all suites | `full`, both modes |
| Single test | `single_test=NAME` as before |

"Touches AVM2" means: AVM2 runtime sources in SWFModernRuntime, the AVM2
translator/emission side of SWFRecomp, or shared code where AVM2 behavior
could plausibly shift — when in doubt, `full`. Rationale: from_avmplus is
pure AVM2 language/builtin coverage; AVM1-only changes can't move it, so
per-change runs skip it and the weekly canary + AVM2-change runs keep its
baselines fresh. Anti-clobber invariants are unchanged: category-scoped
runs publish only the categories they ran; extra-defines (verify) runs
publish nothing.
