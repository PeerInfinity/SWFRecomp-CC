# 2026-05-26 — Doodle Jump browser-WASM, info-label cleanup (Replace path)

Eighth handoff in the Doodle Jump browser-WASM debugging chain:

1. `2026-05-25-doodle-jump-browser-investigation.md` — initial
   investigation + cycling-bug diagnosis.
2. `2026-05-25-doodle-jump-followup.md` — cycling fix (`98b388e46`).
3. `2026-05-25-doodle-jump-clip-events.md` — clip-event LOAD/ENTER_FRAME
   dispatch (`3ac27552e`).
4. `2026-05-25-doodle-jump-audit.md` — 22-gate audit (`c9b11cc99`).
5. `2026-05-25-doodle-jump-bounce-fix.md` — 6 more gates for AS-side
   bounds/hitTest (`68889f5ed`).
6. `2026-05-26-doodle-jump-buttons-clickable.md` — buttons clickable
   (`92606558b` + cursor follow-up `7e9b53a6a`).
7. `2026-05-26-doodle-jump-orphan-text-cleanup.md` — descendant MC
   invalidation on sprite removal/replace (`c2147d58e`).
8. **This doc** — invalidate descendants on
   `tagReplaceObject2RatioWithClipActions` (`bd9e830a9`).

**Branch state at writing:** `master`, ahead of `origin/master` by 7
commits (`92606558b`, `48ae5cf16`, `7e9b53a6a`, `cf5b61b16`,
`c2147d58e`, `abe35fad0`, `bd9e830a9`). Working tree clean. Push when
ready.

## TL;DR

- **Fixed (`bd9e830a9`):** The "info" leftover label after the Doodle
  Jump menu→gameplay click is gone. The depth-7 transition that the
  prior handoff couldn't trace turned out to come from
  `tagReplaceObject2RatioWithClipActions` (recompiler-collapsed
  Remove+Place at the same depth/char_id) — its `#else` branch had no
  invalidation hook in browser-WASM.
- **Not fixed (but better understood):** The
  unbounded-MC-growth issue noted in the prior handoff is real but
  the prior root-cause hypothesis was wrong. Detail in "Open items".
- **No regressions:** trace harness 407=407, Pong md5
  `bb1f52f690672bd558f6e5c6b1c64301`, Snake t02..t06 md5
  `a213fc90328ab539f9c9e7288670d498`, DJ menu bouncing
  (`unique_canvas_sizes=8`, `display_list_counts` stable at 9),
  cursor changes on hover (pointer / default).

## What landed

### `tagReplaceObject2RatioWithClipActions` browser-WASM invalidation
(tag.c ~6443)

The function had a `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)`
block that invalidates the old MC via `actionInvalidateCachedMovieClip`
(name+depth) before calling `tagPlaceObject2Ratio(..., is_replace=1)`.
The corresponding `#else` branch was empty.

Added one call to `invalidate_mc_for_dl_entry(app_context,
&display_list[depth])` in `#else` — same helper used by the prior
session's `tagRemoveObject2` / `tagPlaceObject2` hooks. Pointer-based
descendant invalidation, matching the previous handoff's
"depth+name is ambiguous in DJ" rationale verbatim.

### Why diagnostics weren't needed this session

The prior handoff said "Where depth 7's slot is cleared between menu
and gameplay is the unanswered question." The answer was sitting in
the recompiler-emitted timeline — frame_1 in
`SWFRecomp/tests/flasharchive/Doodle_Jump/RecompiledTags/tagMain.c:78`:

```c
tagReplaceObject2RatioWithClipActions(app_context, 7, 46, 63, 44, 0, 1,
    clip_actions_147, 2, clip_actions_168, 2);
```

The slot wasn't being cleared by an unknown path — it was being
*replaced* (same char_id 46) by a tag whose browser-WASM branch did
nothing about invalidation. Reading the SWF's recompiled tag list
pinpointed the culprit before any probe ran. Saved a probe
round-trip — keep this approach in mind for similar future bugs.

## Diagnosis that worked

