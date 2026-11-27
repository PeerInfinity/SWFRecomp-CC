**Interim #3 residuals: one unledgered LOW band move + two S riders (S each).**

Interim #3 (graphics `45920452660`, results `122987464`; NG `45920462741`, `e6388d6c6`) graded code `6ee6eded7`:
n-seam-caps `faeaaba4b`, browser goto(current) `c91637b7a`, disposition `883d02f35`, pixel gaps `5c0f4f56f`, rm-avm2
`73d80aea1`. Everything matched the ledgers except:
1. **`avm1/movieclip_line_gradient_style` [output] (quality low, golden NOT Flash) 614 → 773 outliers; vs FP32 LOW
   (`session28-fanout-reports/lowq-recapture/png/avm1__movieclip_line_gradient_style__output.low.png`, WIN ≈ LNX 34 ch)
   ours went 15 357 (s28 final, lowq-corner-rule §6 table) → 15 468 channels over tol 6: a small move AWAY from Flash
   on no ledger.** Find the owner with the kill switches on current `origin/master` (which also has TSNAP `1fcf2b1c1`:
   `SWF_LOWQ_TSNAP=0`): `SWF_STROKE_SEAM_CAPS=0`, `SWF_STROKE_CAP_OCTAGON=0`, `SWF_STROKE_HINT_ENDS=0` (n-seam-caps),
   `SWF_STROKE_CENTRE_QSNAP_ALL=1`, `SWF_TF_LOW_PEN_SNAP=0`, `SWF_CAB_HIGH_SNAP=1` (pixel gaps). Prove fidelity on the
   row first (your before render vs CI's actual PNG on `origin/ruffle-image-results`). Then: fix it (the owning rule's
   LOW arm should not apply where Flash disagrees: grade against the FP32 capture, per region), or price it with the
   per-region evidence if the change is Flash-ward elsewhere in the same frame. Also check `movieclip_begin_gradient_fill`
   (same family) did not move.
2. **Rider `avm2/swz` (2/3 vs FP32):** our stack line is `Test.as:16` (the `load()` call), FP32's is `Test.as:12` (the
   `new URLLoader()` line). Flash reports an unhandled ErrorEvent with the stack captured when the DISPATCHER was
   constructed. Snapshot the call stack in the URLLoader constructor (`avm2_display.c` / `avm2_globals.c` URLLoader
   ctor; `avm2_error_callstack_tail`) and print that in `ul_deliver`. Expected: `swz` → pass; `loader_applicationDomain`
   stays pass.
3. **Rider AVM1 `tabIndex = null`:** FP32 (`w1-local-oracles/w2b-tabindex.t_child_numstr_null.txt`) prints
   `undefined` after `m.tabIndex = null` on a script-created clip; we print `0`. Fix in the `actionSetMember` tabIndex
   block (`ab56ff360` landed the raw-mode rule there); add the fixture
   `session29-fanout-reports/w2b-tabindex-oracle/t_child_numstr_null/` as `regression/avm1_tabindex_child_null` with
   that FP32 golden.
Ledger by name, both modes for 2–3 (shared runtime). Siblings: w2-rm-avm1-gnash-land (action.c MovieClip super
context, `ng_shared.c`), w2b-lowq-stroke (`render_webgpu.c` LOW stroke path). Name every function you touch.
