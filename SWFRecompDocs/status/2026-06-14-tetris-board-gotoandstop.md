# Tetris board render: `b_mc[pos].gotoAndStop(color)` was a no-op (browser-WASM)

**Date:** 2026-06-14 (cont. 29)
**Status:** 🟡 **PARTIAL** — three real infrastructure bugs FIXED (the board cells now
resolve and `gotoAndStop` reaches the frame-navigation handler), but the board is
**still blank** because of a separate, deeper bug (#4 below: `shape_array` resolves
to `undefined` in `drawShape`). Verified with `tetris_compare.py`.
**Bucket:** browser-WASM only (not CI-observable for the visible result; fixes #1/#2
compile into OFFSCREEN/NO_GRAPHICS → run CI both modes as a no-regression check).

---

## How the board is actually drawn (corrected mechanism)

The cont. 28 handoff hypothesis ("frame-0 content created at attach but **cleared**
before render") was **wrong**. Fresh instrumentation showed the cells' content
persists; the board is blank because the **colouring path never runs**.

- The board is ~200 `block` cells (`char 10`, an 8-frame sprite) `attachMovie`'d onto
  the `b_mc` sprite (root depth 198). **Frame 0 of `block` is the empty "bang_mc"**
  (`char 2`, whose own frame 0 is empty); frames 1–7 are the coloured block shapes.
  So a fresh cell on frame 0 is **correctly blank** — an empty board renders nothing.
- A cell shows a colour via `drawBlock(num, pos)` → **`b_mc[pos].gotoAndStop(num+1)`**
  (and the preview via `drawNextBlock` → `next_mc[pos].gotoAndStop(...)`).
- So the board/piece are blank iff those `gotoAndStop` calls don't repopulate the
  cell's display list. They didn't — for **four** independent reasons.

## Root causes (traced via PMDIAG instrumentation, now stripped)

1. **`MAX_CHILD_MOVIECLIPS = 128` cache overflow → `parent[child]` unresolvable. FIXED (→512).**
   `findOrCreateMovieClip` caches MCs by (name, parent) in `child_mc_cache`. When the
   cache is **full**, a fresh lookup can't be cached, so **every** `GetVariable("b_mc")`
   / `GetMember(b_mc, pos)` mints a *brand-new* `MovieClip` (empty `dynamic_props`,
   `display_obj==NULL`). Tetris's ~200 board cells overflow 128, so `b_mc`/`next_mc`
   became uncacheable and their attached children (bound on the attach-time instance's
   `dynamic_props`) were unreachable — `b_mc[pos]` resolved to **undefined**, and
   `gotoAndStop` no-op'd on the undefined receiver. Confirmed: after the bump, the
   `next_mc` pointer is **stable** across lookups and `dynprop=1`. `action.c:~20849`.

2. **`_mcm_chain_bypasses_mc` false-positive on vanilla attached sprites. FIXED.**
   The `Object.registerClass` bypass heuristic in `actionCallMethod`'s MOVIECLIP path
   walks `dynamic_props.__proto__` looking for `MovieClip.prototype`; if not found it
   routes MC builtins (`gotoAndStop`, `getDepth`, …) to `_mc_user_dispatch` (→ no-op).
   The `block` cells gain a **generic `dynamic_props` whose `__proto__` is the builtin
   `Object.prototype`** (not a registered class), which legitimately doesn't chain to
   `MovieClip.prototype` — so the heuristic wrongly diverted their `gotoAndStop`. Fix:
   treat the chain as **non-bypassing when the immediate `__proto__` IS the builtin
   `Object.prototype`** (a real `registerClass` replaces `__proto__` with a *user*
   prototype object, even `{}`, which is distinct from the builtin). Confirmed:
   `bypass` went 1→0, `GASBRANCH` now reached. `action.c:~64596`. Keeps
   `register_class/registerClassTest2` correct (its `__proto__` is a user `{}`, not the
   builtin). **CI both modes** as a no-regression check (it compiles into trace builds).

3. **Browser-WASM MC `gotoAndStop` set flags but never rebuilt the display list. FIXED.**
   The `!NO_GRAPHICS && !OFFSCREEN_RENDER` arm of the MC-targeted `gotoAndStop` handler
   only set `dobj->sprite_next_frame`/`sprite_manual_next_frame` and relied on a pump
   that never repopulates an attached cell's `sprite_display_list`. Now it calls
   **`ng_gotoFrameByMC`** (same as the OFFSCREEN arm) to run the frame funcs
   synchronously into the MC's standalone display list. The DJ no-op guard is preserved
   (re-expressed as `mc->currentframe == frame0+1`, which `ng_gotoFrameByMC` keeps in
   sync — `sprite_current_frame` is the *next* frame, not the displayed one), with the
   old flag-set kept as a fallback. `ng_gotoFrameByMC` never touches the root timeline,
   so the Doodle-Jump-cloud-platform concern is moot. `action.c:~64866`. Browser-WASM
   only (not in CI) — **DJ/Snake/Pong should be re-checked manually** (low risk:
   single-frame clips no-op via the guard; the change is the more Flash-correct
   synchronous rebuild).

4. **`shape_array` resolves to `undefined` in `drawShape`. OPEN — the current blocker.**
   With #1–#3 fixed, `gotoAndStop` reaches `ng_gotoFrameByMC`, but the **coloured**
   calls (`b_mc[block_array[i]].gotoAndStop(color+1)`) still hit an undefined receiver,
   because `block_array[i]` is **NaN**: it's computed from
   `blockPos = shape_array[thisShape*16 + rotation*4 + i]`, and **`GetVariable("shape_array")`
   returns undefined** in `drawShape` (`PMDIAG GVUNDEF name=shape_array` fired 12×).
   `shape_array` is a 112-element table built **once** in `script_7` (game-start frame)
   via `new Array(13,9,5,1, …)` (`actionNewObject` with str_102="Array") +
   `SetVariable`. Curiously, **`block_array` (set the same way, 4 elements, later in
   `script_7`) DOES resolve**, and the scalars `xPos`/`yPos`/`thisShape`/`rotation` all
   resolve — only the 112-element `shape_array` is missing. Strong suspects: (a)
   `actionNewObject("Array", N)` with a large `N` mis-consuming the operand stack so the
   following `SetVariable` never binds `shape_array` (or binds a corrupted name), or (b)
   a scope/`this` mismatch specific to that assignment. **Next step:** instrument
   `actionNewObject` (Array path) for the 112-arg call + the `script_7` `SetVariable`
   that targets `shape_array` — confirm whether the var is set at all and in which
   scope. Once `shape_array` is populated, #1–#3 make the board + falling piece render.

## Reproduce / verify (the harness)

```bash
source emsdk/emsdk_env.sh
SWFRecomp/scripts/build_test.sh flasharchive/Tetris wasm --graphics --clean
SWFRecomp/scripts/deploy_example.sh flasharchive/Tetris "$(pwd)/docs2/examples" --no-index --graphics
# single clean run — kill stray chrome/python first, the harness shares ports 8410/8411
/tmp/browser-test-venv/bin/python3 tools/divergence/game_drive/tetris_compare.py
# view tools/divergence/game_drive/compare_out/compare_ok.png (left=Ruffle, right=SWFRecomp)
```

> Process notes for next session: (a) the harness shares fixed ports — **never run two
> concurrently**; a late-finishing `--clean`-build+harness collides and deletes
> `pmdiag.log`. Kill `tetris_compare`/`chrome`/`browser-test-venv` and confirm 8410/8411
> free before each run. (b) `printf("PMDIAG …")` is captured to `compare_out/pmdiag.log`
> by the harness console hook — gate temp diagnostics on `#ifdef __EMSCRIPTEN__`. (c) the
> SWFRecomp side is slow; allow `timeout 600`. (d) build → `strings <wasm> | grep <marker>`
> to confirm a diagnostic actually landed before deploying (a couple of builds raced).

## Changes (this commit)

- `SWFModernRuntime/src/actionmodern/action.c` only:
  - `MAX_CHILD_MOVIECLIPS` 128 → 512 (fix #1).
  - `_mcm_chain_bypasses_mc` Object.prototype guard (fix #2).
  - browser-WASM MC `gotoAndStop` → `ng_gotoFrameByMC` + currentframe-based no-op guard (fix #3).
- No changes to `tag.c`/`tag_stubs.c` (only carried temp diagnostics, now stripped).

## Bug list status (Tetris)

- DONE prior: menu input, textfield-bind value, `paused_mc` overlay, non-root attach render.
- DONE this session: board-cell name resolution (#1), gotoAndStop bypass (#2), gotoAndStop
  display-list rebuild (#3).
- **OPEN (blocker): `shape_array` undefined in `drawShape` (#4)** — board + falling piece
  still blank until fixed.
- OPEN (deprioritized): dynamic-textfield digit italic slant.
