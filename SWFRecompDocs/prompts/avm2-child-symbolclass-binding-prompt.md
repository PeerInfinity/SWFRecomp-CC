# Slice: a loaded AVM2 child's TIMELINE-placed characters get their SymbolClass class (`avm2/loader_duplicate_class`)

**Baseline: `master` at the commit that adds this file.** CLAUDE.md and this
project's memory are auto-loaded — the launch protocol, the CI pipeline
(`.claude/pipeline-handoff.md`) and the standing traps come from there; don't
re-derive them.

**Corpus baseline: diff against results commits `ae28d1ae1` (graphics) and
`c184410f4` (no-graphics, the 2026-09-06 weekly canary, merged in `f9e9c12ae`
and confirmed flat against its predecessor). Read the numbers off
`origin/ruffle-test-results` yourself; never quote a figure from a brief.**
Memory `ci-baseline-must-be-read-fresh` has both reasons.

This is one slice, one session. A second slice (AVM1 `MovieClipLoader` leaves
the holder's `_totalframes` at 1) is queued behind you, and the launching
session will start it after your report. **Do not take it on.**

## 1. What you are fixing, and what is already known

`avm2/loader_duplicate_class` is at **32/48** (`output_mismatch`) in both modes.
Session 18's loader lane improved it from 3/48 and then **diagnosed the rest
without fixing it**. Read its §5.1 first:
`SWFRecompDocs/plans/session18-fanout-reports/w2-avm2-loader-report.md`. In short:

- `loader_domain_child.swf`'s root is `loader_domain_child_fla::MainTimeline`,
  and its frame-1 child is a character bound by `SymbolClass` to
  `DuplicateClass`. We instantiate that character as a bare
  `flash.display.MovieClip`. So (a) the `DuplicateClass` constructor, which
  prints `this.childFromDomainChild = ...` / `Child name: ...`, never runs, and
  (b) assigning the bare clip to `MainTimeline`'s compiler-generated
  `DuplicateClass`-typed field throws `#1034`.
- `new DuplicateClass()` **from script** in the same child works
  (`clip = [object DuplicateClass]`). The class resolves fine in the child's
  domain. **Only the timeline-placed character misses its binding.**
- Missing expected rows: exp 4, exp 5, and exp 19
  (`this.childFromOtherDomain = [object MovieClip]`).
- The report's proposed direction: have the per-character class lookup consult
  the **placing movie's** `symbol_classes` table (the child's `Avm2MovieTables`),
  the way `loader_boot_child_swf` already does for the loaded ROOT's binding (it
  cited `avm2_display.c:5859-5900` in session 18; re-find it, line numbers move).
  Its predicted payoff was the full 48/48. **Treat that as a lead to test, not a
  diagnosis.** Session 18 did not implement it.

This is the last open mechanism of the multi-SWF arc's "MAIN-only symbol map"
family. The same seam was closed three times already, and each closeout is prior
art for where the lookups live and how they fall through to `g_child_movies`:
- `SWFRecompDocs/status/child-embedded-asset-lookup.md`: embedded
  bitmap/ByteArray/Sound. Each needed **two** fall-throughs. Its ruling that a
  payload keys on the **defining** movie is the useful contrast here.
- `SWFRecompDocs/status/avm2-child-render-arm.md`: `char_for_class` →
  `avm2_display_child_char_for_class` for a child's own `new Art()`. That is the
  class→character direction. **Yours is the reverse, character→class, on the
  timeline-placement path.**
- Memories `child-bitmap-registry-and-offset-audit` (which names this test as
  still blocked), `avm2-child-movie-tables`, `avm2-child-render-arm`.

## 2. The trap the test's name is warning you about

The test is called *duplicate* class, and it bundles **two** child SWFs
(`loader_domain_child/` and `loader_domain_other_child/`) plus a
`loader_same_domain/`. Read `Test.as` and the children's sources before
designing anything. Two movies probably define a class with the **same name**
in **different ApplicationDomains**. If so, any binding keyed on the class
**name**, or on a single global table, will bind both placements to whichever
class registered first. That could pass one of exp 4/5 while breaking exp 19,
or the reverse. Expect the right key to be (movie or domain, character id) →
class, resolved in the domain of the movie that **placed** the character.
Confirm that against Ruffle (`~/CC/ruffle`, `core/src/avm2/` and the
SymbolClass handling in `core/src/display_object/movie_clip.rs`) rather than
assuming it.

