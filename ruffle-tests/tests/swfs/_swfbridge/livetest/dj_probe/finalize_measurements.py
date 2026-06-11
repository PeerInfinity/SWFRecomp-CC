#!/usr/bin/env python3
"""finalize_measurements.py — stamp setup/notes prose into each per-run JSON and
emit the consolidated dj_constants_summary.json for the Archipelago-CC handoff."""
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
JDIR = HERE / "measurements" / "json"

SETUPS = {
    "ff_rest": "Forced _root.gotoAndPlay(2) at tick 2. At tick 10 the probe teleported the hero to (60,-600) with vy=0 and jump=false; from tick 10 onward every platform/powerup clip in the container was swept to x=-3000 each tick so the hero fell ballistically until the y>400 death line. M-lines are recorded at the top of the probe's onEnterFrame, BEFORE that tick's pokes; the hero's own enterFrame (the physics step) runs before the probe's each tick, so each record shows the post-physics state of that tick.",
    "ff_launch": "Same harness as ff_rest, but the tick-10 poke set the hero to (60,360) with vy=-40 (stronger than a plain bounce, weaker than a spring) to observe rising gravity and the scroll branch. Platforms swept to x=-3000 every tick.",
    "bounce": "Forced gameplay, NO physics pokes. The probe only steered horizontally: while vy>0 it set hero._x to the screen-bounds center of block_(lastblockhit+1), so the hero bounces up the platform stack forever. Each M-line carries binfo for block_lastblockhit (bxm..byM = bounds in container coords, sxm..syM = bounds in root/screen coords).",
    "spring": "At tick 10 the probe picked the first normal (attribute==0, non-blue) block ahead, set container.attribute[i]=1 and attached a 'spring' clip at the block's (_x,_y) (matching the spawner's placement: spring._y == block._y). Hero steered onto it while falling. jsf in the M-line is hero.jumpspeed_factor; spf is the spring clip's current frame.",
    "keys": "Hero frozen vertically from tick 10 (every probe tick: vy=0, jump=false, _y=200) and all platforms swept away, so hero._x is driven ONLY by DJ's own Key.isDown handling. Native tier: file-driven input events (KeyDown/KeyUp Right then Left then both, see input_measure_keys.json). Ruffle tier: real Chrome keydown/keyup of ArrowRight then ArrowLeft via Playwright (no both-keys phase). k37/k39 in each M-line are Key.isDown(37)/Key.isDown(39) as DJ sees them.",
    "catch": "At tick 10 the probe picked a normal block on screen; from tick 11 every OTHER platform/powerup was swept to x=-3000 each tick. Trials: teleport hero to x = block-bounds-center + offset, y = block-top(screen) - dy, with vy=0/jump=false; watch for landing (hero.jump latched or vy < -4) vs miss (feet passing 45px below block top). offsets probe the catch half-span; the 6 final trials use dy=300 so impact is at terminal velocity (tunneling/snap check). TRIAL/RESULT lines carry per-trial data; feet = hero._y + yradius(22.5).",
    "blue": "At tick 10 the probe picked a normal block and forced it to cloud frame 3 (the moving/'blue' state; the game itself does exactly this at spawn for ~1/10 of blocks, with block._x=0). The inner mover child (named 'aaa') was found by enumeration; chx/chy in each M-line are its block-local coords. Ticks 10..150: hero parked at (120,60) (vy zeroed each tick) for a clean sweep observation. After tick 150: hero dropped onto the moving platform every ~50 ticks from 20px above (bounce + velocity-inheritance check), with an auto-rescue teleport if it missed.",
    "brown": "At tick 10 the probe picked a normal block, set container.attribute[i]=2 and forced cloud frame 2 (the game's breaking-platform spawn state); other platforms swept away each tick. Hero dropped onto it from 80px above; auto-rescue (teleport to y=60, same x) whenever the hero passed y>350, producing repeated drops onto the breaking/falling debris. chx/chy track the frame-4 debris child once it appears; bf is the block's current frame.",
    "jetpack": "Natural bouncing until tick 14, then hero.jetpack=true poked once (equivalent to touching the 'Nail' pickup, attribute 3). No further pokes; the run records the full thrust phase (jetcount 1..100), the post-jetpack fall, and death.",
}

