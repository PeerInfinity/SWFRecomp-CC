# Tetris board renders: `shape_array` undefined was an `actionNewObject` stack-balance bug

**Date:** 2026-06-14 (cont. 30)
**Status:** ✅ **FIXED** — blocker #4 from cont. 29. The Tetris board's falling
piece + next-piece preview now render on the SWFRecomp browser-WASM side (the play
area was previously blank). Verified with `tools/divergence/game_drive/tetris_compare.py`.
**Bucket:** **shared runtime** (`actionNewObject` compiles into trace / NO_GRAPHICS /
OFFSCREEN as well as browser-WASM) → ran CI both modes as a no-regression check.

---

## The bug

`actionNewObject` (`SWFModernRuntime/src/actionmodern/action.c`) popped constructor
args into a fixed `ActionVar args[16]` and, when `num_args > 16`, **clamped
`num_args = 16` and only popped 16 operands**:

```c
ActionVar args[16];
if (num_args > 16) num_args = 16;          // <-- clamp
for (u32 i = 0; i < num_args; i++) popVar(app_context, &args[i]);
```

The clamp left the extra operands on the stack. Tetris's `drawShape` table is built
once in `script_7` (the game-start frame DoAction) as a **112-element**
`new Array(13,9,5,1, … 112 ints)` followed by `SetVariable shape_array`. The bytecode
pushes the *name* `str_66` ("shape_array") **first** (bottom of stack), then the 112
element values, then the count `112`, then `"Array"`, then `NewObject`, then
`SetVariable`. With the clamp, `NewObject` consumed only `"Array"` + count + **16** of
the 112 values, leaving **96 element values + the name `str_66` stranded** below the
array result. The subsequent `SetVariable` then popped `(value=array, name=<a leftover
number>)` → it bound a numeric-named var and **`shape_array` was never set**.

Downstream: `GetVariable("shape_array")` → undefined → `blockPos = shape_array[…]`
undefined → `block_array[i] = NaN` → `b_mc[NaN].gotoAndStop(color+1)` hit an undefined
receiver → no colour. (`PMDIAG GVUNDEF name=shape_array` fired 12× in cont. 29.)

**Why `block_array` resolved but `shape_array` didn't:** `block_array` is built the
exact same way (`new Array(0,0,0,0)` + `SetVariable`) but with **4** elements — under
the 16-arg clamp, so its stack stayed balanced.

## The fix

Always pop **all** `num_args` operands to keep the operand stack balanced for the
following opcode. Only the `new Array(e1,…,eN)` element-list path actually *consumes*
more than 16 args; every other constructor reads `args[0..few]`. So:

- Spill to a heap buffer (`malloc(sizeof(ActionVar) * num_args)`) when `num_args > 16`,
  pop all args into it, and **use + free it in the Array element path**.
- For non-Array constructors, copy the first 16 into the fixed buffer, `free` the heap
  buffer, and set `num_args = 16` (their pre-existing ≤16-arg behavior is unchanged).
- If `malloc` fails, fall back to the old clamp (pop 16) — degraded but safe.

Elements are struct-copied into `arr->elements` (string/object payloads are pointers
that stay valid), so freeing the heap arg buffer afterwards is safe.

`action.c` only; no recompiler change (the bytecode was always correct — the runtime
mis-consumed it).

## Verification

```
PMDIAG NEWARR len=112 elem0type=6 elem111type=6   # array builds fully (F64 elems)
GVUNDEF name=shape_array : 0                       # was 12× in cont. 29
```

`tetris_compare.py` → `compare_out/swfrecomp_ok.png`: the falling piece (blue L) +
next-piece preview (red block) + "tetris" vector title now render where the play area
was blank. In the "ok" state the board is freshly empty (matching Ruffle, which also
shows only a falling piece), so an otherwise-empty grid is correct.

## Follow-ups (lower priority)

- **Scale-normalized parity capture.** The SWFRecomp canvas renders at ~2× Ruffle's
  size (`box 781x777` vs `382x380`), so `swfrecomp_ok.png` only shows the top-left
  quadrant — the level/lines/score labels, quit/pause buttons, and bottom "tetris"
  logo fall off the crop. Need a scale-matched capture to confirm those render before
  declaring full visual parity.
- Deprioritized: dynamic-textfield digit italic slant.
- **Re-check DJ/Snake/Pong manually** for cont. 29 fix #3 (browser-WASM MC
  `gotoAndStop` → `ng_gotoFrameByMC`) — not CI-observable.

## Process notes (cost time this session — heed)

- The handoff's `pkill -9 -f browser-test-venv` / `pkill -f chrome` **self-match the
  launching shell** (the command line literally contains those strings), killing the
  command before it runs (exit 1, no output, stale `pmdiag.log` left behind). Run
  cleanup in a **separate** bash call from the harness launch, and use the bracket
  trick (`pkill -f 'chrom[e]'`, `pkill -f 'tetris_compar[e]'`) or name-based
  `pkill chrome` so the pattern doesn't match its own argv.
- The harness needs Chrome + WebGPU + network (Ruffle CDN) + DISPLAY → run it with the
  Bash sandbox disabled.
