# net/socket arc — triage + tranches

**Created**: 2026-07-28 · **Baseline**: `2ed94a302` (session start), per-suite
`_results/results_graphics.json` from CI `30397635331` (the input-arc closeout
run, SHA `bbefcf376`).
**Status**: **ARC CLOSED 2026-07-29 at +66.** All nine ships landed, every one
at or over its prediction. Full postmortems in §6; final accounting, census
disposition and ranked lessons in **§8**.

| Tranche | Commit / CI | Predicted | Actual | Corpus effective |
|---|---|---|---|---|
| 1 — pure class surface | `937047612` + `722dea0e9` / `30403506144`, `30405770263` | +9 | **+10** | 3890 → 3901 |
| 2 — `socket.json` + Socket/XMLSocket | `767a301d2` + `e173acc9a` / `30412279387`, `30414817519` | +12 | **+14** | 3901 → 3914 |
| 3 — file dialogs | `72fdc5e93` / `30418985155`, `30418993536` | +11 | **+15** | 3914 → 3929 |
| 4 — `URLStream` | `8c3b7673f` / `30477186369` | +2 | **+3** | 3929 → 3932 |
| 3b — AVM1 download/upload | `6cf854900` / `30480184835` | +5 | **+7** | 3932 → 3939 |
| 7 — AVM1 AMF0 + `NetConnection.call` | `702d38a35` + `698bdddfa` / `30494443127` | +7 | **+11** | 3939 → 3950 |
| 5 — AVM2 AMF gaps | `6a07045c4` / `30499537278` | +1 | **+1** | 3951 → 3952 |
| 8 — AVM2 `NetConnection.call` | `01f30d3f5` + `8a302905d` / `30501480658` | +2 | **+2** | 3952 → 3953 |
| 6 — `LocalConnection` registry | `34171042f` / `30505002399` | +3 | **+3** | 3953 → **3957 / 4421** |

Per-suite at close: `avm2` **960 / 1221**, `avm1` **687**, `from_shumway`
**183**, `from_avmplus` **1510**. **Arc total: +66** against a §5 prediction of
+43 (+52 summed per tranche after the census corrections).
**NEXT is not in this arc**: `feature-priority-map.md`'s net row is closed; the
next row by yield is the PixelBender 25 / Stage3D 13 scoping decision. The one
scoped-but-unlanded item is the **AVM1↔AVM2 LocalConnection delivery bridge**
(`avm2/localconnection`, 589/890) — a standalone follow-up, sized in §6's
tranche-6 postmortem.

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
| from_shumway | `flash_net_URLLoader` | 0/7 | `openHandler`/`progressHandler` (`bytesLoaded=2674 bytesTotal=2674`)/`httpStatusHandler`/`completeHandler` order over its own **source file** (`test.as`, not `test.swf`). Same pipeline; listed here because it is one fix away from bucket U's, not because it needs `URLStream`. |
| from_shumway | `stream1` | 0/9 | **Added post-hoc** — a `URLStream` test the sweeps missed, because its NAME says `stream1` and it ships no `.as` source to grep. `readByte`/`readUnsignedShort`/`readBytes` over `stream1.swf.bin` in both endiannesses. |

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

### Tranche 3 — file dialogs · **predicted +10** (re-predicted +11; **actual +15**) · MEDIUM

Bucket D (14 candidates). `FileReference`/`FileReferenceList`/`FileFilter` in
AVM2 (sealed, so absent properties throw #1069) and real `browse()`/`save()`
in AVM1, both over the §3 mock. `filereference_save_and_load` is
`known_failure` (ceiling `ruffle_matched`) and the two 30-plus-line
`load`/`save_and_browse` tests carry the most ordering risk.

### Tranche 4 — `URLStream` · **predicted +2** (**actual +3**) · SMALL

Bucket U. `URLStream` is `URLLoader`'s existing fetch pipeline with an
`IDataInput` sink; `from_shumway/flash_net_URLLoader` rides on the same event
ordering. The third gain, `from_shumway/stream1`, is a `URLStream` test §0's
sweeps could not see — see the postmortem.

### Tranche 5 — AVM2 AMF gaps · **predicted +1** (**actual +1; SHIPPED**) · SMALL

Bucket X's first row. `IExternalizable` + `ObjectEncoding.dynamicPropertyWriter`
in `avm2_amf.c`. One test, two lines, but it is the last thing standing
between us and a 225/225 on the avmplus AMF acceptance suite — and both hooks
are prerequisites for anything that serialises user classes over a wire.

### Tranche 6 — `LocalConnection` registry · **predicted +3** (re-predicted SMALL after tranche 7; **actual +3; SHIPPED**) · LARGE

Bucket L. A per-player channel map with Ruffle's name rules (host prefixes,
`_`-prefixed names, case sensitivity, protected method names), `StatusEvent`
/`AsyncErrorEvent` semantics, and an AMF value bridge between the AVM1 and
AVM2 halves. `avm2/localconnection` (890 lines) is the specification; predict
it does **not** land in this tranche.

### Tranche 7 — AVM1 AMF0 serializer + `NetConnection.call` · **predicted +4, re-scoped 2026-07-29 to +7 of 11 · SHIPPED, actual 11/11** · LARGE

Bucket W (9 candidates; the scoping pass in §7 corrects the census to 11 and
retires two assumed subsystems — `.sol` file I/O and a `.sol`-input reader are
NOT needed). Full scoping, mechanism inventory, per-test dependency matrix,
and the risk register are in **§7** below. Headline: the strict-vs-ECMA rule
is fully resolved from Flash-recorded bytes (numeric-keys-only → StrictArray
`0x0A` with `0x06` holes on the wire; LSO/`getSize` mode keeps ECMAArray),
and the load-bearing unknown is now the **`super()` native-constructor
upgrade** (2 tests) plus byte-exact reference counting (`amf0_serde_suite`
only).

### Tranche 8 — AVM2 `NetConnection.call` wire · **predicted +2** (**actual +2; SHIPPED**) · MEDIUM (→ SMALL after tranche 7)

Bucket X's remaining three. Depends on tranche 1's `NetConnection` and
tranche 7's settled array-promotion rule; the AMF0 writer itself already
exists. After tranche 7 the packet framing (`src/amf_packet.c`) is done and
VM-agnostic, the response-dispatch shape is implemented and graded, and
`avm2/netconnection_send_remote`'s `localhost/test{1,2,3}` are already bundled
— see §6's tranche-7 re-prediction.

### Won't-do in this arc

- **Bucket M** (6 tests) — FLV demux + audio/video decode; row 30's media
  half, not its net half.
- **Bucket Z** (4 tests) — not net; two of them are not even enumerated by
  the harness.

**Arc total if tranches 1–8 land: +43**, leaving 10 dispositioned and 11
scoped-but-unpredicted (the surplus inside buckets S/D/L/W).

**Outcome: all nine ships landed for +66** — every tranche met or beat its
prediction, and the surplus above came in too. Final accounting, per-bucket
disposition and the ranked lessons are in **§8**.

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

### Tranche 2 — SHIPPED `767a301d2` + `e173acc9a`, CI `30412279387` / `30412301703` then `30414817519`

**+14 vs +12 predicted, zero regressions.** All 14 bucket-S targets, in BOTH
modes. Against the session-start baseline `6a622700c`, corpus effective
**3901 → 3914 / 4420**; `avm2` **936 → 945 / 1221**, `avm1` **658 → 663**.
The no-graphics run lands on identical per-suite numbers, so the new tick hook
keeps mode parity in both frame loops. The verification run reports
`OTHER STATUS MOVES: 0`.

The one row `corpus_status_diff` lists as a regression,
`visual/simple_shapes/heavy_tesselation` (`pass → recomp_fail`), is a
**recompiler timeout** at the harness's 30s limit: it reproduces locally
against an untouched recompiler and flipped the *other* way during tranche 1.
Not ours.

**14/14 bucket-S targets pass locally, in BOTH modes, against a predicted 12.**
The two 48-line `socket_read_big` / `socket_read_little` tests — named in §5 as
"the ones with the most surface to get exactly right" — needed **no
socket-specific read code at all**, which is where the +2 came from.

Five pieces, in the order they were built:

1. **The mock transport** (`src/utils.c`, ~330 lines). Ruffle's
   `TestNavigatorBackend::connect_socket` spawns a future over the event list;
   here the future is a per-connection **cursor** over the parsed script, the
   player→server channel is an **outbox queue**, and the server→player channel
   is one global **action queue**. `Receive` / `WaitForDisconnect` become "stop
   advancing the cursor and return". Each connection replays the script from
   its own cursor, because Ruffle clones the event list per connect.
2. **`preprocess_socket_json`** in `verify_output.py` → `SEND/RECV <hex>`,
   `DISCONNECT`, `WAITDISCONNECT`, handed to the runtime through
   `SWF_SOCKET_SCRIPT` (argv slot 1 belongs to input events).
3. **AVM2 `Socket`** — a ByteArray ext PAIR plus a **direction-aware alt
   resolver** registered into `avm2_bytearray.c`. All 28 IDataInput/IDataOutput
   bodies are shared verbatim; only the 11 `write*` entry points changed, from
   `this_ba(act)` to `this_ba_w(act)`.
4. **`flash.events.DataEvent`** (extends TextEvent, `data` = `text`) and a
   native **`XMLSocket`** wrapping a private inner `Socket`.
5. **AVM1 `XMLSocket`** — a pointer-keyed side table (the `NetConnection`
   shape), NUL framing, and a real `onData` default that builds `new XML(...)`
   and calls `this.onXML`.

