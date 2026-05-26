# 2026-05-26 — Doodle Jump browser-WASM, orphan text cleanup

Seventh handoff in the Doodle Jump browser-WASM debugging chain:

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
7. **This doc** — descendant MC invalidation on sprite removal/replace
   (`c2147d58e`).

**Branch state at writing:** `master`, ahead of `origin/master` by 5
commits (`92606558b`, `48ae5cf16`, `7e9b53a6a`, `cf5b61b16`,
`c2147d58e`). Working tree clean. Push when ready.

## TL;DR

- **Fixed (`c2147d58e`):** Three of the four leftover button labels
  ("scores", "options", "play") are now cleaned up when the Doodle Jump
  menu→gameplay transition removes their parent sprites. One label
  ("info") still persists — its parent sprite at depth 7 is *modified*
  rather than removed, and no cleanup site fires for that path.
- **Also fixed:** Nested EditText MCs now have `mc->width`/`mc->height`
  populated from the EditText bounds (was 0 before), so the
  glyph-render stencil mask sizes correctly. This is independent of
  the leftover-text fix and affects all browser-WASM EditTexts placed
  inside sprites.
- **No regressions:** trace harness 407=407, Pong md5
  `bb1f52f690672bd558f6e5c6b1c64301`, Snake t02..t06 md5
  `a213fc90328ab539f9c9e7288670d498`, DJ menu bouncing,
  DJ click-to-transition works, cursor changes on hover.

## What landed

### Group 1: `invalidate_mc_for_dl_entry` helper (tag.c)

New static helper gated to browser-WASM (`!NO_GRAPHICS &&
!HEADLESS_GRAPHICS && !OFFSCREEN_RENDER`). Finds the cached MC whose
`display_obj` equals a given `DisplayObject*`, invalidates it via
`actionInvalidateCachedMovieClipDirect`, and recurses through
`child_mc_cache` invalidating any cached descendants (by parent
pointer, not name).

Pointer-based lookup is critical. The graphics-native cleanup uses
`actionInvalidateCachedMovieClip(name, depth)`, which matches by
name+depth across `child_mc_cache`. Doodle Jump's 4 menu buttons each
contain an EditText named "button_txt" at the same child SWF depth (1)
inside the parent sprite. The 4 cached "button_txt" MCs all have
`mc->depth = -16383` (= child SWF depth 1 - 16384). When
graphics-native invalidates by name+depth, each call (with
`break` on first match) happens to pick its own instance's child only
because the cleanup runs in the same order as cache insertion. In
browser-WASM the order is different (LOAD-handler driven), and the
graphics-native fix would invalidate the wrong instance's child —
leaving exactly one label stuck per cleanup.

### Group 2: tag.c call sites (browser-WASM only)

Three new call sites, each in the existing browser-WASM `#else`
branch:

- `tagRemoveObject2`: invalidates before `clear_display_entry`. Cleans
  up depths 3, 5, 8 (instances 2, 3, 5 in the menu).
