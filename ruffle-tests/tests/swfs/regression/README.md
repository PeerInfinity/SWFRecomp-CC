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

```bash
# one test — `--test` finds the suite that owns the name, no --tests-dir needed
python3 ruffle-tests/verify_output.py --test=fn_call_type1_args --diff --verbose

# whole suite (a few seconds)
python3 ruffle-tests/verify_output.py -v --tests-dir=ruffle-tests/tests/swfs/regression
```

A bare `--test=NAME` searches every suite in `verify_output.py`'s `SUITE_DIRS`.
Names must all resolve to one suite; pass `--tests-dir` to disambiguate.

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
| `ei_closure_scope_order` | `actionEI_callInternalInterface`'s three dispatch quirks — a behavior lock, not a bug repro: local-scope-under-captured (a captured `with(w)` scope shadows the callee's same-named param on lookup), forced `is_with=1` on captured scopes (a `var` in the callee never lands on a captured local frame — the discriminating row; note a plain SetVariable writes THROUGH a with-frame where the property exists, so that row locks write-through, not the force), and the LIVE type-1 `this` bind (`thisObj` readable as `this` at `g_this_depth==0`; `typeof this` is `undefined` when registered with null). Normalizing any of these must flip this test deliberately |
| `mc_event_type1_args` | `mc_call_as2_handler_ng`'s type-1 arm passes the event's arguments at all (fixed `9a8c6dce3`) |
| `timer_cross_swf_version` | `fireTimerCallback` switches to the callback's own SWF version and `_global` group (fixed `60070d96a`) |
| `nc_onstatus_closure` | `nc_dispatch_onStatus` restores the handler's captured scope chain — a behavior lock, not a bug fix |
| `fn_call_type1_args` | `actionCallMethod`'s `.call`/`.apply`-via-GetMember arm: forward arg order + pad (fixed in dispatch Stage 3b) |
| `lc_method_type1_args` | `lc_dispatch_method`'s type-1 arm: forward arg order + clamp/pad (instance ten; fixed migrating it onto `invokeFunctionValue` in dispatch Stage 4) |
| `lc_onstatus_type1_args` | `lc_dispatch_onStatus`'s type-1 arm: clamp/pad the event-object arg to `param_count` (instance eleven; fixed migrating the onStatus family onto `invokeFunctionValue` in dispatch Stage 4) |
| `nc_onstatus_type1_args` | `nc_dispatch_onStatus`'s type-1 arm: clamp/pad the info-object arg to `param_count` (instance twelve; fixed in the same onStatus-family migration) |
| `lv_ondata_type1_args` | `fireLoadVarsCallback`'s type-1 arm: forward arg order + clamp/pad (instance thirteen; fixed migrating it onto `invokeFunctionValue` in dispatch Stage 4) |
| `xml_onload_type1_args` | `soundFireCallback`'s type-1 arm (the shared Sound/XML event dispatcher): forward arg order + clamp/pad (instance fourteen; fixed in the same migration batch) |
| `sort_comparator_type1_args` | `_invoke_sort_comparator`'s type-1 arm: clamp/pad to `param_count` (instance fifteen — a 1-param comparator misbound `b` and leaked a stack slot per comparison into the NEXT sort's comparator; fixed migrating it onto `invokeFunctionValue` in dispatch Stage 4) |
| `timer_type1_args` | `fireTimerCallback`'s two type-1 arms (function-form `setTimeout(f, …)` AND method-form `setTimeout(o, "m", …)` are separate paths): clamp/pad to `param_count` (instance seventeen — the arms pushed forward but a clamped row stranded an operand on the AVM1 stack that corrupted the NEXT callback's pad pop; fixed migrating `fireTimerCallback` onto `invokeFunctionValue` via the exported `actionInvokeFunctionValue` in dispatch Stage 4). The 2-arg rows are deliberate order locks (passed before the fix) |
| `watch_setmember_type1_args` | `actionSetMember`'s OBJECT-receiver watch arm (Site B), type-1 callee: clamp/pad to `param_count` (instance eighteen — the canonical 3-param watcher `function(prop, oldV, newV)` got 4 pushed, binding every arg off by one AND stranding the name string on the caller's eval stack; a 5-param watcher's 5th param popped the caller's SENTINEL). Also pins return-value-becomes-new-value through a defined return; the undefined-return fold (D1) is deliberately NOT asserted |
| `watch_mc_type1_args` | `actionSetMember`'s MOVIECLIP-receiver watch arm (Site C), type-1 callee: clamp/pad (instance eighteen's sibling arm — a 4-param watcher's first param popped a stale caller slot). Locks the preserved userData DROP (the `ud` param pads to undefined, NOT the registered value — flipping that to `UD` is the D6 normalization commit) and return-becomes-value on the MC arm |
| `watch_mc_reentrant_setmember` | the MOVIECLIP watch arm (Site C) read `prop_name` off actionSetMember's static `_sm_buf` AFTER the watcher call — a SetMember inside the watcher clobbered it, storing the assignment under the wrong name (a `this.side="S"` watcher made `m.p="x"` store under `"s"`, leaving `m.p` undefined). Fixed by copying the name to an arm-level buffer before invoking (the OBJECT arm's existing discipline) |
| `watch_timeline_named_params` | the timeline watch arm (Site A) passed the property-name arg OWNING and freed it unconditionally — a NAMED-param (non-register-preloaded) DefineFunction2 watcher's prologue pointer-shares args into its local frame, whose release freed the string first: double-free, glibc abort mid-frame. Fixed by adopting the OBJECT arm's non-owning + never-freed (leak-over-dangle) discipline; the `stash=tv` line pins the no-dangle side |
| `coerce_type1_args` | the coercion paths' (`objectCallValueOf` / `objectToPrimitive` / `convertFloat` / `objectCallToString`) type-1 arms: pad to `param_count` (instance sixteen, one instance for the family — all four sites pushed nothing, so a 2-param valueOf's prologue popped the caller's live stack, including the operand under conversion in `convertFloat`; fixed migrating the family onto `invokeFunctionValue` in dispatch Stage 4) |
