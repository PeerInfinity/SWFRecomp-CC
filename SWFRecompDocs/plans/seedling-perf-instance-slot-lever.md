# Seedling perf — next lever scoping: instance-slot specialization for non-`this` typed receivers

This file IS the session prompt (below). It scopes the extension of compile-time
slot specialization from `this.field` (Step 2) + `Class.staticField` (Step 3 lever B)
to **non-`this` instance receivers of a statically-known sealed ABC class**, the #1
open lever from the 2026-07-15 post-#1/#2 re-profile (GET/property-resolution cluster
~29.5% wasm self-time; `resolved_get` 8.3% + `avm2_op_getproperty_static_ic` 6.7%).

---

## SESSION PROMPT (paste this)

Start a new perf lever for Seedling: **extend compile-time slot specialization to
non-`this` instance receivers whose static type is a known sealed ABC class** — emit a
bare (guarded) `slots[K]` load instead of `avm2_op_getproperty_static_ic` for
`GetPropertyStatic` sites whose receiver operand is a typed local/expression of a
concrete sealed ABC class C. This is the natural continuation of the Step-2 (`this.field`)
and Step-3-lever-B (`Class.staticField`) slot arc, targeting the residue of the ~6.7%
`avm2_op_getproperty_static_ic` + ~8.3% `resolved_get` self-time (the IC *hit* still pays
a vtable-identity check + count guard + `resolved_get` dispatch).

### READ FIRST
- `SWFRecompDocs/plans/seedling-perf-compile-time-specialization.md` — the whole
  compile-time slot arc (Steps 2/3A/3B/4/5), the `AVM2_SLOT_VERIFY` infra, the A/B rig,
  and **the Step-4/Step-5 lesson: both closed below noise because the hot leaf m676
  (`Image.render`) has nothing addressable (native `flash.geom`).** Do not repeat that
  mistake — gate FIRST.
