// SWFRecomp In-Browser Pipeline
// Phase 1: SWFRecomp.wasm (SWF → C files)
// Phase 2: Clang via @wasmer/sdk (C → WASM)
// Phase 3: WASI shim (run WASM, capture trace output)

import { createWASI } from "./wasi_shim.js";


// --- UI helpers ---

function setStep(stepId, state) {
    const el = document.getElementById(stepId);
    el.className = "status-step " + state;
    if (state === "active") el.textContent = el.textContent.replace(/[^\w\s.]/g, "") + " ...";
}

function showStatus() {
    document.getElementById("status").classList.add("visible");
}

function showOutput(text) {
    const container = document.getElementById("output-container");
    container.classList.add("visible");
    document.getElementById("output").textContent = text;
}

function showError(message) {
    const container = document.getElementById("output-container");
    container.classList.add("visible");
    document.getElementById("output-label").textContent = "Error";
    document.getElementById("output-label").style.color = "#ff6b6b";
    document.getElementById("output").textContent = message;
}

// --- Phase 1: Recompile SWF → C files ---

let recompilerModule = null;

async function loadRecompiler() {
    if (recompilerModule) return recompilerModule;

    // SWFRecomp.js is an Emscripten UMD script (not an ES module).
    // Load it via a script tag and access the global SWFRecompModule.
    if (!globalThis.SWFRecompModule) {
        await new Promise((resolve, reject) => {
            const script = document.createElement("script");
            script.src = "SWFRecomp.js";
            script.onload = resolve;
            script.onerror = () => reject(new Error("Failed to load SWFRecomp.js"));
            document.head.appendChild(script);
        });
    }

    recompilerModule = await SWFRecompModule();
    return recompilerModule;
}

function recompileSWF(Module, swfBytes) {
    // Clean up previous run
    try { Module.FS.rmdir("RecompiledTags"); } catch {}
    try { Module.FS.rmdir("RecompiledScripts"); } catch {}
    for (const dir of ["RecompiledTags", "RecompiledScripts"]) {
        try {
            const files = Module.FS.readdir(dir).filter(f => f !== "." && f !== "..");
            for (const f of files) Module.FS.unlink(`${dir}/${f}`);
            Module.FS.rmdir(dir);
        } catch {}
    }

    // Write SWF and config
    Module.FS.writeFile("input.swf", new Uint8Array(swfBytes));
    Module.FS.writeFile("config.toml", [
        "[input]",
        'path_to_swf = "input.swf"',
        'output_tags_folder = "RecompiledTags"',
        'output_scripts_folder = "RecompiledScripts"',
        "",
    ].join("\n"));

    // Run recompiler
    Module.callMain(["config.toml"]);

    // Collect generated files
    const files = {};
    for (const dir of ["RecompiledTags", "RecompiledScripts"]) {
        let entries;
        try {
            entries = Module.FS.readdir(dir).filter(f => f !== "." && f !== "..");
        } catch {
            continue;
        }
        for (const file of entries) {
            const content = new TextDecoder().decode(Module.FS.readFile(`${dir}/${file}`));
            files[file] = content;
        }
    }

    return files;
}

// --- Phase 2: Compile C → WASM via @wasmer/sdk ---

let wasmerInited = false;
let clangPkg = null;

// Intercept both fetch() and XHR to the Wasmer registry and return a
// pre-computed response. Firefox includes User-Agent in CORS preflight
// headers, and registry.wasmer.io doesn't allow it, so the request is
// impossible. We bypass the registry entirely with a cached real response.
let _cachedRegistryResponse = null;
async function getRegistryResponse() {
    if (!_cachedRegistryResponse) {
        const resp = await _originalFetch("./clang_registry_response.json");
        _cachedRegistryResponse = await resp.text();
    }
    return _cachedRegistryResponse;
}

// Patch fetch()
const _originalFetch = globalThis.fetch;
globalThis.fetch = function(input, init) {
    const url = typeof input === "string" ? input : (input instanceof Request ? input.url : "");
    if (url.includes("registry.wasmer.io")) {
        return getRegistryResponse().then(body => {
            return new Response(body, {
                status: 200,
                headers: { "Content-Type": "application/json" },
            });
        });
    }
    return _originalFetch.call(this, input, init);
};

