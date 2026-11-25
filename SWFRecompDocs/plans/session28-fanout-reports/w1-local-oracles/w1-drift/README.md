# w1-drift local Flash oracles (s28 coordinator, 2026-11-25; FP32 LNX, direct)

| request | file | result |
|---|---|---|
| 0 control `avm1/root_onload` `--no-pin` | `root_onload.nopin.txt` | `_root.onLoad was called` == golden |
| 0 control `avm1/root_onload` pinned | `root_onload.pinned.txt` | **empty**: the pin stub loads the test over `_level0`, and Flash fires no frame-1 onLoad for a replaced `_level0`. **Harness trap: re-run root-onLoad rows `--no-pin`.** |
| 1 `avm1_root_onload_child_order` `--no-pin` | `avm1_root_onload_child_order.flash32.nopin.txt` | == ours for all 11 lines (then direct-mode overrun `kid enterFrame` lines). No change needed |
| 2 `avm1_root_onload_proto` `--no-pin` | `avm1_root_onload_proto.flash32.nopin.txt` | **≠ ours**: after `root f1`, Flash prints `proto onLoad _global` then `proto onLoad _level0`, before `f1 of _level0.b`. We print neither. No line for `_level0.b` or `_level0.a`. → wave-2 slot |
