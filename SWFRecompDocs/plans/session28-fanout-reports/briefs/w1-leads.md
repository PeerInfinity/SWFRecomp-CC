**Small leads (S each): `avm1/movieclip_hittest_shapeflag`; remaining fixed-size deferred queues; FileReference
`download()`/`postData`.**

1. `movieclip_hittest_shapeflag` (output_mismatch at baseline): pinned Flash 32 prints `false` on 3 lines where the
   golden says `true` (`session27-fanout-reports/golden-provenance.md` ~line 161: `clip.hitTest(400, 500 / 500, 400 / …`).
   Are those 3 our ACCEPTED lines (`ACCEPTED_DIFFS.md`)? Is the rest of our output == FP32? If our output == FP32 on
   every line, this is a flash_fixes candidate (the coordinator re-captures and adds the entry) + RvF; if not, what
   remains vs FP32 and why. The `trace-provenance` local session may have already captured it — check
   `session28-fanout-reports/trace-provenance.md` first.
2. Deferred queues: `w2b-timers-tail` grew `MAX_DEFERRED_FAILED_LOADS`, `MAX_PENDING_LV_LOADS`, `MAX_DEFERRED_UNLOADS`.
   Inventory every remaining fixed-size `MAX_*` queue/table in the runtime that silently drops on overflow (grep
   `MAX_DEFERRED_`, `MAX_PENDING_`, `MAX_QUEUED_`, fixed arrays with a drop-on-full branch) and grow the reachable ones
   (`ng_table_grow` pattern), each with an overflow fixture.
3. FileReference: what do our AVM1/AVM2 `download()` and `upload()`/`postData` do (stub? trace?), what does Ruffle do,
   and which corpus rows touch them. Fix what a corpus row or Flash-documented behaviour needs; otherwise a priced
   NO-GO.