## 3. A known conflict on the same line

`SWFRecompDocs/plans/session11-fanout-reports/w2-display-singles-report.md`
(around its line 245) records that a **Shape gate** was deliberately written as
a separate `if` on the `char_id` variable next to `char_for_class(obj->cls)`, so
that it survives a later swap of that lookup. If your change touches that site,
**keep the Shape gate applied to whichever lookup's result is used.**

## 4. Grading

- The corpus test is the primary grade: 32/48 → 48/48 in **both** modes, with
  the changed rows attributed. Revert your change and confirm those rows move
  back. If it lands short of 48, say exactly which rows remain and why.
- **Local canary before any CI** (individual tests only, `-P 5` is safe; see
  memory `verify-output-parallel-batching`): every `avm2/loader_*` and
  `avm2/loaderinfo_*`, `avm2/delayed_symbolclass`,
  `avm2/simplebutton_symbolclass`, `mixed_avm/*`, `from_shumway/as3-loader/*`,
  the `import_assets` suite, and the **whole `regression` suite**, which
  includes the `avm2_parent_child_*` fixtures. Diff ACTUAL output against a
  pre-change run, not just status (memory `local-regression-sweep-stash-diff`).
- Add a `regression/` fixture only if your fix has a behaviour the corpus test
  does not discriminate, e.g. the two-domain case if `loader_duplicate_class`
  turns out not to grade it on its own. If you add one, write rows that flip on
  revert.
- **CI:** this is AVM2 runtime code, so use `categories=full`, `images=false`.
  Run **both** modes, **serially**: graphics first, then no-graphics. Read each
  with `scripts/corpus_status_diff.py <pre_merge_sha> WORKTREE --per-suite`
  (`--stem results` for no-graphics). Expected: +1 effective in each mode and
  zero regressions. Report any other movement by name.

## 5. Traps

- **A RED `wasm-link-smoke` IS evidence.** That job builds the BROWSER config
  on every dispatch, whatever the mode.
- **`from_shumway/as3-loader/bug1157243/empty` is a known load-sensitive
  intermittent** (±1 on the graphics total at the same code). It is in your
  canary set, so do not re-derive it.
- **`single_test` resolves the bare name against `tests/swfs/avm1` ONLY**, so a
  `single_test=loader_duplicate_class` dispatch "fails" on path lookup.
- **Never run full test suites locally** (CLAUDE.md). Individual tests only.
- **`verify_output.py` compiles generated C with `-w`.** If you touch the
  recompiler, sweep new emitted C with
  `gcc -fsyntax-only -Werror=return-type -Wall`. A recompiler change also needs
  a manual cmake rebuild and `--recompile` (memory
  `stale-recompiledabc-false-compile-fail`).
- **`git stash` is shared across worktrees.** Byte-identity checks use a patch
  file: `git diff -- <dir> > p.patch; git apply -R p.patch`.
- Pattern kills are guard-denied. Use literal PIDs (memory `pkill-f-self-match`).
- Dispatch CI modes serially, and never run a status-poll loop alongside a live
  `gh run watch`. The zero-quota fallback is in `.claude/pipeline-handoff.md`.

## 6. Done means

1. Closeout doc `SWFRecompDocs/status/avm2-child-symbolclass-binding.md`:
   mechanism, the key the binding uses and why, revert attribution per row, the
   canary table, and both CI run IDs with their corpus deltas.
2. `SWFRecompDocs/plans/polish-sweep-arc.md` §19.4: mark the
   `loader_duplicate_class` line landed, or corrected if it didn't. Also update
   the BACKLOG §Multi-SWF text if your finding changes anything there.
3. Memory: update `child-bitmap-registry-and-offset-audit` (it says this test is
   still blocked) and add anything non-obvious you learned.
4. Commit and push to `master`, CI both modes per §4, merge
   `ruffle-test-results`, and report any regressions by name.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
