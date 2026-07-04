# AVM1 Traps Ahead: Warnings for Upstream

**Living document.** Last updated: July 4, 2026.
**Audience:** LittleCube / upstream contributors — written to be shared. Expanded
from §5.2 of [`../merge/upstream-relationship-2026-07.md`](../merge/upstream-relationship-2026-07.md).

> **This is the deliverable LittleCube asked for** (July 2026): *"whatever
> information you have about flash features that games will expect to behave in a
> particular way, that are not obvious to implement/normally undefined behavior."*
> Sections 1–6 and 9 are the non-obvious behaviors; section 8 covers the
> normally-undefined / Flash-bug territory.

SWFRecomp-CC has spent nine months making the Ruffle/Gnash/Shumway AVM1 test suites
and several complete games pass. Most of that time went to behaviors that are
undocumented, counter-intuitive, or outright Flash Player bugs that content depends
on. Upstream's recent commits show it entering this territory (super, CastOp,
removeMovieClip, fonts), so this is the map of where we hit mines. Entries are
grouped by subsystem and kept short; each is backed by tests we can point to on
request. New entries get added as upstream tracking shows new territory being
entered.

None of this is code — our implementation isn't portable to upstream's
architecture. These are the *semantics*, which are.

---

## 1. `super` (upstream's `super-var` branch is here now)

- **`super` is depth-based, not "call parent".** Each `super` invocation must
  resolve against the prototype chain *relative to where the currently executing
  method was found*, tracked as an explicit depth — not relative to the object's
  own `__proto__`. Recursive/diamond patterns break any simpler model. Storing
  "the parent" at call time fails the moment a method chain re-enters.
- **Argument order for simple (DefineFunction, non-register) functions.** When a
  simple function is invoked through `super()`, `super.method()`, `__resolve`, or
  as an array element, arguments must be pushed **forward** (args[0] deepest).
  We had six dispatch sites doing it in reverse — everything worked until a
  two-argument method was called through `super`, which silently swapped
  width/height in a real game's UI. Multi-arg + super is the test to write.
- **SWF5 vs SWF6+ closure/scope capture differ**, and `super` preload flags in
  DefineFunction2 interact with it. Test both version gates.

## 2. `removeMovieClip` and clip lifecycle

- **Removal defers when `onUnload` exists — anywhere in the subtree.** If the clip
  *or any descendant* has an `onUnload` handler, the clip is not destroyed: it
  survives at a shifted depth (the classic −32769-range bias) until the handler
  has run, while non-surviving lower-depth children are stripped. Naive
  remove-immediately fails Gnash's MovieClip suites specifically on this.
- **User variables survive removal.** A variable the user set on a removed clip's
  name must remain readable (and `typeof` answers do not simply become
  `"movieclip"`-or-undefined the way you'd guess). Do not clear the variable map
  on removal.
- **Instance names are not variables.** A child's instance name resolves via the
  parent's display bindings, not the variable table. Conflating them (one map for
  both) works for months and then breaks re-placement, `duplicateMovieClip`, and
  anything where a user variable shadows an instance name. We de-conflated late
  and it was painful; upstream can get it right from the start.
- **Duplicating over a live clip must fully reset the reused slot** (nested display
  lists, frame counters, current-frame state) — otherwise re-clone merges frame-1
  content onto stale state.

## 3. Virtual properties (`addProperty`) — the 65 budget

SWF7+ enforces a re-entry budget on virtual-property accessors: **65 getter+setter
invocations combined, per property entry** — not a global recursion limit, not
per-function. Exceeding it kills the *script*, silently, mid-execution. Two
consequences:

1. Every internal property read/write path must route through the same
   getter/setter invocation helpers, or your count drifts from Flash's.
2. Your C stack must survive 65-deep re-entry through the interpreter — we had to
   raise `RLIMIT_STACK` at startup and add a call-depth backstop.

Ruffle's `virtual_property_special_recursion_*` tests are the oracle here.

## 4. Timeline navigation — where full games break

Trace tests barely touch this; games live in it.

- **`gotoAndStop`/`gotoAndPlay` catch-up:** jumping forward executes the skipped
  frames' place/remove actions with frame-script `stop()`s suppressed — and a clip
  *placed during* that catch-up must **not** advance its own playhead on its
  placement tick, or it auto-advances past its frame-1 `stop()`. Scope any special
  case narrowly: we over-broadened this once and regressed execution-order tests.
- **Manual navigation must sync the script-visible `_currentframe`** immediately.
  A stopped clip that was `gotoAndStop`'d must report the new frame forever after;
  `gotoAndPlay` masks the bug because the next tick re-syncs.
- **Beware "current frame" meaning "next frame to show" internally.** If your
  engine stores the upcoming frame (common), every comparison against a
  script-requested frame needs unwrapping — the off-by-one hides until a goto
  targets frame 0 from the last frame and reads as "same frame, skip work."
