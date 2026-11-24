# s27 browser-arms-land: browser-WASM AVM1 no-op arms, checked in a real browser build

**Slot:** local one-task session (brief: `browser-arms-land-prompt.md`). **Inputs:**
`w1-browser-avm1-gaps-report.md` / `-prototype.patch` / `-fixtures/`, and the coordinator's probe
`w1-local-oracles/w1-browser-avm1-gaps/browser_probe_run_{a,b}.txt`.

**Landed (one commit, hunks staged individually):**
- the prototype patch as delivered: 18 `action.c` NG‖OR gates deleted, the `actionGetVariableImpl` collapse, the
  `verify_output.py` `SWF_BROWSER_ARMS_TU` harness, and the `gate_inventory.py` `browser-stub`/`browser-thin` categories;
- `tag.c` `tagDefineButton`: `ng_record_button` ungated. This fixes `color` in the browser (§2);
- `action.c`: `getBounds`/`getRect` on a TextField return `undefined`, matching Flash (§4). **This one is CI-visible**;
- `gate_inventory.py`: a new `browser-registry` category; `verify_output.py`: the harness's measured fidelity limit (§3);
- three fixtures in `regression/` with Flash 32 goldens; the Flash traces and this session's probe log
  (`browser_probe_run_c.txt`) are under `w1-local-oracles/w1-browser-avm1-gaps/`.

## 1. Rows, real browser build (`tools/browser-test/child_probe/`)

The comparison drops blank lines and the WebGPU console warning. The probe's trace capture loses empty `trace("")`
lines, so its own "TRACE MATCHES" never fires on these rows.

| Row | Prototype only (coordinator probe) | After this session | Owner / completion mechanism |
|---|---|---|---|
| fixture `avm1_browser_gated_textfield` | matches native | **matches** (golden now Flash: line 7 `undefined`) | done |
| fixture `avm1_browser_gated_depth` | matches | **matches** | done |
| fixture `avm1_browser_gated_color` | matches | **matches** | done |
| avm1/`movieclip_create_text_field` | matches | **matches** | done |
| avm1/`color` | 2 rows wrong (pre-tinted button: identity transform, `getRGB` undefined) | **matches** | fixed: button registry (§2) |
| avm1/`movieclip_getbounds` | every clip query is the 6710886 sentinel | same, 140 lines | **lazy browser sprite build** (§3.2) |
| avm1/`transform` | reported as matching, but **it never did** (see below) | 7 lines: `clip.clip.transform` reads the outer `clip` | same as above (§3.2) |
| avm1/`duplicate_movie_clip` | `load:` order (the predicted HOLD) | same, 13 lines | AQ_KIND_LOAD deferral (§3.3), which belongs to the same mechanism |

**Correction to the coordinator's probe:** `browser_probe.sh` printed `run_child_probe.py … | tail -25`. For
`transform` that dropped the first 20 lines, which are where the diff is. The `transform` row in `run_a` shows only
the tail. So "transform matches native" came from truncated output. I bisected that the current failure is not caused by
anything landed since the probe base `c60f439e1`. I swapped in `c60f439e1`'s `tag.c`, reverted this session's button
hunk, and reverted the `438121c22` `parent_for_init` hunk; the result is the same wrong matrix every time. The
`movieclip_getbounds` row in `run_b` was truncated the same way: only `clip3.getBounds(o)` was visible, but every
query fails.

## 2. `color`: the browser never registered buttons

Instrumenting the real browser build showed:
- `GetVariable("btn")` → `ng_findDisplayEntryByName` finds depth 5, but `ng_isScriptableAtDepth(5) == 0`, so it
  resolves to `_root`;
- `new Color(_root)` gets no `__mc_name__`, so `getRGB` → `undefined` and `getTransform` → identity;
- the display entry itself holds the right cxform (`cx_rb = -50`).

