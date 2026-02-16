// Run a wasm32-wasi test binary using Node.js WASI
// Usage: node --experimental-wasi-unstable-preview1 scripts/run_wasm_test.mjs [test.wasm]
import { readFileSync } from "fs";
import { WASI } from "wasi";
import { argv } from "process";
import { dirname, resolve } from "path";
import { fileURLToPath } from "url";

const __dirname = dirname(fileURLToPath(import.meta.url));
const SWFRECOMP_ROOT = resolve(__dirname, "..");

const wasmPath = argv[2] || resolve(SWFRECOMP_ROOT, "build_wasm", "tests", "add", "test.wasm");

const wasi = new WASI({
    version: "preview1",
    args: [wasmPath],
    env: {},
    preopens: {},
    returnOnExit: true,
});

const wasmBytes = readFileSync(wasmPath);
const compiled = await WebAssembly.compile(wasmBytes);
const importObj = wasi.getImportObject();
const instance = await WebAssembly.instantiate(compiled, importObj);

console.error("Exports:", Object.keys(instance.exports).join(", "));

const exitCode = wasi.start(instance);
console.error(`\nExit code: ${exitCode}`);
