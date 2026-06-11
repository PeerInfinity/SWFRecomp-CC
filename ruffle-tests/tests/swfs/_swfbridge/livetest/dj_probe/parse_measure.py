#!/usr/bin/env python3
"""parse_measure.py — convert a Measure.as trace (trace.txt / console.txt) into
the per-run JSON requested by Archipelago-CC's dj-physics-measurement-spec.

Usage:
  python3 parse_measure.py <trace_file> <experiment> <tier> <run_id> <out.json>

Tier names follow the dj_probe README: "ruffle-web" (tier 1, ground truth),
"swfrecomp-graphics-native" (tier 2, headless), "swfrecomp-graphics-wasm"
(tier 3, browser).

All numbers are RAW: px/tick and px/tick^2 at DJ's native tick rate. No unit
conversion is performed (per the spec, the requester converts)."""
import json
import re
import statistics
import sys

SWF_FPS_HEADER = 20.0  # parsed from the DJ SWF header (240x400, v8, 6 frames)


def conv(v):
    if v == "undefined" or v == "null":
        return None
    if v == "true":
        return True
    if v == "false":
        return False
    try:
        f = float(v)
        return int(f) if f == int(f) and "e" not in v.lower() else f
    except ValueError:
        return v


def parse_trace(path):
    recs, events = [], []
    for line in open(path, encoding="utf-8", errors="replace"):
        line = line.strip()
        # Ruffle console capture: "%cINFO%c web/src/log_adapter.rs:NN%c <msg> color: ..."
        rm = re.match(r"^%c\w+%c [^%]*%c (.*?)(?: color: whitesmoke.*)?$", line)
        if rm:
            line = rm.group(1).strip()
        m = re.match(r"^M (t=.*)$", line)
        if m:
            d = {}
            for kv in m.group(1).split(" "):
                if "=" in kv:
                    k, _, v = kv.partition("=")
                    d[k] = conv(v)
            recs.append(d)
            continue
        em = re.match(r"^(MEAS|HERO|POKE|TRIAL|RESULT|DROP|BROKE|RESCUE|CATCH|BROWN) (.*)$", line)
        if em:
            events.append({"kind": em.group(1), "raw": line})
    # dedup consecutive identical M ticks (frame-func re-runs)
    out = []
    for r in recs:
        if out and out[-1].get("t") == r.get("t"):
            continue
        out.append(r)
    return out, events


def spec_trace(recs):
    """Map raw records onto the spec's per-tick schema (plus raw extras)."""
    rows = []
    prev = None
    for r in recs:
        row = {
            "tick": r.get("t"),
            "x": r.get("hx"),
            "y": r.get("hy"),
            "dx": None,
            "dy": None,
            "keys": {"left": bool(r.get("k37")), "right": bool(r.get("k39"))},
            "events": [],
            "vy_var": r.get("vy"),
            "container_y": r.get("cy"),
            "root_frame": r.get("cf"),
            "timer_ms": r.get("tm"),
        }
        for k in ("j", "lbh", "jsf", "mj", "js", "jp", "jc", "inv", "go",
                  "bi", "bx", "by", "bf", "bxm", "bxM", "bym", "byM",
                  "sxm", "sxM", "sym", "syM", "attr", "chx", "chy", "spf", "bgone"):
            if k in r:
                row[k] = r[k]
        if prev is not None and isinstance(row["x"], (int, float)) and isinstance(prev["x"], (int, float)):
            row["dx"] = round(row["x"] - prev["x"], 4)
        if prev is not None and isinstance(row["y"], (int, float)) and isinstance(prev["y"], (int, float)):
            row["dy"] = round(row["y"] - prev["y"], 4)
        rows.append(row)
        prev = row
    return rows


def measured_rate(rows, tier):
    ts = [r["timer_ms"] for r in rows if isinstance(r.get("timer_ms"), (int, float))]
    if len(ts) < 20:
        return None
    span_ms = ts[-1] - ts[0]
    if span_ms <= 0:
        return None
    hz = (len(ts) - 1) * 1000.0 / span_ms
    return round(hz, 3)


def landings(rows):
    """Ticks where the hero's jump flag latched (hit registered this tick)."""
    out = []
    for i, r in enumerate(rows):
        if r.get("j") is True and (i == 0 or rows[i - 1].get("j") is not True):
            out.append(i)
    return out


def num(v):
    return v if isinstance(v, (int, float)) else None


