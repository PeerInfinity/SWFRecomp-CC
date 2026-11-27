# NO-GO register: work ruled not worth doing (and why)

**Maintained by:** each fan-out coordinator at closeout. Add new verdicts, move refuted ones to §2, and keep every
reopen criterion current. Companion doc: [`PROJECT_STATE.md`](PROJECT_STATE.md) (state + what IS worth doing).
**Compiled:** 2026-11-26, after session 28; **updated 2026-11-27 at s29 closeout** (arc §30, PB §28), from the arc §20–§29, the playbook §18–§27, the s28 reports and the memory
notes. Each claim is cited to where it was ruled.


**Read this first.** Every entry below is a *claim to re-test*, not an instruction
(`memory/disposition-docs-age-into-instructions.md`). In s20, seven standing verdicts fell in one
session, and each one fell when someone built the thing and ran it, not when someone read about it. So every
row carries a reopen criterion. Since the 2026-11-24 ruling, the target is **Flash Player 32**. A NO-GO
whose reason was "it costs a Ruffle-golden pass" is suspect wherever the golden is not Flash.

**Statuses** come from the FINAL s29 results on master (`51ab63688`, run `45938113471`, graphics; NG `63bcc2dd8`). "rm" means
`ruffle_matched`. **Golden provenance** comes from `session28-fanout-reports/trace-provenance.md` (TP).

**Abbreviations**
- Arc: `polish-sweep-arc.md`
- PB: `graphics-fanout-playbook.md`
- s28/…: `session28-fanout-reports/…`
- KF: `known_failure`
- RvF: `RUFFLE_VS_FLASH_DIFFERENCES.md`

---

## 1. Standing NO-GO / declined verdicts

### 1a. Trace axis

