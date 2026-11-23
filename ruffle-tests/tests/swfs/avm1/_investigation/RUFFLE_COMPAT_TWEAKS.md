# Ruffle Compatibility Tweaks

Pragmatic implementation choices made specifically to match Ruffle's expected test output.
These are NOT documented Flash behaviors and NOT cases where Ruffle diverges from Flash.
They are arbitrary adjustments where the "correct" behavior is unclear or unspecified,
and we chose the value that makes the Ruffle test pass.

This is distinct from:
- `ACCEPTED_DIFFS.md` — tests that can never match (UB, platform-specific, etc.)
- `RUFFLE_VS_FLASH_DIFFERENCES.md` — cases where we match Flash but Ruffle disagrees
- `FLASH_BUGS_REPLICATED.md` — documented Flash bugs we deliberately replicate

---

## Text Field Background/Border: +1 Pixel on Right and Bottom Edges

**Affected tests**: `frame_size_translated_negative`, `frame_size_translated_positive`

**What we did**: When rendering text field background/border rectangles, we add 1 pixel
to both width and height:
```c
float w = (info->w + 1.0f) * 20.0f;  // +1 pixel for inclusive right/bottom edge
float h = (info->h + 1.0f) * 20.0f;
```

**Why**: A `createTextField("t", 5, -50, -50, 20, 10)` call creates a text field at
(-50,-50) with width=20, height=10 in pixels. Without the +1, the rendered background
covers pixels (50,50)-(69,59) on the canvas — 20x10 pixels. But Ruffle's expected output
shows the background covering (50,50)-(70,60) — 21x11 pixels. The right column and bottom
row are included.

**Evidence**: Pixel-level diff shows exactly 31 outliers (10 on right edge + 21 on bottom
edge) without the +1. With the +1, both tests achieve 0 outliers.

**Risk**: This may not match Flash's actual behavior. Flash's text field rendering
documentation does not specify whether width/height are inclusive or exclusive bounds.
If future tests reveal that the +1 is wrong for other scenarios, this tweak may need
to be conditioned on specific cases.

**File**: `SWFModernRuntime/src/libswf/tag.c` — `textfield_render_cb()`

---

## Double onLoadProgress for Root Replacement Loads

**Affected tests**: `mcl_replace_root_swf7_to_swf5`, `mcl_replace_root_swf7_to_swf6`

**What we did**: When MovieClipLoader replaces the root movie, we fire `onLoadProgress` twice
(with identical bytesLoaded/bytesTotal). Normal (non-root) loads fire it only once.

```c
fireMCLEvent(app_context, loads[i].mcl, "onLoadProgress", progress_args, 3);
// Root replacement fires onLoadProgress twice (Ruffle behavior)
if (_phase1_switched) {
    fireMCLEvent(app_context, loads[i].mcl, "onLoadProgress", progress_args, 3);
}
```

**Why**: Ruffle's `loader.rs` line 759 in `on_success_root_movie()` explicitly fires
`movie_loader_progress()` twice with the comment "For some reason, progress event is
dispatched twice here." This is empirically-observed Flash behavior that the Ruffle devs
replicated without understanding the underlying reason. Normal loads in Ruffle fire progress
only once per preload tick.

**Evidence**: Both mcl_replace_root expected outputs contain two consecutive identical
`onLoadProgress` blocks. Without the double fire, output shifts by 12 lines. Added in
Ruffle commit 3891fb824 (Feb 2026) by Kamil Jarosz.

**File**: `SWFModernRuntime/src/actionmodern/action.c` — `actionFirePendingLoadInits()`


---

## ~~AVM2 `BitmapData.applyFilter` treats `ConvolutionFilter` as a plain copy~~ (RETIRED s26)

**Retired 2026-11-23 (s26 `w2-avm2-applyfilter-kernels`).** `bd_apply_filter` now convolves
with Flash's semantics (`bd_convolve_source_region`), fitted to the Flash golden of
`avm2/bitmapdata_applyfilter_destpoint_edges` cell 7 (3x3 sharpen at destPoint -10,-10):
0 channels over tolerance 1 there, against 5035 for the old copy. `avm2/bitmapdata_applyfilter_identity`
(1x1 identity kernel) still passes. The Flash-vs-Ruffle split is now recorded in
`RUFFLE_VS_FLASH_DIFFERENCES.md` ("AVM2 `applyFilter` ConvolutionFilter"). Only an empty
(0-column or 0-row) matrix still takes the copy path.

---

## Matrix3D.recompose: the non-unit-quaternion tolerance is `1e-2`

**Test**: `avm2/matrix3d_recompose_edge_cases`, `avm2/matrix3d_compose` (2026-09-11, session 19)

**Tweak**: `recompose()` throws error #2004 when the quaternion is non-unit, leaving the
matrix untouched. Flash's actual tolerance is unspecified, so we use:

```c
if (!(fabs(qn - 1.0) <= 1e-2))
```

**Why this is a judgement call, not parity**: the corpus brackets Flash Player's real
epsilon only to the open interval `(2.7e-4, 0.75)` — every graded row falls outside it, so
any constant in that range scores identically today. `1e-2` sits inside the bracket with
roughly 37x headroom on each side, which is why it was chosen.

