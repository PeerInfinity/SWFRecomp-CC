# Slice: a loaded child's bitmaps — the char lookup and the renderer's range

**Baseline: `master` at the commit that adds this file.** CLAUDE.md and this
project's memory are auto-loaded — the launch protocol, the CI pipeline
(`.claude/pipeline-handoff.md`) and the standing traps come from there, don't
re-derive them.

You are implementing **one slice** of the Multi-SWF (loaded children) arc. Read
`SWFRecompDocs/status/child-placed-clip-uninit.md` first — it is the immediate
predecessor, and §4 below carries two traps it paid for.

**Current corpus baseline: 4362 effective (graphics) / 4363 (no-graphics) at
4487 graded.** Do not use the 4360 figure that appears in older briefs; an
upstream test sync moved it.

## 1. The work: two halves of one family

**Half A — `embedded_bitmap_for_char` never consults child movies.**
`SWFModernRuntime/src/avm2/avm2_bitmap.c:757` looks the character up in the main
movie only, unlike `char_info` and `timeline_for_char`, which both consult
`g_child_movies`. So a loaded AVM2 child's `[Embed]`ed image instantiates as a
BitmapData subclass reporting **0x0**, where the same SWF loaded as the MAIN
movie reports 4x3. The repro fixture is already committed. The predecessor
called this a six-line fix; treat that as a hypothesis, not a measurement.

**Half B — a loaded child's bitmaps never reach the renderer.** Two gates, both
stated in the ROOT movie's terms: `finalizeBitmaps()` is emitted at the end of
the root's `tagInit`, so `render_webgpu_upload_bitmap` early-returns on
`bitmap_static_built`; and the static slot table is sized by the root's
`BITMAP_COUNT` (`ctx->current_bitmap >= ctx->bitmap_count`). A child's
`defineBitmap` calls are therefore dropped. This is a missing feature, not a
corrupt read — and the registry now stores per-bitmap pointers (`ctx->bitmap_ptrs`)
rather than root-relative offsets, so lifting the gates cannot re-inherit the
wrong-array bug that motivated that change. What is left is giving the renderer
a **per-movie static-bitmap range**.

**Take them together.** That is what makes half B gradeable: image comparisons
never gate trace pass/fail in this project (memory
`image-comparisons-dont-gate-passfail`), so the renderer half has no trace signal
of its own — but half A's 0x0-vs-4x3 does, and a child bitmap that reaches the
renderer is a child bitmap whose dimensions the AS side can read. Three
consecutive sessions have independently recommended this pairing.

## 2. The question to get right, because the last two slices each turned on it

**Which movie keys the lookup: the one that DEFINED the character, or the one
whose TAG placed it?** Getting this backwards is now the arc's signature bug.

The predecessor hit it directly: it needed the **placing** movie for transform
ids, and deliberately did *not* reuse the existing `DisplayObject::child_transform_data`,
which is keyed on the **defining** movie. The two disagree for imported
characters — `ng_shared.c` copies the child's movie id onto the local char id at
`tagImportCharacter`, but the parent's tag supplies the transform id. Reusing the
wrong one would have broken `import_assets` / gnash `attachImported` while fixing
the bug in front of it. `import_assets` is 3/3 in CI and is the check that caught
it; see `SWFModernRuntime/include/libswf/swf.h:290` for the comment that now
documents the distinction.

For bitmaps the answer is probably the **defining** movie — a bitmap belongs to
the movie that defined it — which is the *opposite* of the transform case.
Establish it rather than assuming it, say which you concluded and why in the
closeout, and **keep `import_assets` and the gnash import tests in view** as the
canary either way.

## 3. Traps

- **A loaded child's timeline never advances past frame 0.** The predecessor
  gdb-verified this: `actionFirePendingDirectLoads` runs `child_frame_0` and
  nothing ever calls `child_frame_1`, so every tag past a child's first frame is
  dead. It silently voids any multi-SWF fixture whose signal lives later.
  **Put everything your child fixtures read in frame 1.** It is filed in BACKLOG
  §Multi-SWF and memory `loaded-child-timeline-stuck-frame-0`; it is NOT yours to
  fix — it is the next slice.
