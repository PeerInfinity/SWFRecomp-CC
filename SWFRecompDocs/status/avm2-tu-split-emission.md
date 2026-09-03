# TU-split emission mode — status (2026-09-02)

Brief: `SWFRecompDocs/prompts/avm2-tu-split-emission-prompt.md`.
Design context: `SWFRecompDocs/plans/avm2-in-browser-assessment.md` §1.1 (the
measurements), §1.2 ("splitting pays more than linearly"), §1.3 (the shape this
implements).
Baseline: `c8c8c7894` (the try-helper slice's closeout; CI runs 33704812955
default / 33704826524 forced-on, both zero-regression, merged at `87efff571`).

## What the mode is for

Compile time inside the in-browser clang grows **super-linearly** with TU size,
and until this slice every method of a DoABC tag landed in one C file. Measured
against the real in-browser compiler at the pipeline's exact flags (§1.1):

| Input | Result |
|---|---|
| Seedling `abc1_methods.c`, 12.9 MB / 281 K lines, one TU | 399 s |
| the same methods as nine ~1.5 MB TUs, one clang call | **182 s**, half the peak memory, same output |
| Snailiad `abc1_methods.c`, 29.7 MB / 713 K lines | **did not finish in 25 min** (worker at 2.23 GB, no crash) |

So the split is both the only thing between the page and Snailiad-class titles
and a ~1.6× speedup for every AS3 SWF.

The recompiler option is `tu_split`, and its VALUE is the target size in bytes
of one body chunk:

- toml: `[input] tu_split = 1500000` (what `docs/recompiler/pipeline.js` now
  writes for every in-browser recompile, and what the runnable-zip bundle's
  `config.toml` therefore carries);
- env: `SWF_TU_SPLIT=<bytes>` overrides the toml — how `verify_output.py` and
  CI force it across a corpus run. `0`/empty = off;
- workflow: `ruffle-tests.yml` input `tu_split`, exported as `SWF_TU_SPLIT` for
  the whole job. CI forces a deliberately TINY target (4096) — at the page's
  1.5 MB nothing in the Ruffle corpus would split at all and the run would
  prove nothing.

**Default is 0 (off), and at off the emitted C is byte-identical to before the
option existed** — no exceptions this time (see "Verification").

## Design as landed

`SWFRecomp/src/abc/abc_emit.cpp`, the `abc<tag>_methods.c` block.

Everything one method contributes at file scope — its `_exc` exception array,
its `_bt` activation-trait array, its `abcN_mK` function, and (try-helper mode)
the lifted `static int abcN_mK_body(void*)` emitted immediately after it — is
written into one `std::ostringstream unit`. Units are appended to the current
chunk; when the chunk reaches `tu_split` bytes it is closed and a new one
starts. A chunk boundary can therefore only ever fall **between methods**, and
the try-helper pair is structurally inseparable — `_body` stays `static` and
stays in its outer function's chunk (confirmed in the emitted C, and it is why
the split needed no special case for that mode).

Emission at `tu_split > 0`:

- `abc<tag>_methods_<k>.c` — banner + `#include "<prefix>abc_gen.h"` + the
  chunk's units. `abcN_mK`, `abcN_mK_bt` and `abcN_mK_exc` lose `static`
  (`emitMethodBody` and `emitTraitArray` gained an `external` parameter that
  defaults to false, so `emitTraitArray`'s three other callers — the class,
  instance and script trait arrays in `abc<tag>_tables.c` — are untouched).
  The `_md` trait-metadata sub-arrays stay static: only the `_bt` initializer
  right below them reads them, and it is in the same chunk.
- `abc<tag>_methods.c` — the same banner and include, then the extern
  declarations for the chunked symbols, then exactly what it always held: the
  `_pt`/`_po` signature arrays, `Avm2AbcMethodData` and (in `_tables.c`)
  `Avm2AbcFileData`.

**Where the declarations went, and why.** Not into `abc_gen.h` and not into a
per-tag header: straight into the table chunk. That file is their ONLY
consumer — nothing outside the methods family names a method function — while
`abc_gen.h` is included by every generated TU, so a Snailiad-sized tag would
have put ~21 K declarations in front of all nineteen body chunks for nothing.
The cost of the choice is that a body chunk defines non-static functions with
no prior prototype, which is a `-Wmissing-prototypes` diagnostic and nothing
else; that warning is not in any build's flag set (the page compiles `-w`,
`verify_output.py` compiles `-w`, `bundle/build.sh` does not enable it).

**Collapse to one.** A tag whose whole body text fits under the target keeps
today's file set — one `abc<tag>_methods.c` holding bodies then tables, no
chunk files and no extern block. The only difference from the option-off
emission is the linkage keywords. This is what every small corpus test and
every AS3 Ruffle test in the page produces at the 1.5 MB target.

