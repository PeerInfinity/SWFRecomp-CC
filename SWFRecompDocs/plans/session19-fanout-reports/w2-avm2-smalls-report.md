# w2-avm2-smalls — ByteArray #2136 predicate, BitmapFilter abstract gate, Matrix3D #2004 (G3, G4, Q1/Q2)

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a3fc94693a65863b8`
Patch: `SWFRecompDocs/plans/session19-fanout-reports/w2-avm2-smalls.patch`
(also copied to the main tree's `session19-fanout-reports/`).

**New files: NONE.** Four modified runtime files, all in `SWFModernRuntime/src/avm2/`:
`avm2_bytearray.c`, `avm2_filters.c`, `avm2_pixelbender.c`, `avm2_stage3d.c`.
No recompiler change, no header change, no build-system change, no new test fixture.

## 1. Verdict / ledger

| item | test | before | after |
|---|---|---|---|
| G3 | `avm2/bytearray_bad_symbol_class` | `output_mismatch` 1/3 | **PASS** |
| G3 | `avm2/bytearray_bad_symbol_class_other_movie` | `output_mismatch` 4/6 | **PASS** |
| G4 | `avm2/bitmap_filter_abstract` | `output_mismatch` 0/6 | **PASS** |
| Q1 | `avm2/matrix3d_recompose_edge_cases` | `ruffle_matched` (57 diff lines vs `output.txt`) | `ruffle_matched` (**8** diff lines) |
| Q2 | `avm2/matrix3d_append_rotation` | `ruffle_matched` (1 diff line, not 3) | **PASS** |

**Effective yield: +3** (G3 ×2, G4 ×1), exactly as priced by `w1-avm2-report.md`.
Q1/Q2 are quality only (+0 effective, both rows were already `ruffle_matched`):
Q2 does flip `ruffle_matched → pass`, Q1 does not — see §4 for the refutation of
w1's "only one mechanism in the file" claim, and §5 for the one judgement call in
this patch (an epsilon the corpus cannot pin).

**One regression was found and fixed mid-flight**: Q1's first spelling used an
exact `norm != 1.0` and broke `avm2/matrix3d_compose` (`pass → output_mismatch`).
See §5. The delivered patch has `matrix3d_compose` back at `PASS`.

## 2. G3 — the ByteArray symbol-class predicate

Confirmed w1's diagnosis at HEAD. Both fixtures bind `MyBytes` (a `ByteArray`
subclass) to char **100 = `DefineVideoStream`**; the generated
`RecompiledABC/abc_timeline.c` for the first fixture literally reads
`const Avm2CharInfo avm2_generated_chars[] = { { 100, 7, ... } }` (kind 7 =
`AVM2_CHAR_VIDEO`). Flash and Ruffle both raise plain `Error` **#2136**
("The SWF file file:///test.swf contains invalid data."); we constructed an empty
array and traced `created: `.

**Patch** (`avm2_bytearray.c`, `ba_native_init` + one new file-static helper):

* the existing binary-payload scan is unchanged and still runs first; the new arm
  fires only on the `bin == NULL` path, so no behaviour changes for any class that
  *does* resolve to a `DefineBinaryData`;
* the predicate is **"a KNOWN character of a non-binary kind"**, spelled
  `ci != NULL && ci->kind != AVM2_CHAR_OTHER`. `abc_timeline.cpp:1672` records a
  kind-8 (`OTHER`) `CharInfo` for `TAG_DEFINE_BINARY_DATA` **and for nothing else**
  (verified: `ci.kind = 8` has exactly one call site in the whole recompiler), so
  kind 8 is precisely "binary" here. An id that names no character at all stays
  silent, which is the "child movie whose binaries were not emitted" case w1 warned
  about;
* the char lookup is **keyed by the DEFINING movie** — `ba_char_info_for_class`
  walks `cls->super_class` for the first class whose `instance_init.file` maps to a
  child movie (`avm2_display_movie_for_abc`, already exported) and searches *that*
  movie's `chars[]`, falling back to the main movie's `avm2_generated_chars`. This
  is deliberately stricter than `avm2_display.c`'s own `char_info()`, which scans
  main-then-every-child by raw id: an unkeyed scan is exactly how a child's
  ByteArray at char N would collide with the parent's shape at char N and start
  throwing. (That same unkeyed scan is still the shape of the *binary* lookup above
  — see `w1-avm2-report.md` lead 3; I left it alone, since narrowing it is a
  separate behaviour change with no corpus test.)
* the URL comes from the `SWF_URL` compile define directly (`#ifdef SWF_URL`,
  else `""`), the same source `avm2_display.c::root_swf_url` reads. **No export
  from `avm2_display.c` was needed** — w1 priced "a tiny exported wrapper around
  `root_swf_url`"; it is unnecessary, which keeps this patch textually clear of
  **w2-loaders**, who owns that file.

