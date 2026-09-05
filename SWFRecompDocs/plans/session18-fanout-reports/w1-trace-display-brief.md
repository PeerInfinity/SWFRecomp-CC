# w1-trace-display — wave 1 diagnosis: AVM2 display / timeline / loader / focus trace failures

Read `BRIEFS_COMMON.md` first. Read-only: no source edits. Deliverable:
`SWFRecompDocs/plans/session18-fanout-reports/w1-trace-display-report.md`. Scratch dir: `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/w1-trace-display/`.

## Your board (suite `avm2` unless noted)
Prior board of record: `SWFRecompDocs/plans/polish-sweep-arc.md` §18.4 (session-18 "left on the
board") and the s17 reports `session17-fanout-reports/w2-avm2-display-report.md`,
`w2-crossvm-legE-report.md`, `w2-timeline-s1s2-report.md`, `wave1-trace-board.md`. Read the
relevant one before each row; re-verify every claim against HEAD (the corpus moved: the
Multi-SWF arc of 2026-09-03/04 rewrote child-movie loading, char-id re-basing and child timelines —
see `SWFRecompDocs/status/child-*.md`, `per-movie-*.md`).

| test | exp | match | prior note |
|---|---|---|---|
| `displayobject_getrect` | 16 | 11 | §18.4: needs DefineShape4 `EdgeBounds` emitted into `Avm2CharInfo` by the recompiler (~10 lines) — verify and price |
| `stage_display_state` | 6 | 0 | §18.4: `FullScreenEvent.FULL_SCREEN` constant + dispatching `Stage.displayState` setter |
| `stage_scale_factor` | 12 | 6 | |
| `selection_onsetfocus_mixed_avm` | 5 | 0 | §18.4 leg F (~6-line pick extension + `Selection.onSetFocus` broadcast); mechanism in `w2-crossvm-legE-report.md` §6 |
| `mouse_pick_loader_avm1` | 42 | 16 | RUFFLE_VS_FLASH-flagged — check the disposition's scope; 27 lines were priced fixable in §18.4 |
| `large_preload_from_bytes` | 51 | 41 | §18.4: loadee is an embedded `DefineBinaryData` never compiled — needs a bytes→SWF recompile path. Re-check after the Multi-SWF arc |
| `from_shumway/as3-loader/LoaderLoadBytesTest` | 4 | 1 | same mechanism as above |
| `loader_try_click_root` | 16 | 0 | "AVM1-child remainder" in s17 — re-verify after Multi-SWF |
| `loader_duplicate_class` | 48 | 3 | s17: child timeline children not placed before the symbol-class ctor runs — re-verify after Multi-SWF |
| `orphan_removeobject` | 636 | 340 | never diagnosed beyond a s12 mention — 296 lines, probably one mechanism |
| `timeline/frame_script_cleanup_goto2` (suite `timeline`) | 34 | 12 | s17 timeline S1/S2 report |
| `timeline/missing_frame_scripts` (suite `timeline`) | 22 | 12 | §18.4: S3+S4 HOLD, pin M4 (orphan clip loses a tick) |
| `text/links_in_scrolled_text` (suite `text`) | 1 | 0 | HELD patch from s16: `session16-fanout-reports/w2-smalls-links_in_scrolled_text.patch` — re-check whether it applies and what grade it needs |
| `movieclip_addframescript_error` | 9 | 0 | new 2026-08-28 (w1-trace-new may also look; coordinate via report, not messages) |
| `mixed_avm/avm2_loads_avm1_events` (suite `mixed_avm`) | 26 | 7 | known_failure — price only |
| `simplebutton_childevents_multichild` | 152 | 33 | known_failure — price only |
| `loader_events_2` | 35 | 2 | known_failure |
| `from_shumway/as3-loader/events/loader-events` | 36 | 9 | known_failure; §18.4 instance-name counter (6 of 27 lines; A/B first) |
| `event_handler_exception` | 11 | 5 | known_failure |
| `avm1_root` | 58 | 12 | known_failure + RUFFLE_VS_FLASH — confirm the disposition covers all 46 lines, else price |
| `focus_events_mixed_avm_edittext` | 49 | 0 | RUFFLE_VS_FLASH-flagged — confirm scope |

Do NOT touch: `tab_ordering_properties` (ACCEPTED), `loader_applicationDomain`/`swz`/`netstream_*`
(dispositioned or NO-GO decoders), `external_interface` (container-dependent, s17 NO-GO),
`id3_info` (s17: real ID3v2 parsing, MED — mention only if you find it cheaper than believed).

## Method
Run each test locally (`-P 2`, `SWFRECOMP_COMPILE_TIMEOUT=2400`, `--verbose`), read diff +
stderr, find the mechanism, cluster, price FULL-pass flips honestly, check dispositions,
verdict GO/HOLD/NO-GO with files + LOC + canary list. Attack the brief's premises — §18.4 is
three weeks old and the Multi-SWF arc landed since. Sibling agents: w1-trace-new, w1-trace-avm1,
w1-trace-numerics.
