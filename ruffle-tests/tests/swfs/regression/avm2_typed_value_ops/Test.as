package {
	import flash.display.Sprite;

	// Regression net for the typed-value emission lever (compare→branch
	// fusion + the inline numeric/boolean fast arms). Every case below is a
	// shape where a naive specialization gives a DIFFERENT answer than the
	// generic op, so the trace pins the semantics rather than the speed.
	public class Test extends Sprite
	{
		public function Test()
		{
			nanBranchPairs();
			zeroSigns();
			widthPromotion();
			addIsNotNumeric();
			booleanCoercion();
			unaryOnNonNumbers();
		}

		// --- NaN: all four comparisons are FALSE, so a compare and its
		// negation both take the "false" arm. This is the landmine: iflt and
		// ifnlt are distinct opcodes and `!(a<b)` is NOT `a>=b` under NaN.
		private function nanBranchPairs():void
		{
			var n:Number = Number.NaN;
			var one:Number = 1;
			trace("nan lt   " + (n < one) + " " + (one < n));
			trace("nan le   " + (n <= one) + " " + (one <= n));
			trace("nan gt   " + (n > one) + " " + (one > n));
			trace("nan ge   " + (n >= one) + " " + (one >= n));
			// The branch forms (what the verifier splits into cmp+IfTrue and
			// cmp+IfFalse). Both arms must report the FALSE side.
			if (n < one) { trace("nan iflt  taken"); } else { trace("nan iflt  not-taken"); }
			if (n >= one) { trace("nan ifge  taken"); } else { trace("nan ifge  not-taken"); }
			// Negated conditions exercise the opposite branch polarity.
			if (!(n < one)) { trace("nan !lt   taken"); } else { trace("nan !lt   not-taken"); }
			trace("nan eq   " + (n == n) + " " + (n != n));
			trace("nan seq  " + (n === n));
		}

		// --- Signed zero: -0 == +0 and -0 === +0, but the SIGN must survive
		// arithmetic (a specialization that loses it shows up in 1/x).
		private function zeroSigns():void
		{
			var pz:Number = 0;
			var nz:Number = -0;
			trace("zero eq  " + (pz == nz) + " " + (pz === nz));
			trace("zero lt  " + (pz < nz) + " " + (nz < pz));
			var made:Number = 0 * -1;
			trace("zero sgn " + (1 / made) + " " + (1 / (nz * 1)) + " " + (1 / (pz - 0)));
			trace("zero str " + made + " " + nz);
		}

		// --- int/uint/Number mixed widths promote to double before compare;
		// values past 2^31 and 2^53 pin that the promotion is not truncating.
		private function widthPromotion():void
		{
			var i:int = -1;
			var u:uint = 4294967295;
			var d:Number = 4294967295;
			trace("width eq " + (i == u) + " " + (u == d) + " " + (i == d));
			trace("width lt " + (i < u) + " " + (u < d) + " " + (d < u));
			var big:Number = 9007199254740993;
			trace("width big " + (big == 9007199254740992) + " " + (big > 9007199254740991));
			var iz:int = 0;
			var uz:uint = 0;
			trace("width zero " + (iz == uz) + " " + (iz === uz) + " " + (iz < uz));
		}

		// --- `add` is NOT numeric: it concatenates when either side is a
		// string and calls valueOf on objects. It must keep the generic op.
		private function addIsNotNumeric():void
		{
			var s:* = "5";
			var n:Number = 5;
			trace("add mix  " + (s + n) + " " + (n + s) + " " + (s + s));
			trace("add num  " + (n + n) + " " + (n - s) + " " + (n * s));
			var arr:* = [1, 2];
			trace("add obj  " + (arr + "") + " " + (1 + arr));
			var nul:* = null;
			var und:* = undefined;
			trace("add nul  " + (1 + nul) + " " + ("a" + nul) + " " + (1 + und));
			// Subtract/multiply/divide DO coerce — including the string arms.
			var ten:* = "10";
			var three:* = "3";
			var nan_s:* = "x";
			var nul:* = null;
			trace("sub str  " + (ten - three) + " " + (nan_s - 1) + " " + (nul - 1));
		}

		// --- Branch on non-Boolean conditions: the fallback arm of the
		// boolean fast path. Each of these is a distinct coerce_to_boolean rule.
		private function booleanCoercion():void
		{
			var vals:Array = [undefined, null, 0, -0, Number.NaN, 1, "", "0", "false", {}, []];
			var out:String = "";
			for (var k:int = 0; k < vals.length; k++)
			{
				if (vals[k]) { out += "T"; } else { out += "f"; }
			}
			trace("bool arm " + out);
			// The `not` op on the same values.
			out = "";
			for (k = 0; k < vals.length; k++)
			{
				out += (!vals[k]) ? "T" : "f";
			}
			trace("bool not " + out);
		}

		// --- increment/decrement/negate coerce to Number first (never
		// string-concatenating, unlike add).
		private function unaryOnNonNumbers():void
		{
			var s:* = "5";
			s++;
			trace("unary s+ " + s + " " + (typeof s));
			var b:* = true;
			b++;
			trace("unary b+ " + b);
			var nn:* = null;
			nn++;
			trace("unary n+ " + nn);
			var u:* = undefined;
			u++;
			trace("unary u+ " + u);
			var x:* = "7";
			var bad:* = "abc";
			trace("unary neg " + (-x) + " " + (-bad));
			var i:int = 2147483647;
			i++;
			trace("unary iov " + i);
		}
	}
}
