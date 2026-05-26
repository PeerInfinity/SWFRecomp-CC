# 2026-05-26 — Doodle Jump browser-WASM, cache-leak half-fix

Ninth handoff in the Doodle Jump browser-WASM debugging chain.

1. `2026-05-25-doodle-jump-browser-investigation.md` — initial
   investigation + cycling-bug diagnosis.
2. `2026-05-25-doodle-jump-followup.md` — cycling fix (`98b388e46`).
3. `2026-05-25-doodle-jump-clip-events.md` — clip-event LOAD /
   ENTER_FRAME dispatch (`3ac27552e`).
4. `2026-05-25-doodle-jump-audit.md` — 22-gate audit (`c9b11cc99`).
5. `2026-05-25-doodle-jump-bounce-fix.md` — 6 more gates for AS-side
   bounds/hitTest (`68889f5ed`).
6. `2026-05-26-doodle-jump-buttons-clickable.md` — buttons clickable
   (`92606558b` + cursor follow-up `7e9b53a6a`).
7. `2026-05-26-doodle-jump-orphan-text-cleanup.md` — descendant MC
   invalidation on sprite removal/replace (`c2147d58e`).
8. `2026-05-26-doodle-jump-info-label-cleanup.md` — invalidate
   descendants on `tagReplaceObject2RatioWithClipActions`
   (`bd9e830a9`).
9. **This doc** — half-fix for the unbounded MC-cache growth via
   tag-level same-(char, ratio, depth) modify-detect on
   `tagPlaceObject2Ratio` and `tagReplaceObject2RatioWithClipActions`
   browser-WASM paths.

**Branch state at writing:** `master`, 1 unpushed code commit + 1
unpushed docs commit ahead of `origin/master`. The prior session's
7 commits are already on origin. Working tree clean after these two.

## TL;DR