- **Execution ordering** (init actions → place → frame scripts → clip events →
  `onEnterFrame`, with goto-deferral queues) is the single biggest source of
  divergence between AVM1 implementations. Build ordering tests early; Ruffle's
  `execution_order*` tests are good oracles.

## 5. PlaceObject2 subtleties

- **A Move (modify) PlaceObject2 with no matrix means "keep the existing
  transform"** — not "identity". If your recompiler emits a sentinel (e.g.
  transform_id 0) for "no matrix", every runtime modify path must guard on it;
  we missed one path and a cxform-only modify snapped a game's entire UI to (0,0).
- Ratio, cxform, and matrix are independently optional; every combination occurs
  in real content.

## 6. Function-call machinery

- **Argument-count mismatches are defined behavior**: extra args are accessible via
  `arguments`, missing params are `undefined`. Fixed-size assumptions (we clamped
  constructor args at 16 once) don't just truncate — if you pop fewer than pushed,
  the stranded operands corrupt the *next* opcode. Pop everything you counted.
  (Upstream already fixed the more-args case in `5aba28b` — the fewer-args and
  many-args paths deserve the same test.)
- **Method calls must bind `this` to the receiver for simple functions too**, not
  only register-based DefineFunction2 ones. Simple-function methods silently
  reading the *caller's* `this` works surprisingly often — until it doesn't.

## 7. Determinism for testing (adopt early — cheap now, expensive later)

Seed `Math.random` and the clock **per test**: we compile every test with a
`MOCK_DATE_TIME` macro (default matching Ruffle's `--deterministic` mode) and seed
the avmplus RNG from it. Result: two full-suite CI runs at the same commit are
byte-identical, so any fluctuation is by definition a real bug. Retrofitting this
after tests exist means re-blessing every expected output. Related: replicating
**avmplus's exact RNG** and `%.15g`-style number formatting is required to match
Ruffle's expected outputs at all.

## 8. Flash is buggy on purpose — know when to stop "fixing"

A class of behaviors are Flash Player *bugs* that both Ruffle and real content
depend on. Implementing the "correct" version fails tests and games. We keep four
classification documents that are directly reusable (links are to this repo on
GitHub so they work standalone):

- [FLASH_BUGS_REPLICATED.md](https://github.com/PeerInfinity/SWFRecomp-CC/blob/master/ruffle-tests/tests/swfs/avm1/_investigation/FLASH_BUGS_REPLICATED.md)
  — bugs to replicate deliberately (e.g. ColorTransform alpha-multiplier-only
  assignment being a no-op).
- [RUFFLE_VS_FLASH_DIFFERENCES.md](https://github.com/PeerInfinity/SWFRecomp-CC/blob/master/ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md)
  — where Ruffle's expected output reflects Ruffle, not Flash; decide which oracle
  you serve *before* chasing these.
- [ACCEPTED_DIFFS.md](https://github.com/PeerInfinity/SWFRecomp-CC/blob/master/ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md)
  — expected outputs that are platform UB or internally inconsistent; provably
  unfixable, maintain an ignore list instead of burning weeks (we burned the
  weeks).
- [RUFFLE_COMPAT_TWEAKS.md](https://github.com/PeerInfinity/SWFRecomp-CC/blob/master/ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_COMPAT_TWEAKS.md)
  — underspecified behaviors and the pragmatic choices that match real-world
  expectations.

Also in this category: text-field bounds wanting a +1px fudge to match (see
RUFFLE_COMPAT_TWEAKS above), and `setProperty(_x, Infinity)`-class quirks where
Flash's internal numeric representation (float vs twips int) leaks into results.

## 9. Miscellaneous sharp edges

- **`tellTarget` + label goto on dynamically created clips** — target resolution
  must consult dynamically attached clips, not just the authored display list.
- **`_xmouse`/`_ymouse` are per-clip local coordinates** — compute on demand per
  queried clip; caching only the root's value returns 0 everywhere else.
- **Soft references** (a variable holding a removed-then-recreated clip's path)
  rebind by *original target path* — Gnash's MovieClip suites test this
  aggressively.
- **One-shot particle-style clips**: `attachMovie`'d clips' own timelines must
  advance and their final-frame `removeMovieClip` must fire, or effect sprites
  accumulate forever (a memory *and* overdraw problem — we found it as a GPU cost).
- **Duplicate label handling** in the recompiler (upstream hit this — `fc9664b`):
  real SWFs contain duplicate and forward-referenced labels; MTASC output and
  hand-authored content differ here.

---

## Standing offer

For any subsystem above we can supply: the specific Ruffle/Gnash/Shumway test names
that act as oracles, our investigation notes, and (where useful) targeted PRs
written against upstream's architecture.

**Agreed channel (July 2026):** behavioral findings get filed as GitHub issues on
the relevant SWFRecomp org repo, with follow-up discussion on Discord.
