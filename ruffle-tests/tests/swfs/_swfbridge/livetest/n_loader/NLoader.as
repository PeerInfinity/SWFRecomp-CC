// NLoader.as - injected level loader for recompiled "N" (Metanet ninja).
// Loads a SPECIFIC level and DETECTS completion, headless. Pipeline like
// ../dj_probe: MTASC -> extract_bytecode.py -> inject_tracer.py -> recompile.
// Full design + decoded level/demo formats: README.md and
// SWFRecompDocs/status/2026-06-30-n-substrate-investigation.md.
// (Keep this header short: MTASC v8's SWF writer overflows zlib on long
//  comments - "zlib_deflate_end". Detail goes in the README, not here.)
class NLoader {
	static var DEPTH:Number = 1048570;
	static var MAX:Number = 400;     // hard frame cap (quit even if stuck)
	static var SETTLE:Number = 6;    // ticks to wait after boot before loading
	static var MODE:String = "walk"; // "walk" | "fall"

	// --- "fall" fixture: empty map, switch+door stacked just below spawn ----
	static var FALL_SPAWN:String = "5^372,100";
	static var FALL_EXIT:String  = "11^372,124,372,110"; // door(372,124) switch(372,110)

	// --- "walk" fixture: solid floor row, player walks right into switch/door -
	// Floor row mapY=14 (top surface pixel y = (14+1)*24 = 360), spanning
	// mapX 8..18. Player rests at y = 360 - player.r(10) = 350.
	static var FLOOR_Y:Number = 14;
	static var FLOOR_X0:Number = 8;
	static var FLOOR_X1:Number = 18;
	static var WALK_SPAWN:String = "5^276,350";
	static var WALK_EXIT:String  = "11^310,350,294,350"; // door(310) switch(294), y=350
	// 28 ticks of "hold right" (4 packed entries). ~13 ticks reach the door.
	static var WALK_DEMO:String = "28:35791394|35791394|35791394|35791394";

	static var tick:Number = 0;
	static var bootTick:Number = 0;
	static var phase:String = "wait"; // wait -> load -> run -> done
	static var completed:Boolean = false;
	static var r:Object;

	static function main(mc:MovieClip):Void {
		r = _root;
		trace("[nloader] start mode=" + MODE);
		var clip:MovieClip = _root.createEmptyMovieClip("__nloader__", DEPTH);
		clip.onEnterFrame = function():Void { NLoader.tickFn(); };
	}

	static function noop():Void {}   // parks N's active process while we drive ticks

	static function buildLevel():String {
		if (MODE == "fall") {
			var empty:String = "";
			var n:Number = 0;
			while (n < 713) { empty += "0"; n++; }   // 31*23 empty tiles
			return empty + "|" + FALL_SPAWN + "!" + FALL_EXIT;
		}
		// "walk": floor row of solid tiles, else empty (X-outer, Y-inner order).
		var map:String = "";
		var mx:Number = 0;
		while (mx < 31) {
			var my:Number = 0;
			while (my < 23) {
				if (my == FLOOR_Y && mx >= FLOOR_X0 && mx <= FLOOR_X1) map += "1";
				else map += "0";
				my++;
			}
			mx++;
		}
		return map + "|" + WALK_SPAWN + "!" + WALK_EXIT;
	}

	static function tickFn():Void {
		tick++;

		if (phase == "wait") {
			if (r.gamedata != null && r.game != null
			    && r.App_LoadLevel_Raw != undefined) {
				if (bootTick == 0) {
					bootTick = tick;
					trace("[nloader] boot-ready at tick " + tick + ", settling");
				}
				if (tick - bootTick >= SETTLE) startLoad();
			}
		} else if (phase == "run") {
			r.game.Tick();   // one deterministic sim step
			var p:Object = r.player;
			trace("NT" + tick + " gt=" + r.game.GetTime()
			      + " x=" + p.pos.x + " y=" + p.pos.y
			      + " dead=" + p.isDead + " done=" + completed);
			if (completed) {
				trace("[nloader] level complete -> quitting");
				phase = "done"; fscommand("quit", ""); return;
			}
			if (p.isDead) {
				trace("[nloader] PLAYER DIED before exit -> quitting");
				phase = "done"; fscommand("quit", ""); return;
			}
		}

		if (tick >= MAX && phase != "done") {
			trace("[nloader] MAX ticks reached, phase=" + phase
			      + " completed=" + completed + " -> quitting");
			phase = "done"; fscommand("quit", "");
		}
	}

	static function startLoad():Void {
		phase = "load";
		var lev:String = buildLevel();
		trace("[nloader] loading raw level (" + lev.length + " chars)");
		r.game.InitNewGame();
		r.App_LoadLevel_Raw(lev, NLoader.onLoaded);
	}

	static function onLoaded():Void {
		trace("[nloader] level loaded -> entering running state");
		// Set up the running state by hand (App_PlayGame's wall-clock loop would
		// starve game.Tick()), install the completion hook, optionally start the
		// walk demo, then park N's process and drive ticks from tickFn().
		r.gui.HideAll();
		r.game.InitRetryLevel();
		r.App_PlayerDeathEvent = r.App_PlayerDeathEvent_Normal;
		r.App_LevelPassedEvent = function():Void {
			NLoader.completed = true;
			trace("N_COMPLETE tick=" + NLoader.tick);
			NLoader.r.App_LevelPassedEvent_Normal();
		};
		if (MODE == "walk") {
			r.game.LoadDemo(WALK_DEMO);
			r.game.StartDemoPlayback();
		}
		r.SetActiveProcess(NLoader.noop);
		phase = "run";
	}
}
