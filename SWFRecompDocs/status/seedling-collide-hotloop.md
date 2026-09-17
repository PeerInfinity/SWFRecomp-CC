# Seedling's collide hot loop: the IC was hitting, and the hit was the cost (2026-09-16)

**Area:** `SWFModernRuntime/include/avm2/avm2_ops.h`, `src/avm2/avm2_ops.c`
(AVM2 runtime, every build). **Baseline:** `2aa6596d6` (runtime = the pins'
recompiler `bdf734c46`). **Landed:** `2973513c4`. **Brief:**
`SWFRecompDocs/prompts/avm2-seedling-collide-hotloop.md` (session
`swfrecomp-seedling-hotloop-1`, planner `seedling-headless-planning-5` in
Archipelago-CC). **Backlog entry:** `BACKLOG.md` § "AVM2 — performance", first
entry. **Evidence:** `tools/divergence/perf/seedling_hotloop_2026-09-16/`.
**CI:** §6.

## 1. The frame, and proof that it is the same frame

Seedling's first `Game.update` after `Splash.startMenu` loads the menu level
(frame index 544 of the original build). FlashPunk's `Tile.check()` makes four
`Entity.collide("Tile", …)` calls per tile, and each call walks the whole
"Tile" type list. That is ~11.9 M AABB tests in one frame (C4:
`tools/divergence/perf/seedling_c4_2026-09-14/`).

- **The build is the pinned code.** This tree built at the R3 path with
  `EXTRA_LDFLAGS=--profiling-funcs` (a new `build_wasm_avm2.sh` knob) and the
  name section stripped gives **`1d3fac3e143e6edd3676d3826dff63ba`** (wasm)
  and **`5183b74c…`** (js), the Archipelago-CC pin exactly. A first build
  under a scratchpad path differed from the pin in 11 `__FILE__` strings and
  nothing else (`strings` diff), so the path is part of the recipe.
- **The phase.** Seedling's `printItems` dump (`P-Pos: 80, 128`,
  `Level: -1`) is printed between frames 543 and 544. Frame 544 is then the
  only frame over 1 s in every run (9–13 s). The device was lost at the first
  present in every run (`__swfGpu.lost=1`), so this is headless logic-only
  Chromium, with no pixels and no screenshot. The frame is CPU-bound (C4:
  present 0.4 ms), so logic-only wall-clock is a valid instrument for it.
- **Reproduction.** The phase table matches C4 in shape: property-get
  helpers 43.0 % (C4 38.5), body 16.1 (21.9), type checks 16.0 (12.8), numeric
  15.6 (15.9), mp3 3.5 (4.9). It does not match in absolute time: 20.1 s vs
  C4's 10.5 s, because the box was shared (load average ~9 from other
  sessions' vitest/esbuild). Everything below is same-session and interleaved
  for that reason.

## 2. Diagnosis: counters before the lever (§7 rule 6)

`-DAVM2_HOTLOOP_PROF` counts every GetPropertyStatic IC call per site: hit,
or a miss by reason (not an object / no vtable / cold / vtable identity /
count guard), plus the kind of the hit entry and the distinct receiver
classes. It also counts every `add` by operand-kind pair, and every `coerce`
by value kind and superclass depth. The counts are dumped per tick. Tick 545 =
frame 544, on the pinned code path (`counters_k544.txt`):