**Risk / how to revisit**: a future test that grades a quaternion norm between `2.7e-4` and
`1e-2`, or between `1e-2` and `0.75`, would pin the real value and could contradict this.
This is the one constant to change, and it is commented as such in-code. An earlier
spelling of the same rule (`norm != 1.0`, i.e. an exact comparison) regressed
`avm2/matrix3d_compose` from pass to fail — exact equality is definitely wrong.

**File**: `SWFModernRuntime/src/avm2/avm2_stage3d.c` — the `recompose` path.

## Player platform identity: real host OS, pinned to Linux for tests

**Tests:** `avm1/geturl` (`Param: $version=`), and the `System.capabilities`
`version` / `os` / `manufacturer` / `serverString` surface in both VMs.

**The tweak.** The runtime reports the **real host OS** — `WIN` on Windows, `MAC` on
macOS, `LNX` otherwise — and `verify_output.py` passes `-DMOCK_PLATFORM` on *every*
build so graded output never depends on which machine ran it. The pinned test value is
**Linux**, and *that* pin is the Ruffle-compat choice recorded here.

**Why Linux is the right pin and not the right default.** Ruffle hardcodes
`Manufacturer::Linux` and `OperatingSystem::Linux` in `SystemProperties::new()`
(`core/src/system_properties.rs`) on **every host**, with no override in its web or
desktop frontend — a Ruffle user on Windows also sees `LNX 32,0,0,0`. Since every
`output.txt` in the corpus is a Ruffle-derived oracle, the expected token is `LNX`. But
that is **Ruffle's quirk, not Flash's behaviour**: real Flash Player reports the host OS,
which is why we do not adopt it outside tests.

**What this replaces.** The prior framing — "flip all four constants to Ruffle's Linux
defaults; it is a project-identity decision" — was a false choice between two fixed lies.
We previously hardcoded Windows; Ruffle hardcodes Linux; *neither* is what Flash does. The
user's call (2026-09-22) was to report the real OS and pin it for tests, exactly as
`MOCK_DATE_TIME` pins the clock.

**Per-test override:** `mock_platform = "windows" | "linux" | "macintosh"` (or `0|1|2`) in
`test.toml`, parsed by `get_mock_platform()`. No corpus test needs one today.

**Latent bug fixed alongside:** the version literal's `str_size` was `13` for a 12-unit
string, counting the NUL and emitting a stray trailing unit — the `"WIN 32,0,0,0 "` seen
in `SWFRecompDocs/status/2026-05-24-divergence-harness-findings.md`. Now `PLAYER_VER_LEN`.

**Follow-up not taken:** in the Emscripten build the real host is the *browser's* OS,
which C cannot see; it defaults to Linux (matching Ruffle-web) until this reads
`navigator.platform`. And `$version=` can now come **out** of the divergence harness's
`NOISE_PATTERNS`, since both sides agree under the pin — that filter was hiding a real
comparison.

---

## AVM2 bound methods on String receivers: one closure per string *pointer*

**Test**: `avm2/primitive_bound_methods` (`known_failure = true`; s24 w2-avm2-small-natives,
2026-11-22). Lives here because `avm2/_investigation/` has no compat-tweaks file.

**What we did**: reading a method trait off a primitive receiver (`"abc".AS3::toString`,
`(true).AS3::toString`, `(0).f`) goes through an atom-keyed side cache in
`bind_method_entry`, so the same receiver yields the same closure (`===` is true). The
key models avmplus's receiver atom: booleans by value; int-valued Numbers (not `-0`) as
the int atom, so `(0.0).f === (0).f`; `-0`, `NaN` and other non-integral doubles are never
cached (a fresh box per read); a **String keys on its `Avm2String*` pointer**. Interned
literals therefore share and a concat result does not.

**Why this is a compat tweak, not Flash parity**: Flash's line 2,
`("ab"+"c").AS3::toString === ("ab"+"c").AS3::toString` → `true`, cannot be produced by
any receiver-atom model that also gives line 1 (`("ab"+"c")` vs the literal `"abc"`) →
`false`. Ruffle's `ValueKey` compares strings by pointer too and prints `false` for line 2,
which is what we print. The row ends **ruffle_matched** (10/11 against Flash). The
companion row `avm2/weird_number_bound_methods` is a full Flash pass (12/12) under the same
cache, because there Ruffle keys Numbers by bit pattern (`-0`/`NaN` share) while Flash and we
do not.

**Risk / how to revisit**: reverse-engineering Flash line 2 needs an avmplus source read
(`MethodEnv` / `MethodClosure` caching, or concat-result string caching) before trying the
Flash pass. Cache misses only evict (the full key is compared), and every cached closure
holds its receiver in `fn_receiver`, so a string address cannot be recycled while cached.

**File**: `SWFModernRuntime/src/avm2/avm2_ops.c`, `bind_method_entry()` / `pbm_key()`; GC
root `avm2_gc_mark_roots_bound_cache()`.
