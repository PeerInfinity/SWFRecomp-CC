# QuickJS libregexp (vendored)

ECMA-262 regular-expression engine from QuickJS
(https://github.com/bellard/quickjs), vendored for the AVM2 RegExp builtin
(SWFModernRuntime/src/avm2/avm2_regexp.c). MIT license (headers in each
file). Vendored at upstream commit 04be246001599f5995fa2f2d8c91a0f198d3f34c
(2026-06-16, release 2026-06-04).

Files: libregexp.[ch], libregexp-opcode.h, libunicode.[ch],
libunicode-table.h, cutils.[ch] — unmodified. The embedder hooks
(lre_realloc / lre_check_stack_overflow / lre_check_timeout) live in
avm2_regexp.c. Compiled without CONFIG_ALL_UNICODE (BMP case folding only,
like avmplus's own tables).
