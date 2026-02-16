// Test the WASM-compiled SWFRecomp recompiler
// Usage: node scripts/test_wasm_recompiler.mjs [path/to/test.swf]
// Default: tests/trace_hello_world/test.swf

import { readFileSync } from "fs";
import { dirname, resolve } from "path";
import { fileURLToPath } from "url";

const __dirname = dirname(fileURLToPath(import.meta.url));
const SWFRECOMP_ROOT = resolve(__dirname, "..");

// Load the WASM module
const createModule = (await import(resolve(SWFRECOMP_ROOT, "build_wasm", "SWFRecomp.js"))).default;
const Module = await createModule();

// Determine SWF path
const swfPath = process.argv[2] || resolve(SWFRECOMP_ROOT, "tests", "trace_hello_world", "test.swf");
const swfData = readFileSync(swfPath);

// Write SWF and config to MEMFS
Module.FS.writeFile("input.swf", swfData);
Module.FS.writeFile("config.toml", [
    "[input]",
    'path_to_swf = "input.swf"',
    'output_tags_folder = "RecompiledTags"',
    'output_scripts_folder = "RecompiledScripts"',
    "",
].join("\n"));

// Run recompiler
console.log(`Recompiling: ${swfPath}`);
Module.callMain(["config.toml"]);

// List generated files
console.log("\n=== Generated files ===");
for (const dir of ["RecompiledTags", "RecompiledScripts"]) {
    let entries;
    try {
        entries = Module.FS.readdir(dir).filter(f => f !== "." && f !== "..");
    } catch {
        console.log(`(directory ${dir} not created)`);
        continue;
    }
    for (const file of entries.sort()) {
        const content = new TextDecoder().decode(Module.FS.readFile(`${dir}/${file}`));
        console.log(`\n--- ${dir}/${file} (${content.length} bytes) ---`);
        console.log(content);
    }
}
