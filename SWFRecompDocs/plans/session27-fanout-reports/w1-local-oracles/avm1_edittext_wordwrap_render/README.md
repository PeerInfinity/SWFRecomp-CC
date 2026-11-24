Exporter oracle (Ruffle `0ddd12b6a`, `WGPU_BACKEND=vulkan`, `exporter -s -f 1 --trace-log out.txt test.swf out.png`), run by s27-coordinator 2026-11-24 for w1-text-wordwrap's LOCAL ORACLE REQUEST 1.
- `out.txt` == `output.ours.txt` byte for byte (5 lines).
- `out.png` vs the cloud `output.ours-prototype.png`: 15 px differ, max channel diff 64 ALL at field-border corners: (10,10) (70,10) (80,10) (140,10) (150,10) (210,10) (10,70) (80,70) (150,70) (10,80) (70,80) (80,80) (140,80) (10,140) (80,140). This is the s26 border-corner oracle artifact class (playbook §25), even on vulkan; glyphs match exactly. Wave 2 decides the tolerance or the cause. The master render draws 1 clipped line per paragraph, so the wrap itself is confirmed.

**s27 FLASH capture (Flash Player 32 LNX, run_image.py --screen / run_trace.py --wrapped): `flash.png`, `flash.txt`.**
Flash draws NO glyphs in any field and reports one line per field (`textHeight=10`; `h` 2 lines). So this fixture's
synthetic DefineFont2 is Flash-invalid (Flash cannot use it), and the exporter's wrapped render is not a Flash
golden. Wave 2 must rebuild the font so that Flash draws it (compare with `w1-text-glyph-fidelity`'s
`avm1_edittext_scaled_glyphs`, which Flash does render), then take the golden from Flash.
