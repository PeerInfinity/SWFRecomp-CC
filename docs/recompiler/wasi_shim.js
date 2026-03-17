// Minimal WASI preview1 polyfill for running wasm32-wasi trace binaries
// Handles both basic WASI and threading-enabled binaries (wasix_32v1)

export class WASIProcExit extends Error {
    constructor(code) {
        super(`proc_exit(${code})`);
        this.code = code;
    }
}

// WASI error codes
const ERRNO_SUCCESS = 0;
const ERRNO_BADF = 8;
const ERRNO_NOSYS = 52;
const ERRNO_NOENT = 44;

export function createWASI() {
    const stdoutChunks = [];
    const stderrChunks = [];
    const decoder = new TextDecoder();
    let memory;

    // Helper to get DataView (handles SharedArrayBuffer correctly)
    function getMem() {
        return new DataView(memory.buffer);
    }
    function getMem8() {
        return new Uint8Array(memory.buffer);
    }

    const wasi_snapshot_preview1 = {
        fd_write(fd, iovs_ptr, iovs_len, nwritten_ptr) {
            const mem = getMem();
            const mem8 = getMem8();
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
            return ERRNO_SUCCESS;
        },

        fd_read(fd, iovs_ptr, iovs_len, nread_ptr) {
            // stdin returns EOF (0 bytes read)
            getMem().setUint32(nread_ptr, 0, true);
            return ERRNO_SUCCESS;
        },

        fd_close() { return ERRNO_SUCCESS; },
        fd_seek() { return ERRNO_SUCCESS; },
        fd_fdstat_set_flags() { return ERRNO_SUCCESS; },

        fd_fdstat_get(fd, fdstat_ptr) {
            if (fd > 2) return ERRNO_BADF;
            const mem = getMem();
            mem.setUint8(fdstat_ptr, 2); // CHARACTER_DEVICE
            mem.setUint16(fdstat_ptr + 2, 0, true);
            mem.setBigUint64(fdstat_ptr + 8, 0n, true);
            mem.setBigUint64(fdstat_ptr + 16, 0n, true);
            return ERRNO_SUCCESS;
        },

        // CRT calls fd_prestat_get for fd=3,4,5... to discover preopened dirs.
        // Must return EBADF to signal "no more preopened directories".
        fd_prestat_get() { return ERRNO_BADF; },
        fd_prestat_dir_name() { return ERRNO_BADF; },

        proc_exit(code) {
            throw new WASIProcExit(code);
        },

        args_sizes_get(argc_ptr, argv_buf_size_ptr) {
            const mem = getMem();
            mem.setUint32(argc_ptr, 0, true);
            mem.setUint32(argv_buf_size_ptr, 0, true);
            return ERRNO_SUCCESS;
        },

        args_get() { return ERRNO_SUCCESS; },

        environ_sizes_get(count_ptr, buf_size_ptr) {
            const mem = getMem();
            mem.setUint32(count_ptr, 0, true);
            mem.setUint32(buf_size_ptr, 0, true);
            return ERRNO_SUCCESS;
        },

        environ_get() { return ERRNO_SUCCESS; },

        clock_time_get(id, precision, time_ptr) {
            const mem = getMem();
            const now = BigInt(Math.round(performance.now() * 1_000_000));
            mem.setBigUint64(time_ptr, now, true);
            return ERRNO_SUCCESS;
        },

        path_open() { return ERRNO_NOENT; },
        sched_yield() { return ERRNO_SUCCESS; },

        // fd_dup (from wasix) — duplicate fd; stub returns EBADF
        fd_dup() { return ERRNO_BADF; },
    };

    return {
        async run(wasmBytes) {
            stdoutChunks.length = 0;
            stderrChunks.length = 0;

            const compiled = await WebAssembly.compile(wasmBytes);

            // Inspect what the module actually needs
            const neededImports = WebAssembly.Module.imports(compiled);

            // Wrap wasi_snapshot_preview1 in a Proxy so any missing functions
            // get auto-stubbed (returns ENOSYS)
            const wasiProxy = new Proxy(wasi_snapshot_preview1, {
                get(target, prop) {
                    if (prop in target) return target[prop];
                    console.log(`[WASI shim] Auto-stubbing wasi_snapshot_preview1.${prop}`);
                    return () => ERRNO_NOSYS;
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

            // Provide stubs for non-WASI imports (e.g. "env" for threading, "wasix_32v1")
            let importedMemory = null;
            for (const [mod, imports] of Object.entries(moduleGroups)) {
                const stubs = {};

                // wasix_32v1 gets a Proxy too (threading stubs)
                if (mod === "wasix_32v1") {
                    importObject[mod] = new Proxy({}, {
                        get(target, prop) {
                            if (prop in wasi_snapshot_preview1) return wasi_snapshot_preview1[prop];
                            return () => ERRNO_NOSYS;
                        }
                    });
                    console.log(`[WASI shim] Proxied wasix_32v1 (${imports.length} imports)`);
                    continue;
                }

                for (const imp of imports) {
                    if (imp.kind === "function") {
                        stubs[imp.name] = () => 0;
                    } else if (imp.kind === "global") {
                        stubs[imp.name] = new WebAssembly.Global({ value: "i32", mutable: true }, 0);
                    } else if (imp.kind === "memory") {
                        // Shared memory for threading-enabled binaries
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

            // If the binary exports __wasm_init_tls, call it (needed for
            // threading-enabled binaries to initialize thread-local storage)
            if (instance.exports.__wasm_init_tls) {
                const tlsBase = instance.exports.__tls_base?.value || 0;
                instance.exports.__wasm_init_tls(tlsBase);
            }

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
