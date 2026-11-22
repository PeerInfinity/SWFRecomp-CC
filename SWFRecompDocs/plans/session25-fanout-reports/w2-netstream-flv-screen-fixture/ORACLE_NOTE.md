# Coordinator oracle attempt (2026-11-22, Ruffle exporter `0ddd12b6a`)

- `test.swf` as staged cannot be exported: its header RECT packs Xmax = 32000 in 15 signed bits → negative width
  ("Texture target … requested 0 x 400"). Regenerating with a valid 400×400 rect (`gen2` variant, script unchanged)
  exports fine.
- **The exporter never fires `setTimeout`/`setInterval` callbacks** (40 frames: only `start` / `done` print, every
  loop). So the exporter is NOT an oracle for timer callbacks; this fixture still needs Ruffle's deterministic test
  runner or a Flash capture. Fix the RECT before landing it (`nbits` 15 is too small for 32000; use 16+ or a smaller
  stage).
- The landed fix (`timer.c`) is guarded by the corpus row `avm1/netstream_play_flv_screen` (Flash golden), which
  passes.
