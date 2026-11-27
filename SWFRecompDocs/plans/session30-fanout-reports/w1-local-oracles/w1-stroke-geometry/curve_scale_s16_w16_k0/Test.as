package {
  import flash.display.*;
  [SWF(width="800", height="900", backgroundColor="#000000", frameRate="30")]
  public class Test extends Sprite {
    public function Test() {
      var scales:Array = [16]; var widths:Array = [16]; var shapes:Array = [0]; var phases:Array = [0];
      var x:Number = 10, y:Number = 10, rowH:Number = 0;
      for each (var w:Number in widths) for each (var s:Number in scales) for each (var k:int in shapes) for each (var f:Number in phases) {
        var sp:Sprite = new Sprite();
        sp.graphics.lineStyle(w, 0x49D0D7);
        sp.graphics.moveTo(0, 0);
        if (k == 0) { sp.graphics.curveTo(20, 0, 20, 20); sp.graphics.curveTo(10, 30, 0, 20); }
        else { sp.graphics.curveTo(10, 30, 20, 0); }
        sp.scaleX = sp.scaleY = s;
        var bw:Number = 24 * s + w * s, bh:Number = 32 * s + w * s;
        if (x + bw > 800 - 10) { x = 10; y += rowH + 6; rowH = 0; }
        sp.x = x + w * s / 2 + f; sp.y = y + w * s / 2 + f;
        addChild(sp); trace("w=" + w + " s=" + s + " k=" + k + " f=" + f + " at " + sp.x + "," + sp.y);
        x += bw + 6; if (bh > rowH) rowH = bh;
      }
      trace("bottom " + (y + rowH));
    }
  }
}
