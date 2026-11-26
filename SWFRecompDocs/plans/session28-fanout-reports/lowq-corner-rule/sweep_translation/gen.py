import sys, json, math, pathlib, importlib.util
D = pathlib.Path(sys.argv[1])
spec = importlib.util.spec_from_file_location('g', D / 'create_test_swf.py'); g = importlib.util.module_from_spec(spec); spec.loader.exec_module(g)
HERE = pathlib.Path(__file__).resolve().parent
BW = g.BW
cells = []
def add(name, gm, col, row, spread, rect=(4, 4, 32, 32), place=(1, 0, 0, 1, 0, 0)):
    pl = (place[0], place[1], place[2], place[3], place[4] + col * 40, place[5] + row * 40)
    cells.append(dict(name=name, kind='linear', stops=BW, gm=gm, rect=rect, place=pl, focal=None, spread=spread, col=col, row=row))
dxs = [0, 0.05, 0.1, 0.25, 0.5, 1, 2, 5, 10, 20, 40, 80, 160, 320, 640, 1280]
for i, dx in enumerate(dxs):
    add(f'tx+{dx}', g.gbox(32, 32, 7, 20 + dx, 20), i % 8, i // 8, 1)
    add(f'ty+{dx}', g.gbox(32, 32, 7, 20, 20 + dx), i % 8, 2 + i // 8, 1)
# placement sweep: gradient at local (20,20); shape placed further right, gradient compensates -> same screen
for i, dx in enumerate([0, 0.05, 0.5, 5, 50, 500, -50, -500]):
    add(f'plc{dx}', g.gbox(32, 32, 7, 20 - dx, 20), i, 4, 1, rect=(4 - dx, 4, 32, 32), place=(1, 0, 0, 1, dx, 0))
for i, dx in enumerate([0, 0.05, 0.5, 5, 50, 500, -50, -500]):
    add(f'pad{dx}', g.gbox(32, 32, 7, 20 + dx, 20), i, 5, 0)
g.cells = lambda: cells
g.HERE = HERE
import builtins
src = open(D / 'create_test_swf.py').read()
g.build.__globals__['HERE'] = HERE
# stage height
import re
code = g.build.__code__
g.build()
