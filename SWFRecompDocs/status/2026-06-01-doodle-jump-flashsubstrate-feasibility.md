# Doodle Jump — flashSubstrate feasibility probe: capability report

**Date:** 2026-06-01. **Probe brief:**
`SWFRecompDocs/plans/archipelago-doodle-jump-feasibility.md`. **Harness (kept
for reuse):** `ruffle-tests/tests/swfs/_swfbridge/livetest/dj_probe/`.

This is the capability report for the read/write + control feasibility probe of
Doodle Jump (DJ) as a `flashSubstrate` driver. Each of the 5 questions is rated
**possible / partial / not-possible** with the specific AS hooks or obstacle, and
the tiny-proof result where requested. No SWFRecomp runtime/recompiler source was
modified — the probe is pure injected AS plus harness scaffolding.

## Method

DJ's own ActionScript is **non-cooperative** (it never calls `ExternalInterface`).
So rather than rely on cooperative AS, the probe **injects** an AS class into DJ's
SWF *before recompiling*, via the divergence-tracer pipeline: `Probe.as`
(MTASC) → extract DoAction bytecode → `inject_tracer.py` splices it before the
first ShowFrame → recompile. The injected probe has full access to DJ's live
object graph and reports via `trace()`.

Every experiment was run on **three tiers**, Ruffle first then recompiled (per the
brief): **(1) Ruffle web** = ground truth (real Flash); **(2) SWFRecomp
graphics-native**, headless = the fast recompiled tier; **(3) SWFRecomp
graphics-WASM** in headed Chrome = the production browser runtime. Output is
`trace()` (stdout natively, console in both browsers), so the same probe runs
unchanged on all three.

### Headline cross-runtime result

For read/write/placement the recompiled runtime is **byte-identical to Ruffle**.
Example — the Q2 write experiment produced the *exact same* per-frame state on
Ruffle and native (deterministic `MOCK_DATE_TIME` seeding): `score` 20 → 36 → 75
→ 118 → … → 5602, same physics, same write/readback. This is a strong validation
that injected-AS read/write against a real game behaves the same on SWFRecomp as
on Flash.

### DJ object graph (what injected AS sees in gameplay)

Gameplay is reached by `_root.gotoAndPlay(2)` (the PLAY button's Release handler,
`clip_actions_148`; **frame 6 is the INFO screen**, `clip_actions_147` — a trap
that cost an iteration). The **hero clip is DJ's game engine**:

- `_root.hero.{score, gravity, vy, jumpspeed, maxjump, jump, hitBlock, jetpack,
  jetcount, move_inversed, lastblockhit, lastDeletedBlock, xradius, yradius}` —
  all the physics/score/powerup state, declared `var` in the hero LOAD handler
  (`clip_action_28`); the physics loop is `_root.hero.onEnterFrame`
  (`clip_action_29`).
- `_root.gameOver` (boolean), `_root.score_txt` (the score TextField).
- `_root.container.{block_0 … block_N}` — the platforms, each a MovieClip with
  `_x/_y`; `_root.container.attribute[]` — the per-block type array (1=spring,
  2=magicball, 3=nail, 6=inverse, 8=coin); `_root.container.{maxblocks, minblocks,
  distance, lastblock_y, onEnterFrame, attachBlocks}` — the spawn loop + state.

---

## Q1 — Locations (read game state for objectives): **POSSIBLE** (poll, not events)

Injected AS reads every candidate objective each frame from the hero clip / root:

- **Score / height milestones:** `_root.hero.score` is a live number that climbs
  as the hero ascends (observed 0 → 5600+ in a single run). DJ tracks height via
  `lastblockhit` / `lastDeletedBlock` / `lastblock_y` — all readable.
- **Powerup pickups:** observable as state transitions — `jetpack` (bool),
  `move_inversed` (bool), `jumpspeed_factor`/`maxjump` changes, plus the
  per-block `container.attribute[i]` type and the presence of powerup child
  clips (e.g. `container.inverse_9`).
- **Goal/death:** `_root.gameOver` (see Q3).

**Mechanism: polling.** DJ does *not* dispatch AS-level events for these — there
is no observable `onScore`/`onPickup`. A substrate observer reads them each frame
in the probe's `onEnterFrame` (next-frame latency, which is fine for the
frame-based model). Maps to `locations: memory_poke`/cooperative-by-polling.
Ruffle == native byte-identical.

**Caveat (awkwardness, as predicted):** score/height is *continuous*, so "AP
locations" must be arbitrary thresholds (reach 5000, 10000, …) rather than
discrete in-game events. Powerup pickups and gameOver are the only genuinely
discrete signals.

