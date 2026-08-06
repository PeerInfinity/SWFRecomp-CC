# Graphics vs Trace Mode Differences

Trace: 1084/1225 passing | Graphics: 1105/1226 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (20 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `constructsuper_null` | Output Mismatch | 0/2 lines match |
| 2 | `cross_api_version_call_newer` | Output Mismatch | 11/12 lines match |
| 3 | `currency_parse_result` | Output Mismatch | 0/7 lines match |
| 4 | `doabc_and_symbolclass_script_init_goto` | Output Mismatch | 1/8 lines match |
| 5 | `doabc_and_symbolclass_script_init_normal` | Output Mismatch | 1/6 lines match |
| 6 | `error_stack_trace_edge_cases` | Output Mismatch | 0/6 lines match |
| 7 | `error_throwerror` | Output Mismatch | 6/103 lines match |
| 8 | `graphic_linkage` | Output Mismatch | 7/9 lines match |
| 9 | `json_stringify_function` | Output Mismatch | 0/12 lines match |
| 10 | `netfilterevent` | Output Mismatch | 0/10 lines match |
| 11 | `perspective_projection` | Output Mismatch | 1368/1443 lines match |
| 12 | `primitive_toString` | Output Mismatch | 20/277 lines match |
| 13 | `primitive_valueOf` | Output Mismatch | 25/285 lines match |
| 14 | `property_is_enumerable` | Output Mismatch | 25/114 lines match |
| 15 | `proxy_not_overridden` | Output Mismatch | 4/54 lines match |
| 16 | `stage_properties2` | Output Mismatch | 23/213 lines match |
| 17 | `static_length` | Output Mismatch | 11/24 lines match |
| 18 | `system_exit` | Output Mismatch | 0/3 lines match |
| 19 | `timer_invalid_delay` | Output Mismatch | 1/30 lines match |
| 20 | `xml_list_ctor_errors` | Output Mismatch | 5/34 lines match |
