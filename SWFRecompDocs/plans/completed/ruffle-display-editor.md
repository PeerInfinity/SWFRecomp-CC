> **AUDIT OUTCOME (2026-07-04):** Built — demos/ruffle-editor + docs/injector/ruffle_editor.html.

# Ruffle Display Editor — ExternalInterface-based display list editing

## Goal

Build a display list editor that works with **Ruffle** (not SWFRecomp),
using the same concept as the existing `display_editor`: a JSON textarea
alongside the player, with Refresh/Apply buttons. The bridge between JS
and ActionScript uses `ExternalInterface` instead of direct C struct access.

Two variants: an AS2 wrapper SWF and an AS3 wrapper SWF. Both load a
target SWF and expose its display list via ExternalInterface callbacks.

## Architecture

```
┌─────────────────────────────────────────────────────┐
│  HTML page                                          │
│                                                     │
│  ┌──────────────┐  ┌────────────────────────────┐   │
│  │              │  │  <textarea>                 │   │
│  │   Ruffle     │  │    JSON from                │   │
│  │   Player     │  │    getDisplayList()         │   │
│  │   (CDN)      │  │                             │   │
│  │              │  │                             │   │
│  └──────────────┘  └────────────────────────────┘   │
│                                                     │
│  [Load SWF]  [Refresh]  [Apply]                     │
│                                                     │
│  JS ←→ ExternalInterface ←→ ActionScript wrapper    │
│                                     ↓               │
│                              loadMovie / Loader     │
│                                     ↓               │
│                              target SWF             │
└─────────────────────────────────────────────────────┘
```

**Data flow:**
1. User drops/selects a target SWF
2. Wrapper SWF loads the target via `loadMovie` (AS2) or `Loader` (AS3)
3. User clicks Refresh → JS calls `player.ruffle().callExternalInterface("getDisplayList")`
4. AS code enumerates children, reads `_x`/`_y`/`_xscale`/`_yscale`/`_rotation`/`_alpha`
5. Returns serialized data to JS → displayed in textarea
6. User edits JSON, clicks Apply → JS calls `callExternalInterface("setTransform", ...)` per object
7. AS code sets properties on the named MovieClip → Ruffle re-renders

## Key technical details

### Ruffle embedding (already proven)

`docs/demo.html` loads Ruffle from CDN — no local build needed:
```javascript
var ruffleScript = document.createElement('script');
ruffleScript.src = 'https://unpkg.com/@ruffle-rs/ruffle';
ruffleScript.onload = function() {
    var ruffle = window.RufflePlayer.newest();
    var player = ruffle.createPlayer();
    container.appendChild(player);
    player.load({ data: swfBytes });
};
```

### JS ↔ AS communication

Ruffle supports `ExternalInterface` for both AVM1 and AVM2 (confirmed in
source: `core/src/avm1/globals/external_interface.rs` and
`core/src/avm2/globals/flash/external/external_interface.rs`).

**JS → AS (calling registered callbacks):**
```javascript
// Ruffle v1 API
var result = player.ruffle().callExternalInterface("getDisplayList");

// Or via legacy property (Ruffle auto-creates these when addCallback is called)
var result = player.getDisplayList();
```

**AS → JS (calling external functions):**
```actionscript
ExternalInterface.call("onDisplayListReady", jsonString);
```

### ExternalInterface value marshalling

Ruffle converts between AS and JS values:
- Strings, numbers, booleans, null, undefined pass through directly
- Arrays become JS arrays
- Objects become JS objects (but only simple key-value — no nested MC references)

This means we **cannot return MovieClip references** to JS. We must serialize
the display list to a string (or array of plain objects) in ActionScript.

### AS2 wrapper SWF

Compile with MTASC (`~/CC/mtasc/bin/mtasc`).

