package {
	import flash.display.Sprite;
	import flash.utils.getDefinitionByName;
	import flash.utils.getQualifiedClassName;

	import probe.Base;
	import probe.Sub;
	import probe.Dyn;

	// swfmodern.Reflect (namespace-blind trait access) and swfmodern.Rng's
	// draw counter — the two observation hooks injected code uses to read a
	// recompiled, source-less SWF.
	//
	// Every hook row has a control that must DIFFER: the A/B rows read
	// members that the D rows show ordinary property access cannot reach.
	// If a D row ever prints the real value, visibility broke — that is a
	// corpus-wide regression, not a better hook.
	public class Test extends Sprite {
		public function Test() {
			var R:Object = getDefinitionByName("swfmodern.Reflect");
			var G:Object = getDefinitionByName("swfmodern.Rng");

			var b:Base = new Base();
			var s:Sub = new Sub();
			var d:Dyn = new Dyn();

			// --- A: reading through the trait table -----------------------
			// The shadowed pair. Same object, same member name, two owners,
			// two different values: this is what proves the owner argument
			// is load-bearing rather than decorative.
			trace("A1 base.shadowed: " + R.getTrait(s, "probe.Base", "shadowed"));
			trace("A2 sub.shadowed:  " + R.getTrait(s, "probe::Sub", "shadowed"));
			// ...and it agrees with what each class's own code sees.
			trace("A3 via base code: " + s.readShadowed());
			trace("A4 via sub code:  " + s.readOwnShadowed());
			// Protected instance slot, read off a SUBCLASS receiver (the
			// entry is inherited and re-keyed onto Sub's protected ns; the
			// owner is still Base).
			trace("A5 protected:     " + R.getTrait(s, "probe.Base", "prot"));
			// Protected getter — invoked, not slot-read.
			trace("A6 accessor:      " + R.getTrait(b, "probe.Base", "accessor"));
			// Protected STATIC, read off the class object.
			trace("A7 static:        " + R.getTrait(Base, "probe.Base", "protStat"));
			// A public member goes through the same door.
			trace("A8 public:        " + R.getTrait(b, "probe.Base", "pub"));
			// The owner string may be spelled either way.
			trace("A9 qname form:    " + getQualifiedClassName(s));

			// --- B: writing through the trait table -----------------------
			R.setTrait(s, "probe.Base", "prot", 42);
			trace("B1 after set:     " + R.getTrait(s, "probe.Base", "prot"));
			// The declared type still governs: a String lands in an int slot
			// as an int, exactly as an ordinary slot write would coerce it.
			R.setTrait(s, "probe.Base", "prot", "13");
			trace("B2 coerced:       " + R.getTrait(s, "probe.Base", "prot")
			      + " typeof=" + (typeof R.getTrait(s, "probe.Base", "prot")));
			// Protected setter — invoked, not slot-written.
			R.setTrait(b, "probe.Base", "accessor", 5);
			trace("B3 accessor set:  " + R.getTrait(b, "probe.Base", "accessor"));
			// Writing one half of the shadowed pair must not move the other.
			R.setTrait(s, "probe::Sub", "shadowed", "sub-written");
			trace("B4 sub written:   " + R.getTrait(s, "probe::Sub", "shadowed"));
			trace("B5 base untouched:" + R.getTrait(s, "probe.Base", "shadowed"));

			// --- C: refusals, each distinguishable, never null ------------
			trace("C1 " + refuseGet(R, s, "probe.Base", "noSuchMember"));
			trace("C2 " + refuseGet(R, s, "probe.NoSuchClass", "shadowed"));
			trace("C3 " + refuseGet(R, null, "probe.Base", "shadowed"));
			trace("C4 " + refuseGet(R, s, "probe.Base", "secretMethod"));
			trace("C5 " + refuseSet(R, Base, "probe.Base", "FROZEN", 1));
			// A member of the RIGHT name declared by a class that exists but
			// is not this object's: Dyn is real, Sub is not one of its bases.
			trace("C6 " + refuseGet(R, d, "probe.Base", "shadowed"));

			// --- D: controls — ordinary access must NOT see any of it -----
			// Sealed receiver: the name is not in the public namespace, and
			// the class cannot grow one, so the read is a #1069.
			trace("D1 " + control(s, "shadowed"));
			trace("D2 " + control(s, "prot"));
			// Dynamic receiver: the same read is `undefined`, the other
			// shape of "ordinary access cannot see it".
			trace("D3 " + control(d, "hidden"));
			trace("D4 hook sees it:  " + R.getTrait(d, "probe.Dyn", "hidden"));
			// Public members still read normally — the hook added a door, it
			// did not remove the walls.
			trace("D5 public normal: " + b.pub);

			// --- E: the RNG draw counter ---------------------------------
			var d0:Number = G.draws();
			Math.random(); Math.random(); Math.random();
			trace("E1 three draws:   " + (Number(G.draws()) - d0));
			d0 = G.draws();
			trace("E2 no draws:      " + (Number(G.draws()) - d0));
			// The cosmetic stream is a SEPARATE generator and must not count.
			d0 = G.draws();
			G.cosmetic(); G.cosmetic();
			trace("E3 cosmetic:      " + (Number(G.draws()) - d0));
			// Monotonic: reseeding the stream does not rewind the count.
			d0 = G.draws();
			G.setState(12345);
			Math.random();
			trace("E4 across reset:  " + (Number(G.draws()) - d0));
			trace("E5 monotonic:     " + (Number(G.draws()) >= d0));
		}

		// The refusal messages are the contract: a caller must be able to
		// tell "no such trait" from "not readable" from "no such object".
		private function refuseGet(R:Object, obj:Object,
		                           owner:String, name:String):String {
			try {
				var v:* = R.getTrait(obj, owner, name);
				return "NO REFUSAL, got: " + v;
			} catch (e:Error) {
				return e.message;
			}
			return "unreachable";
		}

		private function refuseSet(R:Object, obj:Object, owner:String,
		                           name:String, value:*):String {
			try {
				R.setTrait(obj, owner, name, value);
				return "NO REFUSAL";
			} catch (e:Error) {
				return e.message;
			}
			return "unreachable";
		}

		private function control(obj:Object, name:String):String {
			try {
				var v:* = obj[name];
				return "control: " + v;
			} catch (e:Error) {
				return "control: throws #" + e.errorID;
			}
			return "unreachable";
		}
	}
}
