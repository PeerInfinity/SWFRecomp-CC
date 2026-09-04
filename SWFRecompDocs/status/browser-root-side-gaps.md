# The browser's root-side gaps: `_root` was a TextField

**2026-09-04.** Baseline `83e03a63d`. Brief:
`SWFRecompDocs/prompts/browser-root-side-gaps-prompt.md`.

The previous slice (`browser-wasm-loaded-child-parity.md`) made browser-WASM
load, advance and render child movies, and left two defects it had explicitly
declined to fix, both on the **root** side: `_root._currentframe` reading
`undefined`, and `typeof` a root-placed named bare `DefineShape` reading
`object`. The brief asked one scoping question first — is the `_currentframe`
gap browser-wide, or specific to the probe fixture that found it?

## 1. The scoping question: BROWSER-WIDE, and worse than stated

An ordinary single-movie SWF with no loaded child at all, MTASC-compiled,
run through `tools/browser-test/child_probe/` in a browser-WASM graphics build
against the same C run natively:

```
                                    browser (before)   native
typeof(_root)                       object             movieclip
_root._currentframe                 undefined          1
typeof(_root._currentframe)         undefined          number
_root._totalframes                  undefined          1
main(mc)'s root arg ._currentframe  undefined          1
_root._name                         (empty)            (empty)     <- agreed
_root._x                            0                  0           <- agreed
eval("_root")._currentframe         undefined          1
_level0._currentframe               undefined          1
_root._framesloaded                 undefined          1
```

So it is browser-wide, it needs no child movie, and `_currentframe` was the
smaller half of it: **`typeof(_root)` was wrong too**. That column is what
identified the owner, because it says the failure is not in the playhead at
all.

## 2. The owner: one designated initializer inside a preprocessor gate

`_x` and `_name` agreeing while `_currentframe` / `_totalframes` /
`_framesloaded` all read `undefined` is a signature, not a coincidence: those
three are the only members in `actionGetMember`'s MovieClip block carrying
`&& !MC_IS_TEXTFIELD(mc)`, and `actionTypeof` returns `"object"` for a
MOVIECLIP when `MC_IS_TEXTFIELD(mc) && g_swf_version >= 6`. One predicate
explains all four rows and nothing else.

```c
#define MC_IS_TEXTFIELD(mc) ((mc)->ng_textfield_idx >= 0 || (mc)->ng_textfield_idx == -2)
```

Instrumenting `actionTypeof` in a browser build printed it directly:

```
[TYPEOF] mc=0x15fa8 btn=0 tfidx=0 name='' ver=8
```

`ng_textfield_idx == 0` on the root MovieClip — i.e. "static textfield #0".
`root_movieclip`'s static initializer sets it to `-1`, but that line sat inside

```c
#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)
	.display_obj = NULL,
	.last_transform_id = 0,
	.as_set_flags = 0,
	.ng_textfield_idx = -1,
	.draw_has_bounds = 0,
	.mc_mouse_inside = 0,
	.mc_as_pressed = 0,
	.mc_enterframe_eligible = 1,  // Root is always eligible
#endif
```

The fields are declared unconditionally in `MovieClip` (`action.h:76`); only
the *initializer* was gated. Six of the eight are zero either way, so the gate
was invisible for them. The other two are not: `ng_textfield_idx` means
"not a textfield" at `-1`, and `mc_enterframe_eligible` means "eligible" at
`1`. Any build defining neither macro got C's implicit zeros and a root
MovieClip that claimed to be TextField #0.

**The project had already learned this exact hazard one screen away.** The
`_levelN` constructor carries the comment "HCALLOC zeros ng_textfield_idx, but
`0` means static textfield #0, making MC_IS_TEXTFIELD evaluate true. Mark as
not-a-textfield." The static root had the same hole through a different door.

**Fix:** the gate is deleted; the initializers stay. `cpp -P` proves both CI
modes' token streams are unchanged and the third config gains the line:

```
-DNO_GRAPHICS                     pre-fix: 1   post-fix: 1
-DOFFSCREEN_RENDER -DUSE_WEBGPU   pre-fix: 1   post-fix: 1
-DUSE_WEBGPU                      pre-fix: 0   post-fix: 1
```

### It is not only the browser

