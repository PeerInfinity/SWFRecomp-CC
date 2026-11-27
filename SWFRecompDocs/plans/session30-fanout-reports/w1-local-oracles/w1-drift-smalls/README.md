# w1-drift-smalls LOCAL ORACLE REQUESTS (s30 coordinator, 2026-11-27, FP32 LNX direct pinned)

1. `tabindex_clip_button.v{6,8}.lnx.txt` (the slot's `tabindex_clip_button/{v6,v8}/test.swf`): FP32 agrees with
   Ruffle's model on clips, script clips AND buttons: `-1` → `undefined` (the u32 `-1` sentinel unsets), `-2` stays,
   `-2147483648` stays, `delete x.tabIndex` returns **false** and keeps the value (4). Ours: `-1` → `-1`, delete → true +
   unset. So wave 2 = the two arms without the `MC_IS_TEXTFIELD` gates (v6 == v8 here).
2. `html_img_loadcount.r{1,2}.lnx.txt` (`html_img_loadcount/` = the slot's `Test.as`, built with mxmlc
   `-target-player=11.1 -omit-trace-statements=false -static-link-runtime-shared-libraries -default-frame-rate=30`,
   340 ticks): the two runs are byte-identical. `#2044` count per case:
   0:1, 1:1, 2:2, 3:2, 4:2, 5:2, 6:2, 7:2, 8:2, 9:2, **10 (`<img src='a.jpg'><img src='b.jpg'>`, no text): 1**, 11:1,
   12:1, 13 (reparse): 2. So adjacent identical images are NOT merged for loading; the one case with fewer loads than
   `<img src>` tags is two images with no text around them.
3. `avm2/xmldocument_tostring`: not run (row not in the local download yet; optional).
