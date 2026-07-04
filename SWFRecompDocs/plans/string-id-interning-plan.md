# String-ID Interning — Full Plan

**Created:** July 4, 2026
**Status:** Planned, not started. Umbrella plan; subsumes
[`wasm-game-performance-step3-string-interning.md`](wasm-game-performance-step3-string-interning.md)
(2026-06-02) as Stage 2.
**Origin:** #1 actionable idea in
[`../upstream-comparison/upstream-architecture-advantages.md`](../upstream-comparison/upstream-architecture-advantages.md);
upstream's merged master is the reference implementation (design, not code).

---

## 1. Motivation and honest expectations

Property/variable **name handling** has been the dominant AVM1-side CPU cost since
profiling began (June 2026, `SWFRecomp/scripts/profile_game_native.sh`):

- Initial DJ profile: ~67% of instructions in property-name lookup.
- After landed mitigations (fold-hash gate `537951f4f`, per-object hash index
  `e13388a18`, MC-resolution caches `6308c4a03`, walk pruning `5f2530446`,
  ASCII fast-paths `b7f1a1759`, ng_syncVarToTextFields fast-reject `ca31201a1`):
  the residual name complex is **~40% of N's no-graphics profile**
  (name_fold_hash ~13%, findPropertySlot ~8%, UTF-8↔UTF-16 conversion + malloc
  ~15%) and `actionGetMember` is ~11.5% of Minesweeper's.

**Expectation management:** the profiled games are currently GPU-bound (N, after
`fee8f23f7`) or frame-cap-idle (DJ at ~3% budget). Interning buys **CPU%/battery,
headless/CI throughput, and headroom for heavier titles** — not wall-clock FPS on
today's games. That is why this plan is staged with measurement gates: each stage
must re-justify the next.

## 2. What already exists (do not re-plan it)

Three interning-like mechanisms are already live — the plan builds on them:

| Mechanism | Where | What it covers |
|---|---|---|
| Constant-pool `string_id` on stack strings | recompiler emits `PUSH_STR_ID(str, len, id)`; id at stack offset +12 (`action.h:227`, `action.c:40211`) | Every literal name already carries an id at runtime |
| Variable id-array fast path | `var_array` / `getVariableById` (`variables.c:131`) — O(1) array indexed by string_id | Global variable access by constant name |
| Object-property hashing | `ASProperty.name_hash` (case-folded FNV-1a) + hash-gated scan + lazy per-object open-addressing `hash_index` ≥12 props, all funneled through `findPropertySlot` (`object.c:196`) | Object/dynamic-prop lookup is already ~O(1); *not* a strcmp scan |
| UTF-16 per-id cache | `app_context->str_cache` in `push_str_id_fn` (`action.c:339`) | UTF-8→16 conversion of constants (one direction only) |

**The actual remaining hot spots**, per the July 2026 code survey:

1. **MC builtin-property dispatch ladders** — four generated-code entry points
   match builtin names (`_x`, `_currentframe`, …) with long `strcasecmp` if-ladders
   on the UTF-8-decoded name, and **discard the string_id sitting on the stack**:
   `actionGetMember` (`action.c:50800`, ~27 strcasecmps worst case),
   `actionSetMember` (`:46741`, ~40), `actionGetVariable` (`:40184`, ~23),
   `actionSetVariable` (`:42020`, ~13), plus two near-duplicate helpers
   `getMCBuiltinProperty`/`setMCBuiltinProperty` (`:56290`/`:56317`, used by
   initObject/with/attach paths). ~95 of action.c's 154 strcasecmp call sites.
2. **Per-lookup query hashing** — `name_fold_hash` runs once per property access
   even though constant names hash to the same value every time.
3. **UTF-16→UTF-8 conversion** — member/variable opcodes pop a UTF-16 stack name
   and convert to UTF-8 (`u16_to_utf8` + malloc) before lookup.

## 3. Upstream reference: what we adopt, what we deliberately don't

From upstream master (`4e7c773`/`b17653d`; detailed survey July 2026):

**Adopt (as design):**
- One shared **1-based u32 id space**; **`0` = "dynamic, not interned yet"**
  sentinel. (We already have exactly this convention in `PUSH_STR_ID`.)
- Compile-time half: recompiler dedup map → emitted `str_table[]` /
  `str_len_table[]` / `MAX_STRING_ID`, runtime seeded from them.
- Runtime half: hashmap-based interner; `next_str_id` continues past
  `MAX_STRING_ID`; **lazy interning at the access site** when id==0.

**Reject (would regress us):**
- **rbtree keyed by id as the property store.** Our enumeration is
  insertion-ordered over `properties[]` (`actionEnumerate2`, `action.c:44691`)
  and tests depend on that order; id-ordered iteration breaks it. Upstream's
  enumeration is currently unimplemented, so they haven't hit this yet. We keep
  the insertion-ordered array + existing hash_index.
- **Case-blind ids.** Upstream has no SWF<7 case-insensitivity anywhere (two
  spellings = two ids = two properties). We must preserve our
  `prop_name_match`/`fold_key_lower` semantics (`object.c:57`, `variables.c:18`).
  Any id-keyed comparison we add must be either exact-id on top of a
  behavior-preserving fallback, or use **case-folded interning** for the <7 mode.
- Their `string_id==0` GetVariable stub (they crash on dynamic variable names —
  `action.c:1983` upstream). Ours must keep the hashmap fallback path.

