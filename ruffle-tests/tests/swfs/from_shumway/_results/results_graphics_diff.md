# Ruffle Test Results Diff

**Previous:** `fb36ba11005c` (2026-08-06T23:55:08.745504+00:00)
**Current:** `bf585e4486b6` (2026-08-12T23:11:20.760522+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 189 | 206 | +17 |
| Total | 229 | 229 | 0 |
| Pass rate | 82.5% | 90.0% | +7.5% |
| Mismatched lines | 695 | 315 | -380 |
|   Decreased | | | -380 |

## Newly Passing (17)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` | output_mismatch | 11/48 | 48/48 |
| `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` | output_mismatch | 29/70 | 70/70 |
| `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` | output_mismatch | 25/57 | 57/57 |
| `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` | output_mismatch | 15/71 | 71/71 |
| `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | output_mismatch | 10/16 | 16/16 |
| `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | ruffle_matched | 22/23 | 23/23 |
| `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` | output_mismatch | 21/50 | 50/50 |
| `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` | output_mismatch | 13/67 | 67/67 |
| `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | output_mismatch | 18/26 | 26/26 |
| `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | ruffle_matched | 18/31 | 31/31 |
| `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | output_mismatch | 14/25 | 25/25 |
| `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` | output_mismatch | 12/29 | 29/29 |
| `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75` | output_mismatch | 17/35 | 35/35 |
| `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` | output_mismatch | 17/37 | 37/37 |
| `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | output_mismatch | 16/22 | 22/22 |
| `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | output_mismatch | 14/19 | 19/19 |
| `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b` | output_mismatch | 10/24 | 24/24 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | output_mismatch | 19/43 | 31/43 | -12 |