- `tagRemoveObject`: same pattern for the older PlaceObject form (kept
  symmetric even though DJ doesn't exercise it).
- `tagPlaceObject2`: invalidates the OLD MC at this depth before
  overwriting `char_id`. Catches the depth=8 menu-button →
  score-textfield REPLACE path. The pre-existing
  `display_list[depth].sprite_display_list = NULL` assignment at
  line ~5625 would otherwise orphan the children.

### Group 3: nested EditText width/height (action.c)

`findOrCreateMovieClip`'s nested-textfield branch (line ~21034) now
sets `mc->width` / `mc->height` from `ng_getTextFieldBounds(tf_idx)`.
The matching root branch ~50 lines below already does this; nested
EditTexts were inheriting `mc->width = mc->height = 0` from
`HCALLOC`. `actionIterateTextFieldGlyphs` uses these as `info.w/h`
for the stencil mask — with 0×0, the mask collapses (`mask_w =
0*20 - 80 = -80` → `has_clip = false`) and per-glyph layout reads
zero-extent bounds.

This is what the prior handoff called "bug 1: text-offset". I did not
get to a clean visual A/B against Ruffle (Ruffle's demo iframe needs a
manual click to autoplay so I couldn't screenshot it via probe), but
the AS-side mc->width/_width now matches what the root branch
produces, which is the documented behavior.

## Diagnosis that worked

Same pattern as prior handoffs:

1. **Reproduce deterministically.** Probe with `--click "286,346@2.5"`,
   four labels persist after dl_count goes 9→6.
2. **Instrument the consumer.** Added a `[DJ_TFG]` printf in
   `actionIterateTextFieldGlyphs` that dumps mc pointer, name, current
   `child_mc_count`, current text contents (read from `dynamic_props`),
   and the full parent chain with each MC's `depth`, `avm1_removed`,
   `_x`/`_y`. This single dump revealed:
   - All 4 button_txt MCs survive post-click (depth still -16383, not
     INT_MIN, visible)
   - Their parents (`instance2`...`instance5`) variously got invalidated
     or didn't — only by walking the chain could you see which parent
     was orphaned and which was just modified
   - The score textfield (`score_txt`) is created fresh every tick
     (different memory addresses), accumulating unbounded entries in
     child_mc_cache (a separate but related leak — see "Open items")
3. **Instrument the cleanup sites.** `[DJ_RM2]` in tagRemoveObject2 and
   `[DJ_PO2X]` in tagPlaceObject2 showed which depth transitions went
   through which path. Depth 7's gameplay placement showed
   `old_char=0` — meaning the slot was *already empty* by the time
   `tagPlaceObject2(7, char=46, gameplay)` fired. Something else
   cleared it, but `[DJ_INV]` traces (inside invalidate_mc_for_dl_entry)
   never showed depth 7 being invalidated. Where the clear happens for
   depth 7 is the remaining open item.
4. **Iterative narrowing.** First attempt called
   `actionInvalidateCachedMovieClip(name, depth)` — wrong-instance
   problem (above). Second attempt resolved via
   `actionFindOrCreateMovieClip(name, root)` — but that could
   *create* a fresh MC for a different placement and invalidate
   *its* children, breaking the hero (depth 9 menu hero shares the
   "hero" name with depth 4 gameplay hero). Third attempt
   (`display_obj` pointer equality) was unambiguous.

All instrumentation removed before commit. State-dump tooling stays
out of the commit per the prior handoffs' convention.

## How to reproduce

```
source emsdk/emsdk_env.sh > /dev/null 2>&1
SWFRecomp/scripts/build_test.sh flasharchive/Doodle_Jump wasm --graphics
SWFRecomp/scripts/deploy_example.sh flasharchive/Doodle_Jump \
  "$(pwd)/docs2/examples" --no-index --graphics

source /tmp/pong-probe/venv/bin/activate
python3 tools/browser-test/probe.py flasharchive/Doodle_Jump \
  --wall-clock-seconds 6 --snapshot-interval-seconds 1 \
  --screenshot-timeout-ms 30000 \
  --move "286,346@2.0" --click "286,346@2.5" \
  --out /tmp/dj-transition
```

Pass criteria (current state, with `c2147d58e`):
- `t01..t02`: menu (`dl_count=9`), 4 button labels visible
- `t03..t06`: gameplay (`dl_count=6`), score `0` top-left,
  `menu` button top-right, hero bouncing — and ONLY "info" leftover
  text visible (instead of all four labels)

## Open items

### 1. "info" label still persists post-transition

Depth 7's menu→gameplay transition keeps the same `char_id=46` (both
the "info" menu button and the gameplay back "menu" button are
instances of sprite 46) and updates only the transform + AS-side
state. No tagRemoveObject2(7) fires. `tagPlaceObject2(7)` for gameplay
sees `old_char=0` (slot already cleared somewhere), so the cleanup
site doesn't fire either. The OLD `instance4` MC stays in cache with
its old `button_txt` child still holding `text="info"`.

Where depth 7's slot is cleared between menu and gameplay is the
unanswered question. Candidates worth probing next session:

- `tagPlaceObject2Ratio` and `tagPlaceObject2RatioWithClipActions`
  (untraced so far).
- The recompiler-emitted "goto rewind" sequence: a gotoAndStop from
  frame 1 to a later frame might re-execute frame 0 tags with depth-7
  conditionally placed. Look for inline clears inside the
  recompiler-emitted goto helpers.
- `advance_sprite_frames` loopback at line 1055-1063 clears child
  `char_id=0` directly without going through tagRemoveObject2 — but
  this is for sprite-internal display lists, not root.

Adding `[DJ_INV]` style traces to the candidates above, plus a printf
in `advance_sprite_frames`' loopback block, should pinpoint it.
Alternatively a `clear_display_entry`-side invalidation would catch
all paths uniformly, but `clear_display_entry` is also called from
slot reassignment paths where invalidation might be wrong.

### 2. score_txt leak (unbounded MC growth)

The instrumentation revealed `score_txt` MCs accumulate at ~3 per
tick during gameplay (each tick creates a new MC pointer at depth
-16376, never invalidated). Not user-visible — the latest score MC
renders correctly — but `child_mc_count` grows without bound and will
hit `MAX_CHILD_MOVIECLIPS` (128) in roughly 40 ticks of gameplay,
silently dropping further MCs.

This is the same root cause as the depth-7 leftover ("info") above:
score_txt's parent display entry is being re-initialized each tick
without going through tagRemoveObject2. Fixing the depth-7 transition
should also fix this leak.

### 3. Hero physics in gameplay

The previous handoff noted: "hero (depth 4) at y=632 is off-canvas".
With the current build the hero is at y=465.5 (still toward the
bottom) and DOES advance — `t04..t06` show hero at slightly different
positions. Whether the physics matches Flash/Ruffle wasn't verified
in this session.

## Don't-touch list (cumulative)

Inherited from prior handoffs, plus:

- `invalidate_mc_for_dl_entry` / `invalidate_descendants_of_mc` are
  browser-WASM specific. Don't drop the `#if` gate or call them from
  graphics-native paths — graphics-native uses
  `fire_recursive_child_unloads` + `actionInvalidateCachedMovieClip`
  which assume different cache-population timing.
- `actionInvalidateCachedMovieClipDirect` is now used by tag.c. It's
  defined as a non-static `extern` in action.c but NOT declared in
  `action.h`. The forward declaration lives inline in tag.c at the
  invalidate_descendants_of_mc site. Keep both extern decls if
  refactoring (or promote to action.h).
- The new `mc->width/height` set in `findOrCreateMovieClip`'s nested
  branch affects all build modes (action.c is compiled everywhere).
  If a NO_GRAPHICS test starts failing on `_width`/`_height` reads of
  a nested EditText, it's likely a test that was depending on the
  buggy 0 — fix the test, not the code.

## Pattern note (7th instance)

This one followed the same pattern as the prior six but with an
extra wrinkle: the "afterthought" code path wasn't a single missing
function call, it was a missing cleanup *protocol*. Graphics-native
runs:

1. `fire_recursive_child_unloads` — queues unload events + invalidates
   children by name+depth
2. `actionFirePendingUnloads` in next tagShowFrame — drains the queue
3. `run_pending_finalize` — destroys pending MCs after the drain

Browser-WASM had none of this. Adding the full pipeline would risk
firing AS-level unload handlers that don't have the drain
infrastructure to land correctly. So the fix took just the
invalidation side-effect (which is what affects rendering) and left
the AS-level handlers alone.

This pattern will recur: anywhere graphics-native has a multi-step
queue → drain → finalize pipeline, browser-WASM probably gets only
the immediate effects and skips the deferred ones. When a future bug
surfaces with "AS handler should have fired but didn't" or "MC stayed
in cache after AS thinks it's gone", look for queue→drain pipelines
in the tagRemoveObject2 / tagPlaceObject2 / button-state / loopback
paths.

## Tools / state

- Local Ruffle source: `~/CC/ruffle`
- MTASC: `~/CC/mtasc/bin/mtasc`
- Probe venv: `/tmp/pong-probe/venv`
- Latest known-good probes:
  - DJ post-fix: `/tmp/dj-fix5/`
  - DJ menu bounce: `/tmp/dj-bounce-check/`
  - Pong regression baseline: `/tmp/pong-reg-new/`
  - Snake regression baseline: `/tmp/snake-reg-new/`

Branch `master` is 5 commits ahead of `origin/master`:
- `92606558b` browser-WASM: wire CLIP_EVENT_PRESS/RELEASE/ROLL dispatch
- `48ae5cf16` docs: Doodle Jump browser-WASM buttons-clickable handoff
- `7e9b53a6a` browser-WASM: set MovieClip.display_obj in
  ng_update_button_states_in_dl
- `cf5b61b16` docs: update DJ handoff with cursor follow-up
- `c2147d58e` browser-WASM: invalidate descendants on sprite
  removal/replace

Push when ready.