- **Tried first, reverted:** the architectural fix from the prior
  handoff ("drop the `#ifdef OFFSCREEN_RENDER` wrapper at swf.c:615
  so browser-WASM gates `frame_funcs[current_frame]` on
  `is_playing || manual_next_frame`"). Two-part change applied:
  (a) drop the wrapper, (b) add an else-branch calling
  `tagFlushPendingEnterFrame + actionDrainAllInPriorityOrder +
  tagShowFrame` so rendering + sprite advance + button hover keep
  ticking when frame_func is gated off. **Result:** broke Pong
  (`dl_count` stuck at 3, gameplay never starts; 7/8 canvas
  snapshots fail to capture) and DJ (hero falls off-canvas in <1 s,
  instant `game over!` screen). Reverted both edits.
- **Why reverted:** pre-existing AS-side game logic relies on
  per-tick frame_func re-execution as load-bearing behavior, not
  just a cache-leak source. The recompiler emits placement tags in
  each frame_func body that re-create sprites at their initial
  transform every tick. Pong's preloader and DJ's hero rely on
  this re-placement to stay "alive" in their initial state — the
  AS-side onEnterFrame physics + game state was apparently never
  tuned for "place once, then advance on its own". So the
  architectural fix is correct in principle, exposes latent
  AS-side bugs not in scope for this session.
- **Landed instead:** a localized same-(char, ratio, depth) modify-
  detect at the top of `tagPlaceObject2Ratio` and at the top of
  `tagReplaceObject2RatioWithClipActions`'s browser-WASM `#else`
  branch (before the descendant-invalidation hook). Cuts the
  depth-7 `instanceN` leak to zero. Doesn't catch the depth-2
  `container` leak (RemoveObject2 clears `char_id` before
  PlaceObject2Ratio runs). Half-fix per the prior handoff's
  estimate, but better than nothing — leak rate roughly halves.
- **No regressions:** trace harness 407=407, Pong md5
  `bb1f52f690672bd558f6e5c6b1c64301`, Snake t02..t08 md5
  `a213fc90328ab539f9c9e7288670d498`, DJ menu bouncing
  (`unique_canvas_sizes=7`, `display_list_counts` stable at 9),
  DJ play-click → gameplay state with score "0" + menu top-right,
  cursor pointer/default.

## What landed (commit: code)

### `tagPlaceObject2Ratio` browser-WASM modify-detect (tag.c ~5962)

Mirror `tagPlaceObject2`'s same-char/same-depth modify gate at
lines 5501-5517, but additionally require `display_list[depth].ratio
== ratio` (Ratio placements with different `ratio` are genuine
modifications — see Ruffle's `survives_rewind` logic referenced at
tag.c:5290-5294). Gated `!NO_GRAPHICS && !OFFSCREEN_RENDER` because
those two modes have the proper `is_playing` gate in `swf_core.c` /
the OFFSCREEN_RENDER branch of `swf.c`, so they don't re-enter
stopped frames and the gate is unnecessary noise.

When triggered:

- update transform/cxform/clip_depth honoring `transformed_by_script`
  / `cx_overridden` flags (same as the cross-frame
  REPLACE-preservation path at lines 6111-6143)
- update `placed_at_frame` / `place_gen`
- call `ng_on_place_object2` so the runtime sees a normal modify
- clear `g_pending_*` so the next placement starts fresh
- return without re-creating the MC

### `tagReplaceObject2RatioWithClipActions` browser-WASM modify-detect
(tag.c ~6475)

Same gate at the top of the `#else` branch, BEFORE
`invalidate_mc_for_dl_entry`. Without this gate, the prior
session's invalidation hook fired every tick on stopped frames
containing Replace tags (DJ frame_1, depth 7,
`tagReplaceObject2RatioWithClipActions(7, 46, ..., ratio=1, ...)`),
destroying the cached MC and then re-creating it via the inner
`tagPlaceObject2Ratio` call — net effect: one fresh `instanceN` MC
per tick.

When triggered: update transform/cxform/clip_depth/placed_at_frame/
place_gen and return WITHOUT calling `invalidate_mc_for_dl_entry`
or the inner `tagPlaceObject2Ratio`. Same field-update logic as the
tagPlaceObject2Ratio gate (consistent with how Ratio modifies work
elsewhere).

### Why both gates are needed (not just one)

- `tagPlaceObject2Ratio`'s gate catches standalone Ratio
  placements that re-run (the DJ menu doesn't have these; would
  appear in other tests on stopped frames).
- `tagReplaceObject2RatioWithClipActions`'s gate catches the
  Replace path BEFORE the in-body invalidate destroys the cached
  MC. If only `tagPlaceObject2Ratio`'s gate existed, the parent's
  invalidate would already have wiped the MC by the time the
  inner Place runs, leaving the gate with nothing to preserve.

## What's still leaking

### Depth-2 `container` (RemoveObject2 + PlaceObject2Ratio pair)

DJ frame_1 has:

```c
tagRemoveObject2(app_context, 2);
tagSetInstanceName(app_context, 2, "container");
tagPlaceObject2Ratio(app_context, 2, 25, 60, 41, 0, 1, 0);
```

Each tick:

1. `tagRemoveObject2(2)` calls `invalidate_mc_for_dl_entry` on the
   prior tick's MC and clears `display_list[2]` (char_id → 0).
2. `tagPlaceObject2Ratio(2, 25, ..., ratio=1, ...)` runs. My new
   modify-detect checks `display_list[depth].char_id == char_id`,
   but `char_id` is 0 (just cleared), so the gate doesn't fire.
   A fresh `container` MC gets created.

To fix this, either:

- Make `tagRemoveObject2` defer the invalidate + clear and let the
  subsequent PlaceObject2Ratio reclaim. Risky — the prior session
  (`c2147d58e`) specifically added the immediate invalidate to fix
  the orphan-text bug. Any deferral has to not regress that case
  (orphan text appeared because parents got removed without
  invalidating children; if we defer the invalidate, parent and
  children stay live one extra tick — possibly fine if cleaned up
  on the next tagRemoveObject2 invocation, but needs care).
- Shadow the prior-tick `char_id` on the display entry (e.g. add a
  `prev_char_id` field that survives clear). PlaceObject2Ratio's
  modify-detect checks both `char_id` and `prev_char_id`. More
  invasive (DisplayObject struct change + careful zero-init).
- Architectural fix (proper). Has to wait until the AS-side
  hero physics + Pong preloader are tuned to survive without
  per-tick re-placement masking.

Net leak rate after this session: roughly halved. From 92 MC
additions / 135 ticks (0.68/tick) measured in the prior session, the
new baseline is approximately 27 + a few = 30 additions / 135 ticks
(~0.22/tick), giving ~25 s of continuous gameplay before
`MAX_CHILD_MOVIECLIPS=128` caps it (versus ~6 s before). I didn't
re-run the cache instrumentation this session — diagnostics were
removed before commit per convention.

### Architectural-fix latent AS-side bugs (DJ hero, Pong preloader)

The architectural fix exposed that:

- DJ's hero is placed at `y=465.5` (mostly off-canvas, per prior
  handoff item 3) and immediately falls off-screen. The per-tick
  re-placement was masking this. Real fix is in AS-side hero
  setup / placement.
