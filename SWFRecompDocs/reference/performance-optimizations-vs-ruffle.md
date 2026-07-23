# Performance Optimizations vs. Ruffle — Reference

Companion to [`performance-optimizations.md`](performance-optimizations.md): every
shipped optimization in that catalog, classified by its relationship to Ruffle.
Analysis session 2026-07-22, prompted by
[`../prompts/perf-optimizations-ruffle-applicability.md`](../prompts/perf-optimizations-ruffle-applicability.md).

**Ruffle revision read:** `be11d7e89` (local checkout `~/CC/ruffle`, read-only;
carries our uncommitted oracle/perf patches, none of which touch the code cited
here). gc-arena at `75671ae03f53718357b741ed4027560f14e90836`.

**Evidence rule:** every verdict below cites a Ruffle `file.rs::symbol` that was
actually read this session. No verdict rests on "it's an interpreter, so
presumably…". Where a verdict could not be settled by reading, it says so and
names the measurement that would settle it.

---

## Categories and counts

| | Category | Rows |
|---|---|---|
| **A** | Already in Ruffle (same or different form) | **30** |
| **B** | Portable — Ruffle doesn't do it, could, no architectural conflict | **6** |
| **C** | Structurally impossible in Ruffle | **0** |
| **D** | Not applicable — AOT-only | **0 catalog rows** (but see §D) |

Rows total 36 because five catalog entries split (§1.3, §1.5, §1-L5, §2.7, and
the AOT note on every `[RC]` row).

### The conclusion those counts support

**Almost nothing in our catalog is an idea Ruffle lacks.** Thirty of thirty-six
rows are already in Ruffle, in the same form or a better one. Ruffle's AVM2
verifier runs a full abstract-interpretation pass
(`avm2/optimizer/type_aware.rs::type_aware_optimize`, 2,400 lines, on by default)
that performs *by itself* — statically, against real runtime vtables — what our
`[RC]` levers 2, 3A, 3B, the `this.field` and class-static slot specializations,
coercion elision, and the getlex/domain caches do at recompile time. Its GC
(gc-arena) is an incremental tri-colour collector with debt-based, retention-
tracking pacing, which is a strictly stronger version of our tier-1 watermark
plus tier-2 lazy sweep. Its renderer already batches through a staging belt,
caches tessellation per scale, and uploads texture sub-regions.

The catalog's own numbers corroborate this rather than contradict it: the
Seedling IC arc is recorded as landing at "**Ruffle parity**" (~47 ms), and the
retracted 11x gap ([[rwk-ruffle-gap-is-1_3x-not-11x]]) resolved to 1.30x. Those
levers were **catching up to Ruffle's baseline, not passing it**.

**Column C is empty, and that is the load-bearing finding.** The prompt warned
that the tempting error is filing something as impossible when it is merely
inconvenient in Rust. Having read the code, *nothing* in the catalog is blocked
by gc-arena's borrow discipline, `Gc`/`GcWeak` layout, safe-Rust aliasing, or the
wasm/JS boundary. The closest thing to a structural block — the fingerprint-gated
native intrinsic — is blocked by project *policy*, not architecture, and I have
filed it as B with that stated plainly.

**Column D is empty at the row level, and that is the real architectural
argument.** There is no single catalog entry that only an AOT compiler could
have. What AOT buys is not an entry in this list; it is the **substrate every
entry is expressed in**. Ruffle's optimizer rewrites `getproperty` into
`Op::GetSlot { index }` — and then still pays an interpreter dispatch, a
`Value` enum stack push, and a bounds-checked `Box<[Lock<Value>]>` index for it.
We emit `slots[K]` as a C expression that gcc/LLVM register-allocates, CSEs
against neighbouring ops, and hoists out of loops. Same analysis; the op boundary
is gone. That multiplier applies uniformly to all of §1 and is discussed in §D.

So the honest version of the thesis is: **we do not out-think Ruffle
per-optimization; we out-execute it per-op.** The one place we genuinely beat it
by algorithm is §3's goto walk gate — and even there, the finding is that Ruffle
runs the identical walk and would accept the gate as a patch.

---

## Summary table

Layer legend as in the catalog: **[RT]** runtime, **[RC]** recompiler.

### §1 AVM2 — property/name resolution, dispatch, typed emission

| # | Catalog entry | Cat | One-line reason |
|---|---|---|---|
| 1.1 | vtable name-hash index | **A** | `VTable::get_trait` → `PropertyMap::get_for_multiname` is already an FNV `HashMap` keyed on local name |
| 1.2 | domain-find name hash | **A** | `Domain::get_defining_script` uses the same `PropertyMap` |
| 1.3a | getproperty inline cache | **B** | Ruffle has *no* runtime ICs; it resolves the same sites statically in the verifier. An IC would only pay where the optimizer bails |
| 1.3b | lazy class-name + printf-free ints | **A** | Ruffle formats class names only inside `make_*_error` constructors on the throw path |
| 1.4 | IC → callproperty/setproperty | **B** | Same as 1.3a; `optimize_call_property` covers the typed cases statically |
| 1.5 | `this.field` slot specialization | **A** | `Op::GetPropertyStatic` → `optimize_get_property` → `Op::GetSlot`; local 0 typed from `method.bound_class()` |
| 1.6 | getlex-global domain IC | **A** | `Op::FindPropStrict` → `Op::GetScriptGlobals { script }` |
| 1.7 | class-static slot specialization | **A** | Same path as 1.6 + 1.5 |
| 1.8 | coercion elision | **A** | `Op::Coerce` → `Op::Nop` on type match; `SetSlotNoCoerce` / `SetSlotCoerceI` |
| 1.9 | coerce-class memo | **A** | `PropertyClass::get_class` self-replaces `Name` → `Class`, written back via `VTable::set_slot_class` |
| 1.10 | blit SIMD | **B** | `bitmap/operations.rs` is scalar; but the `+simd128` dual-binary build already exists |
| 1.11 | Rectangle slot fast path | **A** | Reads `rectangle_slots::X/Y/WIDTH/HEIGHT`, build-time-generated slot ids |
| L1 | findpropstrict scope-hit IC | **A** | Verifier walks the scope stack and rewrites to `GetScopeObject`/`GetOuterScope` |
| L2 | find→this | **A** | `optimize_op_to!(Op::GetLocal { index: 0 })` under a `!sets_local_0` guard |
| L3+4a | own-class-static bake, store-path slot spec | **A** | `GetScriptGlobals`; `SetPropertyStatic`/`InitProperty` → `SetSlot*` |
| L3+4b | blit identity-skip (src==dst) | **A** | `copy_pixels_impl`: "Copying the same area of self to self, noop" |
| L5a | compare→branch fusion | **B** | Ruffle goes the *other* way: `verify.rs::translate_op` splits `IfLt` into `LessThan` + `IfTrue`, and no peephole re-fuses |
| L5b | runtime-KIND-checked numeric arms | **A** | `Activation::op_add` already has `(Integer, Integer)` / `(Number, …)` arms |
| L6 | slot-default template + setup_locals memset | **A** | `ScriptObjectData::new` collects defaults from `VTable::slot_table` ("for better performance") |
| L7 | native Flixel collision intrinsic | **B** | Native-method + `CallNative` machinery exists; content fingerprinting of user ABC does not. Policy-blocked, not architecture-blocked |

