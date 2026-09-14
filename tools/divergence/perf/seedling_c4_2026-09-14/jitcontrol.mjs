// C4 control: FlashPunk Entity.collide over the level's Tile list, on V8's JIT.
import { readFileSync } from 'node:fs';
const [oel, W, H] = [process.argv[2], Number(process.argv[3]), Number(process.argv[4])];
const xml = readFileSync(oel, 'utf8');
const tilesBlock = xml.slice(xml.indexOf('<tiles'), xml.indexOf('</tiles>'));
const pts = [...tilesBlock.matchAll(/<tile tx="(\d+)" ty="(\d+)" x="(\d+)" y="(\d+)"/g)]
    .map((m) => [Number(m[3]), Number(m[4])]).filter(([x, y]) => Math.floor(x / 16) < W / 16 && Math.floor(y / 16) < H / 16);
class E { constructor(x, y) { this.x = x + 8; this.y = y + 8; this.originX = 8; this.originY = 8; this.width = 16; this.height = 16; this.collidable = true; this._typeNext = null; this._mask = null; } }
let iters = 0;
function collide(self, first, x, y) {
    let e = first;
    const _x = self.x, _y = self.y; self.x = x; self.y = y;
    while (e) {
        iters++;
        if (x - self.originX + self.width > e.x - e.originX && y - self.originY + self.height > e.y - e.originY
            && x - self.originX < e.x - e.originX + e.width && y - self.originY < e.y - e.originY + e.height
            && e.collidable && e !== self) { self.x = _x; self.y = _y; return e; }
        e = e._typeNext;
    }
    self.x = _x; self.y = _y; return null;
}
const run = () => {
    const ents = pts.map(([x, y]) => new E(x, y));
    let first = null;
    for (const e of ents) { e._typeNext = first; first = e; } // addType prepends
    iters = 0;
    const t0 = performance.now();
    for (const e of ents) { collide(e, first, e.x + 1, e.y); collide(e, first, e.x, e.y - 1); collide(e, first, e.x - 1, e.y); collide(e, first, e.x, e.y + 1); }
    return [performance.now() - t0, iters];
};
const res = []; for (let i = 0; i < 7; i++) res.push(run());
console.log(JSON.stringify({ oel, tiles: pts.length, iters: res[0][1], ms: res.map((r) => +r[0].toFixed(2)) }));
