# Divergence regression gates

Minimal hand-built SWFs that lock a specific fixed divergence. Run via
`run_swfrecomp.py` (the divergence harness's tracer injection trips a separate
recompiler codegen collision on these tiny SWFs, so the harness's auto-inject
path is bypassed — these SWFs `trace()` the asserted state themselves).

## nested_duplicate

`nested_duplicate.swf` (from `nested_duplicate.as`, MTASC `-version 8`): a
`createEmptyMovieClip` child of `parentClip` is `duplicateMovieClip`'d. The
clone must be a sibling (child of `parentClip`), not a `_root` ghost.

Gate (must stay byte-identical to `nested_duplicate.expected.txt`):

```bash
rm -rf /tmp/ndg && \
python3 tools/divergence/run_swfrecomp.py tools/divergence/gates/nested_duplicate.swf /tmp/ndg --frames 2 --recompile >/dev/null 2>&1 && \
grep -aE "typeof|_target|_parent" /tmp/ndg/trace.txt | diff - tools/divergence/gates/nested_duplicate.expected.txt && echo GATE-GREEN
```

Expected:
```
typeof p.dupChild=movieclip
d._target=/parentClip/dupChild
d._parent._name=[parentClip]
d._parent==parentClip:true
typeof _root.dupChild=undefined
```

Regressed before commit `1093c2a33`: clone minted as `_root` ghost →
`p.dupChild=undefined`, `d._parent._name=[undefined]`.

## nested_timeline_clone

`nested_timeline_clone.swf` (hand-assembled from `nested_timeline_clone.swfml`
via `swfmill xml2swf`): three nested timeline sprites — `leaf` placed in
`inner`, `inner` placed in `container`. From `container`'s own frame script it
clones the NESTED, timeline-placed `inner` two ways:

- **method form** `inner.duplicateMovieClip("dup", 5)` — clones for real;
- **function form** `duplicateMovieClip(inner, "dup2", 6)` (ActionCloneSprite).

Locks the nested-timeline-source residual fixed after `1093c2a33` (commit that
follows): `ng_duplicateMovieClip`/`ng_cloneSprite` looked up the source char_id
via `ng_findDisplayEntryByName`, which scans the GLOBAL `display_list` (root's)
and never contains a clip nested inside another sprite → `src_depth=SIZE_MAX` →
the clone's frame 0 never ran → the clone had no children (`dup.leaf=undefined`).
Fixed by falling back to `src_mc->display_obj->char_id`.

Gate (must stay byte-identical to `nested_timeline_clone.expected.txt`):

```bash
rm -rf /tmp/ntcg && \
python3 tools/divergence/run_swfrecomp.py tools/divergence/gates/nested_timeline_clone.swf /tmp/ntcg --frames 3 --recompile >/dev/null 2>&1 && \
grep -aE "typeof|_parent" /tmp/ntcg/trace.txt | diff - tools/divergence/gates/nested_timeline_clone.expected.txt && echo GATE-GREEN
```

Expected (matches Ruffle on every line):

```
typeof inner.leaf=movieclip
dup._parent._name=container      <- method-form clone: real, parented to container, has leaf
typeof dup.leaf=movieclip
typeof dup2.leaf=undefined        <- function-form (ActionCloneSprite) of a nested clip:
dup2._parent._name=                  Ruffle REFUSES it (dup2 undefined); SWFRecomp matches
```

Note the asymmetry: Flash's legacy function-form `CloneSprite` refuses to
duplicate a nested timeline clip (yields nothing), while the method-form
`duplicateMovieClip` succeeds — and SWFRecomp matches both.

To author such SWFs: `swfmill swf2xml` an existing SWF to learn the schema,
edit the XML (AVM1 actions are structured elements — `PushData`/`StackString`/
`GetMember`/`CallMethod`/`CloneSprite`/`Trace`/…), then `swfmill xml2swf`. Note
ActionCloneSprite's runtime stack is `[source-mc] [new-name] [depth]`, and the
source must be a MovieClip ref (`GetVariable`), not a string path.

## attached_clip_playhead  — ⚠️ KNOWN-FAILING (desired-behavior gate)

`attached_clip_playhead.swf` (from `attached_clip_playhead.swfml` via swfmill):
the root attaches a 4-frame `box` symbol twice — `b` left playing, `c` then
`c.stop()`'d — and traces `b._currentframe` / `c._currentframe` each frame.
Ruffle (`attached_clip_playhead.expected.txt`):

```
T1 b=1 c=1
T2 b=2 c=1   <- b auto-advances each tick (attached clips PLAY in Flash); c frozen by stop()
T3 b=3 c=1
T4 b=4 c=1
T5 b=1 c=1   <- b loops back to frame 1
T6 b=2 c=1
T7 b=3 c=1
```

**This gate FAILS on current HEAD**, and the 2026-06-13 re-scoping found it has
TWO distinct causes (the first masks the second):

1. **Method-form `stop`/`play` on an attached clip mis-routes to the ROOT.**
   The gate's `c.stop()` falls through the method-form handler
   (`action.c` stop arm ~64961, play arm ~64884: both only stop/play a clip
   found in the GLOBAL `display_list` via `ng_findDisplayEntryByName`; an
   attached clip's `display_obj` is a standalone heap struct NOT in that list,
   so it falls through to `actionStop` → `is_playing=0` → **stops the root**).
   So the gate's root halts after frame 1 — swfrecomp emits only `T1` then
   "Shutting down" (no `T2…`). This is a real, independently-wrong bug that hits
   ANY game doing `attachedClip.stop()/.play()`. **It is also EXACTLY why the
   earlier #15 prototype regressed N**: N's `menuMC` (objectID 410, a 13-frame
   menu state-machine attached via `CreateSprite`) has `this.stop()` in its
   frame 1 — the same method-form path — so the attached clip was never frozen
   and the playhead pump over-advanced it.
