// Run the Emscripten build of the recompiler (SWFRecomp.js/.wasm) under Node —
// the same module the in-browser recompiler page uses — on one SWF.
//
// Usage: node scripts/test_wasm_recompiler.mjs [options] [path/to/test.swf]
//   --module PATH   SWFRecomp.js to load (default: build_wasm/SWFRecomp.js;
//                   docs/recompiler/SWFRecomp.js after deploy_wasm_demo.sh)
//   --out DIR       write RecompiledTags/, RecompiledScripts/ (and
//                   RecompiledABC/ for AS3 SWFs) under DIR instead of dumping
//                   file contents to stdout
//   --quiet         only print the summary line
// Exit status is non-zero if the recompiler fails or produces no files, so this
// doubles as the CI smoke for SWFRecomp.wasm (see bundle_smoke.sh).

import { readFileSync, writeFileSync, mkdirSync } from "fs";
import { dirname, resolve, join } from "path";
import { fileURLToPath } from "url";

const __dirname = dirname(fileURLToPath(import.meta.url));
const SWFRECOMP_ROOT = resolve(__dirname, "..");
const GENERATED_DIRS = ["RecompiledTags", "RecompiledScripts", "RecompiledABC"];

let modulePath = resolve(SWFRECOMP_ROOT, "build_wasm", "SWFRecomp.js");
let outDir = null;
let quiet = false;
let swfPath = null;
const args = process.argv.slice(2);
for (let i = 0; i < args.length; i++) {
    if (args[i] === "--module") modulePath = resolve(args[++i]);
    else if (args[i] === "--out") outDir = resolve(args[++i]);
    else if (args[i] === "--quiet") quiet = true;
    else swfPath = resolve(args[i]);
}
if (!swfPath) swfPath = resolve(SWFRECOMP_ROOT, "tests", "trace_hello_world", "test.swf");

const createModule = (await import(modulePath)).default;
const log = [];
const Module = await createModule({
    print: (t) => log.push(t),
    printErr: (t) => log.push(t),
});

Module.FS.writeFile("input.swf", readFileSync(swfPath));
Module.FS.writeFile("config.toml", [
    "[input]",
    'path_to_swf = "input.swf"',
    'output_tags_folder = "RecompiledTags"',
    'output_scripts_folder = "RecompiledScripts"',
    "",
].join("\n"));

let exitCode = 0;
let crash = null;
try {
    exitCode = Module.callMain(["config.toml"]) || 0;
} catch (e) {
    if (e && e.name === "ExitStatus") exitCode = e.status;
    else crash = e;
}

function collect(dir, prefix, out) {
    let entries;
    try { entries = Module.FS.readdir(dir).filter(f => f !== "." && f !== ".."); }
    catch { return; }
    for (const name of entries.sort()) {
        const full = `${dir}/${name}`;
        if (Module.FS.isDir(Module.FS.stat(full).mode)) collect(full, `${prefix}${name}/`, out);
        else out[`${prefix}${name}`] = Module.FS.readFile(full);
    }
}
const files = {};
for (const d of GENERATED_DIRS) collect(d, `${d}/`, files);
const names = Object.keys(files);
const total = names.reduce((n, k) => n + files[k].length, 0);

if (crash || exitCode !== 0 || names.length === 0) {
    console.error(`FAIL: ${swfPath}: ${crash ? `crash: ${crash.message || crash}` : `exit ${exitCode}`}, ${names.length} files`);
    console.error(log.join("\n"));
    process.exit(1);
}

if (outDir) {
    for (const [rel, bytes] of Object.entries(files)) {
        const p = join(outDir, rel);
        mkdirSync(dirname(p), { recursive: true });
        writeFileSync(p, bytes);
    }
    writeFileSync(join(outDir, "recompiler.log"), log.join("\n") + "\n");
} else if (!quiet) {
    console.log(log.join("\n"));
    for (const rel of names) {
        console.log(`\n--- ${rel} (${files[rel].length} bytes) ---`);
        console.log(new TextDecoder().decode(files[rel]));
    }
}
console.log(`OK: ${swfPath} -> ${names.length} files, ${total} bytes${outDir ? ` in ${outDir}` : ""}${names.some(n => n.startsWith("RecompiledABC/")) ? " (AVM2)" : ""}`);
