# 2026-05-26 — Doodle Jump browser-WASM, gameplay platforms

Thirteenth handoff in the Doodle Jump browser-WASM debugging chain.

Prior handoffs:
1.  `2026-05-25-doodle-jump-browser-investigation.md` — initial investigation + cycling-bug diagnosis.
2.  `2026-05-25-doodle-jump-followup.md` — cycling fix (`98b388e46`).
3.  `2026-05-25-doodle-jump-clip-events.md` — clip-event LOAD / ENTER_FRAME dispatch (`3ac27552e`).
4.  `2026-05-25-doodle-jump-audit.md` — 22-gate audit (`c9b11cc99`).
5.  `2026-05-25-doodle-jump-bounce-fix.md` — 6 more gates (`68889f5ed`).
6.  `2026-05-26-doodle-jump-buttons-clickable.md` — buttons clickable (`92606558b` + `7e9b53a6a`).
7.  `2026-05-26-doodle-jump-orphan-text-cleanup.md` — descendant MC invalidation (`c2147d58e`).
8.  `2026-05-26-doodle-jump-info-label-cleanup.md` — invalidate descendants on Replace2Ratio (`bd9e830a9`).
9.  `2026-05-26-doodle-jump-cache-leak-half-fix.md` — same-(char, ratio, depth) modify-detect (`a4eb48071`).
10. `2026-05-26-doodle-jump-cache-leak-full-fix.md` — deferred-invalidate via `pending_remove` (`78000f548`).
11. `2026-05-26-doodle-jump-score-fix.md` — pending_remove finalize before AQ_KIND_LOAD drain (`38832b57a`).
12. `2026-05-26-doodle-jump-menu-nav.md` — menu sub-screen navigation via gotoAndStop/Play catch-up (`bed8cd5fd` + `c14b36aef` + docs).
13. **This doc** — gameplay platforms via `container.attachMovie("cloud", ...)` (commit `3ff709191`).

