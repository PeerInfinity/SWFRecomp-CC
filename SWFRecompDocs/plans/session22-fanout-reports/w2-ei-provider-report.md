# w2-ei-provider: AVM2 ExternalInterface test provider (slot C of `w1-trace-tail-report.md` §11)

**NEW FILES**
- `SWFModernRuntime/include/avm2/avm2_external.h`: the provider surface. It is a header only, so there are no source-list, CMake or Emscripten edits.
- `ruffle-tests/tests/swfs/avm2/external_interface/test_harness.c`: the provider plus the host calls. It is git-tracked through a new `.gitignore` exception.

**MODIFIED FILES:** `SWFModernRuntime/src/avm2/avm2_external.c`, `SWFModernRuntime/src/avm2/avm2_main.c` (+8 lines) and `.gitignore` (+6 lines).
**The patch includes `.gitignore`.** Without it, `test_harness.c` sits in an ignored `avm2/*/` dir and CI never sees it.

## Verdict: GO, landed and verified. +1 trace flip

| test | before (clean origin/master, this box) | after (patch) |
|---|---|---|
| `avm2/external_interface` (graphics) | MISMATCH: 3/105 lines, 7 actual, `Error #2067` | **PASS** |
| `avm2/external_interface` (no-graphics) | MISMATCH | **PASS** |

The upstream test files came from `download_tests.sh` against Ruffle master at session time (`653ef4f41`, 2026-10-17).

## EXPECTED-FLIP LEDGER

| test | trace axis | pixel axis |
|---|---|---|
| `avm2/external_interface` | `fail` (output_mismatch) → **`pass`**, in both modes | none (the test has no `[image_comparisons]` and no PNG) |

Nothing else should move. On CI, any other status change is a regression of this patch.

## Mechanism

Ruffle runs this SWF from `tests/tests/external_interface/tests.rs::external_interface_avm2` with `ExternalInterfaceTestProvider` (`mod.rs`). The test has no `test.toml`. We had only the "unavailable" path: `available == false`, and `addCallback` threw #2067 at script init.

**1. `avm2_external.c`: structured values and the provider hook**

All new code is inert unless a provider is installed.
- **`Avm2EiValue`** is a C-owned tree mirroring Ruffle's `external::Value`. Its kinds are Undefined, Null, Bool, Number, String, List and Object (a sorted-key map, so BTreeMap order).
- **`ei_from_avm2`** ports `Value::from_avm2`:
  - Array → List, with holes read as Null.
  - Any other object → Object over its enumerants, via `avm2_object_next_enumerant`.
  - Integer → Number.
  - Depth is capped at 256. Ruffle would recurse forever on a cycle.
- **`ei_into_avm2`** ports `into_avm2`:
  - Object → a fresh plain Object, with keys set in key order.
  - List → Array.
- **`avm2_ei_set_provider()`**: a non-NULL provider makes `ei_available_now()` return 1.
- **`ei_call`** routes to `ei_provider_call` when a provider is set:
  - It converts the args with from_avm2, calls the provider, and converts the result back with into_avm2.
  - It runs after the existing `available` and `argc` checks, so the error order is unchanged.
- **`avm2_ei_call_internal(name, args, argc)`** is the host→AS3 dispatcher, a port of `Player::call_internal_interface` + `Callback::call`:
  - Unknown name → Null.
  - The callback runs with a null receiver.
  - A throw goes through a catch-all frame (reported as uncaught) and returns Null.
  - The result goes through from_avm2.
- Values cross the boundary only as C trees. The transient AVM2 values live inside one call, and the GC collects only between ticks, so nothing needs rooting.
- The string-first browser `avm2_ei_dispatch` and the `__swfBridge` path are untouched.

**2. `avm2_main.c`: after-tick hook in the native tick loop**

The AVM2 loop had no `g_after_tick_handler` call; only the AVM1 loops had one. The patch adds the same NULL-checked call after each tick's try frame, with a 1-based tick number like `swf_core.c`. It goes in the native loop only, which serves both NO_GRAPHICS and OFFSCREEN_RENDER. The browser loop is untouched. Only test harnesses ever set the handler (grep: the demos and regression `ei_*` harnesses, all AVM1).

**3. `test_harness.c`**
- **Provider:**
  - `ping` → prints `[ExternalInterface] ping` and returns "Pong!".
  - `trace` → prints `[ExternalInterface] trace: <args slice Debug>` and returns "Traced!".
  - `reentry` → prints `starting reentry`, then `avm2_ei_call_internal("callWith", ["trace", "successful reentry!"])`.
  - Anything else → Null.
- **At tick 1**, the five host calls from `tests.rs`, in order: `parrot` (string), `parrot` (`{a:100, b:"string"}`), `freestanding`, the `removeMe` bracket, and `callWith` (`["string", 100, Null, false]`).
- **The Rust `Debug` formatter** follows the AVM1 harness's `ev_format`. It implements:
  - f64 Debug: shortest round-trip, decimal for `1e-4 <= |d| < 1e16` with at least one fractional digit, otherwise exponential.
  - str Debug escaping.
  - `List([..])` and `Object({"k": v, ..})`.

**Non-harness builds behave the same.** Every new branch is gated on `g_ei_provider != NULL` or `g_after_tick_handler != NULL`, and only a `test_harness.c` sets either.

## Canaries (graphics mode, same box, before → after)

| row | before | after |
|---|---|---|
| `avm2/abstract_classes` (uses EI) | PASS | PASS |
| `avm2/missing_external_interface` | PASS | PASS |
| `regression/avm2_external_interface_unavailable` | PASS | PASS |
| `regression/ei_closure_scope_order` | PASS | PASS |
| `regression/ei_cross_swf_version` | PASS | PASS |
| `regression/ei_type1_args` | PASS | PASS |
| `avm1/external_interface` | PASS | PASS |
| `avm1/external_interface_toas_basic` | PASS | PASS |
| `avm1/external_interface_escapexml` | PASS | PASS |

The remaining AVM1 `external_interface_*` and `native_objects_*` rows were not run. AVM1 builds never define `SWF_AVM2` and never link `src/avm2/*.c`, so they cannot see this change.

**Render canary.** I ran the `avm2/` subset of `render_canary_tests.txt` (18 members, `render_canary.py capture/compare`, scratch out dir): **18/18 IDENTICAL by md5**, with no trace or image status changes. The other 449 members are AVM1 builds, which do not link the touched files.

**Regression suite.** The four EI fixtures above all pass. I added no new fixture: the new behaviour is graded by the upstream row itself, whose expected output is Flash/Ruffle's, from outside SWFRecomp.

## CI recommendation
- `mode=graphics categories=full` (AVM2 runtime).
- A no-graphics leg is optional. The touched loop is shared by both modes, and both modes passed locally.

## Unfinished
None.

## New unclaimed leads
1. **The browser AVM2 loop** (`avm2_main.c`, emscripten `while(1)`) has no after-tick hook. Add one if browser-side AVM2 test harnesses are ever wanted.
2. **The browser `__swfBridge` could use the structured layer.** `avm2_ei_call_internal` and the `Avm2EiValue` tree could replace the string-first `avm2_ei_dispatch` / JSON marshaling. That would carry object graphs, which Flash does, instead of `String()` coercion. It is out of scope here, and the bridge contract is JSON strings today.

## LOCAL ORACLE REQUESTS
None.
