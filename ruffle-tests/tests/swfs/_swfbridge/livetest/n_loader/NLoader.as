// NLoader.as — injected level loader for recompiled "N" (Metanet, the way of
// the ninja). Increment 1: load a SPECIFIC level and DETECT completion,
// headless, with NO input demo (the bundled demos die partway and never reach
// the exit).
//
// Pipeline (same as ../dj_probe / ../dj_loader): MTASC -> extract_bytecode.py
// -> inject_tracer.py (splice before N's first ShowFrame) -> recompile native.
//
// How it works (all N globals live on _root; reach them through an untyped
// Object `r` so MTASC's typed MovieClip doesn't reject the dynamic calls):
//   1. Wait for N to finish booting (InitApp -> AppBuildModules builds the
//      modules; `gamedata` is the LAST module built, so `r.gamedata != null`
//      means boot is done), then settle a few ticks.
//   2. game.InitNewGame(); App_LoadLevel_Raw(FIXTURE, onLoaded) — loads our raw
//      level string. N's own RunApp drives the multi-frame load; onLoaded is
//      N's LEVEL_LOADED_CALLBACK, fired when the map+objects are in.
//   3. onLoaded: App_PlayGame() (enters App_Tick_RunningGame, the only state
//      that ticks physics + collisions), then OVERRIDE App_LevelPassedEvent
//      with a wrapper that traces N_COMPLETE and chains to N's normal handler.
//   4. The player auto-falls (GRAV=0.15, very gentle) through the exit's
//      SWITCH (opens the door) then the DOOR -> ExitObject.PlayerHitExit ->
//      App_LevelPassedEvent -> our wrapper fires. No gold, no input, no ground.
//
// Level string format (decoded from N): levStr = mapStr "|" objStr
//   mapStr: 31*23 = 713 chars, one per tile, column-major; tile state =
//           charCode - 48, so "0" = empty (TID_EMPTY). All-empty here.
//   objStr: objects joined by "!", each "<type>^<num,num,...>".
//           PLAYER=5 [x,y];  EXIT=11 [doorX,doorY, switchX,switchY];  GOLD=0 [x,y].
// Pixel convention: tile (col,row) center = col*24+12, row*24+12. We stack the
// spawn, switch and door within a few px of each other near (372,~110) so the
// switch and door radii (player.r~10 + switch.r~6 / door.r~12) overlap the slow
// fall path and completion fires within a couple of ticks.

class NLoader {
	static var DEPTH:Number = 1048570;
	static var MAX:Number = 300;     // hard frame cap (quit even if stuck)
	static var SETTLE:Number = 6;    // ticks to wait after boot before loading

	// Fixture: empty map, spawn just above an exit whose switch sits above its
	// door, all on the same x so a straight fall passes through both.
	static var SPAWN:String = "5^372,100";
	static var EXIT:String  = "11^372,124,372,110"; // door (372,124), switch (372,110)

	static var tick:Number = 0;
	static var bootTick:Number = 0;   // tick at which boot-ready was first seen
	static var phase:String = "wait"; // wait -> load -> run -> done
	static var completed:Boolean = false;
	static var r:Object;              // = _root, untyped for dynamic access

	static function main(mc:MovieClip):Void {
		r = _root;
		trace("[nloader] start");
		var clip:MovieClip = _root.createEmptyMovieClip("__nloader__", DEPTH);
		clip.onEnterFrame = function():Void { NLoader.tickFn(); };
	}

	static function buildLevel():String {
		var map:String = "";
		var i:Number = 0;
		while (i < 713) { map += "0"; i++; }   // 31 * 23 empty tiles
		return map + "|" + SPAWN + "!" + EXIT;
	}

	static function tickFn():Void {
		tick++;

		if (phase == "wait") {
			// gamedata is built last; its presence means all modules are up.
			if (r.gamedata != null && r.game != null
			    && r.App_LoadLevel_Raw != undefined) {
				if (bootTick == 0) {
					bootTick = tick;
					trace("[nloader] boot-ready at tick " + tick + ", settling");
				}
				if (tick - bootTick >= SETTLE) {
					startLoad();
				}
			}
		} else if (phase == "run") {
			// Heartbeat: watch the fall + completion.
			var p:Object = r.player;
			trace("NT" + tick + " phase=run x=" + p.pos.x + " y=" + p.pos.y
			      + " dead=" + p.isDead + " done=" + completed);
			if (completed) {
				trace("[nloader] level complete -> quitting");
				phase = "done";
				fscommand("quit", "");
				return;
			}
			if (p.isDead) {
				trace("[nloader] PLAYER DIED before exit (fixture too far?) -> quitting");
				phase = "done";
				fscommand("quit", "");
				return;
			}
		}

		if (tick >= MAX && phase != "done") {
			trace("[nloader] MAX ticks reached, phase=" + phase
			      + " completed=" + completed + " -> quitting");
			phase = "done";
			fscommand("quit", "");
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
		// App_PlayGame sets up game-time / demo recording and SetActiveProcess(
		// App_Tick_RunningGame); reuse it, then swap in our completion hook.
		r.App_PlayGame();
		// App_PlayGame set App_LevelPassedEvent = App_LevelPassedEvent_Normal.
		// Override the pointer with a wrapper; chain to the (untouched) _Normal
		// through r so MTASC's typed dispatch doesn't reject the dynamic call.
		r.App_LevelPassedEvent = function():Void {
			NLoader.completed = true;
			trace("N_COMPLETE tick=" + NLoader.tick);
			NLoader.r.App_LevelPassedEvent_Normal();
		};
		phase = "run";
	}
}
