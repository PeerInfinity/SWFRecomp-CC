# Wave-1 trace-axis triage — session 11 (regenerated at `b4c983ea4`)

Read-only. No source edits, no git state changes. Scratch:
`scratchpad/{near_pass.py, moved.py, near.json, all_fail.json, jobs/*.txt}`.

Data: the 19 top-level leaf `results_graphics.json` (the five nested
`_results` — `from_avmplus/as3/Vector[/nonindexproperty]`,
`from_gnash/misc-ming.all/displaylist_depths`, `from_shumway/{avm1,timeline}`
— excluded as double-counts). All 19 carry `git_sha = c4496a4c8`, total
**4424**, `pass 3942 + ruffle_matched 246 = 4188 (94.7 %)` — exactly the
stated baseline, so the board below is the real current tree.

---

## (a) The board, and how it moved

| | s9 in | s10 in | **s11 in (now)** |
|---|---|---|---|
| near-pass candidates (gap = expected−matching ≤ 5) | 78 | 59 | **49** |
| total non-`pass`/`ruffle_matched` | 248 | 248 | **236** |
| status histogram | — | `output_mismatch 246`, `runtime_error 1`, `recomp_fail 1` | `output_mismatch 235`, **`runtime_error 1`**, **`recomp_fail 0`** |

Per suite (49): avm2 20 · from_shumway 9 · avm1 6 · mixed_avm 5 ·
from_avmplus 4 · audio/fonts/text/visual/`from_gnash misc-swfc.all` 1 each.
Gap histogram `0:6 1:15 2:12 3:5 4:8 5:5`. Shoulder: gap 6–10 = **37**,
11–20 = **32**, > 20 = **118**. No failure lacks line counts.

### Exact snapshot diff `feb8882b0` → `c4496a4c8` (`moved.py`)

12 flips, **0 regressions, 0 tests added/removed, 0 gap moves among the
still-failing near rows.** Nine of the twelve were inside the ≤5 window
(58 → 49); the other three were shoulder/`recomp_fail` rows
(`statictext_text` gap 8, `getobjectsunderpoint` gap 22 → `ruffle_matched`,
`heavy_tesselation` `recomp_fail`).

```
output_mismatch 8 -> pass         avm2/statictext_text
output_mismatch 4 -> pass         avm2/stylesheet_parse_color
output_mismatch 3 -> pass         avm2/stylesheet_transform
output_mismatch 4 -> pass         avm2/subclass_superclass_linked_symbol
output_mismatch 1 -> pass         from_avmplus/as3/RuntimeErrors/Error1081ReadSealedErrorNs
output_mismatch 3 -> pass         from_avmplus/e4x/Statements/e12_1
output_mismatch 4 -> ruffle_matched  from_avmplus/ecma3/Number/toLocaleString_rt
output_mismatch 1 -> pass         from_shumway/acid/acid-text-2
output_mismatch 22 -> ruffle_matched from_shumway/getobjectsunderpoint
output_mismatch 2 -> pass         from_shumway/hittesting/hittesting
output_mismatch 0 -> pass         mixed_avm/avm1_loads_avm2_doaction
recomp_fail     -> pass           visual/simple_shapes/heavy_tesselation
```

**Refill into the ≤5 window: exactly ZERO rows.** Third consecutive session
at zero (s9 0, s10 0, s11 0).

---

## (b) Premise verdicts

