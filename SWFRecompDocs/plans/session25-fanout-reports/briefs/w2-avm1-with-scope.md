**AVM1 scope/dispatch residuals of gnash `DrawingApiTest` (5 + 2 lines left).** From `w1-pixel-drawing` §C (report on master; s25 `0f35012bd` landed the hitTest geometry, 12 → 5 lines). Trace axis. `DrawingApiTest` is in `from_gnash/misc-ming.all/`; check its `known_failure` / `output.ruffle.txt` before booking anything.

Remaining lines (verified locally at `0f35012bd`):
- `13 FAILED: hitTest(376, 139, true)` (DrawingApiTest.as:126): a **bare `hitTest()` inside `with (clip)`**. The method must resolve through the with-scope to the clip.
- `27/28/31/33 FAILED: x.hitTest(...)` (:256-266): **`with`-scope name resolution of a child clip vs a timeline variable**. `x` resolves to the wrong object; even the bounds form fails.
- 2 trailing `FAILED: delete this.onEnterFrame returned false`: **`delete` of an `onEnterFrame` set on a MovieClip returns false.** Flash returns true for a deletable user property; check how clip event-handler slots are stored (the MovieClip own-prop vs a clip-event table) and what `actionDelete`/`actionDelete2` sees.

For each: the mechanism (`action.c` scope chain / `actionGetVariable` with-scope / delete arms), a measured fix, and a sweep over every AVM1 row using `with` (grep the SWFs for ActionWith 0x94) plus `delete`-heavy rows (`avm1/delete*`, gnash `delete*`/`MovieClip-v*`), both modes. Memories: `avm1-target-path-resolution`, `instance-name-variable-deconflation`.

`n-play-game` (local) owns AVM1 button/mouse dispatch. `delete this.onEnterFrame` is near clip-event code, so name every function you touch, and stay out of button/mouse dispatch.
