# Ruffle local patches (oracle + perf tooling)

Our SWFRecomp work uses a **locally patched checkout of Ruffle** at `~/CC/ruffle`
as a correctness/perf oracle. The patches are **uncommitted in that external
working tree** (not in this repo, not upstreamable as-is), so this doc + the
vendored patch file are how we keep them from getting lost across `git pull`s of
Ruffle.

- **Vendored full patch:** [`ruffle-local-patches.patch`](ruffle-local-patches.patch)
  — the complete working-tree diff (incl. the two new files), covering every
  patch below. Re-apply after updating the Ruffle checkout:
  ```bash
  cd ~/CC/ruffle && git apply /home/robert/CC/SWFRecomp-CC/SWFRecompDocs/reference/ruffle-local-patches.patch
  ```
- **Base commit:** captured against upstream Ruffle HEAD `be11d7e89`
  ("chore: Bump the cargo-minor group with 13 updates", 2026-07-22). Regenerate
  the vendored patch after any re-apply/rebase so this stays current (recipe at
  the bottom).
- **Last update: 2026-07-22, `7ea7c8882` → `be11d7e89` (228 commits).** Done with
  `git stash push -u` → `git merge --ff-only origin/master` → `git stash pop`,
  which 3-way-merges rather than context-matching a patch. Upstream had touched 3
  of the 12 patched files; **one conflict**, in `core/src/tag_utils.rs` (B1):
  `SwfMovie::from_data` gained a 4th parameter, so the call became
  `from_data(&data, url, loader_url, None)` — our `url` is already a `String`, so
  upstream's `.into()` is not needed. Verified after: exporter rebuilds clean
  (4m57s), and a 360-frame Elephant Quest oracle run reproduces
  `DOMAIN = armorgames.com` (B1), the served AGI.swf banner (B4), the input
  replay (B2) and the tracing log (B3) — with the menu frame **byte-identical
  (MAD 0.0000)** to the pre-update build. The pre-update stash is retained as
  `stash@{0}` in that checkout ("SWFRecomp local patches pre-update 2026-07-22");
  drop it once you trust the vendored patch.
- **Older single-purpose doc:** [`../ruffle-probing-trace-log.md`](../ruffle-probing-trace-log.md)
  + `../probing-trace-log.patch` document **only** the `--trace-log` patch
  (family A below); this doc supersedes it as the full inventory. The trace-log
  patch itself is unchanged and is now part of the vendored full patch.

> The prebuilt binary at `~/CC/ruffle/target/release/exporter` may lag the
> source. Rebuild after (re-)applying: `cargo build --release -p exporter`
> (~4.5 min cold, no nightly required; the older doc's `+nightly` is not needed).

---

## Family A — `--trace-log`: capture AVM `trace()` output to a file

The original patch. Lets the exporter write AVM `trace()` / `avm_warning` output
to a file alongside the rendered PNG, so we can grade trace parity against
SWFRecomp test suites.

- **Flag:** `--trace-log <PATH>` (single-SWF export). One message per line;
  warnings prefixed `Warning: `.
- **Files:** `exporter/src/cli.rs` (the `Opt::trace_log` field),
  `exporter/src/exporter.rs` (`TraceLogBackend` impl of `LogBackend`, wired via
  `PlayerBuilder::with_log`), `exporter/src/lib.rs` (writes the file after export).
- **Usage:** `exporter movie.swf out.png --trace-log out.txt`

## Family B — the game-bring-up oracle harness (exporter)

The bundle that turns the exporter into a scriptable, environment-faithful oracle
for AS3 game bring-ups (Seedling, Robot-Wants, Elephant Quest). Four independent,
env-gated pieces; each is inert when its env var / file is unset.

### B1 — `RUFFLE_MOVIE_URL`: override `stage.loaderInfo.url`
- **Env:** `RUFFLE_MOVIE_URL=<url>`. When set, the movie's URL (hence
  `loaderInfo.url`, the parsed domain, and Security checks) is this value instead
  of the canonical `file://` path. Mirrors SWFRecomp's `-DSWF_URL`/`GAME_SWF_URL`
  build lever, so a game's portal/sitelock/domain logic resolves the same way in
  both. (E.g. `http://armorgames.com/...` makes Elephant Quest trace
  `DOMAIN = armorgames.com` and its AGI absolute-URL fetch + `allowDomain` stubs
  resolve.)
- **File:** `core/src/tag_utils.rs` (`movie_from_path`).

### B2 — `RUFFLE_INPUT_FILE`: scripted input replay
- **Env:** `RUFFLE_INPUT_FILE=<input.json>`. Replays a Ruffle-test-format
  `input.json` (`MouseMove`/`MouseDown`/`MouseUp`/`KeyDown`/`Wait`/…),
  **one event applied per exported frame**. This is how we drive menus, clicks
  ("New Game"), and keyboard gameplay headlessly.
- **Files:** `exporter/src/exporter.rs` (`InputInjector` wired into `run_frame`),
  **`exporter/src/automation.rs`** (new — `perform_automated_event`, maps input
  events to `PlayerEvent`s), `exporter/Cargo.toml` (dep on `ruffle_input_format`
  at `../tests/input-format`), `exporter/src/lib.rs` (`mod automation`).
- **Gotcha (from RWK):** Flixel/FlashPunk reset keys on state switch — press only
  *after* the target state starts. Frame N of the PNG output = after event N.

