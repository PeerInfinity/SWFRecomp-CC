# Try-helper emission mode — status (2026-09-02)

Brief: `SWFRecompDocs/prompts/avm2-try-helper-emission-prompt.md`.
Design context: `SWFRecompDocs/plans/avm2-in-browser-assessment.md` §3.1 (the
guest/host `jmp_buf` trap) and §4.1 (the shape this implements).
Baseline: `63c633afa` (CI run 33696811049, graphics/full, 4355 effective, zero
regressions).

## What the mode is for

In the in-browser recompiler the generated C is compiled by a guest toolchain
with no setjmp/longjmp of its own. A plain `setjmp` in generated code silently
links the WASIX libc's `stack_checkpoint` version (which the page stubs to
return 0), and — worse for AVM2 — an `Avm2TryFrame` embedding a `jmp_buf` is
guest-allocated but host-written, and the two toolchains disagree on
`sizeof(jmp_buf)` (Emscripten 156 bytes, WASIX a handful), so the host smashed
the method's locals. `wasm_wrappers/guest_setjmp_shim.h` papered over the size;
this slice is the real fix: **generated code executes no setjmp and holds no
libc-typed object.**

The recompiler option is `try_helper`:

- toml: `[input] try_helper = true` (what `docs/recompiler/pipeline.js` now
  writes for every in-browser recompile);
- env: `SWF_TRY_HELPER=1` forces it on regardless of the toml — how
  `verify_output.py` and CI force it across a corpus run;
- workflow: `ruffle-tests.yml` input `try_helper` (`1` = on), exported as the
  `SWF_TRY_HELPER` env var for the whole job.

