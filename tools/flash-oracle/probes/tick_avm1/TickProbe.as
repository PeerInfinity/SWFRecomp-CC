// AVM1 tick-alignment probe: frame 1 traces "tick 1" and draws bar 1; every
// onEnterFrame afterwards traces "tick N" and draws bar N.
class TickProbe {
    static var n:Number = 0;
    static function bar():Void {
        n++;
        trace("tick " + n);
        var x:Number = (n - 1) * 12 + 4;
        _root.beginFill(0x2040C0, 100);
        _root.moveTo(x, 4); _root.lineTo(x + 8, 4); _root.lineTo(x + 8, 40); _root.lineTo(x, 40); _root.lineTo(x, 4);
        _root.endFill();
    }
    static function main(mc):Void {
        bar();
        _root.onEnterFrame = function() { TickProbe.bar(); };
    }
}
