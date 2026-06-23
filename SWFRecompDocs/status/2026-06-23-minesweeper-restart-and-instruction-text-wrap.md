# Minesweeper — RESTART bug + instruction-text paragraph breaks

**Date:** 2026-06-23
**Game:** flasharchive/Minesweeper, browser-WASM graphics (shared graphics text-render code).
**Bucket:** needs-browser (input-gated: the board + instruction text only appear after Start).

Follow-up to the 2026-06-22 Minesweeper board/click/Splash/number fixes. Picks up
the two open follow-ups recorded on the `a40540258` / `6ad7b62af` PROGRESS rows:
(1) the **Restart** "tile/text shift", and (2) the **instruction EditText word-wrap**
gap. They turned out to be the **same** root cause plus a non-bug.

## Symptoms (as reported)
- **Restart** (`DefineButton2_72` → `on(release){ gotoAndPlay(10); }`, which re-runs
  the board build over the still-existing 480 clones): the top-left tile (`cell0_0`)
  appeared to shift up-and-left, and the bottom instruction text "wrapped but its
  lines shifted left".
- **Instruction text doesn't wrap** (the bottom "Mouse click opens a spot…" field):
  the four lines collapsed onto one overflowing line.

## What was actually happening

### Board cells: NO bug (already correct)
Instrumented the composed render. After Restart, **every** clip's state is correct
and idempotent:
- All 71–205 revealed cells (Bomb/HotBomb/numbers) reset to frame 12 ("Unknown").
- `cell0_0` `mc->x/y = 18,18` (and `cell29_15 = 482,258`, etc.) — exact, unchanged
  before vs after Restart.
- `cell0_0`'s **composed world translation** (`render_attached_child` →
  `compose_children`) is exactly `(18.0, 18.0)` both before and after Restart, with
  the render actively running.

So the "tile shifts up-and-left" component does **not** reproduce in the current
build — it was resolved by the recent board-render / per-instance-text-glyph fixes
(`faeccbf11`, `f433bb69a`). No code change needed for the cells.

### Instruction text: the real bug — orphan HTML fields lose paragraph structure
The instruction field is `DefineEditText` chid 82: `multiline=true`,
**`wordWrap=false`**, `html=true`, fontId 3 / 9px `_sans` (device font), with **five
`<P>` paragraphs**:
```
<P>Mouse click opens a spot, </P><P>press SPACE to mark a spot, </P>
<P>hold SPACE and click to open </P><P>neighbor spots</P><P></P>
```
Because `wordWrap=false`, the field is *not* supposed to word-wrap — it is supposed
to break into separate lines at each `</P><P>` paragraph boundary. So "doesn't wrap"
was really "**paragraph breaks aren't rendering**".

Instrumenting the glyph renderer showed the field rendered:
- **on first entry (via Start):** `runs=0, pars=1` → text joined onto **one line**,
  every `<P>` stripped.
- **after a `gotoAndPlay(10)` re-entry (Restart):** `runs=13, pars=5` → correct
  paragraph breaks.

That flip is the "wraps but shifts left after Restart" report: the field only became
correct *after* Restart.

**Root cause.** A static `DefineEditText` is rendered two different ways depending on
whether it has acquired an MC wrapper:
- **No wrapper (orphan):** `actionIterateOrphanTextFields` → `otf_walk_dl` →
  `otf_emit_textfield`. This path passed `text_utf8 = ng_getTextFieldInitialTextByIdx`
  — the **plain, markup-stripped** text — with `runs = NULL`. The HTML paragraph
  structure is gone, so the renderer lays it out as one line.
- **With wrapper:** `findOrCreateMovieClip` parses the field's raw HTML into a
  `TFRunTable` (carrying `SENTINEL_TAG_BREAK` paragraph markers), and
  `actionIterateTextFieldGlyphs` renders from that table — correct.

The instruction field is never touched by AS, so on first entry it's an orphan
(one line). The `gotoAndPlay(10)` Restart happens to trigger a name lookup
(`findOrCreateMovieClip`), which builds the run table — which is why it only
rendered correctly after Restart.

## Fix
`otf_emit_textfield` (action.c): for an HTML field (`tf_flags & 0x0040`) whose text
still comes from the tag (not a bound variable), parse the tag's raw HTML
(`ng_getTextFieldRawHtml`) into a `TFRunTable` via `tf_parse_html` and emit the
resulting `TextFieldGlyphRun`s + table text (with paragraph-break sentinels) —
exactly the run-table the field would get once it acquired an MC wrapper. The
renderer already treats `0xFE`/`0xFF` as `\n`, so paragraphs lay out on separate
lines. Variable-bound fields keep their existing plain-text path (the variable
value, not the tag HTML).

Net effect: the orphan render now matches the with-wrapper render, so the
instruction text shows its four paragraphs on four lines **from the first frame**,
and Restart no longer changes it (the "shift on restart" disappears because there is
no longer a wrong→right transition).

## Verification (headed Chrome, Playwright)
A temporary `dbgInstr`/`dbgDumpCells` export (child_mc_cache walk + composed-matrix
capture, all stripped before commit) drove a Start → reveal → Restart probe:
- Before fix: first render `runs=0 pars=1` (one line); after Restart `runs=13 pars=5`.
- After fix: first render `runs=13 pars=5` (`Mouse…<P>press…<P>hold…<P>neighbor…`),
  **identical** before and after Restart. `cell0_0` composed world `(18,18)` throughout.
- Menu still renders correctly (its single-paragraph HTML fields "Difficulty:" /
  "Enter your name:" are unaffected — confirms single-paragraph HTML is unchanged).

Board pixel screenshots still hang in WSL2 (480-cell SwiftShader present saturation);
verification is via the rendered run/paragraph layout data + the menu screenshot.

## Scope / CI
- Change is in `otf_emit_textfield`, gated `#if !NO_GRAPHICS || HEADLESS_GRAPHICS`, so
  it is **not compiled in NO_GRAPHICS** → no-graphics is byte-identical. The OFFSCREEN
  graphics-native CI exercises it.
- The Ruffle suites are **trace** tests; text-glyph rendering produces no trace output,
  so trace results are expected unchanged. Graphics CI validates the path doesn't crash
  and that no rendered-text test regresses.
- Browser-WASM is not CI-observable; the user-visible win is verified in headed Chrome.

## Decompile / repro
- AS: `java -jar ~/CC/jpexs/ffdec.jar -export script /tmp/ms_cell ~/CC/flasharchive/Minesweeper.swf`
  (board build = `scripts/frame_10/DoAction.as`; Restart = `scripts/DefineButton2_72/`).
- EditText flags: `ffdec -swf2xml … /tmp/ms.xml`, grep the chid-82 `DefineEditTextTag`
  (`wordWrap="false" multiline="true" html="true"`, five `<P>`).
