// Loader.as — PRODUCTION injected level loader for recompiled Doodle Jump.
//
// Renders Archipelago-CC procedurally generated bounceDemo 'dj' levels inside
// the real DJ engine, replacing the JS renderer page. Spec:
//   ~/CC/Archipelago-CC/NewDocs/plans/procedural-generation/dj-loader-integration-spec.md
// This is "Probe.as grown up" (same MTASC -> extract -> inject pipeline; see
// ../dj_probe/). DJ's hero physics are UNTOUCHED — we only disable the native
// random spawner and author the platform stream (the Q4 "Mode 2" capability).
//
// Data flow (two sources, one code path):
//   * EI mode (browser: SWFRecomp WASM page or Ruffle page): pull the level as
//     a compact string via ExternalInterface.call("__swfConfig") (retried each
//     tick until the host has configured), held items via .call("__swfPoll")
//     (FULL current set, idempotent), outward events via
//     .call("__swfSendLocation", id) / .call("__swfSendExit", "id|side")
//     (single packed arg: the recompiled EI marshaler is 1-string-arg).
//     The page-side encoder is dj_swf_bridge.js (level JSON -> compact string).
//   * Fixture mode (EI unavailable: graphics-native headless, or Ruffle with no
//     host page): FixtureData.DATA carries the same compact string plus G|tick|
//     item-grant records (generated from the committed preset by gen_fixture.py).
//     Outward events are trace()-only.
//
// Compact level string (";"-separated records, "|"-separated fields; all
// coordinates are ALREADY mapped to DJ space by the encoder — container-local
// y aligned so the level bottom sits at screen 400, x shifted to the visible
// 240px strip):
//   R|levelId|worldW|worldH|spawnX|spawnY
//   P|idx|pid|type|x|y|gateItem|goalKind|goalId|goalSide
//        type: g green, b brown(breaking), m blue(mover)   [m = later increment]
//        gateItem: platform exists only while this item is held ('' = always)
//        goalKind: loc (pickup, landing collects) | exit (portal, landing exits)
//   C|loc_0,loc_1   (already-checked pickup ids — never re-offered)
//   G|tick|name1,name2  (FIXTURE ONLY: from this tick, held items = this set)
//
// How the level drives DJ's own engine: platforms are container.block_<idx>
// clips ("cloud" attachMovie) with container.attribute[idx] set, because the
// hero's catch loop scans block_(lastblockhit-3) .. block_(lastblockhit+9) by
// INDEX — the encoder assigns indices in bottom-to-top order so the climb
// window always covers reachable platforms. Landing detection reads
// hero.lastblockhit transitions (exact, no physics guessing): goals are
// landing-triggered on their HOST platform per the spec.

class Loader {
	static var DEPTH:Number = 1048570;
	static var GOTO_TICK:Number = 2;
	// Pickup marker visual (native "coin" art above the host platform). NOTE
	// the coin sprite's frame-1 action is gotoAndPlay(1) (a per-tick self-goto).
	static var VIZ_COIN:Boolean = false;
	static var DBG:Boolean = false;
	// Parked clips sit here: outside the wrap range [-23, 263], so the hero's
	// feet point-tests (x +/- 23) can never reach their bbox.
	static var PARK_X:Number = -1000;
	static var nativeBlocks:Number = 0;

	static var tick:Number = 0;
	static var started:Boolean = false;
	static var configured:Boolean = false;
	static var inited:Boolean = false;
	static var EI:Object;
	static var eiMode:Boolean = false;

	// parsed level
	static var levelId:String = "";
	static var worldW:Number = 0;
	static var worldH:Number = 0;
	static var spawnX:Number = 0;
	static var spawnY:Number = 0;
	static var plats:Array;        // records (see parseConfig)
	static var grants:Array;       // fixture item schedule [{t, csv}]
	static var checked:Object;     // pickup ids already collected
	static var exitFired:Object;   // portal ids fired this session
	static var itemsCsv:String = "\x01"; // sentinel: force first apply
	static var held:Object;        // item name -> true
	static var lastLb:Number = 0;