---

## Q2 — Items (write state to grant items): **POSSIBLE** (push), with a nuance

Injected AS writes hero/root state and it takes effect. Proven (Ruffle == native):

- `hero.jetpack = true`, `hero.maxjump = 60`, `hero.gravity = 1` → **persist**
  (readback confirms; values stick across subsequent frames and change physics).
- `hero.score = 4242` → took; the game continued from it (next frame 4297).
- `_root.gameOver = true` → took (see Q3).

**Nuance — derived vars get recomputed:** `hero.jumpspeed = 40` was written and
read back as 40 immediately, but the hero's `onEnterFrame` **recomputes
`jumpspeed` every frame** (back to ~10). So a durable item effect must target the
right *source* variable (e.g. `maxjump`, `jetpack`) or be **re-asserted each
frame** by the injected observer. This is the realistic item-application shape:
the substrate's per-frame hook applies the granted item, rather than a one-shot
write. Maps to `items: push`.

---

## Q3 — Goal / completion: **POSSIBLE**

`_root.gameOver` is a readable **and** writable boolean. A substrate can treat
`gameOver == true` as region completion (death = run over), and/or a score
threshold (`hero.score >= N`) as milestone-completion. The probe both observed it
flip to `false` at gameplay start and force-set it `true`. Clean.

---

## Q4 — Platform & item PLACEMENT control: **POSSIBLE** (+ tiny proof, both ways)

Two levels, both proven (Ruffle == native):

1. **Reposition / retype a placed platform.** Forced `container.block_0` from its
   spawned position to a known `(120, 300)`, and changed `container.attribute[1]`
   from `0` → `1` (normal → spring). Readback confirmed and the override **stuck**
   across subsequent frames against the running game.
2. **Intercept the placement *code*.** Wrapped `container.onEnterFrame` (the
   block-spawn driver) and `container.attachBlocks` with injected functions that
   call through to the originals — the hook **fired every frame**
   (`HOOK container.onEnterFrame fired …`). So injected AS can replace the
   placement loop wholesale and author the platform stream itself.

**Implication (Mode 2 — procgen-rendered content):** because the spawn loop is
interceptable and block position+type are writable, a DJ "zone" can be an
**authored stretch of platforms** rather than a teleport target. Mode-2 content
authoring is feasible on this real game.

**Determinism caveat:** the *initial* block RNG diverges between runtimes — at
gameplay start native `block_0` was `(172, 345)` type-2 while Ruffle was
`(68, 328)` type-1. DJ's `Math.random`-driven block placement is not perfectly
cross-runtime reproducible even under `MOCK_DATE_TIME` (the score *progression*
matched, but block layout did not). An authored substrate would override
placement anyway, so this is a note, not a blocker.

---

## Q5 — Playback bot (simulated-keypress steering)

Split into the three sub-parts the brief asks for:

### Input path — **POSSIBLE** (proven on all three tiers)

DJ polls `Key.isDown(39)` / `Key.isDown(37)` (Right/Left) every frame in
`clip_action_29` and moves `hero._x += 10` / `-= 10`. Simulated keypresses reach
this on every runtime:

- **Native:** file-driven `KEY_DOWN 39` (input.json) → `keys.down[39]=1` →
  `Key.isDown(39)=true` → hero._x climbed 168 → 238 (+10/tick); `KEY_DOWN 37` →
  hero._x dropped 228 → 158.
- **Browser-WASM:** a real DOM `ArrowRight` keydown on `#canvas`
  (`render_webgpu.c::on_key_down` maps `evt.keyCode` → `keys.down[]`) → `k39=true`
  → hero._x 168 → 258 with screen-wrap; `ArrowLeft` → `k37=true` → hero._x 90 →
  20.

The injected probe **also reads `Key.isDown` itself**, so an injected-AS observer
can read input state directly too.

### Perception — **POSSIBLE**

`hero._x/_y/vy` plus every `container.block_N._x/_y` are readable each frame —
enough to choose a target platform and a steering direction.

### Steering proof — **PARTIAL**

- **AS-direct steer** (set `hero._x` toward a target): proven — the hero tracks an
  alternating left/right target precisely (converges to 60, climbs to 180, back),
  Ruffle == native. This is the substrate-relevant "drive the player" capability
  and it works cleanly.
