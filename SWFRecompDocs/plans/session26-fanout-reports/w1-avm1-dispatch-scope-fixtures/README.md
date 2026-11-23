# s26 w1-avm1-dispatch-scope fixtures (staged, not yet in `regression/`)

Hand-assembled AVM1 SWFs (no MTASC in the cloud). `avm1asm.py` is the shared
assembler; each `avm1_*/create_test_swf.py` documents what it pins and the
Ruffle source it follows. Rebuild all: `./build_all.sh`.

Run one (any mode):

```bash
python3 ruffle-tests/verify_output.py \
  --tests-dir=SWFRecompDocs/plans/session26-fanout-reports/w1-avm1-dispatch-scope-fixtures \
  --test=avm1_bare_mc_method_scope [--mode=graphics] --diff --verbose
```

**Every `output.txt` here is ANALYTIC** (written from Ruffle source, then
checked against our prototype). None is a Ruffle exporter trace yet. See
the report's LOCAL ORACLE REQUESTS. When a trace comes back, replace
`output.txt` with it and move the directory to `ruffle-tests/tests/swfs/regression/`.

| fixture | item | exporter-able? | master | prototype |
|---|---|---|---|---|
| `avm1_bare_mc_method_scope` | 1 | yes, 5 frames | 7/19 | pass |
| `avm1_type2_mc_receiver_dispatch` | 2 (L2) | yes, 2 frames | 6/7 | pass |
| `avm1_timer_function_form_activation` | 2 (L3) | **no** (timers; analytic golden) | 0/3 | pass |
| `avm1_hittest_hairline` | 3 | yes, 5 frames | 25/28 no-graphics; pass graphics | pass both |
| `avm1_create_text_field_depth` | 4 + 6 | yes, 2 frames | 1/9 | pass |
| `avm1_edittext_html_typed_runs` | 5 | **no** (`input.json` typing; analytic) | 1/3 | pass |
| `avm1_set_new_text_format_color` | 5 | yes, 2 frames | pass (trace lock) | pass |
| `avm1_device_edittext_xscale` | 7 | yes, 2 frames (absolute widths are device-font dependent) | 3/7 | pass |
| `avm1_wrap_giveup_mixed_runs` | 7 | yes, 2 frames (SWF7) | 0/2 | 0/2 (not prototyped) |
| `avm1_mc_resolve` | new lead | yes, 2 frames | 0/5 | 0/5 (not prototyped) |

`scan_bare_calls.py ROOT...` is the corpus census of bare (`ActionCallFunction`)
MovieClip-method calls by context (with / function / sprite / root / button).