**Symbol prefixing.** Every name the split touches is derived from
`p = prefix_ + "abc" + tag`, so `avm2_symbol_prefix` already covers the new
file names AND the new globals: a child SWF emits
`<child>_abc0_methods_<k>.c` defining `<child>_abc0_m17`. Verified by
recompiling `avm2/loader_events`'s `loadable.swf` with
`symbol_prefix = "loadable_"` (see below).

Other things the brief flagged, checked:
- the `__vlit*` big-literal tables are function-LOCAL statics (emitted inside
  the body, indented), so they have no file-scope linkage at all and cannot
  collide across chunks;
- `bundle/build.sh` globs `RecompiledABC/*.c`, so the chunks are compiled with
  no change — but its per-file opt-level `case` matched `abc*_methods.c`
  literally, so `abc*_methods_*.c` was added there (and the equivalent two
  places in `SWFRecomp/scripts/build_wasm_avm2.sh`) to keep the chunks at
  `ABC_OPT` instead of the runtime's `-O2`;
- `docs/recompiler/pipeline_graphics.js` enumerates `result.files` and
  compiles every `.c` it finds, so it needed no change.

## The child-movie trap, resolved

The brief's warning: dropping `static` creates new GLOBAL symbols, and
`verify_output.py::generate_child_movie_file` merges a child SWF's generated C
into one `movie_<prefix>.c` with regex-driven renaming that only knows
`func2?_*`, `str_*`, `script_*`, the button/clip/sprite tables and the
`draws.c` arrays.

It does not bite, for two independent reasons, and both were checked rather
than assumed:

1. That merge only ever consumes `RecompiledScripts/` and
   `RecompiledTags/tagMain.c` — **AVM1** output. A child's `RecompiledABC/` is
   never merged; it is copied file-by-file into the build dir and compiled as
   its own TUs (`verify_output.py` ~line 2367), which is exactly what the
   chunks want.
2. That copy path already passes `symbol_prefix=<child>_` to the recompiler,
   so the chunk FILE names and every symbol in them are prefixed and cannot
   collide with the parent's.

Proof: `avm2/loader_events` (AVM2 parent with the AVM2 child `loadable.swf`)
passes with `SWF_TU_SPLIT=4096`, and the standalone prefixed recompile emits
`loadable_abc0_methods_{0,1,2}.c` + `loadable_abc0_methods.c` with every symbol
carrying the prefix.

## Verification

**1. Default emission byte-identical (option OFF).** Recompiled
`avm2/{try_catch, graphics_draw_path, hello_world, loader_events,
stage_displayobject_properties}`, `avm1/{try_catch_finally, math_swf8,
stylesheet}`, `from_avmplus/ecma3/Array/e15_4_1`, and `loadable.swf` under
`symbol_prefix = "loadable_"`, with the reverted (pre-change) binary and again
with the new one — `git diff -- SWFRecomp > p.patch; git apply -R p.patch`,
rebuild, recompile, restore, rebuild, recompile, `diff -r`. **No difference**
across `RecompiledScripts`, `RecompiledTags` and `RecompiledABC`.

**2. `gcc -fsyntax-only -Werror=return-type -Wall`** over every generated
`RecompiledABC/*methods*.c`, `*tables.c` and `*registry.c` of that set in four
configurations (off; `tu_split=4096`; `tu_split=4096` + `try_helper=1`;
`tu_split=8000000`, the collapse-to-one path) — **194 files, zero
diagnostics**. `verify_output.py` compiles generated C with `-w`, so this is
the only local thing that sees a malformed file-scope declaration.

**3. Native, option forced ON across the corpus.** `ruffle-tests.yml`,
`mode=graphics`, `categories=full`, `tu_split=4096` — run **33710882328** at
`39ad765df`, conclusion success, all 30 shards green. Compared against the
default-emission run at the SAME commit over the 4482-key intersection
(`corpus_status_diff` rules: full histogram, intersection only, nested
`_results` excluded):

```
  output_mismatch    124 ->   124 (+0)
  pass              4122 ->  4122 (+0)
  ruffle_matched     235 ->   235 (+0)
  runtime_error        1 ->     1 (+0)
  effective         4357 ->  4357 (+0)
GAINS 0 | REGRESSIONS 0 | OTHER STATUS MOVES 0
```

**Zero transitions and an identical histogram** with every AS3 test in the
corpus emitted as many small chunks instead of one TU. Those numbers come from
the run's `ruffle-test-results` ARTIFACT: a `tu_split` run deliberately
publishes NOTHING (see the guard note below), and `origin/ruffle-test-results`
is still at the default run's `ec48daf67` afterwards, which is the check that
the guard held.

