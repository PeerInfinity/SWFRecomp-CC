**Land w1-rm-avm1-gnash's R1–R6 (+11 rm → pass), then the Flash-answered riders (S–M).**

Read `session30-fanout-reports/w1-rm-avm1-gnash-report.md` (on master; also `origin/fanout/w1-rm-avm1-gnash`) and its
`w1-rm-avm1-gnash-prototype.patch`. FP32 answers to its two requests:
`session30-fanout-reports/w1-local-oracles/w1-rm-avm1-gnash/README.md` (read it in full).

1. **Land R1–R6 as measured** (ASnative 900/901 + stub-under-another-name redirect; SWF5 receiver base clip;
   `removeMovieClip("")`; `addProperty` fires a watcher on a new watched name; `LoadVars.sendAndLoad` into an inherited
   `loaded` setter + `XML.prototype.load` on a non-XML receiver; zero-frame sprite header counters). Ledger: the 11 rows
   of the w1 table rm → pass, in graphics AND no-graphics (`tag.c` change). Re-run the w1 648-row gate's argued subsets
   (at minimum: the 93-row pool, the SWF5 + AVM1 `regression/` leg, and every row the R1 redirect can reach) and report
   status moves by name. Write the RvF entry for `XML.prototype.load` on a non-XML receiver (Flash returns true and
   runs the receiver's `onData`; Ruffle returns false).
2. **ASnative identity (FP32 request 1 section D).** At SWF6+, FP32 hands out a FRESH function object per
   `ASnative(901,0)` call: `ASnative(901,0) == MovieClip.prototype.createEmptyMovieClip` is **false**, and so is two
   calls compared. At SWF5 both print true. Make ours match if it costs no ledger row (a fresh native wrapper per call
   bound to the same arm); otherwise price it and keep the shared stub.
3. **Sound-v5 (rider, M).** FP32 section B: in SWF5, after `MovieClip.prototype.createEmptyMovieClip = ASnative(901,0)`,
   a bare `createEmptyMovieClip(...)` WORKS. A script SetMember of a version-hidden prototype member clears (or
   bypasses) the hide flag. Ruffle keeps the flag: RvF entry. Implement that rule (gate it narrowly: script SetMember on
   a native-hidden member). Then B20c: `new Sound(clip)` binds by target path (`getVolume()` undefined once the clip
   is removed, rebinds at 100 to a new same-named clip). Goal: `from_gnash/actionscript.all/Sound-v5` rm → pass (golden
   FP32). If only half lands, keep the half that is Flash-ward and price the rest.
4. **EmbeddedFontTest (rider, S–M).** FP32 request 2: the per-glyph `ceil(advance × size/1024)` `textWidth` rule is
   **SmallText-only**. With SmallText cleared, FP32 gives the unrounded sums, truncated. The recompiler's font case
   (`SWFRecomp/src/swf.cpp`, DefineFont2/3 flags byte, bit 0x20) must carry the SmallText bit to the runtime font record.
   TextField metrics then ceil per glyph for those fonts only. Goal: `from_gnash/misc-ming.all/EmbeddedFontTest`
   rm → pass. Guard: every embedded-font `textWidth`/`textHeight`/`getTextExtent`/autosize `_width` row
   (grep the corpus for SmallText fonts first and list them), both trace and the render canary's text rows. A recompiler
   edit means: rebuild `SWFRecomp/build` and run every leg with `--recompile`.
5. Optional, if time remains: `Function-v5` S part (SWF5 `new` sets no `__constructor__`). Land it only if it is
   Flash-ward on the row and moves nothing else.

Ledger to report: +11 (item 1) and each rider's row by name (Sound-v5, EmbeddedFontTest, Function-v5 lines). Both modes
for every row (`tag.c` change).
Siblings: w2-native-instance edits AVM1 native instance layout in `action.c` (XML/Error/filter ctors,
`setupNativeFuncOwnProps`). w2-native-table-land (`ensureGlobalInit`, `installNativeToString`, `actionGetVariable`'s
Array/String arm) and w1-exec-order (`action_queue.c`, `tag.c` `tagClipEFFireNewerOrEqual`, enterFrame dispatch) are
landing on master now. Rebase onto the newest `origin/master` before your final measurement. You own
`builtin_asnative`, the R1–R6 functions the w1 report names, the Sound ctor/binding, and the font-flag plumbing.
Name every function you touch.
