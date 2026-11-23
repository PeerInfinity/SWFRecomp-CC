# s26 w1-trace-tail-audit: re-audit of every unowned failing graphics trace row

**New files:** this report, `w1-trace-tail-audit-prototype.patch` (one TU, `SWFModernRuntime/src/actionmodern/action.c`, +25/−13).

**Box and baseline.** Cloud box. Dawn and apt OK. Tests were downloaded at upstream Ruffle **`3e98d9ba6`**. Code is origin/master `ec07cc9e` (no runtime change since `697669e5f`).

**Fidelity.** All 39 audited rows were re-run in graphics mode with `--json`. **All 39 are byte-identical to the s26 baseline** (`9277f3799`): same status, same matched, expected and actual line counts. So local grading is CI-grade for this row set.

---

## 0. Verdicts first

| # | Verdict | Rows | Price | Yield |
|---|---|---|---|---|
| **P1** | **GO, FLIP (+1 pass, both modes)** | `from_gnash/misc-swfc.all/sound` | **S** (prototype, measured) | `output_mismatch` 7/7(+5) → **`pass` 7/7** |
| P2 | GO as a diff-line fix, no flip | `avm1/bitmap_data_thorough/pixelDissolve` | S (prototype, measured) | 1335 → **1351**/1371 (+16) |
| P3 | GO as a diff-line fix, no flip | `from_gnash/misc-swfc.all/matrix_accuracy_test1` | S (prototype, measured) | 10 → **12**/18 (+2) |
| — | Disposition refuted, verdict changes | `sound` (above) | — | the ACCEPTED "no audio simulation" story is wrong (§1) |
| — | Disposition text stale/wrong, verdict stands | `pixelDissolve`, `matrix_accuracy_test1`, `globals_swf5`, `bom`/`loader_load`, `eforin_001`, `argstest-v6/7/8`, `movieclip_hittest_shapeflag`, shumway `esc` | doc only | 0 |
| — | Standing NO-GO re-confirmed, same diff, same reason | the other 25 rows | — | 0 |

**Wave-2 recommendation:** land P1+P2+P3 as one slot. It is one TU and three local edits, and the rider sweep found 0 movers outside the ledger (§4). P1 is the only flip. P2 and P3 are Flash-exact against the graded oracle and cost nothing.

Wave 2 must also:
- prune `sound` from `from_gnash/misc-swfc.all/ignored_tests.txt`;
- mark the gnash `ACCEPTED_DIFFS.md` `sound` entry RESOLVED.

---

## 1. P1: `misc-swfc.all/sound` is a case-sensitivity bug, not audio (FLIP)

**Record of disposition:**
- misc-swfc `ignored_tests.txt` and gnash `ACCEPTED_DIFFS.md` ("sound (misc-swfc.all)") say: *"requires sound-position wall-clock simulation… Without audio playback our snd.position stays at 0, so we exit the loop immediately."*
- Board §26.4 does not list the row.

**Refutation.** The disposition contradicts itself. Frame 6's script is:

```
if (snd.position + 100 < snd.duration) gotoandPlay(5) else gotoandPlay(8)
```

With `position == 0` and `duration == 13740` (we print 13740 correctly, line 2), the condition is TRUE. So a faithful player loops forever, and the expected output's truncation at line 7 is exactly that: 30 ticks of looping.
- `test.toml` has no `known_failure`. Ruffle passes it, also with no audio clock.
- We fall through to `totals()` because the call is spelled **`gotoandPlay`** (lower-case `a`; constant-pool `str_154`) and dispatched by `CallFunction`.
- The SWF is **version 6**, so identifiers are case-insensitive. Flash and Ruffle resolve it to `gotoAndPlay`.
- Our `actionCallFunction` MC-navigation arm (`action.c:68014-68025` on origin/master) matches `gotoAndStop`/`gotoAndPlay`/`stop`/`play`/`prevFrame`/`nextFrame`/`getBytesLoaded`/`getBytesTotal`/`getDepth` with **case-sensitive `strncmp`**. So `gotoandPlay` is "not a function", the call is a no-op, and the playhead runs on to the totals frame.

