// C4 probe: exclusive phase attribution of one frame's samples.
import { readFileSync } from 'node:fs';
const [dump, collide, tileCheck, loadlevel, gameUpdate] = process.argv.slice(2);
const d = JSON.parse(readFileSync(dump, 'utf8'));
const has = (st, f) => st.includes(f);
const ALLOC = /^(o1heap\w*|heap_alloc|heap_free|heap_realloc|avm2_alloc\w*|avm2_gc_\w+|gc_\w+|malloc|free|dlmalloc|sbrk|emscripten_resize_heap|__memset|__memcpy)$/;
const HELPER_PROP = /^(avm2_op_getproperty\w*|resolved_get|getproperty_static_impl|resolve_key|avm2_vtable_find\w*|avm2_value_vtable|memcmp)$/;
const HELPER_NUM = /^(avm2_op_add\w*|avm2_coerce_to_(number|primitive)|avm2_op_(subtract|multiply|lessthan|greaterthan)\w*)$/;
const HELPER_TYPE = /^(avm2_value_is_of_type|avm2_coerce_to_(class|type_mn)|avm2_op_coerce\w*|avm2_op_istype\w*|avm2_op_astype\w*)$/;
const phase = (st) => {
    if (st[0] === '(idle)') return 'idle (window edge)';
    if (st[0] === '(garbage collector)' || has(st, 'avm2_gc_maybe_collect') || has(st, 'gc_collect') || ALLOC.test(st[0])) return 'allocator + GC (recompiler runtime)';
    if (has(st, 'sound_play')) return 'mp3 decode (sound_play → minimp3)';
    if (has(st, collide)) {
        if (st[0] === collide) return 'Entity.collide: compiled AS3 body';
        if (HELPER_PROP.test(st[0])) return 'Entity.collide: property-get helpers';
        if (HELPER_NUM.test(st[0])) return 'Entity.collide: numeric add/coerce helpers';
        if (HELPER_TYPE.test(st[0])) return 'Entity.collide: type-check/coerce helpers';
        return 'Entity.collide: other helpers';
    }
    if (has(st, tileCheck)) return 'Tile.check outside collide (addGrass/drawEdges/…)';
    if (st.some((f) => /e4x|xml/i.test(f))) return 'XML parse / E4X';
    if (has(st, loadlevel)) return 'loadlevel: entity construction + Tilemap/Grid';
    if (gameUpdate && has(st, gameUpdate)) return 'Game.update: other';
    return 'other';
};
const m = new Map();
for (const [w, st] of d.stacks) { const p = phase(st); m.set(p, (m.get(p) || 0) + w); }
console.log(`total sampled ${d.total.toFixed(1)} ms`);
for (const [p, w] of [...m].sort((a, b) => b[1] - a[1])) console.log(`| ${p} | ${w.toFixed(1)} | ${(100 * w / d.total).toFixed(1)}% |`);
