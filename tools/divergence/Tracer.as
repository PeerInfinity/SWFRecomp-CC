// Per-frame state dumper. Compiled by MTASC into a tiny SWF whose
// DoInitAction + DoAction tags are extracted and spliced into target SWFs by
// inject_tracer.py.
//
// Emits one trace() line per state observation, prefixed with the tick number,
// so that line-diffing two trace logs identifies the first divergence at the
// granularity of one variable per line.
//
// First version: minimal but useful.
//   F<n> _currentframe=<frame>
//   F<n> _root <prop>=<scalar>          (sorted, scalars only)
//   F<n> <mcpath> _x=<x> _y=<y> _cf=<f> _vis=<v>
//
// Stops after MAX_FRAMES ticks and fires fscommand("quit", "").

class Tracer {
    static var MAX_FRAMES:Number = 100;
    static var MAX_MCS_PER_FRAME:Number = 50;
    static var MAX_MC_DEPTH:Number = 3;

    static var tick:Number = 0;
    static var emitted_mc_count:Number = 0;

    static function main(mc:MovieClip):Void {
        trace("TRACER: start _currentframe=" + _root._currentframe);
        // Hook _root.onEnterFrame. Runs after each frame's script + display update.
        _root.onEnterFrame = function():Void {
            Tracer.dump_tick();
        };
    }

    static function dump_tick():Void {
        tick++;
        emitted_mc_count = 0;

        trace("F" + tick + " _currentframe=" + _root._currentframe);

        dump_scalars("F" + tick + " _root", _root);

        dump_display_list("F" + tick, _root, "_root", 0);

        if (tick >= MAX_FRAMES) {
            trace("TRACER: done");
            fscommand("quit", "");
        }
    }

    // Emit sorted "<prefix> <name>=<value>" lines for scalar own-properties.
    // Skips functions, objects, movieclips (those are handled separately).
    // Skips underscore-prefixed builtins (_x, _y, _parent, etc.) to keep noise
    // out — those are dumped explicitly per-MC by dump_display_list.
    static function dump_scalars(prefix:String, obj:Object):Void {
        var names:Array = [];
        for (var n:String in obj) {
            if (n.charAt(0) == "_") continue;
            var t:String = typeof(obj[n]);
            if (t == "string" || t == "number" || t == "boolean") {
                names.push(n);
            } else if (t == "undefined" || obj[n] == null) {
                names.push(n);
            }
        }
        names.sort();
        for (var i:Number = 0; i < names.length; i++) {
            var key:String = names[i];
            var v = obj[key];
            var s:String;
            if (v === undefined) s = "undefined";
            else if (v === null)  s = "null";
            else if (typeof(v) == "string") s = "\"" + v + "\"";
            else s = "" + v;
            trace(prefix + " " + key + "=" + s);
        }
    }

    // Walk display list, emit per-MC state lines. Children enumerated via
    // for..in (Flash's stable order is depth-sorted).
    static function dump_display_list(frame_prefix:String, mc:MovieClip,
                                       path:String, depth:Number):Void {
        if (depth > MAX_MC_DEPTH) return;
        if (emitted_mc_count >= MAX_MCS_PER_FRAME) return;

        // Emit this MC's own state (skip _root itself — its frame is already
        // dumped at the top of dump_tick).
        if (depth > 0) {
            emitted_mc_count++;
            trace(frame_prefix + " " + path
                  + " _x=" + mc._x
                  + " _y=" + mc._y
                  + " _xs=" + mc._xscale
                  + " _ys=" + mc._yscale
                  + " _rot=" + mc._rotation
                  + " _a=" + mc._alpha
                  + " _cf=" + mc._currentframe
                  + " _vis=" + mc._visible);
        }

        // Recurse into MC children, sorted by name for stable ordering.
        var children:Array = [];
        for (var n:String in mc) {
            if (typeof(mc[n]) == "movieclip") children.push(n);
        }
        children.sort();
        for (var i:Number = 0; i < children.length; i++) {
            if (emitted_mc_count >= MAX_MCS_PER_FRAME) break;
            var name:String = children[i];
            dump_display_list(frame_prefix, mc[name], path + "." + name, depth + 1);
        }
    }
}