### §2 AVM2 — GC & memory

| # | Catalog entry | Cat | One-line reason |
|---|---|---|---|
| 2.1 | Stage 11 mark-sweep GC | **A**, better | gc-arena is *incremental* (`CollectionPhase::{Sleeping,Marking,Marked,Sweeping}`) with write barriers; ours is stop-the-world between ticks |
| 2.2 | collectable strings | **A** | `AvmStringRepr` is `Collect`; the interner holds them in a `WeakSet` |
| 2.3 | raw-alloc reclamation | **A** by construction | Rust ownership/`Drop`; there are no manual scratch allocations to lose |
| 2.4 | weak orphan registry | **A** | `OrphanManager` stores `DisplayObjectWeak`; our commit says so explicitly |
| 2.5 | adaptive GC watermark (tier 1) | **A** | `Pacing::sleep_factor` sleeps until `heap + remembered × 0.5` — retention-tracking by design |
| 2.6 | tier-2 collector cost | **A**, better | Budgeted incremental marking *and* sweeping is gc-arena's normal mode; no per-collect snapshot exists to kill |
| 2.7a | `arrayToCSV` intrinsic | **B** | Same as L7 |
| 2.7b | arena right-size (1984→512 MB) | **A** by construction | Ruffle wasm uses the ordinary growable wasm heap; there is no fixed arena reservation to shrink |

### §3 AVM2 — display tree & timeline walks

| # | Catalog entry | Cat | One-line reason |
|---|---|---|---|
| 3.1 | goto catch-up walk gate | **B** | `run_inner_goto_frame` does the identical ungated full stage + orphan walk |

### §4 AVM1 runtime & shared per-frame path

| # | Catalog entry | Cat | One-line reason |
|---|---|---|---|
| 4.1 | property-name hash gate + per-object hash index | **A** | `avm1/property_map.rs::PropertyMap` is an `IndexMap<_, _, FnvBuildHasher>` |
| 4.2 | per-frame-walk MC resolution cache | **A** by construction | Display objects are `Gc` pointers; there is no name-keyed resolve to cache |
| 4.3 | event-driven enterFrame-walk pruning | **A**, better | `Avm1::run_frame` iterates `clip_exec_list`, an intrusive list maintained on create/remove — never a tree walk |
| 4.4 | N button-hover walk gate | **B** | `run_mouse_pick` fires on every `Player::update`; `skip_mouse_hover` gates only the *event*, not the pick |
| 4.5 | syncVarToTextFields fast-reject | **A** | `notify_property_change` consults a per-object bindings vec, usually empty |
| 4.6 | ASCII fast path in name matching | **A** by construction | `wstr::Units` is Latin-1 bytes or UTF-16 units; no UTF-8 decode exists in the compare path |
| 4.7 | findOrCreateMovieClip cache-scan cut | **A** by construction | Same as 4.2 |

### §5 Renderer / GPU

| # | Catalog entry | Cat | One-line reason |
|---|---|---|---|
| 5.1 | writeBuffer batching | **A** | Per-object transforms accumulate in a CPU `BufferBuilder`, flushed in ~200-object chunks through a `StagingBelt` |
| 5.2 | identical-geometry upload skip | **A**, better | Meshes upload once at `register_shape_internal`; `TessellationCache` avoids re-tessellating by scale |
| 5.3 | fs_main fill-type specialization | **A** | Separate `color.wgsl` / `gradient.wgsl` / `bitmap.wgsl` pipelines |
| 5.4 | writeTexture sub-region upload | **A** | `update_texture` uploads only the `PixelRegion` at `origin: {x_min, y_min}` |

---

## Category A — already in Ruffle

### The big one: Ruffle's verifier is an optimizing compiler (§1, most rows)

This reframes most of §1 and deserves its own writeup before the per-row notes.

**What we do.** Analyse ABC at recompile time in `SWFRecomp/src/abc/abc_emit.cpp`
and emit specialized C: `slots[K]` for proven `this.field`, identity moves for
proven `find→this`, direct static-slot reads, elided `coerce_*`.

**What Ruffle does.** `avm2/verify.rs::verify_method` calls
`avm2/optimizer.rs::optimize`, which runs `peephole::preprocess_peephole`, then
`optimizer/type_aware.rs::type_aware_optimize`, then `postprocess_peephole`,
`dce::eliminate_dead_code`, `nop_remover::remove_nops`. `type_aware_optimize` is
a worklist abstract interpreter over basic blocks (`assemble_blocks`) carrying an
`AbstractState { locals, stack, scope_stack }` of `OptValue { class, not_null,
constant_value }`. It runs **twice**: once to reach fixpoint, once (gated on
`Avm2::optimizer_enabled`, default `true` — `avm2.rs:243`, `player.rs:2664`) to
rewrite ops via the `optimize_op_to!` macro. It is per-method and lazy, on first
verification.

Local 0 enters typed as the receiver: `this_value.class =
method.bound_class()`, `not_null = true`, `constant_value =
Some(ConstantValue::Receiver)`. Declared parameter types seed the other locals
from `resolved_param_config`.

The rewrites it performs that correspond to our levers:

