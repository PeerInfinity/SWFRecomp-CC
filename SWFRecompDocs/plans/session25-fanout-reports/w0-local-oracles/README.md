# s25 wave-0 local oracle runs (coordinator, Ruffle exporter at `0ddd12b6a`)

Answers to s24 `w2-attach-order-v8-report.md` LOCAL ORACLE REQUESTS #1–#3, run before s25 wave 1.

| file | generator | frames | finding |
|---|---|---|---|
| `attach_tagorder_ratio.ruffle-0ddd12b6a.txt` | `mk_ratio.py out.swf` (fixture `regression/avm1_attached_clip_tagorder` with every `place()` as PlaceObject2 + Ratio 0) | 8 | **byte-identical to the fixture's `output.txt`** → s24 lead L4 (we print `kid3 anim f1` twice on each wrap from line 16) is a real bug; this SWF + oracle is a landable fixture once fixed |
| `attach_tagorder_po3.ruffle-0ddd12b6a.txt` | `mk_po3.py out.swf` (every `place()` as PlaceObject3) | 8 | **byte-identical to the fixture's `output.txt`**; we already print it (s24 measured) → landable fixture now |
| `array_generic_receivers.ruffle-0ddd12b6a.txt` | `make_l1.py out.swf` | 1 | Array.prototype `join`/`push` as own methods AND via `.call`: **Object, Function, MovieClip receivers all work in Ruffle** (`a-b`, `3`, len 3); a `new String("xy")` receiver gives `undefined` / empty / `undefined` / `undefined`. We return undefined for Function and MovieClip (s24 lead L5) → a real gap, String-object row is the odd one out (check Flash semantics before matching Ruffle there) |

Generators need `python3 -I <gen> out.swf` (the tagorder variants also accept a 2nd arg `nonroot`).
Exporter: `exporter -s -f <frames> --trace-log out.txt in.swf out.png`.
