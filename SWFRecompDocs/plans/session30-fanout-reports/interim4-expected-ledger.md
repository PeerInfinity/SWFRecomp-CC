# s30 interim #4/#5 expected-flip ledger (coordinator, 2026-11-27)

- **#4 (graphics, `46085491256`, code `9498e80c1`)**: browser ladder #3 `171b302e4` + `dd2f979a5` (timeline sprite
  GotoFrame opcode inline, ALL builds; NOT corpus-priced). Expected: `regression/avm1_timeline_selfgoto_child_replace`
  NEW pass. Every other move is unpriced and owned by `dd2f979a5` (revert = that commit alone).
- **#5 (graphics + no-graphics)**: + batch 4 = w2-rm-avm1-gnash-land. Expected rm → pass, both modes:
  gnash `actionscript.all/setProperty-v5/v6/v7/v8`, `Object-v6/v7/v8`, `LoadVars-v6/v7/v8`, `Sound-v5`;
  `misc-swfmill.all/zeroframe_definesprite`; `misc-ming.all/EmbeddedFontTest`. NEW pass:
  `regression/avm1_asnative_mc_probe_swf5`, `_swf6`. Pixel axis: no moves. No-graphics also grades `dd2f979a5`.