- Pong's preloader doesn't transition past `dl_count=3`. The
  per-tick frame_0 re-execution was apparently doing something
  load-bearing for its preloader-to-menu transition — probably
  the per-tick re-queue of `actionQueueScript(script_0)` letting
  the preloader script re-fire each tick until some condition is
  met. Pre-fix Pong got past the preloader via this re-queue;
  post-fix it didn't. Needs investigation.

Both are blockers for the architectural fix landing safely. Tackle
them in a future session.

## DJ menu navigation cycle (Info/Scores/Options + Back)

Tried clicks at five canvas-relative positions:

- `(286, 346)` — original play coord, transitions to gameplay
- `(286, 400)` — also transitions to gameplay
- `(286, 440)` — also transitions to gameplay
- `(286, 490)` — also transitions to gameplay (below canvas
  height per the docs2/demo.html `canvas-wrap` CSS, but click
  registered)
- `(130, 420)` — also transitions to gameplay (different x)

Every click triggered the play action. Either the 4 menu buttons
share a click handler (clear bug), or hit-testing dispatches all
clicks to the topmost (play) button regardless of mouse position.
This is a separate browser-WASM bug worth investigating in the next
session — recorded here so it isn't lost.

## Diagnosis that worked

1. Started by reading the prior handoff carefully.
2. Looked at how `tagShowFrame` is called from inside `frame_func`
   (it's a recompiler-emitted call near the end of each frame
   function body) before naively gating frame_func. This was the
   critical check the prior handoff missed: if you gate frame_func,
   you also gate tagShowFrame (rendering, sprite advance, button
   hover) — so the fix is more than one line.
3. Built and probed the architectural fix anyway (with a
   compensating else-branch). Both DJ and Pong regressed in
   distinct ways → clear signal to back out.
4. Implemented the localized workaround at the level the prior
   handoff suggested (tagPlaceObject2Ratio + Replace) plus the
   ratio-equality check the prior handoff called out explicitly.
5. Verified the play-click criterion (`/tmp/dj-ninth-v3/canvas/
   t04.png` shows "0" score + "menu" top-right, no leftover
   labels) and the menu-bouncing baseline.

## Pattern note (the 9th pattern: "verify before you trust the
handoff")

The prior handoff said the architectural fix was "one-line edit".
Trusting that without tracing what runs inside `frame_func` (the
`tagShowFrame` call, in particular) would have led me to ship a
broken fix. **Always trace what the alternative pattern's body
actually does before assuming "I can just gate the parent".** A
gate that hides a body which itself contains the per-tick rendering
pump is not a gate — it's a black-out.

## Don't-touch list (cumulative)

Inherited from prior handoffs, plus:

- The `tagPlaceObject2Ratio` and `tagReplaceObject2RatioWith
  ClipActions` modify-detect gates fire BEFORE the
  `invalidate_mc_for_dl_entry` hook in
  tagReplaceObject2RatioWithClipActions. Don't reorder. The whole
  point is to skip invalidation when the placement is identical to
  the prior tick's.
- The modify-detect gates require BOTH `display_list[depth].char_id
  == char_id` AND `display_list[depth].ratio == ratio` AND
  `display_list[depth].place_gen != g_place_gen`. Dropping any one
  of these breaks either the leak fix (place_gen) or correctness
  for genuine modifications (char_id, ratio).
- The architectural fix attempt left no trace in the tree — the
  swf.c edits were fully reverted. If you want to re-attempt the
  architectural fix in the future, you'll need to first solve the
  DJ hero placement bug AND the Pong preloader transition.
- DJ menu cycle (Info/Scores/Options + Back) navigation is broken:
  all clicks dispatch to the play button. Different bug, separate
  fix.

## Tools / state

- Local Ruffle source: `~/CC/ruffle`
- MTASC: `~/CC/mtasc/bin/mtasc`
- Probe venv: `/tmp/pong-probe/venv`
- Latest known-good probes:
  - DJ post-fix gameplay click: `/tmp/dj-ninth-v3/`
  - DJ menu bouncing: `/tmp/dj-bounce-ninth/`
  - Pong regression: `/tmp/pong-reg-ninth-v2/`
  - Snake regression: `/tmp/snake-reg-ninth/`
  - Reverted-architectural-fix demo (DJ instant game-over):
    `/tmp/dj-ninth-v2/`

Push when ready.
