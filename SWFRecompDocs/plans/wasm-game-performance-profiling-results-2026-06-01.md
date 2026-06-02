# WASM Game Performance — Phase 1 Profiling Results (Doodle Jump)

**Date:** 2026-06-01
**Plan:** [wasm-game-performance-profiling-plan.md](wasm-game-performance-profiling-plan.md)
**Harness:** `SWFRecomp/scripts/profile_game_native.sh`

## What was run

```bash
# build + profile 500 frames, NO_GRAPHICS native, deterministic (MOCK_DATE_TIME seeded)
SWFRecomp/scripts/profile_game_native.sh local_batch/Doodle_Jump 500 no-graphics
```

- **Mode:** NO_GRAPHICS native (`swf_core.c`, rendering stubbed) — isolates the
  AVM1 interpreter + tag/queue/sprite cost from the renderer.
- **Build:** `gcc -O2 -g -fno-omit-frame-pointer`, `-DMAX_FRAMES=500`.
- **Tool:** `valgrind --tool=callgrind` → `callgrind_annotate`.
- **Uninstrumented baseline:** 500 frames in **0.44 s** (~0.9 ms/frame), 10 MB RSS.
- **Total instructions profiled:** 548,966,157 Ir over 500 frames.

## Headline finding: property-name lookup is ~⅔ of all work

| Function | Self Ir | % | Role |
|---|---:|---:|---|
| `object.c:prop_name_match` | 202.9M | **36.97%** | per-property name compare |
| `object.c:getProperty` | 78.9M | 14.36% | linear scan of `properties[]` |
| `object.c:findPropertyRaw` | 71.0M | 12.94% | linear scan of `properties[]` |
| `object.c:swf_name_match` | 8.8M | 1.59% | null-terminated name compare |
| `object.c:findPropertyStructWithPrototype` | 4.0M | 0.73% | proto-chain walk |
| `object.c:getPropertyWithPrototype` | 1.6M | 0.28% | proto-chain walk |
| **Property-lookup cluster** | **~367M** | **~67%** | |

Called *underneath* the cluster:
| Function | Self Ir | % |
|---|---:|---:|
| libc `__strncmp_avx2` | 23.2M | 4.23% |
| libc `__strcasecmp_avx2` | 17.2M | 3.13% |
| libc `__strcmp_avx2` | 10.1M | 1.84% |
| libc `__strlen_avx2` | 5.6M | 1.03% |
| **string-compare libc total** | **~56M** | **~10%** |

String (de)coding and allocation on the same path:
| Function | Self Ir | % |
|---|---:|---:|
| `action.c:utf8_to_u16` | 16.3M | 2.98% |
| `action.c:u16_to_utf8` | 12.2M | 2.23% |
| `action.c:utf8_decode_one` | 6.8M | 1.24% |
| libc `_int_malloc` + `malloc` | 12.5M | 2.29% |
| **UTF/alloc total** | **~48M** | **~9%** |

By contrast, the `child_mc_cache` / display-list scans I'd flagged from static
reading are minor here: `tag_stubs.c:ng_findDisplayEntryByName` is 0.95%,
`action.c:findOrCreateMovieClip` 0.27%. The real cost is **object property
resolution**, not movieclip-name resolution.

## Root cause

`getProperty` and `findPropertyRaw` (`object.c:284,263`) both do an **O(n) linear
scan** over `obj->properties[]`, calling `prop_name_match` (a string compare) for
every entry — on essentially every property get/set, multiplied by prototype-chain
depth. The code even carries the comment *"For production, consider hash table for
large objects."* (`object.c:298`).

`prop_name_match` itself takes the fast `strncmp` path for SWF ≥ 7 (Doodle Jump is
SWF 8), so 37% is pure **call volume**, not per-call cost. The libc `strcasecmp`
(3.1%) comes from the SWF ≤ 6 case-insensitive path used by other comparisons /
sub-objects.

## Why this matches the plan — and what to do

This is a direct confirmation of the plan's hypothesis and points at the two
optimizations already named (borrowable from upstream's architecture, **no merge
required**):

1. **String interning + integer-keyed property lookup.** Replace name strings
   with interned IDs so `prop_name_match` becomes an `int` compare, and back
   `properties[]` with a hash or sorted store so lookup is O(1)/O(log n) instead
   of O(n)·strcmp. This collapses the ~67% cluster *and* most of the ~10% libc
   string-compare cost. (Upstream uses enum string IDs + rbtree property storage —
   same idea.)
2. **Drop per-access UTF-8↔UTF-16 conversion + malloc.** ~9% of work is converting
   and allocating name strings on the property path; interning removes most of it
   (names travel as IDs, not freshly converted/allocated buffers).

Estimated upside: if interning + a real property map removes even half of the
combined ~86% spent in lookup/compare/convert/alloc, that is a large per-frame
CPU reduction — which, because the browser loop is frame-capped, shows up as
headroom (battery/CPU, heavy-frame smoothness, uncapped FPS) rather than a higher
capped FPS.

## Caveats / validity

- **NO_GRAPHICS, no input:** the game sits in its menu/attract loop, so some of
  the 549M is one-time init and the steady state is idle-ish. But property lookup
  is *fundamental* to AVM1 execution and only grows under real gameplay, so the
  finding is robust. Refinements below will sharpen it.
- Rendering is stubbed, so this profile says nothing about the renderer's share.

## Next refinements (Phase 1b)

1. **Input-driven profile** — feed an input script (`--input=FILE`) that starts
   and plays the game, so the profile reflects gameplay, not the menu loop.
