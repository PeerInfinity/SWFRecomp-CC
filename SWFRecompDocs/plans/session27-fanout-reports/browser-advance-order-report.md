# s27 browser-advance-order: the browser advances timeline sprites in the CI order

**Slot:** local one-task session (brief: `browser-advance-order-prompt.md`). **Predecessor:**
`browser-eager-init-report.md` §3.1 (code `fe6eb5f9d`). **Base:** `eaa3e70f7` (this slot's own first commit, §2)
plus the coordinator's uncommitted text-render edits in `tag.c` / `ng_shared.c`, which are outside every hunk here.

**Landed:**
- `eaa3e70f7` (sent to the coordinator ahead of the rest): `action.c` declares `ng_rootDLEnter` / `ng_rootDLLeave`
  in every build. **Every browser build since `78fee9e13` trapped on the first root-scoped variable read** (§2).
- `swf.c` (browser-WASM and the native windowed player; CI-invisible, §4):
  - The pre-frame-func advance block is ungated. It is the OFFSCREEN block verbatim: Phase 3 early
    (`exec_order_nested_early`, now compiled in every swf.c build), `advance_sprite_frames` under
    `g_advance_defer_nested`, the attached-clip pump (already shared), and `presync_nested_sprite_currentframe`
    when Phase 3 is not early.
  - After the frame func, the browser runs Phase 3 (`advance_nested_sprite_frames` unless it ran early) and the
    `AQ_KIND_SCRIPT` drain. This is the OFFSCREEN slot, placed before the browser's dynamic-MC eligibility mark, so a
    clip a Phase-3 script creates is marked this tick (the OFFSCREEN order).
- `tag.c`: `tagShowFrame`'s browser arm no longer advances anything. The `advance_sprite_frames` +
  `advance_nested_sprite_frames` pair is gone, and so are `g_browser_tick_advance` and its `placed_at_tick` skip in
  `advance_sprite_frames`: a sprite placed this tick is now placed after the tick's advance, as in CI.
  `advance_attached_clip_frames`, the sprite-initialized upgrades, `finalize_pending_removes_recursive` and the
  `AQ_KIND_LOAD` drain stay where they were.
- Fixture `regression/avm1_browser_eager_init` gains the `inner f2` row (§3.3 below). Golden = the Flash 32
  projector = the Ruffle exporter; oracles are in `w2-local-oracles/browser-advance-order/`.
- `tools/browser-test/child_probe/build_child_probe.sh` links with `-Wl,--fatal-warnings` (§2).

**The parked-frame re-run needed no special case.** The browser still re-runs `frame_funcs[current_frame]` every
tick while parked, with the root DoAction suppressed. That re-run now carries only tags, the in-frame drains and
`tagShowFrame` (render pump, button states, Phase-2 init). The advance sits outside the frame func, so it runs once
per tick whether or not the frame func runs. That is also true past the last frame, where the browser used to stop
advancing.

## 1. Rows, real browser build (`tools/browser-test/child_probe/`)

Both columns use the same generated C and the same `action.c` (HEAD + the extern fix). "Before" is relinked with
`swf.c` / `tag.c` from `eaa3e70f7`, "after" with this patch. The comparison drops blank lines and the WebGPU console
warnings. The native column is the passing golden.

| Row | Browser before | Browser after |
|---|---|---|
| regression `avm1_browser_eager_init` (now with `inner f2`) | **6 diff lines**: `root f2 1 1`, `root f3 2 2`, `inner f2` after `outer f2` | **matches** |
| regression `avm1_browser_gated_{textfield,depth,color}` | match | match |
| regression `avm1_parent_child_render` (loaded child) | match | match |
| avm1 `transform`, `duplicate_movie_clip`, `color`, `movieclip_create_text_field` | match | match |
| avm1 `movieclip_getbounds` | 20 lines vs `output.txt` | the same 20 lines. **Byte-identical to native's actual output** in both columns (§3.2) |

Fixture traces:
```
browser before                 browser after = Flash 32 = Ruffle = native (both CI modes)
load movieclip 1               load movieclip 1
inner f1                       inner f1
outer f1 movieclip 1           outer f1 movieclip 1
root f1 movieclip 1 1          root f1 movieclip 1 1
root f2 1 1                    inner f2
outer f2                       outer f2
inner f2                       root f2 2 2
root f3 2 2                    outer f3
outer f3                       root f3 3 2
root f4                        root f4
```

## 2. The HEAD browser trap (`eaa3e70f7`)

The first "after" build stopped after `outer f1`. `root f1` never printed, the page stayed responsive, and there was
no pageerror. The link log had the cause: `wasm-ld: warning: function signature mismatch: ng_rootDLLeave`.

`78fee9e13` added a root-scoped lookup to `actionGetVariable` (`_GV_RDL_LEAVE`). That code is compiled in every
build. The `extern` declarations of `ng_rootDLEnter` / `ng_rootDLLeave` sat under
`#if NO_GRAPHICS || OFFSCREEN_RENDER`. So the browser compiled an implicit `int ng_rootDLLeave(...)`; `tag.c` defines
it `void`; wasm-ld only warned and linked a stub that traps when called. The first root-scoped variable read in any
browser build ended the frame loop. Fix: the two declarations are ungated (CI preprocess text unchanged; `tag.c`
defines both ungated). I committed it alone because the coordinator needed it before its Pages deploy.

**Guard:** a clean browser link has **zero** wasm-ld warnings (checked on every child_probe row after the fix).
`build_child_probe.sh` now links with `-Wl,--fatal-warnings`; every row in §1 built with it. `build_test.sh` and
`bundle/build.sh` are not changed. Their link inputs differ (AVM2 sources, other bridges) and I did not survey them
for other warnings. `-Werror=implicit-function-declaration` is **not** free either: `action.c` still calls an
undeclared `ng_find_textfield`, which is benign on wasm32 (int and pointer are both i32).

## 3. The brief's other leads

### 3.1 Per-tick advance order: done (above)

### 3.2 `getBounds` "1-twip residual": overturned, not a browser gap
`avm1/movieclip_getbounds` has `[approximations] epsilon = 0.051` in its `test.toml`. **Native prints the same values
the browser does** (`72.45` / `-57.3` / `469.55` / `521.85` / `-99.95` where Ruffle's golden has
`72.5` / `-57.25` / `469.5` / `521.9` / `-99.9`), and passes only through that epsilon. child_probe diffs exactly
against `output.txt`, so it reported a "browser residual" that every build has. I checked this three ways:
- browser trace = native `test_run` output, byte for byte;
- an instrumented native copy and an instrumented browser copy compose the same per-step float matrices
  (`la=1.41421509 … 0.353561401 / -0.353546143`) and land on the same twip (1449, where Ruffle has 1450);
- `verify_output.py --test=movieclip_getbounds` passes.

If someone wants it exact, it is a Ruffle-vs-ours precision question on the cross-space matrix (CI-visible, all
builds), not browser work. Check Flash first: Ruffle's own epsilon suggests Flash rounds differently again.
**Lesson:** for a test with `[approximations]`, compare the browser against native's ACTUAL output (the gen dir's
`test_run`), not against `output.txt`.

