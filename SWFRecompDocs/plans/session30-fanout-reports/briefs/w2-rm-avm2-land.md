**Land w1-rm-avm2's 8 clean S rules (+8 rm → pass), HOLD L1′, and take the FP32-settled toml/golden items (S–M).**
Source: `session30-fanout-reports/w1-rm-avm2-report.md` + `w1-rm-avm2-prototype.patch`. FP32 answers to its requests:
`session30-fanout-reports/w1-local-oracles/w1-rm-avm2/README.md`.

1. **Land R1, R2, M1, BA, RE, PI, FTE-1, FTE-2** (the report's rule table). Ledger: `timeline/swf_9_frame_script_dynamic_goto`,
   `timeline/swf_9_event_goto_frame_script`, `from_shumway/MaskTest-3`, `from_avmplus/regress/bug_558863_swf10`,
   `bug_479786`, `from_avmplus/as3/Math/e15_1_2_2`, `avm2/textblock_releaselines`, `avm2/textline_atom_index_at_char_index`
   rm → pass (all `known_failure` upstream, so check `output.ruffle.txt`); `swf_9_goto_in_construct_frame` 8 → 1 line.
   Re-run each rule's gate (report §Gates) + `categories=full`-class rows near `avm2_ops.c`/`avm2_value.c`/
   `libregexp.c` (from_avmplus regress/ecma3 RegExp/Math/parseInt).
2. **HOLD L1′** (FP32 cannot pin which tick a file-loaded child's traces land in: README §0). Do not land it.
3. **M1 scope:** FP32 says a script `removeChild` of the mask (direct or via an ancestor) does NOT null `maskee.mask`
   (README §4). Keep M1 on the RemoveObject TAG path only; add the FP32 `mask_removal` fixture as a `regression/` row
   (golden = `w1-local-oracles/w1-rm-avm2/mask_removal/fp32.lnx.txt`, SWF there).
4. **`from_shumway/timeline/nav/clipDepth`:** FP32 at 6 frames == the 8-line golden: add a flash_fixes `kind: "toml"`
   entry raising `num_ticks` to the value that prints exactly the golden (report says 4; verify). Then price its
   `getObjectsUnderPoint` clip-layer rule (M) — implement only if S.
5. **`avm2/swf_9_goto_in_construct_frame`:** FP32's steady state is a 6-line cycle; the 20-line golden ends mid-cycle
   (README §3). Decide between a flash_fixes `output.txt` swap to FP32 cut at a clean tick boundary (with the matching
   `num_ticks`), or leaving it rm with an ACCEPTED entry. Prefer the swap if it is exact.
6. **`pixelBounds` (S):** FP32: off-list `transform.pixelBounds` = the transformed bounds × 5 on every component; empty
   → 0 (README §5; fixture `pixelbounds_offlist/`, add it as a `regression/` row). Implement; grade the corpus `pixelBounds` row.
7. `array_sort_swf10_32bit`: LNX FP32 = `_64bit` golden, WIN FP32 = `_32bit` golden (host bitness). No swap; write the
   RvF/ACCEPTED entry (host-bitness split), no code.
8. Write the report's RvF entries (§"RvF entries to add").
Siblings: w2-drift-smalls-land (AVM2 `avm2_xml.c`, `avm2_text.c` img arm, `avm2_display.c` html img loads — coordinate on
`avm2_display.c` by function: you own `run_goto`, `run_local_frame_scripts`, `run_remove_op`, the pixelBounds getter).
Name every function you touch.
