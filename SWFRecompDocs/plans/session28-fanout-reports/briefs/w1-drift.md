**Upstream drift `efb612fd7..c2f7d24b7` (S).**

Upstream Ruffle commits since the s27 drift slots: `45099f016` (swf: only parse the tags we care about in
`decompress_swf`), `fa93ad79f` (avm1: fire the root's load event after its first frame's actions; `avm1/root_onload`
loses `known_failure`), `85eaaffb7`/`0c015cb5e` (chores), `c2f7d24b7` (render: `jpeg-decoder` → `zune-jpeg`). Re-fetch
upstream at start and extend the range if newer commits landed.

Task:
1. For each commit touching `tests/` or behaviour we model: which rows move upstream (new/changed goldens, toml edits),
   and what our rows do after `download_tests.sh` of the affected categories. We already pass both `root_onload` rows:
   confirm after the toml change, and check whether the root-load-event ordering change has any other corpus row or
   regression fixture whose golden depends on root onLoad vs frame-1 action order (grep for `onLoad` on `_root` /
   `this.onLoad` in frame 1 across avm1 + gnash + shumway). If our order differs from Ruffle's new order anywhere,
   decide by Flash (write a FLASH trace request with a minimal direct-mode fixture).
2. zune-jpeg: no golden re-baked yet. Check whether any upstream test PNG changed in the range (git diff --stat on
   `tests/`). If JPEG goldens WERE re-baked, re-price `from_shumway/acid/acid-color-0` (we are a priced Flash-over-Ruffle
   loss to our IJG model; RvF) and `from_shumway/bitmapdata/bitmapdata-clone` (we are bit-exact vs Flash) — never move
   our decoder toward zune.
3. Run `python3 ruffle-tests/apply_flash_fixes.py --check` after your download and report any STALE/UPSTREAMED lines.
Deliver any small patch needed (new rows passing), else a NO-CHANGE report naming every upstream row in the range.