| Ruffle rewrite | Symbol | Our lever |
|---|---|---|
| `GetPropertyStatic` → `GetSlot { index }` | `optimize_get_property` | `this.field` slot spec (1.5), class-static slot spec (1.7) |
| `SetPropertyStatic`/`InitProperty` → `SetSlot`/`SetSlotNoCoerce`/`SetSlotCoerceI` | `Op::SetPropertyStatic` arm | store-path slot spec (L3+4a) |
| `GetPropertyStatic`/`CallProperty` on a virtual → `CallMethod { disp_id }`, and → `CallNative` for final-class fast-call natives | `optimize_get_property`, `optimize_call_property`, `maybe_optimize_static_call` | call devirtualization (§6, we gated it out) |
| `FindPropStrict` → `GetLocal { index: 0 }` when the hit scope is the receiver and local 0 is never written | `Op::FindPropStrict` arm + `optimizer.rs::determine_sets_local_0` | **lever 2, find→this** |
| `FindPropStrict` → `GetScopeObject { index }` / `GetOuterScope { index }` | `Op::FindPropStrict` arm, `ScopeChain::get_entry_for_multiname` | **lever 1, findpropstrict scope-hit IC** |
| `FindPropStrict`/`FindDef` → `GetScriptGlobals { script }` | `Op::FindPropStrict` arm (:1400), `Op::FindDef` arm | getlex-global domain IC (1.6), own-static bake (L3+4a) |
| `Coerce { class }` → `Nop` on type match or null | `Op::Coerce` arm | **coercion elision (1.8)** |
| `Add { inputs_integral } + CoerceI` → `AddI` | `peephole::postprocess_peephole` | part of typed emission (L5) |

Two of these deserve emphasis because the correspondence is uncanny:

- **find→this.** Ruffle's guard is `matches!(value.constant_value,
  Some(ConstantValue::Receiver)) && !sets_local_0`. Ours is the canonical-preamble
  check plus a declared-instance-trait match. Same theorem, independently derived,
  with Ruffle's version scanning for *any* write to local 0 where ours pattern-
  matches the preamble.
- **Subclass shadowing.** Our `this.field` spec bails if any subclass redeclares
  the field (`fe1b9e062`). Ruffle needs no such bail: it resolves against the
  *actual* `VTable` built by `VTable::init_vtable`, so shadowing is already
  reflected. Its analysis is strictly better-informed than ours because it runs
  after class linking, not before.

**Verdict.** Category A across the board for the analysis. Our `[RC]` arc
re-derived, in a different phase of the pipeline, work Ruffle had already done.
The catalog's own record that this arc reached "Ruffle parity" at ~47 ms is
exactly the expected outcome. What we get *beyond* Ruffle from the same analysis
is discussed in §D.

**Note on a real Ruffle limitation.** The optimizer is not sound in one place it
knows about: `Op::FindPropStrict`'s comment records that coercing a `Subclass`
value to a declared `Superclass` can make the scope optimizer skip subclass
traits — and it keeps the behaviour because avmplus does the same
(`tests/swfs/avm2/scope_optimizations`). We inherit no such hazard; our
equivalent bails.

### §1.1 vtable name-hash index — A

**What we do.** Lazy FNV-1a name-keyed hash on `Avm2VTable`, turning `find_mn`
from O(trait count) to O(1). Per-call activation vtables opt out via `no_index`.

**What Ruffle does.** `avm2/vtable.rs::VTable::get_trait` →
`avm2/property_map.rs::PropertyMap::get_for_multiname`. `PropertyMap` *is*
`HashMap<AvmString<'gc>, SmallVec<[(Namespace<'gc>, V); 2]>, FnvBuildHasher>` —
FNV-hashed on the local name, with a small inline vector of namespace/value pairs
per name that is linearly scanned against the multiname's namespace set. Ruffle
has never had a linear vtable scan; the linear `find_mn` was our anomaly.

**Verdict: already there, and the shape is better than ours.** Bucketing by local
name and keeping namespaces in the bucket handles multiname namespace-set
matching natively; our hash keys on the name and filters afterwards. Nothing to
contribute; there is something to learn if we ever revisit namespace matching.

### §1.2 domain-find name hash — A

`avm2/domain.rs::Domain::get_defining_script` and `get_class_inner` both use the
same `PropertyMap` (`DomainDataMut::defs`, `::classes`). The parent-domain walk
is still a recursion (`get_defining_script` tail-recurses into `self.0.parent`),
but each level is a hash probe, not a scan. Already there.

### §1.3b lazy class-name / printf-free ints — A

Our ~8 ms win came from not `snprintf`-ing the receiver's class qname on every
slot write. Ruffle never had this cost: class names are materialized only inside
error constructors on the failure path — `value.rs::Value::get_property`'s `None`
arm calls `error::make_reference_error(...)` with the class, and
`type_aware.rs` calls `make_error_1026`/`make_error_1051` only in `else`/`Err`
branches. Integer stringification goes through Rust's `AvmString` conversions;
there is no printf in the tree. Already there — arguably "we had a self-inflicted
cost Ruffle never had", which is the honest framing.

### §1.5 / §1.7 slot specialization — A

Covered above. `optimize_get_property` returns `Op::GetSlot { index: slot_id }`
for `Property::Slot`/`ConstSlot`, and simultaneously resolves and memoizes the
slot's class via `PropertyClass::get_class` + `VTable::set_slot_class`. Class
statics reach the same path after `FindPropStrict` → `GetScriptGlobals`.

### §1.6 getlex-global domain IC — A

`type_aware.rs`, `Op::FindPropStrict` arm: after the local scope stack and outer
`ScopeChain` both miss, it tries `outer_scope.domain().get_defining_script(&multiname)`
and rewrites to `Op::GetScriptGlobals { script }`. Ruffle's own comment is worth
recording, because it is the exact fork in the road we took:

> NOTE: avmplus rewrites this into a FindDef, and it caches the results of that
> FindDef at runtime, rather than caching the lookup here, in the verifier.
> However, this discrepancy is unlikely to cause any real problems with SWFs.

avmplus caches at runtime (our IC), Ruffle resolves statically (our emit-time
bake). We shipped *both* — `dad415990` (IC) then `a2e4758fb` (bake).

### §1.8 coercion elision — A

`type_aware.rs`, `Op::Coerce { class }` arm: if the stack value is null and the
class is not builtin-non-null, or if `class == stack_class`, the op becomes
`Op::Nop` (later removed by `nop_remover::remove_nops`). Plus the store-side
`SetSlotNoCoerce`/`SetSlotCoerceI` variants. Ruffle's `TODO: this could check for
inheritance` marks the same conservatism our 735-site version has.

### §1.9 coerce-class memo — A

`avm2/property.rs::PropertyClass::coerce` and `::get_class` mutate the
`PropertyClass` in place from `Name(multiname, domain)` to `Class(class)` on
first resolution and signal `changed`, and `VTable::coerce_trait_value` writes
the resolved form back with `VTable::set_slot_class`. That is a per-slot,
self-replacing memo — structurally cleaner than our `coerce_class_memo[]` keyed
on `(file, mn_idx)`, and it sidesteps our "cache non-NULL only" caveat because an
unresolvable name is an error there, not a transient miss.

### §1.11 Rectangle slot fast path — A

`avm2/globals/flash/display/bitmap_data.rs` reads
`rectangle_slots::{X,Y,WIDTH,HEIGHT}` and `point_slots::{X,Y}` via
`Value::get_slot`. Those constants come from `avm2/globals.rs::slots`, which
re-exports the `native_table.rs` generated by `core/build_playerglobal/` at build
time. Ruffle *defines* `flash.geom.Rectangle` itself in playerglobal, so it has
always known the slot indices; it never resolved them by multiname. Category A,
and structurally unavailable to be otherwise.

### §L3+4b blit identity-skip — A

`core/src/bitmap/operations.rs::copy_pixels_impl`:

```rust
if !blend && source.ptr_eq(dest) && source_region == dest_region {
    // Copying the same area of self to self, noop
    return;
}
```

Plus `dest_is_source` handling that clones the source region rather than aliasing
it, at four other call sites. Already there.

### §L5b runtime-KIND-checked numeric arms — A

`avm2/activation.rs::op_add` dispatches `(Integer, Integer)` with `checked_add`,
`(Integer, Number)`, `(Number, Integer)`, `(Number, Number)`, then strings, then
XML, then the generic `coerce_to_primitive` path. Exactly our lever-5 shape. See
§6 for why this matters more than it looks.

### §L6 slot-default template — A

`avm2/object/script_object.rs::ScriptObjectData::new`:

```rust
// We use `iter` and `collect` rather than setting elements of a Box<[]>
// or pushing to a Vec for better performance
let slots = slot_table.iter().map(|si| Lock::new(si.default_value)).collect::<Box<_>>();
```

Defaults live on the class's `VTable::slot_table` as `SlotInfo::default_value`
(populated by `vtable.rs::trait_to_default_value`), and construction copies them.
`Value` is `Copy` and `Lock` is transparent, so this is a memcpy in practice.
Ruffle carries none of our "template may never hold a heap pointer — untraced-root
hazard" risk, because `SlotInfo` is `Collect` and therefore traced.

### §2.1 / §2.5 / §2.6 the GC arc — A, and Ruffle's is better

**What we do.** `avm2_gc.c`: stop-the-world mark-sweep between ticks (VM
quiescent at the boundary), precise field tracing plus a conservative `native_ext`
scan, pinning for immortal objects; tier 1 makes the cadence track *retention*
(post-collect watermark = live bytes); tier 2 adds an arena membership bitmap,
epoch marks, and a budgeted resumable sweep cursor with a born-black nursery
during sweep.

**What Ruffle does.** gc-arena, driven by a single
`self.gc_arena.borrow_mut().collect_debt()` at the end of `player.rs::Player::update`
(:2385) — which `run_frame` goes through, so it is per-tick like ours. But the
work done per call is *not* a full collection:

- `arena.rs::CollectionPhase` is `Sleeping | Marking | Marked | Sweeping`, and
  `Arena::collect_debt` runs `do_collection(&self.root, RunUntil::PayDebt, …)` —
  it performs an amount of marking/sweeping proportional to allocation debt and
  stops. Both mark *and* sweep are incremental; our tier-2 made only sweep so.
- `metrics.rs::Pacing::DEFAULT` is `sleep_factor: 0.5, min_sleep: 4096,
  mark_factor: 0.1, trace_factor: 0.4, keep_factor: 0.05, drop_factor: 0.2,
  free_factor: 0.3`. The documented sleep rule is "wait until the live size
  reaches `<current heap size> + <previous remembered size> * sleep_factor`" —
  i.e. **cadence tracks retention**, which is precisely our tier-1 change, with
  the invariant `mark + trace + keep < 1.0` guaranteeing the collector outruns
  allocation.
- The `Marked` phase can fall back to `Marking` when write barriers fire, so
  Ruffle gets incremental correctness from `Gc::write`/`unlock!` — a discipline
  the whole codebase already pays for other reasons.

**Verdict: already there, in a stronger form.** Our tier-2 arena bitmap and qsort
elimination have no Ruffle counterpart because the cost they removed
(a per-collect sorted census snapshot) never existed there. There is nothing to
contribute upstream; there is a design to learn from if we ever want to go
incremental on the mark phase too. Note one thing we have that they don't: a
`AVM2_GC_STRESS=1` collect-every-tick CI correctness gate. gc-arena's
`Pacing::STOP_THE_WORLD` is the equivalent knob but is not wired to Ruffle's test
suite as a gate.

### §2.2 collectable strings — A

`core/common/src/avm_string/repr.rs::AvmStringRepr` derives `Collect` and is held
as `Gc<'gc, AvmStringRepr<'gc>>`. The interner
(`core/common/src/avm_string/interner.rs::AvmStringInterner`) stores atoms in a
`WeakSet<'gc, AvmStringRepr<'gc>>` backed by `hashbrown::HashTable` with FNV, so
interned strings are collectable rather than immortal — the same property our
"rodata pool entries self-exclude via zero `gc_flags`" achieves by exclusion.
`AvmAtom` hashes and compares **by pointer** (`Gc::as_ptr(self.0).hash(state)`),
which is a nice extra we don't have.

### §2.3 raw-alloc reclamation — A by construction

Our fix freed per-call scratch and grow-and-abandon buffers the census never saw
(EditText layout trees, glyph/sort/floodFill scratch, tombstones, per-object
activation vtables), with `fn_scope` proven aliased and therefore never freed. In
Ruffle every one of those is either a `Gc` (traced) or an owned Rust value
(`Box<[…]>`, `Vec`, `SmallVec`) freed by `Drop` — e.g.
`ScriptObjectData::{slots, bound_methods}`. There is no third category of memory
to leak. Nothing to port; the whole class of bug is absent.

### §2.4 weak orphan registry — A

`core/src/orphan_manager.rs::OrphanManager` holds `Rc<Vec<DisplayObjectWeak<'gc>>>`;
`valid_orphan` upgrades and filters on `parent().is_none()`; `cleanup_dead_orphans`
retains on `placed_by_avm2_script()` after upgrade. Our commit `adec1e505` says it
mirrors this, and it does. The one thing gc-arena buys them that we cannot have
mid-tick is that a `GcWeak` entry can *become* dead during a tick and be dropped
at the next cleanup — see the note in §3.