// Patch XHR (fallback — SDK may retry with XHR if fetch path fails)
const _xhrOpen = XMLHttpRequest.prototype.open;
const _xhrSend = XMLHttpRequest.prototype.send;
XMLHttpRequest.prototype.open = function(method, url, ...rest) {
    this._targetUrl = typeof url === "string" ? url : "";
    return _xhrOpen.call(this, method, url, ...rest);
};
XMLHttpRequest.prototype.send = function(body) {
    if (this._targetUrl.includes("registry.wasmer.io")) {
        const xhr = this;
        getRegistryResponse().then(responseText => {
            setTimeout(() => {
                Object.defineProperties(xhr, {
                    readyState: { get: () => 4 },
                    status: { get: () => 200 },
                    statusText: { get: () => "OK" },
                    responseText: { get: () => responseText },
                    response: { get: () => responseText },
                });
                xhr.dispatchEvent(new Event("readystatechange"));
                xhr.dispatchEvent(new Event("load"));
                xhr.dispatchEvent(new Event("loadend"));
            }, 0);
        });
        return;
    }
    return _xhrSend.call(this, body);
};

// Monkey-patch WebAssembly.Module to log the real error before the SDK
// crashes trying to stringify it (module.rs:74 unwrap-on-None bug).
const _OrigWasmModule = WebAssembly.Module;
WebAssembly.Module = function(bytes) {
    try {
        return new _OrigWasmModule(bytes);
    } catch(e) {
        console.error("[WebAssembly.Module INTERCEPTED]", e);
        console.error("  type:", e?.constructor?.name);
        console.error("  message:", e?.message);
        const input = bytes instanceof ArrayBuffer ? bytes : (bytes?.buffer || bytes);
        console.error("  input size:", input?.byteLength, "bytes");
        throw e;
    }
};
WebAssembly.Module.prototype = _OrigWasmModule.prototype;
Object.setPrototypeOf(WebAssembly.Module, _OrigWasmModule);

async function initWasmer() {
    if (wasmerInited) return;

    const { init } = await import("https://unpkg.com/@wasmer/sdk@0.8.0-beta.1/dist/index.mjs");
    await init({});
    wasmerInited = true;
}

async function loadClang() {
    if (clangPkg) return clangPkg;

    const { Wasmer } = await import("https://unpkg.com/@wasmer/sdk@0.8.0-beta.1/dist/index.mjs");
    clangPkg = await Wasmer.fromRegistry("clang/clang");
    return clangPkg;
}

