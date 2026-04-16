# Splitting `action.c`: Math as First Carve-Out

**Status:** Draft, 2026-04-16.

`SWFModernRuntime/src/actionmodern/action.c` is ~50K lines and recompiles in
~50s at `-O2`. Since most edits to the runtime are inside this file, the
ccache layer added in `d197cfc1` doesn't help our daily loop — each edit
invalidates the cached object and we pay the full cost.

This plan carves out the **Math** subsystem first. Math is the cleanest
available boundary: self-contained, well-defined external surface, and
upstream has already moved Math **out of C entirely** into an AS2 prelude
SWF (see `SWFRecompDocs/merge/upstream-downstream-merge-plan-2024-12.md`
April 2026 update). Extracting Math into its own `.c` is therefore
directionally aligned with upstream, not divergent from it.

## Expected payoff

- Math alone is ~400 lines. A split gets us ~0 lines saved per edit
  to **non-Math** code in `action.c` (cache hits on `math.o`).
- First split proves the pattern: shared internal header, forward
  declarations, Makefile/CMake addition. Subsequent subsystems (Timers,
  Object.registerClass, Super, ClipEvents, Unload, `__resolve`, Selection,
  Settarget) reuse the same pattern.
- After 4–5 subsystems extracted, a typical per-edit compile should drop
  from ~50s to ~5–10s.

## Math subsystem inventory

All line numbers reference `SWFModernRuntime/src/actionmodern/action.c` as of
commit `d197cfc1`.

### What moves to `math.c`

| Section | Lines | Content |
|---------|-------|---------|
| Forward decls + globals | 4139–4147 | `initMathObject` forward, `g_math_funcs[18]`, `g_math_object`, `g_math_init_done` |
| Helpers | 4268–4299 | `coerceMathArgs`, `mathArgToDouble`, `mathReturnDouble` |
| Unary builtins | 4301–4407 | `abs/sin/cos/tan/exp/log/sqrt/round/floor/ceil/atan/asin/acos` |
| Binary builtins | 4409–4461 | `atan2/pow/min/max` |
| ASnative stub | 4463–4472 | `builtin_math_nan_stub` |
| isNaN/isFinite | 4474–4520 | `g_isNaN_func`, `g_isFinite_func`, handlers, init |
| initMathObject | 5955–6026 | Allocation, constant registration, method registration |
| RNG | 13060–13128 | `TRandomFast`, `global_random_state`, `RandomFastInit`, `RandomFastNext`, `RandomPureHasher`, `GenerateRandomNumber`, `Random` |
| Math.random | 13130–13140 | `builtin_math_random` |

Total: roughly 400 lines of code + ~30 lines of helpers.

### What stays in `action.c`

- `ASnative(200, N)` dispatch (lines ~5866–5874): uses the **new** public API
  to fetch a function pointer by index.
- `initGlobalObject` (lines 29223, 29604, 29669, 29670, 29684): installs the
  Math object and isNaN/isFinite functions via the new accessors.
- Global-object enumeration table entry (line 30588): reads Math via
  accessor.
- `PushValueType` handlers for Math / isNaN / isFinite (lines 31803, 31809,
  31872): via accessors.
- The AS2-level `random()` builtin (line 33453): calls
  `actionRNGGenerateRange(max)`.

### Dependencies Math needs from the rest of the runtime

The carved-out `math.c` will call these helpers — they remain in `action.c`
or `variables.c` / `object.c` and must be declared in a new shared internal
header:

| Symbol | Current home | Notes |
|--------|--------------|-------|
| `pushVar`, `popVar`, `convertFloat` | `action.c` | Stack coercion helpers |
| `varToDoubleSWF` | `action.c` | Version-aware number coercion |
| `allocObject`, `retainObject`, `setProperty` | `object.c` | Already exposed via `object.h` |
| `setupNativeFuncOwnProps` | `action.c` | Sets up prototype/__proto__ own-props on a native `ASFunction` |
| `installNativeToString` | `action.c` | Installs a builtin `toString` on an object |
| `setObjectProto` | `action.c` | Sets `__proto__` to `Object.prototype` |
| `makeProtoReadOnly` | `action.c` | Marks an object's prototype properties read-only |
| `g_swf_version` (extern) | `action.c` | Global version flag |

