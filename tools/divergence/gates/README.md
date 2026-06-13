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

**This gate FAILS on current HEAD** — it documents a real, confirmed gap:
**attachMovie'd multi-frame clips do not auto-advance their playhead.**
`advance_sprite_frames` only walks display-list arrays; a root-attached clip's
`display_obj` is a standalone heap struct no list contains, so its timeline
never ticks (`b` stays pinned at `_currentframe=1`). Run it:

```bash
rm -rf /tmp/acpg && \
python3 tools/divergence/run_swfrecomp.py tools/divergence/gates/attached_clip_playhead.swf /tmp/acpg --frames 10 --recompile >/dev/null 2>&1 && \
grep -a "^T" /tmp/acpg/trace.txt | diff - tools/divergence/gates/attached_clip_playhead.expected.txt && echo GATE-GREEN
```

See PROGRESS.md follow-up #15 for the full investigation: a naive
playhead-advance pump (`ng_advance_attached_clip_playheads`) was prototyped and
makes THIS gate green, but it must compose with (a) a creation-tick promotion
(skip the attach tick) and (b) routing the attached clip's frame-1 `stop()`
through the deferred attach-init script — and even with all three it neither
fixed Achievement Unlocked (its real bug is `instance5` + a one-frame attach
*pacing* lag, both upstream of the playhead) nor avoided regressing N
(`MenuMC3`, a non-root attach whose frame-1 stop still wasn't respected →
4941/4941 → 4943). Backed out; this gate is the regression target for a future
correct fix.

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
