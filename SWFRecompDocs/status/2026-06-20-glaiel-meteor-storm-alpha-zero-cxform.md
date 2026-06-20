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

## Fix (two parts)

**1. Gradient row-packing (the environment-independent fix).** Each gradient ramp
is 256×1 RGBA8; the renderer used to store one ramp per **array layer** of a
`texture_2d_array`. Now they are packed one ramp per **row** of a single
`256 × N` 2D texture, sampled at the row center (`v = (layer+0.5)/height`). This is
bounded by `maxTextureDimension2D` (8192+), not `maxTextureArrayLayers` (256), so it
scales to thousands of gradients on **every** adapter — including SwiftShader / WSL2
browsers, where the adapter itself hard-caps array layers at 256 (so `requiredLimits`
alone cannot help there). Touch points in `render_webgpu.c`: the WGSL binding +
sample, the group-2 BGL view dimension, the texture create/view/upload, the dynamic
upload origin, and a 2D dummy-view fallback.

**2. requiredLimits + error callback (defense in depth).** `render_webgpu_init` now
queries the adapter's limits (`wgpuAdapterGetLimits`) and passes them as
`dev_desc.requiredLimits` (helps the still-array-based **bitmap** textures on
real GPUs), and installs an `uncapturedErrorCallbackInfo` handler so device-level
errors print instead of failing silently. Adapter-queried limits are grantable, so
this only *raises* capability.

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

## Browser verification

Rebuilt + redeployed the docs2 graphics-WASM demo and probed it in headed WSL2
Chrome (SwiftShader). Before the row-packing fix: 1039 console errors (the
`gradient_tex` layer-limit cascade — the error callback made them visible), blank
canvas. After: **0 WebGPU errors**, the canvas renders real game content. Gradient
rendering verified unchanged on native: Meteor diff steady at ~1.7k (text-AA only),
Reaction image-identical to Ruffle (tol 0/0).

## Residual / follow-ups

- **Bitmap** textures still use array layers — a game with > adapter-max distinct
  bitmaps would hit the same wall on a 256-capped adapter (requiredLimits covers
  real GPUs but not SwiftShader). Same row/atlas treatment could be applied if a
  game surfaces it; none in the current corpus does.
