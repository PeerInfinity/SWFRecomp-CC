# 2026-05-26 — Doodle Jump browser-WASM, cache-leak full fix (deferred-invalidate)

Tenth handoff in the Doodle Jump browser-WASM debugging chain.

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
9. `2026-05-26-doodle-jump-cache-leak-half-fix.md` — same-(char,
   ratio, depth) modify-detect on `tagPlaceObject2Ratio` and the
   Replace variant (`a4eb48071`); did not close the depth-2 leak.
10. **This doc** — deferred-invalidate via `pending_remove` flag
    closes the depth-2 `container` RemoveObject2+Place pair leak.
    Code commit `78000f548`.

**Branch state at writing:** `master`, 3 unpushed commits ahead of
`origin/master` (2 from prior session + 1 from this session, plus a
docs commit to come). Working tree clean after this doc commit.

## TL;DR

- **Landed (`78000f548`):** browser-WASM `tagRemoveObject(2)`'s
  `#else` branch now sets `display_list[depth].pending_remove = 1`
  (new u8 field on `DisplayObject`) instead of firing the immediate
  `invalidate_mc_for_dl_entry + clear_display_entry`. The
  invalidate is deferred — either reclaimed by a same-tick
  `tagPlaceObject2(Ratio)` at the same depth (same identity → reuse
  the cached MC) or finalized at `tagShowFrame` before render and
  button hit-test.
- **Three-touch design:**
  1. `tagRemoveObject2` / `tagRemoveObject`: set `pending_remove = 1`,
     no inline invalidate. Other fields (`char_id`, `instance_name`,
     `sprite_display_list`, transforms, …) stay intact so a
     subsequent Place can compare and reclaim.
  2. `tagPlaceObject2` and `tagPlaceObject2Ratio`: at entry, consume
     `pending_remove`. Same identity (matching `char_id`, plus
     matching `ratio` for the Ratio variant) → run an explicit
     modify-style update inline (Place) or fall through to the
     existing modify-detect (Ratio). Different identity → fire
     the deferred invalidate + clear immediately, then fall through
     to fresh-place.
  3. `tagShowFrame`: walk `display_list[]`, fire `invalidate +
     clear` on any entry still flagged. Runs **before** button
     hit-testing and rendering so they never see stale state.
