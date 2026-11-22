# w1-textfield-vn: gnash TextField-v6/v7/v8 + AVM1 edittext_set_text_same(_after_edits) (session 25, wave 1)

**New files on this branch:**
- `SWFRecompDocs/plans/session25-fanout-reports/w1-textfield-vn-report.md` (this report)
- `SWFRecompDocs/plans/session25-fanout-reports/w1-textfield-vn-prototype.patch` = `git diff origin/master -- SWFModernRuntime SWFRecomp`. It touches `SWFModernRuntime/src/actionmodern/action.c` (+113/−13) and `SWFModernRuntime/src/libswf/ng_shared.c` (+14). `git apply --check` passes against `origin/master` `ca14fe02`. The source was reverted after measuring.

**Environment:**
- Cloud box. `SETUP_STATUS` is all OK (apt, Pillow, Dawn/lavapipe).
- Base is `origin/master` `ca14fe02`. Its code is the s25 trace baseline `746c39489`.
- Categories downloaded: `avm1 from_gnash`, plus `regression` from git.
- Upstream: `download_tests.sh` prints no SHA. My Ruffle clone at the same time was `3ac8dcb07`. Every headline row reproduced the CI baseline exactly (467/476/478, 28/70, 30/98), so there is no drift on my rows.
- All runs were single tests, graphics mode, at most `-P 2`.

---

## 0. Verdicts and priced flips

| Row | CI baseline (`45043930556`) | Prototype (measured) | Verdict |
|---|---|---|---|
| gnash `TextField-v6` (KF, sidecar) | output_mismatch 467/545. 78 diff lines, **39 ours-only** | output_mismatch **513/545**. 32 diffs, **19 ours-only** | **GO** for wave 2: +46 lines, 0 flips. Flip is **ruffle_matched only**, 6 more phases away (§2) |
| gnash `TextField-v7` (KF, sidecar) | 476/570. 94 diffs, **42 ours-only** | **524/570**. 46 diffs, **21 ours-only** | **GO** +48 lines; flip is 8 phases away |
| gnash `TextField-v8` (KF, sidecar) | 478/571. 93 diffs, **42 ours-only** | **527/571**. 44 diffs, **20 ours-only** | **GO** +49 lines; flip is 7 phases away |
| avm1 `edittext_set_text_same` (no KF) | 28/70 | untouched | **HOLD, L.** Plain-field span model (§4). Flip = **pass** (+1) |
| avm1 `edittext_set_text_same_after_edits` (KF) | 30/98. 68 diffs, 33 ours-only | untouched | **HOLD, L.** The same model gives **ruffle_matched** (+1 effective) |

**Prototype result:**
- 0 new diff lines on any of the 3 versions.
- **195 rider rows with zero status or line-count moves** other than the three headline rows (§3).
- Graphics and no-graphics output are byte-identical on the 3 headline rows.

