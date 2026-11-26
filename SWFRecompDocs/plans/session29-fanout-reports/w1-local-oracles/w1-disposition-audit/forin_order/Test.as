   package { import flash.display.Sprite; import flash.net.URLVariables;
   public class Test extends Sprite { public function Test() {
     var orders:Array = [["a","b"],["b","a"],["lastName","firstName"],["aaa","cccc"],["k1","k2","k3"],["k3","k2","k1"],
                         ["x","y","z","w","v","u"]];
     for each (var ks:Array in orders) {
       var o:Object = {}; var u:URLVariables = new URLVariables();
       for each (var k:String in ks) { o[k] = 1; u[k] = 1; }
       var a:Array = []; for (var n:String in o) a.push(n);
       trace("Object " + ks.join(",") + " -> " + a.join(","));
       trace("URLVariables " + ks.join(",") + " -> " + u.toString());
       var d:URLVariables = new URLVariables(ks.join("=1&") + "=1");
       trace("decoded " + ks.join(",") + " -> " + d.toString());
     } } } }