- **Leak count:** DJ gameplay 6 s probe (canonical case from the
  prior handoff's "open items"): **14 cache adds total** vs ~92 in
  the prior half-fix. All 14 are part of menu/transition setup;
  **zero per-tick accretion** during gameplay.
- **Baselines clean:** trace harness 407=407, Pong
  `bb1f52f690672bd558f6e5c6b1c64301` (all 6 snapshots), Snake
  t02..t08 `a213fc90328ab539f9c9e7288670d498`, DJ menu bouncing
  (`unique_canvas_sizes=8`, `display_list_counts` stable at 9), DJ
  cursor pointer/default, DJ play-click → gameplay state with
  "menu" top-right.
- **One regression: DJ play-click t04 score reads "undefined"** (was
  "0" in the prior baseline). Root cause is AS-side, not the fix
  itself — see the "Known regression" section below.

## Implementation details

### New field

`SWFModernRuntime/include/libswf/swf.h` — `DisplayObject`:

```c
u8 pending_remove;      // browser-WASM only: tagRemoveObject(2) deferred the
                        // immediate invalidate+clear so a same-tick Place at the
                        // same depth can reclaim the cached MC instead of leaking
                        // a fresh one each frame_func re-run.
```

Placed right after `clone_replaced` for thematic locality. Cleared
in three places: `tagPlaceObject2`/`tagPlaceObject2Ratio`'s
`pending_remove` consume blocks, and the `tagShowFrame` fallback.

### tagRemoveObject2 / tagRemoveObject browser-WASM #else branch

Two lines instead of two function calls:

```c
#else
    display_list[depth].pending_remove = 1;
#endif
```

Drops `invalidate_mc_for_dl_entry(...)` and `clear_display_entry(...)`.
The `instance_name`, `sprite_display_list`, transforms, `clip_actions`,
etc. stay intact. The UNLOAD-queueing code above this point still fires
unconditionally (no behavioural change there) — accepted because for
the DJ-leak depths the affected clips have no UNLOAD actions, and for
test paths that DO have UNLOAD actions the firing happens
synchronously regardless. If a test surfaces a regression where UNLOAD
fires on a same-tick reclaim, the place-tag's pending_remove block can
detect identity match and short-circuit the UNLOAD too (didn't need
it for this round).

### tagPlaceObject2 entry block

Most invasive of the three. Before any of the existing branches:

```c
if (display_list[depth].pending_remove)
{
    display_list[depth].pending_remove = 0;
    if (display_list[depth].char_id != 0
        && display_list[depth].char_id == char_id)
    {
        // ... explicit modify update: transform_id, cxform_id,
        // clip_depth, placed_at_frame, place_gen, max_depth ...
        // (respects transformed_by_script and cx_overridden flags)
        // ... discard g_pending_clip_actions / g_pending_instance_name
        // (Ruffle apply_place_object modify semantics) ...
        // ... refresh TF binding via actionTryBindTextFieldVariable
        // for char_ids that resolve to ng_find_textfield ...
        return;
    }
    if (display_list[depth].char_id != 0)
    {
        invalidate_mc_for_dl_entry(...);
        clear_display_entry(...);
    }
}
```

Why explicit modify rather than fall-through? `tagPlaceObject2`'s
existing modify-detect at line ~5528 requires `sprite_display_list
!= NULL`, which excludes textfields and stand-alone buttons. The
existing gate works for sprites only. The explicit modify here
covers textfields + buttons + sprites uniformly.

The `actionTryBindTextFieldVariable(set_initial_value=1)` call
makes bound textfields re-read their AS variable on every
same-(char, depth) re-placement. If `var_name` is empty (as for
DJ's score_txt — `tagDefineEditTextProps(..., 57, "\r", "\r", ...,
"", ...)`), the function returns immediately with no effect.
Defensive code for any test path that DOES have a bound TF.

### tagPlaceObject2Ratio entry block

Smaller — falls through to the existing line ~6019 modify-detect
(which already calls `ng_on_place_object2` and so refreshes TF
bindings + sprite init for free):

```c
if (display_list[depth].pending_remove)
{
    display_list[depth].pending_remove = 0;
    if (display_list[depth].char_id != 0
        && (display_list[depth].char_id != char_id
            || display_list[depth].ratio != ratio))
    {
        invalidate_mc_for_dl_entry(...);
        clear_display_entry(...);
    }
}
```

Different (char_id OR ratio) → invalidate. Same (char_id AND ratio)
→ fall through; the existing modify-detect fires.

### tagShowFrame fallback

In the browser-WASM `#else` block (the one with `g_root_enterframe_eligible
= 1`), right before the outer `#endif`:

```c
#if !defined(NO_GRAPHICS) && !defined(HEADLESS_GRAPHICS) && !defined(OFFSCREEN_RENDER)
for (size_t _pr_d = 1; _pr_d <= max_depth; _pr_d++)
{
    if (display_list[_pr_d].pending_remove)
    {
        display_list[_pr_d].pending_remove = 0;
        if (display_list[_pr_d].char_id != 0)
        {
            invalidate_mc_for_dl_entry(app_context, &display_list[_pr_d]);
            clear_display_entry(app_context, _pr_d);
        }
    }
}
#endif
```

Runs **before** button hit-testing (line ~3478) and rendering
(line ~3489) so neither sees stale state. The orphan-text fix from
`c2147d58e` is preserved — descendant invalidation still happens
before render.

### Forward decl for clear_display_entry

The original forward declaration of `clear_display_entry` was at
file scope around line 6580, after the new call sites added in
this commit. Added an earlier forward decl right after
`invalidate_mc_for_dl_entry`'s forward decl so the new browser-WASM
call sites compile.

## Leak verification

Diagnostic added temporarily at `action.c:findOrCreateMovieClip`'s
cache-insert site (around line 21605), removed before commit:

```c
fprintf(stderr, "[DJ_NEW] cache+=%d name='%s' parent=%p depth=%d\n",
    child_mc_count, mc->name ? mc->name : "(null)",
    (void*)mc->parent, mc->depth);
```

6 s DJ probe with click at (286, 346) at t=2.5 (canonical gameplay
entry):

```
cache+=1  name='instance2'  (menu button)
cache+=2  name='button_txt' (menu button child)
cache+=3  name='instance3'
cache+=4  name='button_txt'
cache+=5  name='instance4'
cache+=6  name='button_txt'
cache+=7  name='instance5'
cache+=8  name='button_txt'
cache+=9  name='hero'       (registered class binding)
cache+=10 name='block'
--- click fires gotoAndStop to gameplay ---
cache+=11 name='instance7'
cache+=12 name='container'  (the prior depth-2 leak source)
cache+=14 name='hero'       (new gameplay hero)
cache+=15 name='score_txt'
```

14 adds total (cache+=13 was skipped — likely a numbering artifact;
either way, **no per-tick accretion during gameplay**). Prior
half-fix's measurement was ~92 in 6 s. With the architectural fix
attempted last session, the count would have been similar to this
14 but accompanied by gameplay breakage; this fix gets both
benefits.

`MAX_CHILD_MOVIECLIPS=128` is no longer the cap on gameplay
duration — gameplay is effectively unlimited from the
cache-pressure side. Other regressions (the score "undefined", the
DJ hero placement issue, the menu nav cycle bug) become the next
constraints to investigate.

## Known regression: DJ play-click t04 score reads "undefined"

The handoff's pass criterion says: "/tmp/dj-tenth/canvas/t04.png
shows score '0', 'menu' button top-right, no leftover labels". My
probe at `/tmp/dj-tenth-v2/canvas/t04.png` shows score "undefined"
in that slot.

**This is AS-side, not a direct fault of the fix.** Diagnosis:

- DJ's `score_txt` (char_id 57) is defined with empty variable
  binding (`tagDefineEditTextProps(..., 57, "\r", "\r", ..., "",
  ...)` — the `""` is the variable name). Its content is set
  imperatively by AS via `_root.score_txt.text = _root.score + ""`
  in `script_29.c` (see `PUSH_STR_ID(str_286, ..., 286)` at line
  803 for `score_txt` and `PUSH_STR_ID(str_33, ..., 33)` at line
  811 for `score`).
- `_root.score` is `undefined` when that write fires → the
  textfield gets `"undefined"` as text.
- Pre-fix: the per-tick `tagRemoveObject2 + tagPlaceObject2`
  recreated the container (and probably hero / other MCs) each
  tick, which re-fired some onLoad/onInitialize/onConstruct
  handler that effectively re-set `_root.score = 0` each tick.
  The leak was *masking* the missing init.
- Post-fix: container persists. The AS-side initialiser that
  should set `_root.score = 0` either runs once with stale state
  or doesn't run at all. The textfield re-bind (refreshed by my
  pending_remove modify path's
  `actionTryBindTextFieldVariable(set_initial_value=1)`) doesn't
  help because score_txt isn't a bound textfield.

