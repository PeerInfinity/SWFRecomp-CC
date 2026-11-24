# N: browser particle self-removal, browser RNG, level 1 route (2026-11-23)

One-task session after `n-gold-streaks` (`n-gold-streaks-report.md` §4), launched by the s26 fan-out coordinator.
Baseline: master `285e09fd7` + coordinator `7e14f54dd`/`dc205324e`. Landed: `005bea42a` (runtime + probe + n_drive
knobs) and the docs/route commit that carries this report.

**Summary**
- **Goal 1, browser `pfx` clips removed 2 ticks late: FIXED (§1).** The brief's suspect, a missing root-last /
  promote ordering in `swf.c`, was wrong: the browser loop already has both. The cause was a NAME-gated browser-only
  hack. Clips attached as `pfx*` were flagged `natural_oneshot` and counted down outside the shared attached-clip pump,
  so they never ran their frame scripts. They advanced a tick late and were removed on wrap.
- **A second browser-only bug turned up while proving it (§2):** the AVM1/AVM2 `Math.random` hasher relied on
  signed-overflow UB. emcc folded it differently from gcc, so from the same seed the browser drew a different sequence
  (from draw 4 on). Fixed in both VMs. Native/CI output is provably unchanged.
- **N level 3 route, browser (seeded) vs Ruffle exporter: 0 diffs** on every NF field over all 946 common ticks,
  including `h=`/`o=`. Before: 155 `h=` ticks.
- **Goal 2, level 1 "cloud city" route: DONE (§3).** Key t=492, switch t=857, exit t=1255. Exporter = native graphics
  byte-identical (1322 NF/ND lines incl. `h=`/`o=`); browser in §3.2.
- Goal 3 (trap-switch colour): §4.

## 1. `pfx` particles: the browser counted them down instead of playing them

**Measurement.** n_drive `OBJHASH`+`CLIPDIFF` on the level 3 route:

| | first seen | last seen | removed |
|---|---|---|---|
| Ruffle exporter / native | t=5, `cf=2/33` | `30/31` | t=34 |
| browser (before) | t=5, `cf=1/33` | `31/31` | t=36 |

