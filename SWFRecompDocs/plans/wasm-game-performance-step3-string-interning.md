# Step 3 plan — string interning / per-id name cache (AVM1 property names)

**Created:** 2026-06-02
**Status:** Planned, not started. Follows optimizations #1/#2 (see
[results doc](wasm-game-performance-profiling-results-2026-06-01.md)).
**Note (2026-07-04):** now **Stage 2** of the umbrella
[string-id-interning-plan.md](string-id-interning-plan.md), which adds a cheaper
Stage 1 (MC-builtin dispatch by id — the strcasecmp ladders) before this and
gates the "bigger alternative" below (full key interning) behind measurements
as Stage 3.
**Prereq context:** property-lookup machinery already optimized (−48.8% on DJ);
the AVM1 interpreter is the browser-CPU bottleneck (graphics-mode cross-check
confirmed rendering is GPU work the browser offloads).

## Target

After #1/#2, the Doodle Jump NO_GRAPHICS profile's remaining top costs are:
- `name_fold_hash` — 17.6% (query name hashed once per lookup)
- UTF-8↔UTF-16 conversion on the stack↔property bridge — ~12.6%
  (`utf8_to_u16` 5.8% + `u16_to_utf8` 4.4% + `utf8_decode_one` 2.4%)

Both are paid repeatedly for the **same literal property names** every frame
("_x", "onEnterFrame", etc.). Property names are almost always bytecode literals
that already carry a constant-pool `string_id` on the stack.

## Mechanism that makes this cheap

`push_str_id_fn` (`action.c:334`) already caches the **UTF-16** form of each
constant string per `string_id` in `app_context->str_cache` /
`str_cache_len`. Stack string values carry their `string_id` at offset +12.

Property opcodes (`actionGetMember`, `actionSetMember`, `actionGetVariable`, …)
pop that UTF-16 name, convert it to UTF-8 (`u16_to_utf8`) to call `getProperty`,
which then hashes the UTF-8 (`name_fold_hash`).

## Design

1. **Add a parallel per-id cache of (UTF-8 bytes, len, fold-hash):**
   `app_context->str_utf8_cache` / `str_utf8_len` / `str_hash_cache`, lazily
   allocated like `str_cache`. Populate on first use of each `string_id`.
2. **Name-extraction helper:** given a popped stack string, return
   `(const char* utf8, u32 len, u32 hash)`. If it has a valid `string_id` and a
   cache hit → return cached (no convert, no hash). Else convert + hash; cache if
   the id is valid.
3. **H-variants of the lookup functions** taking a precomputed `qhash`:
   `getPropertyWithPrototypeH`, `findPropertyStructWithPrototypeH` (the internal
   `findPropertySlot` already takes `qhash`; #2 added `findPropertyRawH`).
4. **Wire the hot opcodes** to use the helper + H-variants on the *main* property
   path (the user-name lookup). Start with `actionGetMember`'s general path
   (highest volume), then `actionSetMember`, `actionGetVariable`.

Most `getProperty(obj, "literal", n)` calls inside these opcodes use short ASCII
constants on special-case branches — leave them (cheap, ASCII fast path). The
win is on the user-name path.

## Risk & validation

- Touches the hottest, most branch-heavy code (`actionGetMember`), so: implement
  incrementally, **verify byte-identical DJ output** after each step
  (`profile_game_native.sh local_batch/Doodle_Jump 500 no-graphics`, diff stdout),
  then full CI in **both** modes (object/action are shared runtime code).
- Cache lifetime ties to `app_context`; free alongside `str_cache`.
- Correctness invariant: cached hash must equal `name_fold_hash(utf8, len)` and
  cached utf8 must round-trip the name — both computed by the same functions, so
  trivially consistent.

## Open question (measure first)

`name_fold_hash`'s 17.6% is spread across *all* lookups (user names + the many
constant-name `getProperty` calls + proto-walk `"__proto__"` hashing), not just
user names. Caching user-name hashes captures only part. **Measure the contained
version (cache + `actionGetMember` main path) before deciding how far to extend.**
Expected: another ~10–20% off the NO_GRAPHICS total; combined with #1/#2 that
would be roughly −60% vs the original.

## Bigger alternative (only if the contained version under-delivers)

Full stack-level interning: names travel as interned integer IDs on the stack
with a precomputed hash, and `properties[]` keys on the ID — eliminating both the
conversion and the per-lookup hashing wholesale (upstream's enum-string-ID
model). Much larger blast radius (stack value representation + many opcodes);
only justified if the targeted cache leaves significant conversion/hash cost.
