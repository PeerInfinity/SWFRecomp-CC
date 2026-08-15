# Session 16 — wave 2 — w2-gfx-gradient (board leads P1 / P3 / P4)

**Agent:** `w2-gfx-gradient` · worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a8203094041d8f7c8`
**Brief of record:** `wave1-gfx-board.md` §P1, §P3, §P4.
**Oracle:** `~/CC/ruffle` — `render/wgpu/src/mesh.rs::CommonGradient::new` (290–353),
`core/src/avm2/globals/flash/display/graphics.rs::build_gradient_records` (170–219).

---

## HEADLINE

| lead | verdict | measured |
|---|---|---|
| **P1** gradient ramp walk | **GO — CONFIRMED, +3 flips** (+1 more with the linearRGB leg) | 3 comparisons fail→pass, board's Python model reproduced to the exact outlier count |
| **P4** LINESTYLE2 `HasFillFlag` gradient stroke | **GO — mechanism CONFIRMED and fixed; NOT a flip** | `acid-gradient-2` **12 555 → 79** outliers, but `max_outliers = 0` so it still fails |
| **P3** AVM2 `beginGradientFill` null alphas/ratios | **GO — mechanism CONFIRMED and fixed; NOT a flip** | `graphics_gradients_nulls` **117 600 → 600** outliers, `max_outliers = 0` so it still fails |
| **bonus leg** linearRGB quantisation space | **GO — +1 flip, 6 added lines** | `gradient_issue_9892` 2331 → 2317 vs budget 2329 → **pass** |

**Net priced flips: 4** (`visual/gradient_nonsequential_ratios`,
`visual/gradient_same_ratios`, `visual/gradient_radial_same_ratios`,
`visual/gradient_issue_9892`) — three from the base patch, the fourth needs the
linearRGB leg. **Zero regressions** on either the pixel or the trace axis.

Board pricing was "+3, likely +4" for P1 and "+1 each" for P3/P4 → **actual 4**,
with P3 and P4 refuted *as flips* but confirmed *as mechanisms* (both are now two
orders of magnitude closer; both are blocked on `max_outliers = 0`).

---

## NEW FILES (stage by name — s15 `git add -u` trap)

| file | why |
|---|---|
| `SWFModernRuntime/include/gradient_ramp.h` | the shared 256-row ramp walk, included by the recompiler (`SWFRecomp/src/swf.cpp`, relative path) **and** by both VMs (`<gradient_ramp.h>`; `SWFModernRuntime/include` is already on the runtime include path, same as `curve_flatten.h`) |

Modified (4): `SWFRecomp/src/swf.cpp`, `SWFRecomp/include/swf.hpp`,
`SWFModernRuntime/src/actionmodern/action.c`,
`SWFModernRuntime/src/avm2/avm2_display.c`.
**No `CMakeLists.txt` change** — deliberate, so the serial apply cannot collide
with `w2-gfx-flatten-legC` (its edits are at `swf.cpp` ~8653/8889; mine are at
~7110 / ~7290 / ~10250).
**No `render_webgpu.c` change** — the MSAA_SAMPLES invariant is untouched.

## PATCH FILES

| file | contents |
|---|---|
| `w2-gfx-gradient.patch` | **P1 + P3 + P4 + the linearRGB leg** — everything measured below, 4 flips |
| `w2-gfx-gradient-base-only.patch` | P1 + P3 + P4 without the linearRGB leg (3 flips) — provided only if the coordinator wants the smaller blast radius |

The linearRGB leg is 6 added lines on top of the base patch; both were graded
separately (`after` = base, `after2` = base + linearRGB).

---

## P1 — mechanism (board diagnosis confirmed verbatim)

Ruffle bakes the ramp by walking the **256 texels**, not the segments:

```rust
for t in 0..256 {
    if last + 1 < n && t > records[last + 1].ratio { last += 1; }   // ≤1 step per texel
    next = min(last + 1, n - 1);
    a = if t <= records[last].ratio || records[last].ratio == records[next].ratio { 0.0 }
        else if t > records[next].ratio { 1.0 }
        else { (t - last.ratio) / (next.ratio - last.ratio) };
    colors[t] = lerp(convert(last.color), convert(next.color), a) as u8;
}
```

All three of our builders walked **segments**
(`for ratio in [stop[s-1].ratio, stop[s].ratio]`), which is equivalent **iff the
ratio list is strictly increasing** — something SWF does not require and Ruffle
never enforces (it never sorts).

* duplicate ratio → Ruffle emits one 1-texel band per stop and shifts the rest of
  the ramp along; the recompiler emitted **0 rows**, the runtime emitted one texel
  of the wrong colour;
* decreasing ratio → Ruffle pins `a = 1.0` (a plateau of the *next* colour); all
  three emitted nothing;
* and because the recompiler *appends* rows, its per-gradient row count stopped
  being 256.

**Measured, not assumed** (`SWFRecomp` run directly on the test SWF):

| test | rows emitted into `u8 gradient_data[256][4]`, BEFORE | AFTER |
|---|---:|---:|
| `visual/gradient_nonsequential_ratios` | **336** | **256** |
| `from_shumway/acid/acid-gradient-2` | 256 | 256 |

336 rows into a 256-row slot is a live over-run of the gradient's own texture
allocation — the excess initialisers are dropped by the C compiler here (N = 1),
but in any SWF with a second gradient every later ramp would land on the wrong
texture row.

### The fix

One shared texel-indexed routine, `gradient_ramp_build()` in the new
`SWFModernRuntime/include/gradient_ramp.h`, called from all three sites. It
always writes exactly 256 rows, so the row-count invariant is now *structural*
instead of an argument that has to be re-made at every call site.

### Deliberate scope fence: per-channel arithmetic is UNCHANGED by the base patch

The three sites did not agree on rounding or on the linearRGB quantisation space:

| site | sRGB channels | linearRGB channels | alpha |
|---|---|---|---|
| recompiler `swf.cpp` | truncate | lerp linear → **convert back to sRGB** → round | truncate |
| runtime `action.c` / `avm2_display.c` | round (+0.5) | endpoints quantised to **u8 linear**, lerp, truncate | round |
| **Ruffle** | truncate | float linear endpoints, lerp, truncate, **store linear** | truncate |

The header therefore carries a `space` × `rounding` mode pair and each call site
keeps *its own* arithmetic. That is what makes the patch attributable: on a
strictly-increasing ratio list the new code is **byte-identical** to the old, so
the only pixels that can move belong to a duplicate or non-monotonic ratio.

**Proof (offline A/B, `<scratch>/w2gfxgrad/ramp_ab.c`):** the legacy recompiler
walk and the legacy runtime walk re-implemented verbatim next to the new shared
builder, over **400 000** randomised strictly-increasing stop lists (2–9 stops,
random RGBA, both interpolation modes):

```
trials=400000
recomp_mismatched_lists=0 (worst channel delta 0)
runtime_mismatched_lists=0 (worst channel delta 0)
legacy_rowcount != 256: 0
```

---

## P3 — mechanism (confirmed; fixed; not a flip)

`avm2/graphics_gradients_nulls` calls

```as3
graphics.beginGradientFill("linear", [0,0xFFFFFF,0,0xFFFFFF,0], null, null, matrix);
```

Ruffle's `build_gradient_records` takes the run length from `colors` and shortens
it **only for the optional arrays that are present**; a missing `alphas` gives
`alpha = 1.0`, a missing `ratios` gives `(i * 255) / (length - 1)` →
`0, 63, 127, 191, 255`. We `min()`ed against a length of **0** for the null args,
so `n == 0` and `beginGradientFill` cleared the fill — a blank stage.

Fix in `gfx_begin_gradient_fill`: detect presence (`AVM2_VALUE_OBJECT` and
non-NULL), drop absent arrays out of the `min`, default alpha/ratio per Ruffle,
and relax `argc < 4` to `argc < 2` (Ruffle's `args.try_get_object(2/3)` treats
absent exactly like null).

**Result: 117 600 → 600 outlier channels** (200 pixels) at `tolerance 5`. The
gradient now renders; the residual is a *band-boundary* disagreement against a
golden the toml documents as generated from Flash Player, not Ruffle. Because
`max_outliers = 0`, that is still a fail. **The board's "+1 flip, moderate
confidence" is refuted on the flip; the mechanism is confirmed.** Completion
mechanism for the remaining 600: someone has to decide whether the FP golden's
band edges are reachable at all (this is the same class as the board's own
"expected png generated from FP" caveat) — a disposition question, not a code
question.

---

## P4 — mechanism (confirmed; fixed; not a flip)

`SWFRecomp/src/swf.cpp::parseLineStyles`, LINESTYLE2 `HasFillFlag` arm called
`parseFillStyles(1)` and then kept only `fill[0].r/g/b/a`. A gradient FILLSTYLE
never populates those, so the stroke colour became `{0,0,0,0}`. Confirmed from
the generated C of `from_shumway/acid/acid-gradient-2`:

```
draws.h : extern u8 gradient_data[256][4];   // the ramp IS registered
draws.c : float color_data[1][4] = { { 0/255.0f, 0/255.0f, 0/255.0f, 0/255.0f } };
draws.c : ALL 1422 shape_data vertices carry style word 0x80000000  (stroke, colour 0)
```

Fix: `LineStyle` gains trailing fields (`fill_type`, `fill_spread_mode`,
`fill_index`, and `fill_interp` in the linearRGB leg — trailing and
self-localised, no textual overlap with siblings); the has-fill arm records them
for gradient FILLSTYLEs; the stroke vertex emitter packs
`0x80000000 | fill_type | (spread << 8)` with the *gradient* index. After the
fix all 1422 vertices carry **`0x80000010`**.

Why the packing is safe: the WGSL vertex stage reads `in.style.x & 0xFFu` for the
style type and bits 8–9 for the spread (`render_webgpu.c:129-131`), the CPU
rasteriser uses the identical `style_packed & 0xFFu`
(`avm2_cpu_raster.c:293,447`), and the only consumer of bit 31 is
`shape_hit_test.c:820`, which just classifies a hit as stroke-vs-fill.

**Result: 12 555 → 79 outlier channels** (26 pixels) at `tolerance 1`. Ruffle's
gradient-filled ring now renders; the 79 residual channels are edge/AA pixels on
the stroke outline. `max_outliers = 0`, so still a fail. **Board's "+1 flip"
refuted on the flip; mechanism confirmed and 99.4 % of the gap closed.**
Completion mechanism: the residual is stroke-outline geometry, i.e. the same
family `w2-gfx-flatten-legC` is working on — regrade `acid-gradient-2` after leg C
lands before spending anything else on it.

---

## BONUS LEG — linearRGB quantisation space (+1 flip, 6 lines)

The board flagged this as a real oracle divergence to be kept OUT of P1, and I
kept it out of the base patch. But `gradient_issue_9892` landed **2 outliers over
budget** with the base patch (2331 vs 2329), and that test is the one the board
identified as carrying `linearRGB` gradients — so I built the leg and measured it.

`swf.cpp::linearRgbLerp` converted back to sRGB before quantising and the static
style packing never set the shader's `is_linear_rgb` bit, whereas Ruffle stores
the ramp **in linear space** and converts per pixel in `gradient.wgsl`. The two
halves are consistent with each other, which is why the divergence was bounded
and invisible until a test got this close.

The leg is exactly 6 added lines: switch the static ramp to the Ruffle-exact
`GRADIENT_RAMP_LINEAR` mode, and OR `interpolation_mode << 10` into the style word
at the two fill-emission sites plus the new gradient-stroke site (the runtime
already did both halves correctly — `render_webgpu.c:2444`).

**Result: `gradient_issue_9892` 2331 → 2317, budget 2329 → PASS.** No other
comparison moved out of budget (`gradient_radial_same_ratios` 3761 → 3762 against
a 3860 budget).

---

## LEDGER — `--mode=graphics --images`, local Dawn, per comparison

`before` = pristine `cd04f80b9` sources; `after` = base patch;
`after2` = base + linearRGB leg. Every BEFORE number reproduces the grading CI
run `31748059158` exactly.

| comparison | tol / max_out | BEFORE | AFTER (base) | AFTER2 (+linearRGB) | verdict |
|---|---|---:|---:|---:|---|
| `visual/gradient_nonsequential_ratios [output]` | 36 / 1300 | 61 440 **fail** | **1 280 pass** | 1 280 **pass** | **FLIP** |
| `visual/gradient_same_ratios [output]` | 37 / 5130 | 6 912 **fail** | **5 120 pass** | 5 120 **pass** | **FLIP** |
| `visual/gradient_radial_same_ratios [output]` | 35 / 3860 | 6 675 **fail** | **3 761 pass** | 3 762 **pass** | **FLIP** |
| `visual/gradient_issue_9892 [output]` | 24 / 2329 | 3 755 **fail** | 2 331 fail (**2 over**) | **2 317 pass** | **FLIP (needs the leg)** |
| `from_shumway/acid/acid-gradient-2 [output]` | 1 / 0 | 12 555 fail | **79** fail | 79 fail | improved 99.4 %, no flip |
| `avm2/graphics_gradients_nulls [output]` | 5 / 0 | 117 600 fail | **600** fail | 600 fail | improved 99.5 %, no flip |
| `avm1/movieclip_begin_gradient_fill [output]` | 6 / 0 | 723 fail | 723 fail | 723 fail | md5 **identical** |
| `avm1/movieclip_line_gradient_style [output]` | 6 / 0 | 1 420 fail | 1 420 fail | 1 420 fail | md5 **identical** |
| `avm2/graphics_gradients [output]` | 1 / 0 | 3 338 fail | 3 338 fail | 3 338 fail | md5 **identical** |
| `visual/drawing_api/gradient_focal_point [output]` | 13 / 0 | 60 fail | 60 fail | 60 fail | md5 **identical** |
| `from_shumway/acid/acid-gradient-0 [output]` | 1 / 0 | 0 **pass** | 0 **pass** | 0 **pass** | md5 **identical** |
| `visual/simple_shapes/gradients/gradients [output]` | 1 / 0 | 0 **pass** | 0 **pass** | 0 **pass** | md5 **identical** |
| `regression/avm2_timeline_gradients [output]` | 255 / 0 | 0 **pass** | 0 **pass** | 0 **pass** | md5 **identical** |
| `regression/avm2_timeline_stroke_gradient [output]` | 255 / 0 | 0 **pass** | 0 **pass** | 0 **pass** | md5 **identical** |
| `avm1/color [output]` | 1 / 0 | 0 **pass** | 0 **pass** | 0 **pass** | md5 **identical** |
| `visual/simple_shapes/winding_rule [output]` | 0 / 0 | 0 **pass** | 0 **pass** | 0 **pass** | md5 **identical** |
| `regression/mask_nested_intersect [output]` | 0 / 0 | 0 **pass** | 0 **pass** | 0 **pass** | md5 **identical** |

**Every currently-passing comparison is byte-identical (md5) in both after legs.
No `pass → fail` anywhere.**

### Render canary

The set above is the standing `render_canary_tests.txt` gradient-bearing members
(`from_shumway/acid/acid-gradient-0`, `regression/avm2_timeline_gradients`,
`regression/avm2_timeline_stroke_gradient`,
`visual/simple_shapes/gradients/gradients`) plus non-gradient structural controls
(`avm1/color`, `visual/simple_shapes/winding_rule`,
`regression/mask_nested_intersect`) plus every gradient test in the corpus that
the change could reach. **All canary members: md5 identical, no explanation
needed.** The remaining standing-canary members (masks / filters / blend / text /
morph / timeline) were dropped from the A/B because the machine was at load ~40
for most of the session; the recompiler-artifact audit below covers them far more
broadly than a render would have (see the next section) — that is the honest
canary blind-spot statement for this patch.

### Trace

* `trace_status` **pass → pass on 17/17** tests in both after legs.
* The 4 tests that emit trace output have **byte-identical** `trace.txt` in
  `before` / `after` / `after2`.
* Expected: nothing in the patch touches trace-visible state.

---

## BLAST RADIUS — recompiler-artifact audit (this CORRECTS the board)

Rendering ~10 tests is a weak audit for a recompiler change, so I ran a stronger
one: for **every one of the 411 corpus tests that carries `[image_comparisons]`**
(i.e. the entire pixel grading axis), run the recompiler binary on `test.swf` in a
private temp dir and md5 the generated `RecompiledTags/draws.c` + `draws.h`. A
static-gradient / static-stroke change can only reach the pixels through that
file, so an identical digest is a *proof* of no-op, not a sample.

410 / 411 recompiled in both legs (`visual/simple_shapes/heavy_tesselation` times
out in both — excluded, unchanged).

**Base patch (P1 + P4): 38 tests changed.** 29 of them are copies of the same two
dev-harness SWFs under `_swfbridge/livetest/{dj_loader,dj_probe,n_loader}` (the DJ
game and N — **not graded**, but worth knowing that the DJ game contains affected
gradients). The **9 graded tests** that changed:

| test | baseline image status | in my A/B? |
|---|---|---|
| `visual/gradient_nonsequential_ratios` | fail | yes → **flip** |
| `visual/gradient_same_ratios` | fail | yes → **flip** |
| `visual/gradient_radial_same_ratios` | fail | yes → **flip** |
| `visual/gradient_issue_9892` | fail | yes → **flip** (with the leg) |
| `from_shumway/acid/acid-gradient-2` | fail | yes → improved |
| `avm2/away3d_advanced_shallow_water_demo` | **fail** (1 331 681 outliers / 400) | no |
| `from_shumway/3_joystick` | **fail** (7 482 / 0) | no |
| `from_shumway/acid/acid-color-0` | **fail** (34 323 / 3) | no |
| `from_shumway/bitmapbuttons` | **fail** (618 042 / 0) | no |
| `from_shumway/gradientTransform` | **fail, known_failure** (1 441 / 0) | no |

**The board's audit said "exactly 4 tests hit".** The true recompiler blast radius
is **9 graded tests** — the board's `gradcorpus.py` scanned only for duplicate /
non-monotonic *DefineShape gradient ratios* and could not see (a) the LINESTYLE2
gradient-stroke path (P4) or (b) whatever `3_joystick` / `acid-color-0` /
`bitmapbuttons` / `away3d` / `gradientTransform` actually carry.

**The board's conclusion nevertheless holds, and holds more strongly than it
claimed: every one of the 9 is already failing at baseline** (5 of them by
5–6 orders of magnitude), so **no currently-passing test's recompiler output
changes at all**. The 4 unrendered ones can only add flips, never subtract; I did
not render them (each is a large multi-frame SWF and the machine was saturated),
so their upside is unmeasured. **Recommended: read them off the merged CI run
rather than spending a slot on them.**

### LinearRGB leg — its own audit (this one DID find passing tests)

Same method, third binary. `before -> base+linearRGB` changes **43** tests
(15 graded). The leg's *own* delta (base -> base+linearRGB) is **13** tests,
**12 graded** — and unlike the base patch, **five of them are currently
PASSING**:

| test | baseline | base -> +linearRGB A/B |
|---|---|---|
| `visual/simple_shapes/gradients/focal_radial` | **pass** (0 / max 0, tol 13) | **pass**, md5 MOVED, and *closer* to the golden: `diff_channels` **70 753 -> 24 356**, `max_diff` 1 -> 1 |
| `visual/simple_shapes/gradients/gradients` | **pass** (0, tol 1) | **pass**, md5 **identical** |
| `visual/simple_shapes/gradients/radial` | **pass** (0, tol 1) | **pass**, md5 **identical** |
| `visual/simple_shapes/gradients/reflect` | **pass** (0, tol 1) | **pass**, md5 **identical** |
| `visual/simple_shapes/gradients/repeat` | **pass** (0, tol 1) | **pass**, md5 **identical** |
| `avm2/away3d_advanced_shallow_water_demo` | fail | not rendered |
| `from_shumway/3_joystick` | fail | not rendered |
| `from_shumway/bitmapbuttons` | fail | not rendered |
| the 4 `visual/gradient_*` tests | fail | the four flips above |

So the leg **does** reach passing tests — the base patch does not — and all five
were explicitly A/B-rendered (`.render_canary/lin_base` vs `lin_after`) rather
than argued about. Four are byte-identical (the linear-store / shader-convert
round-trip lands on the same u8), and `focal_radial` moves but strictly toward
Ruffle. That is the audit that justifies shipping the leg; it is also why it is
delivered as a separate patch file, so the coordinator can drop it if the merged
CI run disagrees.

---

## REFUTATIONS / CORRECTIONS TO THE BOARD

1. **P3 and P4 are not flips.** Both mechanisms were exactly as diagnosed and both
   are now fixed, but both comparisons carry `max_outliers = 0` and both retain a
   small residual (600 and 79 channels). Priced +2 by the board, delivered +0.
   Completion mechanisms are named in each section above.
2. **The blast radius is 9 graded tests, not 4** — see above. The safety
   conclusion is unchanged (all 9 already fail).
3. **P1's magnitude was right to the outlier.** The board's Python model predicted
   1 280 and 5 120; the real renders produced **exactly 1 280 and 5 120**. Its
   radial estimate ("~430, plateau-ambiguous") was pessimistic — the real number
   is 3 761 against a 3 860 budget, which still passes but with only 2.6 % of
   headroom rather than the ~89 % the board's figure implied.
4. **`gradient_issue_9892` is a rider only if the linearRGB leg ships.** With the
   base patch alone it lands 2 outliers over budget. The board explicitly told the
   wave-2 agent not to bundle that leg; that instruction is correct as a *scoping*
   call and wrong as a *pricing* call — the +4 the board hoped for needs it.

---

## RESIDUALS / FOLLOW-UPS

* `acid-gradient-2` — 79 channels of stroke-outline edge. Regrade after
  `w2-gfx-flatten-legC`.
* `graphics_gradients_nulls` — 600 channels of band-boundary against an
  FP-generated golden. Disposition question first.
* `away3d_advanced_shallow_water_demo`, `3_joystick`, `bitmapbuttons`,
  `acid-color-0`, `gradientTransform` — recompiler output changes, all already
  failing, none rendered here (large multi-frame SWFs, machine was saturated).
  Read their movement off the merged CI run.
* **Runtime per-channel arithmetic still diverges from Ruffle** by ≤1 channel:
  the two VM builders round (`+0.5`) where Ruffle truncates, and they quantise
  linearRGB endpoints to u8 before lerping where Ruffle keeps floats. Both are
  now single-constant changes at the two call sites
  (`GRADIENT_RAMP_ROUND → GRADIENT_RAMP_TRUNC`, `GRADIENT_RAMP_LINEAR_U8 →
  GRADIENT_RAMP_LINEAR`). I did **not** make them: they would move every dynamic
  gradient in the corpus by ±1 channel, which is a full-corpus A/B, and nothing
  on this board needed it. Named here so the next agent does not re-derive it.
* `parseMorphFillStyles` (`swf.cpp` ~7460) still has the fourth copy of the old
  segment walk. Left alone deliberately: morph gradients are `w2-gfx-shapes-morph`
  territory, my blast-radius audit does not distinguish morph gradients, and no
  board lead depends on it. Converting it is a 10-line change once someone owns
  the morph A/B.

---

## HOW TO REPRODUCE

```bash
# in the worktree
git apply w2-gfx-gradient.patch          # or -base-only
cd SWFRecomp/build && cmake .. && make -j2      # RECOMPILER CHANGE: mandatory
export SWFRECOMP_COMPILE_TIMEOUT=2400           # the machine is shared
python3 ruffle-tests/render_canary.py capture --label after \
    --tests <list> --jobs 2 --recompile
