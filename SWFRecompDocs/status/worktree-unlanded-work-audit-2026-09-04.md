# Worktree unlanded-work audit — 64 worktrees, 19 GB

**Date:** 2026-09-04 · **Baseline:** `master` at `47f67d403`
**Brief:** `SWFRecompDocs/prompts/worktree-unlanded-work-audit-prompt.md`

**Nothing was deleted, pruned, or removed by this audit.** No branch was
checked out in the main tree; every read used `git -C <worktree>` / `git show`.
Reclamation is the user's call; this document is the evidence for it.

---

## 1. Verdict in one line

**All 64 worktrees are safe to remove.** Every line of tracked work in them is
either on `master` already or preserved on `master` as a committed patch under
`SWFRecompDocs/plans/sessionN-fanout-reports/`. The only three exceptions are
self-labelled scratch instrumentation and a superseded prototype, and all three
are now rescued into `SWFRecompDocs/status/worktree-rescue-2026-09-04/`.

Of the 7 branches ahead of `master`, 6 are landed or deliberately-not-for-merge;
1 (`claude/explore-repository-files-…`, 2025-11-05, 34 lines) is unlanded and
obsolete, holds no worktree, and costs nothing to keep.

---

## 2. What the survey actually found (vs. the brief)

The brief described "62 worktrees" and "three sampled" dirty ones. Measured:

| | brief | measured |
|---|---|---|
| worktrees | 62 | **64** (62 `agent-*` + `w1-gfx-filters` + `w1-gfx-vram`, the last two on detached HEAD) |
| dirty with tracked edits | "three sampled" | **61 of 64**; 3 clean |
| branches ahead | 7 | 7 (confirmed) |
| surfaces | A (branches), B (dirty tracked) | **plus C: untracked files** — the agents' own reports and `.patch` files |

Surface C turned out to be the one that decides the whole question (§4).

Total dirty tracked insertions across the 61: ~20 800 lines. Largest single
worktree: `agent-a15a954ea7dd4a5cf`, 2 557 insertions across 10 files.

---

## 3. Method — and why the brief's fast test does not work here

**§4.3 of the brief proposes `git apply --check -R` against master as the fast
positive test for "already landed". It is useless on this corpus: 0 of the
first 36 worktrees reverse-applied.** Not because the work is unlanded, but
because these worktrees are based on commits from 2026-07-27 … 2026-08-13 and
`master` has moved hundreds of commits past them — reverse-apply fails on
context drift in the same file, independently of whether the change landed.
(The run was abandoned at 36/36 negative rather than finished.)

Nor is `git cherry` usable, for the reason the brief already gives.

**What worked instead — a three-stage content test:**

1. **Same-file line match.** Normalise every significant added line
   (whitespace-collapsed, ≥25 chars, must contain a letter — this discards
   braces and boilerplate that would match by accident in a 50 K-line file) and
   test membership in `master:<same path>`. 30 worktrees came out at 100 %
   immediately.
2. **Whole-tree match**, for code that moved between files during a later
   refactor.
3. **Archived-patch match** — the decisive stage: index the 137 `.patch` files
   already committed under `SWFRecompDocs/plans/sessionN-fanout-reports/`,
   stripping the leading `+`/`-` so patch lines normalise to source lines.

Every match was then attributed by category (same file / other source file /
archived patch / doc-only) so a "landed" verdict is checkable rather than a
percentage. Scripts: `content_check.py`, `tw.py` (session scratchpad; the
method is reproducible from this description in ten minutes).

---

## 4. The finding that decides it: the fan-out already archives its own patches

`SWFRecompDocs/plans/` on `master` carries **10 `sessionN-fanout-reports/`
directories holding 137 `.patch` files and their `*-report.md`**, committed by
the coordinator at the end of each wave.

