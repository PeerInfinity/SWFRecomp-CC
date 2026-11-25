package {
// s28 w1-avm2-vector-flash: Flash sample-point probe (FLASH oracle request).
// Capture at quality LOW and HIGH (run_image.py --quality low / high), tick 1.
// Each cell is 40x40 px; row 0 = solid fills, row 1 = strokes,
// row 2 = gradients, row 3 = bitmaps / cacheAsBitmap / scrollRect.
import flash.display.*;
import flash.geom.*;

[SWF(width="240", height="160", backgroundColor="#FFFFFF", frameRate="30")]
public class Test extends MovieClip {
    public function Test() {
        var g:Graphics;
        var s:Shape;
        // Row 0: fills. Diamond (45 deg edges), slope-2 triangle,
        // rects at x/y offsets .0 .25 .5 .75.
        s = shape(0, 0); g = s.graphics;
        g.beginFill(0xFF0000); g.moveTo(20, 2); g.lineTo(38, 20); g.lineTo(20, 38); g.lineTo(2, 20); g.endFill();
        s = shape(40, 0); g = s.graphics;
        g.beginFill(0x0000FF); g.moveTo(5, 2); g.lineTo(15, 38); g.lineTo(35, 2); g.endFill();
        var offs:Array = [0.0, 0.25, 0.5, 0.75];
        for (var i:int = 0; i < 4; i++) {
            s = shape(80 + i * 40, 0); g = s.graphics;
            g.beginFill(0x008000); g.drawRect(5 + offs[i], 5 + offs[i], 20, 20); g.endFill();
        }
        // Row 1: strokes, widths 1 / 2 / 4 / hairline(0) at x.0 and x.5.
        var widths:Array = [1, 2, 4, 0];
        for (i = 0; i < 4; i++) {
            s = shape(i * 40, 40); g = s.graphics;
            g.lineStyle(widths[i], 0x000000);
            g.drawRect(5, 5, 12, 25);
            g.drawRect(22.5, 5.5, 12, 25);
        }
        s = shape(160, 40); g = s.graphics;
        g.lineStyle(3, 0x000000); g.drawCircle(20, 20, 13);
        s = shape(200, 40); g = s.graphics;
        g.lineStyle(2, 0x000000); g.moveTo(3, 3); g.lineTo(37, 20); g.lineTo(3, 37);
        // Row 2: gradients. Horizontal linear, vertical linear, radial, focal.
        var m:Matrix = new Matrix();
        s = shape(0, 80); g = s.graphics; m.createGradientBox(32, 32, 0, 4, 4);
        g.beginGradientFill(GradientType.LINEAR, [0x000000, 0xFFFFFF], [1, 1], [0, 255], m);
        g.drawRect(4, 4, 32, 32); g.endFill();
        s = shape(40, 80); g = s.graphics; m = new Matrix(); m.createGradientBox(32, 32, Math.PI / 2, 4, 4);
        g.beginGradientFill(GradientType.LINEAR, [0x000000, 0xFFFFFF], [1, 1], [0, 255], m);
        g.drawRect(4, 4, 32, 32); g.endFill();
        s = shape(80, 80); g = s.graphics; m = new Matrix(); m.createGradientBox(32, 32, 0, 4, 4);
        g.beginGradientFill(GradientType.RADIAL, [0xFF0000, 0x0000FF], [1, 1], [0, 255], m);
        g.drawRect(4, 4, 32, 32); g.endFill();
        s = shape(120, 80); g = s.graphics; m = new Matrix(); m.createGradientBox(32, 32, 0, 4, 4);
        g.beginGradientFill(GradientType.RADIAL, [0xFF0000, 0x0000FF], [1, 1], [0, 255], m, SpreadMethod.REPEAT, "rgb", 0.6);
        g.drawRect(4, 4, 32, 32); g.endFill();
        // Row 3: non-smoothed bitmap (4x4 checker scaled x4) at x.0 / x.5,
        // unfiltered cacheAsBitmap shape at (x.5, y.5), scrollRect at .5.
        var bd:BitmapData = new BitmapData(8, 8, false, 0xFFFFFF);
        for (var y:int = 0; y < 8; y++) for (var x:int = 0; x < 8; x++)
            if (((x + y) & 1) == 0) bd.setPixel(x, y, 0xFF00FF);
        var b:Bitmap = new Bitmap(bd); b.scaleX = b.scaleY = 4; b.x = 164; b.y = 124; addChild(b);
        b = new Bitmap(bd); b.scaleX = b.scaleY = 4; b.x = 200.5; b.y = 124.5; addChild(b);
        s = shape(0, 120); g = s.graphics;
        g.beginFill(0x00AAFF); g.drawRect(0, 0, 25, 25); g.endFill();
        s.x = 7.5; s.y = 127.5; s.cacheAsBitmap = true;
        s = shape(40, 120); g = s.graphics;
        g.beginFill(0xFFAA00); g.drawRect(0, 0, 60, 60); g.endFill();
        g.beginFill(0x000000); g.drawRect(10, 10, 5, 5); g.endFill();
        s.x = 47.5; s.y = 127.5; s.scrollRect = new Rectangle(4.5, 4.5, 25, 25);
        s = shape(80, 120); g = s.graphics;
        g.beginBitmapFill(bd, new Matrix(4, 0, 0, 4, 0.5, 0.5), true, false);
        g.drawRect(2, 2, 34, 34); g.endFill();
        s = shape(120, 120); g = s.graphics;
        g.beginBitmapFill(bd, new Matrix(3, 1, -1, 3, 10, 0), true, false);
        g.drawRect(2, 2, 34, 34); g.endFill();
    }
    private function shape(x:Number, y:Number):Shape {
        var s:Shape = new Shape(); s.x = x; s.y = y; addChild(s); return s;
    }
}
}
