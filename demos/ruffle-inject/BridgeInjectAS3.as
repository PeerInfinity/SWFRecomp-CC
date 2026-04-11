package {
    import flash.display.Sprite;
    import flash.display.Stage;
    import flash.display.DisplayObject;
    import flash.display.DisplayObjectContainer;
    import flash.display.Shape;
    import flash.text.TextField;
    import flash.display.Bitmap;
    import flash.external.ExternalInterface;
    import flash.events.Event;

    public class BridgeInjectAS3 extends Sprite {
        private static var MAX_ITEMS:int = 500;

        public function BridgeInjectAS3() {
            super();
            this.visible = false;
            // Wait until we're on stage to register callbacks
            if (stage) {
                init();
            } else {
                addEventListener(Event.ADDED_TO_STAGE, function(e:Event):void {
                    removeEventListener(Event.ADDED_TO_STAGE, arguments.callee);
                    init();
                });
            }
        }

        private function init():void {
            if (!ExternalInterface.available) return;

            ExternalInterface.addCallback("wireCheck", function():String {
                return "ok";
            });

            var stageRef:Stage = stage;

            ExternalInterface.addCallback("getDisplayList", function():String {
                var items:Array = [];
                var root:DisplayObjectContainer = stageRef.getChildAt(0) as DisplayObjectContainer;
                if (root) {
                    enumContainer(root, items, "", 8);
                }
                return '{"displayList":[' + items.join(",") + ']}';
            });

            ExternalInterface.addCallback("setTransform", function(
                nameOrIndex:String, x:Number, y:Number,
                scaleX:Number, scaleY:Number, rotation:Number):void {
                var root:DisplayObjectContainer = stageRef.getChildAt(0) as DisplayObjectContainer;
                if (!root) return;
                var child:DisplayObject = findChild(root, nameOrIndex);
                if (child) {
                    child.x = x;
                    child.y = y;
                    child.scaleX = scaleX;
                    child.scaleY = scaleY;
                    child.rotation = rotation;
                }
            });
        }

        private static function enumContainer(container:DisplayObjectContainer,
            items:Array, prefix:String, maxDepth:int):void {
            if (items.length >= MAX_ITEMS) return;
            for (var i:int = 0; i < container.numChildren; i++) {
                var child:DisplayObject = container.getChildAt(i);
                // Skip our injected bridge sprite
                if (child is BridgeInjectAS3) continue;

                var typeName:String = "unknown";
                if (child is Sprite)         typeName = "sprite";
                else if (child is Shape)     typeName = "shape";
                else if (child is TextField) typeName = "textfield";
                else if (child is Bitmap)    typeName = "bitmap";

                var path:String = prefix.length > 0 ? prefix + "." + child.name : child.name;
                items.push(
                    '{"name":"' + path + '"'
                    + ',"type":"' + typeName + '"'
                    + ',"index":' + i
                    + ',"x":' + child.x
                    + ',"y":' + child.y
                    + ',"scaleX":' + child.scaleX
                    + ',"scaleY":' + child.scaleY
                    + ',"rotation":' + child.rotation
                    + ',"alpha":' + child.alpha
                    + ',"visible":' + child.visible
                    + ',"width":' + child.width
                    + ',"height":' + child.height
                    + '}'
                );

                if (items.length >= MAX_ITEMS) return;
                if (maxDepth > 0 && child is DisplayObjectContainer) {
                    enumContainer(child as DisplayObjectContainer, items, path, maxDepth - 1);
                }
            }
        }

        private static function findChild(root:DisplayObjectContainer, nameOrIndex:String):DisplayObject {
            var parts:Array = nameOrIndex.split(".");
            var current:DisplayObjectContainer = root;
            for (var i:int = 0; i < parts.length; i++) {
                var found:DisplayObject = null;
                // Try by name
                for (var j:int = 0; j < current.numChildren; j++) {
                    if (current.getChildAt(j).name == parts[i]) {
                        found = current.getChildAt(j);
                        break;
                    }
                }
                // Try by index
                if (!found) {
                    var idx:int = parseInt(parts[i]);
                    if (!isNaN(idx) && idx >= 0 && idx < current.numChildren) {
                        found = current.getChildAt(idx);
                    }
                }
                if (!found) return null;
                if (i < parts.length - 1) {
                    if (found is DisplayObjectContainer) {
                        current = found as DisplayObjectContainer;
                    } else {
                        return null;
                    }
                } else {
                    return found;
                }
            }
            return null;
        }
    }
}
