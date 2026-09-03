# Slice: TU-split flag for `abcN_methods.c` (assessment §1.3)

You are starting a fresh session on SWFRecomp-CC at `master`. **Baseline: `c8c8c7894`**
(the try-helper slice's closeout; CI runs 33704812955 default / 33704826524 forced-on,
both zero-regression, results merged at `87efff571`). CLAUDE.md is auto-loaded; it
authorises commit/push/CI/Pages deploy. Work in this tree — the Ruffle-test fan-out
convention is for corpus sessions only, not this one.

Read first, in this order:
1. `SWFRecompDocs/plans/avm2-in-browser-assessment.md` §1.1 (the measurements), §1.2
   ("splitting pays more than linearly"), **§1.3 (the mechanical change you are
   implementing)**, and §5 for where this sits in the arc.
2. `SWFRecompDocs/status/avm2-try-helper-emission.md` — the slice just before yours.
   Read it for the OPTION PATTERN (toml key + env override + workflow input, off by
   default, byte-identical default emission) and for the four traps in its
   "Residuals / notes" and "Two defects" sections. Yours is the same shape of change
   to the same file, so the same traps apply.
3. `SWFRecomp/src/abc/abc_emit.cpp` — the `abc<tag>_methods.c` block at ~line 4117:
   one `ofstream`, then per body an `Avm2AbcException` array, an activation-trait
   array (`emitTraitArray`, ~line 1042), and `emitMethodBody`; then the `_pt`/`_po`
   signature arrays and the `Avm2AbcMethodData` table. `abc_gen.h` is emitted at
   ~line 4345.

## The problem

