#!/usr/bin/env python3
"""Unit tests for divergence_test.analyze_trace_divergence (difflib alignment +
re-convergence / transient classification) and detect_byte_preloader.

Run: python3 tools/divergence/test_analyze.py   (exit 0 = all pass)

These lock the behavior of the preloader-pacing recognizer (follow-up A+B+C):
- A: insert/delete lines are classified as ruffle-only / swfrecomp-only instead
     of shifting every later line into a false divergence.
- B: divergences confined to early frames that re-converge are flagged transient.
- C: byte-loading-preloader detection from the recompiled scripts.
"""
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import divergence_test as dt

REL, ABS = 1e-5, 1e-4
_fails = []


def check(name, cond, extra=""):
    print(f"{'PASS' if cond else 'FAIL'}: {name}" + (f"  ({extra})" if extra and not cond else ""))
    if not cond:
        _fails.append(name)


def an(a, b, accept=None):
    return dt.analyze_trace_divergence(a, b, REL, ABS, accept)


# 1. Identical traces -> no divergence.
r = an(["F1 _currentframe=1", "F1 _root.x _a=100"],
       ["F1 _currentframe=1", "F1 _root.x _a=100"])
check("identical: first is None", r["first"] is None)
check("identical: matched==2", r["matched"] == 2)

# 2. Float-precision-only diff -> absorbed, not a divergence.
r = an(["F1 _root.m _xs=99.8707210039242"],
       ["F1 _root.m _xs=99.870719909668"])
check("float noise: first is None", r["first"] is None)
check("float noise: absorbed==1", r["absorbed"] == 1)

# 3. Ruffle-only inserted lines (preloader clips), then re-converge -> TRANSIENT.
ruffle = ["F1 _currentframe=1",
          "F1 _root.l1 _x=0 _cf=0",
          "F1 _root.l2 _x=0 _cf=0",
          "F2 _currentframe=2",
          "F2 _root.g _a=100"]
swf = ["F1 _currentframe=1",
       "F2 _currentframe=2",
       "F2 _root.g _a=100"]
r = an(ruffle, swf)
check("ruffle-only: kind", r["first"] and r["first"]["kind"] == "ruffle_only")
check("ruffle-only: count==2", r["ruffle_only"] == 2)
check("ruffle-only: 0 swf-only", r["swf_only"] == 0)
check("ruffle-only: transient set", r["transient"] is not None)
check("ruffle-only: reconverge F2",
      r["transient"] and r["transient"]["reconverge_frame"] == 2)
check("ruffle-only: rest matched (not shifted into false divergence)",
      r["matched"] == 3)

# 4. swfrecomp-only inserted lines -> swfrecomp_only classification.
r = an(["F1 a=1", "F2 b=2"], ["F1 a=1", "F1 extra=9", "F2 b=2"])
check("swf-only: kind", r["first"] and r["first"]["kind"] == "swfrecomp_only")
check("swf-only: count==1", r["swf_only"] == 1)

# 5. Real structural replace that PERSISTS every frame -> not transient.
ruffle = ["F1 _root.i _cf=2", "F2 _root.i _cf=3", "F3 _root.i _cf=4"]
swf = ["F1 _root.i _cf=1", "F2 _root.i _cf=2", "F3 _root.i _cf=3"]
r = an(ruffle, swf)
check("persistent replace: first is replace", r["first"] and r["first"]["kind"] == "replace")
check("persistent replace: NOT transient", r["transient"] is None)
check("persistent replace: diverge_frames all", r["diverge_frames"] == [1, 2, 3])

# 6. A value-replace divergence confined to F1 then re-converges -> transient.
r = an(["F1 v=0", "F2 v=100", "F3 v=100"],
       ["F1 v=5", "F2 v=100", "F3 v=100"])
check("early replace then converge: transient", r["transient"] is not None)
check("early replace then converge: reconverge F2",
      r["transient"] and r["transient"]["reconverge_frame"] == 2)

