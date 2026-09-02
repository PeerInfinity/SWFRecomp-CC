# AVM2 (AS3) SWFs through the in-browser recompiler — assessment (2026-09-02)

Brief: `SWFRecompDocs/prompts/avm2-in-browser-investigation-prompt.md`. Companion to
`in-browser-recompiler-refresh-assessment.md` §7–§9 (how the AVM1 in-browser build
works). This slice answered the brief's five questions with measurements taken in
Windows Chrome (real GPU, Playwright from WSL) against the in-browser clang, plus a
few local experiments, and shipped the AVM2 host variant because it turned out to be
the smallest piece.

## 0. Summary and recommendation

**It works today for Seedling.** The ORIGINAL Seedling (7.8 MB SWF), dropped on the
page in Windows Chrome: recompile 57 s → in-browser compile of all 13 C files (182 MB
of C, `draws.c` included) **420 s** → 38.3 MB guest → boots on the AVM2 host and
renders its title screen (PLAY button, 480×480 at 30 fps); the compiler worker peaked
at 2.78 GB. Two of the brief's four blockers turned out not to be blockers and the
host variant is shipped (§3, §6). Measured against the real in-browser compiler (§1):

| Brief's blocker | Measured | Status |
|---|---|---|
| 1. Host built from the AVM1 source set | AVM2 variant: 3.1 MB wasm, links first try, no generated globals to bridge | **shipped** this slice |
| 2. AVM2 output too large for the in-browser clang | Every Seedling TU compiles at -O1: 142 MB `draws.c` 75 s, 33 MB `abc_timeline.c` 54 s, 12.9 MB `abc1_methods.c` 399 s (182 s as 9 chunks). Only Snailiad's 30 MB methods TU exceeds 25 min | **not a blocker for Seedling**; TU-split flag needed for the biggest titles |
| 3. 101 MB guest arena | Seedling static data is 31 MB | **not a blocker** |
| 4. `setjmp` in try-bearing methods | 0.2–0.9 % of methods, every title has some; runtime-helper mode validated mechanically (§4.1) | the one real piece of work (~1 day) |

Versus the bundle path (5:38 local build for Seedling): the in-browser build is
~4.5× slower per TU than native emcc but the whole game still lands in 7 min in one
clang invocation (memory does NOT accumulate across TUs: 2.78 GB peak, i.e. the
`draws.c` TU alone), ≈ 4 min once the methods are chunked (§1.2), so the value is
"no toolchain install", not speed.
Recommendation, in order: **try-helper emission mode** (the only correctness gap; it
also fixes AVM1 try/catch in the page) → **TU-split flag** (Snailiad-class titles,
and 2× faster for everything) → **payload blob** (optional: cuts memory from 2.5 GB
and the zip from 33 MB, and skipping the AVM2-dead AVM1 payload is a one-line win for
the bundle too). ≈ 2.5 developer days total. See §5.

## 1. Compiler ceiling (Q1)