**The one real surprise, and the reusable lesson: our frame loops exit early;
Ruffle's does not.** Both AVM1 loops (`swf_core.c`, `swf.c`) stop as soon as
`quit_swf` is set and nothing is still asking to run — `hasActiveTimers()`,
`hasPlayingSounds()`, `hasActiveNetStreams()`, … Ruffle's harness just runs its
full `num_ticks`. A single-frame movie therefore died on tick 2, before the
socket tick could deliver anything: four of the five AVM1 tests produced only
the `onConnect` line, or nothing. The fix is a new `swf_socket_pending()` in
the same idiom, added at **three** exit sites in `swf_core.c` (the `g_force_quit`
gate, the past-last-frame gate, and the `current_frame >= g_frame_count` gate)
and **two** in `swf.c`. The third `swf_core.c` site is the one that cost the
extra debugging round — it sits ~300 lines *after* the socket tick, so tick 2
pumped and then exited anyway.

Generalize: **any new event source with its own tick cadence must also register
as a reason for the AVM1 loop to keep ticking**, and the loop has more than one
exit. `grep -n hasActiveNetStreams` finds all of them — it is already the
canonical "an async subsystem is still live" predicate. The AVM2 loop
(`avm2_display_run_tick`) has no such early exit and needed nothing.

Two smaller findings:

- **`bytesAvailable` does not need Ruffle's drain-from-front buffer.** Ruffle
  pops the read buffer's front; we advance `position` and append inbound chunks
  at the end. `bytesAvailable = len - position` is observationally identical for
  every corpus test, and it makes `readBytes(ba, 0, 0)`'s "0 means the rest"
  rule fall out of the existing ByteArray body unchanged.
- **`XMLSocket.send(XML)` must use `toXMLString()`, not `toString()`.** The
  distinction is load-bearing and the corpus pins it:
  `<root>Hello!</root>.toString()` is the *text node* `Hello!`, so a
  `toString()` implementation passes `avm1/xml_socket` and fails
  `avm2/xml_socket`'s third `Receive`.

**Blast radius, measured.** A stash-diff sweep over 25 canaries (ByteArray ×7,
AMF ×3, NetConnection ×2, `air_hidden_lookup`, `verify_method_info_oob`, two
input-driven tests, `all_classes/events/swf10`, `global_instance_decls`,
`native_objects_swf6`, `mixed_avm/avm1_loads_avm2`,
`from_avmplus/as3/AMF/AMFSerializer`) is **byte-identical except one**:
`avm2/all_classes/events/swf10` goes from `DataEvent not accessible` to a real
`describeType` block, shifting that dump's alignment. Exactly the
`NetStatusEvent` case from tranche 1 — expect the same `matching_lines` dip on
`all_classes/events/swf{9,10,11,12,30}` and read it as a fix, not a regression.
Graphics-mode canaries were cross-checked against the no-graphics captures and
differ only by Dawn's stderr warnings.

The AVM1 `XMLSocket.prototype` shape was deliberately left **byte-identical to
the stub's** — same six names, same order, same `DONT_ENUM | DONT_DELETE`
flags, only the bodies replaced — because `global_instance_decls` enumerates
this family. Ruffle's `timeout` accessor pair and its `onConnect`/`onClose`/
`onXML` no-op defaults were NOT added: no corpus test observes them, and
tranche 1's lesson cuts both ways (unobserved surface is surface that can only
move someone else's lines).

**What CI caught that the local sweep did not — and it is the tranche-1
lesson for the third time.** The graphics/full run (`30412279387`) landed all
14 targets (`avm1` 658→663, `avm2` 936→945, effective 3901→3914) with **no
pass→fail regression**, but moved four tests `pass → ruffle_matched`:
`from_gnash/actionscript.all/XMLSocket-v{5,6,7,8}`. Effective count unchanged
— and that is exactly why it is easy to miss.

Those four assert `socketObj.connect(host, port) == false` for an unreachable
host. **Flash returns false when no connection is established**; Ruffle
returns true unconditionally, with a comment saying it cannot know
synchronously because connecting is asynchronous — which is why all four are
`known_failure = true` upstream and ship an `output.ruffle.txt`. Our old stub
returned false and therefore scored a full `pass`, i.e. **better than Ruffle**.
Copying Ruffle's `Ok(true.into())` verbatim silently traded that away.

Our transport is a script, so we *do* know synchronously: with no
`socket.json` nothing is ever opened. `connect()` now returns
`s->handle != 0`, which is Flash's rule, restores all four to `pass`, and is
invisible to the five bucket-S AVM1 tests (none reads the return value).

Generalize, third instance: **the oracle is Ruffle's *behaviour*, not Ruffle's
*code* — and a `known_failure` upstream marks a place where the two differ.**
Tranche 1 lost `air_hidden_lookup` by adding a class Ruffle gates; tranche 2
nearly lost four gnash tests by adopting a return value Ruffle itself
documents as wrong. Before porting a Ruffle body verbatim, check whether any
corpus test that exercises it is `known_failure` — that flag is upstream
saying "we know this is not Flash".

Also worth recording: `visual/simple_shapes/heavy_tesselation` went
`pass → recomp_fail` in the same run. It is a **recompiler timeout** at the
30s harness limit (it fails locally on an untouched recompiler and flipped the
*other* way during tranche 1) — a load-dependent flake, not a regression.

**Re-prediction of tranches 3–8 after tranche 2.**

- **Tranche 3 (file dialogs, 14 candidates)** — was +10, now **+11**. The mock
  scaffolding pattern is now proven end-to-end and reusable verbatim (script
  file → env var → per-tick delivery), and `filereference_load`'s
  `OPEN`/`PROGRESS`/`COMPLETE` ordering is the URLLoader drain the Loader arc
  already ships. The AVM1 half now also has a home for its state (the side-table
  idiom this tranche used for `XMLSocket`). Still the largest remaining block.
  Watch item: `filereference_uninitialized` needs the class **sealed** (#1069 on
  `extension`), the negative assertion §6's tranche-1 lesson warned about.
- **Tranche 4 (`URLStream`, 2)** — was +2, now **+2 and cheaper**: `URLStream`
  is `URLLoader`'s pipeline with an `IDataInput` face, and
  `avm2_bytearray_install_data_io` + the alt resolver now make that face a
  two-line addition rather than a port.
- **Tranche 5 (AVM2 AMF gaps, 1)** — unchanged at **+1**.
- **Tranche 6 (`LocalConnection`, 4)** — unchanged at **+3**.
- **Tranche 7 (AVM1 AMF0 serializer, 9)** — unchanged at **+4**; still the one
  genuinely large subsystem in the arc.
- **Tranche 8 (AVM2 `NetConnection.call`, 3)** — unchanged at **+2**.

Arc total if 3–8 land: **+23** on top of tranche 1+2's +24.

### Tranche 3 — SHIPPED `72fdc5e93`, CI `30418985155` (graphics) / `30418993536` (no-graphics), both `full`

**+15 vs +11 predicted, zero regressions.** Both modes land on identical
per-suite numbers: corpus effective **3914 → 3929 / 4420**, `avm2`
**945 → 955 / 1221**, `avm1` **663 → 668**. `REGRESSIONS (effective -> fail):
0`; the only `OTHER STATUS MOVES` rows are the four
`from_gnash/actionscript.all/XMLSocket-v{5,6,7,8}` going
`ruffle_matched → pass`, which is tranche 2's `connect()` fix showing up
against a baseline whose merged results predate it — a gain, and not this
tranche's.

All 14 bucket-D targets passed, plus **`avm2/filefilter_properties`**, which
the §4 census missed: it was 0/4 purely for want of a `FileFilter` class, and
its expected output ends in `TypeError #2023: Class Test$ must inherit from
Sprite` because its `package { public class Test {} }` does not extend Sprite.
That is the whole +4 over prediction — three of it from `save_and_load`,
`save_and_browse` and `load` all landing (they were flagged as the
ordering-risk trio), one from the census miss.

**No harness work at all.** Unlike `input.json` and `socket.json`, the dialog
mock is keyed off test CONTENT — a filter described `debug-select-success`, or
a save hint of exactly `debug-success.txt` — so `verify_output.py`, `test.toml`
handling and the compile defines are untouched. `dialog_events.h` +
~60 lines in `src/utils.c` is the entire mock: a FIFO of
`(callback, opaque target, success)` that both VMs share, with the caller
applying the mock's rules and the queue owning only the timing.

**Timing was the loader drain, exactly as re-predicted.** A dialog opened
during a frame resolves in the SAME tick, right after that frame's scripts,
and one opened from a resolution callback resolves in the same drain —
`filereference_save_and_browse` chains save → COMPLETE → browse → SELECT →
load under `num_ticks = 1`. AVM2 rides `avm2_loader_drain`'s existing
round loop (`swf_dialog_pending()` joins the break condition,
`swf_dialog_pump()` runs per round); AVM1 pumps at the `swf_socket_tick(1)`
call site in both frame loops.

**Tranche 2's frame-loop lesson applied up front, and it cost nothing.**
`swf_dialog_pending()` went into all five AVM1 early-exit gates
(`grep -n hasActiveNetStreams` still finds them) in the same commit as the
pump, rather than after a debugging round. Worth noting *why* it was needed
even though dialogs are same-tick: `funcs[current_frame]` runs at
`swf_core.c:1097` and the socket/dialog tick is at `:1256`, but the
`quit_swf` gate sits between them at `:1174` — a one-frame movie sets
`quit_swf` in its own frame script and would exit before ever reaching the
pump.

