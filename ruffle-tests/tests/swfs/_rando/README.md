# `_rando` — Archipelago `Rando` builtin integration tests

Manual / local integration tests for the native `Rando` (Archipelago) builtin.
These are **not** part of the default Ruffle suites and are **not** run in CI:
they require the runtime to be built with `WITH_AP=1` (which links APCpp), and
the suite lives outside `tests/swfs/avm1` so the corpus downloader ignores it.

Prerequisite: APCpp built locally (see
`SWFRecompDocs/plans/archipelago-randomizer-integration.md`):

```bash
cmake -S ~/CC/APCpp -B ~/CC/APCpp/build -DCMAKE_BUILD_TYPE=Release
cmake --build ~/CC/APCpp/build -j
```

## rando_smoke

Constructs a `Rando` and polls it **without** `connect()` (no server, no network
thread → deterministic). Verifies the AVM1 `new Rando(...)` construct path,
method dispatch, and that APCpp is actually linked/called.

Rebuild `test.swf` (only needed if you edit `Test.as` / `Rando.as`):

```bash
cd ruffle-tests/tests/swfs/_rando/rando_smoke
~/CC/mtasc/bin/mtasc -cp ~/CC/mtasc/ocaml/mtasc/std -cp . \
    -main -header 200:150:30 Test.as -swf test.swf -version 8
```

Run:

```bash
WITH_AP=1 python3 ruffle-tests/verify_output.py \
    --test=rando_smoke --tests-dir=ruffle-tests/tests/swfs/_rando --diff
```

A full live-server test (connect + receive items + send a location) is a manual
step requiring a running Archipelago server.
