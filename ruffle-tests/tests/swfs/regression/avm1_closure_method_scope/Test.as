// avm1_closure_method_scope — closures invoked through the method / ctor /
// coercion arms keep their DEFINING scope (s22 w2-as-core "M5", 0cea97b3e).
// Before the fix, actionCallMethod's object/array/string arms, the type-2
// NewMethod ctor paths and objectToPrimitive's valueOf call dropped the
// closure's captured scope, so `n` / `tag` below resolved to undefined.
// Expected output: Ruffle exporter (see create_test_swf.sh).
class Test {
	static function mk(n) {
		var o = {};
		o.f = function() { trace("method " + n); };
		o.valueOf = function() { trace("valueOf " + n); return 1; };
		return o;
	}
	static function main(mc) {
		var a = mk("A");
		a.f();
		trace(a == 1);
		var tag = "arr";
		var arr = [];
		arr.push = function(x) { trace("own push " + tag + " " + x); return 0; };
		arr.push(5);
		var s = "S";
		String.prototype["who"] = function() { trace("string proto " + s); };
		var str = "x"; str["who"]();
		var k = "K";
		var holder = {};
		holder.Ctor = function() { this.v = k; };
		var inst = new holder.Ctor();
		trace("ctor " + inst.v);
		trace("done");
	}
}