def summarize(exp, rows, events):
    s = {}
    notes = []
    vys = [(i, r["vy_var"]) for i, r in enumerate(rows) if isinstance(r.get("vy_var"), (int, float))]

    if exp in ("ff_rest", "ff_launch"):
        # gravity = per-tick vy increment when airborne (no hits)
        dvs = [round(b[1] - a[1], 6) for a, b in zip(vys, vys[1:])
               if b[0] == a[0] + 1 and rows[b[0]].get("j") is not True]
        rising = [d for d, (a, b) in zip(dvs, zip(vys, vys[1:])) if a[1] < 0]
        falling = [d for d, (a, b) in zip(dvs, zip(vys, vys[1:])) if a[1] >= 0]
        s["gravity_px_per_tick2_mode"] = statistics.mode(dvs) if dvs else None
        s["gravity_rising_values"] = sorted(set(rising))
        s["gravity_falling_values"] = sorted(set(falling))
        s["terminal_vy_px_per_tick"] = max((v for _, v in vys), default=None)
        n_term = sum(1 for _, v in vys if v == s["terminal_vy_px_per_tick"])
        s["ticks_at_terminal"] = n_term
        if exp == "ff_launch":
            scr = [(r["tick"], r["y"], r["container_y"]) for r, p in zip(rows[1:], rows)
                   if isinstance(r.get("container_y"), (int, float)) and isinstance(p.get("container_y"), (int, float))
                   and r["container_y"] != p["container_y"]]
            s["scroll_ticks"] = len(scr)
            ys_during_scroll = [y for _, y, _ in scr]
            s["hero_y_during_scroll_min_max"] = [min(ys_during_scroll), max(ys_during_scroll)] if scr else None

    if exp in ("bounce", "spring"):
        lt = landings(rows)
        imps = []
        for i in lt:
            if i + 1 < len(rows) and isinstance(rows[i + 1].get("vy_var"), (int, float)):
                imps.append({
                    "hit_tick": rows[i]["tick"],
                    "vy_at_hit_tick": rows[i].get("vy_var"),
                    "vy_next_tick": rows[i + 1]["vy_var"],
                    "jsf_at_hit": rows[i].get("jsf"),
                    "hero_y_at_hit": rows[i].get("y"),
                    "block_top_screen": rows[i].get("sym"),
                    "container_y_at_hit": rows[i].get("container_y"),
                })
        s["landings"] = imps
        # world-space apex per bounce: world_y = hy - cy
        apexes = []
        for a, b in zip(lt, lt[1:] + [len(rows) - 1]):
            seg = [r for r in rows[a:b + 1]
                   if isinstance(r.get("y"), (int, float)) and isinstance(r.get("container_y"), (int, float))]
            if not seg:
                continue
            world = [(r["y"] - r["container_y"]) for r in seg]
            hit_world = world[0]
            apex_world = min(world)
            bt = seg[0].get("sym")
            cy0 = seg[0].get("container_y")
            apexes.append({
                "hit_tick": seg[0]["tick"],
                "rise_world_px": round(hit_world - apex_world, 4),
                "block_top_world": round(bt - cy0, 4) if isinstance(bt, (int, float)) else None,
            })
        s["apex_rise_world_px"] = apexes

    if exp == "keys":
        moves = {}
        for p, r in zip(rows, rows[1:]):
            if not isinstance(r.get("dx"), (int, float)):
                continue
            state = (bool(p["keys"]["left"]), bool(p["keys"]["right"]))
            moves.setdefault(state, []).append(r["dx"])
        s["dx_by_keystate_prevtick"] = {
            f"left={l} right={rgt}": {
                "values": sorted(set(v)), "n": len(v),
                "mode": statistics.mode(v) if v else None,
            } for (l, rgt), v in moves.items()
        }
        wraps = [{"tick": r["tick"], "x_before": p["x"], "x_after": r["x"]}
                 for p, r in zip(rows, rows[1:])
                 if isinstance(r.get("dx"), (int, float)) and abs(r["dx"]) > 100]
        s["wrap_events"] = wraps

    if exp == "catch":
        trials = []
        cur = None
        for e in events:
            if e["kind"] == "TRIAL":
                cur = dict(re.findall(r"(\w+)=([\-\d.]+)", e["raw"]))
            elif e["kind"] == "RESULT" and cur is not None:
                res = dict(re.findall(r"(\w+)=([\-\d.]+)", e["raw"]))
                trials.append({
                    "trial": int(res.get("i", -1)),
                    "offset_px": float(cur.get("off", "nan")),
                    "start_dy": float(cur.get("dy", "nan")),
                    "landed": res.get("landed") == "1",
                    "feet_minus_btop_at_result": round(float(res["feet"]) - float(res["btop"]), 3)
                    if "feet" in res and "btop" in res else None,
                    "vy_at_result": float(res.get("vy", "nan")),
                    "ticks_to_result": int(res.get("dt", -1)),
                })
                cur = None
        s["trials"] = trials
        landed_offs = sorted(t["offset_px"] for t in trials if t["landed"] and t["start_dy"] < 100)
        missed_offs = sorted(t["offset_px"] for t in trials if not t["landed"] and t["start_dy"] < 100)
        s["landed_offsets"] = landed_offs
        s["missed_offsets"] = missed_offs
        term = [t for t in trials if t["start_dy"] >= 100]
        s["terminal_drops"] = term

    if exp == "blue":
        ch = [(r["tick"], r["chx"]) for r in rows if isinstance(r.get("chx"), (int, float))]
        dxs = [round(b[1] - a[1], 4) for a, b in zip(ch, ch[1:]) if b[0] == a[0] + 1]
        s["child_x_first"] = ch[0] if ch else None
        s["child_dx_values"] = sorted(set(dxs))
        if ch:
            xs = [x for _, x in ch]
            s["child_x_min_max"] = [min(xs), max(xs)]
        # direction reversals
        revs = []
        for (t0, a), (t1, b), (t2, c) in zip(ch, ch[1:], ch[2:]):
            if (b - a) * (c - b) < 0:
                revs.append({"tick": t1, "x_at_reversal": b})
        s["reversals"] = revs
        bx = [(r["tick"], r.get("bxm"), r.get("bxM")) for r in rows if isinstance(r.get("bxm"), (int, float))]
        if bx:
            s["bounds_xmin_range"] = [min(b[1] for b in bx), max(b[1] for b in bx)]
            s["bounds_xmax_range"] = [min(b[2] for b in bx), max(b[2] for b in bx)]
        lt = landings(rows)
        s["landings_on_moving"] = [{
            "hit_tick": rows[i]["tick"],
            "vy_next": rows[i + 1].get("vy_var") if i + 1 < len(rows) else None,
            "hx_at_hit": rows[i].get("x"),
            "hx_next3": [num(rows[k].get("x")) for k in range(i + 1, min(i + 4, len(rows)))],
        } for i in lt]

    if exp == "brown":
        lt = landings(rows)
        s["hits"] = [{
            "hit_tick": rows[i]["tick"],
            "vy_at_hit_tick": rows[i].get("vy_var"),
            "vy_next_tick": rows[i + 1].get("vy_var") if i + 1 < len(rows) else None,
            "block_frame_at_hit": rows[i].get("bf"),
            "block_frame_next": rows[i + 1].get("bf") if i + 1 < len(rows) else None,
        } for i in lt]
        debris = [(r["tick"], r["chy"]) for r in rows if isinstance(r.get("chy"), (int, float))]
        ddy = sorted(set(round(b[1] - a[1], 4) for a, b in zip(debris, debris[1:]) if b[0] == a[0] + 1))
        s["debris_chy_dy_values"] = ddy
        sym = [(r["tick"], r["sym"]) for r in rows if isinstance(r.get("sym"), (int, float))]
        s["bounds_ymin_first_last"] = [sym[0], sym[-1]] if sym else None
        s["block_gone_tick"] = next((r["tick"] for r in rows if r.get("bgone") == 1), None)

    if exp == "jetpack":
        jp = [(i, r) for i, r in enumerate(rows) if r.get("jp") is True]
        s["jetpack_ticks"] = len(jp)
        if jp:
            seg = [r for _, r in jp]
            dvy = [round(b["vy_var"] - a["vy_var"], 4) for a, b in zip(seg, seg[1:])
                   if isinstance(a.get("vy_var"), (int, float)) and isinstance(b.get("vy_var"), (int, float))]
            s["vy_delta_during_jetpack_values"] = sorted(set(dvy))
            s["vy_min_during"] = min((r["vy_var"] for r in seg if isinstance(r.get("vy_var"), (int, float))), default=None)
            s["js_during"] = sorted(set(r.get("js") for r in seg if r.get("js") is not None))
            s["jsf_during"] = sorted(set(r.get("jsf") for r in seg if r.get("jsf") is not None))
            s["jc_first_last"] = [seg[0].get("jc"), seg[-1].get("jc")]
            world = [(r["y"] - r["container_y"]) for r in seg
                     if isinstance(r.get("y"), (int, float)) and isinstance(r.get("container_y"), (int, float))]
            if world:
                s["world_rise_during_jetpack_px"] = round(world[0] - min(world), 3)

    return s, notes


