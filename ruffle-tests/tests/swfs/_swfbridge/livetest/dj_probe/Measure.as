// Measure.as — injected-AS PHYSICS MEASUREMENT probe for Doodle Jump.
//
// Companion to Probe.as (the feasibility probe). Compiled by MTASC and spliced
// into DJ's SWF by build_measure.sh, which seds __EXP__ to select the
// experiment. Emits one machine-parseable "M t=..." trace line per tick plus
// POKE/TRIAL/RESULT/HERO event lines; parse_measure.py converts trace.txt into
// the JSON schema requested by Archipelago-CC's dj-physics-measurement-spec.
//
// Experiments (EXP):
//   ff_rest   : free fall from rest, all platforms swept off-stage
//   ff_launch : upward launch (vy=-40) from low on screen; scroll-threshold data
//   bounce    : natural plain-platform bounces (steered over next block)
//   spring    : convert a block to spring, steer onto it
//   keys      : hero frozen vertically; arrow keys driven by input json (air
//               control + screen wrap)
//   catch     : landing-span trials at varying x offsets + terminal-velocity
//               drops (snap/tunneling)
//   blue      : force a block to frame 3 (moving); trace sweep; drop hero on it
//   brown     : force attribute=2 + frame 2 (breaking); observe break semantics
//   jetpack   : set hero.jetpack=true; sustained-thrust trace
class Measure {
	static var EXP:String = "__EXP__";
	static var FORCE_GOTO_TICK:Number = 2;
	static var T0:Number = 10;
	static var MAX:Number = 0;
	static var tick:Number = 0;
	static var started:Boolean = false;
	static var quitAt:Number = -1;

	// mode state
	static var target:Number = -1;
	static var childName:String = null;
	static var offsets:Array;
	static var trialIdx:Number = 0;
	static var trialTick:Number = 0;
	static var phase:Number = 0;
	static var lastDrop:Number = 0;

	static function maxFor(e:String):Number {
		if (e == "ff_rest")   return 130;
		if (e == "ff_launch") return 260;
		if (e == "bounce")    return 320;
		if (e == "spring")    return 280;
		if (e == "keys")      return 150;
		if (e == "catch")     return 470;
		if (e == "blue")      return 380;
		if (e == "brown")     return 280;
		if (e == "jetpack")   return 230;
		return 200;
	}

	static function main(mc:MovieClip):Void {
		MAX = maxFor(EXP);
		trace("MEAS start exp=" + EXP + " max=" + MAX + " cf=" + _root._currentframe);
		var clip:MovieClip = _root.createEmptyMovieClip("__probe__", 1048570);
		clip.onEnterFrame = function():Void { Measure.tickFn(); };
	}

	static function heroInfo():Void {
		var h = _root.hero;
		trace("HERO t=" + tick + " w=" + h._width + " hh=" + h._height
		      + " xr=" + h.xradius + " yr=" + h.yradius
		      + " SW=" + Stage.width + " SH=" + Stage.height
		      + " hx=" + h._x + " hy=" + h._y + " grav=" + h.gravity
		      + " js=" + h.jumpspeed + " mj=" + h.maxjump);
	}

	static function rec(extra:String):Void {
		var h = _root.hero;
		var c = _root.container;
		var s:String = "M t=" + tick + " cf=" + _root._currentframe + " tm=" + getTimer();
		if (typeof(h) == "movieclip") {
			s += " hx=" + h._x + " hy=" + h._y + " vy=" + h.vy + " j=" + h.jump
			   + " lbh=" + h.lastblockhit + " jsf=" + h.jumpspeed_factor
			   + " mj=" + h.maxjump + " js=" + h.jumpspeed
			   + " jp=" + h.jetpack + " jc=" + h.jetcount + " inv=" + h.move_inversed;
		}
		if (typeof(c) == "movieclip") s += " cy=" + c._y;
		s += " k37=" + Key.isDown(37) + " k39=" + Key.isDown(39) + " go=" + _root.gameOver;
		if (extra != null && extra != "") s += " " + extra;
		trace(s);
	}

