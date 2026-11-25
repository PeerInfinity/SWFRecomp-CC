# flash-oracle-harness (s28 one-task, LOCAL, 2026-11-25)

Successor to `trace-provenance` (§"Harness findings"). Scope: `tools/flash-oracle/` only. README updated, memory
`flash-player-oracle` updated.

## What changed

| § | Fix | Proof |
|---|---|---|
| 1 | `flashenv.parse_rect`: a 0-bit RECT is legal (all zero). It no longer shifts by −1. | swfmill `tags_after_last_showframe` BYTE-IDENTICAL; verdict **untestable → golden = Flash** |
| 2 | New stub `capture/System/PinStub.as`. The class lives in the EXISTING `System` package, so MTASC's prologue GetVariable hits a real name and logs no "undeclared variable" warning. It deletes `_global.System.PinStub` first and keeps its state in closures. It sets `mc._quality`. | `global_proto_decls` pinned, no flags: BYTE-IDENTICAL. `global_proto_decls_delete` and `argstest-v7` pinned == their `--no-pin` results (only the host `manufacturer` line differs). Pin still holds: `displayobject_scrollrect` BYTE-IDENTICAL. A probe shows an empty `_global` enumeration apart from the test's own class. |
| 3 | `flashenv.run_cap`: (frames+1)/**real** rate + 2 s, plus the pin's cost (2.5 s, or 4 s on Windows, + 3 stub frame periods). Overrun: while flashlog is still growing at the cap, the run continues until 0.5 s quiet, for up to max(5 s, length). A run still writing at the end gives `stop=TRUNCATED` and a boxed WARNING. `pin=None` (the stub never released) also gives a boxed WARNING. `sweep_goldens --direct` now uses the real rate too. | `goto_queued_invalid/swf9` (0.25 fps) by default: the golden is a prefix (its first trace comes at 13.7 s because the stub polls at 0.25 fps). An every-frame tracer gives TRUNCATED + warning. |
| 4 | `run_trace.py` turns `--log-warnings` on when `output.txt` has a `Warning: ` line. | 8 corpus goldens qualify: `set_property_values/swf4`, `global_proto_decls_delete`, `movieclip_onconstruct`, `placeobject_occupied_depth`, `sound_owner_tostring_fail`, `uncaught_exception(_bubbled)`, one shumway fuzz. All 8 == golden pinned with it (`_delete` differs only on its manufacturer line). |
| 5 | `flashenv.root_onload_defined`: a symbolic scan of the root timeline's frame-1 DoActions. It matches `function onLoad`, `onLoad =` and `_root`/`_level0`/`this.onLoad =`, case-folded for SWF ≤ 6. Function bodies are skipped. `run_trace.py` runs a match **unpinned** with a NOTE; `--force-pin` overrides. | It flags exactly 4 of the 4 850 corpus SWFs: the 3 named rows + `regression/onload_type1_args`. All 3 named rows are BYTE-IDENTICAL by default. |
| 6 | trace-provenance rows re-run: 10 rows carry an appended "harness re-run" note, and a pointer paragraph sits under §Harness findings. | see that doc |
| 7 (coordinator) | Re-captured every pinned AVM1 `quality = "low"` image capture that a verdict depends on. Each new file is saved with a `.newstub` suffix, and both READMEs carry a table. | below |

## Overturned / new

- **The old stub never applied quality.** Its unqualified `_quality = …` set `_global._quality`, and a probe traced
  `HIGH`. So **every pinned direct capture of an AVM1 quality=low row before 2026-11-25 was really HIGH**. The s27
  README claim "`_quality` traces LOW" was wrong for this stub. Consequences:
  - gnash `place_object_test` and `shape_test` now **PASS** their goldens. They were 5 209 / 1 071 px, booked
    "not FP32" and "deferred swap/keep". Their goldens ARE Flash at low quality, so our miss there is a real Flash gap.
  - `movieclip_setmask` 16→8 px and `missing_bitmap` 4→16 px; both verdicts are unchanged.
  - The w1-text-glyph-aa filter rows improved but are still not Flash. `String_path_variable_button` is now captured
    (778 px; its old "no capture" did not reproduce).
  - The memory note "some goldens are Flash at DEFAULT high though toml says low" is now marked SUSPECT for pinned-direct
    AVM1 evidence.
- **The `flash_text_TextField` half of finding 3 was not truncation.** Its golden is empty: Flash prints only FAIL
  lines, and it has none.
- 8 parallel Linux projector runs: the pin gate never released (`pin=None`), so the test never ran. 3–4 in parallel is
  fine. The README says ≤ 4, and run_trace now warns.
- `FLASH_ORACLE_PIN_STUB=<swf>` overrides the stub for A/Bs. The old stub is not kept in the tree; rebuild it from git
  history (`capture/PinStub.as` before this commit) if needed.

## Not done / next

- `run_image.py`/`sweep_goldens.py` don't auto-unpin on a root onLoad (images rarely depend on it).
- Other s27 rows graded "direct (pinned)" at quality low were AVM2 (unaffected) or high. Any later session that
  graded AVM1 low-quality rows from pinned captures (besides the two sets re-captured here) should re-capture.
