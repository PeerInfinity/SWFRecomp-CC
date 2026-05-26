# 2026-05-25 — Doodle Jump browser-WASM, audit session

Fourth handoff in today's chain:

1. `2026-05-25-doodle-jump-browser-investigation.md` — initial
   investigation + cycling-bug diagnosis.
2. `2026-05-25-doodle-jump-followup.md` — cycling fix landed
   (`98b388e46`).
3. `2026-05-25-doodle-jump-clip-events.md` — clip-event LOAD /
   ENTER_FRAME dispatch wired (`3ac27552e`).
4. **This doc** — 22-gate audit landed (`c9b11cc99`). Bug A fixed,
   bug B partially fixed.

**Branch state at writing:** `master`, ahead of `origin/master` by 1
commit. Working tree clean.

## TL;DR

- **Bug A FIXED.** Doodle Jump buttons now render the script-set
  labels "play" / "info" / "score" / "options" instead of the static
  "menu" placeholder. Menu state stable t02..t08 byte-identical
  (md5 `56f02ff55d139f5058c9dd65f4beeceb`).
- **Bug B partial.** Hero y-delta dropped 4× (from ~1080/sec to
  ~270/sec) — the collision check now sees `_root.block` properties,
  but bounce doesn't fully counter gravity. Hero still off-screen on
  the menu, never visible. Diagnosing the gameplay-side bug requires
  clicking through "play" in the probe, which doesn't currently happen.
- **Trigger:** the previous handoff hit instance ~5 of the
  "browser-WASM is the afterthought" gate-asymmetry pattern. This
  session committed to the systematic audit the first handoff
  recommended at instance 4.
- **No regressions.** Trace harness 407=407. Pong + Snake browser
  demos byte-identical to pre-audit.

## What landed: `c9b11cc99`

Audit dropped 22 `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)`
gates in `action.c` (~1430 lines of AS-visible behavior unblocked in
browser-WASM) plus widened `ng_setCTAlpha`'s declaration in `tag.h`.

The 22 gates fall into three groups:

### Group 1: `findOrCreateMovieClip` (5 gates)
The root cause of bug A's invisible textfield. When the recompiler
generated `this.button_txt = ...`, `actionGetMember(button_mc,
"button_txt")` resolved via `findOrCreateMovieClip("button_txt",
button_mc)` — but the 607-line text-field-init block in
`findOrCreateMovieClip` (lines 21014-21621) was gated. So
browser-WASM allocated an MC stub with no `ng_textfield_idx`, no
`__proto__` link to `TextField.prototype`, and no initial text/font
properties. The downstream `.text = "play"` write went into the MC's
dynamic_props as a plain string but never triggered the render-side
TF run table update (because `MC_IS_TEXTFIELD(mc)` returned false).
After widening, the same MC creation now runs the full TF init.

Sub-gates (also dropped): `findDisplayEntryInParent` definition,
the HTML-parse `tfRebuildFromHtml` (with `#else` fallback removed),
TF re-place check, canonical_name lookup.

### Group 2: `actionSetMember` (12 gates)
The setMember side of bug A. Even after fixing getMember resolution,
the `.text = "play"` write was hitting another gated block that did
the `tf_*` run table population, htmlText sync, autoSize recalc,
variable-binding notification, etc. Widened all 12. The two
`#else`-bearing gates with simpler fallbacks (`htmlText` HTML-parse
and Phase C TF notify) had their `#else` bodies removed and the
gated body kept.

The two gates kept (`scroll` / `hscroll` setters): both have real
`#else` forks that read `maxscroll` from a different cache in graphics
mode. Those are legitimate forks, not leaks.

### Group 3: `actionGetMember` (5 gates) + helper defs
Bug B's lookup path. The main "Check child instance names" path
(lines 49647-49805) — the single largest dropped gate — handled
both `this.button_txt` (MOVIECLIP receiver, non-underscore property)
AND `_root.block` (root receiver, non-underscore property, falls
through to root-level display_list scan). Without it, both lookups
returned undefined.

Sub-gates: underscore-shadow child resolution (lines 49044-49133),
textfield dimension dispatch (textWidth/textHeight), htmlText getter
+ styleSheet type filter, the `computeTextFieldDimension` /
`computeScrollProperty` helper function definitions (lines
47670-48248).