The `_other_movie` fixture's `at Function/<anonymous>()` frame needed no work
(`avm2_error.c` already renders it), as w1 predicted.

## 3. G4 — the BitmapFilter abstract allocator gate

Confirmed: we traced `Constructed` three times where Flash throws #2012 twice.

**Patch**, using the *existing* idiom rather than a second mechanism:

* `avm2_filters.c::avm2_register_filters` calls `avm2_builtin_set_abstract(ctx,
  g_bitmapfilter_class)` — the shared `stub_native_init_abstract` gate in
  `avm2_globals.c` (the same one Capabilities and the fourteen platform stubs use).
  It already names the class from `obj->cls`, so `CustomFilter$` falls out for free;
* `new_filter_class` clears `c->native_init = NULL` for the nine engine filters,
  and `avm2_pixelbender.c` does the same for `ShaderFilter`. `avm2_builtin_class`
  copies `native_init` down from the super (`avm2_globals.c:381`), and so does the
  SWF-class link step (`avm2_class.c:1405`) — which is exactly what makes
  `CustomFilter` (direct subclass of the base) throw while
  `CustomConvolutionFilter` (via `ConvolutionFilter`) constructs. This reproduces
  Ruffle's "has one of the ten engine filter classes in its chain" rule as
  inheritance, with no chain walk.
