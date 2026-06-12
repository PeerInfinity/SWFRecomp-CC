# DJ level loader — first increment (region_4_4) capability report

**Date:** 2026-06-11. **Request:**
`~/CC/Archipelago-CC/NewDocs/plans/procedural-generation/dj-loader-integration-spec.md`.
**Harness (kept, production-track):**
`ruffle-tests/tests/swfs/_swfbridge/livetest/dj_loader/` (see its README for usage).

The first increment of the production DJ level loader: the **real recompiled
Doodle Jump** renders `region_4_4` of the committed
`bounce_dj_worldgen/AP_14089154938208861744` preset via injected ActionScript,
fulfilling the `window.__swfBridge` contract (configure/pollItems in,
sendLocation/sendExit out) with DJ's hero physics untouched. Per the user's
direction, the page works under **both Ruffle and SWFRecomp WASM** — the same
injected SWF and the same page shim (`dj_swf_bridge.js`); only the player
differs.

## Result summary

| Deliverable | Ruffle (ground truth) | graphics-native (headless) | browser-WASM (production) |
|---|---|---|---|
| Native spawner disabled, level authored | PASS | PASS | PASS |
| Zero-input climb up the green column | PASS | PASS | PASS |
| `sendLocation('loc_0')` on landing p4 | PASS (full EI bridge → mock host) | PASS (fixture/trace mode) | PASS (full EI bridge → mock host) |
| "Brown platforms" via pollItems → p9 exists | PASS | PASS (fixture grant @tick 300) | PASS (mock grant @15s) |
| `sendExit('side_exit_W','W')` on landing p9 | PASS | PASS | PASS (full EI round-trip) |
| Sustained zero-input physics soak | PASS (700+ ticks, 35s) | PASS (400 ticks) | **PASS — 952 and 957 ticks, two consecutive runs** (the ledger item; see below) |
| Bottom-fall respawn at entrance | exercised post-portal | implemented; post-portal tail diverges (below) | not triggered (hero never fell) |
| 600-wide stage (option 1, implemented on go-ahead) | PASS (`stage=600x400`, full sequence, stable to tick 713) | PASS (full sequence, hero at world x=300 1:1) | not yet run (240 default) |

Physics are cross-tier identical where compared: the climb's per-tick
`LT<t> hx= hy= vy= cy= lb= sc=` traces match exactly between Ruffle and
graphics-native through the whole climb (same vy lattice
`-28.2999995946884 → ... → -0.299999594688416`, same scroll `cy` values, same
landing ticks), and browser-WASM produces the same lattice modulo the staged
init's 15-tick offset.

## How the loader drives DJ (architecture)

`Loader.as` ("Probe.as grown up", same MTASC → extract_bytecode →
inject_tracer pipeline) runs from a high-depth injected clip's onEnterFrame:

- **Config inward:** `ExternalInterface.call("__swfConfig")` returns a compact
  level string (the page shim `dj_swf_bridge.js` encodes the level JSON;
  coordinates pre-mapped to DJ space). EI unavailable (graphics-native
  headless) → generated `FixtureData.DATA` fixture with `G|tick|items` grant
  schedule — same parse/apply path.
- **Items inward:** `__swfPoll()` per tick returns the FULL current held-item
  set (idempotent; the page shim holds what the host's `pollItems(received)`
  pushed). Item-gated platforms are parked/positioned on change.
- **Events outward:** `__swfSendLocation(id)`, `__swfSendExit("id|side")`
  (single packed arg — the recompiled EI marshaler is 1-string-arg).
- **Placement:** platforms are DJ's own `container.block_<idx>` clips with
  `container.attribute[idx]` (0 plain / 2 breaking). Indices are assigned
  bottom-to-top by the encoder because the hero's catch loop scans
  `block_(lastblockhit-3) .. block_(lastblockhit+9)` — index locality along
  the climb is load-bearing.
