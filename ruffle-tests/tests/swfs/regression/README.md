# SWFRecomp regression suite

Hand-written trace tests owned by this project. Nothing here comes from Ruffle,
Gnash, or Shumway, and `download_tests.sh` never touches this directory — so
every file is plainly git-tracked, including `test.swf`.

That is the whole reason the suite exists. The sibling `avm1/`, `from_gnash/`,
and `from_shumway/` trees are mirrors of upstream projects: `download_tests.sh`
re-syncs them from `ruffle-rs/ruffle` master on every run and `--clean` deletes
their contents outright. Custom tests parked in those trees had to be defended
with a `.gitignore` negation per test (including an explicit `!.../test.swf` to
un-ignore a binary) plus a `git checkout HEAD --` restore step inside the sync
script. Tests that live here need none of that.

## Running

The suite is not the runner's default `--tests-dir`, so name it explicitly:

```bash
# whole suite (5 tests, a few seconds)
python3 ruffle-tests/verify_output.py -v --tests-dir=ruffle-tests/tests/swfs/regression

# one test
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/regression \
  --test=fn_call_type1_args --diff --verbose
```

CI runs it as its own suite alongside `avm1` (gated on the same `RUN_AVM1`
condition), with results in `_results/` and the usual per-mode diff reports.

## Adding a test

Drop in a directory with `test.swf`, `output.txt`, and `test.toml`. Commit all
three — no `.gitignore` edit is needed. Ship the SWF's generator
(`create_test_swf.py`) next to it so the binary is reproducible, and open the
generator's docstring with what the test pins down and which commit fixed it.

Several of these SWFs are hand-assembled bytecode rather than compiler output,
because MTASC emits `DefineFunction2` for SWF6+ and the type-1 (`DefineFunction`)
arms cannot be reached any other way.

## Contents

| Test | Guards |
|---|---|
| `ei_type1_args` | `actionEI_callInternalInterface`'s type-1 arm: forward arg order + pad to `param_count` (fixed `d8abc5c0a`) |
| `mc_event_type1_args` | `mc_call_as2_handler_ng`'s type-1 arm passes the event's arguments at all (fixed `9a8c6dce3`) |
| `timer_cross_swf_version` | `fireTimerCallback` switches to the callback's own SWF version and `_global` group (fixed `60070d96a`) |
| `nc_onstatus_closure` | `nc_dispatch_onStatus` restores the handler's captured scope chain — a behavior lock, not a bug fix |
| `fn_call_type1_args` | `actionCallMethod`'s `.call`/`.apply`-via-GetMember arm: forward arg order + pad (fixed in dispatch Stage 3b) |