| Premise | Verdict | Evidence |
|---|---|---|
| "The near-pass well is a CLOSED inventory" | **CONFIRMED, hardened** | `moved.py` shows the window shrank by *exactly* the 9 in-window flips. Zero rows entered from the shoulder, zero gap moves. Three sessions of zero refill; this is now a measured invariant, not an inference. |
| "~59 candidates, ~45 live after s10" | **CONFIRMED with a correction** | 49 in-window rows now; **15** are dispositioned (see below), so the **live pool is 34**, not 45. The delta vs the s10 brief is 9 flips + `eforin_001` newly dispositioned in `from_avmplus/ignored_tests.txt`. |
| "results.json truncates outputs, long diffs need a local re-run" | **CONFIRMED** | Not a blocker here — 32 of the 33 live rows have ≤8 expected lines. |
| "runtime_error is the cheapest triage axis" | **CONFIRMED but EXHAUSTED** | The whole corpus has **one** `runtime_error` (`from_avmplus/regress/bug_483783`) and it is already scoped to the GC arc (s10 w2-taxonomy §B7: the GC-retry probe is use-after-free by construction). The `recomp_fail` bucket is now **empty**. This axis yields nothing further. |
| "`ignored_tests.txt` is massively stale (249 entries, s9 §10.4)" | **REFUTED — fixed in s10** | Re-measured: avm2 51 entries / **1** genuine full-pass (`bytearray_oom`), from_shumway 22 / 0, from_avmplus 2 / 0, gnash 7 / 0, global 26 / 1 (`netstream_play_flv_screen`). The other 29 "stale-looking" rows are `ruffle_matched`, which is a *legitimate* ignore-list outcome. Residual hygiene: 2 phantom global entries (`shared_object`, `shared_object_self_ref`) exist in no results file — same as s9, still unfixed. |
| s10 §11.2's "PerspectiveProjectionClass was NOT an oracle conflict" | **CONFIRMED** | Still `output_mismatch` gap 4; test.toml tolerance covers the `focalLength` double. Live. |

---

## (c) Dispositioned out of the 49 — DO NOT TARGET (15 rows)

Declared (ignore lists / the four disposition docs):
`avm1/{geturl, native_objects_swf6, sandbox_type_remote}`,
`avm2/{sandbox_type_remote, bitmapdata_draw_alpha_erase, netstream_flv_date,
sound_constructor_with_args, sound_rootless}`, `avm2/{bom, loader_load}`
(RUFFLE_VS_FLASH ceilings), `from_avmplus/ecma3/Statements/eforin_001`
(**new in s10**, `from_avmplus/ignored_tests.txt`),
`from_avmplus/recursion/pcre_find_fixedlength` (documented libregexp
ceiling), `from_shumway/{esc, fuzz/f404…}`,
`from_gnash/misc-swfc.all/sound`.

### NEW: two rows carry an *undeclared* won't-do from a prior arc

Both were listed as live loader-cluster candidates in the s9 board. They are
not in any ignore list nor in the four disposition docs, but
`avm2/_investigation/CURRENT_STATUS.md:476` and `loader-arc.md`'s tranche-6
scoreboard already record them as **won't-do**:

- **`avm2/loader_applicationDomain`** (gap 4) — "won't-do — needs the real
  Flex `framework_*.swz`". Confirmed by reading `Test.as`: it `URLLoader`s a
  4.5 MB Flex RSL and `getDefinitionByName`s `mx.events.PropertyChangeEvent`
  out of it. Our AOT model cannot execute an ABC that was never recompiled.
- **`avm2/swz`** (gap 2) — same `framework_4.5.0.20967.swz`, same
  `getDefinition("mx.core.ByteArrayAsset")`. Not named in that scoreboard but
  identical in kind.

→ **Both should be added to `avm2/ignored_tests.txt` + a disposition doc**
so the next board stops re-costing them. **Live pool after this: 32.**

---

## (d) The keys that were run over the CURRENT 236 failures

1. **`runtime_error` / `recomp_fail` axis** (cheapest, first) — 1 row, already
   arc-scoped. Dry.
2. **Diff-SHAPE key** (new this session, and it paid):
   `A_extra_only` (matching == expected, we emit MORE) **4**;
   `B_truncated` (matching == actual, we stop short) **25**;
   `C_substitution` (actual == expected, wrong values) **70**;
   `D_mixed` **137**. `A_extra_only` is exactly the shape of s10's B5 win
   (`avm1_loads_avm2_doaction`), and it is a 4-row closed set.
3. **Zero-output axis** — 11 tests emit *nothing* at all. 6 are in the near
   window. Split cleanly into (i) tests whose only expected line is a success
   assertion that legitimately never fires (`links_in_scrolled_text`,
   `bug1157243/*`) and (ii) hard early aborts (`loader_applicationDomain`,
   `swz`, `selection_onsetfocus_mixed_avm`).
