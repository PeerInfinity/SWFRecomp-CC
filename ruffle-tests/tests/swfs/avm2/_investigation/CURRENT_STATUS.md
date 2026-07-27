# avm2 Suite — Current Status

Last updated: 2026-07-19 — **RWK base-compute lever 1 LANDED
(`8caf10e4e`, findpropstrict scope-hit inline cache)**: RWK browser
gameplay 219→165 ms p50 on the real-GPU rig (1.33x; rAF p95 1.48x), native
GC=0 TAS 1.54x, 98.7% of findpropstrict volume now replays from the IC.
Suite impact: **zero** — 823/1215 unchanged, "No changes detected" in every
suite diff, both CI modes. Arc log + next-lever map (GET residue ~23%,
coerce ~11%, IC guard inlining ~9%):
`tools/divergence/perf/RWK_AB_STATUS.md`. Ruffle gameplay anchor is
6.4 ms/frame — the road to 30 fps continues next session.
Prior: **Robot Wants SEQUELS (Puppy, Fishy, Ice Cream)
ALL STAGES DONE**: all three are playable headless with zero uncaught
errors, their menus match Ruffle (MAD 2.334 / 0.001 / 0.200), and all three
browser demos are LIVE — on ONE runtime fix
(`flash.net.LocalConnection`). Prior: RWK AP handoff page DELIVERED
(`docs2/examples/avm2/rwk_ap/`, 13/13 livetests incl. the live teleport).
Prior: live-census growth FIXED (weak orphan registry): Seedling-teleport
idle 9.5 -> ~0 KB/tick, menu 2.0 -> ~0; live object/string counts dead
flat. Prior: raw-alloc reclamation (2026-07-17), collectable strings
(2026-07-16), RWK-3 (browser demo + wasm heap gate), RWK-1/2, Stage 12
sessions.

## Loader / LoaderInfo — tranches 1–5 SHIPPED (2026-07-26/27)

Full plan + per-tranche postmortems:
**`SWFRecompDocs/plans/loader-arc.md`** (per-test triage of all 35
`loader*`/`loaderinfo*` tests, 8 ranked tranches; §5 covers 1+2, §6 covers
3+4, §7 covers 5). The "flash.display.Loader (deferred)" line in the Stage
8/9 notes below is now out of date.

- **Tranches 1+2** (`8213dd4d6`, CI `30226375815`): **+12** (predicted 8).
  Per-instance `LoaderInfo` state machine — every getter now keys on the
  receiving instance's stream state, `stage.loaderInfo` is a distinct
  never-`init`ed object, `#2099` from the eight movie-describing getters
  while NotYetLoaded — plus the load pipeline without content
  (open/progress/complete/ioError, byte accounting, `#2124`).
- **Tranches 3+4** (`f6ba5c677` + `28577da2a`, CI `30230575524`): **+6**
  (predicted 4). Image payloads decode through stb into a
  `BitmapData`/`Bitmap` `content`, and `URLLoader` really reads bundled
  sibling assets.
