# Arc: builtin-container subclasses — ~4–6 tests, four sub-causes

Opus-ready handoff. Fable design pass 2026-07-25 (code sites verified at
`33b3d75be`). Execute the prescription; where a detail says "pin from the
test", read the named test's Test.as + output.txt before coding it.

**This cluster is NOT one mechanism.** The priority map's "~7" is an upper
bound over four independent sub-causes (A–D below) plus one adjacent item
(E). Land A first — it is the bulk of the yield — then take B/C/D in any
order. Treat E as optional. Judge each test by its full diff, not by
whether "the mechanism" landed.

## The tests (status at CI run `30179405893`, graphics)

| Test | lines now | sub-causes |
|---|---|---|
| `from_avmplus/regress/bug_420755` | 25/27 | A only — the cleanest probe |
| `from_avmplus/regress/bug_654807_swf13` | 102/170 | A + B |
| `from_avmplus/regress/bug_654807_swf12` | 54/170 | A + B + D |
| `from_avmplus/as3/Array/length_mods` | 0/20 (dies line 9, `#1065`) | C blocks everything, then A |
| `from_avmplus/as3/ShellClasses/DictionarySubclass` | 20/22 | B only |
| `from_avmplus/regress/bug_687838` | 85/111 | E (separate bug) |

`avm2/displayobject_early_init` (1/54) is **explicitly excluded**: its
remaining diffs are BitmapData `#2015` validation errors and MyButton
construction ordering — platform work, not this arc.

## Verified current state (all file:line checked at `33b3d75be`)

- **`avm2_class_construct` always allocates `AVM2_OBJ_SCRIPT`**
  (`avm2_class.c:1215`). Object *kind* is never inherited.
  `native_ext_size` IS inherited (`avm2_class.c:1154`, and
  `avm2_globals.c:240` for builtin-to-builtin), but that mechanism is
  irrelevant here: Array's class has `native_ext_size == 0` — array
  instances get their `Avm2ArrayExt` manually in `avm2_array_new`
  (`avm2_object.c:189-207`).
- **`avm2_array_ext` returns NULL unless `kind == AVM2_OBJ_ARRAY`**
  (`avm2_object.c:169-173`). So on an `extends Array` instance every
  Array method sees no storage (`push` appends nothing, `get length` = 0)
  and index writes fall through to dyn props. This is exactly the
  `semisealed push FAILED! expected: 0,1,2 got:` / `get_length ... got: 0`
  signature filling bug_654807 and length_mods.
- **`super(args)` into a builtin is a silent no-op.** Builtin classes get
  `instance_init.fn = NULL` (`avm2_globals.c:230`), and
  `avm2_op_constructsuper` (`avm2_ops.c:2834-2850`) just calls that
  method ref. Array's constructor semantics live only in
  `native_construct` (`array_construct`, `avm2_array.c:1048`), which is
  deliberately not inherited (`avm2_class.c:1156-1158`).
- **`delete` of a missing property returns true on every object**
  (`deleteproperty_common`, `avm2_ops.c:1189-1234`; the ES3 rule at
  line 1232). There is no sealed-instance arm. The sealed-WRITE checks
  from the Vector arc exist (`#1056` at `avm2_ops.c:859/1164`) — the
  delete path lacks the parallel rule. `AVM2_CLASS_FLAG_SEALED` is
  `avm2_abc.h:120`; confirm the recompiler sets it for SWF classes
  (grep the emitter) — the runtime sets it by hand for builtins only.
- **Dictionary subclasses already work for storage**:
  `avm2_is_dictionary` walks the super chain (`avm2_dictionary.c:24`).
  Only the two delete rows fail.
- **GC is ready for retyped instances**: the trace dispatch runs the
  generic object trace (slots, dyn props, proto) and then adds precise
  element tracing for `kind == AVM2_OBJ_ARRAY` (`avm2_gc.c:520`,
  `trace_array` at 458). Verify the ordering once — the early `return`
  at 520 must only skip the native_ext blob scan, not the slot trace.