- **There are TWO child-recompile loops** in `ruffle-tests/verify_output.py` —
  `compile_native`'s at :2364 and `compile_wasm`'s at :2887. If you touch child
  recompilation, touch both; the second one has already been missed once.
- **`images=false` stays.** Per CLAUDE.md, `images=true` is a deliberate render
  baseline run, not a per-change default, and image comparisons never gate
  trace pass/fail. If you want visual confirmation of half B, that is a local
  check or a deliberate follow-up run — say so rather than flipping the
  per-change default.
- **The bitmap texture pools are size-classed** (memory `bitmap-texture-pools`:
  12 size-class pools replaced the widest×tallest array). A per-movie range that
  assumes a flat root-sized array will fight that design — read it before
  sizing anything.
- **ASan has been blind to this project's real heap bugs before** (memory
  `graphics-sigabrt-real-heap-bugs`). Don't conclude "no bug" from a clean
  sanitizer run.
- **`verify_output.py` compiles generated C with `-w`.** Sweep any new emitted C
  with `gcc -fsyntax-only -Werror=return-type -Wall`.
- **A recompiler change needs a manual cmake rebuild** before `verify_output.py`
  reflects it; `--recompile` avoids a stale `RecompiledABC` false compile-fail.
- **Local graphics verification hits stale caches** (memory
  `local-graphics-fix-verify-stale-caches`). Local Dawn install at
  `~/CC/dawn-install` or `DAWN_INSTALL`.
- **Never run full test suites locally** (CLAUDE.md). Individual tests only.
- **`git stash` is shared across this repo's worktrees.** Byte-identity checks
  use a patch file: `git diff -- <dir> > p.patch; git apply -R p.patch`.
- **`gh` shares a 5000/hr rate limit across every session on this box**, and the
  secondary limit returns 403 while `gh api rate_limit` still shows core quota.
  API-free fallback: poll `git fetch origin ruffle-test-results` and read the run
  id out of the publish commit message (the no-graphics publish commit is titled
  plain "Update Ruffle test results", no `(mode=...)` suffix). A merge conflict
  on `regression/_results/results.json` from a locally-generated copy resolves
  `--theirs`.
- **This box is shared.** Load average has hit 25 from unrelated sessions. Don't
  run two heavy jobs in parallel, and don't read a slow build as a broken one.

## 4. What "done" is

1. Half A fixed, with the committed repro fixture reading the child's real
   dimensions instead of 0x0.
2. Half B: the renderer takes a per-movie static-bitmap range, a child's
   `defineBitmap` calls are no longer dropped, and there is a **trace-visible**
   assertion that a child bitmap reached the renderer — not only an image.
   If half B turns out to be a genuinely larger job than half A implies, ship
   half A cleanly, say what half B needs, and stop. A half-landed renderer
   change is worse than a clean single-half slice.
3. The defining-vs-placing ruling stated and justified, with `import_assets` and
   the gnash import tests confirmed unmoved.
4. **CI corpus-clean.** `mode=graphics` is required (half B is renderer code);
   `categories=full` per CLAUDE.md since this touches AVM2 runtime; `images=false`.
   Dispatch `no-graphics` as well if half A's change sits in code that is not
   graphics-guarded — when in doubt for shared runtime code, run both. Verify with
   `scripts/corpus_status_diff.py --stem results_graphics <baseline> <new>` (and
   `--stem results` for no-graphics) and quote the histogram, not a headline
   number. A completed-but-failing run is a result to report, naming pass→fail
   regressions.
5. Durable records: a closeout doc under `SWFRecompDocs/status/`, the two BACKLOG
   entries struck or rewritten to what remains, and memory
   `child-bitmap-registry-and-offset-audit` updated — it currently teaches that
   child bitmaps "still never RENDER", which your slice is meant to make false.
6. Commit and push to `master` (no branch — trunk-based), standard trailer.

After this the arc's remaining items are the loaded-child frame-0 timeline (the
next slice, and the largest of them), `flashbang_upload_bitmap`'s unverified fix
— entangled with the standing "delete or fold flashbang into render_webgpu.c"
question, which is worth settling before investing in testing it — and the
dictionary constant-vs-`dictionary_capacity` divergence, which is self-contained
and only worth doing when something needs a stride above 1000.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
