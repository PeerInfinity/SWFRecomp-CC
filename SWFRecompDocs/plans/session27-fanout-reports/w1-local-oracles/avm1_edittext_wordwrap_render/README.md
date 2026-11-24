Exporter oracle (Ruffle `0ddd12b6a`, `WGPU_BACKEND=vulkan`, `exporter -s -f 1 --trace-log out.txt test.swf out.png`), run by s27-coordinator 2026-11-24 for w1-text-wordwrap's LOCAL ORACLE REQUEST 1.
- `out.txt` == `output.ours.txt` byte for byte (5 lines).
- `out.png` vs the cloud `output.ours-prototype.png`: 15 px differ, max channel diff 64 (pixel list in the s27 coordinator notes; edge AA of glyph quads). Wave 2 decides the tolerance or the cause. The master render draws 1 clipped line per paragraph, so the wrap itself is confirmed.
