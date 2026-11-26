// s28 n-stroke-snap: drawing-API strokes, widths x subpixel offsets (rows = widths, cols = offsets)
class Test {
  static function main() {
    var widths = [0, 0.5, 1, 1.1, 1.2, 1.5, 2, 2.25, 3, 4];
    var offs = [0, 0.1, 0.25, 0.4, 0.5, 0.6, 0.75, 0.9];
    var mc = _root.createEmptyMovieClip("g", 1);
    for (var r = 0; r < widths.length; r++) {
      for (var c = 0; c < offs.length; c++) {
        var x = 10 + c * 26 + offs[c], y = 10 + r * 20 + offs[c];
        mc.lineStyle(widths[r], 0x000000, 100);
        mc.moveTo(x, y); mc.lineTo(x + 16, y); mc.lineTo(x + 16, y + 10); mc.lineTo(x, y + 10); mc.lineTo(x, y);
      }
    }
    var h = _root.createEmptyMovieClip("h", 2);
    for (var r = 0; r < widths.length; r++) {
      for (var c = 0; c < offs.length; c++) {
        var x = 230 + c * 26 + offs[c], y = 10 + r * 20 + offs[c];
        h.lineStyle(widths[r], 0x000000, 100, true);
        h.moveTo(x, y); h.lineTo(x + 16, y); h.lineTo(x + 16, y + 10); h.lineTo(x, y + 10); h.lineTo(x, y);
      }
    }
    trace("drawn");
  }
}
