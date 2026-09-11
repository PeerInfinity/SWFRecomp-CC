# avm2_child_simplebutton

A `DefineButton2` defined by a **loaded AS3 child** must produce a real
`SimpleButton`: `upState` / `overState` / `downState` / `hitTestState` all
resolved, and the button measuring its up state's bounds.

`class_for_char` already answered `flash.display::SimpleButton` for a child's
button character (its `chars` row falls through to `g_child_movies`), so the
object existed — but `button_data_for_char` scanned `avm2_generated_buttons`
only, i.e. the MAIN movie's table. `button_create_state` therefore got
`bd == NULL`, returned NULL for all four states, and the button measured 0x0.
The fix is the same `g_child_movies` fall-through that `char_info`,
`timeline_for_char`, `class_for_char`, `statictext_for`, `shape_geom_for_in`
and `avm2_display_char_is_defined` already carry.

Diagnosed in `SWFRecompDocs/plans/session19-fanout-reports/w1-loaders-report.md`
§2. No corpus test grades it: the only child SWF in the whole corpus with a
`DefineButton2` is `from_shumway/as3-loader/LoaderTest2/Loadee2.swf`, which
traces nothing about buttons (the only other hit,
`avm2/mouse_pick_loader_avm1/avm1.swf`, is an AVM1 child — a different code
path). Hence this fixture.

## The shape

    test.swf   AVM2 (mxmlc, Test.as)  — Loader.load("child.swf"), default
               LoaderContext; on COMPLETE it prints each of the four states
    child.swf  AVM2 (mxmlc, Child.as), then tag-injected:
               DefineShape 1     20x20 red
               DefineShape 2     40x40 blue
               DefineButton2 3   up = shape 1
                                 over = shapes 1 + 2   (the MULTI-record arm,
                                                        which wraps in an auto
                                                        Sprite-classed clip)
                                 down = shape 2
                                 hit = shape 1
               root frame 1 places character 3

`over` is deliberately two records: it is the only row that exercises the
multi-record wrapper (`flash.display::Sprite ... kids=2`), and the single-record
rows (`up`/`down`/`hit`) pin that a lone record IS the symbol, not a wrapper.

| row | pre-fix |
|---|---|
| `child0:flash.display::SimpleButton` | already correct (`class_for_char`) |
| `up:` / `over:` / `down:` / `hit:` | `null` on all four |
| `button w=20 h=20` | `button w=0 h=0` |

## Oracle

`output.txt` is the local Ruffle exporter's trace, byte for byte — never our own
output. Recipe (memory `mcl_load_timing`): both SWFs under
`<dir>/armorgames.com/`, then

    RUFFLE_LOCAL_FETCH_DIR=<dir> RUFFLE_MOVIE_URL=https://armorgames.com/test.swf \
      ~/CC/ruffle/target/release/exporter test.swf out -s -f 6 --trace-log ruffle.txt

A plain `file://` movie URL silently never loads the child.

## Rebuild

    python3 create_test_swf.py     # needs ~/CC/flex-sdk/bin/mxmlc
