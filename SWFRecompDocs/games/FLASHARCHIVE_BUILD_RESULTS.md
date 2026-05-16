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

## Results — 2026-05-16

Total in flasharchive: 56 SWFs. Fresh end-to-end build + deploy in
alphabetical order; halted at the first failure (Duck Life 3). All
previously-failing SWFs in this range now build clean thanks to the
recent fixes (lossless format 3/4, JPEG mid-stream EOI+SOI strip,
empty-JPEGTables tolerance, johnson cycle cap, wasm INITIAL_MEMORY
bump 64→256 MB).

Time column is total **build + deploy + per-step catalog regen**.
Notes summarize recoverable warning counts: `cycle-caps` = shapes that
hit the johnson 4000-cycle cap (informative — these shapes still
recompile, just with truncated topology); `jpeg-lenient` = DefineBits
tags decoded as self-contained JPEG because JPEGTables was missing
or empty.

| # | SWF | Status | Time | Notes |
|---|---|---|---|---|
| 1 | Achievement Unlocked.swf | ✅ Built | 0:50 | clean |
| 2 | Age of War.swf | ✅ Built | 2:18 | 64 cycle-caps |
| 3 | Art of War.swf | ✅ Built | 3:02 | 170 cycle-caps. Previously "Recompiler crash" — now clean after Lossless format-3 decoder + clear()-after-catch fixes. |
| 4 | Avalanche.swf | ✅ Built | 0:57 | 3 cycle-caps. Previously had 3 missing bitmaps; now decodes all of them (Lossless format 3 + JPEG mid-stream EOI+SOI). |
| 5 | Bloons TD 2.swf | ✅ Built | 3:10 | 36 cycle-caps. Previously "wasm compile" fail (140+ undeclared labels); fixed by recompiler emit-pass parser-alignment patch (`ae2f7aec`). |
| 6 | Bloons TD.swf | ✅ Built | 1:44 | 17 cycle-caps. Same fix cleared the undeclared-label cascade. |
| 7 | Bloons.swf | ✅ Built | 1:29 | 26 cycle-caps. Same. |
| 8 | Bloxorz.swf | ✅ Built | 3:19 | clean — but required bumping `INITIAL_MEMORY` 64→256 MB in `build_test.sh` (516 bitmaps × ~56 MB total bitmap data + other static = 71 MB wasm-ld initial-memory request). First-time failure was `wasm-ld: error: initial memory too small, 71140064 bytes needed`. |
| 9 | Castle Hero.swf | ✅ Built | 9:49 | 37 cycle-caps, 11 jpeg-lenient. Previously "wasm build (silent)" fail; unlocked by the JPEGTables-empty tolerance + the johnson cycle cap together. The 11 DefineBits tags self-contain-decode (no JPEGTables). |
| 10 | Checkers.swf | ✅ Built | 0:41 | clean |
| 11 | Doodle Jump.swf | ✅ Built | 0:42 | 1 cycle-caps |
| 12 | Duck Life 1.swf | ✅ Built | 3:12 | 16 cycle-caps, 5 jpeg-lenient |
| 13 | Duck Life 2 - World Champion.swf | ✅ Built | 4:05 | 32 cycle-caps, 5 jpeg-lenient. Previously "Recompiler segfault"; same fix bundle made it build clean. |
| 14 | Duck Life 3 - Evolution.swf | ❌ Halt | 30:00+ | New failure mode: SWFRecomp completes recompile but generates a **305 MB `draws.c`** because the shape edge-record bit-stream parser repeatedly loses alignment in StateNewStyles records and emits hundreds of garbage shapes. emcc then hangs / OOMs trying to compile it. A defensive sanity cap (`StateNewStyles fill/line counts > 8192 → throw`) was added during investigation and catches the symptom, but only AFTER many garbage shapes have been emitted. Root cause is deeper. See investigation below. |

**Snake.swf** built fine in a preliminary 0:39 run before the alphabetical
sweep started; it's #44 in the alphabetical order. Builds 15-56 not yet
attempted in this pass — halted at Duck Life 3 per the user's
"build until error, then investigate" workflow.

## Investigation — Duck Life 3 bit-stream misalignment (2026-05-16)

**Symptom.** Recompiling `Duck Life 3 - Evolution.swf` (6 MB SWF body,
SWF v9) writes `RecompiledTags/draws.c` at 305 MB and 3.8 MB
`tagMain.c`, then `emcc` either hangs for hours or runs out of memory
trying to consume that source. Capturing emcc output into a bash
variable (`BUILD_OUTPUT=$(...)`) also OOMs bash.

**Reproduction.** Standalone:

```sh
cd ~/CC/SWFRecomp-CC/SWFRecomp/tests/local_batch/Duck_Life_3_-_Evolution
rm -rf RecompiledScripts RecompiledTags
bash -c 'ulimit -v 4194304; ulimit -s unlimited; exec "$@"' \
  -- ~/CC/SWFRecomp-CC/SWFRecomp/build/SWFRecomp config.toml
```

