// SWFRecomp In-Browser Graphics Pipeline
// Phase 1: SWFRecomp.wasm (SWF → C files) — same as trace pipeline
// Phase 2: Clang via @wasmer/sdk (C → guest WASM with --allow-undefined)
// Phase 3: Load pre-built Emscripten host + instantiate guest + JS bridge

import { createWASI } from "./wasi_shim.js";

// --- Phase 2: Compile per-SWF C → guest WASM ---

let wasmerInited = false;
let clangPkg = null;

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

async function compileGuestModule(generatedFiles, setStatus) {
    if (!setStatus) setStatus = () => {};
    const { Directory } = await import("https://unpkg.com/@wasmer/sdk@0.8.0-beta.1/dist/index.mjs");

    const clang = await loadClang();
    const clangCmd = clang.entrypoint;
    const wasm_ld = clang.commands["wasm-ld"];

    setStatus("Setting up project files");
    const project = new Directory();

    // Write generated files, post-processing to remove extern declarations
    // for globals that are handled by bridge_globals.h macros.
    // The recompiler emits "extern ActionVar g_override_this;" etc. in function
    // bodies, which conflict with the macro expansion.
    for (const [name, content] of Object.entries(generatedFiles)) {
        let processed = content;
        if (name.endsWith(".c")) {
            processed = processed
                // Remove extern declarations for bridged globals
                .replace(/extern\s+ActionVar\s+g_override_this\s*;/g,
                    "/* g_override_this: via bridge */")
                .replace(/extern\s+int\s+g_override_this_set\s*;/g,
                    "/* g_override_this_set: via bridge */")
                .replace(/extern\s+int\s+quit_swf\s*;/g,
                    "/* quit_swf: via bridge */")
                // Fix declaration-after-label: add null statement after goto labels
                // C99/C11/C17 don't allow declarations after labels; C23 does but
                // the in-browser clang 16 may not support it.
                .replace(/(label_\w+:\s*\n)/g, "$1;\n");
        }
        await project.writeFile(name, new TextEncoder().encode(processed));
    }

    // Write guest main
    const guestMainResp = await fetch("./runtime_src_graphics/guest_main_graphics.c");
    await project.writeFile("guest_main_graphics.c",
        new Uint8Array(await guestMainResp.arrayBuffer()));

    // Write bridge globals header
    const bridgeHdrResp = await fetch("./runtime_src_graphics/bridge_globals.h");
    await project.writeFile("bridge_globals.h",
        new Uint8Array(await bridgeHdrResp.arrayBuffer()));

    // Write pre-compiled bridge_globals.o
    const bridgeObjResp = await fetch("./runtime_src_graphics/bridge_globals.o");
    await project.writeFile("bridge_globals.o",
        new Uint8Array(await bridgeObjResp.arrayBuffer()));

    // Write runtime headers
    const headerList = await fetch("./runtime_headers/manifest.json").then(r => r.json());
    const headerDirs = new Set();
    for (const { path } of headerList) {
        const dir = path.substring(0, path.lastIndexOf("/"));
        if (dir) headerDirs.add(dir);
    }
    for (const dir of [...headerDirs].sort()) {
        await project.createDir(dir);
    }
    for (const { path, file } of headerList) {
        const resp = await fetch(`./runtime_headers/${file}`);
        await project.writeFile(path, new Uint8Array(await resp.arrayBuffer()));
    }

    // Write runtime support headers
    for (const f of ["unicode_case_tables.h", "map.h", "o1heap.h"]) {
        const resp = await fetch(`./runtime_src/${f}`);
        await project.writeFile(f, new Uint8Array(await resp.arrayBuffer()));
    }

    const mounts = { "/project": project };

    // Collect .c files to compile
    const cFiles = [
        "guest_main_graphics.c",
        ...Object.keys(generatedFiles).filter(f => f.endsWith(".c")),
    ];
    console.log("[GRAPHICS] .c files to compile:", cFiles);

    // Compile + link in one clang invocation. The slim driver's preset adds
    // --shared-memory etc. to the linker, but we also pass --allow-undefined
    // and --export-all. The resulting WASM will import undefined symbols
    // (runtime functions) and export all defined functions (frame_0, etc.).
    // The --shared-memory in the output is handled by the WASI shim.
    setStatus(`Compiling ${cFiles.length} files + linking guest`);

    const compileResult = await (async () => {
        const instance = await clangCmd.run({
            args: [
                ...cFiles.map(f => `/project/${f}`),
                "-DDYNAMIC_GUEST",
                "-std=gnu2x",
                "-include", "string.h",
                "-include", "strings.h",
                "-I/project",
                "-I/project/include",
                "-I/project/include/actionmodern",
                "-I/project/include/libswf",
                "-I/project/include/memory",
                "-O0",
                "-w",
                "/project/bridge_globals.o",
                "-Wl,--allow-undefined",
                "-Wl,--export-all",
                "-Wl,--no-entry",
                "-Wl,--global-base=201326592",
                "-o", "/project/guest.wasm",
            ],
            mount: mounts,
        });
        return await instance.wait();
    })();

    console.log(`[GRAPHICS COMPILE+LINK] ok=${compileResult.ok} code=${compileResult.code}`);
    if (compileResult.stderr) console.log(`[GRAPHICS COMPILE+LINK] stderr:`, compileResult.stderr);
    if (!compileResult.ok) {
        throw new Error(`Guest compile+link failed (code ${compileResult.code}):\n${compileResult.stderr || "(no output)"}`);
    }

    return await project.readFile("guest.wasm");
}

