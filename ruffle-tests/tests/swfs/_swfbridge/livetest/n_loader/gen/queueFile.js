// queueFile.js - write a batch of levels to the browser global file the Ruffle
// QUEUE harness reads (window.__N_QUEUE). Shared by make_queue_testcases.mjs and
// nVerify.js so the on-disk format stays in one place.
import { writeFileSync } from "node:fs";

const BANNER =
	"// n_queue_testcases.js - GENERATED. Authored/generated levels (N format) for\n" +
	"// the Ruffle batch-verify queue. Not N's proprietary built-in data. Regenerate\n" +
	"// via gen/make_queue_testcases.mjs or gen/nVerify.js; do not edit by hand.\n";

/** Write `payloads` ({levelId, level, demo}) to `path` as window.__N_QUEUE. */
export function writeQueueFile(path, payloads) {
	const slim = payloads.map(({ levelId, level, demo }) => ({ levelId, level, demo }));
	writeFileSync(path, BANNER + "window.__N_QUEUE = " + JSON.stringify(slim, null, 2) + ";\n");
}
