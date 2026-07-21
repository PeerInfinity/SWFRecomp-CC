# avm2_contextmenu_stub

Regression net for the `flash.ui.ContextMenu` / `flash.ui.ContextMenuItem`
stubs (AVM2). Elephant Quest's `SoundBox.initContextMenu` builds a cosmetic
right-click menu at `MainTimeline.frame1`; before the `ContextMenuItem` stub
existed this threw `#1065 "ContextMenuItem is not defined"` **before**
`preloadIt()`, so the preloader never started and the stage stayed blank
(frame-proven via `AVM2_CPU_DUMP`: 120 byte-identical gray frames).

The test mirrors that exact path: `new ContextMenu()` → `hideBuiltInItems()` →
`new ContextMenuItem(caption)` → `item.enabled = false` →
`customItems.push(item)` → `this.contextMenu = menu`, and traces that each step
completes without throwing:

```
menu created: true
item created: true
push: 1
assigned contextMenu, no throw
```

The stubs are intentionally cosmetic (headless never reads the menu back):
`ContextMenu.customItems` returns a fresh discardable Array, `ContextMenuItem`'s
ctor and `enabled` setter are no-ops. Runtime: `avm2_text.c` (flash.ui block);
the `.contextMenu` setter on InteractiveObject already existed. Rebuild the SWF
with `./build_swf.sh` (mxmlc).
