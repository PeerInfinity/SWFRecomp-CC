# Graphics vs Trace Mode Differences

Trace: 189/229 passing | Graphics: 207/229 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (18 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` | Output Mismatch | 11/92 lines match |
| 2 | `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` | Output Mismatch | 29/96 lines match |
| 3 | `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` | Output Mismatch | 25/75 lines match |
| 4 | `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` | Output Mismatch | 15/173 lines match |
| 5 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | Output Mismatch | 10/18 lines match |
| 6 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | Ruffle Matched | 22/26 lines match |
| 7 | `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` | Output Mismatch | 21/75 lines match |
| 8 | `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` | Output Mismatch | 13/108 lines match |
| 9 | `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | Output Mismatch | 18/32 lines match |
| 10 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | Ruffle Matched | 18/38 lines match |
| 11 | `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | Output Mismatch | 14/28 lines match |
| 12 | `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` | Output Mismatch | 12/36 lines match |
| 13 | `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75` | Output Mismatch | 17/41 lines match |
| 14 | `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` | Output Mismatch | 17/63 lines match |
| 15 | `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | Output Mismatch | 19/63 lines match |
| 16 | `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | Output Mismatch | 16/32 lines match |
| 17 | `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | Output Mismatch | 14/19 lines match |
| 18 | `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b` | Output Mismatch | 10/26 lines match |
