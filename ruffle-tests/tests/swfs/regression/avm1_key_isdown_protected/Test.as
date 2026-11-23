// avm1_key_isdown_protected: Key's built-in methods are protected. A plain
// `Key.isDown = f` assignment is ignored (Ruffle; found driving N, s26
// n-level-complete report 5.2); after ASSetPropFlags(Key, "isDown", 0, 7)
// clears the flags it takes. Also checks delete, for-in visibility and a
// sibling method (getCode). Build: see README-style header in create_test_swf.sh.
class Test {
	static function main(mc:MovieClip):Void {
		var K:Object = Key;
		var orig:Function = K.isDown;
		var mine:Function = function(k:Number):Boolean { return true; };
		K.isDown = mine;
		trace("assign: replaced=" + (K.isDown == mine) + " same_as_orig=" + (K.isDown == orig));
		trace("call: " + Key.isDown(65));
		var en:String = "";
		for (var p in K) if (p == "isDown" || p == "getCode") en += p + " ";
		trace("enum: [" + en + "]");
		trace("delete: " + (delete K.getCode) + " still=" + (typeof(K.getCode)));
		_global.ASSetPropFlags(K, "isDown", 0, 7);
		K.isDown = mine;
		trace("after ASSetPropFlags: replaced=" + (K.isDown == mine));
		trace("call: " + Key.isDown(65));
		K.isDown = orig;
		trace("restored=" + (K.isDown == orig));
		K.myProp = 5;
		trace("user prop: " + K.myProp);
	}
}