2. **OFFSCREEN_RENDER profile** — `profile_game_native.sh local_batch/Doodle_Jump
   500 graphics` (Dawn present) to measure the renderer's share via the real
   `swf.c` loop.
3. **Second game** — profile one more title (e.g. Bloons) to check the
   property-lookup dominance generalizes.

Then proceed to Phase 3 optimization, starting with string interning / property
storage, re-running this harness after each change to quantify the win.

---

## Optimization #1 — hash-gated property lookup (2026-06-01)

**Change** (`object.c`, `object.h`): added a `u32 name_hash` to `ASProperty` (a
Unicode-case-folded FNV-1a of the name, with an ASCII fast path) and gated
`prop_name_match` in the 5 property-scan loops behind a `u32` hash compare. The
query name is hashed once per lookup; `prop_name_match` now runs only on hash
matches. The hash lives inside `ASProperty`, so `deleteProperty`'s
struct-copy compaction carries it for free — no parallel structure to keep
coherent. Behavior-preserving in both SWF version modes (the hash is only a
pre-filter; `prop_name_match` still confirms every match).

**Result (Doodle Jump, 500 frames, NO_GRAPHICS), program output byte-identical:**

| Metric | Before | After | Δ |
|---|---:|---:|---:|
| Total instructions | 548.97M | **355.72M** | **−35.2%** |
| `prop_name_match` | 202.9M (37.0%) | 3.8M (0.86%) | −98% |

The dominant `prop_name_match`/strcmp cost is essentially gone. Remaining top
costs are now:
- `getProperty` (17.6%) + `findPropertyRaw` (15.3%) — the **O(n) loop iteration**
  itself (still scans every entry to check its hash).
- `name_fold_hash` (15.9%) — the query name hashed **once per lookup**; the
  prototype-chain walkers (`getPropertyWithPrototype`,
  `findPropertyStructWithPrototype`) re-hash the same name at every chain level.

### Next increments (designed step 2)
1. **Hash once per access**: thread a precomputed query hash through the
   prototype-chain walkers (internal `findPropertyRawH`/`getPropertyH` taking a
   `qhash`), so the name is hashed once per access instead of once per proto
   level. Cuts most of the 15.9% `name_fold_hash`.
2. **Real property map**: back `properties[]` with a per-object hash index so
   lookup jumps to the entry instead of iterating, removing the ~33% in
   `getProperty`/`findPropertyRaw` iteration. (Delete compacts indices, so the
   index rebuilds on delete — deletes are rare.)

Estimated combined headroom after step 2: roughly another 40% off the current
total.

### CI validation (step 1)
Full suite, **both** no-graphics and graphics modes: **zero changes** across all 8
suites (avm1, from_shumway, from_shumway/avm1, from_gnash/{actionscript,
misc-ming, misc-swfc, misc-mtasc, misc-swfmill}.all). No pass→fail or fail→pass,
identical mismatched-line counts. Confirms behavior-preserving. (commits
`537951f4f` + result merges.)

---

## Optimization #2 — per-object hash index + hash-once-per-walk (2026-06-01)

**Change** (`object.c`, `object.h`):
1. Added a per-object open-addressing hash index (`hash_index`/`hash_capacity`
   on `ASObject`) mapping `name_fold_hash` → slot in `properties[]`. Built lazily
   once an object reaches `PROP_HASH_THRESHOLD` (12) properties — so small
   objects (the majority) are untouched and keep the gated linear scan; large
   objects (prototypes, `_global`) get O(1) lookup. All five property functions
   now route through one primitive, `findPropertySlot(obj, name, len, qhash)`,
   which probes the index when present and falls back to the gated scan
   otherwise. The index stores slot indices; array growth keeps them valid, and
   `deleteProperty`'s compaction rebuilds the index (deletes are rare). The one
   external site that reorders `properties[]` directly
   (`action.c:ensureBuiltinPrototypeProps`) calls the new `objectRehashIndex`.
2. Thread a precomputed query hash through the prototype-chain walkers
   (`getPropertyWithPrototype`, `findPropertyStructWithPrototype`) so the name is
   hashed **once per access** instead of once per chain level (also caches the
   `"__proto__"` hash per walk).

**Result (Doodle Jump, 500 frames, NO_GRAPHICS), output byte-identical:**

| Metric | Original | After #1 | After #2 | Δ total |
|---|---:|---:|---:|---:|
| Total instructions | 548.97M | 355.72M | **281.18M** | **−48.8%** |

The O(n) property-iteration cost (`getProperty`+`findPropertyRaw`, ~33%) is gone
— folded into `findPropertySlot` (14.5%, mostly the index probe + small-object
fallback). The new top costs are `name_fold_hash` (17.6%, the query hashed once
per lookup) and the UTF-8↔UTF-16 conversion on the stack↔property bridge
(`utf8_to_u16` 5.8% + `u16_to_utf8` 4.4% + `utf8_decode_one` 2.4% ≈ 12.6%).

### Next lever (step 3, larger change)
The remaining big structural cost is **string handling at the AVM1 stack level**:
member/variable opcodes pop a UTF-16 name off the stack, convert it to UTF-8 to
call `getProperty`, which then hashes it. Full **string interning** — names
travel as interned integer IDs on the stack with a precomputed hash — would
remove most of the ~12.6% conversion cost *and* the 17.6% re-hashing. This is the
big upstream-style change (their enum string IDs); it touches the stack value
representation and many opcodes, so it warrants its own plan + CI cycle.
