// In-browser C -> WASM build + run (stage 2 of the in-browser recompiler).
//
//   1. Load the pre-built graphics HOST (host/graphics_host.{js,wasm}: the whole
//      SWFModernRuntime graphics runtime, Emscripten/WebGPU, built with
//      -DDYNAMIC_HOST by SWFRecomp/scripts/build_graphics_host.sh).
//   2. Compile the generated C (the "guest") with clang running in the browser
//      (@wasmer/sdk + the clang/clang registry package), linked with
//      --import-memory and --global-base = the host's guest arena.
//   3. Instantiate the guest against the host's memory, resolve its imports from
//      the host's exports, and mirror the guest's function table into the host's
//      reserved low table slots so guest function pointers are valid host-side.
//   4. Hand the host the guest's data tables + frame functions, then runSWF().
//
// Design notes and the spike that fixed this shape:
// SWFRecompDocs/plans/in-browser-recompiler-refresh-assessment.md §7.

const SDK_URL = "https://unpkg.com/@wasmer/sdk@0.8.0-beta.1/dist/index.mjs";
const HOST_DIR = "host/";
// Must match host_main_graphics.c / build_graphics_host.sh (GUEST_ARENA_BASE,
// GUEST_ARENA_END); checked against the host's exports before running.
const GUEST_ARENA_BASE = 65536;
const GUEST_ARENA_END = 101 * 1024 * 1024;

let sdk = null;
let clangPkg = null;
let hostFactoryLoaded = false;
let hostInstance = null;   // one host per page: the runtime has global state
let hostRawExports = null; // instance.exports BEFORE Emscripten's JSPI export wrappers
let hostUsed = false;

export function hostAlreadyUsed() { return hostUsed; }

// --- Host ---

export async function loadHost(canvas, log) {
    if (hostInstance) return hostInstance;
    if (typeof WebAssembly.Suspending !== "function") {
        throw new Error("This browser lacks WebAssembly JS Promise Integration (JSPI), which the graphics host needs to suspend mid-frame across in-browser-compiled code. Use Chrome 137+ (or download the build bundle).");
    }
    if (!hostFactoryLoaded) {
        await new Promise((resolve, reject) => {
            const s = document.createElement("script");
            s.src = HOST_DIR + "graphics_host.js";
            s.onload = resolve;
            s.onerror = () => reject(new Error("Failed to load host/graphics_host.js — was the page deployed with the graphics host?"));
            document.head.appendChild(s);
        });
        hostFactoryLoaded = true;
    }
    hostInstance = await createGraphicsHost({
        canvas,
        locateFile: (p) => HOST_DIR + p,
        print: (t) => log(t),
        printErr: (t) => log(t),
        // Emscripten wraps every export in a JS function under JSPI; a guest
        // calling the host through such a wrapper puts a JS frame on the stack,
        // and JSPI cannot suspend across JS frames ("trying to suspend JS
        // frames"). Capture the raw wasm exports here for the guest's imports.
        instantiateWasm: (imports, onSuccess) => {
            WebAssembly.instantiateStreaming(fetch(HOST_DIR + "graphics_host.wasm"), imports)
                .then(({ instance, module }) => { hostRawExports = instance.exports; onSuccess(instance, module); })
                .catch((e) => log(`[host] instantiate failed: ${e}`));
            return {};
        },
    });
    if (!hostRawExports) throw new Error("host instantiated without exposing raw exports");
    const arena = hostInstance._get_guest_arena(), size = hostInstance._get_guest_arena_size();
    if (arena !== GUEST_ARENA_BASE || arena + size !== GUEST_ARENA_END) {
        throw new Error(`host/page arena mismatch: host [${arena}, ${arena + size}) vs page [${GUEST_ARENA_BASE}, ${GUEST_ARENA_END})`);
    }
    return hostInstance;
}

// --- Clang ---

export async function loadClang(setStatus) {
    if (clangPkg) return clangPkg;
    setStatus("Loading Wasmer SDK");
    sdk = await import(SDK_URL);
    await sdk.init({});
    setStatus("Loading Clang (~100 MB, cached by the browser after the first time)");
    clangPkg = await sdk.Wasmer.fromRegistry("clang/clang");
    return clangPkg;
}

