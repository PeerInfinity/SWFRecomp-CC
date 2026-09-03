# Slice: close the two residuals the in-browser arc left behind

You are starting a fresh session on SWFRecomp-CC at `master`. **Baseline: `799f57092`.**
CLAUDE.md is auto-loaded; it authorises commit/push/CI/Pages deploy. Work in this tree —
the Ruffle-test fan-out convention is for corpus sessions only, not this one.

This is a **hardening slice**, not a feature. Three emission options shipped in the last
three sessions (`try_helper`, `tu_split`, `skip_avm1_payload`), each off by default and
each corpus-verified. They left exactly two loose ends, both recorded in their closeouts.
Neither breaks anything today; both are the kind of thing that bites a session weeks
from now. Fix both, in this order.

Read first:
1. `SWFRecompDocs/status/avm2-dead-payload-skip.md` §"Residuals / notes" (the seam, in
   the author's own words) and its §"Where the option lives" for how `dropPayload()` is
   wired.
2. `SWFRecompDocs/status/avm2-tu-split-emission.md` and
   `SWFRecompDocs/status/avm2-try-helper-emission.md` — for the option pattern, the
   `.recomp_mode` stamp, and the publish-guard history.
3. `.github/workflows/ruffle-tests.yml`: the two publish guards (search
   `if: always() && inputs.extra_defines`) and the `env:` block that maps each input to
   its `SWF_*` env var.

---

## Residual 1 — the `is_as3` gate is not "will run under AVM2"

`SWF::dropPayload()` is `skip_avm1_payload && is_as3`. Those two predicates come apart
in exactly one configuration: **an AS3 SWF loaded as a child by an AVM1 parent.** The
AVM1 loader calls a child's `init_func` (= its `tagInit`) — see `entry->init_func` at
five sites in `SWFModernRuntime/src/actionmodern/action.c` — so with the option on, such
a child would silently lose its AVM1-side bitmap/sound dictionary. No corpus test is in
that shape today, which is why it shipped as a documented seam rather than a bug.

**Goal: make the gate correct, and get a test into the corpus that proves it.**

The test is the more valuable half. Right now nothing anywhere would catch a regression
here, so the fix would be unfalsifiable. Build a `ruffle-tests/tests/swfs/regression/`
test (see that suite's `README.md`; custom tests go THERE, never in the upstream
mirrors) in the shape "AVM1 parent loads an AS3 child that has a bitmap and/or sound
payload, and something observable depends on the child's AVM1-side dictionary". Raw
material: `ruffle-tests/tests/swfs/from_shumway/as3-loader/` already has AS3
parent+child pairs (`LoaderTest/Loadee.swf`, `LoaderTest2/Loadee2.swf`); MTASC at
`~/CC/mtasc/` builds the AVM1 parent (CLAUDE.md has the invocation). **The test must
FAIL with `SWF_SKIP_AVM1_PAYLOAD=1` on the current code and pass after your fix** —
show both, that is the deliverable.

Candidate fixes, in rough order of how cheap they look — pick one and justify it:
- **Never drop for a child recompile.** A child is recompiled separately with a
  non-empty `symbol_prefix` / `char_id_base` (`recompile_child_swf` in
  `verify_output.py`), so `dropPayload()` could additionally require
  `avm2_symbol_prefix.empty()`. Cheap, fail-safe, and costs only the (rare, small)
  child payloads.
- Gate on something that actually means "this SWF's tagInit will never run".
- Keep emitting for children but let the AVM1 loader tolerate the absence.

Whichever you choose, say in the closeout what it costs and what it now guarantees.

## Residual 2 — the publish guard is an ever-growing `&&` chain

```
if: always() && inputs.extra_defines == '' && inputs.single_test == ''
    && inputs.try_helper == '' && inputs.tu_split == '' && inputs.skip_avm1_payload == ''
```
Three slices in a row each had to append a clause, and each learned about it the same
way (memory `ci-verify-run-results-clobber`). The chain is duplicated across **two**
steps. The failure mode is silent and expensive: a run whose binaries behave differently
force-pushes its numbers over `results_graphics.json` and poisons the
`{STEM}_previous.json` baseline the NEXT run diffs against.

**Goal: make forgetting impossible, or at least fail-safe.**

The design constraint that matters more than tidiness: **a newly added emission option
that nobody wires into the guard must default to NOT publishing.** A generalised
`||` expression is no better than the `&&` chain if it still has to be edited by hand.

One idea worth evaluating (not a mandate): `verify_output.py` already writes a
`.recomp_mode` stamp — currently `try_helper=<0|1> tu_split=<n> skip_avm1_payload=<0|1>`
— and a new option *has* to be added there or its own recompile caching breaks. That
makes the stamp the one place that cannot be forgotten. If the publish step gated on
"the stamp equals the all-defaults string", adding an option would wire the guard
automatically. Check whether the stamp is reachable from the publish job (it is written
per test dir, and the publish runs in `combine-results` — so it may need lifting to a
job output or artifact) and whether that is worth the plumbing versus a simpler
computed `env`. Either way, leave a comment at the guard saying what a future option
author must do.

Verify the guard still behaves: a default run publishes; a run with a non-default
emission input does not. You can prove the second cheaply — dispatch one non-default run
and confirm `origin/ruffle-test-results` does not move (that is exactly how the last
three slices confirmed it).

---

## Verification

- Native default output byte-identical (residual 1 changes `dropPayload()`, which is
  reachable only with the option ON — confirm that, don't assume it). Recipe from the
  prior closeouts: `git diff -- SWFRecomp > p.patch; git apply -R p.patch`, rebuild,
  recompile a mixed set, restore, rebuild, recompile, `diff -r`. **Not `git stash`** —
  it is shared across this repo's worktrees.
- The new regression test passes, and demonstrably fails without your fix.
- One corpus run: `ruffle-tests.yml`, `mode=graphics`, `categories=full`, default
  (option off). Zero regressions per `scripts/corpus_status_diff.py`. A forced-on run
  is worth it too if residual 1's fix changes what forced-on emission produces — you
  now have a test that covers the seam, so this run is what proves the fix holds
  corpus-wide.
- `verify_output.py` compiles generated C with `-w` and cannot see a malformed
  declaration; if you emit anything new, sweep the generated C with
  `gcc -fsyntax-only -Werror=return-type -Wall` yourself.

## Done means

Both residuals closed; a regression test in the corpus that would have caught residual 1;
the guard fixed such that a future option author cannot silently poison the baseline;
corpus green with zero regressions; a short closeout under `SWFRecompDocs/status/`; the
"Residuals / notes" bullet in `avm2-dead-payload-skip.md` updated from "worth
remembering" to what actually happened; memory updated (`ci-verify-run-results-clobber`
in particular — its "How to apply" should describe the new mechanism, not the old
chain); commit pushed. No Pages deploy needed unless you touch `docs/`.

If either residual turns out to be bigger than it looks — particularly if the seam fix
needs runtime changes rather than a recompiler-side gate — do the other one, write up
what you found, and say so. A well-characterised "this is actually a 2-day change
because X" is a good outcome here; a half-applied fix is not.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