**Prototype:** a local `_MC_NAV_NCMP` macro uses `strncasecmp` when `g_swf_version <= 6`, else `strncmp`. It is `#undef`'d after the arm.

**Measured:**
- `sound` is **PASS 7/7** in graphics and no-graphics (baseline `output_mismatch` 7/7 with 12 actual lines).
- Caveat: `g_swf_version` is the root movie's version. A SWF ≤ 6 child loaded into a SWF 7 root keeps root semantics, which is the same limitation as the existing `g_swf_version <= 6` gates in this file.

---

## 2. P2: `pixelDissolve`: the ACCEPTED mechanism is wrong; 16 of 36 lines are cheap

**Record:** ACCEPTED_DIFFS "`bitmap_data_thorough/pixelDissolve` — Flash-specific Feistel return value". It blames coercion of non-integer seeds (`null`, `undefined`, `valueOf`), plus "no Flash oracle".

**Refutation.** `output.txt` *is* the Flash oracle. Reading it block by block (transparent section, 2×2 effective region) gives the following.

**Plain integer seeds diverge too.** Seed 100 → 1 matches us, but:

| seed | Flash | ours |
|---|---|---|
| 0 | 2 | 1 |
| 2 | 1 | 3 |
| −1 | 2 | 0 |
| −2 | 1 | 3 |

Seed 10 → 3 matches. So this is not coercion.

**Flash returns `2` for a 4-pixel region.** Under Ruffle's trial-and-error 1-round Feistel (`operations.rs:1748`, which ours ports at `action.c:13786`), raw index 2 maps to Feistel index 0, which is always skipped. So `2` is **unreachable from any start index**.

Flash's permutation is a different function. Seeds 2 and 10 (≡ 2 mod 4) give different results, so it also keys on more than `seed mod 4`. A brute-force over 60 simple variants matched at most 7/11 data points:
- f ∈ {x²+1, x, x+1, x², 3x+1};
- perm base {4, 9, 16};
- signed/unsigned start;
- return raw or Feistel.

The remaining 20 lines need Flash's real permutation. That is **L / unknowable without many more Flash captures**, and the Ruffle exporter is no help because Ruffle's is the guess.

**Cheap sub-lead (P2, prototyped)**, from the same oracle:
- `numPixels == 0` (`null`/`undefined`/`{}`/`0`) → Flash **returns `randomSeed` unchanged** (100) and still writes pixel (0,0). We returned `seed % perm_len` = 0. That is 8 lines.
- `numPixels < 0` (−1, −2) → Flash **writes every pixel**, an unsigned count that gets clamped. We wrote only (0,0). That is 8 pixel-dump lines. The two return values on those blocks stay wrong; they are permutation lines.

**Edit** (`bitmapDataPixelDissolve`, `action.c:13876` / `:13926`):
- clamp `num_pixels < 0` to `seq_len`;
- return `random_seed` when `num_pixels == 0`.

**Measured:** 1335 → **1351**/1371, graphics and no-graphics. The AVM2 `bd_pixel_dissolve` (`avm2_bitmap.c:1782`) is untouched.

**Doc fix for wave 2:** rewrite the ACCEPTED mechanism as *"Flash's dissolve permutation is not Ruffle's guessed Feistel: plain integer seeds diverge too, and Flash returns indices our permutation cannot reach."*

---

## 3. P3: `matrix_accuracy_test1`: the oracle is Flash 10, not "Gnash's own output"

**Record:** gnash ACCEPTED Cat 4 and suite ignore. It says *"Gnash's own captured output disagrees with Flash… residual is off-by-one u32-wrap"*, gives the example `obtained "1073741824"`, and cites `incomplete/MATRIX_ACCURACY_TEST1_DECISION.md`.