**Flash-strict, and it beat the scoped ceiling.** `filereference_save_and_load`
is `known_failure = true` **and** `ignore = true` upstream: Ruffle's mock
pre-fills the save destination with the same `Hello, World!`, so its
`load()`-after-save succeeds, fires COMPLETE, and re-enters the handler that
called it — a stack overflow. `output.txt` is Flash's behaviour and Flash's
behaviour is implementable in two rules: a save-derived selection reports
`size` **0** until its COMPLETE fires (it is not on disk yet), and `load()`
on one throws **#2037**. Implemented, the test is a full `pass` rather than
the `ruffle_matched` §5 budgeted. **Fourth instance of "the oracle is
Ruffle's *behaviour*, not Ruffle's *code*" — and the first where the
`known_failure` flag pointed at a place we could do BETTER than Ruffle rather
than merely avoid copying its bug.** Safe because the other save tests comment
their `size` dumps out (a `/* FIXME */` block in each), which was verified
before writing the rule, not after.

**The sealed-class watch item landed as written.** `filereference_uninitialized`
wants `ReferenceError #1069: Property extension not found on
flash.net.FileReference` — `extension` is `[API("661")]` AIR-only in Ruffle's
`FileReference.as`. One line (`cls->flags |= AVM2_CLASS_FLAG_SEALED`) turns
the existing miss path (`avm2_ops.c::getproperty_common`) from "yield
undefined" into that error, with the qualified name already correct. The
negative assertion is graded twice — `filereference_browse_select` repeats it
on a *selected* file — so registering `extension` "for completeness" would
have cost two tests, not one.

**AVM1: shape frozen, bodies replaced.** `global_proto_decls`,
`global_proto_decls_delete` and `global_instance_decls` all enumerate this
family, so `FileReference.prototype` keeps its ten names in their exact
insertion order with `DONT_ENUM | DONT_DELETE`, and `FileReferenceList.prototype`
its five. `installAsBroadcaster` is deliberately NOT reused — it makes
`_listeners` deletable (`PROPERTY_FLAG_CONFIGURABLE`), and
`global_proto_decls_delete` asserts `DONT_DELETE`. The only value changes are
the four stub bodies becoming real and `_listeners` becoming a zero-length
`Array` instead of a plain `ASObject`, which is what
`file_reference_list_asbroadcaster` reads `.length` off (`typeof` is `object`
either way, so the enumeration dumps do not move).

The AVM1 filter validator is where the AVM1 half's complexity actually lives
(`file_reference_list_browse_invalid_filters`, 18 graded cases): fields must
be OWN properties, an `addProperty` getter counts as own, a getter that
THROWS is swallowed and the field reads as missing, but an exception from
`toString()` during the string coercion that follows PROPAGATES to the
script. The swallow needs a C-level `setjmp` frame on
`g_exception_state` (the `call_on_construct_handler` idiom at
`action.c:35439`); the propagate needs only *not* installing one.

**Blast radius, measured.** Stash-diff of the actual `--diff` output against a
pre-change build over eight canaries — `global_proto_decls` (7,462 lines),
`global_proto_decls_delete`, `global_instance_decls`, `native_objects_swf6`,
`globals_swf5`, `mixed_avm/avm1_loads_avm2`, `all_classes/events/swf10`,
`verify_method_info_oob` — is **byte-identical on all eight**. Unlike tranches
1 and 2 there is no `describeType` dip to read as a fix: `all_classes` has no
`net` subdirectory, so three new `flash.net` classes shift nothing. The two
other corpus files that mention `FileReference`
(`bitmapdata_colortransform`, `large_preload_image_from_bytes`) have it inside
`/* */` blocks.

**Census gap found: the seven AVM1 `file_reference_{download,upload}_*` tests
are in no bucket at all.** §4 scoped bucket D from the *dialog* mock's
surface and missed the family members that reach it through `download()` /
`upload()`. They are now one mechanism away each — `download(url, name)` is
the save dialog plus a URL fetch plus the four-event `onSelect`/`onOpen`/
`onProgress`/`onComplete` sequence; `upload()` is that sequence over a
selection `browse()` already produces. `file_reference_download_success`
already improved on this tranche's browse() work alone (its first three
graded lines are filter-rejection cases). Generalize: **a census organised by
MECHANISM will miss tests that reach that mechanism through a different entry
point — sweep the test-name prefix as well as the mechanism.**

**Re-prediction of tranches 4–8 after tranche 3.**

- **NEW — tranche 3b (AVM1 `FileReference.download`/`upload`, 7 candidates)**
  — predict **+5** (**actual +7 — all seven**). The dialog mock, the AsBroadcaster delivery and the
  property-init path all exist; what is missing is the save dialog's AVM1
  entry point, the URL fetch (the AVM1 side of the Loader arc's resolver) and
  an `httperror` branch that four of the seven grade. Cheaper than tranche 6
  or 7 and larger than tranches 4 or 5, so it slots in right after tranche 4.
- **Tranche 4 (`URLStream`, 2)** — **+2 and still cheap**; unchanged by this
  tranche, which touched neither the fetch pipeline nor `IDataInput`. It stays
  separate from tranche 3 rather than folding in: this run was already
  dispatched when the fold was considered, and the two share no code.
- **Tranche 5 (AVM2 AMF gaps, 1)** — unchanged at **+1**.
- **Tranche 6 (`LocalConnection`, 4)** — unchanged at **+3**.
- **Tranche 7 (AVM1 AMF0 serializer, 9)** — unchanged at **+4**.
- **Tranche 8 (AVM2 `NetConnection.call`, 3)** — unchanged at **+2**.

Arc total if 3b + 4–8 land: **+17** on top of tranche 1+2+3's **+39**.

### Tranche 4 — SHIPPED `8c3b7673f`, CI `30477186369` (graphics, full)

**+3 vs +2 predicted, zero regressions.** Corpus effective
**3929 → 3932 / 4420**; `avm2` **955 → 956 / 1221**, `from_shumway`
**180 → 182**. `REGRESSIONS: 0`, `OTHER STATUS MOVES: 0`, and the status
histogram moves only `output_mismatch 483 → 480` / `pass 3689 → 3692` — no new
`segfault` / `timeout` / `runtime_error` / `compile_fail` bucket.

Both bucket-U targets landed, plus one the census missed.

| Test | before | after |
|---|---|---|
| `avm2/urlstream_basic` | 0/5 | **pass** |
| `from_shumway/flash_net_URLLoader` | 0/7 | **pass** |
| `from_shumway/stream1` | 0/9 | **pass** (census miss) |

**`from_shumway/stream1` is the +1, and it is tranche 3's census lesson
repeating in a new key.** It is a `URLStream` test — it loads
`stream1.swf.bin` and grades `readByte`/`readUnsignedShort`/`readBytes` over
the result — but §0's name sweep looks for `urlstream` in the *test name* and
its name is `stream1`, while the content sweep greps `*.as` sources and this
test ships only a `test.fla`. **A sweep over test names plus `.as` sources is
blind to any suite whose tests carry no source file**; from_shumway has 14
such directories. Grepping the compiled `test.swf` for class names would have
found it.

**The IDataInput face cost two lines, exactly as re-predicted.** Tranche 2
generalised the ByteArray bodies over an alt resolver so `Socket` could put a
buffer PAIR behind them; `URLStream` registers a second resolver over its
single sink and inherits all 14 read bodies unchanged. The one structural
change is that `avm2_bytearray.c`'s hook became a short **chain** rather than
one slot — each resolver claims only its own class and returns NULL otherwise,
so registration order is immaterial. `install_data_io` also split into
input/output halves: `URLStream` has no write side, and Ruffle's `URLStream.as`
implements `IDataInput` only.

`URLStream` itself is Ruffle's wrapper written in C: `URLStream.as` is a thin
AS3 shell around a *private* `URLLoader` in binary mode, re-dispatching
open/progress/httpStatus/complete/ioError and forwarding every read to
`_loader.data`. So it lives beside `URLLoader` in `avm2_display.c` and shares
the fetch pipeline outright — `ul_start_load` grew an `is_stream` flag and the
delivery half forks on it. Nothing streams in either player (the bytes land all
at once when the fetch resolves), which is what `urlstream_basic` grades:
`bytesAvailable` is 0 in the `open` handler and the full length from `progress`
on.

**The `from_shumway` rider needed no `URLStream` at all — it was a harness
gap.** `flash_net_URLLoader` subclasses `URLLoader` and fetches its OWN SOURCE
(`test.as`, 2674 bytes), grading the body and the
`OPEN`/`PROGRESS`/`HTTP_STATUS`/`COMPLETE` order, which we already emitted in
that order. It failed because `verify_output.py::find_data_files` excluded
`test.as` from the bundled sibling assets, so the fetch 404'd into #2032.
Ruffle's test navigator serves *every* sibling file, and `Test.as` (capital T,
the avm1/avm2 spelling) was already bundled everywhere — excluding the
lowercase spelling was an accident of the original loadVariables
implementation, not a decision. Un-skipping it bundles a source file into 290
tests; the only behavioural gate that flips is `-DHAS_DATA_FILES`, whose arms
return early on a `findDataFile` miss exactly as the stub does, and no corpus
file names `"test.as"` anywhere (one comment in
`visual/filters/avm1_convolution_initialization` aside).

One hardening that change earned: `getDataFilesMaxImageDims` now probes only
files with an image suffix. It sizes a GPU texture array from
`stbi_info_from_memory`, and stb's TGA/PNM sniffers are loose enough that 290
new text files were worth not feeding them.

Also GC-rooted the pending `URLLoader`/`URLStream` queue, which the Loader
queue beside it already was: between `load()` and the drain that queue can be
the only reference to the target, and `urlstream_basic` drops its stream into
listener closures the stream itself owns — a cycle nothing else reaches.

