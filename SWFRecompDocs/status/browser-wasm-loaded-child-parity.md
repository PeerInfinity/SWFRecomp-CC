# Does the loaded-child arc reach the browser?

**2026-09-04.** Baseline `d1486f93e`. Brief:
`SWFRecompDocs/prompts/browser-wasm-loaded-child-parity-prompt.md`.

Ten slices made loaded child movies work — char ids re-based by the recompiler,
embedded assets reachable, timelines that advance and loop, a full render path —
all verified **natively**. This slice asked whether any of it reaches
browser-WASM, the deployment target.

## 1. Verdict on the brief's hypothesis: REFUTED. The BACKLOG was right.

The brief (§1) read `swf.c:1263`'s `actionAdvancePlayingLevels` call as sitting
outside any `__EMSCRIPTEN__` gate, and inferred the browser might already
advance loaded movies. It does not. The `#endif` at `:1188` closes an inner
block; the enclosing `#ifdef OFFSCREEN_RENDER` opens at **`:1034`** and does not
close until `:1331`.

Checked with a real preprocessor, not by eye:

```
$ cpp -P -D__EMSCRIPTEN__=1                       swf.c | grep -c actionAdvancePlayingLevels   → 0
$ cpp -P -D__EMSCRIPTEN__=1 -DOFFSCREEN_RENDER=1  swf.c | grep -c actionAdvancePlayingLevels   → 2
```

And it was worse than the BACKLOG said. The same block holds every other
loaded-movie drain, so browser-WASM had **none** of them:

| symbol in `swf.c` after `cpp` | browser | OFFSCREEN |
|---|---|---|
| `actionFirePendingDirectLoads` (direct `loadMovie`) | 0 | 2 |
| `actionProcessDeferredFailedLoads` | 0 | 2 |
| `actionAdvancePlayingLevels` (child playhead) | 0 | 2 |
| `actionFirePendingLoadInits` (MovieClipLoader) | 0 | 2 |

`tagShowFrame`'s two `actionFirePendingLoadInits` calls (`tag.c:7013`, `:12738`)
are themselves inside `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)`
arms, so they are not a browser fallback either. The existing comment at
`swf.c:1341` — "LOAD drains already run per tick inside tagShowFrame" — is true
only of the `AQ_KIND_LOAD` clip-event queue (present in the browser, absent in
OFFSCREEN), not of the movie-load drains; reading it the other way is how the
browser gap stayed invisible. Comment corrected in place.

**So the BACKLOG's "moot until browser-WASM advances a loaded movie at all" was
correct in its verdict and understated in its scope: browser-WASM did not
*load* a child movie at all, never mind advance one.**

## 2. Measured, in a browser, before any fix

Browser-WASM graphics build of `regression/avm1_child_timeline_advance`
(harness: `tools/browser-test/child_probe/`), WSLg Chrome:

```
browser (before)                                    native oracle
t1  cf:0 tf:1 ax:undefined b:undefined z:undefined   c1
t2  cf:0 tf:1 ax:undefined ...                       t1 cf:1 tf:5 ax:10 ...
...                                                  c2
                                                     t2 cf:2 tf:5 ax:20 b:movieclip ...
```

Not one `c1`..`c5` line: no frame of the child ever ran. `_totalframes` 1 and
`_currentframe` 0 on the holder — the loaded movie was never linked in.
`holder.a._x` undefined — the child's display children did not exist.

**Every one of the ten slices' behaviours was unreachable from the browser, for
the single reason that the child never loaded.**

## 3. The two fixes

### (a) `swf.c` — the browser-WASM arm gets the loaded-movie drains

The `#if !defined(OFFSCREEN_RENDER) && defined(__EMSCRIPTEN__)` block that
cont. 32 added for `processTimers` is the right home for them. Added, in
OFFSCREEN's / `swf_core.c`'s order and with the same bounds: deferred-failed +
direct-load drain (guard 32), `actionAdvancePlayingLevels`, then — after the
existing timer pump — the MovieClipLoader `actionFirePendingLoadInits` drain
(guard 32). All are strict no-ops when nothing is pending.

That alone got the child loading, advancing, stopping on its own `stop()`,
resuming on `holder.play()` and wrapping to frame 1 — but left one row wrong:

```
browser  ax:10  ax:10  ax:0   ax:0        native  ax:10  ax:20  ax:30  ax:30
```

### (b) `tag.c` — the timeline-Move arm re-bases its placement id

In `tagPlaceObject2`'s `char_id == 0` (PlaceObject2 Move) branch, the
`display_list[depth].transform_id = transform_id` assignment is ungated but the
`ng_cache_transform` call after it was `#if defined(NO_GRAPHICS) ||
defined(OFFSCREEN_RENDER)`. `ng_cache_transform` is not only the `place_*`
cache: it is **the single funnel that re-bases a placement id onto the combined
transform table** (`per-movie-render-tables`). Skipping it while still writing
the raw id left a loaded child's every timeline Move indexing the **root
movie's** rows — wrong for the AVM1 `_x`/`_y` getters (which re-index
`transform_id`) and for the renderer alike. Ungated; the OFFSCREEN-only
`ng_on_place_object2` re-init stays gated exactly where it was.