### 3.3 Nested frame-2 order: fixed in CI on HEAD (by `78fee9e13`), now in the browser too
With `inner` tracing on its frame 2, Flash 32 and the Ruffle exporter print `inner f2, outer f2, root f2`. Native
HEAD now passes that in **both CI modes** (local `verify_output.py`, graphics and no-graphics), thanks to
w2-exec-order-land's Phase 3 early. The browser printed `outer f2, inner f2` before this patch and matches now. The
row is in the fixture; the variant SWF is byte-identical to the committed `test.swf`.

## 4. CI define sets (preprocess md5, `#include` lines stripped, blank lines dropped)

`eaa3e70f7` → `eaa3e70f7` + this patch's hunks (only mine; the coordinator's uncommitted `tag.c` edits are
excluded from both sides):

| File | graphics | graphics + `HEADLESS_RENDER_ENABLED` | no-graphics | browser |
|---|---|---|---|---|
| `tag.c` | `408f4e42` → same | `21b61941` → same | `95cd1472` → same | `cb4d551e` → `a266fbcb` |
| `swf.c` | `8091d232` → same | `8091d232` → same | (empty) → same | `67ba67f6` → `cca9cf26` |
| `action.c` (`eaa3e70f7`, vs its parent) | `cf9eb8ab` → same | `cf9eb8ab` → same | `6ffb4b31` → same | `29ef42b7` → `9608340f` |

