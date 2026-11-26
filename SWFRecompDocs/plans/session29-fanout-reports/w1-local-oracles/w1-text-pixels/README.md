# w1-text-pixels local oracle results (s29 coordinator, 2026-11-26, FP32 LNX, HIGH, AVM1 direct; draw() == --screen, 0 px)

Builder: `mkswf.py` (uses `regression/avm1_edittext_placed_cxform/create_test_swf.py` helpers).

- **W1 `W1_color/`**: the `avm1_edittext_rotated_glyphs` layout (200×200; 90°, rot30, shear 0.5 fields + a 2nd 90°
  field at depth 4), text colour `0xCC3300`, a `0x808080` rect (90..200, 20..140 px) at depth 1 behind the rot30 field.
  The field has its own white background, so glyphs sit on white; the rot30 field's border crosses the grey rect.
  Golden: `W1_color/flash.png`.
- **W2 `W2_shapes/`** (400×220): a 1 px (20 twip) black stroke (10.3,10.1)→(180.7,95.4); a 0-width hairline
  (10.3,110.1)→(180.7,195.4); a black filled triangle (200.2,20.3),(380.6,60.7),(250.4,190.9). Golden: `W2_shapes/flash.png`.
  **Every edge pixel of all three is on the 255 − 16n ladder** (stroke 10 levels, hairline 10, triangle 15; 0 values
  off the ladder). So Flash HIGH's 1/16 coverage quantisation holds for shapes and strokes, not just text. Fitting the
  sub-scanline + exact-x model to these (`w1-text-pixels-evidence/scan.py`) is the w2 / aa-sizing slots' job.