2. **attachMovie'd multi-frame clips don't auto-advance their playhead.**
   `advance_sprite_frames` only walks display-list arrays; a root-attached
   clip's `display_obj` is in no list, so its timeline never ticks (`b` would
   stay at `_currentframe=1` even with the root advancing).

Run it:

```bash
rm -rf /tmp/acpg && \
python3 tools/divergence/run_swfrecomp.py tools/divergence/gates/attached_clip_playhead.swf /tmp/acpg --frames 10 --recompile >/dev/null 2>&1 && \
grep -a "^T" /tmp/acpg/trace.txt | diff - tools/divergence/gates/attached_clip_playhead.expected.txt && echo GATE-GREEN
```

**The correct fix is two ordered steps (see PROGRESS #15):**
- **(1) attached-clip method-form `stop`/`play` routing** — add a
  `mc->display_obj != NULL` branch to both arms so the call acts on the clip's
  own display obj, never the root. Safe, high-value, independently shippable;
  fixes the gate's root-advance AND freezes N's `menuMC` (un-regressing N).
- **(2) attached-clip auto-advance pump** — only safe once (1) lands. The
  earlier prototype (`ng_advance_attached_clip_playheads`) needs a creation-tick
  promotion (skip the attach tick) ordered AFTER the deferred attach-init drain
  so frame-1 `this.stop()` has applied before the clip is ever advanced (the
  #10 `ng_record_*`/`ng_apply_*_after-drain` pattern is the model).
Note: #15 does NOT fix Achievement Unlocked's first divergence — that's an
`instance5` auto-name playhead bug + a one-frame attach-*pacing* lag, both
UPSTREAM of the playhead. This gate is the regression target; N `4941==4941`
must hold.

## nested_sprite_cf_lag  — ✅ FIXED (was follow-up #10a; commit landing 2026-06-12)

**GREEN as of the #10a fix.** `presync_nested_sprite_currentframe` (tag.c) runs
between Phase 1 and the enterFrame flush in both `swf_core.c` (NO_GRAPHICS) and
`swf.c` (OFFSCREEN_RENDER); it writes ONLY the AS-visible `mc->currentframe` of
deferred nested sprites to the value Phase 3 will set (`sprite_current_frame +
1` for a normally-advancing sprite), leaving the playhead counter and all frame
scripts in Phase 3. So a clip whose `onEnterFrame` fires in the flush (e.g. the
tracer, always last-instantiated) reads the post-advance value — matching
Ruffle's flat instantiation-ordered "enterFrame-event-THEN-advance per clip"
exec list — without perturbing nested frame-script execution order (the reason
the advance is deferred). This is option (a) below. Verify:

```bash
python3 tools/divergence/divergence_test.py tools/divergence/gates/nested_sprite_cf_lag.swf --frames 10 --recompile
cat tools/divergence/runs/nested_sprite_cf_lag/divergence.txt   # → Trace: identical
```

The historical analysis (root cause / why it was high-risk) is preserved below.

### Historical (pre-fix): ⚠️ KNOWN-FAILING (desired-behavior gate, follow-up #10a)

`nested_sprite_cf_lag.swf` (from `nested_sprite_cf_lag.swfml` via swfmill) — the
minimal repro for the **nested-sprite `_currentframe` one-tick lag** (#10a).
Structure: a 4-frame sprite `leaf` placed (as `n`) inside a 1-frame holder `mid`
(placed as `c`) → `_root.c.n` is a multi-frame sprite nested one level; plus a
ROOT-LEVEL 4-frame sprite `m` as a control. Root loops (2 frames, no stop) so
everything keeps playing. Run through the **full** harness (the tracer auto-
injects cleanly on this SWF):

```bash
python3 tools/divergence/divergence_test.py tools/divergence/gates/nested_sprite_cf_lag.swf --frames 10 --recompile
cat tools/divergence/runs/nested_sprite_cf_lag/divergence.txt
```

**FAILS on HEAD at filtered line 3** (`_root.c.n _cf`). The control `m`
(root-level) matches Ruffle exactly (`2,3,4,1,…` both sides); only the nested
`c.n` lags one tick:

```
frame:        F1 F2 F3 F4 F5 …
m   (root):    2  3  4  1  2     Ruffle == swfrecomp   (advances in Phase 1, pre-enterFrame)
c.n (nested):  2  3  4  1  2     Ruffle
c.n (nested):  1  2  3  4  1     swfrecomp  ← one tick behind
```

**Root cause (pinned this session):** Ruffle's `Avm1::run_frame`
(`core/src/avm1/runtime.rs:519`) walks ONE flat `clip_exec_list` in
*instantiation order*; each clip's `run_frame_avm1`
(`core/src/display_object/movie_clip.rs:450`) does **enterFrame-event THEN
playhead-advance**. The harness's `__tracer__` clip is `createEmptyMovieClip`'d
at runtime → LAST in that list, so by the time its `onEnterFrame` fires every
game clip (nested included) has already advanced this tick → the tracer reads
post-advance `_currentframe`. SWFRecomp instead uses a *phased* model
(`swf_core.c:994` Phase 1 advances root-level sprites with
`g_advance_defer_nested=1`; `swf_core.c:1021`/`:1056` Phase 2 runs the root
frame func + the `tagFlushPendingEnterFrame` where the tracer's `onEnterFrame`
fires; `swf_core.c:1059` Phase 3 `advance_nested_sprite_frames` advances nested
sprites). So nested sprites advance AFTER the enterFrame flush → the tracer
reads them one tick stale. `swf.c` (OFFSCREEN_RENDER) mirrors this at
`:735`/`:852`. Root-level sprites advance in Phase 1 (before enterFrame) →
no lag, exactly as the `m` control shows.

**Why it's high-risk (do NOT patch blind):** the Phase-3 deferral of nested
advance exists to match nested-sprite *frame-script* execution ORDER relative to
the root script (many MEMORY entries tuned this). Simply moving nested advance
before the enterFrame flush would change script ordering and likely regress the
trace suite. The likely correct shape is to advance the nested playhead COUNTER
(`sprite_current_frame` / `_currentframe`) before enterFrame while keeping the
nested frame SCRIPT in Phase 3 — OR adopt Ruffle's flat instantiation-ordered
"enterFrame-then-advance per clip" exec list. Validate against the full trace
suite both modes; do not regress `nested_sprite_cf_lag` (this gate, becomes
GREEN), Pacman `242==242` (its `Pac`/`CPac` lag should clear), and every
nested-sprite / timeline / execution-order test.

## nested_sprite_inframe_goto  — ✅ FIXED (was follow-up #10; commit landing 2026-06-13)

**GREEN as of the #10 fix.** A sprite's OWN frame-script `gotoAndPlay(T)` is now
applied WITHIN the same tick (no longer deferred a tick), eliminating the
overrun+stutter. Verify:

```bash
python3 tools/divergence/divergence_test.py tools/divergence/gates/nested_sprite_inframe_goto.swf --frames 12 --recompile
cat tools/divergence/runs/nested_sprite_inframe_goto/divergence.txt   # → Trace: identical
```

### Root cause + fix

Sprite frame scripts are QUEUED during `advance_sprite_frames` /
`advance_nested_sprite_frames` and only run when the `AQ_KIND_SCRIPT` queue is
drained — which happens AFTER both advance passes. So a sprite whose frame-N
script calls `gotoAndPlay(T)` (→ `ng_gotoFrameCurrentSprite`) sets
`sprite_manual_next_frame` too late for that tick's advance; the deferred
top-of-loop manual-nav block only processed it NEXT tick, burning an extra tick
(the observer re-read the issuing frame — a "stutter") and then landing on, and
re-observing, the target. Per-frame `_currentframe` (both `m` root-level and
`c.n` nested were IDENTICAL — NOT nested-specific):

```
frame:       F1 F2 F3 F4 F5 F6 F7 F8 F9 …
Ruffle:       2  3  4  5  2  3  4  5  2     clean period-4 loop
swfrecomp (old): 2 3 4 5  5  1  2  3  4     period-6: overran to 5, STUTTERED (5,5), then 1
```

**Fix** (`tag.c` / `tag_stubs.c` / `swf_core.c` / `swf.c`):
`ng_gotoFrameCurrentSprite` records each self-goto via
`ng_record_sprite_self_goto`; the pump calls `ng_apply_pending_sprite_self_gotos`
right after draining `AQ_KIND_SCRIPT` (swf_core.c NO_GRAPHICS + swf.c
OFFSCREEN_RENDER). The apply pass rebuilds the sprite's display list to `T`
(full reset + replay 0..T, tags only — the target's own DoAction is already
queued) and sets `sprite_current_frame = (T+1)%count` so a Play resumes at T+1
next tick. `gotoAndStop` (is_playing==0) is left on the deferred path unchanged.
Scoped to the two test-pump modes; browser-WASM keeps the deferred path.

### IMPORTANT — this gate does NOT capture Pacman's residual `Pac`/`CPac` diff

The diagnosis assumed this gate is "byte-identical to Pacman's `Pac`." That is
true of the *old swfrecomp bug output* (both were `2,3,4,5,5,1`) but NOT of
**Ruffle's** output: Ruffle gives this gate `2,3,4,5` but Pacman `Pac` `2,3,4,1`
— despite `Pac` frame_5 being the same `gotoAndPlay(1)`. The difference is the
**injected tracer's instantiation order**, not the playhead. Ruffle runs ONE
FIFO of `EnterFrame` events + frame `DoAction`s ordered by the clip exec-list
(newest clip at the head, processed first). In this gate the looping sprites are
placed by root-frame-1 `PlaceObject` tags, which run BEFORE the frame-1
`DoAction` that `createEmptyMovieClip`s the tracer → the sprites are OLDER than
the tracer → the tracer's `EnterFrame` runs BEFORE their goto `DoAction` → it
reads the **pre-goto** frame (5). In Pacman, `Pac` is placed on a later `Demo`
frame, AFTER the tracer → `Pac` is NEWER → its goto runs BEFORE the tracer's
`EnterFrame` → the tracer reads the **post-goto** frame (1). Same playhead, the
observer just samples it on opposite sides of the goto.

So the #10 fix makes `Pac`'s playhead correct (the stutter is gone: old
`2,3,4,5,5,1` → now `2,3,4,5`, a clean period-4 loop; frame 5 is the
goto-trigger and is skipped in the RENDER, matching Flash). The remaining
`Pac`/`CPac` `_cf` `5`-vs-`1` is a **reporting/observer-ordering artifact of the
same class as #10a** (instantiation order of the observed clip relative to the
harness tracer), not the #10 overrun/stutter — and it cannot be fixed by
playhead mechanics: there is no single phase placement that yields pre-goto for
clips older than the tracer AND post-goto for clips newer than it. Tracking it
needs per-observer exec-order modeling (a #10a-style follow-up). The root
TIMELINE goto path is unaffected (`goto_frame`, `goto_frame2`, `tell_target`,
`execution_order1-4`, `goto_execution_order{,2}` all pass).

**Resolution (2026-06-13, #10b): tooling-only.** Rather than rearchitect the
phased advance into Ruffle's flat exec-list (option A, deferred), the harness now
has a per-game accepted-diff facility (`../accepted/`, `../accepted_diffs.py`,
wired into `divergence_test.py`) that absorbs the documented Pacman `Pac`/`CPac`
`_cf` `1`↔`5` artifact and reports Pacman converged-modulo-artifact. A rule only
matches when EVERY field but `_cf` is identical and the values are the exact
documented pair, so it cannot mask a real `_cf` bug. See `../accepted/README.md`
and PROGRESS.md #10b. This gate is unaffected (it has no manifest and stays
GREEN — it reads `2,3,4,5` on both sides).
