# Ruffle Test Results Diff

**Previous:** `e0af5c2d15d5` (2026-05-07T03:24:59.825253+00:00)
**Current:** `873e520ed49f` (2026-05-07T16:51:19.143657+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 68 | 72 | +4 |
| Total | 92 | 92 | 0 |
| Pass rate | 73.9% | 78.3% | +4.4% |
| Mismatched lines | 589 | 400 | -189 |
|   Decreased | | | -189 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | ruffle_matched | 1/3 | 3/3 |
| `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | output_mismatch | 0/7 | 7/7 |
| `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | ruffle_matched | 1/3 | 3/3 |
| `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | output_mismatch | 1/5 | 5/5 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | output_mismatch | ruffle_matched | 2/23 | 22/23 |
| `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | output_mismatch | ruffle_matched | 6/31 | 18/31 |

## Line Count Changed (11)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` | output_mismatch | 5/70 | 29/70 | -24 |
| `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` | output_mismatch | 3/57 | 25/57 | -22 |
| `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` | output_mismatch | 1/50 | 21/50 | -20 |
| `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | output_mismatch | 1/22 | 16/22 | -15 |
| `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | output_mismatch | 1/25 | 14/25 | -13 |
| `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | output_mismatch | 3/19 | 14/19 | -11 |
| `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | output_mismatch | 8/26 | 18/26 | -10 |
| `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75` | output_mismatch | 7/35 | 17/35 | -10 |
| `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` | output_mismatch | 9/37 | 17/37 | -8 |
| `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` | output_mismatch | 9/71 | 15/71 | -6 |
| `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` | output_mismatch | 10/67 | 13/67 | -3 |
