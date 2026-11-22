// avm1_closure_base_clip_root_frame - functions defined by a ROOT frame-1
// script capture base_clip=_root, so a call fired from another clip's handler
// still reads free variables from _root's timeline (SWF6+ closure switch).
// Browser-WASM ran root frame 1 with g_current_context=NULL, so every such
// function captured base_clip=NULL, never switched, and read LIMIT from the
// CALLER's clip (undefined). N's "play game": gui.Display(GUI_PLAYMENU) saw
// GUI_LAST_STRING_INDEX undefined. Fixed in swf.c (context set before tagMain
// in every graphics build). eval("X") compiles to a bare GetVariable.
// Expected output: Ruffle exporter (see create_test_swf.sh).
class Test {
	static function main(mc) {
		_root.LIMIT = 17;
		_root.f = function(id) { trace("BC: fn " + id + " " + (eval("LIMIT") < id)); };
		_root.Gui = function() {};
		_root.Gui.prototype.Display = function(id) {
			trace("BC: method " + id + " " + (eval("LIMIT") < id) + " " + eval("LIMIT"));
		};
		_root.gui = new _root.Gui();
		var c = _root.createEmptyMovieClip("c", 1);
		c.onEnterFrame = function() {
			trace("BC: handler LIMIT=" + eval("LIMIT"));
			var g = eval("f");
			g(18);
			_root.f(18);
			_root.gui.Display(27);
			delete this.onEnterFrame;
			trace("BC: done");
		};
	}
}
