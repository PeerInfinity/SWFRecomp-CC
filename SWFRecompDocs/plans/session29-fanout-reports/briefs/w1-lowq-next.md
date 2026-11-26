**Flash LOW quality model, next slice: the .5-tie rule and the LOW stroke y rule (M, diagnosis + measured prototype).**

State of record: `session28-fanout-reports/lowq-corner-rule-report.md` (model landed `ed63ce7c4`; §6 ledger; §3 table and
gates), `w2-lowq-sample-point-report.md`, `snap-pixel-audit-report.md` (defect D1: LOW AA-centre ¼-px quantisation), and
`w1-local-oracles/interim6-low/README.md` (ours→FP32 vs golden→FP32 tables). Measured-and-reverted in s28: a y-rule .5
epsilon (Flash's tie direction depends on the .5's SOURCE), and exempting strokes from the y rule (hurts Flash-golden
`graphics_simple_shapes` + the probe).
1. **.5-tie probe** (`avm2_button_scroll_rect` and the rows lowq named): design a fixture that separates tie sources
   (object translation .5 vs vertex .5 vs scrollRect .5 vs stroke half-width .5) at LOW, ship it as a FLASH image request
   (direct, pinned, `quality=low` set by the SWF; AVM1 root honours the stub's `_quality`, AVM2 roots do NOT — set
   `stage.quality` in the SWF). Prototype the rule the probe predicts.
2. **LOW stroke y rule:** class c rows `visual/.../drawing_order` (+934) and `masks`, `masks_equal_clipdepth` (+279):
   what does Flash do with stroke y at LOW? Check whether their goldens are Flash (playbook §27 / golden-provenance).
3. Gates for any prototype (non-negotiable, from lowq-corner-rule §3): Flash-golden LOW rows 0 losses; HIGH canary
   md5-identical; a by-name ledger of every pass↔fail move with golden provenance per row.
Do NOT turn any swap candidate (`invalidClipDepth`, `from_shumway/gradient`, `acid-gradient(-0)`, `acid-filter`) into a
flash_fix: the coordinator is running the Windows FP32 check on those locally. Kill-switch env var for any model change.
Siblings: w1-aa-sizing (HIGH only, diagnosis), the local N ladder (`render_webgpu.c` stroke builders, closed seam caps).
Name every function you touch in `render_webgpu.c` / `tag.c`; MSAA_SAMPLES never literal.
