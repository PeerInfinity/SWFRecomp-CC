// Fixture for the AVM1 display-property coercion gate.
//
// Ruffle routes SetMember (`mc._x = v`), SetVariable-in-a-with-scope
// (`with(mc){ _x = v }`) and the SetProperty opcode through ONE gate
// (`property_coerce_to_number`, stage_object.rs) and ONE setter per property
// (`set_x`, `set_alpha`, ...). SWFRecomp had four separate implementations that
// disagreed. Every row below is a row where at least two of those paths, or one
// of them and Ruffle, used to differ.
//
// Guard values are deliberately DIFFERENT from the value under test (7 / 77)
// so a "no-op" outcome is distinguishable from a wrong-but-equal parse.
//
// Expected output captured from ~/CC/ruffle/target/release/exporter at
// f2aaf0703 (an oracle outside SWFRecomp), not from our own output.
class Test {
	static function main() {
		var m:MovieClip = _root.createEmptyMovieClip("m", 1);
		var inf = Number.POSITIVE_INFINITY;
		var ninf = Number.NEGATIVE_INFINITY;
		var undef;
		var s10x = "10x";
		var s25 = "25";
		var o = {};
		o.valueOf = function() { return 42; };

		trace("-- SetMember (mc._prop = v) --");
		m._x = 7; m._x = inf;    trace("_x inf: " + m._x);
		m._x = 7; m._x = ninf;   trace("_x -inf: " + m._x);
		m._y = 7; m._y = inf;    trace("_y inf: " + m._y);
		m._x = 7; m._x = undef;  trace("_x undefined: " + m._x);
		m._x = 7; m._x = null;   trace("_x null: " + m._x);
		m._x = 7; m._x = s10x;   trace("_x '10x': " + m._x);
		m._x = 7; m._x = s25;    trace("_x '25': " + m._x);
		m._x = 7; m._x = o;      trace("_x valueOf42: " + m._x);
		m._x = 7; m._x = -10.53; trace("_x -10.53: " + m._x);
		m._x = 7; m._x = 10.53;  trace("_x 10.53: " + m._x);
		m._alpha = 77; m._alpha = -5;    trace("_alpha -5: " + m._alpha);
		m._alpha = 77; m._alpha = 33.3;  trace("_alpha 33.3: " + m._alpha);
		m._alpha = 77; m._alpha = 12.5;  trace("_alpha 12.5: " + m._alpha);
		m._alpha = 77; m._alpha = inf;   trace("_alpha inf: " + m._alpha);
		m._alpha = 77; m._alpha = undef; trace("_alpha undefined: " + m._alpha);
		m._alpha = 77; m._alpha = s10x;  trace("_alpha '10x': " + m._alpha);
		m._visible = true; m._visible = inf;  trace("_visible inf: " + m._visible);
		m._rotation = 7; m._rotation = inf;   trace("_rotation inf: " + m._rotation);
		m._rotation = 7; m._rotation = undef; trace("_rotation undefined: " + m._rotation);
		m._xscale = 77; m._xscale = inf;      trace("_xscale inf: " + m._xscale);
		m._xscale = 77; m._xscale = s10x;     trace("_xscale '10x': " + m._xscale);

		trace("-- with(mc) { _prop = v } --");
		m._x = 7; with (m) { _x = inf; }     trace("_x inf: " + m._x);
		m._x = 7; with (m) { _x = undef; }   trace("_x undefined: " + m._x);
		m._x = 7; with (m) { _x = null; }    trace("_x null: " + m._x);
		m._x = 7; with (m) { _x = s10x; }    trace("_x '10x': " + m._x);
		m._x = 7; with (m) { _x = s25; }     trace("_x '25': " + m._x);
		m._x = 7; with (m) { _x = o; }       trace("_x valueOf42: " + m._x);
		m._alpha = 77; with (m) { _alpha = -5; }    trace("_alpha -5: " + m._alpha);
		m._alpha = 77; with (m) { _alpha = inf; }   trace("_alpha inf: " + m._alpha);
		m._alpha = 77; with (m) { _alpha = undef; } trace("_alpha undefined: " + m._alpha);
		m._alpha = 77; with (m) { _alpha = s10x; }  trace("_alpha '10x': " + m._alpha);
		m._visible = true; with (m) { _visible = inf; }   trace("_visible inf: " + m._visible);
		m._rotation = 7; with (m) { _rotation = undef; }  trace("_rotation undefined: " + m._rotation);
		m._xscale = 77; with (m) { _xscale = undef; }     trace("_xscale undefined: " + m._xscale);
	}
}