# 7. Accepted-diff rule absorbs a one-field replace pair (no false divergence).
try:
    import accepted_diffs
    rule = accepted_diffs.AcceptRule(r"_root\.Pac", "_cf", "1", "5", "demo")
    r = an(["F5 _root.Pac _x=1 _cf=1", "F6 _root.Pac _x=1 _cf=1"],
           ["F5 _root.Pac _x=1 _cf=5", "F6 _root.Pac _x=1 _cf=1"],
           accept=[rule])
    check("accepted rule: absorbs one line", len(r["accepted"]) == 1)
    check("accepted rule: no real divergence", r["first"] is None)
except Exception as e:  # noqa: BLE001
    check("accepted rule wiring", False, str(e))

# 8. detect_byte_preloader: positive + negative against a temp dir.
import tempfile
with tempfile.TemporaryDirectory() as td:
    d = Path(td)
    (d / "RecompiledScripts").mkdir()
    (d / "RecompiledScripts" / "script_defs.c").write_text(
        'char* str_13 = "getBytesLoaded";\n')
    check("preloader detect: positive", dt.detect_byte_preloader(d) is True)
with tempfile.TemporaryDirectory() as td:
    d = Path(td)
    (d / "RecompiledScripts").mkdir()
    (d / "RecompiledScripts" / "script_defs.c").write_text('char* str_0 = "hi";\n')
    check("preloader detect: negative", dt.detect_byte_preloader(d) is False)

# 9. Per-clip self-healing: a NAMED clip diverges ONLY on its first frame then
#    re-converges, WHILE another clip diverges persistently (Riddle School #17:
#    instance68 cursor self-heals, instance65 nested sprite persists). The
#    self-healing clip is absorbed (clip_transient); the persistent clip is the
#    real first divergence and is NOT masked.
ruffle = ["F1 _root.cursor _x=-155 _y=94", "F1 _root.box _cf=3",
          "F2 _root.cursor _x=0 _y=0",     "F2 _root.box _cf=3",
          "F3 _root.cursor _x=0 _y=0",     "F3 _root.box _cf=3"]
swf =    ["F1 _root.cursor _x=0 _y=0",     "F1 _root.box _cf=1",
          "F2 _root.cursor _x=0 _y=0",     "F2 _root.box _cf=1",
          "F3 _root.cursor _x=0 _y=0",     "F3 _root.box _cf=1"]
r = an(ruffle, swf)
check("per-clip transient: cursor absorbed", len(r["clip_transient"]) == 1,
      str(r["clip_transient"]))
check("per-clip transient: cursor path",
      r["clip_transient"] and r["clip_transient"][0]["path"] == "_root.cursor")
check("per-clip transient: persistent box still flagged as first divergence",
      r["first"] is not None and "_root.box" in r["first"]["a"], str(r["first"]))

# 10. A NAMED self-healing clip with NO other divergence -> fully converged modulo
#     the self-healing clip (first is None, clip_transient populated).
r = an(["F1 _root.cursor _x=-155", "F2 _root.cursor _x=0", "F3 _root.cursor _x=0"],
       ["F1 _root.cursor _x=0",    "F2 _root.cursor _x=0", "F3 _root.cursor _x=0"])
check("self-healing only: first is None", r["first"] is None, str(r["first"]))
check("self-healing only: one clip_transient", len(r["clip_transient"]) == 1)

# 11. A NAMED clip diverging on TWO frames (not just its first) is NOT self-healing
#     — a real lag must still be flagged.
r = an(["F1 _root.c _x=1", "F2 _root.c _x=1", "F3 _root.c _x=9"],
       ["F1 _root.c _x=0", "F2 _root.c _x=0", "F3 _root.c _x=9"])
check("multi-frame divergence: not clip_transient", len(r["clip_transient"]) == 0)
check("multi-frame divergence: still flagged", r["first"] is not None)

# 12. A PATHLESS first-frame blip (e.g. root _currentframe) is NOT absorbed by the
#     per-clip recognizer (guard: non-empty clip path) — stays whole-trace transient.
r = an(["F1 v=0", "F2 v=100", "F3 v=100"],
       ["F1 v=5", "F2 v=100", "F3 v=100"])
check("pathless blip: not clip_transient", len(r["clip_transient"]) == 0)
check("pathless blip: whole-trace transient", r["transient"] is not None)

print()
if _fails:
    print(f"{len(_fails)} FAILED: {_fails}")
    sys.exit(1)
print("all analyzer tests passed")
