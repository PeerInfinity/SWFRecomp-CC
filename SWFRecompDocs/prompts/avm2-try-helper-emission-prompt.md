# Slice: try-helper emission mode (exception-table methods through a runtime-allocated try frame)

You are starting a fresh session on SWFRecomp-CC at `master` (baseline: the commit
this file was added in — `git log -1 -- SWFRecompDocs/prompts/avm2-try-helper-emission-prompt.md`;
the work it builds on is `53ee2bc5a`, the AVM2 in-browser host variant). CLAUDE.md is
auto-loaded; it authorises commit/push/CI/Pages deploy. Work in this tree (not the
Ruffle-test fan-out — that convention is for corpus sessions only).

Read first, in this order:
1. `SWFRecompDocs/plans/avm2-in-browser-assessment.md` §3.1 (the guest/host `jmp_buf`
   trap) and §4.1 (the emission mode you are implementing, with the generated-code
   shape and the Node validation), then §0 and §6 for what shipped.
2. `SWFRecomp/src/abc/abc_emit.cpp` — how a method with an exception table is emitted
   today (`setjmp` inline in the prologue, `volatile` sp/scope_n, the handler dispatch).
3. `SWFModernRuntime/src/avm2/avm2_error.c` (`avm2_try_push_frame` and friends,
   `Avm2TryFrame`) and `SWFRecomp/wasm_wrappers/guest_setjmp_shim.h` (the interim fix:
   why a libc-typed struct must not cross the guest/host boundary).
4. `SWFRecomp/src/action/action.cpp` `ACTION_TRY_SETJMP` — the AVM1 try/catch emission
   that gets the same mode (§7.3 of
   `SWFRecompDocs/plans/in-browser-recompiler-refresh-assessment.md` lists it as the
   page's AVM1 limitation).

## The problem

In the in-browser recompiler the generated C is compiled by a guest toolchain with no
setjmp/longjmp support of its own: a plain `setjmp` in generated code silently links
the WASIX libc `stack_checkpoint` version, and an `Avm2TryFrame` embedding a `jmp_buf`
is guest-allocated but host-written (Emscripten's `jmp_buf` is 156 bytes, WASIX's a few
— the host smashed guest locals: Error #1010 on the first trace of any try-bearing
method). The shim papers over the size; the real fix is that generated code never
holds a `jmp_buf`. Today `avm2/try_catch` and `graphics_draw_path` boot and trace in
the page but die at the first throw inside `try` (with a clear interim message).

## Goal

A recompiler option (name it; off by default so native output is byte-identical)
under which every method with an exception table is emitted as §4.1 describes:

- the method body moves into `static int abcN_mK_body(void* env)`; locals/stack/scope
  arrays stay in the outer frame (an `AbcNmKEnv` struct) so they survive re-entry;
  every `return v;` becomes `env->ret = v; return 0;`;
- the outer function allocates the `Avm2TryFrame` through the RUNTIME (a new
  `avm2_try_run(ctx, tf, fn, env)` in `avm2_error.c`: `setjmp` + call, returns 1 on a
  caught throw) and loops `while (avm2_try_run(...)) { env.resume = handler_target;
  env.exc = ...; }` — the try frame's storage must be owned by the runtime side
  (allocated by the runtime, or a runtime-defined opaque size), never a libc type in
  generated code;
- on re-entry the body resets `sp`/`scope_n`, pushes the exception and `switch`es to the
  handler label — the same semantics as the inline version; `volatile` goes away;
- the same mode for `ACTION_TRY_SETJMP` in the AVM1 emitter.

Consider: methods with several exception ranges / nested try, `finally` (how the current
emitter lowers it), rethrow from a handler, a throw inside a handler, generators of the
re-entry `switch` when the handler target is inside a loop body (all labels must be
reachable from the switch — check the current emitter's rules), GC roots (the arrays
moved into the env must still be visible to the collector exactly as before — read
`avm2_gc.c`'s stack-scanning rules first; see memory `avm2-gc-cannot-run-mid-method`),
and `avm2_unbounded_recursion` (the extra indirect call per invocation changes the
native stack depth per level slightly).

## Verification (all of it)

1. Native, option OFF: `render_canary.py` / a handful of tests byte-identical (the
   default emission must not change).
2. Native, option FORCED ON across the corpus: `ruffle-tests.yml` in **graphics**
   mode with `categories=full` (AVM2 emission changed) — CI validates the semantics
   without a browser. Add a way to force the option in `verify_output.py` / the
   workflow (an env var or workflow input); zero regressions per
   `scripts/corpus_status_diff.py`. If a workflow input is the cleanest route, run
   the default (option off) run too, so the default stays graded.
3. In the page (`docs/recompiler`, Windows Chrome via
   `tools/divergence/perf/WINDOWS_PLAYWRIGHT_FROM_WSL.md`): `avm2/try_catch` and
   `graphics_draw_path` trace through their throws; the original Seedling
   (`~/CC/newgrounds/598977_Seedling.swf`) still renders its title screen, and one
   AVM1 test with try/catch runs. Before trusting any "still broken" browser result,
   check who owns the served port (`readlink /proc/<pid>/cwd` of the listener) — a
   stale `http.server` from an earlier session cost the bitmap slice an hour.
4. Pages deploy (`deploy-pages.yml`) after the `docs/` / wrapper change; watch it.

## Done means

- Option implemented for AVM2 and AVM1 emitters, default off; native default output
  byte-identical; forced-on full graphics CI green with zero regressions; the page
  runs try-bearing content (evidence: the two tests + Seedling title screen).
- Remove the interim shim/size-check path only if the option is now what the page
  uses (the loader should compile with the option on for the page).
- Closeout: a short status doc under `SWFRecompDocs/status/` (design as landed,
  what the corpus said with the option forced on, page evidence, residuals);
  §4.1/§6 of the assessment updated to "shipped"; memory updated; commit pushed;
  Pages deploy dispatched.

## After this slice

The assessment's remaining page work, in order: (2) the TU-split flag in
`abc_emit.cpp` (Snailiad's 30 MB methods TU never finishes in the page), (3) skipping
the AVM2-dead payload (`bitmap_data` + `sound_data`, 20.7 MB of Seedling's 31 MB) for
AS3 SWFs. Your report's "next slice's line" should name the TU-split slice with the
baseline it should start from; do not launch it yourself unless the session that
launched you is unreachable AND the closeout is pushed (then follow the memory note
`session-launch-protocol`: prompt file → `~/bin/wsl-launch-claude.sh -m opus -C
/home/robert/CC/SWFRecomp-CC -d : -t <label> -f <prompt.md>` → verify → handshake).

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
