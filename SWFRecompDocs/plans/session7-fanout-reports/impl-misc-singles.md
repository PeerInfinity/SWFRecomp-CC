# Implementation report — four diagnosed misc singles

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-ad0a08934d0385769`
(branch `master` @ `46dcf3a06`, **nothing committed, nothing pushed**).
Patch: `scratchpad/patches/misc-singles.patch` (8 files, +230/-47).

All runs are local, `--mode` default (no-graphics), `SWFRecomp/build` copied from
the shared checkout (changes are runtime-only, so the recompiler binary is valid).
The machine was under heavy load from another session (load avg ~21) throughout,
so batches were capped at 2 concurrent `verify_output.py` invocations.

| # | Target | Before | After |
|---|---|---|---|
| 1 | `from_avmplus/e4x/XML/e13_4_4_36` | output_mismatch 13/16 | **PASS** |
| 2 | `avm2/parse_float_swf10` | output_mismatch 79/81 | **PASS** |
| 3 | `avm2/issue_8630_placeremoveplace` | output_mismatch 13/15 | **PASS** |
| 3 | `avm2/issue_8630_placeremoveplace_scriptremove` | output_mismatch 13/16 | 15/16 (cause B deferred, as scoped) |
| 4 | `from_avmplus/ecma3/ObjectObjects/hasOwnProperty` | output_mismatch 9/10 | **PASS** |

**43 canary tests run, 43 still pass. Zero regressions observed.**

---

## 1. E4X prefix minting + ancestor-first uri tie-break

`SWFModernRuntime/src/avm2/avm2_e4x.c` (+73), all inside the serializer.

Three new statics next to `anc_find_uri`:

* `anc_find_uri_outer` — the same by-uri lookup walking the OUTERMOST `AncNs`
  frame first (ECMA-357 13.3.5.4 step 2 tie-break; avmplus picks the ancestor).
  Used by the `PREFIX_OF` macro and by the close-tag lookup. The in-scope walk
  (`avm2_e4x_in_scope_namespaces`) is untouched and stays inner-first, which is
  what makes row 6's shadowing work.
* `anc_prefix_taken` — is a prefix bound anywhere in the chain (NULL == "").
* `mint_prefix` — ECMA-357 10.2.1 step 11. Returns `NULL` (keep today's
  `xmlns="..."` emission) when the empty prefix is free, else the first free of
  `aaa`, `aab`, … Returning `NULL` rather than an interned `""` keeps
  `anc_contains_exact`'s NULL-vs-`""` distinction unchanged for descendants,
  which is the "minimal form" the diagnosis recommended.

`mint_prefix` is applied at both `decls[]` push sites (node ns and attribute ns),
guarded on `str_is_empty(prefix) && uri->len > 0`.

### Before / after (graded rows)

```
- 4  ... got: <a xmlns="http://foo"><b><c    xmlns="http://bar">d</c></b></a>
+ 4  ... <a xmlns="http://foo"><b><aaa:c xmlns:aaa="http://bar">d</aaa:c></b></a>
- 5  ... got: <a xmlns="http://www.zzz.com"><b    xmlns="http://www.zzz.org">c</b></a>
+ 5  ... <a xmlns="http://www.zzz.com"><aaa:b xmlns:aaa="http://www.zzz.org">c</aaa:b></a>
- 7  ... got: <abc:a ...><def:b xmlns:def="http://www.zzz.com">c</def:b></abc:a>
+ 7  ... <abc:a ...><abc:b xmlns:def="http://www.zzz.com">c</abc:b></abc:a>
```

### Finding worth recording (not in the diagnosis)

Only rows **2–7** of `e13_4_4_36` are graded against literal strings. Rows 1 and
8–15 compare `correct.toString()` against `MYXML.toString()` — i.e. **both sides
go through our own serializer**, so those rows are structurally immune to any
consistent change in prefix selection. That is why the outer-first tie-break
could be applied to attributes as well as element names without breaking the ns5
row (`<moo:bravo poo:attr="1" xmlns:poo="http://moo/">`), even though that row's
expectation looks like it demands inner-first. Do not read those rows as
evidence about prefix policy.

### Canaries (16, all PASS)

`from_avmplus/e4x/XML`: `e13_4_1`, `e13_4_2`, `e13_4_4_23`, `e13_4_4_31`,
`e13_4_4_35`, `kXMLPrefixNotBoundErr`.
`from_avmplus/e4x/TypeConversion`: `bug153363`, `bug153363_2`, `e10_3`.
`avm2`: `xml_tostring_namespace`, `xml_namespace`, `xml_namespace_methods`,
`xml_no_namespace`, `xml_namespaced_property`, `xml_explicit_use_namespace`,
`xml_tostring`, `xml_advanced`, `xml_equals_namespace_check`, `xml_set_name`,
`xml_settings`, `xml_hasownproperty`.

---

## 2. `parseFloat` SWF ≤ 10 double-dot bug compatibility

`avm2_value.c` + `avm2_value.h` + 3 call sites (`avm2_value.c:616`,
`avm2_globals.c` `global_parse_float`, `avm2_text.c` `style_parse_float`).

`avm2_string_to_f64` gained a leading `Avm2Context* ctx` parameter (the
diagnosis's "a parameter is cleaner" option). The accumulator span is now

```c
const char* span_end = (ctx == NULL || ctx->swf_version >= 11) ? p : end;
```

`ctx->swf_version` had no reader before this; it is set in `avm2_main.c:342`
from `avm2_generated_swf_version` before `avm2_globals_init`, so it is live for
every parse. `ctx == NULL` is tolerated and behaves as SWF ≥ 11.

Before: rows 40/42 were `1.2345` / `1.2345`. After: `12345.678` / `12345.6`,
i.e. the whole 81-line output matches. No other row moved, matching the
diagnosis's hand-trace.

### Canaries

`avm2/parse_float` (the SWF ≥ 11 sibling, `avm2_generated_swf_version = 38`) —
PASS. It was run in the same batch as `parse_float_swf10` and both passed on the
first attempt, so no sequential re-run for float noise was needed.

---

## 3. AS3 per-depth queued display tags (cause A only)

`avm2_display.c`: new file-scope `Avm2QueuedDepth { depth, remove_op, add_op,
add_idx }` encoding Ruffle's `QueuedTagList` four states, and a rewritten op loop
in `run_frame_internal`.

Semantics implemented:

* place with `HAS_CHAR`, slot in state `Add` → warn + keep the first (this is the
  real "first Add wins" that `place_object_same_depth_frame` pins);
* place with `HAS_CHAR`, slot in `RemoveThenAdd` → replace the queued add
  silently (Ruffle `RemoveThenAdd(r,_) => RemoveThenAdd(r,new)`);
* remove, slot in `Add` → **annihilate**: the queued add is voided (its
  `queued_places` entry set to `-1`) and NO remove is recorded → `None`;
* remove, slot in `RemoveThenAdd` → drop the add, keep the FIRST remove;
* remove otherwise → `Remove(new)`.
* Removes now drain in a second pass *after* the tag loop but still before
  `ext->current_frame++`, in tag order. (Places were already all deferred to
  `flush_queued_places`, so this changes no place-vs-remove ordering.)

Two deliberate deviations from a literal Ruffle port, both to keep the blast
radius at "narrowing":

* **Modify-only place tags** (no `AVM2_TLF_HAS_CHAR`) are passed straight
  through to `queued_places` and are neither displaced by nor cancelled by
  anything. Ruffle keeps exactly one Add per depth regardless; our existing code
  gated the dup rule on `HAS_CHAR`, and collapsing modify tags into the single
  add slot would silently drop same-frame place+modify pairs. This is the only
  place the implementation is knowingly not Ruffle-shaped.
* **Drain order is tag order, not depth order.** Ruffle's `queued_tags` is a
  `BTreeMap<Depth, _>` so it drains ascending by depth; keeping tag order
  reproduces today's behaviour exactly for every frame that does not mix
  place+remove at one depth.

`flush_queued_places` skips `-1` entries.

### Before / after

```
issue_8630_placeremoveplace              issue_8630_placeremoveplace_scriptremove
- stderr: failed to queue place at        (same two stderr lines gone)
          depth 1/2 (already queued)
