# w2-loaded-shell-land E: onLoadProgress count, FP32 Linux + Windows (s28 coordinator, 2026-11-25)

| row | golden | Linux | Windows | Windows vs predicted |
|---|---|---|---|---|
| mcl_unloadclip | 1 | 2 | 2 | == |
| mcl_loadclip | 5 | 10 | 10 | == (Flash adds a trailing blank line) |
| mcl_target_png / jpg / gif87a / gif89a, mcl_mislabeled_target | 1 | 3 | 2 | == |

Linux adds one progress event per 4096-byte read (host I/O). The 1x goldens are Flash on neither OS. flash_fixes use the Windows (corpus-platform) capture.
