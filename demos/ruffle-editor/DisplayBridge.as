import flash.external.ExternalInterface;

class DisplayBridge {
    static function main(mc:MovieClip) {
        // Let the player element control the visible area, not the SWF stage size
        Stage.scaleMode = "noScale";
        Stage.align = "TL";

        // Create test content: 3 colored boxes
        makeBox(mc, "red_box",   0xFF0000, 50,  50,  80, 80);
        makeBox(mc, "green_box", 0x00FF00, 200, 80,  60, 100);
        makeBox(mc, "blue_box",  0x0000FF, 120, 200, 100, 60);

        // Create holder clip for external SWF loading
        mc.createEmptyMovieClip("_holder", 99999);

        // Register ExternalInterface callbacks
        ExternalInterface.addCallback("wireCheck", null, function():String {
            return "ok";
        });

        ExternalInterface.addCallback("loadSwf", null, function(url:String):Void {
            // Clear test content
            _root.red_box.removeMovieClip();
            _root.green_box.removeMovieClip();
            _root.blue_box.removeMovieClip();
            // Load external SWF into holder
            _root._holder.loadMovie(url);
        });

        ExternalInterface.addCallback("getDisplayList", null, function():String {
            var items:Array = [];
            var clips:Array = [_root, _root._holder];
            var ci:Number = 0;
            while (ci < clips.length) {
                var clip:MovieClip = clips[ci];
                ci++;
                if (clip == undefined) continue;
                for (var name:String in clip) {
                    var child = clip[name];
                    if (typeof(child) == "movieclip" && name != "_holder") {
                        items.push(
                            '{"name":"' + name + '"'
                            + ',"x":' + child._x
                            + ',"y":' + child._y
                            + ',"xscale":' + child._xscale
                            + ',"yscale":' + child._yscale
                            + ',"rotation":' + child._rotation
                            + ',"alpha":' + child._alpha
                            + ',"visible":' + child._visible
                            + ',"width":' + child._width
                            + ',"height":' + child._height
                            + '}'
                        );
                    }
                }
            }
            return '{"displayList":[' + items.join(",") + ']}';
        });

        ExternalInterface.addCallback("setTransform", null,
            function(name:String, x:Number, y:Number,
                     xscale:Number, yscale:Number, rotation:Number):Void {
                // Try _root first, then holder
                var target:MovieClip = _root[name];
                if (target == undefined) {
                    target = _root._holder[name];
                }
                if (target != undefined) {
                    target._x = x;
                    target._y = y;
                    target._xscale = xscale;
                    target._yscale = yscale;
                    target._rotation = rotation;
                }
            }
        );
    }

    static function makeBox(mc:MovieClip, name:String, color:Number,
                            x:Number, y:Number, w:Number, h:Number):Void {
        var box:MovieClip = mc.createEmptyMovieClip(name, mc.getNextHighestDepth());
        box.beginFill(color, 100);
        box.moveTo(0, 0);
        box.lineTo(w, 0);
        box.lineTo(w, h);
        box.lineTo(0, h);
        box.lineTo(0, 0);
        box.endFill();
        box._x = x;
        box._y = y;
    }
}
