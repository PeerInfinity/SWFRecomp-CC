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
| Bloons TD.swf | ❌ wasm compile | Same pattern as Bloons TD 2 (lots of Unimplemented actions + undeclared labels). Also new: `error: \U used with no following hex digits` — a string literal in the SWF starts with `\U` and the emitter doesn't escape backslashes. |
| Bloons.swf | ❌ wasm compile | Far fewer Unimplemented actions than Bloons TD/TD 2 (only `0xFB`), but still one `error: use of undeclared label 'label_63980'` enough to fail the build. |
| Bloxorz.swf | ✅ Built | Only `tag 35 failed: std::exception` + `JPEG3 data returned NULL` — non-fatal, builds fine. |
| Castle Hero.swf | ❌ wasm build (silent) | Recompiler logs `JPEG bitmap tag encountered before JPEGTables!`, `tag 6 failed: std::exception`, **`tag 8 failed: std::bad_alloc`**. build_test.sh produces no `.wasm` and no `error:` in the log — apparently a clean failure during the link / emcc stage. Worth deeper investigation. |
| Checkers.swf | ✅ Built | `tag 35 failed: std::exception` + `Tag type 62 not implemented` (DefineFontInfo2). Builds fine. |
| Doodle Jump.swf | ✅ Built | Zero significant warnings — cleanest recompile so far. |
| Duck Life 1.swf | ✅ Built | Same `tag 8 std::bad_alloc` warning that broke Castle Hero, but here it builds fine. The bad_alloc warning is recoverable in some SWFs and fatal in others — **the difference isn't the warning itself**. |
| Duck Life 2.swf | ❌ Recompiler segfault | Same `tag 8 std::bad_alloc` warning, then `Segmentation fault` (exit 139). Truncated `constants.h` (11 lines, missing `FRAME_COUNT`) and 1-line `draws.h`. Third distinct outcome from the same warning chain. |

## Failure categories observed

### 1. Unsupported `DefineBitsLossless` format

- Affected SWFs so far: Art of War (fatal), Avalanche (non-fatal)
- Recompiler only handles format 5 (32-bit RGBA). Format 3 (8-bit
  paletted indexed) and format 4 (15-bit RGB555) are unsupported.
- **Inconsistency to investigate:** for Art of War this crash terminates
  the whole recompile; for Avalanche the same error is logged but the
  recompile continues. Could be tag-handler-specific exception
  propagation, or Art_of_War may hit a different downstream failure on
  the same shape table.

### 2. Other tag failures that don't terminate

- DefineBitsJPEG2 (tag 21), DefineBitsJPEG3 (tag 35), DefineBitsLossless2
  (tag 36). Avalanche emits "Warning: tag N failed: std::exception" for
  each but continues.

### 3. johnson cycle detection warning

- "Warning: johnson cycle detection exceeded 100000 iterations, skipping
  remaining nodes" appears on multiple SWFs. Looks like a script call-
  graph analyzer giving up on complex SWFs. Non-fatal — just means some
  optimization or analysis is skipped.

### 4. Unimplemented AVM1 actions → undeclared C labels

- Affected: Bloons.swf, Bloons TD.swf, Bloons TD 2.swf
- When the recompiler hits "Unimplemented action 0xXX", it skips the
  opcode but earlier code may have already emitted `goto label_NNNNN;`
  referencing a label that would have lived inside the skipped region.
  The C compile then fails with `error: use of undeclared label`.
- Bloons TD/TD 2 hit 100+ unimplemented opcodes — these look like AS3
  (AVM2) bytecode opcodes appearing in SWFs the recompiler treats as
  AVM1, suggesting the SWF version detection or DoABC/AVM2 dispatch is
  missing.

### 5. Backslash-U not escaped in emitted string literals

- Affected: Bloons TD.swf
- The recompiler emits something like `"…\U…"` directly into a C string
  literal. clang treats `\U` as the start of a 32-bit Unicode escape
  expecting 8 hex digits. Need to escape `\` → `\\` (or use raw byte
  encoding) in the C-string emitter.

### 6. JPEGTables ordering / tag 8 std::bad_alloc

- Affected: Castle Hero (fatal), Duck Life 1 (non-fatal — but same warning).
- "JPEG bitmap tag encountered before JPEGTables!" + `Warning: tag 6
  failed: std::exception` + `Warning: tag 8 failed: std::bad_alloc`.
- For Castle Hero, build_test.sh produces no `.wasm` (no `error:`
  visible either — link stage seems to die silently).
- For Duck Life 1, same warnings, builds fine. Difference unclear —
  needs investigation.

## Open questions

- Why does the same `DefineBitsLossless format 3` error fatally terminate
  Art of War but not Avalanche? Worth tracing through the tag dispatch
  / exception handling path in the recompiler.
- Why does `tag 8 std::bad_alloc` kill Castle Hero's wasm build but not
  Duck Life 1's, given the recompiler exits 0 in both cases?
- Are there other tag types (DefineSound, DefineVideoStream, ScriptLimits,
  etc.) likely to hit the same "unsupported" pattern?
- The Snake demo runs visually; need to verify that "Built" entries
  actually run in the demo page without crashing the runtime.
