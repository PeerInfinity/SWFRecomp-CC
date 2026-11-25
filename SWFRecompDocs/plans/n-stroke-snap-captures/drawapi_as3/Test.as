// s28 n-stroke-snap: AVM2 Graphics strokes, widths x subpixel offsets (left: pixelHinting=false, right: true)
package {
  import flash.display.Sprite;
  public class Test extends Sprite {
    public function Test() {
      var widths:Array = [0, 0.5, 1, 1.1, 1.2, 1.5, 2, 2.25, 3, 4];
      var offs:Array = [0, 0.1, 0.25, 0.4, 0.5, 0.6, 0.75, 0.9];
      for (var h:int = 0; h < 2; h++)
        for (var r:int = 0; r < widths.length; r++)
          for (var c:int = 0; c < offs.length; c++) {
            var x:Number = 10 + h * 220 + c * 26 + offs[c], y:Number = 10 + r * 20 + offs[c];
            graphics.lineStyle(widths[r], 0, 1, h == 1);
            graphics.moveTo(x, y); graphics.lineTo(x + 16, y); graphics.lineTo(x + 16, y + 10);
            graphics.lineTo(x, y + 10); graphics.lineTo(x, y);
          }
      trace("drawn");
    }
  }
}
