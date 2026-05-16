# Flasharchive Build Results

Tracking which `~/CC/avm1/flasharchive/*.swf` files build via
`SWFRecomp/scripts/build_swf_batch.sh` and **why** the failures fail.

Companion to `SWFRecomp/scripts/build_swf_batch.sh` (batch builder) and
`clean_swf_batch.sh`. Successfully-built source SWFs are copied to
`~/CC/avm1/success/` and the compiled output is added to the
`docs/examples/local_batch/` "Local Batch" demo section.

## Manual add-to-Local-Batch procedure

After a one-off `build_test.sh local_batch/<NAME> wasm --graphics` succeeds:

```bash
cd ~/CC/SWFRecomp-CC
SWFRecomp/scripts/deploy_example.sh local_batch/<NAME> docs/examples --no-index --graphics
echo "local_batch" > docs/examples/local_batch/<NAME>/.demo_type
python3 SWFRecomp/scripts/generate_local_catalog.py docs
cp "~/CC/avm1/flasharchive/<original>.swf" ~/CC/avm1/success/
```

`generate_local_catalog.py` rescans `docs/examples/local_batch/` for any
deploy dir containing a `.wasm` file, so adding the dir + regenerating the
catalog is enough — no edits to `index.html` needed.

## Batch script gotcha

`build_swf_batch.sh` wraps `build_test.sh` in `timeout 180`. Some SWFs
(e.g. Age_of_War — 23 frames, SWF6, hundreds of scripts) take longer than
that to compile and get marked BUILD FAILED even though the wasm finished
fine. Standalone `build_test.sh local_batch/<NAME> wasm --graphics`
without the timeout succeeds.

Also: `build_test.sh` skips re-running SWFRecomp if `RecompiledScripts/`
already exists. So a SWFRecomp crash that produced partial output stays
broken across rebuilds unless you `rm -rf
tests/local_batch/<NAME>/Recompiled{Scripts,Tags}` first.

## Results so far (2026-05-14)

Total in flasharchive: 56 SWFs.

| SWF | Status | Notes |
|---|---|---|
| Snake.swf | ✅ Built | First success (SWF5, 57 frames) |
| Achievement Unlocked.swf | ✅ Built | Built fine during partial batch run |
| Age of War.swf | ✅ Built | Builds standalone; batch's 180s timeout was the issue |
| Art of War.swf | ❌ Recompiler crash | `DefineBitsLossless format 3 not yet supported (only format 5).` Tag 20 throws `std::exception` and terminates the recompiler mid-write — `constants.h` is truncated, `draws.h` is 1 line. |
| Avalanche.swf | ✅ Built | SWF8. Recompiler logs `tag 21/35/36 failed: std::exception` (DefineBitsJPEG2, DefineBitsJPEG3, DefineBitsLossless2) and `DefineBitsLossless2 format 3 not yet supported (only format 5).` and `JPEG2 data returned NULL`/`JPEG3 data returned NULL`, but **continues past the failures** and emits a complete output. Visuals will be missing those bitmaps. |
| Bloons TD 2.swf | ❌ wasm compile | Recompiler completes but logs *140+* "Unimplemented action 0xXX" warnings. C compile then fails: `script_NNN.c: error: use of undeclared label 'label_NNNNN';` — earlier `goto label_X;` references targets that would have been emitted inside the unrecognized opcodes. |
| Bloons TD.swf | ❌ wasm compile | Same pattern as Bloons TD 2 (lots of Unimplemented actions + undeclared labels). [Earlier observed `error: \U used with no following hex digits`; not reproducible on a fresh recompile — was a stale-output artifact. The latent escape hole in `GET_URL`/`GOTO_LABEL`/`SET_TARGET` emission was fixed preventatively anyway; see commit log.] |
| Bloons.swf | ❌ wasm compile | Far fewer Unimplemented actions than Bloons TD/TD 2 (only `0xFB`), but still one `error: use of undeclared label 'label_63980'` enough to fail the build. |
| Bloxorz.swf | ✅ Built | Only `tag 35 failed: std::exception` + `JPEG3 data returned NULL` — non-fatal, builds fine. |
| Castle Hero.swf | ❌ wasm build (silent) | Recompiler logs `JPEG bitmap tag encountered before JPEGTables!`, `tag 6 failed: std::exception`, **`tag 8 failed: std::bad_alloc`**. build_test.sh produces no `.wasm` and no `error:` in the log — apparently a clean failure during the link / emcc stage. Worth deeper investigation. |
| Checkers.swf | ✅ Built | `tag 35 failed: std::exception` + `Tag type 62 not implemented` (DefineFontInfo2). Builds fine. |
| Doodle Jump.swf | ✅ Built | Zero significant warnings — cleanest recompile so far. |
| Duck Life 1.swf | ✅ Built | Same `tag 8 std::bad_alloc` warning that broke Castle Hero, but here it builds fine. The bad_alloc warning is recoverable in some SWFs and fatal in others — **the difference isn't the warning itself**. |
| Duck Life 2.swf | ❌ Recompiler segfault | Same `tag 8 std::bad_alloc` warning, then `Segmentation fault` (exit 139). Truncated `constants.h` (11 lines, missing `FRAME_COUNT`) and 1-line `draws.h`. Third distinct outcome from the same warning chain. |

