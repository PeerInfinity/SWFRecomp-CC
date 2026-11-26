import sys, pathlib, importlib.util
D = pathlib.Path(sys.argv[1])
spec = importlib.util.spec_from_file_location('g', D / 'create_test_swf.py'); g = importlib.util.module_from_spec(spec); spec.loader.exec_module(g)
HERE = pathlib.Path(__file__).resolve().parent
cells = []
def add(name, kind, gm, col, row, spread, rect, place):
    pl = (place[0], place[1], place[2], place[3], place[4] + col * 40, place[5] + row * 40)
    cells.append(dict(name=name, kind=kind, stops=g.BW, gm=gm, rect=rect, place=pl, focal=None, spread=spread, col=col, row=row))
for r, sp in enumerate([0, 1]):
    for i, (dx, dy) in enumerate([(0.25, 0), (0.75, 0), (0.5, 0), (0, 0.25), (0, 0.75), (0.35, 0.65), (1.75, 0), (-0.25, 0)]):
        add(f'plc{sp}_{dx}_{dy}', 'linear', g.gbox(32, 32, 7, 20 - dx, 20 - dy), i, r, sp, (4 - dx, 4 - dy, 32, 32), (1, 0, 0, 1, dx, dy))
    for i, (dx, dy) in enumerate([(0.25, 0), (0.75, 0), (0.5, 0), (0, 0.75)]):
        add(f'rad{sp}_{dx}_{dy}', 'radial', g.gbox(16, 16, 0, 20 - dx, 20 - dy), i, 2 + r, sp, (4 - dx, 4 - dy, 32, 32), (1, 0, 0, 1, dx, dy))
g.cells = lambda: cells
g.build.__globals__['HERE'] = HERE
g.build()