**Refutation:**
- The graded file is `output.fp10.txt`. `verify_output.py` picks the highest `player_options.version`.
- Both `output.fp9.txt` and `output.fp10.txt` are **Flash captures** (Ruffle subtests per Flash version).
- FP9 passes all 15 assertions. FP10 fails 5 of gnash's assertions *in Flash itself*, so the `FAILED:` lines are Flash's real values, not Gnash's mistakes.
- The cited decision doc does not exist (dangling reference).
- The example diff is stale. s25's Matrix rounding moved our `_x` readback from `1073741824` to `107374182.35`.

**Mechanism for the `_x`/`_y` lines:**
- The script sets `mc1._x = 1073741823` (and `_y = 1073741568`), so the twips are ≈ 2.1e10, out of i32 range.
- FP9 wraps mod 2³² (−20 twips = −1 px, which passes).
- FP10 stores **INT32_MIN** (`-107374182.4`): the x86 `cvttsd2si` "integer indefinite", for positive overflow too.
- We follow Rust's saturating `as i32` (`spvTwipsTruncatePixels`, `action.c:16026`) and store INT32_MAX (`107374182.35`).

**Edit:** out of range on either side → `INT32_MIN`.

**Rider argument:**
- No corpus `output*.txt` contains `107374182.35`. No graded row expects positive saturation.
- Every `-107374182.4` row comes from ±Infinity or a negative overflow, and those paths are unchanged (`SPV_COORD_SENTINEL`).

**Measured:** 10 → **12**/18, graphics and no-graphics.

**Remaining 6 lines, a full flip is L:**
- `_xscale = 4294967295` reads back `4294967296`, because our scale is stored as `float`. Fixing it changes the storage type on `MovieClip` (M, wide).
- `_width`/`_height` `3276800`/`983040` are Flash 10's matrix internals at extreme scale. Unknown model; Ruffle panics on this row.

---

## 4. Rider sweep (P1+P2+P3 together, graphics, compared with baseline `results_graphics.json`)

**Selection:**
- **P1:** every corpus SWF of version ≤ 6, decompressed (all suites, `regression` included), whose bytes contain a case-variant of a nav name followed by NUL. The only true variant is `gotoandPlay` (sound). Most `Play`/`Stop` hits are suffixes of exact `gotoAndPlay`/`gotoAndStop`; I swept them all anyway. I added `case-v6`, `MovieClip-v5/v6` and the two `regression/avm1_attached_clip_goto_play*` rows.
- **P2:** every AVM1 `pixelDissolve` row.
- **P3:** every row whose expected output holds ±107374182, plus the `set_property_values` family and `movieclip_invalid_get_bounds_8`.

**Results (33 rows):**

| Row | Baseline | After |
|---|---|---|
| misc-swfc `sound` | output_mismatch 7/7 | **pass 7/7** |
| misc-swfc `matrix_accuracy_test1` | output_mismatch 10/18 | output_mismatch **12/18** |
| avm1 `bitmap_data_thorough/pixelDissolve` | output_mismatch 1335/1371 | output_mismatch **1351/1371** |
| misc-ming `callFunction_test` (rm 5/11), `key_event_test` (rm 61/66), `goto_frame_test` (pass), `action_execution_order_test8-v5/v6` (pass) | — | identical |
| misc-swfc `gotoFrameLabelAsFunction`, `opcode_guard_test2` (pass), `gotoFrameFromInterval2` (rm 5/23) | — | identical |
| gnash `Inheritance-v5/v6`, `MovieClip-v5/v6`, `setProperty-v5..v8` (all rm) | — | identical |
| gnash `case-v6` (pass 73/73) | — | identical |
| avm1 `set_property_values/swf4` (346/1571), `/swf5`, `/swf6`, `/swf7` (pass 1743), `bitmap_data_pixeldissolve` (pass 1075), `bitmap_data_pixeldissolve_image`, `movieclip_invalid_get_bounds_8`, `video_prototype_lazy_swf6_child` (4/8) | — | identical |
| regression `avm1_display_prop_coercion`, `avm1_attached_clip_goto_play`, `…_nonroot` (pass) | — | identical |
| misc-swfc `gotoFrameFromInterval` (CI-excluded, `ruffle-tests.yml:869`) | runtime_error (OOM-killed runaway) **before** too, measured A/B | identical |

