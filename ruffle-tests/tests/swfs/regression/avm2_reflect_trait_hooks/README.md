# avm2_reflect_trait_hooks

Pins the two **observation hooks** injected code uses to instrument a
recompiled, source-less SWF: `swfmodern.Reflect.getTrait` / `setTrait`
(namespace-blind trait access) and `swfmodern.Rng.draws()` (the main
stream's monotonic draw counter). Both are runtime instruments, not
playerglobal or ECMA surface — see the comment blocks at
`SWFModernRuntime/src/avm2/avm2_class.c` ("swfmodern.Reflect") and
`src/avm2/avm2_number.c` ("swfmodern.Rng — the determinism hooks").

## Why the hooks exist

Injected AS3 can only name properties in the PUBLIC namespace, so a
recorder cannot read a game's `private`/`protected` state at all. It is not
a matter of spelling the namespace right:

- **private** (ABC kind 0x05) is compared by **pool-entry identity**, never
  by URI (`avm2_propkey_matches`); every ASC `PrivateNamespace` carries the
  same empty name, so no constructed `Namespace` can ever equal one.
- **protected** (0x18) IS compared by `(kind, URI)` — it is *not*
  identity-keyed, which is a real difference from private. It is still
  unreachable from script for a different reason: `new Namespace(...)`
  always yields kind **0x16** (`avm2_nsqname.c namespace_construct`), and
  the kind check fails before the URI is ever looked at.

## The owner argument is required, and that is the point

`getTrait(obj, owner, name)` takes the **declaring class** — not the
object's runtime class — because a base-class `private var x` and a
subclass `protected var x` are genuinely different slots. Rows `A1`/`A2`
read the same name off the same object through two owners and get two
values; `A3`/`A4` show each class's own compiled code agrees. Both
spellings of the owner are accepted (`probe.Base` and `probe::Sub`), since
callers get the string from `getQualifiedClassName` (row `A9`).

**Measured state — owner check disabled** (make `reflect_find` match every
defining class): `A2` reads `base-private`, `B4`+`B5` become
`sub-written`/`sub-written` (the write landed in the WRONG slot), `C2`
stops refusing (`NO REFUSAL, got: sub-written`) and `C6` changes shape.
Four rows, including a silent cross-slot write — which is exactly the
failure mode a name-only lookup would ship.

## The controls

`D1`–`D3` are the negative controls, and they must keep reading as they do:
ordinary property access on a **sealed** class throws `#1069` (`D1`, `D2`)
and on a **dynamic** class returns `undefined` (`D3`), while the hook reads
the real value one row later (`D4`). `D5` reads a public member normally.
If a `D` row ever prints the real value, visibility broke corpus-wide —
that is a regression, not a better hook.

Note for anyone reading the brief this came from: it expected the ordinary
control to "print null/undefined". On a sealed class it is `#1069`, not
null — a sealed receiver cannot grow a public property, so the read
throws. Both shapes are pinned here so the distinction is not rediscovered.

## Refusals (`C1`–`C6`)

Every failure **throws**, with a message that distinguishes the cases: no
such member on a real owner (`C1`), no such owner in this object's
hierarchy (`C2`, `C6`), receiver null/undefined i.e. "not built yet"
(`C3`), the name is a method (`C4`), the trait is a const (`C5`). A missing
trait must never come back as `null`: null is what the broken path returns,
and an instrument that cannot tell "no such trait" from "trait unreadable"
from "object does not exist" has not fixed anything. The message strings
are part of the contract and are pinned deliberately.

## The draw counter (`E1`–`E5`)

`draws()` counts draws from the MAIN stream (`Math.random()`), which is the
only thing that moves the generator a replay would have to step. `E1` draws
three and asserts a delta of 3, `E2` is the zero-draw control, `E3` proves
`cosmetic()` (a separate generator) is not counted, and `E4`/`E5` prove the
counter is monotonic across `setState` — a reset would silently make a
sampled window read as zero draws.

## Targets

Passes in native NO_GRAPHICS and in the wasm build, byte-identical. The
wasm half needed `compile_wasm` taught about AVM2 at all (it copied no
`RecompiledABC/` and defined no `-DSWF_AVM2`, so every AS3 test silently
built as an AVM1 movie that traced nothing); the AVM2 module list is now
one shared `AVM2_CORE_SOURCES` so the two targets cannot drift.

```bash
python3 ruffle-tests/verify_output.py --test=avm2_reflect_trait_hooks --diff
# wasm: build, then run under node (the runner only builds/deploys)
SWF_KEEP_BUILD_DIR=/tmp/wb python3 ruffle-tests/verify_output.py \
    --test=avm2_reflect_trait_hooks --wasm
node -e 'const M=require("/tmp/wb/test.js");
         const t=setInterval(()=>{if(M._runSWF){clearInterval(t);M._runSWF();}},20);'
```

Rebuild the SWF with `./build_swf.sh` (mxmlc; `probe/*.as` are compiled off
the source path). Nothing here derives from any decompiled game.
