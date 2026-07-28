# net/socket arc — triage + tranches

**Created**: 2026-07-28 · **Baseline**: `2ed94a302` (session start), per-suite
`_results/results_graphics.json` from CI `30397635331` (the input-arc closeout
run, SHA `bbefcf376`).
**Status**: triage complete; **tranche 1 SHIPPED** (`937047612` + `722dea0e9`,
CI `30403506144` then `30405770263`, both graphics/full green) — **+10 vs +9
predicted, zero regressions**. Corpus effective 3890 → **3901 / 4420** (the
11th gain is an unrelated `visual` flake), `avm2` 926 → **936 / 1221**.
Postmortem in §6. **NEXT: tranche 2** (socket.json replay, +12,
medium-large).

Scope of this document: the **net block** named as row 4e of
`feature-priority-map.md` ("net/socket (29)"). The census below finds
**38 failing avm2 tests + 26 riders in five other suites = 64**, not 29 — the
map's figure was a name-shaped guess over the avm2 suite alone and predates
the `from_avmplus` / misc-group import. Same overshoot as the input arc
(30 + 6 against a predicted 25), and for the same reason: the map counts a
theme, the census counts tests.

Line counts throughout are `matching/expected` from the graphics baseline.

---

## 0. Method

Three sweeps, unioned, over **every** suite's `results_graphics.json` — not
just avm2:

1. **Name sweep** —
   `socket|netconn|netstream|netgroup|amf|sharedobject|localconnection|
   urlrequest|urlloader|urlstream|urlvariables|responder|filereference|
   navigatetourl|sendtourl|objectencoding|externalinterface|net_|_net`
   (110 tests hit; 58 failing).
2. **Content sweep** over every test's `*.as` for
   `flash\.net\.(Socket|XMLSocket|NetConnection|NetStream|SharedObject|
   LocalConnection|Responder|URLStream|FileReference|DatagramSocket|NetGroup|
   ObjectEncoding|registerClassAlias)|new (NetConnection|LocalConnection|
   Socket)|SharedObject\.get|registerClassAlias|read/writeObject\(`
   (93 dirs hit). This is what found `audio/aac`, `audio/g711` and the five
   `avm1/file_reference_*` tests, none of which the name sweep sees.
3. **Marker sweep** over `test.toml` + test-dir contents: **which tests ship a
   `socket.json`** (14 across the corpus, all 14 failing), which set
   `log_fetch = true`, which set `known_failure = true` (and therefore ship an
   `output.ruffle.txt`), and which name the magic
   `debug-select-success` / `debug-success.txt` file-dialog strings.

Sweep 3 is the decisive one, exactly as `input.json` was for the input arc:
it separates "the API is missing" from "the recorded transport never
replays". **14 of the 64 tests are blocked on a `socket.json` replay the
harness does not implement at all**, and 14 more on a mock file dialog.

Standing caveats applied: `_results/*.json` truncates outputs at ~51 lines, so
every test over that length was re-run locally before being sized
(`netconnection_properties`, `socket_errors`, `socket_read_*`,
`avm2/localconnection`, `AMFSerializer`); and every test is bucketed by
**which VM owns it**, not by the subsystem its name suggests.

---

## 1. What exists today

### AVM2 — `flash.net` (`avm2_globals.c::register_net`, `avm2_amf.c`)

| Class | State |
|---|---|
| `URLRequest`, `URLRequestMethod`, `URLRequestHeader`, `URLLoaderDataFormat`, `URLVariables` | **real** — full property surface, sealed where Ruffle seals |
| `URLLoader` | **real** — Loader-arc tranches 3–5 gave it bundled-sibling-asset loads, per-tick drain, `Event.OPEN`/`PROGRESS`/`COMPLETE`/`HTTP_STATUS`/`IO_ERROR` |
| `navigateToURL` | **real** (`net_navigateToURL_target_normalize` 107/107) |
| `sendToURL` | no-op stub |
| `LocalConnection` | **stub** — `connect`/`send`/`close`/`allowDomain` are `net_noop`; only `domain` is live |
| `SharedObject` | **in-memory** — `getLocal` caches a data bag; `flush`/`clear` work, nothing is written to disk, no AMF involved |
| `registerClassAlias` / `getClassByAlias` / `ObjectEncoding` | **real** |
| `Socket`, `XMLSocket`, `NetConnection`, `NetStream`, `Responder`, `URLStream`, `FileReference`, `FileReferenceList`, `FileFilter`, `DatagramSocket`, `NetGroup`, `NetStreamPlayOptions` | **do not exist** — every one of their tests dies on `ReferenceError #1065: Variable X is not defined` at line 1 |

### AVM2 — AMF (`avm2_amf.c`, 1672 lines)