async function compileToWasm(generatedFiles, setStatus) {
    if (!setStatus) setStatus = () => {};
    const { Directory } = await import("https://unpkg.com/@wasmer/sdk@0.8.0-beta.1/dist/index.mjs");

    const clang = await loadClang();
    setStatus("Setting up project files");
    const project = new Directory();

    // All paths are relative to the Directory root.
    // The Directory is mounted at /project, so "libswfruntime.a" -> /project/libswfruntime.a

    // Write pre-compiled runtime library
    const libResponse = await fetch("./libswfruntime.a");
    const libBytes = new Uint8Array(await libResponse.arrayBuffer());
    await project.writeFile("libswfruntime.a", libBytes);

    // Write runtime headers/support files needed during compilation.
    const runtimeHeaders = ["unicode_case_tables.h", "map.h", "o1heap.h"];
    for (const f of runtimeHeaders) {
        const resp = await fetch(`./runtime_src/${f}`);
        const bytes = new Uint8Array(await resp.arrayBuffer());
        await project.writeFile(f, bytes);
    }

    // Write pre-compiled .o files for large runtime sources.
    // action.c (~10K lines) and object.c (~3K lines) are too large for
    // in-WASI clang. They're pre-compiled offline with matching flags.
    for (const f of ["action.o", "object.o"]) {
        const resp = await fetch(`./runtime_src/${f}`);
        const bytes = new Uint8Array(await resp.arrayBuffer());
        await project.writeFile(f, bytes);
    }

    // Write runtime headers (paths like "include/common.h" -> /project/include/common.h)
    // Create parent directories first (Directory doesn't auto-create them)
    const headerDirs = new Set();
    const headerList = await fetch("./runtime_headers/manifest.json").then(r => r.json());
    for (const { path } of headerList) {
        const dir = path.substring(0, path.lastIndexOf("/"));
        if (dir) headerDirs.add(dir);
    }
    for (const dir of [...headerDirs].sort()) {
        await project.createDir(dir);
    }

    for (const { path, file } of headerList) {
        const resp = await fetch(`./runtime_headers/${file}`);
        const bytes = new Uint8Array(await resp.arrayBuffer());
        await project.writeFile(path, bytes);
    }

    // Write main.c wrapper
    const mainResp = await fetch("./runtime_src/main.c");
    await project.writeFile("main.c", new Uint8Array(await mainResp.arrayBuffer()));

    // Write generated files
    for (const [name, content] of Object.entries(generatedFiles)) {
        await project.writeFile(name, new TextEncoder().encode(content));
    }

    // Collect .c files to compile in-browser.
    // action.c (~10K lines) and object.c (~3K lines) are too large for
    // in-WASI clang (cc1 crashes with exit 45, likely OOM). These are
    // runtime files that don't change per-SWF — pre-compile them offline.
    const cFiles = [
        "main.c",
        ...Object.keys(generatedFiles).filter(f => f.endsWith(".c")),
    ];

    // The clang entrypoint (slim driver) has preset main-args that include
    // -pthread, --shared-memory, etc. The resulting WASM binary imports
    // shared memory and wasix_32v1 threading functions. The WASI shim
    // handles these with appropriate stubs.
    const clangCmd = clang.entrypoint;

    // Helper: run a command via cmd.run(), return wait() result
    async function runCmd(cmd, args, opts) {
        const instance = await cmd.run({ args, ...opts });
        return await instance.wait();
    }

    const mounts = { "/project": project };

    console.log("[DEBUG] crossOriginIsolated:", globalThis.crossOriginIsolated);
    console.log("[DIAG] clang package commands:", Object.keys(clang.commands || {}));
    console.log("[DIAG] .c files to compile:", cFiles);

    // Compile all generated .c files + link in a single invocation.
    setStatus(`Compiling ${cFiles.length} files and linking`);

    const compileResult = await runCmd(clangCmd, [
        ...cFiles.map(f => `/project/${f}`),
        "-DNO_GRAPHICS",
        "-include", "string.h",
        "-include", "strings.h",
        "-I/project",
        "-I/project/include",
        "-I/project/include/actionmodern",
        "-I/project/include/libswf",
        "-I/project/include/memory",
        "-O0",
        "-w",
        "/project/action.o",
        "/project/object.o",
        "/project/libswfruntime.a",
        "-o", "/project/output.wasm",
    ], { mount: mounts });
    console.log(`[COMPILE+LINK] ok=${compileResult.ok} code=${compileResult.code}`);
    console.log(`[COMPILE+LINK] stdout=`, compileResult.stdout || "(empty)");
    console.log(`[COMPILE+LINK] stderr=`, compileResult.stderr || "(empty)");
    if (!compileResult.ok) {
        throw new Error(`Compile+link failed (code ${compileResult.code}):\n${compileResult.stderr || compileResult.stdout || "(no output)"}`);
    }

    // readFile path is relative to the Directory root, not the mount point
    return await project.readFile("output.wasm");
}

// --- Phase 3: Run WASM, capture trace output ---

function extractTraceOutput(stdout) {
    const lines = stdout.split("\n");
    const trace = [];
    for (const line of lines) {
        if (line.startsWith("[") || line.startsWith("===") ||
            line.startsWith("SWF Runtime") || line.startsWith("WASM SWF")) {
            continue;
        }
        trace.push(line);
    }
    // Trim leading/trailing blank lines
    while (trace.length && trace[trace.length - 1] === "") trace.pop();
    while (trace.length && trace[0] === "") trace.shift();
    return trace.join("\n");
}

