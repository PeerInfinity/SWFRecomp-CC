# Slice: survive a lost WebGPU device in the browser build (Seedling at 0.4 fps headless)

**Baseline: `master` at the commit that adds this file.** CLAUDE.md and this
project's memory are auto-loaded — the launch protocol, the CI pipeline
(`.claude/pipeline-handoff.md`) and the standing traps come from there; don't
re-derive them.

**Another slice may be sharing this tree and CI.** `avm2-child-symbolclass-binding`
has pushed its code (`c4a952960`) and is in its CI phase, and an AVM1
`MovieClipLoader` slice will follow it. Your work is browser-only, so the file
sets don't overlap. Still: stage by name only, and **before you dispatch
`ruffle-tests.yml`, confirm no run of it is in progress or queued**
(`gh run list --workflow ruffle-tests.yml --status in_progress`, then
`--status queued`). If one is, `gh run watch` it to completion first.
Overlapping runs clobber each other's results merge.

## 1. The bug, as reported and checked

Reported 2026-09-11 by Archipelago-CC (`archipelago-cc-34`). Its full write-up
is Archipelago-CC `NewDocs/investigation/seedling-no-gpu-branch.md` §4; that
file is gitignored and on this machine at `/home/robert/CC/Archipelago-CC/`.
Summary:

- **Headless Chromium on SwiftShader** (Playwright 1.56, flags
  `--enable-unsafe-webgpu --ignore-gpu-blocklist --enable-unsafe-swiftshader
  --use-angle=swiftshader --no-sandbox`) loses the WebGPU device about 15 ms
  after the **second** `queue.submit` of every Seedling wasm build.
  `device.lost` resolves with `reason=unknown`, message *"A valid external
  Instance reference no longer exists."* After that, every
  `onSubmittedWorkDone()` rejects.
- The frames-in-flight park added in `fee8f23f7` (2026-06-27, the fix for N's
  <1 fps present-queue backlog) then runs its guard to the cap on every other
  frame: `render_webgpu.c` `render_webgpu_open_pass`, `MAX_FRAMES_IN_FLIGHT 2`,
  `emscripten_sleep(1)` ×1000 ≈ 4.4 s. Result: `__swfPerf.cpu` alternates
  `~44 / ~4700` ms, i.e. about 0.4 fps, and headless readback is 0% non-black.
- A fresh `requestDevice()` on the same adapter from page JS works fine
  afterwards. **Real-GPU Windows Chrome shows no loss** (24 fps).
- Cost today: Archipelago-CC's two headless Seedling CI gates spend 161 s and
  897 s per run inside this, and its bot differential hardcodes
  `SECONDS_PER_FRAME=2.5` to work around it.

Checked by the launching session against `c4a952960`:
- The park/guard (`:2438-2444`), work-done registration (`:3494-3503`,
  `AllowSpontaneous`) and full-adapter-limits request (`:1007-1013`) are as
  described.
- `on_frame_work_done` ignores its status, and the device request sets **no
  `deviceLostCallbackInfo`**, so the runtime cannot tell the device is gone.
- **The runtime is not what drops the instance.** Its only
  `wgpuInstanceRelease` (`:5701`, `render_webgpu_free`) is reached only via
  `avm2_render_shutdown`, which is compiled under `OFFSCREEN_RENDER` only. That
  string exists in **both** Dawns. In the emdawnwebgpu port
  (`emsdk/upstream/emscripten/cache/ports/emdawnwebgpu/.../webgpu.cpp:1024`) it
  is the DeviceLost event completing with `EventCompletionType::Shutdown`. A
  JS-level `GPUDevice.lost` / promise rejection can only carry a
  **browser-side** message, so the loss most likely comes from Chromium's
  GPU-process Dawn: its instance going away on a GPU-process crash or restart
  under SwiftShader, possibly the GPU watchdog on a ~1 s CPU-rasterised submit.
  Treat that as the lead, not a finding.
- **The per-frame pageerror flood is emdawnwebgpu's own glue.**
  `library_webgpu.js:2124` attaches no `.catch` to `queue.onSubmittedWorkDone()`
  ("assumed not to reject"). So every rejection is an unhandled promise
  rejection, and the C callback never fires, which is why `g_frames_in_flight`
  never decrements.

## 2. The work, in priority order

**A (must land): degrade gracefully when the device is lost.**
- Register a device-lost callback.
- Once the device is lost, stop parking and stop issuing GPU work, while the
  AVM, the render walk's side effects, and frame pacing keep running normally.
  Expect about 20 ticks/s headless.
- Make the park itself robust: a work-done callback that never comes should not
  cost 4.4 s per frame even without a lost-device signal. Decide whether the
  guard's cap should be much smaller, or wall-clock based.
