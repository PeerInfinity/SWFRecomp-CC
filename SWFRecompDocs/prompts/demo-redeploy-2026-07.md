# Session prompt: redeploy browser demos with the July 2026 runtime improvements

Rebuild and redeploy the docs2 (and, where applicable, docs/) browser demos so
the deployed WASM picks up the accumulated runtime work, none of which is in
the currently-deployed builds (deployed wasm is gitignored — rebuilds are the
only delivery path):

- default-on GC (`bac8b31e8`+`427f0abb1`), dprops/array leak fixes
- the three dispatch Stage-0 fixes (`d8abc5c0a`, `9a8c6dce3`, `60070d96a`)
- sprite-DL realloc/free hardening + right-sized initial capacity (`2f20b1c59`)
- loop-back identity preservation (`9030c61d9`) and backward-goto dynamic-child
  survivorship (`ae9a841a3`)

## Traps (all previously hit — read the memory entries)

- **Catalog type:** do NOT pass `--demo-type graphics` when redeploying
  flasharchive/glaiel demos — the catalog `type` must equal the namespace or
  the index breaks (`docs2-demo-redeploy-catalog-type` memory).
- **docs/ vs docs2/:** docs/ is public GitHub Pages, OSS-licensed content only;
  game SWFs deploy to docs2/ (local-only). Don't move content across the line
  (`docs-vs-docs2-hosting`).
- **Browser-WASM graphics builds** need the documented flags
  (`--use-port=emdawnwebgpu`, `-sASYNCIFY`, `-DUSE_WEBGPU`, 8MB stack); use
  `build_test.sh <test> wasm --graphics` + `deploy_example.sh` per demo, or the
  batch script if the full set is being done.
- Note which demos previously carried deploy-only diagnostic patches (N's A/B
  toggles / HUD variants under /tmp) — deploy CLEAN master builds; the gated
  perf HUD in master is fine (it now includes the live-objects line).

## Verification (browser, headed probes work from the agent shell)

`DISPLAY=:0` + localhost HTTP per `browser_wasm_test_capture` memory; graphics
demos need the Run click (`demo.html?test=...`, `runSwf()` after
`#btn-run:not([disabled])`).

1. **N title demo, `?perfhud=1`, 2+ minutes:** live-objects line hovers ~4k
   flat (the GC sanity check) instead of climbing; no leftover laser/death
   lines; fps stable.
2. **Minesweeper:** difficulty screen → game → restart; radios/textfield work;
   no white-canvas or freeze; spacebar flagging works.
3. **Doodle Jump + Tetris:** load, run ~30s, basic input.
4. Spot-check one trace demo and the demo index page render.

No runtime code changes expected this session. If a browser check FAILS, that
is a finding — capture it (screenshot/console), check whether it reproduces on
a pre-GC build (`SWF_GC=0` via env at build or the runtime flag), document,
and stop rather than hot-patching the runtime mid-deploy.

## Close-out

Note the redeploy (date, commit deployed from) in the results doc or a short
status doc, update the pending-redeploy line in the
`upstream-comparison-doc-directory` memory, `.pipeline-state` n/a (no CI —
deploys aren't CI-observable).