	static function main(mc:MovieClip):Void {
		// Untyped so the variadic AVM1 ExternalInterface.call isn't rejected by
		// MTASC's 1-arg intrinsic signature (same idiom as swfbridge_toy).
		EI = flash.external.ExternalInterface;
		eiMode = (EI.available == true);
		trace("[loader] start ei=" + eiMode
		      + " stage=" + Stage.width + "x" + Stage.height);
		var clip:MovieClip = _root.createEmptyMovieClip("__aploader__", DEPTH);
		clip.onEnterFrame = function():Void { Loader.tickFn(); };
	}

	static function tickFn():Void {
		tick++;

		if (!configured) {
			var cfg:String = eiMode ? String(EI.call("__swfConfig")) : FixtureData.DATA;
			if (cfg != null && cfg != "" && cfg != "undefined" && cfg != "null") {
				parseConfig(cfg);
				configured = true;
				trace("[loader] configured level=" + levelId + " platforms=" + plats.length);
			}
		}

		// Force gameplay (PLAY button = _root.gotoAndPlay(2)); native/Ruffle
		// don't need a click. Only once configured: no level, no game.
		if (configured && !started && tick >= GOTO_TICK) {
			started = true;
			trace("[loader] forcing _root.gotoAndPlay(2)");
			_root.gotoAndPlay(2);
			return;
		}
		if (!started) return;

		if (!inited) {
			// Pre-takeover guard: the NATIVE game (random blocks) runs for the
			// ~17 staged-init ticks, and whether the hero survives it is RNG
			// luck (the wide build's layout killed it -> gameOver -> frame 3
			// -> container gone -> takeover impossible). Pin the hero safe
			// mid-screen and clear gameOver until our level owns it.
			var h = _root.hero;
			if (typeof(h) == "movieclip") { h._y = 180; h.vy = 0; }
			if (_root.gameOver == true) _root.gameOver = false;
			tryInit();
			if (!inited) return;
		}

		pollItemsTick();
		if (DBG) trace("[dbg] t" + tick + " poll ok");
		interceptGameOver();
		if (DBG) trace("[dbg] t" + tick + " igo ok");
		detectLanding();
		if (DBG) trace("[dbg] t" + tick + " dl ok");
		statusTrace();
	}

	// ---- config ----------------------------------------------------------
	static function parseConfig(cfg:String):Void {
		plats = [];
		grants = [];
		checked = {};
		exitFired = {};
		held = {};
		var recs:Array = cfg.split(";");
		for (var i:Number = 0; i < recs.length; i++) {
			var f:Array = recs[i].split("|");
			var kind:String = f[0];
			if (kind == "R") {
				levelId = f[1];
				worldW = Number(f[2]); worldH = Number(f[3]);
				spawnX = Number(f[4]); spawnY = Number(f[5]);
			} else if (kind == "P") {
				plats.push({ idx: Number(f[1]), pid: f[2], type: f[3],
				             x: Number(f[4]), y: Number(f[5]), gate: f[6],
				             goalKind: f[7], goalId: f[8], goalSide: f[9],
				             present: false });
			} else if (kind == "C") {
				var ids:Array = f[1].split(",");
				for (var j:Number = 0; j < ids.length; j++) {
					if (ids[j] != "") checked[ids[j]] = true;
				}
			} else if (kind == "G") {
				grants.push({ t: Number(f[1]), csv: (f[2] == undefined ? "" : f[2]) });
			}
		}
	}

	// ---- init: take over the container -----------------------------------
	static function tryInit():Void {
		var c = _root.container;
		var h = _root.hero;
		if (typeof(c) != "movieclip" || typeof(h) != "movieclip") return;
		// Wait until the native spawner EXISTS and has done its initial attach.
		// Browser-WASM defers the container's frame-1 DoAction relative to our
		// injected clip's enterFrame: taking over before it runs would let
		// attachBlocks() reinstate the spawn loop after our kill and attach 15
		// random blocks whose NAMES (block_0..block_14) collide with ours.
		// Native/Ruffle already initialize after the spawn, so this just makes
		// the ordering deterministic on every tier.
		if (typeof(c.attachBlocks) != "function") return;
		if (!(Number(c.lastBlockAttached) > 0)) return;

		// STAGED takeover — one operation per tick. A single-tick batch of MC
		// ops from the injected clip's context hangs the browser-WASM runtime
		// at end-of-tick (status doc); spread over ticks every step works on
		// every tier. ~15 ticks (~0.75s) of native game run visibly before the
		// takeover completes; resetHero() at the end erases any effect.
		stagedInit(c);
	}

