# Slice: the browser's ROOT-side gaps — `_root._currentframe`, and `typeof` a bare shape

**Baseline: `master` at the commit that adds this file.** CLAUDE.md and this
project's memory are auto-loaded — the launch protocol, the CI pipeline
(`.claude/pipeline-handoff.md`) and the standing traps come from there, don't
re-derive them.

**Corpus baseline: diff against results commits `23c37af72` (graphics) and
`195ea700a` (no-graphics) — read the numbers off `origin/ruffle-test-results`
yourself, never quote a figure from a brief.** Memory
`ci-baseline-must-be-read-fresh` has both reasons.

Read `SWFRecompDocs/status/browser-wasm-loaded-child-parity.md` first — it built
the harness you will reuse (`tools/browser-test/child_probe/`) and it filed the
two gaps you are taking.

## 1. What you are chasing, and why it is ahead of the MCL probe

The previous slice made browser-WASM load, advance and render child movies — 17
arc behaviours measured reaching the browser, four fixtures pixel-identical to
their Ruffle goldens. In passing it found two defects it did **not** fix, and
noted both are **root-side**: the child half of each fixture was correct.

- **`_root._currentframe` reads `undefined` in the browser.** The
  `swf.c:585-608` sync is `OFFSCREEN_RENDER`-gated, but that would yield **0**,
  not `undefined` — so the gating is not the whole story and the owner is
  unidentified.
- **`typeof` a root-placed named bare `DefineShape` is `object`, not
  `movieclip`.**

Its own recommendation was to probe `MovieClipLoader.loadClip` in a browser
build next — the one arc behaviour that is code-complete but unprobed there.
That is a good item and it is queued behind you. **I put these first because
they are root-side**: `_currentframe` is ubiquitous in real Flash content, so if
it is `undefined` for every SWF in the browser rather than only in that probe's
shape, it is a live defect in the deployment target affecting all content — a
different order of problem from a completeness gap in one loader API.

**That "if" is the first thing to settle**, and it is cheap: does
`_root._currentframe` read `undefined` in the browser for an ordinary
single-movie SWF with no loaded child at all? If yes, this is browser-wide and
the slice is worth its session several times over. If it is somehow specific to
the probe's construction, say so and drop to the MCL probe instead — that is a
legitimate pivot, not a failure, and it is why this step comes first.

## 2. Method

The harness exists: `tools/browser-test/child_probe/`. Reuse rather than rebuild.

`undefined` rather than `0` is the useful clue. A gated sync that never runs
leaves a field at its initial value; `undefined` in AVM1 means the *property
lookup* did not resolve — a different failure. Chase what `_currentframe`
resolves through on the root in a browser build before assuming the `:585-608`
gate is the cause. The previous slice was explicit that it had not identified
the owner, so treat the gate as a lead, not a diagnosis.

For the `typeof` gap: `movieclip` vs `object` for a root-placed bare
`DefineShape` is a display-object-identity question, and this repo has prior art
— memory `nonscriptable_display_objects` and `instance-name-variable-deconflation`.
Read them before designing a fix.

## 3. Grading

- **A fixture in `ruffle-tests/tests/swfs/regression/` for each gap you fix**,
  with rows that flip on revert. If a gap is browser-only and the corpus cannot
  see it, say so explicitly and grade it in the browser harness — that is a
  legitimate report, not a missing check.
- **`cpp -P` is the arbiter for anything preprocessor-shaped, not grep.** My
  last brief asserted a `#endif` closed an `OFFSCREEN_RENDER` block when it
  closed an inner one; the enclosing block ran ~300 lines further. `cpp -P
  -D__EMSCRIPTEN__` settled it in one command. Count the *browser's* call sites
  before treating a gate as a gap — six of seven gated sites in the last slice
  were in blocks the browser never executes, and the browser had its own
  parallel arms that already did the work.
