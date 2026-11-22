# w1-avm1-filters-complete — local Ruffle exporter oracles (`0ddd12b6a`, coordinator, 2026-11-22)

| file | source | result |
|---|---|---|
| `dyn_ABD.ruffle-0ddd12b6a.{txt,png}` | `CASES=ABD python3 -I mkdyn.py` (1 frame) | trace == `dyn_ABD.predicted_flash.txt`; **render pixel-identical to the prototype's `dyn_ABD.after.png`** (0 px differ) → golden for `regression/avm1_runtime_filters_cm_bitmap` |
| `l1_nested_filters.ruffle-0ddd12b6a.{txt,png}` | s24 `w1-avm1-tail-probe/mkl1.py` (trace 3 ticks; render 1 frame) | trace == `l1_nested_filters.predicted_flash.txt` (12 lines); in Ruffle the nested row (y 0–160) is pixel-identical to the root row (y 160–320), as the prototype renders → golden for `regression/avm1_nested_po3_filters` |
| `dyn_CEG.ruffle-0ddd12b6a.{txt,png}` | `CASES=CEG python3 -I mkdyn.py` (1 frame) | trace `C 0` / `E 1`; render = the guard for the dynamic-clip colour-transform arc (#5 / #3b). Colour census of the Ruffle render: red (255,0,0) 14400 px, green 10384, blue 4800 — NOT all three green/blue as the probe predicts; the wave-2 worker must locate each case and read what Ruffle does per case (and decide Flash vs Ruffle) |