// --- Graphics pipeline integration ---

async function processSwfGraphics(swfBytes) {
    const { initWasmer: gfxInitWasmer, loadClang: gfxLoadClang,
            compileGuestModule, runGraphicsGuest } = await import("./pipeline_graphics.js");

    showStatus();
    const steps = ["step-recompile", "step-compile", "step-run"];
    steps.forEach(s => setStep(s, ""));

    try {
        // Phase 1: Recompile SWF → C (same as trace)
        setStep("step-recompile", "active");
        const RecompModule = await loadRecompiler();
        const generatedFiles = recompileSWF(RecompModule, swfBytes);
        const fileCount = Object.keys(generatedFiles).length;
        setStep("step-recompile", "done");
        document.getElementById("step-recompile").textContent =
            `Recompiled SWF to ${fileCount} C files`;

        // Phase 2: Compile guest WASM
        setStep("step-compile", "active");
        const compileStatus = document.getElementById("step-compile");
        const setCompileStatus = (msg) => { compileStatus.textContent = msg + " ..."; };
        setCompileStatus("Initializing Wasmer SDK");
        await gfxInitWasmer();
        setCompileStatus("Loading Clang compiler (~100 MB)");
        await gfxLoadClang();
        const guestWasm = await compileGuestModule(generatedFiles, setCompileStatus);
        setStep("step-compile", "done");
        document.getElementById("step-compile").textContent =
            `Compiled guest to WASM (${(guestWasm.length / 1024).toFixed(0)} KB)`;

        // Phase 3: Load host + instantiate guest + run
        document.getElementById("step-run").style.display = "";
        setStep("step-run", "active");
        document.getElementById("step-run").textContent = "Loading graphics host + running...";
        await runGraphicsGuest(guestWasm);
        setStep("step-run", "done");

    } catch (e) {
        console.error(e);
        const currentStep = steps.find(s =>
            document.getElementById(s).classList.contains("active"));
        if (currentStep) setStep(currentStep, "error");
        showError(e.message);
    }
}

// --- Main pipeline ---

function getSelectedMode() {
    return document.querySelector('input[name="mode"]:checked')?.value || "trace";
}

// Detect if generated files indicate graphics content
function detectGraphicsFromFiles(generatedFiles) {
    const draws = generatedFiles["draws.c"] || "";
    // shape_data[1] = empty placeholder (trace), shape_data[N>1] = real shapes (graphics)
    const match = draws.match(/shape_data\[(\d+)\]/);
    if (match && parseInt(match[1]) > 1) return true;
    // Also check for tagDefineShape in tagMain.c
    const tagMain = generatedFiles["tagMain.c"] || "";
    if (tagMain.includes("tagDefineShape")) return true;
    return false;
}

