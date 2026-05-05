# Ruffle Test Results Diff

**Previous:** `e707c6896265` (2026-05-05T02:00:55.906805+00:00)
**Current:** `6d85246e682b` (2026-05-05T02:48:30.205566+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 65 | 68 | +3 |
| Total | 92 | 92 | 0 |
| Pass rate | 70.7% | 73.9% | +3.2% |
| Mismatched lines | 610 | 589 | -21 |
|   Decreased | | | -43 |
|   Increased | | | +22 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | output_mismatch | 3/6 | 6/6 |
| `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | output_mismatch | 5/8 | 8/8 |
| `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | output_mismatch | 4/6 | 6/6 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | output_mismatch | ruffle_matched | 0/3 | 1/3 |

## Line Count Changed (16)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | output_mismatch | 12/43 | 19/43 | -7 |
| `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | output_mismatch | 2/26 | 8/26 | -6 |
| `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` | output_mismatch | 3/37 | 9/37 | -6 |
| `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` | output_mismatch | 5/67 | 10/67 | -5 |
| `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | output_mismatch | 6/16 | 10/16 | -4 |
| `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` | output_mismatch | 9/29 | 12/29 | -3 |
| `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b` | output_mismatch | 7/24 | 10/24 | -3 |
| `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` | output_mismatch | 6/70 | 5/70 | +1 |
| `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | output_mismatch | 3/23 | 2/23 | +1 |
| `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | output_mismatch | 7/31 | 6/31 | +1 |
| `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | output_mismatch | 3/25 | 1/25 | +2 |
| `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75` | output_mismatch | 9/35 | 7/35 | +2 |
| `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | output_mismatch | 3/22 | 1/22 | +2 |
| `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` | output_mismatch | 12/71 | 9/71 | +3 |
| `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` | output_mismatch | 8/57 | 3/57 | +5 |
| `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` | output_mismatch | 6/50 | 1/50 | +5 |