`-DUSE_WEBGPU` with neither `NO_GRAPHICS` nor `OFFSCREEN_RENDER` is exactly
what `build_test.sh` passes for a **native windowed** graphics build
(`build_test.sh:405`). So the defect covered every live-render configuration —
browser-WASM *and* the native player — and was absent only from the two
headless harnesses CI compiles. Every real-content demo this project ships ran
with `typeof(_root) == "object"` and `_root._currentframe` undefined.

### The audit for the same class is closed

A sweep of every file-scope struct initializer in `SWFModernRuntime/src`
finds exactly one containing a preprocessor gate — this one. The two runtime
`sizeof(MovieClip)` allocation sites (`action.c:21617` `calloc`,
`action.c:21751` `HCALLOC`) both set `ng_textfield_idx = -1` explicitly.

## 3. The second defect, which the first one was hiding

With identity fixed, `_root._currentframe` resolves — and reads **1 forever**
in the browser while the playhead advances. The brief's original lead was
right after all; it was simply unobservable behind a property that never
resolved.

`swf.c`'s tick block updates `root_movieclip.currentframe` from the natural
advance, and that update sat inside the function's `#ifdef OFFSCREEN_RENDER`
region (`:557`–`:663`). There is no parallel arm — measured, not assumed:

```
$ cpp -P -DOFFSCREEN_RENDER -DUSE_WEBGPU swf.c | grep -c 'root_movieclip.currentframe = '   -> 1
$ cpp -P                    -DUSE_WEBGPU swf.c | grep -c 'root_movieclip.currentframe = '   -> 0
```

**Fix:** the sync block is hoisted out of the gate (the `#endif` moved above it
and a fresh `#ifdef OFFSCREEN_RENDER` opened below), so OFFSCREEN's statement
order is untouched — `cpp -P -DOFFSCREEN_RENDER -DUSE_WEBGPU` is byte-identical
before and after — and the browser / native-windowed builds gain the six lines.

### The goto family did NOT need the same treatment — checked, not assumed

`action.c` has thirteen `root_movieclip.currentframe =` writes; `cpp` says the
browser config compiles five of them and the two CI modes compile all twelve
(one is inside an `#if/#else` pair). That is a gate count, not a gap count —
the trap this arc keeps re-learning. A hand-built five-frame root probe driving
`gotoAndStop`, `_root.nextFrame()` and `_root.prevFrame()` returned rows
**identical to the native oracle** in the browser:

```
f1 cf:1 / f2 after-nextFrame cf:2 / f3 cf:3 / f3 after-prevFrame cf:3
f4 after-goto1 cf:1 / f1 cf:1
```

The two ungated sites (`action.c:34525`, `:34697`) are the AS goto path, and
the eight gated ones sit in arms the browser does not take. Nothing further is
owed here.

## 4. Grading

New fixture: **`ruffle-tests/tests/swfs/regression/avm1_root_identity_and_playhead`**
— a hand-assembled three-frame root SWF (MTASC emits one frame, and one frame
cannot tell a synced playhead from a frozen one) with a named bare
`DefineShape` at depth 1 and one AVM1 trace row per frame.

Measured in WSLg Chrome on a browser-WASM graphics build:

| state | rows |
|---|---|
| both fixes reverted | `r1 t:object cf:undefined tf:undefined fl:undefined s:object` ×3 |
| identity fix only | `r1 t:movieclip cf:1 tf:3 fl:3 s:movieclip`, then `r2 … cf:1`, `r3 … cf:1` |
| both fixes | `r1 … cf:1`, `r2 … cf:2`, `r3 … cf:3` — matches the native oracle |

All five columns flip on revert, and the middle row is the isolating evidence
that the two defects are independent: the identity fix alone corrects `t:`,
`tf:`, `fl:` and `s:` while leaving `cf:` frozen.

**The corpus cannot flip these rows.** Both defects live in code the two CI
test modes do not compile — `NO_GRAPHICS` and `OFFSCREEN_RENDER` both satisfied
the gates that were wrong. The fixture passes in both native modes before and
after, which is what it is for on that side: a non-regression lock on the
headless path while the browser numbers are graded in the harness. This is the
brief's §3 "graded in the browser harness" case, stated explicitly rather than
implied.

The previously-filed `typeof` gap is graded a second way, in the fixture that
found it: `regression/avm1_parent_child_bitmap_fill` traced `ctl:object` in the
browser before and `ctl:movieclip` after, matching its native oracle exactly.