**0 movers outside the ledger, 0 pass→ruffle_matched.**

**Mode parity:** `sound` PASS, `matrix_accuracy_test1` 12/18 and `pixelDissolve` 1351/1371 in no-graphics too. No `NO_GRAPHICS` arm is touched.

**CI to dispatch:** graphics with `categories=all`. Everything in the patch is AVM1, and from_gnash is in `all`.

---

## 5. The audit table (39 rows; "now" = today's graphics run, identical to the baseline for every row)

Positional `matched/expected (actual)`. "Still true?" asks whether the recorded reason describes today's diff.

| Row | Now | Disposition of record | Still true? | Verdict | Price |
|---|---|---|---|---|---|
| avm1 `bitmap_data_thorough/pixelDissolve` | 1335/1371 | ACCEPTED (Feistel/coercion) + root ignore | **No**: integer seeds diverge too; 16 lines are numPixels 0/neg semantics | P2 GO (+16); the rest NO-GO | S / L |
| avm1 `date` | 6289/6335 | ACCEPTED + ignore | Yes: ±Infinity components, `-8.64e15` UTCHours, fractional TZ offset | NO-GO | — |
| avm1 `external_interface_monkeypatch` | 4/139 (65) | §26.4 NO-GO | Yes | NO-GO | — |
| avm1 `global_instance_decls` | 17/758 (734) | §26.4 NO-GO, RvF | Yes | NO-GO | — |
| avm1 `global_proto_decls` | 50/4562 (3865) | §26.4 NO-GO, RvF | Yes | NO-GO | — |
| avm1 `global_proto_decls_delete` | 461/4158 (2371) | §26.4 NO-GO, RvF | Yes | NO-GO | — |
| avm1 `globals_monkeypatch` | 49/306 (222) | §26.4 NO-GO (KF) | Yes | NO-GO | — |
| avm1 `globals_swf5` | 294/304 | RvF "SWF5 constructor visibility" + ignore | **No, as s24 §3 already showed; still uncorrected**: `output.ruffle.txt` = `output.txt` except line 136, so Flash shows LocalConnection/NetConnection/Video **visible**; the doc's "295/304, 9 lines" was never the count (10 lines since at least s18) | NO-GO stands (un-hiding demotes 3 gnash `-v5` passes to rm); doc fix only | doc |
| avm1 `movieclip_hittest_shapeflag` | 332/338 | ACCEPTED Cat 8 (9 lines) + ignore | Partly: same class, but **6** lines (71, 171–177, 296), not 9; still uncorrected since s24 | NO-GO | doc |
| avm1 `native_objects_swf6` | 114/115 | ACCEPTED (line 56 `new TextField()`) | Yes, same single line | NO-GO | — |
| avm1 `sandbox_type_remote` | 1/3 | root ignore (localhost child mapping + per-movie sandbox) | Yes | HOLD M (unchanged) | M |
| avm1 `set_property_values/swf4` (KF) | 346/1571 (1743) | user ruling 2026-09-29 (RvF §SWF4 correction; arc §22.5): match Flash | Yes: block 1 is `Warning: Object is not a function` / `0` vs our `valueOf` / `2` (SWF4 has no `Object` ctor), plus `"10x"` abandon and the 16.16 `_xscale` | NO-GO until the Flash-exact SWF4 setProperty arc | L |
| avm2 `avm1_root` (KF) | 12/58 (34) | RvF "temporal attachment state" | Yes | NO-GO | — |
| avm2 `bom` | 6/9 | RvF "hashbrown order; we and Flash use insertion order" | **Partly**: not KF (Ruffle passes), and avmplus itself is hash-ordered (see eforin), so "Flash = insertion" is unsupported | NO-GO (hashbrown+FNV emulation, corpus-wide for-in rider risk) | L |
| avm2 `dependent_strings` | 46/84 (83) | RvF `ruffle::isDependent()` hook | Yes | NO-GO | — |
| avm2 `loader_applicationDomain` | 0/4 (0) | ACCEPTED Cat 13 (Flex `.swz` under AOT) | Yes | NO-GO (AOT ceiling) | — |
| avm2 `loader_load` | 126/128 | RvF hashbrown order | Partly (same as `bom`) | NO-GO | L |
| avm2 `number_tostring` | 882/1050 | ACCEPTED Cat 14 + upstream `ignore = true` | Yes, the ceiling holds. Of 168 lines, 31 are corrupt; the other 137 are avmplus's lossy radix printer (exact base-3 is 41 digits, Flash prints 40) | NO-GO (0 flips even if ported) | — |
| avm2 `sandbox_type_remote` | 1/3 | avm2 ignore (same two mechanisms) | Yes | HOLD M | M |
| avm2 `swz` | 0/2 (0) | ACCEPTED Cat 13 | Yes | NO-GO | — |
| avm2 `verify_method_info_duplicate` (KF) | 1/2 | ACCEPTED Cat 2 | Yes, the missing trailing `#1065` | NO-GO | — |
| avmplus `eforin_001` (KF) | 12/16 | ACCEPTED Cat 12 | Verdict yes; wording no: ours prints `0, year, company, length` for literal `{length, company, year, 0}`, which is AVM2 `newobject`'s reverse-push insertion order, not source order | NO-GO | doc |
| avmplus `eforin_002` | 0/10 | ACCEPTED Cat 12 | Yes | NO-GO | — |
| gnash `argstest-v6` / `-v7` / `-v8` (KF) | 84/2192, 78/2061, 121/2434 (2644, 2644, 3006) | ACCEPTED Cat 3 + suite ignore | Mechanism yes (native-object enumeration, e.g. PrintJob lists `toString`/`__constructor__` where Flash lists `send/addPage/start`); **numbers stale**: the ignore entry says actual 7731/7731/8093 | NO-GO | doc |
| gnash `GradientFillTest` | 123/278 | §26.4 NO-GO | Yes (gradient sample colours, e.g. `0xb0bff` vs `0xd0dff`) | NO-GO | — |
| gnash `action_order/ActionOrderTest3` | 4/62 (83) | §26.4 NO-GO | Yes | NO-GO | — |
| gnash `action_order/ActionOrderTest4` | 10/64 (94) | §26.4 NO-GO | Yes | NO-GO | — |
| gnash `action_order/ActionOrderTest5` | 6/51 (58) | §26.4 NO-GO | Yes | NO-GO | — |
| gnash `action_order/PlaceAndRemove` | 15/96 (45) | §26.4 NO-GO | Yes | NO-GO | — |
| gnash `action_order/action_execution_order_extend_test` | 7/32 (28) | §26.4 NO-GO | Yes | NO-GO | — |
| gnash `action_order/action_execution_order_test11` | 26/32 | §26.4 NO-GO | Yes | NO-GO | — |
| gnash `register_class/RegisterClassTest4` (KF) | 7/42 (54) | ACCEPTED + suite ignore | Yes (load/ctor ordering) | NO-GO | — |
| gnash `matrix_accuracy_test1` | 10/18 | ACCEPTED Cat 4 + suite ignore | **No**: the oracle is Flash 10, not Gnash; the example is stale; the decision doc is missing | P3 GO (+2); the rest NO-GO | S / L |
| gnash `sound` | 7/7 (12) | ACCEPTED + suite ignore ("no audio") | **No**: `gotoandPlay` case-sensitivity | **P1 FLIP** | S |
| shumway `bitmapdata/getpixel-from-embedded` | 1/2 | s19/s20 "a disposition, not a fix" (JPEG decoder parity `200d04` vs `220a06`) | Yes, but there is still **no ACCEPTED entry and no ignore entry** (s24 recommended one) | NO-GO | doc |
| shumway `esc` | 0/2 (13) | suite ignore, no per-name reason; s24/§26.4 "AVM2 #1009 runtime_error" | Shape yes; **pricing wrong**: the test compiles `trace('hello, world!')` with ESC at runtime and `loadBytes`es the ABC (`RecompiledABC/abc22_*`), so line 2 is an AOT ceiling (Cat 13 class). The #1009 fix caps at 1/2, no flip | NO-GO (row); the #1009 is a robustness lead | — |
| mixed_avm `avm1_loads_avm2` | 3/7 | s22 `w1-crossvm` §4.3 NO-GO (AVM1-parent → AVM2-child arc) | Yes, the 4 AVM2-side lines are missing | NO-GO | L |
| *(owned by siblings: `file_reference_upload_request` → w1-drift, `video_prototype_lazy_swf6_child` → w1-per-movie-displaylist; not run, except `video_prototype_lazy_swf6_child` as a P1 rider, unchanged 4/8)* | | | | | |

