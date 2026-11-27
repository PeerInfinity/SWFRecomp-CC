class Test { static function main(mc) {
 var c:MovieClip = _root.createEmptyMovieClip("c", 1);
 var rs:Array = [30, 45, 90, -90, 180];
 for (var i = 0; i < rs.length; i++) { c._rotation = rs[i]; var m = c.transform.matrix; trace("rot " + rs[i] + ": " + m.a + " " + m.b + " " + m.c + " " + m.d + " | " + m.toString()); }
 c._rotation = 0; c._yscale = -100; var m2 = c.transform.matrix; trace("yscale-100: " + m2.toString());
 trace("_rotation=" + c._rotation + " _xscale=" + c._xscale + " _yscale=" + c._yscale);
} }