def main():
    trace_file, exp, tier, run_id, out = sys.argv[1:6]
    recs, events = parse_trace(trace_file)
    rows = spec_trace(recs)
    summary, notes = summarize(exp, rows, events)
    hero = next((e["raw"] for e in events if e["kind"] == "HERO"), None)
    pokes = [e["raw"] for e in events if e["kind"] in
             ("POKE", "TRIAL", "RESULT", "DROP", "BROKE", "RESCUE", "CATCH", "BROWN")]
    doc = {
        "experiment": exp,
        "run_id": run_id,
        "tier": tier,
        "swf_fps_header": SWF_FPS_HEADER,
        "measured_tick_rate_hz": measured_rate(rows, tier),
        "setup": None,  # filled in by the runner script / by hand
        "coordinate_spaces": {
            "hero_x": "screen (root)",
            "hero_y": "screen (root)",
            "container_y": "container clip _y on root (world scroll offset; world_y = screen_y - container_y)",
            "bx/by": "container-local block _x/_y",
            "bxm..byM": "block bounds in container coords",
            "sxm..syM": "block bounds in screen (root) coords",
            "chx/chy": "block-inner-child coords local to the block clip",
        },
        "hero_info_line": hero,
        "poke_log": pokes,
        "trace": rows,
        "summary": summary,
        "notes": "",
    }
    json.dump(doc, open(out, "w"), indent=1)
    print(f"{out}: {len(rows)} ticks, rate={doc['measured_tick_rate_hz']}")
    print(json.dumps(summary, indent=1)[:3000])


if __name__ == "__main__":
    main()