| item | rows affected | verdict + reason | ruled where | reopen criterion |
|---|---|---|---|---|
| **action_order family** (per-clip sibling exec-list interleave) | gnash `action_order/ActionOrderTest3/4/5`, `PlaceAndRemove`, `action_execution_order_extend_test`, `_test11` (all mismatch). Plus `_test4` (rm→mismatch in s28 after upstream deleted its `.ruffle.txt`). The `_test`, `_test6`, misc-swfc `_test10` and `loop_test10` (all rm) are owned by the same family | NO-GO, STRUCK s17 ("do not re-fund"). Root-last moved 3/4/5 closer, but none flip | s17 (Arc ~l.2269). Re-confirmed in every board through Arc §27.4, §28.4 and §29.4. s28/w1-drift | The AVM1 exec list becomes flat and instantiation-ordered (each clip's ENTER_FRAME in that list). Or a game needs it. Goldens = Flash (TP), so these are real gaps. **s29 `078350610` (browser-attach-order) landed the SCRIPT half**: natural-advance frame scripts are one list, newest place_seq first, `_root` last, across nested/timeline/attached clips (kill switch `SWF_EXEC_ORDER_MERGED=0`). `_test11` moved Flash-ward (10 → 8 diff lines), none flipped. Still open: enterFrame-before-own-script and the clip-event merge (n-exec-order §2b reqs 1, 3) |
| `global_proto_decls`, `_delete`, `global_instance_decls` | 3 avm1 (mismatch, KF, root-ignored) | **Real Flash gap, priced L** (resolved s29). The golden IS Flash (TP; s29 w1-disposition-audit). Our native-object property set/enumeration differs both ways. The old "Flash uses DONT_ENUM" ignore premise is refuted | Arc §25.2 (s24). s29/w1-disposition-audit | A native-object table generated from the FP32 golden (per class: members, attributes, order), shared with gnash `argstest-v6/7/8` |
| `globals_monkeypatch` | 1 avm1 (mismatch, KF) | NO-GO: the `_global` indirection arc. Upstream rewrote the test (drift), and +5 lines in s25 | Arc §22.5, §23.4. s23 w1-trace-tail §5. Arc §29.4 | FP32 cannot test the last 38 golden lines (they need a `FileReference.browse` host dialog, per TP). Reopen if a `_global`-indirection arc is funded for games |
| `external_interface_monkeypatch` | 1 avm1 (mismatch, KF, 4/139) | NO-GO (L): needs an AS-level `ExternalInterface.as` port (`_initJS`/`_toJS`/`_callOut`…) | s23/w1-drift-avm1. s24/w1-avm1-tail. Arc §29.4 | Golden = Flash (TP). Reopen if an EI.as port is funded for another reason, such as games that monkeypatch EI |
| `GradientFillTest` | gnash misc-ming (mismatch, 123/278) | NO-GO (L+): exact Flash gradient readback in every mode. There is no `.ruffle.txt`, so rm is impossible. The residual is ramp precision, not AA | s18 (plan refuted). s19 "structurally unpromotable". s22. s27/w1-render-bitmap-leads. Arc §29.4 | FP32 is untestable (Linux 39 lines vs Windows 2, ±1 channel). Reopen only after a Flash-exact gradient ramp/sampler model lands on the pixel side |
| shumway `esc` | 1 (mismatch, 0/2) | NO-GO (AOT ceiling): the test compiles ABC with ESC at runtime and `loadBytes`es it. The #1009 null deref (`Util::Hashtable/makeTable`) caps the row at 1/2 | s26 audit (re-priced). Arc §27.4, §29.4 | Never under AOT, unless an ABC interpreter ships. The #1009 fix is a separate robustness lead |
| `avm2/avm1_root` `_level0` | 1 (mismatch, KF, 12/58) | Measured NO-GO: a "temporal attachment state" rule. Flash's own file holds both answers ten lines apart. "Do not build a third gate" (two narrowing gates were built and refuted) | s20 (Arc §21.5). s24/w1-avm2-tail §0.3. s26 audit | A new mechanism hypothesis, plus a Flash fixture that pins the temporal rule. Golden = Flash (TP) |
| `set_property_values/swf4` | 1 avm1 (mismatch, KF) | User ruling 2026-09-29 is to match Flash. The store-0 trade (+1 rm by demoting `swf4opcode`) is DECLINED: "do not re-price it". The "print 1/0" rider was refuted (it would match Ruffle, not Flash) | Arc §22.5. s26 audit | A Flash-exact SWF4 `setProperty` arc (L) gets funded. It covers the `"10x"` abandon, 16.16 `_xscale` quantisation, and `Object is not a function` warning lines. Golden = Flash with `--log-warnings` (TP) |
| `mixed_avm/avm1_loads_avm2` | 1 (mismatch, 3/7) | NO-GO (L): needs an AVM1-parent → AVM2-child arc | s22/w1-crossvm §4.3. s24 §0.3. s26 audit | That arc gets funded. Golden = Flash (TP) |
| `sandbox_type_remote` | avm1 + avm2 (mismatch, 1/3) | HOLD (M): needs localhost child mapping plus a per-movie sandbox type | s22 ignore entry. s26 audit | FP32 cannot test it locally (needs a remote sandbox). Reopen with a harness that serves a remote origin |
| `avm2/verify_method_info_duplicate` | 1 (mismatch, 1/2) | ACCEPTED Cat 2: the trailing `#1065` contradicts the passing `_oob`. Keying on `#1121` would demote `_oob` | ACCEPTED Cat 2. s24 §0.3 (attack failed). s26 audit | A principled avmplus `parseMethodBodies` discriminator between #1121 and #1027. TP: golden = Flash apart from a blank-line convention |
| `avm2/bom`, `avm2/loader_load` | 2 (mismatch) | **NO-GO: Flash-nondeterministic** (resolved s29). FP32 AVM2 for-in order is hash-scattered and changes between runs of the same SWF, so no deterministic model matches its golden. Same class as `eforin_*` | s29 coordinator FP32 captures (`w1-local-oracles/w1-disposition-audit/forin_order`). s29/w2-disposition-land | None while the oracle is nondeterministic |
| `eforin_001`, `eforin_002` | 2 from_avmplus (mismatch) | ACCEPTED Cat 12: for-in order is implementation-defined | ACCEPTED Cat 12. s26 audit (wording fixed) | None. TP: FP32 for-in order is nondeterministic (run 1 ≠ run 2) |
| gnash `argstest-v6/7/8` | 3 (mismatch, KF) | ACCEPTED Cat 3: native-object enumeration differs (e.g. PrintJob members) | ACCEPTED Cat 3. s26 audit (counts stale) | A native-object enumeration model, shared with the decls rows. Goldens are Flash (v6 Windows FP32, v7 = FP32, v8 untestable) |
| gnash `RegisterClassTest4` | 1 (mismatch, KF) | ACCEPTED: load/ctor ordering | gnash ACCEPTED. s26 audit | Golden = Flash (TP). Reopen if loaded-shell/loader tick work moves it |
| gnash `matrix_accuracy_test1` | 1 (mismatch) | P3 (+2) GO landed; the remaining lines are NO-GO | s26 audit P3 | The oracle is Flash 10 (`output.fp10.txt`). Reopen with an FP10-vs-FP32 matrix rule |
| avm1 `pixelDissolve` | 1 (mismatch) | ACCEPTED: Flash's dissolve permutation is not Ruffle's Feistel. P2 (+16) landed; the rest is NO-GO | ACCEPTED summary. s26 audit | FP32 stalls after `pixelDissolve(…,100,-2,…)`, so the golden tail is unverifiable (TP). Reopen only if Flash's PRNG is recovered |
| avm1 `date` | 1 (mismatch) | ACCEPTED (4 rows): platform UB NaN/Infinity casts, extreme-date TZ offset, inconsistent UTCHours at -8.64e15, and a spec-correct NaN preference | ACCEPTED Cat 1/2/4. s26 audit | None. FP32 is untestable here (wall-clock) |
| `movieclip_hittest_shapeflag` | 1 avm1 (mismatch, 6 lines) | **Resolved pre-s30** (`session30-fanout-reports/pre-launch-oracles/README.md` §1): golden == FP32 LNX byte-for-byte. Lines 171–177 (4) stay ACCEPTED Cat 8 (device-font outlines, proprietary). Lines 71 (`layers` shape geometry) and 296 (morph boundary; FP32 `false` like Ruffle's integer-twip path) are REAL gaps, not ACCEPTED | ACCEPTED Cat 8. Pre-launch FP32 2026-11-27 | The row cannot flip while 171–177 stand (needs Flash's device-font outlines). Lines 71/296 are open S leads (s30 board) |
| `array_sort_swf10_32bit` / `_64bit` split | 2 avm2 (`_64bit` rm) | Declined (platform): the SWFs are byte-identical, and FP32 is 64-bit | Arc §29.4. s28/w1b-rm-avm2 refutation 2 | A flash_fix that swaps the `_32bit` golden to FP32's 64-bit output. Then the measured 64-bit atom model gives +1/0 |
| `displayobjectcontainer_stopallmovieclips_nonconstructed` | 1 avm2 (rm) | NO-GO by design: the SWF crashes FP, and the golden is the pre-crash output | s28/w1b-rm-avm2 bucket S | Never replicate a crash. ACCEPTED candidate (entry not yet written) |
| gnash `Inheritance-v5` | 1 (rm) | NO-GO: a cyclic `instanceof` hangs Flash, and the golden is truncated at the hang | s28/w1b-rm-gnash B17. ACCEPTED 1a | Never replicate a hang. (`-v6..v8` are a separate, priced M–L item) |
| Platform-split rows (Windows-FP32 goldens; Linux FP32 differs) | avm2 `Number/cos`, `html_text_img_parsing`, `soundchannel_soundcomplete`, `uncaught_errors_stringified`; avm1 `asnative_instrument`; gnash `ASnative-v5..8`, `Math-v5..8`, `Microphone-v6..8`, `MovieClipLoader-v7/8`; shumway `loader-events`, `flash_text_TextField2` (all rm) | NO-GO (soft). Leave the dispositions | s28/w1b-rm-avm2 bucket R. w1b-rm-gnash B16/B16b. w1b-rm-avm1-misc | A decision to target Windows FP32, or a capture showing we're wrong on Linux FP32 too. `MovieClipLoader` local MEDIA loads have a real gap underneath |
| `loader-events` root `httpStatus` | shumway `as3-loader/events/loader-events` | NO-GO by ruling: Ruffle-only (Flash prints progress) | Arc §23.4 (s22) | None. The row's rm residual is the platform-soft item above |
| w1b "priced, not worked" buckets (ruffle_matched rows with Flash goldens) | ~21 avm1-misc rows + 70 gnash rows over 20 mechanisms + avm2 buckets K–Q | Priced NO-GO at the current price, with a completion mechanism named per bucket. Includes `target_paths/swf5/6` (L), the device-font metrics family (`device_font_no_ink`, `flash_text_TextField`, `edittext_device_transform_metrics`, gnash `TextFormat-v7/8`, `EmbeddedFontTest`), AVM2 frame/event lifecycle (`loader_events_2`, `avm2_loads_avm1_events`, `simplebutton_childevents_*`, `swf_9_*goto*`, `LoaderTest`), `avm1movie` (L), typed nulls (L), hand-assembled ABC (`freestanding_superclass`, `weird_superinterface_properties`), debug line info (`event_handler_exception`), the FTE line model (`textblock_*`), and gnash B7–B9, B12, B14–B15, B17–B20 | s28/w1b-rm-{avm1-misc,gnash,avm2}. Arc §29.4 | These are real Flash gaps, NOT won't-fix. Each bucket's "completion" cell is its reopen criterion. Cheapest named: gnash B20e `ExternalInterface-v8` (S), B8 `loadVariables` meth (S, 0 standalone flips) |

### 1b. Pixel axis

| item | rows affected | verdict + reason | ruled where | reopen criterion |
|---|---|---|---|---|
| **Flash-exact HIGH coverage AA** (renderer-global) | glyph AA, `graphics_draw_triangles`, `acid-text-*`, `acid-mask` | **NO-GO, MEASURED s29** (w1-aa-sizing). The premise "Flash HIGH = 4×4 SSAA" is refuted: Flash HIGH is 4 sub-scanlines at y + j/4 × exact x coverage, quantised to 1/16 (`out = floor((dst(16−n)+cn)/16)`), vertices on the ¼-px grid (w1-text-pixels). Built Flash-exact, it flips 0 of the 10 failing HIGH rows and costs 7 Flash-golden + 4 regression passes; 130 of the 140 failing pixel rows are LOW, where it cannot help. Text keeps the CPU-coverage path (s29 w2-text-coverage-land) | s29/w1-aa-sizing, w1-text-pixels | The structural residues of `acid-shapes`, `acid-mask` and `strokes/scale` are fixed, so AA becomes the floor on those rows. Then re-run the w1-aa-sizing gate |
| `acid-textfield` | shumway acid (fail, tol 0) | NO-GO: Flash anti-aliases CSMTextSettings/FlashType text even at LOW (golden has 795 colours, ours 7) | s28/w1-acid-flash #5 | A FlashType/subpixel grid-fit text rasteriser. Unwinnable at tol 0 otherwise |
| `acid-shapes` | shumway acid (fail; 243 → 88 over limit at s29) | **Live Flash target** (resolved s29). w1-pixel-flash-gaps B moved it 243 → 88 with a geometry rule. Pre-s30 FP32 HIGH capture (golden == FP32 == WIN): it fails only t16 (+85) / t32 (+88), edge-only AA; the t128 residue is 146 px of missing coverage on thick curved strokes' outer edges. It needs BOTH the curved-stroke edge geometry and the faithful HIGH AA rule | s28/w1-acid-flash #4. s29/w1-pixel-flash-gaps B, w1-aa-sizing. Pre-launch README §3 | Fix the curved-stroke edge geometry, then re-run the w1-aa-sizing gate on this row (the AA NO-GO's reopen criterion) |
| GPU display-filter growth | display blur/glow rows | NO-GO, re-priced: unobservable by construction on an unscaled object. The only visible difference is kernel-tail length | PB §26/§27. s28/w1-filter-residuals #4 | A scaled-object fixture where tail length shows. Then it is a kernel-taps slice, not growth |
| "Flash-fidelity NO-GOs of record" (PB §25, minus the s27 swaps) | AVM2 `gfx_gen_ramp` twin (moves *away* from Flash); CPU `BitmapData.draw` gradient sampler; `colorconversion/h263` (3 px; h263-rs port; a float IDCT is a CI-determinism hazard); `bitmapdata_draw` (host-dependent tol-128 hinting); F/G device-font + FlashType text rows and ~5–6 device-text rows (Windows ClearType-off host, unreproducible); `font_lookup_as3` | NO-GO: the fix would not move toward FP32, or the golden's host can't be reproduced | PB §25 (s26). PB §26 "unchanged minus swaps". PB §27 | Per row: a Flash capture or model that proves movement toward FP32. Device-text: the s27 Windows ClearType-off pass did NOT reproduce them, so they keep "unreproducible host" |
| `graphics_simple_shapes`, `gradientTransform` | avm2, shumway | **Live Flash targets** (resolved s29). `gradientTransform` golden swapped to FP32 (flash_fixes, s29 w2-pixel-gaps-land, WIN == LNX). Neither is a NO-GO | PB §25; s29 | — (ordinary targets) |
| `definefont4`, `blend_scroll`, `bitmapdata_opaque`, `graphics_draw_path`, `strokes/scale` | 5 (fail) | No longer NO-GO: golden-swapped to Flash in s27 (`flash_fixes`). They still fail; the residual is now honest | PB §26 (s27 swaps) | Ordinary Flash targets now. Price against FP32 |
| `sprite_with_frames` | avm2 (fail, 4944) | NO-GO until both the text AA and the LOW stroke rule land (the floor is two "Frame 1" labels) | s28/w1-avm2-vector-flash | s29: the "LOW stroke y rule" was refuted (w1-lowq-next) and the LOW stroke raster landed (`6a27fc2e0`); re-grade it vs an FP32 LOW capture. Text AA at LOW stays the floor |
| `BeginBitmapFill` | gnash (fail, 951/100) | NO-GO: the floor is the device-font label (666 px) | s25. Re-confirmed s28/w1-avm2-vector-flash | A device-font render model that matches FP32 |
| 101 priced Flash-over-Ruffle pixel losses (s28) and `acid-color-0` (IJG JPEG, s27) | 101 comparisons (stroke snap 51, LOW model 54, drawing-API snap 3, filter residuals 2, minus recoveries); `acid-color-0` 18838 | DECLINED to recover. Each loss is against a Ruffle-made or exporter golden and was priced by name before landing. Never trade a Flash-correct model for a Ruffle golden | Robert's ruling 2026-11-24. Arc §29. PB §27. snap-pixel-audit. lowq-corner-rule §6 | Only an FP32 capture showing the landed model is wrong for that row. Otherwise the remedy is a golden swap through `flash_fixes` (needs FP32 proof; Windows check first for `invalidClipDepth`, `from_shumway/gradient`, `acid-gradient(-0)`, `acid-filter`) |
| Zero-headroom rows (s24) | `bevel_*`, `glow_with_alpha_strength`, `fills_and_lines`, `fallback_preferences` | **Obsolete** (resolved s29, w1-pixel-flash-gaps): the s28 Flash models moved every row, so "zero headroom vs Ruffle goldens" no longer applies. `fills_and_lines`: FP32 WIN ≠ LNX, golden kept (host-dependent, RvF) | PB §23; s29/w1-pixel-flash-gaps | Grade each against FP32, not its Ruffle golden |
| gnash `shape_test` open-fill parity | gnash misc-ming (fail) | **NO-GO (L)**: 89% of the residual is open-path fill parity across objects (Flash closes/fills per object differently); place_object_test's LOW glyph part DID land | s29/w1-pixel-flash-gaps | A Flash fill-rule model for unclosed paths across shape records, fitted to FP32 |
| LOW translation snap in WORLD space | LOW rows | **Measured negative** (keep): a world-translation snap fails the Flash LOW gate (row 3 nesting 234 px); Flash snaps PER display-list level (TSNAP, landed `1fcf2b1c1`) | s29/w1-lowq-next, w2-lowq-tsnap | None |
| `bitmapdata-clone` | shumway avm2 (pass) | Nothing to do: bit-exact vs Flash, 0 headroom vs its Ruffle golden. An RvF candidate if it ever flips | PB §26/§27 | It flips to fail. Then write the RvF, don't "fix" it |
| `avm1_edittext_rotated_glyphs` (vs Flash) | regression fixture (passes its own golden) | HOLD: 70% of the 1111 px are box borders (Flash's rotated hairline is 25–32% heavier) | s28/w1-text-glyph-aa #3. PB §27 | A rotated/sheared border model fitted to FP32 |

### 1c. Infrastructure / perf

| item | rows affected | verdict + reason | ruled where | reopen criterion |
|---|---|---|---|---|
| AVM2 nursery/bump allocator + generational GC arc | AVM2 perf (RWK, Seedling) | RULED OUT: birth/death is ~6% at HEAD (tier-2 GC and lever 6 harvested it). The free-allocation ceiling is <1.10x. It would also fight the conservative ext scan and arena bitmap | memory `avm2-alloc-arc-ruled-out` (2026-07-20) | A fresh CDP profile of *current* HEAD (none exists on disk) shows the alloc cluster well above 6%. The biggest lever is property GET at 28.4% |
| Inline slots (object + slots in one o1heap block) | AVM2 heap | RULED OUT and reverted: o1heap bins to pow2(size+32), and `sizeof(Avm2Object)` = 208, so a slot tail crosses a bin. Live heap +22% for 1.2% Ir | memory `avm2-inline-slots-ruled-out-o1heap-binning` (2026-07-19). Comment on `avm2_object_alloc` | First shrink `Avm2Object` below the bin boundary, or give o1heap non-pow2 size classes. A bin-gated variant was also rejected |
| Pooled FlxQuadTree / FlxList | RWK quadtree (70.84% of frame) | DEAD: only 9.21% of the region is allocation. The native intrinsic is the lever | memory `avm2-quadtree-is-71pct-pooling-dead` | None. Use the native intrinsic |
| GC on `heap_alloc` failure / within-tick emergency collection | AVM2 runtime | NEVER: method locals and stacks are C locals invisible to the marker, so collection would cause a use-after-free that can look like a pass | memory `avm2-gc-cannot-run-mid-method`, `avm2-browser-footprint-truth` | Precise stack maps or a shadow stack for generated code (its own arc) |
| ABC_OPT -O2/-O3 | AVM2 perf | Ruled out: noise-identical | memory `avm2-findprop-scope-hit-ic` | A new optimizer pass with a measurable Ir win |
| Linking Ruffle's render crates into the runtime | renderer | RULED OUT (user decision 2026-07-29): wgpu-on-Emscripten is WebGL2 not WebGPU, there is no C ABI, the retained/immediate boundary doesn't match, and it is perf-neutral | memory `ruffle-code-reuse-ruled-out` | Only a new user decision. The two viable variants if revisited: lyon tessellator as a Rust staticlib in the *recompiler*, or porting Ruffle's MIT WGSL shaders (missing filters + 9 blend modes) |
| Perf numbers from WSL/WSLg Chrome | all browser perf | NEVER: it is SwiftShader. Use Windows Chrome via WSL interop | CLAUDE.md. `tools/divergence/perf/WINDOWS_PLAYWRIGHT_FROM_WSL.md` | None |
| Frame-rate A/Bs for sub-ms effects | browser perf | Not valid: noise at this size. Use an in-wasm timer (the drawing-API snap measured +0.11 ms, not ~0.7) | Arc §29.2 | None |
| Raising the fixed caps that are NO-GO | `MAX_PENDING_DIALOGS` 16 / `MAX_FILEREF_OPS` 8, `SWF_LOG_FETCH_MAX_QUEUED` 64, `MAX_LEVEL_ADVANCE` 128 / `MAX_DEFERRED_SHELL_CLEARS` 64, `WORKER_PENDING_MAX`, `MAX_WATCH_FIRING`, `MAX_SOUND_CHANNELS` 32 (= Flash's own), `MAX_PLAYING_SOUNDS`, `MAX_ACTIVE_NETSTREAMS` | NO-GO: unreachable in practice, harness-log-only, non-silent, or deliberate resource caps | s28/w1-leads (robustness table) | A row or game hits the cap. Other caps (`MAX_SCROLL_CROPS`, `TIMERS`, …) are still *open* robustness items, not NO-GO |
| FileReference `download()`/`upload()`/`postData` | AVM1/AVM2 FileReference (23 rows pass) | NO-GO, nothing to do: AVM1 is a full Ruffle-mirroring implementation, and Ruffle's AVM2 versions are stubs too | s28/w1-leads #3 | A graded row or a game that needs it. Arc §28.4 still listed it as a "small leftover", so this verdict supersedes that |
| Harness `G-d` tick emulation (`num_ticks` when runtime `stage.frameRate` ≠ header) | harness | HOLD until a row proves a gain | Arc §24.4 | A failing row whose diff is that tick mismatch |

### 1d. Cancelled by user decision

| item | scope | decision | ruled where | reopen criterion |
|---|---|---|---|---|
| **N procgen substrate arc** | level load/detect substrate, level generator (`n-level-generator-plan.md`, P0–P2 done), portals (`n-portals-plan.md`), JS physics (`n-physics-js-reimplementation-plan.md`) | CANCELLED: the whole arc. Existing code and docs stay in place; the N pixel-parity ladder is unaffected | Robert, 2026-11-26 | A new decision from Robert only |

---

## 2. Recently overturned in s26–s29 (do NOT cite these as NO-GO)

Session 26 = Arc §27.2. Session 27 = Arc §28.2. Session 28 = Arc §29.2, plus the s28 wave-2/3 reports.

- "Per-movie DL phase 3 is NO-GO (−2 on `cross_call`)": found GO and landed as w2-loaded-shell-land (s28 w1).
- "Per-movie display lists = L": phase 1 was M and gave +1 (s26).
- "A bare goto in a loaded movie routes to ROOT": it was silently dropped. Fixed `9fa68316e` (s26).
- "`acid-color-0` step 3 NO-GO, floor ~110": it flipped. It is now a priced Flash-over-Ruffle loss (s27).
- "`acid-shapes` 88 = translucent self-intersecting fills" (HOLD): refuted, 0 interior mismatches (s28).
- "`bitmapbuttons` NO-GO feature slice": 618042 → 52 (s26).
- "`pixelbender_dithering` needs a re-sync / only the CPU bitmap-fill arm": it passes against its Flash golden (s26/s27).
- gnash `sound` "no audio simulation" (ACCEPTED): it was SWF6 case-insensitive nav. It passes (s26).
- `pixelDissolve` ACCEPTED mechanism and `matrix_accuracy_test1` oracle: both were wrong (Flash 10 oracle). Docs were corrected (s26).
- "Native attached-clip button dispatch is CI-visible": it is not (0 rows) (s26).
- "AVM1 off-diagonal ColorMatrix needs the GPU pass": false for RGB (s26).
- "acid-clip fill-region order, priced ≤50%": it was cross-layer stroke-over-fill order, and it flipped (s26).
- "Land `glow_kernels` with Ruffle's trace": retired (s26). Then "glow_kernels / draw_filtered held for a Flash capture": captured, landed green (s27).
- "stage3d fractal/raytrace: a failing Context3D call": it is the CPU shading-budget latch (s26).
- "`action.c:10605` is a live miscompile": it was latent UB, fixed as prevention (s26).
- "The native soft-wrap gap may be a large family": 0 corpus rows. The s26 wordwrap fixture was Flash-invalid (s27).
- "Flash 32 decodes JPEG flat like stb": that was `draw()` mipmapping. The IJG model stands (s27).
- "N3 layer-group alpha: Ruffle is per-child like us": Flash groups for filters/blends/alpha (s27).
- "Both hitTest RvF candidates": they were the unpinned show-all scale race (s27).
- "Browser gaps are action.c arms": several lived in `tag.c`/`swf.c` (s27).
- "`ruffle_matched` ≈ pass": 212/259 have FLASH goldens. They are real gaps, and 73 are closed (s28).
- "gnash `place_object_test` / `shape_test` goldens are not Flash; deferred swap": VOID. The old PinStub never applied LOW. They ARE Flash goldens, so our miss is a real gap (s28).
- "The LOW corner paint rule is wrong": the corner rule is right. The defect was reflect/repeat spread (s28).
- "A closed stroke seam is a join": Flash CAPS it (s28).
- "test12 needs an SWF ≤ 7 gate": the rule is FP10's queued enterFrame on a removed clip. Landed (s28).
- "shapeflag hitTest needs a shape-flag fix": the rule is stale last-render bounds (s28).
- "Date TZ rows are gaps": they are harness timezone. "`toString_valueOf-v5` is a regression": refuted (s28).
- "The occupied-depth warning is a Ruffle artifact": Flash prints it under ErrorReporting (s28).
- "Our 4 own stroke fixtures have Flash goldens": none did (s28).
- "The Tetris wasm break is attached-goto code": it was stale RecompiledScripts (s28).
- **`avm2/number_tostring` ACCEPTED Cat 14 / "D2A port: 0 flips even if ported"**: the "corrupt digits" ARE Flash's printer. The avmplus D2A port passes it, and w1b bucket J gave +9 (s28 w2b-avm2-d2a).
- **gnash B10 `Selection.setSelection` HOLD** ("breaks `avm1/selection`"): the break was focus state. `Selection-v6..8` pass (s28 w2b-gnash-holds).
- **gnash B11 "Flash compares NaN by bit pattern"**: the rule is atom identity. `ops-v5..8` pass (s28).
- **gnash B6/B19** (Object-v5, Number-v5, Global-v6) were priced NO-GO in w1b and now pass (s28 w2b-gnash-holds).
- **`load_cancel_via_unloadmovie` HOLD**: it passes ("unloadMovie cancels a load"). `_unloadclip` is still rm (s28).
- **"Thin-stroke tie rule: the global prototype is NO-GO"** (w1-render-flash-headroom #4): superseded by the n-stroke-snap Flash model, which landed (s28).
- **"The harness should render at the golden's quality (HIGH)"**: refuted. `gradientTransform` got worse (s28 w1-render-flash-headroom #1). This is a measured negative; keep it.

**Session 29** (Arc §30.2):
- "`native_objects_swf6` ACCEPTED: we match Flash" / UNSURE: it was a 1-line gap, now pass (s29 w2-disposition-land `883d02f35`).
- "`avm2/bom` is a real Flash gap (TP)": FP32 AVM2 for-in order is hash-scattered AND differs between runs, so a single FP32 golden cannot be matched (s29 coordinator captures). Re-filed in §1a as Flash-nondeterministic.
- "`dependent_strings` is RvF / Ruffle-internal": FP32's empty lines are now the golden (flash_fix) and it passes (s29).
- "`globals_swf5` costs 3 gnash `-v5` passes": the trade was void; those gnash goldens are Flash too. It passes (s29 `883d02f35`).
- "`swz` / `loader_applicationDomain` = AOT ceiling (Cat 13)": FP32 refuses the unsigned SWZ with #2044/#2046. Both now print the Flash path (`loader_applicationDomain` pass s29 interim #3; `swz` pass at s29 FINAL via the URLLoader-ctor stack, w3).
- "from_avmplus Date TZ rows are harness-only NO-GO": `mock_timezone` + per-timestamp DST landed; all 15 avmplus Date rows pass (s29 w2-rm-avm2-land `73d80aea1`).
- The s28 "Open HOLDs" `attach_movie_export_not_yet_run`, `tab_ordering_properties_tab_index_edge_case`, `load_cancel_via_unloadclip`: all three pass (s29 w2-rm-avm1-gnash-land / w2b-tabindex, FP32 fixtures). LocalConnection queue growth, gnash `Function-v5` and the B2' rule stay held (§1a "w1b priced" row).
- "`avm1_color` no-snap rule NO-GO": FP32 shows cacheAsBitmap snaps at LOW only; 1200 → 230 (s29 w2-pixel-gaps-land).
- "Flash HIGH = 4×4 SSAA": it is 4 sub-scanlines × exact x coverage, 1/16-quantised (s29 w1-text-pixels).
- "The LOW stroke y rule" (s28 board): masks are filled curves at fractional placement; the rule is TSNAP + the LOW stroke raster (s29).
- "goto(current frame) re-runs the frame (CI)": Flash is stop/play only, = Ruffle `no_op_goto` (s29 browser-gotoandstop-current).
- "gotoFrameFromInterval needs an after-enterFrame timer check": refuted by FP32; the rule is target children's frame-1 scripts in TAG order (s29 w1-timers-goto).
- "The s26 wordwrap golden is not Flash": it already is FP32 (s29 w1-text-pixels).
- "gnash `ExternalInterface-v8` B20e is S": half refuted; the rest is native enumeration (s29 w1-rm-avm1-gnash).

Older items that also fell (pre-s26; listed so they aren't re-cited):
- the `MovieClip-v8` NO-GO (s24 → rm);
- `swf13` (now pass);
- the `bug_483783`, `pcre_find_fixedlength`, `external_interface`, `embed_name_lookup` and audio-trio NO-GOs (all pass);
- `video_prototype_lazy_swf6_child` (pass);
- `mouse_pick_avm1_root` (pass);
- `blend_shader_luma_lighten` (image passes);
- `static_text_offstage`, `text-bind`, `shader_as_mask` (pass).

---

## 3. ACCEPTED_DIFFS categories (avm1 `_investigation/ACCEPTED_DIFFS.md`)

The doc defines **14 categories**:
1. platform/UB-dependent expected output;
2. internally inconsistent expected output;
3. Flash quirks we don't replicate;
4. Flash UB we intentionally don't replicate;
5. test-harness limitations;
6. missing feature (image loading);
7. Ruffle known failures;
8. shape hit-test accuracy limits;
9. video decoder implementation differences;
10. watch-handler deep re-entrancy, **RESOLVED 2026-08-12**;
11. graphics MSAA-vs-Flash rasteriser differences;
12. implementation-defined `for…in` order;
13. AOT ceiling: runtime-loaded `.swz` ABC;
14. corrupt upstream oracle, **RESOLVED s28** (`number_tostring`).

The summary table has **35 rows**, of which 11 are marked RESOLVED/REMOVED/STALE. That leaves about **24 active rows across ~15 tests**. Most are trace-line residuals of a few lines each: `date` ×4, `array_sort` ×2, `movieclip_getbounds`, `movieclip_library_state_values` ×2, `native_objects_swf6`, `native_subclasses`, `tab_ordering_..._edge_case`, `movieclip_hittest_shapeflag` ×3, `pixelDissolve`, `verify_method_info_duplicate`, `eforin_001/002`, `swz`, `loader_applicationDomain`. The rest are the three Spark/H.263 video image rows.

**Staleness flags** (from today's final results):
- `avm1/netstream_play_flv` and `visual/video/deblocking` now **pass** their image comparisons, although the table still lists 44 and 104 outliers.
- `colorconversion/h263` is at 3 outliers, not 10 808.
- `native_objects_swf6`, `tab_ordering_..._edge_case` and `swz`/`loader_applicationDomain` have premises that s28 trace-provenance contradicts (see the UNSURE rows above).

Prune or re-word these before anyone cites the table.

---

## 4. UNSURE items, collected

All 12 s28 UNSURE items were worked or re-graded in s29. Resolutions (detail in §1 rows and §2):

1. `global_proto_decls*` / `global_instance_decls`: **resolved**. The golden IS Flash; real gap, priced L (§1a, native-object table from the FP32 golden).
2. `native_objects_swf6`: **resolved, passes** (§2).
3. `avm2/bom`: **resolved, NO-GO**. FP32 for-in order is nondeterministic between runs (§1a).
4. `avm2/dependent_strings`: **resolved, passes** with the FP32 golden (§2).
5. `globals_swf5`: **resolved, passes**. The gnash `-v5` trade was void (§2).
6. `swz` / `loader_applicationDomain`: **resolved**. Both print the FP32 securityError path (§2; `swz` graded at s29 FINAL).
7. `tab_ordering_properties_tab_index_edge_case`: **resolved, passes** (root accessor materialises on the first root lookup miss; §2).
8. `movieclip_hittest_shapeflag`: **resolved pre-s30** (FP32 run 2026-11-27): golden = Flash; 4 lines device-font ACCEPTED, lines 71/296 real gaps (§1a).
9. `acid-shapes`: **resolved, live target** (243 → 88 in s29, structural residue; §1b).
10. `cache_as_bitmap/avm1_color`: **resolved**. cacheAsBitmap snaps at LOW only; 1200 → 230 (§2).
11. `graphics_simple_shapes` / `gradientTransform`: **resolved, live targets**; `gradientTransform` golden is FP32 now (§1b).
12. s24 zero-headroom rows: **resolved, obsolete** (§1b).

New UNSURE items from s29:
- TextField `tabIndex = null`: we still coerce to 0; clips/buttons unset (FP32). Needs an FP32 text-field capture (s29 w3 lead).
- ~~`avm2/avm2_layer_group_alpha` / `_erase`~~: **resolved pre-s30**: WIN == LNX; TSNAP's move was Flash-ward (t2 81 986 vs exporter golden 89 617). Re-golden to FP32 LOW in s30; the ~80 k remaining gap is a live lead (pre-launch README §4).
