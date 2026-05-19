# NetConnection-vN Investigation Plan
<!-- TESTS: NetConnection-v6, NetConnection-v7, NetConnection-v8 -->

Last updated: 2026-05-19 (initial planning doc, drafted from local
single-test reproductions at the current `master` SHA; no fixes
landed yet)

<!-- PLAN_META
id: NETCONNECTION_VN_PLAN
status: pending
phases:
  - id: 1
    name: "connect(undefined) is a no-op, not Connect.Success"
    status: pending
  - id: 2
    name: "connect(null) / connect('null') fires Connect.Failed (we fire Connect.Closed)"
    status: pending
  - id: 3
    name: "connect() return value (true/false vs undefined)"
    status: pending
  - id: 4
    name: "nc.uri stored as a string under all argument types"
    status: pending
  - id: 5
    name: "onStatus level field ('error' vs 'status')"
    status: pending
  - id: 6
    name: "infoObj.code shape on Connect.Failed (currently empty)"
    status: pending
  - id: 7
    name: "close() / disconnect resets isConnected to false"
    status: pending
  - id: 8
    name: "statuses queue ordering (Connect.Closed precedes Connect.Failed)"
    status: pending
dependencies:
  - id: SUBTESTS_HARNESS
    reason: "Discovery shipped 2026-05-14 (commit 39b797ac)."
related:
  - id: NETCONNECTION_PLAN
    reason: "AVM1 NETCONNECTION_PLAN (complete) covers basic connect/close lifecycle. The Gnash tests exercise argument-coercion + onStatus payload shape edges the AVM1 tests don't."
blockers: []
status_note: |
  Three sub-tests (v6/v7/v8) all share the same ~50 failure pattern.
  The bug is concentrated in NetConnection.connect()'s argument
  validation logic and the onStatus event shape. Fixing Phases 1-6
  should unblock most of the test in a single session of focused
  work.
-->

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| NetConnection-v6 | 71/126 | 56.3% | output_mismatch |
| NetConnection-v7 | 75/126 | 59.5% | output_mismatch |
| NetConnection-v8 | 75/126 | 59.5% | output_mismatch |

## Test source

Gnash testsuite/actionscript.all/NetConnection.as. Tests
NetConnection.connect() with the full range of argument types
(undefined, null, "null", numbers, booleans, strings, http URIs)
and verifies:

- isConnected toggles correctly
- onStatus payload (`code`, `level`, `infoObj`) is right
- nc.uri is a string of the right form
- Connect.Closed fires before Connect.Failed on disconnect+failed-retry
- The return value of connect() is bool

## Failure clusters

### A. connect(undefined) is a no-op (Phase 1)

Lines: 21, 24, 25, 26, 27, 95, 96, 97, 98, 103.

```
- PASSED: tmp.isConnected == false [./NetConnection.as:58]
+ FAILED: expected: false obtained: true
- PASSED: result == "" [./NetConnection.as:96]
+ FAILED: expected: "" obtained: NetConnection.Connect.Success
```

`nc.connect()` (no arg) and `nc.connect(undefined)` should:
- NOT change isConnected
- NOT fire any onStatus callback (status callback's `result` stays
  empty string from the test harness initializer)

We treat undefined as "connect successfully" and fire
NetConnection.Connect.Success.

### B. connect(null) fires Connect.Failed not Connect.Closed (Phase 2)

Lines: 30, 34, 37, 50, 57, 64, 75 — all `result == "Failed"`
expected, we emit `Closed`.

```
- FAILED: expected: "NetConnection.Connect.Failed" obtained: NetConnection.Connect.Closed
```

When connect fails (invalid URI), the event code should be
`NetConnection.Connect.Failed`. We always emit
`NetConnection.Connect.Closed`. Likely we are using the "close"
helper for both the close path AND the failed-connect path —
distinguish.

### C. connect() return value (Phase 3)

Lines: 28, 35, 41, 48, 55, 62, 68, 73, 102, 111, 119, 144, 163,
173, 194.

```
- PASSED: ret == false [./NetConnection.as:102]
+ FAILED: expected: false obtained:
```

