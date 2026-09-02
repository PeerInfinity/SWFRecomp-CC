# Investigation: can AS3 (AVM2) SWFs run through the in-browser recompiler?

You are starting a fresh session on SWFRecomp-CC at `master`. CLAUDE.md is auto-loaded.
This is an INVESTIGATION slice: the deliverable is a written assessment with measured
answers and a recommended design (or a reasoned "not feasible"), plus any cheap
enabling fixes you find on the way. Do not start the full implementation unless the
assessment turns out to be trivially small. Not the Ruffle-test fan-out convention.

Read first: `SWFRecompDocs/plans/in-browser-recompiler-refresh-assessment.md` §7–§9
(how the AVM1 in-browser build works and why it is shaped that way), then
`docs/recompiler/pipeline_graphics.js`, `docs/recompiler/guest_loader.js`,
`SWFRecomp/scripts/build_graphics_host.sh`, `SWFRecomp/wasm_wrappers/host_main_graphics.c`,
and the AVM2 entry points `SWFRecomp/wasm_wrappers/main.c` (`SWF_AVM2` branch →
`runSWF_avm2`) and `SWFRecomp/scripts/build_wasm_avm2.sh`.

## What exists today

- The page already recompiles AS3 SWFs to C in the browser (Seedling: 65 s, 16 files,
  182 MB of C) and the downloadable bundle's `build.sh` builds them with Emscripten.
- The in-browser RUN refuses AS3 (`compileGuest` guard) because:
  1. The graphics host is built from the AVM1 source set only (no `src/avm2/*.c`,
     `third_party/quickjs-libregexp`, `third_party/lzma`, no `-DSWF_AVM2`).
  2. AVM2 output is huge and lands in few TUs: Seedling `abc_timeline.c` 33 MB,
     `abc1_methods.c` 12 MB, `abc0_methods.c` 1.7 MB, `draws.c` 140 MB (bitmap bytes).
     The in-browser compiler (wasmer `clang/clang`, a clang-16 "slim" driver) handled
     Doodle Jump's 46 files / 19 MB in 61 s, but the March pipeline recorded the full
     clang atom dying with exit 45 (OOM) on a 10 K-line file; the slim driver's ceiling
     for a single TU is UNMEASURED.
  3. The guest data arena is 101 MB (`GUEST_ARENA_BASE..END`, host linked
     `-sGLOBAL_BASE=101MB`); Seedling's static data alone exceeds it.
  4. AVM2 generated code inlines `setjmp` (`abc_emit.cpp` ~2722: `if (setjmp(_tf.jb))`)
     for every try/catch — same limitation as AVM1 try/catch, but far more common in
     AS3 code; the slim driver cannot lower setjmp and a JS stub cannot implement it.

## Questions to answer, with measurements

1. **Compiler ceiling.** Largest single TU the in-browser clang compiles (bytes /
   lines / time / memory), measured with real generated AVM2 files. Does splitting
   (the recompiler could emit `abcN_methods_K.c` chunks) get under it? Is `-O0` needed?
2. **Data path.** Should generated DATA (`draws.c` bitmap/shape bytes, tables) bypass
   the compiler entirely — e.g. the recompiler also emitting a binary blob the loader
   copies into host memory, with the C side referencing it by pointer? That removes
   the 140 MB TU and the arena limit at once; what in the runtime assumes static arrays?
3. **Host variant.** Cost of a second host (`graphics_host_avm2.{js,wasm}`) built with
   the AVM2 source set + `-DSWF_AVM2` + JSPI + `SUPPORT_LONGJMP=wasm`; which globals
   AVM2 generated code references (the AVM1 bridge covers five: see `bridge_globals.h`);
   what `runSWF_avm2` needs from the guest (registry, symbol classes, `abc_gen.h`).
4. **setjmp.** Options: (a) a recompiler emission mode that runs try bodies through a
   runtime helper taking a function pointer (the runtime does the setjmp; Emscripten's
   wasm-sjlj unwinds through guest frames? — test it), (b) accept "no try/catch" and
   measure how much AS3 content that excludes, (c) something else.
5. **Is it worth it** versus the bundle path, which already works for AS3 with a local
   Emscripten (Seedling builds in 5:38, 1.8 GB RAM)? Give a recommendation with the
   estimated effort per component.

Test material: `~/CC/newgrounds/598977_Seedling.swf` (original; its bitmap texture
envelope issue is a separate slice — see `bitmap-texture-envelope-prompt.md`; it may or
may not be fixed by the time you run), plus a SMALL AS3 SWF from
`ruffle-tests/tests/swfs/avm2/` for compiler-ceiling and end-to-end experiments.
Browser experiments: Windows Chrome via Playwright per
`tools/divergence/perf/WINDOWS_PLAYWRIGHT_FROM_WSL.md`; the recompiler page can be
served locally with `(cd docs && python3 -m http.server 8010)` after
`SWFRecomp/scripts/deploy_wasm_demo.sh`.

## Done means

- An assessment doc `SWFRecompDocs/plans/avm2-in-browser-assessment.md` answering the
  five questions with numbers, and a recommendation.
- Any enabling fix you shipped (e.g. a recompiler TU-splitting flag, a data-blob
  emission) committed with its own verification, CI per CLAUDE.md, no regressions.
- Memory updated; commit pushed; Pages deploy only if `docs/` changed.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
