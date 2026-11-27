# w1-rm-avm1-gnash local oracle results (s29 coordinator, 2026-11-26, FP32 LNX direct pinned)

| request | result |
|---|---|
| 1. `avm1_mc_super_native_probe` (SWF8) | `super_native_probe.fp32.txt`. Lines 6+ (`H` _width/_height after negative scales, `B` blendMode) == **prototype**. Lines 1–5 (`S`) match NEITHER leg: Flash runs `super(...)` from a plain function called on a MovieClip for real — `U(7)` gives `u=7`; Boolean: `tsB`/`voB` = the value; Number: `tsN`/`voN` = 5; `tsS`/`tsN` undefined where the wrong-type native is called; `voS` = the clip path (`_level0.m1`). ⇒ lead 1 (a general MovieClip super context) is the real rule; P5 as prototyped is wrong. |
| 2. `loadBitmap` transparency | not built (needs bitmap tags) — not run. |
| 3. `matrix_probe/` (MTASC SWF8; `_rotation` 30/45/90/−90/180, then `_yscale=-100`) | `matrix_probe/flash.txt`: matrix entries are **16.16 fixed point** (`cos 30° = 0.86602783203125`, `cos 45° = 0.707107543945313`); 90/−90/180 exact integers; `_yscale=-100` → `d=-1`. |
