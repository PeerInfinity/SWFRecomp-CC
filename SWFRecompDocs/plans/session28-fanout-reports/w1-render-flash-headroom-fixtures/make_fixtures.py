#!/usr/bin/env python3
"""Build the occupied-depth SWF-version fixtures for the FLASH oracle request
(w1-render-flash-headroom report, LOCAL ORACLE REQUESTS #1).

Copies two corpus tests into ./out/<name>_v<N>/ with ONLY the SWF header's
version byte (offset 3) changed. Run from the repo root after
`ruffle-tests/download_tests.sh from_gnash avm1`:

    python3 SWFRecompDocs/plans/session28-fanout-reports/w1-render-flash-headroom-fixtures/make_fixtures.py
"""
import pathlib, shutil
here = pathlib.Path(__file__).resolve().parent
root = pathlib.Path.cwd() / "ruffle-tests/tests/swfs"
cases = {
    "place_object_test": (root / "from_gnash/misc-ming.all/place_object_test", [5, 6, 7, 8, 10]),
    "placeobject_occupied_depth": (root / "avm1/placeobject_occupied_depth", [5, 6, 7, 8, 15]),
}
for name, (src, versions) in cases.items():
    data = bytearray((src / "test.swf").read_bytes())
    for v in versions:
        dst = here / "out" / f"{name}_v{v}"
        dst.mkdir(parents=True, exist_ok=True)
        d = bytearray(data); d[3] = v
        (dst / "test.swf").write_bytes(bytes(d))
        shutil.copy(src / "test.toml", dst / "test.toml")
        print(dst, "version", v)
