**Implement `w1-avm2-tail` L3 + L4 + L5 as a landable patch** (report `SWFRecompDocs/plans/session24-fanout-reports/w1-avm2-tail-report.md` §3–§5, §8 W2-b; start from those hunks of `w1-avm2-tail-prototype.patch`). Categories to download: `avm2 mixed_avm from_avmplus`.

EXPECTED-FLIP LEDGER: trace `avm2/weird_number_bound_methods` → pass, `avm2/primitive_bound_methods` → ruffle_matched (both known_failure: gains), `avm2/textline_metrics` → pass, `avm2/worker_terminate` → pass; graphics and no-graphics. 0 other moves.

1. L3 bound-method side cache as measured; add `primitive_bound_methods` to `ruffle-tests/tests/swfs/avm2/_investigation/RUFFLE_COMPAT_TWEAKS.md` (or the avm1 one if avm2 has none — check) with the pointer-equal-string rationale.
2. L4 DefineFont4: replace the weak-symbol read with a proper extern table in `avm2_abc.h` + the DYNAMIC_HOST loader (mirror `avm2_generated_device_fonts`) so the browser bundle gets real metrics too; verify the in-browser recompiler build path compiles (`SWFRecomp/scripts/deploy_wasm_demo.sh` style build is NOT required to run — a header/extern consistency check plus a native `--recompile` run is enough; say what you checked). Recompiler change: rebuild and `--recompile` every row you run.
3. L5 Worker: give the pending-worker drain its own call beside `avm2_media_poll` in `avm2_main.c` (both sites) instead of hooking `avm2_media_poll`.
4. Re-run the report's L3 (35), L4 (26, `--recompile`) and L5 sweeps against clean origin/master; categories=full shape.
Siblings: `w2-avm2-netstream-sound` owns `avm2_net.c` / `avm2_media.c` (you may only add the Worker drain call in `avm2_main.c`); `w2-bitmap-encode-shader` owns `avm2_bitmap.c`.
