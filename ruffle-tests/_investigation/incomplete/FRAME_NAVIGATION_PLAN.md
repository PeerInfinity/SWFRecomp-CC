# Frame Navigation Implementation Plan
<!-- TESTS: goto_frame, goto_frame2, goto_label, goto_methods -->

Last updated: 2026-02-25

## Status: COMPLETE (4/4 tests PASS)

All 4 frame navigation tests now pass:

| Test | Status | Lines |
|------|--------|-------|
| goto_frame | PASS | 12/12 |
| goto_frame2 | PASS | 44/44 |
| goto_label | PASS | 13/13 |
| goto_methods | PASS | 20/20 |

## Changes Made

### Runtime (SWFModernRuntime/)

**action.c — `actionGotoFrame2` rewrite:**
- Non-integer numeric values (e.g. 4.123) treated as no-op (fract != 0)
- NaN/Infinity checks before casting (prevents UB)
- Wrapping arithmetic matching Ruffle: `frame_0based = frame_num - 1`, `+= scene_bias`, `frame_final = frame_0based + 1`, check `frame_final <= 0` for no-op
- Frame label lookup for string values via `findFrameByLabel()`
- Boolean/undefined/null: coerced to strings ("true"/"false"/"undefined"/"null") for label lookup (not numeric coercion). SWF version affects undefined/null string form.
- `(s32)(s64)frame_double` for wrapping i32 cast from f64

**action.c — `actionGotoFrame` was_clamped fix:**
- Decrements `g_deferred_goto_queue_count` when frame was clamped (suppresses target script)

**action.c — FRAME_WIDTH/FRAME_HEIGHT guards:**
- Added `#ifdef` guards for Stage width/height properties that reference compile-time constants

**swf_core.c — `_currentframe` sync:**
- Natural frame advance (`current_frame++`) now updates `root_movieclip.currentframe`
- Manual frame advance also updates `root_movieclip.currentframe`

**swf_core.c — Deferred script queue:**
- Replaced single `g_deferred_goto_script`/`g_deferred_goto_target` with a queue (`g_deferred_goto_queue[16]`)
- Multiple gotos in the same script each queue their deferred script
- Deferred scripts execute in order after the calling script finishes

### Recompiler (SWFRecomp/)

**action.cpp — Scene bias fix:**
- Fixed unaligned u16 read in GotoFrame2 scene_bias parsing: `VAL(u16, action_buffer + 1)` → byte-by-byte read
- The `VAL` macro does `*((u16*)x)` which is UB for unaligned pointers

**swf.cpp — Frame labels (already working):**
- FrameLabel tags were already being parsed and emitted; the issue was that old pre-compiled test outputs had `frame_label_count = 0`. Re-running the recompiler (`--recompile`) fixed this.
