# w2-queue-regex: goto-sweep CONSTRUCT + libregexp u16 captures (session 22, wave 2)

**New files:**
- this report
- `w2-queue-regex.patch` (`git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`; `git apply --check -R` passes on the branch head)

No new source files and no new fixture dirs. Files changed (4 source files and 1 README):
- `SWFModernRuntime/src/actionmodern/action_queue.c`
- `SWFModernRuntime/src/avm2/avm2_regexp.c`
- `SWFModernRuntime/third_party/quickjs-libregexp/libregexp.c`
- `SWFModernRuntime/third_party/quickjs-libregexp/libregexp-opcode.h`
- `SWFModernRuntime/third_party/quickjs-libregexp/README.md` (the README says the vendored code is "unmodified". It now documents the local change.)

**Setup.**
- Cloud box. `SETUP_STATUS` shows apt, Pillow and Dawn all OK.
- Base is `origin/master` `0222809b`. Upstream corpus is Ruffle master **`45366370e`**, the same as the coordinator.
- No recompiler change, so I did not pass `--recompile`.
- All runs used `SWFRECOMP_COMPILE_TIMEOUT=2400`, the same box for both legs, and A/B via `git apply -R`.

## 0. Verdict: GO, +2 trace, 0 pixel

| test | category | KF | before (clean master) | after (patch) | mode(s) |
|---|---|---|---|---|---|
| `from_gnash/misc-ming.all/action_order/action_execution_order_test6` | from_gnash | yes | `output_mismatch` 0/24 (actual 20) | **`ruffle_matched`** 19/24 (actual 24) | graphics **and** no-graphics (identical) |
| `from_avmplus/recursion/pcre_find_fixedlength` | from_avmplus | yes | `output_mismatch` 19/20 | **`pass`** 20/20 | graphics |

Rule-3 check: both rows are KF and both move toward Flash's file. test6 goes `output_mismatch → ruffle_matched`, which is not a pass→rm. pcre goes to exact `pass`. Nothing in any canary moved `pass → ruffle_matched`.

## EXPECTED-FLIP LEDGER (check CI against this)

**Trace axis:**
| test | expected CI move | CI legs |
|---|---|---|
| `from_gnash/misc-ming.all/action_order/action_execution_order_test6` | `output_mismatch` → `ruffle_matched` | graphics + no-graphics |
| `from_avmplus/recursion/pcre_find_fixedlength` | `output_mismatch` → `pass` | graphics (`categories=full`) |

**Pixel axis: none.**
- Neither headline row has `[image_comparisons]`.
- The render canary is 60 tests / 102 comparisons: **102 IDENTICAL**, 0 DIFFERS, no trace or image status changes.

Any other movement in CI is outside this ledger and should be treated as a regression of this patch until proven otherwise.

**CI recommendation:** `mode=graphics categories=full` (AVM2 regex runtime), plus a `mode=no-graphics categories=all` leg, because `action_queue.c` is shared by both frame loops.

## 1. Change 1: goto sweep fires `CLIP_CONSTRUCT` for place+remove (`action_queue.c:158-178`)

`aq_drain`'s `fires_chronologically` is now:

```c
entry.kind == AQ_KIND_CLIP_CONSTRUCT
|| ((entry.kind == AQ_KIND_CLIP_INIT || entry.kind == AQ_KIND_REGISTER_CTOR)
    && !entry.queued_in_catchup)
```

- CONSTRUCT now always fires, even for a clip placed and removed inside the same goto sweep. This is Flash's pass-1 `C1, C2, C3` in test6.
- Load and unload kinds are untouched. They still hit the `avm1_removed || pending_removal` skip, so the sweep still cancels them as before.
- **`CLIP_INIT` / `REGISTER_CTOR` are deliberately NOT widened** (per brief). That is listed as a lead in §5.
- Mechanism of record: `w1-trace-tail-report.md` §1. This matches the prototype semantically; it is restructured for readability, with a comment.

**Remaining test6 diff (5 lines, not needed for the flip):**
- It is mechanism (b) from w1 §1: pass 2 is `L1, A1, L2, A2` in Flash and `L1, L2, A1, A2` in ours.
- All 5 lines are inside Ruffle's own diff set, which is why the row reaches `ruffle_matched`.

## 2. Change 2: libregexp u16 capture indices plus the two owed fixes