A complete AMF0 **and** AMF3 writer and reader, with an AMF3 object-reference
table (`24cb841ec`) and AMF0 short-string/ECMA-array handling. It backs
`ByteArray.readObject`/`writeObject` (both `bytearray_readobject_amf0/amf3`
pass) and `SharedObject`. Two hooks in the spec are missing and are named by
exactly one test each (§4, bucket X): `IExternalizable` (`avm2_amf.c:995`
carries the "not implemented" comment) and
`ObjectEncoding.dynamicPropertyWriter`.

### AVM2 — events

`ProgressEvent`, `StatusEvent`, `AsyncErrorEvent`, `SecurityErrorEvent`,
`HTTPStatusEvent`, `IOErrorEvent` all exist and format correctly (the Loader
arc built them). **`NetStatusEvent` and `DataEvent` do not.**

### AVM2 — `ByteArray` is the Socket substrate

`avm2_bytearray.c` already implements all 28 `IDataInput`/`IDataOutput`
methods over an `Avm2ByteArrayExt` (`endian`, `objectEncoding`, `position`,
`bytesAvailable`, `readObject`/`writeObject` via `avm2_amf.c`). `Socket` and
`URLStream` are that surface over a different buffer pair — the read/write
bodies are reusable as-is once the ext lookup is generalised.

### AVM1 (`action.c`)

- `XMLSocket` — **prototype stub**: `connect` returns `false`,
  `send`/`close`/`onData`/`getTimeout`/`setTimeout` are no-op stubs.
- `NetConnection` / `NetStream` — **partly real**: `avm1/netconnection_close`
  (39/39), `avm1/netstream_play_flv` (21/21), `avm1/netstream_seek_flv`
  (25/25) all pass, and `NetConnection.connect(null)`/`close()` fire the
  status callbacks. `NetConnection.call` (the AMF wire) does not exist.
- `LocalConnection` — `avm1/localconnection` (579/579) and
  `localconnection_properties` (8/8) pass; it is a Loader-arc rider that got
  its child SWFs back. `localconnection_top_level` (4/7) shows the gap:
  **argument serialization**.
- `SharedObject` — **headless stub** (`action.c:36434`): `getLocal` returns an
  object with a `data` bag so scripts don't crash; `flush` does nothing.
- `FileReference` / `FileReferenceList` — **AsBroadcaster surface only**:
  `addListener`/`removeListener`/`broadcastMessage`/`_listeners` are real
  (that half of `file_reference_list_asbroadcaster` passes), `browse()` is a
  stub that never fires `onSelect`/`onCancel`.
- **There is no AVM1 AMF serializer at all.** This is the single biggest
  missing subsystem in the arc and it owns 9 tests (§4, bucket W).

### The harness

`verify_output.py` implements `input.json` replay (14 event kinds) and
`log_fetch` (→ `-DLOG_FETCH`, consumed by `swf_log_fetch_queue` /
`swf_log_navigate` in `src/utils.c`). It implements **no** `socket.json`
replay and **no** file-dialog mock. Both are new harness work; both are
purely deterministic (see §2 and §3).

---

## 2. The `socket.json` replay contract (Ruffle `tests/socket-format`)

A scripted, in-order transport script. Ruffle's test navigator
(`tests/framework/src/backends/navigator.rs::connect_socket`) runs it against
a real localhost socket; nothing about it needs a real socket:

| Event | Meaning |
|---|---|
| `{"type":"Send","payload":[…]}` | server → player; delivers bytes to the socket's read buffer |
| `{"type":"Receive","expected":[…]}` | player → server; **blocks** until the player flushes a write, then asserts the bytes equal `expected` |
| `{"type":"Disconnect"}` | server closes; player sees `Event.CLOSE` |
| `{"type":"WaitForDisconnect"}` | blocks until the player closes; receiving data instead is a harness failure |

`connect()` always succeeds when a `socket.json` is present (the future
immediately pushes `SocketAction::Connect(Connected)`), and the script then
runs in order. Under `log_fetch = true` the connect also prints:

```
Navigator::connect_socket
    Host: localhost; Port: 8001
```

(note the 4-space indent on the second line — `avm1/xml_socket_connect_null`
grades exactly this, and nothing else).

Determinism: no timestamps anywhere. Ordering is driven by the player's own
flush/close calls and by the tick loop, i.e. by the same tick counter the
input replay uses. An in-process mock is byte-for-byte reproducible.

---

## 3. The file-dialog mock (Ruffle `tests/framework/src/backends/ui.rs`)

Equally scripted, and keyed off **test content**, not test config:

- `browse(filters)` where any filter's `description == "debug-select-success"`
  → success; otherwise → cancel.