- **Landing-triggered goals:** `hero.lastblockhit` transitions give exact
  landing detection (the hero's own catch maintains it); goals fire on their
  host platform per the spec — pickups dedup via the checked set (and
  `config.checkedLocations`), portals once per session.
- **Respawn:** `_root.gameOver` intercepted (cleared before the hero's
  `_root.gotoAndStop(3)` branch can see it — set at the bottom of the hero's
  enterFrame, checked at the top, so any dispatch order wins), hero back to
  spawn, platforms re-asserted, pickups persist, browns restore.
- **Spawner takeover:** STAGED, one op per tick (see browser-WASM findings):
  kill `container.onEnterFrame`, PARK the 15 native blocks + powerups
  offscreen (x = −1000, outside the wrap range), claim + position
  `block_<idx>` per platform, reset hero. The hero's climb-recycle deletion
  is disabled (`lastDeletedBlock = 999999`) — authored levels keep all
  platforms alive (respawn needs them back).

## Browser-WASM runtime findings (this repo's bugs, worked around)

1. **`build_test.sh` does not re-run the recompiler when only `test.swf`
   changes** — two "fix didn't work" iterations were actually stale builds.
   Always `--clean` after swapping the SWF; verify with `strings *.wasm`.
2. **Mass MC operations in one injected-clip tick hang the runtime** (main
   thread busy-loop at end-of-tick; the page's `setTimeout`s never fire).
   A one-shot takeover (kill OEF + park 18 clips + 11 claims + hero reset in
   one tick) completed its own AS — `LT` trace printed — then the next tick
   never arrived. The SAME ops staged one-per-tick run fine. Not yet
   root-caused (suspect: end-of-tick attached-clip machinery digesting the
   churn); workaround = staged init.
3. **`removeMovieClip` of attachMovie'd container children hangs the runtime
   a few ticks later** — both our original remove+reattach takeover and DJ's
   own climb-recycle deletion (`removeMovieClip(block_(lb-4))` on landing)
   reproduce it: with deletions left enabled, the run froze ~10 ticks after
   the first recycle landing (lb=5 → delete block_0 → hang ~tick 73), with
   the mock host's 15s timeout never firing. With deletions disabled the same
   build runs indefinitely. Worth a dedicated runtime session: likely
   interaction of `actionRemoveSprite` invalidation with the attached-clip
   render/enterFrame walks. The REAL game presumably hits this too on long
   browser climbs (the platform-followups note "block* clips accumulate
   unboundedly in child_mc_cache" is the same neighborhood).
4. The native `coin` sprite (frame-1 action `gotoAndPlay(1)`, a per-tick
   self-goto) is left unattached from injected AS (`VIZ_COIN=false`) pending
   the same investigation — pickup markers currently have no visual.
5. **The container's frame-1 DoAction is deferred** relative to the injected
   clip's enterFrame (it ran ~tick 4-5, after our first ticks; native/Ruffle
   run it before). The loader waits for `attachBlocks`/`lastBlockAttached`
   before taking over so the kill can't be undone by a late `attachBlocks()`.

## Graphics-native finding (post-portal tail only)

After the brown break (`block.gotoAndStop(4)` from the hero), graphics-native
logs `Warning: Failed to place object at depth 1` (the break-frame debris
child placement inside the attached clip) and shortly after `container._y`
reads `undefined`; subsequent respawns then have no platforms. Everything up
to and including the portal event is clean and Ruffle-identical, and in
production the host swaps regions on `sendExit` anyway. Known-adjacent to the
documented "nested children of attached clips after injected goto" gap —
Ruffle is ground truth for the post-break tail (where the hero simply
re-lands on p8 and keeps bouncing).

## Browser-WASM sustained-physics verification (the deferred ledger item)

**VERIFIED.** With the final loader design the production browser runtime ran
the zero-input scenario for **952 and 957 ticks in two consecutive 45s runs**
(climb → loc_0 → 15s soak → grant → portal → stable bounce-in-place on p8 to
the end of capture), on the same physics lattice as Ruffle/native (same vy
values, same scroll heights, no drift, no falls, no respawns). DJ's hero
physics under browser-WASM are stable over sustained play.

**Important caveat — the result is design-dependent.** Earlier iterations of
the loader hung the browser runtime nondeterministically (ticks 6 / 30 / 73
across runs): the page's main thread busy-loops inside **`$malloc` called
from ASYNCIFY's `allocateData`** (pinned via CDP `Debugger.pause` on the hung
thread — `run_pausestack.js`, kept in the harness dir). dlmalloc spinning on
the per-frame asyncify allocation means **corrupted heap chunk metadata**,
i.e. an earlier UAF/OOB write. Triggers correlated with: (a)
`removeMovieClip` of attachMovie'd container children — including DJ's OWN
climb-recycle deletion, (b) large single-tick batches of MC ops from the
injected clip's enterFrame. An ASAN graphics-native run of the identical
scenario is CLEAN (only exit leaks), so the corruption lives in the
browser-only runtime arm (`!NO_GRAPHICS && !OFFSCREEN_RENDER` — the
attached-clip machinery), which native ASAN cannot reach. The final loader
avoids every implicated operation (claim/park instead of remove+reattach,
staged one-op-per-tick takeover, hero recycle-deletion disabled) and has not
hung since. A dedicated runtime session should chase the corruption with
emscripten `-sASAN` (ASAN-in-wasm) on this scenario — until then, treat
`removeMovieClip`-of-attached-clips under browser-WASM as hazardous. NOTE:
the real unmodified DJ exercises the recycle-deletion path on every climb in
browser-WASM, so this bug likely affects long real-game sessions too.

**ADDENDUM (2026-06-11, dedicated hunt session): ROOT-CAUSED AND FIXED.**
The corruption is a **wasm stack overflow**, not an MC-machinery bug.
Emscripten's default stack is 64KB (`STACK_SIZE`); recompiled AVM1 functions
carry multi-KB `ActionVar` frames, and the injected clip's enterFrame
dispatch chain (`tagMain → frame_N → tagFlushPendingEnterFrame → clip_action →
actionCallMethod → …`) overflowed it only ~6 frames deep. Wasm linear memory
has no guard pages, so the overflow silently writes below the stack into
dlmalloc-managed memory — corrupted chunk metadata, and the page later
busy-loops inside `$malloc` (the pinned spin stack). Evidence chain:
(a) the browser arm compiled NATIVELY (render-stubbed, ASAN +
`-DHEAP_PASSTHROUGH`, plus an o1heap/dlmalloc cross-free `--wrap=free` guard)
runs the identical scenario clean for 27k ticks — 8MB native stack;
(b) `-sMALLOC=emmalloc-memvalidate` in the browser detects metadata
corruption on the loader's FIRST tick — even in runs that never hang, so the
"green" soaks were corrupting too and hang timing (ticks 6/30/73) was just
layout luck; (c) `-sSTACK_OVERFLOW_CHECK=2` converts it to an explicit
`stack overflow (Attempt to set SP …)` abort at the same site; (d) with
`-sSTACK_SIZE=8MB` both oracles run clean through the full scenario
including the harsh repro (one-tick mass remove+reattach takeover + hero
recycle-deletions + coin viz clips re-enabled). Fix landed in
`build_test.sh` (both wasm modes) + `build_graphics_host.sh`. The
removeMovieClip / mass-MC-op / coin-self-goto correlations were all just
"deepest call chain that tick". Stock loader re-verified post-fix: 978-tick
fixture soak and 1017-tick full-EI soak, contract events intact. The
loader's claim/park + staged-init design is kept (correct semantics for
authored levels). Previously deployed `docs/` / `docs2/` wasm demos were
built with the 64KB stack and should be rebuilt to pick up the fix.

