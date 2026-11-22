# w2-attach-order-v8: attach-tick tag order + MovieClip-v8 (s24 wave 2, IMPLEMENTATION)

Cloud worker, branch `fanout/w2-attach-order-v8`. Sweeps + canary measured on base `c633d88f`; master then moved
(incl. n-perf-ab `10b5dff6` in `tag.c`), so the patch was **rebased onto `7ae8cc54`** (applied cleanly, 3-way) and the
14 key rows re-run there in both modes (§3, "rebased re-check"). Categories downloaded:
`avm1 from_gnash` (+ `from_shumway` for the canary), upstream Ruffle master at download time (`download_tests.sh`
does not print the SHA; same day as the s24 baseline `bcac30c19`). Box: `SETUP_STATUS` all OK (apt, Pillow, Dawn).

**NEW files:**
- `ruffle-tests/tests/swfs/regression/avm1_attached_clip_tagorder/{create_test_swf.py,test.swf,test.toml,output.txt}`
- `ruffle-tests/tests/swfs/regression/avm1_attached_clip_tagorder_nonroot/{create_test_swf.py,test.swf,test.toml,output.txt}`
- `ruffle-tests/tests/swfs/regression/avm1_array_native_own_method/{create_test_swf.py,test.swf,test.toml,output.txt}`
- `SWFRecompDocs/plans/session24-fanout-reports/w2-attach-order-v8-report.md` (this file)
- `SWFRecompDocs/plans/session24-fanout-reports/w2-attach-order-v8.patch`

**Modified:** `SWFModernRuntime/src/actionmodern/action.c`, `SWFModernRuntime/src/libswf/tag.c`,
`SWFModernRuntime/src/libswf/tag_stubs.c`, `ruffle-tests/tests/swfs/regression/README.md` (3 new rows + caveat),
`regression/avm1_attached_clip_natural_timeline{,_nonroot}/create_test_swf.py` (docstring caveat only; SWF bytes
unchanged).

## Verdict: GO — landable, ledger measured exactly

| | before (clean `c633d88f`) | after (patch) |
|---|---|---|
| graphics, 111-row A/B sweep | 94 pass / 10 rm / 7 mismatch | 97 pass / 11 rm / 3 mismatch |
| rows that moved | — | **exactly the 4 ledger rows; 107/111 byte-identical** (status, line counts, diff text) |

## EXPECTED-FLIP LEDGER (coordinator: check CI against this)

**Trace axis** (both `graphics` and `no-graphics`):

| test | before | after |
|---|---|---|
| `from_gnash/actionscript.all/MovieClip-v8` (known_failure) | output_mismatch (42 lines differ) | **ruffle_matched** (`diffs 25 ⊆ ruffle 68`) — a GAIN (not pass→rm) |
| `regression/avm1_attached_clip_tagorder` (NEW) | (output_mismatch, 4 lines) | **pass** |
| `regression/avm1_attached_clip_tagorder_nonroot` (NEW) | (output_mismatch, 4 lines) | **pass** |
| `regression/avm1_array_native_own_method` (NEW) | (output_mismatch, 2 lines) | **pass** |

Everything else: **0 moves**. **Pixel axis: 0 moves** (see canary below; `images=false` per-change anyway).
The ledger above adds one fixture to the brief's ledger (`avm1_array_native_own_method`, which the brief's item 2 asked
for).

## Patch scope (what changed vs the w1 prototype)

1. **All four `getenv` gates dropped** (`SWFR_NO_ATTACH_TAGORDER`, `SWFR_NO_MCV8`, `SWFR_NO_PIXB`, `SWFR_NO_ARRNAT`),
   logic kept verbatim, prototype comments rewritten as normal comments. `action.c` hunks = the w1 §3.4 list (4 stroke
   sites `h *= 0.5f` for SWF ≥ 8, blendMode f64→wrapping-u8, `createTransformObject` order + DONTENUM `__mc__`,
   GetMember `transform` → undefined when `flash.geom.Transform` is gone, `transformPixelBoundsGetter` via
   `getBounds` + dynamic children, array own-method arm publishes `g_current_executing_func`).
