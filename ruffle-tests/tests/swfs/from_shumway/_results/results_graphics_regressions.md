# Graphics vs Trace Mode Differences

Trace: 73/92 passing | Graphics: 58/92 passing

## Graphics Regressions (15 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `avm1/duplicateMovieClip/dontremove` | Output Mismatch | 3/6 lines match |
| 2 | `avm1/duplicateMovieClip/samedepth` | Output Mismatch | 4/6 lines match |
| 3 | `avm1/mouse-transparency` | Output Mismatch | 0/1 lines match |
| 4 | `avm1/nested-button` | Output Mismatch | 0/1 lines match |
| 5 | `button3` | Output Mismatch | 0/1 lines match |
| 6 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | Output Mismatch | 4/48 lines match |
| 7 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | Ruffle Matched | 1/3 lines match |
| 8 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | Output Mismatch | 4/51 lines match |
| 9 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | Output Mismatch | 2/28 lines match |
| 10 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | Output Mismatch | 2/57 lines match |
| 11 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | Output Mismatch | 4/54 lines match |
| 12 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | Ruffle Matched | 1/5 lines match |
| 13 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | Output Mismatch | 3/51 lines match |
| 14 | `movieinfo1` | Output Mismatch | 1/3 lines match |
| 15 | `timeline/timeline_as2_1` | Output Mismatch | 3/10 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
