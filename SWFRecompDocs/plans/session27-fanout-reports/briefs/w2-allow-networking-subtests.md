**Make `allowNetworking` subtests gradable** (w1-drift §3). Categories: `avm2`, `avm1`, `regression`.

`avm2/allow_networking` and `local_connection_allow_networking` carry `[subtests.X].player_options.allow_networking` variants. The harness grades only the first (`all`), and the runtime has no allowNetworking mode. `50f28249e` (Ruffle) made `SharedObject.getLocal` throw `SecurityError #2146` under `none`. Ruffle's `output.none.txt` is Flash's output (`known_failure` in Ruffle only because of the SWF URL).

1. `verify_output.py`: run each subtest variant as its own graded row (name it like the existing renamed-subtest convention; check `scripts/image_status_diff.py`/`corpus_status_diff.py` "RENAMED ([subtests] split" handling and keep the results JSON schema compatible), passing the variant's player options as compile defines (pattern: `MOCK_DATE_TIME`, `MOCK_PLATFORM`).
2. Runtime: an `ALLOW_NETWORKING` define (all / internal / none) gating `SharedObject.getLocal`, `navigateToURL`/`getURL`, `Socket`, `LocalConnection`, `URLLoader`, `ExternalInterface`, etc., exactly as the two tests (and Flash's documented rules) exercise. The error text exists at `avm2_error.c:1094`.
3. Grade every new variant row before/after; the denominator grows. Name each new row and its status. Expect the CI to show NEW rows: list them for the coordinator.

Mode parity: both CI modes must agree (shared runtime code). Siblings: none in `verify_output.py` except `w2-browser-arms-land` (the `SWF_BROWSER_ARMS_TU` hook); keep your edit localized.
