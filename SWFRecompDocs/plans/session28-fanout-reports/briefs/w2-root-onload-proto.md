**Root onLoad through `MovieClip.prototype` (S): land what Flash showed for `avm1_root_onload_proto`.**

Inputs: `w1-drift-report.md` (on master after landing; else `origin/fanout/w1-drift`), its fixtures
`w1-drift-fixtures/avm1_root_onload_{proto,child_order}/` + `create_test_swfs.py`, and the Flash 32 captures in
`w1-local-oracles/w1-drift/` (README there). Flash (direct, `--no-pin`, test = first root) for `avm1_root_onload_proto`:

```
f1 of _level0.a
root f1
proto onLoad _global
proto onLoad _level0
f1 of _level0.b
root f2
root f3 stop
```
We print the same minus the two `proto onLoad` lines. `child_order` already matches Flash exactly (land it as a
regression row too: it pins the root-onLoad position).

Task:
1. Explain both Flash lines. `proto onLoad _level0` is the root's load event finding `MovieClip.prototype.onLoad`.
   `proto onLoad _global` is a second call whose `this` stringifies as `_global` — find what it is (a second load
   dispatch with no/wrong `this`? the `_global`-bound activation of a prototype function? the root Load firing on a
   non-clip?). Probe variants in the cloud only by reasoning + Ruffle source (`fa93ad79f`), and write variant fixtures
   (own `this.onLoad` + proto; proto defined in f2; `_global.onLoad`; trace `typeof this`, `this == _global`) as
   FLASH requests (`--no-pin`) under LOCAL ORACLE REQUESTS if the mechanism isn't certain.
2. Implement (`action.c` `actionDispatchRootOnLoad` / `actionDispatchMCOnLoad`) so both fixtures match Flash in both
   modes, without moving `avm1/root_onload`, gnash `trace-as2/root_onload`, `root_onload_loaded_level`, or any
   onLoad/MCL row (the w1-drift report lists the 119 onLoad SWFs; gate the avm1/gnash/shumway ones that pass now).
3. Land both fixtures as `regression/avm1_root_onload_proto` and `regression/avm1_root_onload_child_order` with the
   FLASH goldens above. **Their `test.toml` must note that the golden was taken `--no-pin`** (the pinned harness
   replaces `_level0` and Flash then fires no frame-1 onLoad).
4. Draft an RvF entry if Ruffle (post-`fa93ad79f`) differs from Flash here.
