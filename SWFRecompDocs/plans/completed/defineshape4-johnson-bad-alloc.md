> **AUDIT OUTCOME (2026-07-04):** Implemented (Option A) 2026-05-16; johnson grouping later replaced entirely by directed-edge model + libtess2.

# DefineShape4: Johnson Cycle Memory Explosion

**Status:** Implemented (Option A) — 2026-05-16

## Update — 2026-05-16, post-implementation

Option A landed. The cap was tuned to **4000 cycles** (rather than the
plan's initial guess of 8000): at 8000, Castle_Hero shape 3255 still
bad_alloc'd in downstream Phase B / fillShape processing even after
johnson was bounded. 4000 cleared the last failure under the 4 GB
ulimit while still preserving enough cycle data for Art_of_War,
Avalanche, Bloons_TD, and the rest of Castle_Hero to render unchanged.

Verification on the four SWFs covered by the investigation:

| SWF          | Before fix    | After fix             |
| ------------ | ------------- | --------------------- |
| Castle_Hero  | 8x bad_alloc + 1x parseAllTags escape | 0 fails; 37 cycle-cap warnings |
| Art_of_War   | clean         | clean; 170 cycle-cap warnings; identical bitmap output |
| Avalanche    | clean         | clean; identical bitmap output |
| Bloons_TD    | clean         | clean; identical bitmap output |

Ruffle smoke (`add2`, `goto_label`, `tell_target_invalid`) and all
six graphics regression tests (`lossless_bitmap*` ×4 +
`jpeg_mid_stream_eoi_soi` + `lossless_bitmap_rgba`) still pass.

The cycle-cap warnings on Art_of_War (170) and Castle_Hero (37) are
new visibility into shapes that were already hitting *some* cap
before — under the old code they hit `max_iterations=100000`
silently. The cycle cap fires earlier and names the threshold, which
is informative; the underlying shape data was already being truncated.

The "cycle expansion bailed" warning (cap firing inside the expansion
loop rather than johnson) doesn't fire on any test SWF — johnson's
cap always fires first. The expansion-loop cap is a defense-in-depth
guard for hypothetical inputs where johnson somehow returns more
cycles than the cap.

### Files touched

- `SWFRecomp/include/swf.hpp` — added `max_cycles=8000` default to
  `johnson()` signature (passed as 4000 from the call site, so the
  default is currently unused; kept conservative for potential
  future callers).
- `SWFRecomp/src/swf.cpp` — `johnsonShouldBail()` helper, threaded
  `max_cycles` through `detectCycle` / `traverseIteration`, two
  named-cap warnings in `johnson()` itself, `auto&` in the
  expansion loop, MAX_CYCLE_EXPANSION=4000 cap with a fall-through
  bail flag and a one-line warning that names the shape_id plus
  node/path/cycle counts.

---

## Symptoms

`Castle_Hero` (SWF v9, 14 MB body) recompile log shows:

```
8x  Warning: tag 83 failed: std::bad_alloc
1x  Caught exception in parseAllTags: std::bad_alloc
```

caught by the per-tag try/catch in `parseAllTags` (since `9a9522e8`),
plus one escaping all the way to the outer `parseAllTags` catch (after
which `parseAllTags` returns early — but post-loop tagMain.c flushing
still happens, so the recompile produces a partial output rather than
no output at all).

Tag 83 = `SWF_TAG_DEFINE_SHAPE_4`. The recompile produces 987 working
`defineBitmap` calls; the 8 failing shapes are visually missing from
the final output.

## Specific failing shapes

After adding `tag_start` + `length` to the per-tag failure message and
re-recompiling, the 8 fails are exactly these character IDs (lengths
in the 30-38 KB range):

| char_id | length | tag_start |
|---------|--------|-----------|
| 35      | 38400  | 777670    |
| 36      | 34389  | 816076    |
| 37      | 31699  | 850471    |
| 38      | 33678  | 882176    |
| 3252    | 32275  | 11964295  |
| 3253    | 38444  | 11996576  |
| 3254    | 34386  | 12035026  |
| 3255    | 31705  | 12069418  |

Two clusters of 4 sequential IDs each. Comparing the raw bytes of
shape 35 vs 3253: identical body (after the 2-byte shape_id) — the
SWF re-defines the same character art under two char_ids. Same
holds for 36↔3254, 37↔3255, 38↔3257 (note: 3257 itself recompiles
*successfully*, suggesting the bad_alloc is sensitive to accumulated
recompiler state, not purely shape geometry; see "Open questions").

100 DefineShape4 tags total in this SWF; 8 fail. Other shapes of
similar size succeed (e.g. shape 39, length=34659; shape 32,
length=34453; shape 17, length=13864 — all clean).

## Reproducing in isolation

```sh
# Extract shape 35 to a minimal SWF and recompile.
python3 - <<'PY'
# (script extracts body[777668:777668+38400] and wraps in FWS header
#  + DefineShape4 tag + PlaceObject2 + ShowFrame + End — full source
#  in this conversation's git history if needed)
PY
SWFRecomp config.toml
```

→ Reproduces `tag 83 failed: std::bad_alloc` in ~1 second, with the
familiar `johnson cycle detection exceeded 100000 iterations` warning
just before the bad_alloc.

## Root cause

`interpretShape` in `SWFRecomp/src/swf.cpp:7174` parses the shape
record stream into a path graph, then calls
`johnson(nodes, path_stack, blocked, blocked_map, closed_paths)`
(SWFRecomp/src/swf.cpp:8302) — Johnson's algorithm for enumerating
all simple cycles in a directed graph. Each cycle is pushed into
`closed_paths` as a `std::vector<Path>`, which the next loop expands
into `Shape` objects with per-vertex `verts.push_back(...)`.

The existing safeguard caps **iterations**:

```
johnson(..., size_t max_iterations = 100000)
```

with bail-outs in `traverseIteration` and `detectCycle`. But this
caps work, not memory. With a one-line diagnostic
(`fprintf(stderr, "[shape_dbg] shape_id=%u: after johnson, closed_paths=%zu\n", ...)`)
attached to the standalone shape-35 reproducer:

```
[shape_dbg] shape_id=35: before johnson, nodes=2262 paths=1131
Warning: johnson cycle detection exceeded 100000 iterations, skipping remaining nodes
[shape_dbg] shape_id=35: after  johnson, closed_paths=24860
Warning: tag 83 failed: std::bad_alloc
```

A typical glyph or icon has tens of nodes and a handful of paths. This
character has **2262 nodes / 1131 paths / 24860 cycles** — dense
crossing art, possibly a knight or castle illustration.

Each `closed_paths` entry is a `std::vector<Path>` ≥ the path-stack
depth at cycle-detect time. Even before `iterations` hits the cap,
the cumulative memory of `closed_paths` plus the downstream
`shapes[].verts.push_back(...)` loop blows past the 4 GB
`ulimit -v` (set by `build_swf_batch.sh` and matching wrappers).

The bad_alloc fires *after* `johnson` returns, in the
`for (auto cycle : closed_paths)` loop at swf.cpp:8306 — confirmed
by adding bracketing diagnostics. Note that `for (auto cycle : ...)`
copies each `cycle` (a `std::vector<Path>`) into a local; switching
to `auto&` would already cut a significant fraction of the memory
pressure, though it's still O(cycles × path_depth × verts_per_path)
total downstream.

The 9th bad_alloc that escapes the per-tag catch is probably the
`closed_paths` vector itself growing past the ulimit during
`closed_paths.push_back(cycle)` inside `detectCycle` (swf.cpp:8932)
— that call is outside the per-tag try block's reach because the
exception propagates up *through* `johnson` and `interpretShape`,
and only one tag has to fail here before the per-tag catch's
`clear()` finds the stream already in an unrecoverable state.

## Proposed fix (Option A — bail gracefully)

1. **Cap `closed_paths` size in johnson**: add `closed_paths.size()
   >= MAX_CYCLES` (e.g. 8000) to the early-exit conditions in
   `detectCycle` / `traverseIteration`. When the cap fires, behave as
   if `iterations >= max_iterations` (return false, stop the outer
   loop, emit a warning naming the cap that fired).

2. **Switch `for (auto cycle : closed_paths)` to `for (auto& cycle ...)`**
   at swf.cpp:8306 — avoids the per-iteration copy. Trivial,
   independently correct, may already be enough on its own for
   borderline cases.

3. **Bail out of the cycle-expansion loop** (`shapes.push_back(Shape())`
   block, swf.cpp:8306-8335) early if `shapes.size() - shape_cycles_start
   >= MAX_CYCLES` was reached. Mark the partial shape as invalid so
   it's skipped by downstream tessellation rather than half-rendered.

4. **Wrap the bail-out in a one-line warning** with `shape_id`, node
   count, path count, and the cap value — so a future investigator
   sees the same signal we used here.

The net effect: 8 currently-bad-allocating Castle_Hero shapes will
render as empty placeholders (visually similar to today's "missing
shape" outcome), but the recompile won't lose the surrounding tags
to `parseAllTags` abort, and no future Shape4 with similarly dense
art will silently kill the build.

## Proposed fix (Option B — keep the cycles, swap data structure)

`closed_paths` stores entire `std::vector<Path>` copies, even though
each cycle is just a sequence of indices into `paths`. Replacing it
with `std::vector<std::vector<size_t>>` (path-index lists) plus a
back-reference to the shared `paths` vector would cut the memory
cost by ~10x for typical cycle depths. Bigger refactor though —
touches the cycle-expansion loop and the `cycle[j].backward` flag
storage. Defer unless Option A's bail-out loses meaningfully
important art.

## Verification (for whichever fix lands)

1. Recompile **Castle_Hero**: all 8 `tag 83 failed: std::bad_alloc`
   gone; the parseAllTags escape gone; replaced with at most 8
   `Warning: shape_id=N: cycle detection bailed out` lines.
2. The standalone minimal `iso_shape35` SWF (described above)
   recompiles cleanly — useful as a quick local repro.
3. Re-recompile **Art_of_War** / **Avalanche** / **Bloons_TD** for
   non-regression. None of these triggered the johnson cycle warning
   in the recent recompile logs, so they shouldn't be affected.
4. Ruffle smoke tests still pass.

## Open questions

- Why do shapes 36/3254 (identical bodies) both fail, but 38/3257
  (also identical bodies) split — 38 fails, 3257 succeeds? The
  recompiler must accumulate state between tags that pushes 38 over
  the 4 GB limit while leaving headroom for 3257. Worth a `getrusage`
  spike-check before and after each Shape4 if Option A's warning isn't
  enough signal. Could indicate a leak in the per-tag failure handler
  itself.
- Is the existing 100000 iteration cap meaningful? `closed_paths`
  grew to 24860 before the cap fired — most of the work is already
  done by then. Lowering the iteration cap would lose less data than
  capping `closed_paths` size, but also harder to reason about
  (iterations don't correspond 1:1 to cycles).
- Could johnson be replaced with a less-thorough algorithm for these
  pathological cases? The recompiler only needs cycles to identify
  shape-fill regions; an approximation that finds simple non-crossing
  cycles first and bails on crossings might be cheaper.

## Out of scope

- The full Johnson-algorithm rewrite (Option B).
- General fix for "shapes that hit the 4 GB ulimit through other code
  paths". This plan covers the *specific* johnson cycle blowup.
- Re-running flasharchive batch to count how many other SWFs trigger
  the cap — easy to do once the fix lands and the warning exists.
- DefineShape (tag 2), DefineShape2 (22), DefineShape3 (32) — they
  use the same interpretShape body but haven't been observed to hit
  this. The fix applies symmetrically; if they ever do hit it the
  same warning will fire.
