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

Regressed before commit `<this fix>`: clone minted as `_root` ghost →
`p.dupChild=undefined`, `d._parent._name=[undefined]`.