So the browser was one tick behind from the start, and it also showed the last frame, which Ruffle never does
(the clip's last-frame `this.removeMovieClip()` runs before anything samples it).

**Probe first, then the cause.** `wasm_probes/attach_from_stopped_root_enterframe` is the browser twin of
`regression/avm1_attach_from_stopped_root_enterframe`: a stopped root's onEnterFrame attaches a 4-frame
self-removing clip. Built as-is, it **passed** in the browser, and so did a no-`stop()` 1-frame root variant. So the
root-last / promote ordering was already right in `swf.c`. The difference was the NAME:
- `tag_stubs.c` `ng_attachMovie` (browser arm only, e387df685) flagged any multi-frame clip named `pfx*`
  `natural_oneshot` (N's ParticleManager).
- `ng_advance_attached_clip_playheads` skipped those clips.
- `advance_attached_clip_natural` (called from tagShowFrame's browser arm) counted them down instead:
  - placement-free and script-free;
  - skipped the tick after attach (`placed_at_tick`, +1 tick late);
  - removed the clip only when the playhead wrapped (+1 more).
- Why it existed: "attached morphs draw ratio-0 geometry under ratio-N matrices". c948d0e61 (n-gold-streaks) fixed
  exactly that renderer limit (`render_webgpu_draw_morph`, per-instance morph lerp), so the hack had no reason left.

With the probe's clip renamed to `pfx0` it went red (`root ef c=3 … cf=1`, no `pfx0 f2`).

**Fix (`005bea42a`).**
- Deleted the flag block, the pump skip, `advance_attached_clip_natural` and its call, the dead
  `natural_oneshot` test in `hasPlayingSprites`, and the `DisplayObject.natural_oneshot` field.
- `pfx*` clips now play their real timeline through the shared pump, like every other attached clip and like native.
- Probe green (twice; `settle_seconds` raised to 5 s because one SwiftShader run hadn't reached the last line in
  2 s).
- Native/CI are unaffected by construction: the flag was only ever set in the browser arm.
- Regression fixtures still pass in both modes: `avm1_attach_from_stopped_root_enterframe`,
  `avm1_exec_order_attached_selfremove`, `avm1_morph_instances_ratio`.

**N proof.** Level 3 browser rebuild: every `ND clip+`/`clip-` line now matches the exporter (171/171, cf
included). `h=` diffs dropped from 155 ticks to one window, t=205–278, which was §2.

## 2. Browser `Math.random` drew a different sequence

**Finding the remaining window.** New knob `CLIPPOS=205:216` named the clip: `spritebuffer1600.pfx8`.
- `_y` is 467.6 in Ruffle and 480.25 in the browser.
- N's `ParticleManager.SpawnWallDust` sets `_y = pos.y - norm.y*rad - (Math.random()*2*rad - rad)` (read off the
  recompiled C, `func_anonymous_511`).

**Ruling out the seed.**
- The browser build has no `MOCK_DATE_TIME` (only verify_output / run_native.py define it), so it seeds from
  `time()`.
- Rebuilt with `EMCC_CFLAGS=-DMOCK_DATE_TIME=981152406000`: t=205 now matched, but t=214 did not.
- New knob `RANDCOUNT` (wraps `Math.random`, appends `rc=`) showed identical call counts on every tick. N has no
  AS1 `random()` (`actionRandomNumber` is never emitted). So the values themselves differed.

**Cause.**
- `math.c` `RandomPureHasher` / `GenerateRandomNumber`: `iSeed * iSeed * c3`, `iSeed << 13` on negatives, and
  `aNum * 71L` are int32 signed-overflow UB. (`long` is 32-bit on wasm32, so `71L` doesn't widen there.)
- gcc wraps; emcc -O2 folds it differently.
- A standalone copy from the mock seed: gcc -O2 and emcc -O2 diverge from **draw 4**.
- `avm2/avm2_number.c` `avm2_random_pure_hasher` / `avm2_random_next` are the same code.

**Fix (`005bea42a`).** Both are now uint32 wrapping arithmetic, with `>> 21` kept as an arithmetic shift of the signed
value (avmplus; Ruffle uses wrapping ops).

**Proof native/CI is unchanged.**
- The old hasher+`*71L` (verbatim) and the new one, compiled in separate TUs with gcc -O2 (no cross-inlining), agree
  on **all 2^32 inputs** (0 mismatches, 34 s).
- The full sequence from the mock seed is identical under gcc -O0, gcc -O2, gcc -O2 `-fsanitize=undefined` (now
  clean) and emcc -O2.
- avm1 `array_sort_random` passes.

**N proof (level 3, seeded browser build).** 0 diffs vs exporter on every NF field (player, `time=`, `h=`, `o=`)
over all 946 common ticks. Clip and event lines are identical (switch t=762, exit t=966).

**Consequence for real play.** The deployed browser build still seeds from wall time. That is intended (real Flash is
random too). Only with the mock seed can a browser trace be compared to the exporter on RNG-fed values. Before this
fix even the seeded browser couldn't match.

## 3. Level 1 "cloud city" route: complete

### 3.1 The route

The route is in `routes_ep0.txt`, authored with `search.py` one landing at a time on the exporter. Events: key t=492,
switch t=857, exit t=1255. The (60,60) trap switch is never touched.

1. **Onto spring block (180,492).** Run R and jump into its left face, then wall-jump off it (`8:R|20:RJ|5:R|10:RJ`)
   to land on top. The block sinks under you; it is a spring.
2. **Onto the left cloud.** Wait 20 ticks on the block (its rebound phase matters), then jump left onto the left
   cloud's right face (154,~405). Wall-jump off that face at 33 ticks to land on its top at (58,350), next to the
   locked door.
3. **Onto the upper cloud.** Hop onto the wall bump (34,303). Then jump straight up against the stage wall
   (`40:LJ|1:L`) and wall-jump right (`25:RJ`) over the upper cloud's left lobe onto its top (115,198).
4. **Through the slot into the hollow.** Climb right along the top to (261,99). Step off the right side onto the
   lower-right arm (307,158), then run left through the ~22-px slot into the hollow. **Key t=492.** The new
   `OBJDUMP` door tracer prints `ND door 20 … isOpen=true`.
5. **Back out over the middle cloud.** Leave the hollow back to the right (`10:R|45:RJ|40:R`) and drop off the arm's
   right end. Run left over the middle cloud's bump and jump left onto the wall bump (34,303).
6. **Through the door to the switch.** Step right off the bump, then left through the open door into the pocket:
   **switch t=857.**
7. **Out of the pocket and down to the floor.** `40:LJ|1:L|20:RJ` exits the pocket; brake to rest on the left cloud
   (110,374). Step off with only 16 ticks of R: a bigger fall is a **fall death** (type 4, the same signature as
   autokill; check for `ND autokill`).
8. **To the exit.** Run right through the 24-px tunnel under the bottom-right cloud. Do not jump in it: the jump just
   bumps the ceiling. Reach the chimney wall (x=758), then `35:RJ|10:LJ|40:L` into the cave: **exit t=1255.**
   Level 2 loads.

### 3.2 Replay

`START_LEVEL=1 AUTOKILL=true OBJHASH=true OBJDUMP=true FREEZE=""`, exporter `-f 1800`.

| leg | lines | diff |
|---|---|---|
| exporter vs native graphics (`build/test_run` direct; run_native.py's 30 s cap kills it) | 1322 NF/ND | **0** (incl. `h=`/`o=`, door line) |
| exporter vs browser WASM (`EMCC_CFLAGS=-DMOCK_DATE_TIME=981152406000`, SwiftShader) | 1322 NF/ND | **0** |

## 4. Goal 3: the level-1 trap switch is a stroke-coverage diff, not a colour transform

n-gold-streaks §3 guessed "a colour transform or alpha on a nested part is not applied". **It isn't.**

**What the switch is.** It draws `debugDoorTriggerMC` (char 525):
- Frame 1 `exit_closed` places DefineShape2 188 at ×8.33.
- Shape 188 is a 12-px square: fill `acacb5`, a 1-twip `5f5f6b` outline, and an inner half-rect (fill `666666`,
  1-twip black outline).
- On screen it is 6 px (net scale ≈0.5).

**Pixel comparison, native F450 vs exporter frame 449** (stable over 3 exporter frames; scratch dumps):
- **Ours:** the 6×6 inner area is exactly the outline colours, opaque: `5f5f6b` rows, and black `000000` /
  `1a1a1a` at the glyph.
- **Ruffle:** about 50% blends: `878792` = midway between `5f5f6b` and `acacb5`; glyph `4c4c4c`.
- Every surrounding pixel of the switch frame is identical.

**Where this points.** Both players floor the stroke to one device pixel: ours via `hairline_restage`, which every
transform write feeds through `xform_slot_write → hairline_note_xform`, attached clips included; Ruffle via
`tessellator.rs:178`. So the residual is how that 1-px stroke covers pixels:
- Ruffle's is centred on a pixel boundary, giving two half-covered pixels.
- Ours fully covers one pixel.
- The likely cause is vertex/centre quantisation at ×8.33 inside a ×0.06 parent. See memories `vertex-quant` and
  `integer-twips`.

**Cost.** 27 px on level-1 shots. Not fixed.

**Next step if picked up:** splice chars 188/524/525 into a minimal SWF (attach 525 at N's scale) and compare native
vs exporter at tolerance 0, as with n-gold-streaks' coin splice. Then dump the restaged stroke vertices for that draw.

## 5. Next blocker / next slice

0. **CI grading of `005bea42a`** (the coordinator runs graphics/full + no-graphics/full, then the Pages deploy).
   - `math.c` and `avm2_number.c` are shared CI code, and `tag_stubs.c` is on the no-graphics list.
   - All three are byte-identical by construction (§1, §2).
1. **Level 1 trap-switch stroke coverage (§4).** Then the exit-door panel offset (`n-gold-streaks-report.md` §3).
2. **N routes now exist for levels 0–4.** The browser is tick-exact on levels 1 and 3 with a seeded build. Levels 2/4
   in the browser have not been re-replayed since n-levels.

## 6. Tooling / traps

- **n_drive knobs** (README §"s26 n-browser-pfx additions"):
  - `CLIPPOS=lo:hi`: per-clip `x/y/cf` over a tick window.
  - `RANDCOUNT`: counts `Math.random` calls.
  - `OBJDUMP` now also prints `ND door <i> t= …` whenever a door object's fields change (key pickup / open).
- **`author.py` needs `START_LEVEL` in its env** (`search.py` sets it). Without it you author on level 0. This cost a
  confusing round here.
- **A browser trace compares with the exporter on RNG-fed values only when the build is seeded**
  (`EMCC_CFLAGS=-DMOCK_DATE_TIME=981152406000`). With the §2 fix it then matches exactly.
- **Name-gated special cases age badly.** `natural_oneshot` keyed on `"pfx"` outlived its reason, the morph-ratio
  renderer limit fixed one slice earlier.
  - When a browser probe of a mechanism passes but the game still diverges, grep for name or char-id gates on the
    game's own clip names.
