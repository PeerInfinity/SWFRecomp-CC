# w2-avm1-child — AVM1-child-under-AVM2, slots 1 + 2 (session 16, wave 2)

**Agent:** `w2-avm1-child` (wave-2, worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-adfa0869c0c8fb974`).
**Base:** `cd04f80b9`. **Mode:** `--mode=graphics`, sequential/`-P 2`.
**Status of this file:** INTERIM (slot 1 measured; slot 2 in progress).

## New files created by these patches

**None.** All three patches touch existing files only:

| patch | files |
|---|---|
| `w2-avm1-child.patch` (slot 1) | `SWFModernRuntime/src/actionmodern/action.c`, `SWFModernRuntime/src/avm2/avm2_display.c` |
| `w2-avm1-child-lc.patch` (slot 2) | `SWFModernRuntime/src/actionmodern/action.c`, `SWFModernRuntime/src/avm2/avm2_net.c` |
| `w2-avm1-child-docs.patch` | `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` |

**Stacking order: slot 1 → slot 2.** Slot 2 refactors two of slot 1's own hunks
(it factors the child-context swap out of the mouse bridge into
`avm1UnderAvm2EnterChild`/`LeaveChild` and reuses it), so `w2-avm1-child-lc.patch`
does **not** apply to a tree without slot 1. `w2-avm1-child-docs.patch` is
independent of both.

## Verdicts

| slot | verdict | flips |
|---|---|---|
| 1 — depth `-77824` + `#2180` + mouse broadcast bridge | **GO, measured** | `mixed_avm/avm2_loads_avm1` **output_mismatch → pass**; `_v10` 3 differing lines → 1 |
| 2 — cross-VM LocalConnection | (pending) | target: `mixed_avm/avm2_loads_avm1_v9`, `_v10` → pass |
| docs — `avm2/avm1_root` RUFFLE_VS_FLASH entry | **written** | 0 (documentation) |

(Ledger, mechanism notes and the NO-GO record are filled in below as runs land.)