- Memories: `[[seedling-fresh-profile-poststep4-lever-map]]` (the 2026-07-15 re-profile
  section — GET cluster is now decisively #1), `[[seedling-perf-compile-time-specialization]]`,
  `[[seedling-perf-hotpath-is-property-lookup]]`, `[[seedling-blit-simd]]` (last lever's
  measurement lessons), `[[windows-playwright-from-wsl]]` (the real-GPU A/B rig).
- `tools/divergence/perf/SEEDLING_AB_STATUS.md` (session 8, blit) — the A/B method +
  the lesson that a *toggle* A/B can hide the real win; measure **NEW-vs-master**, not
  only the isolated toggle.
- Fresh profile: `tools/divergence/perf/seedling_profile_2026-07-15_post_blit.json`.

### THE SEAM (recompiler)
The existing forward abstract-interp `analyzeSlotSpec` already tracks a static type per
stack slot. In `SWFRecomp/src/abc/abc_emit.cpp`:
- Lattice: `enum TK` + `struct TV { TK k; int inst; }` at **`abc_emit.cpp:908-909`**
  (`TK_INST` + `inst` = ABC instance index). Stack-slot model `struct SV { bool is_this;
  int fp_mn; int cls; TV type; }` at **`abc_emit.cpp:1271`**; locals `localTy` at
  **`abc_emit.cpp:1286`** (seeded: local 0 = `TV{TK_INST, thisCls}` at 1288; params via
  `typeOfMn` at 1290-1291).
- **GetPropertyStatic handler at `abc_emit.cpp:1379-1413`** — TODAY it branches on
  `recv.is_this` (lever A, 1383-1391) and `recv.cls` (lever B statics, 1401-1406), and
  uses `recv.type` only to type the *result* (`memberReadType`, 1409-1410). **The missing
  branch:** when `recv.type.k == TK_INST` on a sealed class → instance slot read. Add it
  here, reusing the existing helpers against `recv.type.inst`:
  - `isSealed(inst)` — `abc_emit.cpp:965-969` (sealed && !interface).
  - `findUniqueSlot(inst, name)` — `abc_emit.cpp:1012-1032` (unique Slot/Const across the
    super chain; `hits != 1` bails).
  - `subclassRedeclares(inst, name)` — `abc_emit.cpp:1039-1056` (**essential here — a
    non-`this` receiver of a non-final class can hold a SUBCLASS instance; the slot index
    is only valid if no subclass shadows the name**).
  - `computeSlotIndex(declInst, traitIdx)` — `abc_emit.cpp:1059-1075` (returns -1 unless
    the full chain is ABC-to-Object, via `inheritedBase` 980-986 / `slotCountOf` 990-1007;
    mirrors the runtime numbering exactly).
- Emit site: case `GetPropertyStatic` at **`abc_emit.cpp:353-368`**; `slotSpec>=0` emits
  the fast op, else the IC. Driver passes `slotSpec[i]` at `abc_emit.cpp:1592-1596, 1651`.

### THE CORE DESIGN PROBLEM (why this is the hardest lever): NULLABILITY
`avm2_op_getproperty_slot` (`SWFModernRuntime/include/avm2/avm2_ops.h:103-108`) is a bare
`recv.u.obj->slots[slot]` with **NO null/object check** — sound for `this` (always a
non-null object) but a non-`this` typed receiver can be **null** at runtime, where
`getproperty` must throw TypeError #1009. So the new lever needs a **guarded** slot op,
e.g. `avm2_op_getproperty_slot_guarded(act, recv, slot, mn_idx)`:
`if (recv.kind==AVM2_VALUE_OBJECT && recv.u.obj) return recv.u.obj->slots[slot]; else
return getproperty_static_impl(...)` (the slow path throws #1009 correctly, and also
covers the rare case the static type was `*`-widened). This guard (a kind+null test) is
still much cheaper than the IC hit (vtable fetch + identity + count guard + `resolved_get`
switch), but it is a *smaller* per-site win than `this`'s unguarded load — factor that
into the payoff expectation. Emit the guarded op for the new branch; keep the unguarded
`avm2_op_getproperty_slot` for `this`/static.

### SOUNDNESS CONDITIONS (all required)
1. `recv.type.k == TK_INST` and `recv.type.inst` is a **concrete sealed ABC class**
   (`isSealed`), NOT an interface, NOT `Object`/`*`/native (`flash.geom` Matrix/Point/etc.
   have no ABC ivtable → `computeSlotIndex` already returns -1; keep that).
2. Name → **unique** Slot/Const instance trait (`findUniqueSlot`), NOT a getter.
3. **No subclass redeclares** the name (`subclassRedeclares`) — the runtime value may be a
   subclass; slots inherit by index only if unshadowed.
4. `computeSlotIndex > 0` (full ABC chain to Object).
5. Path-invariant receiver type only — the lattice already resets stack/local types to
   UNKNOWN at branch-target merges (`abc_emit.cpp:1352-1357`), so only provable types
   drive it. Do not weaken this.

### VALIDATION (reuse Step-2/3 infra — it already covers non-`this`)
- **`-DAVM2_SLOT_VERIFY`** (`SWFModernRuntime/src/avm2/avm2_ops.c:583-623`) already
  cross-checks compile-time K vs a full runtime `resolve_mn` for an arbitrary object
  receiver (checks `recv.kind==OBJECT && non-null`, slot-in-range, resolve→Slot, index
  match) and `avm2_fatal`s on mismatch — it validates the new branch as-is. Point the
  guarded op's verify build at the same check.
- Add a dedicated **`SWF_NO_INST_SLOT`** env toggle (disable ONLY the new instance-receiver
  branch) for a clean isolated A/B, alongside the existing `SWF_NO_SLOT_SPEC`.
- Full-suite verify CI (`-DAVM2_SLOT_VERIFY` via `SWFRECOMP_EXTRA_DEFINES` / the CI
  `extra_defines` input) must hold avm2 829 with ZERO slot-verify aborts, and normal
  no-graphics CI byte-identical. Autonomous commit/push/CI authorized per
  `.claude/pipeline-handoff.md` (no-graphics mode).

### ★ STEP 0 — MANDATORY GATE BEFORE WRITING THE LEVER (measure-first, twice-vindicated)
The whole go/no-go turns on whether the HOT drivers actually read typed-ABC-class
instance fields. Do this first:
1. **Census**: add a temporary emit counter — how many `GetPropertyStatic` sites would
   newly specialize under the rule above, and (crucially) tag which recompiled method
   each is in. Compare to the 5039 `this` + 1432 static sites.
2. **Hot-path check**: cross-reference the newly-specializable sites against the hot
   methods in the fresh profile — the leaf **m676 `Image.render` is native `flash.geom`
   → will NOT specialize** (expected). The hot DRIVERS to check are **m7**
   (`Engine.update`/`render`), **m501**, **m225**, **m94**, **m978**, **m992** (from the
   Step-5 gate analysis in the plan doc). Do those access typed-ABC-class locals/params
   (e.g. FlashPunk `Entity`/`World` fields — `e.x`, `e.type`, `other.world`)? If yes → the
   lever pays; proceed. **If the hot drivers' getproperty hits are dominated by `this`,
   getlex-class, or native receivers (already specialized or unspecializable) → the lever
   is below-noise like Steps 4/5 → STOP and write it up as gated-out, do not ship dead
   complexity.**

### A/B MEASUREMENT (apply the session-8 blit lessons)
- Build BOTH variants FRESH (`.o` cache keys on mtime, not `-D` flags) with
  `EMCC_CFLAGS=--profiling-funcs`: `seedling` (lever on) and `seedling_before`
  (`SWF_NO_INST_SLOT=1`). Deploy via `deploy_wasm_avm2.sh`; interleave with
  `tools/divergence/perf/ab_interleave.sh` (6 rounds, WSL idle — the Windows A/B shares
  cores). **Also measure NEW-vs-master** (a third `seedling_orig` from master) — the
  session-8 blit A/B showed the isolated toggle can sit at noise while the real win shows
  vs master. Real-GPU rig per `[[windows-playwright-from-wsl]]` (`seedling_perf_win.py`,
  confirm adapter `intel / gen-9`, NOT SwiftShader). Re-profile with
  `seedling_cdp_profile_win.py` to confirm `getproperty_static_ic`/`resolved_get` dropped.

### HONEST FRAMING
The north-star (beat Ruffle's browser perf) is already met (~1.4× faster). This is the
one remaining lever big enough (~6.7% + ~8.3% cluster) to *plausibly* clear the
±0.5–1 ms noise — but the nullability guard shrinks the per-site win, and if Step-0 shows
the hot drivers aren't typed-ABC-receiver-heavy, expect a below-noise result (Steps 4/5
pattern). Ship only if the gate + a clean A/B (unanimous rounds, above noise) justify it;
otherwise write it up as gated-out. Byte-exactness / slot-correctness is non-negotiable
regardless (the `AVM2_SLOT_VERIFY` full-suite CI is the proof).

---

## ★ STEP-0 FINDINGS (2026-07-15) — GATE CLOSED: lever NOT built (below-noise, Steps-4/5 pattern)

The mandatory measure-first gate was run and **closed the arc without writing the
lever** — the third consecutive lever (after Step 4 coercion-elision and Step 5
call-devirt) whose Step-0 census proves the hot path has nothing addressable. **No
runtime/recompiler code was shipped; this is a pure read-only census.**

**Method.** Added a temporary `SWF_CENSUS_INST_SLOT` counter to `analyzeSlotSpec`
(reverted after measuring — nothing to ship) that, for every `GetPropertyStatic`
site, records the receiver provenance and — for non-`this` typed-ABC-class
receivers — whether it would newly specialize under the full soundness rule
(`isSealed` + `findUniqueSlot` + `!subclassRedeclares` + `computeSlotIndex > 0`),
tagged by `method_index`. Recompiled Seedling's ABC and cross-referenced the
per-method counts against the fresh profile's hot GET-cluster drivers
(`seedling_profile_2026-07-15_post_blit.json`, GET-cluster =
`resolved_get` + `getproperty_static_ic` + impl/public, attributed to the nearest
`abc0_m*` ancestor frame).

**Census (all 25,738 `GetPropertyStatic` sites in Seedling):**
| provenance | sites | status |
|---|---|---|
| `this.field` (lever A) | 5,826 | DONE |
| getlex-class (lever A) | 13,335 | DONE (find IC; the class read itself is IC'd) |
| `Class.staticField` (lever B) | 1,903 | DONE |
| **non-`this` typed-ABC-inst (candidate)** | **992** | the new lever's pool |
| — reject: unsealed | 26 | |
| — reject: name not a unique slot | 344 | |
| — reject: subclass redeclares | 0 | |
| — reject: slot index ≤ 0 | 1 | |
| — **NEWLY SPECIALIZABLE** | **621** | |

**The kill: the 621 are NOT on the hot path.** Cross-referenced against the 14
hottest GET-cluster drivers (m676 16.7%, m224 13.5%, m269 13.2%, m225 9.3%,
m32 8.4%, m94 5.9%, m95, m488, m978, m677, m252, m839, m478, m992 — together
~3.03 s of the 3.18 s GET-cluster self-time):
- **Top-5 drivers (m676/m224/m269/m225/m32 = 61% of GET-cluster cost): ZERO
  newly-specializable sites.**
- Only **m94 (2 sites)** and **m992 (2 sites)** touch the hot set at all → the new
  lever reaches **4 of 993** hot-driver static-get sites (**0.4%**), covering ~8%
  of hot GET time only through two lower-tier drivers.
- The 621 sites concentrate in **cold/startup methods absent from the profile**:
  m624 (30), m288 (20), m2984 (20), m376 (17), m98 (16), m241/m242 (16)…

**Why the hot drivers don't specialize — provenance of their 993 static gets:**
`this` 18% (lever A ✓) + getlex-class 47% (lever A ✓) + classobj 23% (lever B ✓)
+ **native/dynamic `flash.geom` (Matrix/Point/BitmapData — no ABC slot layout,
unspecializable) 11%** + **new typed-inst 0.4%**. That is **99.6% already-optimal
or structurally unaddressable.** The residual `resolved_get`/`getproperty_static_ic`
self-time in these methods is exactly what the fresh-profile note predicted:
"native-receiver + IC-hit overhead, hard." A non-`this` typed-ABC-class instance
receiver (`e.x`, `other.world`) — the pattern this lever needs — is *rare* in
FlashPunk's hot per-frame path; the hot code reads `this.field`, class statics, and
native `flash.geom` fields.

**Verdict — GATED OUT (do not build).** Per this plan's own Step-0 rule ("if the hot
drivers' getproperty hits are dominated by `this`, getlex-class, or native receivers
→ STOP"), the exact condition holds. Building the guarded instance-slot op would add
real complexity (a new nullable-guarded runtime op + emitter branch + verify path)
to accelerate 0.4% of hot-path gets → a change guaranteed below the ±2–3 ms Seedling
noise floor, like Steps 4 and 5. **The compile-time GET-specialization arc is
structurally exhausted for steady-state frame time**: the three fat provenance
classes (this/getlex/classobj) are all specialized, and what remains is native
`flash.geom` (a *different* lever — give Matrix/Point real ABC slot traits, the
fresh-profile lever #4 at ~2.3%) and IC-hit glue (irreducible). The instance-slot
lever is not the residue's shape. See `[[seedling-instance-slot-lever-gated-out]]`.
