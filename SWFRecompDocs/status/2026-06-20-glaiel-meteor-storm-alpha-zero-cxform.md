# Glaiel Meteor Storm — whole-stage alpha=0 (runtime cxform-alpha render bug) — DEFERRED

**Date:** 2026-06-20 (root cause corrected same day)
**Game:** glaiel `Meteor Storm` (177KB, AVM1/AS2)
**Bucket:** render bug (browser-visible — user confirmed plain white canvas).
**Status:** NOT fixed — root-caused to the runtime render cxform path; deferred.

## Symptom

`divergence_test.py "Meteor Storm.swf" --frames 16` → **Trace identical
(199/199)** (logic perfect). Image: the whole offscreen frame is **alpha=0
(transparent)** with correct RGB (black bg + white "Loading"/bar/"GlaielGames.com"
text). In the **browser** the canvas composites with alpha, so the page shows
through → **plain white canvas** (confirmed by the user). Reaction/Pong (no root
cxform) render alpha=255.

## Root cause — it is NOT the recompiler (earlier note was wrong)

The loading screen is sprite `char 8` (`sprite_44`) placed at root depth 1 with a
**CXFORMWITHALPHA**:
```
PlaceObject2 (chid: 8, dpt: 1) len=21
  0e 01 00 08 00  1c a2 81 dc 80 e8 00 00 00 04 00 ff 3f cf f0 00
```
Hand-decoding per spec (the cxform is **byte-aligned after the 35-bit
translate-only matrix** — this is what fills the 21-byte tag) gives:
**mult = [0, 0, 0, 256], add = [255, 255, 255, 0]** — i.e. RGB forced to white
(×0 +255), **alpha ×1.0 +0 = fully opaque**.

The recompiler decodes this **correctly**: `cxform_data` entry 2 reads, in order,
`mult_r=0, mult_g=0, mult_b=0, mult_a=256/256=1.0` (diagonal at indices
0/5/10/**15**) and `add=[255,255,255,0]` (indices 16–19). (An earlier draft of
this doc wrongly called entry 2 "garbage with alpha-mult 0" — that was a parsing
artifact: the array literals are `VALUE/256.0f`, and a naive number-scan captured
the `256`/`255` denominators plus an off-by-one, fabricating bogus values. Reading
the raw lines shows the entry is correct.)

So: matrix decode correct (transform 21 = translate 5200/3812), cxform decode
correct (white-opaque). **The bug is in the runtime render.**

## Where the bug is (runtime render)

The WGSL `apply_cxform` (render_webgpu.c:159) is a diagonal `mult*color + add`
clamp and is correct in isolation: for an opaque white-tinted shape it returns
`[1,1,1,a]`. Yet the rendered alpha is 0 **everywhere** — including the white text
pixels (whose shape alpha should be 1) and the black background (the clear, which
is hard-set to alpha **1.0** at render_webgpu.c:1668). For the clear's alpha to
read 0, the white-tint cxform must be reaching the whole framebuffer and zeroing
alpha — a defect in how `char 8`'s placement cxform is **composed onto its nested
children / propagated down the sprite hierarchy**, and/or how that interacts with
the **premultiplied-alpha** pipeline (the renderer blends premultiplied; the
shader returns straight-alpha `[1,1,1,a]`; a white RGB with add_rgb=255 over a
premultiplied pipeline is exactly the kind of case that can drop alpha).

Note: the sprite-child draw path (tag.c ~2694) draws shape children with their
**own** `obj->cxform_id` and does not visibly compose the parent sprite's cxform
onto shape children (only the TEXT path composes, and only with the char's baked
cxform) — so how `char 8`'s cxform 2 reaches the children (it clearly does — RGB
is white) and why it zeros alpha is the thread to pull.

## Next steps when resumed (runtime render session)

1. Empirically confirm the cxform is the cause: force `cxform_id=0` for the root
   `char 8` placement in the runtime and re-render — expect opaque output.
2. Trace how a **root sprite's placement cxform** propagates to its shape/text
   children in the OFFSCREEN render, and how alpha flows through the
   premultiplied blend + MSAA resolve + readback. The white text pixels reading
   alpha 0 (not 1) is the precise anomaly to instrument (dump the fragment
   `color.a` going into `apply_cxform` and the resolved texture alpha).
3. Regression gate: `divergence_test.py "$HOME/CC/glaiel/swfs/Meteor Storm.swf"
   --frames 16` → image alpha should become 255 (opaque) matching Ruffle; the
   deployed `docs2/examples/glaiel/Meteor_Storm` demo should show the loading
   screen instead of a white canvas.
