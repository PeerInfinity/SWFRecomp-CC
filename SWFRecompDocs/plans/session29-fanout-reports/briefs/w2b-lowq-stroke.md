**Flash LOW stroke raster: build the FP32 probe, then fit and land the 3-px band rule, the thin-stroke regime and the
hairline-under-TSNAP fix (M; two rounds: probe first).**

Read `session29-fanout-reports/w2-lowq-tsnap-report.md` §2.4, §3 and its LOCAL ORACLE REQUEST 1; TSNAP landed in
`1fcf2b1c1`. Leads: (a) LOW 3-px rect band = "right-of-travel pen", ties to even, 12/12 edges fitted on one width;
(b) LOW thin regime: w ≤ 5 minor-axis pen clamped to 4 at w = 5, polygon at w ≥ 6, Drawing API shares it;
(c) 1-px noScale hairlines under a TSNAP'd parent should stroke with the UNSNAPPED translation (acid-stroke-0 +369).
1. **Round 1 (push early):** build `lowq_stroke_probe` (generator pattern `regression/lowq_tsnap_tie_probe/create_test_swf.py`,
   the SWF sets `_quality = "LOW"`) with exactly REQUEST 1's cells, plus `cells.json` predictions for your candidate
   rules. Commit + push the fixture and a short interim report with `## LOCAL ORACLE REQUESTS` naming it; the
   coordinator watches your branch for `lowq_stroke_probe/test.swf` and archives the FP32 capture to
   `session29-fanout-reports/w1-local-oracles/w2b-lowq-stroke/` on master (`git fetch origin master` and look; poll at most
   every 10 min, and keep working on (c) meanwhile, which needs no new capture beyond the acid-stroke-0 golden).
2. **Round 2:** fit (a) + (b) on the capture; implement the LOW arm (`MSAA_SAMPLES == 1`) in the `render_webgpu.c`
   stroke path (`hairline_restage` / `render_webgpu_stroke_snap` / `stroke_snap_place`) and (c).
3. Gates: the 114-test Flash-golden LOW gate (`w1-lowq-next-fixtures/ledger/flash_golden_low_gate.txt`) 0 losses; HIGH
   canary md5-identical (LOW-gated by construction: prove it); by-name ledger with golden provenance; kill switches.
   Add the probe as `regression/lowq_stroke_probe` with its FP32 golden.
If the capture never lands within ~2 h, deliver (c) alone plus the probe and an exact HOLD.
Siblings: none active in the stroke path now (n-seam-caps closed; its `stroke_snap_place(..., sf, hinted)` signature
is on master). Name every function you touch.