	static function binfo(i:Number):String {
		var c = _root.container;
		var b = c["block_" + i];
		if (typeof(b) != "movieclip") return "bi=" + i + " bgone=1";
		var g:Object = b.getBounds(c);
		var gr:Object = b.getBounds(_root);
		var s:String = "bi=" + i + " bx=" + b._x + " by=" + b._y + " bf=" + b._currentframe
		     + " bxm=" + g.xMin + " bxM=" + g.xMax + " bym=" + g.yMin + " byM=" + g.yMax
		     + " sxm=" + gr.xMin + " sxM=" + gr.xMax + " sym=" + gr.yMin + " syM=" + gr.yMax
		     + " attr=" + c.attribute[i];
		if (childName != null) {
			var ch = b[childName];
			if (typeof(ch) == "movieclip") s += " chx=" + ch._x + " chy=" + ch._y;
		}
		return s;
	}

	// move every platform/powerup except block_<except> far off stage
	static function sweepAll(except:Number):Void {
		var c = _root.container;
		if (typeof(c) != "movieclip") return;
		for (var n:String in c) {
			if (typeof(c[n]) != "movieclip") continue;
			if (n.indexOf("block_") != 0 && n.indexOf("spring_") != 0
			    && n.indexOf("nail_") != 0 && n.indexOf("inverse_") != 0
			    && n.indexOf("coin_") != 0) continue;
			if (except >= 0 && n == ("block_" + except)) continue;
			if (c[n]._x > -2000) c[n]._x = -3000;
		}
	}

	// first normal (attr==0), non-blue (block._x != 0) block ahead of
	// lastblockhit whose screen-y (bounds yMin in _root) is in [syMin, syMax]
	static function findTarget(syMin:Number, syMax:Number):Number {
		var h = _root.hero;
		var c = _root.container;
		var lbh:Number = Number(h.lastblockhit);
		if (isNaN(lbh)) lbh = 0;
		var i:Number = lbh + 1;
		while (i <= lbh + 9) {
			var b = c["block_" + i];
			if (typeof(b) == "movieclip" && c.attribute[i] == 0 && b._x != 0) {
				var gr:Object = b.getBounds(_root);
				if (gr.yMin >= syMin && gr.yMin <= syMax) return i;
			}
			i++;
		}
		// fallback: any normal non-blue block ahead
		i = lbh + 1;
		while (i <= lbh + 9) {
			var b2 = c["block_" + i];
			if (typeof(b2) == "movieclip" && c.attribute[i] == 0 && b2._x != 0) return i;
			i++;
		}
		return -1;
	}

	static function steerTo(i:Number):Void {
		var h = _root.hero;
		var c = _root.container;
		var b = c["block_" + i];
		if (typeof(b) != "movieclip") return;
		var gr:Object = b.getBounds(_root);
		h._x = (gr.xMin + gr.xMax) / 2;
	}

	static function tickFn():Void {
		tick++;
		if (tick == FORCE_GOTO_TICK && !started) {
			started = true;
			trace("MEAS goto2");
			_root.gotoAndPlay(2);
		}
		var h = _root.hero;
		var c = _root.container;
		var heroReady:Boolean = (typeof(h) == "movieclip" && typeof(c) == "movieclip");

		// ---- record first (pre-poke state), then mode logic ----
		var extra:String = "";
		if (heroReady && target >= 0) extra = binfo(target);
		if (EXP == "spring" && heroReady && target >= 0) {
			var sp = c["spring_" + target];
			if (typeof(sp) == "movieclip") extra += " spf=" + sp._currentframe + " spx=" + sp._x + " spy=" + sp._y;
		}
		if (EXP == "bounce" && heroReady) {
			var lb:Number = Number(h.lastblockhit);
			if (!isNaN(lb)) extra = binfo(lb);
		}
		rec(extra);

		if (heroReady) {
			if (EXP == "ff_rest")   modeFF(false);
			else if (EXP == "ff_launch") modeFF(true);
			else if (EXP == "bounce")    modeBounce();
			else if (EXP == "spring")    modeSpring();
			else if (EXP == "keys")      modeKeys();
			else if (EXP == "catch")     modeCatch();
			else if (EXP == "blue")      modeBlue();
			else if (EXP == "brown")     modeBrown();
			else if (EXP == "jetpack")   modeJetpack();
		}

		if (_root._currentframe == 3 && quitAt < 0) quitAt = tick + 3;
		if (tick >= MAX || (quitAt > 0 && tick >= quitAt)) {
			trace("MEAS done t=" + tick);
			fscommand("quit", "");
		}
	}