**Blast radius, measured.** Stash-diff of the actual `--diff` output against a
pre-change build over 12 canaries — `avm2/socket_read_big`,
`avm2/socket_errors` (the resolver chain), `avm2/url_loader`,
`avm2/loader_events` (the pipeline refactor),
`avm2/bytearray_readobject_amf3` (the `data_io` split),
`avm1/netstream_play_flv` (bundled images + the dims scan),
`avm1/mcl_loadclip_properties`, `avm1/native_objects_swf6`, `avm1/xml_socket`,
`avm1/loadvariables`, `visual/filters/avm1_convolution_initialization` (all
newly `HAS_DATA_FILES`) and `from_shumway/flash_net_URLRequest` — is
**byte-identical on all twelve**. Unlike tranches 1 and 2 there is no
`describeType` dip to read as a fix: `avm2/all_classes` has no `net`
subdirectory.

**Re-prediction of tranches 5–8 after tranche 4.** Nothing here touches AMF,
`LocalConnection` or the AVM1 serializer, so tranche 5 stays **+1**, 6 stays
**+3**, 7 stays **+4** and 8 stays **+2**. One note for whoever writes the next
census: re-run the sweep against compiled `test.swf` class names before sizing
a tranche in `from_shumway` or `from_gnash`.

### Tranche 3b — SHIPPED `6cf854900`, CI `30480184835` (graphics, full)

**+7 vs +5 predicted, zero regressions — all seven candidates, no misses.**
Corpus effective **3932 → 3939 / 4420**; `avm1` **668 → 675**. `REGRESSIONS: 0`,
`OTHER STATUS MOVES: 0`, histogram moves only `output_mismatch 480 → 473` /
`pass 3692 → 3699`.

| Test | before | after |
|---|---|---|
| `file_reference_download_cancel` | 1/7 | **pass** |
| `file_reference_download_success` | 6/34 | **pass** |
| `file_reference_download_httperror_dns_error` | 1/13 | **pass** |
| `file_reference_download_httperror_status_code` | 1/23 | **pass** |
| `file_reference_upload_success` | 8/23 | **pass** |
| `file_reference_upload_httperror_dns_error` | 8/18 | **pass** |
| `file_reference_upload_httperror_status_code` | 8/23 | **pass** |

**The +2 over prediction is the `httperror` branch being cheaper than scoped.**
§6's tranche-3 re-prediction budgeted the four `httperror` tests as the risky
half ("an `httperror` branch that four of the seven grade"). It is not a branch
that needs a real transport at all: Ruffle's test navigator answers three magic
**query strings** — `?debug-success` returns `Hello, World!`,
`?debug-error-statuscode` an `HttpNotOk` with a zero-length body,
`?debug-error-dns` an `InvalidDomain` — and every one of the seven URLs carries
one. `strstr` on the URL is the entire transport. **Generalize: when a Ruffle
test's URL contains a `?debug-` marker, the navigator never reaches the disk,
so the "fetch" is a three-way switch, not a fetch.**

**Zero harness work again, for the third mock in a row.** Like the file dialog
(tranche 3) and unlike `input.json` / `socket.json`, everything here is keyed
off test CONTENT. `verify_output.py`, `test.toml` handling and the compile
defines are untouched; the whole tranche is `action.c`.

**Timing needed nothing new.** In Ruffle `download_file_dialog` is ONE future:
it awaits the save dialog, then the fetch, then fires every callback in a
single `update`. So the whole sequence runs inside one resolution callback on
tranche 3's dialog queue, and the AVM1 pump's existing "keep going until the
queue is empty" loop covers the rest. `upload()` opens **no dialog at all** —
it rides the same queue purely to be async, which is exactly what puts its
events after the `onSelect` handler that called it (all three upload tests call
`upload()` from inside `onSelect`).

**Three orderings are load-bearing, and each is graded by exactly one test.**

- **download / `InvalidDomain` fires NO `onOpen`** — the connection never
  opened. `HttpNotOk` fires `onOpen`, the `Error opening URL '…'` trace,
  `onIOError`, and **then** `onProgress`: Flash still runs `onProgress` after
  an error, but only once the connection was established, and the reported
  length is the *error body's* (0 from the test navigator), not the file's.
- **upload fires `onOpen` unconditionally**, before it looks at the result;
  `HttpNotOk` then reports `onProgress(13, 13)` and `onHTTPError`,
  `InvalidDomain` only `onIOError`. Note the asymmetry with download: upload's
  error path uses `onHTTPError` where download's uses `onIOError`.
- **download's `onSelect` reports the SAVE HINT as `name`**, not the mock's
  `test.txt` — Ruffle's save dialog builds its `TestFileSelection` from the
  requested file name. That is why `file_reference_download_success` expects
  `N:debug-success.txt` while every browse-derived test expects `N:test.txt`,
  and it is the one place the two dialog kinds' simulated selections differ.

**The two `false` cases are `Url::parse` failures.** `download("@")` and
`download("baddomain")` have no scheme. Implemented as a scheme scan rather
than a URL parser, which is all the corpus needs. With no explicit file name
the save hint is the URL path's last segment — and `Url` normalizes an empty
path to `/` for the special schemes, so `download("http://example.com")`
derives the **empty** name, the save dialog cancels, and the call still returns
**true** because a dialog *was* displayed. That is `file_reference_download_cancel`
in full. `upload()` additionally requires a prior selection and an http(s)
scheme.