Harness: a probe page (`scratchpad/probe/index.html`, driver
`C:\playwright\ceiling_probe.py`; recipe §7) that runs the wasmer `clang/clang`
package with **exactly the pipeline's flags** (`-O1 -w -std=gnu2x -DDYNAMIC_GUEST
-DSWF_AVM2 … -Wl,--export-table,--global-base=65536,--allow-undefined,--export-all,
--no-entry`) on one generated TU at a time, fresh page per plan. Inputs are today's
recompiler output for the ORIGINAL Seedling (`~/CC/newgrounds/598977_Seedling.swf`,
recompiled natively in 6.3 s) and the other Newgrounds titles.

### 1.1 Measurements (Windows Chrome 14x, real GPU box, 2026-09-02)

| TU | Source | Lines | Flags | Result | Time | Output wasm |
|---|---|---|---|---|---|---|
| `abc0_methods.c` (Seedling) | 1.8 MB | 42 K | -O1 | OK | 36 s | 1.1 MB |
| `abc1_methods.c` (Seedling) | 12.9 MB | 281 K | -O1 | **OK** | **399 s** | 7.1 MB |
| `abc1_methods.c` (Seedling) | 12.9 MB | 281 K | -O0 | OK | **1290 s** (21.5 min) | 35.5 MB |
| `abc1_methods_{0..8}.c` (Seedling, 9-way split, one clang call) | 13.0 MB | 284 K | -O1 | **OK** | **182 s** (peak WS ~1.0 GB) | 7.2 MB |
| `abc_timeline.c` (Seedling, data) | 33 MB | 294 K | -O1 | OK | 54 s | 9.5 MB (peak WS 1.38 GB) |
| `abc1_methods.c` (Snailiad) | 29.7 MB | 713 K | -O1 | **still compiling at the 25-min driver timeout** (worker at 2.23 GB, no crash) | > 1500 s | — |
| `draws.c` (Robot Wants Puppy, data) | 25.7 MB | 3.78 M | -O1 | OK | 16 s (peak WS ~0.9 GB) | 4.0 MB |
| `draws.c` (Seedling, data) | **142 MB** | 20.8 M | -O1 | **OK** | **75 s** (peak WS 2.54 GB) | 22.1 MB |

Reference (native, same TU): `emcc -O1 -c abc1_methods.c` 88 s / 1.29 GB RSS →
the in-browser compiler is ~4.5× slower than native Emscripten on the same code.
`gcc -O1 -c draws.c` (142 MB) 83 s / 2.39 GB; `gcc -O1 -c abc_timeline.c` 23 s / 0.71 GB.

Memory: per-process working sets of chrome.exe were sampled every 2 s from WSL
(`tasklist.exe`); the compiler worker is one renderer process. -O0 on the 12.9 MB TU:
1.1 GB at 3 min → 2.9 GB at 17 min → **3.49 GB peak**. The -O1 run stayed below ~1.8 GB
(the largest process during it was an unrelated 1.7 GB renderer). Data TUs: 0.9 GB
(26 MB), 1.4 GB (33 MB), 2.54 GB (142 MB) — roughly 17 bytes of working set per byte of
C text, which puts the wasm32 4 GB address space at ≈ 230 MB of data C.

### 1.2 Reading
- The brief's "10 K-line file dies with exit 45" was the FULL `clang-16` atom; the
  slim driver the pipeline uses handles a 281 K-line, 12.9 MB TU. The ceiling is not a
  hard byte count but time × memory inside one wasm32 process (4 GB address space).
- **-O0 is not a shortcut**: 3.2× slower than -O1 on the same TU (1290 s vs 399 s), 5× the
  output (35.5 MB vs 7.1 MB) and a 3.49 GB peak working set against the ~1.8 GB ceiling
  observed at -O1 — the unoptimized IR is what costs memory, and 3.5 GB is within sight
  of the wasm32 process's 4 GB address space. Keep -O1.
- **Splitting pays more than linearly**: the same 3158 methods as nine ~1.5 MB TUs in one
  clang invocation compile in 182 s instead of 399 s (2.2×) with half the peak memory and
  the same output size — compile time grows super-linearly with TU size, so the
  recompiler flag is the lever for Snailiad-class titles (30 MB → ~20 chunks ≈ 7 min
  extrapolated).
- **Byte-literal data is cheap**: 25.7 MB / 3.8 M lines of `draws.c` in 16 s, 33 MB of
  `abc_timeline.c` in 54 s (≈ 0.6–1.6 MB/s, ≤ 1.4 GB). The data-path question (§2) is
  therefore about the 142 MB `draws.c` alone, see the last table row.

### 1.3 TU-splitting preview
`scratchpad/probe/split_methods.py` splits `abcN_methods.c` at method boundaries into
K body chunks + one table chunk (functions and their `_bt`/`_exc` tables lose
`static`; the table chunk gets `extern` declarations). All nine chunks pass
`gcc -fsyntax-only`, so the recompiler flag is a mechanical change in
`abc_emit.cpp` (`abc<tag>_methods.c` emission, ~line 3987): emit N files of ~1.5 MB,
drop `static` on `abcN_mK` / `abcN_mK_bt` / `abcN_mK_exc`, emit the prototypes into
`abc_gen.h`. The bundle's `build.sh` already globs `RecompiledABC/*.c`.

## 2. Data path (Q2)

### 2.1 What the data is
Seedling, today's recompiler (`draws.c` 142 MB, `abc_timeline.c` 33 MB):

| Array | Where | C text | Static bytes | Read by AVM2 runtime? |
|---|---|---|---|---|
| `bitmap_data` (decoded RGBA) | draws.c | ~84 MB | 14.05 MB | **No** — only `defineBitmap` in `tagInit`, which `runSWF_avm2` never calls |
| `sound_data` | draws.c | ~40 MB | 6.68 MB | **No** — `tagDefineSound` in `tagInit` only |
| `shape_data`, `transform_data`, `color_data`, `gradient_data`, `cxform_data`, … | draws.c | ~4 MB | 1.25 MB | Yes (render walk, CPU raster, hit test) |
| `snd_N_bytes` (88 sounds) | abc_timeline.c | 23.8 MB | 6.68 MB | Yes (`avm2_generated_sounds[i].data`) |
| `bmp_N_rgba` (284, zlib-deflated) | abc_timeline.c | 4.6 MB | 1.25 MB | Yes (`avm2_generated_bitmaps[i].rgba`, inflated on first use) |
| `bin_N_bytes` (116 DefineBinaryData) | abc_timeline.c | 4.6 MB | 1.39 MB | Yes (`avm2_generated_binaries[i].bytes`) |
| timeline/char/font tables | abc_timeline.c | 0.1 MB | small | Yes |

So the 101 MB guest arena is NOT the limit the brief assumed: Seedling's whole static
data is 31 MB (22 MB `draws.o` + 9.4 MB `abc_timeline.o`), 20.7 MB of it dead under
AVM2. And the C text turned out to be affordable too (§1.1: 142 MB in 75 s / 2.5 GB
in the browser; native gcc needs 83 s / 2.4 GB). What the blob still buys: peak
memory (2.5 GB → ~0), the 33 MB bundle zip and 175 MB of source round-tripping
through the wasmer virtual FS, and the bundle's own `draws.c` compile.

### 2.2 Design: payload blob (optional optimization)
Emit the byte payloads as a binary file the page hands to the host directly; keep the
C form for native builds.
- Recompiler (`swf.cpp` draws emission ~line 942; `abc_timeline.cpp`): a config
  option `data_blob = true` writes `RecompiledTags/draws_payload.bin` (bitmap_data ·
  sound_data · video_data concatenated, offsets in `draws.h`) and
  `RecompiledABC/abc_payload.bin` (snd/bmp/bin bytes), and emits the same bytes as
  today's C arrays into `draws_payload.c` / `abc_payload.c` (bundle/native path
  unchanged). The AVM2 tables keep a pointer field but in blob mode it holds the
  offset, and the guest gets a generated `avm2_payload_relocate(base)` that turns
  offsets into pointers (the tables are emitted non-const in that mode; the runtime
  only reads them). Three consumers: `avm2_bitmap.c:794` (`rgba`),
  `avm2_media.c:719` (`data`), ByteArray from `bytes`.
- Page: skips `*_payload.c`, `malloc`s the blob in host memory (above the arena, so
  no size limit), calls `setBitmapData(ptr, size)` / `setSoundData` — the runtime
  already takes these as pointers under `DYNAMIC_HOST` (`generated_data.h`), and
  `tagMain.c` addresses them by offset (`defineBitmap(0, 2600, …)`,
  `sound_data + 5982`), so under `DYNAMIC_GUEST` `draws.h` declares `extern u8*
  bitmap_data;` and nothing else changes.
- Cheap extra win: for AS3 SWFs (`is_as3`, `swf.cpp:4865`) do not emit the AVM1
  `bitmap_data`/`sound_data` payload at all (dead under AVM2): −120 MB of C, −20.7 MB
  static, bundle `build.sh` time drops by the 83 s `draws.c` compile.
- What in the runtime assumes static arrays: nothing left. The AVM1 tables already
  went pointer-form for the host in the stage-2 work; this slice did the same for
  the 37 `avm2_generated_*` symbols and the four `draws.c` tables the AVM2 runtime
  read as bare `extern` arrays (`avm2_cpu_raster.c`, `avm2_display.c`), see §6.
  `sizeof()` is never taken of any of them.

## 3. Host variant (Q3) — SHIPPED

`build_graphics_host.sh AVM2=1` → `graphics_host_avm2.{js,wasm}`: the AVM1 host's
source set + `src/avm2/*.c` + quickjs-libregexp + lzma, `-DSWF_AVM2 -msimd128
-sUSE_ZLIB=1`, same JSPI / `SUPPORT_LONGJMP=wasm` / table-base / arena link. It
linked on the first try (the AVM1 host's weak stubs cover it).

| | AVM1 host | AVM2 host |
|---|---|---|
| wasm | 1.57 MB | 3.10 MB |
| js | 261 KB | 348 KB |
| exports | — | 1839 (613 `avm2_*`) |
| build (emcc -O2, this box) | ~2 min | ~4 min |

- **Globals the AVM2 generated code references: none.** `abcN_methods.c` calls only
  runtime functions (host exports) and its own tables; the 15 `extern` declarations in
  the ABC output are the guest's own `avm2_generated_*` tables. The AVM1 bridge
  (`bridge_globals.h`, five globals) still serves `tagMain.c`/`RecompiledScripts`.
- **What `runSWF_avm2` needs from the guest:** the 37 `avm2_generated_*` tables and
  scalars. Under `-DDYNAMIC_HOST` they are now pointers/plain scalars
  (`avm2/avm2_abc.h`), filled by one exported setter `setAvm2Tables(const
  Avm2MovieTables*, abc_frames, abc_lazy, symbol_class_frames, device_fonts, n)` from
  the guest's existing `avm2_movie_tables` aggregate (`RecompiledABC/avm2_movie_tables.c`,
  which already carries every pointer+count except those four), plus
  `setAvm2DrawTables` for `color_data`/`uninv_mat_data`/`gradient_data`/
  `morph_end_color_data`. The method function pointers inside `Avm2AbcMethodData`
  need no translation (mirrored table, same as `frame_funcs`).
- Compile-time constants the bundle bakes per SWF (`SWF_URL`, `SWF_FILE_SIZE`,
  `SWF_ONDISK_SIZE`, `MOCK_DATE_TIME`) are host-wide in the variant: `loaderInfo.url`
  is `file:///test.swf` and `bytesTotal` is 0 for every in-browser AS3 run until they
  become runtime-set values (small follow-up; games that gate on their origin —
  Robot Wants Fishy / Ice Cream — will blank the stage, see `build_wasm_avm2.sh`).

### 3.1 The one real guest/host ABI trap: `jmp_buf` inside a guest-allocated struct
The first AS3 run on the page booted (host loaded, guest instantiated, root class
constructed, frame 1 ran) and then died with `Error #1010` on the first `trace`.
Cause: `Avm2TryFrame` (avm2_error.h) embeds `jmp_buf`, generated try-bearing methods
allocate one on THEIR stack and hand it to the host's `avm2_try_push_frame`, and the
two toolchains disagree on `sizeof(jmp_buf)`: **156 bytes** in the Emscripten host
(wasm-sjlj) versus a few bytes in the WASIX sysroot the in-browser clang uses. The
host then writes `excs`/`file`/... past the guest's frame and smashes the method's
locals. The AVM1 page never hit it because `ACTION_TRY_SETJMP` uses a host-owned
`jmp_buf`. Fix shipped: `wasm_wrappers/guest_setjmp_shim.h`, mounted ahead of the
sysroot as `/project/shim/setjmp.h`, pins the host layout (156) and declares
`setjmp` as a plain function (so it becomes the stubbed import instead of linking the
WASIX `stack_checkpoint` implementation); the loader compares the guest's and host's
`sizeof(jmp_buf)` exports before running. Rule for the try-helper mode (§4.1): let
the RUNTIME allocate the try frame, so no libc-typed struct crosses the boundary.

End-to-end (Windows Chrome, page served locally, `C:\playwright\recomp_as3_run.py`):

| SWF | In-browser compile | Run |
|---|---|---|
| **Seedling, original (7.8 MB)** | 13 files (182 MB of C), **419.8 s**, 38.3 MB guest, worker peak 2.78 GB | **boots and renders the title screen**; Newgrounds API code runs (network error, as expected offline); 3886 guest functions mirrored, data [64 KB, 41.3 MB) of the 101 MB arena |
| avm2/bitmapdata_draw (1.7 KB) | 11 files, 12.6 s, 111 KB guest | runs, renders, no error |
| avm2/try_catch (1.2 KB) | 11 files, 11.3 s, 116 KB guest | boots, traces `// Trying to raise and catch an error`, dies at the first throw inside `try` (interim, §4) |
| avm2/graphics_draw_path (5 KB) | 11 files, 16.5 s, 193 KB guest | boots, traces `===== drawPath` / `Odd number of data coordinates`, dies at the first throw inside `try` |
| graphics/awful_shape_swf_4 (AVM1 regression check) | 7 files, 11.0 s | runs as before |

So the host variant, the pointer-form tables, the guest exports and the table
mirroring all work for AS3; what stops the two try-bearing tests is exactly the
setjmp interim of §4, and the escaped Wasm exception now surfaces as a clear message.

## 4. setjmp (Q4)

Prevalence (today's recompiler, `setjmp(` in `*_methods.c`):

| Title | Methods | Try-bearing | % |
|---|---|---|---|
| Seedling | 3607 | 22 | 0.6 |
| Robot Wants Kitty | 794 | 5 | 0.6 |
| Robot Wants Puppy | 1578 | 13 | 0.8 |
| Robot Wants Fishy | 1241 | 7 | 0.6 |
| Robot Wants Ice Cream | 1370 | 6 | 0.4 |
| Elephant Quest | 1310 | 2 | 0.2 |
| Snailiad | 6967 | 65 | 0.9 |
| Ruffle avm2 tests (local sample of 1155) | — | 222 tests | 19 |

Rare per method, present in every title, and typically on boot paths (SharedObject,
loader, JSON). Option (b) "no try/catch" therefore means "the movie runs until the
first throw inside a try, then dies" — acceptable only as the interim the AVM1 page
already lives with (today the loader maps `setjmp → 0`, `longjmp → JS error`). The
page now applies the same interim to AS3 guests through the `setjmp.h` shim (§3.1),
which also keeps the WASIX libc's `stack_checkpoint`-based `setjmp` out of the link.

### 4.1 Option (a): runtime helper — validated mechanically
Node experiment (`scratchpad/sjlj/`): an Emscripten host (`-sSUPPORT_LONGJMP=wasm
-sSHARED_MEMORY=1`, table-base, same as the real host) exporting
`host_try(fn, env, arg)` (does `setjmp`, calls the guest function pointer) and
`host_throw(v)` (`longjmp`); a guest compiled by a plain wasm32 clang with NO EH or
SjLj support, instantiated against the host's memory with its table mirrored.

```
t_plain  0 -> 7      t_plain  5 -> -1005   (throw inside guest body caught by host_try)
t_nested 0 -> 107    t_nested 5 -> -1005   (guest -> host_call -> guest -> host_throw)
t_deep   0 -> 8      t_deep   5 -> -1004   (nested host_try frames: inner one catches)
```
A host `longjmp` under wasm-sjlj is a Wasm exception; it unwinds through
non-instrumented guest frames and lands in the right host frame. So the emission
mode is:

```c
// generated, try-bearing method (today: setjmp inline in the prologue)
static Avm2Value abcN_mK(Avm2Activation* act) {
    Avm2Value loc[..], stk[..]; Avm2ScopeEntry lscope[..];
    AbcNmKEnv env = { act, loc, stk, lscope, /*resume*/ -1, /*ret*/ {0} };
    Avm2TryFrame _tf; avm2_try_push_frame(act->ctx, &_tf, abcN_mK_exc, n, act->file);
    while (avm2_try_run(act->ctx, &_tf, abcN_mK_body, &env))   // runtime: setjmp + call
        { env.resume = _tf.handler_target; env.exc = _tf.exc; }
    avm2_try_pop_frame(&_tf);
    return env.ret;
}
static int abcN_mK_body(void* p) { AbcNmKEnv* env = p; ... if (env->resume >= 0) { sp = 0;
    scope_n = 0; stk[sp++] = env->exc; switch (env->resume) { case T: goto op_T; … } } ...
    /* every `return v;` becomes `env->ret = v; return 0;` */ }