- **`#1065: Variable AS3 is not defined`** kills length_mods at line
  9/20: `a.AS3::pop()` (`length_mods/Test.as:260`) evaluates `AS3` as a
  runtime namespace *value*, and no global `AS3` binding exists. The AS3
  namespace URI and its fold logic are `avm2_class.c:44-50`
  (`http://adobe.com/AS3/2006/builtin`).

## Prescription

### A. `extends Array` gets element storage (the mechanism; most of the yield)

Resolve the builtin ancestor **once per class**, not per construct: at
`avm2_class_define`, if the `super_class` chain reaches
`ctx->builtins.array_class`, record it on `Avm2Class` (e.g. an
`instance_kind` field defaulting to `AVM2_OBJ_SCRIPT`). SWF classes
define before instances exist, and builtins register at boot, so the
chain is complete at define time.

In `avm2_class_construct` (`avm2_class.c:1215`), allocate with that kind
and, for `AVM2_OBJ_ARRAY`, attach a zeroed `Avm2ArrayExt` — mirror
`avm2_array_new` (`avm2_object.c:189-207`) but keep the subclass's own
`cls`/`vtable`/`proto` (the three lines avm2_array_new sets from
`array_class` stay as class_construct already sets them). Do NOT route
this through `native_ext_size` — Array's is 0 by design, and ByteArray
already uses ext-size inheritance; don't collide the two mechanisms.

What A alone should flip: bug_420755's two FAILED lines
(`a[4929] = x` → `length` 4930 through a dynamic subclass), the
bug_654807 `semisealed`/`sealed` storage rows, and the length_mods
`subarrays:` columns (after C unblocks the test).

**`super(args)` decision — pin before building.** `length_mods/Subarray.as`
and both bug_654807 subclasses declare NO constructor, so the synthesized
init calls `super()` with no arguments and a zeroed ext is correct. Read
the tests to confirm no case passes `new Subarray(n)` expecting Array's
length-arg semantics; only if one does, refactor `array_construct` into
alloc + init-on-receiver and wire `avm2_op_constructsuper` to call a
native hook when `super->instance_init.fn == NULL`. Don't build it
speculatively.

**Audit every `kind == AVM2_OBJ_ARRAY` site** — retyping flips all of
them for subclass instances, which is semantically right (avmplus
subclass instances ARE arrays) but two kinds of sites need eyes:
- sites that pair the kind check with `cls == array_class` assumptions:
  `avm2_array.c:20` (receiver guard), `avm2_array.c:63` (proto walk);
- behavior sites: `deleteproperty_common:1203` (index delete now applies
  — correct), JSON/AMF serialization, `concat` flattening
  (avmplus flattens subclass instances too — pin from bug_654807's
  concat row), for-in/hasnext2 enumeration (elements must enumerate on
  subclass instances).
Methods that *return* arrays (`concat`, `slice`, `splice`, `map`,
`filter`) keep returning plain `avm2_array_new` Arrays — that matches
avmplus; don't "fix" them to return subclass instances.

### B. Sealed-instance `delete` returns false

Observed: `semisealed delprop FAILED! expected: false got: true`
(bug_654807) and both `delete literal key from SealedDictionary` rows
(DictionarySubclass). Our delete answers the ES3 "missing property →
true" on every object; avmplus answers **false on sealed (non-dynamic)
class instances**.

Add the arm in `deleteproperty_common`: when the receiver's class lacks
the dynamic bit and the name resolves to nothing deletable, return
false. Guards: `is_prototype` objects are dynamic regardless of class;
globals/activations must be unaffected; the Dictionary object-key branch
(`delete object key` rows PASS today) must keep returning true.

