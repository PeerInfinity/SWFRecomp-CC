# Project state: SWFRecomp-CC

**As of:** 2026-11-27, after fan-out session 30 (code `6441e7d5d`). **Maintained by:** each fan-out coordinator at
closeout (update §1–§3), plus any one-task session that changes a track's status (update §4).
**Companion:** [`NO_GO_REGISTER.md`](NO_GO_REGISTER.md) lists everything ruled not worth doing, each entry with a
reopen criterion.

This page replaces the stale headline numbers in `ruffle-tests/tests/swfs/_investigation/OVERVIEW.md` (2026-07)
and `feature-priority-map.md` (2026-07). Per-session detail lives in `polish-sweep-arc.md` (trace, §31 = s30) and
`graphics-fanout-playbook.md` (pixels, §29 = s30).

**The goal** (Robert's ruling, 2026-11-24): match **Flash Player 32**, not Ruffle. Ruffle's test corpus is the
instrument. A Ruffle golden that FP32 proves wrong gets corrected in `ruffle-tests/flash_fixes/`, never chased. The
oracle is a real FP32 projector, scripted locally (`tools/flash-oracle/`).

## 1. Corpus state (Ruffle test suites)

Source: the s30 FINAL runs. Graphics `46090531443` (results `8abd7880f`); no-graphics `46095073993`
(results `4fb87dedb`, **4890 eff**: identical to graphics except the two audio rows below and the `bug1157243/empty` intermittent, which passed in NG). Mode differences are only `audio/aac` and `avm2/audio_computespectrum`. Never quote these
forward: re-read the newest results (memory `ci-baseline-must-be-read-fresh`).

### Trace (graphics mode)

| suite | rows | pass | ruffle_matched | failing | effective |
|---|---:|---:|---:|---:|---:|
| from_avmplus | 1574 | 1567 | 5 | 2 | 99.9% |
| avm2 | 1353 | 1322 | 26 | 5 | 99.6% |
| avm1 | 791 | 776 | 6 | 9 | 98.9% |
| regression | 346 | 346 | 0 | 0 | 100.0% |
| from_gnash/actionscript.all | 243 | 193 | 47 | 3 | 98.8% |
| from_shumway | 229 | 217 | 10 | 2 | 99.1% |
| visual | 151 | 149 | 2 | 0 | 100.0% |
| from_gnash/misc-ming.all | 111 | 77 | 27 | 7 | 93.7% |
| from_gnash/misc-swfc.all | 21 | 17 | 3 | 1 | 95.2% |
| from_gnash/misc-swfmill.all | 20 | 20 | 0 | 0 | 100.0% |
| timeline | 17 | 16 | 1 | 0 | 100.0% |
| mixed_avm | 12 | 10 | 1 | 1 | 91.7% |
| text | 12 | 12 | 0 | 0 | 100.0% |
| fonts | 9 | 8 | 1 | 0 | 100.0% |
| from_gnash/misc-mtasc.all | 9 | 7 | 2 | 0 | 100.0% |
| stage3d | 8 | 8 | 0 | 0 | 100.0% |
| swf | 7 | 7 | 0 | 0 | 100.0% |
| audio | 5 | 5 | 0 | 0 | 100.0% |
| import_assets | 3 | 3 | 0 | 0 | 100.0% |
| **total** | **4921** | **4760** | **131** | **30** | **99.4%** |

**Read "effective" with care.** `ruffle_matched` (rm) means "our diffs are a subset of Ruffle's diffs". It is not a
Flash pass. s28's `trace-provenance` found 139 of the then-185 rm rows have FLASH goldens; s29 closed 29 and s30 26
more, so **about 85 of the 131 rm rows are real Flash gaps** (re-derive per row from TP before citing).
- Honest Flash-correct count: 4760 pass, plus at most ~46 rm rows.
- Hidden work: about **115 rows** (~85 rm + 30 failing).
- `regression/` (346 rows, all pass) is our own fixture suite, goldens mostly FP32 captures.

**The 30 failing rows**, all dispositioned in `NO_GO_REGISTER.md` §1a: the gnash action_order family ×5
(`ActionOrderTest3/4/5`, `PlaceAndRemove`, `extend_test`; s30 moved `test11` and `_test4` to pass), the AVM1
native-object enumeration rows (`global_instance_decls`, `global_proto_decls_delete`, `argstest-v6/7/8`; s30 moved
`global_proto_decls` to rm), `globals_monkeypatch`, `external_interface_monkeypatch`, `set_property_values/swf4`,
`date`, `pixelDissolve`, `movieclip_hittest_shapeflag` (4 device-font lines, ACCEPTED), `sandbox_type_remote` ×2,
`avm2/avm1_root`, `bom`, `loader_load`, `verify_method_info_duplicate`, `eforin_001/002`, `GradientFillTest`,
`RegisterClassTest4`, `matrix_accuracy_test1`, shumway `esc`, `mixed_avm/avm1_loads_avm2`, and shumway
`as3-loader/bug1157243/empty` (the known ±1 load intermittent: it passes locally and in most CI runs).

### Pixels (graphics `images=true`)

- **564 pass / 137 fail** (+6 ignored, 3 skip; 710 comparisons). s30 on the s29 intersection: **+3 / 0**
  (`acid-shapes`, `gradients`, `morph_test1` frame1); 8 new comparisons pass.
- s30 Flash models: drawing-API and timeline HIGH curve flatten 0.01 px; LOW symmetric vertex tie; LOW field-local
  pen; LOW DefineFont2 whole-px advance at SWF ≥ 7. Earlier: HIGH text coverage, TSNAP, the LOW stroke raster, seams.
- 100 goldens are FP32-corrected through `ruffle-tests/flash_fixes/fixes.json` (+7 in s30).
- Flash-exact HIGH AA stays MEASURED NO-GO (s29). The residual convex stroke excess is NO-GO (s30: Flash is wider
  than the exact offset).

### Trajectory

| when | trace effective | pixels pass | note |
|---|---|---|---|
| 2026-07-24 | 3211 / 4463 (71.9%) | n/a | full corpus imported |
| 2026-07-31 | 3999 / 4421 (90.5%) | n/a | feature-priority arcs |
| s25 (2026-11-22) | 4622 / 4662 | 561 / 613 | |
| s27 (2026-11-24) | 4781 / 4819 | 626 / 665 | real Flash oracle arrives |
| s28 (2026-11-26) | 4827 / 4864 | 545 / 685 | Flash over Ruffle: +75 trace by name, −101 priced pixels |
| s29 (2026-11-27) | 4860 / 4893 | 552 / 692 | +34 trace by name, 0 regressions; flash_fixes 62 → 93 |
| **s30 (2026-11-27)** | **4891 / 4921** | **564 / 701** | +30 trace by name (26 rm→pass), 0 real regressions; pixels +3 / 0; flash_fixes 93 → 100 |

## 2. Worth doing: corpus (ranked; detail in arc §31.4 and playbook §29)

1. **The ~85 Flash-golden rm rows.** The w1b "priced, not worked" buckets (register §1a). Cheapest named (s30
   w1-rm-avm1-gnash table): `Function-v5` (SWF5 `new` sets no `__constructor__`, S, + B6 visibility, M), array-v5..v8
   B20a (M), displaylist_depths ranges (M), button duplication (M), Inheritance B17 (M–L), the ASnative id table beyond
   900/901 (L, generator from gnash `getNative`). AVM2: L1′ loader timing (HELD: needs a gradeable FP32 capture).
2. **The native-object table residue.** Generated table landed (s30). Left: FP32 version value-gating (members present
   but `undefined` below their SWF version, M–L), `for (k in Object)` (S), Error.prototype own slots (S).
3. **Exec order.** Script half (s29) + enterFrame-before-own-script (s30) landed; `ActionOrderTest3/4/5`,
   `PlaceAndRemove` and `extend_test` remain (re-measure each against its FP32 golden first).
4. **Pixels: LOW text and geometry.** `style_changes_in_html` field-5 world-y (+904 vs FP32; the switch is not font
   kind, HTML or zones), the LOW glyph chord rule (recompiler, M), `acid-scale` tie cost (+160), filters LOW (goldens
   host-dependent: grade vs LNX FP32).
5. **Small leads:** `movieclip_hittest_shapeflag` (4 ACCEPTED device-font lines only now), the morph_test1 xtrace
   glyph residue after glyph 3 (FP32 v5–v8 probe), the AVM2 twin of the timeline flatten for fonts (measured: 2 tiny
   moves, not landed).

## 3. Not worth doing (summary; full register in `NO_GO_REGISTER.md`)

- **Trace:**
  - the gnash action_order family (struck s17: it needs a flat instantiation-ordered exec list);
  - shumway `esc` and other runtime-compiled ABC (AOT ceiling);
  - the `avm2/avm1_root` temporal rule (two gates refuted);
  - `GradientFillTest` (needs a Flash-exact gradient sampler first);
  - `eforin_*` and `date` (Flash itself is nondeterministic or platform UB);
  - rows whose goldens record a Flash crash or hang;
  - platform-split rows with Windows-FP32 goldens (soft: only if we decide to target Windows FP32).
- **Pixels:**
  - recovering the 101 priced Ruffle-golden losses (only an FP32 capture reopens one);
  - FlashType `acid-textfield`;
  - GPU display-filter growth;
  - the device-text rows from an unreproducible Windows host;
  - Flash-exact HIGH AA as a renderer change (MEASURED s29: 0 flips, −11 passes).
- **Infra/perf:**
  - the AVM2 nursery/generational allocator (ceiling <1.10x), inline slots, quadtree pooling;
  - GC mid-method (use-after-free);
  - ABC_OPT -O2/-O3;
  - linking Ruffle's render crates (user decision 2026-07-29);
  - WSL Chrome perf numbers;
  - frame-rate A/Bs for sub-ms effects.
- **Overturned verdicts:** about 50 standing verdicts fell in s26–s29 alone (register §2). Treat every NO-GO as a
  claim to re-test, not an instruction.

## 4. Beyond the corpus: games, browser, perf, tooling


### 1. N (Metanet ninja): playable in the browser, pixel parity vs Flash

- **State:** The game is playable natively and in the browser. Level completion and death/retry work. Episodes 0–2 (levels 0–4) have routes that are byte-identical across Ruffle exporter, native and browser (s26–s27). Since s28 the work is pixel parity against **Flash 32**: the thin-stroke snap rule (`09b2c9130`), the drawing-API stroke snap (`e81d27317`), and the cap/corner rule for snapped strokes plus signed noScale width (`03527a3f8`, 2026-11-26). N's ep1 pixel diff improves on every tick.
- **Status:** PARKED at its stroke floor (s29). `n-seam-caps` (`faeaaba4b`, 2026-11-26) landed the seam rule — Flash caps a closed seam only when snapping separates its ends, else joins — and it was N-NEUTRAL on ep1 (the expected gain was phase luck). w3 (`2d40d3799`) made wide un-snappable drawing-API seams joins again.
- **Next step:** none funded. The remaining N stroke residue is AA granularity; Flash-exact HIGH AA was measured NO-GO in s29 (`NO_GO_REGISTER.md` §1b), so the ladder reopens only on that criterion or a new N-specific measurement.
- **Ruled out:**
  - "A closed stroke seam is a join." Flash caps it (arc `polish-sweep-arc.md` §29.2; n-join-disc).
  - Moving the quad ends to place snapped corners. It cracked corners, and the ledger caught it (n-join-disc §3.1).
  - Removing the W ≥ 2 cap/corner residue per vertex. It comes from AA granularity (4 MSAA samples vs Flash's 16) and needs an analytic-coverage pass (n-join-disc §5, item 3).
  - "The drawing-API snap costs ~0.7 ms/frame." An in-wasm timer measured +0.11 ms (arc §29.2).
  - Fixing the L1 trap-switch 27 px. It is a Ruffle tessellation-cache artifact, so the Flash rule was kept (`n-trap-stroke-report.md`, s26).
  - "Coin streaks persist." They are N's authored pickup morphs; one SwiftShader screenshot made it look like a bug (`n-gold-residue-report.md`, 2026-11-22).
  - The edge dots on ragdoll limbs. They come from Ruffle's 0.1 px curve flattening; ours draws the exact curve (`n-ragdoll-strokes-report.md`, s27).

### 2. N procgen substrate: level generator, portals, JS physics

- **Status: CANCELLED (Robert, 2026-11-26).** The whole arc is cancelled: the level-load/detect substrate, the level
  generator (P0–P2 had been done), portals, and the `nPhysics.js` reimplementation. Do not fund any part of it.
- **What stays:** the existing code and docs remain in place; nothing was deleted. The N pixel-parity ladder (§1) is a
  separate track and is NOT affected.
- **Reopen:** only by a new decision from Robert (`NO_GO_REGISTER.md` §1d).

### 3. Other AVM1 browser games (Doodle Jump, Pacman, Tetris, Minesweeper) and the DJ level loader

- **State:**
  - DJ level loader: the injected-AS procgen levels render on Ruffle, native and WASM, and the runtime `_alpha` fix landed (2026-06-12).
  - Pacman: the movement, keyboard, ghost and death-resume fixes are from 2026-06-24/25.
  - Minesweeper interactivity is DONE.
  - The newest evidence is a Tetris wasm build break. It turned out to be stale RecompiledScripts, and `build_test.sh` now regenerates stale C (`60877dc63`, 2026-11-25).
- **Status:** PARKED.
- **Next step:** The DJ PLAY freeze is FIXED (s29 `3fd694def`: an infinite same-frame self-goto requeue on 1-frame clips, in every build); DJ plays 3/3 seeds in the browser. The blue bitmap now draws. Still UNCONFIRMED: the brown platform break animation (memory `dj-platform-rendering`).
- **Ruled out:**
  - "The Tetris wasm break is attached-goto code." It was stale generated C (arc §29.2).
  - Wall-clock browser screenshots for fast game moments. Use exact-tick native PNGs or event-driven shots instead (dj-level-loader, 2026-06-12).

### 4. Browser/WASM parity (browser ladder + gate inventory)

- **State:**
  - s27 local ladder ported CI's eager placement init, per-tick advance order, and parked-root frame behaviour into the browser. It also made every browser link fail on any wasm-ld warning (`c8ed0e679`).
  - s28 sent root gotos and attached-clip gotos through the CI arms and deleted `advance_attached_clip_frames` (`dc6c75a64`, `a9fb68b42`, 2026-11-26). Browser audio is now an AudioWorklet (`0cb5464e5`, 2026-10-19).
- **s29 (local ladder, 3 slices):** goto(current frame) = stop/play only in EVERY build, CI was the wrong side (`c91637b7a`); the DJ freeze (`3fd694def`); natural-advance frame scripts as ONE exec list by place_seq across nested/timeline/attached clips, all builds (`078350610`, kill switch `SWF_EXEC_ORDER_MERGED=0`).
- **s30 (local ladder, 5 slices):** attach-child early advance gated + loopback place warning gone (`3944257a4`, browser-only); nested swapDepths/removeMovieClip act on the parent sprite's list, ALL builds (`92f7d5e8a`); timeline-sprite self-goto ported + a sprite's own GotoFrame opcode applies inline in ALL builds (`171b302e4`, `dd2f979a5`, corpus-neutral on CI); clip-event enterFrame order = CI + later-frame child init ungated (`cd519d658`, browser-only); the pending-finalize queue + slot unload events ported (`b8671fd2f`, browser-only). The browser = FP32 on the 3 exec-order fixtures.
- **Status:** ACTIVE. It is a local ladder between sessions.
- **Next steps (worth doing), in order:**
  1. `browser-pending-finalize` (s30 #5) is running at s30 closeout (code `b8671fd2f` landed, browser-only); its report names the next slice. Candidates on the board: browser = FP32 on gnash `action_execution_order_test11`/`_test4` past line 20/18 (pending-finalize) and `ng_queue_slot_unload_events` (timeline swapDepths+removeMovieClip drops onClipEvent(unload); FP32 fixture first).
  - The gate inventory's triage column is still empty; regenerate it with `tools/gate_inventory.py` (count UNCONFIRMED).
- **Ruled out:**
  - "Browser gaps are action.c arms." The eager-init, advance-order and parked-frame gaps were in `tag.c`/`swf.c` (arc §28 standing verdicts).
  - The action.c-only `SWF_BROWSER_ARMS_TU` harness as a verdict. Confirm in the real browser via child_probe (memory `browser-wasm-gate-inventory`, s27).
  - "We caught most browser branch bugs." The hit rate did not fall once exposure is accounted for (gate-inventory note, 2026-07-23).

### 5. AVM1 performance (browser games)

- **State:**
  - The property-lookup hash gate and the per-object hash index cut DJ instructions by 49% (June 2026).
  - Browser frame CPU is dominated by per-shape GPU `writeBuffer`, not AVM1 walks.
  - The newest evidence is that the attached-clip pump's O(n²) root sort cost N 1.5 ms/frame; it was fixed back to parity (`10b5dff69`, 2026-11-21).
- **Status:** PARKED.
- **Next step:** String-ID interning (`SWFRecompDocs/plans/string-id-interning-plan.md`; "Planned, not started", 2026-07-04; no size given, but it touches stack value representation and many opcodes). It is only worth doing if a game is CPU-bound, since browser AVM1 cost is mostly writeBuffer.
- **Ruled out:**
  - Adopting upstream's concurrent GC, locks or AS2-prelude stdlib for perf (`wasm-game-performance-profiling` note, June).
  - Thread-safety from upstream: near-zero benefit for 455 globals / 208 signatures of cost (`SWFRecompDocs/upstream-comparison/`).
  - The NO_GRAPHICS native profile as a browser-perf proxy (memory `browser-perf-is-writebuffer-not-avm1-walks`).
  - WSL Chrome numbers. It renders with SwiftShader, so use Windows Chrome via interop (CLAUDE.md).

### 6. AVM2 performance (Flixel / FlashPunk titles)

- **State:**
  - All 5 AVM2 demos clear 30 fps in real-GPU Chrome: Seedling 18.4 ms mean, RWIC 14.7, RWF 21.6 p50, RWK 21.6, RWP 22.5. RWK and RWP got there through the fingerprint-gated native Flixel collision intrinsic. Ruffle misses 30 fps on every title it renders, and renders nothing on RWF/RWIC (scoreboard, 2026-07-20d).
  - Later work: the Seedling level-load collide frame got 1.41x from inlining the IC slot hit (`2973513c4`, 2026-09-16), and `s += x` became amortised O(n) (`5367e2b33`, 2026-10-16).
- **Status:** DONE for the 30 fps objective. Further levers are PARKED.
- **Next step (optional):** Two levers are counted but not built: `add` Number+int (the int+int arm must stay first) and `coerce Entity`. Each is about 2.2 s of Seedling's remaining ~9.5 s level-load frame (memory `seedling-collide-ic-hit-inline`). Compare→branch fusion is the highest-value item on the upstream-contribution list (`SWFRecompDocs/reference/performance-optimizations-vs-ruffle.md`). No sizes are given.
- **Ruled out:**
  - Nursery/bump allocator + generational GC: the ceiling is under 1.10x (memory `avm2-alloc-arc-ruled-out`, 2026-07-20).
  - Inline slots in one o1heap block: live heap grew 22% because of power-of-2 binning (`avm2-inline-slots-ruled-out-o1heap-binning`, 2026-07-19; the comment is on `avm2_object_alloc`).
  - Pooling FlxQuadTree/FlxList: only 9.21% of the quadtree's cost is allocation (`avm2-quadtree-is-71pct-pooling-dead`, 2026-07-20).
  - An AS3 rewrite of the quadtree: about 37 ms, which misses the bar. The native intrinsic was chosen (same note).
  - Non-this instance-slot GET specialization: gated out below noise (`seedling-instance-slot-lever-gated-out`, 2026-07-15).
  - Call devirtualization (Step 5): the gate closed the arc (`seedling-perf-compile-time-specialization`).
  - Per-title tuning or arena constants: disqualified by the "just works" objective (`avm2-browser-footprint.md` §4).
  - Claiming any `[RC]` lever as an architectural advantage over Ruffle: Ruffle's `type_aware.rs` already does 30 of 36 (`performance-optimizations-vs-ruffle.md`, 2026-07-22).
  - The GC=0 native A/B recipe for wall-clock: runs end on arena exhaustion (memory `avm2-native-ab-recipe-gc0-invalid`).
  - The "11x Ruffle gap on RWK": it was measured on a title screen; the real gap was 1.30x before the intrinsic (`rwk-ruffle-gap-is-1_3x-not-11x`).

### 7. AVM2 browser memory (arena sizing + leaks)

- **State:**
  - A native `arrayToCSV` intrinsic killed the single-tick transient, and the arena went 1984 → 512 MB for AVM2 and 1024 → 256 MB for AVM1. That was implemented and browser-rig validated on 2026-07-21 (`avm2-browser-footprint.md` head).
  - The Seedling wasm room-swap OOM is fixed (`c6be20a88` + `4c450f076`, 2026-10-03), and so is the ~78 KB/frame activation-vtable leak (`c1fa89bc2`, 2026-10-19).
- **Status:** DONE.
- **Next step:** None queued. One open flag: Snailiad's 603 MB live set exceeds the 512 MB arena, which blocks its browser demo (see §10).
- **Ruled out:**
  - A within-tick emergency collection: it breaks the between-tick quiescence invariant (`avm2-browser-footprint.md` §4).
  - o1heap size-class / binning-slack changes (same doc, §3 lever 3 and §4).
  - Freeing closure chains without an ABA-proof id (memory `avm2-raw-heap-leak-hunting`).

### 8. Seedling (FlashPunk, the headline AVM2 title)

- **State:**
  - It plays in the browser (keyboard, real audio, render), beats Ruffle at 18.4 vs 36.9 ms (2026-07-20), and its AP bridge (generic ExternalInterface subset + `__swfBridge` page) has been DONE since 2026-07-16.
  - The newest evidence is the browser SharedObject persistence host hook (`746c39489`, 2026-11-22).
  - Archipelago-CC is actively building on Seedling (its commits from 2026-11-14/15 include region-map hooks and the Seedling lab).
- **Status:** DONE (bring-up). It is maintained on demand for Archipelago-CC.
- **Next step:** Nothing is queued in this repo; the optional perf levers are in §6. UNCONFIRMED: whether Archipelago-CC has pending asks.
- **Ruled out:** Compiled-in AP hooks. The user ruled for the generic AVM2 EI subset instead (memory `seedling-ap-ei-ruling`, 2026-07-16).

### 9. Robot Wants series (RWK, Puppy, Fishy, IceCream; Flixel)

- **State:** All four are DONE, with live browser demos on docs2. RWK-1/2/3 run 2026-07-16..18, and the sequels came up on one runtime fix (LocalConnection) on 2026-07-18. The RWK Archipelago handoff page passes 13/13 livetests (2026-07-18). All titles are at 30 fps via the collision intrinsic (2026-07-20/21).
- **Status:** DONE.
- **Next step:** None recorded. The RWK kitty TAS WinState was "handed to RWK-4" (memory `avm2-rwk3-browser-demo`); whether RWK-4 ran is UNCONFIRMED.
- **Ruled out:** See §6. Also, `rwf_ruffle` / `rwic_ruffle` are dead arms for A/Bs, because Ruffle renders nothing on them (scoreboard note).

### 10. Other AVM2 bring-ups: Elephant Quest, Snailiad

- **Elephant Quest.**
  - **State:** EQ-0..EQ-4 are DONE (2026-07-22, `6fefd4552`). The goto catch-up walk gate made `init2()` complete (more than 1000 s → 6.2 s). Live scrolling gameplay runs past the point where Ruffle's watchdog freezes it, which makes EQ the first title we play that Ruffle cannot. Native text render (2026-07-22) closed gap #10. Nothing was found after 2026-07-22.
  - **Status:** PARKED.
  - **Next step:** EQ-5: menu render fidelity (MAD 37.1), the black level tile field (a render gap), and 3 non-fatal `#1009 "play"` errors (`SWFRecompDocs/plans/avm2-elephant-quest.md`; no size given). The AVM2 vector track's next item is T7 masks/blends/filters (memory `avm2-vector-render-track`).
  - **Ruled out:** `getDefinitionByName` as the init2 hotspot (`f252807fb`, EQ-3). A pixel oracle past init2 is VOID because Ruffle ends up in a different game state (plan §4).
- **Snailiad.**
  - **State:** It reached native gameplay with zero code changes (2026-07-22). Its gameplay frame scored MAD 0.261 against Ruffle. It compiles and renders in the in-browser recompiler page after the TU-split mode (28.6 min, 2026-09-02).
  - **Status:** PARKED.
  - **Next step:** From `avm2-snailiad.md` §7: a `regression/` getPixel/frame-hash gate for the boot chain; a graphics-mode spot check; a browser demo (blocked by the 603 MB live set vs the 512 MB arena); a tick-pacing check at `FlxG.framerate = 120`. No sizes. AP readiness was assessed as all-available (§8), and no apworld exists.
  - **Ruled out:** None recorded.

### 11. In-browser recompiler (`docs/recompiler/`)

- **State:**
  - Stage 1 (recompile to C + downloadable build bundle) and stage 2 (in-browser clang → WASM on a JSPI graphics host) shipped 2026-09-02. The AVM2 host variant and the try-helper, TU-split and dead-payload-skip emission modes followed, taking Seedling's in-page compile from 668.8 to 277.4 s.
  - Then came the walk API, Document-Isolation-Policy, the vendored SDK and a sha256-pinned clang (`048e9b604`, 2026-10-14).
  - The N closure fix was verified on the live page (2026-11-22).
- **Status:** DONE (maintained).
- **Next step:** Only the optional payload blob is left (about 1 day). Memory says its case is now weak: open it only if a title is actually blocked on memory or zip size (memory `avm2-in-browser-recompiler`). There is also an open lead: on the DYNAMIC_HOST path, a 1-frame root repeats its frame-1 trace every tick (memory `n-play-game-click`, 2026-11-22; UNCONFIRMED whether still open). Known limits: AVM1 try/catch (inline setjmp) is unsupported in the page, only one SWF runs per page load, and Chrome 137+ is required.
- **Ruled out:**
  - The PIC side module / MAIN_MODULE route: wasmer's slim clang 16 can't do it (`in-browser-recompiler-refresh-assessment.md` §7.1).
  - ASYNCIFY for the host: it corrupts state when the renderer sleeps mid-frame, so JSPI is required (§7.2).
  - Trace mode: removed in stage 1.
  - Tracking the generated bundle or wasm in git, or a submodule (user decision, 2026-09-02).

### 12. Archipelago (AP) integration

- **State:**
  - AVM1 `Rando` builtin: Phase 1 (native APCpp) and Phase 2 (WASM archipelago.js) are done and live-tested. Phase 3 slices 1 (pluggable transport + toy test) and 2a/2b (APQuest live, native + browser toy SWF) were done on 2026-05-31.
  - AVM2: the EI bridge (2026-07-16) and the RWK handoff (2026-07-18) are done. Seedling's leak fixes (2026-10) and the SharedObject hook (2026-11-22) serve the Archipelago targets.
- **Status:** ACTIVE in Archipelago-CC, which consumes the work (Seedling commits there on 2026-11-15). This repo's side is DONE / on demand.
- **Next step:** Phase 3 Slice 3 (the cross-repo SWF substrate via the existing `iframeAdapter` protocol) lives in Archipelago-CC (`archipelago-phase3-substrate-and-item-application.md` §8). Whether it is complete is UNCONFIRMED from this repo. A Snailiad apworld is possible: readiness is assessed, nothing is built.
- **Ruled out:**
  - The native toy-SWF live test: dropped by decision, because NO_GRAPHICS does no wall-clock pacing (phase-3 plan, Stage 2b).
  - Compiled-in AP hooks for AVM2 (§8).

### 13. Docs site / GitHub Pages (`docs/` public, `docs2/` local)

- **State:** Pages carries the demo gallery and the in-browser recompiler, and is deployed each session. The newest is the REAL deploy `45898148485` (2026-11-26). It took a third try, because `deploy-pages@v4` twice failed to list its own artifact. Pages builds link with `-Wl,--fatal-warnings`, and the runtime snapshot gained `avm1_filter_kernels.c` (`1994a761f`, 2026-11-24). `docs2/` is intentionally local-only, because it holds non-OSS games.
- **Status:** ACTIVE (routine maintenance).
- **Next step:** None beyond deploying after `docs/` or recompiler changes. Check that the Deploy step actually ran, because a green `dry_run` deploys nothing (memory `pages-dry-run-is-not-a-deploy`).
- **Ruled out:**
  - Publishing `docs2/` (copyrighted games; `docs-vs-docs2-hosting`).
  - Committing `SWFRecomp.wasm` or the bundle (CLAUDE.md; gitignored).

### 14. Upstream relationship

- **State:** The arrangement is a permanent friendly fork with knowledge exchange only, confirmed by LittleCube on 2026-07-04. The September 2026 review is done: upstream master hadn't moved, and the warnings doc was delivered.
- **Status:** PARKED.
- **Next step:** Two issue candidates are still unfiled (memory `upstream-comparison-doc-directory`). File them only if wanted.
- **Ruled out:** Code-level merges in either direction (`SWFRecompDocs/merge/upstream-relationship-2026-07.md`). Linking Ruffle's render crates (user decision, 2026-07-29, memory `ruffle-code-reuse-ruled-out`).

---

### Summary table

| track | status | last evidence | next step |
|---|---|---|---|
| N: play + Flash pixel parity | PARKED (stroke floor) | 2026-11-26 (`faeaaba4b`) | none funded; reopens on the AA criterion (register §1b) |
| N procgen substrate / portals / physics-js | **CANCELLED** (Robert, 2026-11-26) | 2026-06-30 | none |
| Other AVM1 games (DJ, Pacman, Tetris, Minesweeper) | PARKED | 2026-11-26 (`3fd694def` DJ freeze fixed) | DJ brown-platform break anim UNCONFIRMED |
| Browser/WASM parity ladder | ACTIVE (ladder, between sessions) | 2026-11-27 (`078350610`) | `browser-attach-child-early` (S), then nested swapDepths+remove (M), then self-goto port §5a (M) |
| AVM1 perf | PARKED | 2026-11-21 (`10b5dff69`) | string-ID interning (planned, not started) |
| AVM2 perf | DONE (30 fps met); levers PARKED | 2026-10-16 (`5367e2b33`) | optional: `add` Number+int, `coerce Entity` |
| AVM2 browser memory | DONE | 2026-10-19 (`c1fa89bc2`) | none (Snailiad 603 MB flag) |
| Seedling | DONE (maintained for AP) | 2026-11-22 (`746c39489`) | none queued; UNCONFIRMED AP-side asks |
| Robot Wants series | DONE | 2026-07-21 | UNCONFIRMED (RWK-4 TAS handoff) |
| Elephant Quest | PARKED | 2026-07-22 | EQ-5 render fidelity (black tile field, menu) |
| Snailiad | PARKED | 2026-09-02 | regression gate; browser demo needs arena fix |
| In-browser recompiler | DONE (maintained) | 2026-11-22 (live verify); code 2026-10-14 | none (payload blob weak); DYNAMIC_HOST repeat-trace lead UNCONFIRMED |
| Archipelago integration | ACTIVE in Archipelago-CC; this repo DONE / on demand | 2026-11-22 here; 2026-11-15 in Archipelago-CC | Slice 3 status UNCONFIRMED (Archipelago-CC) |
| Docs site / Pages | ACTIVE (maintenance) | 2026-11-27 (`46033409898`) | deploy after `docs/` changes |
| Upstream relationship | PARKED | 2026-09 | 2 unfiled issue candidates |
