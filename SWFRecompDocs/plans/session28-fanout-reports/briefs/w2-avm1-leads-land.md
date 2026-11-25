**Land the w1-leads robustness + onUnload scope (S–M).**

Inputs: `w1-leads-report.md` §2 + "New unclaimed leads" 1 (on master), `w1-leads-prototype.patch`, its fixtures
`w1-leads-fixtures/`, and the coordinator's Flash 32 captures in `w1-local-oracles/w1-leads/` (README).

1. **Queues:** apply `w1-leads-prototype.patch` (4 growable queues; `tag.c` `queue_pending_finalize_mc` /
   `run_pending_finalize` take-ownership walk). Land 3 fixtures in `regression/` with the FLASH goldens:
   `avm1_sprite_goto_script_overflow` and `avm1_remove_unload_finalize_overflow` (FP32 == ours-with-patch, byte for
   byte); `avm1_loadvars_ondata_overflow` (FP32: 20/20 onData but `frame 2` prints BEFORE the onData lines, ours
   after) — find why our LoadVars onData fires before frame 2's script (delivery tick vs frame-script order; owner
   `avm1FireFormDataEvents` / LoadVars drain) and fix it if it's a general rule (gate every LoadVars/loadVariables
   row in avm1 + gnash + shumway), else land with the Flash golden and a HELD note.
2. **onUnload handler scope:** FP32 for `avm1_onunload_setvar_scope`: `in handler: n=2 this=_level0.a
   this.n=undefined`, `_root.n=2` (the unqualified `n` resolves through the function's captured scope chain, not the
   dying clip). Fix `actionFireOnUnload` (or wherever the onUnload dispatch sets scope/target) and land the fixture.
   Gate: `onunload_*` rows, `regression/onunload_type1_*`, every avm1/gnash row with `onUnload`, both modes.
3. Optional if time remains (S each, no corpus row): `MAX_LC_MESSAGES` / avm2 `LC_MAX_QUEUE` growable (send() must not
   return true and drop); `DRAW_INLINE_MAX` needs a canary — skip unless trivially gated.
Both modes for everything (`tag.c` arm is NO_GRAPHICS‖OFFSCREEN).
