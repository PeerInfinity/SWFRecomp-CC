// Minimal WASI preview1 polyfill for running wasm32-wasi trace binaries
// Only implements the syscalls actually used by wasi-libc compiled programs

export class WASIProcExit extends Error {
    constructor(code) {
        super(`proc_exit(${code})`);
        this.code = code;
    }
}

export function createWASI() {
    const stdoutChunks = [];
    const stderrChunks = [];
    const decoder = new TextDecoder();
    let memory;

    const wasi_snapshot_preview1 = {
        fd_write(fd, iovs_ptr, iovs_len, nwritten_ptr) {
            const mem = new DataView(memory.buffer);
            const mem8 = new Uint8Array(memory.buffer);
            let totalWritten = 0;
            for (let i = 0; i < iovs_len; i++) {
                const buf_ptr = mem.getUint32(iovs_ptr + i * 8, true);
                const buf_len = mem.getUint32(iovs_ptr + i * 8 + 4, true);
                const bytes = mem8.slice(buf_ptr, buf_ptr + buf_len);
                const text = decoder.decode(bytes, { stream: true });
                if (fd === 1) stdoutChunks.push(text);
                else if (fd === 2) stderrChunks.push(text);
                totalWritten += buf_len;
            }
            mem.setUint32(nwritten_ptr, totalWritten, true);
            return 0;
        },

        fd_close() { return 0; },
        fd_seek() { return 0; },

        fd_fdstat_get(fd, fdstat_ptr) {
            const mem = new DataView(memory.buffer);
            mem.setUint8(fdstat_ptr, 2); // CHARACTER_DEVICE
            mem.setUint16(fdstat_ptr + 2, 0, true);
            mem.setBigUint64(fdstat_ptr + 8, 0n, true);
            mem.setBigUint64(fdstat_ptr + 16, 0n, true);
            return 0;
        },

        proc_exit(code) {
            throw new WASIProcExit(code);
        },

        args_sizes_get(argc_ptr, argv_buf_size_ptr) {
            const mem = new DataView(memory.buffer);
            mem.setUint32(argc_ptr, 0, true);
            mem.setUint32(argv_buf_size_ptr, 0, true);
            return 0;
        },

        args_get() { return 0; },

        environ_sizes_get(count_ptr, buf_size_ptr) {
            const mem = new DataView(memory.buffer);
            mem.setUint32(count_ptr, 0, true);
            mem.setUint32(buf_size_ptr, 0, true);
            return 0;
        },

        environ_get() { return 0; },

        clock_time_get(id, precision, time_ptr) {
            const mem = new DataView(memory.buffer);
            const now = BigInt(Math.round(performance.now() * 1_000_000));
            mem.setBigUint64(time_ptr, now, true);
            return 0;
        },
    };

    return {
        async run(wasmBytes) {
            stdoutChunks.length = 0;
            stderrChunks.length = 0;

            const compiled = await WebAssembly.compile(wasmBytes);

            // Inspect what the module actually needs and provide stubs
            const neededImports = WebAssembly.Module.imports(compiled);

            // Wrap wasi_snapshot_preview1 in a Proxy so any missing functions
            // (like sched_yield from threading) get auto-stubbed
            const wasiProxy = new Proxy(wasi_snapshot_preview1, {
                get(target, prop) {
                    if (prop in target) return target[prop];
                    console.log(`[WASI shim] Auto-stubbing wasi_snapshot_preview1.${prop}`);
                    return () => 0;
                }
            });

            const importObject = { wasi_snapshot_preview1: wasiProxy };

            // Group non-WASI imports by module
            const moduleGroups = {};
            for (const imp of neededImports) {
                if (imp.module === "wasi_snapshot_preview1") continue;
                if (!moduleGroups[imp.module]) moduleGroups[imp.module] = [];
                moduleGroups[imp.module].push(imp);
            }

            // Provide stubs for non-WASI imports (e.g. "env" for threading)
            let importedMemory = null;
            for (const [mod, imports] of Object.entries(moduleGroups)) {
                const stubs = {};
                for (const imp of imports) {
                    if (imp.kind === "function") {
                        stubs[imp.name] = () => 0;
                    } else if (imp.kind === "global") {
                        stubs[imp.name] = new WebAssembly.Global({ value: "i32", mutable: true }, 0);
                    } else if (imp.kind === "memory") {
                        // Shared memory for threading stubs
                        importedMemory = new WebAssembly.Memory({
                            initial: 256, maximum: 16384, shared: true
                        });
                        stubs[imp.name] = importedMemory;
                    } else if (imp.kind === "table") {
                        stubs[imp.name] = new WebAssembly.Table({ initial: 0, element: "anyfunc" });
                    }
                }
                importObject[mod] = stubs;
                console.log(`[WASI shim] Stubbed ${imports.length} imports from "${mod}":`,
                    imports.map(i => `${i.name}(${i.kind})`));
            }

            const instance = await WebAssembly.instantiate(compiled, importObject);
            // Use exported memory if available, otherwise use the imported memory
            memory = instance.exports.memory || importedMemory;

            let exitCode = 0;
            try {
                instance.exports._start();
            } catch (e) {
                if (e instanceof WASIProcExit) {
                    exitCode = e.code;
                } else {
                    throw e;
                }
            }

            return {
                exitCode,
                stdout: stdoutChunks.join(""),
                stderr: stderrChunks.join(""),
            };
        },
    };
}