-  7  2.75  +  7  0.75   -> now 2.75     rows 7-8 fixed the same way
-  8  2.75  +  8  0.75   -> now 2.75     - 16  0  + 16  2.75   (STILL FAILS)
   => PASS                                  => 15/16, output_mismatch
```

Line 16 of `_scriptremove` is cause B (`transformed_by_script`), explicitly out
of scope for this task. Exactly the predicted outcome.

### Canaries (18, all PASS)

`avm2`: `place_object_same_depth_frame`, `place_object_replace`,
`place_object_replace_2`, `place_multiple`, `issue_8630_scriptremove`,
`movieclip_displayevents_timeline`, `displayobjectcontainer_timelineinstance`,
`displayobjectcontainer_removechild_timelinemanip_remove1`,
`movieclip_goto_overwrite`, `remove_dobj`, `goto_methods`.
`from_shumway/timeline`: `Timeline3`, `Timeline4`, `Timeline8`, `Timeline9`,
`timeline_loop`.
`regression`: `avm2_goto_catchup_scale`, `avm2_timeline_solid`,
`avm2_timeline_gradients`, `avm2_timeline_stroke_gradient`, `avm2_timeline_text`.

---

## 4. String instance methods in the AS3 namespace

New `avm2_builtin_add_method_as3` in `avm2_globals.c` (declared in
`avm2_globals.h`) — identical to `avm2_builtin_add_method_n` except
`e.key = builtin_key("http://adobe.com/AS3/2006/builtin", name)`. The 16
`avm2_builtin_add_method` calls in `avm2_register_string` switched to it; the
`length` getter deliberately stays public, and the `String.prototype` copies via
`avm2_proto_add_function_n` are untouched.

Dispatch is unchanged because `avm2_propkey_matches` folds AS3 ↔ public in both
directions. I re-verified the strict-public readers: `avm2_vtable_find_public`
still has exactly three callers (`avm2_ops.c:4166` = `hasOwnProperty`,
`avm2_flixel.c:236`/`:1060` = the Flixel fingerprint gate). The two other
`avm2_propkey_is_public` vtable walkers (`avm2_json.c:818`, `avm2_amf.c:372`)
now skip String's methods, which is more correct, not less — both already skip
`AVM2_PROP_METHOD` entries or serialize slots only.

Before: `str.hasOwnProperty("split")` → `true` (row 2 of 10). After: `false`,
test PASS.

### Canaries (17, all PASS)

`from_avmplus/ecma3/ObjectObjects`: `isPrototypeOf`, `propertyIsEnumerable`,
`class_001`, `e15_2_4_2`, `e15_2_4_3`, `e8_6_2_6_001`.
`from_avmplus/ecma3/String`: `Split`, `concat`, `substr`, `esplit_001`,
`e15_5_3`, `e15_5_4`, `e15_5_4_4_1`, `e15_5_4_11_1`, `e15_5_4_13`, `e15_5_5_1`.
`avm2`: `hasownproperty_namespaces`, `string_split`, `string_replace`.

Not run (baseline is already `output_mismatch`, so they cannot regress a pass):
`avm2/primitive_toString`, `avm2/primitive_valueOf`.

---

## Deviations from the brief

* Fix 3's two intentional departures from a literal `QueuedTagList` port
  (modify-only place tags, tag-order drain) are documented above.
* Fix 1's tie-break was applied to attribute prefixes as well as element names,
  since `PREFIX_OF` serves both — safe for the reason described under "Finding
  worth recording".
* Test dirs and `SWFRecomp/build` were rsynced into the worktree (they are
  gitignored downloads); `git diff` is source-only.

## Worth propagating

* `SWFRecompDocs/plans/polish-sweep-arc.md` §5.5 files the `issue_8630` pair
  under "TextField bounds"; it is "AS3 queued display tags" and there is no
  TextField in either SWF. §6.6's `hasOwnProperty` entry should say "String's
  instance-side namespace", not "the whole ES3 prototype surface".
* `Array`, `Number`, `Date`, `RegExp` have the same avmplus namespace shape as
  `String` did. Nothing in the corpus asserts it today, so they were left alone.