`nc.connect(...)` should return `true` if the connection attempt
proceeds, `false` if it's rejected immediately. We return undefined.

### D. nc.uri stored as string (Phase 4)

Lines: 45, 46, 47, 52, 66, 67, 83, 84, 167, 168, 219, 220.

```
- PASSED: typeof(tmp.uri) == "string" [./NetConnection.as:123]
+ FAILED: expected: "string" obtained: null
- PASSED: tmp.uri == "null" [./NetConnection.as:124]
+ FAILED: expected: "null" obtained: null
```

After `nc.connect(arg)` for non-undefined args, `nc.uri` should
always be a string — the argument coerced via `convertString`
(null → "null", 6 → "6", "string" → "string"). We are storing the
raw value (null stays null, 6 stays number).

### E. onStatus level field (Phase 5)

Lines: 26, 31, 38, 51, 58, 65, 76, 105, 114, 136, 147, 166, 197.

```
- PASSED: level == "error" [./NetConnection.as:105]
+ FAILED: expected: "error" obtained: status
```

On Connect.Failed events, the `infoObj.level` should be "error"
(not "status"). We always emit "status". Distinguish Failed from
Success/Closed.

### F. infoObj.code on Connect.Failed (Phase 6)

Lines: 85, 87, 88.

```
- PASSED: infoObj.code == "NetConnection.Connect.Failed" [./NetConnection.as:231]
+ FAILED: expected: "NetConnection.Connect.Failed" obtained:
- PASSED: infoObj instanceof Object [./NetConnection.as:234]
+ FAILED: infoObj instanceof Object
- PASSED: infoObj.toString() == "[object Object]" [./NetConnection.as:235]
+ FAILED: expected: "[object Object]" obtained:
```

`infoObj.code` is empty. The infoObj passed to onStatus should be
a plain Object with `level` and `code` string props. We are likely
passing a raw status string instead of an object, or constructing
an object whose `code` field is unset.

### G. close() resets isConnected (Phase 7)

Lines: 295.

```
- PASSED: nc.isConnected == false [./NetConnection.as:295]
+ FAILED: expected: false obtained: true
```

After `nc.close()` we leave isConnected true. Setter probably not
updating the field.

### H. statuses queue ordering (Phase 8)

Lines: 54, 61, 72, 140, 151, 184.

```
- PASSED: statuses.toString() == "NetConnection.Connect.Closed,NetConnection.Connect.Failed" [./NetConnection.as:140]
+ FAILED: expected: "..." obtained: NetConnection.Connect.Closed
- PASSED: statuses.toString() == "NetConnection.Connect.Success" [./NetConnection.as:184]
+ FAILED: expected: "..." obtained: NetConnection.Connect.Closed,NetConnection.Connect.Success
```

When connect(badArg) is called after a previous successful connect,
the sequence should be: fire Closed (old conn), fire Failed (new
attempt). We sometimes only fire Closed (missing the Failed); other
times we accumulate stale entries from previous Closed events.

Likely interacts with Phase 2 (Failed vs Closed) — once Phase 2
lands, half of these failures may resolve automatically.

## Recommended fix order

1. **Phase 1 (connect(undefined) no-op)** — gate the early "treat
   undefined as success" path. Small fix, removes many false
   positives. Estimate: 30 min.
2. **Phase 2 + 5 + 6 (distinguish Failed from Closed; level=error;
   infoObj.code)** — same code path. Fix as one. Estimate: 2 hours.
3. **Phase 4 (uri coercion to string)** — add `convertString` in
   the setter. Estimate: 30 min.
4. **Phase 3 (connect return value)** — bool return. Estimate:
   30 min.
5. **Phase 7 (close sets isConnected=false)** — single line.
   Estimate: 15 min.
6. **Phase 8 (statuses ordering)** — likely follows Phase 2.
   Estimate: 30 min once Phase 2 lands; may need additional work.

Total estimate: 4-5 hours, 1-2 sessions. Strong candidate for
ruffle_matched promotion in a single landing.

## Promotion plumbing

`known_failure = true` + `output.fpN.ruffle.txt` sidecars. The
~55-60% line-match rate means subset-match needs Phases 1+2+5+6+8
all landed before promotion fires.