The 7 small gates kept in `actionGetMember` (`_x`/`_y`/`_xmouse`/
`_ymouse` readers + `_xscale`/`_yscale`/`_rotation` sync calls)
either have `#else` browser-WASM-specific code or just gate a single
`syncTransformIfNeeded` call. Not bug-blockers.

## Linkage fix: `ng_setCTAlpha`

`tag.h` declared `ng_setCTAlpha` only under `#ifdef NO_GRAPHICS`,
even though the definition in `tag_stubs.c` is unconditional. Once
the calling gate in `actionSetMember` was dropped, browser-WASM
got an implicit-int declaration that mismatched the void definition.
wasm-opt's validator caught it as a call/callee type mismatch.

Heuristic for future work: if dropping an AS-side gate uncovers
implicit-function-declaration warnings, the helper function's header
declaration probably has its own `#ifdef NO_GRAPHICS` gate that
needs widening to match.

## Remaining bug B: hero falls without fully bouncing

### Symptom

Hero (`_root.hero`, depth=9 in display_list) on the deployed menu
screen has `_y` monotonically increasing across snapshots:

| t   | y (pre-audit) | y (post-audit) |
|-----|--------------:|---------------:|
| t01 | 2056.6        | 1081.6         |
| t02 | 3136.6        | 1351.6         |
| t03 | 4801.5        | 1636.6         |
| t04 | 6646.5        | 1906.6         |
| t05 | 7846.5        | 2161.6         |

Pre-audit delta ~1080/sec. Post-audit ~270/sec. The 4× drop is
direct evidence that the collision check in `clip_action_26` is now
finding `_root.block` (it returns `root_depth=10` per my pre-final
instrumentation), reading its position, and applying SOME upward
impulse — just not enough to overcome gravity.

The hero is **not visible** on the menu canvas — `_y > 1000` is well
below the ~480 px canvas. The green doodle character at the top of
the menu (next to "v2.4") is a decorative graphic, not the hero MC.

### What's known
- `clip_action_25` (LOAD): sets `vy=0`, `gravity=4`, `yradius=hero._height/2`,
  `jump=false`, `jumpspeed=9` on the hero MC. Runs in browser-WASM
  (LOAD dispatch wired in `3ac27552e`).
- `clip_action_26` (EnterFrame): integrates `vy += gravity`, then
  `_root.hero._y += vy`, then collision check that should set
  `jump=true; vy = -jumpspeed` when hero touches block. Runs in
  browser-WASM (EnterFrame wired in `3ac27552e`).
- `_root.block` now resolves correctly (verified via debug printf in
  `actionGetMember` — `root_depth=10`, `findOrCreateMovieClip` runs
  full init path).
- The 4× slowdown is real: something in the bounce logic IS firing
  per-tick, but its upward magnitude is wrong (small relative to
  gravity acceleration).

### Likely root cause

Possibilities:
- `_root.block._height` or `_root.block._width` returns wrong value
  (0, undefined, or a different unit). Without those, the bounding
  box check might pass even when the hero is far below the block,
  triggering a tiny correction per tick.
- The hero starts BELOW the block (`hero._y > block._y` already at
  spawn) and the collision check's predicate isn't symmetric — it
  triggers a bounce but doesn't snap the hero back above the block.
- One of the bounce arithmetic operations reads a different value
  in browser-WASM than in graphics-native (e.g., `_yradius` was set
  via `this.yradius = hero._height/2` in LOAD, and `_height` in
  browser-WASM may differ).

### What I'd try first
1. Compare the per-tick AS state of `_root.hero._y`, `_root.hero._height`,
   `_root.hero.vy`, `_root.hero.jump`, `_root.block._y`,
   `_root.block._height` between graphics-native (`OFFSCREEN_RENDER`)
   and browser-WASM. Trace harness already proves they match for
   the first 30 frames in graphics-native — adapt that mechanism to
   dump from browser-WASM and diff.
2. Or click through to the gameplay screen in the probe by sending
   a click event to the play button's location (~ (160, 200) on the
   menu canvas), and observe the hero behavior in actual gameplay.

### Don't go chasing

