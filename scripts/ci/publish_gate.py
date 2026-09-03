#!/usr/bin/env python3
"""Decide whether a ruffle-tests.yml run may publish its results.

WHY THIS EXISTS
---------------
`ruffle-tests.yml` picks its result-JSON stem from `mode` alone, so ANY input
that changes what the test binaries do — while leaving the stem alone — makes a
run's numbers incomparable with a normal run's. Publishing them force-pushes
them over `{STEM}.json` on `ruffle-test-results`, which is exactly the file the
NEXT run fetches as `{STEM}_previous.json`: the poisoned baseline then reports
phantom transitions with no code change behind them (memory
`ci-verify-run-results-clobber`; it really happened, run 29716664671).

The guard used to be a hand-maintained `&&` chain on both publish steps
(`inputs.extra_defines == '' && inputs.single_test == '' && ...`). Three
emission-option slices in a row each had to append a clause to it, and each
learned that the hard way. The chain is fail-OPEN: forget it and the run
publishes.

This script inverts that. It is fail-CLOSED:

    an input whose value differs from the default DECLARED IN THE WORKFLOW
    blocks publishing, unless its name is in PUBLISH_SAFE below.

A new input is therefore guarded the moment it is declared, with no second edit
anywhere. Adding a name to PUBLISH_SAFE is a deliberate, reviewable act, and the
only reason to do it is that the input cannot change what a test binary does or
what a published number means.

Usage (in the workflow):

    - name: Decide whether this run may publish results
      id: publish_gate
      env:
        ALL_INPUTS: ${{ toJSON(inputs) }}
      run: python3 scripts/ci/publish_gate.py

  then gate each publish step on
  `steps.publish_gate.outputs.publish == 'true'`.

Exits non-zero (and leaves publish=false) if it cannot parse the workflow's
input declarations — a broken gate must be loud AND closed, never silently
open.

`python3 scripts/ci/publish_gate.py --self-test` runs the unit cases below
without a workflow context.
"""
import json
import os
import re
import sys
from pathlib import Path

WORKFLOW = Path(__file__).resolve().parents[2] / ".github/workflows/ruffle-tests.yml"

# Inputs whose value CANNOT make a published number incomparable.
#
#   mode        chooses the result stem itself; each mode has its own baseline.
#   categories  a suite subset publishes only the suites it ran; the others are
#               inherited untouched from the results branch. This is the
#               documented cheap way to validate a workflow change
#               (memory `ci-cheap-validation-is-categories-not-limit`).
#   parallel    shard count only.
#   images      adds the image-comparison instrument; image comparisons never
#               gate trace pass/fail, and the trace numbers are unaffected.
#
# Everything else — anything that changes the binaries (extra_defines, swf_gc,
# avm2_gc, try_helper, tu_split, skip_avm1_payload, …), that runs only part of
# the corpus (limit), or that rebuilds the tree around one test (single_test) —
# blocks by simply not being here.
PUBLISH_SAFE = {"mode", "categories", "parallel", "images"}


def parse_declared_defaults(text):
    """{input name: declared default} from a workflow's input blocks.

    Both `workflow_dispatch.inputs` and `workflow_call.inputs` are read, and a
    name declared in both must declare the SAME default — a divergence means
    one trigger path publishes under conditions the other blocks, so it is an
    error, not something to paper over.
    """
    defaults = {}
    block = None          # 'dispatch' | 'call' | None
    name = None
    seen = {}
    for line in text.splitlines():
        if re.match(r'^\S', line):        # a top-level key ends any block
            block = None
            name = None
        m = re.match(r'^  (workflow_dispatch|workflow_call):\s*$', line)
        if m:
            block = m.group(1)
            name = None
            continue
        if block is None:
            continue
        if re.match(r'^    inputs:\s*$', line):
            name = None
            continue
        m = re.match(r'^      ([A-Za-z_][A-Za-z0-9_-]*):\s*$', line)
        if m:
            name = m.group(1)
            seen.setdefault(name, {})[block] = ''   # no `default:` => ''
            continue
        m = re.match(r"^        default:\s*(.*?)\s*$", line)
        if m and name is not None:
            raw = m.group(1)
            if len(raw) >= 2 and raw[0] == raw[-1] and raw[0] in "'\"":
                raw = raw[1:-1]
            seen[name][block] = raw
    for n, per_block in seen.items():
        vals = set(per_block.values())
        if len(vals) > 1:
            raise ValueError(
                f"input '{n}' declares different defaults per trigger block: "
                + ", ".join(f"{b}={v!r}" for b, v in sorted(per_block.items())))
        defaults[n] = next(iter(vals))
    if not defaults:
        raise ValueError("no workflow inputs parsed")
    return defaults


