# Slice: does the loaded-child arc reach the browser at all?

**Baseline: `master` at the commit that adds this file.** CLAUDE.md and this
project's memory are auto-loaded — the launch protocol, the CI pipeline
(`.claude/pipeline-handoff.md`) and the standing traps come from there, don't
re-derive them.

**Corpus baseline: diff against results commits `21a6270ce` (graphics) and
`d9cf90aff` (no-graphics) — read the numbers off `origin/ruffle-test-results`
yourself, do not quote a figure from this brief.** The graphics total is
intermittent-dependent by ±1 at the same code and a diff's intersection is not
the corpus total; memory `ci-baseline-must-be-read-fresh` has both mechanisms.

## 1. Why this slice, and what makes it worth a session

Ten slices made loaded child movies work: char ids re-based by the recompiler,
embedded assets reachable, timelines that advance and loop, and a full render
path (shapes, bitmaps, static text, morphs) — all verified **natively**.

This project's deployment target is the browser. **Nobody has checked whether
any of that reaches browser-WASM**, and the BACKLOG's own framing assumes it
does not: "Browser-WASM does not re-base a loaded movie's placement ids…
inert rather than wrong, and **moot until browser-WASM advances a loaded movie
at all**."

That assumption is worth testing, because a quick read suggests it may be
wrong. `actionAdvancePlayingLevels` is called at
`SWFModernRuntime/src/libswf/swf.c:1263`, inside `tagMain` (which begins at
`:394`); that call is **not** inside an `__EMSCRIPTEN__`-gated arm — the last
preprocessor directive above it is an `#endif` at `:1188` — and there is **no**
`emscripten_set_main_loop` in `swf.c` at all, so the browser drives `tagMain`
from JS rather than through a separate frame body. If that reading holds, the
browser may already advance loaded movies and the "moot" premise is false.

**This is a grep-level reading and I have not run anything.** Treat it as a
hypothesis to test, not a finding — and note that whoever wrote the BACKLOG
entry may have had evidence I don't.

**Either answer is valuable**, which is what makes this a good slice rather than
a gamble:
- If the browser already advances and renders loaded children, the "moot" entry
  is wrong, the placement re-base becomes live work rather than inert, and ten
  slices of value are confirmed reachable by the real target.
- If it does not, you have found the gap that separates all of that work from
  the product, and closing it is worth far more than the small items it was
  competing with.

## 2. Step one is a measurement, and it may be the whole slice

Build a browser-WASM demo whose parent `loadMovie`s a child that exercises what
the arc fixed: a **multi-frame** child (does it advance? does it loop?) that
places a shape, a bitmap and some static text (do they render? with the child's
own geometry or the root's?). Observe it in a browser and write down what
actually happens, feature by feature.

Say plainly which of the ten slices' behaviours survive the trip and which do
not. That table is the deliverable even if you fix nothing.

**If the gap is large, report it and stop.** Scoping a browser-parity sub-arc is
a legitimate outcome and is worth more than a half-closed gap. If it is small,
close it.

## 3. The one concrete gap already filed

Several `ng_cache_transform` call sites sit behind
`#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)`, so the placement
re-base does not happen in the browser *graphics* build (that gate appears 62
times in `tag.c`; `ng_cache_transform` itself is at `:209` with call sites
around `:9002`, `:9067`, `:9239`, `:9305`). The BACKLOG calls this inert — an
un-re-based id keeps indexing the root rows it indexed before — which is true
only while nothing else about a loaded child works in the browser. **If step one
shows the browser does advance and render loaded movies, this stops being inert
and becomes a live wrong-row bug.** Check that implication explicitly.

## 4. Traps

- **WSL/WSLg Chrome is SwiftShader.** Fine for functional and
  rendering-correctness probes, which is all this slice needs. **Never** for
  frame rates or performance comparisons — every "gap" it shows is an artifact
  (CLAUDE.md; memory `windows-playwright-from-wsl` has the real-GPU recipe if
  you ever need one).
- **The `:8010` server serves `docs2/`**, so `/recompiler/` and
  `/docs/recompiler/` both 404 on it. Serve the repo root on a fresh port and
  check `readlink /proc/<pid>/cwd` plus the actual path before believing a
  "still broken" browser result — a previous session wrote up a misread of this
  as fact.
- **Browser-WASM has its own standing quirks**, several of which could confound
  a loaded-child probe. Read these memories first rather than rediscovering
  them: `removemovieclip-noop-browser-wasm`, `browser-wasm-xmouse-root-only`,
  `browser-wasm-perframe-dump-freezes-page` (a per-frame dump freezes the page —
  do not instrument that way), `browser-wasm-processtimers-pump`,
  `browser-wasm-loop-dies-on-quit-swf`, and `browser_wasm_frame_func_rerun`.
- **CI's `wasm-link-smoke` job covers link/compile breakage only** — it compiles
  and links one trace-WASM and one browser-WASM demo and never executes them
  (`.claude/pipeline-handoff.md`). Behavioural checks are manual browser smoke;
  do not read a green CI as evidence this slice worked.
- **`compile_wasm` gained AVM2 support only on 2026-09-04** (`14e8eae5c`).
  Before that an AS3 test silently built as an AVM1 movie tracing nothing while
  reporting `WASM_BUILT`. Any pre-dated wasm result may not mean what it says.
- **Dispatch the two CI modes SERIALLY**, and never run a status-poll loop
  alongside a live `gh run watch`. The watcher has now been killed on three
  consecutive slices (OOM twice, secondary rate limit once); the documented
  zero-quota fallback is in `.claude/pipeline-handoff.md`. Use it and say so.
- **`from_shumway/as3-loader/bug1157243/empty` is a known load-sensitive
  intermittent**, adjudicated with 472 local runs. Do not re-derive it.
- **`single_test` resolves the bare name against `tests/swfs/avm1` ONLY.**
- **Never run full test suites locally** (CLAUDE.md). Individual tests only.
- **`git stash` is shared across this repo's worktrees.** Byte-identity checks
  use a patch file: `git diff -- <dir> > p.patch; git apply -R p.patch`.
- **`verify_output.py` compiles generated C with `-w`.** Sweep new emitted C with
  `gcc -fsyntax-only -Werror=return-type -Wall`.

## 5. What "done" is

1. A written, observed answer to "which of the loaded-child behaviours reach
   browser-WASM" — feature by feature, from a running browser, not from reading
   `#ifdef`s.
2. The §1 hypothesis confirmed or refuted, and the BACKLOG entry corrected
   either way; if the "moot" premise falls, the placement-re-base entry needs
   rewriting from inert to live.
3. Whatever gap you closed, closed completely, with the rest specified.
4. **If you changed shared runtime code: trace CI corpus-clean in BOTH modes**,
   serial, `images=false`, diffed against the commits named at the top. If you
   changed only browser-gated code, say so and explain why the corpus cannot
   see it — that is a legitimate report, not a missing check.
5. Durable records: closeout under `SWFRecompDocs/status/`, BACKLOG updated,
   memories updated.
6. Commit and push to `master` (no branch — trunk-based), standard trailer.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
