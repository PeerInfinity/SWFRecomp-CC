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
	// START_LEVEL: episode-0 level to start on (IncrementCurrentLevel that many
	// times before App_StartNewGame). OBJHASH: append h=<n> to every NF line, an
	// order-independent integer hash of the positions of every MovieClip two
	// levels under _root (N's object/enemy clips), so drones/thwumps diverging
	// shows up even when they never touch the player. (N is SWF6 = case-
	// insensitive: the hash method must not be named objHash, which IS OBJHASH.)
	static var START_LEVEL:Number = 0;
	static var OBJHASH:Boolean = false;
	// CLIPDIFF: with OBJHASH, also trace "ND clip+ path" / "ND clip- path" for
	// clips appearing/disappearing two levels under _root (+ their _currentframe).
	static var CLIPDIFF:Boolean = false;
	// CLIPPOS "lo:hi" (with OBJHASH, s26 n-browser-pfx): for ticks lo..hi of every
	// attempt, trace "ND cp t= path x= y= cf=" for each clip the h= walk hashes.
	static var CLIPPOS:String = "";
	// RANDCOUNT (s26 n-browser-pfx): wrap Math.random and append rc=<calls so far>
	// to every NF line, to find where two players' RNG streams fall out of step.
	static var RANDCOUNT:Boolean = false;
	static var rc:Number = 0;
	// WORLDHASH (with OBJHASH, s26 n-levels): also append o=<n>:<hash>, an
	// order-dependent hash over N's own object list (_root.objects.objArray:
	// drones, thwumps, mines, gold, doors...) of OBJ_TYPE + pos to 1e-3. The
	// h= clip walk only sees pooled GUI/effect clips, never level objects.
	// OBJDUMP: at each attempt's first tick, trace "ND obj <i> type=<T> x= y=".
	static var OBJDUMP:Boolean = false;
	// TRACKOBJ (authoring): objArray index traced once per game tick as
	// "NT t= ob=x,y" (-1 = off). E.g. a thwump or drone a route must dodge.
	static var TRACKOBJ:Number = -1;
	// TRACKGOLD (s26 n-gold-streaks): after each RunApp, one "NG f= i= cf= v=" line
	// per gold object whose clip is off its NOT_COLLECTED frame 1.
	static var TRACKGOLD:Boolean = false;
	// TRACKPLAYER (s27 n-ragdoll-strokes) "lo:hi" probe frames: after each RunApp,
	// "NP f= <name> x= y= xs= ys= rot= cf= v=" for player.mc, its child clips and
	// the ragdoll stick clips. Postlevel has no NF lines; this covers it. At frame
	// lo it also prints "NH f= <path> ..." for every clip (<= 4 levels under
	// _root) whose bounds contain the player: who draws at the player's spot.
	static var TRACKPLAYER:String = "";
	static var lastSet:Object;
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
		if (RANDCOUNT) {
			var M:Object = _global.Math;
			M.__ndRand = M.random;
			_global.ASSetPropFlags(M, "random", 0, 7);
			M.random = function():Number { NDrive.rc++; return _global.Math.__ndRand(); };
		}
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
			+ " st=" + p.curState + " k=" + (ks == "" ? "-" : ks) + " time=" + r.game.playerCurTime
			+ (OBJHASH ? " h=" + NDrive.clipPosHash() + " o=" + NDrive.worldHash() : "")
			+ (RANDCOUNT ? " rc=" + NDrive.rc : ""));
		if (OBJDUMP && t == 0) NDrive.dumpObjects();
		if (OBJDUMP) NDrive.doorDiff(t);
		if (TRACKOBJ >= 0) { var tob:Object = r.objects.objArray[TRACKOBJ]; trace("NT t=" + t + " ob=" + tob.pos.x + "," + tob.pos.y); }
	}
	static function goldTrace():Void {
		var arr:Array = r.objects.objArray;
		for (var i:Number = 0; i < arr.length; i++) {
			var o:Object = arr[i];
			if (o == undefined || Number(o.OBJ_TYPE) != 0 || o.mc == undefined) continue;
			if (o.mc._currentframe != 1) trace("NG f=" + frame + " t=" + r.game.tickCounter + " i=" + i + " cf=" + o.mc._currentframe + " v=" + o.mc._visible);
		}
	}
	static function mcLine(n:String, m:MovieClip):String {
		return "NP f=" + frame + " " + n + " x=" + m._x + " y=" + m._y + " xs=" + m._xscale + " ys=" + m._yscale + " rot=" + m._rotation + " cf=" + m._currentframe + " v=" + m._visible;
	}
	// clips (<= 4 levels) whose bounds contain the player's position: who draws there
	static function hitWalk(m:Object, path:String, lvl:Number):Void {
		var px:Number = r.player.pos.x;
		var py:Number = r.player.pos.y - 5;
		for (var k:String in m) {
			var c:Object = m[k];
			if (typeof(c) != "movieclip" || c._parent != m) continue;
			if (c.hitTest(px, py, false)) trace("NH f=" + frame + " " + path + "." + k + " v=" + c._visible + " cf=" + c._currentframe + " x=" + c._x + " y=" + c._y + " xs=" + c._xscale + " ys=" + c._yscale + " rot=" + c._rotation);
			if (lvl < 4) hitWalk(c, path + "." + k, lvl + 1);
		}
	}
	static function playerTrace():Void {
		var lh:Array = TRACKPLAYER.split(":");
		if (frame < Number(lh[0]) || frame > Number(lh[1])) return;
		if (frame == Number(lh[0])) hitWalk(r, "_root", 0);
		var p:Object = r.player;
		if (p == undefined || p.mc == undefined) return;
		trace(mcLine("mc", p.mc));
		var names:Array = new Array();
		for (var k:String in p.mc) if (typeof(p.mc[k]) == "movieclip") names.push(k);
		names.sort();
		for (var i:Number = 0; i < names.length; i++) trace(mcLine("mc." + names[i], p.mc[names[i]]));
		var sl:Object = p.raggy.sList;
		var sn:Array = new Array();
		for (var k2:String in sl) sn.push(k2);
		sn.sort();
		for (var j:Number = 0; j < sn.length; j++) trace(mcLine("rag." + sn[j], sl[sn[j]].mc));
	}
	static function worldHash():String {
		var arr:Array = r.objects.objArray;
		if (arr == undefined) return "-";
		var hv:Number = 0;
		var n:Number = 0;
		for (var i:Number = 0; i < arr.length; i++) {
			var o:Object = arr[i];
			if (o == undefined || o.pos == undefined) continue;
			n++;
			hv = (hv * 31 + Math.round(o.pos.x * 1000) * 7 + Math.round(o.pos.y * 1000) + Number(o.OBJ_TYPE)) % 1000000007;
		}
		return n + ":" + hv;
	}
	// OBJDUMP (s26 n-browser-pfx): trace "ND door <i> t= k=v,..." whenever a door
	// object's own primitive fields change (key pickup, switch, open/close).
	static var doorState:Array;
	static function doorDiff(t:Number):Void {
		var arr:Array = r.objects.objArray;
		if (t == 0 || doorState == undefined) doorState = new Array();
		for (var i:Number = 0; i < arr.length; i++) {
			var o:Object = arr[i];
			if (o == undefined || o.doorpos == undefined) continue;
			var s:String = "";
			for (var k in o) {
				var v = o[k];
				var ty:String = typeof(v);
				if (ty == "number" || ty == "boolean") s += k + "=" + v + ",";
			}
			if (doorState[i] != s) { if (t > 0) trace("ND door " + i + " t=" + t + " " + s); doorState[i] = s; }
		}
	}
	static function dumpObjects():Void {
		var arr:Array = r.objects.objArray;
		for (var i:Number = 0; i < arr.length; i++) {
			var o:Object = arr[i];
			trace("ND obj " + i + " type=" + o.OBJ_TYPE + " x=" + o.pos.x + " y=" + o.pos.y
				+ (o.trigger != undefined ? " trig=" + o.trigger.pos.x + "," + o.trigger.pos.y : "")
				+ (o.doorpos != undefined ? " door=" + o.doorpos.x + "," + o.doorpos.y + " trap=" + o.isTrap + " locked=" + o.isLocked : ""));
		}
	}
	static function clipPosHash():String {
		var n:Number = 0;
		var sx:Number = 0;
		var sy:Number = 0;
		var cur:Object = new Object();
		var cpOn:Boolean = false;
		var ct:Number = r.game.tickCounter;
		if (CLIPPOS != "") {
			var cpr:Array = CLIPPOS.split(":");
			cpOn = ct >= Number(cpr[0]) && ct <= Number(cpr[1]);
		}
		for (var a in r) {
			var c:Object = r[a];
			if (typeof(c) != "movieclip" || a == "__ndrive__") continue;
			for (var b in c) {
				var d:Object = c[b];
				if (typeof(d) != "movieclip" || d._parent != c) continue;
				n++; sx += Math.round(d._x * 100); sy += Math.round(d._y * 100);
				if (CLIPDIFF) cur[a + "." + b] = d._currentframe + "/" + d._totalframes;
				if (cpOn) trace("ND cp t=" + ct + " " + a + "." + b + " x=" + d._x + " y=" + d._y + " cf=" + d._currentframe);
			}
		}
		if (CLIPDIFF) {
			var t:Number = r.game.tickCounter;
			if (lastSet != undefined) {
				for (var k in cur) if (lastSet[k] == undefined) trace("ND clip+ t=" + t + " " + k + " cf=" + cur[k]);
				for (var k2 in lastSet) if (cur[k2] == undefined) trace("ND clip- t=" + t + " " + k2 + " lastcf=" + lastSet[k2]);
			}
			lastSet = cur;
		}
		return n + ":" + sx + ":" + sy;
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
			r.onEnterFrame = function():Void { NDrive.preFrame(); NDrive.r.RunApp(); if (NDrive.TRACKGOLD) NDrive.goldTrace(); if (NDrive.TRACKPLAYER != "") NDrive.playerTrace(); };
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
					if (START_LEVEL > 0) {
						// App_StartNewGame hard-codes App_LoadLevel(0, ...): bumping
						// curLevel alone only renamed level 0 (s26 n-levels). Same
						// body, loading the current level's map instead.
						for (var i:Number = 0; i < START_LEVEL; i++) r.gamedata.IncrementCurrentLevel();
						r.console.Show();
						var snd:Sound = new Sound();
						snd.stop();
						r.game.InitNewGame();
						r.App_PlayerDeathEvent = r.App_PlayerDeathEvent_Normal;
						r.App_LevelPassedEvent = r.App_LevelPassedEvent_Normal;
						r.App_LoadLevel(r.gamedata.GetCurrentLevelID(), r.App_StartPreLevelPause);
					} else r.App_StartNewGame();
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