## THE key open question: 240px stage vs 600px worlds — RESOLVED (option 1, IMPLEMENTED)

**Option 1 is implemented and verified on Ruffle + graphics-native** (the
go-ahead arrived mid-session; option 3 is dead per the AP side). It is much
cheaper than the spec feared:

The hero's wrap is NOT a hardcoded 240: the decompiled hero load handler does
`var SW = Stage.width` and the enterFrame wraps with
`if (this._x - xradius > SW) this._x = 0; if (this._x < -xradius) this._x = SW;`.
The only 240 literals anywhere relevant are (a) the native spawner's
`randomx` — which the loader disables, and (b) dead `_level1` accelerometer
code (motion.swf never loads). So:

- **The SWF header RECT is patched at injection time**: `inject_tracer.py
  --stage-width 600` re-packs the FrameSize RECT (fields are SIGNED sharing
  one nbits, so 12000 twips needs nbits 14→15 — a 1-byte header growth, no
  tag rewriting, no bytecode constant rewrite at all).
- `Stage.width` then reports 600 on BOTH runtimes (verified: the loader
  traces `stage=600x400` under Ruffle and SWFRecomp native) → `SW=600` → the
  hero's wrap is correct for 600-wide worlds **by itself**. The encoders take
  `--stage-width 600` (gen_fixture) / `window.__DJ_STAGE_W=600` (page) for
  1:1 x mapping; the canvas/Ruffle element becomes 600×400 (no zoom).
