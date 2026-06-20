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

## Additional browser hardening (gradient path)

While verifying in-browser, two more gradient-path changes were made — both
native byte-identical (Reaction tol 0/0), so they don't change real-GPU output,
but they remove fragile software-WebGPU dependencies:

- **Gradient sampling via `textureLoad`** (exact integer row + manual U-lerp)
  instead of `textureSample` with a computed V. Eliminates any chance of
  bilinear V-filter bleed between row-packed ramps on adapters whose linear
  filtering doesn't land exactly on the texel center.
- **Static gradient-matrix inversion on the CPU** (the same `invert_4x4_matrix`
  the dynamic path uses) instead of a GPU compute shader. SwiftShader's compute
  backend is unreliable; the matrices are simple 2D affines inverted once at
  init, so CPU inversion is both correct everywhere and trivially cheap. The
  compute pipeline is left allocated but unused.

## KNOWN REMAINING ISSUE — browser-WASM menu renders corrupt (all browsers)

After the alpha-zero fix the demo renders, but the **menu** screen (after the
loading screen) renders as a mostly-gray mess with exploded geometry. The user
confirmed this on **Windows Firefox AND Chrome** (real GPUs) — so it is NOT a
SwiftShader/WSL2 software-rasterizer issue (an earlier draft of this section
wrongly concluded that). It is a deterministic browser-WASM rendering bug. The
**loading screen renders correctly** in the browser; only the later menu is wrong.

Characterized via end-of-shader fragment probes (the only valid placement — an
early `return` before the unconditional `textureSample` calls is a WGSL
"uniform control flow" compile error, which silently rendered (0,0,0,0) and
produced several **bogus "everything reads 0"** intermediate results before this
was caught). Comparing native (lavapipe, OFFSCREEN capture) vs browser on the
**same original SWF** (injected-vs-original confound eliminated) at the static
menu:

| signal (solid fills) | native | browser |
|---|---|---|
| vertex `style_id` (color index) | 246 / 20 / 469 (varied) | **487 / 486** dominant + OOB 14348 |
| `transform_id` (from `instance_index`) | **22** (static slot, ~75% coverage) | **600 / 601** (dynamic slots) |

So in the browser the menu's shapes are routed through **high/dynamic transform
slots holding bad matrices** (→ giant exploded triangles) and read **different
style indices**. Both are wrong, consistently.

**Leading hypothesis:** the native test harness captures via `tagRerenderFrame`
(an OFFSCREEN/capture-only path that re-composes transforms into dynamic slots its
own way), while the **browser's live render loop uses a different
transform-composition path** (`tagShowFrame` / per-frame compose). The harness
therefore never exercises the path the browser actually runs — a classic
browser-WASM-only bug that CI/divergence cannot see (cf. the browser-WASM notes in
project memory). The loading screen working but the menu not is consistent with a
defect that surfaces once dynamic transform composition / deeper display lists
kick in.

**Next step (needs C-side instrumentation, not shader probes):** dump the live
draw stream (per-shape `transform_id`, `cxform_id`, vertex offset, and the
composed matrix at `transforms[transform_id]`) from the browser path and diff
against the capture path for the menu frame; find where a menu shape's
`transform_id` diverges and which composition step writes the bad dynamic-slot
matrix. Distinct from the original alpha-zero bug, which is fully fixed.

- **Bitmap** textures still use array layers — a game with > adapter-max distinct
  bitmaps would hit the 256 cap on a 256-capped adapter (requiredLimits covers
  real GPUs but not SwiftShader). Same row/atlas treatment could be applied if a
  game surfaces it; none in the current corpus does.
