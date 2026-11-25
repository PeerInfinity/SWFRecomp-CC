**Bisect and fix the interim #3 regression `avm2/mouse_pick_avm1_root` (S–M).**

Interim #3 (graphics run `45707261082`, results `4163c12aa`; code `16033a154`) moved `avm2/mouse_pick_avm1_root`
pass → output_mismatch: the golden's first line `avm1 child clicked` is now `Clicked on: [object Stage] (null)` — the
AVM1 child movie loaded under the AVM2 root no longer receives the (input.json) click. It passed at interim #2
(`947443a23`, code `10a5b515a`). Landed between the two (one of them is the cause):
`0f2caed84` w2-avm1-leads-land (queues, loadVariables delivery tick, onUnload scope), `bc585e9f2` filter residuals,
`e7afd5ad2` + `5d186720f` w2-loaded-shell-land (newest-load-first delivery/advance, A′ same-tick direct-load delivery,
next-tick loaded goto, next-tick loadClip, unloadMovie cancel, MCL progress), `227392553` text edit, `d8b91ff94` avm2
D2A, `613c0f100` occupied depth (SWF ≤ 5 keep-both under chain in `tag.c`), `24c179dc6` lowq_fill_edges (test only).

Task: bisect (local single-test runs, graphics mode, both modes if the cause is shared code), find the mechanism, fix it
without undoing the owning commit's Flash-proven behaviour (each commit's report under `session28-fanout-reports/`
names its Flash fixtures — they must keep passing), and gate on `avm2/mouse_pick*`, `mixed_avm/*`, `regression/avm1_loaded_*`,
`regression/*mcl*`, the AVM1-under-AVM2 rows (`grep -l avm1 ruffle-tests/tests/swfs/avm2/*/test.toml` neighbourhood).
EXPECTED-FLIP LEDGER required.