```
`avm2_try_run` is ~6 lines in `avm2_error.c` (`if (setjmp(tf->jb) == 0) { fn(p);
return 0; } return 1;`). The arrays live in the outer frame so they survive the
re-entry; `sp`/`scope_n` no longer need `volatile`. Cost: one indirect call per
invocation of a try-bearing method (0.2–0.9 % of methods). Behind a recompiler
option so native output is unchanged; the same mode applied to `ACTION_TRY_SETJMP`
in the AVM1 emitter removes §7.3's AVM1 limitation too. Effort ≈ 1 day including
the regression run with the option forced on natively (CI validates semantics
without a browser).

### 4.2 Option (c'): the slim driver CAN lower setjmp
Probe `sj_*` (10-line setjmp/longjmp file): with `-mllvm -wasm-enable-sjlj` the
in-browser clang-16 emits the LLVM-16 wasm-SjLj lowering — imports `saveSetjmp`,
`testSetjmp`, `getTempRet0`, `__wasm_longjmp`, and DEFINES+exports its own
`__c_longjmp` tag (2.6 s, 83 KB). Without the flag the WASIX libc `setjmp`
(`stack_checkpoint`/`stack_restore` syscalls) is linked instead, which is why the
page renames it. Making (c') work end to end would need: host implementations of
the LLVM-16 ABI (`saveSetjmp`/`testSetjmp`, ~40 lines), and — because the guest's
tag is not the host's — `avm2_throw` routing throws targeting guest frames through a
JS import that throws the guest's exported tag (`new WebAssembly.Exception(guestTag,
…)`). Untested beyond "compiles and imports"; it saves the emitter work but adds a
toolchain-version dependency (the ABI changed in LLVM 18), so (a) is the
recommendation and (c') the fallback.

## 5. Is it worth it (Q5)

| Component | Effort | Also benefits |
|---|---|---|
| try-helper emission mode (§4.1) | ~1 day | AVM1 try/catch in the page (§7.3 of the stage-2 doc) |
| TU-splitting flag (§1.3) | ~0.5 day | 2× faster in-browser methods compile; bundle path parallel builds; gcc-ICE guard for giant TUs |
| Skip the AVM1 bitmap/sound payload for AS3 SWFs (§2.2) | ~0.2 day | bundle path (−83 s, −2.4 GB gcc RAM for Seedling), −120 MB C, −13 MB zip |
| Payload blob (§2.2) | ~1 day | in-browser peak memory, zip size; optional |
| Runtime-set `SWF_URL`/sizes for the host (§3) | ~0.5 day | origin-gated titles (RWF/RWIC) |
| Host variant + loader + pipeline (§3) | done | — |

Measured in-browser Seedling: recompile 57 s + compile 420 s (one clang call, 13 TUs,
2.78 GB peak — memory does not accumulate across TUs) + host load ≈ 8 min to a
rendered title screen; ≈ 4.5 min once the methods TU is chunked. Its 22 try-bearing
methods did not throw on the boot path, so the setjmp interim did not bite here (it
will on the first caught exception in gameplay — the Newgrounds API's failed connect
is handled by an event, not a catch). The bundle path is 5:38 with a local
Emscripten and produces a standalone wasm. So: worth it for "try any AS3 SWF with nothing installed" and for
the runnable-zip download, not as a replacement for the bundle on big titles.
The AS3 corpus tests (1155 avm2 + 1574 avmplus) all fit comfortably — the
in-browser path is usable for them today (§3 end-to-end) modulo try/catch.

## 6. What shipped this slice

- `SWFModernRuntime/include/avm2/avm2_abc.h`: `DYNAMIC_HOST` pointer/scalar forms
  of the 37 generated symbols (native builds textually unchanged).
- `SWFModernRuntime/include/libswf/generated_data.h`: `GEN_EXTERN_COLOR_DATA`,
  `_UNINV_MAT_DATA`, `_GRADIENT_DATA`, `_MORPH_END_COLOR_DATA`;
  `avm2_cpu_raster.c` / `avm2_display.c` use the macros instead of bare externs.
- `SWFRecomp/wasm_wrappers/host_main_graphics.c`: `SWF_AVM2` section (pointer
  definitions, `setAvm2Tables`, `setAvm2DrawTables`, `runSWF → runSWF_avm2`).
- `SWFRecomp/scripts/build_graphics_host.sh`: `AVM2=1`; `deploy_wasm_demo.sh` builds
  both hosts into `docs/recompiler/host/`.
- `SWFRecomp/wasm_wrappers/guest_main_graphics.c`: `SWF_AVM2` exports
  (`get_avm2_movie_tables`, `get_avm2_abc_frames/lazy`, `get_avm2_symbol_class_frames`,
  `get_avm2_device_fonts[_count]`).
- `SWFRecomp/wasm_wrappers/guest_setjmp_shim.h` (+ `get_jmp_buf_size` /
  `get_guest_jmp_buf_size` exports): §3.1.
- `docs/recompiler/guest_loader.js`: picks the host variant from the guest's exports,
  fills the AVM2 tables, checks the `jmp_buf` sizes; `pipeline_graphics.js`: AS3 no
  longer refused, mounts the shim, adds `-DSWF_AVM2 -I/project/include/avm2`;
  `pipeline.js`: the run flow preloads the matching host and the runnable zip ships it.
- Verification: native `verify_output.py` smokes for avm2/try_catch (graphics and
  no-graphics) and avm1/try_catch (graphics) pass with the header changes; the four
  page runs above; CI per CLAUDE.md (graphics, `categories=full`) — run id in the
  commit's pipeline state.

## 7. Re-running the measurements

- Probe page + plans: `scratchpad/probe/` (`index.html`, `gen_plans.py`,
  `split_methods.py`, `plans/*.json`); serve the directory
  (`python3 -m http.server 8011`) — it needs `coi-serviceworker.js` next to it for
  the SDK's SharedArrayBuffer — and run
  `python.exe C:\playwright\ceiling_probe.py "http://localhost:8011/index.html?plan=plans/plan_X.json" C:\playwright\probe_X.json`.
  Results: `C:\playwright\probe_*.json` (stderr, timings, output size, imports for
  the `sj_*` jobs). The SDK's "oneshot canceled" worker race can fail a whole plan;
  rerun it in a fresh page.
- AS3 end-to-end on the page: `python.exe C:\playwright\recomp_as3_run.py
  http://localhost:8010/docs/recompiler/ C:\playwright\<test>.swf <tag>` after
  `deploy_wasm_demo.sh` (or after copying a locally built `graphics_host_avm2.*` and
  the current `guest_main_graphics.c` into `docs/recompiler/host/`).
- Memory: `tasklist.exe /FI "IMAGENAME eq chrome.exe" /FO CSV` polled from WSL; the
  in-page `performance.measureUserAgentSpecificMemory()` is useless here (it counts
  every worker the SDK ever spawned, ~4.5 GB reserved per clang run, never freed).

## 8. Brief items this slice overturned

- §"What exists today" (3): "Seedling's static data alone exceeds the 101 MB arena" —
  no: 31 MB static (§2.1). The arena is not a blocker for any title in the set; the
  C-text size is.
- (2): the slim driver's single-TU ceiling is well above the "10 K-line" data point
  (that was the full atom): 281 K lines / 12.9 MB compiles at -O1 (§1.1).
- (4): the slim driver can lower `setjmp` with `-mllvm -wasm-enable-sjlj` (§4.2); the
  reason plain `setjmp` "works" in the AVM1 page is that the WASIX libc version is
  linked and its syscalls are stubbed — the page now renames it for AS3 guests.
- (1): the host variant is a two-hour job, not the expensive component (§3). The
  expensive-looking part that WAS real is the `jmp_buf` layout trap (§3.1), which the
  brief did not list.
- The brief's framing "should the data bypass the compiler" and "is it worth it versus
  the bundle" both assumed the page could not run Seedling at all; it can (§0), so the
  remaining work is quality (try/catch), speed (TU split) and footprint (blob), not
  feasibility.
