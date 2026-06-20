# Glaiel Meteor Storm — whole-stage alpha=0 — FIXED (WebGPU texture-array-layer limit)

**Date:** 2026-06-20 (root-caused & fixed same day)
**Game:** glaiel `Meteor Storm` (177KB, AVM1/AS2)
**Bucket:** render bug (browser-visible — plain white canvas).
**Status:** FIXED — `SWFModernRuntime/src/rendering/render_webgpu.c`.

## Symptom

`divergence_test.py "Meteor Storm.swf"` → **Trace identical (199/199)** but the
whole offscreen frame read back as **(0,0,0,0)** — fully transparent black, **no
content at all** (not "black bg + white text"; the earlier note describing visible
RGB was wrong). The browser canvas composited the zero alpha → plain white canvas.

## Root cause — it was NOT the cxform (the whole earlier theory was wrong)

The recompiler and the cxform decode were both correct; the cxform was a red
herring. The real cause is a **WebGPU device limit**:

The renderer packs each distinct gradient (and bitmap) into its **own array layer**
of a single texture-array (`gradient_tex` = 256×1×N where N = gradient count).
Meteor Storm has **519 gradients → 519 array layers**, but the device was created
with **default limits**, where `maxTextureArrayLayers` is **256**. Texture creation
therefore failed:

```
Texture size (Extent3D ...depthOrArrayLayers:519) exceeded maximum texture size
(...depthOrArrayLayers:256). This adapter supports a higher maxTextureArrayLayers
of 2048, which can be specified in requiredLimits when calling requestDevice().
```

An invalid `gradient_tex` invalidated the `fragment_sampler_bg` bind group, which
in turn invalidated **every command buffer** that bound it — so Dawn silently
**dropped the entire frame's GPU work, including the clear and the MSAA resolve**.
The offscreen target was never written and read back as its initial zero. With **no
uncaptured-error callback installed**, none of this was visible — the failure
looked like a transparent render rather than a rejected submission.

This is why a whole **class** of content-heavy games was blank
(Age of War, Art of War, Bloons, Bloons TD, Bloxorz, Duck Life 2, Riddle School,
Meteor Storm, …) while lighter games (Pong, Reaction) rendered fine.

## Fix

In `render_webgpu_init`, query the adapter's limits (`wgpuAdapterGetLimits`) and pass
them as `dev_desc.requiredLimits` so the device is created at the adapter maximum
(commonly 2048 array layers + larger buffer sizes) instead of the spec defaults.
Also installed an `uncapturedErrorCallbackInfo` handler so future device-level
errors print instead of failing silently. Limits queried from the adapter are by
definition grantable, so this can only *raise* capability — working games are
unaffected.

## How it was found

Divergence harness + targeted instrumentation in `render_webgpu.c`: a red-clear /
skip-draws / per-pass readback (`PEEK`) probe showed even a **zero-draw** pass with
an explicit red clear read back as `(0,0,0,0)` for Meteor while Pong read red —
isolating the failure to the clear+resolve submission itself, not the draws or the
cxform. Adding the uncaptured-error callback then surfaced the exact limit error.
(All probe instrumentation was stripped before commit; the error callback is kept.)

## Verification

- `divergence_test.py "Meteor Storm.swf" --frames 16`: image alpha now 255
  everywhere; outliers 256,966 → ~1.7k, all residual = text-AA gray-level edge
  diffs in the "Loading"/"GlaielGames.com" text (accepted text-AA divergence).
  Trace still identical (199/199).
- Regression: Pong still renders correctly (alpha 255, content present, 0 errors).
- Age of War (previously blank) now renders opaque with 0 WebGPU errors.

## Residual / follow-ups

- A game with **> adapter-max** gradients/bitmaps (e.g. > 2048 layers) would still
  fail; the long-term fix is to pack gradients more densely (atlas / fewer layers)
  rather than one-layer-per-gradient. Not needed for the current corpus.
- Browser/WASM (emdawnwebgpu) shares this code; the same `requiredLimits` path
  compiles there and should lift the white-canvas demos once redeployed.
