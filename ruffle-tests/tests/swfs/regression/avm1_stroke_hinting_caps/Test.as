// s29 n-seam-caps: pixelHinting W = 4/5/6 snapped corners + caps (AVM1 drawing API).
// Rows: per width, 4 shapes (L corner RD, L corner DL, cap R, cap D); cols: 16 (qx, qy) quarter-px offsets.
class Test {
  static function main() {
    var ws = [4, 5, 6];
    var mc = _root.createEmptyMovieClip("g", 1);
    var row = 0;
    for (var i = 0; i < ws.length; i++) {
      for (var s = 0; s < 4; s++) {
        for (var q = 0; q < 16; q++) {
          var x = 14 + q * 24 + (q % 4) * 0.25, y = 14 + row * 24 + Math.floor(q / 4) * 0.25;
          mc.lineStyle(ws[i], 0x000000, 100, true);
          if (s == 0) { mc.moveTo(x - 10, y); mc.lineTo(x, y); mc.lineTo(x, y + 10); }
          else if (s == 1) { mc.moveTo(x, y - 10); mc.lineTo(x, y); mc.lineTo(x - 10, y); }
          else if (s == 2) { mc.moveTo(x, y); mc.lineTo(x + 10, y); }
          else { mc.moveTo(x, y); mc.lineTo(x, y + 10); }
        }
        row++;
      }
    }
    trace("drawn");
  }
}
