# AVM2 SharedObject host hook (browser wasm)

**Audience:** the page/host that embeds an AVM2 wasm build (Archipelago-CC
flashPanel for Seedling) and wants `SharedObject.getLocal` saves to survive a
page reload.

**Scope:** AVM2 `flash.net.SharedObject` only (`SWFModernRuntime/src/avm2/avm2_amf.c`).
AVM1 SharedObject is untouched. The code is compiled only in the browser build
(`__EMSCRIPTEN__ && !OFFSCREEN_RENDER`). Native, headless and CI builds don't
contain it.

**Division of labour:** the runtime stays generic. It encodes and decodes AMF3
and calls the hook at fixed points. The host owns everything else: keys,
localStorage (or any store), wrapping and encoding, debouncing and timing.

## 1. Installing the hook

Set a plain object on `Module` before the SWF's first `getLocal` (the simplest
way is in the `Module` literal, before the wasm script loads):

```js
Module.swfSharedObjectHost = {
  load(name, localPath, key)         { /* -> bytes | null */ },
  store(name, localPath, bytes, key) { /* bytes: Uint8Array | null */ },
};
```

The runtime checks for the hook on **every** hook point. If
`Module.swfSharedObjectHost` is not an object, nothing is encoded, decoded or
called, and SharedObject stays memory-only, exactly as it was before the hook.
Either method may be missing. A missing `load` means "no bytes", and a missing
`store` drops the write.

### Arguments (both methods)

| arg | type | meaning |
|---|---|---|
| `name` | string | `getLocal`'s first argument, as AS3 passed it (coerced to String). Seedling: `"shrumsave"`. |
| `localPath` | string \| null | `getLocal`'s second argument, or **null** when AS3 omitted it or passed null/undefined. Seedling passes none, so it is null. |
| `key` | string | the runtime's full storage key `host/path/name` (Ruffle's `local_shared_object_key`, derived from the build-time `SWF_URL`, default `file:///test.swf`). Seedling with the default URL: `"localhost/test.swf/shrumsave"`. It is stable for a given build. Use it, or `(name, localPath)`, as your storage key. |

### `load(name, localPath, key)` → bytes | null

Return the bytes the matching `store` last received, as any of:
`Uint8Array`, another `ArrayBufferView`, `ArrayBuffer`, `number[]`, or a
**base64 string**. Return `null`/`undefined` (or empty bytes) for "nothing
stored". A throw is logged with `console.error` and treated as null.
`load` must be synchronous.

### `store(name, localPath, bytes, key)`

- `bytes` is a **fresh `Uint8Array` copy** (yours to keep) of the AMF3
  encoding of `so.data`, encoded as one AMF3 value: an anonymous object whose
  dynamic properties are the save fields.
- `bytes === null` means **delete this entry**. It is sent by `clear()`.
- A throw is logged and ignored.

## 2. When the runtime calls the hook

1. **First `getLocal` of a key in the page's life** → `load(...)`. The
   runtime makes this call **once per key**. If bytes come back, they are
   AMF3-decoded into `data`. If the bytes are null or don't decode, `data`
   starts empty. Every later `getLocal` of the same key returns the cached
   SharedObject and **never calls `load` again**. That includes a `getLocal`
   after `clear()`, which returns the cleared in-memory object.
   (`Main.freshSaveForLevelSet` does `clear()` and then `getLocal`.)
2. **`so.flush()`** → `store(..., bytes)`. `flush()` still returns
   `"flushed"`. If the encoder throws (for example a `writeExternal` that
   throws), the store is skipped silently.
3. **`so.clear()`** → `data` is replaced with a new empty object, then
   `store(..., null)`.
4. `getRemote`, `close`, `setProperty` and `size` are not hooked. `size` still
   reports 0.

The runtime has **no implicit flush points**. Flash auto-flushes on unload,
but this runtime does not. Use §3's flush-all.

## 3. Exports (host → runtime)

Call these **only between ticks** (from your own JS: a timer, an event
handler, `pagehide`). Never call them from inside a callback that AS3 is
running (an ExternalInterface call, or the hook itself). They allocate and
may run AS3, and the AVM2 collector assumes the VM is quiescent.

```js
// Flush every getLocal'd SharedObject through store(). Returns how many were stored.
const n = Module.ccall('avm2_so_flush_all', 'number', [], []);

// reloadSharedObject: fetch bytes through load() and repopulate the EXISTING data object
// in place. Pass null (or "") as localPath when getLocal was called without one.
const ok = Module.ccall('avm2_so_reload', 'number', ['string', 'string'], ['shrumsave', null]);
```

`avm2_so_reload(name, localPath)`:
- It finds the SharedObject by the same key `getLocal(name, localPath)`
  would compute, calls `load(...)` (a second, explicit load for that key),
  and AMF3-decodes the result.
- On success it **deletes every dynamic property of the existing `data`
  object, then writes the decoded ones into the same object**. The object
  is never swapped, so AS3 code that cached `SAVE_FILE.data` (or any
  `var d = so.data`) sees the new values. It returns **1**.
- It returns **0** and leaves `data` untouched when: no hook is installed,
  the name was never `getLocal`'d in this page, `load` returned no bytes, or
  the bytes don't decode to an object.

Exported in `SWFRecomp/scripts/build_wasm_avm2.sh` and
`SWFRecomp/wasm_wrappers/bundle/build.sh`. A wasm built before this change
has neither export, and `ccall` throws "not exported".

## 4. Limits

- The per-name cache holds 64 keys. A key beyond the 64th is never hooked:
  there is no load, and flush/clear don't store.