Checked every untracked `.patch` / `.diff` / `*-report.md` in all 64 worktrees
against that archive: **exactly one has no byte-identical copy on master**
(`w1-gfx-filters/proto-w1-gfx-filters.diff`, itself a duplicate of that
worktree's own dirty diff). Every other agent report and patch — including the
work its coordinator deliberately **held** rather than landed — is already
committed.

So the fan-out pattern does not merely leave residue; **it self-archives.** A
dirty worktree left on a merged base is not a risk of lost work, because the
agent's patch was committed to `master` before the worktree went cold. This is
the durable lesson, and it is what makes the 19 GB reclaimable with confidence
rather than with hope.

---

## 5. Surface A — the 7 branches ahead of `master`

### 5.1 `worktree-agent-a2f63695b17bd7caf` (+4, 712 insertions) — **LANDED, all four commits**

The brief singled this out as "the most likely place for real unlanded work"
and asked for it first. **It is fully landed.** Adjudicated on content, commit
by commit:

| commit | content | evidence on master |
|---|---|---|
| `ba47bcad7` T7 P0/A | `avm2_builtin_class_api()` + 3 describeType rule fixes | `builtin_class_impl(…, min_swf)` `avm2_globals.c:362`; `avm2_builtin_class_api` now used at **19 sites in `avm2_display.c` alone**; `dt_class_extends_error` :2306; packaged-`length` suppression :5908; "Flash emits NO `<constructor>`" :6067 |
| `54c1a19b7` T7 P3 | ABC trait metadata, recompiler → runtime | `emitTraitMetadata` `abc_emit.cpp:1003`; `Avm2AbcMetadata`/`Item` `avm2_abc.h:63-91`; both accessor metadata halves `avm2_class.h:81-86`; `DtMeta`/`dt_json_metas`/`DT_INCLUDE_METADATA` in `avm2_globals.c` |
| `b9a1f6c74` T7 P4 pilot | builtin type descriptor + Event/Error/security | `dt_desc_classes` table present with **all** its rows: `dt_p_error_ctor`, `dt_m_error`, `dt_m_drm_error`, `dt_m_x500`, `dt_m_x509`, `dt_desc_find/member/apply`, `register_security_certs`, `security_stub_null/string`; EOFError-extends-IOError and the DRMManagerError `[API("667")]` gate both in `avm2_error.c:1690,1711` |
| `c750ed6bb` cleanup | drop dead counter in `emitTraitMetadata` | no `emitted` counter on master |

**The one apparent gap is the proof, not the counter-example.** Two symbols from
P4 — `dt_p_event_ctor` and `dt_m_event`, the hand-written `flash.events::Event`
row — are absent from master. Master's own table says why, in a comment at the
site:

> `DT_DESC_EVENTS_ROWS` … "It SUPERSEDES the hand-written Event /
> EventDispatcher rows that used to head this table: `dt_desc_find` takes the
> FIRST match, so a hand row left above would shadow the generated one for
> exactly the two classes the generator models best."

Master's table is a strict superset of the branch's (65 generated
`flash.display` rows + 66 `flash.events` rows + display3D + accessibility +
`flash.xml`), and the two missing hand rows were removed **on purpose** by the
generator that replaced them.

> **This overturns the brief's §3 exception.** "T7 P4 descriptors" is still
> listed as an open lead in `feature-priority-map`, but the pilot in this
> branch is not what is open — the pilot shipped and grew a generator
> (`tools/descriptor/gen_display_descriptors.py`). Whatever remains under that
> label is downstream of what is already on master. **No re-land slice is
> needed**, and the brief's "if it is substantial, make it its own slice"
> contingency does not fire.

Also: this worktree's own `wave2/w2-describetype.patch` and
`w2-describetype-report.md` are byte-identical to the
`session14-fanout-reports/` copies on master.

### 5.2 The three `w2-*` sibling patches — **LANDED**

| branch | claim | evidence on master |
|---|---|---|
| `worktree-agent-a8c00c876e87e1966` — bitmapmax + clipDepth masking | landed | `g_avm2_mask_capture` ×11, `active_clip_depth` ×6, `renderer_begin_clip_mask`/`renderer_end_clip` ×3 each, `dynamic_bitmap_max` ×15 in `avm2_display.c` |
| `worktree-agent-af67a17789b50d337` — box-blur kernel | landed | `blur_box_kernel`, `render_webgpu_run_blur`, `first_weight`, `last_offset`, `full_size`, `m2` all in `render_webgpu.c` |
| `worktree-agent-a3768f27197f6c8a9` — w2-avclasses safe bundle | landed | `NetFilterEvent`/`nfe_clone`/`net_filter_init` in `avm2_events.c`; `flashtrace_get_level`, `currencyparseresult_ctor` in `avm2_globals.c`; `AV_SLOT_NAMES`/`av_slot_get`/`av_ctor` in `avm2_media.c` |

The brief's §3 prior — "sibling patch / base for / staging point titles are the
signature of a landed fan-out" — **holds exactly** for these three.

### 5.3 `t5-iso-base` (+1) — **LANDED**

The quadruple-`Revert` restores the Ruffle test-navigator request log. On
master: `SWFModernRuntime/src/utils.c` has `swf_log_fetch_queue` (:176),
`swf_log_fetch_pending/flush` (:216, :221), `swf_log_navigate` (:274),
`"Navigator::fetch:"` (:187); `utils.h` has `SwfLogPair` and the `LOG_FETCH`
gate; `verify_output.py` has `get_log_fetch()` (:2213) feeding `-DLOG_FETCH=1`
at both build sites.

### 5.4 `t5-iso-v1` (+2) — **DO NOT LAND** (subtractive isolation probe)

Its extra commit is `test(iso): tranche 5 minus URLRequestHeader ctor+slots
(variant 1)` — **2 insertions, 39 deletions**, removing `urlreqheader_ctor` and
the `flash.net::URLRequestHeader` class registration. It is an A/B bisect
variant, not a feature. Master carries the full `URLRequestHeader`
(`avm2_globals.c` ×6, `avm2_display.c` ×3). Landing this branch would be a
regression.

### 5.5 `claude/explore-repository-files-011CUq1NmiHuuom4iGjkCrf1` (+1) — **UNLANDED, obsolete**

`CC-note-root.md` (2025-11-05, 33 lines): a session note describing how an
agent ran `git submodule update --init --recursive` to populate
`SWFModernRuntime/`, `SWFRecomp/`, `SWFRecompDocs/`. Not on master. **The
structure it documents no longer exists** — master carries those as ordinary
trees, not gitlinks. It also bumps the then-`SWFRecomp` submodule pointer,
which is meaningless now.

Holds no worktree, so **no space is at stake**; keeping the branch is free.
Do not land.

---

## 6. Surface B — the 61 dirty worktrees

Attribution of every significant added line (`samefile` = present in master's
copy of the same file; `archived-patch` = present in a `.patch` committed on
master; `MISSING` = present nowhere):

| bucket | worktrees | verdict |
|---|---|---|
| 100 % same-file | **30** | landed outright |
| same-file + archived-patch remainder, 0 missing | **28** | landed in part; remainder committed as an archived patch |
| non-zero MISSING | **3** | see §7 |
| clean (no tracked edits) | **3** | `agent-a2f63695b17bd7caf`, `agent-a676be22cbbf1c87e`, `agent-ab3d33125b5424be7` |

**Zero doc-only matches** outside `w1-gfx-filters` (3 lines), so the verdicts do
not rest on accidental prose matches.

Every archived-patch attribution is topic-coherent — the remainder maps to the
archived patch for the *same feature*, never to a random one:

| worktree | remainder | archived at |
|---|---|---|
| `agent-a84b624a7e0ebb766` | 137 | `session14/w2-gfx-morph-legb.patch`, `session15/w2-morph-legb2.patch` |
| `agent-a3b01760b5d476323` | 104 | `session14/w2-gfx-morph-legb.patch` (101), `session15/w2-morph-legb2.patch` (93) |
| `agent-af6bf853db68a2f68` | 84 | `session15/w2-gfx-blur-capacity.patch` (63), `w2-gfx-blur-plumb.patch` (21) |
| `agent-a7b703478aecc633f` | 44 | `session16/w2-gfx-vram-clamp.patch` (27), `w2-gfx-vram-smooth.patch` (17) |
| `agent-a67464a268863eda4` | 38 | `session16/w2-smalls-links_in_scrolled_text.patch` (33) |
| `agent-a6c8a37f88974d645` | 34 | `session14/w2-gfx-bitmapfill.patch` (34) |
| `agent-a15a954ea7dd4a5cf` | 32 | `session16/w2-all-classes-display.patch`, `session17/w2-all-classes-events.patch` |
| `agent-ac40f187a7e1a0d31` | 19 | `session15/w2-t10-descriptor.patch` |
| `agent-a655b4467e99edb7c` | 12 | `session13`+`session14/w2-describetype.patch` |
| (19 more) | ≤17 each | same pattern |

### 6.1 Worth naming: the one that looked genuinely unlanded

`agent-a84b624a7e0ebb766` carries `SWF::computeStaticPlacementScales()` — a
recompiler pre-pass that records the largest static placement scale each
character is ever composed at (propagated through `DefineSprite` nesting) so
that curve-flattening tolerance stops being blind to placement scale. Master's
adaptive flattening has **no** placement-scale term (`master:SWFRecomp/src/swf.cpp`
tolerance sites :8380, :8439, :8479, :9278 — none divide by a per-character
scale), and master's only pre-pass is the unrelated *morph edge-pairing* one.

So that half is genuinely not on master — it is the "HELD flattening leg C" the
session-15 closeout names. **But it is archived**, in
`session14/w2-gfx-morph-legb.patch` and `session15/w2-morph-legb2.patch`, both
committed. Its sibling half (the morph path-command pairing, `emits_path` /
`emits_vertex`) *did* land: 9 occurrences each in `master:SWFRecomp/src/swf.cpp`.

This is the exact shape the whole audit reduces to: **held ≠ lost.**

---

## 7. The only three worktrees holding content that is nowhere on master

All three are self-labelled by their own authors as not-for-merge. All three
are now rescued to `SWFRecompDocs/status/worktree-rescue-2026-09-04/`.

| worktree | missing lines | what it is |
|---|---|---|
| `w1-gfx-vram` | 41 / 41 | `// --- SCRATCH INSTRUMENTATION (w1-gfx-vram, NOT FOR MERGE) ---` — `SWF_VRAM_LOG`/`SWF_DYNBMP_REPORT` env-gated VRAM accounting. Its *findings* landed (the 12 size-class bitmap pools). Base `cd04f80b9`. |
| `w1-gfx-filters` | 54 / 104 | `// --- PROTOTYPE (w1-gfx-filters, session 16): DisplayObject.filters render arm.` **Superseded by a matured version on master**: `avm2_render_filtered` `avm2_display.c:17954`, `AVM2_RENDER_MAX_FILTERS` (replacing the literal 32), `renderer_snapshot_filter_source`, `renderer_run_blur`, and the prototype's own rules (`quality == 0` impotent, `blur_x <= 65536`, "Plain blur is always strength 1"). What is missing is the `SWFR_FILT_DUMP` debug prints and the `g_avm2_filter_skip` re-entry mechanism that master redesigned. Base `cd04f80b9`. |
| `agent-aa09df5fafcc255bb` | 30 / 45 | `// --- w1-gfx-displace-blend instrumentation (env-gated, worktree only) ---` — `SWFR_DISPLACE_DUMP` bitmap-fill / vertex-stream dumps. Its real patch, `wave1-gfx-displace-blend.patch`, is byte-identical to the copy in `session15-fanout-reports/`. Base `42a324cef`. |

None is a feature that master lacks.

---

## 8. Reclaim verdict

**Safe to remove — all 64 worktrees**, ~19 GB (`.git` is 452 MB and is not
touched by worktree removal).

- 61 worktrees: **no read needed.** Content is on master or in a committed
  archived patch.
- 3 worktrees (`w1-gfx-vram`, `w1-gfx-filters`, `agent-aa09df5fafcc255bb`):
  **already read, already rescued** (§7). Their patches are in this commit.

**Branches: keep all of them.** They cost kilobytes, and two carry information
that the worktree removal would otherwise discard —
`claude/explore-repository-files-…` (unlanded, obsolete) and `t5-iso-v1` (a
subtractive probe that must never be merged; §5.4).

Suggested order, largest first: `agent-aacc614c6d270b658` (937 M),
`agent-a7b703478aecc633f` (903 M), `agent-a97865983ec472cba` (895 M),
`agent-a6c8a37f88974d645` (726 M), `agent-a360c309db628703d` (571 M),
`agent-ae069176b0f039386` (497 M), `agent-ace18009389126e2d` (399 M),
`agent-aa09df5fafcc255bb` (389 M), then the rest.

`git worktree prune` reclaims nothing — all 64 directories exist, so no
registration is stale. Removal has to be explicit.

**Removing a worktree does not delete its branch**, so a `worktree-agent-*`
branch survives its directory. The three `worktree-agent-*` branches that are
already ahead-of-master *without* a worktree (`a3768f27…`, `a8c00c876…`,
`af67a177…`) are what that looks like afterwards — and all three are landed
(§5.2).

---

## 9. What this overturns in the brief

1. **§3's exception is refuted.** `worktree-agent-a2f63695b17bd7caf` is fully
   landed, all four commits, including the P4 pilot the brief expected to find
   unlanded. The one absent symbol was deliberately superseded by a generator.
   No follow-up slice.
2. **§4.3's fast test does not work here** — reverse-apply is 0/36 on a corpus
   this far behind master, for context-drift reasons unrelated to landing.
3. **§3's prior is confirmed, but for a stronger reason than the brief gives.**
   The titles ("sibling patch", "staging point") are weak evidence; the strong
   evidence is that the coordinator commits every agent's patch to
   `SWFRecompDocs/plans/sessionN-fanout-reports/` at wave end. 137 archived
   patches, and exactly one untracked artefact in 64 worktrees lacks a copy.
4. **The brief missed a surface.** Untracked files (agent reports and patches)
   are neither Surface A nor B — and they are what makes the verdict safe.
5. **The count is 64, not 62**, and 61 are dirty, not "three sampled".

## 10. Next slice

None required by this audit. The reclamation is a user action, not a slice.
If `feature-priority-map`'s "T7 P4 descriptors" lead is picked up, start from
`gen_display_descriptors.py` and the `DT_DESC_*_ROWS` generator on master —
**not** from the branch, which is behind it.
