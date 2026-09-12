# w2-avm2-json: JSON stack frames + integral-number wrapping (G1, G2 from `w1-avm2-report.md`)

Read `BRIEFS_COMMON.md` (wave-2 section included), then `w1-avm2-report.md` §G1/§G2. That report
is your diagnosis of record; re-verify its before/after claims yourself rather than trusting them.
Worktree agent: nothing commits, you deliver a patch.

## Scope (+2 effective)
**G1 `avm2/json_parse_errors` → pass (+1, ~15 LOC).** All 64 content lines already match; the
whole 80-line gap is stack frames. `JSON/parse()` must render as `JSON$/parse()` (native static
frames lose their `$` in `frame_is_class_trait`), plus a synthetic `Error$/throwError()` /
`JSON$/parseCore()` frame.

**G2 `avm2/json_parse_numbers` → `ruffle_matched` (+1, S–M).** We wrap EVERY integral JSON number
to i32 (`1782219299000` → `-192128840`). **This is a live product bug, not just a test row** — say
so in your report, and check whether the same wrap exists on any other JSON/number path you touch.
Also: serde's out-of-range reject, and G1's frames. The reachable target here is `ruffle_matched`,
NOT `pass` — do not chase `pass` past it.

## Required checks
- Headlines both ways: `avm2/json_parse_errors`, `avm2/json_parse_numbers`
  (`--tests-dir=ruffle-tests/tests/swfs/avm2`).
- Stack-frame rendering is shared machinery: run the AVM2 error/stack-trace tests near it
  (grep the corpus for tests whose expected output contains `at ` frames — at minimum
  `avm2/*error*`, `avm2/*stack*`, plus `from_avmplus/ecma3/JSON/*`). A frame-format change is
  exactly the kind of edit that moves unrelated tests, so budget for that sweep.
- `from_avmplus/ecma3/JSON/adhoc` is owned by **w1-drift** (upstream moved it today). Do not edit
  its files, but DO report what your change does to it — that is useful evidence for the drift agent.
- Number formatting is shared too: check `avm2/number_to_string` and `number_tostring` (both
  ACCEPTED/KF) do not move, and the `from_avmplus/ecma3/Number` family.
- `regression` suite members near JSON/numbers.

Siblings and their files: **w2-avm2-smalls** edits `avm2_class.c`-style registration paths
(BitmapFilter abstract init, ByteArray symbol-class predicate) and matrix3d; **w2-loaders** edits
`avm2_display.c` and `swf_core.c`. Self-localize and flag any overlap in your final message.
