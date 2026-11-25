**gnash `action_execution_order_test12`: land Flash's "queued enterFrame survives same-tick removal" rule with the
discriminator Flash shows (M).**

Inputs: `w1-test12-enterframe-report.md` (on master), `w1-test12-enterframe-prototype.patch` (`SWF_EF_SNAPSHOT`
modes), fixtures `w1-test12-enterframe-fixtures/` (+ `avm1_dis.py`), and the coordinator's Flash 32 captures in
`w1-local-oracles/w1-test12-enterframe/` (README). Facts:
- `avm1/clip_events` and `avm1/movieclip_in_removed_button` goldens ARE Flash (so mode 1 unconditional is wrong).
- The fixture prints identically at SWF 7 and SWF 8: **the gate is not the SWF version**; the prototype's default
  (SWF ≤ 7) is overfit — replace it.
- The fixture's Flash trace differs from both prototype legs on 9 lines: the clip-event `c clipEvent(enterFrame)`
  ordering relative to method handlers, `frame 4 typeof(a.k)=movieclip` after `k unload`, and which clips fire on rf=5.

Task:
1. Fit ONE rule that produces test12's FP10 golden, the fixture's Flash trace (both SWF versions), `clip_events` and
   `movieclip_in_removed_button`, byte for byte. Candidate axes from the w1 report: multi-frame playing clip vs 1-frame
   clip; removal by a parent's loop-back vs a root RemoveObject2; clip-event vs method handler ordering. If one capture
   can't separate two fits, write a minimal fixture variant per axis as a FLASH request (built SWF).
2. Implement it (functions named; `tag.c` / `swf.c` frame loop and `action.c` enterFrame dispatch are shared with the
   N/browser ladders — self-localize), both modes.
3. Gate: the 125-row sweep of the w1 report + gnash `action_order` family (report any line movement on the NO-GO rows)
   + `regression`. Land the fixture(s) as `regression/` rows with the FLASH goldens (the README gives the files).
4. Expected flip: test12 output_mismatch → pass. Draft the RvF entry (Ruffle drops the queued enterFrame of a clip
   removed later in the tick: `player.rs` `run_actions`; FP10+ does not).