**Uncertainty to resolve from the test, not by guessing:** in
DictionarySubclass, reads/writes of the literal key on the sealed
subclass evidently work (those rows pass) while delete must report
false. Read `DictionarySubclass/Test.as` to see whether the literal key
lands in dictionary storage (delete-of-present-key → false is then a
*Dictionary-specific* sealed rule) or was never stored (plain
missing-property-on-sealed rule). bug_654807's delprop row tells you the
plain-Array-subclass half. The two may need slightly different arms.

### C. Global `AS3` namespace binding (unblocks length_mods)

Define the public global `AS3` as a namespace value for
`http://adobe.com/AS3/2006/builtin` (representation: see the Namespace
class in `avm2_nsqname.c`; URI constant already at `avm2_class.c:44`).
avmplus defines it in the toplevel. After it resolves, `a.AS3::pop()`
must actually dispatch — our builtin Array methods are public traits
(`builtin_key("", name)`), and the AS3-ns fold (`avm2_class.c:50`) likely
already maps AS3-qualified lookups onto them; verify with the test
before adding AS3-namespaced trait aliases.

### D. bug_654807 swf12 vs swf13 version gate

Same Test.as at SWF versions 12 and 13. swf13 expects the semisealed
method rows to succeed; swf12 expects `ReferenceError: Error #1069` for
the same calls. This is the [[version-gate-new-api-surface]] pattern:
SWF ≤ 12 does not see some of Array's public prototype surface from
sealed-subclass receivers. **Diff the two `output.txt` files first** to
enumerate exactly which calls flip, then implement the narrowest gate
that produces those #1069s (likely: skip the public *prototype* function
fallback for sealed receivers below SWF 13). Do not regress swf13.

### E. (adjacent — take only if cheap) bug_687838 proto-chain index reads

26 rows of `expected: one A got: undefined`. Failing variants are
`Cls .proto ... array trans` and `Fcn .proto ... array trans/immed`;
`Cls ... immed` and plain `Arr` rows pass. A user prototype that IS a
real Array (assigned `.prototype = [...]` or mutated later) isn't
consulted for index reads in some paths — the same family as
[[avm2-array-prototype-index-storage]] but for user prototypes, which
never get `is_prototype`-retyped. Read the test's a–f case definitions;
the trans/immed split names the broken path. Separate commit if taken.

## Risks

- A retype is wide-reaching: run CI `categories=full` and read the
  **histogram**, not just transitions. Post-mops baseline to beat:
  segfault 3 / timeout 3 / runtime_error 8 / recomp_fail 1
  (`corpus_status_diff.py` prints it).
- The avm2 suite has many passing array-adjacent tests; sub-cause B
  (delete semantics) is the riskiest for collateral — `delete` on plain
  Objects/dynamic classes must keep ES3 behavior. Grep the avm1 side is
  unaffected (separate VM, no shared delete path — verify).
- `as3/Array/insertremove` (30766/30870, pre-existing) is adjacent to A:
  insertAt/removeAt hole shifting against prototype-supplied indices.
  Stretch goal only if A's work makes the diff obvious; it is NOT
  counted in the yield.
- Where sub-cause B's rule is ambiguous, prefer the arm the tests pin
  and document any arbitrary choice in RUFFLE_COMPAT_TWEAKS.md per
  CLAUDE.md.

## Process

Standard pipeline (`.claude/pipeline-handoff.md`): commit per sub-cause,
graphics CI `categories=full`, one watcher,
`corpus_status_diff.py <sha> WORKTREE --per-suite`. Baseline commit for
the diff: the commit before your first change
([[ci-baseline-commit-must-postdate-its-run]]). Docs after CI:
feature-priority-map (map + memory), from_avmplus CURRENT_STATUS, this
header, `.pipeline-state`.

## After this arc (queue, from the 2026-07-25 re-rank)

`as3/ByteArray` (5, undiagnosed, 2 timeouts) · `recursion/pcre_*` (5,
undiagnosed) · declared-ABC method arity checking
(`avm2/wrong_arg_count`, `avm2/error_geterrormessage`).
