# w2-gfx-avm2-blend — wave 2: the AVM2 render walk has NO blend arm (+1 pixel flip, `displayobject_blendmode` 62 400 → 0)

Read `BRIEFS_COMMON.md` (incl. wave-2 + graphics canary rules) and `SIBLING_FILE_MAP.md`, then
the diagnosis of record: `w1-gfx-fill-report.md` §1 A1 and §6 slice "avm2-blend-arm". Isolated
worktree; no commits. Local Dawn at `~/CC/dawn-install`; `MSAA_SAMPLES` never literal 4.

## Scope
`DisplayObject.blendMode` in AVM2 only writes a `__blendMode` dynamic property that nothing reads;
`renderer_*_blend` is called from `tag.c` only (AVM1 route). Add the blend arm to the AVM2 render
walk in `avm2_display.c` (~80 LOC): cache the numeric blend mode on the display ext at set time
(and from PlaceObject3's blend byte if the AVM2 timeline placement carries one — check
`abc_timeline.cpp`/the placement op), and wrap the object's render in the same
`renderer_*_blend` push/pop `tag.c` uses (read `tag.c`'s blend usage first; mirror its layer
semantics for `BlendMode.LAYER`, `ERASE`, `ALPHA` where `tag.c` already handles them — do not
implement layer groups, `render_webgpu.c:4394` says they are unimplemented; that is a HOLD).
Target: `avm2/displayobject_blendmode` (200x200, `BlendMode.ADD`) 62 400 → 0. Also grade
`avm2/blend_shader_luma_lighten` before/after (report §4 says its residual is a factor-4 green
scale in the shader, NOT this arm — confirm it does not move or say what moved).

## Verification
`--mode=graphics --images --image-out-dir` on the target and on every `avm2/*blend*` test +
`visual/blend_modes/*` (all — the AVM1 route must be byte-identical; those are the 45° tie rows
w2-gfx-blend-tie owns — report identical md5 for them). Render canary `render_canary.py`
(`--timeout 5400`) md5 identity. Trace canaries: `avm2/displayobject_*` passing tests (sample 10),
`avm2/blendmode*`, `regression` suite render fixtures. `-P 2`, compile timeout 2400,
`--recompile` on first use. Runtime-only → copying `SWFRecomp/build` is valid.

## Deliverables
`SWFRecompDocs/plans/session18-fanout-reports/w2-gfx-avm2-blend.patch` + `w2-gfx-avm2-blend-report.md`
(NEW files first; per-comparison before/after; canary md5 ledger; refutations; unclaimed leads).
Copy to the main tree if allowed.