**Base: prototype `w1-trace-tail-prototype-3-regexp-u16-captures.patch`, applied unchanged.**
- `save_start`/`save_end` take a u16 operand (size 3) and `save_reset` takes two (size 5).
- The header is 10 bytes, with a u16 capture count at offset 2, the register count at 4 and the bytecode length at 6.
- `CAPTURE_COUNT_MAX` goes 255 → 1024.
- Every emitter and reader is updated: the parser, the 2 `save_reset` insertion sites, the 2 top-level `save_*` 0 emitters, the exec loop, `lre_exec`, `lre_get_alloc_count`, `lre_get_capture_count`, and the dump code.
- `compute_register_count` and the capture-init scan walk the bytecode by `reopcode_info[].size`, so they pick up the new sizes automatically.

**On top of the prototype:**

1. **Named-group back-reference > 255 is now a parse error, not a clamp to 255.**
   - Before, the prototype clamped the index, which silently referenced the wrong group.
   - New: a `back_reference_overflow` flag on `REParseState` is set by `re_parse_captures` / `find_group_name` when they emit an index above `BACK_REFERENCE_INDEX_MAX` (255).
   - The `\k<name>` site returns `re_parse_error("too many captures")` after emission if the flag is set. The same error fires if the count of same-named groups exceeds 255, because the `n` operand is also u8.
   - The numeric `\NNN` path uses the same constant, as in the prototype.
2. **`re_find`'s capture array is now sized for `lre_get_alloc_count`** (`avm2_regexp.c`, `re_find`).
   - The array is now `RE_MAX_CAPTURES*2 + RE_MAX_REGISTERS` (2048 + 255).
   - An explicit guard returns no-match if `lre_get_alloc_count()` ever exceeds it. By construction it cannot, because captures ≤ 1024 and registers ≤ `REGISTER_COUNT_MAX` 255.
   - `RE_MAX_CAPTURES` / `RE_MAX_REGISTERS` moved to the top of the file. The demote threshold in `re_preprocess` now uses `RE_MAX_CAPTURES` instead of a literal.

**Stack note.**
- `ReMatch.g` grows from 510 to 2048 `int64_t`, which is 16 KB.
- The `re_replace` callback's `cargs` array grows by the same ratio.
- Every build uses `STACK_SIZE=8MB` (native and all three wasm scripts), so this is fine. The arrays live on the linear-memory stack, not the 64 KB asyncify stack.

### Standalone libregexp harness (ASan, gcc -O1; scratchpad only, not committed)

| case | master | patch |
|---|---|---|
| `(?<=` 500×`(` `blah` 500×`)` `)hello` on `blahhello` | compile error "too many captures" | match: cc=501, [4,9], every group [0,4] |
| 300×`(a)` then `\300` | compile error | compile error (u8 back-ref operand) |
| 299×`(a)` then `(?<x>b)\k<x>` (index 300) | compile error (cc limit) | **compile error** (new overflow check; prototype would have clamped to group 255) |
| `\k<x>` then 299×`(a)(?<x>b)` (forward ref, index 300) | compile error | **compile error** |
| `(a)(?<x>b)\k<x>` on `abb` | match [0,3] [0,1] [1,2] | identical |
| `(?:` 300×`(x)` `){2}` (u16 `save_reset`) | compile error | match [0,600], groups [300..600) (last iteration) |
| 250×`(a{1,3})` on 750 `a` (alloc 503) | match | identical |
| `(\d+)-(\d+)` | match | identical |

### Latent overflow on master (the `re_find` crash repro)

Master's `re_find` allocates `uint8_t* capture[255*2]` (510 slots). `lre_exec` writes `lre_get_alloc_count()` = 2·captures + registers slots.

**Repro:** 250 groups followed by 12 nested counted quantifiers.

```as3
var p:String = "";
for (var i:int = 0; i < 250; i++) p += "(a)";
for (i = 0; i < 12; i++) p += "(?:";
p += "b";
for (i = 0; i < 12; i++) p += "){1,2}";
var s:String = ""; for (i = 0; i < 250; i++) s += "a"; s += "b";
trace(new RegExp(p).exec(s) != null);   // Flash/Ruffle: true
```

- This pattern has 251 captures and **alloc = 514** slots, which is more than 510.
- It is under the 255 demote threshold, so master compiles it as-is.
- Under ASan in the same harness (master libregexp, a 510-slot stack array exactly like `re_find`), it gives **`stack-buffer-overflow` in `lre_exec_backtrack` (libregexp.c:3059)**: a register write past the array.
- In a release build the overwrite lands on adjacent stack, which is UB. It may go silent or crash.
- With the patch the array has 2303 slots and the pattern matches.

I did **not** add a `regression/` fixture. Its expected output must come from outside SWFRecomp, and there is no AS3 compiler or Ruffle exporter in the cloud. See LOCAL ORACLE REQUESTS.

