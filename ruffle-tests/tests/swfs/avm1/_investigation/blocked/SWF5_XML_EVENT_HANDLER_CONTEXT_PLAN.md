<!-- TESTS: swf5_xml_event_handler_context -->
# SWF5 XML Event Handler Context Plan

## Status: BLOCKED — requires XML.load() with HTTP/file loading + multi-SWF child execution

## Test Summary

| Test | Lines | Match | Status | Root Cause |
|------|-------|-------|--------|------------|
| swf5_xml_event_handler_context | 2 | 0/2 (0%) | output_mismatch | XML.load() not implemented |

## What the Test Does

Source: `~/CC/ruffle/tests/tests/swfs/avm1/swf5_xml_event_handler_context/`

The test has two SWFs (test.swf is SWF5, child.swf is loaded into `_level2`) and
a `test.xml` file containing `<test>success</test>`.

**test.swf (SWF5, script_0.c):**
1. Loads `child.swf` into `_level2` via `getURL2("child.swf", "_level2")`
2. Sets a local variable `ctxName = "parent"`
3. Calls `stop()`

**child.swf (script_1.c):**
1. Calls `stop()`
2. (Presumably sets up XML.load with onLoad callback — the SWF bytecode for the
   child's initialization is in the child.swf, but since child.swf is not separately
   recompiled, we only see script_1 which is the parent's frame 2 script)

**Expected output:**
```
xmlDoc.onLoad(success: true)
callback called from child
```

The test verifies that:
1. `XML.load("test.xml")` loads the file and fires `onLoad(true)`
2. The onLoad callback executes in the correct SWF5 context (child's context)
3. The callback can call a function defined in the parent's scope

## Root Cause Analysis

Two independent blockers prevent this test from producing any output:

### Blocker 1: XML.load() Not Implemented

`XML.load(url)` requires:
- HTTP or file-based resource loading (fetch `test.xml` from the test directory)
- Asynchronous callback: parse the loaded XML, then fire `xmlDoc.onLoad(success)`
- The XML parsing itself IS implemented (XML_PLAN is complete), but the loading
  mechanism is not

This is the same blocker as `xml_load` (which is in `ignored_tests.txt`).

### Blocker 2: Child SWF Execution

The test loads `child.swf` into `_level2`. While `actionGetURL2` has basic
`_level` loading infrastructure, the child SWF would need to be:
1. Available as a `MovieEntry` (registered at compile time)
2. Recompiled by the recompiler (child.swf → C code)
3. Linked into the test binary

The verify_output.py test runner currently only recompiles the primary `test.swf`.
Child SWF support exists for some multi-SWF tests but requires explicit handling.

### Blocker 3: File-Based Resource Loading

Even if XML.load() were implemented for HTTP, this test loads a local file
(`test.xml`). In the trace-only test environment, there's no filesystem context
for the SWF to load resources from.

## What Would Be Needed

1. **XML.load() implementation** — resource loading mechanism (HTTP or file)
2. **Child SWF recompilation** — verify_output.py support for child SWFs
3. **Async callback dispatch** — fire onLoad after the resource is loaded
4. **SWF5 context handling** — ensure the callback runs in child's SWF5 context
   (this is what the test name refers to — SWF5's looser scoping rules for
   event handler `this` binding)

## Difficulty Assessment

**Not feasible.** This test requires two major infrastructure pieces that don't exist:
- XML/HTTP resource loading (same blocker as 7 other ignored xml_* tests)
- Multi-SWF child execution (same blocker as several loadmovie tests)

The test itself is tiny (2 lines), but the infrastructure needed is massive.

## Recommendation

**Do not implement.** This test is blocked by the same XML.load() infrastructure
that blocks the 7 `xml_*` tests already in `ignored_tests.txt`. Consider adding
this test to `ignored_tests.txt` as well, since its root cause is identical to
`xml_load`.