- **Pillow's `getbbox()` on an RGBA image is ALPHA-ONLY.**
  `ImageChops.difference(a,b).getbbox()` returns `None` for any two opaque
  images and will report a 7200-pixel-wrong render as pixel-perfect. Use
  `tools/browser-test/child_probe/pixcmp.py`, which does it correctly.
  (I audited the rest of the repo: the CI image path uses no `getbbox`, and
  `tools/divergence/glyph_compare/compare_both.py` converts to RGB first, so
  nothing else is affected — but do not reintroduce it.)
- **A Playwright screenshot of the WebGPU canvas is blank white under WSLg**
  while the page renders correctly; the GPU readback of the same frame shows the
  real image. The previous slice nearly wrote up "nothing renders in the
  browser" because of it. Do not trust a canvas screenshot as evidence of
  absence.

## 4. Traps

- **A RED `wasm-link-smoke` IS evidence**, even when your change is
  preprocessor-identical in both CI test modes. That job builds the BROWSER
  config on every dispatch, any mode. Last slice proved cpp-invariance and
  wrongly concluded CI could not see its change; the link smoke then caught a
  real break — `wasm-ld` had been dropping `actionFirePendingDirectLoads` as
  unreachable, which had silently hidden that `build_test.sh --graphics` was
  missing `image_decode.c` / `video_codec.c` / `stb_image_impl.c`.
  **cpp-invariance justifies PREDICTING a flat corpus, never skipping the
  dispatch.**
- **WSL/WSLg Chrome is SwiftShader** — fine for functional and
  rendering-correctness probes, never for performance (CLAUDE.md).
- **The `:8010` server serves `docs2/`** — `/recompiler/` and
  `/docs/recompiler/` both 404 on it. Serve the repo root on a fresh port and
  check `readlink /proc/<pid>/cwd` before believing a "still broken" result.
- **Browser-WASM quirks that could confound a root probe**, read first:
  `removemovieclip-noop-browser-wasm`, `browser-wasm-xmouse-root-only`,
  `browser-wasm-perframe-dump-freezes-page` (a per-frame dump freezes the page —
  do not instrument that way), `browser-wasm-processtimers-pump`,
  `browser-wasm-loop-dies-on-quit-swf`, `browser_wasm_frame_func_rerun`.
- **Dispatch the two CI modes SERIALLY**; never run a status-poll loop alongside
  a live `gh run watch`. The watcher has been killed on three consecutive slices;
  the zero-quota fallback is documented in `.claude/pipeline-handoff.md`.
- **`from_shumway/as3-loader/bug1157243/empty` is a known load-sensitive
  intermittent** — do not re-derive it.
- **`single_test` resolves the bare name against `tests/swfs/avm1` ONLY.**
- **Never run full test suites locally** (CLAUDE.md). Individual tests only.
- **`verify_output.py` compiles generated C with `-w`.** Sweep new emitted C
  with `gcc -fsyntax-only -Werror=return-type -Wall`.
- **`git stash` is shared across this repo's worktrees.** Byte-identity checks
  use a patch file: `git diff -- <dir> > p.patch; git apply -R p.patch`.

## 5. Scope

Settle §1's scoping question, then fix what you can. **If `_currentframe` turns
out to be browser-wide, that alone is the slice** — it is worth more than both
gaps half-done. If both gaps close comfortably, fold in the previous slice's
recommendation: a `MovieClipLoader.loadClip` browser probe, a fixture shaped
like `avm1_child_timeline_advance` but driven by `loadClip`/`onLoadInit`. Do
that only if the first two are genuinely finished.

## 6. What "done" is

1. `_root._currentframe`'s scope established by measurement (browser-wide, or
   specific), the owner identified, and it fixed — or a clear statement of what
   it needs and why you stopped.
2. The `typeof` gap fixed or specified.
3. Fixtures for what you fixed, rows flipping on revert.
4. **Trace CI corpus-clean in BOTH modes**, serial, `images=false`, diffed
   against the commits named at the top; quote the histogram. Dispatch even if
   you predict it flat.
5. Durable records: closeout under `SWFRecompDocs/status/`, BACKLOG entries
   struck or rewritten, memories updated.
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