// --- Phase 3: Load host + instantiate guest + run ---

let hostModule = null;

async function loadGraphicsHost() {
    if (hostModule) return hostModule;

    // Load the Emscripten graphics host module
    await new Promise((resolve, reject) => {
        const script = document.createElement("script");
        script.src = "graphics_host.js";
        script.onload = resolve;
        script.onerror = () => reject(new Error("Failed to load graphics_host.js"));
        document.head.appendChild(script);
    });

    // Wait for Emscripten to initialize
    hostModule = await new Promise((resolve) => {
        const checkReady = () => {
            if (typeof Module !== "undefined" && Module.calledRun) {
                resolve(Module);
            } else {
                setTimeout(checkReady, 50);
            }
        };
        checkReady();
    });

    console.log("[GRAPHICS] Host module loaded");
    return hostModule;
}

async function runGraphicsGuest(guestWasmBytes) {
    const host = await loadGraphicsHost();

    // Grow host memory so the guest's data segments (at --global-base=192MB)
    // can be initialized during instantiation. The host's 128MB heap allocation
    // happens later during swfStart.
    const currentPages = host.wasmMemory.buffer.byteLength / 65536;
    const neededPages = Math.ceil(210 * 1024 * 1024 / 65536);  // 210 MB
    if (currentPages < neededPages) {
        const growBy = neededPages - currentPages;
        console.log(`[GRAPHICS] Growing memory from ${currentPages} to ${neededPages} pages (${(neededPages * 65536 / 1024 / 1024).toFixed(0)} MB)`);
        try {
            host.wasmMemory.grow(growBy);
        } catch (e) {
            throw new Error(`Failed to grow memory to ${(neededPages * 65536 / 1024 / 1024).toFixed(0)} MB. Your browser may not have enough memory for graphics mode. Try trace mode instead. (${e.message})`);
        }
    }

    // Build a guest→host function pointer translation map.
    // Will be populated after guest instantiation, used by wrappers.
    let guestTable = null;  // set after instantiation
    const guestToHostFuncPtr = {};  // lazy cache: guest idx → host idx

    function translateFuncPtr(guestIdx) {
        if (guestIdx === 0) return 0;  // null
        if (guestToHostFuncPtr[guestIdx] !== undefined) return guestToHostFuncPtr[guestIdx];
        // Look up the guest function and register it in the host's table
        if (guestTable) {
            const func = guestTable.get(guestIdx);
            if (func) {
                const hostIdx = host.addFunction(func, "viiiiii");  // Function2Ptr sig
                guestToHostFuncPtr[guestIdx] = hostIdx;
                return hostIdx;
            }
        }
        console.warn(`[GRAPHICS] Cannot translate func ptr: guest idx ${guestIdx}`);
        return guestIdx;  // fallback
    }

    console.log(`[GRAPHICS] Instantiating guest (${guestWasmBytes.length} bytes)`);

    // Compile the guest module
    const guestCompiled = await WebAssembly.compile(guestWasmBytes);
    const neededImports = WebAssembly.Module.imports(guestCompiled);

    console.log("[GRAPHICS] Guest imports:", neededImports.length);

    // Build import object: map guest's undefined symbols to host exports.
    // The guest also imports wasi_snapshot_preview1 and wasix_32v1 from the
    // linked WASI libc — provide no-op stubs for these since the guest
    // functions are called by the host (not run as a standalone program).
    const ERRNO_NOSYS = 52;
    const ERRNO_BADF = 8;
    const wasiStubs = new Proxy({}, {
        get(_, prop) {
            if (prop === "fd_prestat_get" || prop === "fd_prestat_dir_name") return () => ERRNO_BADF;
            if (prop === "proc_exit") return (code) => { throw new Error(`proc_exit(${code})`); };
            return () => ERRNO_NOSYS;
        }
    });
    const importObject = {
        env: {},
        wasi_snapshot_preview1: wasiStubs,
        wasix_32v1: wasiStubs,
    };

    for (const imp of neededImports) {
        if (imp.module !== "env") continue;

        if (imp.kind === "memory") {
            // Share host's memory
            importObject.env[imp.name] = host.wasmMemory;
            console.log(`[GRAPHICS] Shared memory: env.${imp.name}`);
        } else if (imp.kind === "function") {
            // Map to host's exported function.
            const wasmExports = host.wasmExports || host.asm || {};
            const hostFunc = wasmExports[imp.name]
                || host["_" + imp.name]
                || host[imp.name];

            // Wrap functions that take function pointers to translate
            // guest table indices → host table indices
            if (imp.name === "actionDefineFunction2" && hostFunc) {
                importObject.env[imp.name] = (ctx, name, func_ptr, pc, rc, flags) => {
                    const hostPtr = translateFuncPtr(func_ptr);
                    return hostFunc(ctx, name, hostPtr, pc, rc, flags);
                };
            } else if (imp.name === "actionDefineFunction" && hostFunc) {
                importObject.env[imp.name] = (ctx, name, func_ptr, pc) => {
                    const hostPtr = translateFuncPtr(func_ptr);
                    return hostFunc(ctx, name, hostPtr, pc);
                };
            } else if (hostFunc) {
                importObject.env[imp.name] = hostFunc;
            } else {
                console.warn(`[GRAPHICS] Missing host function: ${imp.name}`);
                importObject.env[imp.name] = (...args) => {
                    // Only log once per function
                    if (!importObject.env[imp.name]._logged) {
                        console.error(`[GRAPHICS] Called unresolved: ${imp.name}`);
                        importObject.env[imp.name]._logged = true;
                    }
                    return 0;
                };
            }
        } else if (imp.kind === "global") {
            importObject.env[imp.name] = new WebAssembly.Global(
                { value: "i32", mutable: true }, 0);
        } else if (imp.kind === "table") {
            importObject.env[imp.name] = new WebAssembly.Table({ initial: 1024, element: "anyfunc" });
        }
    }

    // Instantiate guest with host's exports
    const guestInstance = await WebAssembly.instantiate(guestCompiled, importObject);
    const guest = guestInstance.exports;
    // Set guest table reference for function pointer translation
    guestTable = guest.__indirect_function_table || null;
    console.log("[GRAPHICS] Guest instantiated, exports:", Object.keys(guest));
    if (guestTable) console.log(`[GRAPHICS] Guest function table: ${guestTable.length} entries`);

    // Initialize bridge globals (pointer indirection to host's globals)
    const cum = host._get_catch_up_mode_addr();
    const gtsm = host._get_g_tag_skip_mode_addr();
    const qs = host._get_quit_swf_addr();
    const got = host._get_g_override_this_addr();
    const gots = host._get_g_override_this_set_addr();
    guest.bridge_init(cum, gtsm, qs, got, gots);
    console.log("[GRAPHICS] Bridge globals initialized");

    // Read SWF metadata from guest
    const frameCount = guest.get_frame_count();
    const fps = guest.get_fps();
    const swfVersion = guest.get_swf_version();
    const width = guest.get_frame_width();
    const height = guest.get_frame_height();
    console.log(`[GRAPHICS] SWF: ${width}x${height}, ${frameCount} frames, ${fps} fps, v${swfVersion}`);

    // Configure host app context
    host._configureAppContext(frameCount, fps, swfVersion, width, height);

    // Set data pointers (guest's data is in shared memory at offset 64MB+)
    host._setShapeData(guest.get_shape_data(), guest.get_shape_data_size());
    host._setTransformData(guest.get_transform_data(), guest.get_transform_data_size());
    host._setColorData(guest.get_color_data(), guest.get_color_data_size());
    host._setStageToNdc(guest.get_stage_to_ndc());
    host._setBitmapInfo(guest.get_bitmap_count(), guest.get_bitmap_highest_w(), guest.get_bitmap_highest_h());
    host._setUninvMatData(guest.get_uninv_mat_data(), guest.get_uninv_mat_data_size());
    host._setGradientData(guest.get_gradient_data(), guest.get_gradient_data_size());
    host._setBitmapData(guest.get_bitmap_data(), guest.get_bitmap_data_size());
    host._setGlyphData(guest.get_glyph_data(), guest.get_glyph_data_size());
    host._setTextData(guest.get_text_data(), guest.get_text_data_size());
    host._setCxformData(guest.get_cxform_data(), guest.get_cxform_data_size());
    host._setMorphData(
        guest.get_morph_end_shape_data(), guest.get_morph_end_shape_data_size(),
        guest.get_morph_end_color_data(), guest.get_morph_end_color_data_size()
    );

    // Register tagInit from guest
    const tagInitIdx = host.addFunction(guest.tagInit, "vi");
    host._setTagInit(tagInitIdx);

    // Register ALL guest functions that might be called via function pointers
    // in the host's function table. This includes frame_N, sprite_N_frame_M,
    // and any generated Function2 callbacks.
    // The guest's function table has different indices than the host's table.
    // We register each guest function in the host's table and build a mapping.
    const guestToHostIdx = {};  // guest table index → host table index

    // Find all callable functions exported by the guest
    const guestFuncNames = Object.keys(guest).filter(name =>
        typeof guest[name] === "function" &&
        (name.startsWith("frame_") || name.startsWith("sprite_") ||
         name.startsWith("func2_") || name === "tagInit" || name === "script_0" ||
         name.startsWith("script_"))
    );

    for (const name of guestFuncNames) {
        const func = guest[name];
        // Determine the function signature for addFunction:
        // frame_N, sprite_N_frame_M, tagInit, script_N: void(SWFAppContext*) = "vi"
        // func2_*: ActionVar(SWFAppContext*, ActionVar*, u32, ActionVar*, void*) = complex
        let sig = "vi";  // default: void(int)
        if (name.startsWith("func2_")) {
            // Function2 returns ActionVar (64 bits) and takes 5 args
            // In wasm32, ActionVar is returned by sret (hidden first param)
            sig = "viiiiii";  // void(sret_ptr, app_ctx, args, argc, regs, this)
        }
        try {
            const hostIdx = host.addFunction(func, sig);
            // Try to get the guest's own table index for this function
            // so we can patch sprite_frame_funcs arrays in shared memory
            if (guest.__indirect_function_table) {
                // Search guest's function table for this function
                const guestTable = guest.__indirect_function_table;
                for (let gi = 0; gi < guestTable.length; gi++) {
                    if (guestTable.get(gi) === func) {
                        guestToHostIdx[gi] = hostIdx;
                        break;
                    }
                }
            }
            console.log(`[GRAPHICS] Registered ${name} at host table index ${hostIdx}`);
        } catch (e) {
            console.warn(`[GRAPHICS] Failed to register ${name}: ${e.message}`);
        }
    }

    // Set main frame functions
    for (let i = 0; i < frameCount; i++) {
        const frameFuncName = `frame_${i}`;
        const frameFunc = guest[frameFuncName];
        if (frameFunc) {
            // Find the host table index we registered earlier
            const hostIdx = host.addFunction(frameFunc, "vi");
            host._setFrameFunc(i, hostIdx);
        }
    }

    // Patch sprite frame function pointers in shared memory.
    // sprite_N_frame_funcs[] arrays contain guest table indices that are
    // meaningless in the host's table. Overwrite with host table indices.
    const mem32 = new Uint32Array(host.wasmMemory.buffer);
    for (const name of Object.keys(guest)) {
        const spriteMatch = name.match(/^sprite_(\d+)_frame_funcs$/);
        if (!spriteMatch) continue;

        // Get the memory address of the array (may be a WebAssembly.Global)
        let arrAddr = guest[name];
        if (arrAddr && typeof arrAddr === "object" && "value" in arrAddr) {
            arrAddr = arrAddr.value;  // WebAssembly.Global
        }
        if (typeof arrAddr !== "number" || arrAddr === 0) {
            console.warn(`[GRAPHICS] Cannot find address for ${name}: ${arrAddr}`);
            continue;
        }

        const spriteId = spriteMatch[1];
        // Count sprite_N_frame_M exports
        let spriteFrameCount = 0;
        while (guest[`sprite_${spriteId}_frame_${spriteFrameCount}`]) spriteFrameCount++;

        // Write host table indices into the array
        for (let fi = 0; fi < spriteFrameCount; fi++) {
            const funcName = `sprite_${spriteId}_frame_${fi}`;
            const func = guest[funcName];
            if (!func) continue;
            // Register in host table if not already done
            const hostIdx = host.addFunction(func, "vi");
            const ptrAddr = arrAddr + fi * 4;
            const oldVal = mem32[ptrAddr >> 2];
            mem32[ptrAddr >> 2] = hostIdx;
            console.log(`[GRAPHICS] Patched ${name}[${fi}] (${funcName}): ${oldVal} → ${hostIdx}`);
        }
    }

    // Also patch the main frame_funcs array in guest memory
    let frameFuncsAddr = guest.frame_funcs;
    if (frameFuncsAddr && typeof frameFuncsAddr === "object" && "value" in frameFuncsAddr) {
        frameFuncsAddr = frameFuncsAddr.value;
    }
    if (typeof frameFuncsAddr === "number" && frameFuncsAddr > 0) {
        for (let i = 0; i < frameCount; i++) {
            const func = guest[`frame_${i}`];
            if (!func) continue;
            const hostIdx = host.addFunction(func, "vi");
            mem32[(frameFuncsAddr + i * 4) >> 2] = hostIdx;
            console.log(`[GRAPHICS] Patched frame_funcs[${i}]: → ${hostIdx}`);
        }
    }

    // Initialize variable array if needed
    if (guest.get_max_string_id && guest.get_max_string_id() > 0) {
        host._initVarArray(guest.get_max_string_id());
    }

    // Show canvas
    const canvas = document.getElementById("canvas");
    if (canvas) canvas.style.display = "block";

    // Run!
    console.log("[GRAPHICS] Starting SWF execution...");
    host.ccall("runSWF", null, [], [], { async: true });
}

// Export for use by the main pipeline
export { initWasmer, loadClang, compileGuestModule, loadGraphicsHost, runGraphicsGuest };