Default (option off) run at the same commit so the shipped default stays
graded — run **33710871686**, conclusion success, results merged.
`scripts/corpus_status_diff.py 39ad765df WORKTREE --per-suite`:

```
=== intersection: 4482 tests (39ad765df -> WORKTREE, results_graphics) ===
  output_mismatch    124 ->   124 (+0)
  pass              4122 ->  4122 (+0)
  ruffle_matched     235 ->   235 (+0)
  runtime_error        1 ->     1 (+0)
  effective         4357 ->  4357 (+0)
GAINS 0 | REGRESSIONS 0 | OTHER STATUS MOVES 0
```

The publish guard: `ruffle-tests.yml` picks its result-JSON stem from `mode`
alone, so a forced-on run would force-push its numbers over
`results_graphics.json` and poison the `{STEM}_previous.json` baseline the next
default run diffs against (memory `ci-verify-run-results-clobber`).
`inputs.tu_split == ''` now guards both publish steps, alongside
`extra_defines`, `single_test` and `try_helper`. `verify_output.py`'s
`.recomp_mode` stamp became `try_helper=<0|1> tu_split=<n>` so a cached tree
from a different mode regenerates.

**4. In the page** (`docs/recompiler`, Windows Chrome via Playwright from WSL,
served from a FRESH port — the long-lived 8010 listener on this box is
`--directory docs`, i.e. it serves `/recompiler/`, not `/docs/recompiler/`;
check `readlink /proc/<pid>/cwd` and what `/` actually returns before trusting
a "still broken" result). Snapshot `39ad765df`, `pipeline.js` at
`tu_split = 1500000`:

| SWF | Recompile | In-browser compile | Result |
|---|---|---|---|
| **Snailiad, original (6.4 MB)** | 37 C files, 216.08 MB, 51.7 s | 34 files → **51.78 MB guest in 1717.5 s** (28.6 min), max chrome.exe process ~1.73 GB | **boots and renders** (800×480, 2 frames @ 24 fps, SWF v10): sky, terrain and the title panel. 7083 function-table entries mirrored, guest data [64 KB, 45.3 MB) of the 101 MB arena. **Before this slice its methods TU alone did not compile in 25 min** |
| **Seedling, original (7.8 MB)** | 27 C files, 182.04 MB, 52.1 s | 24 files → 38.28 MB guest in **414.1 s** (was **668.8 s** at `ef20d2cbc`), max process 2.57 GB | title screen renders as before (480×480, PLAY button) |
| `avm2/try_catch` (1.2 KB) | 14 files, 0.5 s | 11 files → 109.6 KB guest in 9.7 s | traces all 11 lines, **byte-identical to `output.txt`**; single-tag, so it took the collapse-to-one path (one 43.3 KB `abc0_methods.c`) |

So: **1.62× faster on Seedling** end to end for the compile phase, and
Snailiad — the largest title in the set — goes from "never finishes" to
28.6 minutes and a rendered frame. Snailiad's `abc1` bodies became 19 chunks
of ~1.43 MiB plus a 928 KB table chunk; its peak working set (1.73 GB) is now
BELOW Seedling's (2.57 GB, driven by Seedling's 142 MB `draws.c`, untouched
here — that is the next slice's §2.2 target).

The wasmer SDK's "oneshot canceled" worker race fired on the first Snailiad
attempt (after two internal retries) and is unrelated to this work — rerun in
a fresh page.

**5. Pages deploy.** `deploy-pages.yml` run `33714844540` at `39ad765df`. (Only `pipeline.js` is tracked under `docs/recompiler/`;
`SWFRecomp.wasm`, `bundle/` and `host/` are gitignored and rebuilt by the
workflow.)

## Residuals / notes

- **The target is per-CHUNK bytes, not a chunk count.** The measured sweet
  spot was ~1.5 MB, which is what the page uses; nothing in the emitter
  hard-codes it. A chunk closes as soon as it REACHES the target, so chunks
  run slightly over it and the last one runs under (Snailiad: eighteen at
  1.43–1.45 MiB, one at 831 KB, plus two outliers at 1.84 and 2.06 MiB, where the method that
  closed the chunk was itself large — the split cannot subdivide a method).
- 1717.5 s for Snailiad is one clang invocation over 34 TUs, so it is not a
  wall we can push much further by chunking alone: at 1.5 MB the methods are
  already ~21 MB of the 216 MB of C, and `abc_timeline.c` (28.16 MB) and
  `draws.c` are single TUs the split does not touch. The next lever is
  emitting less C, not smaller C — §2.2.
- Not done here (and not asked for): making the mode the NATIVE default.
  Native gcc handles the giant TUs fine and multiple TUs would only help a
  parallel build; the `recompiler-giant-function-gcc-ice` guard now HAS this
  lever if a giant TU ever ICEs, but nothing currently needs it.
