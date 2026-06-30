// NLoader.as - injected level loader for recompiled "N" (Metanet ninja).
// Loads a SPECIFIC level and DETECTS completion. Pipeline like ../dj_probe:
// MTASC -> extract_bytecode.py -> inject_tracer.py -> recompile.
// Full design + decoded level/demo formats + the __swfBridge contract: README.md
// and SWFRecompDocs/status/2026-06-30-n-substrate-investigation.md.
// (Keep this header short: MTASC v8's SWF writer overflows zlib on long
//  comments - "zlib_deflate_end". Detail goes in the README, not here.)
class NLoader {
	static var DEPTH:Number = 1048570;
	static var MAX:Number = 1500;    // hard frame cap (quit even if stuck); queue needs headroom
	static var EI_WAIT:Number = 12;  // ticks to poll __swfConfig before fixture fallback
	static var MODE:String = "walk"; // fixture used when no EI host: "walk" | "fall"
	static var DONE:String = "__N_DONE__"; // __swfConfig sentinel: queue exhausted -> quit

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

	// Per-frame telemetry / event recording state.
	static var goldCount:Number = 0;
	static var switchOpen:Boolean = false;
	static var hooksInstalled:Boolean = false;

	// __swfBridge / ExternalInterface state. Inward config (level), outward exit.
	static var EI:Object;
	static var eiMode:Boolean = false;
	static var resolved:Boolean = false;   // config (EI or fixture) decided
	static var levelId:String = "fixture";
	static var levelStr:String = "";
	static var demoStr:String = "";        // "" => keyboard input (no demo playback)
	static var rawCfg:String = "";         // last __swfConfig string seen (queue dedup key)
	static var lastConfig:String = "";     // rawCfg of the level currently/last loaded
	static var levelsDone:Number = 0;      // count of completed levels this session

	static function main(mc:MovieClip):Void {
		r = _root;
		EI = flash.external.ExternalInterface;       // untyped: variadic call ok
		eiMode = (EI.available == true);
		trace("[nloader] start mode=" + MODE + " ei=" + eiMode);
		var clip:MovieClip = _root.createEmptyMovieClip("__nloader__", DEPTH);
		clip.onEnterFrame = function():Void { NLoader.tickFn(); };
	}

	static function noop():Void {}   // parks N's active process while we drive ticks

	// Build the baked fixture level string from MODE (no-EI fallback).
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

	// Host config string (from __swfConfig): "levelId\nlevStr\ndemoStr". Newline
	// is the only separator safe vs N's level chars ('0'..'Q', | ! ^ , :).
	static function parseConfig(cfg:String):Void {
		var parts:Array = cfg.split("\n");
		levelId  = (parts[0] != undefined) ? String(parts[0]) : "host";
		levelStr = (parts[1] != undefined) ? String(parts[1]) : "";
		demoStr  = (parts[2] != undefined) ? String(parts[2]) : "";
	}

	static function useFixture():Void {
		levelId = "fixture-" + MODE;
		levelStr = buildLevel();
		demoStr = (MODE == "walk") ? WALK_DEMO : "";
	}

	// One structured telemetry line per simulated frame. Parsed by n_record.mjs
	// into a JSON record. Velocity is Verlet (pos-oldpos = last step's motion);
	// st = curState (0 stand,1 run,2 skid,3 jump,4 fall,5 wallslide,6 ragdoll,
	// 7 celebrate); L/R/J/JT = input applied this tick (PINPUT_L/R/J/JTRIG).
	static function recordFrame():Void {
		var p:Object = r.player;
		var inp:Object = p.inputList;
		trace("NF t=" + tick + " gt=" + r.game.GetTime()
		      + " x=" + p.pos.x + " y=" + p.pos.y
		      + " vx=" + (p.pos.x - p.oldpos.x) + " vy=" + (p.pos.y - p.oldpos.y)
		      + " st=" + p.curState
		      + " air=" + (p.IN_AIR ? 1 : 0) + " wall=" + (p.NEAR_WALL ? 1 : 0)
		      + " jt=" + p.jumptimer + " face=" + p.facingDir
		      + " L=" + (inp[0] ? 1 : 0) + " R=" + (inp[1] ? 1 : 0)
		      + " J=" + (inp[2] ? 1 : 0) + " JT=" + (inp[3] ? 1 : 0)
		      + " gold=" + goldCount + " swon=" + (switchOpen ? 1 : 0)
		      + " dead=" + (p.isDead ? 1 : 0));
	}

	// Wrap N's gold-collect and exit-switch so they emit NEV events + counters,
	// chaining to the originals (via an untyped `self` to dodge MTASC's typed
	// `this` dispatch). Installed once, after the level is loaded.
	static function installHooks():Void {
		if (hooksInstalled) return;
		hooksInstalled = true;
		var GO:Object = r.GoldObject;
		GO.prototype.__nOrigDis = GO.prototype.Dissapear;
		GO.prototype.Dissapear = function():Void {
			var self:Object = this;
			NLoader.goldCount++;
			trace("NEV gold tick=" + NLoader.tick);
			self.__nOrigDis();
		};
		var EO:Object = r.ExitObject;
		EO.prototype.__nOrigTrig = EO.prototype.PlayerHitTrigger;
		EO.prototype.PlayerHitTrigger = function():Void {
			var self:Object = this;
			NLoader.switchOpen = true;
			trace("NEV switch tick=" + NLoader.tick);
			self.__nOrigTrig();
		};
	}

