# Session 28 — worker launch-order / id map

Mode: CLOUD-FIRST (standing user directive): every slot is a cloud session in env "SWFRecomp fan-out"
(`env_01QSs9FrDsLyis2RzQXg1UrW`), Opus, delivering on branch `fanout/<slug>`. Coordinator `s28-coordinator` local
(merge, CI dispatch, results accounting, Flash oracle, exporter `0ddd12b6a`). Size: full.
Baseline (read fresh 2026-11-25): graphics run `45547012629` at `7c3cfdcb7`, results `e1425f417`: trace 4781 eff / 4819
(4522 pass + 259 rm, 38 failing); pixels 630 pass / 39 fail / 678 comparisons (status sum; s27's "626 / 39" headline
counted differently — 0 status moves `cb14cd063` → `e1425f417`). No-graphics `2e286cf2f`: 4779 eff (40 failing).
Upstream: `efb612fd7..c2f7d24b7` → w1-drift.

## Local one-task sessions

- `trace-provenance` launched 2026-11-25 at startup (pid 1610143, cwd verified, handshake sent). DONE `9bb3276d7` (REPORT BACK verified on disk): 212/259 ruffle_matched rows have FLASH goldens (real gaps) → wave 1b `w1b-rm-{avm2,gnash,avm1-misc}`; 2 trace flash_fixes (`goto_rewind_movieclip_replace` rm→pass expected; `movieclip_hittest_shapeflag` stays mismatch). Successor local `flash-oracle-harness`.
- Browser ladder: `browser-root-goto` launched 2026-11-25 (pid 1644617, cwd verified, handshake sent): OFFSCREEN inline root-goto catch-up → browser.
- N ladder: `n-stroke-snap` launched 2026-11-25 (pid 1644898, cwd verified, handshake sent): Flash thin-stroke pixel snapping.

## Wave 1 (diagnosis, cloud)

| # | slug | task | session id |
|---|---|---|---|
| 1 | w1-acid-flash | `briefs/w1-acid-flash.md` | session_018CoDi6JnxfpNaNRyzuxogB — launched 2026-11-25 |
| 2 | w1-avm2-vector-flash | `briefs/w1-avm2-vector-flash.md` | session_018CoDi3wZhe7zdvykrZukfV — DELIVERED; culling LANDED `958313b73` (draw_triangles 1812→996, 0 flips); Flash LOW sample point (x+.5,y)/paint (x,y+.5) + HIGH = 4×4 SSAA; Flash capture of lowq probe → w2-lowq-sample-point |
| 3 | w1-drift | `briefs/w1-drift.md` | session_018CoDi5UJfjUtnXKTsT6MEU — DELIVERED (no source): drift −1 eff gnash `test4` (rm→fail: upstream deleted output.ruffle.txt; §27.4 interleave NO-GO), +1 new row `root_onload_loaded_level` pass; no PNG re-bake; Flash: proto onLoad gap → w2-root-onload-proto |
| 4 | w1-filter-residuals | `briefs/w1-filter-residuals.md` | session_018CoDi5uWF1jhfrRDKG6F9B — launched 2026-11-25 |
| 5 | w1-leads | `briefs/w1-leads.md` | session_018CoDi3t5rtjVnrzbpL8LRN — DELIVERED; shapeflag premise refuted, Flash: same-frame stale shape hitTest → w2-hittest-shape-stale; 4 queues + onUnload scope (Flash n=2) → w2-avm1-leads-land; FileReference NO-GO |
| 6 | w1-loaded-shell-residuals | `briefs/w1-loaded-shell-residuals.md` | session_018CoDi6VXdE1GrhC7pebVyf — launched 2026-11-25 |
| 7 | w1-render-flash-headroom | `briefs/w1-render-flash-headroom.md` | session_018CoDi3SHpVL9RmKCJ3YhgZ — DELIVERED: quality-harness NO-GO (our LOW is closer to Flash HIGH); Flash occupied-depth keep-both = SWF5 only (captured) → w2-occupied-depth; tie-rule evidence → n-stroke-snap; no swap in reach |
| 8 | w1-test12-enterframe | `briefs/w1-test12-enterframe.md` | session_018CoDi7N5Bch7zdwEeLUYZ4 — DELIVERED; rule = FP10 keeps a queued enterFrame of a clip removed later that tick; SWF≤7 gate refuted by Flash (v7==v8); corpus goldens Flash → w2-test12-land |
| 9 | w1-text-edit-tail | `briefs/w1-text-edit-tail.md` | session_018CoDi59FTJJJPfNtJqs7E1 — DELIVERED; Flash: restrict fires+deletes (=Ruffle), SNF defer (=Ruffle), AVM2 selection tinted (=ours, RvF) → w2-text-edit-land |
| 10 | w1-text-glyph-aa | `briefs/w1-text-glyph-aa.md` | session_018CoDi5Jv8Udc64LppZrHrZ — DELIVERED; Flash snaps glyph outlines to ¼ px (wordwrap 199→23 px vs Flash; 22 Ruffle-golden losses unpriced); rotated residual = border weight; 16-level AA NO-GO L → w2-glyph-quarter-snap |

## Wave 2 (implementation, cloud)

| slug | from | ledger (expected) | session id |
|---|---|---|---|
| w2-root-onload-proto | w1-drift + Flash captures | 2 new regression rows (Flash goldens, --no-pin) | session_018CoDi891eqd2tntZB6DyKz — launched |
| w2-occupied-depth | w1-render-flash-headroom + Flash captures | trace `place_object_test` rm→pass, `place_object_test2` rm→pass; flash_fixes `placeobject_occupied_depth` (warning lines) | session_018CoDi3xRoN7CviWpsxgTey — launched |
| w2-lowq-sample-point | w1-avm2-vector-flash + Flash lowq probe | Flash-ward vector rows; 0 Flash-golden losses required | session_018CoDi6jKqMzjzZrf6c2R4Y — launched |
| w2-avm1-leads-land | w1-leads + Flash | 4–5 regression fixtures (Flash goldens) | session_018CoDi4VAVkGy2CQUkCbfQU — launched |
| w2-hittest-shape-stale | w1-leads + Flash probe | fixture; shapeflag flash_fix (0 flips) | session_018CoDi7pH2PXPvBaoSjSrcd — launched |
| w2-text-edit-land | w1-text-edit-tail + Flash | 3 regression fixtures (Flash goldens); RvF selection tint | session_018CoDi3oPLgPKaaLnZ4fAEX — launched |
| w2-glyph-quarter-snap | w1-text-glyph-aa + Flash captures | wordwrap golden → Flash; rotated_borders fixture; priced RvF losses | session_018CoDi7ye6JuqkAj3DtMYv6 — launched |
| w1b-rm-avm2 | trace-provenance table A | rm→pass (Flash gains) by mechanism | session_018CoDi4K1YrfUyotfKco1y4 — launched (wave 1b) |
| w1b-rm-gnash | trace-provenance table A | rm→pass (Flash gains) by mechanism | session_018CoDi7EJcG2PzxYnxubmxh — launched (wave 1b) |
| w1b-rm-avm1-misc | trace-provenance table A | rm→pass (Flash gains) by mechanism | session_018CoDi4KkhjNDFiySBwY5AV — launched (wave 1b) |
