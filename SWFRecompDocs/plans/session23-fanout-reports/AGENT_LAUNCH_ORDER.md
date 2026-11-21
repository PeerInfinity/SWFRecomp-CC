# Session 23 — worker launch-order / id map

Mode: CLOUD-FIRST (user directive 2026-10-16, re-confirmed 2026-11-21): every slot is a cloud session in env
"SWFRecomp fan-out" (`env_01QSs9FrDsLyis2RzQXg1UrW`), Opus, delivering on branch `fanout/<slug>`. Coordinator
local (merge, CI dispatch, results accounting, exporter oracle).
Session-start infra fix: `08709f658` pins CI runners to `ubuntu-24.04` (`ubuntu-latest` = 26.04 has no
swfmill; the weekly canary's WASM link-smoke had failed 4 weeks running; also keeps CI lavapipe == cloud env).
Baseline runs at `08709f658` (upstream `0ddd12b6a`): graphics/full/images `44922638965`, no-graphics/full
`44922646202`.

## Wave 1 (diagnosis) + direct wave-2 slots

| # | slug | axis | task | session id |
|---|---|---|---|---|
