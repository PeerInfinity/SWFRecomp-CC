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

## The child's embedded ASSETS (added by the child-bitmap slice)

Three more rows, one per embedded-asset table, all reading a character the
CHILD movie defines:

| row | reads | pre-fix |
|---|---|---|
| `child:pix:4x3` | `[Embed]`ed PNG -> `BitmapData` subclass `width`/`height` | `0x0` |
| `child:blob:9` | `[Embed(mimeType="application/octet-stream")]` -> `ByteArray.length` | `0` |
| `child:snd:1044` | `[Embed]`ed MP3 -> `Sound.length` (ms) | `0` |

Each was a **two-layer** miss, not one (see
`SWFRecompDocs/status/child-embedded-asset-lookup.md`):

1. `g_symbol_map` (class -> char id) is built once at stage build from the MAIN
   movie's SymbolClass rows, so a child-defined asset class resolved to char
   **0** and never reached a payload table at all. The three sites now call
   `avm2_display_child_char_for_class`.
2. The payload tables (`avm2_generated_bitmaps` / `_binaries` / `_sounds`) were
   scanned in the main movie only, unlike `char_info` / `timeline_for_char`
   which already consult `g_child_movies`. All three now fall through.

Both layers are load-bearing: reverting either one alone puts `child:pix` back
to `0x0`.

**The control is the same SWF as the MAIN movie.** `child.swf` run directly as
`test.swf` reports `4x3` / `9` / `1044` — before and after the fix — so these
rows measure main-vs-child parity, not the absolute values. (`1044` in
particular is our own `Sound.length` computation, not an oracle number.)

## Rebuild

```bash
./build_swf.sh
```

`pixel.png` (4x3), `blob.bin` (9 bytes, ASCII) and `silence.mp3` are the
embedded assets; `silence.mp3` is a copy of `avm2/sound_valueof/silence.mp3`.