- Decide whether to try re-requesting a device (a fresh `requestDevice` works,
  per the report). It is optional. If you do it, the renderer's GPU resources
  must be rebuilt, which may be too big for this slice. Say which you chose and
  why.
- Do not patch the emsdk port's JS glue in place: it is a cache, and a rebuilt
  port would silently revert it. If the unhandled rejection needs handling, do
  it from our side (e.g. the device-lost flag stops new `onSubmittedWorkDone`
  registrations). If an upstream bug report is warranted, write the text in
  your closeout; don't file it.

**B (time-boxed, about a third of the session): why SwiftShader loses the
device.** Getting real pixels back headless would be worth a lot. Start with
Chromium's logs (`--enable-logging=stderr --v=1`, GPU-process crash lines,
chrome://gpu in a headed SwiftShader run), then A/B the report's three
candidates one at a time: MSAA 1 vs 4 (`MSAA_SAMPLES`; never write a literal 4,
per memory `graphics-fanout-playbook`), default vs adapter-max `requiredLimits`,
and the per-tick 103 KB `writeTexture`. If it's a Chromium or SwiftShader limit
we can avoid with a setting, fix it. If not, document what you ruled out.

## 3. Grading

- **Headless SwiftShader, before and after**, on a Seedling build: per-frame
  `__swfPerf.cpu`, count of `device.lost` events, count of "external Instance"
  pageerrors, and ticks/s over a fixed window. Build with
  `SWFRecomp/scripts/build_wasm_avm2.sh` (memory `avm2-stage13-browser-13a`). A
  FRESH=1 Seedling build is about 19 min, so do it once and then iterate
  runtime-only if the build scripts allow. Archipelago-CC's page and harness are
  a second check, but **don't modify anything in Archipelago-CC**.
- **Real-GPU regression check (mandatory): the park must still do its job.**
  `fee8f23f7` fixed N freezing below 1 fps from a present-queue backlog, so
  measure N and Seedling on real-GPU Windows Chrome before and after (memory
  `windows-playwright-from-wsl`; never take perf numbers from WSL Chrome, which
  is SwiftShader). Expect unchanged fps and present time.
- Prove the native modes are byte-identical with `cpp -P` (graphics
  `-DOFFSCREEN_RENDER`, and `-DNO_GRAPHICS`) if your edit stays inside
  `__EMSCRIPTEN__ && !OFFSCREEN_RENDER` arms. **Still dispatch one CI run**
  (graphics, `categories=all`, `images=false`): `wasm-link-smoke` builds the
  BROWSER config on every dispatch, and a red one IS evidence. Expected: flat
  corpus (read it with `scripts/corpus_status_diff.py`).
- **A headless-SwiftShader smoke check, if cheap.** The report's proposed
  assertion: boot, wait about 3 s after Start, then check `device.lost` is still
  pending (or handled), there are zero "external Instance" pageerrors, and no
  frame took over 1 s. Wiring it into this repo's CI is optional. If you don't,
  record the exact check in the closeout for whoever does.

## 4. Traps

- **WSL/WSLg Chrome is SwiftShader.** It's the target environment for A/B and
  part B, and never valid for perf claims about real users.
- **A WebGPU canvas screenshot is blank white under WSLg** even when it renders
  fine. Use the GPU readback (memory `browser-child-probe-harness`).
- The `:8010` server serves `docs2/`. Serve what you need on a fresh port and
  check `readlink /proc/<pid>/cwd`.
- Don't instrument with a per-frame dump; it freezes the page (memory
  `browser-wasm-perframe-dump-freezes-page`).
- Pattern kills are guard-denied. Use literal PIDs. `git stash` is shared
  across worktrees.
- **Never run full test suites locally** (CLAUDE.md).

## 5. Done means

1. Closeout doc `SWFRecompDocs/status/browser-webgpu-device-lost.md`: the
   mechanism (part A), part B's findings (fixed, or ruled out with evidence), the
   before/after tables for headless and real GPU, and the CI run ID.
2. BACKLOG §Browser-WASM — rendering: add an entry for whatever part B leaves
   open.
3. Memory: a new entry for the device-lost handling and the two-Dawns / unhandled
   work-done-rejection facts, plus a pointer in `MEMORY.md`.
4. Commit and push to `master`, CI per §3, merge `ruffle-test-results`.
5. **Handoff line for Archipelago-CC.** Its pinned Seedling wasms
   (PeerInfinity/seedling-wasm @071ac1c) keep the bug until they are rebuilt
   from the fixed runtime. That rebuild and re-pin is Archipelago-CC's job, so
   put the exact runtime commit and what to verify in your REPORT BACK.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