## 3. Canaries (clean master vs patch, same box)

| set | rows | mode | result |
|---|---|---|---|
| Queue canaries (w1's 63): all 17 `misc-ming.all/action_order/*`, 11 `displaylist_depths/*`, `DepthLimitsTest`, `consecutive_goto_frame_test`, `goto_frame_test`, `gotoFrame2Test`, `multi_doactions_and_goto_frame_test`, `unload_movieclip_test1`, `duplicate_movie_clip_test{,2}`, misc-swfc `gotoFrameFromInterval2`, `gotoFrameLabelAsFunction`, `movieclip_destruction_test1..4`, and 22 avm1 rows (`goto_*` ×16, `button_goto`, `clip_events`, `clip_event_propagation_order`, `movieclip_onconstruct`, `on_construct`, `unload_clip_event`) | 63 | graphics | only test6 moved. Every other row is identical in status **and** in matching/expected/actual line counts |
| same 63 | 63 | no-graphics | only test6 moved (same numbers as graphics) |
| `regression/` goto/clip-event members: `avm1_attach_clipevent_enterframe`, `avm1_child_timeline_{advance,frame1_stop,holder_stop,loop}`, `avm1_parent_child_modify_place`, `avm2_goto_catchup_scale`, `onconstruct_{cross_swf_version,type1_args}`, `onload_type1_args`, `onunload_type1_{args,local_frame}`, `mc_event_{cross_swf_version,type1_args}`, `enterframe_type1_args`, `root_enterframe_cross_swf_version` | 16 | graphics + no-graphics | all `pass` → `pass` |
| Regex canaries: `from_avmplus/recursion/*` (6), `as3/RegExp/*` (3), `as3/RuntimeErrors/Error1100RegExpFlagsArg`, ecma3 `String/{Split,split_504567,split_407156,ematch_001..004,esplit_001..003,search,replace_439458,ereplace_001}` (13), `avm2/regexp_*` (6), `avm2/string_{match,replace,search,split}` (4), regress `bug_{479786,532791,549389,672012,673284}` (5) | 38 | graphics | only `pcre_find_fixedlength` moved. 34 pass, 2 rm (`bug_479786`, `as3/RegExp/replace`), all unchanged |
| Render canary (`render_canary.py`, full standing list) | 60 tests / 102 PNGs | graphics | **102 IDENTICAL**, no trace or image status changes |

Notes:
- My regex set is 38 rows. w1 reported 40 but did not list them by name; this set rebuilds it from w1's family description.
- In the BEFORE leg, `avm2/string_match` showed `compile_fail` ("ld returned 1"). That was a link race between my two parallel `verify_output.py` processes. Run alone on clean master it is `PASS`, and in the AFTER leg it is `PASS`. It is not a move.
- The full regression suite was not run; only the 16 near-change members above.

## 4. Could not finish / open items

- **`regression/` fixture for the `re_find` overflow.** It needs an oracle outside SWFRecomp. Completion: the LOCAL ORACLE REQUEST below. Then add `regression/avm2_regexp_capture_registers/` with the coordinator's Ruffle trace as `output.txt`.
- Nothing else is open.

## 5. New unclaimed leads

1. **Goto-sweep `CLIP_INIT` / `REGISTER_CTOR` for place+remove** (`action_queue.c`, the same condition).
   - test6 shows Flash fires CONSTRUCT for swept place+remove, and Flash probably fires the other placement-time events too.
   - No corpus row measures them. A Flash/Ruffle oracle run on a synthetic `#initclip` + `registerClass` swept clip would decide it.
2. **test6 exact pass** (w1 §1 (b)): Flash runs each clip's `onLoad` followed by that clip's frame-1 DoAction. Check `action_execution_order_test11` alongside it.
3. **Back references to groups > 255.** They are now a clean parse error, so the pattern never matches. avmplus PCRE accepts them. Widening the `back_reference` operand to u16 would close this, but no corpus row needs it.

## LOCAL ORACLE REQUESTS

1. **`re_find` capture-register overflow fixture.** Compile the AS3 snippet in §2 (document class, `trace` only) to a SWF and run it through the local Ruffle exporter for 1 frame. I expect `true`.
   - Better: also trace `m.length` (expected 251) and `m[250]` (expected `a`).
   - Archive the SWF and trace, and the coordinator (or a follow-up slot) adds `ruffle-tests/tests/swfs/regression/avm2_regexp_capture_registers/`.
   - With this patch we pass it. On master it is a stack overflow (UB).
