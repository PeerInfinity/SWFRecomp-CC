# Archipelago Randomizer Integration (APCpp ↔ AVM1 `Rando` class)

**Status:** Phase 0 (download + build + link de-risk) **complete** 2026-05-31.
Phase 1 (native proof-of-pipe) **implemented + verified** 2026-05-31 — `Rando`
builtin class lands in the runtime, gated on `WITH_AP`; a smoke test passes
end-to-end (see §5.6). Phases 2–3 pending.

**Owner:** PeerInfinity / Claude. Originated from a conversation with LittleCube
(EVRS) about turning SWFRecomp games (Pong, Snake, Doodle Jump) into Archipelago
(AP) randomizers.

---

## 1. Goal

Expose an Archipelago client to recompiled AVM1 (ActionScript 1/2) games as a
native builtin class `Rando`, backed by LittleCube's **APCpp** library
(`~/CC/APCpp`, `github.com/OmniaRandomizers/APCpp`). Game-specific randomizer
logic is written in ActionScript and injected into the target SWF; the `Rando`
class is the bridge between that AS and the AP server.

Target API shape (LittleCube's sketch — polling style):

```actionscript
var rando:Rando = new Rando("127.0.0.1", "38281", "Player1", "mypassword");
rando.connect();

if (rando.hasItem(ITEM.JUMP)) { /* allow jump */ }
while (receivedCount < rando.receivedItemsSize()) { givePlayerItem(rando.receivedItem(receivedCount++)); }
if (game.thingHappened()) { rando.sendLocation(LOCATION.OF_THING_THAT_HAPPENED); }
```

`LOCATION` / `ITEM` are plain AS static-object "enums" filled out per game — no
runtime support needed.

---

## 2. What APCpp is (verified)

- **Flat C-style global API** in `Archipelago.h` (`AP_New`, `AP_Init`, `AP_Start`,
  `AP_IsConnected`, `AP_GetReceivedItemsSize`, `AP_GetReceivedItem(idx)`,
  `AP_GetLocationIsChecked(id)`, `AP_SendItem(id)`, `AP_StoryComplete`, message
  polling, DeathLink, slot-data). State is an **opaque `struct AP_State*`** from
  `AP_New()` — ideal as a per-instance native handle.
- **Deps:** IXWebSocket (transport) + jsoncpp + zlib + (OpenSSL on Linux /
  mbedtls on Windows) + pthread. C++11.
- **Polling-friendly:** the `AP_Get*` accessors are the thread-safe read path;
  APCpp runs its own network thread. Phase 1 reads them from the AVM1 main thread
  — no cross-thread callback into the interpreter.

### 2.1 Key finding: `Archipelago.h` is NOT C-includable

`extern "C"` fixes name-mangling only — the signatures still use C++ types. The
header `#include`s `<string>`, `<vector>`, `<map>`, `<json/json.h>`, declares
`extern std::string ap_player_name;` outside the `extern "C"` block, and several
"C" functions take/return C++ types:

```cpp
void AP_SendItems(AP_State*, std::set<int64_t> const&);
std::string AP_GetItemName(AP_State*, std::string game, int64_t id);
void AP_Say(AP_State*, std::string);
```

➡ The C runtime (`action.c`, compiled `-std=c17`) **cannot include this header**.
We need a thin **C++ shim**:

- `rando_ap.cpp` — `#include "Archipelago.h"`, compiled with `g++`. Translates
  POD ↔ C++ types.
- `rando_ap.h` — **pure POD** (only `int64_t`, `const char*`, `bool`, `size_t`,
  opaque `struct AP_State;`). The C runtime includes only this.

The Phase-1 polling subset maps almost entirely onto APCpp functions that are
*already* pure-POD, so the shim is small (see §7 mapping table). The
std::string/map functions (`AP_Say`, slot-data maps) get POD wrappers later or
are deferred.

---

## 3. Phase 0 — Done (2026-05-31)

- Cloned `~/CC/APCpp` with submodules (`IXWebSocket`, `jsoncpp`, `lib/zlib`;
  mbedtls ships as a bundled tarball, used on Windows only).
- Built with its own CMake (Release). On **Linux** it uses **system zlib +
  OpenSSL** — no mbedtls. Bundled jsoncpp. Produced three static libs:
  - `~/CC/APCpp/build/libAPCpp-static.a`
  - `~/CC/APCpp/build/IXWebSocket/libixwebsocket.a`
  - `~/CC/APCpp/build/lib/libjsoncpp.a`
- **Link de-risked end-to-end:** a pure-C TU declaring only the POD subset linked
  against the three C++ static libs, ran, and printed
  `AP_New=0x… connected=0 items=0` (correct with no server). This validates the
  shim pattern and the whole native link chain before any runtime code.

**Verified native link recipe** (extends `build_test.sh`'s existing `gcc` +
`-lstdc++` pattern; link driver stays `gcc`):

```
~/CC/APCpp/build/libAPCpp-static.a \
~/CC/APCpp/build/IXWebSocket/libixwebsocket.a \
~/CC/APCpp/build/lib/libjsoncpp.a \
-lz -lssl -lcrypto -lpthread -lstdc++ -lm
```

`-lm` is required (IXWebSocket's backoff uses `pow`); `build_test.sh` already
passes it. Two deltas in our favor vs. the original estimate: **no mbedtls** on
Linux, and the dep set is just `ixwebsocket + jsoncpp + openssl + zlib + pthread`.

---

## 4. Architecture

```
ActionScript (game + injected glue + ITEM/LOCATION enums)
        │  new Rando(...) / rando.method(...)
        ▼
AVM1 runtime  (SWFModernRuntime/src/actionmodern/rando.c)   ← NEW, pure C
        │  pure-POD calls (rando_ap.h)
        ▼
C++ shim      (SWFModernRuntime/src/actionmodern/rando_ap.cpp) ← NEW, g++
        │  AP_* (C++-typed)
        ▼
APCpp static libs  →  IXWebSocket  →  TCP/TLS websocket  →  Archipelago server
```

- **Native builds:** the full chain works (Phase 1).
- **Browser-WASM builds (peerinfinity.com demos):** IXWebSocket cannot link under
  emscripten (raw BSD sockets, no emscripten path — confirmed). The transport
  layer must be replaced (Phase 2). Everything above the transport is reusable.

---

## 5. Phase 1 — Native proof-of-pipe  ✅ IMPLEMENTED 2026-05-31

Smallest thing that demonstrates AVM1 ↔ APCpp. Native NO_GRAPHICS build only, no
game logic. **Verified file:line anchors below.**

### As-built summary

Files added:
- `SWFModernRuntime/include/actionmodern/rando_ap.h` — pure-POD bridge header.
- `SWFModernRuntime/src/actionmodern/rando_ap.cpp` — C++ shim over APCpp (g++).
- `SWFModernRuntime/include/actionmodern/actionrando.h` — public runtime header.
- `SWFModernRuntime/src/actionmodern/rando.c` — the `Rando` builtin class.

Edits:
- `include/actionmodern/object.h` — added `NATIVE_RANDO = 23` to `enum NativeType`.
- `src/actionmodern/action.c` — `#include actionrando.h`; `initRandoPrototype()`
  in `ensureGlobalInit`; `REG_FUNC("Rando", 5, …)` (both `#ifdef WITH_AP`).
- `SWFRecomp/scripts/build_test.sh` — `WITH_AP=1` gate: copy rando sources,
  g++-compile the shim, link APCpp libs. (NOTE: `build_test.sh`'s NO_GRAPHICS
  path is pre-existingly broken — missing `action_queue.c`/
  `sprite_frame_scripts.c` — so the **maintained** build path is verify_output.py
  below; the build_test.sh hooks are kept for parity but untested via that path.)
- `ruffle-tests/verify_output.py` — `WITH_AP=1` env gate in `compile_native`:
  copies rando sources, adds `-DWITH_AP` + APCpp include, g++-compiles
  `rando_ap.cpp`, links `libAPCpp-static.a` + `libixwebsocket.a` +
  `libjsoncpp.a` + `-lssl -lcrypto -lpthread -lstdc++`. **This is the working
  native build path.**

The AVM1 `new Rando(...)` reaches the generic native-constructor path in
`actionNewObject` (no special-case needed): `lookupFunctionByName` finds the
registered `g_rando_constructor`, the path allocates the instance, wires
`__proto__` to `g_rando_prototype`, and calls `advanced_func(…, this_obj=obj)`
(action.c:51805/51891/`function_type==2` branch). The `AP_State*` handle is
stashed via the wrapper `RandoAP*` as a hidden DontEnum `__ap_handle__` property.

Default builds (no `WITH_AP`) are entirely unaffected: rando.c isn't copied,
action.c's Rando references are `#ifdef`'d out, and the verify_output.py hooks
are env-gated. Confirmed: an existing `typeof` test still passes without WITH_AP.

### 5.1 New files

| File | Lang | Purpose |
|------|------|---------|
| `SWFModernRuntime/src/actionmodern/rando_ap.h`  | C (POD) | pure-POD bridge decls; `struct AP_State;` opaque |
| `SWFModernRuntime/src/actionmodern/rando_ap.cpp` | C++ | `#include "Archipelago.h"`, POD↔C++ translation |
| `SWFModernRuntime/src/actionmodern/rando.c`     | C | `Rando` constructor + prototype + method handlers |
| `SWFModernRuntime/include/actionmodern/rando.h` | C | `initRandoPrototype()`, ctor accessor decls |

### 5.2 Runtime binding (model on `math.c` / `date.c`)

- **Method handler signature** (confirmed `include/actionmodern/action.h:399`):
  ```c
  typedef ActionVar (*Function2Ptr)(SWFAppContext*, ActionVar* args,
                                    u32 arg_count, ActionVar* registers,
                                    void* this_obj);
  ```
  `this_obj` = receiver `ASObject*`; args pre-popped; return an `ActionVar`
  (caller pushes). Pattern confirmed at `math.c:31` (`builtin_math_abs`).
- **Constructor + prototype** mirror `initDatePrototype` (`date.c`): a
  `g_rando_constructor` ASFunction (`function_type=2`,
  `advanced_func=builtin_rando_constructor`) and a `g_rando_prototype` ASObject
  holding method ASFunctions, attached via `setProperty`.
- **Native backing:** store the `AP_State*` on the instance. Two options:
  1. hidden numeric property `__ap_state__` holding the pointer as `u64` in
     `numeric_value` (the `__date_time__`-as-double trick, `date.c:204`); or
  2. add `NATIVE_RANDO` to `enum NativeType`
     (`include/actionmodern/object.h`) + a parallel handle store.
  Start with (1) — least invasive. Constructor calls `AP_New()`/`AP_Init()`;
  add cleanup → `AP_Free()` (where AVM1 frees objects, or leak-for-now in P1).

### 5.3 Global registration (`action.c`)

- `ensureGlobalInit()` at **`action.c:36782`**; `initDatePrototype` called at
  **`:36846`** — add `initRandoPrototype(app_context);` nearby.
- REG_FUNC/REG_OBJ macros at **`:37218`/`:37222`**; registration block starts
  **`:37244`**. Add:
  ```c
  REG_FUNC("Rando", 5, &g_rando_constructor);
  ```
- `new Rando(...)`: route through the standard prototype-construct path used for
  user classes (constructor's `advanced_func` receives the new `this_obj`), **not**
  the hardcoded `if (strcmp(ctor_name,"Array")...)` chain in `actionNewObject`.

### 5.4 Build / link (`SWFRecomp/scripts/build_test.sh`)

- Native link step uses `gcc` (**`build_test.sh:357`**); HEADLESS_GRAPHICS already
  links C++ via `gcc` + `-lstdc++` (**`:350`**) — same pattern.
- Add (gated to native, opt-in via an env flag e.g. `WITH_AP=1` so non-AP tests
  are unaffected):
  ```bash
  NATIVE_EXTRA_INCLUDES="-I$HOME/CC/APCpp $NATIVE_EXTRA_INCLUDES"
  NATIVE_EXTRA_LIBS="$AP/libAPCpp-static.a $AP/IXWebSocket/libixwebsocket.a \
      $AP/lib/libjsoncpp.a -lz -lssl -lcrypto -lpthread -lstdc++ -lm $NATIVE_EXTRA_LIBS"
  ```
- `rando_ap.cpp` must compile with `g++` (the rest is `gcc *.c`). Either add a
  separate `g++ -c rando_ap.cpp` step or rename so the existing C++ compile path
  (used for Dawn) picks it up. **CMake alternative:** add the libs at
  `SWFModernRuntime/CMakeLists.txt` link section (`:167`) + include dir.

### 5.5 Phase 1 acceptance test

A tiny hand-authored SWF/AS (or a recompiled test) that:
1. `new Rando("archipelago.gg","38281","Test","")` → non-null,
2. `rando.connect()` then poll `rando.isConnected()`,
3. against a **local** AP server, `rando.receivedItemsSize()` reflects items and
   `rando.sendLocation(id)` registers a check server-side.

Native-only; runs locally (not in the no-graphics CI trace harness, which has no
network). Document as a manual/integration test, not a suite test.

### 5.6 Phase 1 acceptance result ✅

Smoke test at `ruffle-tests/tests/swfs/_rando/rando_smoke/` (`Test.as` +
intrinsic `Rando.as`, compiled with MTASC to `test.swf`). It constructs a Rando
and polls it **without** calling `connect()` — no server, no network thread, so
output is deterministic in any environment:

```
function          // typeof Rando
object            // typeof new Rando(...)
false             // isConnected()  (not connected)
0                 // receivedItemsSize()
false             // hasItem(42)
false             // locationIsChecked(1)
```

Run: `WITH_AP=1 python3 ruffle-tests/verify_output.py --test=rando_smoke \
--tests-dir=ruffle-tests/tests/swfs/_rando --diff` → **PASS**. This exercises
the real link (AP_New/AP_Init/AP_IsConnected/AP_GetReceivedItemsSize/
AP_GetLocationIsChecked are actually called) and the AVM1 construct + method
dispatch. The `_rando` suite is excluded from the default Ruffle runs (it
lives outside `tests/swfs/avm1` and requires `WITH_AP`).

A live-server round-trip test (connect + receive items + send a location) is now
**fully automated** for the native path:
`ruffle-tests/tests/swfs/_rando/livetest/run_livetest.sh` builds the shim +
a C harness on `rando_ap.h`, starts a local Archipelago server (ChecksFinder
seed 1) via Archipelago-CC's `scripts/setup/setup_ap_server.py`, asserts connect
+ starting item (80002) + `sendLocation(81001)`→checked, and tears the server
down. PASSES end-to-end. Note: the item a self-location grants is filtered from
`received_items` by APCpp (`sending_player == self && location > 0`), so the
round-trip is asserted via the checked-locations signal, not a received item.
(The WASM/browser path's live test — Playwright-driven — is still pending.)

---

## 6. Phase 2 — WASM transport bridge

**Full plan: [archipelago-phase2-wasm-bridge.md](archipelago-phase2-wasm-bridge.md).**

IXWebSocket can't reach the browser WebSocket API (raw BSD sockets, no emscripten
path). Rather than port the transport, we **bypass APCpp in the browser** and
talk to the AP server through **`archipelago.js`** (v2.1.0, browser-native
WebSocket) — the JS transport already proven in `~/CC/flash-ap-api`. Phase 2 is
just a second implementation of the `rando_ap.h` seam (`rando_ap_wasm.c` → EM_JS
→ `window.__randoBridge` → archipelago.js); `rando.c` and the AVM1 surface are
unchanged. Locked decisions:

- **Hybrid connect** via a single `bridge.connect(host,port,slot,pw)` chokepoint,
  callable from both AS (`new Rando(...); connect()`, args stashed at construct)
  and an **HTML connect form** (convenience override) — one AS codebase across
  backends, with an idempotency guard.
- **Vendor archipelago.js** into the demo assets (self-contained, version-pinned).
- **No ASYNCIFY** for the Rando path (fire-and-forget connect + synchronous POD
  state reads); hot path is POD-only, strings cross once at construct/connect.
- **Transport only** — item *application* + `ITEM`/`LOCATION` enums are Phase 3.

This phase gates the peerinfinity.com browser demos; native works without it.

---

## 7. Phase 1 API mapping (AS ↔ APCpp, all POD)

| `Rando` AS method | APCpp call | Notes |
|---|---|---|
| `new Rando(ip,port,slot,pw)` | `AP_New()` → `AP_Init(st,"ip:port",game,slot,pw)` | `game` from ctor or a setter |
| `connect()` | `AP_Start(st)` | |
| `isConnected()` | `AP_IsConnected(st)` → bool | |
| `receivedItemsSize()` | `AP_GetReceivedItemsSize(st)` → size_t | |
| `receivedItem(i)` | `AP_GetReceivedItem(st,i)` → int64 | item id |
| `hasItem(id)` | derived: scan received items for `id` | helper in `rando_ap.cpp` |
| `locationIsChecked(id)` | `AP_GetLocationIsChecked(st,id)` → bool | |
| `sendLocation(id)` | `AP_SendItem(st,id)` | AP "send item" = check a location |
| `storyComplete()` | `AP_StoryComplete(st)` | |

Deferred (need std::string/map wrappers): `AP_Say`, slot-data maps, message
queue, DeathLink.

---

## 8. Phase 3 — Doodle Jump apworld (later)

- **AS injection** via the **prelude-SWF** mechanism already prototyped in
  `SWFRecompDocs/plans/runtime-swf-injection-demos.md` (Demo 4,
  `demos/runtime-swf/prelude_swf/`). The prelude defines the `ITEM`/`LOCATION`
  enums and the randomizer glue in `_global`, recompiled **before** the game SWF.
- Game-specific hooks: jump-gating, platform/pickup randomization, item receipt,
  location checks (per LittleCube's sketch). Requires identifying hook points in
  Doodle Jump's AS (or patching the generated C at known sites).
- The matching AP **apworld** (Python, server side) is out of scope for this repo
  — separate deliverable.

---

## 9. Open questions / risks

- **`Rando` lifetime / `AP_Free`:** where does AVM1 GC/free an ASObject with a
  native handle? Need a finalize hook or accept a per-session leak in P1.
- **`new Rando` dispatch:** confirm the standard native-ctor construct path gives
  the handler the freshly-allocated `this_obj` (vs. needing an `actionNewObject`
  special-case). Validate during P1.
- **Threading:** APCpp's network thread vs. AVM1 main thread — confirm the
  `AP_Get*` accessors are safe to poll without locking (they appear to be; verify
  against `Archipelago.cpp`).
- **Determinism / tests:** AP needs a live server; keep it out of the
  deterministic trace suites. Phase 1 test is manual/integration.
- **Phase 2 transport** is the real unknown; native value is deliverable without
  it.

---

## 10. References

- APCpp: `~/CC/APCpp` (`OmniaRandomizers/APCpp`); API: `~/CC/APCpp/Archipelago.h`.
- Built libs: `~/CC/APCpp/build/{libAPCpp-static.a, IXWebSocket/libixwebsocket.a, lib/libjsoncpp.a}`.
- Builtin-class patterns: `SWFModernRuntime/src/actionmodern/math.c`,
  `date.c`; registration `action.c:36782` (`ensureGlobalInit`) +
  `:37244` (REG block); handler typedef `include/actionmodern/action.h:399`.
- Native build/link: `SWFRecomp/scripts/build_test.sh` (`:350` C++ link pattern,
  `:357` gcc link); `SWFModernRuntime/CMakeLists.txt` (`:116` lib, `:167` link).
- AS injection prior art: `SWFRecompDocs/plans/runtime-swf-injection-demos.md`.
