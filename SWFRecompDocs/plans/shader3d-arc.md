# Shader/3D arc (PixelBender + Stage3D) — scoping

**Status**: scoped 2026-07-30 (pre-implementation). Census + oracle sweeps
done; no tranche shipped yet. Oracle: Ruffle @ `75c3cec57` (local fork).

## 0. The decision this replaces

The priority map queued "PixelBender 25 vs Stage3D 13" as a choice. The
census dissolves it: both blocks are trace-graded API/validation/compute
work with **zero GPU dependency in any graded line**, they total **42
candidates** (27 PixelBender-side, 15 Stage3D-side — both undercounted by
the map), and Stage3D-surface is the same census→surface→validate shape as
the input/net arcs. This is ONE arc with PixelBender and Stage3D tranches.
Board check at scoping time: nothing bigger remains in avm2 — the only
larger family is `all_classes/*` (25 whole-registry audit dumps, thousands
of lines each) which converge with overall surface growth, not with any
single arc. A `strings` sweep of every sourceless-suite `test.swf` for
`ShaderJob|PixelBender|Context3D` found zero hidden riders.

## 1. Census (baseline `34171042f` results)

### PixelBender side — 27 candidates, ~4,600 graded lines

| test | lines | needs |
|---|---|---|
| avm2/pixelbender_parameters | 1/1563 | surface + evaluator (20 types × 27 values matrix) |
| avm2/pixelbender_param_qualifier | 0/512 | parser (qualifier byte: `2`=out, else in → #2004 no-out) |
| avm2/pixelbender_conversions | 1/270 | evaluator |
| avm2/pixelbender_parameters_bool | 0/240 | surface + evaluator (bools ARE ints end-to-end) |
| avm2/pixelbender_malformed_data | 0/190 | value-coercion rules at start() (§3.4) |
| avm2/pixelbender_conditional | 0/138 | evaluator (if/else/endif) |
| avm2/pixelbender_input | 4/103 | evaluator + input textures + #2165 sizing |
| avm2/pixelbender_shaderdata_setter | 3/99 | evaluator + replaced-param default fallback |
| avm2/pixelbender_ceil | 5/77 | parser float-only gate + evaluator |
| avm2/pixelbender_sign | 5/60 | same (sign = (x>0)-(x<0), NOT native sign) |
| avm2/pixelbender_parameters_int_vs_bool | 0/54 | surface + evaluator |
| avm2/pixelbender_shaderdata | 0/49 | surface only (metadata/property dump) |
| avm2/pixelbender_div | 1/36 | evaluator |
| avm2/pixelbender_rsqrt | 1/24 | evaluator (rsqrt(0)=∞→clamp 1.0, NaN→0) |
| avm2/pixelbender_padding_bytes | 0/22 | parser (padding skipped, NOT validated) |
| avm2/pixelbender_logicalnot | 0/20 | evaluator |
| avm2/pixelbender_outputs | 0/13 | #2162 gate (output channels must be 3|4) + run |
| avm2/pixelbender_vector_output | 1/11 | evaluator + Vector target (3-ch de-padded) |
| avm2/pixelbender_dithering | 0/8 | surface only (sorted property enumeration) |
| avm2/pixelbender_eof | 1/7 | parser + **5-frame builtin stack trace** |
| avm2/pixelbender_parse_errors | 0/6 | parser error mapping (IoError→#2030, else #2004) |
| avm2/pixelbender_no_out_param | 0/6 | parser + same stack trace |
| avm2/pixelbender_select_kinds | 0/8 | parser kind validation (2 of 8 compile) |
| avm2/pixelbender_multiple_out_params | 0/1 | LAST declared out param wins |
| avm2/shaderparameter_value | 0/4 | pure AS surface (bare ShaderParameter, by-ref value) |
| avm2/blend_shader_luma_lighten | 1/3 | URLLoader .pbj + #2007 null-data + blendMode="shader" |
| avm2/pixelbender_effect_glassDisplace_shaderfilter | 0/4 | ShaderFilter identity + generateFilterRect (512×512 growth) |

Six render-only siblings (`pixelbender_images`, five `effect_*`) already
pass trivially (0 trace lines). `tests.rs:9-60` in the pixel_bender crate
has a golden parsed-shader fixture; the corpus tests ship `.pbasm`
sidecars that are readable specs per test.

### Stage3D side — 15 candidates, ~750 graded lines

| test | lines | needs |
|---|---|---|
| stage3d/request_matching_profiles | 0/190 | profile negotiation (§3.6), 126 ticks |
| avm2/stage3d_context3d_string_args | 0/158 | string-arg #2008 validators (setCulling etc.) |
| avm2/stage3d_blend | 0/81 | setBlendFactors accepting valid values (trace is test-side) |
| avm2/stage3d_agal_upload_errors | 0/66 | **AGAL bytecode validator** (#3696 w/ token pos, #3612, …) |
| avm2/stage3d_x_y | 0/22 | Stage3D.x/y coercion |
| avm2/stage3d_program_constants_invalid_input | 0/21 | setProgramConstants validation |
| stage3d/request_profiles | 0/16 | negotiation + dispose→null, 12 ticks |
| avm2/context3d_creation | 0/9 | context3DCreate at END-OF-FRAME (one-frame delay) + stack trace |
| avm2/stage3d_errors | 0/7 | error family |
| avm2/stage3d_errors_swf_29 | 0/6 | version-gated variants |
| avm2/stage3d_errors_atf | 0/3 | ATF upload errors |
| avm2/stage3d_multistage_triangle | 0/3 | stage.stage3Ds count (4) + configure traces |
| stage3d/sampler_odd_size | 0/1 | BitmapData fillRect/getPixel32 + context plumbing to reach it |
| stage3d/scissor_rectangle_invalid | 0/1 | Rectangle.toString inside CONTEXT3D_CREATE handler; Context3D method surface must not throw (AGALMiniAssembler runs as pure AS — agal_compiler already passes on our VM) |
| avm2/stage_stage3Ds_vector | 0/1 | stage.stage3Ds Vector identity |

21 render-only stage3d tests already pass trivially. NONE of the 42
candidates is `known_failure` or `ignore` upstream; their `with_renderer`
gates reflect Ruffle's wgpu-only implementation, not trace dependence.

## 2. The one strategy-level finding

**Ruffle has NO CPU PixelBender evaluator.** `run_pixelbender_shader` is
implemented only by the wgpu backend (`render/wgpu/src/pixel_bender.rs:353`);
canvas/webgl/null all return Unimplemented. Even Vector/ByteArray targets
run a GPU pass into Rgba32Float and read back. So the port is: their PBJ
**parser** (`render/pixel_bender/src/parser.rs`, 834 lines — clean to
transliterate) + a **from-scratch C evaluator** using the naga transpiler
(`render/naga-pixelbender/src/lib.rs:857-1420`) as the opcode-semantics
spec. 45 opcodes implemented there; our test set is fully inside that set
(the 10 unimplemented ones — Exp2/Log/Log2/MatMatMul/LogicalXor/BoolToInt/
VectorEqual/VectorNotEqual/BoolAny/BoolAll — panic in Ruffle and appear in
no test). Registers are vec4-f32 + parallel vec4-i32 banks; matrices are
column-major across consecutive regs; execution model is
pixel-independent, no tiles; `_OutCoord` is pixel-CENTER (x+0.5, y+0.5).

## 3. Byte-level rules (from the sweeps; cites are Ruffle files)

1. **Parse at construction.** `new Shader(bytes)` → ShaderData →
   `_setByteCode` parses immediately; IoError→EOFError #2030, everything
   else→ArgumentError #2004 (`shader_data.rs:31-36`). Ruffle panics (not
   errors) on unknown opcode / bad meta type / mask asserts — we must NOT
   copy the panics; map to #2004.
2. **ShaderData surface** (`shader_data.rs:20-89`): shader-level metadata
   as dynamic props with single-int values as plain ints
   (`tint_as_int=true`); per-param `ShaderParameter`/`ShaderInput` under
   the param name; TWO independent index counters (normal vs texture);
   `_OutCoord` and `qualifier==out` params SKIPPED entirely. Param
   metadata values: single ints become 1-ELEMENT ARRAYS
   (`tint_as_int=false`); floats with no fractional part print as ints
   (`pixel_bender.rs:155-161`). `defaultValue` also initializes `.value`.
   `index` = declaration order among surviving normal params.
3. **ShaderJob.start** is synchronous either way; no COMPLETE event.
   Output-channel gate first: channels ∉ {3,4} → #2162. Bitmap target →
   pixel writeback; else Bytes{width,height}: ByteArray → raw f32 LE at
   offset 0 (position unmoved), Vector.<Number> → storage replaced;
   anything else → #2004 AFTER the run. 3-channel output: alpha forced
   1.0 on bitmap, de-padded (length 3) on Vector readback.
4. **Param value coercion at start()** (`pixel_bender.rs:27-147`): value
   must be Array/null; elements ONLY Number/Integer accepted (no string
   coercion, bool/null/undefined/Object/Array → #2004); missing/short →
   0.0 pad; EXTRA ELEMENTS NEVER READ (so `[1,2,3,4,"test"]` on float4
   succeeds); array holes → 0; floats `as f32`, ints/bools `as i16`.
   **Replaced ShaderParameter** (overwrote `shader.data.foo` itself) →
   silent fallback to metadata defaultValue (`shader_job.rs:124-128`).
   `.value` is stored BY REFERENCE and never re-read/mutated by start().
   Input sizing: needs ≥ W*H*channels floats else #2165 (message %1 =
   SHADER name, not input name). ByteArray inputs assert little-endian.
5. **unorm8 quantization** (the main parity hazard for the ~16 hex-pixel
   tests): clamp(x,0,1)*255 round-to-nearest (2.1/8→0x43=67), ∞→0xff,
   **NaN→0x00**. getPixel32 prints ARGB. Almost all targets are 1×1
   BitmapData — the "pixel store" burden is trivial.
6. **Stage3D negotiation** (`Stage3D.as` + `stage_3d.rs:6-69`): fixed
   priority standardExtended > standard > standardConstrained >
   baselineExtended > baseline > baselineConstrained; highest-ranked
   REQUESTED profile wins regardless of vector order; #2008 messages
   differ singular ("profile") from `checkProfile` vs plural ("profiles")
   from the empty-vector check; render mode string never validated.
   Context creation is DEFERRED to end-of-frame (one-frame delay — why
   request_profiles needs 12 ticks, matching 126); dispose() →
   `context3D` null. driverInfo is "Dummy Ruffle driver" but neither
   profile test grades it.
7. **Stack traces**: pixelbender_eof / no_out_param grade a 5-frame
   builtin stack: `ShaderData/_setByteCode()` → `ShaderData()` →
   `Shader/set byteCode()` → `Shader()` → `Test()` — dictated by
   Ruffle's AS-side class layout. Our Shader/ShaderData must produce
   equivalent frames in getStackTrace(). NAMED RISK (§5.1).

## 4. Tranches

Order: S1 first (cheapest, proven shape), then P1→P2, then the tails.

### Tranche S1 — Stage3D API surface · predicted +10 of 14 · MEDIUM
`stage.stage3Ds` (Vector of 4, stable identity), Stage3D x/y +
requestContext3D/MatchingProfiles per §3.6, deferred context3DCreate at
the end-of-frame phase, Context3D as a validating no-op surface (profile
getter, dispose, setCulling/setProgramConstants/setBlendFactors/…
string-arg #2008 validators — string_args' 158 lines enumerate them),
program_constants_invalid_input, the errors family, sampler_odd_size,
scissor_rectangle_invalid (methods must accept valid input silently).
Excluded: agal_upload_errors (S2). Risks: context3d_creation's
event-vs-frame interleaving; errors_atf's messages.

### Tranche S2 — AGAL validator · predicted +1 · SMALL-MEDIUM
`agal_upload_errors` (66 lines): Program3D.upload validation — #3612
little-endian check, #3696 sampler-register consistency with token
positions, and whatever else its .as enumerates. Pure bytecode
validation; the AGAL assembler itself is test-side AS (already runs).

### Tranche P1 — PBJ parser + Shader/ShaderData/ShaderParameter surface ·
predicted +6 of 8 · MEDIUM
Port parser.rs (strings NUL-terminated; floats BIG-endian f32; ints/regs
little-endian; swizzle/mask encodings; metadata association rule
parser.rs:799-834; validation: float-only Ceil/Sign, Select kind rules,
If/Select int-condition rule, MissingOutputParameter; padding SKIPPED not
validated; qualifier byte `2`=out else in). Surface per §3.1-3.2.
Yields: parse_errors, select_kinds, shaderdata, dithering,
shaderparameter_value, param_qualifier (its 512 lines are #2004-no-out
repeats), and — gated on the stack-trace risk — eof + no_out_param.

### Tranche P2 — the evaluator + ShaderJob · predicted +14 of 18 · LARGE
C interpreter per §2/§3.3-3.5: vec4f/vec4i banks, the 45 opcodes
(semantics from naga-pixelbender lib.rs:857-1420 — copy Sign's
(x>0)-(x<0), BoolToFloat=zero-vec quirk, IntToBool=identity), if/else/
endif stack, Select, SampleNearest/Linear with CLAMP for ShaderJob
(transparent-black is ShaderFilter-only — lib.rs:106-118), dst-mask
zip rule (source component i → i-th SET bit), matrix packing, 1×1
BitmapData writeback with §3.5 quantization, Vector/ByteArray targets,
input textures + #2165. Yields the 16 BitmapData math/matrix tests +
vector_output + input. Risk: rounding parity on half-way cases.

### Tranche P3 — tails · predicted +1 of 2 · SMALL
blend_shader_luma_lighten (URLLoader .pbj sidecar, #2007 on null data,
blendMode side effect — no execution needed). Stretch:
glassDisplace_shaderfilter (ShaderFilter identity semantics +
generateFilterRect 512×512 growth — touches the filter pipeline).

**Arc prediction: +32 of 42.** Re-predict after each tranche (arc
convention).

## 5. Named risks

1. **Builtin stack-trace frames** (P1): two tests grade
   `ShaderData/_setByteCode()`-shaped frames from inside `new Shader()`.
   If our getStackTrace can't represent builtin-internal frames, those 2
   tests cap below full pass. Check how existing error-stack tests
   handle builtin frames FIRST; budget a mechanism if absent.
2. **unorm8 rounding parity** (P2): expected bytes come from Flash (and
   Ruffle's GPU agrees) — round-to-nearest on clamp*255, NaN→0, ∞→255.
   Exact-half cases unverified; if a test hits one, resolve from its
   recorded byte, not from a rounding-mode guess.
3. **End-of-frame event phase** (S1): context3DCreate must land after
   exitFrame of the requesting frame and before enterFrame of the next
   (context3d_creation grades the interleaving exactly).
4. **`_OutCoord` is pixel-center** — off-by-half errors will pass 1×1
   tests and fail `input`'s 4×4; test the 4×4 case early in P2.

## 6. Postmortems

(append per tranche as shipped)
