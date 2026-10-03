# AVM2 native-memory leaks behind the Seedling wasm OOM (2026-10-03)

Session `swfrecomp-seedling-leak-fix`. Brief:
`~/CC/Archipelago-CC/NewDocs/plans/swfrecomp-seedling-leak-fix-prompt.md`. Handoff it built on:
`~/CC/Archipelago-CC/NewDocs/plans/seedling-wasm-leak-report.md` (the measurements, from session `seedling-wasm-leak`).

## The result

The recompiled Seedling (p4e SWF) used to die after ~170 overworld room swaps on its 512 MiB wasm arena.

| measurement | before (14a54b6e9) | after (4c450f076) |
|---|---|---|
| room-swap floor (probe `--mode=V`, west pair) | **2,734,437 B/swap**; OOM at 170 swaps | **59.48 → 59.55 MB over 516 swaps (~140 B/swap)**; 520 swaps, no death |
| idle bridge (`--mode=I`, `botStatus` at 10 Hz) | 9,166 B/call | **0 B/call**: the post-collection floor is 60.09 MB at every collection from call 201 to call 931 |
| live object census per collection (`AVM2_GC_HIST`) | XMLList +21.7k, XML +3.5k per collection | flat: 8,835 / 11,703, alternating with the two rooms |

The fix landed in three steps. Each step uncovered the next.

1. **`c6be20a88`** built on the `seedling-wasm-leak` branch (`36b0377cb`, `cd2ee479e`, `bb47c043d`):
   - E4X becomes collectable:
     - a node lives while an XML or XMLList wrapper reaches its connected tree;
     - wrappers are no longer pinned;
     - the node registry is swept after a completed mark.
   - JSON stringify/parse scratch is freed.
   - Array and Vector growth frees the old buffer.
   - E4X per-operation scratch is freed: the serializer `Buf`, one in-scope-namespace list per serialized element, and the parser stacks.

   On Seedling the swap leak fell from 2.73 MB to ~190 KB per swap.
2. **`4c450f076`** (the residual). The marked set was flat, so what remained was raw heap that the census never sees. The
   allocation-site tracker (below) named the biggest piece: `ByteArray.readUTFBytes` leaked an 81 KB UTF-8 buffer per
   level-XML read. A runtime-wide scan then found the same shapes elsewhere:
   - **alloc → `avm2_string_new` (which copies) → never freed**: about 20 sites (String case conversion and
     `fromCharCode`, `escape`/URI, RegExp `toString`, the TextField string builder, ...);
   - **grow without freeing the old buffer**: ByteArray storage, display render/depth lists, the per-frame
     `queued_places`, the AMF tables;
   - **per-call vectors**: `Function.apply`, Proxy `callProperty`, the RegExp UTF-16 subject view;
   - **the receiver's bound-method cache nodes**, never freed with the receiver.

## How it was found (reuse these)

- `AVM2_GC_HIST=1`: the live (marked) census by class, top 40, per collection. It named E4X.
- `AVM2_GC_WHY=<Class>`: the first-marker path to a root for up to 8 live instances.
- `AVM2_GC_VERBOSE`'s per-collect line now ends `heap N MB`: the o1heap allocated bytes. **If the census is flat and
  `heap` climbs, the leak is raw (non-census) memory.**
- `-DHEAP_TRACK_SITES` (wasm only) + `EXTRA_LDFLAGS=--profiling-funcs`: every `heap_alloc` while `g_heap_track_on`
  records its size and 6 return PCs. `Module.ccall('avm2_ei_track_set', null, ['number'], [1])`,
  `avm2_ei_track_reset` and `avm2_ei_track_report` drive it from the page, and the report prints 60 stack groups.
  - Resolve the PCs with `llvm-objdump -t <wasm> | awk '$3=="F"{print $1,$5,$6}'` plus a bisect. Function names need
    `--profiling-funcs`; the release link has none, but a named relink keeps the same code offsets.
  - Tracking makes every allocation slow (`emscripten_return_address`), so track only a few swaps.
  - What is outstanding after a window includes the current room's live set: look for the groups that do not match
    one room.
- All of these cost nothing when off. The tracker is compiled out unless `-DHEAP_TRACK_SITES` is set.

## Regression tests (`ruffle-tests/tests/swfs/regression/`)

- `avm2_json_roundtrip_bounded`, `avm2_array_growth_bounded` and `avm2_e4x_parse_bounded` each run 120 ticks in a
  64 MB arena, via `SWF_HEAP_MB` from the new per-test `test_env.json` that `verify_output.py` reads.
  - On the leaking runtime all three die with `heap_alloc ... out of memory`.
  - On the fixed runtime they pass at 32–128 MB, with flat floors of 4.39 MB, 4.4–4.9 MB and 5.14 MB.
  - Their output is byte-identical to the old runtime's when the arena is large enough.