NOTES = {
    ("ff_rest", "native"): "vy increments by exactly +4/tick from rest and clamps at exactly 22 (43 consecutive ticks at 22 until ground). All _x/_y values are twip-quantized (1/20 px). The pre-teleport ticks (3-9) include one natural landing - ignore for freefall extraction.",
    ("ff_rest", "ruffle"): "Byte-identical to the native run for every tick of the teleported fall (ticks 11-55 hy/vy match exactly). Ruffle ignores fscommand quit, so the trace continues past MAX on the death screen; tick rate measured from getTimer deltas = 20.02 Hz over 14s.",
    ("ff_launch", "native"): "Rising vy also changes by exactly +4/tick (same constant rising vs falling). No cap on rising speed was hit at vy=-40 (cap only applies to vy > maxjump, i.e. falling).",
    ("ff_launch", "ruffle"): "hy/vy identical to native for the whole launch arc; only the absolute container._y offset differs (different pre-poke bounce history from layout RNG). Confirms gravity/scroll on ground truth.",
    ("bounce", "native"): "Every plain landing: vy=0 on the hit tick (hit registered with a one-tick lookahead at feet+vy), then vy=-28.2999995946884 on the next tick (= -(17 * 1.89999997615814) + 4). World-space rise per bounce 114.05-114.1 px (world_y = hy - cy). Successive block origins are exactly 55.15 px apart vertically (= block bbox height 40.15 + distance 15).",
    ("bounce", "ruffle"): "First two landings byte-identical to native (same ticks, same vy). Ruffle's layout RNG diverges from native after that, but every landing shows the identical impulse/apex; this run also includes one NATURAL spring (jsf=4, vy_next=-64, rise 544.0) confirming the spring impulse on ground truth without any poke.",
    ("spring", "native"): "Spring landing: vy zeroed on hit tick, vy=-64 next tick (= -(17*4) + 4), world rise 544.0 px. maxjump stays 22; jumpspeed_factor returns to 1.9 on the next plain landing.",
    ("keys", "native"): "dx = +10 while only Right held, -10 while only Left held, 0 while BOTH held (both branches run: +10-10), 0 immediately on release (no momentum, no decay; there is NO vx variable in the game at all). Wrap: at x_before=258.6/260 the next tick lands at exactly 0 (right edge); from -20 the next tick is exactly 240 (left edge). With xradius=23 this matches the game's rule: wrap when x-23 > 240 (entirely off the right edge -> x=0) or x < -23 (entirely off the left -> x=240). Instant teleport, single tick, never on both sides at once. The +-258/-20 jumps in dx stats are the wraps, and the 99.65 value is the tick-10 freeze poke artifact.",
    ("keys", "ruffle"): "Real DOM ArrowRight/ArrowLeft through Chrome/Ruffle: identical +10/-10 flat per-tick deltas and identical wrap teleports (258.6->0, 260->0, -20->240). No both-keys phase on this tier (covered natively).",
    ("catch", "native"): "Landing span measured around the block-bounds center (block bbox 60 wide x 40.15 tall): offsets -52..+53 land, -53/+54 miss (the asymmetry at the exact edge is twip rounding of the fractional block x). Implies half-span = blockWidth/2 (30) + hero xradius (23) = 53, i.e. the hit test is two point-tests at the hero's feet at x +- 23. Landing leaves the hero's feet ABOVE the block top: feet-btop = -7.5 at vy=16 impact, -19.55 at terminal vy=22 (the lookahead test fires while the predicted point is inside the 40px-tall bbox; the hero never sinks to the surface; NO snap-to-top). Terminal-velocity drops landed 6/6: tunneling is impossible because the bbox band (40.15px) is taller than the max fall step (22px). One-way: the hit-test loop only runs while vy>0 (structural; visible in every rising segment).",
    ("blue", "native"): "DIVERGENCE (native loses): after the forced gotoAndStop(3), the inner mover child never runs its enterFrame in the SWFRecomp graphics-native build - the block's bounds stay frozen (bxm constant) and chx stays 0. Ruffle (ground truth) shows the real sweep. Landings on the (static) block still show the plain -28.3 impulse and an unchanged hero._x (no inheritance).",
    ("blue", "ruffle"): "GROUND TRUTH for blue. Inner child starts at local x=0 moving +5 (the clip's load handler hardcodes ac=5; NO RNG anywhere in the mover): dx is exactly +-5 every tick, uniform (no easing). Steady-state local-x range 15..195 (reversal AFTER crossing: x>190 -> ac=-5, so it turns at 195; x<20 -> ac=+5, turns at 15); period 72 ticks (reversals every 36). For a natural blue spawn block._x=0, so the platform's 60px bbox center sweeps container x 15..195. Landing on the moving platform: same -28.3 impulse as green, and hero._x is UNCHANGED on and after the hit tick (hx_next3 constant) - the hero does NOT inherit platform velocity. Phase is deterministic given the spawn tick (same start pos, same direction every time).",
    ("brown", "native"): "Matches Ruffle for the bounce semantics (vy NOT zeroed: vy_next = vy_at_hit - 32.3 + 4; measured 20 -> -8.3). DIVERGENCE (native loses): the frame-4 debris child does not run its enterFrame natively, so the debris never falls; re-hits happen on the frozen bbox instead.",
    ("brown", "ruffle"): "GROUND TRUTH for brown. The hero DOES bounce off a breaking platform (this Flash DJ differs from canonical mobile DJ): hit tick latches jump with jsf=1.9 but does NOT zero vy, so vy_next = vy_at_hit - 32.2999995946884 + 4 (measured: 20 -> -8.3; 22 -> -6.3). The block jumps to frame 4 on the SAME tick as the hit; the debris child then falls at exactly +8 px/tick (block-local chy), forever - removeMovieClip(block) in the frame-4 script is dead code (it checks _y<0 while _y grows, and 'block' doesn't resolve in that scope), so the falling debris REMAINS LANDABLE indefinitely: repeated weak bounces measured at ticks 27/37/45/53 while it fell. It is only cleaned up by the game's lastblockhit-4 deletion sweep. Crumble delay between touch and visual break: 0 ticks.",
    ("jetpack", "native"): "Sustained thrust, not an impulse: while jetpack is true the game re-latches jump every tick with jumpspeed=10, jsf=0.5, so each tick vy += -5 (impulse) + 4 (gravity) = net -1 px/tick^2 upward. Duration exactly 100 ticks (jetcount 1..100), vy reached -95.3 (NO rising speed cap), world rise during thrust 4578.9 px. Afterwards jumpspeed reverts to 17, jetpack/jetcount reset, normal gravity fall (capped at 22) resumes. Pickup = 'Nail' clip (attribute 3) hitTest while falling. No horizontal effect.",
}