## 4. Staged design

Each stage lands independently, is verified byte-identical, and gates the next on
a fresh profile. Stop when the name complex stops being worth the risk.

### Stage 1 — MC builtin dispatch by id (small, highest confidence)

**Idea:** stop discarding the stack string_id in the four entry points. Add a
lazily-populated **per-id classification cache**: `u8* mc_builtin_class` sized
`MAX_STRING_ID+1` (grown if dynamic ids ever consult it), values
`{UNKNOWN=0, NOT_BUILTIN, X, Y, XSCALE, …}`.

- On entry with `id != 0`: `class = cache[id]`; if known, jump straight to the
  builtin's handler (a `switch`) or skip the ladder entirely; if `UNKNOWN`, run
  the existing ladder once and record the answer.
- On `id == 0` (dynamic names): unchanged ladder. No recompiler change needed.
- **Behavior-preserving by construction:** the cache memoizes what the existing
  ladder decides for that exact string; case rules, version gates, and
  per-site chain differences are inherited, not re-implemented. This matters
  because the four ladders are *not* identical (GetVariable's list ≠ GetMember's)
  — so use **one cache per chain variant** (get-member / set-member /
  get-variable / set-variable), not one global.
- The duplicated helpers (`getMCBuiltinProperty`/`setMCBuiltinProperty`) get the
  same treatment (they receive `char*` today — thread the id through their two
  call-site clusters, or leave them if profiling says they're cold).

**Cost:** ~4 sites + a small cache module. **Risk:** low. **Invalidation:** none
needed — constant-pool id→string is immutable for a run.

### Stage 2 — per-id UTF-8 + hash cache on the object-property path
(= the existing Step 3 plan, unchanged; see
[`wasm-game-performance-step3-string-interning.md`](wasm-game-performance-step3-string-interning.md))

Parallel per-id cache of `(utf8 bytes, len, fold-hash)` next to the existing
UTF-16 `str_cache`; a name-extraction helper returning cached utf8+hash for
id!=0; `…H` variants of the lookup funnels taking a precomputed hash (the
internal `findPropertySlot` already takes `qhash`). Wire `actionGetMember`'s
main path first, then SetMember/GetVariable. Kills `name_fold_hash` re-hashing
and `u16_to_utf8` conversion+malloc for constant names.

**Cost:** moderate. **Risk:** low-moderate (hot branchy code; incremental
wiring). Expected combined Stage 1+2: the majority of the remaining ~40% name
complex on N's profile.

### Stage 3 — full key interning (large; only if Stages 1–2 under-deliver)

Names travel as interned ids end-to-end; `ASProperty` gains `u32 name_id` (keep
`name`/`name_hash` during migration); `findPropertySlot` compares ids first.
Requires a global two-way intern table (exact + case-folded id per name for the
<SWF7 mode), dynamic interning on property creation, and touching every
name-producing opcode. Preserves `properties[]` insertion order and the existing
hash_index (ids replace *comparison*, not *storage layout*).

**Gate:** write the detailed design only if the post-Stage-2 profile still shows
≥10% in name handling on a game we care about. Upstream's dynamic-interner shape
(c-hashmap, `next_str_id`, seed-from-table) is the model, with the case-folding
extension they lack.

## 5. Verification protocol (every stage)

1. **Byte-identical outputs first:** `profile_game_native.sh` builds of DJ + N +
   Minesweeper (no-graphics, `MOCK_DATE_TIME` deterministic) — stdout diff must
   be empty vs. pre-change.
2. **Callgrind before/after** on the same three (N is the primary oracle; DJ
   NO_GRAPHICS; Minesweeper for the GetMember-heavy UI path). Record Ir totals
   and the name-complex breakdown in a results doc alongside this plan.
3. **Full CI, both modes** (`object.c`/`action.c` are shared runtime code —
   per the pipeline rules this is a both-modes change). Zero pass→fail.
4. Enum-order sensitive tests are the canary for any Stage-3 work
   (`actionEnumerate2` consumers; array `enum_keys` tests; for-in ordering).

## 6. Risks

| Risk | Mitigation |
|---|---|
| The four ladders differ subtly; a shared cache changes behavior | Per-chain caches; memoize the existing ladder's answer, never re-implement it |
| Case rules (SWF<7 fold vs ≥7 exact) diverge between id path and string path | Stage 1/2 never compare ids across *different* strings — ids only memoize per-exact-id results, and hashes are computed by the same `name_fold_hash` |
| Enumeration order regression (Stage 3) | Ids affect comparison only; `properties[]` stays insertion-ordered; canary tests in §5.4 |
| `id==0` dynamic-name paths silently degrade | Keep string fallbacks permanently; upstream's crash-on-dynamic-variable is the cautionary example |
| Cache memory growth | Per-id arrays are `MAX_STRING_ID`-sized u8/ptr tables — trivial next to str_cache |
| Effort spent on a non-bottleneck | Stage gates: fresh profile after each stage; stop when name complex <10% |

## 7. When to execute

Not urgent: no current title's *user-visible* performance depends on it. Good
opportunistic triggers: a CPU-bound game surfacing via the perf HUD (headroom
≥100%), a batch/headless workload (procgen validation at scale), or simply the
next perf session. Stage 1 is small enough to ride along with any perf-adjacent
session; Stage 2 warrants a dedicated one; Stage 3 needs its own design doc.
