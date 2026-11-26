# w1-disposition-audit local oracle results (s29 coordinator, 2026-11-26, FP32 LNX direct pinned)

| request | result |
|---|---|
| 1. `forin_order/` (AS3 for-in, mxmlc `-target-player=11.1`), 2 runs | **Flash's AVM2 for-in order is hash-scattered AND differs between runs** (`flash.r1.txt` vs `flash.r2.txt`: 4 of 7 key sets reorder; e.g. `aaa,cccc` → `cccc,aaa` in r1, `aaa,cccc` in r2). Object, URLVariables and decoded URLVariables agree within a run; insertion order is irrelevant (`a,b` and `b,a` both → `b,a` in r1). ⇒ `avm2/bom`, `avm2/loader_load` order lines are **Flash-nondeterministic**: NO-GO (like `eforin_*`), not a gap. |
| 2a. `L3a_v6`, `L3a_v7` (MTASC; `createTextField("textField")` then `typeof new TextField()`, `typeof TextField`) | v6: `undefined`, `object`; v7: `object`, `function` → the SWF ≤ 6 case-insensitive shadowing rule is confirmed (item 2). |
| 2b. `L3b_tabindex{,_v7,_v8}` (MTASC class `main`, `var r:Object=_root; r.tabIndex="s"`, …) | **All three versions COERCE**: `-2147483648, 5, -2147483648, -2147483648, -2147483648, 7`. This **contradicts** the w1 rule "first set is a string ⇒ sticky raw mode". Yet the corpus row (SWF8, frame-script `this.tabIndex = "asdf"`) re-runs **byte-identical to its raw golden** pinned and `--no-pin` (`tab_edge_corpus.*.flash.txt`). The discriminator (frame-script `this` vs a typed local / MTASC function scope / something else) is unknown. Item 7: HOLD. |
| 2c. `L3c_v5` (MTASC v6 build, header byte patched to 5) | no output at all (an MTASC class SWF does not run as v5) — no golden. |
