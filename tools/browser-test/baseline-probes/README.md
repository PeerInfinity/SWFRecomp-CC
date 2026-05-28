# Baseline probes

Single-script Playwright probes that exercise the canonical demos
(Snake, DJ, Pong) end-to-end in browser-WASM and screenshot the
result. Used as the manual don't-regress check after runtime changes
that touch shared graphics-mode code.

These are NOT the wasm probe suite (which lives at
`SWFRecomp/tests/wasm_probes/` and runs via
`tools/wasm_probe_runner.py` with golden-image diffing). Baseline
probes are larger-scope visual sanity checks — they reach into actual
gameplay / sub-screens that the targeted unit probes can't easily
isolate.

## Inventory

| Probe | What it checks | Screenshots written to |
|---|---|---|
| `snake_title.py` | Snake title screen (no click): SNAKE / CHOOSE LEVEL / SLUG WORM PYTHON / URL all positioned correctly. | `/tmp/snake-title-shots/` |
| `snake_gameplay.py` | Snake title → click slug → countdown → gameplay → game-over. Uses hover + explicit mouse.down/up because `page.mouse.click` can get swallowed by the button's OVER-state animation. | `/tmp/snake-play-shots/` |
| `dj_menu.py` | DJ menu (no click): doodle character + play/info/scores/options buttons all positioned correctly. | `/tmp/dj-baseline-shots/` |
| `dj_info.py` | DJ menu → click play coords (which actually lands on info on the current canvas scaling). Verifies the info-subscreen renders, "mushroom: inverse control" not truncated. | `/tmp/dj-play-shots/` |
| `pong_loading.py` | Pong loading screen renders (notebook paper background + "Glaiel Games.Com" handwritten signature). | `/tmp/pong-baseline-shots/` |

Note: each probe currently writes its screenshots to a fixed `/tmp/<name>-shots/`
directory. That's intentional — the artifacts are throwaway, the
probe scripts themselves are what's worth keeping. Inspect via
`Read /tmp/.../<filename>.png` after running.

## Running

Each probe is standalone:

```bash
xvfb-run -a /tmp/pong-probe/venv/bin/python tools/browser-test/baseline-probes/<probe>.py
```

`xvfb-run` is needed in the WSL2 environment because the probes
launch a headed Chromium (more reliable than headless for WebGPU).

## Venv dependencies

The Playwright venv at `/tmp/pong-probe/venv/` is a runtime
dependency. To recreate from scratch:

```bash
python3 -m venv /tmp/pong-probe/venv
/tmp/pong-probe/venv/bin/pip install playwright
/tmp/pong-probe/venv/bin/playwright install chromium
# Plus Pillow if running the wasm probe suite too:
/tmp/pong-probe/venv/bin/pip install Pillow
```

The venv is not committed (lives outside the repo).

## When to run

After any change to `SWFModernRuntime/src/libswf/tag.c`,
`actionmodern/action.c`, `libswf/swf.c`, or the recompiler
(`SWFRecomp/src/swf.cpp`), run all five probes and visually inspect
the screenshots. If the wasm probe suite (`tools/wasm_probe_runner.py`)
also passes, that's a strong signal the change is safe.