`ng_isScriptableAtDepth` asks `ng_find_button`. Its table is filled only by `tagDefineButton`'s `ng_record_button`,
which sat in `#if NO_GRAPHICS || OFFSCREEN_RENDER` (`tag.c:14361`, from `feb8882b0`). **The prototype's
GetVariable collapse made this load-bearing.** The old browser-only arm used `findDisplayObjectByName` and never asked
about scriptability. The CI arm it collapsed to does. Without the ungate, the prototype would have turned *every
named button* in the browser into `_root`. Before the prototype that was only a mis-numbered `instanceN` auto-name
for unnamed buttons, also a bug and fixed by the same line. `ng_record_button` (`ng_shared.c`) is unconditional, so
the browser link is unchanged.

## 3. Why the native harness passes rows the browser fails

`SWF_BROWSER_ARMS_TU=action.c` compiles only `action.c` with browser defines. `tag.c`, `swf.c` and `tag_stubs.c` stay
CI-graphics. Three measured classes fall through that gap. All three are now written into `verify_output.py` next to
the harness.

1. **Definition-time tables gated off the browser** (`color`). The harness's `tag.c` fills the table, the browser's
   does not, and the reader is in `action.c`. `gate_inventory.py` now classifies these as **`browser-registry`**: a
   `browser-none` site in a `tagDefine*` body or one that calls `ng_record_*` / `ng_register_*`. On `HEAD` before
   this commit it finds exactly 2: `tagDefineButton` (fixed here) and `tag_stubs.c:1193`
   `ng_record_sprite_self_goto`. The second is a `swf_core`/OFFSCREEN frame-loop goto record, not a table that
   `action.c` reads, so it is a false positive to keep in mind. After this commit only the second is left.
2. **The browser builds sprite children lazily** (`movieclip_getbounds`, `transform`). Instrumented `getBounds` in
   the browser:
   - a root-level sprite (`clip4`) has `display_obj` set but `sprite_display_list == NULL` while the frame-1 DoAction
     runs;
   - nested `clip.clip` has no `display_obj`, and the name walk dies on the parent's NULL list.

   The cause is the frame loop. The browser `tagPlaceObject2` arm (`tag.c` `#if !NG && !OR` block before
   `ng_on_place_object2`) skips `ng_on_place_object2` and the INIT/CONSTRUCT/LOAD queue. The eager-init machinery,
   `process_sprite_needs_init` / `process_sprite_init_at_depth` (`tag.c:527–999`, NG‖OR only), has a browser stub.
   `swf.c` says it outright: "Timeline sprites still advance later, inside tagShowFrame, in this build". So a sprite's
   frame-0 children exist only after `advance_sprite_frames` inside `tagShowFrame`, which runs *after* the frame's
   DoAction. Flash builds them before the parent's script runs.

   The `getBounds` code itself is correct; it has no display list to read. `transform` fails the same way: `clip.clip`
   resolves to the outer `clip`. I deliberately did not patch `getBounds` around this. Any frame-N query of a frame-N
   sprite's children is wrong in the browser, and a bounds-from-definition fallback would hide that.
3. **AQ_KIND_LOAD ordering** (`duplicate_movie_clip`). The browser `tagPlaceObject2` arm defers `onClipEvent(load)` to
   `AQ_KIND_LOAD` so that it drains after `tagShowFrame` has built the children (the Doodle Jump `button_txt`
   comment). `actionCloneSprite`'s browser-only `AQ_KIND_LOAD` drain pairs with it. This is a compensation for
   class 2, not an independent bug.