	// The takeover, one step per tick:
	//   step 0: kill the native spawner (container.onEnterFrame, set by
	//           attachBlocks() in the levelcontainer's frame-1 DoAction)
	//   step 1: PARK all natively spawned blocks/powerups offscreen — claim,
	//           don't remove: removeMovieClip of attached clips hangs the
	//           browser-WASM runtime a tick later, and repositioning existing
	//           clips is probe-proven on all tiers. Powerup children
	//           (spring_/nail_/inverse_/coin_) stay parked forever: with
	//           attribute[] all 0/2 the hero never consults them.
	//   step 2: fresh attribute[]
	//   steps 3..3+N: claim + position block_<idx> per platform (gated ones
	//           stay parked until pollItems grants their item)
	//   last:   hero to the region spawn, engine state reset
	static var initStep:Number = 0;
	static function stagedInit(c):Void {
		if (DBG) trace("[dbg] stagedInit step " + initStep + " (tick " + tick + ")");
		if (initStep == 0) {
			c.onEnterFrame = null;
			delete c.onEnterFrame;
		} else if (initStep == 1) {
			nativeBlocks = Number(c.blocknr);
			if (!(nativeBlocks > 0)) nativeBlocks = 0;
			for (var b:Number = 0; b < nativeBlocks; b++) {
				parkNamed(c, "block_" + b);
				parkNamed(c, "spring_" + b);
				parkNamed(c, "nail_" + b);
				parkNamed(c, "inverse_" + b);
				parkNamed(c, "coin_" + b);
			}
		} else if (initStep == 2) {
			c.attribute = new Array();
		} else if (initStep >= 3 && initStep < 3 + plats.length) {
			var p = plats[initStep - 3];
			var gateOk:Boolean = (p.gate == "" || held[p.gate] == true);
			if (gateOk) positionPlat(p); else parkPlat(p);
		} else {
			resetHero();
			inited = true;
			trace("[loader] init done: spawner disabled, " + plats.length
			      + " platforms authored over " + nativeBlocks + " native blocks");
		}
		initStep++;
	}

	static function parkNamed(c, name:String):Void {
		if (typeof(c[name]) != "movieclip") return;
		c[name]._x = PARK_X;
	}

	static function placeAll():Void {
		for (var i:Number = 0; i < plats.length; i++) {
			var p = plats[i];
			var gateOk:Boolean = (p.gate == "" || held[p.gate] == true);
			if (gateOk) positionPlat(p);
			else parkPlat(p);
		}
	}

	// Claim (or create, for levels larger than the native spawn) block_<idx>
	// and position/type it for platform p.
	static function positionPlat(p):Void {
		var c = _root.container;
		var b = c["block_" + p.idx];
		if (typeof(b) != "movieclip") {
			// More platforms than native blocks (or one was deleted by the
			// hero's climb-recycle): attach a fresh one. Fixed deterministic
			// depths above the native getNextHighestDepth range.
			if (DBG) trace("[dbg] attach block_" + p.idx + " (" + p.pid + ")");
			b = c.attachMovie("cloud", "block_" + p.idx, 6000 + p.idx);
		}
		b._x = p.x;
		b._y = p.y;
		if (p.type == "b") {
			b.gotoAndStop(2);              // brown/breaking; restores after break
			c.attribute[p.idx] = 2;        // hero: bounce-no-vy-zero + break
		} else if (p.type == "m") {
			b.gotoAndStop(3);              // blue mover (later increment: sweep
			c.attribute[p.idx] = 0;        //  driven per OUR spec, not native phase)
		} else {
			b.gotoAndStop(1);              // plain green (same-frame goto = no-op)
			c.attribute[p.idx] = 0;
		}
		p.present = true;
	}

