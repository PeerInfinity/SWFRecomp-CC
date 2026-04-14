# Ruffle Test Results Diff

**Previous:** `83d3748a6081` (2026-04-13T19:34:06.417766+00:00)
**Current:** `1d207c167423` (2026-04-13T23:00:07.773024+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 17 | 48 | +31 |
| Total | 47 | 92 | +45 |
| Pass rate | 36.2% | 52.2% | +16.0% |
| Mismatched lines | 221 | 648 | +427 |

## Added Tests (82)

| Test | Status | Lines |
|------|--------|-------|
| `avm1/array` | pass | 7/7 |
| `avm1/bitmapdata/getPixel` | pass | 2/2 |
| `avm1/bitmapdata/loadBitmap` | output_mismatch | 0/3 |
| `avm1/callee` | pass | 2/2 |
| `avm1/depth` | pass | 6/6 |
| `avm1/doactionorder/doactionorder` | output_mismatch | 3/7 |
| `avm1/doactionorder/symbolclass` | pass | 4/4 |
| `avm1/duplicateMovieClip/dontremove` | output_mismatch | 3/6 |
| `avm1/duplicateMovieClip/duplicateMovieClip` | output_mismatch | 1/4 |
| `avm1/duplicateMovieClip/name-coercion` | output_mismatch | 1/3 |
| `avm1/duplicateMovieClip/samedepth` | output_mismatch | 4/6 |
| `avm1/externalinterface` | pass | 4/4 |
| `avm1/filters` | pass | 149/149 |
| `avm1/haxe/flocons1` | pass | 2/2 |
| `avm1/haxe/flocons2` | output_mismatch | 2/3 |
| `avm1/hitarea` | output_mismatch | 2/4 |
| `avm1/label` | pass | 4/4 |
| `avm1/levels` | pass | 9/9 |
| `avm1/loadevent` | pass | 9/9 |
| `avm1/loadvariables/loadvariables` | pass | 7/7 |
| `avm1/loadvariables/loadvars` | output_mismatch | 0/2 |
| `avm1/lookup` | pass | 3/3 |
| `avm1/mouse-transparency` | pass | 1/1 |
| `avm1/moviecliploader` | output_mismatch | 1/7 |
| `avm1/nativeinheritance` | pass | 6/6 |
| `avm1/nested-button` | pass | 1/1 |
| `avm1/operations` | pass | 13/13 |
| `avm1/property-paths/property-paths-6` | output_mismatch | 5/6 |
| `avm1/property-paths/property-paths-7` | pass | 7/7 |
| `avm1/propertycase/propertycase` | pass | 7/7 |
| `avm1/propertycase/propertycase-preserving-6` | output_mismatch | 0/2 |
| `avm1/propertycase/propertycase-preserving-7` | pass | 5/5 |
| `avm1/rollover` | pass | 4/4 |
| `avm1/scope` | pass | 14/14 |
| `avm1/setinterval` | pass | 20/20 |
| `avm1/settimeout` | pass | 17/17 |
| `avm1/super` | pass | 11/11 |
| `avm1/target` | pass | 18/18 |
| `avm1/text-bind` | pass | 0/0 |
| `avm1/textfield/textfield-html` | output_mismatch | 3/4 |
| `avm1/textfield/textfield-text-setters` | output_mismatch | 4/8 |
| `avm1/undefined/undefined-swf6` | pass | 39/39 |
| `avm1/undefined/undefined-swf7` | pass | 39/39 |
| `avm1/watch` | pass | 2/2 |
| `avm1/xml/xmlbuild` | pass | 1/1 |
| `avm1/xml/xmlload` | output_mismatch | 0/4 |
| `avm1/xml/xmlstring` | pass | 9/9 |
| `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | output_mismatch | 3/6 |
| `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` | output_mismatch | 11/48 |
| `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | pass | 0/0 |
| `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | output_mismatch | 1/3 |
| `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | output_mismatch | 1/1 |
| `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` | output_mismatch | 6/70 |
| `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` | output_mismatch | 8/57 |
| `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` | output_mismatch | 12/71 |
| `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | output_mismatch | 6/16 |
| `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | output_mismatch | 0/7 |
| `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | output_mismatch | 3/23 |
| `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` | output_mismatch | 6/50 |
| `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` | output_mismatch | 5/67 |
| `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | pass | 0/0 |
| `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | output_mismatch | 2/26 |
| `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | output_mismatch | 3/3 |
| `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | output_mismatch | 7/31 |
| `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | pass | 0/0 |
| `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | output_mismatch | 0/3 |
| `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | output_mismatch | 3/25 |
| `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | output_mismatch | 5/8 |
| `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` | output_mismatch | 9/29 |
| `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | output_mismatch | 1/5 |
| `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75` | output_mismatch | 9/35 |
| `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | output_mismatch | 4/6 |
| `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` | output_mismatch | 3/37 |
| `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | output_mismatch | 12/43 |
| `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | output_mismatch | 3/22 |
| `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | output_mismatch | 3/19 |
| `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b` | output_mismatch | 7/24 |
| `timeline/timeline_as2_1` | output_mismatch | 0/3 |
| `timeline/timeline_as2_2` | pass | 3/3 |
| `timeline/timeline_as2_3` | pass | 3/3 |
| `timeline/timeline_as2_4` | pass | 2/2 |
| `timeline/timeline_as2_5` | output_mismatch | 1/4 |

## Removed Tests (37)

| Test | Previous Status | Lines |
|------|----------------|-------|
| `3_joystick` | output_mismatch | 0/4 |
| `MaskTest` | pass | 0/0 |
| `MaskTest-2` | pass | 0/0 |
| `MaskTest-3` | output_mismatch | 0/4 |
| `ZeroClipboardTest` | output_mismatch | 0/3 |
| `as3-interfaces` | output_mismatch | 0/6 |
| `avm1movie` | output_mismatch | 0/13 |
| `bitmapbuttons` | pass | 0/0 |
| `button1` | output_mismatch | 0/1 |
| `button2` | output_mismatch | 0/1 |
| `captions` | output_mismatch | 0/8 |
| `clipping` | pass | 0/0 |
| `encoding1` | output_mismatch | 0/31 |
| `esc` | output_mismatch | 0/2 |
| `flash_events_Event` | output_mismatch | 0/3 |
| `flash_geom_ColorTransform` | pass | 0/0 |
| `flash_net_SharedObject` | output_mismatch | 0/4 |
| `flash_net_URLLoader` | output_mismatch | 0/7 |
| `flash_net_URLRequest` | output_mismatch | 0/6 |
| `flash_net_classes` | output_mismatch | 0/22 |
| `flash_text_TextField` | pass | 0/0 |
| `flash_text_TextField2` | output_mismatch | 0/18 |
| `flash_utils_Timer` | output_mismatch | 0/2 |
| `getobjectsunderpoint` | output_mismatch | 0/34 |
| `gradient` | pass | 0/0 |
| `hardwrap` | output_mismatch | 0/1 |
| `hitTestStyleChange` | output_mismatch | 0/1 |
| `image-loading` | output_mismatch | 0/4 |
| `local2global` | output_mismatch | 0/1 |
| `localconnection` | output_mismatch | 0/12 |
| `lzma` | output_mismatch | 0/5 |
| `lzma_bytes` | output_mismatch | 0/2 |
| `movieclip` | output_mismatch | 0/9 |
| `slider_component` | output_mismatch | 0/4 |
| `stream1` | output_mismatch | 0/9 |
| `stroke1` | output_mismatch | 0/1 |
| `stylesheet` | output_mismatch | 0/3 |