**State that Flash does not expose stays out of the property set.** Ruffle's
`FileReferenceData` carries `is_initialised` and the selected bytes; both
matter to `upload()` (uploading before a browse answers false; `onProgress`
reports the stored data's length) and neither is script-visible. They live in a
pointer-keyed side table — the `NetConnection`/`XMLSocket` idiom — rather than
as hidden own properties, because `global_instance_decls` enumerates this
family. The prototype shape is otherwise untouched: `upload` and `download`
were already present as stubs, and `addStubMethodToProto` →
`addNativeMethodToProto` is the same property, same order, same
`DONT_ENUM | DONT_DELETE` flags, with only `advanced_func` different.

**Blast radius, measured.** Stash-diff of the actual `--diff` output against a
pre-change build over 11 canaries — `global_proto_decls` (7,462 lines),
`global_proto_decls_delete`, `global_instance_decls`, `native_objects_swf6`,
`file_reference_browse_cancel`, `file_reference_list_browse_select`,
`file_reference_list_browse_invalid_filters`,
`file_reference_list_asbroadcaster`, `avm2/filereference_load`,
`avm2/filereference_save_and_browse`, `avm1/xml_socket` — is
**byte-identical on all eleven**.

**Re-prediction of tranches 5–8 after tranche 3b.** Unchanged: **+1 / +3 / +4 /
+2**. Nothing here touched AMF, `LocalConnection` or the AVM1 serializer. One
input to tranche 7, though: the AVM1 `FileReference` side table is now the
precedent for where AVM1 native state lives when Flash does not expose it, and
tranche 7's `SharedObject` `.sol` persistence will want the same shape.

### Tranche 7 — SHIPPED `702d38a35` + `698bdddfa`, CI `30494443127` (graphics, full) then `30496277452`

**11 of 11, against a predicted +7. Zero regressions.** Every row of §7.6's
dependency matrix landed, including the three the prediction treated as upside
(the two `super()`-upgrade tests and `netconnection_send_remote`) and the one it
called a stretch (`amf0_serde_suite`). All three `known_failure` targets are FULL
passes, not `ruffle_matched`.

Against baseline `056c9d3ce`, corpus effective **3939 → 3950 / 4420 (+11)`**;
`avm1` **675 → 686**. No other suite moved. Status histogram:
`output_mismatch 473 → 462` / `pass 3699 → 3710`, with `ruffle_matched` (240),
`runtime_error` (7) and `recomp_fail` (1) all flat and no `segfault`, `timeout`
or `compile_fail` bucket on either side. `REGRESSIONS: 0`,
`OTHER STATUS MOVES: 0`, and **zero** `matching_lines` drift among the tests
that fail on both sides — the +11 is exactly the eleven targets and nothing
else.

Run `30494443127` is nonetheless RED, and the reason is worth recording: its
`wasm-link-smoke` job failed with eight undefined symbols out of `action.o` and
`swf_core.o`. `build_test.sh` and `build_wasm_avm2.sh` keep their own explicit
source lists — they do NOT link `libswfruntime.a` the way `build_wasm_test.sh`
and `deploy_wasm_demo.sh` do — so adding a runtime file means editing FOUR
places, not two: `CMakeLists.txt`, `verify_output.py`, and those two scripts.
Fixed in `698bdddfa`, and run `30496277452` (a `single_test` dispatch, which
does not publish) is green on both `WASM link-smoke` and the test itself, so
`amf0_serde_suite` is confirmed passing in CI graphics mode as well as locally.
The 30 corpus shards were never affected — they build natively.

| Test | before | after | §7.6 confidence |
|---|---|---|---|
| `localconnection_top_level` | 4/7 | **pass** | high |
| `amf_array_serialization` | 3/10 | **pass** | high (beats known_failure) |
| `netconnection_serialize_arrays` | 1/6 | **pass** | high (beats known_failure) |
| `amf_serialize_typed_objects` | 1/6 | **pass** | high |
| `amf_swf6_serialize_typed_objects` | 1/6 | **pass** | high |
| `amf_swf6_case_insensitive_typed_objects` | 1/6 | **pass** | high |
| `amf_swf8_case_sensitive_typed_objects` | 1/6 | **pass** | high |
| `amf_sharedobject_strict_array_serialization` | 2/3 | **pass** | medium (7.5) |
| `amf_strict_array_serialization` | 1/7 | **pass** | medium (7.5) |
| `netconnection_send_remote` | 2/50 | **pass** | medium |
| `amf0_serde_suite` | 16/144 | **pass** | **stretch** |

#### Which §7 claims held

Every byte-level rule in §7.2 held exactly as recorded, first try: the uniform
array rule with `0x06` hole padding, native-Array-ness as the sole shape input
(a demoted real array stays `0x0A`, an Object wearing `Array.prototype` stays
`0x03`), `length` excluded from the key set that decides the shape, ECMAArray's
u32 being the `length` property with entries in insertion order, getters never
invoked, functions omitted as property values but serialized as plain objects at
top level, display objects undefined at every level, the typed-object resolution
order and its "inherited `constructor` does not count / `ASSetPropFlags` is
irrelevant" corollaries, the SWF-version registry split at 7, and the
latest-casing rule for SWF≤6. §7.3's packet layout, response-URI-per-flush,
`mustUnderstand` default and zero-argument failure `onStatus` all held too.
§7.1's three retirements held: no `.sol` I/O, no `.sol` reader, and the AVM2
`rd0_*` reader really was the right shape to port.

**§7.1's "zero harness work, 5th tranche running" did NOT hold** — the one
question it flagged as open (does `find_data_files` recurse?) answers *no*, and
neither does `download_tests.sh`. Both now carry nested data files keyed by the
path relative to the test directory, because Ruffle's navigator maps
`http://<host>/<path>` to `<test_dir>/<host>/<path>`
(`tests/framework/src/backends/navigator.rs`) and
`netconnection_send_remote`'s scripted responses live in `localhost/test{1,2,3}`.
The exclusion filter (asasm/abc build layout, nested image/video sources) was
checked against the whole upstream corpus: it admits exactly the two
`netconnection_send_remote/localhost/` sets. `large_bytearray`'s five 100 KB
`.bin` files sit behind their own `test.swf` and stay excluded by the
separate-test rule that was already there for Loader children.

**§7.5 was wrong in the useful direction: the "one hard mechanism" was already
90% built.** It scoped the `super()` array upgrade as needing a `native_type`
flag plus an attached ASArray side table with index/length routing through the
property paths. In fact `invokeNativeSuperConstructor`'s Array arm has set
`native_type = NATIVE_ARRAY` on the receiver `ASObject` — storing indices as
ordinary string-keyed properties beside a `length` — since long before this arc.
The gap was only `length` bookkeeping on index writes: extend when a write lands
at or past the end, truncate when `length` shrinks. About fifty lines in
`actionSetMember`'s object arm, plus an array-like view over a `NATIVE_ARRAY`
`ASObject` in the writer. **Lesson: before designing a side table for a
"structurally impossible" conversion, grep for whether a partial form of it
already exists.** Both tests then passed with no further work — and
`amf_sharedobject_strict_array_serialization` turned out to grade only three
trace lines (the litmus, a banner, and the flush), so the `.sol` in its
directory never mattered at all.

#### The stretch target, and what actually made it pass

`amf0_serde_suite` came down to `Array.length`, twice.

**First: Flash's array-index scanner is INTEGER-ONLY** — an optional `-`, then
digits, whole string consumed. `arr[2.5]` and `arr[9223372036854775807]` (which
AVM1 stringifies to `"9.2233720368548e+18"`) are plain string properties that do
**not** touch `length`; integral spellings, including negative ones and digit
runs far past 2^64, do. Our extended-index arm fell back to `strtod` and so
accepted both, which is why `arr_negative` serialized with an ECMAArray length of
3 where Flash says 1, and why `arr_sparse` reported 49153 — `ToUint32` of the
*decimal* `9.2233720368548e+18` is 49152, not the 0 the exact `2^63` would give.
`array_length` pins the accepting side of this rule and is unchanged; nothing in
it uses a non-integral key.

**Second: a signed length increase can be an unsigned decrease, and Flash
truncates on it.** `a[4294967295]` takes `length` from 2147483649 to 0 by u32
wrap. The elements past the new end are really gone, not merely out of range:
`arr_sparse[0]` reads back **undefined** even though the following
`a[4294967296]` puts `length` back to 1. That single truncation is what makes
Flash's `arr_sparse` serialize with no `"0"`/`"4"` pairs at all — and those two
pairs are exactly 28 bytes, which is exactly the gap between our `getSize()` of
1607 and the expected 1579. One fix, three graded lines.

The remaining serde-suite delta was the reference table, and the answer is that
**the AVM1 reader does not rebuild the reference graph at all.** It never
populates the table, so every `0x07` reads as undefined and a DAG that survived
the writer arrives broken. The test grades that directly:
`ref_strict_is_exact` is **false** on the LocalConnection channel, which
round-trips, against **true** on the SharedObject channel, which reads the live
cached instance and never serializes. §7.2 predicted this ("fresh EMPTY cache per
LC-delivered argument"); the implementation is simply a `rd_ref_claim` that
returns -1.

#### Three bugs outside the new files, each surfaced by a target

- **`addProperty` must create an ORDINARY enumerable property.** `setProperty`
  force-clears `ENUMERABLE` for the names `constructor` and `__proto__` — they
  are DontEnum wherever the runtime itself installs them — but Flash's
  `addProperty` does not, so a virtual `constructor` appears in for-in and in the
  stream. `amf_serialize_typed_objects` cases 11 and 17 were the entire diff
  after everything else matched: two missing `constructor` → `0x06` pairs.
- **A `SUPER` thisArg binds the instance it proxies.** `super` is a view onto
  `this`, not an object of its own. `super.call.apply(super, arguments)` — the
  whole body of `netconnection_send_remote`'s `CustomNetConnection` — fell
  through `Function.apply`'s primitive arm to `_global`, so the builtin ran with
  the wrong receiver, found no `uri`, and the test stalled after its second trace
  line with no error of any kind. Three thisArg extraction sites in `action.c`
  needed the arm; a `SUPER` value's `numeric_value` is already the receiver's
  `ASObject*`.
- **`setArrayElement`'s growth overflowed u32.** `(index + 1) * 2` wraps to 0 for
  any index at or past `0x7FFFFFFF`, and a wrapped capacity of 0 made `realloc`
  *shrink* the block while the write below still used the huge index — an
  out-of-bounds write reachable from ordinary script assignment, not just from
  the new reader. Computed in 64 bits with a cap now. The reader independently
  caps at the same 1 MiB `actionSetMember` uses and stores bigger keys as named
  properties, because an ECMAArray in this stream legitimately carries
  `"4294967295"`.

#### Shape of the code

`amf_packet.c` is deliberately VM-agnostic — it frames and parses packets over
byte ranges the caller has already serialized, and mentions no VM type — so
tranche 8 (AVM2 `NetConnection.call`) reuses it as-is. `avm1_amf.c` holds the
codec, `SharedObject`, and the per-connection call queue. The queue drains once
per tick into ONE packet, at a new call site immediately before
`processLocalConnectionMessages` in both frame loops: after frame scripts **and**
after timers, so a call issued from either lands in the same tick's packet, and
before LC delivery because that is the interleaving Flash's own
`amf_array_serialization` output shows. Tranche 2's five-site `quit_swf`
exit-gate list was re-checked and needs **no** entry — unlike a socket, the drain
is synchronous and always empties the queue, so nothing is ever left pending
across a tick boundary.

#### Re-prediction of tranches 5, 6, 8 after tranche 7

- **Tranche 5 — AVM2 AMF gaps · was +1 · now +1, and cheaper.** Unchanged in
  scope, but the Flash-vs-flash-lso rules are now pinned by a passing AVM1
  implementation, so if any of bucket X turns out to want the uniform array rule
  or nested typed objects, the semantics are settled and only `avm2_amf.c`'s `w0`
  writer needs the port. Note `avm2_amf.c`'s `w0_value` still emits ECMAArray for
  every array and never `0x0A`/`0x0F`/`0x10` — that is now known to be Ruffle's
  behaviour, not Flash's.
- **Tranche 6 — `LocalConnection` registry · was +3 · now +3, and SMALL rather
  than LARGE.** Its cost estimate assumed argument marshalling was still ahead of
  it. LC is now a real wire channel (serialize at `send`, deserialize at
  delivery, with Flash's type translations), and `localconnection_top_level` —
  which §7.0 moved out of bucket L on the grounds that its three failing lines
  were pure serialization — is already passing. What is left in bucket L is the
  registry semantics proper.
- **Tranche 8 — AVM2 `NetConnection.call` wire · was +2 · now +2, and MEDIUM
  drops toward SMALL.** The packet framing exists and is VM-agnostic; the
  response-dispatch shape (`/N/onResult`, `/N/onStatus`, 1-based per flush,
  silent drop on a malformed packet, zero-argument `onStatus` on a failed fetch)
  is implemented and graded; `avm2/netconnection_send_remote`'s
  `localhost/test{1,2,3}` are already bundled by this tranche's harness change.
  What remains is AVM2-side: `nc_call`'s stub, and whatever the AVM2 executor
  wants for response timing (see `avm2-loader-timing-is-executor-drain`).

### Tranche 5 — SHIPPED `6a07045c4`, CI `30499537278` (graphics, full)

**+1 vs +1 predicted, zero regressions.** Corpus effective **3951 → 3952 / 4421**;
`from_avmplus` **1509 → 1510**. `REGRESSIONS: 0`, `OTHER STATUS MOVES: 0`, and the
histogram moves only `output_mismatch 462 → 461` / `pass 3710 → 3711`.
`from_avmplus/as3/AMF/AMFSerializer` finishes **225/225**, closing the avmplus AMF
acceptance suite.

Both hooks were about as small as scoped — the AMF3 externalizable trait bit and a
static accessor pair — but **the blocker was a third thing neither §7 nor the
tranche note predicted, and it was not in `avm2_amf.c` at all.**

**A builtin class that "implements" an AS3 interface needs its methods keyed
TWICE.** `writeExternal(output:IDataOutput)` calls `output.writeObject(...)`, and
ASC compiles a call on an interface-typed reference to the **interface
namespace alone** — `flash.utils:IDataOutput::writeObject`, never public. ABC
classes get those keys from `avm2_class.c`'s interface-alias pass
(`add_iface_aliases_from`); builtin classes never run it, so ByteArray's 26
IDataInput/IDataOutput methods were unreachable through an IDataOutput-typed
parameter and the call raised `#1069`. Both halves are now installed under the
public key and the interface key, which Socket and URLStream inherit for free.
The same rule is why the `IDynamicPropertyOutput` handed to
`writeDynamicProperties` carries an explicit `flash.net:IDynamicPropertyOutput::
writeDynamicProperty` entry. **Generalize: the corpus only notices a missing
interface alias when a test passes an instance through an interface-TYPED
parameter, which no amount of grepping for the method name will reveal.**
(`avm2_ns_fold` folds namespace kind 0x08 and 0x16 together, so one 0x16-keyed
entry answers ASC's 0x08 multiname.)

Two smaller findings worth keeping:

- **An externalizable class-def joins the trait table, so the table entry needs an
  `externalizable` field.** Without it a plain object with the same alias, zero
  statics and `dynamic = false` matches the externalizable entry and emits a trait
  *reference* that the reader then interprets as an opaque body.
- **The reader cannot know an opaque body's length, so the ByteArray it hands
  `readExternal` is the answer.** It gets the whole remaining stream and its final
  `position` is how many bytes the body consumed. That also fixes the framing
  question in the other direction: Adobe's serializer shares the enclosing
  stream's string/object reference tables with the body, we give it a fresh
  ByteArray, and the two choices are indistinguishable for any body that does not
  reference the outer graph — which is every body in the corpus.

`ObjectEncoding.dynamicPropertyWriter` REPLACES the dynamic half of an object
body rather than filtering it: the hook decides which expandos reach the stream
and under what names, so the writer applies none of its own filtering on that
path (not even the function-valued skip). The active writer is a saved/restored
file static, so a nested dynamic object re-entering the hook cannot retarget an
outer serializer.

### Tranche 8 — SHIPPED `01f30d3f5` + `8a302905d`, CI `30501480658` (graphics, full)

**+2 vs +2 predicted, and one regression — found by CI, not by the local
canaries.** Corpus effective **3952 → 3953 / 4421**; `avm2` **956 → 958 (+2)`,
`from_shumway` **182 → 181 (-1)**. The third target,
`avm2/amf_array_serialization`, went 6/17 → 16/17 with **both** remoting packets
byte-exact and landed as a pass in tranche 6, which supplied its LocalConnection
leg.

| Test | before | after |
|---|---|---|
| `avm2/netconnection_send_remote` | 0/50 | **pass** (also un-ignored) |
| `avm2/netconnection_serialize_arrays` | 1/6 | **pass** (beats known_failure) |
| `avm2/amf_array_serialization` | 6/17 | 16/17 → pass in tranche 6 |

§6's re-prediction held: `amf_packet.c` was reused **unchanged**, and the whole
AVM2 side is the queue, the two stubs, and the AMF0 writer's Flash rules. The
response-dispatch shape, the per-flush `/N` numbering and the case-insensitive
header replacement all came across as-is.

**The regression is the arc's best canary lesson.** `from_shumway/encoding1`
(pass → output_mismatch) dumps `ByteArray.writeObject`'s AMF0 bytes for a dense
`["a", {}]`, and Flash writes that as an **ECMAArray** — so the StrictArray
promotion is CHANNEL-scoped, exactly as AVM1's is between the wire and an LSO
body: a NetConnection/LocalConnection packet promotes, local serialization does
not. Gated behind a `wire_mode` flag that only the NC/LC entry point sets
(`8a302905d`). The other three writer changes — typed objects `0x10`, XML `0x0F`,
the reference table — apply on every channel, as they do in AVM1.

Why 46 local canaries missed it: **the canary list was built from test NAMES**
(everything matching `amf|bytearray|socket|net`), and `encoding1` says nothing
about either. It ships no `.as` source, either — the same blindness tranche 4
recorded for `stream1`. **Generalize: a serializer change must pick canaries by
CONTENT — grep the expected outputs for hex dumps (`Body: [` / long `[0-9A-F,]`
runs) — because the tests that pin bytes are exactly the ones whose names do not
mention the codec.**

Two mechanisms outside the wire, each surfaced by a target:

- **`flash.system.fscommand` did not exist.** `netconnection_send_remote` calls
  `fscommand("exit")` and then `removeEventListener`, so the `#1065` killed the
  *unregistration*, and the movie kept tracing `# End of Test N` for every
  remaining tick. Ruffle's harness recognises only `quit` and `captureImage`;
  `"exit"` is an unknown command that does **nothing**. The test does not need
  the player to exit — it needs the call not to throw.
- **`addHeader`'s `mustUnderstand` defaults to FALSE in AVM2 and TRUE in AVM1.**
  Same method name, opposite default, and each VM's recorded bytes pin its own:
  AVM2's default is the AS3 signature's (`mustUnderstand:Boolean = false`).

And one general-runtime finding, from the one target that needed a plain object
serialized: **dynamic-property enumeration puts integer-spelled keys BEFORE string
keys.** Two recorded outputs pin the pair of rules — `{"0": "fake_0", "length": 1}`
serializes `"0"` first (Flash and Ruffle bytes agree), while the all-string
`{a: this.test, b: true}` traces as `{"b":true,"a":…}`, reverse of source, because
`newobject` sets a literal's pairs last-first. Tail-appending satisfies only the
second. **Generalize: when two graded outputs disagree about "insertion order",
look for a KEY-CLASS partition before concluding the insertion direction is
wrong** — both players key an integer-spelled property by its integer value
(Ruffle `DynamicKey::Uint`, avmplus an int atom) and enumerate that class first.

### Tranche 6 — SHIPPED `34171042f`, CI `30505002399` (graphics, full)

**+3 vs +3 predicted, zero regressions**, and the stretch target moves from
67/890 to **589/890**. Corpus effective **3953 → 3957 / 4421**; `avm2`
**958 → 960**, `from_shumway` **181 → 183**. The run's fourth gain is
`from_shumway/encoding1` coming back — tranche 8's regression, fixed in
`8a302905d` and verified here — so the tranche's own yield is +3.
`REGRESSIONS: 0`, `OTHER STATUS MOVES: 0`.

| Test | before | after |
|---|---|---|
| `avm2/localconnection_send` | 0/4 | **pass** |
| `from_shumway/localconnection` | 3/12 | **pass** |
| `avm2/amf_array_serialization` | 16/17 | **pass** (beats known_failure) |
| `avm2/localconnection` | 67/890 | 589/890 (stretch, as predicted) |

§6's re-prediction that this was SMALL rather than LARGE held: the wire was
already built, so the tranche is registry semantics plus two event gaps.

**The plan's instruction to check the stretch test's `#1009` first paid for
itself in one local run.** It was not a Loader-arc leftover: the AVM2 child does
`lc.client = {}` then `lc.client.test = …`, and the stub's `client` getter
returned **null**. The 890-line spec test was blocked by this tranche's own stub,
not by another arc — which is why implementing `client` alone took it from 67
matching lines to nearly 600.

**Ruffle's asymmetry is the load-bearing rule: the StatusEvent goes to the
SENDER, the AsyncErrorEvent to the RECEIVER.** `avm2/localconnection` grades it
in words ("receiver received event AsyncErrorEvent.ASYNC_ERROR"), and getting it
backwards would have failed both LC tests while looking plausible. The other
Ruffle rules transferred verbatim: the double "is anyone listening" check (at
send AND at delivery, so whatever holds the name at delivery is what receives),
`'_'`-prefixed names skipping the superdomain prefix, a `':'` rejected by
`connect` but honoured by `send`, and the six reserved method names.

**Sealing the class is what produces `#1069`, with no special-casing.** A send
naming a method the default client (the connection itself) lacks must raise
`ReferenceError #1069`, not "not a function". Marking the builtin class SEALED
routes it through the shared property path, which already had the behaviour —
the first attempt special-cased it inside the delivery function and was deleted.

Two event gaps neither the census nor §4 saw, both because nothing had ever
constructed these events from C:

- **`AsyncErrorEvent`'s 5th constructor argument is an Error OBJECT**, where its
  `ErrorEvent` base reads an `errorID` there. It had been sharing
  `error_event_init`, so `event.error` was unreachable.
- **`StatusEvent` had no `toString` override**, so tracing one printed `Event`'s
  four fields without `code`/`level` — and its String-typed `code`/`level` must
  keep a **null** rather than coerce it to the string `"null"`
  (`localconnection_send` grades `code=null`).

**What is left in `avm2/localconnection` is the AVM1↔AVM2 delivery bridge.** Our
AVM1 LocalConnection keeps its own channel map in `action.c`, so a cross-VM send
finds no listener and the test's "Calling an AVM1 movie" half — the argument-
translation battery against `avm1child` — still fails. Both halves of the bridge
now exist (each VM has an AMF0 codec and a compatible key format); what is
missing is one shared registry plus a delivery entry point per VM. That is the
arc's one scoped-but-unlanded item, and it is a standalone follow-up, not a
tranche.

## 7. Tranche 7 scoping (2026-07-29, pre-implementation)

Two very-thorough sweeps (our runtime; Ruffle @ `75c3cec57` — note: a fork
with local AMF commits of 2026-07-24; some `*.ruffle.txt`/`*.ruffle.sol`
snapshots predate them) plus local `--diff` runs of every candidate.

### 7.0 Census correction — bucket W is 11 tests, not 9

In (prefix sweep, the tranche-3b lesson):
- `avm1/netconnection_send_remote` (2/50) — the full `NetConnection.call`
  lifecycle: 4 sequential connects, `addHeader`, scripted AMF *response*
  packets (`localhost/test{1,2,3}` files), `Responder`-object callbacks,
  `onStatus()` with zero args on fetch failure, and a
  `CustomNetConnection extends NetConnection` subclass calling
  `super.call.apply(super, arguments)`.
- `avm1/localconnection_top_level` (4/7) — moved from bucket L: its 3
  failing lines are pure serialization (`TextField → undefined`,
  `Function → [object Object]` plain-object round-trip, function result
  undefined). No registry work needed — our LC already delivers.

Out:
- `shared_stack` (11/16) — NOT SharedObject: it tests that the AVM1 value
  stack is shared across clips/frames within a tick (Ruffle commit
  `5931b2982` "Clear stack only between frames"). Bucket Z; possible cheap
  standalone fix, not this tranche.
- `shared_object` / `shared_object_self_ref` — two-run persistence protocol
  (`output1.txt`/`output2.txt`); our runner is single-shot. Stay in
  `ignored_tests.txt`.
- `from_shumway/flash_net_SharedObject` — already `ruffle_matched`
  (effective); upstream `known_failure`, zero corpus gain available.

### 7.1 What the sweeps retired (assumed subsystems NOT needed)

1. **`.sol` file I/O — none.** Ruffle's `TestStorageBackend` is an
   in-memory map that STARTS EMPTY; a shipped `.sol` is an *expected
   output* fixture, never an input. Our harness reads no
   `[shared_objects."…"]` toml table and diffs no `.sol` — only
   `output.txt` lines grade. So: no TCSO header parser, no file writes.
   `getSize()` must still return the byte length a full LSO write *would*
   produce (`body + 10 + 2+len(name)+3+1 + 6`; `amf0_serde_suite` expects
   1579) — compute from an in-memory serialize.
2. **`.sol`-input reader — not needed.** `amf0_serde_suite`'s
   "VERIFYING CHANNEL: SharedObject" block reads the *live cached
   instance* (same-run `getLocal` identity), not a deserialized file.
   An AMF0 **reader is still required**, but only for (a) LC in-process
   round-trip and (b) NC response-packet dispatch — and our AVM2
   `rd0_*` reader (avm2_amf.c:1252-1386) already handles every marker;
   the AVM1 reader is a port of that, building ActionVars.
3. **Harness work — zero, again** (5th tranche running). `log_fetch`
   arrives as `-DLOG_FETCH=1`; the VM-agnostic fetch logger
   (`utils.c:176-230`) already produces the exact Rust `{:02X?}` format;
   `.sol` and the scripted `localhost/test{1,2,3}` response files are
   embedded by `find_data_files` (verify `localhost/` subdir recursion —
   the one open harness question; `findDataFile` matches basename, so
   "test1" resolves regardless of path prefix).

### 7.2 The Flash serialization rules (from recorded bytes — all resolved)

**Two writer paths** (Ruffle `core/src/avm1/amf.rs`; Flash behaves the same
way except where noted):
- **Path A — top-level values** (each `NC.call`/`LC.send` argument,
  `addHeader` value): display objects and `Value::MovieClip` → `0x06`
  undefined; native Array → array rule below; XML → `0x0F` (u32 len +
  UTF-8); Date → `0x0B` (f64 ms + u16 tz always 0); Function objects →
  serialized as objects (own enumerable props); other objects → `0x03` or
  typed `0x10`.
- **Path B — nested values + the whole SharedObject `data` tree**:
  functions **omitted entirely** (property not written); getters NEVER
  invoked (virtual property → `0x06`, `// Flash never evaluates getters
  during AMF serialization`); throwing `__resolve` swallowed.

**The array rule** (was the arc's load-bearing unknown; now proven from
Flash-recorded `output.txt` bytes):
- Wire channels (NC packet, LC): every key parses as usize → **StrictArray
  `0x0A`**, densified 0..max(length, maxIndex+1), holes emitted as `0x06`
  (sparse `[0],[5]` → strict count 6 with four `0x06`). Any non-numeric
  key (incl. `-1`, `2.5`) → **ECMAArray `0x08`** (u32 = `length` prop, all
  entries as named pairs, insertion order). Plain Object with `length` →
  `0x03`, always: the decision input is native-Array-ness, NOT the proto
  chain (a "demoted" real array stays `0x0A`; an Object with
  `__proto__ = Array.prototype` stays `0x03`).
- LSO mode (`getSize`, flush byte-count): nested dense arrays stay
  **ECMAArray**, sparse writes only present keys (no hole padding) —
  Flash's own `.sol` proves it. One serializer, an `lso_mode` flag.
- **Ruffle's known bug** (`known_failure` on amf_array_serialization,
  netconnection_serialize_arrays, amf0_serde_suite): path B always emits
  ECMAArray nested, and never emits nested typed objects. Implementing
  Flash's uniform rule beats Ruffle → full passes.
- Huge indices: key strings are AVM1 number→string forms (`2^63` →
  `"9.2233720368547e+18"`), `length` is a truncating u32 cast.

**Typed objects `0x10`** (top-level only in Ruffle; Flash also emits them
NESTED — part of beating the serde suite): resolution at *serialization*
time: (1) own non-virtual `constructor` prop; (2) stored `__constructor__`
(chain walk, stops at virtual); (3) ptr-compare against the registerClass
registry, **last registration wins**; alias string wins over function
identity; re-pointed alias: old ctor → `0x03`; `ASSetPropFlags` irrelevant;
inherited-via-proto `constructor` does NOT count.
SWF-version: split at **version ≥ 7** (our `registered_class.c:73` already
splits there — the "swf8" test name is cosmetic). SWF6 re-registration
under different casing collapses to ONE entry and emits the **latest
casing** — our CI registry lowercases keys and DISCARDS original casing
(`registered_class.c:165,176`); it needs an original-casing field plus a
ctor→alias reverse lookup (AVM2's `class_to_alias` avm2_amf.c:78-85 is the
model; registered_class.c exports no iterator today).

**Reference table `0x07`** (`amf0_serde_suite` only): fresh table per
top-level value; Flash slots ONLY referenceable values — Object, Typed,
ECMAArray, StrictArray, Date, XML (primitives never; the synthetic
StrictArray wrapping call args doesn't count either). Ruffle increments on
every element (its `07 003A` vs Flash `07 000F`) — copying flash-lso's
counter would be copying the bug. Reader side: fresh EMPTY cache per
LC-delivered argument and per NC response → cross-references and cycles
resolve to `undefined` (Flash's own graded output agrees:
`ref_strict_is_exact: false`).

**Strings**: standard u16-length UTF-8, `0x0C` LongString only >65535.
Unpaired surrogates are NOT actually exercised (Rascal left `\uD83D` as
literal ASCII text) — do not build CESU-8 handling for this tranche.

### 7.3 NetConnection.call machinery

Current state: `connect`/`close` real (`builtin_nc_connect`,
`NCState` pointer side-table action.c:2579-2596), `call`/`addHeader` pure
stubs (action.c:36363-36364). No packet framing code exists anywhere in the
repo (avm2 `nc_call` is also stubbed "tranche 8" — build the framing module
VM-agnostic and both tranches share it).

- Packet: `00 00 | u16 header_count | per-header (u16 name-len, name, u8
  mustUnderstand, u32 EXACT value-len, AMF0 value) | u16 msg_count |
  per-msg (target URI, response URI "/N" 1-based PER FLUSH, u32 exact body
  len, StrictArray of args — always, even zero args)`.
- `addHeader`: one header per name ASCII-case-insensitive (replace in
  place), `mustUnderstand` DEFAULTS TO TRUE, value serialized at
  addHeader time; headers re-sent with EVERY packet.
- Queue per NC; per-tick flush drains the whole queue into ONE packet →
  `swf_log_fetch_queue(url=connect uri, POST, application/x-amf, body)`.
  AVM1 has NO fetch-log call site today — add the queue site and a flush
  at the LC end-of-frame analogue (`swf_core.c:1480` / `swf.c:1203`), and
  re-check tranche 2's five-site exit-gate list (`quit_swf` sits between
  the frame funcs and the pump).
- Response: fetch resolves `http://host:port/path` → embedded data file
  (basename match makes `localhost/test1` findable); parse response
  packet; target `/N/onResult|/N/onStatus` → 1-based responder index;
  deserialize with fresh cache; invalid responses silently ignored; fetch
  FAILURE → `nc.onStatus()` with ZERO arguments.
- connect semantics deltas from ours to verify: `connect(null)` fires
  Connect.Success sync; `http://` fires NOTHING and `isConnected` stays
  FALSE for remoting; `close()` on remoting fires Closed + one extra
  empty `onStatus()`.

### 7.4 SharedObject minimal-real surface

`getLocal(name)` → per-full-name same-run cache (AVM2's `g_so_cache`
pattern, avm2_amf.c:1519-1574) with the name-validation/null rules
(forbidden chars ``~%&\;:"',<>?# `` + space → null; localPath must be a
literal-string path-prefix; `#` prefix when name contains `/`); `data`
DONT_DELETE; `flush()` → true (empty body: true without "writing");
`getSize()` → full-LSO byte length via lso_mode serialize; `clear()`
empties `data` in place. No onStatus/Flush.Pending. REGRESSION WATCH:
`shared_object_serialize_typed_objects` currently passes 1/1 — verify its
one line still matches once getLocal is real.

### 7.5 The `super()` upgrade — the tranche's one hard mechanism

`amf_strict_array_serialization` + `amf_sharedobject_strict_array_serialization`
both run: plain Object with `__proto__.{__constructor__: Array}` calls
`super()` inside a method → Flash converts the receiver into a REAL array
in place (litmus: `o[5]=x` then `o.length === 6` → "Did super() upgrade
instance? YES"; then `length = 1` truncates, and the object serializes as
StrictArray count 1). Ruffle passes: its `NativeObject::Array` is a bit it
can set on an existing object. Our `ASObject` vs `ASArray` struct split
makes in-place conversion impossible — this needs either a native_type
`upgraded-array` flag + attached ASArray side-table with index/length
routing in the property paths (post-dispatch-consolidation there are fewer
sites, but this touches hot paths — keep the flag check cheap), or another
mechanism. WITHOUT it those 2 tests cannot pass (no output.ruffle.txt →
no ruffle_matched fallback; the Body bytes also depend on it). Related but
separate: `netconnection_send_remote`'s `super.call.apply(super,
arguments)` through an AS2 subclass of NetConnection (action.c:58444
currently returns undefined for native-class super) — method-through-super
dispatch, not an upgrade.

### 7.6 Dependency matrix and prediction — **+7 of 11**

| test | needs | confidence |
|---|---|---|
| localconnection_top_level | writer+reader (LC round-trip) | high |
| amf_array_serialization | + NC wire, SO cache | high (beats known_failure) |
| netconnection_serialize_arrays | writer + NC wire | high (beats known_failure) |
| amf_serialize_typed_objects | + typed objects | high |
| amf_swf6_serialize_typed_objects | + registry casing | high |
| amf_swf6_case_insensitive_typed_objects | same | high |
| amf_swf8_case_sensitive_typed_objects | same | high |
| amf_sharedobject_strict_array_serialization | + super()-upgrade, flush | medium (7.5) |
| amf_strict_array_serialization | + super()-upgrade | medium (7.5) |
| netconnection_send_remote | + responses, subclass super | medium |
| amf0_serde_suite | + byte-exact refs, getSize | stretch |

Predict **+7** (the seven "high" rows); the two super()-upgrade tests, the
send_remote lifecycle, and the serde suite are upside, not the base case.
Ship order: 7a writer/reader + LC + SO (yields 1-2 rows alone) → 7b NC
wire (4 more rows) → 7c registry casing (already partly in 7b's rows) →
7d super()-upgrade → 7e send_remote + serde suite polish.

Regression canaries for the local stash-diff sweep: `localconnection`
(579 lines, currently raw-pointer arg passing — serializing MUST NOT
change its output), `localconnection_properties`, `netconnection_close`,
`shared_object_serialize_typed_objects`, `xml_socket_*` (flush-point
neighbours), `file_reference_*` (same pump sites), plus the 11 targets.

---

## 8. Arc closeout (2026-07-29) — **CLOSED at +66**

Nine ships across eight numbered tranches (3b included), **+66 corpus tests**
against a §5 prediction of +43. Corpus effective **3890 → 3957 / 4421** across the
arc (the one test of difference from the summed tranche gains is the
`heavy_tesselation` CI flake documented in tranche 1); `avm2` **926 → 960**,
`avm1` **658 → 687**, `from_shumway` **180 → 183**, `from_avmplus`
**1509 → 1510**. Every tranche beat or matched its prediction, and exactly one
regression was introduced and fixed inside the arc
(`from_shumway/encoding1`, tranche 8).

| Tranche | Predicted | Actual | Ship |
|---|---|---|---|
| 1 — class surface, no transport | +9 | **+10** | `937047612` + `722dea0e9` |
| 2 — `socket.json` replay | +12 | **+14** | `767a301d2` + `e173acc9a` |
| 3 — file dialogs | +11 | **+15** | `72fdc5e93` |
| 3b — download/upload | +5 | **+7** | `6cf854900` |
| 4 — `URLStream` | +2 | **+3** | `8c3b7673f` |
| 7 — AVM1 AMF0 + `NetConnection.call` | +7 | **+11** | `702d38a35` + `698bdddfa` |
| 5 — AVM2 AMF gaps | +1 | **+1** | `6a07045c4` |
| 8 — AVM2 `NetConnection.call` | +2 | **+2** | `01f30d3f5` + `8a302905d` |
| 6 — `LocalConnection` registry | +3 | **+3** | `34171042f` |
| **total** | **+52** | **+66** | |

(The +43 headline in §5 predates the three census corrections — tranche 3b's
seven tests, bucket W's 11-not-9, and `stream1` — which is why the summed
per-tranche prediction is +52.)

### Final disposition of the census

| Bucket | Tests | Landed | Left |
|---|---|---|---|
| P — class surface | 10 | 10 | — |
| S — socket replay | 14 | 14 | — |
| D — file dialogs | 14 | 14 (+2 census misses: `filefilter_properties`, and 3b's seven) | — |
| U — `URLStream` | 3 | 3 | — |
| L — `LocalConnection` | 4 | 3 | `avm2/localconnection` (589/890 — the AVM1↔AVM2 bridge) |
| W — AVM1 AMF0 + NC | 11 | 11 | — |
| X — AVM2 AMF + NC wire | 4 | 4 | — |
| M — media transport | 6 | 0 | **won't-do in this arc** (FLV demux + AAC/G.711/H.263 decode) |
| Z — caught by the sweeps, not net | 4 | 0 | not net; two are not even enumerated |

Everything the arc set out to do is done except **one half of one test**. Bucket M
stays dispositioned out — `netstream_flv_date` (4 lines, wants only `onMetaData`
off an FLV's AMF0 metadata tag) remains the cheapest re-entry point if a media
arc ever opens. Bucket Z's four are unrelated property-flag / native-identity
questions, plus two two-run tests the harness does not enumerate.

Also shipped along the way, none of it in the census: `flash.system.fscommand`,
`flash.utils.IExternalizable`, `ObjectEncoding.dynamicPropertyWriter`,
`AsyncErrorEvent.error`, `StatusEvent.toString`, ByteArray's interface-namespace
method aliases, integer-key-first dynamic enumeration, a VM-agnostic AMF0
remoting packet module (`src/amf_packet.c`), and three heap/overflow fixes
reachable from ordinary script (`setArrayElement`'s u32 growth overflow, the
AMF0 cyclic-graph recursion, `addProperty`'s enumerable flag).

### Lessons, ranked by how much they would have saved

1. **Bucket by OWNER, then re-predict after every tranche.** Six of the nine
   tranches beat their prediction, and every overshoot has the same cause: a
   mechanism built for tranche N turned out to be most of tranche N+1. The
   re-predictions in §6 (tranche 6 LARGE → SMALL, tranche 8 MEDIUM → SMALL) were
   what made the last three tranches cheap, and they were only possible because
   each postmortem asked "what does this change make free?" explicitly.
2. **Canaries must be chosen by CONTENT, not by name.** The arc's one regression
   (`encoding1`) and its two census misses (`stream1`, `filefilter_properties`)
   are the same failure: a name-and-`.as`-source sweep is blind to tests that
   ship no source and whose names do not mention the mechanism. For a serializer,
   grep the expected OUTPUTS for hex dumps; for a class, grep for the error
   number.
3. **Read the oracle's source, not its behaviour, for the rules — but read
   FLASH's recorded bytes for the values.** Ruffle's source gave the arc every
   state machine (the NetConnection two-variant enum, the LocalConnection double
   listener check, the sender/receiver event asymmetry, the file-dialog and
   socket mock contracts) and got them right first try. Where Ruffle's own
   *output* was the reference it was wrong four times — the `known_failure`
   tests — and Flash's bytes settled each one. `known_failure` upstream means
   **Ruffle is not the oracle**; treating those as `ruffle_matched` ceilings
   would have left seven full passes on the table.
4. **A "structurally impossible" conversion is usually already half-built.**
   Tranche 7 scoped the `super()` array upgrade as a new side table plus routing
   through the property paths; `NATIVE_ARRAY` had been on the receiver for
   months and the gap was fifty lines of `length` bookkeeping. Grep for a partial
   form before designing the mechanism.
5. **Zero harness work, six tranches running.** Every mock the arc needed
   (`socket.json`, the file dialog, the `?debug-` fetch switch, the scripted
   remoting responses) is keyed off test CONTENT, so `verify_output.py` changed
   once in the whole arc — to embed nested data files, and only because Ruffle's
   navigator maps a URL path to a subdirectory.
6. **Interface-typed parameters are an invisible dependency.** A builtin class
   that implements an AS3 interface needs its methods keyed under the interface
   namespace as well as public, and nothing reveals the omission until a test
   passes an instance through such a parameter (tranche 5's `#1069`).
7. **When two graded outputs disagree about ordering, look for a key-class
   partition.** Integer-spelled dynamic keys enumerate before string keys in both
   players; assuming a single insertion order (either direction) cannot satisfy
   both recorded outputs.
8. **A new runtime `.c` file registers in FOUR places.** `CMakeLists.txt`,
   `verify_output.py`, `build_test.sh`, `build_wasm_avm2.sh` — the last two keep
   their own source lists. CI's `wasm-link-smoke` job catches the omission, which
   is how tranche 7 found it.

### What this unlocks next

`feature-priority-map.md`'s net row is CLOSED. The AMF codecs, the remoting
packet framing and the LocalConnection registry are now shared infrastructure:
anything that serialises user classes over a wire (Flash Remoting games, AMF
save files, cross-SWF messaging) has a working substrate in both VMs. The next
row by yield is the **PixelBender 25 / Stage3D 13** scoping decision.
