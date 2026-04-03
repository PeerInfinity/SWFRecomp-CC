# NetConnection Plan
<!-- TESTS: netconnection_close, netconnection_send_remote -->

<!-- PLAN_META
id: NETCONNECTION
status: blocked
phases:
  - id: 1
    name: "NetConnection state machine (connect/close)"
    status: complete
  - id: 2
    name: "onStatus dispatch helper"
    status: complete
  - id: 3
    name: "Register real methods"
    status: complete
  - id: 4
    name: "netconnection_send_remote (AMF + HTTP)"
    status: blocked
dependencies: []
blockers:
  - blocker: 7
    reason: "Phase 4 blocked on AMF codec + HTTP client infrastructure"
-->

Last updated: 2026-04-03

## Status: BLOCKED — netconnection_close 39/39 PASS, netconnection_send_remote blocked on AMF + HTTP

### Blocker (2026-04-03)

`netconnection_send_remote` requires AMF serialization/deserialization, HTTP POST via Navigator::fetch,
async response dispatch, and `log_fetch` infrastructure. None of this exists in the runtime.
This is a full networking stack requirement — not implementable without significant new infrastructure.

### Implementation (2026-03-31)

Commit `a6a3e688`: Implemented `builtin_nc_connect`, `builtin_nc_close`, `nc_dispatch_onStatus`, and `nc_dispatch_onStatus_undefined` in action.c. Replaced stub method registrations on NetConnection.prototype with real implementations.

Key behaviors:
- `connect(null)`: sets isConnected=true, fires onStatus with `NetConnection.Connect.Success`
- `connect(null)` when already connected: fires `Connect.Closed` then `Connect.Success`
- `close()` when connected: fires `Connect.Closed`, sets isConnected=false
- `close()` when not connected: no-op
- `connect("http://...")`: sets isConnected=true, stores URI, no onStatus
- `close()` after remote connect: fires `Connect.Closed` then a second onStatus with undefined event

### Test Summary

| Test | Lines | Current | Status | Actionable? |
|------|-------|---------|--------|-------------|
| netconnection_close | 39 | 3/39 (8%) | ignored | **Yes** — state machine + onStatus dispatch only |
| netconnection_send_remote | 50 | 1/50 (2%) | ignored | **No** — needs AMF serialization + HTTP POST |

### netconnection_close — Detailed Analysis

**Expected output** (39 lines, 1 frame):

The test creates a NetConnection, assigns an `onStatus` handler, then exercises the
connect/close lifecycle:

```
/// connection.close()
                                    ← no onStatus (closing when not connected)

/// connection.connect(null)
-- NetConnection.onStatus start --
typeof(event) == object
event.level = status (string)
event.code = NetConnection.Connect.Success (string)
-- NetConnection.onStatus end --
                                    ← isConnected becomes true

/// connection.connect(null)        ← re-connect while connected
-- NetConnection.onStatus start --
typeof(event) == object
event.level = status (string)
event.code = NetConnection.Connect.Closed (string)
-- NetConnection.onStatus end --
-- NetConnection.onStatus start --
typeof(event) == object
event.level = status (string)
event.code = NetConnection.Connect.Success (string)
-- NetConnection.onStatus end --
                                    ← close then re-open

/// connection.close()
-- NetConnection.onStatus start --
typeof(event) == object
event.level = status (string)
event.code = NetConnection.Connect.Closed (string)
-- NetConnection.onStatus end --

/// connection.connect("http://example.org")
                                    ← no onStatus (non-null URL — we don't support remote)

/// connection.close()
-- NetConnection.onStatus start --  ← but still fires close
...
```

**Key behaviors:**
1. `connect(null)` — local connection, sets `isConnected = true`, fires `onStatus` with
   `code = "NetConnection.Connect.Success"`, `level = "status"`
2. `connect(null)` when already connected — fires `Connect.Closed` then `Connect.Success`
3. `close()` when connected — fires `Connect.Closed`, sets `isConnected = false`
4. `close()` when not connected — no onStatus fired
5. `connect("http://...")` — non-null URL, no onStatus (remote connections not supported),
   but connection IS considered "connected" for subsequent close
6. onStatus event is an ASObject with `code` (string) and `level` (string) properties

### Current Stubs

All methods are stubs returning undefined (`action.c:23269-23272`):
```c
addStubMethodToProto(ctx, proto, "connect", 7, flags);
addStubMethodToProto(ctx, proto, "close", 5, flags);
addStubMethodToProto(ctx, proto, "call", 4, flags);
addStubMethodToProto(ctx, proto, "addHeader", 9, flags);
```

