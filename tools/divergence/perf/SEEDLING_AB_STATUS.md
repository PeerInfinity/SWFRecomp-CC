# Seedling perf A/B — status

## ★★★★ UPDATE 2026-07-14 (session 7) — COERCE-CLASS-RESOLUTION MEMO: ~6 ms (~12%), CLEANLY ABOVE NOISE — the fresh-profile #1 lever, and the first win past the compile-time-slot arc
New perf arc opened from the post-Step-4 fresh profile
([[seedling-fresh-profile-poststep4-lever-map]], lever #1). `avm2_coerce_to_type_mn`
re-ran `avm2_class_for_mn` (**2.9 % self-time** — `avm2_domain_find` + `avm2_vtable_find`)
on EVERY coerce, for a compile-time-constant `mn_idx` → a stable Class. The
`(file, mn_idx) → Class*` mapping is a pure function of append-only state (a class
installs into a script global once; the domain is append-only, first-match, stable
identity), so a non-NULL resolution is permanent.

**Runtime-only** (no recompiler change, unlike Steps 2-4). `avm2_class_for_mn` was
split into `avm2_class_for_mn_resolve` (old body) + a memoizing wrapper backed by a
per-file `coerce_class_memo[]` (sized `multiname_count`, in `Avm2AbcFileRt`). Only
NON-NULL results are cached — a type name is transiently unresolvable during its own
cinit and that miss must not be frozen. Vector.<T> and recursive base/param resolves
route back through the wrapper, so they cache too. One choke point covers `op_coerce`
+ `setup_locals` (typed-param coercion) + `setproperty_resolved` + `coerce_return`.
Commit `e05a8fe0d`.

**Real-GPU interleaved A/B (Intel Gen9, `seedling` = memo ON vs `seedling_before` =
`-DSWF_NO_CLASS_MEMO`, both fresh same-flags `--profiling-funcs` builds):**
```
  CLEAN batch (WSL idle, 6 rounds, settle 30s):
  round   on(ms)   off(ms)   Δ
    1      41.7     46.6     +4.9
    2      40.8     46.0     +5.2
    3      39.9     46.5     +6.6
    4      44.2     53.1     +8.9
    5      49.8     53.9     +4.1
    6      43.5     50.6     +7.1
  ON  mean 43.3  median 42.6  stdev 3.3
  OFF mean 49.5  median 48.6  stdev 3.2
  Δ = +6.1 ms mean / +6.0 ms median favoring the memo (~12%) — ON < OFF EVERY round,
      cleanly above the ±3.3 ms noise.
```
A first (partially machine-contended) batch agreed in direction on all 6 rounds; its
two clean opening rounds read ON 30.3 vs OFF 33.2/34.2 (+3.4 ms, fps 33 vs 30) at a
lower machine-load baseline. Two independent batches, **unanimous ON < OFF**. Present
~0.5-0.6 ms both sides (render off the critical path). **Unlike Step-4/Step-5 (both
below noise), this lever is clearly measurable** — it removes a real 2.9 % self-time
function that sits ON the per-frame coerce path, not a cold/startup site.

**Correctness (mirrors lever A):** `-DAVM2_CLASS_MEMO_VERIFY` re-runs the full resolve
on every memo HIT and aborts on divergence; `-DSWF_NO_CLASS_MEMO` disables the cache
(A/B baseline). Full-suite verify CI (run 29386334757): **avm2 829/1205 held, ZERO
`class-memo mismatch` aborts across all 829 tests.** Normal CI (run 29386363337):
avm2 829/1205, avm1 634/707, shumway 73/92 — identical to the verify run and to
baseline → byte-identical, no regression. `ruffle-test-results` merged.

**Arc status:** the 30 fps / 33.3 ms target was met at Step 3 (~32.6 ms); this is a
*fresh* arc (a different, cacheable hot bucket the compile-time-slot arc never
touched). Remaining fresh-profile levers: blit SIMD (~5.7 %), typed-Number arithmetic
spec (~2-4 %), Matrix/Point sealed slots (~2.3 %).

---

## ★★★ UPDATE 2026-07-14 (session 6) — STEP 4 coercion elision: sound but ~1 ms (below noise), hot path already coerce-clean
Final step of the compile-time type-specialization arc (plan
`seedling-perf-compile-time-specialization.md`). The recompiler now elides
`coerce_*` / `coerce_return` sites its forward abstract-interp proves are value
no-ops (operand already has the target static type). **735 elided sites in
Seedling** (344 return, 167 CoerceD, 113 named, 76 Boolean, 18/9/8 I/S/U).

**Real-GPU interleaved A/B (Intel Gen9, 6 rounds, `seedling` = elision vs
`seedling_before` = `SWF_NO_COERCE_ELIDE`):**
```
  round   on(ms)   off(ms)
    1      49.7      43.9    (r1 on = warmup hiccup, p95 68.5)
    2      40.7      47.1
    3      37.6      39.2
    4      41.8      41.5
    5      40.5      42.3
    6      40.0      42.7
  on mean 41.7 (median 40.6, stdev 3.8)   off mean 42.8 (median 42.5, stdev 2.4)
  Δ = +1.1 ms mean / +1.9 ms median favoring elision — WITHIN the ±2.4-3.8 ms noise
```
Favorable direction, below clean measurability. **The hottest method m676
(Image.render) has ZERO elidable coerces** (its coerces are `ReturnVoid`
defaults + native flash.geom Matrix/Point types); the 735 sites live in
cold/startup + per-frame-logic methods (m523=46, m630=24, m247=21). Coercion
elision is structurally near-exhausted for steady-state frame time — the AS3
compiler already leaves the hot arithmetic coerce-clean.

**Correctness:** `-DAVM2_COERCE_VERIFY` makes every elided site run the REAL
coerce and abort on any value change (mirrors `-DAVM2_SLOT_VERIFY`); 8
coercion-critical avm2 tests pass locally with zero aborts. Full-suite CI
(commit `3b5a6b925`): verify-mode run 29382549715 + normal run 29382556130 BOTH
give the identical avm2 breakdown pass=829 / runtime_error=4 / output_mismatch=347
— byte-identical to baseline, ZERO coerce aborts across all 829 tests. Commit
`3b5a6b925`.

**Arc verdict: 30 fps target met at Step 3 (~32.6 ms); Step 4 closes the arc.**
The remaining lever is monomorphic devirtualization (needs class-hierarchy
analysis — FlashPunk methods aren't `final`), deferred.

---


## ★★★★★ UPDATE 2026-07-14 (session 5) — COMPILE-TIME SLOT SPECIALIZATION: ~3-4 ms (~7-9%), the first win past the IC plateau
Step 2 of the compile-time type-specialization arc (plan
`seedling-perf-compile-time-specialization.md`). The recompiler now emits a bare
`recv.u.obj->slots[K]` load for `GetPropertyStatic` sites it proves are
`this.field` where the field is a SLOT/CONST trait — skipping the inline-cache
call, vtable-identity check, count guard, and `resolved_get` dispatch that even an
IC *hit* pays. This is the compile-time resolution an interpreter structurally
cannot do (Step-1 scout's lever). **5039 specialized sites in Seedling.**

**Real-GPU interleaved A/B (Intel Gen9, 4 rounds, same-session `--profiling-funcs`
builds: `seedling` = specialized, `seedling_before` = IC-only via `SWF_NO_SLOT_SPEC=1`):**
```
  round   after(ms)   before(ms)   Δ
    1       43.0        46.8       -3.8
    2       42.1        47.1       -5.0
    3       46.9        46.8       +0.1   ← after outlier (p95 69, machine hiccup)
    4       42.5        45.8       -3.3
  after mean 43.6   before mean 46.6   Δ 3.0 ms (6.4%)
  excluding r3 outlier: after 42.5  before 46.6   Δ 4.0 ms (8.6%)
```
3 of 4 rounds show a clean 3.3-5.0 ms win — the first change to clear the ±10%
noise floor since the IC arc plateaued at parity (the last IC extension bought
~2%). Present ~0.6 ms both sides (render off the critical path, as established).

**Correctness (the hard part):**
- Compile-time slot index K mirrors `avm2_class.c` ivtable numbering exactly
  (`inheritedBase` seed — 0 for an Object base — + sequential auto-assign,
  honoring explicit `slot_or_disp_id`). `-DAVM2_SLOT_VERIFY` cross-checks K vs the
  runtime resolve on every specialized read and aborts on mismatch.
- Seedling verify smoke: 6 frames, hot per-frame methods' sites executing, ZERO
  mismatches.
- The verify build CAUGHT a real bug: `sub_super_same_field` mis-specialized
  `this.pubSameName` (compile-time slot 1 != runtime slot 3 on a LevelTwo
  receiver) because a SUBCLASS redeclares the field, shadowing it. Fixed by also
  bailing when any descendant subclass redeclares the name (`subclassRedeclares`);
  5041 → 5039 sites. Full-suite verify-mode CI validates all 829 tests.
- Sound subset: receiver is `this` (local 0 of an instance method that never
  writes local 0); `this`'s class sealed; full ABC chain to Object; name resolves
  UNIQUELY to a slot/const trait in the chain AND no subclass redeclares it.

**Next levers (Step 3, bigger — from the Step-1 scout):** the two LARGER get
levers are still untouched — getlex-global resolution (~32% of get weight: bake
the resolved global/class pointer, kills `avm2_domain_find`) and class-static slot
(~22%: `FP.x` on a compile-time-known Class). Plus coercion elision (bucket C).


## ★★★★ UPDATE 2026-07-14 (session 4) — IC extended to callproperty + setproperty: ~1 ms (~2%), the AVM tick is near its floor
Extended the session-2 getproperty inline-cache to the two other receiver-vtable
property ops — **CallProperty/CallPropVoid** and **SetPropertyStatic** — the next
lever flagged by `prof_approachA.json`. Pure reuse of the `Avm2InlineCache`
design (avm2_ops.h): a repeat call/write whose receiver has the same vtable
identity (unchanged `count`) replays the resolved entry INDEX directly, skipping
the `avm2_vtable_find_mn` multiname match. Same correctness invariants as
getproperty (cache only plain-object receivers whose PRIMARY find hit; exclude
xmlish + `no_index` newactivation/newcatch; count-guarded; a matching vt ⟹
byte-identical). Emitter change: block-scoped `static Avm2InlineCache` per site
(4765 call + 2922 set sites in Seedling). Commit `c7f9f5e26`.

**Real-GPU Windows Chrome A/B (Intel Gen9, adapter "intel / gen-9"), INTERLEAVED
before/after in one session to cancel machine drift** (both fresh same-session
`--profiling-funcs` builds; `seedling` = after, `seedling_before` = baseline):
```
  round   BEFORE(ms)   AFTER(ms)
    1        47.6         47.6
    2        50.1         46.5
    3        48.7         58.2 ← after outlier (p95 83.9, max 134 — a hiccup)
    4        46.1         46.5
  BEFORE mean (ex-r3): ~47.9      AFTER mean (ex-r3): ~46.9    Δ ~1.0 ms (~2%)
```
The ~1 ms sits right at the ±10% run-to-run noise floor — as the plan predicted
for a slice that was only ~2-3% of the frame. **Clean same-session CDP self-time
profile confirms the mechanism landed** (`prof_before_baseline.json` vs
`prof_callset_ic.json`, same rig):
```
  function                 BEFORE      AFTER
  avm2_vtable_find_mn       5.1%(1583)  4.0%(1212)   ← -23%, the direct target
  avm2_propkey_matches      3.7%(1149)  3.1%( 941)   ← drops with the scan
  setproperty_impl (disp.)  1.3%( 391)  ~0           ← IC-hit bypasses the dispatcher
  avm2_domain_find          3.6%        3.7%         ← unchanged (no findprop IC — expected)
  callproperty path         op 1.0% + common 0.9%    _ic 1.2% + common 1.0%
```
Render byte-identical. Local avm2 correctness spot-checks pass across the tricky
exclusion paths (class_methods, callproplex_class, getter_different_namespace_
setter, event_target_getter, proxy_callproperty, proxy_getproperty, flash_xml,
array_hasownproperty). Full-suite CI grade (no-graphics, run
29362960851): **avm2 829 → 829, mismatched lines 47323 → 47323 ("No changes
detected"), avm1 634 → 634** — ZERO pass→fail, byte-identical, the emitter change
regenerated + graded across all 1205 avm2 tests.

**HONEST CONCLUSION — the AVM tick is near its floor.** Cumulative arc: 280 → ~47
ms (≈6x), gap vs Ruffle ~6.0x → ~1.02x. This IC extension nudges ~47.9 → ~46.9,
keeping us at parity-to-marginally-ahead of Ruffle (~46 ms). The remaining top
self-time slices are the **irreducible property READ / method dispatch**
(`resolved_get`/`getproperty_static_ic`/`avm2_call_method_ref`/`resolve_mn`) plus
the two levers with a *different* IC shape (`avm2_domain_find` 3.7% +
`avm2_op_findproperty` 2.9% — scope-chain + global-domain scan, NOT a receiver
vtable) and `bd_copy_pixels` 3.1% (the FlashPunk CPU blit). No single remaining
change buys a landslide; the honest verdict is **at parity with marginal
headroom**. The next real lever, if pursued, is a scope/domain IC for
findproperty (harder — the resolved global-domain entry could be cached per site
keyed on domain identity, but the scope-chain part varies per activation).


## ★★★ UPDATE 2026-07-14 (session 3) — writeTexture 110x GPU-traffic cut (byte-identical), but frame time is AVM-bound
The session-2 profile flagged `writeTexture` as the clear #1 self-time slice
(~17.6%). Measured it first (per the plan's FIRST STEP) and found the real story:
Seedling's FP.buffer source is only **160×160** (FlashPunk renders at 160×160 and
scales 3× to the 480×480 stage — retro pixel art), but the shared static+dynamic
bitmap texture array is sized to Seedling's **4480×640 embedded atlas**, so each
tiny dynamic upload padded to **4481×641** and uploaded **11.49 MB/frame for
102 KB of real data — a ~112× waste bug.**

**Fix (approach A, LANDED) — upload only the source sub-region.** In
`render_webgpu_draw_bitmap_quad_scaled` (render_webgpu.c, the AVM2 + AVM1-
attachBitmap + graphics-native blit path), upload just the `(src+1)×(src+1)`
sub-rect at the layer origin instead of the full padded `bw×bh` layer.
Byte-identical: the quad's inverse matrix maps the on-stage quad EXACTLY onto
bitmap coords `[0,src]` (`sx = src_w/(dst_w·20)`), sampler is Nearest+ClampToEdge,
`bitmap_sizes` stays the padded `{bw,bh}` so UV normalization is unchanged → the
shader only ever addresses texels `[0,src]`; the untouched padding is never read.

**Measured, real-GPU Windows Chrome (Intel Gen9, adapter "intel / gen-9"):**
```
                       BEFORE          AFTER (approach A)      Δ
  writeTexture bytes   11,489,284 B    103,684 B (161²·4)     110.8× less  ← ✓ counter
  writeTexture calls   1/frame         1/frame                (single FP.buffer)
  present (renderer_poll) ~11.45 ms    ~0.68 ms               ~17× less
  writeTexture self-time  ~17.6% (#1)  gone from top-35       collapsed    ← ✓ CDP re-profile
  frame CPU mean       ~47 ms          ~47-51 ms (noisy ±10%) UNCHANGED
  delivered fps        ~19-21          ~18-21 (within noise)  UNCHANGED
  render               —               byte-identical          ✓ OverWorld matches oracle
```
**The upload was OFF the critical path** — it overlapped the AVM tick, so cutting
it 110× removed the #1 CDP self-time slice + 110× GPU traffic + ~11 ms of present
latency, all byte-identical, but did NOT move the delivered frame rate. The
re-profile (`prof_approachA.json`) shows the frame is now unambiguously bound by
the **AVM2 property-lookup tick**:
```
   8.1%  resolved_get
   7.6%  avm2_op_getproperty_static_ic
   6.8%  (idle)
   5.1%  avm2_vtable_find_mn      ← residual: callproperty/findproperty/setproperty (no IC)
   3.7%  avm2_propkey_matches
   3.5%  avm2_domain_find
   3.0%  bd_copy_pixels          ← FlashPunk CPU blit
   2.8%  avm2_op_findproperty  2.7% avm2_call_method_ref  2.6% avm2_value_vtable ...
```
Still worth shipping: fixes a real 112× resource-waste bug, byte-identical, big
GPU-bandwidth + present-latency win (matters on lower-end GPUs / battery / higher
res), and clears the render path so future AVM-tick wins aren't masked by it.

**THE REAL NEXT LEVER (unblocked, evidence above):** the AVM2 property-lookup
tick. Extend the session-2 getproperty inline-cache to **callproperty /
setproperty** (receiver-vtable analogs of getproperty — `avm2_vtable_find_mn`
5.1% + `avm2_op_callproperty` + `setproperty_resolved`) and a scope/domain IC for
**findproperty** (`avm2_op_findproperty` 2.8% + `avm2_domain_find` 3.5%). Pure
reuse of the `Avm2InlineCache` design (avm2_ops.h) — AVM-only → simpler
no-graphics CI. This is what will actually move fps beyond parity.
Tools added: `render_bytes_win.py` (per-frame writeTexture/writeBuffer byte
counters from `__swfRender`), `iv_perf_win.py` (ground-truth delivered frame
period `S.iv`, steady-state filtered). Profiles: `prof_approachA.json`; render
`seedling_approachA.png` (byte-identical to `seedling_final.png`).

## ★★ UPDATE 2026-07-14 (session 2) — PARITY WITH RUFFLE: 62 → 47 ms/frame
Three byte-identical AVM2 hot-path micro-optimizations landed (commit
`c608083d4`), taking Seedling from the ~62 ms after-domain-hash baseline to
**~47 ms/frame — parity with Ruffle (~46 ms), the milestone this whole arc
targeted** (gap ~1.3x → ~1.02x). Real-GPU A/B, same rig (Intel Gen9,
adapter "intel / gen-9"). Render VERIFIED byte-identical (`seedling_final.png`).
avm2 CI **829 → 829, ZERO pass→fail, mismatched lines 47323 → 47323** ("No
changes detected") — the emitter change was regenerated + graded across all
1205 tests. Incremental measured deltas (each its own build):
```
                       frame CPU   avm+submit   the change
  after domain-hash    ~62 ms      ~52 ms       (session-1 baseline)
  + getproperty IC     ~56 ms      ~45 ms       inline cache (below #1)
  + printf int paths   ~54 ms      ~43 ms       (below #3; small — printf hog was #2 not #3)
  + lazy setprop cn    ~47 ms      ~36 ms       (below #2 — the DOMINANT win, ~8 ms)
```
**What each did (all proven byte-identical):**
1. **Per-call-site monomorphic inline cache for GetPropertyStatic.** The
   recompiler (`abc_emit.cpp`) now emits a block-scoped `static Avm2InlineCache`
   per getproperty site (25 738 sites in Seedling) and threads its address into
   a new `avm2_op_getproperty_static_ic` (avm2_ops.h/.c). A repeat call whose
   receiver has the same vtable identity (+ unchanged `count`) replays the
   resolved vtable entry, skipping multiname matching. Only plain-object
   receivers whose PRIMARY vtable find hits are cached; XML (content-varying)
   and the GC'd `no_index` newactivation/newcatch vtables are EXCLUDED, so a
   hit is provably identical to the full path (a matching vt determines
   not-null/not-xmlish/not-vector). Caches the entry INDEX (stable across
   `entries` realloc), count-guarded. `avm2_vtable_find_mn` 6.5 → 3.7%.
2. **Lazy class-name in `setproperty_resolved` — the real printf hog.** CDP
   showed `printf_core`+`__fwritex`+`__vfprintf_internal`+`pad` ≈ 10% of frame,
   and 98.7% of it was `avm2_class_qname_buf` called from `setproperty_resolved`
   — NOT number formatting. `cn` (receiver class qname) was `snprintf`'d on
   EVERY slot write but is only used on the throw branches. Now computed
   per-throw. This one change: ~54 → 47 ms. The whole printf cluster vanished
   from the top-15 self-time.
3. **printf-free integer stringification.** Fast-path exact integers in
   `avm2_format_number` (skip `shortest_digits`' up-to-18 `snprintf("%.*e")`/
   `strtod` probes) + a `write_i32_decimal` for the INTEGER `coerce_to_string`
   arm. Byte-identical (verified natively over millions of values + INT32_MIN).
   Small on its own (the printf hog was #2), but legitimate and compounds.

**Next levers (in `prof_cn.json`, the post-change profile):**
- `writeTexture` is now the clear **#1 at ~17.6%** (GPU upload — FlashPunk's
  full-buffer `copyPixels`→`writeBuffer` each frame). Dirty-rect / partial
  upload / format tuning is the biggest remaining single slice.
- `avm2_vtable_find_mn` **4.3%** residual comes from `callproperty`/
  `findproperty`/`setproperty` (no IC there yet) — extend the inline-cache
  pattern to those ops.
- `__memset` **3.3%** — `resolve_mn`'s `memset(out,0,sizeof)` + the fast-path
  `Resolved r={0}` per get; a leaner Resolved init could shave it.
- `resolved_get` 6.0% + `getproperty_static_ic` 6.5% are now largely the
  irreducible property READ (slot load / method bind / getter call).
Raw profiles: `prof_ic.json`, `prof_printf.json`, `prof_int.json`, `prof_cn.json`
(all in `C:\playwright\`); render `seedling_final.png`.

## ★ UPDATE 2026-07-14 — CDP self-time profile: the hot path is PROPERTY LOOKUP, not the blit
Real-GPU Windows-Chrome CDP sampling profile of our tick (symbolicated build via
`EMCC_CFLAGS=--profiling-funcs`, driver `seedling_cdp_profile_win.py`, Intel Gen9,
35 619 samples @ 200µs). **This overturns the expected suspect.** The FlashPunk
`Image.render`→`copyPixels`/`bd_draw` blit is CHEAP (`bd_copy_pixels` 0.9%,
`writeTexture` 4.7%). The frame is dominated by the **AVM2 property-lookup /
method-resolution machinery**:

```
  31.9%  avm2_vtable_find_mn      ← linear O(count) scan of the receiver vtable
  19.7%  avm2_propkey_matches     ← per-entry name+ns memcmp (called from the scan)
   8.5%  avm2_domain_find         ← linear scan of the global domain (findproperty)
   4.7%  writeTexture (GPU upload — not AVM)
   2.6%  avm2_op_getproperty_static
   2.2%  printf_core  (+ __vfprintf_internal/__fwritex/out/pad ≈ 4% — number→string fmt)
   2.2%  resolved_get / 1.6% resolve_mn / 1.3% avm2_class_for_mn / 1.2% findproperty ...
  MODULE: 93.5% seedling.wasm, 6.3% native/idle, 0.2% js
```
The property-lookup cluster (vtable_find_mn + propkey_matches + domain_find +
class_for_mn + resolve_mn + findproperty + getproperty_common + value_vtable + …)
is **~60–70% of all self-time**. Root cause: `avm2_vtable_find*` (avm2_class.c)
does a **linear scan with per-entry string compares** on every getproperty/
callproperty/findproperty — no hash, no inline cache. Ruffle's vtable is a
HashMap (O(1)); that alone plausibly explains most of the ~6x gap. This is the
AVM2 analog of the AVM1 `findOrCreateMovieClip`/property-name cluster.
Raw profile: `seedling_profile_2026-07-14.json`. Driver+method:
`WINDOWS_PLAYWRIGHT_FROM_WSL.md`.

**Fix #1 LANDED + VERIFIED (this session):** lazy name-keyed hash index on
`Avm2VTable` (avm2_class.c) → `avm2_vtable_find`/`find_mn`/`find_public` become
O(1)+small-bucket, byte-identical match semantics preserved (same predicate on
candidates, ascending-index order). Per-call newactivation/newcatch vtables opt
out (`no_index`) so their GC'd index can't leak. **Measured real-GPU A/B (same
rig, Intel Gen9):**
```
                    BEFORE            AFTER (vtable hash)     Δ
  frame CPU mean    ~280 ms           154.1 ms               -45% (1.8x faster)
  fps               ~3.6              6.5
  avm+submit        ~264 ms           137.8 ms
  present (GPU)     ~17 ms            16.4 ms  (unchanged)
  avm2_vtable_find_mn  31.9%          5.3%     ← the target, collapsed
  gap vs Ruffle (46ms) ~6.0x          ~3.3x
```
Render VERIFIED byte-identical (OverWorld house/grass/water/path/trees/player;
scratchpad `seedling_after.png`). Profiles: `seedling_profile_2026-07-14.json`
(before), `..._after_vtablehash.json` (after).

**Fix #2 LANDED + VERIFIED — hash `avm2_domain_find` (`avm2_globals.c`).** Same
lazy name-keyed index as the vtable (append-only domain, full-propkey match,
ascending-index order → byte-identical). **Measured real-GPU A/B (same rig):**
```
                    after fix#1       after fix#2 (domain)    Δ (this fix)
  frame CPU mean    154.1 ms          61.6-64.3 ms            -60% (2.5x)
  fps               6.5               ~16
  avm+submit        137.8 ms          ~52 ms
  avm2_domain_find     14.9%          1.7%    ← collapsed
  avm2_propkey_matches 13.5%          3.2%    (most calls came from domain scan)
  gap vs Ruffle (46ms) ~3.3x          ~1.3x
```
Render VERIFIED byte-identical (`seedling_after2.png`). New profile:
`seedling_profile_2026-07-14_after_domainhash.json`. A **22% "(idle)"** slice
now appears — the tick is no longer CPU-saturated every ms.

**CUMULATIVE: 280 → ~62 ms/frame (≈4.5x), ~6.0x → ~1.3x vs Ruffle**, from two
lookup-hashing changes. We are now within striking distance of Ruffle on
Seedling (the milestone that motivated the whole arc).

**Next levers (in the after-domainhash profile):**
1. `avm2_vtable_find_mn` still **6.5%** — the hash helped but big shared-name
   buckets (or hot `mn_match` re-parsing) remain; consider caching the resolved
   entry per (vtable, mn_idx) call site (a true inline cache) rather than
   re-matching each call.
2. ~4% `printf_core`/`__vfprintf_internal`/`__fwritex` — number→string
   formatting per frame; fast-path integers to skip printf.
3. `writeTexture` **10.3%** (GPU upload) is now a real slice — the FlashPunk
   full-buffer `copyPixels`→writeBuffer each frame; dirty-rect or format tuning
   could help once the AVM side is squeezed further.
4. Residual dispatch (`resolved_get`/`resolve_mn`/`getproperty_static`) → the
   per-call-site inline cache in (1) covers most of this too.


**Goal (project headline milestone):** same-machine, real-GPU frame-time/FPS
comparison of Seedling in **our WASM** vs **Ruffle-WASM**, both on the teleport
SWF (boots straight to OverWorld1). See `swfrecomp-purpose-beat-ruffle-perf`.

## Rig — BUILT & DEPLOYED (both sides ready)
- **Ours:** `docs2/examples/avm2/seedling/` (24 MB `seedling.wasm`, browser AVM2
  build from `SWFRecomp/scripts/build_wasm_avm2.sh` +
  `deploy_wasm_avm2.sh`). Perf HUD = swf.c's `window.__swfPerf` (steady-state
  filtered), URL `demo.html?test=avm2/seedling&perfhud=1`. **Click "Run SWF".**
- **Ruffle:** `docs2/examples/avm2/seedling_ruffle/` — the existing local
  `~/CC/ruffle` **profiling** web bundle (`__rufflePerfTick`/`__rufflePerfRender`)
  + the teleport SWF + a steady-state HUD. URL `examples/avm2/seedling_ruffle/`.
- Serve: `cd docs2 && python3 -m http.server 8000` (WSL2 forwards localhost).

## Numbers — NONE YET
WSL Chrome is SwiftShader; it **cannot** measure real GPU/CPU perf (every prior
"gap" it produced was an artifact — see `ruffle-wasm-perf-shim-and-build`). The
A/B must run on the user's **Windows** machine (real GPU).

**Runbook to hand to Windows:** `WINDOWS_SEEDLING_AB.md` (chrome://gpu real-GPU
check, the two URLs, a REPORT-BACK block). Paste the filled block back here and
record the first numbers below.

## First Windows results
```
Run 1 (2026-07-13, ours only, BEFORE the Rectangle.intersects fix):
  ours: frame CPU mean 46.87 ms  p95 67  max 134  (141% of 30fps budget)
        avm+submit 24.77 ms / present 22.10 ms   ~21 fps sustainable
        steady-state 120/120 frames (0 excluded — clean measurement)
  NOTE: this run threw flash.geom.Rectangle.intersects (Error #1069) EVERY frame
  (FlashPunk culling) — a per-frame throw+catch AND broken culling (likely
  overdraw). Fixed in commit a380ab7dd; re-measure expected to improve.
  Rendered-correctly? — not yet reported.

Run 2 (2026-07-13, ours, AFTER the Rectangle.intersects fix, real GPU):
  ours: frame CPU ~222 ms mean (14 untainted steady-state frames; run-1 variant
        345 ms all-throttled) → ~4-5 fps. Split: avm+submit ~210-325 ms,
        present only ~13-20 ms.
  *** The fix made the number look WORSE — because it's now HONEST. Pre-fix,
  intersects threw on the FIRST call each frame, and the top-level catch aborted
  the rest of the frame's FlashPunk World.update + World.render (the CPU
  copyPixels tilemap blits). So 46.9 ms was a partial/aborted frame. With
  intersects working the frame runs to completion → ~222 ms, and it is
  overwhelmingly AVM/CPU-bound (present/GPU is cheap ~15 ms). The cost is the
  recompiled AS3 FlashPunk per-frame software-buffer blitting (~279 Image.render
  copyPixels/tick into FP.buffer). This is the real baseline the perf-optimization
  arc must attack — NOT a browser-path bug. ***
ruffle: ~86-97 ms/frame (mean 86, p95 117) → ~11-12 fps. tick(avm) ~97 ms,
        render ~1 ms. (135 frames, real Windows GPU, 480x480, profiling build.)
verdict: *** RUFFLE IS ~2.5x FASTER THAN OURS on Seedling ***
        ours ~222 ms/frame (~4-5 fps) vs Ruffle ~90 ms/frame (~11-12 fps).
        BOTH are pure AVM/CPU-bound (render ~1-15 ms on each side) — so this is a
        clean interpreter-vs-recompiled AVM comparison, and our recompiled AS3 is
        LOSING to Ruffle's interpreter by ~2.5x. This is the opposite of the
        project thesis (recompile beats interpret) and is THE number the perf arc
        must close. (Both are below Seedling's 30fps target → the "unplayable in
        Ruffle" premise holds: Ruffle only manages ~12fps; we manage ~4-5.)
render-correctly: YES — our canvas paints the OverWorld CORRECTLY (house/grass/
        water/path/trees/player), confirmed by the user on real GPU. BUT it is a
        STATIC image: no fade-in, grass doesn't animate. Ruffle shows both.
```

## Render correctness (2026-07-13, user, real GPU): CORRECT + ANIMATING (just slow)
The Stage-9 Bitmap-blit compose is validated live on the real WebGPU surface — the
OverWorld renders correctly (matches the CPU-dump/oracle). **CORRECTION (user,
follow-up): the animation is NOT frozen — the grass Spritemap IS advancing, it's
just taking a few real seconds per animation frame because the game runs at
~3.6-5 fps.** So there is NO separate "animation not advancing" bug — it's the
SAME perf problem. The fade-in likewise just completes fast during the slow
warmup. `getTimer` advances correctly (~33 ms/tick via `run_due_timers` in
`avm2_display_run_tick`; `avm2_generated_frame_rate = 7680` = 30fps); the clock
was never the issue. **One problem, not two: fix the ~2.5x perf gap and the
animation runs at proper speed automatically.**

## UPDATE 2026-07-14 — self-service rig + same-harness A/B: ~6x SLOWER
Now measurable from WSL: headed Playwright drives the user's real-GPU Windows
Chrome via WSL→Windows interop (`WINDOWS_PLAYWRIGHT_FROM_WSL.md` +
`seedling_perf_win.py`) — no more paste-the-HUD. Both sides measured through the
SAME harness at real-GPU steady state (Intel Gen9, WebGPU adapter "intel / gen-9"):
- **Ours:   ~280 ms/frame (~3.6 fps)** — avm+submit ~264, present ~17.
- **Ruffle: ~46 ms/frame (~22 fps)** — tick ~45, render ~0.7.
→ **Ruffle is ~6x faster** (280/46). The earlier "~2.5x" used a warmup-inflated
Ruffle read (86 ms over 135 frames) vs our 222 ms; with both settled over the same
harness (Ruffle 600 frames → 46 ms) the honest gap is ~6x. Both AVM/CPU-bound
(render cheap on each). ANIMATION IS FINE (advances at the slow fps — one problem,
perf, not two). This is THE number to close.

## (SUPERSEDED by the ~6x same-harness read above) 2026-07-13: est. ~2.5x
The milestone A/B is done and the answer is humbling but precise: our recompiled
Seedling is **~2.5x slower** than Ruffle's interpreter, both AVM/CPU-bound. The
perf-optimization arc now has a concrete target and a reproducible rig. Where our
time goes (next-session profiling, real-GPU CDP + `--profiling-funcs`):
- The FlashPunk per-frame CPU software-buffer path: `Image.render` →
  `BitmapData.copyPixels` / `bd_draw` (avm2_bitmap.c) — is our native blit slower
  than Ruffle's Rust one? (~279 copyPixels/frame.)
- Recompiled AS3 method-dispatch / property-lookup overhead per FlashPunk op
  (the analog of the AVM1 `findOrCreateMovieClip`/property-name cluster).
Ruffle's split (tick 97 / render 1) says its render is ~free (1 GPU draw of the
buffer); ours present ~15 ms is also cheap — the whole gap is in the AVM tick.
**Next-session perf levers (AVM/CPU-bound, present cheap):** profile the AS3 tick
— the FlashPunk `Image.render`→`BitmapData.copyPixels`/`bd_draw` CPU blit hot path
(avm2_bitmap.c) and recompiled-method dispatch overhead. Real-GPU CDP profile of
`demo.html?test=avm2/seedling` is the tool (symbolicate via
`EMCC_CFLAGS=--profiling-funcs`).

## Liveness proof (WSL SwiftShader — correctness only, not perf)
Headless-Chrome smoke of `examples/avm2/seedling/smoke.html`: `runSWF_avm2` boots,
WebGPU device + textures OK, browser loop runs and feeds `__swfPerf` (8 frames).
One caught per-frame gameplay gap: `flash.geom.Rectangle.intersects` unimplemented
(Error #1069, non-fatal) — a 13c/correctness item, not a browser-path bug.
