package {
  import flash.display.*; import flash.events.*;
  [SWF(width="400", height="300", frameRate="30")]
  public class Test extends Sprite {
    private var f:int = 0; private var s:Sprite, s2:Sprite, s3:Sprite, m1:Shape, m2:Shape, m3:Shape, holder:Sprite;
    private function box(c:uint):Sprite { var x:Sprite = new Sprite(); x.graphics.beginFill(c); x.graphics.drawRect(0,0,50,50); addChild(x); return x; }
    private function msk():Shape { var m:Shape = new Shape(); m.graphics.beginFill(0); m.graphics.drawRect(10,10,20,20); return m; }
    public function Test() {
      s = box(0xFF0000); s2 = box(0x00FF00); s3 = box(0x0000FF);
      m1 = msk(); addChild(m1); s.mask = m1;
      holder = new Sprite(); addChild(holder); m2 = msk(); holder.addChild(m2); s2.mask = m2;
      m3 = msk(); addChild(m3); s3.mask = m3;
      trace("f0 " + (s.mask == m1) + " " + (s2.mask == m2) + " " + (s3.mask == m3));
      addEventListener(Event.ENTER_FRAME, tick);
    }
    private function tick(e:Event):void {
      f++;
      if (f == 1) { removeChild(m1); trace("removeChild direct: s.mask=" + s.mask + " m1.parent=" + m1.parent); }
      if (f == 2) { removeChild(holder); trace("removeChild ancestor: s2.mask=" + s2.mask); }
      if (f == 3) { m3.visible = false; trace("hidden: " + (s3.mask == m3)); addChild(m1); trace("re-add m1: s.mask=" + s.mask); }
      if (f == 4) { removeEventListener(Event.ENTER_FRAME, tick); trace("done"); }
    }
  }
}