### B3 — `RUST_LOG` tracing subscriber: surface uncaught AVM2 errors *(added 2026-07-21)*
- **Why:** the stock exporter installs **no** tracing subscriber, so
  `ruffle_core`'s `tracing::error!`/`warn!` — **uncaught AS3 errors and
  unimplemented-API stubs** — are silently dropped; only `avm_trace` via
  `--trace-log` was capturable. This patch routes them to stderr.
- **Env:** `RUST_LOG` (default `info`). Run with `... 2> log.txt` to capture.
  This is what made Elephant Quest's `Error #1010` and the world-map watchdog
  `RustError("...taken too long to execute...")` visible.
- **Files:** `exporter/src/main.rs` (`tracing_subscriber::fmt()` init),
  `exporter/Cargo.toml` (`tracing`, `tracing-subscriber` deps).

### B4 — `RUFFLE_LOCAL_FETCH_DIR`: file-serving navigator *(added 2026-07-21)*
- **Why:** the stock exporter uses `NullNavigatorBackend` — **every** external
  fetch fails silently, which masks a game's real failure behind an early
  missing-dependency error (see [[ruffle-oracle-nullnav-perf-watchdog]]). This
  serves external SWFs/assets from local files so the game's environment is
  faithfully reproduced *without* a live network stack.
- **Env:** `RUFFLE_LOCAL_FETCH_DIR=<dir>`. Maps `http(s)://host/path` →
  `<dir>/host/path` (same scheme as Ruffle's own `TestNavigatorBackend`). Fetch
  futures run on a `NullExecutor` polled once per frame.
- **Files:** **`exporter/src/local_navigator.rs`** (new — `LocalFileNavigator`),
  `exporter/src/exporter.rs` (wires the navigator + per-frame executor pump),
  `exporter/src/lib.rs` (`mod local_navigator`), `exporter/Cargo.toml`
  (`url`, `async-channel` deps).
- **Recipe:** download the real asset to `<dir>/host/path` (e.g.
  `fetchroot/cache.armorgames.com/assets/agi/AGI.swf`), then set
  `RUFFLE_LOCAL_FETCH_DIR` + `RUFFLE_MOVIE_URL` together.

**Combined oracle run (the Elephant Quest recipe):**
```bash
RUST_LOG=info \
RUFFLE_INPUT_FILE=input.json \
RUFFLE_LOCAL_FETCH_DIR=fetchroot \
RUFFLE_MOVIE_URL="http://armorgames.com/566862_ElephantQuest.swf" \
  ~/CC/ruffle/target/release/exporter game.swf outdir/ --frames 850 --graphics gl -s 2> log.txt
```
(The multi-frame output arg must be a **directory** — a `.png` path silently
keeps one frame. `--frames N`, `-s`/`--silent`, `--graphics gl` are stock flags.)

**Gotcha — frame filenames are zero-padded to the WIDTH OF THE FRAME COUNT**, not
a fixed 4: `--frames 1200` writes `0000.png`…`1199.png`, `--frames 360` writes
`000.png`…`359.png`. A comparison harness that hardcodes `%04d` silently finds
nothing when the frame count changes. Glob the directory instead.

## Family C — browser perf-comparison instrumentation (web + wgpu)

For apples-to-apples Ruffle-vs-SWFRecomp browser perf A/Bs (see
`tools/divergence/perf/WINDOWS_PLAYWRIGHT_FROM_WSL.md`). All gated behind the web
crate's `profiling` cargo feature, so **default web builds are byte-for-byte
unchanged**.

- **What:** per-frame CPU timing split into `tick` (AVM/sim) and `render`
  (command-build + GPU submit), pushed onto JS ring buffers
  `window.__rufflePerfTick` / `__rufflePerfRender` (cap 600) + scalars
  `__rufflePerfLastTick` / `__rufflePerfLastRender`; plus a per-frame shape
  `draw_indexed` count via a `draw_counter` atomic. An external harness reads
  these the same way it reads SWFRecomp's `swf_perf_report` HUD. Mirrors the
  SWFRecomp perf HUD for direct comparison.
- **Feature flags:** build the web crate with `--features profiling`
  (pulls in `ruffle_render_wgpu/draw_counter`).
- **Files:** `web/src/lib.rs` (`record_frame_ms`, timing in the tick closure),
  `web/Cargo.toml` (`profiling` feature + `Performance` websys feature),
  `render/wgpu/src/lib.rs` (`DRAW_CALLS` atomic + `take_draw_calls()`),
  `render/wgpu/src/surface/commands.rs` (increment on `draw_indexed`),
  `render/wgpu/Cargo.toml` (`draw_counter` feature).
- **Reminder:** WSL/WSLg Chrome is SwiftShader — never use it for perf numbers;
  drive Windows Chrome from WSL per the perf doc.

---

## Regenerating this vendored patch

After re-applying and/or extending the patches in `~/CC/ruffle`, refresh the
vendored copy (includes the untracked new files via intent-to-add, then undoes
it):
```bash
cd ~/CC/ruffle
git add -N exporter/src/automation.rs exporter/src/local_navigator.rs
{ echo "# Ruffle local patches vs upstream HEAD $(git rev-parse --short HEAD)"; \
  echo "# Re-apply: git apply <this file>  (from ~/CC/ruffle)"; echo "#"; \
  git diff HEAD; } > /home/robert/CC/SWFRecomp-CC/SWFRecompDocs/reference/ruffle-local-patches.patch
git reset -q -- exporter/src/automation.rs exporter/src/local_navigator.rs
```
Then update the base-commit hash and any new env var / flag in this doc.