| mechanism | calls in the frame | split |
|---|---|---|
| `avm2_op_getproperty_static_ic` | **53,905,556** | **99.97 % hits**, 100 % on SLOT entries; 0 non-object, 0 count-guard misses; vtable-identity misses ≈ 2.5 K per 11.9 M at the per-element sites |
| `avm2_op_add` | 19,971,981 | **Number+int 19,956,599 (99.9 %)**; int+int 8,414; Number+Number 6,953 |
| `avm2_op_coerce` → `net.flashpunk::Entity` | 11,932,546 | 99.99 % objects, **depth 1** (the receiver's class extends Entity directly); 1,677 null |

The "Tile" type list holds **16 classes** (Tile, Tree, OpenTree, Rock, Pole,
Building, BrickWell, DungeonSpire, Chest, the locks, …). They sit in the list
in runs, so a monomorphic IC re-caches only at class boundaries.

**The dominant mechanism is the IC hit path, not an IC miss.** The brief read
`resolved_get` (1.59 s in C4) as the slow path. It is the hit path:
`avm2_op_getproperty_static_ic` on a hit calls `avm2_value_vtable`, zeroes a
`Resolved`, calls `avm2_mn_name` (for an error message it never prints), and
calls `resolved_get`. That function walks six resolution-kind branches (proxy,
proto array, array, vector, bytearray, dynamic) before it reaches `switch
(e->kind)` → `slots[slot_index]`. At C4 speed that is ~75 ns per get. The
recompiler's `this.field` specialization emits the same read as one load.

**Why the existing levers miss it:**

- **getproperty IC `c608083d4`:** it applies (99.97 %). It was built to skip
  the multiname match, and it does. The generic dispatch after the match was
  still out of line. On steady-state frames that residue was "irreducible
  IC-hit glue" (session 9); in a 54 M-get frame it is 40 % of the time.
- **`this.field` slot specialization `ab236e611`:** it only covers `this`.
  The loop reads `e.x`, `e.originX`, … on a local typed `Entity`.
- **Non-`this` instance-slot specialization (session 9, gated out):** the
  census was cut against the steady-state gameplay profile, whose top-5 GET
  drivers had 0 new sites. A one-shot level-load pass never appears in a
  steady-state profile.
- **Coercion elision `3b5a6b925`:** `e = e._typeNext` is read through an IC
  get with no static type, so its `coerce Entity` cannot be proven
  redundant, and the coerce-class memo `e05a8fe0d` only removes the class
  lookup.
- **`add`:** lever 5 left `add` generic. `add_values` has int+int and
  Number+Number arms, but `x - originX` is a Number (subtract always boxes a
  Number) and `width` is `int`. So all 20 M adds take `coerce_to_primitive` ×2
  and `coerce_to_number` ×2.

## 3. The lever: inline the slot hit

`Avm2InlineCache` gains `slot_plus1`. `getproperty_static_impl` writes it
together with `vt`/`vt_count`/`entry_index`: `slot_index + 1` when the found
entry is `AVM2_PROP_SLOT`, else 0. `avm2_op_getproperty_static_ic` becomes a
`static inline` in `avm2_ops.h`:

```c
if (recv.kind == AVM2_VALUE_OBJECT && ic->slot_plus1 != 0) {
    Avm2Object* o = recv.u.obj;
    const Avm2VTable* vt = o->vtable ? o->vtable : (o->cls ? &o->cls->ivtable : NULL);
    if (vt == ic->vt && vt->count == ic->vt_count && !o->is_prim_box)
        return o->slots[ic->slot_plus1 - 1];
}
return avm2_op_getproperty_static_ic_slow(act, recv, mn_idx, ic);   // the old function, renamed
```

**It is equivalent for all inputs.** `unbox_scope_prim` leaves exactly this
receiver alone (an OBJECT that is not a primitive scope box). `vt` is
computed as `avm2_value_vtable` computes it. The out-of-line hit with a SLOT
entry and an all-zero `Resolved` returns `recv.u.obj->slots[e->slot_index]`.
Only GetPropertyStatic sites populate `slot_plus1`; the set and call IC sites
have their own zero-initialized caches. The change is runtime + header only:
the generated C is recompiled, and nothing is re-recompiled from the SWF.

- **Toggle `-DAVM2_NO_IC_SLOT_INLINE`** removes exactly the lever: no field,
  no inline, the original function name. **That build of this tree is the
  pinned bytes:** `1d3fac3e…` (seedling_original) and `5c81dfe7…` /
  `56105677…` (seedling_bot_ap_p4d). The instruments are default-off and
  inert. The frame digest lives in `render_webgpu.h` precisely so that
  `render_webgpu.c`'s `assert()` `__LINE__` constants do not move. A first
  placement inside the `.c` shifted 16 bytes of line numbers.
- **Verify `-DAVM2_IC_SLOT_VERIFY`** runs the out-of-line op on every inline
  hit and `avm2_fatal`s on any kind or payload difference.

Cost: the ON wasm is 35.86 MB vs 33.71 MB (the inline at 16,884 IC get sites), and the
generated TUs compile ~1.6× slower.

## 4. Byte-identity

`-DSWF_FRAME_DIGEST` keeps an FNV-1a digest of every `writeBuffer` /
`writeTexture` payload (with offsets) and every draw's arguments, and pushes
one per submit to `window.__swfDigest`. The upload stream is still issued on
a lost device. The run covered the load + 600 frames, one run each, same
session (`probe.mjs`):

| build | frames | digests equal to OFF | console lines | verify aborts |
|---|---|---|---|---|
| OFF (`-DSWF_FRAME_DIGEST -DAVM2_NO_IC_SLOT_INLINE`) | 601 | — | 56 | — |
| ON (`-DSWF_FRAME_DIGEST`) | 601 | **601 / 601** | 56, identical | — |
| VERIFY (`-DAVM2_IC_SLOT_VERIFY -DSWF_FRAME_DIGEST`) | 602 | **601 / 601** | 56, identical | **0** |

The run produced 191 distinct digests in 601 frames, so the digest tracks
real content. The two `PAGEERROR`s per run are the headless device-loss
message, and they appear in all three builds.

## 5. The A/B

The runs were headless logic-only Chromium (`HEADLESS_LOGIC_ONLY_ARGS`),
under Archipelago-CC's box lock. There were 5 rounds, strictly interleaved
with alternating order (ON OFF, OFF ON, …). The table gives medians of each
frame's `swf_perf_report` elapsed time (`ab.csv`). Headless is valid here
because the measured frames are CPU-bound; real-GPU Windows Chrome was not
used (§7 rule 2 caveat). The box was shared with other sessions (load 2–6
during the rounds), so the absolute OFF numbers run ~20 % above C4's quiet-box
10.2 s.

| title / frame | ON median | OFF median | ratio | ON faster |
|---|---|---|---|---|
| **seedling_original k=544** (the collide frame) | **8,689.0 ms** | **12,235.5 ms** | **1.41×** (−3.55 s) | 5 / 5 |
| seedling_original k=543 (level load) | 466.2 | 500.3 | 1.07× | — |
| seedling_original k=545 | 62.4 | 76.1 | 1.22× | — |
| seedling_original steady frames 30–559 (excl. 543/544), median / mean | 2.10 / 3.88 | 2.10 / 4.12 | 1.00× / 1.06× | — |
| **seedling_bot_ap_p4d k=1** (boot: 58 % mp3 decode + L0 collide) | **1,068.6 ms** | **1,169.6 ms** | **1.09×** (−101 ms) | 5 / 5 |
| seedling_bot_ap_p4d steady frames 30–44, median | 22.0 | 24.9 | 1.13× | — |

No steady-state regression. The p4d gain is small because only ~25 % of its
boot frame is the collide pass.

**Phase table after the lever** (one profiled run each, same session,
`results.txt`):

| phase (k=544) | OFF ms | ON ms |
|---|---|---|
| property-get helpers | 5,180.6 (38.9 %) | **20.9 (0.2 %)** |
| compiled body `abc0_m96` | 2,552.9 | 3,699.4 (39.1 %) — absorbs the inline loads |
| numeric add/coerce helpers | 2,046.3 | 2,224.0 (23.5 %) |
| type-check/coerce helpers | 2,180.8 | 2,154.8 (22.8 %) |
| mp3 decode | 579.3 | 644.4 |
| **frame** | **13,303.9** | **9,470.3** |

## 6. CI

All on `2973513c4` (the code), baseline `2aa6596d6`, read with
`scripts/corpus_status_diff.py`:

| run | mode / inputs | verdict |
|---|---|---|
| `35163868554` | graphics, `categories=full` | effective 4440 → 4439 over the 4526-test intersection; **1 move: `avm2/goto_framescript_queued/swf13` ruffle_matched → output_mismatch — upstream drift, not this change** (below). Merged `6c1329197` → `317ac43cf` |
| `35166754380` | no-graphics, `categories=full` (at `317ac43cf`) | effective 4439 → 4439: the same drift test, plus `avm2/mouse_pick_avm1_root` output_mismatch → pass, which is the no-graphics baseline being stale (the 2026-09-12 canary; graphics already passed it). Merged `6bf7f3c30` |
| `35163877697` | no-graphics, `categories=full`, `extra_defines=-DAVM2_IC_SLOT_VERIFY` (publishes nothing) | **0 `ic-slot-verify` aborts** in any shard artifact; per-test status + matching-line count identical to the normal no-graphics run for **4,477 / 4,477** tests |

**The drift.** Ruffle `7e8e2de8a` (2026-09-15, "avm2: Queue play/stop action
alongside the frame for queued gotos") rewrote `goto_framescript_queued`'s
`output.txt` and `output.ruffle.txt`, and `b20e2fdf9` added
`goto_framescript_queued_same_frame`. Our actual output is the same 48 lines
with 17 matching on both sides of the run, so only the Ruffle reference moved
under us. That makes it a candidate for the AVM2 timeline backlog, not a
regression.

## 7. What is left in this frame, measured and not built

These are two levers, each ~2.2 s of the remaining 9.5 s:

1. **`add` Number+int arm.** 19.96 M adds per frame, all mixed-kind. An arm
   `if (both numeric) return avm2_number(to_double(a) + to_double(b))` after
   the int+int arm is what the generic path already computes: primitives
   coerce to themselves, then `coerce_to_number` adds. This is not the
   rejected lever-5 arm, which flattened int+int to Number; that arm stays
   first.
2. **`coerce <class>` fast path.** 11.93 M coerces at depth 1. The generic
   path pays `avm2_mn_name`, the `*`/`void` tests, the memo lookup, 4 + 6
   builtin-class compares and the chain walk. A per-site cache (or an inline
   `v.u.obj->cls == cached || cls->super_class == cached`) is the candidate.

The body itself (39 %) is the ASYNCIFY-instrumented generated code. That is
out of this slice's scope.

## 8. Instruments added (all default-off)

| flag | what |
|---|---|
| `-DAVM2_HOTLOOP_PROF` | per-tick `[HLPROF]` dump (ticks with ≥ 1 M IC gets): per-IC-site hit / miss-by-reason / entry kind / distinct receiver classes; add kind pairs; coerce value kind + superclass depth. Counts the out-of-line path, so build it with `-DAVM2_NO_IC_SLOT_INLINE` to see every get |
| `-DSWF_FRAME_DIGEST` | per-submit FNV digest of all uploads + draws → `window.__swfDigest` (browser builds) |
| `-DAVM2_IC_SLOT_VERIFY` / `-DAVM2_NO_IC_SLOT_INLINE` | the lever's verify / off switch |
| `EXTRA_LDFLAGS` (`build_wasm_avm2.sh`) | extra link flags, e.g. `--profiling-funcs` |

`tools/divergence/perf/seedling_hotloop_2026-09-16/probe.mjs` is the driver.
It runs headless logic-only Chromium over one or more build dirs under one
box-lock hold, records per-frame CPU with end timestamps, stamps console lines
with the frame count, keeps `__swfDigest`, and can take an optional CDP
profile from frame 520. It imports Playwright, the flags and the lock from
`~/CC/Archipelago-CC`.