---

## 6. Doc corrections for the coordinator (no source change)

1. **gnash `ACCEPTED_DIFFS.md` `sound`:** mark RESOLVED by P1 and prune the misc-swfc ignore entry (on landing).
2. **avm1 `ACCEPTED_DIFFS.md` `pixelDissolve`:** fix the mechanism (§2), and record the numPixels 0/negative semantics as fixed by P2.
3. **gnash `ACCEPTED_DIFFS.md` Cat 4 `matrix_accuracy_test1`:** the oracle is Flash 10 (fp9 = Flash 9, all pass). Update the example and the residual, and drop the dangling `MATRIX_ACCURACY_TEST1_DECISION.md` reference.
4. **RvF "SWF5 Constructor Visibility" (`globals_swf5`):** apply s24 §3's correction (Flash's capture shows them visible; we follow gnash `-v5` to keep 3 KF passes). The count is 294/304, 10 lines.
5. **ACCEPTED Cat 8 `movieclip_hittest_shapeflag`:** 6 lines, not 9 (s24 lead 3, still open).
6. **RvF hashbrown entry (`bom`, `loader_load`):** drop "we and Flash use insertion order". Neither row is KF, and avmplus order is pointer-hashed.
7. **Cat 12 (`eforin_001`):** our string-key order is AVM2 `newobject` insertion order (last pair first), not source order.
8. **actionscript.all `ignored_tests.txt` argstest:** actual line counts are now 2644/2644/3006.
9. **shumway `esc`:** give it a per-name reason: "runtime ESC compile + `loadBytes` of generated ABC: AOT ceiling (Cat 13 class)". `getpixel-from-embedded`: add the ACCEPTED entry s24 recommended (JPEG decoder parity).