**Default is OFF, and at OFF the emitted C is byte-identical to before the
option existed with exactly one deliberate exception** (a pre-existing
constraint violation this slice had to fix to get an AVM1 try/finally script
through the in-browser clang — see "Two defects this slice's own testing
found") — verified by recompiling a mixed AVM1/AVM2 set with the pre-change and
post-change binaries and `diff -r` (see "Verification").

## Design as landed

### AVM2 (`SWFRecomp/src/abc/abc_emit.cpp`)

A method whose exception table has an active entry is emitted as an outer frame
plus a lifted body:

```c
static int abc0_m6_body(void* _p);
static Avm2Value abc0_m6(Avm2Activation* act)
{
    Avm2Value loc[3]; Avm2Value stk[3]; Avm2ScopeEntry lscope[2];
    avm2_setup_locals(loc, 3, act, 6);
    Avm2TryFrameStorage _tf;
    Avm2TryEnv _env;
    _env.act = act; _env.loc = loc; _env.stk = stk;
    _env.lscope = lscope; _env.tf = &_tf; _env.resume = -1;
    _env.exc = avm2_undefined(); _env.ret = avm2_undefined();
    avm2_try_push_frame_st(act->ctx, &_tf, abc0_m6_exc, 1, act->file);
    int _rc;
    while ((_rc = avm2_try_run(act->ctx, &_tf, abc0_m6_body, &_env)) < 0)
    {
        _env.resume = (int32_t) avm2_try_handler_target(&_tf);
        _env.exc = avm2_try_exc(&_tf);
    }
    avm2_try_pop_frame_st(&_tf);
    return _env.ret;             /* + coerce-after-pop, see below */
}

static int abc0_m6_body(void* _p)
{
    Avm2TryEnv* _env = (Avm2TryEnv*) _p;
    Avm2Activation* act = _env->act;
    Avm2Value* loc = _env->loc; Avm2Value* stk = _env->stk;
    Avm2ScopeEntry* lscope = _env->lscope;
    Avm2TryFrameStorage* _tfp = _env->tf;
    uint32_t sp = 0; uint32_t scope_n = 0;
    if (_env->resume >= 0)
    {
        sp = 0; scope_n = 0;
        stk[sp++] = _env->exc;
        switch (_env->resume) { case 13: goto op_13;
            default: avm2_fatal("bad exception handler target"); }
    }
    ...ops, with `_tfp->op_index = N;` where the inline form writes `_tf.op_index`...
}
```

Three points where this departs from the §4.1 sketch, each deliberate:

1. **The try frame's storage is an opaque, runtime-defined blob.** The sketch
   had generated code declare an `Avm2TryFrame` (which embeds a `jmp_buf`) and
   read `_tf.handler_target` / `_tf.exc` from it — that is exactly the layout
   coupling §3.1 is about. What landed is
   `Avm2TryFrameStorage { uint32_t op_index; uint32_t reserved; union {…} opaque; }`
   with `AVM2_TRY_FRAME_STORAGE` = 512 bytes and a
   `_Static_assert(sizeof(Avm2TryFrame) <= AVM2_TRY_FRAME_STORAGE)` on the
   runtime side; the runtime places its `Avm2TryFrame` inside `opaque` and the
   generated code reaches `handler_target`/`exc` through
   `avm2_try_handler_target()` / `avm2_try_exc()` (cold: once per catch).
   `op_index` is hoisted OUT of the blob because it is written before every op
   and must stay a plain store; `Avm2TryFrame` gained
   `const uint32_t* op_index_ext`, and `avm2_throw` reads the live index through
   it when set. Nothing about the guest's libc can now affect the layout.
2. **`avm2_try_run` returns -1 on a caught throw and otherwise the body's exit
   code.** The inline emission pops the try frame BEFORE `ReturnVoid`'s
   `avm2_op_coerce_return` but AFTER `ReturnValue`'s — so a throw out of the
   coercion escapes to the caller in the first case and is caught locally in the
   second. To preserve that exactly, `ReturnVoid` in a coercing method returns
   exit code 1, and the outer function does the coercion after
   `avm2_try_pop_frame_st`. `ReturnValue` coerces inside the body, frame still
   installed, as before.
3. **`sp`/`scope_n` lose `volatile` and are plain locals of the body.** A
   re-entry after a catch is a fresh CALL of the body, so they start at 0 —
   which is precisely the reset the inline version performs by hand. The value
   arrays stay in the outer frame (via `Avm2TryEnv`) so they survive.

Everything else is unchanged: one try frame per method covering all its
exception ranges (nested try / several ranges are already handled by
`op_index` + the exception table, not by frame nesting); the frame stays
installed across a catch (`avm2_throw` leaves `ctx->try_top` at it), so a
rethrow or a throw inside a handler re-enters the same `while` loop; `finally`
is whatever the ABC compiler lowered it to and needs nothing special.

GC: unaffected. `avm2_gc.c` collects only BETWEEN ticks precisely because
method-body operand stacks and locals live on the C stack, so those arrays are
never scanned; moving them one frame outward changes nothing (memory note
`avm2-gc-cannot-run-mid-method`).

Cost: one indirect call per invocation of a try-bearing method (0.2–0.9 % of
methods per the §4 census) and one extra native frame, which slightly changes
the depth at which `avm2_stack_check` reports #1023. The guard measures real
stack addresses, so it self-adjusts.

### AVM1 (`SWFRecomp/src/action/action.cpp`)

AVM1's `jmp_buf` already lives in the runtime (`g_exception_state`); only the
`setjmp` itself was in generated code. The mode lifts the **try body** — not the
whole method — into `static int _swftry_N(void*)` and calls it through
`avm1_try_run` (which does `setjmp(*actionGetExceptionJmpBuf(...))`, i.e. arms
the frame `actionTryBegin` pushed, in exactly the old order):

```c
    // Try-Catch-Finally (lifted body _swftry_1)
    actionTryBegin(app_context);
    Avm1TryEnv _te1 = {0};
    _te1.app_context = app_context; _te1.str_buffer = str_buffer;
    int _trc1 = avm1_try_run(app_context, _swftry_1, &_te1);
    if (_trc1 != AVM1_TRY_THROWN) {
        switch (_trc1) {
        case AVM1_TRY_EXIT_RETURN_VALUE: return _te1.ret;
        case 100: goto label_86;
        default: break;
        }
    } else {
        // Catch block ... (unchanged)
    }
```

The `if (…) {` opens exactly the one brace the old `if (ACTION_TRY_SETJMP(…) == 0) {`
opened, so the existing catch/finally/end boundary machinery closes it unchanged.

Control flow that LEAVES the try body cannot be a `goto`/`return` any more (the
body is a different C function), so it comes back as an exit code:

| exit | meaning | replayed as |
|---|---|---|
| `AVM1_TRY_EXIT_FALLTHROUGH` (0) | ran off the end | fall through |
| `AVM1_TRY_EXIT_RETURN` (1) | `return;` in a void script | `return;` |
| `AVM1_TRY_EXIT_RETURN_VALUE` (2) | `return X;` in a function | `return _teN.ret;` |
| `100 + k` | jump to the k'th label outside the body | `goto label_…;` |
| `AVM1_TRY_THROWN` (-1) | a throw landed here | the catch branch |

Two emitter helpers (`retStmt` / `gotoStmt`) produce every `return`/`goto` the
AVM1 emitter writes, so the rewrite is uniform and nested lifts compose: the
dispatch of an INNER try, emitted while an outer lift is still capturing, goes
through the same helpers and becomes an exit of the outer body. `gotoStmt`
classifies a target by the try body's byte range (and treats every jump emitted
while parsing a nested WITH buffer as internal to that buffer). Function bodies
(`DefineFunction` / `DefineFunction2`) save-and-clear the lift stack around
their recursive parse — they are their own C function and must keep real
returns.

