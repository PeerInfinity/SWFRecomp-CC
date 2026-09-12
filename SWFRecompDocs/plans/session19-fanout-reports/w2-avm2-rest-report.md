# w2-avm2-rest report — G5 EdgeBounds, G7 ID3Info, G6 EditText scroll event

**Branched from master `f48c532bf`** (master has since advanced to `3cce6a1f7`; both newer
commits touch `actionmodern/action.c`, `input_events.c`, `swf_core.c` only — no textual
overlap with anything here, so the patches apply clean).

**New files: none.** Three patches, one per item, textually disjoint by file:

| patch | files |
|---|---|
| `w2-avm2-rest-1-edgebounds.patch` (G5) | `SWFRecomp/src/abc/abc_timeline.cpp`, `SWFModernRuntime/include/avm2/avm2_abc.h`, `SWFModernRuntime/src/avm2/avm2_display.c` |
| `w2-avm2-rest-2-id3info.patch` (G7) | `SWFModernRuntime/src/avm2/avm2_media.c` |
| `w2-avm2-rest-3-scrollevent.patch` (G6) | `SWFModernRuntime/src/avm2/avm2_text.c` |

They are independent and can land in any order or separately. **G5 is a recompiler change**:
everything below was measured with the worktree's own `SWFRecomp` build and `--recompile` on
first use of every copied test dir.

---

## 1. Verdicts — 3 GO, +3 effective, all three priced flips materialized

| item | test | before | after | mode |
|---|---|---|---|---|
| G5 | `avm2/displayobject_getrect` | output_mismatch (11/16 lines) | **pass** | no-graphics **and** graphics |
| G7 | `avm2/id3_info` | output_mismatch (0/8 lines) | **pass** | no-graphics **and** graphics |
| G6 | `avm2/edittext_scroll_event` | output_mismatch (7/37 lines) | **pass** | no-graphics **and** graphics |

No pass→fail and no pass→ruffle_matched anywhere in the families checked.

---

## 2. G5 — DefineShape4 `EdgeBounds` / DefineMorphShape2 `StartEdgeBounds`

**The wave-1 mechanism is confirmed exactly, including the morph half being load-bearing.**
Baseline survivors were lines 4, 6, 8, 10, 16 — every `getRect` line; line 6 is the
`MorphShape` and lines 10/16 are the aggregate that contains it, so a DefineShape4-only fix
would have scored 2 of 5 and no flip.

**Scope refinement (worth noting for the commit message): `swf.cpp` is NOT touched.**
The wave-1 note pointed at `swf.cpp:8623/8677/8687`, but that is the AVM1 tag walk; the AVM2
bounds come from the ABC scanner's own `defineChar`, which read only the first RECT. Keeping
the change inside `abc_timeline.cpp` means **AVM1 shape parsing, tessellation and every render
path are untouched** — the blast radius is one table and one `getRect` branch.

* `abc_timeline.cpp` — `defineChar` gains an `edge_kind` argument (0 none / 1 DefineShape4 /
  2 DefineMorphShape2, which must skip `EndBounds` first). It reads further into a by-value
  `ByteReader` the caller discards, so nothing else shifts. `CharInfo` gains `edge[4]` +
  `has_edge`, emitted as 5 trailing columns.
* `avm2_abc.h` — `Avm2CharInfo` gains trailing `exmin/exmax/eymin/eymax` + `has_edge`. Trailing
  by design: older positional initializers stop at `init_text` and the new fields zero out.
* `avm2_display.c` — `char_self_bounds` takes `no_strokes` and returns the edge box when the
  character has one. `has_edge == 0` (DefineShape1-3, DefineMorphShape1) falls back to the
  shape box, which is exactly what Ruffle's reader substitutes
  (`swf/src/read.rs:1487/1237`), so pre-v4 content is bit-identical to before.

`g_bounds_no_strokes` is set only by `do_get_bounds_mode(act, 1)`, i.e. AVM2 `getRect` alone
(`avm2_display.c:4214`) — verified, this is why the renderer cannot see the new branch.

**Checks run (all `--recompile`)**

| test | result | baseline |
|---|---|---|
| `avm2/displayobject_getrect` | **pass** | output_mismatch |
| `avm2/displayobject_getbounds_shape` `--mode=graphics --images` | pass, **image 3716 outliers / limit 3800** | pass, same 84-channel margin |
| `avm2/bounds_mode` | ruffle_matched | ruffle_matched (unchanged) |
| `avm2/displayobject_scrollrect`, `rectangle`, `movieclip_drawrect`, `shape_drawrect`, `graphics_round_rects` | pass ×5 | pass ×5 |
| `avm1/textfield_props_swf8`, `avm1/movieclip_getbounds` | pass ×2 | pass ×2 |
| `regression/avm2_morph`, `avm2_static_text`, `avm2_timeline_text`, `avm2_bitmapdata_draw_textfield`, `avm2_parent_child_render`, `avm2_graphics_runtime`, `avm2_timeline_stroke_gradient`, `avm1_parent_child_morph` | pass ×8 | pass ×8 |

