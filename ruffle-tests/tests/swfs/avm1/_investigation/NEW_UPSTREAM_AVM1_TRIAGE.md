# New Upstream AVM1 Tests — Triage (2026-06-19)

The `avm1` suite grew from 654 → **701 tests** as `download_tests.sh` syncs fresh
from `ruffle-rs/ruffle` master each run. The older `CURRENT_STATUS.md` "100%
filtered, zero failures" claim was based on the 654-test snapshot and is stale.
This doc triages every non-ignored failing avm1 test in the fresh CI
`results.json` (SHA `1bef9e7b1`, 2026-06-19), so future sessions don't have to
re-discover them.

How the list was found: glob `**/test.swf` on disk minus the `test` names in
`_results/results.json`, then filter `results.json` for status ∉
{pass, ruffle_matched} and not in `ignored_tests.txt`.

## Update 2026-07-02 (CI 2026-06-30, SHA `56970ac27`)

Suite is now **704 tests**; filtered **639/661 effective (96.7%)** — 627 pass +
12 RM; **20 non-ignored filtered failures** after the ignore-list rename below.

Changes vs the 2026-06-19 state of this doc:

- **Fixed since:** `array_unshift` → **PASS**, `array_reverse` → **PASS**
  (Bucket C, fixed without a doc update at the time);
  `coerce_to_primitive_resolve` already marked fixed below.
- **`virtual_property_special_recursion_*` → fixed by `63f7af229`** (type-1
  virtual getter/setter params padded/ordered): `double_swf6` → **PASS**,
  `swf6` → **ruffle_matched**.
- **Upstream renamed both recursion families:**
  `watch_special_recursion_*` → `watch_recursion_*` and
  `virtual_property_special_recursion_*` → `virtual_property_recursion_*`
  (`test.swf` byte-identical; old-name dirs linger locally since
  `download_tests.sh` doesn't `--clean`). The two ignored swf7 watch variants
  reappeared as "new" failures under the new names until `ignored_tests.txt`
  was re-pointed (2026-07-02) — they remain accepted diffs
  (`ACCEPTED_DIFFS.md` Category 10), not regressions.
- **New non-ignored failures, untriaged:**
  - `virtual_property_recursion_double_swf7` (129/523) — the swf7 mutual
    variant of the fixed swf6 family (`virtual_property_recursion_swf7`
    single **passes**); likely the 65-deep re-entry analog of the watch swf7
    accepted diffs — verify before assuming fixable.
  - `virtual_property_recursion_scope` (6/11) — new scope variant.
  - `bitmapdata_hittest_threshold` (5/6) — 1 line off.
  - `amf_strict_array_serialization` (1/7) — joins Bucket A's AMF codec group.
- **Unchanged:** Bucket A (AMF, FileReference, multi-SWF child frames), Bucket
  B (`sound_setters` 14/43), `set_property_values/*` (still blocked at 92.9% /
  swf4 22.3%).

## Already resolved this session

- **`watch_special_recursion_{swf6,double_swf6}` → ruffle_matched**;
  **`{swf7,double_swf7}` segfault → clean output_mismatch** (ignored). Version-aware
  watch re-entrancy bound. See `ACCEPTED_DIFFS.md` Category 10 and the watch fix
  commit `1bef9e7b1`.
- **`geturl_target_normalize`, `geturl_opcode_target_normalize` → ignored.** They
  trace Ruffle's internal `Navigator::navigate_to_url:` dispatch log (URL/Target
  lines), not Flash trace output — same category as the long-ignored `geturl`. We
  don't (and shouldn't) emit Ruffle's navigator log.

## Remaining non-ignored failures (21 after the two geturl ignores)

### Bucket A — Infrastructure-blocked / deferred (11)

| Test | Need | Notes |
|------|------|-------|
| `amf_array_serialization` | AMF0/3 codec | Same deferred byte-exact AMF codec as the `shared_object` SharedObject tests (see `_investigation/NEW_UPSTREAM_TESTS_TRIAGE.md`). |
| `amf_serialize_typed_objects` | AMF0/3 codec | " |
| `netconnection_serialize_arrays` | AMF0/3 codec | " |
| `file_reference_list_browse_cancel` | FileReference file-dialog input | Headless has no OS file dialog; needs a synthetic browse-result injection path in `verify_output.py`. |
| `file_reference_list_browse_select` | FileReference file-dialog input | " |
| `file_reference_list_browse_invalid_filters` | FileReference file-dialog input | " (50% — partial: validates filter parsing before the dialog). |
| `looping_child_swf5` | Multi-SWF child-frame execution | Child SWF frames/labels don't advance/label correctly ("in frame" vs "in child frame"). |
| `looping_child_swf9` | Multi-SWF child-frame execution | " |
| `looping_child_swf32` | Multi-SWF child-frame execution | " |
| `shared_stack` | Multi-SWF child-frame execution | Stops at the child's frame 2; child frames don't run. Same root family as `looping_child_*`. |
| `load_cancel_via_removemovieclip` | loadMovie cancel lifecycle | Cancelling an in-flight load by removing the target clip; likely tied to the multi-SWF load path. |

