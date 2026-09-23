# AVM1 Traps Ahead: Warnings for Upstream

**Living document.** Last updated: September 22, 2026 (previous: July 4, 2026).
**Audience:** LittleCube / upstream contributors — written to be shared. Expanded
from §5.2 of [`../merge/upstream-relationship-2026-07.md`](../merge/upstream-relationship-2026-07.md).
**Delivery:** shared on the SWFRecomp Discord on July 4, 2026 and acknowledged.
The September revision adds §1's correction, the post-July AVM1 findings in
§§2, 6, 8, 11, and a new §12 (AVM2) for whenever upstream gets there.

> **This is the deliverable LittleCube asked for** (July 2026): *"whatever
> information you have about flash features that games will expect to behave in a
> particular way, that are not obvious to implement/normally undefined behavior."*
> Sections 1–8 and 11 are the non-obvious behaviors; section 10 covers the
> normally-undefined / Flash-bug territory; section 9 is test methodology.

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

## 1. `super`

(July 2026 note: upstream's `super-var` branch was fighting this at the time;
`super` has since shipped in master via PR #3, and `super-var` is abandoned.
The rules below still apply — the second bullet in particular only shows up
with multi-argument methods.)

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
- **A `super` reference used as a *value* proxies the instance.** `super.m.apply(super, args)`
  must bind `this` to the object `super` was resolved from, not to `_global` or
  the prototype; we had it landing on `_global` until an AMF test called
  through it (July 2026).

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
- **Nothing may be freed the moment its refcount hits zero — if scripts can
  hold uncounted references.** Directly relevant to a refcounted design: AVM1
  locals and registers live in the generated function's C frame, so if any of
  those are borrowed (ours are), dropping an object's last *counted* reference
  mid-script frees memory the script can still name. We moved all destruction
  to a tick-boundary drain (July 2026, after a use-after-free in a real game).
  Your stack-integrated `PUSH_OBJ`/`POP` retains avoid the stack half of this;
  the register/local half is worth an audit.

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
- **Loop-back must preserve child identity (`survives_rewind`).** When a
  sprite's timeline wraps to frame 1 (or any backward goto lands on a frame
  that re-places the same character at the same depth), the existing child
  **survives** — same instance name, same variables, same playhead, same
  button state — and the re-place applies as a *modify*. The naive
  clear-everything-then-replay mints a fresh instance every loop, which both
  breaks scripts (state stored on children evaporates; `instanceN` names
  drift) and leaks unboundedly (we measured ~4 clips/tick on a looping UI
  sprite until caches overflowed). Dynamically created children (attachMovie/
  duplicateMovieClip depth range, ≥16384) survive **every** backward goto, not
  just natural loops — Ruffle's removal logic only considers depths below the
  dynamic bias at all. Ruffle's `run_goto` is the reference; fixing this
  outright repaired a Gnash execution-order test for us, and a second bug in
  the same family (explicit backward gotos destroying attached children) was
  the root cause of a use-after-free (July 2026). Decide survivorship against
  per-frame placement data, not by diffing live state.
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
- **Every asynchronous dispatch site is a dispatch site.** When we finally
  funnelled all ~129 call sites through one core (July 2026) it found six more
  live bugs in paths nobody thinks of as "calling a function": the root
  `onEnterFrame` running under the wrong SWF version, `onUnload` leaking its
  parameters into the timeline scope, `valueOf` during numeric coercion missing
  `this`, a sort comparator losing its captured scope, `Object.watch` callbacks
  dropping their userData argument, and `LoadVars`' URL encoder. Thirteen
  shipped bugs from one structural cause, total. If you keep one calling
  convention (you do), keep it for timers, events, coercions, comparators and
  watchers as well — not just `CallFunction`/`CallMethod`.

## 7. Case sensitivity is a *runtime mode*, not a constant (SWF ≤ 6)

Property, variable, function, and instance-name lookup is **case-insensitive in
SWF6-and-below movies** and case-sensitive in SWF7+. Three consequences that are
easy to miss:

- It's decided by the *movie's* version at runtime, per comparison — not a
  compile-time choice. Our matchers branch on the SWF version inside the compare
  function itself.
- Folding must be **Unicode-aware**, not `strcasecmp` — AVM1 folds non-ASCII
  codepoints too (we use a codepoint case-fold with an ASCII fast path, and the
  property hash is computed with the same fold so hash and compare agree).