	// ---- ff_rest / ff_launch ------------------------------------------------
	static function modeFF(launch:Boolean):Void {
		var h = _root.hero;
		if (tick >= T0) sweepAll(-1);
		if (tick == T0) {
			heroInfo();
			h.jump = false;
			h._x = 60;
			if (launch) { h._y = 360; h.vy = -40; }
			else        { h._y = -600; h.vy = 0; }
			trace("POKE " + EXP + " teleport hx=60 hy=" + h._y + " vy=" + h.vy);
		}
	}

	// ---- bounce: natural physics, steered over the next block ---------------
	static function modeBounce():Void {
		var h = _root.hero;
		if (tick > T0 && Number(h.vy) > 0) {
			var ni:Number = Number(h.lastblockhit) + 1;
			steerTo(ni);
		}
	}

	// ---- spring --------------------------------------------------------------
	static function modeSpring():Void {
		var h = _root.hero;
		var c = _root.container;
		if (tick == T0) {
			heroInfo();
			target = findTarget(100, 330);
			if (target < 0) { trace("POKE spring NO TARGET"); return; }
			c.attribute[target] = 1;
			var b = c["block_" + target];
			var sp = c.attachMovie("spring", "spring_" + target, c.getNextHighestDepth());
			sp._x = b._x;
			sp._y = b._y;
			trace("POKE spring target=" + target + " " + binfo(target));
		}
		if (tick > T0 && target >= 0 && Number(h.vy) > 0) steerTo(target);
	}

	// ---- keys: freeze hero vertically; harness drives arrow keys -------------
	static function modeKeys():Void {
		var h = _root.hero;
		if (tick >= T0) sweepAll(-1);
		if (tick == T0) heroInfo();
		if (tick >= T0) { h.vy = 0; h.jump = false; h._y = 200; }
	}

	// ---- catch: landing-span trials -------------------------------------------
	static function modeCatch():Void {
		var h = _root.hero;
		var c = _root.container;
		if (tick > T0) sweepAll(target);  // AFTER target selection only
		if (tick == T0) {
			heroInfo();
			target = findTarget(140, 300);
			offsets = [0, 20, 40, 44, 46, 48, 50, 51, 52, 53, 54, 56, 60,
			           -20, -40, -44, -46, -48, -50, -51, -52, -53, -54, -56, -60];
			trialIdx = -1;
			phase = 0;
			trace("POKE catch target=" + target + " " + binfo(target));
		}
		if (tick <= T0 || target < 0) return;
		var b = c["block_" + target];
		if (typeof(b) != "movieclip") { trace("CATCH target gone"); target = -1; return; }
		var gr:Object = b.getBounds(_root);
		var bcx:Number = (gr.xMin + gr.xMax) / 2;
		var btop:Number = gr.yMin;
		if (phase == 0) {
			trialIdx++;
			var off:Number = 0;
			var dy:Number = 70;
			if (trialIdx >= offsets.length) {
				if (trialIdx >= offsets.length + 6) {
					if (quitAt < 0) quitAt = tick + 2;
					return;
				}
				off = 0; dy = 300;  // terminal-velocity drops
			} else off = offsets[trialIdx];
			h.jump = false; h.vy = 0; h.move_inversed = false;
			h._x = bcx + off;
			h._y = btop - dy;
			trialTick = tick;
			phase = 1;
			trace("TRIAL i=" + trialIdx + " off=" + off + " dy=" + dy
			      + " btop=" + btop + " bcx=" + bcx + " hx=" + h._x);
		} else {
			var feet:Number = Number(h._y) + Number(h.yradius);
			if (h.jump == true || Number(h.vy) < -4) {
				trace("RESULT i=" + trialIdx + " landed=1 feet=" + feet + " btop=" + btop
				      + " hx=" + h._x + " vy=" + h.vy + " dt=" + (tick - trialTick));
				phase = 0;
			} else if (feet > btop + 45 || tick - trialTick > 30) {
				trace("RESULT i=" + trialIdx + " landed=0 feet=" + feet + " btop=" + btop
				      + " hx=" + h._x + " vy=" + h.vy + " dt=" + (tick - trialTick));
				phase = 0;
			}
		}
	}

