import flash.external.ExternalInterface;

class BridgeInject {
    static function main(mc:MovieClip) {
        trace("BRIDGE_INJECT: main() called");
        trace("BRIDGE_INJECT: ExternalInterface.available = " + ExternalInterface.available);
        // Register ExternalInterface callbacks directly on the target SWF
        ExternalInterface.addCallback("wireCheck", null, function():String {
            return "ok";
        });

        ExternalInterface.addCallback("getDisplayList", null, function():String {
            var items:Array = [];
            var seen:Object = {};
            var MAX_ITEMS:Number = 500;

            // BFS queue
            var queue:Array = [];
            queue.push({clip: _root, prefix: ""});

            var qi:Number = 0;
            while (qi < queue.length && items.length < MAX_ITEMS) {
                var entry:Object = queue[qi];
                qi++;
                var clip:MovieClip = entry.clip;
                var prefix:String = entry.prefix;

                for (var name:String in clip) {
                    if (items.length >= MAX_ITEMS) break;
                    var child = clip[name];
                    if (typeof(child) != "movieclip") continue;
                    var path:String = (prefix.length > 0) ? prefix + "." + name : name;
                    if (seen[path]) continue;
                    seen[path] = true;
                    items.push(
                        '{"name":"' + name + '"'
                        + ',"path":"' + path + '"'
                        + ',"type":"movieclip"'
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
                    queue.push({clip: child, prefix: path});
                }
            }
            return '{"displayList":[' + items.join(",") + ']}';
        });

        ExternalInterface.addCallback("setTransform", null,
            function(path:String, x:Number, y:Number,
                     xscale:Number, yscale:Number, rotation:Number):Void {
                // Navigate dotted path from _root
                var parts:Array = path.split(".");
                var target:MovieClip = _root;
                var pi:Number = 0;
                while (pi < parts.length && target != undefined) {
                    target = target[parts[pi]];
                    pi++;
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
}
