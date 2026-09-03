# avm2_parent_child_symbol_stride

Lock on the **unified child character-id stride**: a loaded child movie's
character ids are re-based by `char_id_base = movie_id * CHILD_CHAR_ID_STRIDE`,
and every reader of them — on both sides of the AVM1/AVM2 line — has to agree
on that one number.

## Why it exists

Until `SWFRecompDocs/status/child-charid-stride-unify.md` there were **two**
strides for the same child. `verify_output.py` handed the recompiler
`char_id_base = movie_id * 10000`, which reached only the ABC/AVM2 emissions
(the SymbolClass registry and the AVM2 timeline tables); the tag side of the
same child was then re-based by the harness at `movie_id * 1000`. An AS3
child's SymbolClass binding named character 10001 while its `tagDefineSprite`
defined 1001. Latent, because AVM2 never reads the AVM1 dictionary — but the
unification moves every AVM2 child id (10001 → 1001), and that is what this
test guards.

## The shape

    test.swf   AVM2 (mxmlc, Test.as)    Loader.load("child.swf")
    child.swf  AVM2 (mxmlc, Child.as + Second.as), 3 frames, one embedded PNG

| row | reads |
|---|---|
| `child:tf3` | the child root's `declared_frames`, out of `child_avm2_generated_timelines` keyed by character id. The row is emitted at `char_id_base + 0`; the root is instantiated under `tables->char_id_base`. The "no timeline row" fallback is `1`, so `3` can only come from a hit. |
| `child:…:Child_Pix` | the child's embedded PNG gives it a SECOND, non-zero character with its own SymbolClass row, so `char_id_base + 0` is not the only id in the movie. |
| `root:Child` | `loader_boot_child_swf` finds the child's root class by matching a SymbolClass row's `char_id` against `tables->char_id_base`. A miss falls through to the "binding names no character ⇒ it is the root class" arm and the content comes up a bare `MovieClip`. |

**Both rows are locks, not repros.** They pass on the pre-unification baseline
too: the two strides disagreed but nothing read across them, so no
trace-visible repro of the disagreement exists (see the closeout doc, §"No
repro exists").

## Positive control

They do discriminate. Emitting the tables aggregate's `char_id_base` as
`info.char_id_base + 1` (`SWFRecomp/src/abc/abc_timeline.cpp`) — a one-off
desync between the base and the SymbolClass rows built from it — makes both
rows fail loudly:

```
-  child:tf3:Child_Pix
+  TypeError: Error #2023: Class Child_Pix$ must inherit from Sprite to link to the root.
-  root:Child
+  root:flash.display::MovieClip
```

## Known gap this test does NOT read

`new Pix()` yields a `Child_Pix` whose `width`/`height` are **0**, where the
same SWF run as the MAIN movie reports `4x3`. `embedded_bitmap_for_char`
(`SWFModernRuntime/src/avm2/avm2_bitmap.c`) scans only the main movie's
`avm2_generated_bitmaps` and never consults `g_child_movies`, unlike its
neighbours `char_info` and `timeline_for_char`. Independent of the stride —
it reproduces at either one — and left for the child-bitmap slice, so this
test deliberately reads the class name and not the pixels.

## Rebuild

```bash
./build_swf.sh
```