	// ---- blue: force frame 3, trace sweep, then drop hero onto it ------------
	static function modeBlue():Void {
		var h = _root.hero;
		var c = _root.container;
		if (tick > T0) sweepAll(target);  // AFTER target selection only
		if (tick == T0) {
			heroInfo();
			target = findTarget(100, 330);
			if (target < 0) { trace("POKE blue NO TARGET"); return; }
			var b = c["block_" + target];
			b.gotoAndStop(3);
			for (var n:String in b) {
				if (typeof(b[n]) == "movieclip") { childName = n; break; }
			}
			trace("POKE blue target=" + target + " child=" + childName + " " + binfo(target));
			lastDrop = tick + 140;  // pure sweep observation first
		}
		if (tick <= T0 || target < 0) return;
		// keep hero parked away from the block during sweep observation
		var b2 = c["block_" + target];
		if (typeof(b2) != "movieclip") return;
		var gr:Object = b2.getBounds(_root);
		if (tick < T0 + 140) {
			h.vy = 0; h.jump = false; h._y = 60; h._x = 120;
		} else if (Number(h._y) > 350) {
			// missed the moving block: rescue before the death line
			h.vy = 0; h.jump = false; h._y = 60;
			trace("RESCUE t=" + tick);
		} else if (tick == lastDrop) {
			h.jump = false; h.vy = 0;
			h._x = (gr.xMin + gr.xMax) / 2;
			h._y = gr.yMin - 20;
			trace("DROP t=" + tick + " hx=" + h._x + " hy=" + h._y
			      + " bxm=" + gr.xMin + " bxM=" + gr.xMax + " sym=" + gr.yMin);
			lastDrop = tick + 50;
		}
	}

	// ---- brown: force attribute=2 + frame 2; drop hero; watch the break ------
	static function modeBrown():Void {
		var h = _root.hero;
		var c = _root.container;
		if (tick > T0) sweepAll(target);  // AFTER target selection only
		if (tick == T0) {
			heroInfo();
			target = findTarget(100, 330);
			if (target < 0) { trace("POKE brown NO TARGET"); return; }
			c.attribute[target] = 2;
			var b = c["block_" + target];
			b.gotoAndStop(2);
			trace("POKE brown target=" + target + " " + binfo(target));
			lastDrop = tick + 4;
		}
		if (tick <= T0 || target < 0) return;
		var b2 = c["block_" + target];
		if (typeof(b2) != "movieclip") { trace("BROWN block removed t=" + tick); return; }
		// once broken (frame 4), find the falling child for chy tracking
		if (childName == null && b2._currentframe == 4) {
			for (var n:String in b2) {
				if (typeof(b2[n]) == "movieclip") { childName = n; break; }
			}
			trace("BROKE t=" + tick + " child=" + childName);
		}
		if (Number(h._y) > 350) {
			// fell past the (broken) block: rescue, keep x -> natural re-drop
			h.vy = 0; h.jump = false; h._y = 60;
			trace("RESCUE t=" + tick);
		} else if (tick == lastDrop) {
			var gr:Object = b2.getBounds(_root);
			h.jump = false; h.vy = 0;
			h._x = (gr.xMin + gr.xMax) / 2;
			h._y = gr.yMin - 80;
			trace("DROP t=" + tick + " hx=" + h._x + " hy=" + h._y + " sym=" + gr.yMin);
			lastDrop = tick + 60;  // second drop later, during/after crumble
		}
	}

	// ---- jetpack ---------------------------------------------------------------
	static function modeJetpack():Void {
		var h = _root.hero;
		if (tick > T0 && tick < T0 + 4 && Number(h.vy) > 0) {
			steerTo(Number(h.lastblockhit) + 1);
		}
		if (tick == T0 + 4) {
			heroInfo();
			h.jetpack = true;
			trace("POKE jetpack=true t=" + tick + " hy=" + h._y + " vy=" + h.vy);
		}
	}
}
