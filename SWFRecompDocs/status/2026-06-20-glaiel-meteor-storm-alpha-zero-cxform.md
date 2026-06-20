# Glaiel Meteor Storm — whole-stage alpha=0 (malformed placement cxform) — DEFERRED

**Date:** 2026-06-20
**Game:** glaiel `Meteor Storm` (177KB, AVM1/AS2)
**Bucket:** headless-diagnosable (image), but root cause is recompiler cxform emission.
**Status:** NOT fixed — logged as a follow-up.

## Symptom

`divergence_test.py "Meteor Storm.swf" --frames 16` → **Trace identical
(199/199)** (logic perfect). Image F1 diverges with 256966 outliers / max_diff 255
across the *whole* frame.

The RGB content is **correct** (black background + white "Loading" / loading bar /
"GlaielGames.com" logo, matching Ruffle). The divergence is purely the **alpha
channel**: SWFRecomp's offscreen framebuffer is **alpha=0 (fully transparent)
everywhere**, while Ruffle's is alpha=255 (opaque). Composited on the white PNG
viewer background, transparent → white, so it *looks* blank. Confirmed:
Reaction/Pong output alpha=255; Meteor Storm alpha min=max=0 across all 16 frames.

## Lead (root cause, unconfirmed end-to-end)

The loading screen is one sprite `char 8` (`sprite_44`) placed at root depth 1
**with a color transform**: `tagPlaceObject2(app_context, 1, 8, 21, 2, 0, 0)` →
`cxform_id=2`. (Reaction, which renders opaque, places its root content with
`cxform_id=0` = none.)

`cxform_data` entry 2 is **malformed**. Layout is 20 floats per entry, diagonal
multipliers at cx[0]/cx[5]/cx[10]/cx[15] and adds at cx[16..19]
(`ng_init_cxform_from_data`, tag_stubs.c:764). Entry 0 (identity) is clean
(`1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1, 0,0,0,0`). Entry 2 is
`0,255,0,0, 256,0,0,0, 0,0,256,0, 0,0,0,0, 256,0,0,0` — i.e. **alpha-mult cx[15]=0**
(→ whole sprite alpha 0) and **out-of-range mults** (cx[10]=256, cx[16]=256 where
≤1.0 is expected; `roundf(256*256)` overflows the int16 cast). Entry 1 is likewise
off. So the recompiler's cxform emission is wrong for this SWF — the values look
mis-scaled / mis-strided (some entries use ×256, identity uses ×1).

Curiously the **RGB stays correct** even though cx[0]=cx[5]=0 for entry 2 (which
would black-out RGB if applied) — so the malformed cxform's alpha component
reaches the framebuffer alpha but its RGB component does not, suggesting only the
alpha path consumes the bad value (or the visible white text is a sub-element not
under this cxform). Needs render-pipeline tracing to pin which.

## Why deferred

- Trace identical + RGB correct → low functional impact headless; the open question
  is whether it makes the game invisible **in-browser** (canvas alphaMode), which
  needs a browser check.
- Root cause is in the **recompiler's CXFORMWITHALPHA decode/emit** for this SWF's
  format — a focused recompiler investigation, not a one-liner, and SWF-specific
  (Reaction/Pong/most games use cxform_id=0 on their root and are unaffected).

## SWF ground truth (ffdec dump)

The placement IS a CXFORMWITHALPHA (confirmed via `ffdec.jar -dumpSWF`):
```
PlaceObject2 (chid: 8, dpt: 1) len=21
  0e 01 00 08 00  1c a2 81 dc 80 e8  00 00 00 04 00 ff 3f cf f0 00
```
flags `0e` = HasCharacter(2)+HasMatrix(4)+HasColorTransform(8). depth=1, char=8.
The matrix (`1c a2 81 dc 80 e8 …`) is bit-packed **translate-only** (HasScale=0,
HasRotate=0, NTranslateBits=14, tx=5200/ty=3812 twips). **The matrix decode is
CORRECT** — the recompiler emitted `transform[21] = [1,0,0,0, 0,1,0,0, 0,0,1,0,
5200,3812,0,1]`, matching a hand bit-decode exactly. So the CXFORM read starts at
the right bit offset (just past the 35-bit matrix). The garbage is therefore in
the **CXFORMWITHALPHA decode itself**, not matrix misalignment. The cxform spans
the remaining ~11 bytes (`80(part) e8 00 00 00 04 00 ff 3f cf f0 00`) — a
substantial transform (HasMult+HasAdd with a wide NBits), NOT identity — and the
recompiler turned it into entry 2 with mults of 256 (over-range) + alpha-mult 0.
**Bit-trace `swf.cpp`'s CXFORMWITHALPHA reader** (NBits width, signed-field
extraction, and the float scaling it writes into `cxform_data` — identity uses
1.0 but entry 2 uses 256, so the scale convention is inconsistent between code
paths). Likely a sign/width bug in the recompiler's cxform field reader for
wide-NBits records.

## Next steps when resumed

1. Confirm transform_id 21 decodes to the right translate (matrix decode OK?), then
   bit-trace where the CXFORMWITHALPHA read starts in `swf.cpp` for this tag — a
   misaligned start is the prime suspect for the garbage entry 2.
2. If the SWF cxform is benign (e.g. identity/opaque) and the recompiler garbled
   it → fix the recompiler cxform reader (likely a bit-alignment / scale bug in
   `swf.cpp`'s CXFORM emit). If the SWF genuinely sets alpha-mult 0 → check how
   Ruffle keeps the stage opaque (stage backing is opaque regardless of a
   full-cover child's alpha).
3. Regression gate: `divergence_test.py "$HOME/CC/glaiel/swfs/Meteor Storm.swf"
   --frames 16` → image alpha should become 255 (opaque) matching Ruffle.
</content>