- **Closed-loop keypress steering** (host reads state → injects keys → physics
  moves the player): the *mechanics* are proven (keys move the hero on all tiers,
  positions are readable), but a **robust bot that survives** (lands on platforms
  reliably, reacts to physics, doesn't fall) is the genuinely hard part and was
  not demonstrated. It needs a per-frame feedback controller plus coordinate
  alignment (hero screen-`_x` vs block container-local `_x`) and real-time physics
  timing. **This is the piece flagged for human-in-the-loop / iteration:** a crude
  steer is viable; production-quality automated playback of this real-time action
  game needs dedicated controller work.

Maps to the deferred `getPlaybackController`: feasible in principle, non-trivial
in practice for DJ specifically.

---

## Summary table

| # | Capability | Verdict | Key hook / obstacle | Tiers |
|---|---|---|---|---|
| 1 | Locations (read) | **Possible** (poll) | `hero.score`, `gameOver`, `jetpack`/`move_inversed`, `container.attribute[]`; no AS events → poll per frame | R/N/W |
| 2 | Items (write) | **Possible** (push) | write `hero.{jetpack,maxjump,gravity,score}`; derived vars (`jumpspeed`) need per-frame re-assert | R/N |
| 3 | Goal / completion | **Possible** | `_root.gameOver` read+write; or `hero.score` threshold | R/N |
| 4 | Placement control | **Possible** | reposition `block_N` + set `attribute[]`; wrap `container.onEnterFrame`/`attachBlocks` → Mode 2 authoring | R/N |
| 5 | Input path | **Possible** | sim keys → `keys.down[]` → `Key.isDown` → hero moves (file + DOM) | R/N/W |
| 5 | Perception | **Possible** | `hero._x/_y/vy` + `block_N._x/_y` per frame | R/N |
| 5 | Steering | **Partial** | AS-direct steer works; reliable keypress-bot needs a feedback controller (human/iteration) | R/N/W |

(R = Ruffle, N = native, W = WASM-browser. Read/write/placement are R==N byte-identical.)

## Notable cross-runtime divergences (minor)

- **`_root._currentframe` reads `undefined` in browser-WASM** (native/Ruffle
  report the real frame number). Doesn't affect gameplay; the probe just can't use
  `_currentframe` as a state signal under WASM.
- **Initial block-placement RNG differs** Ruffle vs native (Q4 caveat).
- **Native physics is *full* at the correct gameplay frame** — an earlier
  impression that "native can't reach gameplay" was the wrong frame (6=info, not
  2); at frame 2 native runs the same physics + score progression as Ruffle.
- The **menu's button hit-testing is browser-WASM-only**, so native/Ruffle reach
  gameplay via forced `gotoAndPlay(2)` rather than a click. (Injected AS forcing
  the goto is itself a useful substrate capability: the substrate can start the
  game without a click.)

## Recommendation

**Doodle Jump is a good enough driver for `flashSubstrate` steps 4–6, and a
productive (if hard) stress test for step 7 — recommend using it for 4–6 now, and
keeping a purpose-built fixture in reserve for the playback-controller bring-up.**

- **Steps 4–6 (item-push, teleport/zones-as-goal, memory-poke, real-game
  migration): use DJ.** Q1–Q4 are all *possible* with clean Ruffle==recompiled
  parity. DJ exercises exactly the capabilities these steps need: poll-based
  location observation, push item application (with the realistic per-frame
  re-assert pattern), a readable/writable goal, and — valuably — **Mode-2 content
  authoring** via placement interception, which a JS placeholder could never have
  validated. The injection + EI path maps directly onto the proven `__swfBridge`
  contract (the injected probe would report objectives via
  `ExternalInterface.call("__swfSendLocation", …)` and apply items via
  `__swfPoll`, exactly as the toy minigame does).

- **The awkwardness is exactly where the brief predicted, and it's informative:**
  continuous score/height means AP "locations" are arbitrary thresholds, not
  discrete events; there are no AS-level event hooks (everything is polled). That
  productively stresses the `locations` model toward `memory_poke`/poll rather
  than cooperative events — a real finding for the design.

- **Step 7 (playback bot): DJ is a hard case — start the playback-controller on a
  simpler purpose-built AVM1 fixture, then graduate to DJ.** The input path and
  perception are proven, and AS-direct steering works, but reliable
  *keypress-driven* playback of a real-time physics platformer is genuinely
  non-trivial (coordinate alignment, physics timing, survival). A purpose-built
  fixture with discrete, deterministic locations and a trivial "walk to location"
  motion model will bring up `getPlaybackController` far faster; DJ then serves as
  the realistic stress test once the controller exists.

**Net:** don't fall back to a purpose-built fixture for steps 4–6 — DJ validates
them on a real game, including Mode-2 authoring, which is the highest-value result
here. Do keep a fixture for the playback work. The probe harness
(`dj_probe/`) is kept in-repo as the starting point for a production DJ substrate
adapter.