2. **Attach tag order, refactored into `ng_script_only_place()`** (`tag.c`, static, placed immediately before
   `tagPlaceObject2`; CI modes only). `tagPlaceObject2`'s script-only return calls it. Two hardenings over the
   prototype: `char_id < dictionary_capacity` bound check, and `g_attach_tagorder_parent` is cleared to NULL around
   the child's own init (a nested script-only replay inside the child walks the CHILD's display list and must not
   resolve grandchildren against the attached clip; grandchildren keep the old after-the-frame order).
3. **NEW: `tagPlaceObject2Ratio` script-only guard** (item 3, see §1). `tag_stubs.c`: the global
   `g_attach_tagorder_parent` set/restored around `pai->func`.

Sibling note: the `tag.c` edits are the helper (before `tagPlaceObject2`), `tagPlaceObject2`'s script-only return,
and the first lines of `tagPlaceObject2Ratio` — none touch `ng_advance_attached_clip_playheads` (n-perf-ab's area).
No `SIBLING_FILE_MAP.md` existed at start. Patch regenerated against `origin/master` at delivery time (see bottom).

## 1. Item 3: `tagPlaceObject2Ratio` / `tagPlaceObject3` in the attach-init replay — FIXED (Ratio), PROVEN SAFE (PO3)

- **`tagPlaceObject3`** and `tagPlaceObject2WithClipActions` delegate to `tagPlaceObject2`, so they inherit its
  script-only return and the new tag-order init. PO3 then writes `blend_mode` from the tag, the same value Phase 1
  wrote — harmless. **Measured**: a PO3 variant of the fixture (every `place()` emitted as tag 70) PASSES the
  same oracle text, root and non-root, graphics. Probe not landed (no Ruffle oracle for that SWF; it would be the
  same text by construction, see LOCAL ORACLE REQUESTS #2).
- **`tagPlaceObject2Ratio` had NO script-only guard at all** — a pre-existing bug, not a double init: in a script-only
  replay (attach init AND `process_sprite_init_at_depth`'s sni==2 Phase 2) it ran a full placement again. Since
  `tagSetInstanceName` is a script-only no-op, the re-placed child lost its name (`instance3 anim f2`) and its frame-1
  init was reset and never ran. Measured on a Ratio variant of the fixture (`place()` with flag 0x10, ratio 0):
  clean master and prototype alike printed `s stopper f1 / m multi f1 / instance3 anim f2 …` (every line from 1 on
  wrong). Fix: the same `if (g_script_only_mode) { ng_script_only_place(...); return; }` at the top of Ratio's CI arm.
  After: lines 1–15 (the whole attach tick and the first loop) match the oracle text.
- **Exposure is tiny and measured**: a SWF tag scan of every `avm1`/`from_gnash`/`regression` `*.swf` finds only 6
  SWFs with a Ratio-flagged PlaceObject2 of a sprite inside a DefineSprite (`movieclip_invalid_get_bounds_6/7`,
  `netstream_play_flv_screen`, `target_clip_removed`, `execution_order4`, `action_execution_order_extend_test`). All
  6 are byte-identical before/after (in the 111-row sweep), and also identical between a guard limited to the
  attach replay and the general guard (temporary A/B switch, removed) — so the general guard was kept (it is the
  documented Phase-2 contract).
- Residual, NOT fixed (lead L4): the Ratio variant still differs from line 16 on — on each wrap of the attached
  `multi` back to frame 1 we print `kid3 anim f1` twice. Identical with the guard limited to the attach replay, so it
  is the attached-clip natural-timeline wrap path with a Ratio child (pump territory, `ng_advance_attached_clip_playheads`
  / wrap re-place), not the replay. No corpus row (scan above) and no oracle for that SWF.

## 2. Item 4 / lead L1: other own-method native-invoke arms — NO further fix (different mechanism)

- Only one native reads `g_current_executing_func` to name itself: `builtin_array_method` (`action.c` ~69411; grep
  of `g_current_executing_func->`). So L1 reduces to "an `Array.prototype` native installed as an own method of a
  non-array receiver".
- Probe (16 lines; receivers Object, Function, `new String("xy")`, MovieClip; each given `0:'a', 1:'b', length:2`,
  `join`/`push` = `Array.prototype.join/push`; each own call paired with a `Array.prototype.join.call(recv,'-')`
  control):

  | receiver | own `join('-')` | `.call` control | own `push('c')` |
  |---|---|---|---|
  | Object | `a-b` | `a-b` | `3` |
  | Function | undefined | undefined | undefined |
  | String object | undefined | undefined | undefined |
  | MovieClip | undefined | undefined | undefined |

  The Object arm already publishes the callee (`action.c` ~72049). The other three fail **identically through
  `.call`**, so the missing piece is `builtin_array_method`'s generic path (it only handles an `ASObject` receiver),
  not the per-arm one-liner. Per the brief: not fixed, no fixture rows added; Flash output for them is a LOCAL
  ORACLE REQUEST (#3).

## 3. Per-test before/after (same box, clean `c633d88f` vs patch)

Headline + fixtures, both modes:

| test | graphics before | graphics after | no-graphics before | no-graphics after |
|---|---|---|---|---|
| `from_gnash/actionscript.all/MovieClip-v8` | output_mismatch (1045/1087) | **ruffle_matched** (1062/1087, 25 ⊆ 68) | output_mismatch (1045/1087) | **ruffle_matched** (25 ⊆ 68) |
| `regression/avm1_attached_clip_tagorder` | mismatch (30/34) | **pass** | mismatch (30/34) | **pass** |
| `regression/avm1_attached_clip_tagorder_nonroot` | mismatch (30/34) | **pass** | mismatch (30/34) | **pass** |
| `regression/avm1_array_native_own_method` | mismatch (6/8) | **pass** | mismatch (6/8) | **pass** |
| `from_gnash/actionscript.all/MovieClip-v5/6/7` | ruffle_matched | ruffle_matched (identical) | ruffle_matched | ruffle_matched (identical) |
| `regression/avm1_attached_clip_natural_timeline{,_nonroot}`, `_goto_play{,_nonroot}`, `avm1_attach_clipevent_enterframe` | pass | pass (identical) | pass | pass (identical) |

**No-graphics A/B, 35 rows** (headline, MovieClip-v5/6/7, the 3 fixtures, all 27 attach/child-timeline/onunload/
array regression rows, the 6 Ratio-scan rows, `attach_movie_export_not_yet_run`, `avm1/transform`,
`movieclip_blend_mode_property`): **31/35 byte-identical, the 4 movers = the ledger**. **Mode parity: all 35 rows have
identical status, line counts and detail in graphics and no-graphics after the patch.**

**Rebased re-check on `7ae8cc54`** (clean vs patch, `--recompile`, graphics AND no-graphics): `MovieClip-v8`,
`MovieClip-v7`, the 3 new fixtures, `avm1_attached_clip_natural_timeline{,_nonroot}`, `_goto_play{,_nonroot}`,
`avm1_attach_clipevent_enterframe`, `execution_order4`, `target_clip_removed`, `movieclip_invalid_get_bounds_6`,
`attach_movie_export_not_yet_run`: **10/14 byte-identical in each mode; the 4 movers = the ledger**, same line
counts as on `c633d88f`.

**Graphics A/B sweep, 111 rows** (= the w1 62-row attach set and 43-row MovieClip-v8 collateral set, rebuilt from
the w1 §1.4/§3.3 criteria by decompressed-body grep — it came out as 64 + 49 because the 3 new fixtures and a few
`regression/avm2_*` rows matching `transform` are included — plus the 6 Ratio-scan rows and the array fixture):
**107/111 byte-identical** (status, line counts, ruffle/ours diff counts, full diff text after stripping timings);
the 4 movers are the ledger. Unchanged non-pass rows: `globals_monkeypatch`, `movieclip_hittest_shapeflag`,
`action_execution_order_extend_test` (mismatch); `attach_movie_export_not_yet_run`, `movieclip_library_state_values`,
`BitmapData-v8`, `MovieClip-v5/6/7`, `Transform-v8`, `matrix_test`, `registerClassTest2`, `registerclass_test3`
(ruffle_matched). Lists: `/tmp` only (criteria above reproduce them).

**Regression suite near the change**: every `regression/avm1_attach*`, `avm1_child_timeline_*`,
`avm1_parent_child_*`, `onunload_type1_*`, `array_method_type1_args` row (27) is in the sweep, all identical except
the 3 new fixtures.

## 4. Graphics canary

`render_canary.py capture/compare`, `--jobs 2 --timeout 5400`, clean vs patch. The standing list has 103 members;
all categories it names were downloaded (`avm1 from_gnash from_shumway avm2 visual fonts text`; `regression` is in
git) and captured in two halves (33 AVM1/regression/shumway members, 69 AVM2/visual/fonts/text members — 102 tests,
one listed twice). **IDENTICAL 68/68 + 92/92 PNGs, DIFFERS 0, APPEARED/VANISHED 0, no trace or image status
changes.** No covering member appended: the change class is script order (attach tick) and `_width`/`getBounds`/
`pixelBounds` reads, not a render path; the trace fixtures grade it.

## Refutations / attacks on the brief

- **"Item 3 = possible double init"** — refuted as stated: PO3 cannot double-init (it delegates); Ratio never
  double-inited, it RE-PLACED (lost the instance name, reset the timeline) in every script-only replay. Fixed.
- **"L1: same missing `g_current_executing_func` on the other arms"** — refuted: only `builtin_array_method` consumes
  it, the Object arm already sets it, and the Function/String/MovieClip receivers fail through `.call` too.
- Ledger pricing re-checked: MovieClip-v8 is `known_failure = true`, mismatch → rm is a gain (rule 3); every fixed
  line moves to `output.fp23.txt`'s text (w1 §3.2).

## Not finished / HOLDs (each with completion mechanism)

- **Browser-WASM live attach arm** (w1 §1.5): HOLD, unchanged. Mechanism: run the child's frame-0 build at its
  PlaceObject inside the live `funcs[0]` run (`tag_stubs.c` `#if !NO_GRAPHICS && !OFFSCREEN_RENDER` arm); verify with
  the s24 browser probe harness. The new fixtures grade CI modes only.
- **L4 (new)**: attached clip wrap with a Ratio-placed child double-runs the child's frame 1 (§1). Mechanism: get the
  Ruffle oracle for the Ratio variant (request #1), then trace the wrap re-place in the attached-clip pump; coordinate
  with n-perf-ab (same function).

## New unclaimed leads

- **L4** — above.
- **L5** — `builtin_array_method` generic receivers (Function, String object, MovieClip): `Array.prototype.join.call(f,
  '-')` returns undefined. Needs the oracle (#3) before sizing; no corpus row measured.
- **L2** (from w1, unchanged) — `getBounds` engine folds only a dynamic child's own drawing, not grandchildren;
  `pixelBounds` is patched locally.

## LOCAL ORACLE REQUESTS

1. Ruffle exporter `--frames 8` for the **Ratio variant** of the tagorder fixture: generate with
   `regression/avm1_attached_clip_tagorder/create_test_swf.py` after changing `place()` to
   `tag(26, bytes([0x02|0x10|0x20]) + struct.pack('<HHH', depth, cid, 0) + s(name))` (ratio 0). Expected: equal to
   `avm1_attached_clip_tagorder/output.txt`; if so it becomes a third fixture and L4 is a real bug.
2. (Optional) Same for a **PlaceObject3** variant (`tag(70, bytes([0x02|0x20, 0x00]) + struct.pack('<HH', depth, cid) + s(name))`)
   — we already print the oracle text for it; a match would let it land as a fixture.
3. Ruffle exporter `--frames 1` (and Flash if available) for the L1/L5 probe: generator text below, writes 16 trace
   lines (`obj/fn/str/mc own join`, `call join`, `own push`, `len`). It pins whether Array generics work on
   Function / String-object / MovieClip receivers.

<details><summary>L1 probe generator (make_l1.py)</summary>

```python
import struct,sys
def tag(code,data):
    return struct.pack('<H',(code<<6)|len(data))+data if len(data)<63 else struct.pack('<HI',(code<<6)|0x3f,len(data))+data
def s(x): return x.encode()+b'\0'
def push(*items):
    b=b''
    for it in items:
        if isinstance(it,str): b+=b'\x00'+s(it)
        elif isinstance(it,int): b+=b'\x07'+struct.pack('<i',it)
    return b'\x96'+struct.pack('<H',len(b))+b
GV=b'\x1c'; GM=b'\x4e'; SV=b'\x1d'; SM=b'\x4f'; TR=b'\x26'; CM=b'\x52'; NM=b'\x53'; IA=b'\x42'; IO=b'\x43'; ADD2=b'\x47'; POP=b'\x17'
def deffn(body): return b'\x9b'+struct.pack('<H',5)+b'\x00'+struct.pack('<H',0)+struct.pack('<H',len(body))+body
AP=lambda m: push('Array')+GV+push('prototype')+GM+push(m)+GM
code=b''
def setup(name, make):
    global code
    code+=push(name)+make+SV
    code+=push(name)+GV+push(0,'a')+SM
    code+=push(name)+GV+push(1,'b')+SM
    code+=push(name)+GV+push('length',2)+SM
    code+=push(name)+GV+push('join')+AP('join')+SM
    code+=push(name)+GV+push('push')+AP('push')+SM
recv={
 'obj': push(0)+IO,
 'fn': deffn(b''),
 'str': push('xy',1,'String')+NM,
}
# MovieClip receiver
code+=push('_root')+GV
code+=push(1,'mc',2)+push('_root')+GV+push('createEmptyMovieClip')+CM+POP
for k,v in recv.items(): setup(k,v)
# mc: set props via _root.mc
code+=push('mc')+GV+push(0,'a')+SM+push('mc')+GV+push(1,'b')+SM+push('mc')+GV+push('length',2)+SM
code+=push('mc')+GV+push('join')+AP('join')+SM+push('mc')+GV+push('push')+AP('push')+SM
for k in ['obj','fn','str','mc']:
    code+=push(k+' own join: ')+push('-',1,k)+GV+push('join')+CM+ADD2+TR
    code+=push(k+' call join: ')+push('-',k)+GV+push(2)+AP('join')+push('call')+CM+ADD2+TR
    code+=push(k+' own push: ')+push('c',1,k)+GV+push('push')+CM+ADD2+TR
    code+=push(k+' len: ')+push(k)+GV+push('length')+GM+ADD2+TR
body=tag(69,struct.pack('<I',0))+tag(9,b'\xff\xff\xff')+tag(12,code+b'\0')+tag(1,b'')+tag(0,b'')
nb=13; bits='{:05b}'.format(nb)+''.join('{:013b}'.format(v) for v in (0,4000,0,3000)); bits+='0'*((8-len(bits)%8)%8)
rect=int(bits,2).to_bytes(len(bits)//8,'big'); hdr=rect+struct.pack('<HH',30<<8,1)
open(sys.argv[1],'wb').write(b'FWS'+bytes([8])+struct.pack('<I',8+len(hdr)+len(body))+hdr+body)
```
</details>

## Patch proof

`w2-attach-order-v8.patch` = `git diff --binary origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py
ruffle-tests/render_canary_tests.txt ruffle-tests/tests/swfs/regression` against `origin/master` = **`7ae8cc54`**
(new fixture dirs included via `git add -N`; `--binary` carries the three `test.swf`). 18 files, +493/−13, 768 lines.
`git apply --check -R` on the delivered tree: **OK**. (`verify_output.py` / `render_canary_tests.txt` unchanged; no new
`.c`/`.h` files.)