## Investigation update (2026-05-15)

Two fixes landed in `SWFRecomp/src/action/action.cpp`:

1. **Emit-pass parser-alignment bug** (the actual unlock). The `default` arm
   for unimplemented opcodes didn't advance `action_buffer += length;` past
   the opcode's payload. The label-collection pass *did* advance correctly
   at the bottom of its loop, so for high-bit unimplemented opcodes
   (0x80-0xFF), the emit pass walked into the payload and treated those
   bytes as further opcodes — cascading the parser into garbage. Any
   JUMP/IF the emit pass invented from that garbage emitted
   `goto label_X` references to labels the collection pass never saw,
   producing "use of undeclared label" C-compile errors. One-line fix
   plus a clarifying comment.

2. **Latent backslash-escape hole in `GET_URL` / `GOTO_LABEL` /
   `SET_TARGET`** (preventative). `escape_c_string` was already escaping
   Push/ConstantPool strings, but these three opcodes emitted raw SWF
   strings into C source with no (or only partial) escaping. None of the
   current flasharchive SWFs trigger it on a fresh recompile, but any
   SWF with `\`, `"`, or a control byte in those fields would have
   broken the build. Now routed through `escape_c_string`.

Re-test of the 14 flasharchive SWFs against the new recompiler
(`scripts` = number of `script_*.c` files emitted; `unimpl` = count of
"Unimplemented action 0xXX" warnings logged):

| SWF | Pre-fix status | Post-fix |
|---|---|---|
| Snake | ✅ | rc=0, 22 scripts, 0 unimpl |
| Achievement Unlocked | ✅ | rc=0, 39 scripts, 0 unimpl |
| Age of War | ✅ | rc=0, 320 scripts, 0 unimpl |
| Art of War | ❌ "crash" | rc=0, 611 scripts — *and the "crash" itself turned out to be non-deterministic, see open question #1* |
| Avalanche | ✅ | rc=0, 94 scripts, 0 unimpl |
| Bloons TD 2 | ❌ wasm compile (140+ unimpl) | rc=0, 451 scripts, **671 unimpl** still — recompile completes but wasm compile not yet retested end-to-end |
| Bloons TD | ❌ wasm compile (`\U` + undeclared labels) | rc=0, 152 scripts, 19 unimpl. C-compile errors dropped from 20+ to ~3, and the 3 remaining are all caused by *one* separate exception (constant-pool overflow in script_61, truncating that file mid-statement). |
| Bloons | ❌ wasm compile | rc=0, 260 scripts, 2 unimpl |
| Bloxorz | ✅ | rc=0, 356 scripts |
| Castle Hero | ❌ wasm silent | rc=0, 466 scripts |
| Checkers | ✅ | rc=0, 12 scripts |
| Doodle Jump | ✅ | rc=0, 41 scripts |
| Duck Life 1 | ✅ | rc=0, 1064 scripts |
| Duck Life 2 | ❌ segfault | ❌ still segfaults (exit 139, 993 scripts emitted before crash) — unaffected by these fixes |

**End-to-end wasm builds for the formerly-broken set have NOT been
retested yet.** "rc=0" only confirms the recompile step. Bloons family
still needs at least the constant-pool issue solved before its wasm
will link; Castle Hero's silent emcc failure is still unexplained.

## Failure categories observed

### 1. Unsupported `DefineBitsLossless` format

- Affected SWFs so far: Art of War, Avalanche
- Recompiler only handles format 5 (32-bit RGBA). Format 3 (8-bit
  paletted indexed) and format 4 (15-bit RGB555) are unsupported.
- ~~Inconsistency: Art of War fatal, Avalanche non-fatal.~~
  **Answered 2026-05-15:** not actually a per-SWF difference. The
  `throw std::exception()` inside `EXC_ARG` propagates out of an
  in-flight `operator<<` chain on `constants.h` / `draws.h`, which
  sets `failbit` on the ofstream. The per-tag `catch` at
  `swf.cpp:586` did not reset `failbit`, so all subsequent writes
  silently no-op'd — and the rest of the recompile would emit fewer
  scripts because downstream tag handlers chained `defined_chars` /
  bitmap-index updates through the same stream-write paths. The
  result was non-deterministic: Art_of_War landed in the truncated
  branch ~1-in-3 runs, Avalanche always in the lucky branch.
  **Fixed 2026-05-15** by calling `clear()` on every context-owned
  ofstream after the per-tag catch. 6/6 Art_of_War runs now produce
  identical output (611 scripts, 16-line constants.h, 232-line
  draws.h, was variable across {387, 415, 611, 611, 611, 611} pre-fix).
  Castle_Hero / Avalanche / Doodle_Jump also stabilized at full
  output. The underlying format-3 / format-4 *decoder* gap is still
  unimplemented — the fix just makes the failure no longer corrupt
  later writes.

