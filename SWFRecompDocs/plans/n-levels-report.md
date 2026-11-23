# N: telemetry byte-identity, real levels 1–4, thwump and drone routes (2026-11-23)

This is a one-task session following `n-exec-order` (`n-exec-order-report.md` §5), launched by the s26 fan-out coordinator. Baseline: master `9df3a8a60`. Landed: `1396f1e10` (runtime fix + fixture + probe tooling) and the docs/routes commit that carries this report.

**Summary**
- **Goal 1, telemetry byte-identity: DONE, but not by the brief's route.**
  - N's last `h=` diff (t=56/58) was not the probe sampling from an older sibling clip. `NF` is already printed from inside N's `RunApp`, which is `_root`'s onEnterFrame.
  - It was **two runtime bugs** in clips attachMovie'd from `_root.onEnterFrame` while the root timeline is stopped (§1). Both are fixed.
  - Result: level 1 native = Ruffle exporter, byte-identical including `h=`.
  - The exec-list rearchitecture (`n-exec-order-report.md` §2b) is still parked and was not needed.
- **Goal 2, levels 1–4: partly done (2 of 4 completed), and the previous "levels 1–4" result is overturned (§2).**
  - The probe's `START_LEVEL` never loaded level k: it renamed level 0. Fixed. The real maps load now.
  - Exploration scripts on all four real levels: native = exporter, byte-identical, including a new object-list hash `o=`.
  - Completing routes for **level 2 (thwumps)** and **level 4 (drone)**, each with an enemy-death attempt first. Both are tick-exact against the exporter (§3).
  - Levels 1 and 3 have no enemies. Their routes are not authored yet (§5).
- **Goal 3, native 1:1 pixel pass: DONE** (`w2-attached-holder-render` landed as `f0fa5cfb7` during this session).
  - Level 0's 10 frame-locked shots differ from the exporter in 19–132 of 475,200 px.
  - The one real residual is gold-pickup streaks running 2–3 frames late on ours (§4). That is the next slice.

## 1. The `h=` residual: two attach bugs on a stopped root

N's root timeline is stopped for the whole game, and N's `RunApp` runs from `_root.onEnterFrame`. `ParticleManager.SpawnParticle*` attachMovie's `pfx<n>` clips from inside it.

**Instrument.** I added probe-side `_currentframe` traces at three points per frame: the probe clip's enterFrame, right before `RunApp`, and right after it. I also added temporary runtime prints of the attach, promote, pump and deferred-root-ef order.
- Ruffle: a pfx attached in frame 251 reads `_currentframe` 2 on frame 252. The 31-frame particles are already gone by the time any script reads them on frame 281.
- Native: 1 on frame 252, and the particle is still present at cf=31 on frame 281 (one tick late throughout).
- The runtime print order per tick on native was PUMP → PROMOTE → ROOTEF.

**Bug A (graphics only): promotion before the deferred root onEnterFrame.**
- `swf.c` `tagMain` (OFFSCREEN) ran `ng_promote_attached_playheads` right after the frame-func block.
- With the root stopped, no frame func runs. The deferred root onEnterFrame (n-exec-order root-last) fires at the end of the later `actionDrainActionQueueByKind(SCRIPT)`.
- So a clip attached by the handler stayed at `attached_playable=1` through the next tick's pump and advanced one tick late.
- `swf_core.c` already promoted after that drain, which is why this fixture passed in no-graphics. (`verify_output` defaults to no-graphics. Run `--mode=graphics` before calling an attach-timing fixture green.)
- **Fix:** the OFFSCREEN promote moves to after the SCRIPT drain, the same slot as `swf_core.c`.

**Bug B (both modes): attach-init never ran on a stopped root.**
- An attached clip's frame-1 script is queued as `AQ_KIND_ATTACH_INIT`. Only `tagShowFrame`, inside a root frame func, and the goto Phase-2 path drained that kind.
- With the root stopped, a clip attached from onEnterFrame, a timer, or any drain after `tagShowFrame` **never ran its frame 1**. The entry sat in the queue indefinitely.
- Ruffle runs it the same frame, after the attaching handler.
- **Fix:** `ng_fire_pending_attach_inits` after the stopped-root SCRIPT drain and the past-last-frame SCRIPT drain in `swf_core.c` `swfStart`, and after the SCRIPT drain in `swf.c` `tagMain` (OFFSCREEN). It runs before the promote, so a frame-1 `stop()` still lands before the first advance.
- Browser-WASM is unchanged: it queues the frame-1 script live (no `ATTACH_INIT` there) and already promotes at end of tick.

**Fixture:** `regression/avm1_attach_from_stopped_root_enterframe`.
- Generated SWF6 (`create_test_swf.py`), golden from the Ruffle exporter.
- Shape: holder `h` + stopped root; `_root.onEnterFrame` attaches a 4-frame self-removing `pfx` on its 2nd call; root ef traces `h.p._currentframe`.
- Before the fix:
  - no-graphics missing `p f1`;
  - graphics missing `p f1` and every cf one behind.