### §2.7b arena right-size — A by construction

Our 1984 → 512 MB (AVM2) / 1024 → 256 MB (AVM1) shrink exists because emscripten
`mmap` commits our o1heap arena resident at init, so the *reservation* size is
the resident footprint. Ruffle's wasm build uses the ordinary Rust allocator on a
growable wasm linear memory; gc-arena allocates each `Gc` individually
(`Gc::new` → `context.rs` allocation) with no pre-reserved arena. The parameter
we tuned does not exist there. This is a self-inflicted cost we removed, not an
idea to contribute.

### §4.1 AVM1 property-name hash — A

`avm1/property_map.rs::PropertyMap` is
`IndexMap<PropertyName<'gc>, V, FnvBuildHasher>`, with case sensitivity chosen
*per lookup* (`CaseSensitive`/`CaseInsensitive` wrapper types implementing
`Equivalent`) to serve SWF≤6 semantics, and insertion order preserved for
enumeration. Both halves of our optimization (hash gate, per-object index) are
present; the case-insensitive-hash trick is something we should look at if our
`prop_name_match` ever shows up hot again under SWF6 content.

### §4.2 / §4.7 MovieClip resolution caching — A by construction

Our two wins here (memoize the resolved `MovieClip*` on the `DisplayObject`;
cheapen the child-MC cache scan) exist because our runtime resolves clips through
name/path-keyed structures on hot per-frame paths. Ruffle passes
`MovieClip<'gc>` — a `Gc` pointer — directly; `run_frame_avm1` is called on the
clip itself, and "is this a MovieClip" is `DisplayObject::as_movie_clip()`, a
downcast. There is no resolve to memoize. Nothing to port.

### §4.3 event-driven enterFrame-walk pruning — A, and it is their primary design

**What we do.** Maintain the two pure-recursion enterFrame walks event-driven
instead of re-walking the tree per tick (`5f2530446`), after shelving a full-tree
recompute variant that cost ~10%.

**What Ruffle does.** `avm1/runtime.rs::Avm1::run_frame` walks
`context.avm1.clip_exec_list` — an **intrusive singly-linked list of MovieClips**
threaded through `next_avm1_clip()`, maintained at clip creation
(`Avm1::add_to_exec_list`) and pruned in-line during the walk when
`clip.avm1_removed()`. It is never a display-tree recursion. Ruffle needs this
not for speed but for semantics: "AVM1 execution order is determined by the
global execution list, based on instantiation order."

**Verdict: already there, for a better reason.** Their structure is forced by
AVM1 ordering semantics and gets the pruning for free. Worth checking whether our
event-driven lists agree with instantiation order in the cases where tree order
and creation order differ — that is a correctness question our optimization
raises and theirs answers.

### §4.5 syncVarToTextFields fast-reject — A

`avm1/object/stage_object.rs::notify_property_change` reads
`dobj.avm1_text_field_bindings()` — a per-display-object
`Vec<Avm1TextFieldBinding>` (`display_object.rs::Avm1TextFieldBinding`,
registered by `register_binding`, torn down by `unregister_bindings`) — and
filters it by name. For an object with no bound fields the vec is empty and the
call is a length check. Unbound fields wait in `context.unbound_text_fields` and
are re-tried by `Avm1TextFieldBinding::bind_variables`. Strictly better than our
"fast-reject the scan": there is no scan.

### §4.6 ASCII fast path in name matching — A by construction

`wstr/src/common.rs::Units` is `Bytes(T)` (LATIN-1) or `Wide(U)` (UTF-16 with
unpaired surrogates allowed). Ruffle's strings are never UTF-8, so name
comparison never decodes; `AvmString::eq_ignore_case` and friends operate on code
units. The cost our fast path removes cannot arise there.

### §5.1 writeBuffer batching — A

`render/wgpu/src/surface/commands.rs::WgpuCommandHandler` holds a `transforms:
BufferBuilder` and accumulates each drawn object's `Transforms` into it,
flushing in chunks sized by `dynamic_transforms.rs::ESTIMATED_OBJECTS_PER_CHUNK`
(200, clamped to `max_uniform_buffer_binding_size`). All buffer writes go through
`wgpu::util::StagingBelt` — created once per frame context
(`backend.rs::ActiveFrame`, `StagingBelt::new(65536)`), written via
`buffer_builder.rs::BufferBuilder::finish` → `staging_belt.write_buffer(...)`,
and closed with `staging_belt.finish()` before submit, `recall()` after. That is
our per-frame CPU staging mirror plus one flush, generalized: the belt reuses
chunk buffers across frames.

### §5.2 identical-geometry upload skip — A, better

Shape geometry is uploaded once, at `backend.rs::register_shape_internal`, which
builds `BufferBuilder`s for vertices and indices and calls `.finish(...)` into
`Mesh { vertex_buffer, index_buffer }`. Re-registration on scale change is
avoided by `core/src/tessellation_cache.rs::TessellationCache::find_near_and_touch`
— a 4-entry LRU of `(scale, ShapeHandle)` per shape, reusing any entry within a
2x scale ratio (`RETESSELLATION_SCALE_THRESHOLD`). Our optimization compares the
uploaded bytes and skips; Ruffle avoids generating them. Their approach is the
better one and is worth stealing if our dynamic-geometry path ever regresses.

### §5.3 fs_main fill-type specialization — A

`render/wgpu/shaders/` contains `color.wgsl`, `gradient.wgsl`, `bitmap.wgsl`
(plus `alpha_mask.wgsl`, `copy.wgsl`, `common.wgsl`, and `blend/`, `filter/`
subdirectories) — one shader per fill type, with pipelines built in
`pipelines.rs`. Solid fills sample nothing, same as our variants.

### §5.4 writeTexture sub-region upload — A

`backend.rs::update_texture` takes a `region: PixelRegion` and issues
`queue.write_texture` with `origin: Origin3d { x: region.x_min, y: region.y_min,
z: 0 }` and `extent` = the region size, with an early return when the region is
empty. It falls back to a whole-texture upload only when `clamp_bitmap` resized
the texture, because the resize filter makes region mapping unsound — a caveat
worth having in our own path.

---

## Category B — portable (the upstream contribution list)

Six rows. These are the ones where a patch would be welcome and no architectural
commitment blocks it.

### §3.1 goto catch-up walk gate — B, portable, and easier there than here

*Verified 2026-07-22 against `be11d7e89`; re-verified this session.*