**CI-invisible in every CI define set.** The only CI-visible change is the fixture's new `inner f2` row, which
passes locally in both modes.

## 5. Games (WSLg Chrome = SwiftShader: function only, never perf)

**N, seeded browser builds** (`EMCC_CFLAGS=-DMOCK_DATE_TIME=981152406000`, `routes_ep0.txt`,
`START_LEVEL=<n> AUTOKILL=true OBJHASH=true FREEZE=""`), compared with the Ruffle exporter on the same SWF
(`-f 1800`). NF lines are compared on every field, including `h=` / `o=`.

| Level | NF ticks | ND events / phase `frame=` | Note |
|---|---|---|---|
| L4 lockness | **984/984 identical** (second run) | all equal | First run: 1 tick (`a=1 t=113`) differed in `h=` Σx/Σy only, then rejoined. It did not reproduce on a rebuild of the same source, nor in an L4 run with `CLIPPOS`/`CLIPDIFF`. HEAD swf.c/tag.c on the same SWF: 984/984. I read it as a run-time flake (FRAMELOCK slack under SwiftShader); it is unattributed. |
| L2 thwumps | **1266/1266 identical** | all 18 equal, **including every `frame=`** | memory recorded a 1-frame `frame=` drift after the death here before; none now |
| L1 cloud city | **1315/1315 identical** | equal up to the run's end | the last 2 exporter lines (frames 1717–1738) fall after my capture window |

With `CLIPDIFF`, two `clip+`/`clip-` lines swap places within one tick (t=162, t=191). That is for-in enumeration
order over the probe's own `cur` object; the set and `cf` values are equal. I did not measure it on the old build.

**Menus** (`demo.html`, GPU readback via `dbgCapturePNG` + `getDisplayListJSON`, 0 console errors on each):
- Pacman: title, then a held click on PLAY GAME reaches the maze with "GET READY!" (41 display entries).
- Minesweeper: start screen with registerClass radios ("Easy (40 mines)" / "Medium" / "Tough"), name field, Start.
- Doodle Jump: menu with the play/info/scores/options labels that `onClipEvent(load)` sets, hero on the pad.

An instantaneous Playwright `mouse.click` (down and up in one frame) on PLAY GAME only hovered. A press held for
300 ms works. **Pre-existing**: a Pacman build with HEAD `swf.c` / `tag.c` behaves the same. Probably a press and
release consumed within one tick; not investigated (Flash counts that as a click). Drive browser buttons with a held
press.

## 6. What is left

- **`build_test.sh` / `bundle/build.sh` guard.** Survey their browser links for wasm-ld warnings. If there are none,
  add `-Wl,--fatal-warnings` there too. That is the build the Pages deploy ships. Price S.
- **Remaining browser-only arms in `tag.c` / `swf.c`:** the `pending_remove` deferral + `finalize_pending_removes`,
  the parked-frame re-run itself (the browser runs the frame func while stopped; CI gates it on
  `is_playing || manual_next_frame`), `advance_attached_clip_frames` in `tagShowFrame`, and the OFFSCREEN-only
  `ng_apply_pending_sprite_self_gotos`. The native `SWF_BROWSER_ARMS_TU=action.c` harness still cannot see any of
  them, so confirm in child_probe or with a game route (oracle: the N routes, now tick-exact on L1/L2/L4). Next
  slice candidate: **the browser's parked-frame re-run vs CI's gated frame func**, with a fixture where a stopped
  root's re-run tags matter (a RemoveObject/PlaceObject pair on the parked frame). Price M.
- `graphics_stubs.c` Group 1 still stubs `ng_queue_placement_clip_events` / `ng_queue_slot_unload_events` for the
  browser (browser-eager-init §3.4). No row measures it yet.