def _norm(value):
    """Compare a run's input value with a declared default as text.

    `toJSON(inputs)` types a `type: boolean` input as a real JSON bool while
    the declaration reads `default: false`, so normalise both to lower-case
    text; every other input type is already a string or a number.
    """
    if value is None:
        return ''
    if isinstance(value, bool):
        return 'true' if value else 'false'
    text = str(value)
    return text.lower() if text.lower() in ('true', 'false') else text


def decide(inputs, defaults):
    """(publish: bool, reason: str). Unknown names count as non-default."""
    offenders = []
    for name, value in sorted(inputs.items()):
        if name in PUBLISH_SAFE:
            continue
        value = _norm(value)
        if name not in defaults:
            offenders.append(f"{name}={value!r} (undeclared input)")
        elif value != _norm(defaults[name]):
            offenders.append(f"{name}={value!r} (default {defaults[name]!r})")
    if offenders:
        return False, "non-default inputs: " + ", ".join(offenders)
    return True, "all inputs at their declared defaults (or publish-safe)"


def self_test():
    text = WORKFLOW.read_text()
    defaults = parse_declared_defaults(text)
    for required in ("mode", "categories", "limit", "extra_defines",
                     "single_test", "try_helper", "tu_split",
                     "skip_avm1_payload", "swf_gc", "avm2_gc"):
        assert required in defaults, f"{required} not parsed from {WORKFLOW}"
    assert defaults["mode"] == "graphics", defaults["mode"]
    assert defaults["limit"] == "0", defaults["limit"]
    assert defaults["extra_defines"] == "", defaults["extra_defines"]

    base = dict.fromkeys(defaults, "")
    base.update(defaults)

    def d(**over):
        v = dict(base)
        v.update(over)
        return decide(v, defaults)

    cases = [
        ("defaults publish", d(), True),
        ("no-graphics publishes", d(mode="no-graphics"), True),
        ("suite subset publishes", d(categories="avm1"), True),
        ("shard count publishes", d(parallel="10"), True),
        ("image run publishes", d(images="true"), True),
        ("extra_defines blocks", d(extra_defines="-DAVM2_SLOT_VERIFY"), False),
        ("single_test blocks", d(single_test="hello_world"), False),
        ("try_helper blocks", d(try_helper="1"), False),
        ("tu_split blocks", d(tu_split="4096"), False),
        ("skip_avm1_payload blocks", d(skip_avm1_payload="1"), False),
        ("swf_gc blocks", d(swf_gc="1"), False),
        ("avm2_gc blocks", d(avm2_gc="1"), False),
        ("limit blocks", d(limit="5"), False),
        # The point of the whole exercise: an option nobody wired anywhere.
        ("future option blocks", d(brand_new_mode="1"), False),
    ]
    failures = 0
    for label, (got, reason), want in [(c[0], c[1], c[2]) for c in cases]:
        ok = got is want
        print(f"  {'ok  ' if ok else 'FAIL'}  {label}: publish={got} ({reason})")
        failures += not ok
    print(f"{len(cases) - failures}/{len(cases)} cases passed")
    return 1 if failures else 0


def main():
    if "--self-test" in sys.argv:
        return self_test()

    raw = os.environ.get("ALL_INPUTS", "")
    bad_json = None
    try:
        # A `schedule:` trigger has an EMPTY inputs context (toJSON gives
        # `null`), which means "every input at its default" — that publishes.
        inputs = json.loads(raw) if raw.strip() else {}
        if inputs is None:
            inputs = {}
        if not isinstance(inputs, dict):
            raise json.JSONDecodeError("inputs is not an object", raw, 0)
    except json.JSONDecodeError as e:
        print(f"publish gate: ALL_INPUTS is not JSON ({e})", file=sys.stderr)
        bad_json = e
        inputs = None

    out = os.environ.get("GITHUB_OUTPUT")

    def emit(publish, reason):
        # $GITHUB_OUTPUT is line-oriented; an input value could carry a newline.
        reason = " ".join(reason.split())
        print(f"publish={publish} — {reason}")
        if out:
            with open(out, "a") as fh:
                fh.write(f"publish={'true' if publish else 'false'}\n")
                fh.write(f"reason={reason}\n")

    if bad_json is not None:
        emit(False, "could not read the run's inputs")
        return 1
    try:
        defaults = parse_declared_defaults(WORKFLOW.read_text())
    except (OSError, ValueError) as e:
        emit(False, f"could not read the workflow's input declarations: {e}")
        return 1

    publish, reason = decide(inputs, defaults)
    emit(publish, reason)
    return 0


if __name__ == "__main__":
    sys.exit(main())
