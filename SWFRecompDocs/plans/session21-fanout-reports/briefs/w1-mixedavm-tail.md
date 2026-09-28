# w1-mixedavm-tail — mixed-AVM / loader / focus tail (wave 1, main tree, read-only)

Rows (see the inventory for line counts): `avm2/focus_events_mixed_avm_edittext` (0/49, RVF), `avm2/mouse_pick_loader_avm1` (16/42, RVF), `avm2/selection_onsetfocus_mixed_avm` (0/5), `mixed_avm/avm2_loads_avm1_events` (5/26, KF), `from_shumway/as3-loader/events/loader-events` (5/36, KF), `from_shumway/as3-loader/LoaderLoadBytesTest` (1/4), `text/links_in_scrolled_text` (0/1). `mixed_avm/avm1_loads_avm2` is a NO-GO of record — only touch it if a mechanism you find for the others provably covers it.

Two of these carry an RVF flag: read the RUFFLE_VS_FLASH entry for each FIRST and say whether it still describes the current diff (it may have aged). For each row: run it (`--mode=graphics --diff --verbose`), name the mechanism(s) with owner file:line, whether rows share a mechanism, a flip price, and GO/NO-GO for wave 2. Zero-output rows (0/N) are the cheap axis — find where the output stops and why. Prior diagnosis: grep `SWFRecompDocs/plans/session1[5-9]-fanout-reports` and `session20-fanout-reports` for each test name.

Deliverable: `SWFRecompDocs/plans/session21-fanout-reports/w1-mixedavm-tail-report.md`.