async function processSwf(swfBytes, modeOverride) {
    let mode = modeOverride || getSelectedMode();

    if (mode === "auto" || mode === "graphics") {
        // For auto mode on dropped files, we need to recompile first to detect.
        // For explicit graphics or auto-detected graphics, use the graphics pipeline.
        if (mode === "auto") {
            // Quick recompile to detect mode
            const Module = await loadRecompiler();
            const files = recompileSWF(Module, swfBytes);
            mode = detectGraphicsFromFiles(files) ? "graphics" : "trace";
            console.log(`[AUTO] Detected mode: ${mode}`);
        }
        if (mode === "graphics") {
            return processSwfGraphics(swfBytes);
        }
    }
    showStatus();
    const steps = ["step-recompile", "step-compile", "step-run"];
    steps.forEach(s => setStep(s, ""));
    document.getElementById("step-run").style.display = "none";

    try {
        // Phase 1: Recompile SWF → C
        setStep("step-recompile", "active");
        const Module = await loadRecompiler();
        const generatedFiles = recompileSWF(Module, swfBytes);
        const fileCount = Object.keys(generatedFiles).length;
        setStep("step-recompile", "done");
        document.getElementById("step-recompile").textContent =
            `Recompiled SWF to ${fileCount} C files`;

        // Phase 2: Compile C → WASM
        setStep("step-compile", "active");
        const compileStatus = document.getElementById("step-compile");
        const setCompileStatus = (msg) => { compileStatus.textContent = msg + " ..."; };
        setCompileStatus("Initializing Wasmer SDK");
        await initWasmer();
        setCompileStatus("Loading Clang compiler (~100 MB)");
        const wasmBytes = await compileToWasm(generatedFiles, setCompileStatus);
        setStep("step-compile", "done");
        document.getElementById("step-compile").textContent =
            `Compiled to WASM (${(wasmBytes.length / 1024).toFixed(0)} KB)`;

        // Phase 3: Run WASM
        document.getElementById("step-run").style.display = "";
        setStep("step-run", "active");
        console.log(`[PHASE 3] Running WASM (${wasmBytes.length} bytes)`);
        const wasi = createWASI();
        const result = await wasi.run(wasmBytes);
        console.log(`[PHASE 3] exitCode=${result.exitCode}`);
        console.log(`[PHASE 3] stdout=${JSON.stringify(result.stdout)}`);
        console.log(`[PHASE 3] stderr=${JSON.stringify(result.stderr)}`);
        setStep("step-run", "done");

        const trace = extractTraceOutput(result.stdout);
        if (trace) {
            showOutput(trace);
        } else {
            showOutput("(no trace output)");
        }

        if (result.stderr) {
            console.warn("stderr:", result.stderr);
        }

    } catch (e) {
        console.error(e);
        const currentStep = steps.find(s =>
            document.getElementById(s).classList.contains("active"));
        if (currentStep) setStep(currentStep, "error");
        showError(e.message);
    }
}

// --- File drop / click handlers ---

const dropZone = document.getElementById("dropZone");
const fileInput = document.getElementById("fileInput");

dropZone.addEventListener("click", () => fileInput.click());

dropZone.addEventListener("dragover", (e) => {
    e.preventDefault();
    dropZone.classList.add("dragover");
});

dropZone.addEventListener("dragleave", () => {
    dropZone.classList.remove("dragover");
});

dropZone.addEventListener("drop", (e) => {
    e.preventDefault();
    dropZone.classList.remove("dragover");
    const file = e.dataTransfer.files[0];
    if (file) handleFile(file);
});

fileInput.addEventListener("change", () => {
    const file = fileInput.files[0];
    if (file) handleFile(file);
});

function handleFile(file) {
    if (!file.name.endsWith(".swf")) {
        showError("Please select a .swf file");
        return;
    }
    setListOpen(false);
    dropZone.querySelector("p").textContent = file.name;

    const reader = new FileReader();
    reader.onload = () => processSwf(reader.result);
    reader.readAsArrayBuffer(file);
}

// --- Demo search + run ---

let demoList = { trace: [], graphics: [] };
let selectedDemo = null;

// Load demo manifest
fetch("./demos.json").then(r => r.json()).then(data => {
    demoList = data;
    updateDemoSearch();
}).catch(() => {
    // Fallback if demos.json doesn't exist
    demoList = { trace: ["add_swf_4"], graphics: ["keyboard_input"] };
    updateDemoSearch();
});

const demoSearch = document.getElementById("demoSearch");
const demoResults = document.getElementById("demoResults");

function getEffectiveMode() {
    const mode = getSelectedMode();
    return mode === "auto" ? "trace" : mode;  // for demo list, auto shows trace
}

function getDemosForMode() {
    const mode = getSelectedMode();
    if (mode === "auto") {
        // Show both lists combined, with graphics prefixed
        return [
            ...demoList.trace,
            ...demoList.graphics.map(d => `graphics/${d}`),
        ];
    }
    return mode === "graphics" ? demoList.graphics : demoList.trace;
}

function updateDemoSearch() {
    const demos = getDemosForMode();
    const mode = getSelectedMode();
    demoSearch.placeholder = `Search demos... (${demos.length} ${mode} tests)`;
    if (selectedDemo && !demos.includes(selectedDemo)) {
        selectedDemo = null;
        demoSearch.value = "";
    }
    filterDemos();
}