**Flip arithmetic:**
- `ruffle_matched` requires our diff-line indices to be a subset of Ruffle's (`verify_output.py:3914`).
- So only **ours-only** lines (where Ruffle matches Flash and we don't) gate the flip. Lines that both of us get wrong ("shared") do not.
- A Flash-exact `pass` is impossible. The ACCEPTED `restrict=""` pair and the `#passed/#failed` summary lines can never match. So `ruffle_matched` is the only landing for all three rows.
- Since all three are KF, no `pass → ruffle_matched` regression is possible.

### Premises attacked

1. **"The ≈26-line prototype `hasOwnProperty` block is the natural first phase" is half true.**
   - It is the biggest line block: 26 per version, measured.
   - But **all 26 lines are SHARED with Ruffle.** Ruffle defines the TextField props eagerly (`core/src/avm1/globals/text_field.rs:108`, `define_properties_on(class.proto, PROTO_DECLS)`), so it fails them too.
   - The block is worth **+26 lines and zero flip progress.** Only the 3 per-instance broadcaster lines that rode along with it are ours-only.
2. **The plan's Phase-2 mechanism is wrong.**
   - The plan says to move the addProperty registrations into the TextField constructor, per instance.
   - Flash defines the 35 native props **on `TextField.prototype`, at first instantiation.** The gnash test asserts both halves: `!TextField.prototype.hasOwnProperty('background')` before (TextField.as:86-112), then `TextField.prototype.hasOwnProperty(...)` after `createTextField` (:175-200).
   - The Flash-authored avm1 `textfield_props_swf6/7/8` show that `new TextField()` is a trigger too. My first prototype missed that trigger and regressed all three; adding it restored them.
3. **Phase 2 was blocked by an unlisted prerequisite (new phase P0).**
   - gnash's `Dejagnu.swf` is **SWF5**. Its imported `_xtrace_win` field is instantiated before line 86.
   - Our runtime treats that field as an SWF6+ TextField, because instantiation uses the global `g_swf_version` (7) and `mc->swf_version` and `movie_id` are 0 for imported clips.
   - So the field fired the prototype definition first, and a Phase-2-only patch measured **+0**.
   - Flash says the field is SWF5-style: v7/v8 :43 `!instanceof TextField`, :45 `typeof == "movieclip"`.
4. **The plan of record is stale in 5 places** (phase table, §1).
   - Phases 9 and 11 no longer fail.
   - Phase 1's per-instance half exists already (`installTextFieldBroadcaster`), but it had the wrong shape (own methods).
   - Phase 8's mechanism is misdescribed.
   - Four ours-only clusters are not in the plan at all, and they are the cheapest yield found: replaceSel/selection, createTextField depth and name, SWF5 import identity, and the per-instance broadcaster shape.
5. **The ACCEPTED `restrict=""` entry's premise does not hold.**
   - The entry (`from_gnash/_investigation/ACCEPTED_DIFFS.md:441`) treats avm1 `edittext_restrict` as the authoritative Flash test and gnash as inconsistent.
   - But gnash's `output.fp*.txt` are Flash outputs too: all 9 expected files PASS :550/:551.
   - The two tests differ in context. gnash sets `restrict = ""` after `"olH"` on a `createTextField` field. `edittext_restrict` sets `''` after `null` on a SWF7 DefineEditText field.
   - So the two results are probably not contradictory. A rule like "`""` collapses to null only from null" would satisfy both.
   - The lines are shared with Ruffle (no flip value, +2 lines). I left them as a lead (§6), not a fix.

---

## 1. The plan of record re-read against today's code

Measured by positional alignment of our output vs `output.fp13-17.txt` (the graded highest-version subtest) and vs `output.fp13-17.ruffle.txt`. "OO" means ours-only lines; "Sh" means lines shared with Ruffle.

| Plan phase | Plan status | Today (baseline `746c39489`) | Lines v6 / v7 / v8 |
|---|---|---|---|
| 1 AsBroadcaster | in_progress | Prototype half **done**. Per-instance half exists (`installTextFieldBroadcaster`, `action.c:40464` pre-patch), but it runs `installAsBroadcaster` on the instance, so `tf.hasOwnProperty('broadcastMessage'/'addListener'/'removeListener')` is wrongly true (:169-171). Ruffle `edit_text.rs:2117 initialize_listeners` defines only `_listeners` (DONT_ENUM, DONT_DELETE). **Fixed in prototype.** | 3 OO each |
| 2 prototype hasOwnProperty | pending | Mechanism in the plan is wrong (premise 2). Blocked by P0 (premise 3). **Fixed in prototype.** | 26 Sh each |
| 3 getFontList | done | done | 0 |
| 4 boolean coercion | done | done | 0 |
| 5 null-typed props | in_progress | maxChars and variable done. `restrict` is ACCEPTED, premise questionable (premise 5). | 2 Sh each |
| 6 MC frame props | done | done | 0 |
| 7 type normalize | done | done | 0 |
| 8 tf.length | pending | **Mechanism misdescribed.** The failing check is :371, *after* `tf.length = 10` (the plan reads it as :369 after `text=""`). The `length` setter stores 10 instead of being a read-only no-op. | 1 OO each |
| 9 maxhscroll | pending | **No longer fails (stale).** | 0 |
| 10 _width/_height | done | done | 0 |
| 11 _parent | pending | **:476 no longer fails (stale).** What remains is `_root._parent == 'fake_parent'` (:1199, an `xcheck`), Sh. | 1 Sh |
| 12 replaceText exists | done | done. The v7/v8 *behaviour* block :1147-1169 (12 lines) is Sh. | 12 Sh v7/v8 |
| 13 container identity | pending | Mechanism refined: `createTextField` must **call the current `_global.TextField` as a constructor with `this` = the new field** (:1225-1248: `count==1`, `storedthis === tfmo`, `tfmo.bo`). | 5 OO each |
| **P0 (new)** SWF5-imported field identity | n/a | **Fixed in prototype.** | +0 / +2 / +2 (1 OO + 1 Sh) |
| **P14 (new)** programmatic `setFocus` on an EMPTY field | n/a | `g_tf_select_all` is lazy: it tracks the current text length. So `setFocus(empty)`, then `text = "Text in a string"`, then `replaceSel("More ")` replaces everything (:1067-1110). Ruffle captures `for_range(0, len)` at focus time. **Fixed in prototype.** | 10 / 10 / 11 OO |
| **P15 (new)** free-function `createTextField` depth and numeric name | n/a | `actionCallFunction`'s createTextField arm did `(void)depth_val`, so `getDepth()` returned 0 (:808, :1056). A numeric name gave `""`, so `_root[3]` was undefined (:1045-1050). **Fixed in prototype** (with ToNumber via `varToDoubleSimple`). | 7 OO each |
| **P16 (new)** variable binding to paths | n/a | `tf.variable = "_level0.inputVar"` / `"_level0.o.t"` sync semantics (:754-772). | 6 OO each |
| **P17 (new)** device-font metrics on createTextField fields | n/a | `textWidth` 0 (Flash 30/63) and `textHeight` 2 (Flash 12) on a Noto Sans device-font field (:909, :949, :969, :972, v8 :978). | 4 OO each |
| **P18 (new)** `_name`/`_target` setter on TextField | n/a | `tf._name = 'fake_name'` is not applied (:1207, :1209). | 2 OO each |
| **P19 (new)** CallMethod `createTextField` return value for SWF<8 | n/a | `r.toString() == undefined` (:1254). We return the field, and its toString gives "Hoppla!". | 1 OO v6/v7 |
| **P20 (new)** `tf._root != tf._ROOT` (v7+ case sensitivity) | n/a | :461 | 1 OO v7/v8 |
| **P21 (new)** variable bound to `undefined` gives text `"undefined"` (v7+) | n/a | :783 | 1 OO v7/v8 |
| other Sh | n/a | autoSize=center width 60 vs 63 (2); softref typeof after removal (2); replaceSel (1, 20) (v6 4 lines); summary lines (2) | Sh |

---

## 2. Ranked phase list: line gains and flip prices

**Done in the prototype** (all measured stepwise, no new diff lines at any step):

| Rank | Phase | Price | Δ lines v6 / v7 / v8 | Ours-only removed |
|---|---|---|---|---|
| 1 | P2 + P1b (lazy proto props + instance `_listeners` only), needs P0 | S | +29 / +29 / +29 | 3 / 3 / 3 |
| 2 | P0 SWF5-imported field (no TF proto, typeof movieclip, no trigger) | S | +0 / +2 / +2 | 0 / 1 / 1 |
| 3 | P14 setFocus on empty field, collapsed selection | S | +10 / +10 / +11 | 10 / 10 / 11 |
| 4 | P15 free-function createTextField depth + numeric name | S | +7 / +7 / +7 | 7 / 7 / 7 |
| | **Prototype total** | | **+46 / +48 / +49** | **20 / 21 / 22** |

**Remaining, priced for wave 2.** These are ours-only lines, so every one is required for the flip.

| Rank | Phase | Price | OO lines v6 / v7 / v8 | Notes |
|---|---|---|---|---|
| 5 | P8 `length` read-only | S | 1 / 1 / 1 | setter no-op in the `actionSetMember` MOVIECLIP TF arm |
| 6 | P18 `_name`/`_target` setter | S | 2 / 2 / 2 | rename the TF clip. Check the `_target` recompute |
| 7 | P19 CallMethod createTextField returns undefined <8 | S | 1 / 1 / 0 | the CallMethod `createTextField` arm (≈`action.c:73864` pre-patch) |
| 8 | P20 `_ROOT` case-sensitive on TF, v7+ | S | 0 / 1 / 1 | |
| 9 | P21 bound `undefined` gives "undefined", v7+ | S | 0 / 1 / 1 | |
| 10 | P16 variable-binding path semantics | M | 6 / 6 / 6 | Phase-B binding (`actionTryBindTextFieldVariable`). Flash: setting the variable re-reads it, writing `text` writes through, but writing the bound var does not update `text` |
| 11 | P13 createTextField calls `_global.TextField` | M | 5 / 5 / 5 | construct with `this` = field object; identity must hold (`===`) |
| 12 | P17 device-font metrics on createTextField fields | M | 4 / 4 / 4 | textWidth 0 means no device-font measurement for these fields. Overlaps the pixel-text arc |

**Flip price, `ruffle_matched`:**
- **v6:** all of phases 5-7 plus 10-12. That is 6 phases (3 S + 3 M) for 19 lines.
- **v7:** phases 5-12. That is 8 phases (5 S + 3 M) for 21 lines.
- **v8:** phases 5, 6, 8-12. That is 7 phases (4 S + 3 M) for 20 lines.
- The S batch alone (≈1 session, +4/+6/+5 lines) flips nothing. The three M phases are the real price.
- **Total for +3 effective rows: ≈ L** (one S batch + 3 M).

---

## 3. The measured prototype

### Mechanisms (all in `SWFModernRuntime/src/actionmodern/action.c` unless noted; functions named for sibling coordination)

- **`initTextFieldPrototype`:** no longer defines the 35 native props.
- **New `textFieldDefineProtoProps` (static, one-shot, SWF6+):** defines the 35 props on `TextField.prototype` in the old reverse order (the for-in order is unchanged). It skips a name a script already put there.
  - Called from `installTextFieldBroadcaster`. That function runs at every TF display-object instantiation: two sites in `findOrCreateMovieClip`, the clone site, and the `actionCallFunction` createTextField site.
  - Also called from `actionNewObject`'s `new TextField()` arm.
- **`installTextFieldBroadcaster`:**
  - Now returns early for SWF5-sourced fields.
  - Defines only an own `_listeners` (PROPERTY_FLAG_WRITABLE, i.e. DontEnum + DontDelete), with self as element 0. It no longer runs `installAsBroadcaster` on the instance.
- **New `tfIsSwf5Sourced(mc)`:**
  - Reads new `ng_getTextFieldSrcSwfVersion(tf_idx)` in `libswf/ng_shared.c`. `ng_record_textfield_props` records `g_swf_version` at DefineEditText time. During ImportAssets, the runtime sets `g_swf_version` to the child's version (5 for Dejagnu).
  - Used in the `actionTypeof` MOVIECLIP arm (gives "movieclip") and the two `__proto__ = TextField.prototype` gates in `findOrCreateMovieClip`.
  - `findOrCreateMovieClip` now sets `mc->ng_textfield_idx` before the `installTextFieldBroadcaster` call at both sites. It was previously set a few lines later to the same value.
- **New `tfSetFocusSelectAll(mc)`:** used by `builtin_selection_setFocus` (2 sites). It returns 0, a collapsed selection, when the field's text is empty at focus time.
  - **This touches Selection focus code.** The parallel `n-play-game` session works on AVM1 button/mouse dispatch. I did not touch `tag.c` or any mouse or button function, but wave 2 should tell that session about this edit.
- **`actionCallFunction` free-function `createTextField` arm:**
  - Depth goes through `varToDoubleSimple` (ToNumber; NaN gives 0) and is stored into `child->depth`.
  - A numeric first argument is ToString'd into the instance name.

**Not landed, a residual lead:** the CallMethod `createTextField` arm also discards depth (`(void)depth_val`) and drops numeric names. I applied the same fix there and it moved the `_root[3]` lines from v7 to v8 (v7 regressed by 4) and produced garbage depths. So I reverted it. The likely cause is that a `"3"` clip gets created by both paths. That needs its own diagnosis.

### Stepwise measurement (diff lines; no step added a new diff line)

| Step | v6 | v7 | v8 |
|---|---|---|---|
| baseline | 78 | 94 | 93 |
| + P1b (instance `_listeners` only) | 75 | 91 | 90 |
| + P2 lazy proto (with P0's trigger gate) | 49 | 65 | 64 |
| + P0 typeof / instanceof | 49 | 63 | 62 |
| + P14 setFocus | 39 | 53 | 51 |
| + P15 createTextField (func form) | **32** | **46** | **44** |

### Rider sweep: 195 rows, graphics mode, compared with the CI baseline `results_graphics.json` per suite

- **avm1, 131 rows:**
  - Every TextField/EditText row (72).
  - Every focus/selection/tab_ordering row.
  - `as_broadcaster`, `text_format_prototype_lazy`, `lazy_prototype_shared`.
  - Every avm1 SWF whose bytecode contains `createTextField` (60, found by scanning the decompressed SWFs).
- **gnash actionscript.all, 33 rows:** `TextField-v5..v8`, `TextFieldHTML-v5..v8`, `MovieClip-v6/7/8`, `toString_valueOf-v5..v8`, `Selection-v6/7/8`, plus every row whose SWF calls `createTextField`.
- **gnash misc-ming / misc-mtasc / misc-swfc, 29 rows:** `DefineEditText*`, `TextFieldTest`, `edittext_test1`, plus every row whose SWF calls `createTextField`.
- **regression, 2 rows:** `avm1_parent_child_text` plus the createTextField users.

**Result:** zero status or matching-line moves outside the three headline rows.
- One row has no CI baseline entry: `misc-swfc.all/gotoFrameFromInterval`. It gives runtime_error on clean master too (measured).
- An intermediate prototype without the `new TextField()` trigger regressed `textfield_props_swf6/7/8` (pass → mismatch). That is how I found the second trigger. The final patch passes all three.

**Pixel risk:**
- P15 now gives free-function createTextField fields their real depth. Previously they all sat at depth 0, which could change z-order for overlapping fields.
- P14 can change the selection highlight of a programmatically focused empty field once text is assigned.
- Wave 2 must run the render canary plus an images run.

---

## 4. `edittext_set_text_same` / `_after_edits`: the data-model change and its price

**Where per-character formats live today:**
- `TFRunTable` (`action.c:23049`, pre-patch) holds `TFRun runs[512]` and `char text[16384]`.
- There are `TF_MAX_TABLES` = 32 static tables, about 290 KB each (a TFRun is about 560 B). `tf_get_table` evicts slot 0 when all 32 are used.
- Tables are created only on the **HTML** paths:
  - the `htmlText` SetMember (`tf_styled_runs_from_html` and the parse at ≈`action.c:56144`);
  - `text =` on an `html=true` field (≈56043);
  - the DefineEditText HTML init (≈23924, ≈24146).
- A plain field has **no table.** Measured with instrumentation in this test: `tf_find_table(field) == NULL` on every `setTextFormat` call. In the passing `textfield_set_text_format_args` a table exists.
- So on a plain field:
  - `setTextFormat` writes only field-wide `_tf_fontHeight` / `_tf_fontId` / `_tf_leading` / margins. These are bookkeeping for textWidth and the renderer.
  - `getTextFormat(i)` then returns `tf_get_defaults` (size 12).
  - `setNewTextFormat` writes the same `_tf_fontHeight` (`action.c:74890` arm) and never updates what `getNewTextFormat` returns (12 vs Flash 20).
  - That accounts for the whole diff on both rows: every `sizes=` and `new=` column is 12.

**The change needed** (it agrees with s23 `w2-tf-css-report.md` §3, re-verified today):

1. **Give plain fields a `TFRunTable` lazily, on first `setTextFormat` / `setNewTextFormat` / `textColor=`.** Seed it with one run from the current text and the field's default format.
   - Fix eviction at the same time: never evict a table whose `mc` is live. Eviction today silently discards a live field's formats; with plain fields in play that becomes common in games.
2. **Store a new-text-format record** on the field. Today the new text format is not separate from the textWidth bookkeeping. Route `getNewTextFormat` through the record.
3. **Text-assignment rule** (Ruffle `edit_text.rs:445 set_text`):
   - the same text is a no-op that keeps the spans;
   - different text resets to one span in the new text format;
   - a one-shot force flag set by `setNewTextFormat` (Ruffle `avm1/globals/text_field.rs:164`) makes the next same-text assignment re-format.
4. **`textColor=` recolors every span.**
5. **after_edits only:** `replaceText` / `replaceSel` set the new text format to the format at the edit point. Ruffle *also* lacks part of this, which is why the row is KF.

**Price:** **L** (one wave-2 slot).
- Gain: `edittext_set_text_same` fail → **pass** (no KF, no sidecar; Ruffle passes it).
- Gain: `_after_edits` (KF) → **ruffle_matched**, which needs the 33 ours-only lines. Ruffle's 35 diffs are all the edit-op inheritance.
- **Total: +2 effective.**
- **Risk:** it changes the glyph renderer's input for every plain field that calls setTextFormat, so it needs a graphics `full` run plus an images canary.
- **Shared code:** the `setTextFormat` / `getTextFormat` / `setNewTextFormat` / `getNewTextFormat` arms of the AVM1 CallMethod dispatcher, `tf_get_table`, `tf_get_defaults` and `tf_apply_new_format_font`.
  - This does **not** touch `textFormatDefineLazyProps` or `lazyProtoMarkInitialized`, the sibling `w1-avm1-proto-timeline`'s `text_format_prototype_lazy` area.
  - It reads TextFormat fields via `getProperty(fmt_obj, …)`. If the sibling turns TextFormat fields into prototype accessors with native backing, these readers (and the 4 arms above) must switch to the accessor-aware getter.
  - My TextField prototype patch deliberately does **not** reuse `lazyProtoMarkInitialized`. Ruffle has no lazy TextField props, so the shared-set semantics of `lazy_prototype_shared` would be wrong here.

---

## 5. Wave-2 recommendation

1. **Land the prototype** (+46/+48/+49 lines, 0 flips, 195 riders clean).
   - CI: `graphics`, `categories=all`.
   - Add a no-graphics leg, because the createTextField and getter arms sit in `NO_GRAPHICS || OFFSCREEN_RENDER` regions and `ng_shared.c` is shared. Graphics and no-graphics output are measured identical on the headline rows.
   - Run the render canary for P14/P15.
2. **Same slot:** the S batch (phases 5-9).
3. **Second slot, M×3:** P16, P13, P17. This flips all three to ruffle_matched (+3 effective).
4. **Separate L slot:** the §4 plain-field span model (+2 effective). It shares no code with steps 1-3.

---

## 6. New unclaimed leads

- **CallMethod `createTextField` discards depth and numeric names.**
  - The same bug as P15, in the CallMethod `createTextField` arm (`(void)depth_val`).
  - A naive fix interacts with the free-function path: `_root[3]` resolves to the wrong clip, with garbage depths. It needs diagnosis.
  - Probably affects any AVM1 content that relies on `getDepth()` / z-order of `this.createTextField(...)` fields, so it likely has pixel yield.
- **Imported-SWF clip identity in general.**
  - Characters imported via ImportAssets keep `movie_id = 0` and inherit `swf_version` from the parent.
  - P0 fixes only the TextField surface, by recording the version at DefineEditText time.
  - Imported *sprites* from an SWF5 library presumably still get SWF6+ semantics (case sensitivity, `typeof`, getSWFVersion). Every gnash `actionscript.all` row uses `Dejagnu.swf` this way.
- **`restrict = ""`.** Re-test the ACCEPTED entry. Both tests are Flash, and the context rule is the open question (premise 5). No Ruffle oracle helps, because Ruffle collapses `""` to None unconditionally. It needs a Flash run or a decompile of `edittext_restrict`'s input sequence.
- **`softref` dangling typeof** (:811, :816; shared, 2 lines). `typeof` of a removed-TextField reference should be `"movieclip"`.
- **autoSize=center width 60 vs 63** (shared, 2 lines). This is probably the same device-font metric gap as P17.

## LOCAL ORACLE REQUESTS

None. The Ruffle exporter cannot arbitrate any open item: every remaining ours-only line is one Ruffle already matches Flash on, and the restrict question is Flash-vs-Flash.