Constructor sets `isConnected = false` (`action.c:35484-35505`).

### Implementation Plan for netconnection_close

#### Phase 1: NetConnection State Machine

Replace the `connect` and `close` stubs with real implementations:

```c
void builtin_netconnection_connect(SWFAppContext* ctx, ActionVar* args, ...) {
    ASObject* nc = (ASObject*)this_obj;

    // If already connected, fire Close first
    ActionVar* is_conn = getProperty(nc, "isConnected", 11);
    if (is_conn && is_conn->data.numeric_value == 1) {
        dispatchOnStatus(ctx, nc, "NetConnection.Connect.Closed", "status");
    }

    // connect(null) = local connection — always succeeds
    if (args[0].type == ACTION_STACK_VALUE_NULL ||
        (arg_count == 0 || args[0].type == ACTION_STACK_VALUE_UNDEFINED)) {
        ActionVar bv = makeBool(1);
        setProperty(ctx, nc, "isConnected", 11, &bv);
        dispatchOnStatus(ctx, nc, "NetConnection.Connect.Success", "status");
    } else {
        // Non-null URL — mark as connected but don't fire onStatus
        // (remote connections not supported)
        ActionVar bv = makeBool(1);
        setProperty(ctx, nc, "isConnected", 11, &bv);
    }
}

void builtin_netconnection_close(SWFAppContext* ctx, ActionVar* args, ...) {
    ASObject* nc = (ASObject*)this_obj;

    ActionVar* is_conn = getProperty(nc, "isConnected", 11);
    if (is_conn && is_conn->data.numeric_value == 1) {
        ActionVar bv = makeBool(0);
        setProperty(ctx, nc, "isConnected", 11, &bv);
        dispatchOnStatus(ctx, nc, "NetConnection.Connect.Closed", "status");
    }
    // If not connected, close() is a no-op (no onStatus)
}
```

#### Phase 2: onStatus Dispatch Helper

Create a helper to dispatch onStatus events:

```c
void dispatchOnStatus(SWFAppContext* ctx, ASObject* target,
                      const char* code, const char* level) {
    // Look up onStatus on the target
    ActionVar* handler = getProperty(target, "onStatus", 8);
    if (!handler || handler->type != ACTION_STACK_VALUE_FUNCTION) return;

    // Create event object: { code: "...", level: "..." }
    ASObject* event = allocObject(ctx, 2);
    ActionVar code_var = makeString(code, strlen(code));
    ActionVar level_var = makeString(level, strlen(level));
    setProperty(ctx, event, "code", 4, &code_var);
    setProperty(ctx, event, "level", 5, &level_var);

    // Call handler with event as argument, target as this
    ActionVar event_arg = { .type = ACTION_STACK_VALUE_OBJECT,
                            .data.numeric_value = (u64)event };
    // Push this + arg, invoke function
    callFunctionWithThis(ctx, handler, target, &event_arg, 1);
}
```

#### Phase 3: Register Real Methods

Replace the stub registrations with real implementations using `advanced_func` callbacks
(type 2 functions), similar to how Sound methods are registered.

### netconnection_send_remote — Why Blocked

This test needs:
1. **AMF serialization**: NetConnection.call() serializes arguments into AMF binary format
2. **HTTP POST**: Sends AMF data to `http://localhost:8000/test1` via `Navigator::fetch`
3. **AMF deserialization**: Parses AMF response into ActionScript objects
4. **Async response dispatch**: onResult/onStatus callbacks fire when response arrives
5. **addHeader()**: Adds custom HTTP headers to the request
6. **log_fetch = true**: The test expects fetch logging output (URL, Method, Mime-Type, Body hex)

None of this infrastructure exists. This is a full HTTP client + AMF codec requirement.

### Key Code Locations

| Component | File | Lines |
|-----------|------|-------|
| NetConnection prototype | `action.c` | 23245-23276 |
| NetConnection constructor | `action.c` | 35484-35505 |
| connect/close/call stubs | `action.c` | 23269-23272 |
| Stub method implementation | `action.c` | 923-931 |

### Dependencies

- netconnection_close: **None** — self-contained state machine
- netconnection_send_remote: Blocked on AMF codec + HTTP client

### Estimated Complexity

**netconnection_close**: Low. ~80 lines:
- Phase 1 (connect/close state): ~40 lines
- Phase 2 (onStatus dispatch): ~30 lines
- Phase 3 (method registration): ~10 lines

**netconnection_send_remote**: Very high. Would need AMF codec (~500+ lines) + HTTP client.
