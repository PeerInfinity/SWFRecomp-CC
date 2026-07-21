# avm2_tolerant_verify_quarantine

Regression net for the recompiler's **tolerant per-body verify** (AVM2). One
method body in `test.swf` is hex-patched so its first bytecode op is the
**undefined opcode `0xf4`** — the exact `betz`-obfuscator decoy that Elephant
Quest (`566862_ElephantQuest`) hides in its dead body 1309. Real AVM2 debug ops
stop at `0xf3`, so `0xf4` never decodes.

**What it pins down:** an undecodable opcode in one body must quarantine *only
that body* — the emitter drops a runtime-throw stub (`avm2_verify_error_body`,
`abc_emit.cpp:2828`) for it — while **every other body still emits and runs**.
The whole ABC must NOT abort. This mirrors Ruffle's lazy per-method verify; our
recompiler verifies AOT (`swf.cpp` per-body loop → `verifyMethodBody`), and the
per-body catch has existed since AVM2 Stage 2 (`0fec4fbe6`). Elephant Quest's
1310-body ABC is the first real title to exercise it; this test is the minimal
reproduction so a future refactor can't silently regress it.

`decoyBody()` (the patched body) is deliberately **never invoked**, so its
quarantine stub is never reached and the two good traces must appear:

```
good body A
good body B: helper-ran
```

If tolerant verify ever regresses to a whole-file abort, the ABC recompiles to
nothing, `output.txt` comes back empty, and this test fails loudly. (The
non-empty expected output is what makes the guard real — an empty expected file
would score a boot-death as PASS; see the plan's
`avm2-localconnection-silent-blank-stage` trap.)

## Rebuilding the SWF

```bash
./build_swf.sh          # mxmlc Test.as -> test.clean.swf, then patch -> test.swf
```

`create_test_swf.py` decompresses the mxmlc CWS output, parses the ABC to find
the body whose code traces the marker `"DECOY SHOULD NEVER RUN"` (located by the
marker string, **not** a method/pool index, so pool shuffles don't break it),
**overwrites** that body's first opcode byte with `0xf4`, and re-emits an
uncompressed FWS. Overwrite (not insert) keeps `code_length`, the DoABC tag
length and the SWF file length all unchanged — the byte stream never desyncs,
and the verifier's decode fails identically.

Verify the patch landed:

```bash
SWFRecomp/build/SWFRecomp --check-abc test.swf
#   -> status=VERIFY_FAIL bodies=5 verify_fails=1
#      body=3 msg="unknown ABC opcode 0xf4"     (same shape as EQ body=1309)
```
