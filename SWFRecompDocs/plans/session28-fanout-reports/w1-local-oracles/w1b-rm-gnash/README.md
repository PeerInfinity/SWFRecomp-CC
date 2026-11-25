# w1b-rm-gnash local Flash oracles (s28 coordinator, 2026-11-25; FP32 LNX direct pinned, new PinStub)

`avm1_gnash_flash_probes` at SWF 8 / 6 / 5: `test.flash32.txt`, `test_v6.flash32.txt`, `test_v5.flash32.txt`. Diff vs `output.ours-prototype.txt` (SWF 8): Flash prints NO `P2 func depth N` lines (the `with` cap behaves differently inside DefineFunction), and P3 (setSelection arg rules), P4 (NaN == matrix) and P5/P6 differ — read the files.