	static function parkPlat(p):Void {
		var c = _root.container;
		if (typeof(c["block_" + p.idx]) == "movieclip") c["block_" + p.idx]._x = PARK_X;
		c.attribute[p.idx] = 0;
		p.present = false;
	}

	static function resetHero():Void {
		var h = _root.hero;
		_root.container._y = 0;
		h._x = spawnX;
		h._y = spawnY;
		h.vy = 0;
		h.jump = false;
		h.lastblockhit = 0;
		// Disable DJ's climb-recycle deletion (hero removes block_(lb-4) on
		// each climb landing): authored levels keep ALL platforms alive — the
		// bottom-fall respawn needs them back, and removeMovieClip of attached
		// clips hangs the browser-WASM runtime a tick later (status doc). The
		// hero's guard is `DeleteBlock > lastDeletedBlock`, so a huge value
		// means never.
		h.lastDeletedBlock = 999999;
		lastLb = 0;
	}

	// ---- items (host -> game), gated existence ----------------------------
	static function pollItemsTick():Void {
		var csv:String;
		if (eiMode) {
			csv = String(EI.call("__swfPoll"));
			if (csv == "undefined" || csv == "null") csv = "";
		} else {
			csv = "";
			for (var g:Number = 0; g < grants.length; g++) {
				if (tick >= grants[g].t) csv = grants[g].csv;
			}
		}
		if (csv == itemsCsv) return;
		itemsCsv = csv;
		held = {};
		var names:Array = csv.split(",");
		for (var i:Number = 0; i < names.length; i++) {
			if (names[i] != "") held[names[i]] = true;
		}
		trace("[loader] items=[" + csv + "]");
		// Existence gating takes effect immediately (next frame at the latest).
		for (var k:Number = 0; k < plats.length; k++) {
			var p = plats[k];
			if (p.gate == "") continue;
			var want:Boolean = (held[p.gate] == true);
			if (want != p.present) {
				if (want) positionPlat(p); else parkPlat(p);
				trace("[loader] gate " + p.pid + " (" + p.gate + ") -> "
				      + (want ? "exists" : "absent"));
			}
		}
	}

	// ---- landings -> goals (game -> host) ---------------------------------
	static function detectLanding():Void {
		var lb:Number = Number(_root.hero.lastblockhit);
		if (lb == lastLb) return;
		lastLb = lb;
		for (var i:Number = 0; i < plats.length; i++) {
			var p = plats[i];
			if (p.idx != lb) continue;
			if (p.goalKind == "loc" && checked[p.goalId] != true) {
				checked[p.goalId] = true;
				var c = _root.container;
				if (typeof(c["apviz_" + p.idx]) == "movieclip") c["apviz_" + p.idx].removeMovieClip();
				trace("[loader] sendLocation " + p.goalId);
				if (eiMode) EI.call("__swfSendLocation", p.goalId);
			} else if (p.goalKind == "exit" && exitFired[p.goalId] != true) {
				exitFired[p.goalId] = true;
				trace("[loader] sendExit " + p.goalId + " " + p.goalSide);
				if (eiMode) EI.call("__swfSendExit", p.goalId + "|" + p.goalSide);
			}
			break;
		}
	}

	// ---- bottom fall = respawn at the entrance (not death) ----------------
	static function interceptGameOver():Void {
		if (_root.gameOver != true) return;
		// Clear before the hero's own gameOver branch can _root.gotoAndStop(3):
		// the hero checks at the TOP of its enterFrame and sets it at the
		// BOTTOM, so clearing here (any dispatch order) wins the race.
		_root.gameOver = false;
		trace("[loader] fell off the bottom -> respawn at entrance");
		// Collected pickups persist (checked survives); broken browns restore.
		placeAll();
		resetHero();
	}

	// ---- per-tick state trace (sustained-physics evidence + cross-tier diff)
	static function statusTrace():Void {
		var h = _root.hero;
		trace("LT" + tick + " hx=" + h._x + " hy=" + h._y + " vy=" + h.vy
		      + " cy=" + _root.container._y + " lb=" + lastLb + " sc=" + h.score);
	}
}
