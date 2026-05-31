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

## nested_timeline_clone

`nested_timeline_clone.swf` (hand-assembled from `nested_timeline_clone.swfml`
via `swfmill xml2swf`): three nested timeline sprites — `leaf` placed in
`inner`, `inner` placed in `container`. From `container`'s own frame script it
clones the NESTED, timeline-placed `inner` two ways:

- **method form** `inner.duplicateMovieClip("dup", 5)` — clones for real;
- **function form** `duplicateMovieClip(inner, "dup2", 6)` (ActionCloneSprite).

Locks the nested-timeline-source residual fixed after `1093c2a33` (commit that
follows): `ng_duplicateMovieClip`/`ng_cloneSprite` looked up the source char_id
via `ng_findDisplayEntryByName`, which scans the GLOBAL `display_list` (root's)
and never contains a clip nested inside another sprite → `src_depth=SIZE_MAX` →
the clone's frame 0 never ran → the clone had no children (`dup.leaf=undefined`).
Fixed by falling back to `src_mc->display_obj->char_id`.

Gate (must stay byte-identical to `nested_timeline_clone.expected.txt`):

```bash
rm -rf /tmp/ntcg && \
python3 tools/divergence/run_swfrecomp.py tools/divergence/gates/nested_timeline_clone.swf /tmp/ntcg --frames 3 --recompile >/dev/null 2>&1 && \
grep -aE "typeof|_parent" /tmp/ntcg/trace.txt | diff - tools/divergence/gates/nested_timeline_clone.expected.txt && echo GATE-GREEN
```

Expected (matches Ruffle on every line):

```
typeof inner.leaf=movieclip
dup._parent._name=container      <- method-form clone: real, parented to container, has leaf
typeof dup.leaf=movieclip
typeof dup2.leaf=undefined        <- function-form (ActionCloneSprite) of a nested clip:
dup2._parent._name=                  Ruffle REFUSES it (dup2 undefined); SWFRecomp matches
```

Note the asymmetry: Flash's legacy function-form `CloneSprite` refuses to
duplicate a nested timeline clip (yields nothing), while the method-form
`duplicateMovieClip` succeeds — and SWFRecomp matches both.

To author such SWFs: `swfmill swf2xml` an existing SWF to learn the schema,
edit the XML (AVM1 actions are structured elements — `PushData`/`StackString`/
`GetMember`/`CallMethod`/`CloneSprite`/`Trace`/…), then `swfmill xml2swf`. Note
ActionCloneSprite's runtime stack is `[source-mc] [new-name] [depth]`, and the
source must be a MovieClip ref (`GetVariable`), not a string path.
