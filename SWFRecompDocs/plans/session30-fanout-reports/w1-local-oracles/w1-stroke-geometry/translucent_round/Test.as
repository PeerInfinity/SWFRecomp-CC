package {
  import flash.display.*;
  [SWF(width="300", height="200", backgroundColor="#FFFFFF", frameRate="30")]
  public class Test extends Sprite {
    public function Test() {
      var a:Shape = new Shape(); a.graphics.lineStyle(10, 0xFF0000, 0.5); a.graphics.drawRect(20, 20, 80, 40); addChild(a);
      var b:Shape = new Shape(); b.graphics.lineStyle(10, 0xFF0000, 0.5); b.graphics.drawCircle(200, 60, 35); addChild(b);
      var c:Shape = new Shape(); c.graphics.lineStyle(10, 0x0000FF, 0.5); c.graphics.drawRoundRect(20, 110, 120, 60, 30, 30); addChild(c);
      var d:Shape = new Shape(); d.graphics.lineStyle(20, 0x00AA00, 0.5); d.graphics.drawEllipse(170, 110, 100, 60); addChild(d);
      trace("ok");
    }
  }
}