### 2. Other tag failures that don't terminate

- DefineBitsJPEG2 (tag 21), DefineBitsJPEG3 (tag 35), DefineBitsLossless2
  (tag 36). Avalanche emits "Warning: tag N failed: std::exception" for
  each but continues.

### 3. johnson cycle detection warning

- "Warning: johnson cycle detection exceeded 100000 iterations, skipping
  remaining nodes" appears on multiple SWFs. Looks like a script call-
  graph analyzer giving up on complex SWFs. Non-fatal — just means some
  optimization or analysis is skipped.

### 4. Unimplemented AVM1 actions → undeclared C labels [FIXED 2026-05-15]

- Affected: Bloons.swf, Bloons TD.swf, Bloons TD 2.swf
- The original framing ("goto references a label that would have lived
  inside the skipped region") was misleading. The real root cause:
  the emit-pass `default` arm for unimplemented opcodes failed to
  advance `action_buffer` past the opcode's payload, while the
  label-collection pass did. For high-bit opcodes (0x80-0xFF), the
  `length` payload bytes leaked into the parse stream and were
  misinterpreted as further opcodes. The emit pass then invented
  JUMP/IF instructions from that garbage, emitting `goto label_X`
  references to labels the collection pass had never seen → C-compile
  "undeclared label" errors. Fixed by adding the missing
  `action_buffer += length;`.
- One side effect of the original bug: the garbage interpretation
  often hit a 0x83 byte (GET_URL opcode), causing the parser to read
  arbitrary forward bytes as a "URL string" until the next null.
  That's where the "stale `\U` in a string literal" symptom for
  Bloons TD came from — fake GetURLs synthesized from garbage memory.
  The string-escape fix in category #5 was preventative; the parser
  fix is what made the false GetURLs go away.
- Post-fix counts: Bloons.swf 2 unimpl (was many more), Bloons TD 19
  (was 140+), Bloons TD 2 671 (was 140+, climbed because the parser
  now correctly identifies opcodes it previously skipped past).

### 5. Backslash-U not escaped in emitted string literals [FIXED preventatively]

- Originally noted on Bloons TD.swf but was a stale-output artifact —
  not reproducible on a fresh recompile.
- Investigation found a real latent hole: `escape_c_string` correctly
  escaped Push/ConstantPool strings, but `GET_URL`, `GOTO_LABEL`, and
  `SET_TARGET` emitted SWF strings directly into C source with no (or
  only partial) escaping. None of the current flasharchive SWFs trigger
  it, but any SWF whose URL/label/target name contains `\`, `"`, or
  control bytes would have broken the build. Now routed through
  `escape_c_string`.

### 6. JPEGTables ordering / tag 8 std::bad_alloc

- Affected: Castle Hero (fatal), Duck Life 1 (non-fatal — but same warning).
- "JPEG bitmap tag encountered before JPEGTables!" + `Warning: tag 6
  failed: std::exception` + `Warning: tag 8 failed: std::bad_alloc`.
- For Castle Hero, build_test.sh produces no `.wasm` (no `error:`
  visible either — link stage seems to die silently).
- For Duck Life 1, same warnings, builds fine. Difference unclear —
  needs investigation.

## Open questions

- ~~Why does the same `DefineBitsLossless format 3` error fatally
  terminate Art of War but not Avalanche?~~ **Answered + fixed
  2026-05-15.** See category #1 above — was `failbit` set on
  context ofstreams by the in-flight `<<` chain when EXC_ARG threw;
  per-tag catch didn't `clear()`. Now does, and the truncation
  is gone.
- Why does `tag 8 std::bad_alloc` kill Castle Hero's wasm build but not
  Duck Life 1's, given the recompiler exits 0 in both cases?
- Why does Duck Life 2 still segfault during recompile? Bisecting which
  tag/script triggers it would localize whether it's the same
  `tag 8 std::bad_alloc` chain or a separate failure mode.
- Bloons TD's last remaining wasm-compile blocker is `Constant pool
  index 3 out of range (pool size: 2)` in script_61 — bytecode bug or
  pool-tracking bug in the recompiler? script_60 and script_62 emit
  cleanly so the pool state is presumably wrong specifically at
  script_61's entry.
- Bloons TD 2 still has 671 unimplemented opcodes after the
  parser-alignment fix. Now that we know they're real opcodes (not
  parser garbage), what AVM1 opcodes are they? Distribution of
  0xXX values would tell us whether they're a small number of
  high-frequency opcodes worth implementing, or a long tail.
- Are there other tag types (DefineSound, DefineVideoStream, ScriptLimits,
  etc.) likely to hit the same "unsupported" pattern?
- The Snake demo runs visually; need to verify that "Built" entries
  actually run in the demo page without crashing the runtime.