## 5. CI

Both edits are **preprocessor-identical in both CI test modes** — proven with
`cpp -P`, per §2 and §3 above. The corpus is therefore predicted flat, and per
the previous slice's own lesson that prediction is not a licence to skip the
dispatch: `wasm-link-smoke` builds the BROWSER configuration on every dispatch
in any mode, and it is the one CI signal that can move for a change like this.

**Graphics**, run `33913083605` at `ed39ce53d`, `categories=full`,
`images=false`, diffed against `23c37af72`:

```
=== intersection: 4498 tests (23c37af72 -> WORKTREE, results_graphics) ===
  output_mismatch    124 ->   124 (+0)
  pass              4138 ->  4138 (+0)
  ruffle_matched     235 ->   235 (+0)
  runtime_error        1 ->     1 (+0)
  effective         4373 ->  4373 (+0)
GAINS 0   REGRESSIONS 0   OTHER STATUS MOVES 0
```

`completed success` — every job green, **`wasm-link-smoke` included**, which is
the signal that actually matters for a change shaped like this one. `regression`
89/89, the new fixture among them (it is outside the 4498-test intersection
because it did not exist at the baseline).

**No-graphics**, run `33916672580` at `f0fd711c7`, `categories=full`,
`images=false`, diffed against `195ea700a`:

```
=== intersection: 4498 tests (195ea700a -> WORKTREE, results) ===
  output_mismatch    123 ->   123 (+0)
  pass              4138 ->  4138 (+0)
  ruffle_matched     236 ->   236 (+0)
  runtime_error        1 ->     1 (+0)
  effective         4374 ->  4374 (+0)
GAINS 0   REGRESSIONS 0   OTHER STATUS MOVES 0
```

`completed success`, `regression` 89/89. Both modes flat, exactly as the
`cpp -P` invariance proof said they had to be — and dispatched anyway, because
that proof covers the two CI *test* modes and says nothing about the browser
configuration, which `wasm-link-smoke` builds on every dispatch. Here it stayed
green in both runs; a green link smoke is not evidence the change WORKS (it
compiles and links, it never executes), so §4's browser measurements remain the
only evidence for that.

## 6. Folded in: the `MovieClipLoader.loadClip` browser probe

The brief's §5 allowed the previous slice's recommendation to be folded in if
the two gaps closed. They did, so it was: an MTASC parent that
`new MovieClipLoader()` / `addListener` / `loadClip("child.swf", _root.h)` into
a `createEmptyMovieClip` holder, plus a hand-built 3-frame child that traces
`c1`/`c2`/`c3`, places two named children and `stop()`s itself.

**MCL reaches the browser.** Same events, same order, same child frames, same
display children, same end state:

```
                       native                          browser
onLoadStart h          yes                             yes
c1                     yes                             yes
onLoadInit h cf:0 tf:1 yes                             yes
c2, c3                 yes                             yes
t3..t6                 cf:3 a:movieclip b:movieclip    identical
```

The one divergence is a **one-tick phase offset on the root's own
`onEnterFrame`**, not on the load: the browser dispatches an extra enterFrame
tick before the child's frame 2 runs, so `t1` reads `cf:0 b:undefined` where
native's `t1` already reads `cf:2`, and every later `t` row is shifted by one.
`t3` onward agree exactly. That belongs to the browser frame-loop phase family
(`browser_wasm_frame_func_rerun`, `mcl_load_timing`), not to the loaded-child
arc, and it is why this probe was not promoted to a checked-in fixture: a
stable expectation needs that phase question settled first.

Also noticed in passing, in **both** builds equally, so not a browser gap: an
MCL-loaded holder reports `_totalframes` **1** while its `_currentframe` walks
1→3. The direct-`loadMovie` fixtures read `tf:5` correctly, so MCL's
registration is not setting the holder's frame count. Filed.

## 7. What is left

* The MCL one-tick phase offset and the MCL `_totalframes` gap above.
* The `#if defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)` blocks the
  previous slice added to `swf.c` (the loaded-movie drains, the pending-removal
  finalize + dead-child reclaim) exclude the **native windowed** player, which
  defines neither macro. Nothing here measured whether that matters; it is the
  same shape of hole this slice found, one gate over.
