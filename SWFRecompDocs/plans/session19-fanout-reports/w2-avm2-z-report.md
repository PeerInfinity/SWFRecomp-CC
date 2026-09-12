# w2-avm2-z report — `DisplayObject.z` (slice Z)

**Verdict: GO, delivered. +2 pass, both headlines flip. No regressions found.**

* Branched from master **`f48c532bf`** ("recompiler: LINESTYLE2 cap and join styles reach the
  stroke builder"), the tip at the time this agent started.
* Patch: `SWFRecompDocs/plans/session19-fanout-reports/w2-avm2-z.patch` (also in the main tree).
* **New files: none.** One file touched: `SWFModernRuntime/src/avm2/avm2_display.c`
  (+62 / −6). No header, no CMake, no `verify_output.py` source-list change.

## Ledger

| test | trace before | trace after | pixel before | pixel after |
|---|---|---|---|---|
| `avm2/displayobject_z` | **output_mismatch** 6/38 (uncaught #1009 at line 9) | **PASS** 38/38 | FAIL 270806 outliers / 6500 | FAIL **211814** / 6500 (verdict unchanged) |
| `avm2/geom_transform` | **output_mismatch** 71/74 | **PASS** 74/74 | FAIL 12746 / 4000 | FAIL **12746** / 4000 (byte-identical verdict + count) |

Both headlines were re-run under `--mode=graphics` as well: **both PASS** there too.

Guard tests, all `PASS` before **and** after (no-graphics unless noted):
`avm2/perspective_projection_basic`, `avm2/edittext_autosize_lazy_bounds_props`,
`avm2/stage_properties2`, `avm2/displayobject_transform`, `avm2/matrix3d`,
`from_shumway/avm2/flash/geom/matrix3d/TransformBasics`,
`from_shumway/avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass`.

`regression` suite: `avm2_parent_child_render`, `avm2_graphics_runtime`,
`avm2_goto_catchup_scale`, `avm2_typed_value_ops`, `avm2_static_text`,
`avm1_parent_child_modify_place` — all **PASS** after. (`avm1_parent_child_modify_place` is the
only regression test whose sources mention `transform` at all; none mention `z` or `matrix3D`.)

## Mechanism

Ruffle `45be8d536` gave `DisplayObjectBase` a plain `f64 tz`
(`core/src/display_object.rs:472/1621`) that is **not** part of the 2D matrix. Four wiring points,
all implemented:

1. `get z` → `tz` (was `do_get_zero`).
2. `set z` → store `tz`, **raise the matrix3d stub bit**, and mark transformed-by-script
   (`avm2/globals/flash/display/display_object.rs:388-401`). The stub bit is why the expected
   output flips `transform.matrix` to `null` and `transform.matrix3D` to a live Matrix3D the
   instant anything assigns `z` — *including `z = 0`*. That missing bit is the entire cause of
   the old `#1009 … (accessing field: rawData)` death at expected line 9.
3. `Transform.matrix3D` getter → `Matrix3D::from_matrix(matrix)` then `set_tz(z as f32)`
   (`geom/transform.rs:294`): `m3d_from_ext` now takes `tz` and writes `raw[14]`.
4. `Transform.matrix3D` setter → `set_z(matrix3d.tz())`, and its **null arm resets `z` to 0**
   (`transform.rs:319-329`).

Storage is a `dont_enum` dynamic property `__mtz` on the display object, the same idiom the file
already uses for `__m3dstub` and the four `__pp*` perspective slots. **No struct field, so
`avm2_globals.h` is untouched** — the header siblings are editing. All edits are inside
`avm2_display.c` and textually distant from the `avm2_display.c` hunks w2-loaders and
w2-gfx-geometry landed (those are in the SimpleButton / bounds regions).

f32 narrowing is free: `avm2_geom_matrix3d_new` already runs `m3d_narrow` over the whole array, so
`raw[14]` is quantised exactly as Ruffle's `set_tz(z as f32)`. `±1000000000` round-trips exactly.

### Three places I deliberately did **not** set `z`

Verified against Ruffle source, because each looked like an obvious place to "also" carry `tz`:

* `Transform.matrix = <Matrix>` / `= null` — `transform.rs:71-93` touches the stub bit and the 2D
  matrix only. `geom_transform` depends on this: after `sprite3D.transform.matrix = null`, `z`
  must still be **8**.
* `DisplayObject.transform = t` — `display_object.rs set_transform:822-848` copies matrix +
  stub bit + colour transform, and **not** `z`. So `m3d_to_ext` stays 2D-only and the tz write
  lives at the `Transform.matrix3D` setter call site instead.
* `Stage` — Ruffle's `Stage.as` overrides only `set z` (→ #2071); the getter is inherited. Our
  stage override table now uses `do_get_z` instead of `do_get_zero`, which is behaviourally
  identical (the setter always throws, so stage `tz` can never become non-zero) but no longer a
  second, divergent implementation.

## Refutations / premise checks

* **The brief's "+2 effective" survives intact** — both rows really are one mechanism, and both
  land on `pass`, not on `ruffle_matched`. Neither test is `known_failure`.
* **Slice Z's own claim that `m3d_from_ext` "hardcodes `raw[14] = 0`" was true but incomplete**:
  the getter was only half the `geom_transform` story. The other half is that the **setter**
  dropped `raw[14]`, so even a correct getter would have read back 0 for `sprite3D`. Both halves
  are fixed; fixing only the getter would have flipped 0 of the 3 diff lines.
* **`avm2/textblock_recreateline` moves one line, and it is an improvement, not a regression.**
  It sets `line2.z = 30` and traces `line2.z` *after* `recreateTextLine`, which in Flash resets
  every property. Expected (Flash) line 50 is `0`; we used to print `0` **by accident** (our `z`
  setter was a no-op) and now print `30`. Ruffle's own `output.ruffle.txt` line 50 is also `30`,
  and so are lines 41/43/46/47/48/49 where we already matched Ruffle. The test is
  `known_failure = true` and was `output_mismatch` at 41/180 before and stays `output_mismatch`
  after; the real gap is `TextBlock.recreateTextLine` not resetting the line's display-object
  properties, which is unrelated to this slice. Net effect: strictly closer to Ruffle's diff set.
* **The pixel side behaved exactly as slice Z predicted, and the change is NOT a pixel
  regression.** `geom_transform` is bit-for-bit the same comparison (12746 / 4000) before and
  after — its image failure is upstream drift from ruffle `45be8d536`, not ours.
  `displayobject_z`'s outlier count *drops* 270806 → 211814 purely because the test used to die
  before `testImageComparison()` ever ran (blank stage); now it runs and draws the 8 unscaled
  stacked bitmaps. Verdict is FAIL → FAIL either way. Matching it needs the renderer-wide
  `projection × view` work the brief scoped out.

## Patch scope

`SWFModernRuntime/src/avm2/avm2_display.c` only:
* new `M3D_TZ_KEY` + `m3d_tz_get` / `m3d_tz_set` next to `m3d_stub_get`/`m3d_stub_set`;
* `m3d_from_ext` gains a `double tz` parameter (sole caller updated);
* `transform_set_matrix3d`: writes `tz` from `raw[14]` on the object arm, resets it to 0 on the
  null arm;
* new `do_get_z` / `do_set_z` next to `do_get_zero`;
* `add_getset(ctx, dobj, "z", …)` now points at them; the Stage override table's `z` getter
  likewise.

## Risks

1. **Any AVM2 content that assigns `z` now sees `transform.matrix == null`** (and a live
   `transform.matrix3D`). That is Flash's and Ruffle's behaviour, but content that sets `z` and
   then reads `transform.matrix` without a null check will now take a `#1009` where it previously
   got a matrix. No corpus test in the affected set does this; the only `.z =` users in the whole
   test tree with AS sources are `displayobject_z`, `textblock_recreateline`,
   `edittext_autosize_lazy_bounds_props`, `stage_properties2` (all checked), plus Vector3D `.z`
   in `vector3d_near_equals` / `matrix3d_*` / `stage3d_*` helpers, which is a different class.
   Game bring-ups (Flixel/Snailiad/EQ) do not use `z`.
2. `do_set_z` calls `mark_transformed_by_script`, which Ruffle also does. If any timeline test has
   a display object whose `z` the *timeline* sets, this would newly pin it against timeline
   overwrite — but nothing on the SWF tag side writes `z`, so this can only fire from script.
3. The tz dyn prop is `dont_enum`, so it cannot leak into `for…in` / `describeType`, same as the
   existing `__m3dstub` and `__pp*` slots.

## Tests run

Worktree `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a1259ef47d3769cd4`, recompiler
built fresh in-worktree, `SWFRECOMP_COMPILE_TIMEOUT=2400`, sequential. A/B by `git apply -R` /
`git apply` of the patch (never `git stash`). Logs in
`<scratchpad>/w2-avm2-z/{before,after,before-dz,before-tb,after-tb}.log`.

## New unclaimed leads

* **`avm2/displayobject_z` + `avm2/geom_transform` pixel halves** (the P1/P2 the drift report
  parked). Now that the trace side is green, `displayobject_z`'s image is a clean, self-contained
  probe for a perspective pipeline: a per-object `focal/(focal + tz)` scale about the projection
  centre plus a near-plane reject at `focal + tz <= 0`, with `focal ≈ 480.25` at 500 px and
  fov 55°. The test deliberately brackets the cull threshold (`z = -490` invisible, `-450`
  visible) and stacks 100 sprites to the vanishing point. Price it against the `[image_comparisons]`
  tolerance table (6500 / 17500), not against pixel identity. Graphics-agent work.
* **`TextBlock.recreateTextLine` does not reset the recreated line's display-object properties**
  (`avm2/textblock_recreateline`, 41/180). Ruffle fails it too and our output now agrees with
  Ruffle on the whole `blendMode … z` block, so the *reachable* target is `ruffle_matched`, not
  `pass`. Worth a cheap diff-set comparison against `output.ruffle.txt` to see how many of the
  remaining 139 lines are ours versus shared with Ruffle.
* **`rotationX` / `rotationY` / `scaleZ` are still `do_get_zero` / `do_get_one` + no-op setters.**
  Ruffle stubs these too (no backing field), so there is no cheap flip here — but they sit next to
  `z` and will be the next thing a real Matrix3D-on-DisplayObject implementation needs.
