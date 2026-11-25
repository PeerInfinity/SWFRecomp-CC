# w1b-rm-avm1-misc local Flash oracles (s28 coordinator, 2026-11-25; FP32 LNX direct, new PinStub)

| request | file | result |
|---|---|---|
| 1 corpus `avm1/tab_ordering_properties` | `tab_ordering_properties.flash32.txt` | == golden byte for byte. Both tab goldens are Flash → the edge-case rule needs the third probe the slot describes (raw string stored only while the value is not yet a number / only for `this`) |
| 2 `export_timing/probe_stop` (5 s) | `export_timing_probe_stop.flash32.txt` | `frame1 ran` then **`undefined` on every tick (131×)**: an export in a never-reached frame is NOT available → exports register when the playhead reaches the frame (move `tagRegisterExport` into the frame function) |
| 2 `export_timing/probe_play` (control) | `export_timing_probe_play.flash32.txt` | `_level0.fromFrame2`, then `_level0.e` every tick: control OK |