def main():
    runs = []
    for f in sorted(JDIR.glob("*.json")):
        if f.name == "dj_constants_summary.json":
            continue
        d = json.load(open(f))
        exp = d["experiment"]
        tier_short = "ruffle" if d["tier"].startswith("ruffle") else "native"
        d["setup"] = SETUPS.get(exp)
        d["notes"] = NOTES.get((exp, tier_short), d.get("notes") or "")
        if tier_short == "native":
            d["measured_tick_rate_hz"] = None
            d["tick_rate_note"] = ("native headless runs offline (not wall-clock paced); "
                                   "tick rate is meaningless on this tier. Use the Ruffle runs (20.0 Hz).")
        json.dump(d, open(f, "w"), indent=1)
        runs.append((d["run_id"], exp, d["tier"]))
        print("stamped", f.name)

    P = "px/tick"
    P2 = "px/tick^2"
    summary = {
        "_about": "Doodle Jump (Flash, SWF v8) measured physics constants and semantics for the Archipelago-CC bounceDemo 'dj' profile. ALL values are in DJ-native units (px and ticks at the SWF's native tick rate). Provenance run_ids refer to the JSON files in this directory. 'code:' provenance = read from the decompiled hero enterFrame (clip_action_29) / container spawner and CONFIRMED by the named run.",
        "frame_rate": {
            "swf_header_fps": 20.0,
            "measured_tick_rate_hz_ruffle": 20.02,
            "measured_tick_rate_hz_native": None,
            "provenance": "header parsed from test.swf; ruffle rate from getTimer() deltas over 14-24s in ff_rest_ruffle_01 / blue_ruffle_01; native tier is offline/headless so wall-clock rate is meaningless there",
        },
        "stage": {"width_px": 240, "height_px": 400, "provenance": "SWF header RECT; Stage.width/height read by probe (HERO line, all runs)"},
        "hero": {
            "bbox_w_px": 46, "bbox_h_px": 45,
            "xradius_px": 23, "yradius_px": 22.5,
            "note": "xradius/yradius are captured ONCE in the hero load handler (this._width/2) and used for all hit tests and wrap checks",
            "provenance": "HERO lines, all runs (both tiers identical)",
        },
        "gravity": {
            "value_px_per_tick2": 4.0,
            "same_rising_and_falling": True,
            "curve": "constant increment, no curve",
            "terminal_fall_vy_px_per_tick": 22.0,
            "terminal_note": "cap is 'if (vy > maxjump) vy = maxjump' with maxjump reset to 22 on every landing; NO cap on rising (negative) vy - jetpack reached vy=-95.3",
            "rising_cap": None,
            "provenance": "ff_rest_native_01 + ff_rest_ruffle_01 (byte-identical falls), ff_launch_* for rising, jetpack_native_01 for no-rising-cap",
        },
        "position_quantization": {
            "value": "all _x/_y are twip-quantized (multiples of 0.05 px, truncated)",
            "provenance": "visible in every trace (e.g. container _y deltas 20.25 for vy -20.3)",
        },
        "bounce_impulses": {
            "structural": "landing latches jump=true; the IMPULSE is applied on the NEXT tick: vy -= jumpspeed*jumpspeed_factor, then gravity (+4) is added the same tick before movement. Plain/spring landings also zero vy on the hit tick itself; brown does NOT zero vy.",
            "plain": {
                "vy_tick_after_landing": -28.2999995946884,
                "formula": "0 - 17*1.89999997615814 + 4",
                "apex_above_hit_point_px": 114.1,
                "zeroes_vy_on_hit_tick": True,
                "provenance": "bounce_native_01 + bounce_ruffle_01 (identical)",
            },
            "spring": {
                "vy_tick_after_landing": -64.0,
                "formula": "0 - 17*4 + 4",
                "apex_above_hit_point_px": 544.0,
                "zeroes_vy_on_hit_tick": True,
                "trigger": "spring.hitTest(hero) full-bbox overlap (not just feet), only evaluated while vy>0; spring sits on TOP of a normal block (attribute 1 spawns block + spring)",
                "provenance": "spring_native_01 (poked spring) + bounce_ruffle_01 (NATURAL spring, identical numbers)",
            },
            "brown_breaking": {
                "vy_tick_after_landing": "vy_at_hit - 32.2999995946884 + 4 (vy NOT zeroed; depends on fall speed: 20 -> -8.3, terminal 22 -> -6.3; range -6.3 .. -28.3)",
                "provenance": "brown_ruffle_01 (ground truth) + brown_native_01 (same bounce math)",
            },
            "horizontal_effect_of_landing": "none - hero._x unchanged on/after every hit; no vx exists to zero, no kick",
        },
        "air_control": {
            "structural": "FLAT per-tick displacement, no acceleration, no velocity state. hero._x += 10 while Key.isDown(39), hero._x -= 10 while Key.isDown(37); both branches run independently so both-held = 0; release = instant stop; identical during rise/fall/apex (the x code runs before any y physics, unconditionally).",
            "dx_px_per_tick": 10.0,
            "both_keys_cancel": True,
            "release": "instant stop (dx=0 the very next tick)",
            "vx_state": "none (structural - confirmed: no momentum ever observed)",
            "tilt_path_note": "there is also an accelerometer path (hero._x += _level1.ay*13) but _level1 (motion.swf) never loads in any runtime; Number(undefined)*13 = NaN and NaN position writes are ignored, so it is inert",
            "inverse_powerup": "attribute 6 ('Inverse' pickup) flips the +/- for 80 ticks (counter in hero enterFrame), then auto-reverts (code-derived; not trace-measured)",
            "provenance": "keys_native_01 (file-driven keys incl. both-held) + keys_ruffle_01 (real Chrome arrow keys; identical)",
        },
        "screen_wrap": {
            "rule": "after the key move: if (x - 23 > 240) x = 0; if (x < -23) x = 240  (23 = xradius)",
            "semantics": "instant teleport of _x in the same tick, only when the hero is ENTIRELY off-screen; the hero is never on both sides at once; wrap target is the bare stage edge (0 or 240 = hero CENTER at the edge, so it re-enters half-visible)",
            "measured": "rightward: x=258.6 (then +10 -> 268.6 internally) -> 0 next tick; leftward: x=-20 (then -10 -> -30) -> 240 next tick",
            "vy_unaffected": True,
            "provenance": "keys_native_01 + keys_ruffle_01 (identical wrap ticks)",
        },
        "platform_catch": {
            "structural": "while vy>0 (falling only - rising passes through, one-way confirmed) the hero tests blocks i = lastblockhit-3 .. lastblockhit+9 with TWO POINT tests at (x-23, feet+vy) and (x+23, feet+vy), feet = _y + 22.5, against the block's CURRENT-FRAME BBOX (no shapeflag). One-tick lookahead: the test point is where the feet WILL be next tick.",
            "block_bbox_w_px": 60.0,
            "block_bbox_h_px": 40.15,
            "catch_half_span_px": 53.0,
            "half_span_formula": "blockWidth/2 (30) + xradius (23)",
            "measured_span": "offsets -52..+53 from block-bounds center land; -53 and +54 miss (exact-edge result is twip-rounding dependent)",
            "landing_snap": "NONE - vy is zeroed where the lookahead fired, leaving the feet 7.5px (slow impact) to 19.55px (terminal impact) ABOVE the bbox top; the hero never sinks to the surface and never embeds",
            "tunneling": "impossible: bbox band (40.15px tall) > max fall step (22px); 6/6 terminal drops landed",
            "provenance": "catch_native_01 (25 offset trials + 6 terminal drops); cross-checked implicitly by every Ruffle landing",
        },
        "scroll_camera": {
            "structural": "movement step: if (vy < 0 AND pre-move hero._y < 185) then container._y -= vy and score += -Math.round(vy), hero stays; else hero._y += vy. Hero rising above screen y=185 scrolls the world instead.",
            "threshold_screen_y": 185.0,
            "threshold_comparison": "strict <, evaluated on the PRE-move hero _y",
            "measured": "max pre-move hy that scrolled = 184.8; min pre-move hy that moved while rising = 185.1 (both tiers)",
            "world_mapping": "world_y = screen_y - container._y (container only ever moves DOWN, i.e. _y increases; blocks live in container space; hero lives in screen space). container._y deltas are twip-truncated |vy|.",
            "score": "score increments by round(|vy|) per scroll tick; score IS the height-in-px climbed above the threshold line",
            "death_line": "if (hero._y + hero._height/2 > 400) gameOver = true (screen space)",
            "provenance": "bounce_*/spring_*/ff_launch_* traces, both tiers",
        },
        "platform_census": {
            "_attribute_array": "container.attribute[i] per block index; spawner picks ONE special per slot, priority order below (first match wins), else plain green. Probabilities are per-block at spawn (round(random()*N)==1 means p=1/N for N>=1.5).",
            "types": [
                {"attribute": 0, "name": "green / plain (cloud frame 1)", "semantics": "static; plain bounce (vy=0 then -28.3); the only type v1 needs beyond blue/brown", "probability": "remainder (~70-80%)"},
                {"attribute": 0, "name": "BLUE / moving (cloud frame 3; attribute STAYS 0)", "semantics": "same plain bounce as green; inner child sweeps local x at +-5 px/tick, uniform, reverses at >190 (turns at 195) and <20 (turns at 15), period 72 ticks; spawns at block._x=0 so the 60px platform's center sweeps container x 15..195; ALWAYS starts at local x=0 moving RIGHT (ac=5 hardcoded in the load handler - phase is deterministic given the spawn tick, NO RNG); hero does NOT inherit platform velocity; hit test uses the CURRENT bbox position each tick", "probability": "1/10 (after the specials below decline)"},
                {"attribute": 2, "name": "BROWN / breaking (cloud frame 2 at spawn)", "semantics": "hero DOES get a bounce (weakened: vy_next = vy_at_hit - 32.3 + 4, so -6.3 at terminal fall .. -28.3 in theory) AND the block breaks the same tick (frame 4); debris falls at +8 px/tick forever (the removal code is dead) and REMAINS LANDABLE - repeated weak bounces off falling debris measured; never two browns in a row (spawner checks previous block)", "probability": "1/6"},
                {"attribute": 1, "name": "spring (on top of a plain block)", "semantics": "full-bbox overlap while falling -> impulse -64, apex 544px; the carrier block still gives a plain bounce if the feet hit the block but miss the spring bbox; spring shows frame 2 (sprung) after trigger", "probability": "1/(15 - score/2000) - INCREASES with height (1/15 at start)"},
                {"attribute": 3, "name": "'Nail' = JETPACK pickup", "semantics": "full-bbox overlap while falling -> jetpack: sustained net -1 px/tick^2 for exactly 100 ticks (re-latched jump with jumpspeed=10, factor=0.5, minus gravity), no rising speed cap (vy reached -95.3), world rise ~4579px, then reverts; no horizontal effect", "probability": "1/80"},
                {"attribute": 6, "name": "'Inverse' pickup", "semantics": "full-bbox overlap while falling -> left/right controls REVERSED for 80 ticks, then auto-revert (code-derived)", "probability": "1/40"},
                {"attribute": 7, "name": "coin", "semantics": "full-bbox overlap while falling -> score += 500, clip removed", "probability": "1/40"},
            ],
            "no_other_types": "no white/vanishing, no vertical movers, no decoys in this Flash DJ. (A 'magicball'/attribute-2-adjacent powerup exists in code but lives in motion.swf/_level1 which never loads - dead.)",
            "spawning": {
                "vertical_gap": "next block._y = prev block._y - (block._height(40.15) + 15 + powerupHeight(17 spring/nail/coin, 20 inverse, else 0)) -> 55.15px plain spacing (measured)",
                "x": "random: blockWidth/2 .. 240-blockWidth/2 (centers 30..210); blue spawns at _x=0 (mover provides the x)",
                "lookahead": "maxblocks = lastblockhit + 9; blocks below lastblockhit-4 are removed as you climb",
            },
            "provenance": "decompiled spawner (levelcontainer DoAction) + blue_ruffle_01 + brown_ruffle_01 + bounce traces",
        },
        "tick_order_within_frame": {
            "value": "hero enterFrame order: (1) key/tilt x moves, (2) wrap, (3) consume pending jump -> impulse, (4) gameOver check, (5) vy += 4, clamp to 22, (6) death check, (7) move hero OR scroll container, (8) falling hit-test loop (lookahead, latches jump for next tick), (9) jetpack re-latch. The probe's clip runs AFTER the hero each tick, so M-lines show post-physics state.",
            "provenance": "decompiled clip_action_29, confirmed by every trace's phase relationships",
        },
        "cross_tier_findings": [
            "Physics parity native vs Ruffle is EXACT (byte-identical hy/vy per tick) for: freefall, launch, plain bounce, spring, keys/wrap, jetpack, catch mechanics.",
            "DIVERGENCE (Ruffle wins, per spec): nested timeline children of attachMovie'd clips do not run their onClipEvent(enterFrame) in the SWFRecomp graphics-native tier after a forced gotoAndStop - so blue platforms don't move and brown debris doesn't fall natively. Blue/brown per-type semantics in this summary are therefore taken from the Ruffle runs (blue_ruffle_01, brown_ruffle_01). (The browser-WASM production tier has a separate fix for this; the native gap only affects this headless measurement tier.)",
            "Platform-layout RNG differs across tiers (known, by design of the experiments: nothing above depends on a specific layout).",
        ],
    }
    out = JDIR / "dj_constants_summary.json"
    json.dump(summary, open(out, "w"), indent=1)
    print("wrote", out)


if __name__ == "__main__":
    main()
