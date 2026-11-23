// Collector UAF lock (s26 n-collector-uaf): a clip removed by
// removeMovieClip() (no onUnload) is evicted from the MovieClip registry,
// so the Stage-3 collector stops rooting its dynamic_props -- but the dead
// clip kept pointing at them. A user variable still holding the dead clip
// then read freed memory after the next collection (N's retry reset +
// for..in over _root clips). Flash/Ruffle: the dangling reference has no
// members, so for..in enumerates nothing and member reads are undefined.
class Test {
	static var f:Number = 0;
	static function main(mc) {
		_root.createEmptyMovieClip("holder", 1);
		_root.holder.createEmptyMovieClip("stick", 1);
		_root.holder.stick.payload = {a: 1, b: [1, 2, 3]};
		_root.holder.stick.label = "s";
		_root.keep = _root.holder.stick;      // user var: dangling after removal
		var o = new Object();
		o.clip = _root.holder.stick;          // object slot: same
		_root.box = o;
		trace("before: " + typeof(_root.keep) + " " + _root.keep.label);
		_root.holder.stick.removeMovieClip();
		trace("removed: " + typeof(_root.keep) + " " + _root.keep.label);
		// Self-removal inside the clip's own handler: same-tick reads through
		// `this` (and a local) still see the props in Ruffle.
		_root.createEmptyMovieClip("self", 2);
		_root.self.tag = "t";
		_root.self.onEnterFrame = function() {
			var me = this;
			this.removeMovieClip();
			var c = 0;
			for (var k in me) c++;
			trace("self after removal: tag=" + this.tag + " local=" + me.tag + " c=" + c);
			_root.selfKeep = me;
		};
		_root.onEnterFrame = function() {
			Test.f++;
			// The default collector runs every 60 ticks: enumerate the dead
			// clip on both sides of several collections.
			if (Test.f % 20 == 0) {
				var n = 0;
				for (var k in _root.keep) n++;
				var m = 0;
				for (var k2 in _root.box.clip) m++;
				trace("f=" + Test.f + " keep=" + typeof(_root.keep) + " n=" + n + " m=" + m +
					" label=" + _root.keep.label + " payload=" + _root.box.clip.payload +
					" self=" + _root.selfKeep.tag);
			}
			if (Test.f == 200) trace("done");
		};
	}
}
