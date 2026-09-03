# Slice: don't emit the AVM2-dead AVM1 payload for AS3 SWFs (assessment §2.2)

You are starting a fresh session on SWFRecomp-CC at `master`. **Baseline: `68518b088`**
(the TU-split slice's closeout; CI 33710871686 default / 33710882328 forced-on, both
zero-transition, results merged at `709b24ab9`). CLAUDE.md is auto-loaded; it authorises
commit/push/CI/Pages deploy. Work in this tree — the Ruffle-test fan-out convention is
for corpus sessions only, not this one.

Read first, in this order:
1. `SWFRecompDocs/plans/avm2-in-browser-assessment.md` **§2.1 (the table of what the
   data actually is and who reads it)** and **§2.2 (the design; you are implementing
   its "cheap extra win" bullet, NOT the blob)**, then §0 and §5 for where this sits.
2. `SWFRecompDocs/status/avm2-tu-split-emission.md` and
   `SWFRecompDocs/status/avm2-try-helper-emission.md` — the two slices before yours,
   in that order. They establish the option pattern (toml key + env override +
   workflow input, off by default, byte-identical default emission), the CI publish
   guard, and the local-verification recipe. Reuse all of it; do not reinvent.
3. `SWFRecomp/src/swf.cpp`: the `is_as3` flag (~line 4865) and the draws emission
   (~line 942) that writes `bitmap_data` / `sound_data` into `RecompiledTags/draws.c`.

## The problem

For an AS3 SWF the AVM1 payload in `draws.c` is **dead**: `bitmap_data` (decoded RGBA)
and `sound_data` are read only by `defineBitmap` / `tagDefineSound` in `tagInit`, and
`runSWF_avm2` never calls `tagInit`. AVM2 carries its own copies in `abc_timeline.c`
(`bmp_N_rgba`, `snd_N_bytes`, `bin_N_bytes`), which it does use. For Seedling that dead
payload is **~120 MB of the 142 MB `draws.c`** and 20.7 MB of the 31 MB of static data.

The TU-split slice moved the bottleneck onto exactly this: after the split, Snailiad's
peak working set (1.73 GB) is now BELOW Seedling's (2.57 GB), and Seedling's is driven
by `draws.c`. So this is the biggest single lever left, and it is nearly free — it also
removes the 83 s `draws.c` compile and ~2.4 GB of gcc RAM from the **bundle** path.

## Goal

An option (off by default, same pattern as `try_helper` / `tu_split`) under which an
**AS3** SWF does not emit the `bitmap_data` / `sound_data` byte arrays at all.

- Gate on `is_as3` AND the option — an AVM1 SWF must be untouched, and with the option
  off the emitted C must be byte-identical for both kinds.
- `draws.h` / `tagMain.c` still reference these symbols by offset
  (`defineBitmap(0, 2600, …)`, `sound_data + 5982`). Decide and state how you keep the
  TU linking: emit empty/zero-length definitions, `#if`-out the consumers, or skip the
  `tagInit` emission wholesale for AS3. Whichever you pick, the AVM2 path must still
  link and run, and `tagInit` must not become reachable-but-wrong.
- Check `video_data` and the other `draws.c` arrays against §2.1's table before you
  assume they are dead too — that table lists exactly which arrays the AVM2 runtime
  DOES read (`shape_data`, `transform_data`, `color_data`, `gradient_data`,
  `cxform_data`, `uninv_mat_data`, `morph_end_color_data`). Those must stay.

Explicitly OUT of scope: the payload blob (§2.2 proper — offsets + `avm2_payload_relocate`).
That is the slice after yours. If you find the blob is the only way to make this one
work, stop and say so rather than growing into it.

## Verification (all of it)

1. **Native, option OFF:** emitted C byte-identical to the baseline binary's, for an
   AVM1 SWF **and** an AS3 SWF. Method (from the two prior closeouts):
   `git diff -- SWFRecomp > p.patch; git apply -R p.patch`, rebuild, recompile a mixed
   set into a scratch dir, restore, rebuild, recompile again, `diff -r`. Do NOT use
   `git stash` — it is shared across this repo's worktrees.