Compile time inside the in-browser clang grows **super-linearly** with TU size, and
today every method of a DoABC tag lands in one file. Measured (§1.1, real in-browser
clang at the pipeline's exact flags):

| Input | Result |
|---|---|
| Seedling `abc1_methods.c`, 12.9 MB / 281 K lines, one TU | 399 s |
| The **same** methods as nine ~1.5 MB TUs, one clang call | **182 s**, half the peak memory, same output size |
| Snailiad `abc1_methods.c`, 29.7 MB / 713 K lines | **did not finish in 25 min** (no crash, worker at 2.23 GB) |

So this is both the only thing standing between the page and Snailiad-class titles and
a ~2× speedup for every AS3 SWF. It also gives the gcc-ICE guard a lever (memory
`recompiler-giant-function-gcc-ice`).

## Goal

A recompiler option (name it; **off by default so native output is byte-identical**)
that emits `abc<tag>_methods.c` as N chunk files plus one table file, as §1.3
describes and as `scratchpad/probe/split_methods.py` prototyped (its nine chunks all
pass `gcc -fsyntax-only`):

- split at **method boundaries**, targeting a chunk size (~1.5 MB was the measured
  sweet spot — make the target the option's value, not a hard-coded constant);
- `abcN_mK`, its `_bt` activation-trait array and its `_exc` exception array lose
  `static`; the table chunk gets `extern` declarations for the ones it references;
- the prototypes go into `abc_gen.h` (or a per-tag generated header — your call, but
  say which and why);
- the `Avm2AbcMethodData` table, the `_pt`/`_po` signature arrays and `Avm2AbcFileData`
  stay in the table chunk.

Consider: the try-helper mode's `static int <fn>_body(void*)` (emitted immediately
before its outer function, so a method-boundary split keeps the pair together — it can
stay `static`, confirm that); the big-literal `__vlit*` tables (function-local statics,
should be fine); `emitTraitArray`'s other callers; `avm2_symbol_prefix` (child-SWF
emission already prefixes every exported symbol — your new globals must respect it);
and a tag with very few methods (N should collapse to 1 and produce today's file set).

## The trap that will bite you if you skip it

**Dropping `static` creates new GLOBAL symbols, and `ruffle-tests/verify_output.py`'s
`generate_child_movie_file` merges a child SWF's generated C into one
`movie_<prefix>.c` with regex-driven symbol renaming that only knows about `func2?_*`
and `str_*`.** The try-helper slice deliberately kept its lifted AVM1 bodies `static`
for exactly this reason. Check what happens to a test with an AVM2 child movie before
you trust a green local run — and note that the child path already sets
`symbol_prefix`, which may be all the isolation you need. Prove it either way.

## Verification (all of it)

1. **Native, option OFF:** the emitted C must be byte-identical to the baseline
   binary's. Method: `git diff -- SWFRecomp > p.patch; git apply -R p.patch`, rebuild,
   recompile a mixed set into a scratch dir, restore, rebuild, recompile again,
   `diff -r`. (Do NOT use `git stash` — it is shared across this repo's worktrees.)
2. **Native, option FORCED ON across the corpus:** `ruffle-tests.yml` in **graphics**
   mode with `categories=full` (AVM2 emission changed). Add the force-on surface the
   way `try_helper` did it (env var read in `config.cpp` + a workflow input exported
   as that env var). **If you add a workflow input, add `inputs.<yours> == ''` to BOTH
   publish guards** — a run that changes what the binaries do while keeping the `mode`
   stem would force-push its numbers over `results_graphics.json` and poison the next
   run's baseline (memory `ci-verify-run-results-clobber`; the try-helper slice had to
   cancel two runs mid-flight over this). Also extend the `.recomp_mode` stamp in
   `verify_output.py::recompile_swf` so a cached tree from the other mode regenerates.
   Zero regressions per `scripts/corpus_status_diff.py`. Run the default (option off)
   run too, so the shipped default stays graded.
3. **In the page** (`docs/recompiler`, Windows Chrome via
   `tools/divergence/perf/WINDOWS_PLAYWRIGHT_FROM_WSL.md`), with the option on in
   `pipeline.js` at whatever threshold you land on:
   - **Snailiad is the target** — get it to compile at all, and report the time. This
     is the slice's headline number.
   - Seedling: report compile time against the 668.8 s / 38.23 MB guest the try-helper
     slice measured at `ef20d2cbc`, and confirm the title screen still renders.
   - One small AS3 test (e.g. `avm2/try_catch`) still traces its expected output.
   Serve from a FRESH port: this box has a long-lived `http.server` on 8010 rooted at
   `docs2/`, which does NOT serve `/docs/recompiler/`. Check
   `readlink /proc/<pid>/cwd` of the listener before believing any "still broken"
   browser result. Expect the wasmer SDK's "oneshot canceled" worker race on roughly
   half of first attempts — rerun in a fresh page, it is not your bug.
4. **Pages deploy** (`deploy-pages.yml`) after the `docs/` change; watch it.

Note for the local Ruffle runs: `verify_output.py` compiles generated C with `-w`, so
it cannot see a malformed declaration. If you emit anything new at file scope, run
`gcc -fsyntax-only -Werror=return-type -Wall` over a few generated `RecompiledABC/*.c`
yourself.

## Done means

- Option implemented, default off, native default output byte-identical; forced-on full
  graphics CI green with zero regressions and the default run graded too; the page
  compiles Snailiad (or, if it still does not, a measured account of where the wall now
  is — that is a real result, not a failure, but say so plainly).
- Closeout: a short status doc under `SWFRecompDocs/status/`; §1.3 and §5 of the
  assessment updated to "shipped" with the measured numbers; memory updated (add a
  note, and update `avm2-in-browser-recompiler`'s "remaining slices" line); commit
  pushed; Pages deploy dispatched.

## After this slice

The assessment's last piece: **skip the AVM2-dead `bitmap_data`/`sound_data` payload
for AS3 SWFs** (§2.2 — 20.7 MB of Seedling's 31 MB static, ~120 MB of C, one-line win
for the bundle path too), and optionally the payload blob. Your report's "next slice's
line" should name it with the baseline it should start from; do not launch it yourself
unless the session that launched you is unreachable AND your closeout is pushed (then
follow the memory note `session-launch-protocol`).

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
