# avm2_static_and_store_slots

Regression net for property-arc levers 3+4 (2026-07-19 session) plus the
bitmap identity-self-copy skip:

- **find→own-class-static** (lever A): unqualified own-class-static READ
  (`return staticName;` — mxmlc emits `getlex`, which lowers to the same
  `findpropstrict+getproperty` pair old ASC emits) is the fused
  `avm2_op_getlex_ownstatic` site; unqualified static STORE
  (`counter = counter + 1;`) exercises the standalone guarded find
  (`avm2_op_findprop_ownstatic`) + generic set. Lines 1–4.
- **store-path slot specialization** (lever B): constructor field
  initializers (initproperty on find-substituted `this` receivers — the
  Flixel ctor-churn shape), typed-local receiver stores with the declared-
  type coerce KEPT (`f.intField = v` where v:* = 3.7 → 3), coerce ELIDED
  (null → Object slot, String → String slot, int literal → Number slot with
  runtime coerce), a null typed receiver (#1009 via the fallback path), and
  a `const` slot initialized in the ctor. Lines 5–11.
- **bitmap identity self-copy skip**: `bd.copyPixels(bd, bd.rect, (0,0))`
  must leave pixels unchanged (the skip), and a disjoint-rect self-copy
  still copies. Lines 12–13.

Expected output generated with the Ruffle exporter oracle
(`--trace-log`), then adjusted on ONE line:

**Caveat, line 2 (`2 sub-instance`):** `Sub` declares an INSTANCE var with
the same (public) name as `Base`'s STATIC; `Base.readStatic()` on a `Sub`
instance resolves the unqualified name against the scope walk, whose first
probe (`this`) hits the instance trait — our runtime prints `sub-instance`.
Ruffle prints `base-static` because its verifier/optimizer EARLY-BINDS
lexical references from the static scope types (avmplus does the same, so
real Flash also prints `base-static`). Pre-existing divergence of our
purely-dynamic scope walk, NOT introduced by the levers (identical output
with `SWF_NO_FIND_STATIC=1 SWF_NO_SET_SLOT=1`); the lever's runtime cache
guard (this-vtable identity) deliberately preserves our dynamic semantics —
on a `Sub` receiver the fused op's guard misses and the full walk runs. If
verifier-style early binding is ever implemented, update this line to
`base-static`.