4. **Capability-gap × oracle-conflict** (s10's paying key) — re-run; found
   the two won't-do rows in §(c) and one real conflict in §(e) B1.
5. Confirmed dry again, do not re-mine: `error_signature` Counter,
   same-index error-code substitution census, namespace-half,
   runtime-name-half.

---

## (e) Ranked wave-2 batch proposals

Ranked by yield ÷ effort × confidence. All were re-verified at HEAD by a
single local `verify_output.py --test=… --diff` run (no-graphics; mode parity
is complete, and every line count matched the graphics baseline).

---

### B1 — Malformed/empty sibling SWF must raise IOError #2124 ★ TOP PICK
- **Tests:** `from_shumway/as3-loader/bug1157243/empty` (gap 1),
  `from_shumway/as3-loader/bug1157243/invalid` (gap 1). 2 tests, 2 lines,
  **2 full passes**.
- **Current diff (both):** expected `true`, actual **nothing at all**.
- **Mechanism — DIAGNOSED end to end.** The ABC (`--dump-abc`) shows the
  SWF registers `IOErrorEvent.IO_ERROR` on `contentLoaderInfo`, `load`s
  `empty.swf` / `invalid.swf`, and traces
  `e.text.search("Loaded file is an unknown type") != -1`. The runtime
  already has the whole #2124 path
  (`avm2_display.c:5507-5533 loader_deliver`, `LI_CT_UNKNOWN` arm). It never
  runs because the file never resolves:
  - `verify_output.py:1777 skip_suffixes` excludes `.swf` from the data-file
    registry, so `findDataFile` misses;
  - `verify_output.py:2184` only emits a `MovieEntry` when
    `recompile_child_swf()` **succeeds** — and a 0-byte / 30-byte-garbage
    "SWF" cannot be recompiled, so no entry exists;
  - `avm2_display.c:5731 loader_resolve_url` therefore returns 0, and its own
    comment says the load then "stays silent".
  Note also `avm2_display.c:5754` hard-codes `out->content_type = LI_CT_SWF`
  for any `MovieEntry` — so even with an entry the sniff must be made
  conditional on the raw bytes.
- **Fix shape:** emit a minimal `MovieEntry` (filename + `file_size` +
  `raw_bytes`, NULL frame_funcs/init_func) when child recompilation fails,
  and make `loader_resolve_url` sniff `m->raw_bytes` instead of assuming SWF.
- **ORACLE CONFLICT — the one real trap on this board.** The corpus contains
  exactly **4** `.swf` files without an `FWS`/`CWS`/`ZWS` header: the two
  above, plus `avm1/movieclip_state_values/no correct file (text).swf` and
  `… (image).swf`. `avm1/movieclip_state_values` is **currently PASSING**
  and pins the opposite for the text file: `getBytesTotal() = -1`,
  `getSWFVersion() = -1`, i.e. the AVM1 `loadMovie` must keep **failing**.
  `findDataFile` is consumed by AVM1 in eight places in `action.c`
  (2194/3647/19534/23719/34650/34678/38178/47622), so the naïve
  "bundle bad .swf as a data file" fix WILL move it. **Mandatory canary:
  `avm1/movieclip_state_values`.** Prefer the MovieEntry route (AVM2-only)
  over the data-file route.
- **Yield:** +2. **Effort:** S–M. **Confidence: HIGH** on the mechanism,
  MED on the blast radius (hence the canary).
- **Dispositions:** neither test in any ignore list or disposition doc; the
  `bug1157243` name matched a doc grep only via the generic words
  "empty"/"invalid" (false positive — verified).

---

### B2 — ABC verifier: method_info association rules (`#1107` / `#1034`)
- **Tests:** `avm2/method_association` (gap 4), `avm2/verify_method_info_duplicate`
  (gap 1). 2 tests, 5 lines.
- **Current diffs.**
  `method_association`: expected `1107 / 1107 / 1034 / Passed / Passed`;
  actual `Passed / Passed / Passed / Passed`.
  `verify_method_info_duplicate`: line 1 (`VerifyError: Error #1121: Method
  Test/hello() has a duplicate method body.`) already **matches**; the
  trailing `ReferenceError: Error #1065: Variable Test is not defined.` is
  missing (we stop after 1 line).
- **Mechanism — DIAGNOSED from `--dump-abc`.** The four probes each trace
  `e.errorID` (only the CODE matters, not the message text):
  - `test1` = `NewFunction method[1]` where `method[1]` **is** the
    trait-bound `Test/test1` → avmplus: newfunction on a method_info that
    already has declaring traits is **#1107**.
  - `test2` = `PushNull; CallStatic method[4]` where `method[4]` is the free
    `<anon>` that `test4` legitimately `NewFunction`s → callstatic on a
    method_info with **no** declaring traits is **#1107**.
  - `test3` = `NewObject pairs=0; CallStatic method[1] "Test/test1"` —
    callstatic on a trait-bound method is legal, but the `{}` receiver must
    coerce to `Test` → **#1034 at runtime**.
  - `test4` = `NewFunction method[4]` twice from one site → legal, `Passed`.
  So the rule set is: *newfunction requires an UNassociated method_info;
  callstatic requires an ASSOCIATED one; callstatic's receiver coerces to the
  declaring class.* That is self-consistent across all four probes.
- **Machinery already exists.** `abc_verifier.cpp:41 fail(err, code, detail)`
  already carries the numeric code, and `abc_emit.cpp:2377` already emits a
  per-body `avm2_verify_error_body(act, "…")` stub — which is exactly the
  deferred, per-method, catchable form these probes need.
- **Files:** `SWFRecomp/src/abc/abc_verifier.cpp` (association bookkeeping in
  `validateAbcFile` / `verifyMethodBody`), `abc_emit.cpp` (per-body stub is
  already wired), plus the #1034 receiver coercion on the CallStatic path.
  The `#1065` half of `verify_method_info_duplicate` is the "class failed to
  define ⇒ the SymbolClass binding reports #1065" follow-on.
- **Recompiler change ⇒ manual cmake rebuild + a broad local `--recompile`
  sweep before CI** (memory `parallel-triage`), and this is a
  `categories=full` reason (the whole `from_avmplus` corpus is verifier
  traffic).
- **Yield:** +2 (5 lines). **Effort:** M. **Confidence: MED-HIGH** on
  `method_association`, **MED** on the `#1065` half.
- **Ruffle reachability:** `verify_method_info_duplicate` ships an
  `output.ruffle.txt` that differs from `output.txt` on line 1 only (Ruffle
  says #1107 where Flash says #1121). We already match Flash's #1121, so the
  fix scores a **full pass**, strictly better than `ruffle_matched`.
- **Dispositions:** neither test in any doc or ignore list. Oracle grep:
  `Error #1107` / `Error #1121` appear in expected output of only
  `avm2/error_geterrormessage` (a message-table dump, unaffected) and these
  two tests.

---

### B3 — Three XS singles with one-line pins (bundle them; ~1 h total)

Give all three to one agent as one commit each — they share no code, only
their size.

**B3a — `<!DocType>` must be case-insensitive.**
`from_avmplus/regress/bug_550958` (gap 1, +2 extra lines). The test is
literally titled *"XML parse !DOCTYPE case insensitive"*: `new XML("<!DOCTYPE
HTML>")` and `new XML("<!doctype html>")` pass, `new XML("<!DocType html>")`
throws `TypeError: Error #1090: XML parser failure: element is malformed.`
**Pin: `SWFModernRuntime/src/avm2/avm2_e4x.c:2044` —
`starts_with(&ps, "<!DOCTYPE") || starts_with(&ps, "<!doctype")`.** Needs a
case-insensitive compare (and `ps.pos += 9` stays correct). Check the second
parser too (`avm2_xml.c:2906 XN_DOCTYPE`). Oracle: `Error #1090` appears in
only 3 expected outputs (`error_geterrormessage`, `xml_list_ctor_errors`,
`xml_ctor_from_tostring`) — none constrains DOCTYPE casing.
**Yield +1. Effort XS. Confidence HIGH.**

**B3b — `constructsuper` on a null/undefined receiver must throw #1009.**
`avm2/constructsuper_null` (gap 2). ABC: `PushNull; Coerce Test;
ConstructSuper args=0` inside a try/catch that traces `e.errorID`; expected
`1009` + `undefined.super() errored`, actual `This shouldn't be traced!` ×2.
**Pin: `SWFModernRuntime/src/avm2/avm2_ops.c:3523 avm2_op_constructsuper`** —
it checks `act->bound_class == NULL` (script-init arm, must stay) and
`recv.kind == AVM2_VALUE_OBJECT` only on the `native_super_init` branch; the
general `avm2_call_method_ref` path takes a null `recv` silently. Add the
null/undefined guard **after** the `bound_class == NULL` early return.
Oracle: only this test's `output.txt` mentions `undefined.super()`.
**Yield +1. Effort XS. Confidence HIGH.**

**B3c — `flash.system.System.exit` must exist and throw SecurityError #2017.**
`avm2/system_exit` (gap 3). `Test.as` is 8 lines:
`try { System.exit(0) } catch (e:*) { trace(e.getStackTrace()) }`. Expected
is the 3-line stack
`SecurityError: Error #2017: Only trusted local files may cause the Flash
Player to exit.` / `\tat flash.system::System$/exit()` / `\tat Test()`;
we give `TypeError: Error #1006: exit is not a function.` / `\tat Test()`.
So: register a static `System.exit` that unconditionally throws #2017, and
make sure its own frame appears in `getStackTrace()` as
`flash.system::System$/exit()`. #2017 is already in `avm2_error.c`'s table
neighbourhood; `Error #2017` appears in only two expected outputs
(this test + `error_geterrormessage`'s message dump) — no conflict.
**Yield +1. Effort S** (the stack-frame line is the only unknown; if the
static-method frame does not render, this becomes MED). **Confidence MED-HIGH.**

---

### B4 — `removeMovieClip` must cancel a pending load
- **Tests:** `avm1/load_cancel_via_removemovieclip` (gap **0** — all 4
  expected lines already match; we emit 4 *extra*).
- **Current diff:** after the 4 correct lines we additionally print
  `MovieClipLoader.onLoadStart` / ` - this should not trace!` /
  `MovieClipLoader.onLoadInit` / ` - this should not trace!`.
- **Mechanism — well localised.** Loads are queued as `PendingMCLLoad`
  (`action.c` ~34590) and drained by
  **`action.c:34617 actionFirePendingLoadInits`**, whose only guard is
  `loads[i].target != NULL`. A clip removed by `removeMovieClip` between
  queue and drain is marked *destroyed* (`depth == INT_MIN`, see the comments
  at `action.c:20102` and `:23243`) but is not NULL, so the whole
  onLoadStart/Progress/Complete/Init sequence still fires. Add a
  destroyed-target check that drops the entry entirely (not just skips the
  handler) — this is the AVM1 twin of s10's B5 suppression half.
- **Yield:** +1. **Effort:** S. **Confidence: MED-HIGH.**
- **Dispositions:** not in any doc/ignore list.
  `avm1/_investigation/NEW_UPSTREAM_AVM1_TRIAGE.md:90` triages it as
  "loadMovie cancel lifecycle … likely tied to the multi-SWF load path" —
  a triage note, **not** a disposition; the diff shape (extra lines only,
  zero missing) shows the multi-SWF half already works.
- **Blast radius:** the `mcl_*` / `loadmovie_*` families. Canary those.

---

### B5 — API-version gate on `flash.events.Event`'s worker constants
- **Tests:** `avm2/cross_api_version_call_newer` (gap 1 — 11/12 lines already
  match; this is the residual of a loader-arc tranche-6 rider that went
  0/12 → 11/12).
- **Current diff:** line 1 expected
  `Initialized Newer with parent: null Event = undefined`, actual
  `… Event = workerState`.
- **Mechanism.** `newer/com/ruffle/Newer.as` reads `Event["WORKER_STATE"]`.
  The child SWF is version **43**, the root is version **12**; Flash gates
  API surface on the **root** movie's version, so the constant must be
  absent. **Pin: `SWFModernRuntime/src/avm2/avm2_events.c:1955`** — the
  `consts[]` table registers `CHANNEL_MESSAGE` / `CHANNEL_STATE` /
  `WORKER_STATE` unconditionally at :1957-1962. The gating idiom already
  exists in this exact shape (`avm2_number.c:636`
  `if (ctx->swf_version >= 16) add_number_statics(...)`;
  `avm2_globals.c:3770` for JSON at 13). Gate the worker trio at
  `ctx->swf_version >= 18`.
- **Yield:** +1. **Effort:** XS. **Confidence: MED** (the exact gate version
  and whether other constants in the same table need it are unverified —
  check `cross_api_version_call_older`, which currently **passes**, as the
  canary).
- **Dispositions:** none. See memory `version-gate-new-api-surface`.

---

### B6 — MorphShape `hitTestPoint(shapeFlag = true)`
- **Tests:** `from_shumway/acid/acid-morph` (gap 2).
- **Current diff:** expected `true false false true false false`, actual
  `true false true false false false` — lines 3 and 4 are transposed.
- **Mechanism — suspected, narrow.** The ABC does
  `morph.hitTestPoint(100,100,true)` and `morph.hitTestPoint(300,300,true)`
  from an `onFrameConstructed` handler over 30 frames. Two probes disagree in
  a way consistent with the shape-level test using the **start** outline
  rather than the outline interpolated at the current `ratio`, i.e. the hit
  geometry lags the rendered geometry by the morph phase.
- **Yield:** +1. **Effort:** M. **Confidence: MED.**
- **Note:** this test also carries `[[image_comparisons]]` — it is on the
  pixel board too, so a correct fix may be worth more than +1 trace.
- **Dispositions:** none.

---

### B7 — `PerspectiveProjection` clone + root defaults (≈2 mechanisms)
- **Tests:** `from_shumway/avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass`
  (gap 4). Confirmed **live** — s10 refuted the s9 "oracle conflict" call
  (test.toml tolerance covers the `focalLength` double), and the run at HEAD
  agrees: the two `focalLength` lines now MATCH.
- **Current diff (4 lines, 3 mechanisms):**
  - `perspectiveProjection returns a clone: true` → we say `false`
    (the getter must return a copy, not the live object);
  - `Initial root projectionCenter: (x=250, y=187.5)` → we say `(250, 250)`
    (root default centre is stage **height**/2 for y, we use width/2);
  - `changed root fieldOfView: 100` / `changed root focalLength:
    209.7749077943` → we say `55` / `480.2455444336` (a write through the
    returned object must persist back onto the root's transform — the
    write-back half of the clone semantics).
- **Yield:** +1. **Effort:** M. **Confidence: MED.** Listed on §11.3.

---

### Carried from the s10 §11.3 board, unchanged and still live
`avm2/graphic_linkage` (gap 2 — script-`new` vs timeline instantiation
discriminator in `display_native_init`; diff is `my shape: 0 / 0` vs our
`40.35 / 40.35`, i.e. a script-constructed clip must NOT instantiate its
linked Graphic child) · `avm2/doabc_and_symbolclass_script_init_normal`
(gap 5, + rider `…_goto` gap 6 — lazy script inits, `C,Z,B` not `Z,C,B`,
rewrite of the step-3/4 contract) · `fonts/device_font_kerning` (gap 4,
`LM width: 50` vs `23`; + riders `device_font_glyph_fallback` gap 7,
`device_font_list` gap 58 — B9, **scope first**) ·
`from_avmplus/regress/bug_483783` (the corpus's only `runtime_error` →
the GC arc, do NOT re-file as polish).

---

## (f) Explicit DO-NOT-TAKE list for wave 2

| Test(s) | Why |
|---|---|
| `avm2/loader_applicationDomain`, `avm2/swz` | **NEW this session** — undeclared won't-do; both need the real Flex `framework_4.5.0.20967.swz` executed. `avm2/_investigation/CURRENT_STATUS.md:476`, `loader-arc.md` tranche-6 scoreboard. Should be added to `avm2/ignored_tests.txt`. |
| `mixed_avm/{avm1_loads_avm2, avm2_loads_avm1_doabc, avm2_loads_avm1_loads_avm2_doabc, avm2_loads_avm1_loads_into_root, avm2_loads_avm1_v10}`, `avm2/{mouse_pick_avm1_root, selection_onsetfocus_mixed_avm}`, `avm1/shared_stack` | Declared dual-VM / multi-SWF child-frame execution arc (`loader-arc.md:793`, `avm1/_investigation/NEW_UPSTREAM_AVM1_TRIAGE.md:89`). 8 near rows, 26 lines — the single largest block in the live pool and entirely one arc. Note s10's B5 already took the *suppression* half; every remaining row needs the child's code to actually RUN. |
| `from_shumway/as3-loader/{LoaderTest2, LoaderLoadBytesTest}` | loader-arc **tranche 6** (AVM2 child-SWF execution) — `LoaderTest2` wants a symbol from the loadee's domain, `LoaderLoadBytesTest` is missing the loadee's own `from loadee: loaded` trace. Same arc, not polish. (`bug1157243/*` are NOT this — see B1.) |
| `audio/g711` | `SoundMixer.computeSpectrum` = real FFT over mixed audio. 3 tests / ~137 lines with `avm2/audio_computespectrum` + `audio/aac`, but it is a feature arc. |
| `text/links_in_scrolled_text` | Named blocker already on record: needs a wrap-aware `ng_getCharIndexAtPoint` in **AVM1** (`avm2/_investigation/CURRENT_STATUS.md:206`). Real work, not a near-pass. |
| `visual/definefont4` | gap 0 / 24 extra lines, but the SWF embeds the entire TLF (`flashx.textLayout.*`) runtime: **>25 min of gcc locally, hard `compile_fail` at both the 300 s default and a 1500 s override**. Cannot be iterated on this machine. It also carries `output.expected.png` — treat it as a pixel-board item (§11.3 already lists `heavy_tesselation` there). |
| `avm2/button_nested_frame_simple` | gap 0 / 12 extra lines, but the extras are 3 whole extra enterFrame→frameConstructed→exitFrame cycles plus re-run child framescripts — a timeline-length/stop() question inside the button+nested-timeline machinery, not a suppression one-liner. MED-LARGE; sized here so nobody mistakes gap 0 for cheap. |
| `avm2/scope_optimizations` (gap 1), `from_shumway/bitmapdata/getpixel-from-embedded` (gap 1, `200d04` vs `220a06` decode rounding), `avm1/remove_different_level` (gap 1) | Owned elsewhere / low confidence: the first is abc-verifier lattice Stage 3; the second is a lossless-image decode rounding question with no sibling; the third needs one trailing `undefined` after `onUnload` on a cross-level removal. |

---

## (g) Predicted wave-2 total

| Batch | Tests | Lines | Yield | Effort | Confidence |
|---|---|---|---|---|---|
| B1 malformed-SWF IOError #2124 | 2 | 2 | +2 | S–M | HIGH |
| B2 verifier method_info association | 2 | 5 | +2 | M | MED-HIGH |
| B3a `<!DocType>` case | 1 | 3 | +1 | XS | HIGH |
| B3b `constructsuper` null → #1009 | 1 | 2 | +1 | XS | HIGH |
| B3c `System.exit` → #2017 | 1 | 3 | +1 | S | MED-HIGH |
| B4 removeMovieClip cancels load | 1 | 4 extra | +1 | S | MED-HIGH |
| B5 Event worker-const version gate | 1 | 1 | +1 | XS | MED |
| B6 MorphShape shape hit-test | 1 | 2 | +1 | M | MED |
| B7 PerspectiveProjection clone | 1 | 4 | +1 | M | MED |
| **Total** | **11** | **26** | **+11** | | |

Carried §11.3 items (`graphic_linkage`, B8b lazy script init, B9 device
fonts) add +1 … +5 more if separately staffed.

**+11 conservative from a live pool of 32.** The full partition of those 32
rows (they sum exactly):

- **11 proposed above** (B1 ×2, B2 ×2, B3 ×3, B4, B5, B6, B7);
- **14 blocked on a declared arc or on this machine** — 8 dual-VM /
  multi-SWF, 2 loader tranche 6, 1 GC (`bug_483783`), 1 computeSpectrum
  (`g711`), 1 named AVM1 blocker (`links_in_scrolled_text`), 1 uniterable
  (`definefont4`);
- **3 carried from §11.3** (`graphic_linkage`, B8b lazy script init,
  B9 device fonts) — +1 … +5 if separately staffed;
- **4 low-confidence / owned elsewhere** (`remove_different_level`,
  `button_nested_frame_simple`, `scope_optimizations`,
  `getpixel-from-embedded`).

After this wave the near-pass well is essentially spent: 11 of the 17
non-arc-blocked rows are proposed, and the refill rate has been measured at
**zero for three consecutive sessions**. The next trace session should be
re-aimed at the gap 6–10 shoulder (37 tests, and it contains direct riders:
`doabc_and_symbolclass_script_init_goto`, `mixed_avm/avm2_loads_avm1_v9`,
`fonts/device_font_glyph_fallback`, `matrix3d/TransformBasics`,
`avm2/error_stack_trace{,_edge_cases}`) or at a declared arc. The polish
sweep has roughly one session of runway left.