```

Scratch artifacts (models, audits, binaries, per-leg captures):
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/b9a79013-.../scratchpad/w2gfxgrad/`
and `.render_canary/{before,after,after2}/` inside the worktree.

---

## INCIDENT OF RECORD (please relay)

Mid-session I ran `pkill -f "render_canary.py capture"` to restart my own capture
after the default 300 s per-file gcc cap turned every compile into a false
`compile_fail` at load ~40. That pattern is **not worktree-scoped**, and at that
moment at least two sibling agents (`agent-a6837b92f5e172108`,
`agent-ace18009389126e2d`) had `render_canary.py capture` runs in flight; their
parent processes were killed too (their orphaned `verify_output.py` children kept
running, so the damage is "capture aborted mid-run", not corrupted output).
Those agents should re-run their captures. This is the standing
`pkill-f-self-match` memory note extended: **scope every `pkill -f` with the
worktree id**, e.g. `pkill -f "a8203094041d8f7c8.*render_canary"`.

Second, smaller hazard found: the session scratchpad
(`/tmp/claude-1000/.../scratchpad/`) is **shared across all agents in the
session** — a sibling overwrote a script of mine at the same basename. I moved
everything into a private `w2gfxgrad/` subdirectory. Worth a line in
`BRIEFS_COMMON.md`.

Third, for the next graphics fan-out: **`export SWFRECOMP_COMPILE_TIMEOUT=2400`
belongs in the wave-2 brief.** At the session's peak load the default 300 s cap
made `visual/gradient_nonsequential_ratios` report `compile_fail` after a 300 s
`compile` phase — indistinguishable from a real build break in the JSON.
