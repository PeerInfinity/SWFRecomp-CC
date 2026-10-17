# QuickJS libregexp (vendored)

ECMA-262 regular-expression engine from QuickJS
(https://github.com/bellard/quickjs), vendored for the AVM2 RegExp builtin
(SWFModernRuntime/src/avm2/avm2_regexp.c). MIT license (headers in each
file). Vendored at upstream commit 04be246001599f5995fa2f2d8c91a0f198d3f34c
(2026-06-16, release 2026-06-04).

Files: libregexp.[ch], libregexp-opcode.h, libunicode.[ch],
libunicode-table.h, cutils.[ch] — unmodified except one local change
(session 22): capture indices widened from u8 to u16 so a pattern can hold
up to 1024 groups (avmplus PCRE has no 255 ceiling). `save_start`/`save_end`
take a u16 operand (size 3), `save_reset` two (size 5), and the bytecode
header is 10 bytes with a u16 capture count. Back references keep u8
indices; one naming a group above 255 is a parse error. The embedder hooks
(lre_realloc / lre_check_stack_overflow / lre_check_timeout) live in
avm2_regexp.c. Compiled without CONFIG_ALL_UNICODE (BMP case folding only,
like avmplus's own tables).