- Green in both modes after.
- Variants `root` (attach into `_root`), `holderloop` and `rootloop` (looping 2-frame root) passed before the fix too. Ruffle runs `p f1` in both, so that variant splits the stopped case from the playing case.

**Pricing sweep (before landing).**
- Candidates: every test SWF whose decompressed bytes contain `attachMovie`, across `avm1`, `from_gnash`, `from_shumway`, `regression` and the misc categories. That is 63 rows, including every `regression/avm1_attach*` and `avm1_attached_clip_*`.
- Run in both modes, with a temporary probe logging any tick where the new drain found pending `ATTACH_INIT` work, or where the moved promote saw more pending clips than the old slot would have.
- **Only 2 rows reach the new code:** `avm1/clip_event_propagation_order` and `avm1/issue_2084` (tick 1 each). With a temporary kill switch, both pass with and without the fix, in both modes.
- The other rows' failures, all pre-existing, never touch the new code, so they are byte-unchanged.
- **0 status moves.**
- Caveat: the sweep ran on a tree that also held `w2-attached-holder-render`'s then-staged hunks, which later landed as `f0fa5cfb7`.

**N result** (`START_LEVEL=1 OBJHASH=true AUTOKILL=true FREEZE="" build.sh "400:-/300:R"`, exporter `-f 900` vs native): 437/437 NF lines and every ND line byte-identical, `h=` included.

## 2. `START_LEVEL` was level 0 renamed (n-pixel-pass §4 overturned)

`App_StartNewGame` calls `App_LoadLevel(0, App_StartPreLevelPause)` unconditionally.
- The probe's `START_LEVEL` only called `gamedata.IncrementCurrentLevel()` k times before it. That changes `GetCurrentLevelName()` (the `lvl=` text) and nothing else.
- The new `OBJDUMP` showed the same 116 objects on "levels" 1–4: level 0's map.
- `n-pixel-pass-report.md` §4's "levels 1–4 player-exact" and its "958 pooled clips on every level" were level 0 four times.
- **Fix (probe):** for `START_LEVEL > 0`, run `App_StartNewGame`'s body with `App_LoadLevel(gamedata.GetCurrentLevelID(), …)`.

The real maps (objects from `OBJDUMP`, by type):

| level | name | objects | enemies / features |
|---|---|---|---|
| 1 | cloud city | 43 | 2 exits (one is a trap-door decoy), 2 test doors (one locked + key), 6 bounce blocks. No enemies |
| 2 | all about thwumps | 68 | **3 thwumps, 41 mines**, exit |
| 3 | the box, the box! | 45 | 4 launchpads, 8 one-ways, 3 bounce blocks, locked door + key, exit. No enemies |
| 4 | lockness | 17 | **1 drone** (chaser), 4 locked doors used as stepping stones (keys would open them), launchpad, exit |

**Exploration on the real maps.** Script `400:-/300:R/300:L/200:RJ/200:LJ`, with `OBJHASH` (`h=` + `o=`) and exporter `-f 3400` vs native graphics.

| level | lines (exp = nat) | diff lines | notes |
|---|---|---|---|
| 1 | 2482 | 0 | |
| 2 | 1660 | 0 | the corridor thwump crushes the standing player at t=114 (kill type 0), attempts 0 and 5 |
| 3 | 2470 | 0 | |
| 4 | 2638 | 0 | the drone drifts the whole time (in `o=`) |

## 3. Routes that complete levels 2 and 4 (enemy interaction)

They were authored on the local exporter with the new `search.py`, growing a prefix one landing at a time. They are in `n_drive/routes_ep0.txt`.

**Level 2 "all about thwumps"** (`START_LEVEL=2`).
- a0: stand still; the corridor thwump crushes the player at t=114.
- a1:
  - step right before the thwump lands (it falls 4.29 px/tick, rises 1.71);
  - jump as it lands and drift left over its top, which is 18 px wide; the player only clears its side within a few ticks of the jump peak;
  - ride it to the top;
  - run left over the left thwump to the switch nook (**switch t=507**);
  - step into the left thwump's lane so it drops down the 24-px gap, wait on the short pillar, step onto it as it rises (t≈940) and ride it up;
  - hop over the corridor thwump onto the right thwump's top;
  - run right and drop to the door (**exit t=1144**).
- a2: level 3 loads.

**Level 4 "lockness"** (`START_LEVEL=4`).
- The four locked doors are solid 24-px bars.
- The route stands still, then hops bar to bar without the keys (+96/−48 ×2, +72/−72, then +60/−72 to the ledge).
- a0: switch t=453, then the chasing drone kills the player on the ledge at t=508.
- a1: same chain with a faster last hop: switch t=444, **exit t=476**, ahead of the drone.

**Replay, native vs exporter** (`AUTOKILL=true OBJHASH=true FREEZE=""`, native graphics):