function highlightMatch(text, query) {
    if (!query) return text;
    const idx = text.toLowerCase().indexOf(query.toLowerCase());
    if (idx < 0) return text;
    return text.slice(0, idx) +
        `<span class="match">${text.slice(idx, idx + query.length)}</span>` +
        text.slice(idx + query.length);
}

const browseBtn = document.getElementById("demoBrowseBtn");

function setListOpen(open) {
    if (open) {
        filterDemos();
        browseBtn.style.borderColor = "#4ecca3";
        browseBtn.style.color = "#4ecca3";
    } else {
        demoResults.style.display = "none";
        browseBtn.style.borderColor = "#555";
        browseBtn.style.color = "#888";
    }
}

function filterDemos() {
    const query = demoSearch.value.trim();
    const demos = getDemosForMode();
    const filtered = query
        ? demos.filter(d => d.toLowerCase().includes(query.toLowerCase()))
        : demos;

    if (filtered.length === 0) {
        demoResults.innerHTML = `<div style="padding: 0.4rem 0.8rem; color: #666; font-size: 0.85em;">No matches</div>`;
    } else {
        demoResults.innerHTML = filtered.map(d =>
            `<div class="demo-item${d === selectedDemo ? ' selected' : ''}" data-demo="${d}">${highlightMatch(d, query)}</div>`
        ).join("");
    }
    demoResults.style.display = "block";
    browseBtn.style.borderColor = "#4ecca3";
    browseBtn.style.color = "#4ecca3";
}

function isListOpen() {
    return demoResults.style.display !== "none";
}

demoSearch.addEventListener("input", () => { setListOpen(true); });
demoSearch.addEventListener("focus", () => { setListOpen(true); });
demoSearch.addEventListener("blur", () => {
    setTimeout(() => { setListOpen(false); }, 200);
});

browseBtn.addEventListener("click", () => {
    if (isListOpen()) {
        setListOpen(false);
    } else {
        setListOpen(true);
        demoSearch.focus();
    }
});
demoSearch.addEventListener("keydown", (e) => {
    if (e.key === "Enter") {
        const demos = getDemosForMode();
        const query = demoSearch.value.trim();
        const match = query
            ? demos.find(d => d.toLowerCase().includes(query.toLowerCase()))
            : null;
        if (match) {
            selectedDemo = match;
            demoSearch.value = match;
            demoResults.style.display = "none";
            runSelectedDemo();
        }
    }
});

demoResults.addEventListener("click", (e) => {
    const item = e.target.closest(".demo-item");
    if (item) {
        selectedDemo = item.dataset.demo;
        demoSearch.value = selectedDemo;
        setListOpen(false);
    }
});

document.querySelectorAll('input[name="mode"]').forEach(r =>
    r.addEventListener("change", updateDemoSearch)
);

async function runSelectedDemo() {
    if (!selectedDemo) return;
    const mode = getSelectedMode();

    // Determine if this is a graphics demo
    let isGraphics;
    if (mode === "auto") {
        isGraphics = selectedDemo.startsWith("graphics/");
    } else {
        isGraphics = mode === "graphics";
    }

    // Build the URL — strip "graphics/" prefix for the path
    const demoName = selectedDemo.replace(/^graphics\//, "");
    const swfUrl = isGraphics
        ? `../examples/graphics/${demoName}/test.swf`
        : `../examples/${demoName}/test.swf`;

    dropZone.querySelector("p").textContent = `${selectedDemo}/test.swf`;
    const resp = await fetch(swfUrl);
    if (!resp.ok) {
        showError(`Could not load ${swfUrl}`);
        return;
    }
    const bytes = await resp.arrayBuffer();
    processSwf(bytes, isGraphics ? "graphics" : "trace");
}

document.getElementById("demoBtn").addEventListener("click", () => {
    setListOpen(false);
    if (selectedDemo) {
        runSelectedDemo();
    } else {
        // Fallback: pick first demo
        const demos = getDemosForMode();
        if (demos.length > 0) {
            selectedDemo = demos[0];
            demoSearch.value = selectedDemo;
            runSelectedDemo();
        }
    }
});