- **This interacts directly with string-ID interning** (relevant to your merged
  architecture, which we surveyed in July 2026: property lookup is exact `u32`
  id equality and the interner keys the hashmap by exact bytes). Under that
  scheme, `foo` and `Foo` intern to different ids and become *different
  properties* — correct for SWF7+, wrong for ≤6, where they must alias. The fix
  shape: fold names before interning when the movie version is <7 (or intern a
  folded id alongside the exact one). Lots of SWF5/6 games rely on sloppy
  casing; this surfaces as "handler never fires" / "variable is undefined" bugs
  that look unrelated to string handling.

## 8. `for..in` enumeration order is load-bearing

AVM1 enumerates object properties in **insertion order** (delivered in reverse,
because Enumerate pushes them and the loop pops LIFO). Real content and emulator
test suites both depend on it. Two traps:

- **An id- or hash-ordered store breaks it.** An rbtree keyed by string id
  iterates in id order (= interning order), not insertion order. If your
  property store doesn't preserve insertion order natively, keep a side list or
  ordered index for enumeration. (Your `ActionEnumerate` is currently
  unimplemented, so this hasn't bitten yet — cheaper to design for now than to
  retrofit.)
- **Hidden-property masks are SWF-version-dependent.** `ASSetPropFlags` hiding
  bits mean different things per movie version; enumeration must apply the
  right mask. And mutations have quirky order effects — e.g. `Array.shift()`
  densifies holes and moves a reassigned index to the *end* of enumeration
  order. When you implement Enumerate, the Ruffle/Gnash enumeration tests are
  the oracle to run early.
- **`Array.shift` is a per-element native move with flag semantics** (July
  2026): each reassigned index has its `ASSetPropFlags` reset and is
  re-inserted at the end of enumeration order; a DontDelete index keeps its
  value slot, flags and position but still gets overwritten; a move is blocked
  only when the index is DontDelete *and* ReadOnly. Ruffle's `array_shift`
  test is the oracle.
- **`addProperty` creates an ordinary, *enumerable* property.** Only the
  names `constructor` and `__proto__` are force-hidden by `setProperty`;
  `addProperty` hides nothing. We had virtual properties invisible to `for..in`
  until an AMF serialization test enumerated one.

## 9. Determinism for testing (adopt early — cheap now, expensive later)