1. Read `RecompiledTags/tagMain.c` from the start to understand the
   exact tag sequence per frame. DJ's menu is frame 0 (placements
   only), gameplay starts at frame 1 (RemoveObject2 + Place per
   depth, *except* depth 7 which uses
   `tagReplaceObject2RatioWithClipActions`).
2. Grep `tagReplaceObject2` in libswf's tag.c. One definition. Inside,
   a `#if NO_GRAPHICS || OFFSCREEN_RENDER` block does the invalidation
   work. The `#else` is empty.
3. Compare to the previously-fixed `tagPlaceObject2` (which has the
   same shape: NO_GRAPHICS branch was the original implementation;
   browser-WASM `#else` got an invalidation hook in `c2147d58e`).
4. Pattern match — write the same `#else` hook.

## Open items

### 1. Unbounded MC accumulation during gameplay — real, different root cause

Instrumented `findOrCreateMovieClip`'s cache-insert site to dump each
new MC's name/parent/depth, and the swf.c tick boundary to track
`child_mc_count`. Across 135 ticks (4 s probe) of DJ gameplay:

```
Total new MC cache additions: 92
  'container'     : 27   (SWF depth 2, ratio placement, char 25)
  'instanceN'     : 28   (SWF depth 7, anon — Replace 7/46 with no setInstanceName)
  ... mix of 'button_txt', 'hero', 'block', 'instanceN' ...
```

Menu phase (cur=0): cache stays at 10 entries. Stable.
Gameplay phase (cur=1): cache grows ~1-2 entries per tick, capping at
MAX_CHILD_MOVIECLIPS=128.