### Bucket B — Documented / known (1)

| Test | Notes |
|------|-------|
| `sound_setters` | Sound `setVolume` after `mc._name` rename needs `_root.<varname>` to survive the rename — the soft-reference rebinding gap already noted in `CURRENT_STATUS.md` (2026-05-22) and `[[soft-ref-rebinding-blocks-movieclip-vN]]`. |

### Bucket C — Tractable, no infra needed (9 — future-fix candidates)

| Test | % | Effort | Notes |
|------|---|--------|-------|
| `set_property_values/swf5` | 92.9% | **BLOCKED** | **Unpromotable** — full PASS needs `_x`/`_y`←Inf to read back `-107374182.4` (INT_MIN/20, 9 sig figs) but `mc->x/.y` are `float` → `-107374184`. No `output.ruffle.txt`. ~111 other lines are fixable coercion quirks on the shared setProperty hot path. Full quirk map + plan: `blocked/SET_PROPERTY_VALUES_PLAN.md` (2026-06-19). |
| `set_property_values/swf6` | 92.9% | **BLOCKED** | Same source/blocker, SWF6 gates. See `blocked/SET_PROPERTY_VALUES_PLAN.md`. |
| `set_property_values/swf7` | 92.9% | **BLOCKED** | Same source/blocker, SWF7 gates. See `blocked/SET_PROPERTY_VALUES_PLAN.md`. |
| `set_property_values/swf4` | 22.3% | Large | Same source; `output.ruffle.txt` **present** so `ruffle_matched` reachable, but a much bigger, *separate* SWF4 gap (likely SWF4 property-number addressing) — not addressed by the swf5-7 quirk fixes. |
| `coerce_to_primitive_resolve` | **100% ✅** | **FIXED 2026-06-19** | Whole diff was **1 missing `[type Object]`** from `trace(obj3)`. Real mechanism is Ruffle `action_trace`: on `coerce_to_string` Err it prints fallback `[type Object]` **and** propagates. Fixed by wrapping `actionTrace` object-coercion in a local `setjmp` frame (print + re-throw). `complete/COERCE_TO_PRIMITIVE_RESOLVE_PLAN.md`. |
| ~~`array_unshift`~~ | — | **FIXED** | → PASS (see 2026-07-02 update). Was: sparse/own-property + length semantics. |
| ~~`array_reverse`~~ | — | **FIXED** | → PASS (see 2026-07-02 update). |
| ~~`virtual_property_special_recursion_swf6`~~ | — | **FIXED `63f7af229`** | → ruffle_matched (renamed upstream to `virtual_property_recursion_swf6`). Type-1 getter/setter param pad/order fix. |
| ~~`virtual_property_special_recursion_double_swf6`~~ | — | **FIXED `63f7af229`** | → PASS (renamed to `virtual_property_recursion_double_swf6`). |

## Recommended next targets

1. ~~`coerce_to_primitive_resolve`~~ — **FIXED 2026-06-19** (100%). Was a real Ruffle behavior after all (in `action_trace`, not `coerce_to_string`); the "no oracle" call was an artifact of a stale `~/CC/ruffle` checkout. `complete/COERCE_TO_PRIMITIVE_RESOLVE_PLAN.md`.
2. ~~`virtual_property_special_recursion_swf6/double_swf6`~~ — **FIXED `63f7af229`** (type-1 getter/setter param pad; the predicted broad `set`/`addProperty` dispatch fix). Remaining family members: `virtual_property_recursion_double_swf7` + `virtual_property_recursion_scope` (see 2026-07-02 update).
3. ~~`set_property_values/swf5-7`~~ — **BLOCKED/unpromotable** (float precision on `_x`/`_y`←Inf; no RM file). See `blocked/SET_PROPERTY_VALUES_PLAN.md`. Don't re-investigate.

Bucket A is genuinely blocked on infrastructure (AMF codec, file-dialog input, multi-SWF child frames) — low ROI until a shipped game or a larger test cohort needs those subsystems.
