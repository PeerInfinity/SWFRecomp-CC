# avm2_agi_shell

Regression net for the **AGI no-op shell** (AVM2; Elephant Quest EQ-3, gap #3).

EQ's New Game handler (`MainMenu.clicky`, `playB` case) runs the **unguarded**
`this.shell.agi.hideAGILogin()` → `this.agi.hideLoginStatus()`, where
`AGIStuff.agi` is `loader.contentLoaderInfo.content`, assigned only in the
Loader's `COMPLETE` handler (`AGIStuff.loadComplete`). With no real AGI.swf that
content is `undefined`, so `hideLoginStatus()` throws **#1010** and New Game dies
— exactly Ruffle's Failure 1 under a null navigator.

## Fix shape (runtime: `avm2_display.c`, `loader_load`)

A `Loader.load()` whose request URL is the ArmorGames AGI helper SWF
(`…/agi/AGI.swf`, matched on the `AGI.swf` marker):

- constructs a **no-op AGI shell** — an internal concrete `Sprite` subclass
  (`swfrecomp.internal::AGINoopShell`) whose AG-API methods
  (`init`/`initAGUI`/`hideLoginStatus`/`showLoginStatus`/`retrieveUserData`/
  `submitUserData`/`showScoreboardSubmit`/`showScoreboardList`/
  `showGameShareList`/`showGameShareNavi`/`showAGILogin`/`hideAGILogin`) are all
  no-ops returning `undefined`;
- seeds it as the Loader's `contentLoaderInfo.content` (a new `content` field on
  `Avm2LoaderInfoExt`; `li_get_content` returns it when set, else the root
  movie); and
- fires a **synchronous** `Event.COMPLETE` on the contentLoaderInfo, so the
  game's own `loadComplete` assigns `agi = shell`, `addChild`s it, and calls
  `init`/`initAGUI` on it — all no-ops.

Because COMPLETE fires *inside* `load()`, the handler's traces precede the
post-`load()` line:

```
COMPLETE fired
content non-null: true
content is DisplayObject: true
addChild ok
agi no-op methods ok, no #1010
after load, reached end
```

The test mirrors `AGIStuff`'s exact sequence (`new Loader()` → add COMPLETE
listener → `load(AGI.swf URL)` → in COMPLETE: read `content`, `addChild` it,
call the unguarded `hideLoginStatus()` + the rest of the AG-API surface EQ
touches). It **fails** without the fix (COMPLETE never fires; `content` is null;
`hideLoginStatus()` on a null/undefined content throws #1010).

The generic (non-AGI) `Loader.load()` no-op path — COMPLETE never fires, content
stays null — is pinned separately by `avm2_loader_stub`.

This is a **reusable capability**: it unblocks New Game on any ArmorGames /
AGI-portal game whose New Game handler dereferences the AGI content. It does
**not** implement the real ArmorGames API or runtime SWF loading.

Rebuild the SWF with `./build_swf.sh` (mxmlc).