**Root cause (different from prior handoff's hypothesis):** in
browser-WASM, `swf.c` runs `frame_funcs[current_frame]` every tick,
even when `is_playing=0` and `manual_next_frame=0`. The
OFFSCREEN_RENDER branch at `swf.c:615-619` gates this:

```c
if (current_frame < g_frame_count && frame_funcs[current_frame] != NULL
#ifdef OFFSCREEN_RENDER
    && (is_playing || manual_next_frame)
#endif
    )
```

The gate is missing in browser-WASM. So during DJ gameplay (which
stops on frame_1), frame_1 re-runs every tick, issuing
`tagRemoveObject2(2) + tagPlaceObject2Ratio(2, 25)` and
`tagReplaceObject2RatioWithClipActions(7, 46)` each time. The
RemoveObject2 invalidates the existing "container" MC; the subsequent
PlaceObject2Ratio creates a *fresh* one.

`tagPlaceObject2` has a "same char, same depth, different generation
→ modify" gate at lines 5501-5517 that prevents this for non-Ratio
re-placements (which is why menu's frame_0 doesn't leak — char 50, 51,
46 at depths 1, 2, 3, 5, 7, 8 get the modify path on each re-run).
`tagPlaceObject2Ratio` has no equivalent gate, and it wouldn't fire
anyway because the RemoveObject2 cleared `char_id` to 0 right before.

Why the prior handoff's hypothesis was wrong: it said "score_txt's
parent display entry is being re-initialized each tick without going
through tagRemoveObject2." In fact `tagRemoveObject2` *does* fire
(repeatedly, because frame_1 re-runs), and it *does* invalidate
correctly — what creates the leak is that the subsequent re-place
creates a brand new MC each cycle. Identical pattern, not what the
handoff said.

**Why deferring this is reasonable for now:**

- Two reasonable fixes, neither is risk-free:
  - **Architectural fix (right answer):** drop the `#ifdef
    OFFSCREEN_RENDER` around the `is_playing || manual_next_frame`
    gate so browser-WASM stops re-running stopped frames.
    Flash-accurate. But the current behavior has been the status quo
    in browser-WASM since the file existed; tests that pass may be
    depending on the re-run side-effects (e.g. setInstanceName
    re-applying every tick, queued scripts re-queuing, etc.). Needs
    a deliberate audit + careful per-test verification — too risky
    for end-of-session.
  - **Localized workaround:** add a `tagPlaceObject2Ratio`
    same-char/same-depth modify gate analogous to
    `tagPlaceObject2`'s 5501-5517. Would catch the "info" replace's
    secondary effect (so the depth-7 leak is also fixed), but
    `tagRemoveObject2(2)` clears char_id=0 before
    `tagPlaceObject2Ratio(2, 25)` runs, so the "container" leak path
    is unreachable from that gate. Half-fix only.

- Not user-visible until the cache fills, which takes ~6 s of
  continuous gameplay at 30 fps before silent drops begin.

- I removed all diagnostics before commit (per session convention).

If you want to try the architectural fix next session, the one-line
edit is the `#ifdef OFFSCREEN_RENDER` ... `#endif` removal at swf.c
615/619. Run the full regression set (trace, Pong, Snake, DJ menu,
DJ click→gameplay) after; if Pong/Snake regress, the per-tick
script-queuing inside their frame_0 is the most likely culprit.

### 2. "score_txt" specifically is no longer accumulating

The prior handoff said `score_txt` accumulates at ~3 per tick. With
the depth-7 fix in place, the cache trace shows only ONE `score_txt`
entry across 135 ticks of gameplay. The 27 "container" and 28
"instanceN" entries reflect the actual leak shape now. The prior
session's "3/tick score_txt" was probably a mix of all anon/named
MCs that hashed under the same instrumentation; my finer-grained
trace (printing per-name) clarifies this.

### 3. Hero physics in gameplay — still unverified

Inherited from prior handoff. Hero is at y=465.5 (mostly off-canvas).
Not addressed this session.

## Don't-touch list (cumulative)

Inherited from prior handoffs, plus:

- The `tagReplaceObject2RatioWithClipActions` `#else` branch's
  invalidation hook fires BEFORE `tagPlaceObject2Ratio`. Don't move
  it after — `tagPlaceObject2Ratio` will have already overwritten
  `display_list[depth]` fields, and `invalidate_mc_for_dl_entry`
  uses `display_obj` pointer equality on the OLD entry.
- If you add a `tagPlaceObject2Ratio` modify-detect gate analogous to
  `tagPlaceObject2`'s 5501-5517 for the architectural-fix-avoidance
  workaround, gate it on `display_list[depth].ratio == ratio` in
  addition to char_id (Ratio placements with different `ratio` are
  genuine modifications and shouldn't be skipped — see Ruffle
  `survives_rewind` logic referenced in tag.c:5290-5294).

## Pattern note (8th instance)

This was the 8th in a row where the bug was a missing browser-WASM
`#else` branch next to an existing graphics-native implementation.
The pattern: graphics-native got a feature first, browser-WASM was
left with an empty `#else` (or no `#else` at all) when the original
author assumed "the recompiler-emitted call path doesn't apply
here." Each handoff reveals one more case.

Counting strategy that finally worked this session: read the
recompiler-emitted *consumer* (RecompiledTags/tagMain.c per frame),
not the runtime's tag definitions. The consumer tells you exactly
which tag function gets called; the runtime tells you what each one
does. Crossing both views pinpoints missing `#else` branches in O(1)
rather than the O(N) "instrument all candidates" approach.

## Tools / state

- Local Ruffle source: `~/CC/ruffle`
- MTASC: `~/CC/mtasc/bin/mtasc`
- Probe venv: `/tmp/pong-probe/venv`
- Latest known-good probes:
  - DJ post-fix (this session): `/tmp/dj-eighth-final/`
  - Pong regression: `/tmp/pong-reg-eighth/`
  - Snake regression: `/tmp/snake-reg-eighth/`
  - DJ menu bouncing: `/tmp/dj-bounce-eighth/`

Branch `master` is 7 commits ahead of `origin/master`:
- `92606558b` browser-WASM: wire CLIP_EVENT_PRESS/RELEASE/ROLL dispatch
- `48ae5cf16` docs: Doodle Jump browser-WASM buttons-clickable handoff
- `7e9b53a6a` browser-WASM: set MovieClip.display_obj in
  ng_update_button_states_in_dl
- `cf5b61b16` docs: update DJ handoff with cursor follow-up
- `c2147d58e` browser-WASM: invalidate descendants on sprite
  removal/replace
- `abe35fad0` docs: Doodle Jump browser-WASM orphan-text-cleanup handoff
- `bd9e830a9` browser-WASM: invalidate descendants on
  tagReplaceObject2RatioWithClipActions

Push when ready.