**What we do.** Skip the construct / frame-script catch-up on display subtrees
with no pending work (`walk_clean` per node, `dirty_kids` per container, a
dirty-orphan candidate list). `SWFModernRuntime/src/avm2/avm2_display.c`,
§ "Catch-up walk gate", commit `6fefd4552`.

**What Ruffle does.** The same full walk, ungated.
`core/src/frame_lifecycle.rs::run_inner_goto_frame` (:124) runs
`stage.construct_frame` then `stage.run_frame_scripts` over the whole tree plus
every orphan, on **every** explicit goto — including a no-op goto to the current
frame (`movie_clip.rs::goto_frame` :881 → `goto_frame_now` :923 → `no_op_goto`
:940). Both walks are unconditional recursions with no quiescence check:
`movie_clip.rs::run_frame_scripts` (:2648) is `run_local_frame_scripts` + `for
child in self.iter_render_list()`, and the `DisplayObject` default
(`display_object.rs`:2403) is the same. Orphans:
`orphan_manager.rs::OrphanManager::each_orphan_obj` (:45) iterates the entire vec
— and `run_all_phases_avm2` iterates it three times per frame (enter, construct,
frame-scripts) plus `cleanup_dead_orphans`, mirroring the three scans our
profiling found.

**Verdict: portable, and easier there than here.** The mechanism is a flag on
`DisplayObjectBase` plus a mark up the parent chain — no architectural conflict.
Ruffle has two advantages we lacked: `Cell`-based interior mutability makes the
flag cheap, and it has a single `set_parent` choke point where we had to hook ten
separate parent-assignment sites. Two porting hazards: (1) every playhead advance
that bypasses `run_goto` needs its own mark — the equivalent of our
`run_frame_internal`'s `current_frame++`, which broke the boot until marked;
(2) the dirty-orphan list holds `DisplayObjectWeak`, so entries need an upgrade
check on use.

**Note.** gc-arena lets Ruffle's orphan list shrink when entries become
unreachable, which we cannot do mid-tick. That did not save it on Elephant Quest
— the tiles are held live by the game's own `this.tiles` array — but it is a real
advantage on other workloads, and belongs in the writeup.

### §1.3a / §1.4 runtime inline caches — B, portable, mostly redundant

**What we do.** Per-site monomorphic ICs on GetProperty / CallProperty /
CallPropVoid / SetProperty (vtable identity + count guard → replay slot index),
and a scope-hit IC on findpropstrict.

**What Ruffle does.** Nothing at runtime. There is no cache structure anywhere in
`core/src/avm2/` attached to an op site: `value.rs::Value::get_property` goes
`self.vtable(activation)` → `VTable::get_trait` → `PropertyMap` probe on *every
execution* of a `GetPropertyStatic` the optimizer could not rewrite. The
optimizer's static rewrites (see the §1 A-writeup) cover the typed cases so
thoroughly that the residue is genuinely dynamic: untyped (`*`/`Object`) locals,
`with` scopes, `Dictionary`-ish access, and receivers whose class the abstract
interpreter widened to `any`.

**Verdict: portable, low expected value, worth measuring before proposing.** An
IC keyed on `Gc::ptr_eq` of the vtable would be a small `Cell<Option<(…)>>` on
the op — no borrow-discipline problem, since ops already live in a
`&[Cell<Op>]` during optimization and in `VerifiedMethodInfo::parsed_code`
afterwards. The reason to be cautious is that Ruffle would be paying cache
maintenance for the *cold* residue: our IC's measured value on Seedling was
~15 ms of a 62 ms frame *because our runtime had no static resolution at all at
that point*. **Could not determine without a measurement**: what fraction of
Ruffle's executed `GetPropertyStatic`/`CallProperty` ops survive the optimizer on
a real title. The measurement is a counter in `Activation::run_loop`'s
`Op::GetPropertyStatic` arm on a local Ruffle build, run on RWK and Seedling —
deliberately not done this session, since the checkout is read-only.

### §1.10 blit SIMD — B, portable, and the hard part is already built

**What we do.** `bd_copy_pixels`/`bd_draw` dispatch whole rows as 4-px WASM-SIMD
spans (`blend_over` / `copy_force_opaque` / memcpy), byte-exact via the
`(x*32897)>>23 == floor(x/255)` identity, `-msimd128` in `build_wasm_avm2.sh`,
with a scalar fallback.

**What Ruffle does.** Scalar per-pixel loops. `core/src/bitmap/operations.rs` has
~20 `for y in … { for x in … }` nests (`copy_pixels_impl`,
`copy_pixels_with_alpha_source`, `fill_rect`, `flood_fill`, `perlin_noise`, …),
none vectorized. The only SIMD mention in the whole tree is a TODO in
`render/src/matrix.rs`: "Consider using portable SIMD when it's stable".

**Verdict: portable, and the expensive prerequisite already exists.** Ruffle
already ships **two** wasm binaries with runtime feature detection:
`web/packages/core/tools/build_wasm.ts::buildWasm` builds the `extensions` flavor
with `target-feature=+bulk-memory,+simd128,+nontrapping-fptoint,+sign-ext,+reference-types`
and (under `BUILD_WASM_MVP`) a vanilla fallback. So the dual-build and
dispatch problem — the part that cost us build-script work — is solved there. The
remaining cost is real but bounded: Rust's `std::simd` is unstable, so the code
would be `core::arch::wasm32` intrinsics behind `#[cfg(target_feature = "simd128")]`
with the scalar loop as the `#[cfg(not(...))]` arm, or a crate like `wide`. Our
byte-exactness identity transfers verbatim and is the part worth contributing.

**Which workload would show it:** Seedling-shaped titles that `copyPixels` a
full-screen buffer each frame. Our measured value was ~1.4 ms of ~24 ms (~6%),
fastest in 11/11 paired rounds.

### §L5a compare→branch fusion — B, portable, and Ruffle currently moves away from it

**What we do.** Emit `if (lessthan_test(a, b)) goto L;` — no boolean is
materialized, no boxing, no second dispatch.