| script | frames | NF/ND lines (exp = nat) | diff | events (identical) |
|---|---|---|---|---|
| level 2 | 2600 | 1936 | 0 | thwump kill a0 t=114; switch a1 t=507; exit a1 t=1144; level 3 loads |
| level 4 | 2200 | 1006 | 0 | switch a0 t=453; drone kill a0 t=508; switch a1 t=444; exit a1 t=476 |

`o=` covers every thwump, mine and drone position on every tick, and it matches throughout. No runtime divergence was found in enemy behaviour, so no fix or fixture was needed for this goal.

## 4. Native 1:1 pixel pass (goal 3)

Recipe from `n-pixel-pass-report.md` §7:
- level 0 `script.txt` with default freezes;
- exporter `-f 1790`;
- native `run_native.py --frames 1800 --capture-ticks <shot frame+1>`, then `build/test_run` run directly with `CAPTURE_TRIGGERS` (the 30 s cap);
- comparison: native `F(k)` vs exporter `k-1` (best of k-2..k), counting pixels with max channel delta > 24.

Telemetry is identical over the common span: native's 5 extra NF lines are frames 1791–1800, past the exporter's last frame.

| shot | 205 | 487 | 609 | 766 | 998 | 1237 | 1378 | 1560 | 1684 | 1776 |
|---|---|---|---|---|---|---|---|---|---|---|
| differing px (of 475,200) | 26 | 25 | 28 | 19 | 25 | 61 | 64 | 88 | 61 | 132 |

Compare the previous browser pass: 1,000–1,700 per shot, mostly EditText −2,−2, since fixed in `63d13990e`.

Residual classes:
1. **fps counter** (bottom-left, about 13–15 px). It reads wall clock, so it is expected to differ.
2. Single-pixel AA on tile/stroke edges.
3. **Gold-pickup streaks are 2–3 frames LATE on ours.**
   - The pickup tick is identical in telemetry. N collects with `GoldObject … mc.gotoAndPlay("COLLECTED")` from inside RunApp.
   - Measured on native F1760–1776: each streak appears and vanishes about 2–3 frames after Ruffle's.
   - A minimal attached `gotoAndPlay("label")` from a stopped root's onEnterFrame (holder and `_root` variants) **matches Ruffle in both modes**, so the plain goto is not the cause.
   - Suspect: the streaks are nested morph children of the gold clip (char 570 frames 5–28, morphs 568/569). Their timeline after the parent's goto is the next lead (§5).

## 5. Next blocker / next slice

0. **Gold-pickup streak phase lag (§4 item 3).** This is the only pixel-visible N divergence left on native. Extract char 570 (+568/569) into a minimal SWF (the splice trick from memory `n-play-game-click`), attach it, `gotoAndPlay("COLLECTED")` from a stopped root's onEnterFrame, and trace the nested child's `_currentframe` per frame against the exporter.
1. Routes for levels 1 and 3 (no enemies).
   - Level 1: key (204,204) inside the upper-left cloud, reached through the notch at about (300,130); locked door (48,348); switch (36,396); exit (708,492). The other exit's switch (60,60) also closes the trap door (360,372) on its own exit.
   - Level 3: switch on the top-right box roof (732,60) via the right-wall one-ways; exit inside the top-left U (204,132); key (252,420) for the bottom-right launchpad door.
2. The rest of episode 0 (levels 5+): turrets, floor guards and homing launchers haven't been met yet.
3. Related, unfixed and UNVERIFIED (seen while reading, not tested): `swf.c` marks dynamic MCs enter-frame-eligible BEFORE the stopped-root SCRIPT drain, while `swf_core.c` marks them after promote. A clip created (not attached) by a stopped root's onEnterFrame may get its first onEnterFrame one tick earlier or later in graphics. No row or N divergence shows it; candidate fixture shape: §1's fixture with `createEmptyMovieClip` + `onEnterFrame` in place of attach.

## 6. Tooling

`n_drive`: `START_LEVEL` fix, `OBJHASH` `o=`, `OBJDUMP`, `TRACKOBJ`, `search.py`, `routes_ep0.txt` (README §"s26 n-levels additions").

Traps:
- `run_native.py`'s 30 s run cap is hit by about 900 N frames on this machine. Run `build/test_run` directly. For captures, set `CAPTURE_TRIGGERS=F0001:iteration:1,…` and `CAPTURE_OUTPUT_DIR`, as `run_native.py` does.
- Never commit from a shared index holding a peer's staged hunks. This session committed through a temp index (`GIT_INDEX_FILE` + `read-tree HEAD`), then `git reset -- <own paths>` in the real index.

## 7. CI / Pages

- `1396f1e10` is CI-observable in both modes (shared `swf_core.c` + OFFSCREEN `swf.c`). The coordinator folded it into the s26 final grading run.
- Browser-WASM code is untouched, so no Pages deploy is needed for this slice.
