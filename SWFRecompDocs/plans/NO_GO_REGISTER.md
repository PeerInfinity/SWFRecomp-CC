# NO-GO register: work ruled not worth doing (and why)

**Maintained by:** each fan-out coordinator at closeout. Add new verdicts, move refuted ones to §2, and keep every
reopen criterion current. Companion doc: [`PROJECT_STATE.md`](PROJECT_STATE.md) (state + what IS worth doing).
**Compiled:** 2026-11-26, after session 28, from the arc §20–§29, the playbook §18–§27, the s28 reports and the memory
notes. Each claim is cited to where it was ruled.


**Read this first.** Every entry below is a *claim to re-test*, not an instruction
(`memory/disposition-docs-age-into-instructions.md`). In s20, seven standing verdicts fell in one
session, and each one fell when someone built the thing and ran it, not when someone read about it. So every
row carries a reopen criterion. Since the 2026-11-24 ruling, the target is **Flash Player 32**. A NO-GO
whose reason was "it costs a Ruffle-golden pass" is suspect wherever the golden is not Flash.

**Statuses** come from the FINAL s28 results on master (`014124ed5`, run `45878805896`, graphics). "rm" means
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
| **action_order family** (per-clip sibling exec-list interleave) | gnash `action_order/ActionOrderTest3/4/5`, `PlaceAndRemove`, `action_execution_order_extend_test`, `_test11` (all mismatch). Plus `_test4` (rm→mismatch in s28 after upstream deleted its `.ruffle.txt`). The `_test`, `_test6`, misc-swfc `_test10` and `loop_test10` (all rm) are owned by the same family | NO-GO, STRUCK s17 ("do not re-fund"). Root-last moved 3/4/5 closer, but none flip | s17 (Arc ~l.2269). Re-confirmed in every board through Arc §27.4, §28.4 and §29.4. s28/w1-drift | The AVM1 exec list becomes flat and instantiation-ordered (each clip's ENTER_FRAME in that list). Or a game needs it. Goldens = Flash (TP), so these are real gaps |
| `global_proto_decls`, `_delete`, `global_instance_decls` | 3 avm1 (mismatch, KF, root-ignored) | NO-GO. The mismatch runs both ways (339 missing, 180 extra) against thousands of lines. "Nobody should touch `setupNativeFuncOwnProps` for score" | Arc §25.2 (s24). Re-confirmed in s26/w1-trace-tail-audit | **UNSURE.** The ignore entry's premise ("Ruffle's golden has Object.prototype methods ENUMERABLE; Flash uses DONT_ENUM") conflicts with TP, which ran pinned FP32 under the new stub: `global_proto_decls` was byte-identical to its golden, and `_delete` differed by one host line. So the golden IS Flash, and these are real gaps. Re-price as a native-object enumeration-model arc |
| `native_objects_swf6` | 1 avm1 (mismatch, 114/115) | ACCEPTED: "we match Flash (line 56 `new TextField()`); Ruffle's test is KF" | ACCEPTED_DIFFS summary. Re-confirmed in s26 audit | **UNSURE.** TP says golden = Flash, and our diff vs FP32 is -1/+1. That contradicts "we match Flash". Run FP32 on line 56 before citing it |
| `globals_monkeypatch` | 1 avm1 (mismatch, KF) | NO-GO: the `_global` indirection arc. Upstream rewrote the test (drift), and +5 lines in s25 | Arc §22.5, §23.4. s23 w1-trace-tail §5. Arc §29.4 | FP32 cannot test the last 38 golden lines (they need a `FileReference.browse` host dialog, per TP). Reopen if a `_global`-indirection arc is funded for games |
| `external_interface_monkeypatch` | 1 avm1 (mismatch, KF, 4/139) | NO-GO (L): needs an AS-level `ExternalInterface.as` port (`_initJS`/`_toJS`/`_callOut`…) | s23/w1-drift-avm1. s24/w1-avm1-tail. Arc §29.4 | Golden = Flash (TP). Reopen if an EI.as port is funded for another reason, such as games that monkeypatch EI |
| `GradientFillTest` | gnash misc-ming (mismatch, 123/278) | NO-GO (L+): exact Flash gradient readback in every mode. There is no `.ruffle.txt`, so rm is impossible. The residual is ramp precision, not AA | s18 (plan refuted). s19 "structurally unpromotable". s22. s27/w1-render-bitmap-leads. Arc §29.4 | FP32 is untestable (Linux 39 lines vs Windows 2, ±1 channel). Reopen only after a Flash-exact gradient ramp/sampler model lands on the pixel side |
| shumway `esc` | 1 (mismatch, 0/2) | NO-GO (AOT ceiling): the test compiles ABC with ESC at runtime and `loadBytes`es it. The #1009 null deref (`Util::Hashtable/makeTable`) caps the row at 1/2 | s26 audit (re-priced). Arc §27.4, §29.4 | Never under AOT, unless an ABC interpreter ships. The #1009 fix is a separate robustness lead |
| `avm2/avm1_root` `_level0` | 1 (mismatch, KF, 12/58) | Measured NO-GO: a "temporal attachment state" rule. Flash's own file holds both answers ten lines apart. "Do not build a third gate" (two narrowing gates were built and refuted) | s20 (Arc §21.5). s24/w1-avm2-tail §0.3. s26 audit | A new mechanism hypothesis, plus a Flash fixture that pins the temporal rule. Golden = Flash (TP) |
| `avm2/bom`, `avm2/loader_load` | 2 (mismatch) | NO-GO (L): needs hashbrown+FNV enumeration emulation, with corpus-wide for-in rider risk | RvF hashbrown entry. s24 §0.3. s26 audit | **UNSURE.** s26 called the RvF's "we and Flash use insertion order" unsupported, and TP finds the `bom` golden = Flash (-3/+3), so `bom` is a real Flash gap, not RvF. `loader_load` is untestable in FP32 (network) |
| `avm2/dependent_strings` | 1 (mismatch, 46/84) | RvF: tests the Ruffle-internal `ruffle::isDependent()` hook | RvF. s24 §0.3. s26 audit | **UNSURE.** TP: FP32 prints empty lines there. Check whether our output already equals FP32. If it does, record it as an RvF pass with no gap |
| `set_property_values/swf4` | 1 avm1 (mismatch, KF) | User ruling 2026-09-29 is to match Flash. The store-0 trade (+1 rm by demoting `swf4opcode`) is DECLINED: "do not re-price it". The "print 1/0" rider was refuted (it would match Ruffle, not Flash) | Arc §22.5. s26 audit | A Flash-exact SWF4 `setProperty` arc (L) gets funded. It covers the `"10x"` abandon, 16.16 `_xscale` quantisation, and `Object is not a function` warning lines. Golden = Flash with `--log-warnings` (TP) |
| `globals_swf5` | 1 avm1 (mismatch, 294/304, ignored) | NO-GO: un-hiding LocalConnection/NetConnection/Video in SWF5 (the Flash-correct behaviour) demotes 3 gnash `-v5` passes | Arc §25.2 (rationale replaced). s26 audit | **UNSURE under the Flash-over-Ruffle ruling.** Robert's rule is "never trade a Flash-correct pass". If the 3 gnash `-v5` goldens are not FP32 output, the trade goes the other way. Reopen: check the gnash `-v5` goldens against FP32 |
| `mixed_avm/avm1_loads_avm2` | 1 (mismatch, 3/7) | NO-GO (L): needs an AVM1-parent → AVM2-child arc | s22/w1-crossvm §4.3. s24 §0.3. s26 audit | That arc gets funded. Golden = Flash (TP) |
| `sandbox_type_remote` | avm1 + avm2 (mismatch, 1/3) | HOLD (M): needs localhost child mapping plus a per-movie sandbox type | s22 ignore entry. s26 audit | FP32 cannot test it locally (needs a remote sandbox). Reopen with a harness that serves a remote origin |
| `avm2/verify_method_info_duplicate` | 1 (mismatch, 1/2) | ACCEPTED Cat 2: the trailing `#1065` contradicts the passing `_oob`. Keying on `#1121` would demote `_oob` | ACCEPTED Cat 2. s24 §0.3 (attack failed). s26 audit | A principled avmplus `parseMethodBodies` discriminator between #1121 and #1027. TP: golden = Flash apart from a blank-line convention |
| `eforin_001`, `eforin_002` | 2 from_avmplus (mismatch) | ACCEPTED Cat 12: for-in order is implementation-defined | ACCEPTED Cat 12. s26 audit (wording fixed) | None. TP: FP32 for-in order is nondeterministic (run 1 ≠ run 2) |
| `avm2/swz`, `avm2/loader_applicationDomain` | 2 (mismatch, 0/2, 0/4) | ACCEPTED Cat 13 (AOT ceiling): runtime-loaded Flex `.swz` ABC "would require an AVM2 interpreter" | ACCEPTED Cat 13. s26 audit | **UNSURE.** TP: FP32 *refuses* the unsigned `.swz` (`#2044` securityError / `#2046` invalid signature, 3 lines; Linux = Windows). Its golden is not Flash. The Flash target may be a cheap security-error path, not an interpreter. Re-price now |
| gnash `argstest-v6/7/8` | 3 (mismatch, KF) | ACCEPTED Cat 3: native-object enumeration differs (e.g. PrintJob members) | ACCEPTED Cat 3. s26 audit (counts stale) | A native-object enumeration model, shared with the decls rows. Goldens are Flash (v6 Windows FP32, v7 = FP32, v8 untestable) |
| gnash `RegisterClassTest4` | 1 (mismatch, KF) | ACCEPTED: load/ctor ordering | gnash ACCEPTED. s26 audit | Golden = Flash (TP). Reopen if loaded-shell/loader tick work moves it |
| gnash `matrix_accuracy_test1` | 1 (mismatch) | P3 (+2) GO landed; the remaining lines are NO-GO | s26 audit P3 | The oracle is Flash 10 (`output.fp10.txt`). Reopen with an FP10-vs-FP32 matrix rule |
| avm1 `pixelDissolve` | 1 (mismatch) | ACCEPTED: Flash's dissolve permutation is not Ruffle's Feistel. P2 (+16) landed; the rest is NO-GO | ACCEPTED summary. s26 audit | FP32 stalls after `pixelDissolve(…,100,-2,…)`, so the golden tail is unverifiable (TP). Reopen only if Flash's PRNG is recovered |
| avm1 `date` | 1 (mismatch) | ACCEPTED (4 rows): platform UB NaN/Infinity casts, extreme-date TZ offset, inconsistent UTCHours at -8.64e15, and a spec-correct NaN preference | ACCEPTED Cat 1/2/4. s26 audit | None. FP32 is untestable here (wall-clock) |
| `movieclip_hittest_shapeflag` | 1 avm1 (mismatch) | ACCEPTED Cat 8 (proprietary Noto glyph outlines, morph precision). Its trace flash_fix landed in s28 | ACCEPTED Cat 8. Arc §29.4. PB §27 | **UNSURE / open lead.** w1-leads found that the 3 FP32-`false` lines are *not* our ACCEPTED lines, and that we print `true` (≠ FP32). The row keeps ≥6 diff lines. Needs one Flash run |
| from_avmplus Date TZ rows | `e15_9_5_22_1`, `28_1`, `29_1`, `35_1`, `10_10`, `10_11` (rm) | NO-GO *as runtime gaps*: the goldens are US-Pacific-TZ captures (Windows) | s28/w1b-rm-avm2 bucket I. Arc §29.2/§29.4 | A per-test `tz` override in `test.toml` + `verify_output.py` (S, harness) makes `22_1` pass as-is. `28_1`/`29_1` then expose a real S–M DST-of-result bug |
| `array_sort_swf10_32bit` / `_64bit` split | 2 avm2 (`_64bit` rm) | Declined (platform): the SWFs are byte-identical, and FP32 is 64-bit | Arc §29.4. s28/w1b-rm-avm2 refutation 2 | A flash_fix that swaps the `_32bit` golden to FP32's 64-bit output. Then the measured 64-bit atom model gives +1/0 |
| `displayobjectcontainer_stopallmovieclips_nonconstructed` | 1 avm2 (rm) | NO-GO by design: the SWF crashes FP, and the golden is the pre-crash output | s28/w1b-rm-avm2 bucket S | Never replicate a crash. ACCEPTED candidate (entry not yet written) |
| gnash `Inheritance-v5` | 1 (rm) | NO-GO: a cyclic `instanceof` hangs Flash, and the golden is truncated at the hang | s28/w1b-rm-gnash B17. ACCEPTED 1a | Never replicate a hang. (`-v6..v8` are a separate, priced M–L item) |
| Platform-split rows (Windows-FP32 goldens; Linux FP32 differs) | avm2 `Number/cos`, `html_text_img_parsing`, `soundchannel_soundcomplete`, `uncaught_errors_stringified`; avm1 `asnative_instrument`; gnash `ASnative-v5..8`, `Math-v5..8`, `Microphone-v6..8`, `MovieClipLoader-v7/8`; shumway `loader-events`, `flash_text_TextField2` (all rm) | NO-GO (soft). Leave the dispositions | s28/w1b-rm-avm2 bucket R. w1b-rm-gnash B16/B16b. w1b-rm-avm1-misc | A decision to target Windows FP32, or a capture showing we're wrong on Linux FP32 too. `MovieClipLoader` local MEDIA loads have a real gap underneath |
| `loader-events` root `httpStatus` | shumway `as3-loader/events/loader-events` | NO-GO by ruling: Ruffle-only (Flash prints progress) | Arc §23.4 (s22) | None. The row's rm residual is the platform-soft item above |
| w1b "priced, not worked" buckets (ruffle_matched rows with Flash goldens) | ~21 avm1-misc rows + 70 gnash rows over 20 mechanisms + avm2 buckets K–Q | Priced NO-GO at the current price, with a completion mechanism named per bucket. Includes `target_paths/swf5/6` (L), the device-font metrics family (`device_font_no_ink`, `flash_text_TextField`, `edittext_device_transform_metrics`, gnash `TextFormat-v7/8`, `EmbeddedFontTest`), AVM2 frame/event lifecycle (`loader_events_2`, `avm2_loads_avm1_events`, `simplebutton_childevents_*`, `swf_9_*goto*`, `LoaderTest`), `avm1movie` (L), typed nulls (L), hand-assembled ABC (`freestanding_superclass`, `weird_superinterface_properties`), debug line info (`event_handler_exception`), the FTE line model (`textblock_*`), and gnash B7–B9, B12, B14–B15, B17–B20 | s28/w1b-rm-{avm1-misc,gnash,avm2}. Arc §29.4 | These are real Flash gaps, NOT won't-fix. Each bucket's "completion" cell is its reopen criterion. Cheapest named: gnash B20e `ExternalInterface-v8` (S), B8 `loadVariables` meth (S, 0 standalone flips) |
| Open HOLDs (Flash oracle first) | `attach_movie_export_not_yet_run`, `tab_ordering_properties_tab_index_edge_case`, `load_cancel_via_unloadclip` (all rm); LocalConnection queue growth; gnash `Function-v5` (rm); B2' `with`-after-overflow rule (fitted) | HOLD pending a Flash capture | s28/w1b-rm-avm1-misc. w2-avm1-leads-land. w2b-gnash-holds. Arc §29.4 | A local FP32 capture of the shipped probe. **UNSURE** for `tab_ordering_..._edge_case`: ACCEPTED says "conflicting test expectations", but TP says golden = Flash (FP32 stores a string `tabIndex` raw on `_root`; S once decided). It should not be ACCEPTED |

### 1b. Pixel axis

| item | rows affected | verdict + reason | ruled where | reopen criterion |
|---|---|---|---|---|
| **Flash 16-level coverage AA** (Flash HIGH = 4×4 SSAA; WebGPU MSAA allows `sampleCount` 1 or 4) | renderer-global: glyph AA, `graphics_draw_triangles` residual (996), `acid-text-*` (pass only by tolerance), `acid-mask` .01/.05/.10 | NO-GO (L, renderer-global): needs 4×4 SSAA (16× fill) or an analytic coverage pass | s28/w1-text-glyph-aa #4. w1-avm2-vector-flash. w1-acid-flash #3 (acid-mask, s25 verdict stands). PB §27 | PB §27 says: size the AA mode against HIGH edge residuals *before any slot*. Reopen if that measurement shows a large row set it would flip |
| `acid-textfield` | shumway acid (fail, tol 0) | NO-GO: Flash anti-aliases CSMTextSettings/FlashType text even at LOW (golden has 795 colours, ours 7) | s28/w1-acid-flash #5 | A FlashType/subpixel grid-fit text rasteriser. Unwinnable at tol 0 otherwise |
| `acid-shapes` | shumway acid (fail; 88 → 243 over limit) | w1-acid-flash: "NO-GO, AA noise" | s28/w1-acid-flash #4 | **UNSURE.** PB §27 calls it the only Flash-golden row that worsened (0.25% away from Flash: thick curved strokes, quarter-grid AA) and keeps it *on the board* |
| `cache_as_bitmap/avm1_color` | visual (fail, 1200) | NO-GO: the Flash no-snap rule costs passes | PB §25/§26. s28/w1-avm2-vector-flash §4 | **UNSURE.** s28 corrected the premise: the no-snap rule costs a *Flash*-golden pass (not only 3 Ruffle-golden ones). A FLASH request (cached shape at x.5/y.5, LOW+HIGH) is filed. Reopen on that capture |
| GPU display-filter growth | display blur/glow rows | NO-GO, re-priced: unobservable by construction on an unscaled object. The only visible difference is kernel-tail length | PB §26/§27. s28/w1-filter-residuals #4 | A scaled-object fixture where tail length shows. Then it is a kernel-taps slice, not growth |
| "Flash-fidelity NO-GOs of record" (PB §25, minus the s27 swaps) | AVM2 `gfx_gen_ramp` twin (moves *away* from Flash); CPU `BitmapData.draw` gradient sampler; `colorconversion/h263` (3 px; h263-rs port; a float IDCT is a CI-determinism hazard); `bitmapdata_draw` (host-dependent tol-128 hinting); F/G device-font + FlashType text rows and ~5–6 device-text rows (Windows ClearType-off host, unreproducible); `font_lookup_as3` | NO-GO: the fix would not move toward FP32, or the golden's host can't be reproduced | PB §25 (s26). PB §26 "unchanged minus swaps". PB §27 | Per row: a Flash capture or model that proves movement toward FP32. Device-text: the s27 Windows ClearType-off pass did NOT reproduce them, so they keep "unreproducible host" |
| `graphics_simple_shapes`, `gradientTransform` (also in that NO-GO list) | avm2 (124), shumway (6) | Listed as Flash-fidelity NO-GOs of record | PB §25 | **UNSURE.** s27 golden provenance says "`gradientTransform` stays a Flash target" (golden = Flash at HIGH). Both rows improved under the s28 LOW model and appear in PB §27's "better bands". Treat them as live targets, not NO-GOs |
| `definefont4`, `blend_scroll`, `bitmapdata_opaque`, `graphics_draw_path`, `strokes/scale` | 5 (fail) | No longer NO-GO: golden-swapped to Flash in s27 (`flash_fixes`). They still fail; the residual is now honest | PB §26 (s27 swaps) | Ordinary Flash targets now. Price against FP32 |
| `sprite_with_frames` | avm2 (fail, 4944) | NO-GO until both the text AA and the LOW stroke rule land (the floor is two "Frame 1" labels) | s28/w1-avm2-vector-flash | The LOW stroke y rule (PB §27 next slice) plus text AA |
| `BeginBitmapFill` | gnash (fail, 951/100) | NO-GO: the floor is the device-font label (666 px) | s25. Re-confirmed s28/w1-avm2-vector-flash | A device-font render model that matches FP32 |
| 101 priced Flash-over-Ruffle pixel losses (s28) and `acid-color-0` (IJG JPEG, s27) | 101 comparisons (stroke snap 51, LOW model 54, drawing-API snap 3, filter residuals 2, minus recoveries); `acid-color-0` 18838 | DECLINED to recover. Each loss is against a Ruffle-made or exporter golden and was priced by name before landing. Never trade a Flash-correct model for a Ruffle golden | Robert's ruling 2026-11-24. Arc §29. PB §27. snap-pixel-audit. lowq-corner-rule §6 | Only an FP32 capture showing the landed model is wrong for that row. Otherwise the remedy is a golden swap through `flash_fixes` (needs FP32 proof; Windows check first for `invalidClipDepth`, `from_shumway/gradient`, `acid-gradient(-0)`, `acid-filter`) |
| Zero-headroom rows (s24) | `bevel_*`, `glow_with_alpha_strength`, `fills_and_lines`, `fallback_preferences`, `edittext_border_filters` | NO-GO (re-confirmed s24): zero headroom vs Ruffle goldens | PB §23 ("unchanged from §22") | **UNSURE / stale.** Not re-confirmed since s24. `edittext_border_filters` now passes. The bevel family and `fills_and_lines` now fail far over limit after the s28 Flash models (`fills_and_lines` is a priced loss). Re-grade against FP32 |
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

## 2. Recently overturned in s26–s28 (do NOT cite these as NO-GO)

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

1. `global_proto_decls*` / `global_instance_decls`: the ignore premise "golden ≠ Flash" conflicts with TP's "golden = Flash".
2. `native_objects_swf6`: ACCEPTED "we match Flash" conflicts with TP's "golden = Flash, we differ by 1".
3. `avm2/bom`: the RvF framing is wrong (TP: golden = Flash, -3/+3).
4. `avm2/dependent_strings`: FP32 prints empty lines. We may already be Flash-exact, or be a cheap fix.
5. `globals_swf5`: "costs 3 gnash passes" may invert under the Flash-over-Ruffle ruling.
6. `swz` / `loader_applicationDomain`: FP32 throws a securityError. The "AOT ceiling" is not the Flash target.
7. `tab_ordering_properties_tab_index_edge_case`: ACCEPTED as "conflicting expectations", but TP says golden = Flash (S fix once decided).
8. `movieclip_hittest_shapeflag`: 3 FP32-false lines sit outside our ACCEPTED set. Needs one Flash run.
9. `acid-shapes`: "AA noise NO-GO" (w1-acid-flash) vs "on the board, 0.25% away from Flash" (PB §27).
10. `cache_as_bitmap/avm1_color`: the premise was corrected to "costs a Flash-golden pass". A Flash request is pending.
11. `graphics_simple_shapes` / `gradientTransform`: listed as Flash-fidelity NO-GOs, but provenance says `gradientTransform` is a Flash target, and both improved in s28.
12. The s24 zero-headroom pixel rows have not been re-confirmed since s24. Their statuses changed under the s28 Flash models.