**Completion mechanism for classes 2 and 3 (one item):** port eager placement init to the browser frame loop. That
means running `ng_on_place_object2` plus the INIT/CONSTRUCT/REGISTER_CTOR/LOAD queue and `process_sprite_needs_init`
in the browser `tagPlaceObject2` and `tagSetClipActions` arms (the `tag.c` stubs at `:12229`/`:12809` in the w1
report's numbering). Then delete the AQ_KIND_LOAD deferral and the `actionCloneSprite` browser drain.
- **Price: M–L.** Every browser-played AVM1 game rides this path (Doodle Jump, Pacman, N), and the w1 report's "New
  leads" item already called it M with a browser oracle.
- **Oracle:** these three corpus rows, `child_probe`, plus a browser game smoke before and after.

The harness cannot measure it until it can build `tag.c` in browser mode. The w1 report measured 23 multiple-definition
clashes for that and needs a link shim.

## 4. Fixture line 7: Flash says a TextField has no getBounds

`tools/flash-oracle/run_trace.py` (Linux Flash 32 debug projector):

| Fixture | Flash direct | Flash `--wrapped` | Ruffle exporter |
|---|---|---|---|
| `avm1_browser_gated_textfield` | line 7 `tfA bounds undefined,…` | same | same |
| `avm1_browser_gated_depth` | byte-identical | — | identical |
| `avm1_browser_gated_color` | `cm a=3.12 d=1.56 tx=23.5 ty=7.75` | **byte-identical** | identical |

- **Textfield:** Flash and Ruffle agree, and our runtime was wrong in **every** build. `03bf11667` (Mar 2026) added a
  "this MC is a text field" bounds block. Fixed in `actionCallMethod`: TextField receivers of `getBounds`/`getRect`
  push `undefined`, and the dead block is removed. The `output.txt` golden is now Flash's.
- **Color:** the direct-mode `concatenatedMatrix` includes the projector window's stage scale (×1.56) and letterbox
  offset. That is an oracle-environment artifact; the wrapped run (which loads the SWF as a child, so no stage scale)
  matches the fixture exactly.

## 5. CI define sets (preprocess md5, `gcc -E -P`)

Run on `HEAD` (`d37ca69b5`) plus only this commit's hunks:

| Define set | `action.c` HEAD | + prototype | + TextField fix (final) | `tag.c` HEAD → final |
|---|---|---|---|---|
| graphics (`USE_WEBGPU OFFSCREEN_RENDER NDEBUG`) | `7efe7667` | `7efe7667` | `a8893c1f` | `945b820b` → `945b820b` |
| graphics + images (`+HEADLESS_RENDER_ENABLED`) | `7efe7667` | `7efe7667` | `a8893c1f` | `9a990dd6` → `9a990dd6` |
| no-graphics (`NO_GRAPHICS`) | `ee41911c` | `ee41911c` | `0dcaacf2` | `be066645` → `be066645` |
| browser (`USE_WEBGPU __EMSCRIPTEN__`) | `97c3d0e7` | `50dff5f4` | `6ace5305` | `b89040d5` → `f2547e4a` |

Two conclusions:
- The prototype and the button ungate are **CI-invisible** in every CI set (the w1 report's claim, re-proved on
  today's HEAD).
- The only CI-visible change is the 12-line TextField `getBounds` hunk, the same in all three sets. It needs one
  graphics `all` grading run; the coordinator folds it into its next one.

## 6. Native checks (local, single tests)

All pass:
- the 3 fixtures, in both no-graphics and graphics;
- `--mode=graphics`: `movieclip_getbounds`, `movieclip_create_text_field`, `color`, `transform`, `edittext_autosize`,
  `edittext_margins`, `textfield_properties`, `movieclip_invalid_get_bounds_1`, `button_v6`, `button_children`.

## 7. Not done

- The browser game smoke (optional goal 3) was not run. The button ungate is the change most worth smoking on a
  button-heavy flasharchive game.
- The `gate_inventory.py` selftest has no `browser-registry` fixture site. I checked the category on the live tree
  only (2 sites on HEAD).
- `SWFRecompDocs/reference/browser-wasm-gate-inventory.md` is still not regenerated (same reason as w1: a
  600-line churn).

**Next slice:** the browser eager-placement-init port (§3), with `movieclip_getbounds`, `transform` and
`duplicate_movie_clip` in child_probe plus a Doodle Jump / Pacman browser smoke as its oracle.