async function fetchBytes(url) {
    const r = await fetch(url);
    if (!r.ok) throw new Error(`Failed to fetch ${url} (${r.status})`);
    return new Uint8Array(await r.arrayBuffer());
}

// Generated C referencing bridged runtime globals declares them `extern`
// inside function bodies, which clashes with the bridge_globals.h macro
// expansion; strip those. (Same treatment the original pipeline applied.)
function patchGeneratedSource(text) {
    return text
        .replace(/extern\s+ActionVar\s+g_override_this\s*;/g, "/* g_override_this: via bridge */")
        .replace(/extern\s+int\s+g_override_this_set\s*;/g, "/* g_override_this_set: via bridge */")
        .replace(/extern\s+int\s+quit_swf\s*;/g, "/* quit_swf: via bridge */")
        .replace(/extern\s+int\s+catch_up_mode\s*;/g, "/* catch_up_mode: via bridge */")
        .replace(/extern\s+int\s+g_tag_skip_mode\s*;/g, "/* g_tag_skip_mode: via bridge */")
        // clang 16 rejects a declaration directly after a label (C23 allows it,
        // gcc/newer clang accept it): give every bare `label_N:` a null statement.
        .replace(/^(\s*label_\w+:)\s*$/gm, "$1;");
}

export async function compileGuest(result, setStatus) {
    if (Object.keys(result.files).some(p => p.startsWith("RecompiledABC/"))) {
        throw new Error("This is an AS3 (AVM2) SWF. The in-browser run only supports AVM1 so far (the graphics host is built without the AVM2 runtime and AS3 output is too large for the in-browser compiler); download the build bundle instead — its build.sh handles AVM2.");
    }
    const clang = await loadClang(setStatus);
    setStatus("Preparing sources");
    const project = new sdk.Directory();

    // Runtime headers + the few support headers generated code pulls in, from
    // the same snapshot the downloadable bundle uses.
    const manifest = await (await fetch("bundle/manifest.json")).json();
    const headers = manifest.filter(e => e.path.startsWith("runtime/include/") && e.path.endsWith(".h"));
    const dirs = new Set();
    for (const { path } of headers) {
        const rel = path.replace(/^runtime\//, "");        // include/...
        const d = rel.substring(0, rel.lastIndexOf("/"));
        const parts = d.split("/");
        for (let i = 1; i <= parts.length; i++) dirs.add(parts.slice(0, i).join("/"));
    }
    for (const d of [...dirs].sort()) await project.createDir(d);
    await Promise.all(headers.map(async ({ path }) => {
        await project.writeFile(path.replace(/^runtime\//, ""), await fetchBytes(`bundle/${path}`));
    }));
    for (const [src, dst] of [
        ["runtime/lib/c-hashmap/map.h", "map.h"],
        ["runtime/lib/o1heap/o1heap.h", "o1heap.h"],
        ["runtime/src/actionmodern/unicode_case_tables.h", "unicode_case_tables.h"],
    ]) await project.writeFile(dst, await fetchBytes(`bundle/${src}`));
    for (const f of ["guest_main_graphics.c", "bridge_globals.h", "bridge_globals.c"]) {
        await project.writeFile(f, await fetchBytes(HOST_DIR + f));
    }

    // Generated files, flattened (generated code includes them unqualified).
    const cFiles = ["guest_main_graphics.c", "bridge_globals.c"];
    const dec = new TextDecoder();
    for (const [path, bytes] of Object.entries(result.files)) {
        const name = path.substring(path.lastIndexOf("/") + 1);
        if (name.endsWith(".c") || name.endsWith(".h")) {
            await project.writeFile(name, new TextEncoder().encode(patchGeneratedSource(dec.decode(bytes))));
        } else {
            await project.writeFile(name, bytes);
        }
        if (name.endsWith(".c")) cFiles.push(name);
    }

    const arena = GUEST_ARENA_BASE;
    const args = [
        ...cFiles.map(f => `/project/${f}`),
        "-DDYNAMIC_GUEST",
        "-std=gnu2x",
        "-include", "string.h",
        "-include", "strings.h",
        "-I/project", "-I/project/include", "-I/project/include/actionmodern",
        "-I/project/include/libswf", "-I/project/include/memory",
        "-O1", "-w",
        // The clang driver preset already adds --import-memory/--shared-memory.
        `-Wl,--export-table,--global-base=${arena},--allow-undefined,--export-all,--no-entry,-z,stack-size=8388608`,
        "-o", "/project/guest.wasm",
    ];
    setStatus(`Compiling ${cFiles.length} C files with in-browser clang`);
    const t0 = performance.now();
    // The SDK occasionally fails a run with "oneshot canceled" (a worker race
    // in @wasmer/sdk 0.8.0-beta.1); the same command succeeds on retry.
    let r;
    for (let attempt = 1; ; attempt++) {
        try {
            const inst = await clang.entrypoint.run({ args, mount: { "/project": project } });
            r = await inst.wait();
            break;
        } catch (e) {
            if (attempt >= 3 || !/oneshot|canceled|cancelled/i.test(String(e))) throw e;
            setStatus(`Compiler worker hiccup (${e}); retrying ${attempt}/2`);
            await new Promise(res => setTimeout(res, 500));
        }
    }
    const ms = Math.round(performance.now() - t0);
    if (!r.ok) {
        const err = (r.stderr || "").replace(/clang-16: warning: -Wl[^\n]*\n/g, "");
        throw new Error(`In-browser compile failed (code ${r.code}):\n${err || r.stdout || "(no output)"}`);
    }
    const bytes = await project.readFile("guest.wasm");
    return { bytes, ms, fileCount: cFiles.length };
}

// --- Instantiate + run ---

export async function runGuest(guestBytes, host, canvas, setStatus, log) {
    if (hostUsed) throw new Error("The graphics host can only run one SWF per page load — reload the page to run another.");
    hostUsed = true;

    const mod = await WebAssembly.compile(guestBytes);
    const imports = WebAssembly.Module.imports(mod);
    const missing = [];
    const env = { memory: hostRawExports.memory };
    const stub = (name) => (...a) => {
        if (!stub[name]) { stub[name] = 1; log(`[guest] called unresolved runtime function: ${name}`); }
        return 0;
    };
    for (const imp of imports) {
        if (imp.module !== "env" || env[imp.name]) continue;
        if (imp.kind === "function") {
            if (imp.name === "setjmp") {
                // AVM1 try/catch inlines setjmp into generated code and the
                // in-browser clang cannot lower it; run the try body as if no
                // exception can occur. A throw inside it surfaces as an error.
                env.setjmp = () => 0;
            } else if (imp.name === "longjmp") {
                env.longjmp = () => { throw new Error("AVM1 try/catch (longjmp) is not supported in the in-browser build; use the downloadable bundle"); };
            } else {
                const f = hostRawExports[imp.name];
                if (f) env[imp.name] = f;
                else { missing.push(imp.name); env[imp.name] = stub(imp.name); }
            }
        } else if (imp.kind === "global") {
            env[imp.name] = new WebAssembly.Global({ value: "i32", mutable: true }, 0);
        } else if (imp.kind === "table") {
            env[imp.name] = new WebAssembly.Table({ initial: 1, element: "anyfunc" });
        }
    }
    if (missing.length) log(`[guest] ${missing.length} imports not exported by the host: ${missing.slice(0, 12).join(", ")}${missing.length > 12 ? " ..." : ""}`);
    const ENOSYS = 52, EBADF = 8;
    const wasiStubs = new Proxy({}, {
        get(_, p) {
            if (p === "fd_prestat_get" || p === "fd_prestat_dir_name") return () => EBADF;
            if (p === "proc_exit") return (c) => { throw new Error(`guest proc_exit(${c})`); };
            return () => ENOSYS;
        },
    });
    const instance = await WebAssembly.instantiate(mod, { env, wasi_snapshot_preview1: wasiStubs, wasix_32v1: wasiStubs });
    const g = instance.exports;

    // Arena check: guest data + its shadow stack must fit below the host's data.
    const heapBase = g.__heap_base ? g.__heap_base.value : 0;
    if (heapBase && heapBase > GUEST_ARENA_END) {
        throw new Error(`Generated data (${((heapBase - GUEST_ARENA_BASE) / 1048576).toFixed(1)} MB) exceeds the ${((GUEST_ARENA_END - GUEST_ARENA_BASE) / 1048576).toFixed(0)} MB guest arena; use the downloadable bundle for this SWF`);
    }

    // Mirror the guest's function table into the host's reserved low slots.
    const gt = g.__indirect_function_table;
    const base = host._get_host_table_base();
    if (!gt) throw new Error("guest exports no function table (link without --export-table?)");
    if (gt.length > base) throw new Error(`guest function table (${gt.length}) exceeds the host's reserved ${base} slots`);
    const ht = hostRawExports.__indirect_function_table;
    let mirrored = 0;
    for (let i = 1; i < gt.length; i++) {
        const f = gt.get(i);
        if (f) { ht.set(i, f); mirrored++; }
    }
    log(`[guest] function table: ${gt.length} entries, ${mirrored} mirrored into host slots < ${base}; data [${GUEST_ARENA_BASE}, ${heapBase}), frame_funcs[0] = ${new Uint32Array(hostRawExports.memory.buffer, g.get_frame_funcs(), 1)[0]}, tagInit = ${g.get_tagInit_ptr()}`);

    // Bridged runtime globals (bridge_globals.h): guest reads/writes host's copies.
    g.bridge_init(host._get_catch_up_mode_addr(), host._get_g_tag_skip_mode_addr(), host._get_quit_swf_addr(),
                  host._get_g_override_this_addr(), host._get_g_override_this_set_addr());

    const frameCount = g.get_frame_count(), fps = g.get_fps(), swfVersion = g.get_swf_version();
    const width = g.get_frame_width(), height = g.get_frame_height();
    canvas.width = width; canvas.height = height;
    host._configureAppContext(frameCount, fps, swfVersion, width, height);
    host._setFrameFuncs(g.get_frame_funcs());
    host._setTagInit(g.get_tagInit_ptr());
    host._setShapeData(g.get_shape_data(), g.get_shape_data_size());
    host._setTransformData(g.get_transform_data(), g.get_transform_data_size());
    host._setColorData(g.get_color_data(), g.get_color_data_size());
    host._setStageToNdc(g.get_stage_to_ndc());
    host._setBitmapInfo(g.get_bitmap_count(), g.get_bitmap_highest_w(), g.get_bitmap_highest_h());
    host._setUninvMatData(g.get_uninv_mat_data(), g.get_uninv_mat_data_size());
    host._setGradientData(g.get_gradient_data(), g.get_gradient_data_size());
    host._setBitmapData(g.get_bitmap_data(), g.get_bitmap_data_size());
    host._setGlyphData(g.get_glyph_data(), g.get_glyph_data_size());
    host._setTextData(g.get_text_data(), g.get_text_data_size(), g.get_text_char_codes ? g.get_text_char_codes() : 0);
    host._setCxformData(g.get_cxform_data(), g.get_cxform_data_size());
    host._setMorphData(g.get_morph_end_shape_data(), g.get_morph_end_shape_data_size(),
                       g.get_morph_end_color_data(), g.get_morph_end_color_data_size());
    host._setFrameLabels(g.get_frame_label_data(), g.get_frame_label_count());

    // The ASYNCIFY frame loop resumes from timers, so a trap inside a frame
    // surfaces as an uncaught error, not as a rejection of the runSWF promise.
    window.addEventListener("error", (ev) => {
        if (ev.error) log(`[trap] ${(ev.error.stack || String(ev.error)).split("\n").slice(0, 14).join(" <- ")}`);
    });
    window.addEventListener("unhandledrejection", (ev) => {
        const r = ev.reason;
        if (r && !/wasmer|panicked/.test(String(r.stack || r))) log(`[trap] ${(r.stack || String(r)).split("\n").slice(0, 14).join(" <- ")}`);
    });
    setStatus(`Running ${width}x${height}, ${frameCount} frames @ ${fps} fps, SWF v${swfVersion}`);
    canvas.style.display = "block";
    canvas.focus();
    // ASYNCIFY frame loop: resolves when the movie quits.
    await host.ccall("runSWF", null, [], [], { async: true });
}