- The E4X test is also a liveness lock under `AVM2_GC_STRESS=1`: identity across ticks, `parent()` from a leaf held
  alone, detached subtrees, a list whose target only the list reaches, namespaces, and a notification closure.

## Verification

- Local, `AVM2_GC_STRESS=1`: avm2 xml/json/array/vector (148) + from_avmplus e4x (177) = 325/325, equal to the
  baseline.
- Local, ASAN + `SWFRECOMP_EXTRA_DEFINES=-DHEAP_PASSTHROUGH` (malloc, so ASAN sees use-after-free inside what would
  otherwise be the o1heap arena) + GC stress:
  - 12 xml/json/regression tests after step 1;
  - 24 tests covering every path step 2 touched (amf, bytearray, regexp, string, edittext html, removeChildren,
    apply, formatToString, URI, StaticText, domain memory).

  No sanitizer report in either set.
- CI on `c6be20a88`: graphics full 37136809909, no-graphics full 37136817336, graphics full with `avm2_gc=1`
  37136824100. No real regressions:
  - `avm1/point`, `avm1/rectangle` and `from_gnash/actionscript.all/Rectangle-v8` are upstream drift (point's expected
    output went from 175 to 329 lines in the 2026-10-03 sync, and Rectangle-v8's own output is unchanged);
  - `as3-loader/bug1157243/empty` is the known load-flaky test;
  - the stress run matches the non-stress run test-for-test.
- CI on `4c450f076`: see §"CI on the final SHA" below.

## Traps for the next session

- **A free on growth is only safe if nothing holds the old pointer across the growth.** Three places did, and each was
  fixed with a copy rather than skipping the free:
  - the AMF3 reader held `TraitEntry* trait` across nested reads that can grow the trait table;
  - the RegExp `replace` callback runs AS3 while the subject view is live, so the view is released before the
    callback;
  - `flush_queued_places` re-reads `ext->queued_places` through `ext`.

  Re-check this before adding a free to any growable table.
- **Closure scope chains (`avm2_op_newfunction` → `avm2_scope_capture`) are still never freed, by design.** The
  find-property inline caches (`Avm2FindCache.outer`, `Avm2StaticFindCache.outer`) key on chain POINTER identity
  ("outer chains are allocated once and never freed, so the chain-identity guard cannot alias"). Freeing chains needs
  an ABA-proof chain id in those caches first. The measured Seedling floor is flat without it (whatever closures
  Seedling makes per swap cost under ~140 B/swap), so it was left alone.
- Vtable `entries`/`metas` growth also never frees the old array: ICs and bound-method nodes hold `Avm2PropEntry*`
  pointers. Vtable growth is bootstrap-time, except for per-activation vtables.
- `verify_output.py` reads `test_env.json` for per-test runtime env.

## CI on the final SHA (`4c450f076`)

- Graphics full, run 37150142225: 0 regressions against the `c6be20a88` results. The status histogram is identical
  (effective 4476).
- Graphics full with `avm2_gc=1` (stress), run 37150149686: every test matches the non-stress run except six NEW
  upstream tests (`html_text_img_*`, absent from the previous runs). They fail in both modes. The avm2 one exercises
  htmlText, which this change touched, so it was checked locally: its output is byte-identical between `14a54b6e9`
  and `4c450f076` (a pre-existing gap, not a regression).

## Seedling builds on `4c450f076` (all three Archipelago targets)

Built from the pinned SWFs with `FRESH=1 build_wasm_avm2.sh`, as `seedling_lf_{p4e,p4d,original}`. Probed in the
throwaway Archipelago worktree. The real pins are NOT touched; that rebuild belongs to the Archipelago side.

| build | probe | result |
|---|---|---|
| p4e (default) | `--mode=V` west pair, 520 swaps | floor 59.36/59.48 → 59.55 MB; no death |
| p4d (control) | `--mode=V`, 520 swaps | 59.48 → 59.55 MB; no death |
| original (`826ba77`) | `l0-original.mjs` Esc↔menu, 60 world swaps, real pixels | 60.46 → 60.47 MB (was 110 → 446 MB over 40 swaps) |
| p4e (instrumented twin) | `--mode=I`, `botStatus` 10 Hz, 120 s | post-collection floor 60.09 MB at every collection, calls 201–931 |

Not measured here: the live panel's `queueItems` → `getItemQueue` → `JSON.parse` path. The probe's `--panel` mode
drives only the preset's pinned build, and the game drains the queue only once the panel has configured BridgeGeneric.
The JSON.parse fix itself is locked by `avm2_json_roundtrip_bounded`.