- `save(data, fileNameHint)` where the hint is `"debug-success.txt"` →
  success; otherwise → cancel.
- The simulated selection is always: name `test.txt` (`test1.txt`,
  `test2.txt`, `test3.txt` for the multi-file variant), contents
  `Hello, World!` (13 bytes), type `.txt`, creation/modification time
  **`None`** (which is why `filereference_browse_select` expects
  `creationDate: null`, not a date).
- `URLLoader`/`URLStream` against a URL containing `?debug-success` also
  return `Hello, World!` — `navigator.rs:124`.

---

## 4. Per-test triage

### Bucket P — pure class surface, **no transport of any kind** · 10 tests

Nothing here needs a byte to move. Every one of these tests currently scores
0 because the class does not exist.

| Suite | Test | lines | What it actually asserts |
|---|---|---|---|
| avm2 | `socket_errors` | 0/56 | All 28 `IDataInput`/`IDataOutput` methods **plus** `flush()`/`close()` throw `Error #2002 Operation attempted on invalid socket.` on an unconnected `Socket`. Renders as `Error: Error #2002…` — our `error_init` already gives `flash.errors` subclasses `name = "Error"`, so an `IOError` prints correctly with no extra work. |
| avm2 | `netconnection_properties` | 0/78 | The whole `NetConnection` property surface in three states (fresh / `connect(null)` / `connect("http://…")`). All values are constants (`maxPeerConnections 8`, `objectEncoding 3`, `proxyType "none"`, `farNonce` = 64 `0`s, `protocol "rtmp"`, `uri` the string `"null"`); everything not available in a state throws `ArgumentError #2126`. Model: `net_connection.rs::NetConnection::{is_connected,far_id,…}` — a two-variant enum, `Local` vs `FlashRemoting`. |
| avm2 | `netconnection_close` | 0/55 | `NetStatusEvent` **order**, dispatched synchronously inside `connect`/`close`: `connect(null)` → `Connect.Success`; re-`connect` while connected → `Connect.Closed` then `Connect.Success`; `close()` while connected → `Connect.Closed`; `close()` while not connected → nothing; `connect("http://…")` → **no event at all**; `close()` after an http connect → `Connect.Closed` **plus** a second event with `code`/`description`/`details` all `""` (Ruffle's own comment: "I have no idea why, but a NetConnection receives a second and nonsensical event on close"). Needs `flash.events.NetStatusEvent`. |
| avm2 | `netstream_connect` | 0/7 | Same `Connect.Success` event via a `NetStream`-shaped test; only needs `NetConnection` + `NetStatusEvent.toString()`. |
| avm2 | `netstream_client` | 0/10 | `new NetStream(con).client` defaults to the stream itself; assigning a non-Object (`3`, `true`, `"abcd"`, `null`, `undefined`) throws `TypeError` `errorID 2004`; assigning `{}` or a `Class` succeeds. No streaming. |
| avm2 | `responder_null_callbacks` | 0/1 | `trace(new Responder(null, null))` → `[object Responder]`. |
| avm2 | `av_networking_params` | 0/9 | `flash.media.AVNetworkingParams` — three Booleans, ctor defaults `(false, true, false)`. |
| avm2 | `net_stream_play_options` | 0/6 | `flash.net.NetStreamPlayOptions` — `len -1`, `offset -1`, `oldStreamName null`, `start -2`, `streamName null`, `transition null`. |
| avm2 | `air_datagram_socket` | 0/1 | `trace("Socket: " + new DatagramSocket())` → `[object DatagramSocket]`. `[player_options] runtime = "AIR"`; we gate nothing on runtime, so registering the class is enough. |
| avm2 | `sandbox_type_local_network` | 0/1 | `Security.sandboxType` must be `localWithNetwork` when the SWF's `FileAttributes.UseNetwork` bit is set. We hardcode `localWithFile` (`avm2_globals.c:1805`). The recompiler **already** emits `#define SWF_USE_NETWORK` (`swf.cpp:1115`) and AVM1 already reads it (`g_use_network`, `action.c:37611`). One line. |

### Bucket S — `socket.json` replay: `Socket` + `XMLSocket` data path · 14 tests

One mechanism (harness preprocessor + in-process mock transport + the two
socket classes' buffers), split across both VMs.

| Suite | Test | lines | Note |
|---|---|---|---|
| avm2 | `socket_connect` | 0/4 | `connected` false before/after `connect()`, **true** inside the `Event.CONNECT` handler, false after `close()`. Script asserts the `writeUTF("Hello!")` bytes. |
| avm2 | `socket_close` | 0/2 | `Event.CONNECT` then `Event.CLOSE` from a `Disconnect`-only script. |
| avm2 | `socket_after_disconnect` | 0/1 | `connected` is already `false` inside the `CLOSE` handler. |
| avm2 | `socket_read_big` | 0/48 | Every `read*` over a 78-byte `Send`, big-endian. Pure `ByteArray` reuse. |
| avm2 | `socket_read_little` | 0/48 | Same, `Endian.LITTLE_ENDIAN`. |
| avm2 | `socket_write_big` | 0/15 | Every `write*`; graded by the script's `Receive` assertion, and by 15 trace lines. |
| avm2 | `socket_write_little` | 0/14 | Same, little-endian. |
| avm2 | `socket_read_write_object` | 0/8 | `writeObject`/`readObject` under both `ObjectEncoding.AMF3` and `AMF0` on the same socket, plus a `ProgressEvent.SOCKET_DATA` with `bytesLoaded=8 bytesTotal=0`. Both AMF codecs already exist. |
| avm2 | `xml_socket` | 0/11 | `XMLSocket`: `timeout` clamps `0 → 250` (default 20000); `close()`/`send()` while unconnected throw #2002; `send(XML)` writes `toString()` + NUL; inbound NUL-delimited frames become `DataEvent.DATA`. Needs `flash.events.DataEvent`. |
| avm1 | `xml_socket` | 1/8 | `onConnect(true)`, `onXML` per frame, `onClose`. Our stub's `connect` returns `false` so nothing fires. |
| avm1 | `xml_socket_on_data` | 0/7 | If `onData` is overridden it replaces `onXML` entirely (`onXML` must never run). |
| avm1 | `xml_socket_close_in_handler` | 0/6 | `close()` **inside** `onData` must not re-enter or fire `onClose`. |
| avm1 | `xml_socket_segmented` | 0/29 | The NUL-framing spec: 12 `Send`s split across frame boundaries produce 14 `onData` calls, including three empty strings; a trailing unterminated fragment is dropped at disconnect. |
| avm1 | `xml_socket_connect_null` | 1/12 | **No transport at all** — `log_fetch = true`, `socket.json` is `[]`. `connect()` / `connect(null)` / `connect(undefined)` fall back to the movie URL's domain (`localhost`) and port `0`; an explicit host passes through. Grades only the `Navigator::connect_socket` log block. |

### Bucket D — file dialogs · 14 tests

| Suite | Test | lines | Note |
|---|---|---|---|
| avm2 | `filereference_uninitialized` | 0/8 | Property surface before any browse: `creator`/`data` are `null`; `creationDate`/`modificationDate`/`name`/`size`/`type` throw `Error #2037`; `extension` throws `ReferenceError #1069` (**the class must be sealed**). |
| avm2 | `filereference_browse_cancel` | 0/3 | Default `browse()` → `Event.CANCEL`, properties still #2037. |
| avm2 | `filereference_browse_select` | 0/9 | `debug-select-success` filter → `Event.SELECT`, `name test.txt`, `size 13`, `type .txt`, dates `null`. |
| avm2 | `filereference_load` | 0/31 | `load()` after select → `OPEN`/`PROGRESS`/`COMPLETE` + `data` as a `ByteArray`. |
| avm2 | `filereference_save` | 0/16 | `save(data, "debug-success.txt")`. |
| avm2 | `filereference_save_and_browse` | 0/42 | Sequencing of the two dialogs. |
| avm2 | `filereference_save_and_load` | 0/22 | **`known_failure = true`** — best case is `ruffle_matched`. |
| avm2 | `filereferencelist_browse_cancel` | 0/6 | `fileList` is `null` before browse and `[]` (traces as empty) after. |
| avm2 | `filereferencelist_browse_select` | 0/7 | Three files. |
| avm1 | `file_reference_browse_cancel` | 10/21 | `onCancel` never fires (the 11 missing lines are the post-cancel dump). |
| avm1 | `file_reference_list_browse_cancel` | 1/4 | Same. |
| avm1 | `file_reference_list_browse_select` | 1/7 | `browse([{description:"debug-select-success", …}])` → `true`, then `onSelect` with a 3-entry `fileList`. |
| avm1 | `file_reference_list_browse_invalid_filters` | 18/36 | Filter-object validation errors (half already right). |
| avm1 | `file_reference_list_asbroadcaster` | 0/9 | `_listeners.length` starts at **0** — ours is undefined at that point; pure AsBroadcaster wiring, no dialog. |

### Bucket U — `URLStream` · 2 tests

| Suite | Test | lines | Note |
|---|---|---|---|
| avm2 | `urlstream_basic` | 0/5 | `URLStream` = `URLLoader`'s fetch pipeline with an `IDataInput` face (`bytesAvailable`, `readUTFBytes`) and `OPEN`/`PROGRESS`/`COMPLETE` in that order. The sibling asset (`data.txt`) is bundled and `findDataFile` already resolves it — this is the URLLoader path with a different sink. |
| from_shumway | `flash_net_URLLoader` | 0/7 | `openHandler`/`progressHandler` (`bytesLoaded=2674 bytesTotal=2674`)/`httpStatusHandler`/`completeHandler` order over its own `test.swf`. Same pipeline; listed here because it is one fix away from bucket U's, not because it needs `URLStream`. |

### Bucket L — `LocalConnection` as an in-process registry · 4 tests

Ruffle's `LocalConnections` is a per-player map from channel name to
listener. Both endpoints of every corpus test are **inside the same player**
(the main movie plus child SWFs the Loader arc already executes), so no IPC
is needed — but a cross-VM value bridge is.

| Suite | Test | lines | Note |
|---|---|---|---|
| avm2 | `localconnection` | 67/890 | The specification: 30 sub-tests over connect/close/send with funky names, prefixes, case sensitivity, protected method names, `AsyncErrorEvent` for a missing callback, `StatusEvent` `level "error"` vs `"status"`, **and** message delivery into an AVM1 child and an AVM2 child with argument translation. Currently dies with `#1009` inside the AVM2 child's `Child()` — check this first, it may be a Loader-arc leftover rather than a LocalConnection problem. |
| avm2 | `localconnection_send` | 0/4 | `send(null, …)` → `TypeError #2007 Parameter connectionName must be non-null`; `send(name, null)` → `… methodName …`; then a `StatusEvent` with `code=null level="error"`. |
| from_shumway | `localconnection` | 3/12 | Two-SWF send/receive: `#2082` on double connect, `#2095` `AsyncError` wrapping the callee's `#1069`, and a successfully delivered string. |
| avm1 | `localconnection_top_level` | 4/7 | Argument **serialization** across the wire: a `Date` survives, an `XML` survives, a `TextField` becomes `undefined`, a `Function` becomes `[object Object]`. Needs bucket W's serializer. |

### Bucket W — AVM1 AMF0 serializer + `NetConnection.call` wire · 9 tests

All nine grade the `Navigator::fetch:` body — a hex dump of an AMF0 packet —
or a SharedObject round-trip through the same codec. There is no AVM1 AMF
code today; `avm2_amf.c`'s `w0_*` writer is the model, but it walks
`Avm2Object`, so the AVM1 side is a real port, not a call.

| Test | lines | Note |
|---|---|---|
| `amf0_serde_suite` | 16/144 | The acceptance suite: every AMF0 type round-tripped through SharedObject, LocalConnection and NetConnection channels, incl. `2^31`/`2^32`/`2^63` array indices, unpaired surrogates, negative and fractional keys. `known_failure` — ships `avm1_test_suite.ruffle.sol` and `output.ruffle.txt`. |
| `amf_array_serialization` | 3/10 | dense/sparse/mixed/fake arrays + Date + XML + nesting across all three channels. `known_failure`. |
| `amf_strict_array_serialization` | 1/7 | Which array shapes serialize as **StrictArray (`0x0A`)** vs **ECMAArray (`0x08`)** — Flash promotes a dense array to strict; Ruffle does not, which is why several of these are `known_failure`. |
| `amf_sharedobject_strict_array_serialization` | 2/3 | Only `SharedObject flushed successfully.` is missing — `flush()` must return truthy and write the `.sol`. |
| `amf_serialize_typed_objects` | 1/6 | `Object.registerClass` aliases → AMF0 typed-object marker `0x10`; last registration wins; alias resolution happens at **serialization** time, not construction time. |
| `amf_swf6_serialize_typed_objects` | 1/6 | SWF6 variant. |
| `amf_swf6_case_insensitive_typed_objects` | 1/6 | SWF6 alias lookup is case-**insensitive**. |
| `amf_swf8_case_sensitive_typed_objects` | 1/6 | SWF8 is case-sensitive. |
| `netconnection_serialize_arrays` | 1/6 | `NetConnection.call` with array arguments. |

### Bucket X — AVM2 AMF gaps · 4 tests

| Suite | Test | lines | Note |
|---|---|---|---|
| from_avmplus | `as3/AMF/AMFSerializer` | 223/225 | **Two lines.** (a) `ObjectEncoding.dynamicPropertyWriter` — an `IDynamicPropertyWriter` hook consulted per dynamic property during `writeObject`; (b) `IExternalizable` — a class implementing it serializes via `writeExternal(IDataOutput)`/`readExternal(IDataInput)` with the AMF3 `0x07` externalizable trait bit. Both live in `avm2_amf.c`; the "not implemented" comment is already at line 995. Note `test.toml` sets `ignore = true` upstream (Ruffle stack-overflows on the recursive-object case); our harness does not honour `ignore`, and we get past that case, so this is gradeable for us. |
| avm2 | `netconnection_send_remote` | 0/50 | `NetConnection.call` over Flash Remoting: AMF0 packet framing (`00 00 | header count | body count | "test.method" | "/1" | length | StrictArray`), `Responder.onResult`/`onStatus`, `addHeader`. `log_fetch = true`. |
| avm2 | `netconnection_serialize_arrays` | 0/6 | Same wire, array shapes. `known_failure` (Flash promotes dense arrays to StrictArray in the AMF0 body; Ruffle emits ECMAArray). |
| avm2 | `amf_array_serialization` | 4/17 | Same, plus a `LocalConnection` leg and a `ByteArray` leg. `known_failure`. |

### Bucket M — media transport · 6 tests · **WON'T DO in this arc**

`netstream_play_flv` (0/16), `netstream_seek_flv` (0/49),
`netstream_play_stop_replay` (0/11), `netstream_flv_date` (1/4),
`audio/aac` (3/18), `audio/g711` (2/6).

Derived from what they assert: each one requires a real FLV demuxer plus an
audio or video decoder (AAC, G.711 A-law/µ-law, H.263/VP6) and, for two of
them, an image comparison against a decoded frame. `netstream_flv_date` is
the cheapest (4 lines — it only wants `onMetaData` off an FLV's AMF0
metadata tag) and is the one to revisit if a media arc ever opens. That is
`feature-priority-map.md` row 30's other half, not this arc.

### Bucket Z — caught by the sweeps, **not net** · 4 tests

Recorded so the next census does not re-litigate them.

| Test | Why not net |
|---|---|
| `avm1/native_objects_swf6` (114/115) | Confirmed by local run: the single diff is `new TextField(): non-object: undefined` vs our `native`. A native-class-identity question. |
| `avm1/global_instance_decls` (26/758) | Confirmed by local run: the diffs are `__proto__` missing `DONT_DELETE` and `PrintJob`'s read-only geometry properties. A property-flags question — but see the canary note in §5, because it **does** enumerate `LocalConnection`, `NetConnection`, `XMLSocket`, `SharedObject`, `flash.net.FileReference` and `flash.net.FileReferenceList`, so anything this arc adds to those prototypes moves its lines. |
| `from_gnash/misc-ming.all/NetStream-SquareTest` (91/216) | Half AVM1 `NetConnection`/`NetStream` property surface (already passing), half FLV playback with an `input.json` — bucket M owns the remainder. Ships an `output.ruffle.txt`, so `ruffle_matched` is its ceiling. |
| `avm2/shared_object`, `avm1/shared_object` | Two-run tests (`output1.txt`/`output2.txt`) that the harness does not enumerate at all; they are not in any results file. A harness feature, not a net feature. |

---

## 5. Ranked tranches

Ranked by yield-per-effort. Predictions get postmortemed in §6 — arc
convention — and **later tranches get re-predicted after each one lands**.

### Tranche 1 — pure class surface, no transport · **predicted +9** · SMALL-MEDIUM

The gate item, and it clears the ≥5 bar by itself: bucket P is 10 tests that
need constants, getters, and one synchronous event dispatch. Two files
(`avm2_globals.c` for the classes, `avm2_events.c` for `NetStatusEvent`),
plus one line in the `Security` block.

1. `flash.net.Socket` — the full `IDataInput`/`IDataOutput` method set,
   `connect`/`close`/`flush`, `connected`/`bytesAvailable`/`bytesPending`/
   `endian`/`objectEncoding`/`timeout`. With no transport every method
   throws `IOError #2002`; tranche 2 fills in the buffers behind them.
2. `flash.net.NetConnection` + `flash.net.Responder`, modelled on
   `net_connection.rs`'s two-variant protocol enum, with `ArgumentError
   #2126` for every accessor unavailable in the current state.
3. `flash.events.NetStatusEvent` (`info` object, `toString`), dispatched
   synchronously from `connect`/`close` in Ruffle's exact order — including
   the second, empty-code event on an explicit close of a Flash Remoting
   connection.
4. `flash.net.NetStream` — `client` only (default self, `TypeError #2004`
   for non-objects), enough for `netstream_client`/`netstream_connect`.
5. `flash.net.NetStreamPlayOptions`, `flash.media.AVNetworkingParams`,
   `flash.net.DatagramSocket` — constant-valued stubs.
6. `Security.sandboxType` ← `SWF_USE_NETWORK`.

Targets: `socket_errors`, `netconnection_properties`, `netconnection_close`,
`netstream_connect`, `netstream_client`, `responder_null_callbacks`,
`av_networking_params`, `net_stream_play_options`, `air_datagram_socket`,
`sandbox_type_local_network` (10 candidates; predict 9 — `netconnection_close`
is the one whose event order is inferred from Ruffle's source rather than read
off a diff, and 55 lines leave no slack).

Blast radius: new classes only, plus one existing getter. Canaries:
`avm2/bytearray_readobject_amf0`, `avm2/bytearray_readobject_amf3`,
`avm2/urlrequest`, `avm2/net_navigateToURL`, `avm2/shared_object_no_root`,
`avm1/netconnection_close`, `avm1/global_instance_decls` (§4 bucket Z), plus
the standing link canaries `avm2/verify_method_info_oob`,
`avm2/verify_method_info_duplicate`, `mixed_avm/avm1_loads_avm2`.

### Tranche 2 — `socket.json` replay + `Socket`/`XMLSocket` data path · **predicted +12** · MEDIUM-LARGE

Bucket S (14 candidates). Three pieces: a `preprocess_socket_json` in
`verify_output.py` mirroring `preprocess_input_json`; an in-process mock
transport in the runtime that both VMs share (script cursor, read buffer,
write buffer, `Receive` assertion, `Disconnect`/`WaitForDisconnect`); and the
two socket classes' buffer plumbing on top. Adds the
`Navigator::connect_socket` emitter to `src/utils.c` next to
`swf_log_fetch_queue`. Predict 12 of 14 — the two `read_big`/`read_little`
48-line tests are the ones with the most surface to get exactly right.

### Tranche 3 — file dialogs · **predicted +10** · MEDIUM

Bucket D (14 candidates). `FileReference`/`FileReferenceList`/`FileFilter` in
AVM2 (sealed, so absent properties throw #1069) and real `browse()`/`save()`
in AVM1, both over the §3 mock. `filereference_save_and_load` is
`known_failure` (ceiling `ruffle_matched`) and the two 30-plus-line
`load`/`save_and_browse` tests carry the most ordering risk.

### Tranche 4 — `URLStream` · **predicted +2** · SMALL

Bucket U. `URLStream` is `URLLoader`'s existing fetch pipeline with an
`IDataInput` sink; `from_shumway/flash_net_URLLoader` rides on the same event
ordering.

### Tranche 5 — AVM2 AMF gaps · **predicted +1** · SMALL

Bucket X's first row. `IExternalizable` + `ObjectEncoding.dynamicPropertyWriter`
in `avm2_amf.c`. One test, two lines, but it is the last thing standing
between us and a 225/225 on the avmplus AMF acceptance suite — and both hooks
are prerequisites for anything that serialises user classes over a wire.

### Tranche 6 — `LocalConnection` registry · **predicted +3** · LARGE

Bucket L. A per-player channel map with Ruffle's name rules (host prefixes,
`_`-prefixed names, case sensitivity, protected method names), `StatusEvent`
/`AsyncErrorEvent` semantics, and an AMF value bridge between the AVM1 and
AVM2 halves. `avm2/localconnection` (890 lines) is the specification; predict
it does **not** land in this tranche.

### Tranche 7 — AVM1 AMF0 serializer + `NetConnection.call` · **predicted +4** · LARGE

Bucket W (9 candidates). A new `ActionVar → AMF0` writer plus reader, the
`Object.registerClass` alias table on the write side, SharedObject `.sol`
persistence, and `NetConnection.call` packet framing into the fetch log.
Predict 4 of 9: the strict-vs-ECMA array promotion rule is the load-bearing
unknown and four of these tests are `known_failure`, so several can only
reach `ruffle_matched`.

### Tranche 8 — AVM2 `NetConnection.call` wire · **predicted +2** · MEDIUM

Bucket X's remaining three. Depends on tranche 1's `NetConnection` and
tranche 7's settled array-promotion rule; the AMF0 writer itself already
exists.

### Won't-do in this arc

- **Bucket M** (6 tests) — FLV demux + audio/video decode; row 30's media
  half, not its net half.
- **Bucket Z** (4 tests) — not net; two of them are not even enumerated by
  the harness.

**Arc total if tranches 1–8 land: +43**, leaving 10 dispositioned and 11
scoped-but-unpredicted (the surplus inside buckets S/D/L/W).

---

## 6. Postmortem

### Tranche 1 — SHIPPED `937047612` + `722dea0e9`, CI `30403506144` then `30405770263` (graphics, full)

**+10 vs +9 predicted, zero regressions** after the follow-up. The first run
landed the 10 gains and one regression (`air_hidden_lookup`, below); the
verification run after the AIR gate is green on all 34 jobs with **no
regressions at all**.

Against the session-start baseline `2ed94a302`, corpus effective
**3890 → 3901 / 4420 (+11)**; `avm2` **926 → 936 / 1221**. The eleventh gain
is **not** ours: `visual/simple_shapes/heavy_tesselation` was `recomp_fail` in
the baseline run and passes here, an unrelated CI-side flake — **the arc's
gain is +10.** Status histogram moved `output_mismatch 522 → 512` /
`pass 3650 → 3661` / `recomp_fail 1 → 0`; `ruffle_matched` (240) and
`runtime_error` (7) flat, and there is no `compile_fail`, `segfault` or
`timeout` bucket in either run.

Three corpus-wide `matching_lines` drops, all benign and all the same cause:
`avm2/all_classes/events/swf{10,11,12}` go 4 → 1 of ~1700. These dump
`describeType` XML for every `flash.events` class, so **adding
`NetStatusEvent` correctly** inserts a block and shifts the whole diff's
alignment — the classic `results-diff-line-metrics-mislead` case where
matching_lines falls on a fix. Verified by local run: the class now emits
`base="flash.events.Event"` in the right sorted position, and these tests'
real failure (the `describeType` shape itself) is untouched and belongs to
another arc. `swf9` gained a line for the same reason.

All ten predicted targets landed:

| Test | before | after |
|---|---|---|
| `socket_errors` | 0/56 | **pass** |
| `netconnection_properties` | 0/78 | **pass** |
| `netconnection_close` | 0/55 | **pass** |
| `netstream_connect` | 0/7 | **pass** |
| `netstream_client` | 0/10 | **pass** |
| `responder_null_callbacks` | 0/1 | **pass** |
| `av_networking_params` | 0/9 | **pass** |
| `net_stream_play_options` | 0/6 | **pass** |
| `air_datagram_socket` | 0/1 | **pass** |
| `sandbox_type_local_network` | 0/1 | **pass** |

Three more improved without flipping, all as predicted side effects:
`amf_array_serialization` 4/17 → 6/17 (a `Responder` now exists, so the test
gets past its first construction), `socket_connect` 0/4 → 2/4 (the two
`connected` lines outside the CONNECT handler), `sandbox_type_remote`
0/3 → 1/3.

**What the triage got wrong — one regression, `avm2/air_hidden_lookup`
(pass → 1/2).** `flash.net.DatagramSocket` is `[API("668")]`, i.e. AIR-only,
and `air_hidden_lookup` asserts that `getDefinitionByName` on it **throws**
under a plain Flash Player runtime. The triage read `air_datagram_socket`'s
`[player_options] runtime = "AIR"` and concluded "we gate nothing on runtime,
so registering the class is enough" — which is true for that test and exactly
backwards for its twin. Registering it unconditionally trades one test for the
other. Fixed by `722dea0e9`: `verify_output.py` turns `runtime = "AIR"` into
`-DSWF_RUNTIME_AIR` at both build sites and `avm2_net.c` gates the class on it,
so both tests pass. The three `runtime = "AIR"` tests in the corpus are
`air_datagram_socket`, `air_ifilepromise` and `native_menu_basic`; the latter
two were already failing on unrelated AIR classes and are unchanged.

**Lesson to carry into tranche 3.** A `[player_options]` marker is not only a
capability the harness must *provide* — it is also a capability the harness
must *withhold* from every other test. The census's marker sweep found the
tests that need a mock; it did not ask which tests assert the mock's absence.
Bucket D (`FileReference`) has the same shape: `filereference_uninitialized`
asserts that `extension` is **not** a property of `FileReference`, i.e. that
the class is sealed, in the same breath as the other tests asserting that
`browse()` works. Sweep for the negative assertion before adding the class.

**What the triage got right.** The "no transport at all" separation held
exactly: every one of the ten is a constant, a getter, or one synchronous
event dispatch, and none of them needed a byte to move. Two findings paid for
themselves immediately — Ruffle's two-variant protocol enum (which is why
`connect("http://…")` reports `connected == false` while still answering
`uri`, a shape no amount of guessing would have produced) and the fact that
`error_init` already gives `flash.errors` subclasses `name = "Error"`, so the
56-line `socket_errors` acceptance table needed no error work whatsoever.

**Re-prediction of later tranches after tranche 1** (arc convention). Nothing
tranche 1 revealed changes tranche 2's or 3's shape, and both remain the two
largest blocks. One adjustment: tranche 5 (`IExternalizable` +
`dynamicPropertyWriter`) is now slightly cheaper than scoped, because
`Responder` and `NetConnection` exist and `avm2_net.c` is the obvious home for
the `NetConnection.call` half of tranche 8 that will consume them.