- **Tranche 5** (navigator fetch log, `a9900a478`): **+2 in this suite** —
  `net_navigateToURL`, `navigateToURL_target_normalize` — plus 2 in avm1
  (see that suite's status). The runtime now emits Ruffle's
  `TestNavigatorBackend` request log under `-DLOG_FETCH` (set from
  `log_fetch = true` in `test.toml`), shared between both VMs in
  `SWFModernRuntime/src/utils.c`. **Neither predicted test landed:**
  `loader_load` reaches 124/128 and stops on Ruffle's hash-ordered property
  enumeration (`avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`
  §"AVM2 dynamic-property enumeration order"), and `loader_method` sits at
  83/85 waiting on uncaught-error tracing.

Findings worth having here rather than only in the plan:

1. **The load timing model is Ruffle's async executor, not "one frame
   later".** A fetch resolves *after* the frame that issued it, and a load
   started by the resulting `complete`/`ioError` handler resolves in the
   **same** drain — `loader_bitmap_transparency` chains three loads inside
   `num_ticks = 2`. Separately, init/complete are not uniform: an image's
   fire inline out of `movie_loader_complete`, a child SWF's wait for the
   clip's own `on_exit_frame` one tick later.
2. **A malformed image is not an ioError.** Ruffle's `decode_png` hands back
   an empty bitmap at the header's declared dimensions
   (`loader_loadbytes_invalid_png`), so a failed full decode falls back to
   `stbi_info_from_memory` + transparent pixels.
3. **AOT is not the blocker it looks like.** `verify_output.py` already
   recompiles every sibling `.swf` of a test at build time and registers it
   in `findMovieEntry(filename)` (the AVM1 `loadMovie` path). The child
   SWFs these tests load are already in the binary; the remaining gaps are
   that `MovieEntry` has no AVM2/ABC entry point and carries no bytes, that
   `download_tests.sh` drops nested `child/child.swf` children, and that
   `loadBytes` needs a bytes→movie identity (resolvable at build time in
   every corpus case). That is tranche 6, the one large item.

A fifth finding, from tranche 5, and the most reusable thing in it:
**uncaught AVM2 errors are TRACED**, not just logged. Ruffle's
`Avm2::uncaught_error` runs `error.to_string()` — the value coerced to a
string plus the call stack the Error captured — through `avm_trace` whenever
the player is in Debug mode, which the test harness always is. Our
`print_uncaught` writes only to stderr. Implementing it is worth **+4**
(`uncaught_error_basic`, `loader_method`, and lines in
`event_handler_exception` / `uncaught_errors_stringified`) but it **cost 65
net passes in CI `30235525066` and was reverted** (`d1c307c51`): **288
corpus tests expect ZERO trace lines** (image-only, graded on the render) and
55 of them pass today by printing nothing while swallowing an error we throw
and Ruffle does not. loader-arc.md §7 carries the census of the ~18 causes —
Stage3D `context3D` undefined (21), `fscommand` (8), `ShaderJob` (6),
`BlurFilter`/`ColorMatrixFilter` (6), and a dozen singletons. **Re-land
`git revert d1c307c51` at the END of the Stage3D / PixelBender / filters
work**, where it becomes a tripwire against exactly this failure mode.
Related: parameter coercion is attributed to the CALLER (Ruffle coerces the
signature in `init_from_method`, before the callee's call-stack frame
exists), so a `#1034` from an argument prints `at Caller/method()`.

**`avm2/edittext_align` is a NONDETERMINISTIC graphics-CI segfault** (all
60/60 lines correct, then SIGSEGV; ~50% per run; byte-identical builds give
both outcomes — loader-arc.md §7 has the run table). It is a real
pre-existing bug, not a flake to dismiss and not attributable to any recent
commit. Expect the corpus segfault count to flicker 0/1 on unrelated work
until the graphics job captures a core dump.

Reachable: 12 of the 19 remaining avm2 failures (+ up to 9 in
`from_shumway/as3-loader`). Next up is tranche 6 (AVM2 child-SWF execution,
+6 and up to 9 more in from_shumway) — the one large item in the arc.
Won't-do: `loader_applicationDomain` (needs the real Flex framework SWZ).
`mouse_pick_loader_avm1` belongs to the dual-VM arc. Note the earlier
won't-do call on `loader_jpegxr`/`loader_jpegxr_alpha` was **wrong** — they
only trace `contentType`, so a magic-byte sniff passed both without any
JPEG-XR decoder.

## Robot Wants sequels — Puppy / Fishy / Ice Cream (2026-07-18)

Plan + full census: `SWFRecompDocs/plans/avm2-robot-wants-sequels.md`
(source of truth). Template: the RWK plan. Three more Flixel/AS3 games on
the AVM2 runtime, taking the count of real AVM2 games from 2 to 5.

**Result: stages 1-3 (census, headless bring-up, gameplay probe) complete
for all three, on exactly one runtime fix.**

| Game | SWF ver | ABC bodies | verify_fails | New ops | Runtime fixes | Heap peak |
|---|---|---|---|---|---|---|
| Puppy | 9 | 1578 | 0 | 0 | none | 330 MB |
| Fishy | 10 | 1241 | 0 | 0 | LocalConnection | 1577 MB |
| Ice Cream | 10 | 1370 | 0 | 0 | LocalConnection | 1770 MB |

**Census: no new opcode or verifier surface.** These are our first AVM2
games above SWF v9, and the version bump brought nothing new — every op a
sequel uses that RWK does not is already implemented. The sponsor chains
(GameShed/Kong/MD5/Network) are dead in all three by the same mechanism as
RWK: `xplor.Version.v = "Plain"`. Flixel is 2.21 (Puppy) / 2.35 (Fishy,
Ice Cream); the 2.35 delta is `FlxPreloader` + `FlxMonitor` added and
`FlxEmitter` removed. Fishy's water/swim is a plain second `FlxTilemap`
layer plus game code, not an engine feature.

**The one fix: `flash.net.LocalConnection` (`avm2_globals.c`).** Fishy and
Ice Cream gate their entire boot on `new LocalConnection().domain` as the
first instruction of the preloader; the class did not exist, so both died
with Error #1065 before Flixel started. The `locallock` "site-lock" is an
anti-local-copy stub whose whitelist array is EMPTY — any domain except
`"localhost"` passes, so nothing needed spoofing and no SWF was patched.
`domain` now mirrors Ruffle's `LocalConnections::get_domain` exactly:
`file://` and IP literals -> `localhost`, unparseable -> `unknown`,
otherwise the exact host (AVM2 uses the host, not AVM1's superdomain);
userinfo and port are stripped. connect/send/close/allowDomain are no-ops.
Graded by new regression test **`avm2_localconnection_domain`** (mxmlc;
expectations captured from Ruffle, byte-identical).

**GOTCHA — a silent blank-stage boot death reads as a PASS.** Fishy's
pre-fix run produced no output at all, so the harness reported PASS against
an empty `output.txt`. For a game bring-up, absence of trace output is not
evidence of success; dump frames (`AVM2_CPU_DUMP`) before believing it.

**FlxText carried over for free** — RWK-2's `bd_draw(TextField)` glyph
rasterization renders every menu button, help text, and HUD label in all
three games with no further work. This is the main reason the bring-ups
were cheap.

**Stage-5 (browser demo) blockers, measured now so they are not
rediscovered later:**
1. `build_wasm_avm2.sh` hardcodes `-DSWF_URL="file:///test.swf"`, which
   yields `domain == "localhost"` -> Fishy and Ice Cream blank-stage
   themselves. The demos must be built with an http `SWF_URL`.
2. Heap. Against the 1984 MB wasm arena, Ice Cream peaks at 1770 MB
   (~214 MB headroom) and Fishy at 1577 MB — versus RWK's 1409 MB, which
   already OOMs in-browser after ~6-7 min. Same `FlxTilemap.arrayToCSV`
   transient-string garbage, scaled by map size and layer count (Ice Cream
   runs three tilemap layers). Puppy at 330 MB is unaffected. The
   collectable-strings / eden-arena follow-up is the real fix.

**Stage 4 (menu render parity, state-aligned by offset scan — the RWK-1
wall-clock `getTimer` gotcha):** Puppy MAD 2.334 / 5.74% px with the whole
diff confined to two animated decorations (title art, every button and
label, credits all 0.00% differing); Fishy MAD 0.001 / 0.00% px, i.e.
pixel-perfect; Ice Cream MAD 0.200 / 0.45% px, the diff a 64x54 box around
the bobbing ice-cream cone (the analogue of RWK's kitty-UFO artifact). The
drift rate varies per game (Puppy 2.2x, Fishy ~1.04x) so tick offsets are
NOT reusable across games; export ~700 oracle frames, since 300 left Ruffle
still on Puppy's splash.

**Stage 5: all three demos LIVE** — `docs2/examples/avm2/{rwp,rwf,rwic}/`,
catalog entries added, each verified in headed Chrome on real WebGPU: menu
renders, zero page errors, live mouse tracking confirmed. Fishy and Ice
Cream are built with `SWF_URL="http://www.maxgames.com/test.swf"` (the
former hardcoded `file:///test.swf` in `build_wasm_avm2.sh` is now an env
override with an unchanged default).

**Still open:** PlayState in-browser is UNMEASURED for Fishy and Ice Cream.
`probe.py`'s synthetic click hovers the menu button correctly but never
fires it — Flixel's `FlxButton` needs press and release on separate ticks
and Playwright's down/up land in one event-loop turn. Probe tooling, not a
demo defect (RWK-3 verified the live-mouse path), but it leaves the heap
question unsettled, so make no browser-gameplay claim for those two yet.
Two probe gotchas worth keeping: pass
`--screenshot-timeout-ms 40000 --load-timeout-ms 60000` or the `#btn-run`
click times out at 8 s on a 12 MB wasm; and `--click/--move` coordinates
are CSS pixels of the displayed canvas (779x585 here, ~1.217x), NOT the
game's internal 640x480 space — headless `input.json` files are the
opposite.

## RWK Archipelago handoff page (2026-07-18)

**`docs2/examples/avm2/rwk_ap/` is the Robot Wants Kitty counterpart of
`seedling_teleport_ap/`** — the injected RWK SWF (original +
flash-ap-api `BridgeGeneric` DoABC, canonical artifact owned by
Archipelago-CC and consumed read-only) packaged as a self-contained
same-origin-iframe game page. **Zero runtime and zero recompiler changes
were needed** — §4 of the RWK plan predicted this and it held exactly.

**Host usage** (identical to Seedling): load `game.html` as a SAME-ORIGIN
iframe, call `__swfBridgeStart()` from a user gesture INSIDE the iframe
(WebGPU/audio consume the activation), then drive
`contentWindow.__swfBridge` — `game.wireCheck()/configure(json)/
readState()`, `queueItems()`, `onStateChanged`.

**Unlike Seedling, ONE SWF reaches the full grade.** Seedling needed a
separate teleport build because `Main.SAVE_FILE` is set in a constructor
behind the NG preloader click, so unattended runs could not grade the
write path. RWK has no preloader gate and `robotkitty.json` carries a
config-driven teleport (`remove_last_child` of LogoState's stray
logoBitmap + `new_instance` of `xplor.PlayState` into `FlxG.state`, then
`path_write` of the live Player's x/y), so the single injected SWF goes
title screen → gameplay → write → apply → re-report.

**No-op parity re-verified at current HEAD** (stronger than a trace
diff): `--check-abc` OK (2 abc_tags, 812 bodies, 0 verify fails); fresh
recompiles of injected + plain; native NO_GRAPHICS 300 ticks stdout +
stderr byte-identical; native **graphics 300 ticks: 300/300 CPU-dumped
frames byte-identical** (stderr differs only in the dump filenames).

**Livetest — `ruffle-tests/tests/swfs/_swfbridge/livetest/rwk_avm2/`,
13/13 PASS** (`run_rwk_livetest.sh`). Behavior A (no shim): game boots,
zero `[BridgeGeneric]` output, no page errors. Behavior B drives the
DEPLOYED `game.html` in a same-origin iframe via `contentWindow`, exactly
as `flashSubstrate/bridge.js` does: bridge alive → `wireCheck` →
`configure(robotkitty.json)` (0 properties, 2 path reads, 1 class
resolved) → `xplor.PlayState` resolved → pre-teleport `readState` =
`{"player_x":null,"player_y":null}` (correct: no live Player on the title
screen) → teleport queued → `RemoveLastChild` + `new xplor.PlayState()` +
`PathWrite .x/.y` → `stateChanged("player_x", 1072)` outbound →
post-teleport `readState` = `{"player_x":1072,"player_y":1202}` (y
settled from the written 1200 under gravity — live physics, not an echo).

**Memory gate (native `AVM2_HEAP_STATS`, injected vs plain @600 and
@1200 ticks) — the cleanest no-op evidence in this arc:**

| build    | allocated @600 | allocated @1200 | growth/tick |
|----------|---------------:|----------------:|------------:|
| injected |     23,487,168 |      25,266,816 |  2.897 KB   |
| plain    |     23,403,648 |      25,183,296 |  2.897 KB   |

The deltas are **equal to the byte** (1,779,648 B each), so the dormant
bridge costs **0 bytes/tick**; the injected build's entire footprint is a
**constant 83,520 B** (the BridgeGeneric ABC), identical at both tick
counts. (2.897 KB/tick is the TITLE-SCREEN figure — not comparable to the
1.008 KB/tick gameplay number from the plan_k TAS measurement.)

**FIXED 2026-07-18 — the HUD live counts are now real for AVM2.**
Previously `avm2_main.c` passed literal `0, 0` to `swf_perf_report`, so an
AVM2 page's HUD always read 0 and any "flat census" gate built on it passed
vacuously (the RWK AP session built one, caught it, and replaced it). The
AVM2 frame loop now passes `avm2_gc_live_objects()` and
`avm2_gc_live_strings()`; the HUD label reads `live AS objs N
arrays/strings M` (slot 2 is VM-dependent — AVM1 arrays, AVM2 strings —
hence the neutral label; the `EM_JS` in `libswf/swf.c` is shared).
`avm2_gc_live_bytes()` exists in `avm2_gc.h` but is NOT wired to JS (the
two HUD slots are `int`).

**Write browser-side AVM2 memory gates against a SAWTOOTH, not a flat
line.** These are post-collection live censuses sampled between
collections, so they ramp and then drop when the GC runs. Measured on
`demo.html?test=avm2/rwk` (2026-07-18, idle title screen): objs climb
~2400→5500 and strings ~8k→125k over ~60 s, then a collection drops them
to ~3400 / ~15k and the ramp repeats at the same slope. The gate is
"successive cycle PEAKS don't grow", not "the number is constant".
Native `AVM2_HEAP_STATS` remains the precise per-tick instrument.

**Perf note:** a frame-rate A/B under WSL cannot resolve bridge cost —
WSL headed Chrome software-renders RWK at ~200 ms/frame, so the render
path swamps everything. `run_rwk_livetest.sh --gates` therefore times the
inbound EI round trip directly and soaks for bridge-active survival. The
authoritative frame number remains the real-GPU rig (RWK-3: 5.1 ms/frame).

**Gate results (`--gates`, 2026-07-18):** inbound EI round trip
**1.049 ms/call** (300 `readState()` calls in 314.7 ms — each a full
JS → `avm2_ei_dispatch` → BridgeGeneric → 2-path walk → JSON → JS trip).
Bridge-active gameplay soak **10.0 min / 1984 frames / 1974 readState
calls: zero aborts, zero page errors, still ticking and still answering
`readState` at the end** — comfortably past the 6-7 min window where
RWK-3 (pre collectable-strings, pre weak-orphan-registry) OOM-exited the
browser at ~94 MB/min.

## Live-census growth — weak orphan registry (2026-07-18)

**The last AVM2 Seedling leak is fixed** (prompt
`SWFRecompDocs/prompts/avm2-live-census-growth.md`). The ~9.5 KB/tick
Seedling-teleport idle growth was LIVE census growth: exactly **2
TextField objects + 6 strings per tick** (2 auto `instanceN` names + 4
empty strings) stayed reachable — the FlashPunk HUD creates temp
`new TextField()`s per frame, draws them into a BitmapData, and drops
them, but `avm2_display.c`'s orphan registry (`g_orphans`) enrolled each
at construction and marked them all as **strong** GC roots forever.
Ruffle's `OrphanManager` stores `DisplayObjectWeak` explicitly ("we don't
want to keep these objects alive if they would otherwise be
garbage-collected... matches Flash's behavior").

**Fix:** the orphan registry is now weak — `avm2_gc_mark_roots_display`
no longer marks orphans; `avm2_display_gc_prune_dead_orphans()` (called
by `gc_collect` after a *completed* mark, before sweep) drops entries
whose object went unmarked. Orphan tests stay deterministic under GC
stress because listener-bearing orphans remain rooted via the
(deliberately strong, unlike Ruffle's weak) enterFrame broadcast
registry, and `goto_on_orphan`'s clip is a class member.

**Measured:** teleport idle live census flat at 14,565 objects / 6,810
strings from collect #11 through #91 (was 15.2k→19.5k / 8.6k→21.3k);
allocated 56.0 MB @300 → 55.9 MB @2400 ticks (was +9.5 KB/tick, 81 MB
@2400). Stock menu flat at 2,219 / 1,396 (was +1,290 obj + 1,290 str per
cycle, ~2.0 KB/tick). RWK unchanged: 1.008 KB/tick (prior 1.03), traces
byte-identical, absolute footprint −5 MB (79.15 MB @1560).

**Verification:** teleport + menu traces byte-identical
normal/stress/GC=0 at 300 and 2400 ticks; 3 `avm2_gc_*` regression tests
pass in all 3 modes; 11 sampled suite tests (orphan ×4, xml_advanced,
broadcast_event, event_bubbles, closures, edittext ×2, timer)
byte-identical default vs stress, no status changes.

## Raw-alloc reclamation (2026-07-17)

**The census-invisible ~39.5 KB/tick RWK gameplay leak is fixed** (prompt
`SWFRecompDocs/prompts/avm2-scratch-reclamation.md`). Measured attribution
(RWK native, plan_k gameplay TAS, allocated delta over ticks 1560→3000):

- Baseline: **39.55 KB/tick** (135.6 MB @1560 → 192.6 MB @3000).
- Fix 1 — EditText relayout tree (`et_relayout` freed nothing: old layout
  tree, autosize probe tree, UTF-16 `units`, grow-abandoned line/box
  buffers): → **27.66 KB/tick** (−11.9, ~30%). The Flixel HUD rewrites
  `text=` every frame, leaking a full layout tree per tick.
- Fix 2 — per-call scratch (BitmapData.draw(TextField) glyph path: `gl`
  placements + `units` + xs/ys/cx/cdir scanline buffers, per HUD blit per
  frame; Array/Vector sort scratch): → **1.03 KB/tick** (−26.6, the
  dominant share). t1560 level 121.5 → 85.4 MB.
- Fix 3/4 — GC-sweep reclamations (dyn-prop tombstone purge on live
  objects + newactivation/newcatch per-object vtables gated on `no_index`
  + synthetic catch classes via `AVM2_CLASS_FLAG_SYNTH_CATCH` + swept
  TextField EditText ext/layout/spans): steady-state share 0 in RWK, but
  closes two unbounded-growth classes and drops the level ~1 MB.
- Final: **1.03 KB/tick** (97.4% eliminated), 84.4 MB @1560 → 85.9 MB
  @3000. Seedling/browser headroom at this burn rate ≈ many hours.

**Deliberately NOT freed:** closure `fn_scope` chains — aliasing confirmed
(`newactivation` stores `act->outer` as `method_scope` in activation
vtable entries; an activation can outlive its defining closure), so
freeing at closure sweep would be a UAF. Over-retained per the GC rule;
this is the bulk of the residual ~1 KB/tick.

**Verification:** RWK 600-tick traces byte-identical normal/stress/GC=0;
350 frame dumps pixel-identical normal vs stress; the two
`avm2_gc_string_*` regression tests + new `avm2_gc_dynprop_tombstone_purge`
(delete→re-add for-in order stable across purges; mid-iteration delete
unshifted; cursor reset re-derives) pass in all three GC modes; 11 sampled
edittext/sort/bitmapdata suite tests identical default vs stress.

## Collectable strings (2026-07-16)

**Heap `Avm2String`s are now a swept species** (prompt
`SWFRecompDocs/prompts/avm2-collectable-strings.md`). `Avm2String` gained
appended GC fields (`gc_next`, `gc_flags` — static pool entries stay
all-zero/rodata and are never written); the two constructors
(`avm2_string_new`/`avm2_string_concat`) enroll in a string census;
`avm2_gc_mark_value` marks string values; marking is byte-range-based
(interior-pointer tolerant — dyn-prop names are by-value copies sharing the
census string's inline bytes); the conservative ext scan also matches
string ranges, covering every depth-0 ext string field. Precise tracer/root
extensions: EDListener.type, EditText text/html/restrict + span/default
formats, StyleSheet selectors+formats, `g_aliases` (registerClassAlias),
`ctx->dxns`, Timer/Mouse.cursor statics, and an **E4X all-nodes registry**
(every immortal E4XNode's local/text/ns strings marked as roots each cycle
— robust against raw field stores; also closes the latent `notify`
object edge). Kill switch: `AVM2_GC_STRINGS=0` disables the string sweep.

**Measured (RWK native, plan_k gameplay TAS, 1560 ticks incl. PlayState
boot):** allocated 1467 MB → **129 MB** (boot spike reclaimed); menu leak
23.8 KB/tick → **flat**; gameplay steady-state 67.4 → 39.5 KB/tick with the
string census dead flat (14,948 live strings at t1560 and t3000). Traces
byte-identical GC-on/GC-off/stress. Seedling menu: stress-identical, flat.

**Residual (follow-up, NOT strings):** the remaining ~39.5 KB/tick of RWK
gameplay growth is non-census raw `avm2_alloc` churn — grow-and-abandon
buffers (array/vector elems, dyn-prop chains) and per-call scratch
(join/format/html builders, AMF reader tables); `heap_free` exists at only
~8 sites. Needs its own free-on-grow / scratch-reclamation session.

Two regression tests: `avm2_gc_string_concat_reclaim` (multi-frame
loop-concat; length+slices survive reclamation) and
`avm2_gc_string_survives_collect` (slot/array/dyn-prop name+value/
Dictionary key/listener type/E4X text re-read across stress collects).

## State (RWK-3 — browser demo + wasm heap gate + kitty TAS, 2026-07-18)

**The RWK browser demo is live and playable** (`docs2/examples/avm2/rwk/`,
`demo.html?test=avm2/rwk`, 6.9 MB wasm, avm2_catalog.json listed): menu text
renders on the real render path, **live mouse** click starts the game, live
keys walk the player, title/game music mixes after the autoplay gesture
(verified: `_swfAudioCtx.state === "running"` + non-zero samples pulled via
`Module._audio_fill_buffer`), zero uncaught errors (the `rando_bridge.js`
404 is demo.html's optional-AP HEAD probe). Real-GPU spot check
(windows-playwright rig, Intel Gen9): **5.1 ms/frame mean (~195 fps
capacity), present 0.6 ms**. WSL headed Chrome renders RWK fine (no
Seedling-style texture-array limit), so menu/PlayState/input probes all
work from the agent shell.

**Lever 0 (wasm heap gate) — measured, arena sizing chosen:**
- New env-gated `AVM2_HEAP_STATS=1` (avm2_main.c) prints o1heap diagnostics
  after the native tick loop. RWK PlayState boot peak **1409 MB**;
  steady-state 1373 MB; post-boot growth **~52 KB/tick ≈ 94 MB/min**
  (AVM2 strings are never collected).
- wasm32 AVM2 arena 1 GB → **1984 MB** (heap.c, `__EMSCRIPTEN__ &&
  SWF_AVM2`): o1heap's 32-bit capacity max is 2 GB (FRAGMENT_SIZE_MAX) and
  emscripten's anonymous mmap fails at exactly 2048 MB (1984 measured OK);
  build_wasm_avm2.sh adds `-sMAXIMUM_MEMORY=4GB`. AVM1 demos keep 1 GB.
- Fixed `vmem_reserve` (utils.c): mmap failure returns MAP_FAILED, not
  NULL — heap_init's NULL check had let 0xffffffff flow into o1heapInit.
- **Known limit:** the browser demo OOM-exits after ~6-7 minutes of play
  (611 MB headroom / 94 MB-min). Collectable strings (string census +
  sweep between ticks) is the follow-up — the C-side `const Avm2String*`
  escape surface (display names, text ext, E4X, AMF, statics) needs its
  own session; AVM2_GC_STRESS is the correctness tripwire.

**Live mouse (Stage-13c ring extended):** `avm2_input_inject_mouse`
(avm2_display.c; kind/x/y/button/click_count) fed from render_webgpu.c's
emscripten mouse callbacks under `#ifdef SWF_AVM2`. Double-click detected
in the callback (500 ms / 4 px — EmscriptenMouseEvent has no DOM `detail`);
delivery keeps harness parity (MOUSE_DOWN code odd parity = doubleClick).
Native/harness behavior byte-identical (the ring is only fed in browser).
Browser getTimer note: AVM2 getTimer is the µs tick counter (33.3 ms/tick
at 30 fps) — tick-driven, not wall-clock; pacing indistinguishable at full
frame rate.

**Kitty TAS (handed to RWK-4):** 7 iteration plans this session
(`ruffle-tests/_rwk_tas/` — now git-tracked; README.md is the source of
truth). Solid results: corrected physics (player max walk ~1.05 world
px/tick = 1.6x alien speed — the RWK-2 "4x" note was wrong; falls ~15
ticks; kill band < 20 world px), a world-coordinate map of the descent
(J at world 168 anchors it), alien patrol schedules with periods
(alien-2 317, alien-3 256, floor alien ~678), and decisive negatives:
the shelf-2 "direct right" exit does not exist (1-tile step); platform-2
has NO safe park (alien-3's right-end turnaround IS the lip — plan_l died
there); the floor pocket at world ~310 is lethal during t~1030-1116.
plan_k proved the clean platform-1 landing one alien-2 cycle later
(t1203). Next session: re-measure alien-3's left-end turn (~t1210, the
old t1192 anchor is early), then cross p2 in one motion. Powerups persist
across deaths — segment the remaining route (SHOOT/DBLJUMP/corridor/
shaft) with deliberate suicides. **Oracle spot-check done:** state-aligned
park frame vs the RUFFLE_INPUT_FILE exporter: **MAD 1.23, 2.07% px**,
player + tiles 0 diff px; every diff = a documented pacing-artifact class
(entity phases, SetHelp text lifetime, HUD clock). Exporter gotcha: its
wall-clock elapsed under-drives long holds — oracle inputs need their own
schedule (click ~wait 655), never reuse native tick numbers.

## State (RWK-2 — FlxText rasterization + gameplay, 2026-07-16)

**`BitmapData.draw(TextField)` now CPU-rasterizes glyphs — the two-game text
fix (Flixel FlxText + FlashPunk Text both render text this way).**
- **Recompiler**: DefineFont2/3 glyph SHAPEs are parsed (previously skipped,
  `abc_timeline.cpp`) and emitted as flattened contour polylines in font
  units (curves subdivided 8x at recompile time) — four new outline fields on
  `Avm2FontData` (avm2_abc.h; all NULL for outline-less fonts, e.g. the Noto
  device fallback, which stays an honest no-op).
- **Runtime**: `avm2_edittext_collect_glyphs` (avm2_text.c) walks the Stage-6
  layout (LLayout boxes → per-glyph pen x/baseline/color/scale, Ruffle's
  layout_to_local + render_layout_box + Font::evaluate composition, box
  culling + gutter mask incl. scroll offsets); `bd_draw_textfield`
  (avm2_bitmap.c) fills outlines with a non-zero-winding scanline pass at
  pixel centers through the full affine draw matrix, composing
  colorTransform (per-glyph, like Ruffle's text_transform) and blend modes;
  the field mask is enforced exactly by inverse-mapping pixel centers to
  field-local twips. clipRect stays unsupported (same as the bitmap paths).
- **Grade**: new regression test `avm2_bitmapdata_draw_textfield` (mxmlc,
  [Embed] DejaVu ttf embedAsCFF=false): drawn-pixels / solid-text-color /
  integer-matrix-shift / cxform-composition assertions, expectations captured
  from Ruffle; PASS in BOTH modes. bitmapdata_draw* family + font/edittext
  spot checks: all baseline results hold (alpha_erase mismatch pre-existing,
  untouched).
- **RWK menu**: state-aligned MAD **5.53 → 0.765** (3.11% → 0.69% px); the
  ONLY residual is the kitty-UFO oscillation phase (pacing artifact). Every
  text row (buttons, credits, splash) is pixel-exact vs the oracle.
- **Seedling smoke**: recompile + 300 frames, zero errors, world unchanged.

**Gameplay (headless keyboard) works; found + fixed a real PlayState
blocker.** Menu click → PlayState **OOM'd the 1 GB heap** before its first
frame: `FlxTilemap.arrayToCSV` builds a 15792-tile CSV by repeated string
concatenation (~0.8+ GB of transient garbage in ONE tick) and **AVM2 strings
are not garbage-collected** (GC also only runs between ticks). Fix: native
64-bit arena default 1 GB → 4 GB (heap.c; wasm/wasi unchanged). Collectable
strings are the honest long-term fix (flagged for a future session). After
it: full gameplay loop headless — movement, gravity, alien kills, respawns,
HUD clock, SetHelp FlxText in-world. **State-aligned gameplay frame vs
Ruffle running the SAME scripted input: MAD 1.68, 1.47% px — every single
diff is a moving entity's patrol/animation phase** (jellyfish/aliens/kitty
bob/logo sparkle/clock digit); tilemap, player, and both help-text lines are
pixel-identical. Flixel physics verified byte-identical to Ruffle via
standalone mxmlc probes (vacuum motion, FlxU.collide + fixed floor, tilemap
preCollide path).

**New tooling (RWK-3 will want these):**
- **Input-scripted oracle**: local `~/CC/ruffle` exporter patch — set
  `RUFFLE_INPUT_FILE=<input.json>` (Ruffle-test format, one Wait per frame;
  events injected after each run_frame). Rebuild: `cargo build --release -p
  exporter`. GOTCHA: Flixel calls `FlxG.keys.reset()` on every state switch —
  key events sent during a fade are wiped; press keys only after the target
  state is live. Menu pacing drifts per export run (wall-clock getTimer) —
  schedule clicks generously late and state-align afterwards.
- Scratch TAS driver + tracker (`rwk_drive.py`, `rwk_track.py` — plan
  compiler → line-format events → `./test_run <events>` with
  `AVM2_MAX_TICKS`/`AVM2_CPU_DUMP`; camera tracking via FFT phase correlation
  anchored on the kitty/J-powerup blobs). Recipes in the
  `avm2-rwk2-text-gameplay` memory.
- Kitty-collection TAS → RWK-3: spawn exits are RIGHT-fall only (left wall;
  right step + shelf alien); descent legs to the JUMP powerup at tile (10,82)
  each proven survivable; three aliens patrol the route at 20 px/s
  (deterministic phases per run — measure from dumped frames, then time
  crossings). Win condition is proximity (<30px both axes) on the kitty
  block top.

## State (RWK-1 — Robot Wants Kitty headless bring-up, 2026-07-16)

**The second real game — and the first Flixel game — reaches its menu with
zero uncaught errors, in both build modes.** Target was the *injected* SWF
(`~/CC/Archipelago-CC/.../robotkitty_injected.swf`, BridgeGeneric spliced by
flash-ap-api `inject.py`; recompiles to 2 abc tags / 812 bodies / 0 verify
fails). Full plan/status: `SWFRecompDocs/plans/avm2-robot-wants-kitty.md`.

- **Boot chain = ONE fix.** `flash.net.SharedObjectFlushStatus` was missing
  (Error #1065): Flixel `FlxSave.forceSave` compares `SharedObject.flush()`
  against `SharedObjectFlushStatus.FLUSHED` inside FlxGame's boot
  (sound-persistence path). Added the constants class in `avm2_amf.c`
  (FLUSHED="flushed"/PENDING="pending"; our flush() already returned
  "flushed"). Graded by new regression test **`avm2_sharedobject_flushstatus`**
  (mxmlc). After it: LogoState (MaxGames splash) auto-advances into the
  **TitleState menu**, 300 frames, zero uncaught errors. The feared
  GameShedAchievement/Kong sponsor chain never runs — this Newgrounds variant
  ships `Version.v="Plain"`.
- **Bridge no-op verified (stronger than the Seedling check):** without the
  shim, injected-vs-plain over 300 headless frames is **byte-identical on
  stdout AND on all 300 `AVM2_CPU_DUMP` frames**; EI stays unavailable, no
  Error #2067 escapes (BridgeGeneric's availability gate works untouched).
- **Ruffle-oracle menu comparison** (exporter, 300 frames): state-aligned menu
  frame = **MAD 5.53, 3.11% px differ, all rows ≥240** — the title art,
  tilemap, buttons and robot are pixel-identical. The ONE render gap:
  **FlxText renders nothing** — Flixel draws a TextField into `_framePixels`
  via `BitmapData.draw(tf)`, and `bd_draw` silently ignores non-Bitmap
  DisplayObject sources (avm2_bitmap.c). Probe (mxmlc `[Embed]` DejaVu ttf,
  `bd.draw(textField)` → count nonzero px): Ruffle=true, ours=false. That is
  RWK-2 lever #1.
- **GOTCHA (oracle pacing):** Ruffle's AVM2 `getTimer` is **wall-clock**
  (`Instant::now()` — core/src/avm2/globals/flash/utils.rs), so under the
  exporter a variable-timestep engine like Flixel advances by real render
  time (~28ms/frame) while we advance a deterministic 33.3ms (== Flixel's
  MAX_ELAPSED clamp). Frame indices drift (+15 @60 → +39 @220); compare
  state-aligned via an offset scan. FlashPunk (Seedling) was immune — fixed
  timestep.
- Headless drive recipe unchanged from Seedling (scratch test dir +
  `verify_output` with `KEEP_BUILD_DIR` patch, `SWFRECOMP_OPT_LEVEL=-O0`);
  RWK builds in ~57s at -O0 (vs Seedling's minutes).

## State (AVM2 ExternalInterface + AP handoff page, 2026-07-16)

**`flash.external.ExternalInterface` exists for AVM2** (`avm2_external.c` —
the RULED generic subset: `available`/`addCallback`/variadic `call`, plus
`objectID`→null and `marshallExceptions`). Browser availability gates on the
page exposing `window.__swfBridge` (AVM1 gate design); everywhere else the
class throws the FP `Error #2067` from call/addCallback — the upstream
**`missing_external_interface` test flipped output_mismatch → PASS**. New
regression test `avm2_external_interface_unavailable` (mxmlc; gotcha: mxmlc
strips `trace()` without `-omit-trace-statements=false`). Inbound dispatch is
the exported `avm2_ei_dispatch` (string name + string arg → string), safe
while the browser loop parks at `emscripten_sleep`; outward args marshal
string-first as a JSON scalar array so BridgeGeneric's 2-arg
`stateChanged(pname, pvalue)` delivers real booleans/ints to the host.

**Verification ladder (all green):**
- `_swfbridge/livetest/toy_browser_avm2/` — mxmlc AS3 toy, headed Chrome,
  **8/8** (available, wireCheck/configure/readState inbound, typed-bool
  stateChanged, getItemQueue application, DONE).
- `_swfbridge/livetest/seedling_avm2/` — the REAL injected Seedling
  (flash-ap-api `inject.py`, `--check-abc` clean on both variants). Without
  the shim BridgeGeneric no-ops silently: native headless 300-frame trace
  **byte-identical** injected-vs-plain. With the shim, the teleport-injected
  build passes **8/8** including a `hasSword=true` property write applied via
  getItemQueue and re-reported. The injected ORIGINAL is verified through
  configure + Main resolution; its state monitoring correctly waits for the
  player to start the game (`Main.SAVE_FILE` is constructor-set behind the NG
  preloader) — livetest grades it with `FULL_B=0`.
- **Perf gate (real-GPU Windows Chrome, intel/gen-9, 3+3 runs):** bridge
  active (14 monitored props, host `readState` every 33 ms, per-frame
  `getItemQueue`) mean ≈33.6 ms vs plain baseline ≈34.8 ms — within
  run-to-run noise; **~30 fps held**.

**Handoff artifact (Archipelago-CC consumes this):**
`docs2/examples/avm2/seedling_teleport_ap/` — self-contained
(`game.html` + `seedling_teleport_ap.{js,wasm}` + `swf_bridge_avm2.js`),
loadable as a SAME-ORIGIN iframe src. Usage (verified end-to-end via a parent
page + `frameLocator`): click/call `__swfBridgeStart()` from a user gesture
INSIDE the iframe (WebGPU+audio need the activation), then drive
`iframe.contentWindow.__swfBridge` — `game.wireCheck()/configure(json)/
readState()`, `queueItems([...])`, `onStateChanged` override. Regenerate with
`inject.py` → `build_wasm_avm2.sh seedling_teleport_ap
~/CC/seedling_ap_build/recompiled_teleport` → `deploy_wasm_avm2.sh` (game.html
comes from `wasm_wrappers/swf_bridge_game_page.html`). Ruffle oracle: the
deploy stages `seedling_teleport_ap_ruffle/` (same injected SWF under Ruffle)
for side-by-side behavior checks; the teleport build's frame oracle remains
`~/CC/seedling_teleport_build/ruffle_oracle_60`. Known-environmental: WSLg
Chrome floods `Invalid Texture "bitmap_tex"` (adapter texture-array-layer cap
vs Seedling's 284 bitmaps) — identical on the plain build, absent on real GPU.

## State (real audio output — browser-WASM Seedling, 2026-07-16)

**The AVM2 browser demo is AUDIBLE.** Stage 10's flash.media surface was
trace-graded only; this session bridged it to the shared `src/audio` mixer and
the Web Audio sink. Seedling plays music (FlashPunk `fadeToLoop`) + SFX in the
browser; verified via headed-Chrome smoke (AudioContext `running`,
`audio_fill_buffer` returns 4090/4096 nonzero samples).

- **Recompiler:** `abc_timeline.cpp` now emits DefineSound payload bytes
  (`snd_<i>_bytes[]`); `Avm2SoundData` gains `data`/`data_len` (full tag bytes
  incl. the 2-byte MP3 seek prefix). `data_size` keeps its bytesTotal
  semantics (trace-graded). Seedling: 88 payloads, wasm 24→30 MB.
- **Mixer (`audio.c`):** per-channel SoundTransform gains (identity for AVM1 —
  bit-identical mix), generation-checked channel handles
  (`audio_start_sound_ex` / `audio_channel_stop/set_gains/position_ms/active`),
  loops restart at startTime (AS3 semantics; AVM1 path still restarts at 0).
- **Bridge (`avm2_media.c`):** sounds registered at boot
  (`avm2_media_register_sounds`); `Sound.play(startTime, loops, transform)` →
  mixer; `SoundChannel.stop`/`SoundMixer.stopAll` → mixer stops;
  `soundTransform` setters push gains live; `SoundChannel.position` reads the
  mixer clock; `avm2_media_poll` (per tick) dispatches `Event.SOUND_COMPLETE`
  for drained channels (manual stops don't dispatch — Flash semantics). Live
  channels are GC roots (`avm2_gc_mark_roots_media`) — a fire-and-forget
  play()'s SoundChannel may have no other reference.
- **Browser init (`avm2_main.c`):** `audio_output_init` runs before renderer
  init AND before any script (the click gesture must still be active —
  renderer's `emscripten_sleep` consumes it; same rule as AVM1 swf.c).
- **Trace-inert by construction:** nothing prints; positions only advance when
  a sink pulls `audio_mix` — never in the native harness. All sound tests
  (NO_GRAPHICS + graphics) verified locally unchanged; the 3 network-load
  sound failures (`sound_constructor_with_args`, `sound_load_multiple`,
  `sound_rootless`) are byte-identical to baseline (still deferred).
- **Still deferred:** `soundchannel_position` / `soundchannel_soundcomplete`
  (upstream known_failure — need the harness to pull audio),
  SoundMixer cross-frame accumulation, Sound.load network tests.

## State (Stage 12 — Seedling bring-up, session 5 2026-07-13, commit `b3ec6d48c`)

**SEEDLING GAMEPLAY RENDERS.** The ~99%-black overworld was root-caused to
**empty embedded ByteArrays**, not the s4 NaN-matrix lead (those NaN draws are
day/night MULTIPLY/HARDLIGHT overlays with a null matrix — unrelated to terrain).
Flex `[Embed(mimeType="application/octet-stream")]` `.oel` levels compile to
`ByteArrayAsset` subclasses SymbolClass-bound to a `DefineBinaryData` char, and
`new LevelClass()` was constructing an EMPTY ByteArray (runtime never seeded it)
→ FlashPunk `loadlevel` did `readUTFBytes(0)="" ; new XML("")` → `FP.width=0` →
the tile-build loop ran zero times → zero tiles.

- **Fix (`avm2_bytearray.c` `ba_native_init`):** when the constructed class
  maps to a SymbolClass binary char (`avm2_display_char_for_class`), seed the
  ByteArray from `avm2_generated_binaries` (len/bytes, position 0). The
  ByteArray analog of the s2 embedded-Bitmap seed; binaries are emitted RAW.
- **Result:** real OverWorld.oel parses (width=320, 405 tiles added),
  `Image.render` goes ~4→~279 calls/tick, and the GPU-free `AVM2_CPU_DUMP`
  matches the Ruffle oracle — **frame black 98.7%→0.1%, MAD 3.834 vs
  `ruffle_oracle_60/41.png`** (house/grass/water/path/trees/player/fence).
- **Regression test:** `regression/avm2_embed_bytearray` — a minimal AS3 SWF
  embeds a 23-byte octet-stream asset and asserts `new Payload().length==23` +
  its readUTFBytes content. Empty before, PASS after. Existing avm2
  bytearray/bitmapdata_embedded tests unaffected.
- **Deferred render-fidelity (out of scope per session prompt — do NOT reopen
  bd_draw):** day/night MULTIPLY overlay + HARDLIGHT compose pass a **null
  matrix** to `BitmapData.draw` → read as NaN → finite-guard no-ops them (no
  tint applied). Needs null-matrix→identity AND real MULTIPLY/HARDLIGHT/ADD
  blend in the CPU raster. Also: HUD hearts, Emitter particles,
  ColorMatrixFilter.

---

## State (Stage 12 — Seedling bring-up, session 4 2026-07-13)

Session 4 targeted the gameplay render gap (FlashPunk `BitmapData.draw` with a
matrix). Three things landed; the Seedling gap moved but did not fully close.

- **`flash.geom.Matrix` was a bare stub** (only `toString` + the a/b/c/d/tx/ty
  ctor) — the *real* blocker. `bitmapdata_draw_rotation`'s `matrix.rotate()`
  threw, aborting the test ctor **before** `b.draw(...)`, so `bd_draw` was never
  even reached. Implemented the full method surface in `avm2_display.c`
  (identity/clone/scale/rotate/translate/concat/invert/createBox/
  createGradientBox/transformPoint/deltaTransformPoint/setTo/copyFrom/
  copyRowFrom/copyColumnFrom), ported from Ruffle `avm1/globals/matrix.rs` +
  `render/src/matrix.rs` but in **pure f64 pixel space** (Flash's own doubles),
  not Ruffle's twips-quantized f32. Added a minimal `flash.geom.Vector3D` init
  (x/y/z/w) so copyRow/copyColumnFrom read real components.
- **`bd_draw` general affine CPU raster** (`avm2_bitmap.c`): the identity-2x2
  guard now falls through to an inverse-map (dest→src, pixel-center,
  nearest-neighbor) raster for a **BitmapData source under an arbitrary affine
  matrix** (+ optional colorTransform), matching Ruffle's GPU quad coverage
  rule. Non-finite/degenerate matrices are a clean no-op. Validated against the
  Ruffle oracle via the GPU-free `AVM2_CPU_DUMP` path: **rotation frame is
  MAD 0.134, only 116/220000 px differ (>10)** — all on the rotated diamond's
  edge (nearest-neighbor boundary), i.e. essentially pixel-perfect.
- **IMPORTANT metric finding: image comparisons never gate pass/fail.**
  `verify_output.py` sets a test's `status` purely from the TRACE comparison
  (`if match:`); `image_comparisons` is recorded but never read back into the
  status. Every render test has an empty/trivial `output.txt`, so it "passes"
  the trace check regardless of pixels. So the Stage-9 "8/9 bitmap tests pass"
  and every graphics-mode avm2 pass count are **trace passes** — image
  correctness was recorded but never gated. Decision (with the user): keep
  pass/fail trace-based and use `run_image_tests.py` →
  `ruffle-image-results.{md,html}` as the image source of truth. That script now
  sweeps the **avm2 render subset** (62 of 108; skips Stage3D/AGAL/PixelBender/
  Loader/JPEG-XR/NetStream/filter tests that need unsupported backends;
  `--all-avm2` for the full set, `--suite=` to scope) and reports per-suite.
  NOTE: local WSL2 rendering is not pixel-exact vs the expected PNGs even for
  CI-passing tests (e.g. `copypixels` matches in mean but has 25k tol-0
  outliers locally), so the CPU-dump is the reliable local validator.
- **Seedling render gap re-diagnosed (finding corrected).** With Matrix methods
  in, Seedling's scenery draws now **reach `bd_draw`'s affine branch** (not
  dropped) — but the input matrices are **all NaN** (`m=[nan nan nan nan …]`).
  FlashPunk `Image.render` computes `_matrix.a = scaleX * scale` etc.; the
  character still renders via `copyPixels` (so *its* `scale==1`), but scenery
  graphics feed NaN scale/origin — a property/level (`.oel`/Spritemap) init
  divergence, NOT a `bd_draw` gap. Frame 59 is still ~98.7% black (unchanged
  from s3), 0 uncaught. `bd_draw` now no-ops non-finite matrices so this is a
  clean miss, not garbage. This NaN-matrix source is the next Seedling target.

## State (Stage 12 — Seedling bring-up, session 3 2026-07-13)

- **FIRST VISUALLY-VALIDATED Seedling frames — GPU-free.** Added an env-gated
  CPU-composite frame dump (`AVM2_CPU_DUMP=<prefix>` → `<prefix>NNN.ppm`) in
  `avm2_display.c`, compiled in EVERY build (NOT under `OFFSCREEN_RENDER`). It
  walks the same display tree the tick built and inverse-maps each on-stage
  Bitmap's premultiplied-ARGB pixels into a CPU framebuffer (Porter-Duff over,
  concatenated alpha), bypassing the WebGPU/lavapipe capture OOM entirely. This
  validates render *correctness* for a bitmap-based FlashPunk game with no GPU.
- **Ruffle oracle state-matched to the Splash.** Ruffle's exporter on `file://`
  shows the preloader PLAY button forever (needs a MOUSE_UP), so it never
  matched our portal-auto-start state. Patched Ruffle
  `core/src/tag_utils.rs::movie_from_path` to honor a **`RUFFLE_MOVIE_URL`** env
  override (falls back to the `file://` URL) — set it to the same armorgames
  portal URL and the NG preloader auto-starts into the game, matching our
  `GAME_SWF_URL` lever. (This patch lives in `~/CC/ruffle`, the oracle tool
  repo, NOT this project.)
- **Validation (600 frames, our CPU dump vs Ruffle portal export):** 155/600
  frames **pixel-perfect** (MAD < 0.01), 165 near-perfect (MAD < 1), **no frame
  worse than MAD 15**. The NEWGROUNDS splash logo and the CONNOR ULLMANN credit
  screen match to the pixel / 1px edge. Remaining diffs are all understood and
  out of the Stage-9 Bitmap-blit scope: (a) 1px nearest-neighbor edges on
  *fractionally-scaled* bitmaps (splash zoom, title art); (b) the FlashPunk
  alpha fade-in on the "Music by" headphones — Ruffle applies it via
  `BitmapData.draw` with an alpha colorTransform, which the Stage-9 draw() CPU
  fast-path ignores (renders full opacity) — the documented draw()-colorxform
  gap; (c) the NG preloader progress bar (`graphics.drawRect`) + "0%" TextField,
  which are shape/text draws (not bitmaps).
- **Drove past the 3-splash sequence into the Game title screen.** The splash is
  3 sponsor logos × 150 ticks (`Splash(0→1→2)`) then `FP.world = new Game()`;
  reaching Game needs ~500 frames. Added an **`AVM2_MAX_TICKS`** runtime
  frame-depth override (avm2_main.c) so a bring-up game can be driven arbitrarily
  deep without a full rebuild (`MAX_FRAMES` is a `-D` on every TU, so bumping it
  busts ccache for the whole AVM2 build). At 600 ticks the game reaches its
  **title/menu screen** (the "Seedling" vine logo + NEWGROUNDS tank + a green
  continue arrow), rendered correctly.
- **First Game divergence found + fixed: `flash.geom.Point` was a bare
  x/y/toString stub.** FlashPunk hit `#1069: Property clone not found on Point`
  (56×/frame). Implemented the full Point method surface (clone/add/subtract/
  equals/offset/normalize + `length` getter + static distance/interpolate/polar)
  in `avm2_globals.c`, ported from Ruffle `globals/flash/geom/point.rs` (incl.
  the AS3-truthy `if(length)` guard in normalize — 0 AND NaN skip). **Backed by
  the upstream `point` oracle: now 100% pass** (was aborting at the first
  missing method). After the fix: **Seedling runs 600 frames with ZERO uncaught
  errors** in no-graphics.
- **Reached real GAMEPLAY via a source-recompile teleport** (not `AVM2_MAX_TICKS`,
  which only fast-forwards intros). Rebuilt the Seedling AS3 source with the Flex
  SDK (`mxmlc`, `~/CC/seedling` + NewgroundsAPI.swc) using **`Main` as the
  document class** (drops the whole Newgrounds preloader/ad chain) and
  `Game.menu = false; new Game(0,80,128)` in `Main.begin()` — boots straight into
  OverWorld1, controllable. Recompiles cleanly (703 classes, 0 verify fails);
  built with `SWFRECOMP_OPT_LEVEL=-O0` + `SWFRECOMP_COMPILE_TIMEOUT=900` (new
  verify_output env overrides — the single-DoABC 13 MB `abc0_methods.c` TU
  exceeds the 300 s `-O2` budget). **Our AVM2 runtime runs 60 gameplay frames
  with ZERO uncaught errors** (logic fully correct — character spawns, world
  loads, HUD present). **Render gap:** vs the Ruffle export of the same SWF, our
  output is ~99% black — only the character + HUD (`copyPixels` Image blits)
  render; the tilemap/scenery composite via `BitmapData.draw` with camera
  matrices, which the Stage-9 draw() CPU path only handles at identity → never
  composites. Full FlashPunk software-buffer rendering (`BitmapData.draw` w/
  arbitrary matrix + Canvas/Tilemap blits) is the next render target. Recipe +
  finding in the `seedling-teleport-gameplay` memory.
- **Next session:** the gameplay render gap (FlashPunk `BitmapData.draw`-matrix +
  Canvas/Tilemap software-buffer compositing) is the highest-value render work —
  now scoped by a live gameplay oracle. Also the splash-phase draw()-colorxform
  alpha fade (same draw() family). Optional: feed input via the Stage-8
  input.json harness to drive the character around.

## State (Stage 12 — Seedling bring-up, session 2 2026-07-13)
Stage 11
(GC enrollment + perf soak) COMPLETE; Stage 10 (audio + timers + saves + asset
compression), Stage 9 (minimal AVM2 render path), Stage 8 (input harness +
input→event bridge), Stage 7 (embedded assets + BitmapData/Bitmap), Stage 6
(TextField/EditText engine), Stage 5, E4X and Stage 4 before it.

## State (Stage 12 — Seedling bring-up, session 2 2026-07-13)

- **Embedded-image assets fixed — the "Invalid source image" blocker is
  cleared.** A Flex `[Embed]` image asset generates the class chain
  `<owner>_<var>` → `mx.core.BitmapAsset` → `mx.core.FlexBitmap` →
  `flash.display.Bitmap`, where FlexBitmap's ctor forwards its DEFAULT **null**
  bitmapData up the `super()` chain. The native Bitmap init saw an explicit null
  arg0 and *cleared* bitmapData instead of seeding from the SymbolClass-bound
  embedded asset, so `(new EmbedClass()).bitmapData` returned null. FlashPunk's
  `FP.getBitmap()` is exactly `(new source).bitmapData`, so every embedded image
  resolved to a null BitmapData → the game's own `Image`/`Spritemap` threw
  "Invalid source image". Fixed to match Ruffle `bitmap.rs`: only a real
  BitmapData arg overwrites; a null/absent arg keeps any timeline-seeded value,
  else creates a BitmapData from the (sub)class's embedded char.
  **Backed by upstream oracle `bitmap_subclass`** (`new EmbedClass().bitmapData`);
  also unlocked the former known-miss `bitmap_subclass_properties`.
- **Toward `Main`: 4 more flash.* classes.** Driving the real recompiled
  Seedling headless on the **portal auto-start path** (a new `GAME_SWF_URL`
  override in verify_output.py points SWF_URL at an armorgames domain so the NG
  preloader skips its play-button gate and auto-calls `startup()`) surfaced a
  short divergence chain, each a small flash.* class FlashPunk's Engine/Splash
  touch at startup / every frame:
  - `flash.display.StageDisplayState` (NORMAL/FULL_SCREEN/FULL_SCREEN_INTERACTIVE)
    — Engine.setStageProperties sets `stage.displayState = NORMAL`.
  - `flash.display.LineScaleMode` (NORMAL/HORIZONTAL/VERTICAL/NONE) — FlashPunk
    Draw.lineStyle. Both are enumerated by the `all_classes/display/swf*`
    describeType oracles (constant sets match verbatim).
  - `flash.ui.Mouse` (static `cursor` getset + hide/show no-ops) +
    `flash.ui.MouseCursor` (AUTO/ARROW/BUTTON/HAND/IBEAM) — Splash sets
    `Mouse.cursor` every frame. No `all_classes/ui` oracle in-suite; game-driven
    stubs (headless has no cursor).
- **Result: the recompiled Seedling.swf now runs 30 frames on the headless
  portal auto-start path with ZERO uncaught errors, in BOTH build modes.** It
  reaches the FlashPunk `Engine` game loop and the `Splash` world (past the
  former "Invalid source image"). In **graphics mode** the render path executes
  without crashing — but the PNG *capture* hits the known WSL2 lavapipe bug
  (`VK_ERROR_OUT_OF_DEVICE_MEMORY` during the frame → device lost →
  `render_webgpu_save_png: buffer map failed (status 4)`), so a visual
  first-frame image diff vs Ruffle is still blocked. Characterized: the AVM2
  render path allocates a 481×481×64-layer RGBA bitmap texture array
  (MAX_DYNAMIC_BITMAPS=64) + MSAA + offscreen; under lavapipe's WSL2 memory
  ceiling an in-frame allocation OOMs. **Render-infra, separate from game logic**
  — the next unlock for a *visual* first frame, deferred.
- **CI baseline (bitmap fix, sha `1af36539f`, avm2_gc=1):**
  - **graphics (run 29270812691): avm2 827 / 1204 (68.7%)** — **+2** over the
    Stage-12 825 baseline (`bitmap_subclass`, `bitmap_subclass_properties`);
    zero newly-failing across all suites. (Cumulative no-graphics + graphics at
    sha `c2506a703`, adding the 4 constant classes, dispatched — see the
    `avm2-stage12-seedling` memory for the final numbers.)
- **Next session (to first-playable):** (a) the graphics-mode capture OOM
  (render-infra) for a visual first frame; (b) reach `Main` on the natural
  `file://` path via an injected play-button click (Stage-8 input.json); (c)
  drive past the 150-tick Splash into `Game`, surfacing the next divergences
  (flash.ui.Keyboard capsLock, Music/Sound, Draw line paths).

## State (Stage 12 — Seedling bring-up, first session 2026-07-13)

- **The real Seedling.swf recompiles + links + runs — both build modes.** The
  recompiler emits exactly the census counts (284 DefineBitsLossless2 bitmaps,
  116 DefineBinaryData, 88 DefineSound; abc_timeline.c 8.9 MB compressed, 0
  verify failures over 3,607 bodies). Native no-graphics AND graphics (Dawn
  offscreen) both link and run without crashing.
- **Divergence-harness workflow (headless-first): the entire Newgrounds-API
  preloader error chain is cleared.** Seedling's document class is the
  **Newgrounds API v3.1.3 AS3** preloader (NG ads/medals wrapper around the
  FlashPunk `Main`). Running the recompiled game headless surfaced a chain of
  missing-class / null-access divergences, each fixed and (where an upstream
  family exists) backed by a trace test:
  1. `loaderInfo.url` → **#1009** (loaderInfo returned null). Implemented
     **flash.display.LoaderInfo** (root-movie singleton: shared across all
     on-stage objects, null off-stage; `content`=root; bytesLoaded/Total=on-disk
     size; url/contentType/actionScriptVersion/frameRate/width/height/swfVersion/
     parameters/applicationDomain/loader/childAllowsParent/parentAllowsChild/
     sameDomain). **+3 tests: loaderinfo_properties, loaderinfo_root,
     loaderinfo_root_allows.** Added `-DSWF_ONDISK_SIZE` to verify_output (the
     root LoaderInfo reports the compressed download size, not SWF_FILE_SIZE's
     uncompressed header size).
  2. **#1065 Security** → implemented **flash.system.Security** (sandboxType
     "localWithFile", allowDomain/allowInsecureDomain/loadPolicyFile no-ops,
     sandbox-type constants). **+1 test: sandbox_type_local_file.**
  3. **#1065 URLVariables** → implemented the **flash.net URL stack**
     (URLRequest with #2008 method validation, URLVariables, URLRequestMethod,
     URLLoaderDataFormat, URLRequestHeader, URLLoader [EventDispatcher;
     load()=no-op, no network layer], navigateToURL/sendToURL). **+1 test:
     urlrequest.**
  4. **#1006 addEventListener on URLLoader** → registration-order bug:
     `register_net` ran before `avm2_register_events`, so URLLoader was created
     when `event_dispatcher_class` was still NULL (builtin classes snapshot the
     parent vtable at creation). Moved `register_net` after events.
  5. **#1065 ProgressEvent** → implemented the **flash.events network family**
     (ProgressEvent, ErrorEvent, IOErrorEvent, SecurityErrorEvent,
     AsyncErrorEvent, HTTPStatusEvent, StatusEvent) with static type constants.
     No upstream trace family — game-driven stubs.
- **Result:** Seedling now runs the NG preloader **with zero uncaught errors**;
  at ~3000 ticks the NG API connection **times out gracefully** ("Unable to
  connect to the API" — correct headless behaviour, there is no network). The
  preloader then reaches its **play-button gate** (the `onPlayClick` /
  `onMouseDown` handlers in the abc dump): starting the FlashPunk `Main` needs
  an injected mouse click — the next session's work (input.json harness, then
  first render).
- **Reading the game's own source** (`~/CC/seedling/src/Preloader.as` + Main.as)
  confirmed the exact flow: on `file://` the preloader shows a Newgrounds
  `FlashAd` **play button and waits for a MOUSE_UP click** → `onPlayClick` →
  `startup()` → `getDefinitionByName("Main")` → `new Main()`. On a **portal URL**
  (armorgames.com etc.) `flashAd` stays null and `onEnterFrame` calls
  `startup()` **automatically** (no click, skips API.connect). Driving the game
  with a portal `SWF_URL` is the headless auto-start lever; it pushed two more
  divergences toward `Main`:
  - **#1065 PixelSnapping** (Bitmap default pixelSnapping) → added
    **flash.display.PixelSnapping** + the sibling constant classes FlashPunk's
    `Engine` sets at startup (**BlendMode, StageScaleMode, StageAlign,
    StageQuality**). Pure string-constant bags.
  - **"Error: Invalid source image"** — thrown by the game's OWN FlashPunk code
    (an `Image`/`Spritemap` built from a null/invalid `BitmapData`), i.e. an
    **embedded-image-asset decode gap** (the NG-logo / FlashAd PNGs; and every
    `[Embed]` image in `Game.as`). The next real unlock toward a rendered game.
- **Known gaps / next session:** (a) embedded-image asset decode ("Invalid
  source image"); (b) reach `Main` on the natural `file://` path via an injected
  play-button click (Stage-8 input.json); (c) graphics-mode capture hits
  `render_webgpu_save_png: buffer map failed (status 4)` / lavapipe
  `VK_ERROR_OUT_OF_DEVICE_MEMORY` under WSL2 — render-infra, separate from game
  logic (headless no-graphics path is clean); (d) URLLoader.load never
  dispatches COMPLETE/IO_ERROR (no network) — a faithful async IOError would let
  API-gated preloaders fall through without the ~3000-tick timeout Timer.
- **The game is the INTEGRATION check, never the oracle:** every fix above is
  graded by its upstream trace family (5 new passes) except the flash.events
  network stubs (no upstream family) and the flash.net load()/navigator paths
  (need Ruffle's navigator mock — url_loader/net_navigateToURL stay deferred).

## State (Stage 11)

- **Stage 11 COMPLETE (2026-07-12): AVM2 mark-sweep garbage collector.**
  Before Stage 11 every `avm2_object_alloc`'d object was immortal (a deliberate
  Stage-2 simplification — fine for MAX_FRAMES-bounded trace tests, unbounded
  growth for a 30fps blitting game like Seedling). Now a real root-traced
  mark-sweep collector reclaims per-frame garbage. New files
  `SWFModernRuntime/src/avm2/avm2_gc.c` + `include/avm2/avm2_gc.h`; full design +
  gotchas in the `avm2-stage11-gc` memory. Key design:
  - **Collect only between ticks (VM quiescent).** `Avm2Activation` holds no
    operand stack / locals (emitted bodies keep those as C locals), so the only
    safe collection point is the top of the runSWF_avm2 tick loop, where the
    live set == the persistent root graph. Separate census (`g_gc_head`) from
    AVM1's ASObject/ASArray lists.
  - **Deterministic byte-watermark trigger** (default 4 MB). Short trace tests
    allocate << 4 MB → GC never triggers → trace output byte-identical.
    `AVM2_GC_STRESS=1` forces collect-every-tick (CI correctness gate, workflow
    input `avm2_gc`); `AVM2_GC=0` disables.
  - **Marking:** precise struct fields (proto/slots/dyn_props/bound_methods/
    fn_*/class_ref) + array/vector elems + module ext tracers (EventDispatcher
    listeners, DisplayObject children/frame_scripts/EditText stylesheet) +
    **conservative pointer-scan of every other native_ext blob** (the
    missed-edge safety net — can only over-retain, never free a live object).
    Class objects/prototypes + XML wrappers pinned immortal.
  - **Soak evidence** (`AVM2_GC_SOAK=<ticks>`, synthetic per-frame garbage on
    the real context): GC OFF → live climbs 770 → 2,000,370 over 5000 ticks
    (611 MB, 0 freed); GC ON (4 MB) → bounded sawtooth ~370–11.5k (1,990,400
    reclaimed); STRESS → **dead-flat live=370 across 5000 collections, 2,000,000
    objects swept**. ASAN stress soak (1500 collections) zero AddressSanitizer
    errors.
  - **CI baseline (sha `b5695059b`, avm2_gc=1 STRESS = collect every tick):**
    - **no-graphics (run 29224963308): avm2 819 / 1,204 (68.0%)** — zero
      pass→fail vs the pre-Stage-11 baseline (8c4e8518e, 819). avm1 (634),
      from_gnash, from_shumway (73), regression (41) all "No changes detected";
      wasm-link-smoke green. The GC collecting on EVERY tick produces
      byte-identical trace output across all 1,204 avm2 tests + every AVM1 suite
      — the full marking-correctness gate.
    - **graphics (run 29224968114, avm2_gc=1): avm2 819 / 1,204 (68.0%)** —
      identical to no-graphics; supercall_two_classobjects segfault→2/2, all 10
      fixed, zero newly-failing across all suites; wasm-link-smoke green. GC is
      mode-independent (render reads the same tree), confirmed byte-identical in
      both build modes under collect-every-tick.
    - **The stress run FOUND two real marking bugs in the first pass** (10 avm2
      failures at sha b4db40f98), both fixed in b5695059b: class-scope capture
      of live instances (supercall_two_classobjects segfault) + uninitialized
      Avm2DynProp.key_obj/dead exposed by GC memory reuse (scene/label/callee
      cluster read null). The default 4 MB watermark keeps the trace suite
      GC-inert (byte-identical) regardless.


## State (Stage 10)

- **Stage 10 COMPLETE (2026-07-12): audio + timers + saves + the deferred
  asset-table compression.** Graded families (local single-test runs;
  `_investigation/STAGE10_CANDIDATES.txt`):
  - **flash.utils.Timer / TimerEvent + getTimer — 6/6** (timer, timer_events,
    timer_finished, timer_reset, timer_setdelay, get_timer).
  - **flash.media Sound family — 12 pass** (soundtransform, soundmixer_buffertime,
    soundmixer_stopall, soundchannel_soundtransform{,_exists}, soundchannel_stop,
    sound_valueof, sound_embeddedprops, sound_play, movieclip_soundtransform).
    2 deferred (soundmixer_soundtransform / simplebutton_soundtransform: multi-
    entity SoundMixer accumulation + timeline-child transform persistence), 3
    network-load-deferred (sound_rootless / sound_constructor_with_args /
    sound_load_multiple), 2 upstream known_failure (soundchannel_position /
    _soundcomplete).
  - **flash.net.SharedObject — shared_object_no_root pass** (getLocal → dynamic
    `data` Object); shared_object deferred (two-run .sol harness + AMF byte-exact
    size, unsupported by verify_output).
  - **Asset-table zlib compression** (the Stage-7 ~46 MB finding): the recompiler
    now zlib-DEFLATEs each DefineBitsLossless2 RGBA table (level 9); the runtime
    inflates on BitmapData construction. **Seedling recompile 46 MB → 8.9 MB**
    (~80% smaller), exit 0; bitmapdata_accuracy still bit-exact. Also added a
    DefineSound `data_size` field (bytesTotal) to the recompiler tables.
  - What landed: new `SWFModernRuntime/src/avm2/avm2_media.c` (Sound/SoundChannel/
    SoundTransform/SoundMixer); the Timer class + a Ruffle-faithful µs timer core
    (one priority list, strict `tick_time < cur_time`, MIN_INTERVAL/MAX_TICKS,
    fired at the TAIL of the tick like Ruffle's run_frame→update_timers) in
    avm2_display.c; TimerEvent in avm2_events.c; DisplayObject.soundTransform in
    avm2_display.c; SharedObject in avm2_amf.c; DefineSound `data_size` +
    zlib-compressed bitmap tables in `SWFRecomp/src/abc/abc_timeline.cpp` +
    runtime inflate in avm2_bitmap.c; `getTimer`. verify_output.py adds
    avm2_media.c to the AVM2 source set.
  - **CI baseline BOTH modes (sha `8c4e8518e`):**
    - **no-graphics (run 29219023622): avm2 819 / 1,204 (68.0%)** — **+18** over
      Stage 9's 801 (all 18 Stage-10 candidates + `agal_compiler` bystander).
    - **graphics (run 29219031270): avm2 819 / 1,204 (68.0%)** — identical +18,
      confirming the zlib-compressed bitmap tables render bit-identically.
    - `soundchannel_position` + `soundchannel_soundcomplete` moved
      output_mismatch → **ruffle_matched** (effective pass). `soundmixer_
      soundtransform` (888/900) + `simplebutton_soundtransform` (829/887)
      improved but not fully passing (multi-entity accumulation gap).
    - **ZERO pass→fail regressions in EITHER mode across ALL suites** (avm1 634,
      from_shumway 73, from_gnash sub-suites, regression 41 all unchanged);
      wasm-link-smoke green in both runs.


## State (Stage 9)

- **Stage 9 COMPLETE (2026-07-12, commit `bf93755e0`): minimal AVM2 render
  path — 8/9 pure-blit bitmap family pass** under `--mode=graphics`
  (`_investigation/STAGE9_CANDIDATES.txt`). A real render-tree walk over the
  AVM2 display tree feeding the existing WebGPU offscreen backend (which was
  already linked in AVM2 graphics builds but never driven). What landed:
  - `SWFModernRuntime/src/avm2/avm2_display.c` — a new `#ifdef OFFSCREEN_RENDER`
    render block. `avm2_render_init` replicates swfStart's renderer setup
    (renderer_new/init, stage_to_ndc, stage bg from g_stage_color, dynamic-bitmap
    layer sizing, capture triggers) for the AVM2 entry. `avm2_render_frame`/
    `avm2_render_finish` run a depth-ordered render-list walk after each tick (a
    NEW pass reading the SAME list the tick built — no timeline/goto re-run),
    composing world matrix + concatenated alpha per node and blitting each
    Bitmap's premultiplied-ARGB BitmapData pixels via
    `renderer_draw_bitmap_quad_scaled` into a per-object dynamic xform slot.
    Capture mirrors swf.c/capture.c (last_frame/iteration/fs_command).
  - `SWFModernRuntime/src/avm2/avm2_main.c` — drives render_init before the tick
    loop, render_frame after each tick, render_finish at the end, all gated on
    OFFSCREEN_RENDER (NO_GRAPHICS builds compile none of it).
  - `SWFModernRuntime/src/avm2/avm2_bitmap.c` — BitmapData.draw()'s CPU fast path
    ported from Ruffle operations.rs (BitmapData/Bitmap source + normal blend +
    identity 2x2 matrix -> copy_on_cpu / blend_and_transform; BitmapData-source
    Alpha/Erase = documented Flash no-op). DisplayObject sources / impactful
    blends / scaled matrices still need the offscreen GPU pipeline (Stage 10+).
  - Passing (graphics): bitmapdata_fillrect, _clone, _copychannel, _copypixels,
    _colortransform, _embedded, _sync, _pixeldissolve_image. Miss:
    bitmap_subclass_properties (a pre-existing embedded-subclass trace abort,
    fails identically in no-graphics — NOT a render bug).
  - **DEFERRED to Stage 10+** (documented): asset-table zlib compression (the
    ~46 MB Stage-7 finding — orthogonal to Stage-9 grading, tests use tiny
    bitmaps; a broad recompiler change better done in the asset/audio session;
    only blocks the real Seedling recompile), shape/gradient/text/mask rendering
    (Graphics records only an AABB), and the draw() offscreen-GPU pipeline (the
    bulk of the bitmapdata_draw* family).
  - **CI baseline BOTH modes (sha `bf93755e0`):**
    - **no-graphics (run 29216031666): avm2 801 / 1,204 + 22 RM = 823 effective
      (68.4%)** — IDENTICAL to Stage 8's 823 (the render + draw() additions are
      no-graphics-inert / net-zero); no-graphics diff "No changes detected".
    - **graphics (run 29216038323): avm2 801 / 1,204 + 22 RM = 823 effective
      (66.5% raw pass), +793 over the previously-broken graphics baseline (8)**
      — this is the first real avm2 graphics baseline; the image tests now
      render. Zero graphics regressions (vs trace AND vs previous graphics).
  - **ZERO pass→fail regressions in EITHER mode across ALL suites** (avm1,
    from_gnash all sub-suites, from_shumway, regression all "No changes
    detected" in both modes); wasm-link-smoke green.

## State (Stage 8)

- **Stage 8 COMPLETE (2026-07-12, commit `ee2107860`): ~42/71 input.json
  candidates pass locally** (`_investigation/STAGE8_CANDIDATES.txt`; up from 0
  — the AVM2 runtime ignored input.json entirely before this). The ~29 misses
  are triaged there and cluster on features outside the input bridge: mask
  hit-testing, flash.display.Loader (deferred), SimpleButton highlight_bounds
  geometry + arrow navigation, IME, HTML link events, real-shape hit-testing.
  What landed:
  - `ruffle-tests/verify_output.py` — input.json injection wired to the AVM2
    build; `KEY_DOWN` now carries keyCode/charCode/keyLocation, `MOUSE_DOWN`
    the double-click index, `SET_CLIPBOARD_TEXT` escapes embedded newlines.
  - `SWFModernRuntime/src/avm2/avm2_events.c` — flash.events MouseEvent /
    KeyboardEvent / FocusEvent / TextEvent (subclass ctors, getters, toString
    overrides via in-place vtable replace).
  - `SWFModernRuntime/src/avm2/avm2_display.c` — the input section: parser +
    per-WAIT-tick pump, mouse hit-test (Ruffle mouse_pick_avm2 AABB) + 3-phase
    dispatch (down/up/click/middle/right/rollOver/rollOut/mouseMove/wheel with
    mouseEnabled/mouseChildren gating), Sprite.startDrag/stopDrag/dropTarget,
    keyboard→stage.focus dispatch, the focus manager (mouse+Tab focus, focusIn/
    Out/keyFocusChange/mouseFocusChange, automatic 6y+x tab order + custom
    tabIndex order, is_tabbable/tab_enabled per type, buttonMode/useHandCursor).
    Also fixed a pre-existing bug — MovieClip did not inherit Sprite.graphics
    (getter registered after MovieClip was derived), which crashed every input
    test that drew via `this.graphics.beginFill`.
  - `SWFModernRuntime/src/avm2/avm2_text.c` — TextField editing bridge over the
    Stage-6 EditText engine: text_input (typed + pasted, newline/control
    filter, textInput event, restrict, maxChars, change), text controls
    (move/select/backspace/delete/cut/copy/paste), EditTextRestrict.
  - **CI baseline (no-graphics, run 29213200637, sha `ee2107860`): avm2 800 /
    1,204 passing + 22 ruffle_matched = 822 effective (68.3%)** — +47 over
    Stage-7's 775 (the input harness + the MovieClip.graphics fix unlocked
    bystanders well beyond the 71 candidates). avm1 (634/706+RM), gnash,
    shumway (73/92+RM), regression (41/41) all unchanged; wasm-link-smoke
    green. **One pass→fail regression** — `edittext_autosize_lazy_bounds_
    interactions` (re-focusing the already-focused TextField stopped applying
    pending autosize bounds because the new `set_focus` early-returns on an
    unchanged focus) — **fixed in commit `003b12c89`** (stage.focus applies
    pending bounds unconditionally, like the old setter; set_focus then only
    fires focusIn/Out when the focus actually changes).
  - **Confirmation run 29213827286 (sha `003b12c89`): avm2 801 / 1,204 + 22 RM
    = 823 effective (68.4%), ZERO pass→fail regressions in avm2 or ANY AVM1
    suite** (edittext_autosize_lazy_bounds_interactions newly passing again),
    wasm-link-smoke green. Net Stage-8 gain: **+48 effective** over Stage 7.


## State (Stage 7)

- **Stage 7 COMPLETE (2026-07-12): 28/31 Stage-7 candidates pass locally**
  (`_investigation/STAGE7_CANDIDATES.txt`; exit >=22 met). The 3 misses are
  triaged there: draw_alpha_erase (needs the Stage-9 draw() blend pipeline),
  loader_bitmap_transparency (needs Loader + JPEG/PNG decoders — deferred),
  bitmap_pixelsnapping (upstream `ignore = true`). What landed:
  - `SWFRecomp/src/abc/abc_timeline.cpp` — decode DefineBitsLossless/2 to
    straight-RGBA pixel tables at RECOMPILE time (zlib inflate + 8-bit
    palettized / 15-bit / 32-bit swizzle, ported from Ruffle
    render/utils.rs); emit `avm2_generated_bitmaps` + `avm2_generated_binaries`
    (DefineBinaryData) + `avm2_generated_sounds` (DefineSound metadata). Also
    fixed a PlaceObject3 className bug (the SWF19-spec `HasImage && HasChar`
    wording is wrong — Ruffle uses `HasImage && !HasChar`; the old code
    mis-parsed the char id of every image placed by id, e.g. timeline
    Bitmaps).
  - `SWFModernRuntime/src/avm2/avm2_bitmap.c` (new, ~1.1K lines) —
    flash.display.BitmapData (premultiplied ARGB pixel store, exact Flash
    un-premultiply table, ctor validation with the version-gated
    is_size_valid, get/setPixel(32), fillRect, clone, dispose, noise,
    get/setPixels + copyPixelsToByteArray, get/setVector, copyPixels (+alpha
    source + blend_over), floodFill, threshold, hitTest, histogram,
    pixelDissolve (Feistel permutation), colorTransform, copyChannel, scroll,
    getColorBoundsRect; SymbolClass-bound subclass construction from the
    embedded asset) and flash.display.Bitmap (bitmapData/pixelSnapping/
    smoothing, cached-dims self bounds, timeline placement seeding).
  - `avm2_display.c` — BITMAP chars instantiate as Bitmap display objects;
    a BitmapData-subclass-bound bitmap char seeds a plain Bitmap whose
    bitmapData is that subclass (ctor run with 1,1). Bitmap self bounds hook.
  - `avm2_globals.c` — flash.geom.Point.toString ("(x=, y=)").
  - Seedling smoke: recompiling the real SWF emits 284 bitmaps + 116 binaries
    + 88 sounds (matches the census); generated abc_timeline.c is ~46 MB of
    raw RGBA — compresses well, revisit before Stage 9 (see memory).
  - **CI baseline (run 29209081975, 2026-07-12): 754 / 1,204 passing + 21
    ruffle_matched = 775 effective (62.6%)** — +27 over Stage 6's 748, in
    avm1 (634/706, unchanged), gnash/shumway (73/92, unchanged), regression
    (41/41, unchanged); wasm-link-smoke green. 28 newly passing (all Stage-7
    bitmap candidates). The single avm2 "newly failing" is a PHANTOM regression
    from upstream test drift, NOT this change: `stage_properties2`'s output.txt
    grew 8→213 lines upstream (now asserts full stack-TRACE frames for the
    Stage 2071 setters — `Error$/throwError`/`set height`/`logError`); our
    getStackTrace formatting for those setter frames differs. Unrelated to
    BitmapData/Bitmap; a pre-existing getStackTrace gap newly exposed.


**Plan:** `SWFRecompDocs/plans/avm2-support-plan.md` (umbrella; stages,
architecture sketch, tranche definitions). Phase-1 metric: pass rate on this
suite's trace tests.

## State

- **CI baseline (run 29180816425, 2026-07-12): 727 / 1,201 passing +
  21 ruffle_matched = 748 effective (62.3%)** — up from Stage 5's 657
  effective (+91), **zero pass->fail regressions** in avm2 or ANY AVM1
  suite (avm1 634/706+17RM, gnash suites, shumway 73/92 + 46/47,
  regression 41/41 all unchanged), wasm-link-smoke green. Beyond the 62
  candidate passes, Stage 6 also unlocked all_classes/security/swf11,
  cryptscore, button_nested_frame, displayobject_hittestobject,
  edittext_autosize_height_dynamic and other bystanders (+88 raw).
- **Stage 6 COMPLETE (2026-07-12, commits `45a507da5`..`415205ed7`):
  75/85 Stage-6 candidates pass locally** (72 pass + 3 ruffle_matched;
  exit criterion >=60 met; `_investigation/STAGE6_CANDIDATES.txt` carries
  the triage of the 10 misses: 7 flash.text.engine
  (TextBlock/TextLine family, own follow-up), 2 Loader-infrastructure
  font tests, 1 device-font metric parity). What landed:
  - Tranche 0 — all 13 Stage-5 stragglers: instance scope = class scope
    + [class object] (static slot writes from ctors), SimpleButton
    event/order/naming fixes (wrapper counter slot, nested-framescript
    ctor ordering, set_state detach, set_state_child semantics,
    addedToStage state recursion, button-parent added-event gate),
    nextScene/prevScene current-scene fallback, goto Replace
    swaps-in-place per type, manual_frame_construct.
  - `SWFRecomp/src/abc/abc_timeline.cpp` — full DefineEditText parse ->
    `avm2_generated_edittexts`; DefineFont2/3 (names/codes/advances/
    metrics) -> `avm2_generated_fonts`; CSMTextSettings (tag 74).
  - `SWFModernRuntime/src/avm2/avm2_text.c` (new, ~5K lines) — TextFormat
    (nullable fields, round_to_even, 64-char font cap), FormatSpans
    (normalize/get/set/replace/mix_with), from_html parser + to_html
    writer (canonical FP form), condense_white_swf8, the layout engine
    (f32-exact metrics, wrap_line, align/margins/justify/bullet,
    two-pass autosize, LAZY autosize bounds incl. render-phase apply),
    the full TextField property/method surface, flash.text.Font
    (SymbolClass binding, enumerateFonts/registerFont), StyleSheet
    (CSS parser + EditText integration), TextRun/TextLineMetrics/
    Rectangle/ColorTransform classes, flash.text.engine.FontDescription
    + constant classes, flash.utils setTimeout/setInterval.
  - Display: TextField width/height/x/y route through EditText bounds;
    hitTestObject/hitTestPoint/getBounds/getRect/globalToLocal/
    localToGlobal; Transform concatenatedMatrix (FP quality quirk)/
    pixelBounds/colorTransform; real stage.focus tracking; AVM2 trace
    normalizes \r to \n.

- **CI baseline (run 29174330330, 2026-07-12): 639 / 1,201 passing +
  18 ruffle_matched = 657 effective (54.7%)** — up from the E4X
  baseline's 476 (+163), **zero pass->fail regressions** in avm2 or ANY
  AVM1 suite, wasm-link-smoke green.
- **Stage 5 COMPLETE (2026-07-12): 141/159 Stage-5 candidates pass
  locally and in CI** (`_investigation/STAGE5_CANDIDATES.txt`; exit
  criterion >=100 met; the 18 misses are triaged in that file's header —
  5 infrastructure (Loader/BitmapData/filters/TextField-matrix/
  ApplicationDomain), 6 frame/goto edge semantics, 7 SimpleButton
  event-order details). What landed (commits `f662d9b9a`..`66ae469e1`):
  - `SWFModernRuntime/src/avm2/avm2_events.c` — real flash.events:
    Event internal state + const getters + clone/formatToString family,
    EventDispatcher with priority buckets/capture split/dedup, the
    3-phase DOM dispatch, EventDispatcher(target) aggregation,
    willTrigger parent walk, IEventDispatcher interface aliases, the FP
    broadcast registry (enterFrame/exitFrame/frameConstructed/render,
    length-snapshotted iteration).
  - `SWFRecomp/src/abc/abc_timeline.cpp` — an independent second pass
    over the decompressed tag stream (AVM2 SWFs only) emitting
    RecompiledABC/abc_timeline.c: per-timeline place/remove op tables
    (matrices/names/depths/ratio/visible), frame labels (scene data
    supersedes FrameLabel tags), scenes, a character dictionary with
    bounds + EditText initial text (HTML pre-stripped), DefineButton/2
    state records, stage rect/rate/bg color.
  - `SWFModernRuntime/src/avm2/avm2_display.c` — the AVM2-owned display
    tree: full DisplayObject property surface (matrix decomposition
    cache, twips quantization, exact NaN/Infinity rules, width/height
    cross-coupled scale formulas), container render/depth-list duality
    (rotate-move insert, timeline lock/pull via placed_by_avm2_script,
    2006/2024/2025/2150/3783), Ruffle's allocator model for
    script-created objects, Sprite.constructChildren with the
    RUNNING_CONSTRUCT_FRAME guard, the 5-phase tick, queued gotos +
    survives_rewind, scenes/labels surface, Stage (frameRate clamps,
    color alpha, 2071 setter overrides, invalidate->render),
    SimpleButton eager state construction (wrapper sprites, the
    has-MovieClip nested frame + one-shot framescript order),
    TextField.text, FrameLabel/Scene/Graphics/Matrix/Transform/System
    classes. runSWF_avm2 drives the real frame lifecycle.
  Session prompt `SWFRecompDocs/prompts/avm2-stage5-frames.md` carries
  the gotcha list + the static-slot-write lead for the button misses.
  Next: input.json harness (interactive tests), flash.display.Loader /
  LoaderInfo, BitmapData, or the AVM1-interop track.
- **CI baseline (run 29165717217, 2026-07-11): 475 / 1,201 passing
  (39.6%)** — up from tranche 3's 411/1200 (+64), **zero pass->fail
  regressions** in avm2 or ANY AVM1 suite (avm1 634/706, gnash suites,
  shumway 73/92 + 46/47, regression 41/41 all unchanged),
  wasm-link-smoke green. Beyond the 51 candidate passes, the E4X commit
  also unlocked flash_xml, flash_xml_cloneNode, flash_xml_namespace,
  flash_xml_removeNode (the legacy family), issue_13780, checkfilter,
  doabc_is_eager, bitmapdata_draw_cpu_overwrite_gpu, and three
  edittext_autosize* runtime_error->0-line-mismatch conversions; 40
  more tests moved runtime_error -> output_mismatch (they now run to
  the end). A follow-up commit added describeType(null/undefined)
  ("null"/"void" types), getQualifiedSuperclassName, and the
  flash.utils-vs-avmplus describeType split (1010 on undefined) —
  confirmed by run 29166383620: **476/1201 (39.6%)**, null_void_types
  now passing, zero regressions anywhere, wasm-link-smoke green.
- **E4X/XML engine (2026-07-11): 53 / 55 E4X candidates pass locally**
  (`_investigation/E4X_CANDIDATES.txt`; exit criterion >=40 met). The 2
  misses are triaged infrastructure gaps, not E4X gaps:
  xml_socket (needs flash.net.XMLSocket + the Ruffle test-framework
  socket.json mock) and xml_appendchild_swf_v21 (its first 7 lines pass;
  the rest needs flash.display.Loader loading loadable.swf).
  What landed:
  - `SWFModernRuntime/src/avm2/avm2_e4x.c` — E4XNode tree, hand-written
    parser for the E4X subset (entities + char refs with Ruffle's
    "&[^;]*;-or-verbatim" rule, CDATA/comments/PIs, DOCTYPE/decl skip,
    lenient end tags, dup-attr 1104, errors 1083-1097), namespace
    resolution (xmlns decls, dxns), ECMA-357 ToXMLString with
    prettyPrinting/prettyIndent, toString simple-content rules,
    matches_name/handle_input_multiname (incl. the original-set+public
    rebuild — xml_explicit_use_namespace), deep equals/copy, mutation.
  - `SWFModernRuntime/src/avm2/avm2_xml.c` — XML/XMLList classes: full
    method surface (namespace ops incl. the ECMA 9.1.1.13 prefix strip,
    appendChild/insertChild*/replace/setChildren with maybe_escape_child
    SWF gates, normalize, setName 1117 + namespace clearing), class-call
    conversions (XML(x) identity, 1088), settings statics, the
    [[TargetObject]]/resolve_value append machinery, list numeric-index
    [[Put]], the notification API (attributeAdded/attributeChanged/
    nameSet with ancestor bubbling — xml_notification_bubbling), and the
    legacy flash.xml.XMLNode/XMLDocument/XMLNodeType family (ported from
    Ruffle's AS3 impls; xmldocument/xmlnode/xml_ignore_white).
  - Property engine: XML/XMLList receivers intercept get/set/delete in
    every path of avm2_ops.c (static/dyn/QName/RTQName), with the
    avmplus Toplevel.cpp quirk (public method-trait hits reroute to E4X
    access; explicit AS3::name binds the method), numeric-index rules
    (xml[0] === xml; node->obj wrapper caching for ===), call fallback
    (simple-content string delegation, 1-element list delegation), `in`/
    hasOwnProperty, enumeration hooks, with-scope resolution for filter
    loops, abstract_eq XML/XMLList/QName arms, and the XML+XML → XMLList
    add operator.
  - Ops: GetDescendants (static/lazy/RTQName forms), CheckFilter (1123),
    Dxns/DxnsLate (ctx->dxns, dynamically scoped via avm2_call_method_ref
    save/restore + SET_DXNS reset; feeds handle_input + parser).
  - Integration: AMF3 writer XML arm (0x0B XmlString, pretty-sensitive —
    amf_xml), QName is_attribute flag (honored by lazy names and
    flash_proxy::isAttribute — qname_as_lazy_name_attribute_multiname),
    real describeType (E4X tree: attrs, extendsClass chain, constructor
    signatures, Object's AS3 method trio; atom-int class rule —
    function_proto_created, number_autoconv), avmplus flag constants,
    primitive builtin classes now SEALED|FINAL, avm2_alloc(0) fixed
    (empty-table ABCs — xml_explicit_use_namespace).
  **Census ceiling 1155 -> 1163/1164** with 128 ops
  (`_investigation/E4X_OPS.txt` = TRANCHE3_OPS + GetDescendants/
  CheckFilter/Dxns/DxnsLate); the only op-blocked test left is the
  alchemy (Li8/Sf64/...) one.

- **CI baseline (run 29158224391, 2026-07-11): 411 / 1,200 passing
  (34.2%)** — up from tranche 2's 354/1200 (+57), zero pass->fail
  regressions in avm2 or ANY AVM1 suite (avm1 634/706, gnash suites,
  shumway 73/92 + 46/47, regression 41/41 all unchanged),
  wasm-link-smoke green. Beyond the candidate list, the tranche unlocked
  error_tostring, fast_index_access, get_definition_by_name,
  get_qualified_class_name, nested_iteration, net_getClassByAlias,
  number_autoconv_amf, stage3d_sampler x2, and
  coerce_to_primitive_side_effects_with_nulls (ruffle_matched). NOTE:
  bytearray_oom now runs far enough to TIMEOUT in CI instead of
  erroring (it is upstream-ignored, but it costs its timeout budget
  each run).
- **Stage 4 tranche 3 (2026-07-11): 48 / 53 tranche-3 candidates pass
  locally and in CI** (`_investigation/TRANCHE3_CANDIDATES.txt`; exit
  criterion >=42 met). The 5 misses, all triaged: bytearray_oom +
  dictionary_weak_keys (upstream-ignored / known_failure), amf_xml +
  qname_as_lazy_name_attribute_multiname (E4X — XML literals /
  GetDescendants, deferred to the E4X plan), amf_array_serialization
  (needs flash.net.LocalConnection/NetConnection plus the Ruffle
  test-framework Navigator fetch mock — deferred).
  New since tranche 2: Namespace/QName classes + PushNamespace + the
  full lazy-namespace multiname surface (RTQName/RTQNameL emission,
  QName-valued lazy names, ns-set trait matching for lazy names),
  flash.utils.Dictionary (object-identity keys, numeric-name enumerants,
  tombstoned expandos + a Ruffle dynamic_map-style enumeration cursor so
  delete-during-iteration doesn't shift the iterator),
  flash.utils.Proxy (full property-engine hook routing incl. enumeration
  + coerce_to_primitive side effects), flash.utils.ByteArray
  (endian-aware I/O, avmplus-lenient UTF-8 decode, iconv-backed
  readMultiByte/writeMultiByte, zlib compress/uncompress, [] index
  access), AMF3/AMF0 readObject/writeObject byte-exact against Ruffle's
  flash-lso output (string/trait/object reference-table quirks included),
  flash.net.registerClassAlias/getClassByAlias/ObjectEncoding, a minimal
  Date (millis + getTime/valueOf/toString), and flash.geom.Point as a
  sealed two-slot class. flash.errors instances now keep name "Error"
  (their constructors never re-set it after super()).
  **Census ceiling 1148 -> 1155/1163** with 124 ops
  (`_investigation/TRANCHE3_OPS.txt` = STAGE4_OPS + PushNamespace).
  Remaining blocking ops: GetDescendants (3, E4X), CheckFilter (3, E4X),
  DxnsLate/alchemy (1).
- **CI baseline (run 29154109023, 2026-07-11): 354 / 1,200 passing
  (29.5%)** — up from Stage 3's 296/1198 (+58), zero pass→fail
  regressions in avm2 or ANY AVM1 suite (avm1 634/706, gnash suites,
  shumway 73/92 + 46/47, regression 41/41 all unchanged),
  wasm-link-smoke green. Remaining avm2 statuses: 764 output_mismatch,
  71 runtime_error, 11 ruffle_matched. Beyond the candidate list, the
  tranche unlocked application_domain, event_* (bubbles/cancelable/
  type), eventdispatcher_dispatchevent_this/haseventlistener,
  primitive_edge_cases, resolve_order, rng, symbol_class_root_not_zero,
  negative_volume_panned.
- **Stage 4 tranche 2 (2026-07-11): 50 / 55 tranche-2 candidates pass
  in CI and locally** (`_investigation/TRANCHE2_CANDIDATES.txt`; was 2
  at the Stage-3 baseline — the ≥45-of-55 exit criterion is met). The 5
  misses are all triaged to later work: class_call +
  amf_nondynamic_function_prop (ByteArray/AMF, tranche 3),
  coerce_to_primitive_side_effects (Proxy, tranche 3),
  function_proto_created (avmplus-shell describeType XML / E4X, deferred),
  json_stringify (its output.txt is hand-edited to Ruffle's FnvHashMap
  property iteration order — unmatchable in principle; one line differs).
  New since Stage 3: Vector (ApplyType + full runtime, avm2_vector.c),
  RegExp backed by vendored QuickJS libregexp
  (SWFModernRuntime/third_party/quickjs-libregexp, avm2_regexp.c) incl.
  String match/replace/search/split regex paths, JSON (avm2_json.c,
  SWF13+ gated), the avmplus Error name/message slot model +
  flash.errors classes, minimal flash.events Event/EventDispatcher,
  flash.system.ApplicationDomain (currentDomain + has/getDefinition),
  a describeType attribute stub, findproperty's global-prototype-chain
  fallback, primitive scope boxing, and lenient ConstructProp on
  primitive receivers.
- **Stage-3 CI baseline (run 29145483298, 2026-07-11): 296 / 1,198
  passing (24.7%)** — zero pass→fail regressions in avm2 or ANY AVM1
  suite, wasm-link-smoke green. 152/166 tranche-1 candidates.
- **Static op-surface ceiling: 1148 / 1162 censused tests** with the
  Stage-4 op surface of 123 IR ops
  (`_investigation/STAGE4_OPS.txt`; Stage 3's 122 ops + ApplyType — the
  census: `python3 SWFRecomp/tools/abc_op_census.py --implemented-file
  ruffle-tests/tests/swfs/avm2/_investigation/STAGE4_OPS.txt`).
  Remaining blocking ops: PushNamespace (6), GetDescendants (4, E4X),
  CheckFilter (3), DxnsLate/alchemy ops (1).
- **What exists now (Stage 3, 2026-07-11):**
  - **Emitter** (`SWFRecomp/src/abc/abc_emit.cpp`): full-body emission —
    `op_N:` labels for every branch/switch/exception target, gotos for
    Jump/IfTrue/IfFalse/LookupSwitch, inline (noreturn) aborts for
    unsupported ops with NO truncation. Bodies with active exception tables
    push an `Avm2TryFrame` (setjmp) whose handler dispatches to the catch
    target with the thrown value as the sole stack entry; `sp`/`scope_n`
    are volatile in such bodies. Emits int/uint/double pools, method
    signatures (flags, param types, optional defaults, return type,
    activation traits, `is_function`), class interfaces + protected ns,
    trait default values, and the SWF version
    (`avm2_generated_swf_version` — sort/parse quirks are version-gated).
    Class/script initializer bodies are marked "interpreter mode" (avmplus
    runs them interpreted; the index fast path then ignores the ns set —
    class_init_interpreter_mode, array_access_interpreter).
  - **Runtime** (`SWFModernRuntime/src/avm2/`, now 11 files): full coercion
    matrix + abstract eq/lt + ECMA Add split; Number→string via shortest
    round-trip decimal + Ruffle's MAX_PRECISION exponential arm;
    string_to_f64/int ports (incl. the >15-digit and powi rounding quirks);
    property engine with getters/setters (GETSET merge), prototype chains,
    bound-method caching (obj.m === obj.m), interface-ns aliases,
    protected-ns aliases with override sync, slot metadata tables
    (shadowed parent slots keep their own defaults — supercalls), typed
    slot coercion, sealed/dynamic miss semantics (1069 vs 1081/1056,
    strict "public" = empty-URI Namespace/Package); functions/closures
    (NewFunction, NewActivation, arguments/rest, optional defaults,
    unchecked functions, 1063 with FP display names, call/apply,
    fn.prototype incl. explicit-null state); typed exceptions
    (setjmp/longjmp try frames, is_of_type catch matching, catch-scope
    objects with a synthetic sealed class named after the variable,
    uncaught errors abort only the current top-level entry); debug call
    stack + Error.getStackTrace (construction-time snapshot, FP frame
    names); builtins: Object/Class/Function, String (UTF-16-aware
    length/charAt/charCodeAt/index math over UTF-8 storage, Flash-table
    case mapping, split/slice/substr/substring/indexOf/lastIndexOf/
    localeCompare/fromCharCode incl. surrogate pairs), Number/int/uint/
    Boolean (toString radix, toFixed/toPrecision/toExponential in Rust
    digit-string style), Array (dense+sparse storage, holes resolving
    through the prototype, avmplus qsort port with SWF-version compare
    quirks, sortOn, splice/slice/indexOf/removeAt/insertAt/...), Math
    (avmplus RNG seeded from MOCK_DATE_TIME), Error family (exact FP
    message strings), toplevel (trace/isNaN/isFinite/parseInt/parseFloat/
    escape/unescape/getQualifiedClassName/getDefinitionByName in both
    flash.utils and avmplus namespaces), stubs for XML/XMLList/Date/
    flash.geom.Point.
  - **Harness**: `verify_output.py` gained Ruffle-framework approximations
    semantics — numeric compare is enabled by the presence of an
    `[approximations]` section (epsilon 0 = exact double equality) and
    `max_relative` is honored. Tests with no section keep exact string
    compare, so AVM1 suites can only gain from this.
- **Remaining tranche-1 misses (14, all triaged):**
  - RegExp (tranche 2): string_match, string_replace, string_search,
    string_split, function_unbound_this (also needs dispatchEvent).
  - Vector/ApplyType (tranche 2): try_catch, class_call (also ByteArray),
    array_vector_null_callback.
  - describeType / E4X XML output (deferred): number_autoconv,
    function_proto_created.
  - ByteArray/AMF (tranche 3): number_autoconv_amf.
  - Display/graphics (Stage 5): nan_scale.
  - Upstream `ignore = true`: number_tostring (added to
    ignored_tests.txt along with bytearray_oom in the Stage-3 audit).
- **ABC front-end (Stage 1)** and **Stage-2 wiring** unchanged — see git
  history of this file for the Stage-1/2 tables.
- Run one test: `python3 ruffle-tests/verify_output.py --test=NAME
  --tests-dir=ruffle-tests/tests/swfs/avm2 --diff`. Do NOT run the full
  suite locally (project rule) — full suite via CI.

## Tranche targets (from the 2026-07-10 corpus survey)

1. **Tranche 1 (~90):** pure language — DONE 2026-07-11 (see above).
2. **Tranche 2 (~50):** Vector, JSON, RegExp, object/proto edge cases.
   Vector (ApplyType) is the single biggest unlock: 80 censused tests.
3. **Tranche 3 (~60):** Namespace/QName/Proxy/Dictionary, ByteArray, AMF.
4. **Deferred:** XML/E4X (~51 + describeType), frame-lifecycle tests
   (Stage 5), graphics.