## Proposed file layout

```
SWFModernRuntime/
├── include/actionmodern/
│   ├── action.h              (unchanged public API)
│   ├── action_internal.h     (NEW — helpers shared across subsystem files)
│   └── math.h                (NEW — Math's public accessors)
└── src/actionmodern/
    ├── action.c              (shrinks by ~400 lines)
    └── math.c                (NEW)
```

### `math.h` (public Math API)

Only symbols that `action.c` or other future subsystems need to call.
Everything else (`builtin_math_*`, `coerceMathArgs`, `g_math_*`) stays
file-static in `math.c`.

```c
#ifndef ACTIONMODERN_MATH_H
#define ACTIONMODERN_MATH_H

#include <libswf/swf.h>
#include "object.h"

// Ensure Math object + function table are initialized (idempotent).
void initMathObject(SWFAppContext* app_context);

// Accessors — call initMathObject() internally if needed.
ASObject*   actionMathGetObject(SWFAppContext* app_context);
ASFunction* actionMathGetFunc(int index);         // 0..17, NULL out of range
ASFunction* actionMathGetIsNaN(void);
ASFunction* actionMathGetIsFinite(void);

// RNG access for the top-level AS2 `random(n)` function.
int32_t actionRNGGenerateRange(int32_t range);

#endif
```

### `action_internal.h` (helpers shared across subsystem files)

Not a public API — only included by other `.c` files in `src/actionmodern/`.
Starts small and grows with each subsequent extraction.

```c
#ifndef ACTIONMODERN_ACTION_INTERNAL_H
#define ACTIONMODERN_ACTION_INTERNAL_H

#include <libswf/swf.h>
#include "object.h"
#include "variables.h"

extern int g_swf_version;

void   pushVar(SWFAppContext* app_context, ActionVar* v);
void   popVar(SWFAppContext* app_context, ActionVar* v);
void   convertFloat(SWFAppContext* app_context);
double varToDoubleSWF(SWFAppContext* app_context, ActionVar* v, int swf_version);

void setupNativeFuncOwnProps(SWFAppContext* app_context, ASFunction* fn);
void installNativeToString(SWFAppContext* app_context, ASObject* obj);
void setObjectProto(SWFAppContext* app_context, ASObject* obj);
void makeProtoReadOnly(ASObject* obj);

#endif
```

Each helper listed there needs its `static` qualifier dropped in
`action.c`, nothing else.

## Step-by-step execution

Total effort: ~2–3 hours of careful work, ~20 commits of mechanical change.

### Step 1 — Add `action_internal.h`

Create the header with the declarations above. No code changes yet. Build
to verify it parses (nothing includes it yet).

### Step 2 — Drop `static` on helpers Math needs

In `action.c`, remove `static` from:
- `pushVar`, `popVar`, `convertFloat`, `varToDoubleSWF`
- `setupNativeFuncOwnProps`, `installNativeToString`
- `setObjectProto`, `makeProtoReadOnly`

Add `#include "action_internal.h"` at the top of `action.c`. Build — still
passes because declarations match.

### Step 3 — Create `math.h` and `math.c`

Copy the Math regions listed in the inventory table into `math.c`. Include
`math.h` and `action_internal.h`. Keep `g_math_funcs`, `g_math_object`,
`g_math_init_done`, all `builtin_math_*`, `coerceMathArgs`, RNG state and
helpers as `static` inside `math.c`.

Implement the accessors:
```c
ASObject* actionMathGetObject(SWFAppContext* ctx) {
    initMathObject(ctx);
    return g_math_object;
}
ASFunction* actionMathGetFunc(int i) {
    if (i < 0 || i >= 18) return NULL;
    return &g_math_funcs[i];
}
ASFunction* actionMathGetIsNaN(void)   { return &g_isNaN_func; }
ASFunction* actionMathGetIsFinite(void) { return &g_isFinite_func; }
int32_t actionRNGGenerateRange(int32_t r) { return Random(r, &global_random_state); }
```

