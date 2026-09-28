# w1-trace-tail — unclaimed trace tail (wave 1, main tree, read-only)

Rows: `avm2/simplebutton_childevents_multichild` (IGN KF), `avm2/textline_atom_index_at_char_index` (KF), `avm2/sound_load_multiple` (IGN), `avm1/hitarea_remove_owner_drag` (2/10), `timeline/missing_frame_scripts` (12/22), `avm1/globals_monkeypatch` (KF), `from_gnash/misc-swfc.all/movieclip_destruction_test3` / `_test4` (KF), `from_gnash/actionscript.all/MovieClip-v6/-v7/-v8` (KF, ~35-67 lines each), `from_gnash/misc-ming.all/NetStream-SquareTest` (KF), `avm1/set_property_values/swf4` (KF — see memory note "set-property-values-float-blocker": a prior "blocked" verdict was REFUTED; re-price it).

The `action_order` family is STRUCK (arc §21.4) — do not touch it. `TextField-v6..8` / `argstest` / `array-v*` belong to other slots.

For each row: run it (`--mode=graphics --diff --verbose`, sequential), mechanism with owner file:line, shared mechanisms across rows, flip price (a diff-line lead is not a flip lead — say what else limits the row), GO/NO-GO. Prior diagnosis: grep `SWFRecompDocs/plans/session1[5-9]-fanout-reports`, `session20-fanout-reports` and `polish-sweep-arc.md` for each name, and check for a STRIKE. For KF rows, a `pass→ruffle_matched` risk analysis is mandatory.

Deliverable: `SWFRecompDocs/plans/session21-fanout-reports/w1-trace-tail-report.md`.