→ exits 0, but produces `draws.c` of 305 MB.

**Diagnostic finding.** Added `fprintf` checkpoints inside the
StateNewStyles call site in `interpretShape` (swf.cpp ≈ 7797). Many
shapes log normal values then a follow-up entry with
`fill_style_count=0 line_style_count=65535`. 65535 = `0xFFFF` = the
maximum UI16, occurring because the bit-stream cursor read garbage
bytes (`0xFF` UI8 → "extended" → next UI16 = `0xFFFF`).

**gdb stack trace** (`-batch -ex run -ex bt 20`):

```
#0 SWFRecomp::SWFField::parse(...)
#1 SWFRecomp::SWFTag::parseFields(...)
#2 SWFRecomp::SWF::parseLineStyles(...)
#3 SWFRecomp::SWF::interpretShape(...)
#4 SWFRecomp::SWF::interpretTag(...)
#5 SWFRecomp::SWF::parseAllTags(...)
```

`parseLineStyles(65535)` allocates `new LineStyle[65535]` (OK by
itself) then loops 65535 times calling `parseFields`, walking
`cur_pos` past the end of the SWF buffer → SIGSEGV.

**Defensive cap added** in the same commit:

```cpp
const u32 SHAPE_STYLE_COUNT_CAP = 8192;
if (fill_style_count > SHAPE_STYLE_COUNT_CAP ||
    line_style_count > SHAPE_STYLE_COUNT_CAP) {
    fprintf(stderr, "Shape %u StateNewStyles: implausible style counts ...");
    throw std::exception();
}
```

This converts the SIGSEGV into a recoverable per-tag failure (caught
at `swf.cpp:677`). But it doesn't address the underlying
misalignment: shape edge records that get mis-parsed leak garbage
into `draws.c` for the parts the cap didn't catch. With Duck Life 3,
this happens often enough that `draws.c` reaches 305 MB even though
no SIGSEGV occurs.

**Root cause hypothesis.** The shape edge record stream uses a bit-
packed format whose alignment depends on accurate per-record bit
length parsing. If any record's bit count is mis-read (e.g. an
unsupported edge variant skipped without consuming the right number
of bits), every subsequent record reads from the wrong bit offset.
`StateNewStyles` records inside the edge stream then read
fill/line/style counts from arbitrary cursor positions. Some land on
plausible-looking values (2 fills, 1 line) and we keep parsing; others
land on `0xFFFF` and hit the cap.

**What the cap does and doesn't do.**

- ✅ Prevents SIGSEGV on `parseLineStyles(65535)` walking off the end.
- ✅ Aborts shapes whose misalignment is severe enough to hit a
  sentinel-like value.
- ❌ Does NOT fix the misalignment itself. Shapes whose mis-read
  counts happen to be small (e.g. 5, 12) parse 5 or 12 fake style
  entries from junk bytes, advance the cursor further, write fake
  shape data to `draws.c`, and continue.
- ❌ Does NOT bound the per-tag emission. A shape parsed across
  10000 misaligned StateNewStyles records can each emit hundreds of
  vertices into the shape data stream.

**Open questions.**

- Which edge-record opcode does the bit parser mishandle? Likely
  candidates: `EDGE_RECORD` with a bit length we miscount; a
  `STYLE_CHANGE` flag combination we don't fully consume; or a
  DefineShape4-specific bit added later that we skip without bit-
  alignment fix-up.
- Could we cheaply bound the per-shape emission output to (say) the
  source SWF's tag length × N? If a shape parses into more output
  than tag-length × 100, we're almost certainly emitting garbage.
- A second `StateNewStyles` instrumentation pass should print
  cur_pos relative to the tag start; cur_pos > tag_end is a clean
  abort signal.

**Suggested next steps.** Choose one:

A. **Cap shape output size.** Track bytes emitted into shape_data /
   path_data / color_data per shape; abort the shape if it exceeds
   a per-shape ceiling (e.g. 10× the SWF tag length). Easy. Doesn't
   fix the parser but stops the runaway emission.

B. **Tag-end bound check** in interpretShape's edge loop. After each
   edge / StateNewStyles record, compare `cur_pos - tag_start` to
   `tag.length`. If past, abort the shape. Properly addresses the
   "walked into the next tag's bytes" mode of the misalignment.

C. **Bit parser audit.** Step through interpretShape's edge record
   loop for Duck Life 3 shape 37 (the first to hit the cap) under
   gdb / printf instrumentation. Identify the specific bit-length
   off-by-one. Hardest but only path to fixing affected shapes
   correctly instead of just aborting them.

---

## Previous results (2026-05-14, retained for context)

These were the originally-reported failures. All but the deep
DefineShape4 / bit-stream issues now build clean as noted in the
2026-05-16 results above.

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
