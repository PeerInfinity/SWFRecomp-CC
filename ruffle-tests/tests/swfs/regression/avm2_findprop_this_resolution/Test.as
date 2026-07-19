package {
	import flash.display.Sprite;

	// Regression for the recompiler's find->this lever: unqualified
	// own-member access compiled as FindPropStrict(mn)+GetProperty(mn)
	// must keep resolving exactly like the full scope walk when the
	// recompiler substitutes the find with a direct `this` push (and the
	// read with a baked slot load). Covers: plain slot reads, reads
	// through a base-class method when a subclass shadows the name
	// (private-ns resolution), getters, unqualified own-method calls,
	// unqualified statics, a name that collides with a package-level
	// function, dynamic classes, `with`-blocks, and try/catch bodies
	// (the last two must gate the substitution off).
	public class Test extends Sprite {
		public function Test() {
			var b:Base = new Base();
			trace("base.readField: " + b.readField());
			trace("base.readShadowed: " + b.readShadowed());
			trace("base.readViaGetter: " + b.readViaGetter());
			trace("base.callOwn: " + b.callOwn());
			trace("base.readGlobalCollide: " + b.readGlobalCollide());
			trace("base.readStatic: " + b.readStatic());

			var s:Sub = new Sub();
			trace("sub.readField: " + s.readField());
			// Base method's unqualified read uses Base's private ns ->
			// must read BASE's slot even on a Sub instance.
			trace("sub.readShadowed: " + s.readShadowed());
			trace("sub.readOwnShadow: " + s.readOwnShadow());
			trace("sub.callOwn: " + s.callOwn());

			var d:Dyn = new Dyn();
			trace("dyn.readField: " + d.readField());

			trace("base.withBlock: " + b.withBlock());
			trace("base.tryBlock: " + b.tryBlock());
		}
	}
}

function helper():String { return "global-helper"; }

class Base {
	private var shadowed:String = "base-shadowed";
	public var field:int = 41;
	public static var stat:String = "base-static";
	private var _g:Number = 2.5;

	public function get viaGetter():Number { return _g * 2; }

	public function readField():int {
		// unqualified own slot read (findprop+getprop in old ASC output)
		return field + 1;
	}
	public function readShadowed():String {
		return shadowed;
	}
	public function readViaGetter():Number {
		return viaGetter;
	}
	public function ownMethod():String { return "own-method"; }
	public function callOwn():String {
		return ownMethod();
	}
	public function readGlobalCollide():String {
		// `helper` is a package-level function, NOT a member: the find
		// must fall through to the global/domain, never bind to `this`.
		return helper();
	}
	public function readStatic():String {
		return stat;
	}
	public function withBlock():String {
		var o:Object = { field: 900 };
		with (o) {
			// inside `with`, `field` must resolve to o.field, not this.field
			return "with:" + field;
		}
		return "unreachable";
	}
	public function tryBlock():String {
		try {
			return "try:" + field;
		} catch (e:Error) {
			return "catch";
		}
		return "unreachable";
	}
}

class Sub extends Base {
	private var shadowed:String = "sub-shadowed";
	public function readOwnShadow():String {
		// Sub's own unqualified read must see SUB's slot.
		return shadowed;
	}
	override public function ownMethod():String { return "sub-own-method"; }
}

dynamic class Dyn {
	public var field:String = "dyn-field";
	public function readField():String {
		return field;
	}
}
