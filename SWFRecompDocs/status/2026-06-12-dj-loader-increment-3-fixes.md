# DJ level loader — increment 3 hand-verify fixes

**Date:** 2026-06-12, same-day turnaround on the hand-verify results
(addendum-2 "Hand-verify results" section).

## ⚠ SYNC: re-copy `loader_bytecode.bin` only (shim unchanged, as expected)

1. **Background fill REMOVED** (user decision, 3.3 reverted). The hand-play
   observation confirms what the stale-door bug also showed: dynamic-clip
   z-ordering in live in-app conditions does not honor the depth reasoning
   the fill relied on (it composited above the authored blocks/coins/doors).
   Stage-extension cosmetics are parked; the empty strip stays.

2. **Stale doors on region swap — FIXED, mechanism identified.** The
   "survives one swap, clears on the second" pattern pinned it: on the
   swfrecomp tier, **name lookup of dynamically created clips is unreliable**
   (`_root["apdoor_3"]` resolved undefined while the clip existed), so
   removal-by-name was a silent no-op; vizTick's reuse-by-name also failed,
   so it re-created doors every tick at the same depth (masking the lookup
   failure), and a stale door only vanished when a later region reused its
   index — `createEmptyMovieClip` at the occupied depth replaced it. The
   second hand-verify round also surfaced the same staleness for a
   container-attached COIN (one stale coin survived a swap), so by-name
   removal is unreliable for `attachMovie` children there too. FIX: the
   loader now keeps **AS-side clip-REFERENCE registries** (idx → clip) for
   coins, doors, and ghosts; creation stores the ref, every reuse/dim/move/
   remove goes through the ref, and re-configure clears all three registries
   on the same tick that re-authors the level (with an offscreen park as the
   belt to removeMovieClip's suspenders, and same-depth creation as the
   final backstop). No name lookup remains in any visual path.

   Verified: deterministic ping-pong across 3 swaps with a state dump on the
   revisit shows exactly one coin (dimmed, a=25 — the revisit dimming the
   user couldn't judge behind the fill is confirmed working), exactly one
   door at the correct host riding the container, zero stale visuals; the
   browser-WASM rerun of the previously-failing scenario shows the single
   correct coin and door with the stale ones gone.

3. Arrows + ghost alpha confirmed good — untouched. Collected-coin alpha
   stays 25 for the user's re-check now that the fill is gone.

**Runtime-bug note for this repo's ledger** (not chased now): dynamic-clip
name lookup (`parent["name"]`) on the swfrecomp graphics tier fails for
`createEmptyMovieClip` children of `_root` and is unreliable for removal of
`attachMovie` children of a sprite, while `container["block_N"]` lookups
(used by DJ's own engine) work. Worth a minimal repro + runtime session
eventually; the loader no longer depends on it either way.
