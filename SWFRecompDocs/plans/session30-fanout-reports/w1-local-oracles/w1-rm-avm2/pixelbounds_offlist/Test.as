package {
  import flash.display.*; import flash.geom.*;
  [SWF(width="400", height="300", frameRate="30")]
  public class Test extends Sprite {
    public function Test() {
      var r:Array = [[0,0,100,100],[10,20,30,40]];
      for each (var a:Array in r) for each (var sx:Number in [1, 2]) {
        var s:Sprite = new Sprite(); s.graphics.beginFill(0xFF0000); s.graphics.drawRect(a[0],a[1],a[2],a[3]); s.graphics.endFill();
        s.scaleX = sx; s.x = 5; s.y = 7;
        trace("rect " + a + " sx=" + sx + " off: " + s.transform.pixelBounds + " getBounds(s)=" + s.getBounds(s));
        addChild(s); trace("  on: " + s.transform.pixelBounds); removeChild(s); trace("  removed: " + s.transform.pixelBounds);
      }
      var n:Sprite = new Sprite(); trace("empty off: " + n.transform.pixelBounds);
    }
  }
}