	static function tickFn():Void {
		tick++;

		if (phase == "wait") {
			// Wait for N to finish booting (gamedata is the last module built).
			if (r.gamedata == null || r.game == null
			    || r.App_LoadLevel_Raw == undefined) return;
			if (bootTick == 0) {
				bootTick = tick;
				trace("[nloader] boot-ready at tick " + tick);
			}
			if (!resolved) {
				if (eiMode) {
					var cfg:String = String(EI.call("__swfConfig"));
					if (cfg != null && cfg != "" && cfg != "undefined"
					    && cfg != "null" && cfg != DONE) {
						parseConfig(cfg);
						rawCfg = cfg;
						resolved = true;
						trace("[nloader] EI configured id=" + levelId
						      + " levchars=" + levelStr.length
						      + " demo=" + (demoStr != ""));
					} else if (tick - bootTick >= EI_WAIT) {
						useFixture(); resolved = true;
						trace("[nloader] EI host silent -> fixture " + levelId);
					}
				} else if (tick - bootTick >= EI_WAIT) {
					useFixture(); resolved = true;
					trace("[nloader] no EI -> fixture " + levelId);
				}
			}
			if (resolved) startLoad();
		} else if (phase == "run") {
			r.game.Tick();   // one deterministic sim step
			recordFrame();   // structured per-frame telemetry (NF line)
			var p:Object = r.player;
			if (completed) {
				levelsDone++;
				// In EI mode the host may have a NEXT level queued: re-arm and
				// poll __swfConfig instead of quitting. Otherwise quit.
				if (eiMode) {
					trace("[nloader] level complete (" + levelsDone
					      + ") -> polling for next");
					rearm(); return;
				}
				trace("[nloader] level complete -> quitting");
				phase = "done"; fscommand("quit", ""); return;
			}
			if (p.isDead) {
				trace("[nloader] PLAYER DIED before exit -> quitting");
				phase = "done"; fscommand("quit", ""); return;
			}
		} else if (phase == "poll") {
			// Re-armed after a completion: wait for the host to serve the NEXT
			// level (a config string different from the one we just ran), or the
			// DONE sentinel meaning the queue is exhausted.
			var ncfg:String = String(EI.call("__swfConfig"));
			if (ncfg == DONE) {
				trace("[nloader] queue done (" + levelsDone + " levels) -> quitting");
				phase = "done"; fscommand("quit", ""); return;
			}
			if (ncfg != null && ncfg != "" && ncfg != "undefined"
			    && ncfg != "null" && ncfg != lastConfig) {
				parseConfig(ncfg);
				rawCfg = ncfg;
				trace("[nloader] next level id=" + levelId
				      + " levchars=" + levelStr.length + " demo=" + (demoStr != ""));
				startLoad();
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
		lastConfig = rawCfg;   // remember which config this load corresponds to
		trace("[nloader] loading level " + levelId + " (" + levelStr.length + " chars)");
		r.game.InitNewGame();
		r.App_LoadLevel_Raw(levelStr, NLoader.onLoaded);
	}

	// Reset per-level state after a completion and re-enter the poll phase so the
	// host can serve the next queued level (App_LoadLevel_Raw again, same session).
	static function rearm():Void {
		completed = false;
		goldCount = 0;
		switchOpen = false;
		demoStr = "";
		phase = "poll";
	}

	static function onLoaded():Void {
		trace("[nloader] level loaded -> entering running state");
		// Set up the running state by hand (App_PlayGame's wall-clock loop would
		// starve game.Tick()), install the completion hook -> __swfSendExit, start
		// the demo if provided, park N's process, drive ticks from tickFn().
		r.gui.HideAll();
		r.game.InitRetryLevel();
		installHooks();   // gold/switch -> NEV events + counters
		r.App_PlayerDeathEvent = r.App_PlayerDeathEvent_Normal;
		r.App_LevelPassedEvent = function():Void {
			NLoader.completed = true;
			trace("NEV exit tick=" + NLoader.tick + " id=" + NLoader.levelId);
			trace("N_COMPLETE id=" + NLoader.levelId + " tick=" + NLoader.tick);
			if (NLoader.eiMode) NLoader.EI.call("__swfSendExit", NLoader.levelId);
			NLoader.r.App_LevelPassedEvent_Normal();
		};
		if (demoStr != "") {
			r.game.LoadDemo(demoStr);
			r.game.StartDemoPlayback();
		}
		r.SetActiveProcess(NLoader.noop);
		phase = "run";
	}
}
