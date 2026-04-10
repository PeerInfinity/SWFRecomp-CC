package {
    import flash.display.Sprite;
    import flash.display.Shape;
    import flash.display.Loader;
    import flash.display.DisplayObject;
    import flash.display.DisplayObjectContainer;
    import flash.display.StageScaleMode;
    import flash.display.StageAlign;
    import flash.text.TextField;
    import flash.display.Bitmap;
    import flash.media.Video;
    import flash.external.ExternalInterface;
    import flash.net.URLRequest;
    import flash.events.Event;
    import flash.system.LoaderContext;
    import flash.system.ApplicationDomain;
    import flash.system.SecurityDomain;

    public class DisplayBridge3 extends Sprite {
        private var loader:Loader;
        private var testBoxes:Sprite;

        public function DisplayBridge3() {
            // Let the player element control the visible area
            stage.scaleMode = StageScaleMode.NO_SCALE;
            stage.align = StageAlign.TOP_LEFT;

            // Create test content
            testBoxes = new Sprite();
            addChild(testBoxes);
            makeBox("red_box",   0xFF0000, 50,  50,  80, 80);
            makeBox("green_box", 0x00FF00, 200, 80,  60, 100);
            makeBox("blue_box",  0x0000FF, 120, 200, 100, 60);

            // Create loader for external SWFs
            loader = new Loader();

            // Register ExternalInterface callbacks
            if (ExternalInterface.available) {
                ExternalInterface.addCallback("wireCheck", function():String {
                    return "ok";
                });

                ExternalInterface.addCallback("loadSwf", function(url:String):void {
                    // Remove test content
                    if (testBoxes.parent) {
                        removeChild(testBoxes);
                    }
                    // Remove old loaded content
                    if (loader.parent) {
                        removeChild(loader);
                    }
                    addChild(loader);
                    loader.load(new URLRequest(url));
                });

                ExternalInterface.addCallback("getDisplayList", function():String {
                    var items:Array = [];
                    // Enumerate test boxes
                    if (testBoxes.parent) {
                        enumContainer(testBoxes, items);
                    }
                    // Enumerate loaded content
                    if (loader.content is DisplayObjectContainer) {
                        enumContainer(loader.content as DisplayObjectContainer, items);
                    }
                    return '{"displayList":[' + items.join(",") + ']}';
                });

                ExternalInterface.addCallback("setTransform", function(
                    nameOrIndex:String, x:Number, y:Number,
                    scaleX:Number, scaleY:Number, rotation:Number):void {

                    var child:DisplayObject = findChild(nameOrIndex);
                    if (child) {
                        child.x = x;
                        child.y = y;
                        child.scaleX = scaleX;
                        child.scaleY = scaleY;
                        child.rotation = rotation;
                    }
                });
            }
        }

        private function findChild(nameOrIndex:String):DisplayObject {
            var root:DisplayObjectContainer = null;
            if (testBoxes.parent) root = testBoxes;
            else if (loader.content is DisplayObjectContainer) root = loader.content as DisplayObjectContainer;
            if (!root) return null;

            // Handle dotted paths (e.g., "instance3.child1")
            var parts:Array = nameOrIndex.split(".");
            var current:DisplayObjectContainer = root;
            for (var i:int = 0; i < parts.length; i++) {
                var found:DisplayObject = findInContainer(current, parts[i]);
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

        private function findInContainer(container:DisplayObjectContainer, nameOrIndex:String):DisplayObject {
            // Try by name
            for (var i:int = 0; i < container.numChildren; i++) {
                if (container.getChildAt(i).name == nameOrIndex) {
                    return container.getChildAt(i);
                }
            }
            // Try by index
            var idx:int = parseInt(nameOrIndex);
            if (!isNaN(idx) && idx >= 0 && idx < container.numChildren) {
                return container.getChildAt(idx);
            }
            return null;
        }

        private static var MAX_ITEMS:int = 500;

        private function enumContainer(container:DisplayObjectContainer, items:Array, prefix:String = "", maxDepth:int = 8):void {
            if (items.length >= MAX_ITEMS) return;
            for (var i:int = 0; i < container.numChildren; i++) {
                var child:DisplayObject = container.getChildAt(i);
                var typeName:String = "unknown";
                if (child is Sprite)          typeName = "sprite";
                else if (child is Shape)      typeName = "shape";
                else if (child is TextField)  typeName = "textfield";
                else if (child is Bitmap)     typeName = "bitmap";
                else if (child is Video)      typeName = "video";

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

                // Recurse into containers (sprites, movieclips)
                if (items.length < MAX_ITEMS && maxDepth > 0 && child is DisplayObjectContainer) {
                    enumContainer(child as DisplayObjectContainer, items, path, maxDepth - 1);
                }
            }
        }

        private function makeBox(name:String, color:uint, x:Number, y:Number, w:Number, h:Number):void {
            var box:Sprite = new Sprite();
            box.name = name;
            box.graphics.beginFill(color);
            box.graphics.drawRect(0, 0, w, h);
            box.graphics.endFill();
            box.x = x;
            box.y = y;
            testBoxes.addChild(box);
        }
    }
}