## New unclaimed leads

- **`esc` #1009** (`Util::Hashtable/makeTable()` ← `Util::Hashtable()` ← `global$init()`; `RecompiledABC/abc1_methods.c` `abc1_m21`, the first op `FindPropStrict {ns-set 4}::Array` → `GetPropertyStatic` → `Construct`). It is a null deref in a script-init class constructor. It flips nothing (the row is AOT-capped). It's a runtime-robustness probe (M, unpriced) for w1-runtime-robustness if it wants an AVM2 script-init case.
- **`gotoFrameFromInterval` (misc-swfc, CI-excluded):** grows memory until the kernel OOM-kills it locally, in ~17 s, both before and after the patch. CI excludes it as a 30 s runaway, but a test that exhausts memory is a robustness signal. Worth a heap cap or diagnosis in the robustness slot.
- **Other case-sensitive dispatch arms:** P1 fixes only the `actionCallFunction` nav arm. A grep for exact `strncmp`/`strcmp` on builtin method names in other CallFunction/CallMethod arms would show whether SWF ≤ 6 case-insensitivity is missing elsewhere. The corpus has no other variant spelling (scan in §4), so it is game-exposure only.
- **avmplus radix printer** (`number_tostring`'s 137 non-corrupt lines). It is portable from Tamarin `MathUtils::convertDoubleToString`. 0 flips here; only worth it if another row needs it.

## LOCAL ORACLE REQUESTS

None. Every lead here grades against Flash captures already in the corpus, and the Ruffle exporter would not help: `sound` already passes in Ruffle, and pixelDissolve's Ruffle permutation is the guess being refuted.
