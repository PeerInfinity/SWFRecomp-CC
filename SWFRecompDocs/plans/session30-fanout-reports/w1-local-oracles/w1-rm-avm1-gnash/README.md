# w1-rm-avm1-gnash LOCAL ORACLE REQUESTS (s30 coordinator, 2026-11-27)

FP32 LNX, direct pinned (`tools/flash-oracle/run_trace.py --swf`). Fixture sources copied from
`fanout/w1-rm-avm1-gnash` (`w1-rm-avm1-gnash-fixtures/`); SWFs rebuilt locally with the slot's scripts.

## 1. `avm1_asnative_mc_probe/` (`swf5.lnx.txt`, `swf6.lnx.txt`, 3 frames)

| section | SWF5 FP32 | SWF5 ours-prototype | SWF6 FP32 | SWF6 ours-prototype |
|---|---|---|---|---|
| A bare call of a var holding `ASnative(901,0)` | movieclip | same | movieclip, depth 10 | same |
| **B** SWF5 bare `createEmptyMovieClip` after `MovieClip.prototype.createEmptyMovieClip = ASnative(901,0)` | **movieclip `_level0.a2`** | **undefined** | movieclip | same |
| C own property `_root.mk` | movieclip | same | movieclip | same |
| **D** `ASnative(901,0) == MovieClip.prototype.createEmptyMovieClip`; two ASnative calls equal | true / true | same | **false / false** | **true / true** |
| E `ASnative(900,10)` as `a3.gd` | 12 | same | 12 | same |
| F bare `cs("inner",1)` inside a method of `a3` | none anywhere | same | lands on `_root` | same |

- **B: FP32 clears (or ignores) the SWF5 version-hide flag when a script SetMembers the prototype member.** Ruffle
  keeps it (`script_object.rs` set_local keeps attributes) → RvF entry when it lands. This is Sound-v5's half (a).
- **D (SWF6): ASnative hands out a FRESH function object per call**, not the prototype's stub (the `asnative_sweep`
  comment was right). SWF5 prints true/true (SWF5 equality of function values); the prototype matches there.
  Wave 2: return a fresh native wrapper per `ASnative(900|901, n)` call in SWF6+ (or document if the gnash rows don't
  care: none of the 11 ledger rows tests identity).

## 2. `embeddedfont_smalltext_probe/` (`on.lnx.txt`, `off.lnx.txt`, 30 frames)

- `smalltext_on` (= the corpus SWF) reproduces the golden **byte-for-byte** (sanity).
- `smalltext_off`: `textWidth` 43, 72, 214, 144, 172, … = the unrounded per-glyph sums truncated (slot's estimates
  43.6, 73.0, 215.1, 145.4, 173.1), and the range checks FAIL.
- **Verdict: the per-glyph `ceil(advance × size/1024)` rule is SmallText-only.** No re-pricing of other embedded-font
  `textWidth` rows is needed. Price S-M: recompiler font case emits the DefineFont2/3 SmallText flag (bit 0x20),
  TextField metrics ceil per glyph for those fonts only.
