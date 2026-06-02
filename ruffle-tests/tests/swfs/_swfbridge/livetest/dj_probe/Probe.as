// Probe.as — THROWAWAY injected-AS feasibility probe for Doodle Jump.
//
// Compiled by MTASC, its DoAction/DoInitAction tags extracted and spliced into
// Doodle_Jump test.swf (before the first ShowFrame) by inject_tracer.py. Runs
// under three runtimes: Ruffle (ground truth), SWFRecomp native graphics
// (headless), SWFRecomp WASM (browser). Output is via trace() so it reaches the
// console/stdout on all three.
//
// The MODE static selects which experiment runs (set by editing this constant,
// rebuilding, and re-running). All modes first FORCE gameplay from the menu via
// _root.gotoAndPlay(2): the PLAY button's Release handler (clip_actions_148) is
// `_root.gotoAndPlay(2)` and frame 2 is the gameplay frame (frame 6 is the INFO
// screen — that button is clip_actions_147). Forcing the goto reaches the
// gameplay object graph without needing a button click, which matters because
// the headless native build doesn't hit-test the menu buttons.
//
//   "observe" : dump the live object graph each tick (Q1/Q3 readability)
//   "write"   : Q2 — write powerup/physics vars and read them back
//   "place"   : Q4 — force one platform (block_N) to a known position / type
//   "perceive": Q5 — dump hero._x + nearby block positions each tick
//   "steer"   : Q5 — directly set hero._x toward a target each tick (AS steer)

class Probe {
	static var MODE:String = "observe";
	static var MAX:Number = 400;
	// FORCE_GOTO: if > 0, _root.gotoAndPlay(FORCE_GOTO) at START_GAMEPLAY_TICK to
	// reach a frame without a click. 0 = observe only (drive the menu via a real
	// click in the harness). NOTE: gotoAndPlay(6) was found to be the INFO screen,
	// not gameplay — the play button is driven by click instead.
	static var FORCE_GOTO:Number = 2;
	static var START_GAMEPLAY_TICK:Number = 2;
	static var tick:Number = 0;
	static var started:Boolean = false;

	static function main(mc:MovieClip):Void {
		trace("PROBE: start mode=" + MODE + " _currentframe=" + _root._currentframe);
		var clip:MovieClip = _root.createEmptyMovieClip("__probe__", 1048570);
		clip.onEnterFrame = function():Void { Probe.tickFn(); };
	}

	static function tickFn():Void {
		tick++;

		if (FORCE_GOTO > 0 && tick == START_GAMEPLAY_TICK && !started) {
			started = true;
			trace("PROBE: forcing _root.gotoAndPlay(" + FORCE_GOTO + ")");
			_root.gotoAndPlay(FORCE_GOTO);
		}

		trace("PF" + tick + " rootcf=" + _root._currentframe);

		if (MODE == "observe")       observe();
		else if (MODE == "write")    writeExp();
		else if (MODE == "place")    placeExp();
		else if (MODE == "perceive") perceive();
		else if (MODE == "steer")    steer();
		else if (MODE == "keyspy")   keyspy();

		if (tick >= MAX) {
			trace("PROBE: done");
			fscommand("quit", "");
		}
	}

	// ---- Q1/Q3: read the live object graph -------------------------------
	static function observe():Void {
		var names:Array = [];
		for (var n:String in _root) {
			if (n == "__probe__") continue;
			names.push(n);
		}
		names.sort();
		for (var i:Number = 0; i < names.length; i++) {
			var k:String = names[i];
			var v = _root[k];
			var t:String = typeof(v);
			var line:String = "PF" + tick + " root." + k + " : " + t;
			if (t == "number" || t == "string" || t == "boolean") line += " = " + v;
			trace(line);
		}
		report("container"); report("hero"); report("scores"); report("score");
		report("gameOver"); report("gameover"); report("score_txt"); report("attachBlocks");
		// Enumerate the HERO clip's own props (score/physics/powerups live here,
		// declared via `var` in the hero LOAD handler clip_action_28).
		var h = _root.hero;
		if (typeof(h) == "movieclip") {
			var hn:Array = [];
			for (var hk:String in h) hn.push(hk);
			hn.sort();
			for (var hi:Number = 0; hi < hn.length; hi++) {
				var hkey:String = hn[hi];
				var hv = h[hkey];
				var ht:String = typeof(hv);
				var hl:String = "PF" + tick + " hero." + hkey + " : " + ht;
				if (ht == "number" || ht == "string" || ht == "boolean") hl += " = " + hv;
				else if (ht == "movieclip") hl += " _x=" + hv._x + " _y=" + hv._y;
				trace(hl);
			}
		}
		// If container exists, enumerate its children + key own props.
		var c = _root.container;
		if (typeof(c) == "movieclip") {
			var cn:Array = [];
			for (var m:String in c) cn.push(m);
			cn.sort();
			for (var j:Number = 0; j < cn.length; j++) {
				var ck:String = cn[j];
				var cv = c[ck];
				var ct:String = typeof(cv);
				var cl:String = "PF" + tick + " container." + ck + " : " + ct;
				if (ct == "number" || ct == "string" || ct == "boolean") cl += " = " + cv;
				else if (ct == "movieclip") cl += " _x=" + cv._x + " _y=" + cv._y;
				trace(cl);
			}
		}
	}

	static function report(path:String):Void {
		var v = _root[path];
		var t:String = typeof(v);
		var line:String = "PF" + tick + " probe _root." + path + " : " + t;
		if (t == "number" || t == "string" || t == "boolean") line += " = " + v;
		else if (t == "movieclip") line += " _x=" + v._x + " _y=" + v._y + " _cf=" + v._currentframe;
		trace(line);
	}