**What Ruffle does.** The opposite, deliberately. `avm2/verify.rs::translate_op`
takes ABC's *already-fused* `AbcOp::IfLt { offset }` and **splits** it into two
ops — `Op::LessThan` followed by `Op::IfTrue { offset: offset - 1 }` — and does
the same for `IfLe`, `IfNge`, and the rest of the family. `Op::LessThan` is
implemented by `activation.rs::op_less_than`, which pushes a `Value::Bool` onto
the operand stack; `Op::IfTrue` then pops and tests it. Nothing re-fuses:
`optimizer/peephole.rs::postprocess_peephole` has rules for `Dup+SetLocal`,
`SetLocal+GetLocal`, `Add+CoerceI`, `CoerceB` before branches — but no
compare+branch pair rule, and `op.rs` has no fused `IfLt`-style op to fuse into.

The split is not an oversight: it makes every op single-purpose for the abstract
interpreter, which is what lets `type_aware.rs` reason about the boolean.

**Verdict: portable, with a stated cost.** Adding `Op::IfLessThan { offset }`
(and siblings) plus a peephole pair rule is mechanical; the cost is that
`abstract_interpret_ops` needs arms for the fused ops, and `process_jump` needs
to handle a compare-and-branch as one state transition. Two ops become one:
one dispatch, one stack round-trip, and no `Value::Bool` materialization saved
per comparison. Our measured value for the whole of lever 5 was ~1.1x (mean/p50),
of which the fusion was the larger half; on an interpreter with a heavier
per-op cost, the relative win should be **larger** than ours, not smaller —
which makes this the highest-expected-value item on this list.

### §4.4 button-hover walk gate — B, portable, with a real hazard

**What we do.** Run the per-frame button-hover walk only on mouse-move
(`b3e45b9e2`).

**What Ruffle does.** `player.rs::Player::update_mouse_state` computes
`let new_over_object = if mouse_in_stage { run_mouse_pick(context, true) } else { None };`
**unconditionally**. It is called from `Player::update` (:2382) with
`changed_mouse_buttons = EnumSet::empty(), is_mouse_moved = false`, and
`Player::run_frame` goes through `Player::update` — so the full hit-test pick
runs on every frame whether or not the mouse moved. Ruffle *has* a
`skip_mouse_hover` flag computed right above (`!is_mouse_moved &&
changed_mouse_buttons.is_empty() && context.mouse_data.hovered.is_some()`), but
it gates only the hover-change *event dispatch* further down
(`if !skip_mouse_hover && !InteractiveObject::option_ptr_eq(...)`), not the pick
itself.

**Verdict: portable, but the naive gate is wrong and Ruffle's code shows why.**
The pick's result is also consumed to cancel hover when the hovered object
disappears under a stationary mouse — `update_mouse_state` explicitly clears
`skip_mouse_hover` when `!hovered.as_displayobject().visible()`, and separately
handles `hovered.avm1_removed()`. So a mouse-move-only gate needs a
display-list-dirty escape hatch (hover target removed, hidden, or re-parented),
which is exactly the reason ours is scoped to N rather than made general.
A defensible upstream version: skip the pick when the mouse has not moved **and**
no display-list mutation has occurred since the last pick, tracked with a single
context-level counter.

### §L7 / §2.7a fingerprint-gated native intrinsics — B (mechanically), policy-blocked

**What we do.** Pool-normalized FNV-1a fingerprint of ABC method bodies matches
`org.flixel::FlxQuadTree`+`FlxList` (and `FlxTilemap.arrayToCSV`); on exact match,
class-link installs a native C implementation, order-identical to the source. Any
mismatch falls through to the game's own code (fail-safe). Measured 2.59x native
wall-clock; RWK rig 60.8 → 21.6 ms.

**What Ruffle does.** Nothing like it — and this is the row where it was most
tempting to write "structurally impossible", so it got the closest reading.

What Ruffle *has*: a complete native-method substrate.
`avm2/method.rs::MethodKind::Native { native_method, fast_call }` lets any method
be backed by Rust; `globals.rs::native` includes a build-generated
`native_table.rs` binding playerglobal declarations to Rust functions; and
`optimizer/type_aware.rs::maybe_optimize_static_call` will rewrite a
`CallMethod` into `Op::CallNative { method }` when the receiver's class is final
and the argument types match. Installing a native body over a class's methods is
therefore already an expressible operation.

What Ruffle does *not* have: any content fingerprinting of user ABC. Its only
per-content compatibility machinery is `core/src/compatibility_rules.rs`, which
is **host-based URL rewriting** (`UrlRewriteRule { stage, fetch_reasons, host,
replacement }`) — not a behavioural swap, and not keyed on code identity. There
is no precedent to point at.

**Verdict: B, portable in mechanism; blocked by policy, not architecture.**
Nothing in gc-arena, the borrow discipline, or the interpreter loop prevents
hashing method bodies at ABC load and swapping in a native class. What would
prevent it in practice is Ruffle's correctness-first project stance: replacing a
game's own code with a reimplementation makes every divergence in the
reimplementation a silent behavioural bug in a player whose entire value
proposition is fidelity. Our fail-safe design (exact match or fall through)
answers that objection, and the honest thing to say is that this is a *proposal
Ruffle would have to accept*, not a patch it would merge on technical merit
alone.

**This is also the least-general of our wins.** It is per-engine (Flixel) and
partly per-title (obfuscated 2.35 needs per-title constants). Counting it as an
architectural advantage would overstate the case; it is an engine-specific
accelerator that any player could adopt.

---

## Category C — structurally impossible in Ruffle

**Empty.**

This was the bucket the prompt flagged as the likely source of error, so it is
worth stating what was checked and rejected:

- **The walk gate** looked like a candidate (a mutable flag threaded through a
  GC'd tree during traversal) and is not: `DisplayObjectBase` already carries
  `Cell`-based flags, and `Gc::write`/`unlock!` handles the barrier.
- **The weak orphan registry** is *theirs first*, not something they can't have.
- **Runtime inline caches** looked like a candidate (mutating verified code) and
  are not: verified ops already live behind `Cell` during optimization.
- **Native intrinsics** are the closest call and resolve to policy (above).
- **Raw-alloc reclamation** and **arena right-sizing** are problems Ruffle's
  memory model does not have, which is the opposite of a structural block.

If a future entry does belong in C, the bar set here is: name the specific
Ruffle type or invariant that forbids it, quoting the code.

---

## §D Category D — AOT-only

**Zero catalog rows**, and that is the finding — but it is not the whole story,
because the AOT advantage is real and simply is not shaped like a catalog row.

### What AOT actually buys, stated precisely

Take the single best-corresponded pair in this document: our `this.field` slot
specialization and Ruffle's `optimize_get_property` → `Op::GetSlot { index }`.
The *analysis* is the same (and Ruffle's is better-informed, running after class
linking). What differs is what the analysis result costs to execute:

| | Ruffle | Us |
|---|---|---|
| Result of the analysis | `Op::GetSlot { index: K }` in `VerifiedMethodInfo::parsed_code` | `slots[K]` in generated C |
| Per execution | dispatch through `Activation::run_loop`'s `match op`, `pop_stack()` (a `Value` enum move), `TObject::get_slot` → `ScriptObjectWrapper::get_slot` → `Box<[Lock<Value>]>` index, `push_stack()` | one load; the index is a C constant |
| Cross-op optimization | none — each op is an opaque interpreter step | full: gcc/LLVM CSEs repeated slot reads, hoists them out of loops, keeps them in registers across ops |
| Where types live | `Value` enum tag, checked per op | often erased entirely by typed emission |

So the AOT win is a **uniform multiplier on the whole op stream**, not a
capability. Every `[RC]` row in §1 is category A for its idea and inherits this
multiplier for its execution. That is why the arc's per-lever numbers were real
even though each lever's *idea* already existed upstream: we were applying known
transforms to a substrate where they pay several times more.

The nearest interpreter-shaped equivalent would be a JIT — i.e. a different
project, exactly as the prompt's category definition says. Ruffle's optimizer is,
in effect, the front half of a JIT with no back end.

### The one thing that is genuinely ours by construction

Not a catalog row, but worth recording: because we emit C, **the C compiler is
part of our optimizer**, and improvements to it accrue to us for free. Ruffle's
equivalent leverage — LLVM optimizing the *interpreter loop* — does not compound
with the SWF's own structure. This is the durable form of the advantage, and it
is also why our Ir-vs-wall-clock rule (§7.1 of the catalog) keeps biting: removing
ops from a stream the compiler was already optimizing well often removes fewer
cycles than the instruction count suggests.

---

## §6 bonus pass — does Ruffle ship what we rejected?

| Our rejected candidate | Does Ruffle do it? | Note |
|---|---|---|
| Flixel quadtree **pooling** | No | No user-object pooling anywhere; consistent with our arithmetic-first kill |
| **inline slots** (object+slots in one alloc) | **No — same choice we ended at** | `script_object.rs::ScriptObjectData::slots` is `Box<[Lock<Value>]>`, a separate allocation. Different reason (Rust layout convenience vs our o1heap binning), same conclusion |
| **nursery / generational GC** | **No** | gc-arena is non-generational: `arena.rs::CollectionPhase` has no nursery phase, and `metrics.rs::Pacing` has no young/old split. The most mature GC in this comparison also declined to go generational — corroborates our <1.10x ceiling ruling |
| `add` numeric fast arm | **Yes — and Ruffle gets right what we got wrong** | `activation.rs::op_add` does `(Integer, Integer) => n1.checked_add(n2)` and **stays `Value::Integer`** on no-overflow, falling to `f64` only when it overflows. Our arm flattened int+int to NUMBER, which was observable, so we reverted the whole arm. **Finding: the idea was sound; the bug was kind preservation.** Worth revisiting with Ruffle's overflow-checked form |
| call devirtualization | **Yes** | `optimize_call_property` → `Op::CallMethod { disp_id }`, and `maybe_optimize_static_call` → `Op::CallNative` for final-class fast-call natives. We gated it out because our calls were already IC'd and static calls never missed — a different starting point, both defensible |
| non-`this` instance-slot GET spec | **Yes, unconditionally** | Ruffle's `optimize_get_property` doesn't care whether the receiver is `this`; any statically-typed receiver gets `GetSlot`. Our census found 0 newly-specializable sites, which is a statement about our corpus, not the transform |
| `ABC_OPT=-O2/-O3` | n/a | No generated TUs to compile |
| AVM1 full-tree subtree-pruning recompute | Moot | `clip_exec_list` (§4.3) makes the recompute unnecessary by construction |

**Two things to take from this pass.** First, the `add` row is a genuine
actionable finding: we reverted a lever for a fixable bug, and the reference
implementation shows the fix. Second, the nursery row is the most reassuring
result in the document — an independent, mature GC reached the same conclusion we
did by arithmetic.

---

## Open questions (explicitly unsettled)

Marked per the prompt's rule that uncertainty is a legitimate verdict.

1. **How often does Ruffle's optimizer actually fire on our corpus?** Every
   category-A verdict in §1 rests on the optimizer's *capability*, which is read
   from code. Whether it fires on Flixel's ASC output, on RWK's obfuscated 2.35
   ABC, or on Elephant Quest's jmtb02 engine depends on how many declared types
   survive in that bytecode. **Settling measurement:** a counter incremented in
   the `optimize_op_to!` macro in `optimizer/type_aware.rs`, aggregated per
   method, on a local Ruffle build running each title. Not done — the checkout is
   read-only this session.
2. **Expected value of the three unmeasured B rows.** Compare→branch fusion
   (§L5a), blit SIMD (§1.10), and the hover gate (§4.4) are all "portable and
   plausibly worth it", but the sizes are ours, not theirs. **Settling
   measurement:** profile Ruffle on Seedling (blit), RWK (fusion), and an
   N-style hover-heavy SWF (pick), attributing to `op_less_than`,
   `bitmap::operations::copy_pixels_impl`, and `run_mouse_pick`.
3. **Whether the walk gate's win survives Ruffle's smaller constant.** §3 records
   Ruffle taking ~18 s on the Elephant Quest build loop against our pre-gate
   >1000 s, i.e. a ~20-40x smaller per-node constant. The gate is O(n²) → O(n) so
   it should still dominate, but the crossover point on smaller titles is
   unknown.

---

## Cross-references

- Catalog being annotated: [`performance-optimizations.md`](performance-optimizations.md)
- Per-lever A/B evidence: `tools/divergence/perf/RWK_AB_STATUS.md`,
  `tools/divergence/perf/SEEDLING_AB_STATUS.md`
- Session prompt: [`../prompts/perf-optimizations-ruffle-applicability.md`](../prompts/perf-optimizations-ruffle-applicability.md)
- Ruffle checkout recovery: [`ruffle-local-patches.md`](ruffle-local-patches.md)
- Memory: [[swfrecomp-purpose-beat-ruffle-perf]],
  [[rwk-ruffle-gap-is-1_3x-not-11x]], [[avm2-goto-catchup-walk-gate]],
  [[avm2-flixel-native-intrinsic]], [[avm2-gc-tier2-collector-cost]],
  [[ruffle-optimizer-already-does-our-rc-levers]]
