# avm2_loader_stub

Regression net for the `flash.display.Loader` stub (AVM2). Elephant Quest's
`AGIStuff` constructs a `Loader` during `Shell.init` (`agi.init()` →
`AGIStuff.initAGI`): `new Loader()` → `loader.contentLoaderInfo.addEventListener(
Event.COMPLETE, cb)` → `loader.load(urlRequest)` (fire-and-forget AGI.swf load).
Before the stub existed, our runtime deferred `flash.display.Loader`, so
`new Loader()` threw `#1065 "Loader is not defined"`, aborting `Shell.init`
**before** `startIntro()` — the intro/title was never reached (EQ-2.5 wall).

The test mirrors that exact path and traces that each step completes without
throwing:

```
loader created: true
contentLoaderInfo: true
addEventListener ok
load ok, content=null
no #1065, reached end
```

Stub shape (runtime: `avm2_display.c`, `flash.display.Loader` extends
`DisplayObjectContainer`):

- `new Loader()` is non-throwing (concrete `display_native_init`; larger
  `native_ext` — `Avm2LoaderExt` — for the per-instance `contentLoaderInfo`
  and `content`).
- `contentLoaderInfo` returns the Loader's **own** fresh `LoaderInfo` (which
  extends `EventDispatcher`), so `addEventListener(COMPLETE, …)` is a real
  no-op registration with stable identity across reads.
- `load` / `loadBytes` / `close` / `unload` / `unloadAndStop` are no-ops for a
  **generic** URL. No second SWF is ever loaded, so `COMPLETE` never fires
  (`onComplete` is never traced) and `content` stays `null`. This test now uses
  a generic (non-AGI) URL to pin exactly that no-op path.

**EQ-3 update:** the one exception is the ArmorGames **AGI helper SWF** URL
(`…/agi/AGI.swf`), which now takes the *agi-shell* path — a synthetic `COMPLETE`
with a no-op shell as `content` — so EQ's New Game handler's unguarded
`agi.hideLoginStatus()` no-ops instead of throwing #1010. That behavior is
covered by the sibling **`avm2_agi_shell`** test (gap #3's `agi` no-op shell).

This is a **reusable capability** — it unblocks any AGI/preloader-style game
that constructs a `Loader` during init. It does **not** implement real runtime
SWF loading.

Rebuild the SWF with `./build_swf.sh` (mxmlc).
