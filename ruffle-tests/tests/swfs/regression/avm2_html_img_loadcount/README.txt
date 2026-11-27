s30 w2-drift-smalls-land: how many htmlText <img> loads (=> unhandled ErrorEvent #2044 lines) ONE parse starts,
one case per 20 frames. Rule (avm2_text.c html_img_flush_pending_load): one load per <img src> (adjacent identical
images are NOT merged; empty src still loads) EXCEPT an image with no character after it, which starts none
(case 10 `<img src='a.jpg'><img src='b.jpg'>` -> 1).
Source: Test.as (mxmlc -target-player=11.1 -omit-trace-statements=false -static-link-runtime-shared-libraries
-default-frame-rate=30), = session30-fanout-reports/w1-local-oracles/w1-drift-smalls/html_img_loadcount/.
output.txt = REAL Flash Player 32 (LNX debug projector, direct, 340 ticks; 2 runs byte-identical), archived as
w1-local-oracles/w1-drift-smalls/html_img_loadcount.r1.lnx.txt, with ONE platform line swapped: line 4 (case 1,
src='') is `#2124: Loaded file is an unknown type` on LNX (the empty URL resolves to the SWF's directory) and
`#2035: URL Not Found` on WINDOWS FP32 (the corpus golden avm2/html_text_img_parsing, a Windows capture, prints
#2035 for its src='' case). We follow the Windows side, as the corpus golden does. All counts are the LNX capture's.