**Branch state at writing:** `master`, 1 unpushed commit ahead of `origin/master` (this session's runtime fix; docs commit follows).

## TL;DR

- **Root cause stack** (three coupled gaps; fixing one without the others doesn't help):
  1. `attachMovie` (both `CallMethod` and `CallFunction` paths) in `action.c` was a 2-line no-op stub in browser-WASM — the full impl was gated `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)`.
  2. `ng_fire_child_constructors` + `fire_eager_constructors` in `tag.c` shared the same gate — once attachMovie ran in browser-WASM, those needed to be linkable from it.
  3. `exec_sprite_frame` in `graphics_stubs.c` (the browser-WASM-only stub) didn't swap `g_current_context` to the sprite's MC, so sprite frame scripts ran in root context. DJ's container.frame_0 script (`script_4`) sets `this.onEnterFrame = func_anonymous_1`; with `this = _root`, it bound to root and `this.attachMovie("cloud", ...)` resolved to `_root.attachMovie`, not `container.attachMovie`.
- **The 3-way ordering matters.** Fixing only #1 + #2 (without #3) routes container.attachMovie calls to root, where they're either no-ops (post the new root-noop guard) or trigger the DJ script_15 `MCSpyConnection` constructor-spam hang (without the guard). Fixing only #3 doesn't help because attachMovie is still a stub.
- **Pass criterion met (stretch):** Play click transitions to gameplay (`dl_count` 9→6 at root), spawns **15 platforms + 1 coin + 1 inverse** via `container.attachMovie`, hero scores **320+** before falling off (vs pre-fix instant gameover with no scoring). Memo: gameplay still ends quickly because hero physics + platform-y-position interaction isn't yet stable; the platforms exist and are collidable to *some* extent (non-zero score), but the bounce loop isn't sustainable. Separate follow-up.
- **Baselines clean:** trace harness 407=407, DJ menu unchanged (8 unique canvases, dl=9 stable, cursor pointer/default over/off play button, all 4 button labels "play/info/score/options" visible), DJ info-click loads sub-screen (dl=3 with "back" button), Snake menu renders (dl=16 stable). Pong dl=3 (was 2 pre-fix) — still preloader-stuck (pre-existing item B), visual loading screen renders the same.

## Root cause — the three gaps

### Gap 1: `attachMovie` is a stub in browser-WASM

`action.c`'s `actionCallMethod` handler for method name "attachMovie" (line 63931) and `actionCallFunction` handler for func name "attachMovie" (line 56402) both gated their full implementation on `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)`. The `#else` arm in both was:

```c
#else
    if (args != NULL) FREE(args);
    pushUndefined(app_context);
#endif
```

So in browser-WASM, every `attachMovie` call silently returned `undefined`. DJ's `container.onEnterFrame` (`func_anonymous_1`) loops `for (i=0; i<maxblocks; i++) this.attachMovie("cloud", "block_"+blocknr, this.getNextHighestDepth())` — all 15 calls were dropped, no platforms spawned, hero fell off-canvas.

Same pattern as the historical `cloneSprite` / `removeSprite` fix (`e0568fe7`, memory entry `browser-wasm-frame-func-rerun` option 1): originally implemented for the offscreen / headless paths because browser-WASM was assumed to do all AS-side dynamic placement via the renderer; once browser-WASM grew real games with AS-side attachMovie, the gate became wrong.

### Gap 2: `ng_fire_child_constructors` was gated out of browser-WASM

Action.c's attachMovie impl calls `ng_fire_child_constructors` for the newly-attached MC (so child sprites placed during the attach's `funcs[0]` run get their registered-class constructors fired). That helper lived behind the same `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)` gate at `tag.c:8247`, and its only call-target `fire_eager_constructors` (static, line 4733) was also gated.

Linker error after un-gating only Gap 1:
```
wasm-ld: error: action.o: undefined symbol: ng_fire_child_constructors
```

Fix: removed both gates. The function bodies use only `actionFindOrCreateMovieClip`, `actionInvokeRegisteredClassConstructor`, `actionSetupRegisteredClassPrototype`, `ng_lookupExportName` — all available in browser-WASM.

`ng_fire_child_constructors` sits inside a large NO_GRAPHICS-only block (lines 8163-8326). To expose it without restructuring that block, the fix uses a temporary `#endif`/`#if` split around just the function:

```c
#endif // NO_GRAPHICS — opens at line 8163, reopen below
void ng_fire_child_constructors(...) { ... }
#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER) // reopen the block
```

### Gap 3: `exec_sprite_frame` in browser-WASM didn't swap `g_current_context`

The full `exec_sprite_frame` in `tag.c:345` (gated `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)`) does:

```c
if (obj->instance_name != NULL) {
    MovieClip* mc = actionFindMovieClipByName(obj->instance_name);
    if (mc) { actionSetCurrentContext(mc); actionSetBaseClip(mc); }
}
f(app_context);
actionSetCurrentContext(saved_ctx);
```

The browser-WASM stub in `graphics_stubs.c:158` only set `g_current_sprite_obj`. The existing in-file comment at `action_queue.c:636-643` documented this as a known gap:

> "In browser-WASM (USE_WEBGPU without OFFSCREEN_RENDER) the exec_sprite_frame stub in graphics_stubs.c sets g_current_sprite_obj but doesn't swap g_current_context, so ctx_mc captured here is NULL"

And `tag.c:3413-3416` (inside tagShowFrame's branch comparison) explicitly noted:

> "the wasm graphics build relies on no-op stubs in graphics_stubs.c and skips this — sprite-relative scripts in wasm graphics still run in root context."

Consequence for DJ: `script_4` (container's frame_0 script) ran with `g_current_context = NULL`. Inside it, `actionDefineFunction("attachBlocks", ...)` + `attachBlocks()` set `this.onEnterFrame = func_anonymous_1` — `this` resolves to root (since context was NULL). `func_anonymous_1` then ran each tick as root's onEnterFrame; inside, `this.attachMovie("cloud", ...)` resolved to `_root.attachMovie`, which hit the root-noop gate (see "Why the root-noop gate exists" below). Zero platforms spawned.

Fix mirrors tag.c's pattern but uses `actionFindOrCreateMovieClip` (not `actionFindMovieClipByName`): browser-WASM's `process_sprite_needs_init` doesn't run (gated out of `tagShowFrame`'s wasm branch at `tag.c:3413`), so timeline-placed sprites never get their MCs created elsewhere. Without create-on-miss, the first `exec_sprite_frame` for a sprite finds no MC and skips the swap — same effective bug.

**Critical: only create-on-miss for sprites with NO clip actions** (`obj->clip_action_count == 0`). DJ's menu buttons (sprite_46 at depths 3/5/7/8) have clip actions — those MCs are already created via the clip-event LOAD dispatch path. Creating a shadow MC here breaks button hit-test AND the LOAD-set button label: the first attempt without the guard produced a menu screen with no "play/info/score/options" text and cursor=default over the play button.

## Why the root-noop gate exists (browser-WASM only)

Once gap 1 was fixed, the menu started hanging at ~t=2.25s. Diagnosis: DJ's `script_15` (Spy library init, queued in frame_0) calls `_root.attachMovie("MCSpyConnection", "mcSpyConnection", _root.getNextHighestDepth(), {_x:0, _y:0})` which registers SpyConnection1 as a class and attaches an MCSpyConnection at the next free depth.

In browser-WASM, root `frame_funcs` re-execute every tick (no `is_playing` gate — see memory entry `browser-wasm-frame-func-rerun`). So `script_15` re-runs every tick, calling `_root.attachMovie(...)` every tick, which fires the SpyConnection1 registered-class constructor every tick. SpyConnection1 opens a LocalConnection, tries to call methods on it, and various other Flash-API operations that aren't fully wired up in browser-WASM — cumulative state grows and the WASM hangs after ~45 frames (45 / 20 FPS ≈ 2.25 s, matching the symptom).

Fix: gate `attachMovie` to a no-op when `mc == &root_movieclip`, browser-WASM only. The DJ container's attachMovie call has `mc == container` (a child sprite MC), so it falls through. The DJ Spy library's `_root.attachMovie` no-ops cleanly (its only visible side-effect would be the spy connection which we can't honor anyway).

This is symptomatic, not architecturally correct: a "real" fix would either (a) gate root frame_funcs on is_playing in browser-WASM swf.c (the `browser-wasm-frame-func-rerun` issue), or (b) implement LocalConnection enough to make SpyConnection1 idempotent across re-attaches, or (c) add a "skip if same name+char_id+depth already attached" guard to attachMovie root-attaches. Option (c) was tried first; turned out to make the hang worse (probably because `getProperty` lookups for the existing MC hit some other bug). The root-noop is the smallest fix that unblocks DJ without regressing the menu.

## Three-way fix diagnostic chain

The reason this took so many iterations is each gap masks the others:

| Fix(es) applied | Symptom |
|---|---|
| (none) — pre-fix baseline | Hero falls off; no platforms; instant gameover |
| Gap 1 only | Link error: `ng_fire_child_constructors` undefined |
| Gaps 1 + 2 only | Menu hangs at t=2.25s (script_15 MCSpyConnection constructor spam) |
| Gaps 1 + 2 + root-noop | Menu OK, but gameplay still has no platforms (container.attachMovie resolves to `_root.attachMovie` — no-op'd) |
| Gaps 1 + 2 + root-noop + Gap 3 (no clip_action_count filter) | Cursor inverted on menu (`pointer` off button, `default` over button), no button labels — shadow MC for sprite_46 breaks button MC |
| All four, with clip_action_count filter | DJ menu OK, cursor OK, info-click OK, gameplay spawns platforms, scores 320+ |

Debug prints used to walk the chain (all removed before commit):
- `[DJ_DBG_AM]` in attachMovie — log mc/root/name/linkage/depth
- `[DJ_DBG_ESF]` in exec_sprite_frame — log obj/name/ctx + "-> set ctx=" when MC found
- `[DJ_DBG_S25F0]` in sprite_25_frame_0 — log ctx at entry
- `[DJ_DBG_S4]`, `[DJ_DBG_AB]`, `[DJ_DBG_FA1]` — log ctx at script_4 / attachBlocks / func_anonymous_1 entry

Key transition the prints revealed (post all 4 fixes):
```
[DJ_DBG_ESF] obj=0x15e0330 name=container ctx=0      ← container's exec_sprite_frame
[DJ_DBG_ESF] -> set ctx=0x4172b348 (mc for container) ← find-or-create succeeds
[DJ_DBG_S25F0] entry ctx=0x4172b348 catch_up=0 skip=0 ← container's frame_0 has container context
[DJ_DBG_S4] entry ctx=0x4172b348                      ← script_4 sees container as this
[DJ_DBG_AB] attachBlocks ctx=0x4172b348               ← attachBlocks sees container
[DJ_DBG_FA1] entry ctx=0x4172b348                     ← onEnterFrame fires on container
[DJ_DBG_AM] mc=0x4172b348 root=0x10078 name=block_0 linkage=cloud depth=0   ← attachMovie spawns block_0
[DJ_DBG_AM] mc=0x4172b348 root=0x10078 name=block_1 linkage=cloud depth=1
... 15 total blocks + coin_6 + inverse_11 ...
```

## What this fix DOESN'T address

- **Hero physics / platform-bounce stability.** Hero falls through platforms after scoring 320ish — gameplay ends quickly. Platforms exist and are collidable to some extent (otherwise score would be 0), but the bounce loop isn't sustained. Could be:
  - Platform y-coordinates wrong (cloud sprite frame_0 places shape at twips coords that don't match what hero physics expects).
  - Hero's `vy` reset on bounce uses wrong handler.
  - `_root.lastblockhit` or `_root.lastDeletedBlock` tracking is wrong.
  - `MOCK_DATE_TIME`-seeded Math.random in attachBlocks's `randomx` calc produces a deterministic but unfortunate sequence on the first run.
  Investigate by adding score-progression tracing or comparing hero `_y` trajectory to Ruffle's.
- **Pong preloader transition.** Pre-existing item B from prior handoffs. Pong now shows `dl_count=3` (was `dl_count=2`) but is still stuck on the preloader. The new entry at depth 4 is sprite_10 — possibly because my exec_sprite_frame change exercises a code path that places a sprite that the previous stub silently skipped. Functionally the preloader screen still looks the same. Investigate when tackling item B.
- **Browser-WASM root frame_funcs re-running every tick.** The fundamental architecture issue (memory `browser-wasm-frame-func-rerun`). This session adds another symptomatic patch (root-noop attachMovie); the real fix is option 1 from that memory entry, which the prior attempt reverted. Don't re-attempt without first fixing the AS-side issues that revert exposed.
- **MCSpyConnection / LocalConnection support.** DJ's spy library is non-functional. The library opens a LocalConnection for cross-SWF debugging that's not used by the game proper, so no impact on gameplay.

## Don't-touch list (cumulative — adds to handoff #12's list)

(All entries from handoff #12 remain. Adding:)

- **`exec_sprite_frame` in `graphics_stubs.c` find-or-create gate: `obj->clip_action_count == 0`.** Sprites with clip actions (DJ's menu buttons sprite_46 with clip_actions_145..148) MUST be skipped. Their MCs are created elsewhere via the clip-event LOAD dispatch path. Creating a shadow MC here breaks button hit-test (cursor stays `default` when over button) and the LOAD-set button label (text never gets set, buttons appear blank). Verified: removing the filter regresses DJ menu — `play`/`info`/`score`/`options` labels disappear and clicks on buttons don't register.

- **`actionFindOrCreateMovieClip` parent = `g_current_context ?: &root_movieclip`.** For root-level sprite placements g_current_context is NULL → uses root. For nested sprite placements (e.g. a sprite-inside-a-sprite), g_current_context should be the outer sprite's MC. The mirror is `tag.c:558` `pmc = (g_current_context != NULL) ? g_current_context : &root_movieclip`. Same convention.

- **`attachMovie` browser-WASM `mc == &root_movieclip` no-op gate (action.c:63976 + 56409).** Required: root frame_funcs re-execute every tick in browser-WASM, so a root-targeted attachMovie's registered-class constructor would fire every tick. DJ's script_15 `_root.attachMovie("MCSpyConnection", ...)` triggers this cycle. Symptom of removing: menu hangs at ~t=2.25s (~45 frames).

- **`ng_fire_child_constructors` and `fire_eager_constructors` are now compiled in all three builds.** Their bodies use only generic runtime helpers; the previous NO_GRAPHICS||OFFSCREEN_RENDER gate was historical (matched the gate on attachMovie's call sites that used them).

## Tools / state

- Local Ruffle source: `~/CC/ruffle`
- MTASC: `~/CC/mtasc/bin/mtasc`
- Probe venv: `/tmp/pong-probe/venv`
- Latest known-good probes / shots:
  - DJ menu shot (after fix): `/tmp/dj-menu-shot.png` (play / info / score / options labels visible)
  - DJ play-click shot (after fix): `/tmp/dj-shot-t01.png` (game over, score 320)
  - DJ info-click shot (after fix): `/tmp/dj-info-shot.png` (info screen, back button visible, dl=3)
  - DJ cursor check (after fix): `/tmp/cursor-check.py` → `'pointer'` over play, `'default'` off
  - Snake probe: `/tmp/snake-final/` (dl=16, 8 canvases, no errors)
  - Pong probe: `/tmp/pong-fresh3/` (dl=3, preloader stuck — pre-existing)
- Debug prints used during diagnosis (all removed before commit):
  - `[DJ_DBG_AM]` in action.c attachMovie CallMethod gate
  - `[DJ_DBG_ESF]` in graphics_stubs.c exec_sprite_frame
  - `[DJ_DBG_S25F0]` / `[DJ_DBG_S4]` / `[DJ_DBG_AB]` / `[DJ_DBG_FA1]` in the recompiled script files
  - To re-add: same pattern, `fprintf(stderr, "[DJ_DBG_X] ...", ...)` with a static counter to bound output

Push when ready.
