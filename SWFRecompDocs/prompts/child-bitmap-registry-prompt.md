# Slice: a loaded child movie's bitmaps index the wrong array

You are starting a fresh session on SWFRecomp-CC at `master`. **Baseline: `3fd9b7cc5`.**
CLAUDE.md is auto-loaded; it authorises commit/push/CI/Pages deploy. Work in this tree —
the Ruffle-test fan-out convention is for corpus sessions only, not this one.

Read first:
1. `SWFRecompDocs/status/emission-mode-residuals.md` — the slice immediately before
   yours. It fixed the SAME CLASS of bug for **sounds** (a child's char ids were offset
   at some call sites and not others) and deliberately left this one open, saying why.
   Its regression test `ruffle-tests/tests/swfs/regression/avm1_parent_as3_child_payload/`
   is the shape yours should take — read it before writing your own.
2. Memory note `child-movie-charid-offset-per-callsite` (the sound bug's lesson: the
   offsetting is per-call-name and hand-maintained, so it is missing wherever nobody
   looked).

## The bug

`defineBitmap(offset, size, width, height, char_id)` (`SWFModernRuntime/src/libswf/tag.c`
~12754) forwards to `ng_registerBitmapMetadata(char_id, offset, ...)`. That `offset` is a
byte offset into **the emitting movie's own** `bitmap_data` array.

The consumer — `BitmapData.loadBitmap`, `SWFModernRuntime/src/actionmodern/action.c`
~14460 — does:

```c
if (!ng_getBitmapMetadata((u16)char_id, &offset, &size, &width, &height)) return r;
GEN_EXTERN_BITMAP_DATA;
u32* src_pixels = (u32*)(bitmap_data + offset);
```

`bitmap_data` there is always the **main movie's** array. When a child SWF is loaded, its
generated array is renamed `<prefix>_bitmap_data` by `verify_output.py`'s
`generate_child_movie_file` (see its symbol list, ~line 1525/1541/1782), so the registry
holds a child's offset and the reader applies it to the parent's array. The registry
records *where in an array*, but never *which array*.

Nothing in the corpus exercises it, which is exactly why it survived — and why your first
job is a test, not a fix.

## Goal

1. **A regression test that fails first.** `ruffle-tests/tests/swfs/regression/` (custom
   tests go THERE, never in the upstream mirrors — see that suite's `README.md`). Shape it
   on `avm1_parent_as3_child_payload`: a parent that loads a child, where the child owns a
   bitmap and something observable depends on reading its pixels
   (`BitmapData.loadBitmap` on an exported symbol). It must FAIL on current `master` and
   pass after your fix — show both, that is the deliverable.
2. **Give the registry a per-movie base.** `ng_registerBitmapMetadata` should record which
   array the offset belongs to (a base pointer set by the caller from its own TU's
   `bitmap_data`, or a movie id the reader can resolve), and `loadBitmap` should use it
   instead of the ambient global. `GEN_EXTERN_BITMAP_DATA` already has a `DYNAMIC_HOST`
   pointer form (`SWFModernRuntime/include/libswf/generated_data.h`) — look at how the
   AVM2 host variant made those tables pointer-shaped before inventing a mechanism.

**Check the render path too, and say what you find.** `defineBitmap` also calls
`renderer_upload_bitmap(context, offset, size, ...)` with the same offset. If that has the
same ambiguity for a child's bitmaps, it is the same bug with a different symptom — fix it
in the same breath or state explicitly why it is unaffected. A half-fixed dictionary is
worse than a documented one.

Also worth a few minutes: the sound fix landed as a *pair* of call sites because moving
one without the other broke a different case. Look for the other bitmap-adjacent call
names in `generate_child_movie_file`'s offset list and check none is half-applied.

## Verification

- The new test fails before, passes after (both shown).
- One corpus run: `ruffle-tests.yml`, `mode=graphics`, `categories=full`. Zero regressions
  per `scripts/corpus_status_diff.py`. This touches the AVM1 runtime, so it is a real
  regression risk — unlike the last three slices, your change is ON by default.
- The publish gate is now computed rather than enumerated
  (`scripts/ci/publish_gate.py`, and `.claude/pipeline-handoff.md` §"The publish gate is
  computed, not enumerated"): a default run publishes, any non-default input does not.
  You should not need to touch it — if you think you do, say why.
- `verify_output.py` compiles generated C with `-w` and cannot see a malformed
  declaration; if you emit anything new, sweep with
  `gcc -fsyntax-only -Werror=return-type -Wall`.

## Done means

The test is in the corpus and the fix makes it pass; the render path is either fixed or
explicitly cleared; corpus green with zero regressions; a short closeout under
`SWFRecompDocs/status/`; the `emission-mode-residuals.md` note about this defect updated
from "still broken, deliberately left" to what happened; memory updated; commit pushed.

If the fix turns out to need a wider change than the registry — for instance if the
runtime has no way to know which movie a `char_id` came from — stop at a
well-characterised write-up plus the failing test, and say what the real shape is. A
falsifiable test plus an accurate diagnosis is a good outcome; a speculative half-fix
across the dictionary is not.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