**This is the §3 backlog entry, and step 1 promoted it from inert to live
exactly as the brief predicted it would.** But its mechanism was different from
what that entry assumed: of the seven `ng_cache_transform` sites gated
`NO_GRAPHICS || OFFSCREEN_RENDER`, six sit inside blocks the browser never
executes at all (button-state preservation, backward-goto survives-rewind,
cross-frame sprite REPLACE, two ratio arms) and the browser takes its own
parallel arms — `tag.c:9002` and `:10049`, both of which already called
`ng_cache_transform`. Exactly **one** site had no browser counterpart. Browser
`ng_cache_transform` call sites: 8 → 9.

## 4. What reaches the browser now — feature by feature, measured

Every row observed in WSLg Chrome on a browser-WASM graphics build, trace lines
diffed against each fixture's native `output.txt`, pixels against its Ruffle
golden. "before" = the same page with fix (a) reverted.

| Arc behaviour | Fixture | before | after |
|---|---|---|---|
| Direct `loadMovie` links the child in | `avm1_child_timeline_advance` | **no** | **exact** |
| Child timeline advances frame by frame | `avm1_child_timeline_advance` | no | exact |
| Child's own `stop()` parks its playhead | `avm1_child_timeline_advance` | no | exact |
| `holder.play()` targets the child's playhead | `avm1_child_timeline_advance` | no | exact |
| Child's later-frame `RemoveObject2` | `avm1_child_timeline_advance` | no | exact |
| Child's timeline Move (`_x` 10→20→30) | `avm1_child_timeline_advance` | no | exact |
| Child wraps to its frame 1, clearing its own children | `avm1_child_timeline_loop` | no | exact¹ |
| Two out-of-phase children don't clear each other | `avm1_child_timeline_loop` | no | exact¹ |
| Child placement: char id, name, `_x`/`_y` | `avm1_parent_child_modify_place` | no | exact |
| Child shape geometry (hitTest outline + bbox) | `avm1_parent_child_render` | absent | exact |
| Child shape **pixels** | `avm1_parent_child_render` | 7200/40000 px wrong | **identical to golden** |
| Child embedded bitmap (`BitmapData.draw`+`getPixel`) | `avm1_parent_child_bitmap` | absent | exact |
| Child bitmap-fill **pixels** | `avm1_parent_child_bitmap_fill` | — | **identical to golden** |
| Child static text (glyph hitTest + `TextSnapshot`) | `avm1_parent_child_text` | absent | exact |
| Child static text **pixels** | `avm1_parent_child_text` | — | **identical to golden** |
| Child morph END shape | `avm1_parent_child_morph` | absent | exact |
| Child morph **pixels** | `avm1_parent_child_morph` | — | **identical to golden** |

¹ except one line — see §5.

`MovieClipLoader.loadClip` in the browser is **code-complete but unprobed**:
the drain is now called, and no regression fixture in the arc exercises MCL
under an AVM1 parent in a browser build. Named in BACKLOG.

## 5. Two out-of-arc browser gaps the probe surfaced

Both are on the **parent/root** side — the child half of each fixture is
correct — so neither belongs to this arc, and neither is fixed here.

* **`_root._currentframe` reads `undefined` in browser-WASM** where native
  reads `1` (`avm1_child_timeline_loop`, the `rf:` column). The root-playhead
  sync `root_movieclip.currentframe = _disp_frame + 1` at `swf.c:585-608` is
  `#ifdef OFFSCREEN_RENDER`, which is a necessary but **not sufficient**
  explanation: an unmaintained field would read `0`, not `undefined`, and the
  getters at `action.c:44956/55124/59616` are ungated. Owner not identified.
  The other half of that fixture's parent-rewind guard — `t` rising 1..9 exactly
  once — holds, so the parent is not being rewound.
* **`typeof` a root-placed named bare `DefineShape` is `object`** in
  browser-WASM where native and Ruffle say `movieclip`
  (`avm1_parent_child_bitmap_fill`, `ctl:object` vs `ctl:movieclip`). The
  child's identically-shaped `sub` reads `movieclip` in the same run, so this
  is a root-side non-scriptable-display-object gap, not a child one.

## 6. CI

Both edits are **preprocessor-identical in both CI modes** — proven, not
assumed:

```
swf.c  -DNO_GRAPHICS                        IDENTICAL
swf.c  -DOFFSCREEN_RENDER -DUSE_WEBGPU      IDENTICAL
tag.c  -DNO_GRAPHICS                        IDENTICAL
tag.c  -DOFFSCREEN_RENDER -DUSE_WEBGPU      IDENTICAL
```

Fix (a) is inside a `!OFFSCREEN_RENDER && __EMSCRIPTEN__` arm neither CI mode
compiles. Fix (b) moves a statement out of a `#if` whose condition both CI
modes satisfy, leaving their token stream unchanged. CI was dispatched anyway
per CLAUDE.md (shared runtime code), serial, `images=false`; results in §7.
`wasm-link-smoke` compiles and links only — it is not evidence this slice
worked, and the browser measurements above are.

## 7. CI results

(filled in below)
