package {
	import flash.display.Sprite;

	// Regression net for the per-class slot-default TEMPLATE
	// (avm2_slots_init_defaults: memcpy of a precomputed image + a patch loop
	// over the slots that must be realized per object).
	//
	// The template is only sound if (a) every declared-type default is
	// reproduced exactly, (b) values that are POINTERS are never parked in the
	// shared image, and (c) slots needing per-object realization are realized
	// per object rather than shared. Each case below fails loudly if one of
	// those breaks.
	public class Test extends Sprite
	{
		public function Test()
		{
			typedDefaults();
			constInitializers();
			perObjectIdentity();
			templateIsNotAliased();
			subclassShadowing();
			manyInstances();
		}

		// --- (a) The declared-type defaults. These are what the old code
		// re-derived per construction via a name lookup + memcmp chain, and
		// what the template now bakes. int/uint are 0, Number is NaN, Boolean
		// is false, String and any class type are null, `*` is undefined.
		private function typedDefaults():void
		{
			var d:Defaults = new Defaults();
			trace("i=" + d.i);
			trace("u=" + d.u);
			trace("n=" + d.n);
			trace("nIsNaN=" + isNaN(d.n));
			trace("b=" + d.b);
			trace("s=" + d.s);
			trace("sIsNull=" + (d.s === null));
			trace("o=" + d.o);
			trace("oIsNull=" + (d.o === null));
			trace("star=" + d.star);
			trace("starIsUndef=" + (d.star === undefined));
			trace("arr=" + d.arr);
			trace("arrIsNull=" + (d.arr === null));
		}

		// --- Constant initializers. The non-pointer ones are templatable; the
		// STRING one is a pointer into the static pool and must come out of
		// the patch loop, not the shared image.
		private function constInitializers():void
		{
			var c:Inits = new Inits();
			trace("ci=" + c.ci);
			trace("cn=" + c.cn);
			trace("cb=" + c.cb);
			trace("cs=" + c.cs);
			trace("csLen=" + c.cs.length);
			trace("cnull=" + c.cnull);
			trace("cnullIsNull=" + (c.cnull === null));
			// int slot with a double initializer: the coercion to the declared
			// type happens once at template-build time and must still truncate.
			trace("ctrunc=" + c.ctrunc);
		}

		// --- (c) Per-object realization. Two instances must NOT share a slot
		// value that is an object. If a pointer ever got baked into the shared
		// template, these would be the SAME object and both traces would say
		// true.
		private function perObjectIdentity():void
		{
			var a:Holder = new Holder();
			var b:Holder = new Holder();
			a.bag.push("only-a");
			trace("bagsAreDistinct=" + (a.bag !== b.bag));
			trace("aBagLen=" + a.bag.length);
			trace("bBagLen=" + b.bag.length);
		}

		// --- Mutating one instance's slots must not disturb the template that
		// the NEXT construction copies from. This is the aliasing bug the
		// memcpy would introduce if the image were handed out by reference.
		private function templateIsNotAliased():void
		{
			var first:Defaults = new Defaults();
			first.i = 4242;
			first.n = 1.5;
			first.s = "written";
			var second:Defaults = new Defaults();
			trace("secondI=" + second.i);
			trace("secondNIsNaN=" + isNaN(second.n));
			trace("secondSIsNull=" + (second.s === null));
			trace("firstIStillSet=" + (first.i === 4242));
		}

		// --- A subclass adds slots and redeclares a name. The meta table
		// covers every slot ever allocated, including parent slots shadowed by
		// a subclass, so the template must be built per vtable and cover the
		// inherited range too.
		private function subclassShadowing():void
		{
			var s:Sub = new Sub();
			trace("subBase=" + s.baseVal);
			trace("subOwn=" + s.ownVal);
			trace("subOwnIsNaN=" + isNaN(s.ownVal));
			trace("subStr=" + s.subStr);
			var asBase:Base = s;
			trace("viaBase=" + asBase.baseVal);
		}

		// --- Repeat construction: the template is built lazily on the first
		// construction and reused thereafter, so instance #1 and instance #N
		// must agree. A stale or half-built image shows up here.
		private function manyInstances():void
		{
			var mismatches:int = 0;
			for (var k:int = 0; k < 50; k++)
			{
				var d:Defaults = new Defaults();
				if (d.i !== 0 || d.b !== false || d.s !== null
				    || d.star !== undefined || !isNaN(d.n))
				{
					mismatches++;
				}
				d.i = k;  // dirty it, so a shared image would drift
			}
			trace("mismatchesOver50=" + mismatches);
		}
	}
}

class Defaults
{
	public var i:int;
	public var u:uint;
	public var n:Number;
	public var b:Boolean;
	public var s:String;
	public var o:Object;
	public var star:*;
	public var arr:Array;
}

class Inits
{
	public var ci:int = 7;
	public var cn:Number = 2.5;
	public var cb:Boolean = true;
	public var cs:String = "pooled";
	public var cnull:String = null;
	public var ctrunc:int = 9.75;
}

class Holder
{
	// Realized per object: a fresh Array per construction. Never templatable.
	public var bag:Array = new Array();
}

class Base
{
	public var baseVal:int = 11;
}

class Sub extends Base
{
	public var ownVal:Number;
	public var subStr:String = "sub";
}
