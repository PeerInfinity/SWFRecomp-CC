# avm2_slot_default_template

Regression net for the **per-class slot-default template** in
`avm2_slots_init_defaults` (avm2_class.c) — the alloc/ctor lever that replaced
a per-slot, per-construction loop with a `memcpy` of a precomputed image plus a
short patch loop.

Expected output generated with the Ruffle exporter oracle:

```bash
~/CC/ruffle/target/release/exporter test.swf /tmp/x.png --trace-log /tmp/t.txt
```

Rebuild the SWF with `./build_swf.sh` (mxmlc / Flex SDK, AS3 — not MTASC).

## What each case pins

The template is sound only if three things hold. Each has a case here that
fails loudly — with a *different* trace, not a crash — when it breaks.

1. **Declared-type defaults are reproduced exactly.** `typedDefaults` covers
   every arm of the old `slot_type_default`: `int`/`uint` → 0, `Number` → NaN,
   `Boolean` → false, `String` and class types → null, `*` → undefined. This is
   the work the template exists to remove — the old path re-derived each of
   these per construction via `avm2_mn_name` plus a chain of `memcmp`s, so
   these values are precisely what must survive the change.

2. **No pointer is ever parked in the shared image.** The template is plain
   malloc'd memory that the collector neither traces nor sweeps, so a `String`
   or `Object` pointer stored in it would be an untraced root. `constInitializers`
   covers a string constant (a static-pool pointer, which must come out of the
   patch loop) alongside the non-pointer constants; `ctrunc` additionally pins
   that the declared-type coercion — now performed once at template-build time
   rather than per construction — still truncates `9.75` to `9`.

3. **Per-object realization stays per object.** `perObjectIdentity` builds two
   `Holder`s and mutates one's array. If a realized pointer were ever shared
   via the template, both instances would see the same object and
   `bagsAreDistinct` would flip to false — the single most important line here.

Beyond those: `templateIsNotAliased` writes through one instance and checks the
next construction still gets pristine defaults (catches handing out the image
by reference instead of copying it); `subclassShadowing` exercises a subclass
that adds slots and inherits others, since the meta table covers every slot
ever allocated including parent slots shadowed by a subclass; and
`manyInstances` constructs 50 objects, dirtying each, because the template is
built lazily on the *first* construction and reused thereafter — a stale or
half-built image would show up as a non-zero `mismatchesOver50`.

## Related

`-DAVM2_SLOTTPL_VERIFY` is the heavier, non-durable check: it re-runs the
reference loop on **every** construction and aborts on any divergence. It was
clean over 1200 ticks default-GC and 400 ticks GC-stress of the RWK plan_k TAS
(12.7M+ constructions). This test is the durable, cheap version that runs in CI.

Note that inline slots (allocating object + slots in one o1heap block) were
tried in the same session and **ruled out** — see the comment on
`avm2_object_alloc` and `tools/divergence/perf/RWK_AB_STATUS.md`.