**Refusal case.** A jump from OUTSIDE the try body that targets a label INSIDE
it cannot be lifted (the label moves into the lifted function). The label
pre-scan now records `(source, target)` edges, and such a body keeps the inline
`ACTION_TRY_SETJMP` form. No test in the corpus hits this; a movie that does
still gets today's page behaviour for that one try, not a miscompile.
A label inside the body that the emitter walk never reaches (dead code) is
emitted at the end of the LIFTED body rather than by the leftover-label pass at
the end of the enclosing function, so a goto that stayed inside still resolves.

**File placement.** Lifted bodies are `static` and must sit at file scope in the
file that uses them, so:
- for a try inside a function, `action.cpp` flushes them into
  `script_defs.c` immediately before the function definition (the accumulator is
  parked/restored around each function-body parse so one function cannot steal
  another scope's definitions — the bug that first showed up as
  `‘_swftry_1’ undeclared` in `loadvars_tostring`);
- for a top-level script, the eight `swf.cpp` emission sites now buffer the
  function into an `ostringstream` and `writeScriptFile()` inserts the
  definitions after the leading `#include` block (they use runtime types, so
  they cannot precede the includes). With the option off `writeScriptFile`
  degenerates to the plain write.

## Verification

**1. Default emission byte-identical (option OFF).** Recompiled
`avm1/{try_catch_finally, try_catch_stack, try_finally_simple,
catch_references_registers, math_swf8, stylesheet, timeout,
movieclip_onconstruct}` and `avm2/{try_catch, graphics_draw_path, hello_world}`
with the reverted (pre-change) recompiler and again with the new one:
`diff -r` reports no difference across `RecompiledScripts`, `RecompiledTags`
and `RecompiledABC`.

**2. Native, option forced ON.** Every AVM1 test in the corpus whose generated
C contains a try (22 of them) plus a 40-test sample of the 233 AVM2 tests with
an exception table, run locally with `SWF_TRY_HELPER=1` in `--mode=graphics`:
60/62 strict passes, and neither of the two non-passes is a regression —
`avm2/coerce_to_primitive_side_effects_with_nulls` is `ruffle_matched` in the
published baseline too, and `avm2/away3d_advanced_shallow_water_demo` times out
on this box **with the option OFF as well** (a control run confirmed it; the
machine was at load average ~25 from unrelated work, and the test passes in CI).

Plus, in both modes, `gcc -fsyntax-only -Werror=return-type` over every
generated script of the 22 AVM1 try tests — clean. Keep this check when
touching the AVM1 emitter: `verify_output.py` compiles with `-w`, so it is the
only local thing that sees a malformed return.

Corpus run: `ruffle-tests.yml`, `mode=graphics`, `categories=full`,
`try_helper=1` — run **33704826524** at `ef20d2cbc`, conclusion success, all 30
shards green. Compared to the published baseline (`ruffle-test-results`, run
33696811049 at `53ee2bc5a`) over the 4482-key intersection, using the
`corpus_status_diff` rules (full histogram, intersection only, nested
`_results` excluded):

```
status histogram (intersection):
  output_mismatch    124 ->   124  +0
  pass              4122 ->  4122  +0
  ruffle_matched     235 ->   235  +0
  runtime_error        1 ->     1  +0
transitions: 0
```

**Zero transitions and an identical histogram** — every try-bearing method and
try body in the whole corpus was emitted through the runtime helper and not one
test changed status. (This also settles the local `away3d` timeout: it is
`pass` here in both runs.) A `try_helper` run deliberately publishes NOTHING to
`ruffle-test-results` — see the workflow guard note below — so these numbers
come from the run's `ruffle-test-results` ARTIFACT.

The publish guard is itself a fix this slice had to make: `ruffle-tests.yml`
picks its result-JSON stem from `mode` alone, so a forced-on run would have
force-pushed its numbers over `results_graphics.json` and poisoned the
`{STEM}_previous.json` baseline the next default run diffs against — the exact
trap the `extra_defines` guard already existed for (memory
`ci-verify-run-results-clobber`). `inputs.try_helper == ''` now guards both
publish steps.

Default (option off) run at the same commit, so the shipped default stays
graded — run **33704812955**, conclusion success, results merged
(`87efff571`). `scripts/corpus_status_diff.py ef20d2cbc WORKTREE --per-suite`:

```
=== intersection: 4482 tests (ef20d2cbc -> WORKTREE, results_graphics) ===
  output_mismatch    124 ->   124 (+0)
  pass              4122 ->  4122 (+0)
  ruffle_matched     235 ->   235 (+0)
  runtime_error        1 ->     1 (+0)
  effective         4357 ->  4357 (+0)
GAINS 0 | REGRESSIONS 0 | OTHER STATUS MOVES 0
```

So the two modes and the pre-slice baseline all agree, test for test.

**3. In the page** (`docs/recompiler`, Windows Chrome via Playwright-from-WSL,
served from a FRESH port — the long-lived 8010 server on this box is rooted at
`docs2/` and does not serve `/docs/recompiler/`; check
`readlink /proc/<pid>/cwd` of the listener before trusting a "still broken"
result). Snapshot `ef20d2cbc`:

| SWF | In-browser compile | Result |
|---|---|---|
| `avm2/try_catch` | 14 files, ~15 s | **traces all 11 lines, byte-identical to `output.txt`** (before: died at the first throw inside `try`) |
| `avm2/graphics_draw_path` | 14 files | runs through every `try`, emitting the full `Error thrown: … / at …` trace for each case |
| `avm1/try_catch_finally` | 9 files, ~15 s | **119/119 lines, byte-identical to `output.txt`** — catch, finally, rethrow-through-finally and `try_finally_return()`'s deferred return all correct. This removes §7.3's AVM1 limitation in `in-browser-recompiler-refresh-assessment.md` |
| Seedling, original (7.8 MB) | 16 files (182 MB of C) recompiled in 65 s; 13 compiled to a **38.23 MB guest in 668.8 s** | boots on the AVM2 host and **renders its title screen** (480×480, 2 frames @ 30 fps, 3908 guest functions mirrored); Newgrounds API reports its expected offline `Error #2032` |

The wasmer SDK's "oneshot canceled" worker race (assessment §7) fires on maybe
half of the first attempts and is unrelated to this work — rerun in a fresh
page.

**4. Pages deploy.** `deploy-pages.yml` run `33706633114` at `ef20d2cbc`:
success. (Nothing in `docs/recompiler/` needed committing — `SWFRecomp.wasm`
and `host/` are gitignored and the workflow builds them at deploy time; the
only tracked change there is `pipeline.js`.)

## Two defects this slice's own testing found

**1. Bare `return;` inside a lifted body (introduced here, caught in the page).**
Six emission sites — the script-context arms of `if (actionBaseClipRemoved())
return;` and `if (actionCall(app_context)) return;` — were not routed through
`retStmt`, so inside a lifted body they returned *no value* from a function
declared `int`. `verify_output.py` compiles generated C with `-w`, so gcc said
nothing and the tests passed on an indeterminate exit code; the in-browser
clang rejected it outright (`non-void function '_swftry_8' should return a
value`) on the first AVM1 page run. Fixed by routing them, and by dispatching
BOTH return exits in both contexts so a void return inside a function body and
a valued return inside a void script are replayed the way the emitter handles
those shapes outside a try. The local check that would have caught it is now
part of the verification below: `gcc -fsyntax-only -Werror=return-type` over
every generated script of the 22 AVM1 try tests, in both modes.

**2. A pre-existing bug the page surfaced.** A top-level (void) script with
try/finally emitted `return actionGetPendingReturn(app_context);` — a value
returned from a `void` function. gcc only warns (and `-w` hid it), so no native
test ever failed, but clang rejects it, which would have blocked
`avm1/try_finally_simple` in the page with the option OFF too. Fixed the way
the emitter already handles a top-level `RETURN` action: the pending value is
dropped (`(void) actionGetPendingReturn(app_context); return;`). This is the
one intended change to the DEFAULT emission; `try_finally_simple`,
`try_catch_finally`, `try_catch_stack` and `catch_references_registers` all
pass in both modes after it.

## Residuals / notes

- The `guest_setjmp_shim.h` size-pin and the loader's `jmp_buf` size check stay.
  They are no longer load-bearing for AVM2 (generated code allocates no
  `jmp_buf`), but the shim's `setjmp` stub still covers the AVM1 refusal case
  above, and keeping it costs nothing.
- `verify_output.py` now stamps `RecompiledScripts/.recomp_mode` and
  invalidates a cached tree when `SWF_TRY_HELPER` changes — the env var alters
  the generated C without touching the binary or the SWF, which the mtime-based
  staleness check cannot see.
- The runnable-zip bundle the page produces carries `try_helper = true` in its
  `config.toml`, so a local rebuild from that zip reproduces what ran in the
  browser.
- Not done here (and not asked for): making the mode the NATIVE default. It
  costs an indirect call on a rare method shape and buys nothing outside the
  guest toolchain, so the inline emission stays the default.
