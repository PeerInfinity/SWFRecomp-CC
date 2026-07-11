#!/usr/bin/env python3
"""Sweep the avm2 test corpus through the ABC parser + verifier.

Runs `SWFRecomp --check-abc` over every test.swf under the avm2 suite and
aggregates the ABC-CHECK result lines into a report. This PARSES files only
(no test execution), so running the full corpus locally is fine.

Usage:
    python3 SWFRecomp/tools/abc_corpus_sweep.py [--tests-dir DIR] [--binary PATH]
        [--jobs N] [--report FILE]
"""

import argparse
import concurrent.futures
import os
import re
import subprocess
import sys

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

CHECK_RE = re.compile(
    r'^ABC-CHECK (?P<path>\S+) status=(?P<status>\S+) abc_tags=(?P<tags>\d+) '
    r'bodies=(?P<bodies>\d+) verify_fails=(?P<fails>\d+)(?: first_error="(?P<err>.*)")?$')
FAIL_RE = re.compile(r'^ABC-VERIFY-FAIL (?P<path>\S+) (?P<detail>.*)$')


def run_batch(binary, paths):
    cmd = [binary, '--check-abc'] + paths
    proc = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.DEVNULL,
                          text=True, errors='replace')
    checks = []
    fails = []
    for line in proc.stdout.splitlines():
        m = CHECK_RE.match(line)
        if m:
            checks.append(m.groupdict())
            continue
        m = FAIL_RE.match(line)
        if m:
            fails.append(m.groupdict())
    return checks, fails


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--tests-dir',
                    default=os.path.join(REPO_ROOT, 'ruffle-tests', 'tests', 'swfs', 'avm2'))
    ap.add_argument('--binary',
                    default=os.path.join(REPO_ROOT, 'SWFRecomp', 'build', 'SWFRecomp'))
    ap.add_argument('--jobs', type=int, default=os.cpu_count() or 4)
    ap.add_argument('--batch-size', type=int, default=25)
    ap.add_argument('--report', default=None,
                    help='write the failure table to this file (markdown)')
    args = ap.parse_args()

    swfs = []
    for root, dirs, files in os.walk(args.tests_dir):
        dirs[:] = [d for d in dirs if not d.startswith('_')]
        if 'test.swf' in files:
            swfs.append(os.path.join(root, 'test.swf'))
    swfs.sort()
    if not swfs:
        print(f'No test.swf files under {args.tests_dir}', file=sys.stderr)
        return 1
    print(f'Sweeping {len(swfs)} SWFs with {args.binary}')

    batches = [swfs[i:i + args.batch_size] for i in range(0, len(swfs), args.batch_size)]
    all_checks = []
    all_fails = []
    with concurrent.futures.ThreadPoolExecutor(max_workers=args.jobs) as pool:
        futures = [pool.submit(run_batch, args.binary, b) for b in batches]
        for i, fut in enumerate(concurrent.futures.as_completed(futures)):
            checks, fails = fut.result()
            all_checks.extend(checks)
            all_fails.extend(fails)
            done = len(all_checks)
            if done % 200 < args.batch_size:
                print(f'  ... {done}/{len(swfs)}')

    def rel(p):
        return os.path.relpath(p, args.tests_dir)

    by_status = {}
    for c in all_checks:
        by_status.setdefault(c['status'], []).append(c)

    total_bodies = sum(int(c['bodies']) for c in all_checks)
    print()
    print(f'=== ABC corpus sweep: {len(all_checks)}/{len(swfs)} SWFs checked, '
          f'{total_bodies} method bodies ===')
    for status in sorted(by_status):
        print(f'  {status}: {len(by_status[status])}')

    missing = len(swfs) - len(all_checks)
    if missing:
        print(f'  (no ABC-CHECK line for {missing} SWFs — crashed? rerun those serially)')
        reported = {c['path'] for c in all_checks}
        for s in swfs:
            if s not in reported:
                print(f'    MISSING: {rel(s)}')

    lines = []
    for status in ('SWF_LOAD_FAIL', 'PARSE_FAIL', 'NO_ABC'):
        for c in sorted(by_status.get(status, []), key=lambda c: c['path']):
            lines.append(f"| {rel(c['path'])} | {status} | {c.get('err') or ''} |")
    fails_by_path = {}
    for f in all_fails:
        fails_by_path.setdefault(f['path'], []).append(f['detail'])
    for c in sorted(by_status.get('VERIFY_FAIL', []), key=lambda c: c['path']):
        details = fails_by_path.get(c['path'], [])
        first = details[0] if details else (c.get('err') or '')
        lines.append(f"| {rel(c['path'])} | VERIFY_FAIL {c['fails']}/{c['bodies']} | {first} |")

    if lines:
        print()
        print('| test | result | detail |')
        print('|------|--------|--------|')
        for line in lines:
            print(line)

    if args.report:
        with open(args.report, 'w') as f:
            f.write(f'# ABC corpus sweep\n\n{len(all_checks)}/{len(swfs)} SWFs, '
                    f'{total_bodies} bodies\n\n')
            for status in sorted(by_status):
                f.write(f'- {status}: {len(by_status[status])}\n')
            f.write('\n| test | result | detail |\n|------|--------|--------|\n')
            for line in lines:
                f.write(line + '\n')
            f.write('\n## Per-body verify failures\n\n')
            for path in sorted(fails_by_path):
                f.write(f'### {rel(path)}\n')
                for d in fails_by_path[path]:
                    f.write(f'- {d}\n')
        print(f'\nReport written to {args.report}')

    return 0


if __name__ == '__main__':
    sys.exit(main())
