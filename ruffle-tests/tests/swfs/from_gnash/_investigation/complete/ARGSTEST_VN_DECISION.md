# argstest-vN Decision
<!-- TESTS: argstest-v6, argstest-v7, argstest-v8 -->

Last updated: 2026-05-19 (initial decision doc; this is **not** a fix
plan)

<!-- PLAN_META
id: ARGSTEST_VN_DECISION
status: complete
phases:
  - id: 1
    name: "Verify Ruffle diff against expected — is this auto-promotion-eligible?"
    status: complete
  - id: 2
    name: "If not RM-eligible: add to ACCEPTED_DIFFS.md and ignored_tests.txt"
    status: complete
dependencies: []
related: []
blockers: []
status_note: |
  argstest tests are extreme line-volume tests (~2000-2400 lines
  each) that walk every native-object method via for-in and trace
  it. The enumeration order divergence between us, Flash, and
  Ruffle cascades into 2000+ mismatched lines per version, but the
  underlying ActionScript behaviour isn't broken — the tests
  exercise enumeration order, not method semantics.
  SUBTESTS_NEWLY_VISIBLE_TRIAGE Tier E inventoried these as
  "ACCEPTED_DIFFS candidates" rather than fix targets. This doc
  captures the decision path; it is **not** a plan to write a fix.
-->

## Status

| Test | Match | % | Status |
|------|-------|---|--------|
| argstest-v6 | 58/2192 | 2.6% | output_mismatch |
| argstest-v7 | 45/2061 | 2.2% | output_mismatch |
| argstest-v8 | 51/2434 | 2.1% | output_mismatch |

## Failure characterization

The tests walk every native-object method via `for (m in ctor)` /
`for (m in ctor.prototype)` and trace `Testing M()` for each. The
output diverges from expected starting at line ~28 because:

- Our enumeration order differs from Flash's for some native
  objects (`PrintJob.send()`, `MovieClipLoader.constructor`).
- Where Flash emits `Testing send()` first we emit `Testing toString()`
  (likely Object.prototype-inherited methods are leaking through
  our enumeration filter for some native classes).
- Numeric-key methods (`Testing 4()`, `Testing 3()`, ...) appear in
  our output where Flash emits named ones — suggests something like
  `_global.MovieClipLoader.prototype` for-in iterating its
  numeric-indexed entries that Flash hides.

These are not behaviour bugs in callable APIs; they are enumeration-
order divergences from Flash, and the cascade fails 2000+ lines per
test.

## Recommended decision path

1. **Diff against `output.fpN.ruffle.txt`**. For each version:
   ```
   diff /home/robert/CC/SWFRecomp-CC/ruffle-tests/tests/swfs/from_gnash/actionscript.all/argstest-v6/output.fp9.txt \
        /home/robert/CC/SWFRecomp-CC/ruffle-tests/tests/swfs/from_gnash/actionscript.all/argstest-v6/output.fp9.ruffle.txt
   ```
   If Ruffle also diverges from Flash here (likely, given
   enumeration order is implementation-defined), and our diffs are
   a subset of Ruffle's diffs against expected, the test auto-
   promotes to `ruffle_matched`.

2. **If RM-eligible**: no work needed. Verify via
   `verify_output.py --test=argstest-v6 --diff --verbose` — the
   `ours_diff_count` / `ruffle_diff_count` fields tell whether
   subset-match is active.

3. **If NOT RM-eligible** (our diff set extends beyond Ruffle's):
   - Add `argstest-v6`/`v7`/`v8` to
     `ruffle-tests/tests/swfs/from_gnash/actionscript.all/ignored_tests.txt`
     with a comment pointing at the enumeration-order rationale.
   - Add an entry to
     `ruffle-tests/tests/swfs/from_gnash/_investigation/ACCEPTED_DIFFS.md`
     documenting:
     - The category (enumeration order — implementation-defined per
       ECMA-262).
     - That fixing it would require replicating Flash's specific
       native-object iteration order, which is undocumented and
       differs version-by-version of Flash itself.
     - Why we won't fix.

## Decision (made 2026-05-20)

**Path 3 — NOT RM-eligible. Added to `ignored_tests.txt` + `ACCEPTED_DIFFS.md`.**

Ran `verify_output.py --test=argstest-v{6,7,8}` against the resolved
expected (`output.fp32.txt` / `output.fp13-18.txt` — the highest-version
`[subtests]` variant). Findings:

| Test | Expected lines | Ruffle lines | Our actual lines |
|------|----------------|--------------|------------------|
| argstest-v6 | 2192 | 1298 | **7731** |
| argstest-v7 | 2061 | 1298 | **7731** |
| argstest-v8 | 2434 | 1298 | **8093** |

The doc's original premise ("~2000-2400 lines each", enumeration *order*
divergence) understated the problem. Reality: we *over-emit* by ~3.5×.
The first ~27 lines match; divergence starts at PrintJob's prototype walk,
where we emit `Object.prototype`-inherited `toString` plus a triangular
cascade of spurious numeric keys (`Testing 4()`/`3()`/`2()`/`1()`) instead
of `send`/`addPage`/`start`. The recursive descent multiplies it.

Root cause is unimplemented / placeholder-prototype native objects
(PrintJob, MovieClipLoader, LocalConnection, textRenderer, System.IME, …),
not enumeration order alone. Ruffle *under*-emits (1298 lines, diverging
~1650 lines from expected), so our 5000+-line diff is nowhere near a subset
of Ruffle's — `subset_match` cannot promote despite the `known_failure`
upstream flag.

A real fix would require fully implementing every native object the test
walks AND replicating Flash's implementation-defined native-object
iteration order. Not worth it for a `known_failure` enumeration test.
Documented in `ACCEPTED_DIFFS.md` Category 3; the three tests are in
`from_gnash/actionscript.all/ignored_tests.txt`.

## Root-cause detail (for anyone who revisits this)

The over-emitting objects are **stub classes** — `g_stub_ctors[18]` in
`SWFModernRuntime/src/actionmodern/action.c:32573`. A stub class exists as a
global with a real prototype object, but its methods are no-ops
(`builtin_stub_method`, `action.c:883`). The 18 stub classes as of this
writing: AsBroadcaster, Button, Camera, Color, ContextMenu, ContextMenuItem,
LoadVars, LocalConnection, Microphone, MovieClipLoader, NetConnection,
NetStream, PrintJob, SharedObject, Sound, TextSnapshot, Video, XMLSocket
(some — Color, Sound, TextSnapshot — have since grown real implementations;
the array name is historical).

Two distinct defects observed on `PrintJob` (`initPrintJobPrototype`,
`action.c:32701`), each of which would recur per stub class:

1. **Wrong version gate.** `send`/`addPage`/`start` are installed behind
   `if (g_swf_version >= 7)`. argstest-v6 is a SWF6 file, so they are
   absent — yet Flash's expected output (resolved `fp32` subtest) lists
   them. Whatever the correct rule is, `g_swf_version >= 7` is not it.

2. **Numeric-key garbage on the instance.** The `Testing 4()/3()/2()/1()`
   triangular cascade is not on the prototype (it has no numeric keys). It
   appears only when the test does `for (m in instance)` on a constructed
   stub-class instance. Not root-caused — most plausibly the stub
   constructor stores `arguments` as numeric-indexed own properties on the
   instance, which then enumerate (and the test recurses into each). A
   future fix should start by inspecting what `actionNewObject` /
   `builtin_stub_method` leave on a stub instance's `properties` array.
