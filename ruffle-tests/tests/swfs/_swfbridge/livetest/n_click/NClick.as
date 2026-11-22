// NClick.as - probe for N's "play game" click. Logs menuMC frame; at tick 60
// calls the game's own handlers directly (no wrappers). See README.md.
class NClick {
	static var DEPTH:Number = 1048571;
	static var tick:Number = 0;
	static var lastFrm:Number = -1;
	static var r:Object;
	static function main(mc:MovieClip):Void {
		r = _root;
		var clip:MovieClip = _root.createEmptyMovieClip("__nclick__", DEPTH);
		clip.onEnterFrame = function():Void { NClick.tickFn(); };
		clip.onMouseDown = function():Void { trace("NC mdown t=" + NClick.tick + " x=" + _root._xmouse + " y=" + _root._ymouse); };
		clip.onMouseUp = function():Void { trace("NC mup t=" + NClick.tick + " x=" + _root._xmouse + " y=" + _root._ymouse); };
	}
	static function cf():String { var m:Object = r.gui.menuMC; return "cf=" + m._currentframe + " vis=" + m._visible; }
	static function tickFn():Void {
		tick++;
		if (tick == 60) {
			trace("NC A " + cf());
			r.App_StartPlayMenu();
			trace("NC B after App_StartPlayMenu " + cf());
			r.gui.Display(r.GUI_MAINMENU);
			trace("NC C after Display(MAINMENU) " + cf());
			r.gui.Display(r.GUI_PLAYMENU);
			trace("NC D after Display(PLAYMENU) " + cf());
			r.gui.DisplayFrame("main_menu");
			trace("NC E after DisplayFrame(main_menu) " + cf());
			r.GUIEvent_MainMenu_PlayGame();
			trace("NC F after GUIEvent_MainMenu_PlayGame " + cf());
		}
		var m:Object = r.gui.menuMC;
		if (m != undefined && m._currentframe != lastFrm) {
			lastFrm = m._currentframe;
			trace("NC frame t=" + tick + " " + cf());
		}
	}
}
