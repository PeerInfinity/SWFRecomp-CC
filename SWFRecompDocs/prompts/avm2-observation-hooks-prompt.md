# Slice: observation hooks for injected AS3 — `swfmodern.Reflect` and an RNG draw counter

**Baseline: `master` at the commit that adds this file.** CLAUDE.md and this
project's memory are auto-loaded — the launch protocol, the CI pipeline
(`.claude/pipeline-handoff.md`) and the standing traps come from there, don't
re-derive them.

**Current corpus baseline: 4362 effective (graphics) / 4363 (no-graphics) at
4487 graded; regression 80/80 both modes.**

This slice is different from the ones around it: the work is entirely in this
repo (`SWFModernRuntime/`), but the *requirement* comes from a neighbouring
project — the kittyengine arc's Flash oracle, which injects a recorder into a
recompiled, source-less SWF and cannot see what it needs to see. They verified
the boundary themselves: nothing in their tree changes for this to be verified.

## 1. What to build

Two exports, in the family `swfmodern.Rng` already establishes.

**(A) A namespace-blind trait accessor.** Something of the shape
`swfmodern.Reflect.getTrait(obj, "dashTime")` and
`setTrait(obj, name, value)`, resolving through the class's **trait table**
rather than the public-namespace lookup `getproperty` does — so `protected`,
`private` and `protected static` members are readable by injected code.

**(B) A draw counter on `swfmodern.Rng`** — `draws()`, monotonically
increasing, so a per-tick RNG stream can say how many numbers were drawn and not
merely that the state moved. With one seeded 31-bit xorshift the count is
recoverable offline by stepping the generator; the counter makes the stream
self-describing.

Names, signatures and exact shape are yours. Follow the precedent:
`avm2_builtin_class(ctx, "swfmodern", "Rng", b->object_class)` at
`SWFModernRuntime/src/avm2/avm2_number.c:857`, reachable from AS3 via
`flash.utils.getDefinitionByName("swfmodern.Rng")`. The comment block at
`avm2_number.c:515+` explains the design intent of that family; read it before
adding to it.

## 2. Two facts gathered while writing this brief

**The requester's failed attempt has a structural explanation, and it rules out
the obvious workaround permanently.** They tried
`new QName(new Namespace("xplor:Player"), "dashTime")` and it failed. Memory
`avm2-private-namespace-identity` says why: ASC emits one `PrivateNamespace`
pool entry per class and **every one carries the same empty name string**, so
avmplus, Ruffle and this runtime all compare private namespaces by **pool-entry
identity, never by URI** (we got this wrong once — before `b4d4457f1` every
class's privates aliased every other class's). A `Namespace` constructed from a
URI therefore cannot match a private one, however it is spelled.

Note this is stated for *private*. **Protected** namespaces do carry a URI (the
class name), so whether the same identity comparison governs them is a real
question with a real answer in the code — find it rather than assuming it
either way. It changes whether (A) needs a trait walk for both cases or only
one.

**The trait tables you need exist.** `Avm2AbcTrait` arrays hang off the ABC
structures — `instance_traits` / `instance_trait_count` and `class_traits` /
`class_trait_count` at `SWFModernRuntime/include/avm2/avm2_abc.h:165-168`. A
name-only walk over those is the likely shape of (A). Confirm it fits before
building on it.

## 3. The design hazard the request does not mention

**A namespace-blind lookup by name is ambiguous, and this codebase has already
been bitten by the ambiguity it creates.** Two different traits can share a
name: a `private var x` in a base class and a `protected var x` in a subclass
are genuinely different slots, and memory `avm2-private-namespace-identity`
records that private members are **not** virtual — `Base`'s method reads BASE's
slot, and a shadowing subclass slot is a different one. So `getTrait(obj, "x")`
has more than one defensible answer.

**Decide the rule, document it, and make the fixture prove it.** Most-derived
wins, an optional class-name argument, an error on ambiguity — any of these is
defensible; silently returning whichever the walk hits first is not, and
`setTrait` writing the wrong slot is worse than `getTrait` reading it. This is
the arc-adjacent failure mode: five recent slices in this repo turned on a
lookup being keyed on the wrong thing.

## 4. Constraints on the fixtures — read before writing any

- **Nothing derived from the decompiled game may enter this repo.** The
  requester's evidence lives outside it and is **read-only** for you:
  `~/CC/Archipelago-CC/NewDocs/plans/platformer-longterm/measurements/PZ5-REPORT.md`
  (§3 "The five seams" item 1, §7 item 6), `~/CC/kittyengine-CC/flash/bot/RwkBot.as`,
  and the decompiled `~/CC/jpexs/output/robotkitty/scripts/xplor/Player.as`.
  Read them for context if useful; **do not modify anything under those paths,
  and do not copy decompiled game source into this repo.** Your fixture is a
  hand-written SWF with a class of your own.
