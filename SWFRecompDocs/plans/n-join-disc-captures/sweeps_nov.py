#!/usr/bin/env python3
"""NoVScale / NoHScale width sweep (s28 n-join-disc goal 2): 8 px declared stroke,
24 px rect outlines, rows normal / nov / noh x a set of matrices. Prints the spec."""
import json, math
def R(t):
    c, s = math.cos(math.radians(t)), math.sin(math.radians(t)); return [[c, -s], [s, c]]
def mul(A, B): return [[sum(A[i][k] * B[k][j] for k in range(2)) for j in range(2)] for i in range(2)]
def D(x, y): return [[x, 0], [0, y]]
import sys
MATS2 = [("dm21", D(-2, 1)), ("d2m1", D(2, -1)), ("d1m2", D(1, -2)), ("R180", R(180)), ("R135", R(135)),
         ("Rm45d21", mul(R(-45), D(2, 1))), ("Rm45d12", mul(R(-45), D(1, 2))), ("R60d21", mul(R(60), D(2, 1))),
         ("R120d21", mul(R(120), D(2, 1))), ("dm2m1", D(-2, -1)), ("R20d31", mul(R(20), D(3, 1))),
         ("R70d13", mul(R(70), D(1, 3))), ("Rm20d13", mul(R(-20), D(1, 3))), ("shx-.5", [[1, -.5], [0, 1]]),
         ("R10", R(10)), ("R80", R(80)), ("R100", R(100))]
MATS = [("I", D(1, 1)), ("d21", D(2, 1)), ("d12", D(1, 2)), ("dh1", D(.5, 1)), ("d1h", D(1, .5)),
        ("R30", R(30)), ("R45", R(45)), ("R45d12", mul(R(45), D(1, 2))), ("R45d21", mul(R(45), D(2, 1))),
        ("R30d12", mul(R(30), D(1, 2))), ("R30d21", mul(R(30), D(2, 1))), ("d12R45", mul(D(1, 2), R(45))),
        ("d21R45", mul(D(2, 1), R(45))), ("shx.5", [[1, .5], [0, 1]]), ("shy.5", [[1, 0], [.5, 1]]),
        ("R90d12", mul(R(90), D(1, 2))), ("dm12", D(-1, 2))]
if len(sys.argv) > 1: MATS = MATS2
items = []; cell = 90; cols = 6; k = 0
for row, fl in (("norm", {}), ("nov", {"nov": 1}), ("noh", {"noh": 1})):
    for name, M in MATS:
        cx, cy = (k % cols) * cell + cell // 2, (k // cols) * cell + cell // 2
        # place the rect centre (12, 12 px local) at the cell centre
        lx, ly = 12 * 20, 12 * 20
        tx = cx * 20 - (M[0][0] * lx + M[0][1] * ly); ty = cy * 20 - (M[1][0] * lx + M[1][1] * ly)
        it = {"lw": 160, "rw": 24, "rh": 24, "v": 4, "row": row, "label": name,
              "m": [M[0][0], M[1][0], M[0][1], M[1][1], round(tx), round(ty)]}
        it.update(fl); items.append(it); k += 1
rows = (k + cols - 1) // cols
print(json.dumps({"w": cols * cell, "h": rows * cell, "items": items}))
