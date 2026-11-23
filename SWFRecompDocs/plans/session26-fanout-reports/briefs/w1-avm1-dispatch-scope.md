**AVM1 dispatch / scope leftovers from s25** (arc §26.4). Categories: `avm1`, `regression`, `from_gnash` (+ what your probes need).

Each item is small and was found but not fixed by an s25 worker; read `session25-fanout-reports/w2-avm1-with-scope-report.md`, `w2-netstream-flv-screen-report.md`, `w1-pixel-drawing-report.md`, `w2-edittext-span-model-report.md`, `w1-pixel-text-report.md` (their "New unclaimed leads") first:
1. sibling bare-call arms that ignore `with` (`createTextField` hard-codes root, …) — enumerate every bare MovieClip-method call arm and which ones resolve against the `with`/scope chain;
2. type-2 dispatch arms missing the MC-receiver flag pair (w2-netstream L2) and the function-form `setInterval(f, ms)`/`setTimeout` timer arm (L3);
3. hairline `lineStyle(0)` Drawing-API `hitTest(shapeflag)`;
4. CallMethod `createTextField` depth / numeric-name residual;
5. keyboard/IME edit paths dropping HTML run tables; `setNewTextFormat` writing `textColor`;
6. `replace_at_depth` for `createTextField`/`createEmptyMovieClip`;
7. device-text x-scale for DefineEditText device fields; the SWF≤7 wrap give-up rule in the other wrap loops.

None has a failing corpus row today (verify: grep the baseline failing list `../s26-baseline-trace-failing.txt`; `movieclip_hittest_shapeflag` is ACCEPTED_DIFFS Cat 8 — re-test that claim against item 3). So each GO needs a `regression/` fixture whose golden comes from the Ruffle exporter (timers excepted: the exporter never fires them — for item 2 use an MTASC/hand-built SWF and reason from Ruffle source, mark the golden "analytic, Ruffle-source-derived" and request a run anyway). Write fixture SWF sources + build scripts, put each request under LOCAL ORACLE REQUESTS. Prototype the cheap ones, measured, with a ~40-test argued sweep in both modes. Rank by game-visibility. Siblings: `w1-attached-button-dispatch` owns button dispatch + button-bound EditText; `w1-runtime-robustness` owns `ng_shared.c` caps.
