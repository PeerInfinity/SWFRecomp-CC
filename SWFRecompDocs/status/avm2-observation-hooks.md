# AVM2 observation hooks — `swfmodern.Reflect` and `Rng.draws()`

**Status: shipped.** Brief:
`SWFRecompDocs/prompts/avm2-observation-hooks-prompt.md` (baseline
`c8dbf185d`). Requested by the kittyengine arc's Flash oracle, which injects a
recorder into a recompiled, source-less SWF and could see neither the game's
non-public state nor how many random numbers a tick consumed. Nothing outside
this repo changed; no decompiled game source entered this tree.

## What landed

**(A) `swfmodern.Reflect`** — `SWFModernRuntime/src/avm2/avm2_class.c`
(implementation + the design comment block), declared in
`include/avm2/avm2_globals.h`, registered from `avm2_globals.c` next to
`avm2_register_nsqname`.

```as3
var R:Object = getDefinitionByName("swfmodern.Reflect");
R.getTrait(obj, "xplor.Player", "dashTime");            // -> the value
R.setTrait(obj, "xplor.Player", "dashTime", 0.25);      // -> undefined
```

- Argument 2 is the **declaring class** (the trait's OWNER), required, in
  either spelling: `"pkg.Class"` or the `getQualifiedClassName` form
  `"pkg::Class"`.
- Reads slots (`var`/`const`) and invokes protected getters; writes slots
  **with declared-type coercion** (the same `avm2_coerce_to_type_mn` an
  ordinary slot write uses — an instrument cannot park a String in an `int`
  slot) and invokes setters, honouring `setter_defining_class`.
- Statics work by passing the **class object** as the receiver; class traits
  live on the class object's own vtable with the same `defining_class` stamp,
  so it is the same code path.
- Every failure **throws** with a distinguishing message. Never null.

**(B) `swfmodern.Rng.draws()`** — `src/avm2/avm2_number.c`. A monotonic
`uint64` bumped in `avm2_generate_random_number`, i.e. once per MAIN-stream
draw (`Math.random()` / `Number.random()`). `cosmetic()` runs a separate
generator and is deliberately **not** counted; `setState()` does **not** reset
the counter, because the whole use is `draws()` sampled twice and subtracted,
and a reset would make a window read as zero draws.

**Fixture:** `ruffle-tests/tests/swfs/regression/avm2_reflect_trait_hooks`
(30 rows, mxmlc, `probe/*.as` hand-written). Passes **byte-identically** in
native NO_GRAPHICS and in the wasm build.

## What the brief got wrong, and what that changed

**1. The `Avm2AbcTrait` arrays are the wrong mechanism.** §2 proposed a
name-only walk over `instance_traits` / `class_traits`
(`include/avm2/avm2_abc.h:165-168`). That cannot work on its own: a trait's
`slot_or_disp_id` is very often **0 = auto-assign**, so the static table does
not say which slot a trait owns — you would have to replay the entire vtable
build to find out. The **flattened runtime vtable** (`Avm2Class::ivtable`)
already holds the answer and, decisively, already stamps `defining_class` on
**every** entry including slots (`avm2_vtable_add_traits` sets it before the
kind switch), preserves that stamp when a subclass inherits the entry, and
keeps a shadowed base slot alongside the subclass's own. The owner-keyed
lookup the brief specifies is therefore a ~30-line walk over data that is
already correct, instead of a re-derivation.

**2. Protected namespaces are NOT identity-compared — and the workaround is
still ruled out, for a different reason.** §2 left this open and asked for a
code answer. `avm2_propkey_matches` (`avm2_class.c:97`) consults `ns_priv`
identity **only** for kind `0x05` (private); every other kind, protected
(`0x18`) included, falls through to a `(folded kind, URI)` compare. So
protected traits ARE matchable by URI in principle. They are still unreachable
from injected script because `new Namespace(uri)` always produces kind
**`0x16`** (`avm2_nsqname.c:136`, `namespace_construct`) — a namespace object
only carries another kind when it was boxed from an ABC constant pool that
declares it — and the kind check fails before the URI is compared. Net effect
for (A): one trait walk covers both cases; no private/protected split was
needed. This has been added to the `avm2-private-namespace-identity` memory.

**3. `compile_wasm` did not support AVM2 at all.** §4 named it as "the wasm
path". It copied only `RecompiledScripts`/`RecompiledTags`, compiled no
`src/avm2/*.c`, and defined no `-DSWF_AVM2` — so an AS3 test built as an AVM1
movie, ran `swfStart`, and traced **nothing** while reporting `WASM_BUILT`
(the `--wasm` mode only builds/deploys, it never diffs, so this was invisible).
Fixed by hoisting the AVM2 module list into a shared `AVM2_CORE_SOURCES`
constant + `copy_avm2_third_party()` used by both `compile_native` and
`compile_wasm`, copying `RecompiledABC/`, and defining `-DSWF_AVM2` on the
same `RecompiledABC` trigger. No ASYNCIFY is needed: `runSWF_avm2`'s
`while(1) + emscripten_sleep` loop is gated on `__EMSCRIPTEN__ && !NO_GRAPHICS`,
so the NO_GRAPHICS wasm build takes the plain bounded frame loop and runs to
completion under node. An AVM1 `--wasm` build was re-verified unchanged.

**4. The negative control on a sealed class is `#1069`, not null.** §4 asked
for a control that "must still print null/undefined". Ordinary property access
for a non-public name on a **sealed** class throws `ReferenceError #1069` — a
sealed receiver cannot grow a public property, so there is nothing to return.
`undefined` is what a **dynamic** class gives. The fixture pins both shapes
(`D1`/`D2` sealed, `D3` dynamic) so the control is a differing VALUE either
way, which is what the requirement was actually protecting.

## The ambiguity rule, and the evidence that it is load-bearing

The owner argument is required rather than optional, per §3. Disabling only
the owner check in `reflect_find` (matching every defining class, first hit
wins) flips four rows of the fixture:

| row | with owner check | owner check disabled |
|---|---|---|
| `A2 sub.shadowed` | `sub-protected` | `base-private` |
| `B4 sub written` | `sub-written` | `sub-written` |
| `B5 base untouched` | `base-private` | **`sub-written`** |
| `C2` (unknown class) | refusal message | `NO REFUSAL, got: sub-written` |

`B5` is the one that matters: a name-only lookup does not merely read the
wrong slot, it **writes** the wrong one, silently corrupting a base-class
private field while the caller believes it wrote the subclass's. That is the
failure the required-owner signature removes by construction.

## Deliberately not built

`hasTrait`, a trait enumerator, a `cosmeticDraws()` counter, and a
private/protected split in the lookup. §6 says the requester's next slices
will ask if they need more; a `try/catch` around `getTrait` already answers
"does this exist" because the refusals throw.

## Corpus

Additive: two new builtin classes in the `swfmodern` package (which already
holds `Rng`) and one counter increment. CI run in both modes with
`categories=full`, `images=false` — see the commit that carries this file.
