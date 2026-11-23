# Ruffle Test Results Diff

**Previous:** `7e14f54dd961` (2026-11-23T22:39:55.346384+00:00)
**Current:** `005bea42a286` (2026-11-23T23:56:28.951873+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1285 | 1241 | -44 |
| Total | 1339 | 1294 | -45 |
| Pass rate | 96.0% | 95.9% | -0.1% |
| Mismatched lines | 2308 | 2308 | 0 |

## Missing Tests — Shard Failure (45)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 44 were previously passing
- 1 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `displayobject_mask` | pass | 3/3 |
| `displayobject_mask_self_referential` | pass | 0/0 |
| `displayobject_metaData` | pass | 3/3 |
| `displayobject_name` | pass | 22/22 |
| `displayobject_name_from_timeline` | pass | 24/24 |
| `displayobject_opaque_background` | pass | 6/6 |
| `displayobject_parent` | pass | 12/12 |
| `displayobject_root` | pass | 24/24 |
| `displayobject_rotation` | pass | 1284/1284 |
| `displayobject_scrollrect` | pass | 33/33 |
| `displayobject_set_matrix_nested` | pass | 0/0 |
| `displayobject_set_name_loaded` | pass | 3/3 |
| `displayobject_subclass` | pass | 2/2 |
| `displayobject_transform` | pass | 89/89 |
| `displayobject_visible` | pass | 23/23 |
| `displayobject_width` | pass | 4852/4852 |
| `displayobject_x` | pass | 614/614 |
| `displayobject_y` | pass | 617/617 |
| `displayobject_z` | pass | 38/38 |
| `displayobjectcontainer_addchild` | pass | 32/32 |
| `displayobjectcontainer_addchild_lazy_sprite` | pass | 1/1 |
| `displayobjectcontainer_addchild_timelinepull0` | pass | 58/58 |
| `displayobjectcontainer_addchild_timelinepull1` | pass | 60/60 |
| `displayobjectcontainer_addchild_timelinepull2` | pass | 62/62 |
| `displayobjectcontainer_addchildat` | pass | 42/42 |
| `displayobjectcontainer_addchildat_timelinelock0` | pass | 34/34 |
| `displayobjectcontainer_addchildat_timelinelock1` | pass | 34/34 |
| `displayobjectcontainer_addchildat_timelinelock2` | pass | 34/34 |
| `displayobjectcontainer_contains` | pass | 66/66 |
| `displayobjectcontainer_getchildat` | pass | 4/4 |
| `displayobjectcontainer_getchildbyname` | pass | 9/9 |
| `displayobjectcontainer_getchildbyname_wrongcase` | pass | 5/5 |
| `displayobjectcontainer_getchildindex` | pass | 28/28 |
| `displayobjectcontainer_getobjectsunderpoint` | pass | 15/15 |
| `displayobjectcontainer_remove_reentrant` | pass | 257/257 |
| `displayobjectcontainer_remove_reparent` | pass | 189/189 |
| `displayobjectcontainer_removechild` | pass | 10/10 |
| `displayobjectcontainer_removechild_errors` | pass | 4/4 |
| `displayobjectcontainer_removechild_timelinemanip_remove1` | pass | 38/38 |
| `displayobjectcontainer_removechildat` | pass | 18/18 |
| `displayobjectcontainer_removechildren` | pass | 51/51 |
| `displayobjectcontainer_removechildren_events` | pass | 56/56 |
| `displayobjectcontainer_setchildindex` | pass | 42/42 |
| `displayobjectcontainer_stopallmovieclips` | pass | 2/2 |
| `displayobjectcontainer_stopallmovieclips_nonconstructed` | ruffle_matched | 19/19 |

</details>