```actionscript
import flash.external.ExternalInterface;

class DisplayBridge {
    static var holder:MovieClip;

    static function main(mc:MovieClip) {
        holder = mc.createEmptyMovieClip("holder", 1);

        ExternalInterface.addCallback("loadSwf", null, function(url:String) {
            holder.loadMovie(url);
        });

        ExternalInterface.addCallback("loadSwfData", null, function() {
            // loadMovie only works with URLs, not binary data
            // For dropped files, we use a blob URL from JS
        });

        ExternalInterface.addCallback("getDisplayList", null, function():String {
            var items:Array = [];
            for (var name:String in holder) {
                var child = holder[name];
                if (typeof(child) == "movieclip") {
                    items.push(
                        '{"name":"' + name + '"' +
                        ',"x":' + child._x +
                        ',"y":' + child._y +
                        ',"xscale":' + child._xscale +
                        ',"yscale":' + child._yscale +
                        ',"rotation":' + child._rotation +
                        ',"alpha":' + child._alpha +
                        ',"visible":' + child._visible +
                        ',"width":' + child._width +
                        ',"height":' + child._height +
                        '}'
                    );
                    // Also enumerate nested children
                    for (var cname:String in child) {
                        var gc = child[cname];
                        if (typeof(gc) == "movieclip") {
                            items.push(
                                '{"name":"' + name + '.' + cname + '"' +
                                ',"x":' + gc._x +
                                ',"y":' + gc._y +
                                ',"xscale":' + gc._xscale +
                                ',"yscale":' + gc._yscale +
                                ',"rotation":' + gc._rotation +
                                ',"alpha":' + gc._alpha +
                                ',"visible":' + gc._visible +
                                ',"width":' + gc._width +
                                ',"height":' + gc._height +
                                '}'
                            );
                        }
                    }
                }
            }
            return '{"displayList":[' + items.join(",") + ']}';
        });

        ExternalInterface.addCallback("setTransform", null,
            function(path:String, x:Number, y:Number,
                     xscale:Number, yscale:Number, rotation:Number):Void {
                // path is like "holder.mcName" or "holder.mcName.child"
                var mc:MovieClip = eval("_root.holder." + path);
                if (mc != undefined) {
                    mc._x = x;
                    mc._y = y;
                    mc._xscale = xscale;
                    mc._yscale = yscale;
                    mc._rotation = rotation;
                }
            }
        );
    }
}
```

**Build command:**
```bash
~/CC/mtasc/bin/mtasc -cp ~/CC/mtasc/ocaml/mtasc/std \
    -main -header 550:400:30 -version 8 \
    DisplayBridge.as -swf wrapper_as2.swf
```

### AS3 wrapper SWF

Requires `mxmlc` (Apache Flex SDK) — not currently installed.

```actionscript
package {
    import flash.display.Sprite;
    import flash.display.Loader;
    import flash.display.DisplayObject;
    import flash.display.DisplayObjectContainer;
    import flash.external.ExternalInterface;
    import flash.net.URLRequest;
    import flash.utils.ByteArray;

    public class DisplayBridge extends Sprite {
        private var holder:Sprite;
        private var loader:Loader;

        public function DisplayBridge() {
            holder = new Sprite();
            addChild(holder);
            loader = new Loader();
            holder.addChild(loader);

            ExternalInterface.addCallback("loadSwf", function(url:String):void {
                loader.load(new URLRequest(url));
            });

            ExternalInterface.addCallback("getDisplayList", function():String {
                return enumerate(loader.content as DisplayObjectContainer);
            });

            ExternalInterface.addCallback("setTransform", function(
                index:int, x:Number, y:Number,
                scaleX:Number, scaleY:Number, rotation:Number):void {
                var container:DisplayObjectContainer =
                    loader.content as DisplayObjectContainer;
                if (container && index < container.numChildren) {
                    var child:DisplayObject = container.getChildAt(index);
                    child.x = x;
                    child.y = y;
                    child.scaleX = scaleX;
                    child.scaleY = scaleY;
                    child.rotation = rotation;
                }
            });
        }

        private function enumerate(root:DisplayObjectContainer):String {
            if (!root) return '{"displayList":[]}';
            var items:Array = [];
            for (var i:int = 0; i < root.numChildren; i++) {
                var child:DisplayObject = root.getChildAt(i);
                items.push(
                    '{"index":' + i +
                    ',"name":"' + child.name + '"' +
                    ',"x":' + child.x +
                    ',"y":' + child.y +
                    ',"scaleX":' + child.scaleX +
                    ',"scaleY":' + child.scaleY +
                    ',"rotation":' + child.rotation +
                    ',"alpha":' + child.alpha +
                    ',"visible":' + child.visible +
                    ',"width":' + child.width +
                    ',"height":' + child.height +
                    '}'
                );
            }
            return '{"displayList":[' + items.join(",") + ']}';
        }
    }
}
```

**Build command:**
```bash
mxmlc -output wrapper_as3.swf DisplayBridge.as
```

### Limitations compared to SWFRecomp version

