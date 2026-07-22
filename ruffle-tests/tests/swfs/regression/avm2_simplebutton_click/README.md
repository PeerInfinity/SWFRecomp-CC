# avm2_simplebutton_click

Gates AVM2 mouse hit-testing / `click` dispatch to a **nested SimpleButton**.

A `flash.display.SimpleButton`'s visual and hit-test state children live in the
runtime's `btn_up`/`btn_hit` slots, **not** in the container `render_list` that
`mouse_pick`, `bounds_with_transform`, and the render walk iterate. So before the
fix `mouse_pick` computed the button's self-bounds as EMPTY and MISSED it: a
click over the button dispatched nothing, and any `addEventListener(CLICK)` on it
never fired.

`mouse_pick` (`avm2_display.c`) now hit-tests a SimpleButton via its
`hitTestState` (falling back to the up state), inverse-mapping the stage point
into the state's local space, and returns the **button** as the pick target
(mirroring Ruffle `avm2_button.rs::mouse_pick_avm2` — a button's states are never
interactive and never receive the event). A down+up on the same target then
dispatches `"click"`, which bubbles to the button's own listener.

The button is nested one level deep (`root -> container -> button`) so the test
proves the pick descends a container into the button and the click bubbles back
up. `input.json` clicks the button centre (stage px 160,125 = container (100,100)
+ hit-rect centre (60,25)).

This is the exact gap that blocked **Elephant Quest**'s frame1 preloader Play
button (`SimpleButton 'playB'`, nested `root -> preloader -> playB`) from
advancing the boot on a click (EQ-2; see
`SWFRecompDocs/plans/avm2-elephant-quest.md` gap #9). The fix unblocks every
AVM2 button-driven game, not just EQ.

Rebuild the SWF with `./build_swf.sh` (mxmlc). Expected `output.txt`:

```
ready
CLICK ok target=true
```
