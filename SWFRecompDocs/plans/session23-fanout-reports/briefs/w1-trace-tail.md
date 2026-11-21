You are a CLOUD WORKER in SWFRecomp-CC corpus fan-out session 23 (dual-axis #15), slot `w1-trace-tail`, wave 1 (DIAGNOSIS, measured prototypes welcome). Run autonomously to completion: nobody will answer questions, and messages sent to you may never arrive. Do not spawn subagents.

The user has approved you pushing to the scratch branch `fanout/w1-trace-tail` (and ONLY that branch; never master, never force-push). Your report on that branch is your only deliverable.

FIRST: read `SWFRecompDocs/plans/session23-fanout-reports/BRIEFS_COMMON.md` (in this repo, on origin/master) and follow its Setup, Standing rules and Delivery sections exactly. Your branch is `fanout/w1-trace-tail`; your report is `SWFRecompDocs/plans/session23-fanout-reports/w1-trace-tail-report.md` (plus an optional `w1-trace-tail-prototype.patch`). Also read `CLAUDE.md`.

---- YOUR TASK ----
**Trace tail, non-drift** (graphics rows still failing after s22; board = `polish-sweep-arc.md` §23.4). Categories to download: `avm1 avm2 from_gnash audio fonts` (only what you need).

Price each and deliver GO/NO-GO with a measured prototype where cheap:
1. `avm1/edittext_html_duplicate_attributes` 241/247: AVM1 `getTextFormat` ignores styleSheet CSS (see `session22-fanout-reports/w2-htmltext-report.md` §6). Is the remaining 6-line diff one mechanism? Prototype it.
2. `from_gnash/misc-swfc.all/movieclip_destruction_test3` / `_test4` (known_failure): `session22-fanout-reports/w1-trace-tail-report.md` §7 says the attached chain's frame-8 scripts land AFTER the root frame-9 check. Probe the frame timing with a trace instrument first, then decide whether it is one mechanism (+2) and where it lives (`tag.c` / attach path / `swf.c` frame loop). Remember `known_failure` means pass → ruffle_matched rules: check `output.ruffle.txt`.
3. `audio/aac`, `audio/g711`: `SoundMixer.computeSpectrum` + a NetStream audio tap (+2, M/L per the board). Price it: which lines, which decoder, what would a minimal spectrum implementation need to match the expected text (exact or approx in `test.toml`?).
4. New upstream rows from the s22 sync: `avm2/textline_metrics` (DefineFont4 typo metrics, GO-maybe), `fonts/device_font_name_case` (AVM1 device-font slot), `avm2/dictionary_qname_keys` (unpriced). Run, price, mechanism.
5. Re-confirm (cheaply: one run each, no deep work) that the standing NO-GOs still fail for the stated reason: `MovieClip-v8` (gnash), `globals_monkeypatch`, `GradientFillTest`, the `action_order` family. Attack them only if a run shows a different diff shape than the record says.

Siblings: `w2-crossvm-legf` owns the cross-VM focus/selection rows; `w1-drift-*` (launched later) own upstream drift since `45366370e` — if a row you run has new upstream changes, say so and leave the drift pricing to them.