| Feature | SWFRecomp | Ruffle+ExternalInterface |
|---------|-----------|------------------------|
| Plain shapes | Yes (direct transform_data) | No (only named MovieClips) |
| Nested depth access | Yes (all display_list entries) | Partial (needs recursive enumeration) |
| GPU-direct writes | Yes (renderer_write_transform) | No (Ruffle re-renders automatically) |
| Latency | Instant (same frame) | Next frame (AS property → render) |
| loadMovie from bytes | N/A | AS2: needs blob URL; AS3: Loader.loadBytes |
| Works offline | Yes (WASM) | No (CDN) unless Ruffle bundled |

### Loading user-dropped SWFs

The user drops a .swf file in the browser. We need to get it into the
wrapper SWF running in Ruffle.

**Option A — Blob URL:** Create a blob URL from the dropped bytes, pass
it to the wrapper's `loadSwf(url)` callback. Requires Ruffle to allow
loading from blob: URLs (needs `allowNetworking: "all"`).

**Option B — Two Ruffle instances:** Don't use a wrapper SWF at all.
Load the target SWF directly in Ruffle. Inject the ExternalInterface
bridge AS into the target SWF before loading (swfmill round-trip to
inject a DoAction tag). More complex but avoids loadMovie issues.

**Option C — loadBytes (AS3 only):** Pass the SWF bytes directly to
AS3's `Loader.loadBytes()`. No URL needed. Not available in AS2.

Recommendation: Start with **Option A** (blob URL). It's the simplest
and works for both AS2 and AS3. Fall back to Option B if Ruffle blocks
blob URLs.

## Milestones

### Milestone 1: AS2 wrapper with hardcoded test SWF

- Write `DisplayBridge.as` (AS2 wrapper with ExternalInterface bridge)
- Compile with MTASC into `wrapper_as2.swf`
- Create HTML page that loads the wrapper in Ruffle (CDN)
- Hardcode a test SWF URL (e.g., one of the existing test.swf files)
- Verify: Refresh button shows JSON, Apply button moves objects
- Location: `docs/injector/ruffle_editor.html` + wrapper SWF

### Milestone 2: File drop support

- Add drop zone to the HTML page
- Create blob URL from dropped file, pass to wrapper's `loadSwf()`
- Test with various SWFs (AS1, AS2, with/without named instances)
- Handle the "no named MovieClips" case gracefully (empty display list)

### Milestone 3: AS3 wrapper

- Install Apache Flex SDK (`mxmlc`)
- Write AS3 `DisplayBridge.as` with `Loader` and ExternalInterface
- Compile into `wrapper_as3.swf`
- Auto-detect AS3 SWFs (SWF version >= 9) and use the AS3 wrapper
- Test with AS3 SWFs

### Milestone 4: Polish

- Unified page that handles both AS2 and AS3 automatically
- Recursive child enumeration (not just top-level children)
- Error handling for SWFs without named instances
- Side-by-side with SWFRecomp version for comparison

## Open questions

1. **Blob URL loading in Ruffle:** Does `loadMovie("blob:...")` work in
   Ruffle? If not, we need Option B or C. Easy to test empirically.

2. **ExternalInterface return value size:** Large display lists produce
   long JSON strings. Is there a practical limit on ExternalInterface
   string return values in Ruffle? Probably fine for hundreds of objects.

3. **AS3 compiler:** Apache Flex SDK needs to be downloaded and installed.
   Java 21 is already available. The alternative is to skip AS3 initially
   and add it when a compiler is set up.

4. **for..in enumeration of loaded MovieClips:** When AS2's `loadMovie`
   loads a SWF into a clip, can the parent enumerate the loaded content's
   children with `for..in`? This works for MovieClips placed on the
   timeline but may behave differently for dynamically loaded content.
   Needs empirical testing.

## Files

- `docs/injector/ruffle_editor.html` — main HTML page
- `demos/ruffle-editor/DisplayBridge.as` — AS2 wrapper source
- `demos/ruffle-editor/wrapper_as2.swf` — compiled AS2 wrapper
- `demos/ruffle-editor/DisplayBridge3.as` — AS3 wrapper source (milestone 3)
- `demos/ruffle-editor/wrapper_as3.swf` — compiled AS3 wrapper (milestone 3)

## Tools required

- **MTASC** (AS2): `~/CC/mtasc/bin/mtasc` — already installed
- **mxmlc** (AS3): Apache Flex SDK — needs installation (milestone 3)
- **Ruffle**: CDN at `https://unpkg.com/@ruffle-rs/ruffle` — no local build
- **swfmill**: `/usr/bin/swfmill` — available if SWF manipulation needed