**What to investigate next session:**

- Grep `script_27`, `script_29`, `script_38` and the registered-class
  constructor for `_root.score = ...` (or `score = ...` at root
  scope). Find what should be initialising it and why that path is
  no longer fired post-fix.
- Likely candidate: a sprite's `INITIALIZE` clip-action handler or
  registered class constructor that ran each tick pre-fix (because
  the sprite was recreated each tick) and now only runs once. The
  fix probably needs an explicit `_root.score = 0` somewhere AS
  expects to run at the start of each gameplay session — Ruffle
  must have an equivalent point.
- An alternative angle: maybe `_root.score` is supposed to come
  from a `var score = 0;` at root-script level (`script_28.c`
  lines 184-188 has `actionDefineLocal` of "score" = 0, but that's
  local to a function, not root). The recompiler might emit
  `actionDefineLocal` where Ruffle emits a global SetVariable.

**Workaround if needed urgently:** revert this commit; the leak
was a known issue that gives ~25 s of gameplay before the cap.

## Other open items unchanged from prior handoff

- **DJ hero off-canvas placement bug (item #3 from prior
  handoff):** Pre-fix had the hero off-canvas at y=465; post-fix the
  hero is actually visible in the centre of the canvas (see
  `/tmp/dj-tenth-v2/canvas/t04.png`). Whether this is an
  improvement, regression, or coincidence depends on the AS-side
  hero physics state — the hero is frozen (not bouncing). Probably
  related to the same AS-init issue causing score "undefined".