- Fixtures go in `ruffle-tests/tests/swfs/regression/` — never the upstream
  mirrors (that suite's `README.md`; memory `custom-tests-live-in-regression-suite`).
- **The negative control must be a value that DIFFERS, not an absence** — the
  requester's own hard-won trap, and it is exactly right. For (A) the control is
  the same member read through **ordinary property access**, which must still
  print null/undefined: that is what distinguishes "an accessor exists" from
  "we quietly made everything public". If your change makes the control pass,
  you have broken visibility rather than added a hook, and that is a corpus-wide
  regression waiting to happen.
- For (B): draw N times, assert `draws() == N`, with a control that draws 0.
- **Both targets: native NO_GRAPHICS and the wasm build.** The requester's oracle
  runs both and has measured native == Chrome byte-identical, so a hook that
  behaves differently per target is itself a finding. `compile_wasm` in
  `ruffle-tests/verify_output.py` is the wasm path.
- `ExternalInterface` is unavailable natively — fixtures observe through
  `trace()`.

## 5. Traps

- **`verify_output_keep.py`'s source list is missing `src/amf_packet.c` and
  `src/actionmodern/avm1_amf.c`**, which blocks the KEEP_BUILD_DIR path at head
  (BACKLOG "Tooling — build scripts"). If you need that path, that is why it
  fails; the requester's workaround was dropping the two files into their own
  build dir. Fixing it properly is a separate filed item — don't absorb it.
- **`SWFRecomp/build/run-SWFRecomp.sh` is untracked and hardcodes the LIVE
  tree's binary**, so a worktree build silently runs the live recompiler.
- **The recompiler reads `--help` as a config-file path** and aborts on a toml
  parse error.
- **`verify_output.py` compiles generated C with `-w`.** Sweep new emitted C with
  `gcc -fsyntax-only -Werror=return-type -Wall`.
- **A recompiler change needs a manual cmake rebuild**; `--recompile` avoids a
  stale `RecompiledABC` false compile-fail.
- **Never run full test suites locally** (CLAUDE.md). Individual tests only.
- **`git stash` is shared across this repo's worktrees.** Byte-identity checks
  use a patch file: `git diff -- <dir> > p.patch; git apply -R p.patch`.
- **`gh` shares a 5000/hr rate limit across every session on this box**; the
  secondary limit returns 403 while `gh api rate_limit` still shows core quota.
  API-free fallback: poll `git fetch origin ruffle-test-results` and read the run
  id from the publish commit message (no-graphics publishes are titled plain
  "Update Ruffle test results"). A conflict on `regression/_results/results.json`
  resolves `--theirs`.
- **This box is shared** with the requesting arc, which runs browser
  measurements on it. Don't run two heavy jobs in parallel; don't read a slow
  build as a broken one.

## 6. Scope

(B) is small and self-contained. **If (A) proves large, ship (B) anyway** — it is
the requester's named want #1 and it should not be held hostage to the harder
half. If (A) is large but tractable, say what remains rather than half-landing a
lookup that returns the wrong slot in the ambiguous cases.

Do not extend the hooks beyond what §1 asks for because a further one seems
useful; the requester's next slices will ask if they need more.

## 7. What "done" is

1. Both hooks exist and follow the `swfmodern.Rng` precedent, or (B) alone with
   (A)'s remaining shape written down.
2. The protected-vs-private namespace question of §2 answered from the code.
3. The §3 ambiguity rule chosen, documented, and proven by a fixture — including
   the shadowed-name case, not only the easy one.
4. Fixtures pass in native NO_GRAPHICS **and** wasm, each with a differing-value
   negative control; ordinary property access still returns null/undefined.
5. **CI corpus-clean in BOTH modes**, `categories=full` (this is AVM2 runtime),
   `images=false`. Verify with `scripts/corpus_status_diff.py --stem
   results_graphics <baseline> <new>` and `--stem results`; quote the histogram.
   The hooks are additive, so a byte-inert corpus is the regression check and the
   fixtures are the evidence.
6. Durable records: a closeout under `SWFRecompDocs/status/`, and memory updated
   — at minimum `avm2-private-namespace-identity` if you learn something it does
   not say about protected namespaces.
7. Commit and push to `master` (no branch — trunk-based), standard trailer.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.

Note for the report: the requesting arc (`kittyengine-orchestrator-4`) is
waiting on this and will consume it in a later slice of theirs. Say plainly in
your report what landed and what did not, so I can relay something accurate
rather than optimistic.