- Verified end-to-end: wide build runs the full region_4_4 sequence on
  graphics-native (hero at world x=300, both events fire) and on Ruffle with
  the full EI bridge (stable to tick 713). SWFRecomp's offscreen framebuffer
  follows the header (600×400 PNGs) with no runtime change.
- Build: `python3 gen_fixture.py --stage-width 600 && STAGE_WIDTH=600
  ./build_loader.sh`; wide Ruffle harness via `WIDE=1 ./run_ruffle.sh`.
- One real finding from the wide bring-up: the pre-takeover NATIVE game
  (random blocks, ~17 staged-init ticks) is RNG-luck — in the wide build the
  hero died before takeover (gameOver → frame 3 → container gone). The
  loader now pins the hero mid-screen and clears gameOver until the level
  owns the game; this made startup deterministic on every tier/variant.
- Residual cosmetics only: DJ's 240-wide background/menu art leaves the right
  strip empty (stretchable from injected AS later); browser-WASM wide run not
  yet exercised (240 remains the default until the AP side wants the swap).

Option 2 (per-frame wrap un-teleport) remains a fallback we won't need;
option 3 (240-wide generation profile) is officially dead.

## Archipelago-CC exchange — all three asks ANSWERED mid-session

1. **Expected traces** (`~/CC/Archipelago-CC/NewDocs/plans/procedural-generation/
   dj-loader-traces/region_4_4_expected.json`) — cross-checked against our
   graphics-native run, aligned at the first landing on p0 per the file's
   note. RESULTS: climb cadence matches (11 ticks per platform with a single
   12-tick gap somewhere in the column — theirs lands the extra tick at
   p2→p3, ours at p6→p7, a sub-quantum phase difference), the p8
   bounce-in-place period matches exactly (alternating 15/16 ticks), and the
   goals fire at matching offsets (loc_0 on the p4 landing ≈ dt 44–47 from
   first landing; the portal right after grant+climb, theirs t=304 for grant
   @300, ours LT305 for grant @tick-300). Hover variance on our side matches
   their per-landing `hover` values' range (mixed sign, −3..+20px by arrival
   phase) — per their registration verdict (platform.y IS the catch line),
   our `block._y = world_y` placement stands with NO offset.
2. **pollItems semantics** — CONFIRMED by the AP side: full current held set
   per tick, idempotent, matching `main.js` lastItems. That is what we built.
3. **600-wide go-ahead** — received and implemented this session (section
   above). Option 3 (240-wide regeneration) is dead.

Remaining items for the next exchange:
- If the 1-tick phase-placement difference in the climb matters for playback
  /verification, we can dig into the catch-order semantics (real DJ tests
  post-move feet with current vy); for item logic it is irrelevant.
- Later increments per the spec (input gating, springs/jetpacks, blue movers
  under OUR sweep spec, region swaps on configure) — no blockers visible.
- A browser-WASM run of the WIDE build when you want it as the embed default.