* No script-new guard is needed: nothing in the runtime mints the `BitmapFilter`
  base (`avm2_filters_bitmapfilter_class()` has exactly two callers — the accessor
  and `avm2_pixelbender.c`'s super argument), so the unconditional form is safe.
  `avm2/abstract_classes` does not enumerate `BitmapFilter`, so that test is
  untouched either way.

## 4. Q1 — Matrix3D.recompose quaternion #2004, and the REFUTATION that came with it

Implemented in `avm2_stage3d.c::matrix3d_recompose`: in the **quaternion arm only**
(the `axisAngle` sibling is genuinely unvalidated in FP), throw `ArgumentError`
#2004 when `x² + y² + z² + w² != 1.0`, **before** any write to `e->m`. Verified
against all twelve `testQuaternion()` inputs: the five unit spellings pass, and
`(0,0,0,0)`, `(0.5,0,0,0)`, `(2,0,0,0)`, `(1,1,1,1)` plus the three non-finite ones
throw (a non-finite component fails `== 1` on its own, so no `isfinite()` arm).
This closed **49 of the 57** diff lines.

> **Refutation of `w1-avm2-report.md` §Q1**: "This is the ONLY Flash/Ruffle
> disagreement in the file" is **wrong**. Eight lines survive, in a second,
> undiagnosed family that w1 did not mention — the last three `axisAngle` rows
> (non-finite) and all five of `testSpecialValues()`. Diffed actual output:
>
> ```
> NaN scale            Flash NaN,NaN,NaN,NaN,0,1,0,0,...   ours 1,NaN,NaN,0,NaN,...
> special translation  Flash NaN,NaN,NaN,0,...,Inf,-Inf,NaN,1   ours 1,0,0,0,0,1,0,0,...
> ```
>
> **Mechanism (new, diagnosed here):** FP's `recompose` is a chain of genuine 4×4
> matrix products, not the direct slot writes we (and Ruffle) do, and `0 * NaN =
> NaN` poisons cells our algebra never touches — including the projection column
> `m[3]/m[7]/m[11]` and `m[15]`, which are literal 0/1 for us. The `special
> translation` row is the proof: a translation of `(∞, −∞, NaN)` cannot reach the
> 3×3 block by any shortcut, but in a real `R · T` product `m[0][0] = R00·T00 +
> … + R03·T30 = … + 0·∞ = NaN`. Closing those 8 lines means rewriting recompose as
> `S`/`R`/`T` products — NOT the "~12 LOC" Q1 was priced at, and it moves no test
> (the row is `ruffle_matched` before and after).

Q1 **is kept in the patch**: it is strictly closer to Flash (the oracle is the
test's own `output.txt`), and the run confirms the row is still `ruffle_matched`
(our remaining diff set is still a subset of Ruffle's). Its cost is the epsilon
below, which is the single reviewable judgement call in this patch; reverting Q1
alone is a one-hunk revert if the coordinator disagrees.

### The epsilon — Q1's regression, and the honest bracket

The first spelling, `x²+y²+z²+w² != 1.0`, **regressed `avm2/matrix3d_compose`
from `pass` to `output_mismatch`**. That test round-trips
`decompose("quaternion") → recompose(..., "quaternion")` on a sheared matrix, and
the extracted quaternion is genuinely NOT unit: hand-recomputing from the
fixture's own traced `rawData` gives `(0, 0.018509, 0, 0.999695)`, norm
**0.99973** — off by 2.7e-4 — and FP accepts it. A 1e-4 window still rejected it
(measured, not assumed). So the bracket the corpus gives is:

* **wider than 2.7e-4** (`matrix3d_compose` must pass), and
* **narrower than 0.75** (the nearest REJECTED norm is 0.25).

Nothing narrows it further — every rejected norm in the edge-case fixture is 0,
0.25, 4 or non-finite. The patch uses **1e-2**, inside that bracket with ~37x
headroom over the observed legitimate round-trip and ~75x below the nearest real
rejection, and the code comment says exactly that, so a future fixture that pins
FP's real value has one constant to change. This is a
`RUFFLE_COMPAT_TWEAKS.md`-class choice and should be recorded there if the patch
lands. Stated risk: content calling `recompose(..., QUATERNION)` with a
far-from-unit quaternion now throws where it previously returned a matrix — which
is what FP does, so no Flash-authored content can depend on the old behaviour.

## 5. Q2 — `matrix3d_append_rotation`: DONE, `ruffle_matched → pass`

Fresh actual vs `output.txt` showed **one** surviving line, not three:

```
22c22
< appendRotation zero axis, NaN pivot: NaN×16
> appendRotation zero axis, NaN pivot: NaN,NaN,NaN,0,NaN,NaN,NaN,0,NaN,NaN,NaN,0,NaN,NaN,NaN,1
```

> **Refutation of the s18 L1 / w1 §Q2 write-up:** the other two rows attributed to
> this item (`zero axis, 0 degrees` / `180 degrees`) **already match Flash** —
> `m3d_build_rotation`'s "a zero-length axis skips only the normalization" arm is
> the landed fix. The item was over-counted by two lines.

The survivor is the **same** `0 · NaN` 4×4-product mechanism as §4: FP composes a
pivoted rotation as `T(−p) · R · T(p)` with three real products, and with
`p = (NaN,NaN,NaN)` the zeros in `R`'s projection column meet a NaN, so all 16
cells go NaN. We short-circuited the pivot algebraically into `t[12..14]`
(`matrix3d_xform`, `kind == 2`), which is exact for finite pivots and is precisely
why the NaN never spread.

**Patch (6 LOC):** build `T(-p)` and `T(p)` with the existing
`m3d_build_translation` and run the existing double-precision `m3d_mul` twice.
Algebraically identical for finite pivots — the folded form's `px - p·Rcol` IS the
`c = 3` column of the product, and the 3×3 block picks up only `px * tmp[3]` with
`tmp[3]` an exact 0 — which is why the whole `matrix3d_*` family (25 tests,
`matrix3d_precision` included) is unmoved. This was priced at "~10 LOC" and is the
one wave-1 estimate on this board that held exactly.

## 6. Tests run (all `--mode=no-graphics`, sequential, `SWFRECOMP_COMPILE_TIMEOUT=2400`)

Baseline for every canary below is the s19 wave-0 board: none of them appears in
`wave0-trace-inventory.txt`, i.e. every one was `pass`/`ruffle_matched` at
`254145a5b`.

**Headlines, before → after** (before re-measured locally at HEAD, not copied):

| test | before | after |
|---|---|---|
| `avm2/bytearray_bad_symbol_class` | `output_mismatch` (1/3) | PASS |
| `avm2/bytearray_bad_symbol_class_other_movie` | `output_mismatch` (4/6) | PASS |
| `avm2/bitmap_filter_abstract` | `output_mismatch` (0/6) | PASS |
| `avm2/matrix3d_recompose_edge_cases` | `ruffle_matched` | `ruffle_matched` (57 → 8 diff lines) |
| `avm2/matrix3d_append_rotation` | `ruffle_matched` | **PASS** |

**ByteArray family (13/13 PASS)** — `bytearray`, `_compress`, `_errors`,
`_method_serialization`, `_oom`, `_readobject_amf0`, `_readobject_amf3`,
`_readutf8bytes_with_bom`, `_serialization`, `_string_null`, `_tostring`,
`_utf16`, `_writeobject`.

**Filter family (22/22 PASS)** — `bevel_filter`, `blur_filter`, `checkfilter`,
`color_matrix_filter`, `convolution_filter`, `displacement_map_filter`,
`displayobject_filters`, `drop_shadow_filter`, `filter_rewind`,
`filters_array_holes`, `glow_filter`, `gradient_bevel_filter`,
`gradient_glow_filter`, `vector_filter`,
`pixelbender_effect_glassDisplace_shaderfilter` (the ShaderFilter reset's own
canary), `bitmapdata_applyfilter_{blur,colormatrix,destpoint,destpoint_edges,
identity}`, `bitmapdata_filter_sourcerect`, `bitmapdata_draw_filters`.

**Matrix3D / Stage3D geometry family (25/25 PASS or `ruffle_matched`)** — every
`avm2/matrix3d_*` plus `perspective_projection{,_basic}`. `matrix3d_precision`
(the f32-rounding pin), `matrix3d_interpolate` (the other quaternion consumer)
and `matrix3d_compose` (the decompose→recompose round trip) are the three that
actually grade this patch, and all three pass.

**`regression` suite (8/8 PASS)** — `avm2_embed_bytearray` (THE canary for the G3
predicate: a real `DefineBinaryData` must still seed, not throw),
`avm2_parent_child_symbolclass_domain`, `avm2_parent_child_symbol_stride`,
`avm2_parent_child_render`, `avm2_parent_child_static_text`,
`avm1_parent_as3_child_payload`, `avm2_loader_stub`, `avm2_graphics_runtime`.

**66 distinct tests run, 0 regressions in the delivered patch.** All four modified
files also pass `gcc -fsyntax-only`. Not run: `--mode=graphics` (mode parity is
complete per `BRIEFS_COMMON.md`, and none of these changes touch a render path);
no images (none of these tests has an image comparison).

## 7. What I completed and what I left

**Completed: G3 (+2 effective), G4 (+1 effective), Q1 (quality), Q2 (quality,
`ruffle_matched → pass`).** Everything in the brief's scope shipped. The brief's
optional rider (Q2) turned out to be genuinely small — 6 LOC — and was taken.

**Left, with the completion mechanism named:**

1. **The 8 surviving lines of `matrix3d_recompose_edge_cases`** (§4). Mechanism
   diagnosed here and NOT in scope: FP's `recompose` is real 4×4 `S`/`R`/`T`
   products, so `0 · NaN` poisons the projection column and the translation row.
   Rewriting it is not the "~12 LOC" Q1 was priced at, moves no test (the row is
   `ruffle_matched` either way), and would owe the same 25-test geometry canary.
2. **FP's true quaternion epsilon** (§4). Bracketed to `(2.7e-4, 0.75)` by the
   corpus; 1e-2 chosen inside it. Completion = a `regression/` fixture built from
   the Ruffle exporter or Flash that walks norms across the bracket. I did NOT
   write one, because the exporter is Ruffle, and Ruffle does not implement the
   check at all — it could only produce the wrong answer. Flash Player itself is
   the only oracle that can settle it.
3. **`ba_native_init`'s unkeyed binary lookup** (§9 lead 2) — deliberately left
   as-is; narrowing it is a behaviour change with no corpus test.

## 8. Sibling-collision note

`builtin_class_impl` / the class-registration tables are shared machinery, and
**w2-loaders** owns `avm2_display.c`. My final patch **does not touch
`avm2_display.c` at all** — the `root_swf_url` export w1 priced turned out to be
unnecessary. My only class-registration edits are in `avm2_filters.c` and
`avm2_pixelbender.c`, which no sibling lists. **w2-avm2-json** edits
`avm2_json.c` / `avm2_error.c`; I touch neither. No merge coordination needed.

## 9. New unclaimed leads

1. **FP's Matrix3D geometry is real 4×4 products; ours is algebraic short-circuits.**
   This patch closes the `appendRotation` half; the `recompose` half (8 lines in
   `matrix3d_recompose_edge_cases`) is open, **+0 effective**, and owes the same
   25-test geometry canary. Ruffle has the same shortcut, so this is a
   Flash-vs-both divergence, not a Ruffle port gap.
   **Generalize the warning:** any "FP writes a literal 0/1 into a matrix slot"
   assumption in `avm2_stage3d.c` is suspect — FP gets those cells from a
   product, and only a NaN/∞ fixture can tell the two apart. `matrix3d_compose`
   is the trap that catches you (it round-trips a SHEARED matrix, so exact
   unit-norm reasoning fails there).
2. **`ba_native_init`'s binary lookup is still unkeyed by movie** (w1 lead 3). This
   patch keys the new `CharInfo` lookup by the defining movie but deliberately left
   the payload scan as-is. Two movies with the same raw char id can still cross-seed
   a ByteArray with the wrong payload. `ba_char_info_for_class` is now the ready-made
   template for fixing it.
3. **`AVM2_CHAR_OTHER` is overloaded as "binary" by construction.** The `kind = 8`
   slot is emitted only by `TAG_DEFINE_BINARY_DATA` today, and G3's predicate now
   depends on that. If anyone ever emits a kind-8 `CharInfo` for fonts/sounds (the
   enum comment invites it — "fonts, sounds, ... (not placeable)"), G3 silently stops
   throwing. A dedicated `AVM2_CHAR_BINARY` value would make this safe; it is a
   recompiler + header change, so out of scope here.
4. **`avm2/matrix3d_compose`'s Test.as carries an upstream TODO that this patch
   answers**: `// FIXME - add back 'QUATERNION' when Ruffle properly throws an
   exception.` (line 35). Ruffle still does not throw; we now do. If that FIXME is
   ever resolved upstream, the test grows a quaternion arm we already satisfy —
   worth watching as a free future row rather than a risk.
