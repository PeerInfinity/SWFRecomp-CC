// test_swf_inject.mjs — byte-identity contract test: swf_inject.mjs must
// produce EXACTLY the bytes of inject_tracer.py for the same inputs (the
// embedding host's vendored copy pins the same check on its side).
//
// Usage: node tools/divergence/test_swf_inject.mjs <target.swf> <bytecode.bin>
//        (defaults: the Doodle Jump test SWF + dj_loader's loader_bytecode.bin)
import { execFileSync } from 'node:child_process';
import { readFileSync, mkdtempSync, rmSync } from 'node:fs';
import { tmpdir } from 'node:os';
import { join, dirname } from 'node:path';
import { fileURLToPath } from 'node:url';
import { injectSwf } from './swf_inject.mjs';

const HERE = dirname(fileURLToPath(import.meta.url));
const ROOT = join(HERE, '..', '..');
const swfPath = process.argv[2]
	|| join(ROOT, 'SWFRecomp/tests/flasharchive/Doodle_Jump/test.swf');
const binPath = process.argv[3]
	|| join(ROOT, 'ruffle-tests/tests/swfs/_swfbridge/livetest/dj_loader/loader_bytecode.bin');

const swf = new Uint8Array(readFileSync(swfPath));
const bin = new Uint8Array(readFileSync(binPath));

let fail = 0;
const tmp = mkdtempSync(join(tmpdir(), 'swfinject-'));
try {
	for (const stageWidth of [0, 600]) {
		const args = [join(HERE, 'inject_tracer.py'), swfPath, join(tmp, 'py.swf'),
			'--bytecode', binPath];
		if (stageWidth) args.push('--stage-width', String(stageWidth));
		execFileSync('python3', args, { stdio: ['ignore', 'ignore', 'ignore'] });
		const py = new Uint8Array(readFileSync(join(tmp, 'py.swf')));
		const js = await injectSwf(swf, bin, { stageWidth });
		const ok = py.length === js.length && py.every((b, i) => b === js[i]);
		console.log(`stageWidth=${stageWidth}: py=${py.length}B js=${js.length}B `
			+ (ok ? 'IDENTICAL' : 'MISMATCH'));
		if (!ok) fail = 1;
	}
} finally {
	rmSync(tmp, { recursive: true, force: true });
}
process.exit(fail);