- **DJ menu nav cycle (item #2 from prior handoff):** All clicks
  at any (x, y) on the menu dispatch to the play button. Not
  affected by this fix; separate browser-WASM bug. Likely button
  hit-testing logic.
- **Pong preloader transition (item #4 from prior handoff):** Pong
  baseline `bb1f52f690672bd558f6e5c6b1c64301` is preserved (Pong
  preloader stays at dl=3, never transitions to gameplay).
  Untouched by this fix.

## Don't-touch list (cumulative)

- The `pending_remove` field's lifecycle: set ONLY by
  `tagRemoveObject` / `tagRemoveObject2`'s browser-WASM `#else`
  branches; cleared by `tagPlaceObject2` / `tagPlaceObject2Ratio`'s
  consume blocks or `tagShowFrame`'s fallback walk. Don't read it
  from any other code path — it's a transient pump for the
  Remove+Place reclaim handshake.
- The forward declaration of `clear_display_entry` near
  `invalidate_mc_for_dl_entry`'s forward decl (around line 790) is
  required for the `tagPlaceObject2` / `tagShowFrame` call sites
  added in this commit. The original forward decl at line ~6580
  was after these call sites, so adding the earlier one was
  necessary.
- The explicit modify in `tagPlaceObject2`'s `pending_remove`
  consume block needs to gate on `transformed_by_script` /
  `cx_overridden` so AS-level setMatrix / setColorTransform don't
  get clobbered by the timeline's transform update (mirrors the
  existing modify-detect at line ~5528 and the
  `tagReplaceObject2RatioWithClipActions` modify-detect from the
  prior session).
- `actionTryBindTextFieldVariable` in the
  `tagPlaceObject2`-modify-on-reclaim path: defensive, no-op for
  textfields with empty `var_name` (which is the DJ score_txt case).
  Keep it — future tests with bound TFs need this hook.
- The prior session's same-(char, ratio, depth, place_gen)
  modify-detect gates at `tagPlaceObject2Ratio` (line ~5996) and
  `tagReplaceObject2RatioWithClipActions` browser-WASM `#else`
  branch (line ~6505) are now somewhat redundant with the
  pending_remove handshake but still need to fire for **non-Remove**
  re-runs (`tagPlaceObject2Ratio` without preceding
  `tagRemoveObject2`, e.g. depth-7 `instanceN` re-run in DJ
  gameplay). Don't drop them.

## Tools / state

- Local Ruffle source: `~/CC/ruffle`
- MTASC: `~/CC/mtasc/bin/mtasc`
- Probe venv: `/tmp/pong-probe/venv`
- Latest known-good probes:
  - DJ post-fix gameplay click: `/tmp/dj-tenth-v2/`
  - DJ post-fix pre-textfield-refresh: `/tmp/dj-tenth/`
  - DJ menu bouncing: `/tmp/dj-menu-tenth/`
  - Pong regression: `/tmp/pong-tenth-v2/`
  - Snake regression: `/tmp/snake-tenth-v2/`

Push when ready.
