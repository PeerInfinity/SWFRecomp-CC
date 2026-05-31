# Divergence regression gates

Minimal hand-built SWFs that lock a specific fixed divergence. Run via
`run_swfrecomp.py` (the divergence harness's tracer injection trips a separate
recompiler codegen collision on these tiny SWFs, so the harness's auto-inject
path is bypassed — these SWFs `trace()` the asserted state themselves).

## nested_duplicate

`nested_duplicate.swf` (from `nested_duplicate.as`, MTASC `-version 8`): a
`createEmptyMovieClip` child of `parentClip` is `duplicateMovieClip`'d. The
clone must be a sibling (child of `parentClip`), not a `_root` ghost.

Gate (must stay byte-identical to `nested_duplicate.expected.txt`):

```bash
rm -rf /tmp/ndg && \
python3 tools/divergence/run_swfrecomp.py tools/divergence/gates/nested_duplicate.swf /tmp/ndg --frames 2 --recompile >/dev/null 2>&1 && \
grep -aE "typeof|_target|_parent" /tmp/ndg/trace.txt | diff - tools/divergence/gates/nested_duplicate.expected.txt && echo GATE-GREEN
```

Expected:
```
typeof p.dupChild=movieclip
d._target=/parentClip/dupChild
d._parent._name=[parentClip]
d._parent==parentClip:true
typeof _root.dupChild=undefined
```

Regressed before commit `1093c2a33`: clone minted as `_root` ghost →
`p.dupChild=undefined`, `d._parent._name=[undefined]`.

## nested_timeline_clone — XFAIL (documents an open residual)

`nested_timeline_clone.swf` (hand-assembled from `nested_timeline_clone.swfml`
via `swfmill xml2swf`): three nested timeline sprites — `leaf` placed in
`inner`, `inner` placed in `container`. From `container`'s own frame script,
`inner.duplicateMovieClip("dup", 5)` clones a NESTED, timeline-placed sprite.

This is the `ng_cloneSprite`/`ng_duplicateMovieClip` residual noted in
PROGRESS follow-up #9: the clone's PARENT is now correct (`1093c2a33`), but the
display-list copy + frame_0 re-run are skipped for a nested timeline source
because `ng_findDisplayEntryByName` scans the GLOBAL `display_list` (root's),
which never contains a clip nested inside another sprite → `src_depth=SIZE_MAX`.

Target (Ruffle, `nested_timeline_clone.expected.txt`):

```
typeof inner.leaf=movieclip
dup._parent._name=container
typeof dup.leaf=movieclip
```

**Currently** SWFRecomp diverges on line 3 (`typeof dup.leaf=undefined` — the
clone has no children; see `nested_timeline_clone.swfrecomp-current.txt`).
Lines 1–2 already match (parenting fixed). When the DL-copy residual is fixed,
this gate flips to fully green:

```bash
rm -rf /tmp/ntcg && \
python3 tools/divergence/run_swfrecomp.py tools/divergence/gates/nested_timeline_clone.swf /tmp/ntcg --frames 3 --recompile >/dev/null 2>&1 && \
grep -aE "typeof|_parent" /tmp/ntcg/trace.txt | diff - tools/divergence/gates/nested_timeline_clone.expected.txt && echo GATE-GREEN
```

To author such SWFs: `swfmill swf2xml` an existing SWF to learn the schema,
edit the XML (AVM1 actions are structured elements — `PushData`/`StackString`/
`GetMember`/`CallMethod`/`Trace`/…), then `swfmill xml2swf` to assemble.