The 4× slowdown is evidence of progress — the collision check IS
running. Don't revert any of the 22 dropped gates without first
confirming via the trace-harness style diff which value is wrong.

## How to reproduce
```
# Build & deploy
source emsdk/emsdk_env.sh > /dev/null 2>&1
SWFRecomp/scripts/build_test.sh flasharchive/Doodle_Jump wasm --graphics
SWFRecomp/scripts/deploy_example.sh flasharchive/Doodle_Jump \
  "$(pwd)/docs2/examples" --no-index --graphics

# Probe
source /tmp/pong-probe/venv/bin/activate
python3 tools/browser-test/probe.py flasharchive/Doodle_Jump \
  --wall-clock-seconds 8 --snapshot-interval-seconds 1 \
  --screenshot-timeout-ms 30000 --out /tmp/dj-probe-X
```

Pass criteria:
- Menu screen shows "play" / "info" / "score" / "options" buttons
  (NOT "menu" placeholder).
- `unique_canvas_sizes >= 2` from t01 stabilizing.
- t02..t08 byte-identical (the menu doesn't animate).
- Console: 0 errors, 0 page_errors.

Don't regress:
- Trace harness: `python3 tools/divergence/divergence_test.py
  SWFRecomp/tests/flasharchive/Doodle_Jump/test.swf --frames 30
  --skip-ruffle` → must report `407=407`.
- Pong (glaiel/Pong): `unique_canvas_sizes=1`,
  md5 `bb1f52f690672bd558f6e5c6b1c64301`.
- Snake (flasharchive/Snake): t02..t05 md5
  `a213fc90328ab539f9c9e7288670d498`.

## Don't-touch list

The 22 dropped gates are now interlocking: dropping them was correct,
but the 9 kept gates have real `#else` browser-WASM-specific code
paths. Specifically:

- **Don't drop** the `_x` / `_y` reader gates in `actionGetMember`
  (49208 / 49267) — they have real `#else` paths that read from
  `display_list` differently.
- **Don't drop** the `_xmouse` / `_ymouse` reader gates (49351 / 49359)
  — same reason.
- **Don't drop** the `_xscale` / `_yscale` / `_rotation` reader gates
  (49318 / 49323 / 49328) — they call `syncTransformIfNeeded`, which
  might cause real issues if invoked at the wrong time in browser-WASM.
- **Don't drop** the `scroll` / `hscroll` setter gates in
  `actionSetMember` (46861 / 46886) — `#else` reads `maxscroll`
  from a different cache.

## Pattern note (5th instance, formal audit landed)

Every browser-WASM bug today fit the template described in handoff
#1's pattern note. Today's audit was meant to clear the recurring
class of bug — but it touched only `action.c` and `tag.h`. There
are still 225 `NO_GRAPHICS || OFFSCREEN_RENDER` gates across the
codebase:
- 166 in `action.c` — many are legitimate (genuine graphics-mode
  forks like `_x`/`_y` readers) but more remain that may be hiding
  similar AS-leak bugs in other functions.
- 59 in `tag.c` — almost all are render-side and probably fine.

If a future browser-WASM-only bug surfaces, the diagnosis pattern is
now well-defined:
1. Find the AS path that should produce the missing value.
2. Search for `NO_GRAPHICS || OFFSCREEN_RENDER` along that path.
3. Drop the gate if (a) the gated body uses helpers available in
   browser-WASM (check `tag_stubs.c` / `ng_shared.c` / unguarded
   parts of `action.c` and `tag.c`) and (b) there's no `#else`
   branch with a clearly different storage model.

## Tools / state

- Local Ruffle source: `~/CC/ruffle`
- MTASC: `~/CC/mtasc/bin/mtasc`
- Probe venv: `/tmp/pong-probe/venv`
- Latest known-good probes:
  - DJ (audit landed, bug A fixed): `/tmp/dj-probe-final/`
  - Pong (regression baseline, unchanged): `/tmp/pong-after-audit2/`
  - Snake (regression baseline, unchanged): `/tmp/snake-after-audit2/`

Branch `master` is 1 commit ahead of `origin/master`:
- `c9b11cc99 browser-WASM: widen 22 NO_GRAPHICS||OFFSCREEN_RENDER AS-resolution gates`

Push when ready.
