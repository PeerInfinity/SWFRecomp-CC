# Glaiel Reaction — nested motion-tween `_xscale`/`_x`/`_rotation` frozen (FIXED)

**Date:** 2026-06-20
**Game:** glaiel `Reaction` (126KB, AVM1/AS2 — Tyler Glaiel's chain-reaction game)
**Bucket:** headless-diagnosable (divergence harness, OFFSCREEN).
**CI-observable:** yes — shared `action.c` transform-read path (NO_GRAPHICS + OFFSCREEN).

## Symptom

`divergence_test.py "Reaction.swf" --frames 16` → first trace divergence at
filtered line 12:

```
ruffle:    F4 _root.instance5.instance6 ... _xs=32.1044921875 _ys=32.1044921875 ... _a=1.953125
swfrecomp: F4 _root.instance5.instance6 ... _xs=30.84716796875 _ys=30.84716796875 ... _a=1.953125
```

`instance5.instance6` is a nested sprite that Flash motion-tweens (scale grows
30.85% → 32.10% → 33.36% … each frame **and** alpha fades 0 → 1.95 → 3.51 …).
SWFRecomp tracked the **alpha** perfectly but **froze the scale** at the initial
30.847% across every frame. The parent `instance5._cf` advanced correctly (not a
playhead lag); only the child's matrix was frozen.

## Root cause

The recompiler correctly bakes the per-frame tween matrices (transform_ids
377/378/379 = scale 0.3210/0.3336/0.3461, confirmed in `draws.c`) and emits them
as per-frame `tagPlaceObject2` **modify** tags inside `sprite_31`'s frames. The
runtime modify path (`tag.c` `tagPlaceObject2`, `char_id==0`) **did** update
`display_list[depth].transform_id` and call `ng_cache_transform` on the nested
entry (verified by instrumentation: MODIFY fired with `tbs=0 cxov=0`).

The freeze was downstream, in **`syncTransformIfNeeded`** (`action.c`). The
`_xscale`/`_x`/`_rotation` getters read cached `mc->xscale`/`mc->x`/`mc->rotation`
fields. `syncTransformIfNeeded` refreshes those from the display entry located via
**`ng_findDisplayEntryByName(mc->name)` — which only scans the ROOT display
list**. For a clip nested in a parent sprite's sub-display-list, that lookup
returns `SIZE_MAX`, so the function returned early and the cached scale never
updated. Meanwhile `_alpha` reads via `mcReadAlpha`, which reads
`mc->display_obj` **directly** — so alpha stayed fresh. Exactly the
"scale frozen, alpha tracks" asymmetry.

## Fix

`action.c`: when `ng_findDisplayEntryByName` misses, fall back to
`syncTransformFromDisplayObj(mc)`, which decomposes `mc->xscale`/`yscale`/
`rotation`/`skew`/`x`/`y` from the linked display entry's cached
`place_a/b/c/d/tx/ty` fields (populated by `ng_cache_transform` at placement/
modify with the correct `g_active_transform_data` table). Mirrors `mcReadAlpha`'s
`mc->display_obj`-direct read. Guards:
- `obj == NULL` → no-op (name-lookup-created wrappers with no display link;
  unchanged behavior).
- all-zero `place_*` (never-cached, zero-init slot) → no-op (don't clobber with a
  degenerate scale-0 matrix).
- per-attribute `as_set_flags` honored (AS-set `_x`/`_xscale`/etc. not overwritten).
- `last_transform_id` change-guard (skip redundant work).

Root clips are unaffected (their name lookup succeeds → original path).

## Result

`Reaction` trace **identical (46/46)**. Remaining image diff at F1 is heavier red
URL text ("WWW.GAMESOFGONDOR.COM" / "WWW.GLAIELGAMES.COM") — font-weight/AA on the
small labels (cosmetic text-rendering class); title/loading-bar/layout all match.

Generalizes to **any motion-tweened nested clip** (very common in AS2 content) —
its scripted-read `_xscale`/`_x`/`_rotation` now track the timeline.

## Regression gate

```
python3 tools/divergence/divergence_test.py "$HOME/CC/glaiel/swfs/Reaction.swf" --frames 16 --skip-ruffle
# → Trace: identical (46/46)
```

Local trace tests verified pre-commit: getproperty, getproperty_swf5, nan_scale,
matrix, mouse_pos_with_scale_factor, sound_nested_clips, unload_nested_child (all pass).
</content>
</invoke>
