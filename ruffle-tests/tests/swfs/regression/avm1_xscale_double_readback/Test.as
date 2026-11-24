class Test {
	static function main(mc) {
		_root.createEmptyMovieClip("m", 1);
		var vals = [82.99999999, 100 / 3, 50.123456789, 12.3456789012345, -7.77777777777, 99.9999999999];
		for (var i = 0; i < vals.length; i++) {
			_root.m._xscale = vals[i];
			_root.m._yscale = vals[i];
			trace("x " + _root.m._xscale + " floor " + Math.floor(_root.m._xscale) + " y " + _root.m._yscale);
		}
		_root.m._width = 0; _root.m._xscale = 82.99999999;
		trace("after _width: " + _root.m._xscale);
		_root.m._rotation = 30;
		trace("after rotation: " + _root.m._xscale + " " + Math.floor(_root.m._xscale));
	}
}
