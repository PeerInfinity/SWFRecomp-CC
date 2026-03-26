# Ruffle Test Results Index

| Category | Pass | Total | Rate | Report | Filtered |
|----------|-----:|------:|-----:|--------|----------|
| avm1 | 548 | 608 | 90.1% | [results](tests/swfs/avm1/_results/results.md) | [filtered](tests/swfs/avm1/_results/results_filtered.md) (547/564, 97.0%) | **⚠️ 30/30 shards**
| from_gnash/actionscript.all | 51 | 190 | 26.8% | [results](tests/swfs/from_gnash/actionscript.all/_results/results.md) | [filtered](tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) (51/181, 28.2%) |
| from_gnash/misc-swfmill.all | 11 | 14 | 78.6% | [results](tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) | [filtered](tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) (11/14, 78.6%) |
| from_shumway | 17 | 47 | 36.2% | [results](tests/swfs/from_shumway/_results/results.md) | [filtered](tests/swfs/from_shumway/_results/results_filtered.md) (17/17, 100.0%) |
| from_shumway/avm1 | 12 | 23 | 52.2% | [results](tests/swfs/from_shumway/avm1/_results/results.md) | [filtered](tests/swfs/from_shumway/avm1/_results/results_filtered.md) (12/23, 52.2%) |

### ⚠️ Incomplete runs

- **avm1**: 30/30 shards produced results (0 missing). Some tests may be absent due to shard failure, not code changes.

### avm1 failures

| Category | Count |
|----------|------:|
| output_mismatch | 57 |
| runtime_segfault | 2 |
| timeout | 1 |

### from_gnash/actionscript.all failures

| Category | Count |
|----------|------:|
| output_mismatch | 139 |

### from_gnash/misc-swfmill.all failures

| Category | Count |
|----------|------:|
| output_mismatch | 3 |

### from_shumway failures

| Category | Count |
|----------|------:|
| output_mismatch | 30 |

### from_shumway/avm1 failures

| Category | Count |
|----------|------:|
| output_mismatch | 10 |
| runtime_error | 1 |
