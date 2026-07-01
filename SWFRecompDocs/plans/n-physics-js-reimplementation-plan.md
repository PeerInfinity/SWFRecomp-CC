# N physics — faithful JS reimplementation (plan)

Date: 2026-06-30. Goal (user): a JavaScript implementation of N's physics that
matches the original as closely as possible, so we can run cheap approximations in
JS and confirm in real Flash physics. This UPGRADES the current motion model (a
coarse measured envelope table, `nMotion.js`) to a true per-tick simulator — the
same architecture Archipelago-CC's Bounce Demo uses for Doodle Jump.

## The Doodle Jump precedent (Archipelago-CC — study this)

`~/CC/Archipelago-CC/frontend/modules/bounceDemo/`:
- **`physics.js`** — the model. `DEFAULTS` + `PROFILES` where the **`dj` profile's
  constants are MEASURED from real DJ** (tick-native: TICK_HZ 20, GRAVITY px/tick²,
  impulses, CATCH_BAND, POSITION_QUANTUM = Flash twip 0.05, etc.). A **pure
  `step(state, input, level, abilities, C)`** — one call = one tick, returns new
  state, branches on structural DATA fields (LANDING/AIR_CONTROL/WRAP), never on a
  profile name. Plus `simulate(level, …, policy, opts)` (run N ticks, collect
  trajectory + events) and `launchRise` (measures discrete rise by running `step`
  itself, not closed-form — discrete effects are large). Constants are embedded in
  the world payload stamp so already-generated worlds never shift.
- **`gameCore.js`** — a session state machine over `step`: items→abilities,
  landings→events (`pickup`/`exit`/`fell`/`lockedPortal`…); portals carry a
  `direction`. Same modules the solver and renderer share, so derived rules can't
  drift from runtime.
- **`physics.test.js`** — verifies `step` against the measured DJ ground truth.
- **`djReal/`** — the real-DJ-SWF renderer/loader (Doodle_Jump.swf + dj_loader.swf +
  swf_inject.mjs) — the analog of our `n_loader`, used to measure/confirm.
- Measurement harness (ours): `ruffle-tests/.../dj_probe/Measure.as` +
  `parse_measure.py` → `dj_probe/measurements/` (per-mode: bounce/spring/jetpack/
  blue/brown/catch/keys). N's analog already exists: `n_loader/gen/nProbe.js` +
  `calibrate.mjs` + `nTelemetry.js` (per-frame `NF` traces).

Related: `SWFRecompDocs/status/2026-06-30-n-substrate-investigation.md`,
`SWFRecompDocs/reference/n-level-and-demo-format.md`,
`SWFRecompDocs/plans/n-level-generator-plan.md` (§2 "N has a dual oracle").

## Why N is a good fit — and where it's harder than DJ

Advantages we already have:
- **Rich per-frame ground truth**: the recorder emits `NF t gt x y vx vy st air wall
  jt face L R J JT …` every tick, and the demo system replays exact input. So
  frame-exact verification (JS `step` vs recorded real-N trajectory under the same
  demo) is straightforward — better telemetry than the DJ effort started with.
- **Many constants already known**: from the decompile + calibration — `GRAV=0.15`,
  ground clamp `vx[n+1]=min(5, vx*0.99+0.15)`, air accel ~0.1, variable jump
  (`jumpGrav≈0.025`, `max_jump_time=30`, launch impulse vy≈−3), terminal `r*0.9`,
  tile size 24, player r 10, switch/door radii 6/12.

Harder than DJ (DJ is 1-D bounce + one-way platforms, no tile collision):
- **Real 2-D swept-circle tile collision** against the 31×23 grid — walls, floors,
  and eventually the slope/half-tile family (states 2–33). This is the bulk of the
  work; N resolves a circle vs tile edges/corners per tick.
- **Wall-slide / wall-jump** and **skid/turn-around** (leftward + reversal) — needed
  for vertical/serpentine courses; currently unmeasured.

## Approach (dual-oracle, measure-then-verify)

1. **`nPhysics.js`** — `CONSTANTS` (measured/decoded) + a pure
   `step(state, input, grid, C)` returning the next state (`{x,y,vx,vy,onGround,
   againstWall,jumpTimer,face,…}`), mirroring N's per-tick update order (input →
   horizontal accel/clamp → jump impulse/variable-hold → gravity/terminal →
   integrate → **collide vs tiles** → state). Plus `simulate(grid, demo|policy)` →
   trajectory + events, like Bounce's `simulate`.
2. **Frame-exact verification** against recorded real-N traces: run `nPhysics` with
   a demo, diff x/y/vx/vy per tick vs the `NF` capture. A `physics.test`-style gate;
   the recorder is the ground truth (no new Flash tooling needed).
3. **Scope by what the generator needs first**: axis-aligned FULL tiles only (floors,
   walls, gaps, steps) — enough to replace `nMotion` envelopes for
   flat/gap/step/course generation. Defer slopes, wall-jump, enemies.
4. **Keep the real-N gate**: `nVerify` (Ruffle) stays the final judge. `nPhysics` is
   the cheap pre-filter/solver (reachability, demo synthesis, tighter margins); real
   N confirms. Where `nPhysics` and real N disagree, the trace diff localizes the
   collision/constant to fix — the calibration loop.
5. **Later**: fold `nMotion`'s envelope queries to derive from `nPhysics` (single
   source of truth), and share it with an Archipelago-CC N substrate (Bounce's
   split: solver + renderer import the same `step`).

## Sequencing note

This is a substantial module (2-D collision is the hard part) and pairs naturally
with the vertical/serpentine course work (both need wall/turn dynamics). Recommend
its own focused session, measure-then-implement, verified frame-exact against the
recorder we already have.
