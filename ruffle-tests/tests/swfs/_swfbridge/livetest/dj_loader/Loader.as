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
	// Goal visuals: native "coin" art above pickup hosts (exonerated from the
	// 2026-06-11 hang — that was the 64KB wasm stack), drawing-API "door"
	// above portal hosts. v1 is a human playing; they need to SEE goal hosts.
	static var VIZ_GOALS:Boolean = true;
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
	static var cfgGen:Number = 0;  // last seen __swfConfigGen (0 = no support)
	static var genPoll:Boolean = false; // page exposes __swfConfigGen
	static var maxIdxEver:Number = 0;   // widest block_<idx> set authored so far
	// Mover clock: ticks since region entry/respawn (t=0 at the spawn state).
	// Phases restart on respawn and on re-configure, per the AP sweep spec.
	static var regionTick:Number = 0;
	static var BLUE_SPEED:Number = 5;

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
				if (eiMode) {
					// Snapshot the configure generation counter (region swaps:
					// the host re-configures on every region move; we poll one
					// int per tick and re-pull the string only on change).
					// Pages without __swfConfigGen -> NaN -> polling disabled.
					var g0:Number = Number(EI.call("__swfConfigGen"));
					if (!isNaN(g0)) { cfgGen = g0; genPoll = true; }
				}
				trace("[loader] configured level=" + levelId + " platforms="
				      + plats.length + (genPoll ? (" gen=" + cfgGen) : ""));
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

		checkReconfigure();
		pollItemsTick();
		if (DBG) trace("[dbg] t" + tick + " poll ok");
		interceptGameOver();
		if (DBG) trace("[dbg] t" + tick + " igo ok");
		regionTick++;
		moverTick();
		vizTick();
		if (DBG && tick == 60) placeAlphaTestClips();
		if (DBG && tick == 330) dumpClips();
		detectLanding();
		if (DBG) trace("[dbg] t" + tick + " dl ok");
		statusTrace();
	}

	// ---- blue movers: deterministic triangle wave (AP sweep spec) ----------
	// x(t) = min + tri(BLUE_SPEED * t over a 2*span cycle), t = regionTick.
	// This OVERRIDES DJ's native spawn-anchored mover: the inner child "aaa"
	// (charId 32) is frozen at local 0 each tick (ac=0 kills its own
	// `this._x += ac` clip action where it runs at all), making the mover
	// geometrically identical to a green at the block origin (charId 35
	// bounds x[-30,30] at aaa placement (0,0)) — so block._x IS the platform
	// center and the same catch line applies.
	static function moverTick():Void {
		var c = _root.container;
		for (var i:Number = 0; i < plats.length; i++) {
			var p = plats[i];
			if (p.type != "m" || !p.present || isNaN(p.sweepMin)) continue;
			var b = c["block_" + p.idx];
			if (typeof(b) != "movieclip") continue;
			if (typeof(b.aaa) == "movieclip") { b.aaa.ac = 0; b.aaa._x = 0; }
			b._x = sweepX(p);
		}
	}

	static function sweepX(p):Number {
		var span:Number = p.sweepMax - p.sweepMin;
		var cyc:Number = 2 * span;
		var ph:Number = (BLUE_SPEED * regionTick) % cyc;
		if (ph < 0) ph += cyc;
		return p.sweepMin + ((ph <= span) ? ph : (cyc - ph));
	}

	// ---- region swaps: host re-configures on every region move ------------
	static function checkReconfigure():Void {
		if (!genPoll) return;
		var g:Number = Number(EI.call("__swfConfigGen"));
		if (isNaN(g) || g == cfgGen) return;
		cfgGen = g;
		var cfg:String = String(EI.call("__swfConfig"));
		if (cfg == null || cfg == "" || cfg == "undefined" || cfg == "null") return;
		parseConfig(cfg);  // replaces plats/checked/exitFired (host owns the
		                   // global collected set via the C| record)
		reauthorLevel();
		trace("[loader] reconfigured -> " + levelId + " (" + plats.length
		      + " platforms, gen " + cfgGen + ")");
	}

	// Tear down the current region and author the new one. Claim/park makes
	// this a re-position pass; batched MC ops are safe post stack-fix
	// (0b5f20966), so unlike the initial takeover this runs in ONE tick — a
	// region move should not show 15 ticks of the old level.
	static function reauthorLevel():Void {
		var c = _root.container;
		var n:Number = maxIdxEver;
		if (nativeBlocks > n) n = nativeBlocks;
		for (var b:Number = 0; b < n; b++) {
			parkNamed(c, "block_" + b);
		}
		// ALL visuals cleared via their reference registries on the SAME tick
		// that re-authors the level — never by name lookup (by-name removal
		// of dynamic clips is unreliable on the swfrecomp tier: stale doors
		// AND a stale coin both survived swaps in hand-verify).
		var k:String;
		for (k in doors) {
			if (typeof(doors[k]) == "movieclip") killViz(doors[k]);
		}
		for (k in ghosts) {
			if (typeof(ghosts[k]) == "movieclip") killViz(ghosts[k]);
		}
		for (k in coins) {
			if (typeof(coins[k]) == "movieclip") killViz(coins[k]);
		}
		doors = {};
		ghosts = {};
		coins = {};
		c.attribute = new Array();
		// Gated platforms stay parked until the next pollItemsTick re-applies
		// the held set onto the NEW plats (forced via the itemsCsv sentinel).
		held = {};
		itemsCsv = "\x01";
		placeAll();
		resetHero();
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
				// P| v2 trailing fields: center-sweep bounds for blue movers
				// (empty/missing -> NaN -> static).
				plats.push({ idx: Number(f[1]), pid: f[2], type: f[3],
				             x: Number(f[4]), y: Number(f[5]), gate: f[6],
				             goalKind: f[7], goalId: f[8], goalSide: f[9],
				             sweepMin: (f[10] == "" || f[10] == undefined) ? Number.NaN : Number(f[10]),
				             sweepMax: (f[11] == "" || f[11] == undefined) ? Number.NaN : Number(f[11]),
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

	// (3.3 background fill REMOVED by user decision after hand-verify: in
	// live z-order the fill composited ABOVE the authored blocks/coins/doors
	// despite its low container depth — stage-extension cosmetics are
	// deliberately not pursued for now; the empty strip stays.)

	static function parkNamed(c, name:String):Void {
		if (typeof(c[name]) != "movieclip") return;
		c[name]._x = PARK_X;
	}

	static function placeAll():Void {
		if (plats.length > maxIdxEver) maxIdxEver = plats.length;
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
		updateViz(p);
	}

	// ---- goal-host + gate visuals (increment 3) ----------------------------
	// Coins (pickups) are container-attached native "coin" clips — attachMovie
	// reliably parents into the container on every tier. Doors (portals) and
	// gate GHOSTS are drawing-API clips on _ROOT, positioned EVERY tick from
	// container-local coords + container._y by vizTick(): increment 2's
	// container.createEmptyMovieClip door did not scroll with the level in
	// real play (the AP 3.2 bug), so screen-space + per-tick positioning is
	// the tier-agnostic fix. Names are OUR namespace (apviz_/apdoor_/apghost_)
	// so DJ's native coin logic (attribute==7 + "coin_<i>") can't touch them.
	//
	// States (matching the JS renderer's visual language):
	//   pickup uncollected -> full coin; collected/checked -> coin at _alpha
	//   25 (stays readable, per the user); portal door rides its host with a
	//   direction arrow, dimmed to 22 while the host is item-gated away;
	//   gated-absent platforms show a translucent platform-colored ghost
	//   (swept blues' ghosts ride the same x(t)); broken browns ghost NOTHING.
	static function updateViz(p):Void {
		if (!VIZ_GOALS) return;
		if (coins == undefined) coins = {};
		var c = _root.container;
		if (p.goalKind == "loc") {
			var v = coins[p.idx];
			if (typeof(v) != "movieclip") {
				v = c.attachMovie("coin", "apviz_" + p.idx, 6500 + p.idx);
				coins[p.idx] = v;
			}
			v._x = p.x;
			v._y = p.y - 28;
			v._alpha = (checked[p.goalId] == true) ? 25 : 100;
		} else if (typeof(coins[p.idx]) == "movieclip") {
			killViz(coins[p.idx]);
			delete coins[p.idx];
		}
	}

	static var DOOR_DEPTH:Number = 900000;
	static var GHOST_DEPTH:Number = 901000;
	// AS-side CLIP-REFERENCE registries for the _root drawing visuals. On the
	// swfrecomp tier, name lookup of createEmptyMovieClip children on _root
	// (`_root["apdoor_3"]`) resolves undefined even while the clip exists —
	// which made removal-by-name a no-op (stale doors survived a region swap,
	// frozen, until a LATER region reused the same idx and the same-depth
	// createEmptyMovieClip replaced them: exactly the hand-verify symptom).
	// Holding direct references sidesteps name lookup on every tier.
	static var doors:Object;   // idx -> clip ref
	static var ghosts:Object;  // idx -> clip ref
	static var coins:Object;   // idx -> clip ref (container-attached "coin")

	// Current host CENTER x in container space (live mover x when present,
	// the sweep formula for gated-away movers so ghosts ride the same wave).
	static function hostX(p):Number {
		if (p.type == "m" && !isNaN(p.sweepMin)) {
			if (p.present) {
				var b = _root.container["block_" + p.idx];
				if (typeof(b) == "movieclip") return b._x;
			}
			return sweepX(p);
		}
		return p.x;
	}

	static function vizTick():Void {
		if (!VIZ_GOALS || plats == undefined) return;
		if (doors == undefined) doors = {};
		if (ghosts == undefined) ghosts = {};
		var c = _root.container;
		var cy:Number = Number(c._y);
		if (isNaN(cy)) cy = 0;
		for (var i:Number = 0; i < plats.length; i++) {
			var p = plats[i];
			var hx:Number = hostX(p);
			if (p.goalKind == "exit") {
				var d = doors[p.idx];
				if (typeof(d) != "movieclip") {
					d = _root.createEmptyMovieClip("apdoor_" + p.idx, DOOR_DEPTH + p.idx);
					drawDoor(d, p.goalSide);
					doors[p.idx] = d;
				}
				d._x = hx;
				d._y = p.y + cy;
				d._alpha = p.present ? 80 : 22;
			}
			var wantGhost:Boolean = (!p.present && p.gate != "");
			var g = ghosts[p.idx];
			if (wantGhost) {
				if (typeof(g) != "movieclip") {
					g = _root.createEmptyMovieClip("apghost_" + p.idx, GHOST_DEPTH + p.idx);
					drawGhost(g, p.type);
					ghosts[p.idx] = g;
				}
				g._x = hx;
				g._y = p.y + cy;
			} else if (typeof(g) == "movieclip") {
				killViz(g);
				delete ghosts[p.idx];
			}
			// Coins follow their host too (mover hosts; also self-heals any
			// stale visual onto its true host).
			if (p.goalKind == "loc" && coins != undefined) {
				var v = coins[p.idx];
				if (typeof(v) == "movieclip") { v._x = hx; v._y = p.y - 28; }
			}
		}
	}

	// Remove a _root drawing visual via its DIRECT reference, with an
	// offscreen park as the belt to the suspenders (position-by-ref provably
	// works on every tier — it's how vizTick moves these clips).
	static function killViz(clip):Void {
		clip._x = -3000;
		clip.removeMovieClip();
	}

	// A translucent "door" around the clip origin (= the host's catch line):
	// body (-12,-38)..(12,-4) + a white direction arrow per the exit side.
	static function drawDoor(d, side:String):Void {
		d.beginFill(0x9933FF, 55);
		d.moveTo(-12, -38); d.lineTo(12, -38); d.lineTo(12, -4);
		d.lineTo(-12, -4); d.lineTo(-12, -38);
		d.endFill();
		d.beginFill(0xFFFFFF, 90);
		if (side == "N") {
			d.moveTo(0, -30); d.lineTo(7, -16); d.lineTo(-7, -16); d.lineTo(0, -30);
		} else if (side == "S") {
			d.moveTo(0, -12); d.lineTo(7, -26); d.lineTo(-7, -26); d.lineTo(0, -12);
		} else if (side == "W") {
			d.moveTo(-8, -21); d.lineTo(6, -14); d.lineTo(6, -28); d.lineTo(-8, -21);
		} else { // E
			d.moveTo(8, -21); d.lineTo(-6, -14); d.lineTo(-6, -28); d.lineTo(8, -21);
		}
		d.endFill();
	}

	// Platform-shaped ghost around the origin (top edge at the catch line),
	// tinted per type at low alpha — the metroidvania "what the item unlocks".
	static function drawGhost(g, type:String):Void {
		var col:Number = (type == "b") ? 0xA0784F : 0x5B9BD5;
		g.beginFill(col, 24);
		g.moveTo(-30, 0); g.lineTo(30, 0); g.lineTo(30, 13);
		g.lineTo(-30, 13); g.lineTo(-30, 0);
		g.endFill();
	}

	static function parkPlat(p):Void {
		var c = _root.container;
		if (typeof(c["block_" + p.idx]) == "movieclip") c["block_" + p.idx]._x = PARK_X;
		c.attribute[p.idx] = 0;
		p.present = false;
		// Visuals stay: vizTick dims the door and shows the gate ghost.
	}

	static function resetHero():Void {
		var h = _root.hero;
		_root.container._y = 0;
		h._x = spawnX;
		h._y = spawnY;
		h.vy = 0;
		h.jump = false;
		h.lastblockhit = 0;
		// Clear native POWERUP contamination from the pre-takeover window: the
		// pinned hero can brush a random nail/inverse during the native game's
		// staged-init ticks (Ruffle RNG is unseeded, so this is per-run luck).
		// A live jetpack is poison: DJ's jetpack branch INCREMENTS
		// lastblockhit every rising tick, which our landing detection would
		// read as the hero landing on successive goal hosts — phantom
		// sendLocation/sendExit storms (the AP 3.1 in-play weirdness).
		h.jetpack = false;
		h.jetcount = 0;
		h.move_inversed = false;
		h.counter = 0;
		h.jumpspeed = 17;
		h.maxjump = 22;
		// ...and the jetpack ART: a nail pickup does hero.gotoAndStop(3/4)
		// (jetpack frames) and nothing restores the frame once the variable
		// is cleared (DJ only swaps frames on key input or jetpack expiry) —
		// the hero would keep wearing the jetpack + flame after takeover
		// (seen once on a Ruffle run). Frame 1 = the facing-right default;
		// all hero frames are bare stop()s, so the goto is side-effect-free.
		h.gotoAndStop(1);
		// Disable DJ's climb-recycle deletion (hero removes block_(lb-4) on
		// each climb landing): authored levels keep ALL platforms alive — the
		// bottom-fall respawn needs them back, and removeMovieClip of attached
		// clips hangs the browser-WASM runtime a tick later (status doc). The
		// hero's guard is `DeleteBlock > lastDeletedBlock`, so a huge value
		// means never.
		h.lastDeletedBlock = 999999;
		lastLb = 0;
		regionTick = 0;
		moverTick(); // movers take their t=0 position at the spawn state
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
		// While a jetpack is live, DJ increments lastblockhit every rising
		// tick (no landings happen) — never treat that march as landings.
		// Authored levels can't grant jetpacks (attribute is only ever 0/2),
		// but keep the guard in case one ever leaks in.
		if (_root.hero.jetpack == true) {
			lastLb = Number(_root.hero.lastblockhit);
			return;
		}
		var lb:Number = Number(_root.hero.lastblockhit);
		if (lb == lastLb) return;
		lastLb = lb;
		for (var i:Number = 0; i < plats.length; i++) {
			var p = plats[i];
			if (p.idx != lb) continue;
			if (p.goalKind == "loc" && checked[p.goalId] != true) {
				checked[p.goalId] = true;
				// Collected pickups stay readable: dim, don't remove (3.1).
				if (coins != undefined && typeof(coins[p.idx]) == "movieclip") {
					coins[p.idx]._alpha = 25;
				}
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
	// DBG fixture for the runtime-_alpha bug: side-by-side full vs _alpha=25
	// clips at fixed screen spots — container-attached coins (the cxform
	// path) and root drawing squares (the drawing-fold path). Screenshot any
	// time after tick 60; the dim one must render faint on every tier.
	static function placeAlphaTestClips():Void {
		var c = _root.container;
		var ly:Number = 60 - Number(c._y);
		var a1 = c.attachMovie("coin", "aptestA", 7771);
		a1._x = 50; a1._y = ly;
		var a2 = c.attachMovie("coin", "aptestB", 7772);
		a2._x = 85; a2._y = ly;
		a2._alpha = 25;
		var d1 = _root.createEmptyMovieClip("aptestC", 903001);
		d1.beginFill(0xCC2222, 100);
		d1.moveTo(140, 140); d1.lineTo(160, 140); d1.lineTo(160, 160);
		d1.lineTo(140, 160); d1.lineTo(140, 140);
		d1.endFill();
		var d2 = _root.createEmptyMovieClip("aptestD", 903002);
		d2.beginFill(0xCC2222, 100);
		d2.moveTo(170, 140); d2.lineTo(190, 140); d2.lineTo(190, 160);
		d2.lineTo(170, 160); d2.lineTo(170, 140);
		d2.endFill();
		d2._alpha = 25;
		trace("[dbg] aptest placed");
	}

	static function dumpClips():Void {
		var c = _root.container;
		for (var n:String in c) {
			if (typeof(c[n]) != "movieclip") continue;
			trace("[dump] c." + n + " x=" + c[n]._x + " y=" + c[n]._y
			      + " a=" + Math.round(c[n]._alpha) + " vis=" + c[n]._visible);
		}
		for (var m:String in _root) {
			if (typeof(_root[m]) != "movieclip") continue;
			trace("[dump] r." + m + " x=" + _root[m]._x + " y=" + _root[m]._y);
		}
	}

	static function statusTrace():Void {
		var h = _root.hero;
		var line:String = "LT" + tick + " hx=" + h._x + " hy=" + h._y
		      + " vy=" + h.vy + " cy=" + _root.container._y + " lb=" + lastLb
		      + " sc=" + h.score + " rt=" + regionTick;
		// Present movers append their current center x (table validation).
		for (var i:Number = 0; i < plats.length; i++) {
			var p = plats[i];
			if (p.type == "m" && p.present && !isNaN(p.sweepMin)) {
				line += " mx" + p.idx + "=" + _root.container["block_" + p.idx]._x;
			}
		}
		trace(line);
	}
}