	// ---- Q2: write powerup/physics state, read back ----------------------
	static function writeExp():Void {
		var h = _root.hero;
		if (typeof(h) != "movieclip") { trace("PF" + tick + " write: hero not ready"); return; }
		trace("PF" + tick + " state vy=" + h.vy + " gravity=" + h.gravity
		      + " maxjump=" + h.maxjump + " jumpspeed=" + h.jumpspeed
		      + " jetpack=" + h.jetpack + " move_inversed=" + h.move_inversed
		      + " _y=" + h._y + " score=" + h.score + " gameOver=" + _root.gameOver);
		if (tick == 10) {
			trace("PF" + tick + " WRITE jetpack=true maxjump=60 jumpspeed=40 gravity=1 vy=-40");
			h.jetpack = true; h.maxjump = 60; h.jumpspeed = 40; h.gravity = 1; h.vy = -40;
			trace("PF" + tick + " READBACK jetpack=" + h.jetpack + " maxjump=" + h.maxjump
			      + " jumpspeed=" + h.jumpspeed + " gravity=" + h.gravity + " vy=" + h.vy);
		}
		if (tick == 14) {
			trace("PF" + tick + " WRITE score=4242 (grant score)");
			h.score = 4242;
			trace("PF" + tick + " READBACK score=" + h.score + " score_txt.text=" + _root.score_txt.text);
		}
		if (tick == 30) {
			trace("PF" + tick + " WRITE _root.gameOver=true (force completion)");
			_root.gameOver = true;
			trace("PF" + tick + " READBACK gameOver=" + _root.gameOver);
		}
	}

	// ---- Q4: force one platform to a known position / type ---------------
	static function placeExp():Void {
		var c = _root.container;
		if (typeof(c) != "movieclip") { trace("PF" + tick + " place: container not ready"); return; }
		var b0 = c.block_0;
		trace("PF" + tick + " place block_0 _x=" + b0._x + " _y=" + b0._y
		      + " attr0=" + c.attribute[0] + " attr1=" + c.attribute[1]);
		if (tick == 10) {
			trace("PF" + tick + " PLACE force block_0 -> (120,300); attribute[1]=1 (spring)");
			c.block_0._x = 120; c.block_0._y = 300;
			c.attribute[1] = 1;
			trace("PF" + tick + " READBACK block_0 _x=" + c.block_0._x + " _y=" + c.block_0._y
			      + " attr1=" + c.attribute[1]);
		}
		if (tick > 10 && tick <= 13) {
			// re-assert each tick: the game's onEnterFrame may move blocks; show
			// whether our override sticks against the running placement loop.
			c.block_0._x = 120; c.block_0._y = 300;
			trace("PF" + tick + " block_0 now _x=" + c.block_0._x + " _y=" + c.block_0._y);
		}
		// Deeper Q4: intercept the placement CODE. Wrap the spawn loop + the
		// attachBlocks fn so our hook runs and can author/alter what is placed.
		if (tick == 15) {
			trace("PF" + tick + " HOOK installing wrappers on container.onEnterFrame + attachBlocks");
			c.__origOEF = c.onEnterFrame;
			c.onEnterFrame = function():Void {
				trace("HOOK container.onEnterFrame fired (lastBlockAttached=" + this.lastBlockAttached + ")");
				this.__origOEF();
			};
			if (typeof(c.attachBlocks) == "function") {
				c.__origAB = c.attachBlocks;
				c.attachBlocks = function():Void {
					trace("HOOK attachBlocks intercepted");
					this.__origAB();
				};
			}
		}
	}

	// ---- Q5: perception ---------------------------------------------------
	static function perceive():Void {
		var h = _root.hero;
		trace("PF" + tick + " perceive hero _x=" + h._x + " _y=" + h._y + " vy=" + h.vy);
		var c = _root.container;
		if (typeof(c) == "movieclip") {
			for (var m:String in c) {
				if (m.indexOf("block_") == 0) {
					var b = c[m];
					trace("PF" + tick + " block " + m + " _x=" + b._x + " _y=" + b._y);
				}
			}
		}
	}

	// ---- Q5: input path — does injected key input reach Key.isDown? -------
	// The probe reads Key.isDown(37/39) itself AND hero._x, so we see both that
	// the key state arrives and that DJ's own clip_action_29 moves the hero
	// (hero._x += 10 when Key.isDown(39)). Drive keys via the harness input.json
	// (native) / synthetic DOM keydown (browser).
	static function keyspy():Void {
		var h = _root.hero;
		var hx:String = (typeof(h) == "movieclip") ? ("" + h._x) : "NA";
		trace("PF" + tick + " keyspy k37=" + Key.isDown(37) + " k39=" + Key.isDown(39)
		      + " hero._x=" + hx);
	}

	// ---- Q5: AS-direct steer (set hero._x toward a moving target) ---------
	static function steer():Void {
		var h = _root.hero;
		if (typeof(h) != "movieclip") { trace("PF" + tick + " steer: hero not ready"); return; }
		// Target alternates left/right every 20 ticks; nudge hero._x toward it.
		var target:Number = ((Math.floor(tick / 20)) % 2 == 0) ? 60 : 180;
		var dx:Number = target - h._x;
		var step:Number = (dx > 0) ? 6 : -6;
		if (Math.abs(dx) < 6) step = dx;
		h._x = h._x + step;
		trace("PF" + tick + " steer target=" + target + " hero._x=" + h._x + " _y=" + h._y);
	}
}