### Step 4 — Delete Math regions from `action.c`

Delete every region listed in the inventory table. Add
`#include "math.h"` at the top. Build — will fail at every Math callsite.

### Step 5 — Update Math callsites in `action.c`

Replace direct references with accessor calls:

| Before | After |
|--------|-------|
| `&g_math_funcs[method_index]` | `actionMathGetFunc(method_index)` |
| `g_math_object` (lookup) | `actionMathGetObject(app_context)` |
| `&g_isNaN_func` | `actionMathGetIsNaN()` |
| `&g_isFinite_func` | `actionMathGetIsFinite()` |
| `Random(max, &global_random_state)` | `actionRNGGenerateRange(max)` |

The table at line 30588 (`{"Math", 4, g_math_object}`) is a static
initializer; the lookup has to move to the code path that uses the table
(it already calls `initMathObject` — just use the accessor).

### Step 6 — Update CMakeLists.txt / build scripts

Two places:
- `SWFModernRuntime/CMakeLists.txt` — add `src/actionmodern/math.c`
- `ruffle-tests/verify_output.py` (`compile_native`, around line 1245 in
  the `core_sources` list) — add `"src/actionmodern/math.c"`

### Step 7 — Build, run the single hand-written Math tests locally

```bash
cd SWFRecomp/build && cmake .. && make -j$(nproc)
python3 ruffle-tests/verify_output.py --test=math_min_max --diff --verbose
python3 ruffle-tests/verify_output.py --test=math_round --diff --verbose
```

If those pass, commit.

### Step 8 — Measure

```bash
# Cold cache — confirm overall compile time shrinks somewhat
# (action.c slightly smaller, math.c compiles in parallel with -j)
python3 ruffle-tests/verify_output.py --test=add --verbose --no-ccache

# Now touch action.c (add a trivial comment), rerun with ccache:
python3 ruffle-tests/verify_output.py --test=add --verbose
# Expect: math.o hits cache (was ~1s of that 50s), rest is action.c recompile.
```

The real payoff shows up on the **next** extraction (when a second,
larger subsystem comes out of `action.c` — each one is additive).

### Step 9 — Push and let CI verify the full suite

The ccache-enabled CI workflow will confirm nothing regressed.

## Risks / things to watch

1. **Forward declaration ordering.** `math.c` needs `ASFunction`,
   `Function2Ptr`, `ActionVar` — all in the existing public headers. No
   new ordering issues expected.
2. **`g_swf_version` is a global.** Currently `extern int` in one place
   inside `action.c`. Promote the `extern` into `action_internal.h`.
3. **`Random()` signature.** The AS2 `random()` callsite at line 33453 uses
   `Random(max, &global_random_state)` — the accessor hides the state
   pointer, which is the right encapsulation.
4. **Test file dependencies.** `verify_output.py` copies runtime sources
   into a temp dir per test. Adding `math.c` to `core_sources` is a
   one-line addition but must not be missed — otherwise tests fail to
   link with "undefined reference to initMathObject".
5. **No behavior changes.** This is a pure file-reorganization. Every
   test that passed before should pass after. If any fail, the delta is
   small enough that git bisect on the carve-out commits is fast.

## What comes next

After Math lands cleanly, the remaining candidates in rough order of
value (biggest / cleanest first):

1. **Date** (~1500 lines, starts at line 6028). Largest single
   self-contained block.
2. **Object.registerClass + register_class machinery** (~400 lines).
3. **Timers (setInterval/setTimeout/clearInterval)** (~300 lines).
4. **Super keyword depth-based dispatch** (~300 lines).
5. **Clip event dispatch + enterframe machinery** (~400 lines).
6. **Unload / pending-removal machinery** (~300 lines).

Each follows the same pattern established here: `action_internal.h` grows
slightly, one new `subsystem.c` appears, `action.c` shrinks.

After ~5 extractions, `action.c` should be under 45K lines and a typical
edit-one-subsystem loop should compile in under 10s.
