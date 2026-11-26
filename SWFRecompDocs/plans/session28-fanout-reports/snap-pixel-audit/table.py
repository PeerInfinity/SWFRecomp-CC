import json, sys, os
S = os.path.dirname(os.path.abspath(__file__))
g = {(r["test"], r["cmp"]): r for r in json.load(open(f"{S}/grade.json"))}
ch = json.load(open(f"{S}/changed_on_snapoff.json"))
cur2 = sys.argv[1] if len(sys.argv) > 1 else "cur"
FONT = {"bevel", "bevel_full", "bevel_inner", "bevel_outer", "drop_shadow", "glow",
        "glow_with_alpha_strength", "glow_without_composite_source"}

def cls(t, c):
    n = t.split("/")[-1]
    if t.startswith("from_gnash") : return "b → flash_fixes", "swap (6 × fail→pass)"
    if n in ("avm1_hairline_scaled_instances", "avm1_stroke_style_id_order"):
        return "b (own fixture)", "golden → Flash capture, max_outliers measured"
    if n in ("acid-gradient-2", "doubleAndRegister"): return "**away (D1)**", "handed to stroke owner"
    if n in FONT: return "c (host fonts)", "none (stroke moves Flash-ward on changed px)"
    if n == "mouse_events_visible_enabled": return "c (input.json)", "none"
    if n == "blur_scales_with_screen": return "c (stage size)", "none"
    if n in ("drawing_order", "masks", "masks_equal_clipdepth", "displacement_map", "layers"):
        return "b (neutral)", "RvF"
    return "b", "RvF"

def prov(t, c):
    n = t.split("/")[-1]
    if n.startswith("avm1_hairline") or n.startswith("avm1_stroke"): return "Ruffle exporter (d70f2c0aa)"
    if n.startswith("avm2_layer_group"): return "upstream Ruffle layer_* golden"
    if n in FONT or n in ("mouse_events_visible_enabled", "blur_scales_with_screen"): return "untestable (s27)"
    return "not Flash (s27)"

def f(v): return "–" if v is None else f"{v[0]}"
rows = []
for (t, c), r in g.items():
    fl = "flash_screen" if r.get("golden_vs_flash_screen") else "flash_draw"
    gf = r.get("golden_vs_flash_screen") or r.get("golden_vs_flash_draw")
    off = r.get("snapoff", {}).get(fl) if r.get("snapoff") else None
    on = r.get(cur2, {}).get(fl) if r.get(cur2) else None
    own = r.get(cur2, {}).get("golden") if r.get(cur2) else None
    k = f"{t}|{c}"
    cx = ch.get(k)
    chs = f"{cx['A_exact']}/{cx['B_exact']} of {cx['changed']}" if cx else "–"
    gl = r.get("glyphoff", {}).get("golden") if r.get("glyphoff") else None
    owner = "stroke snap 09b2c9130"
    if gl and own and gl[0] != own[0]: owner += f" (+glyph: glyphoff {gl[0]})"
    k1, act = cls(t, c)
    mode = "screen" if fl == "flash_screen" else "draw"
    rows.append(f"| `{t}` | {c} | {r['tol']} | {owner} | {prov(t,c)} | {f(own)} | {f(gf)} | {f(off)} | {f(on)} | {chs} | {mode} | {k1} | {act} |")
print("| test | cmp | tol | owner | golden provenance | ours vs golden | golden vs Flash | before (snap off) vs Flash | after vs Flash | changed px within 2 of Flash: after/before | Flash mode | class | action |")
print("|---|---|---:|---|---|---:|---:|---:|---:|---|---|---|---|")
print("\n".join(rows))
print(f"\n<!-- {len(rows)} rows -->")
