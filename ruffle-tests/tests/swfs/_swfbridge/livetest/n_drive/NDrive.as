// NDrive.as - deterministic input driver for N. Overrides Key.isDown so N's
// own per-game-tick input read (GetInputState) gets a tick-indexed script;
// Space is pressed by phase. Emits one NF telemetry line per game tick.
class NDrive {
	static var DEPTH:Number = 1048569;
	static var SCRIPT:String = "";
	static var AUTOKILL:Boolean = false; // authoring: kill at script end -> retry -> next attempt
	static var hooked:Boolean = false;
	// FRAMELOCK: wrap _root.onEnterFrame (= N's RunApp) so each frame's catch-up
	// loop in App_UpdateGame(_Demo) gets a budget of exactly ONE game tick
	// (APP_GAMETIME_t0 = now, REMAINDER = 1.5 ticks), independent of wall clock and
	// player frame rate. Then frame-based visuals (timeline anims, N's eased HUD
	// timer) line up frame-for-frame across players. Freeze points "attempt:tick"
	// give zero ticks for FREEZE_FRAMES frames ("ND shot" at frame 10).
	static var FRAMELOCK:Boolean = true;
	static var locked:Boolean = false;
	static var FREEZE:String = "0:250,0:330,1:200,1:409,1:520,1:663,2:60";
	static var FREEZE_FRAMES:Number = 30;
	static var freezeLeft:Number = 0;
	static var freezeLabel:String = "";
	static var PHASE_WAIT:Number = 40;
	static var r:Object;
	static var K:Object;
	static var frame:Number = 0;
	static var phase:String = "boot";
	static var phaseFrames:Number = 0;
	static var started:Boolean = false;
	static var space:Boolean = false;
	static var attempt:Number = -1;
	static var segs:Array;
	static var lastTick:Number = -1;
	static var wasDead:Boolean = false;
	static var gold:Number = 0;
	static var dbgSp:Boolean = false;
	static function main(mc:MovieClip):Void {
		r = _root;
		K = _global.Key;
		K.__ndOrig = K.isDown;
		_global.ASSetPropFlags(K, "isDown", 0, 7);
		K.isDown = function(k:Number):Boolean { return NDrive.isDown(k); };
		var clip:MovieClip = _root.createEmptyMovieClip("__ndrive__", DEPTH);
		clip.onEnterFrame = function():Void { NDrive.tickFn(); };
		trace("ND start replaced=" + (K.isDown != K.__ndOrig) + " same=" + (K == Key) + " test=" + Key.isDown(32));
	}
	static function phaseName():String {
		var t:Object = r.TickApp;
		if (t == r.App_Tick_RunningGame) return (r.player.isDead ? (r.APP_WAITING_TO_RETRY ? "retrywait" : "dead") : "run");
		if (t == r.App_Tick_PreLevelPause) return "prelevel";
		if (t == r.App_Tick_PostLevelPause) return "postlevel";
		if (t == r.App_Tick_PostLevelPause_EpVictory) return "epvictory";
		if (t == r.App_Tick_MainMenu) return "mainmenu";
		if (t == r.AppLoadingLevel) return "loading";
		if (t == r.AppResettingObjects) return "resetting";
		if (t == r.App_Tick_GameOver) return "gameover";
		return "other";
	}
	static function parseAttempt(i:Number):Void {
		var all:Array = SCRIPT.split("/");
		segs = new Array();
		var s:String = (all[i] != undefined) ? String(all[i]) : "";
		if (s == "") return;
		var parts:Array = s.split("|");
		var end:Number = 0;
		for (var j:Number = 0; j < parts.length; j++) {
			var kv:Array = String(parts[j]).split(":");
			end += Number(kv[0]);
			segs.push({end: end, keys: String(kv[1])});
		}
	}
	static function keysAt(t:Number):String {
		if (segs == undefined) return "";
		for (var j:Number = 0; j < segs.length; j++) if (t < segs[j].end) return segs[j].keys;
		return "";
	}
	static function isDown(k:Number):Boolean {
		var g:Object = r.game;
		if (k == 32) { if (space && !dbgSp) { dbgSp = true; trace("ND space read phase=" + phase + " frame=" + frame); } return space; }
		if (phase == "run" && g != undefined) {
			var t:Number = g.tickCounter;
			var ks:String = keysAt(t);
			if (k == g.KEYDEF_L) {
				if (t != lastTick) {
					lastTick = t; telemetry(t, ks);
					if (FRAMELOCK && ("," + FREEZE + ",").indexOf("," + attempt + ":" + t + ",") >= 0) {
						freezeLeft = FREEZE_FRAMES + 1;
						freezeLabel = "a" + attempt + "t" + t;
					}
				}
				return ks.indexOf("L") >= 0;
			}
			if (k == g.KEYDEF_R) return ks.indexOf("R") >= 0;
			if (k == g.KEYDEF_J || k == 90) return ks.indexOf("J") >= 0;
		}
		return false;
	}
	static function telemetry(t:Number, ks:String):Void {
		var p:Object = r.player;
		trace("NF a=" + attempt + " t=" + t + " x=" + p.pos.x + " y=" + p.pos.y
			+ " vx=" + (p.pos.x - p.oldpos.x) + " vy=" + (p.pos.y - p.oldpos.y)
			+ " st=" + p.curState + " k=" + (ks == "" ? "-" : ks) + " time=" + r.game.playerCurTime);
	}
	// Event hooks (NLoader pattern): chain to N's originals, only add a trace.
	static function installHooks():Void {
		if (hooked) return;
		hooked = true;
		var EO:Object = r.ExitObject;
		EO.prototype.__ndTrig = EO.prototype.PlayerHitTrigger;
		EO.prototype.PlayerHitTrigger = function():Void {
			var self:Object = this;
			trace("ND EV switch a=" + NDrive.attempt + " t=" + NDrive.r.game.tickCounter);
			self.__ndTrig();
		};
		EO.prototype.__ndExit = EO.prototype.PlayerHitExit;
		EO.prototype.PlayerHitExit = function():Void {
			var self:Object = this;
			trace("ND EV exit a=" + NDrive.attempt + " t=" + NDrive.r.game.tickCounter);
			self.__ndExit();
		};
		var G:Object = r.NinjaGame;
		G.prototype.__ndKill = G.prototype.KillPlayer;
		G.prototype.KillPlayer = function(kt, fx, fy, px, py, obj):Void {
			var self:Object = this;
			trace("ND EV kill a=" + NDrive.attempt + " t=" + self.tickCounter + " type=" + kt + " fx=" + fx + " fy=" + fy + " px=" + px + " py=" + py);
			self.__ndKill(kt, fx, fy, px, py, obj);
		};
	}
	// Runs right before N's RunApp each frame (see FRAMELOCK).
	static function preFrame():Void {
		var now:Number = getTimer();
		r.APP_GAMETIME_t0 = now;
		r.APP_GAMETIME_REMAINDER = (freezeLeft > 0) ? -1000 : r.APP_GAMETIME_TICKLEN * 1.5;
	}
	static function tickFn():Void {
		frame++;
		if (FRAMELOCK && !locked && r.RunApp != undefined && r.onEnterFrame == r.RunApp) {
			locked = true;
			r.onEnterFrame = function():Void { NDrive.preFrame(); NDrive.r.RunApp(); };
			trace("ND framelock on frame=" + frame);
		}
		if (!started) {
			if (r.gamedata != null && r.game != null && r.TickApp == r.App_Tick_MainMenu) {
				phaseFrames++;
				if (phaseFrames >= 10) {
					started = true;
					trace("ND startgame frame=" + frame);
					installHooks();
					r.gamedata.LoadEpisodeNum(0);
					r.App_StartNewGame();
				}
			}
			return;
		}
		if (freezeLeft > 0) {
			freezeLeft--;
			if (freezeLeft == FREEZE_FRAMES - 10) trace("ND shot " + freezeLabel + " frame=" + frame + " tick=" + r.game.tickCounter);
			return;
		}
		var ph:String = phaseName();
		if (ph != phase) {
			trace("ND phase " + phase + "->" + ph + " frame=" + frame + " tick=" + r.game.tickCounter
				+ " lvl=" + r.gamedata.GetCurrentLevelName() + " x=" + r.player.pos.x + " y=" + r.player.pos.y);
			if (ph == "run" && phase == "prelevel") { attempt++; lastTick = -1; parseAttempt(attempt); trace("ND attempt " + attempt + " segs=" + segs.length); }
			phase = ph; phaseFrames = 0;
		}
		phaseFrames++;
		if (phaseFrames == 20 && (phase == "prelevel" || phase == "postlevel" || phase == "retrywait"))
			trace("ND shot " + phase + "_" + attempt + " frame=" + frame);
		if (AUTOKILL && phase == "run" && segs.length > 0 && r.game.tickCounter >= segs[segs.length - 1].end) {
			trace("ND autokill a=" + attempt + " t=" + r.game.tickCounter);
			r.game.KillPlayer(4, 0, 0, r.player.pos.x, r.player.pos.y, r.player);
		}
		space = ((phase == "prelevel" || phase == "postlevel" || phase == "retrywait") && phaseFrames >= PHASE_WAIT);
	}
}
