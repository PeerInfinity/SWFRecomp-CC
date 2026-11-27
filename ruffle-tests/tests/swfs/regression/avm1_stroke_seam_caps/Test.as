// s29 n-seam-caps: closed rects under every caps x joints combination (rows 0-8: caps
// none/square/round x joints round/miter/bevel, moveTo + 4 lineTo), then fill-AUTO-closed
// rects (moveTo + 3 lineTo inside beginFill/endFill; row 9 round/round, row 10 none/miter).
// Columns: W = 1/2/3 px x offsets 0 / 0.5 / 0.25.
// Flash: the seam is two CAPS when snapping moves the two seam endpoints apart, else a JOIN;
// an auto-closed seam behaves like an explicit one.
class Test {
  static function main() {
    var caps = ["none", "square", "round", "round", "none"];
    var joints = ["round", "miter", "bevel"];
    var ws = [1, 2, 3];
    var offs = [0, 0.5, 0.25];
    var mc = _root.createEmptyMovieClip("g", 1);
    for (var row = 0; row < 11; row++) {
      var cap = row < 9 ? caps[Math.floor(row / 3)] : caps[row - 6];
      var joint = row < 9 ? joints[row % 3] : (row == 9 ? "round" : "miter");
      var col = 0;
      for (var i = 0; i < ws.length; i++) {
        for (var j = 0; j < offs.length; j++) {
          var x = 10 + col * 30 + offs[j], y = 10 + row * 24 + offs[j];
          mc.lineStyle(ws[i], 0x000000, 100, false, "normal", cap, joint, 3);
          if (row >= 9) mc.beginFill(0xFFFFFF, 100);
          mc.moveTo(x, y); mc.lineTo(x + 16, y); mc.lineTo(x + 16, y + 12); mc.lineTo(x, y + 12);
          if (row < 9) mc.lineTo(x, y);
          if (row >= 9) mc.endFill();
          col++;
        }
      }
    }
    trace("drawn");
  }
}