**The sibling's curve-bounds margin is intact**: `displayobject_getbounds_shape` renders
3716 outliers against its 3800 limit, the exact number the brief quoted. Not eaten.

---

## 3. G7 — `flash.media.ID3Info` and the ID3v2 walk

Mechanism as diagnosed: `sound_get_id3` returned `null` unconditionally and no `ID3Info` class
existed. Added to `avm2_media.c`:

* `flash.media.ID3Info` — `public final dynamic class` with the seven `String` vars of Ruffle's
  `ID3Info.as`, backed by **dont-enum dynamic props pre-seeded to `null`** (reads exactly like
  an unassigned String slot, and a `for-in` over the object stays empty as with real traits).
* An ID3v2.2/2.3/2.4 frame walk (~230 LOC incl. comments): syncsafe vs plain frame sizes,
  extended-header skip, TALB/TPE1/TCON/TIT2/TRCK/TYER/TDRC + the first COMM (encoding, 3-byte
  language, terminated short description, then text), with latin-1 / UTF-8 / UTF-16
  (BOM and BE, surrogate pairs) → UTF-8 decoding. `track`/`year` go through a numeric filter
  because Ruffle's `tag.track()`/`tag.year()` are integers and a non-numeric frame yields
  `None`.
* Dispatch order mirrors `loader.rs:1511` exactly: open → progress → **id3** → complete, inside
  `media_poll_simulated`. The event fires **only when the bytes actually parsed as a tag**
  (Ruffle's `tag.is_ok()` gate); the `ID3Info` object is stored either way.

**GC**: no new root list. The `ID3Info` is parked on the `Sound` itself as the dont-enum
dynamic prop `_id3` — the same trick `AVTagData` already uses — so it is traced with its owner
and `sound_get_id3` just reads it back. The raw bytes kept on the ext
(`ext_data`/`ext_data_len`) point into the linked-in `DataFileEntry` payload, i.e. static
storage, never the GC heap.

**Checks run (all `--recompile`)**

| test | result | baseline |
|---|---|---|
| `avm2/id3_info` | **pass** (no-graphics + graphics) | output_mismatch |
| `avm2/sound_play`, `sound_embeddedprops`, `sound_rootless`, `sound_constructor_with_args` | pass ×4 | pass ×4 |
| `avm2/soundchannel_position`, `soundchannel_soundcomplete` | ruffle_matched ×2 | ruffle_matched ×2 |
| `avm2/sound_load_multiple` | output_mismatch | output_mismatch (unchanged; blocked by `loadCompressedDataFromByteArray`, a different mechanism) |
| `avm2/abstract_classes` | unaffected — `ID3Info` is a plain concrete class, not registered abstract | pass |

---

## 4. G6 — the `scroll` event, and a REFUTATION of its pricing

The wave-1 report priced G6 as "the weakest on the board" and said the flip hinged on
`et_maxscroll` over the embedded SpaceAB font. **That premise is wrong in both directions.**

* `et_maxscroll` was already **18** for this fixture (probed at HEAD) — comfortably over the
  `≥ 10` the wheel block needs. Font metrics were never the risk.
* The real blocker was a **one-line default bug nobody had named**:
  `Avm2EditTextExt::mouse_wheel_enabled` was never initialised, so it sat at 0 out of the
  zeroed ext and `avm2_text_mouse_wheel` bailed at its first guard — for **every** AVM2
  TextField in the corpus. Ruffle's `EditTextData::mouse_wheel_enabled` is
  `Cell::new(true)` (`edit_text.rs:347`). The wheel was reaching the field correctly the whole
  time (probed: `MPICK wheel = TextField 'instance1' me=1` for all six wheel events).

So the patch is two things:

1. `et_dispatch_scroll` — Ruffle `on_scroller`'s AVM2 arm (`edit_text.rs:2142`): a bare,
   non-bubbling, non-cancelable `"scroll"` dispatched **synchronously inside the setter, only
   when the clamped value actually moved**. Wired into `txt_set_scroll_v` (which now early-
   returns on a no-op write) and `avm2_text_mouse_wheel`. `set_hscroll` deliberately gets no
   hook — Ruffle has none either.
2. `et->mouse_wheel_enabled = 1` at ext init.

**Staging**: with only (1), the test went 7/37 → 19/37 matching lines — the entire scripted
half correct, the six wheel blocks still missing. Adding (2) took it to 37/37.

**Sibling note**: `avm2_text.c` was clean of w2-gfx-text's at-point probes when I branched and
still is at master `3cce6a1f7`. My hunks are in `txt_set_scroll_v` (~L8260), the ext init
(~L2325) and `avm2_text_mouse_wheel` (~L10430) — none near the at-point methods.

**Checks run (all `--recompile`)**

| test | result | baseline |
|---|---|---|
| `avm2/edittext_scroll_event` | **pass** (no-graphics + graphics) | output_mismatch |
| `avm2/mouse_wheel_events` | pass | pass |
| `avm2/edittext_autosize_lazy_bounds_props` (traces `mouseWheelEnabled`) | pass | pass |
| `avm2/edittext_scrollh`, `edittext_max_scroll_v_basic`, `edittext_bottom_scroll_v_basic`, `edittext_max_scroll_h_basic`, `edittext_getcharboundaries_scroll` | pass ×5 | pass ×5 |
| `visual/cache_as_bitmap/edittext_scroll` `--mode=graphics --images` (the only other wheel-input test in the corpus) | trace pass; images **566 / 570 outliers** | trace pass; images **566 / 570** — byte-identical, no pixel movement |

The `visual` row is the honest audit of the `mouseWheelEnabled` default flip: it is the one
other corpus test that feeds `MouseWheel` to a text field, and its render did not move at all.

---

## 5. Render canary — NOT run, with the argument for why

The standing 132-member canary needs a BEFORE and an AFTER graphics capture; on this box that
is multi-hour and the machine is shared with seven siblings. Instead:

* **G5 is renderer-neutral by construction** — the recompiler hunk only reads extra bytes from
  a discarded cursor and adds table columns nothing else reads; the runtime hunk is behind
  `g_bounds_no_strokes`, which `do_get_bounds_mode(act, 1)` (AVM2 `getRect`) is the sole
  writer of. No render path calls `char_self_bounds` in that mode.
* **G7 touches `avm2_media.c` only** — no geometry, no draw.
* **G6's render-visible half** (`mouseWheelEnabled`) was checked directly against the one
  corpus test that exercises it, at the pixel level, and moved nothing.
* Three image-bearing tests were run for real in `--mode=graphics --images`:
  `avm2/displayobject_getbounds_shape` (3716/3800, margin unchanged) and
  `visual/cache_as_bitmap/edittext_scroll` (566/570, identical to the s18 baseline).

**Recommendation**: land with `mode=graphics`, `categories=full` (G5 is recompiler emission),
`images=false`. If the coordinator wants a canary, it is an A/B over the combined patch and
belongs to whoever runs the merge, not to this slice.

---

## 6. Risks

1. **G5 header/table lockstep.** `Avm2CharInfo` and the emitter must land together — a runtime
   built against the new header with an old generated table is fine (trailing fields zero,
   `has_edge == 0`, old behaviour), but the reverse is not. Both halves are in patch 1; do not
   split it.
2. **G6 reentrancy.** `avm2_text_mouse_wheel` now runs a user handler mid-input-pump when a
   `scroll` listener exists. Ruffle does the same (synchronous dispatch from `set_scroll`), and
   the setter path already ran handlers via the property setter, but it is a new edge for the
   wheel.
3. **`mouseWheelEnabled` default is corpus-wide.** Every AVM2 TextField now honours the wheel.
   Audited: only two corpus tests feed `MouseWheel` to an AVM2 field
   (`avm2/edittext_scroll_event`, `visual/cache_as_bitmap/edittext_scroll`), plus
   `avm2/mouse_wheel_events` which sets the flag explicitly. All three checked.
4. **G7 unsynchronisation.** The ID3 header's unsync flag (bit 7) is parsed but not undone; no
   corpus asset uses it, and the walk degrades to "no frames found" rather than misreading.
5. **G7 `_id3` name collision.** A script could set a dynamic `_id3` on a `Sound` and see it
   through `id3`. `AVTagData` already accepts the same class of collision for `_data`.

---

## 7. New unclaimed leads

* **`avm2/sound_load_multiple`** (output_mismatch, unchanged) is now blocked by exactly one
  thing: `Sound.loadCompressedDataFromByteArray` does not exist. The expected output is mostly
  `Error #2037` rows, so this is a "throw the right error from a stub" shape, not a decoder.
  Smaller than it looks.
* **`avm2/bounds_mode`** stays `ruffle_matched` after G5 — worth a look now that the
  stroke-exclusive box is real, since that was the reason its diff was accepted as Ruffle's.
* **`visual/cache_as_bitmap/edittext_scroll`** fails its images at 566/570 outliers over a
  70×20 canvas with `with_default_font = true`. The test's own upstream comment says it
  should not depend on the default font. Device-font raster, not scrolling — the wheel half is
  now correct.
* **`et_maxscroll` is not the fragile thing it was assumed to be** for embedded fonts: it
  returned 18 for a 21-line SpaceAB field in a 100px box, first try. Future text-metric pricing
  should not treat it as a risk without probing it.