2. **Native, option FORCED ON across the corpus:** `ruffle-tests.yml` in **graphics**
   mode, `categories=full`. **Add `inputs.<yours> == ''` to BOTH publish guards** — a
   run that changes what the binaries do while keeping the `mode` stem would force-push
   its numbers over `results_graphics.json` and poison the next run's baseline (memory
   `ci-verify-run-results-clobber`; two slices have now had to add this). Extend the
   `.recomp_mode` stamp in `verify_output.py::recompile_swf` so a cached tree from the
   other mode regenerates. Zero regressions per `scripts/corpus_status_diff.py`; run
   the default (option off) run too so the shipped default stays graded.
   Note the lesson the TU-split slice learned the hard way about value-carrying
   options: make sure the value you force in CI actually exercises the new path on
   corpus-sized inputs — a setting that no test in the corpus trips proves nothing.
   Here the relevant question is whether the corpus has AS3 tests with bitmap/sound
   payloads at all; check, and say what you forced and why it bites.
3. **Sizes, measured, before/after** for the original Seedling
   (`~/CC/newgrounds/598977_Seedling.swf`) and one Robot Wants title: `draws.c` bytes,
   `draws.o` bytes, total generated C, and the native `gcc -O1 -c draws.c` wall time.
   These numbers are the slice's headline — §2.2 predicts −120 MB of C, −20.7 MB
   static, −83 s.
4. **In the page** (`docs/recompiler`, Windows Chrome via
   `tools/divergence/perf/WINDOWS_PLAYWRIGHT_FROM_WSL.md`), with the option on in
   `pipeline.js`: Seedling compile time and peak worker memory against the TU-split
   slice's numbers (414.1 s), title screen still renders; Snailiad still compiles; one
   small AS3 test still traces its expected output; one AVM1 test unaffected.
   **Serve the repo root on a fresh port.** The long-lived `:8010` server on this box
   serves `docs2/` — both `/recompiler/` and `/docs/recompiler/` 404 on it (verified
   2026-09-02; a previous session misread its `-d docs2` as `-d docs`). Check
   `readlink /proc/<pid>/cwd` AND curl the actual path before believing any
   "still broken" browser result. The wasmer SDK's "oneshot canceled" worker race
   fires on roughly half of first attempts — rerun in a fresh page, it is not your bug.
5. **Bundle path:** confirm the runnable zip still builds and runs for an AS3 SWF with
   the option on (this is where the 83 s / 2.4 GB saving actually lands for users).
6. **Pages deploy** (`deploy-pages.yml`) after the `docs/` change; watch it.

`verify_output.py` compiles generated C with `-w`, so it cannot see a malformed
declaration — run `gcc -fsyntax-only -Werror=return-type -Wall` over a few generated
`RecompiledTags/*.c` yourself.

## Done means

- Option implemented, default off, native default output byte-identical for both AVM1
  and AS3; forced-on full graphics CI green with zero regressions and the default run
  graded too; measured before/after sizes and timings; the page and the bundle both
  still work for AS3.
- Closeout: a short status doc under `SWFRecompDocs/status/`; §2.2's cheap-win bullet
  and §5 of the assessment updated to "shipped" with the measured numbers; memory
  updated (add a note; update `avm2-in-browser-recompiler`'s "remaining slices" line);
  commit pushed; Pages deploy dispatched.

## After this slice

The last item in the arc: **the payload blob** (§2.2 proper — `draws_payload.bin` /
`abc_payload.bin`, offsets in the tables, `avm2_payload_relocate(base)`, the loader
`malloc`s it in host memory above the arena). Worth it only if your measurements still
leave the in-browser peak memory or the zip size somewhere that hurts — your closeout
should say whether it is still worth doing and why, since after your slice the numbers
it was justified by will have changed. Your report's "next slice's line" should say
either "blob, from <sha>, because X" or "arc complete, the blob is no longer worth it,
because X".

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
