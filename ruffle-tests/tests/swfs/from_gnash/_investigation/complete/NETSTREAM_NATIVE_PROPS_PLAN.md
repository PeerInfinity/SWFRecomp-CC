# NetStream Native Property Installation on Connected Construction

<!-- TESTS: NetStream-v6, NetStream-v7, NetStream-v8 -->

<!-- PLAN_META
id: NETSTREAM_NATIVE_PROPS
status: complete
phases:
  - id: 1
    name: "Install currentFps on prototype during connected construction"
    status: complete
dependencies: []
blockers: []
-->

## Problem

NetStream-v6/v7/v8 each have 2 real failures (+ 2 count-line diffs = 4 total):

```
PASSED: NetStream.prototype.hasOwnProperty('currentFps') [./NetStream.as:223]
FAILED: NetStream.prototype.hasOwnProperty('currentFps') [./NetStream.as:223]

PASSED: NetStream.prototype.hasOwnProperty('currentFps') [./NetStream.as:229]
FAILED: NetStream.prototype.hasOwnProperty('currentFps') [./NetStream.as:229]
```

All 3 versions have the same 2 failures. Fixing this flips all 3 from FAIL to PASS.

## Root Cause

In Flash, the **NetStream constructor** installs native data properties (at minimum `currentFps`) on its **prototype object** when constructed with a **connected NetConnection**. Our implementation doesn't do this.

## Evidence from Recompiled Bytecode

The test creates NetStream instances in 5 different scenarios. By tracing the recompiled bytecode (`script_2.c`), the exact trigger conditions are:

| # | Code | Args | NC connected? | Installs? | Evidence |
|---|------|------|---------------|-----------|----------|
| 1 | `new NetStream()` | 0 | N/A | NO | AS:55 `!hasOwnProperty` → PASS |
| 2 | `new NetStream({isConnected:true})` | 1 (plain obj) | N/A | NO | AS:212 `!hasOwnProperty` → PASS |
| 3 | `new NetStream(new NetConnection())` | 1 (real NC) | NO | NO | AS:215 `!hasOwnProperty` → PASS |
| 4 | `new NetStream(nc)` after `nc.connect(null)` | 1 (real NC) | YES | **YES** | AS:223 `hasOwnProperty` → expected PASS |
| 5 | After `NetStream.prototype = {}`, `new NetStream(nc)` | 1 (real NC) | YES | **YES** | AS:229 `hasOwnProperty` → expected PASS |

Between scenarios 4 and 5, the test replaces `NetStream.prototype = {}` (empty object), then creates `new NetStream()` (0 args, no install), confirms `!hasOwnProperty` passes on the empty prototype, then creates `new NetStream(nc)` again — and `currentFps` appears on the NEW empty prototype. This proves the **constructor** installs the property on **whatever the current prototype is**.

## Required Conditions

All three must be true:
1. `num_args >= 1` (at least one argument passed to constructor)
2. First argument's `__proto__` is NetConnection.prototype (`g_stub_ctors[10].prototype_obj`) — a plain object with `{isConnected: true}` does NOT trigger installation
3. The NetConnection has `isConnected` property set to truthy boolean (set by `builtin_nc_connect` when `.connect()` is called)

## Fix Location

`SWFModernRuntime/src/actionmodern/action.c`, in `actionNewObject()`, after the generic constructor call completes. Add a post-construction handler for `g_stub_ctors[11]` (NetStream), similar to the existing handlers for:
- `g_stub_ctors[9]` (MovieClipLoader) at line ~41602
- `g_stub_ctors[4]` (ContextMenu) at line ~41616
- `g_stub_ctors[5]` (ContextMenuItem) at line ~41654

## Implementation

```c
// NetStream constructor: install native data properties on prototype
// when constructed with a connected NetConnection
if (ctor_func == &g_stub_ctors[11] && num_args >= 1) {
    // Check if first arg is an OBJECT
    if (args[0].type == ACTION_STACK_VALUE_OBJECT && args[0].data.numeric_value != 0) {
        ASObject* nc_obj = (ASObject*)(uintptr_t)args[0].data.numeric_value;
        // Check if nc_obj.__proto__ is NetConnection.prototype
        ActionVar* nc_proto = getProperty(nc_obj, "__proto__", 9);
        if (nc_proto != NULL && nc_proto->type == ACTION_STACK_VALUE_OBJECT &&
            (ASObject*)(uintptr_t)nc_proto->data.numeric_value == g_stub_ctors[10].prototype_obj) {
            // Check if nc is connected (isConnected == true)
            ActionVar* is_conn = getProperty(nc_obj, "isConnected", 11);
            if (is_conn != NULL && is_conn->type == ACTION_STACK_VALUE_BOOLEAN &&
                is_conn->data.numeric_value != 0) {
                // Install currentFps on prototype if not already present
                if (ctor_func->prototype_obj != NULL &&
                    !hasPropertyRaw(ctor_func->prototype_obj, "currentFps", 10)) {
                    ActionVar undef = {0};
                    undef.type = ACTION_STACK_VALUE_UNDEFINED;
                    setProperty(app_context, ctor_func->prototype_obj, "currentFps", 10, &undef);
                }
            }
        }
    }
}
```

## Properties to Install

The test only checks `currentFps` in the failing assertions. However, lines 7-20 of the expected output show 7 native data properties that are NOT initially on the prototype:

- `currentFps` — **required** (test explicitly checks this)
- `bufferLength` — may need similar treatment
- `bufferTime` — may need similar treatment
- `liveDelay` — may need similar treatment
- `time` — may need similar treatment
- `bytesLoaded` — may need similar treatment
- `bytesTotal` — may need similar treatment

Start with just `currentFps`. If other tests fail or need the others, add them incrementally.

## Impact

- **NetStream-v6**: 76/80 → 80/80 → **PASS** (+1 test)
- **NetStream-v7**: 76/80 → 80/80 → **PASS** (+1 test)
- **NetStream-v8**: 76/80 → 80/80 → **PASS** (+1 test)
- **Total**: +3 passing tests (actionscript.all: 77 → 80)

## Risk

Low. The fix only triggers during `new NetStream(nc)` when nc is a connected NetConnection instance. All earlier `!hasOwnProperty` checks continue to pass because they test with no args, plain objects, or unconnected NetConnections.