Seed `Math.random` and the clock **per test**: we compile every test with a
`MOCK_DATE_TIME` macro (default matching Ruffle's `--deterministic` mode) and seed
the avmplus RNG from it. Result: two full-suite CI runs at the same commit are
byte-identical, so any fluctuation is by definition a real bug. Retrofitting this
after tests exist means re-blessing every expected output. Related: replicating
**avmplus's exact RNG** and `%.15g`-style number formatting is required to match
Ruffle's expected outputs at all.

## 10. Flash is buggy on purpose — know when to stop "fixing"

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

## 11. Miscellaneous sharp edges

- **Functions carry their *defining* SWF's version.** Version-sensitive
  semantics (string→bool coercion, case rules, version-partitioned `_global`
  views) must follow the SWF version of the movie that *defined* the executing
  function, not the caller's — and that includes asynchronous re-entry: timers,
  event handlers, loaded-child-SWF callbacks. We shipped and fixed exactly this
  (July 2026): a v6 child SWF's `setInterval` callback ran under the v7 host's
  semantics, resolved the wrong version-view of `_global`, so its own
  `clearInterval` silently no-op'd and the timer re-fired ~41×/tick forever.
  Relevant to your prelude-SWF architecture whenever the prelude's compiled
  version differs from the user movie's — the version switch has to happen at
  *every* dispatch site (timers, events, coercions), not just the main
  CallFunction path; the async paths are the ones everyone forgets.
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
- **Array indices are integer-only.** Flash's array-index scanner accepts only
  canonical non-negative integers: `arr[2.5] = x` and `arr["1e3"] = x` are
  *named* properties and must not bump `length`. Also make sure capacity
  arithmetic for `arr[hugeIndex] = x` is 64-bit — ours overflowed u32 into an
  out-of-bounds write (July 2026).
- **Geometry is integer twips.** Flash (and Ruffle's `Twips`, an `i32`) keeps
  positions, bounds and mouse coordinates as whole twips. Carry doubles if you
  like, but *quantize before any comparison* — tab-order and hit-test decisions
  hinge on exact `<=` between edges, `localX`/`localY` are always an exact twip
  count, and an "invalid bounds" sentinel is `0x7ffffff` on all four edges,
  not the origin. Four separate defects in our input/focus work traced to this
  one rule (July 2026).
- **AMF0 serialization is channel-scoped** (relevant once you touch
  `NetConnection`/`SharedObject`/`LocalConnection`): on the *wire* a native
  Array whose keys are all indices is a StrictArray (`0x0A`), densified with
  `undefined` for holes, at every nesting level, and one non-index key demotes
  the whole value to ECMAArray (`0x08`); in *local* serialization (`ByteArray.
  writeObject`, LSO bodies) it is always ECMAArray and sparse writes emit only
  the present keys. Typed objects (`0x10`) nest, XML is `0x0F`, and a write
  reference table counts only referenceable values. Ruffle gets three of these
  wrong and marks the tests `known_failure`; Flash is the oracle, not Ruffle.
- **Report the real host OS.** `System.capabilities.os` / `$version` must say
  what the host actually is; content branches on it. Pin it for tests the way
  you pin the clock (we use a `MOCK_PLATFORM` macro next to `MOCK_DATE_TIME`).

## 12. AVM2 (ActionScript 3) — for when you get there

Upstream has no AVM2 today, so this section is short and stays at the level of
"design for this now". We built our AVM2 runtime July–September 2026 against
Ruffle's avm2 corpus (1,278 tests) and Tamarin's acceptance suite (1,574); the
traps below each cost a session.

- **Private namespaces compare by identity, not name.** ASC emits one
  `PrivateNamespace` pool entry per class, all with the same empty name. Compare
  by pool-entry identity (per ABC file + index) or every class's privates alias
  every other class's — `Base`'s method reads `Sub`'s shadowing slot.
  Ruffle's `namespace.rs` says this outright.
- **Dynamic property names that parse as canonical `uint`s become integer
  keys** and enumerate *ahead of* string keys; `"00"` and `"-1"` stay strings.
  Object literals set pairs last-first. Two graded outputs disagree about
  "insertion order" until you see the key-class partition.
- **Calling a class as a function is a one-argument coercion**: `C()` and
  `C(a, b)` throw `ArgumentError #1112` — unless the class installs its own call
  behavior (Array, String, Number/int/uint/Boolean, Error, Date, RegExp,
  Function, Object, Vector, Namespace, QName, XML, XMLList all do). Static-only
  classes (`JSON`, `Math`) are abstract: `new JSON()` throws `#2012`.
- **Vector index errors are not version-gated.** A valid `uint` index out of
  range is `RangeError #1125` at every SWF version; non-`uint` names keep the
  versioned `#1069`/`#1056` behavior; `delete v[i]` is true, `delete v.length`
  false. Ruffle gates `#1125` behind SWF 11 and is wrong.
- **An accessor's two halves can be declared by different classes.** A subclass
  may override only the setter and call `super.prop = v` inside it; if your
  vtable entry stores one "defining class" for the pair, `super` resolves from
  the wrong class. Keep a per-half binding.
- **Builtin prototypes are instances with default primitives.**
  `String.prototype.toString()` is `""`, `Number.prototype.valueOf()` is `0`.
  A "coerce the receiver" implementation recurses to stack overflow when the
  receiver is the prototype object itself — every ES3 method on a builtin
  prototype needs a non-coercing guard.
- **`null` is not `undefined` for optional object arguments.** AS3 code passes
  explicit `null` for optional matrices/colorTransforms/clip rects constantly;
  an `arg_present()` that only checks `undefined` then reads `.a` off `null` as
  0/NaN and silently draws nothing. Test `bmp.draw(src, null, null)`.
- **Sealed `Array` subclasses are version-gated** (avmplus bug 654807): SWF ≥ 13
  gets no element storage; SWF ≤ 12 gets storage *and* sealed index access, so
  the dense-path methods work and the generic-loop ones throw `#1069`.
- **Loader timing is an executor drain, not "next frame".** A `load()` issued
  in frame N resolves *after* frame N; a load started from the resulting
  `complete` handler resolves in the same drain; `init`/`complete` fire inline
  for images but one tick later for child SWFs. Three chained loads in two
  ticks is a real test.
- **The root SymbolClass binding is "any id that names no character"**, not
  id 0 — obfuscated SWFs use other invalid ids. And the bound class must have
  `Sprite` in its chain.
- **Trace-first, then games.** Ruffle implements nearly all of `flash.*` in
  ActionScript (~470 `.as` files / ~23K lines compiled into a playerglobal
  SWF) with only native-flagged leaf methods in Rust; its build metadata is an
  inventory of the minimal native surface an AVM2 host must provide. That is
  the same shape as your AS2 prelude — the approach transfers.

---

## Standing offer

For any subsystem above we can supply: the specific Ruffle/Gnash/Shumway test names
that act as oracles, our investigation notes, and (where useful) targeted PRs
written against upstream's architecture.

**Agreed channel (July 2026):** behavioral findings get filed as GitHub issues on
the relevant SWFRecomp org repo, with follow-up discussion on Discord.