- The bytes are a single AMF3 value. They are not the `.sol` file format, and
  they aren't meant to be read by anything except this runtime's `load` path.
  Class aliases (`registerClassAlias`) round-trip the same way
  `ByteArray.writeObject`/`readObject` do.

## 5. Seedling notes (read before wiring)

Read from `Archipelago-CC/vendor/seedling/src` (`Main.as`, `LevelSet.as`,
`Bot.as`, `Inventory.as`, `Game.as`) at Archipelago-CC `c0cf42327d`:

- **Seedling never calls `flush()`.** The only grep hit is FlashPunk's
  `Data.as`, a different store. So the host's `avm2_so_flush_all` (on
  pagehide, on dispose, and on whatever cadence the host picks) is the
  **only** way a save reaches the host. `clear()` is the only other store, and
  it sends null.
- **⚠ Don't flush-all before the reload.** When the host answers `load` with
  null at boot, Seedling runs on an empty save stamped with the vanilla set
  (`reconcileSave`'s "no save at all" arm: it builds the table and stamps the
  vanilla id, and it does **not** `clear()`). If `avm2_so_flush_all` runs
  between boot and `avm2_so_reload` (for example a pagehide while the AP
  connection is still pending), it stores that vanilla boot save over the
  persisted AP save. The host must gate flush-all until after its reload
  (or until it decides there is nothing to restore).
- `clear()` → `store(null)` happens in `Main.freshSaveForLevelSet` (a
  `reconcileSave` set mismatch) and `Main.clearSave` (`Game.as:1288` and the
  `Player.as` debug warps). After a reload whose `levelSetId` matches the
  delivered set and whose table length matches, `reconcileSave` keeps the
  save and does not clear.
- **The startSave "copy-outs" are not copies.** Every startSave line
  (`hasSword = hasSword` … `grassCut = grassCut`, `Main.as:252-357`) is a
  getter/setter pair on `SAVE_FILE.data` itself, so it writes back into the
  same `data` object. No separate static holds a boot-time copy. After an
  in-place reload, every `Main.*` getter, and `Game.time` (which is
  `Main.time`, `Game.as:492-496`), reads the restored value.
- **What is stale after the reload is the world.** The boot world (`new
  Game(0, 80, 128)`, `Main.as:51`) was built from the empty save, and room
  entities read the persistence/key arrays in their constructors or in the
  first `check()`. The post-`deliver()` reset in
  `seedlingRandomizerWiring.js` is a `teleport({level,x,y})` (the
  `new_instance Game($level,$x,$y)` recipe) or the new-game arm (level < 0).
  Both build a **new** `Game`, whose `begin()` → `loadLevelIndex` and
  `inventory.check()` read the restored save. So the restored cleared flags,
  keys, seals and totems apply to the start room, with no extra restart.
  `Inventory.items` is rebuilt by `addItemsFromSave` (called every
  `Inventory.update`) in its canonical order. That is the same order a
  native Flash reload produces, and `primary`/`secondary` are restored
  byte-for-byte.
- **The new-game arm resets two things on purpose** (`Game.as:829-836`):
  `time = dayLength/2` and the Wind cutscene. A restored mid-day `time` does
  **not** survive that arm. The explicit-start teleport keeps it.
- **`botStart` is not on this path, but if it ever is, the restore is
  wiped.** `Bot.botStart` (the tape harness) unconditionally resets the
  persistence table to all-true and resets keys, totems and seals to the
  fresh values (Ruling 25, `Bot.as:1700-1770`), then applies only what the
  tape declares. A live AP start driven through `botStart` would discard
  the restored progress unless the tape re-declares it.

## 6. Measured save size (Seedling, AMF3)

These were measured with this runtime's AMF3 encoder (`ByteArray.writeObject`
on an object of Seedling's exact save shape: the 22 startSave scalars, 15
badges, 5 keys, 5 totem parts, 16 seal slots, position/level, `levelSetId`, and
the persistence table of `rooms × 30` booleans):

| rooms | end-game save | fresh save | base64 (end-game / fresh) |
|---|---|---|---|
| 116 (vanilla count) | **4175 B** | 4215 B | **5568 B** / 5620 B |
| 64 | 2614 B | 2654 B | 3488 B / 3540 B |
| 200 | 6695 B | 6735 B | 8928 B / 8980 B |

The table dominates (≈30 B per room, 1 B per boolean). A fresh save is 40 B
*larger* because the 16 empty seal slots are −1, and each −1 costs 4 B as a
U29 instead of 1 B. The `levelSetId` was a 39-char placeholder, so add or
subtract its real length. The fixture is a replica built from the source
shape, not a dump from a live run. Values change only a few bytes (U29 widths
and the id length).

## 7. Tests

- Native/headless, no hook: every AVM2 `amf_*` row and
  `shared_object_get_local_error` / `shared_object_no_root` pass in graphics
  mode, with a no-graphics spot-check. `shared_object` itself is the two-run
  `.sol` test, which is not graded by the runner.
- Browser contract test:
  `ruffle-tests/tests/swfs/_swfbridge/livetest/so_hook/run_so_hook_test.sh`.
  It runs `Test.as` → wasm, then `harness.html` (a reference host) and the
  `so_hook_test.js` driver, and makes 18 checks:
  - one load per key across getLocal/clear/getLocal;
  - flush → store(Uint8Array), and clear → store(null);
  - reload returns 0 on garbage, null and an unknown name, and leaves data
    untouched;
  - reload returns 1, and an AS3 alias of `so.data` sees the restored values;
  - flush_all stores bytes identical to the original flush;
  - a fresh page whose base64 load answer is those bytes restores them at
    boot.

  Uses headed WSLg Chrome by default, or `HEADLESS=1`.
